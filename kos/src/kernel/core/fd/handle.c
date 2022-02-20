/* Copyright (c) 2019-2022 Griefer@Work                                       *
 *                                                                            *
 * This software is provided 'as-is', without any express or implied          *
 * warranty. In no event will the authors be held liable for any damages      *
 * arising from the use of this software.                                     *
 *                                                                            *
 * Permission is granted to anyone to use this software for any purpose,      *
 * including commercial applications, and to alter it and redistribute it     *
 * freely, subject to the following restrictions:                             *
 *                                                                            *
 * 1. The origin of this software must not be misrepresented; you must not    *
 *    claim that you wrote the original software. If you use this software    *
 *    in a product, an acknowledgement (see the following) in the product     *
 *    documentation is required:                                              *
 *    Portions Copyright (c) 2019-2022 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef GUARD_KERNEL_SRC_FD_HANDLE_C
#define GUARD_KERNEL_SRC_FD_HANDLE_C 1
#define _KOS_SOURCE 1
#define _GNU_SOURCE 1

#include <kernel/compiler.h>

#ifndef CONFIG_USE_NEW_HANDMAN
#include <debugger/config.h>
#include <debugger/hook.h>
#include <kernel/except.h>
#include <kernel/fs/fifohandle.h>
#include <kernel/fs/fifonode.h>
#include <kernel/fs/filehandle.h>
#include <kernel/fs/fs.h>
#include <kernel/fs/path.h>
#include <kernel/fs/vfs.h>
#include <kernel/handle.h>
#include <kernel/malloc.h>
#include <kernel/mman/event.h>
#include <kernel/paging.h>
#include <kernel/pipe.h>
#include <kernel/types.h>
#include <kernel/user.h>
#include <sched/cpu.h>
#include <sched/cred.h>
#include <sched/group.h>
#include <sched/task.h>

#include <hybrid/atomic.h>

#include <kos/except/reason/fs.h>
#include <kos/except/reason/inval.h>
#include <kos/ioctl/_openfd.h>

#include <assert.h>
#include <fcntl.h>
#include <sched.h>
#include <stddef.h>
#include <string.h>

#if HANDLE_TYPE_UNDEFINED > 0xffff || \
  ((HANDLE_TYPE_UNDEFINED & 0xff) != ((HANDLE_TYPE_UNDEFINED >> 8) & 0xff))
#error "Unsupported value for `HANDLE_TYPE_UNDEFINED'"
#endif

DECL_BEGIN

#if !defined(NDEBUG) && !defined(NDEBUG_FINI)
#define DBG_memset memset
#else /* !NDEBUG && !NDEBUG_FINI */
#define DBG_memset(...) (void)0
#endif /* NDEBUG || NDEBUG_FINI */

#ifdef NDEBUG
#define handle_manager_assert_integrity(self) (void)0
#else /* NDEBUG */
PUBLIC ATTR_NOINLINE NONNULL((1)) void
NOTHROW(FCALL handle_manager_assert_integrity)(struct handle_manager *__restrict self) {
	unsigned int i, counted, counted_cloexec, counted_clofork;
	if (self->hm_mode == HANDLE_MANAGER_MODE_HASHVECTOR) {
		assert(self->hm_count <= self->hm_hashvector.hm_hashuse);
		counted = 0;
		for (i = 0; i <= self->hm_hashvector.hm_hashmsk; ++i) {
			if (self->hm_hashvector.hm_hashvec[i].hh_handle_id != HANDLE_HASHENT_SENTINEL_ID)
				++counted;
		}
		assert(self->hm_hashvector.hm_hashuse == counted);
		assert(self->hm_hashvector.hm_vecfree <= self->hm_count);
		assert(self->hm_hashvector.hm_vecfree <= self->hm_hashvector.hm_alloc);
	}
	assert(self->hm_minfree <= self->hm_count); /* Yes, this one makes sense! */
	assert(self->hm_cloexec_count <= self->hm_count);
	assert(self->hm_clofork_count <= self->hm_count);
	assert(self->hm_count <= self->hm_linear.hm_alloc);
	counted         = 0;
	counted_cloexec = 0;
	counted_clofork = 0;
	for (i = 0; i < self->hm_linear.hm_alloc; ++i) {
		assert(self->hm_linear.hm_vector[i].h_type < HANDLE_TYPE_COUNT);
		if (self->hm_linear.hm_vector[i].h_type != HANDLE_TYPE_UNDEFINED) {
			if (self->hm_linear.hm_vector[i].h_mode & IO_CLOEXEC)
				++counted_cloexec;
			if (self->hm_linear.hm_vector[i].h_mode & IO_CLOFORK)
				++counted_clofork;
			++counted;
		}
	}
	assertf(self->hm_count == counted,
	        "self->hm_count(%u) != counted(%u)",
	        self->hm_count, counted);
	assertf(self->hm_cloexec_count == counted_cloexec,
	        "self->hm_cloexec_count(%u) != counted_cloexec(%u)",
	        self->hm_cloexec_count, counted_cloexec);
	assertf(self->hm_clofork_count == counted_clofork,
	        "self->hm_clofork_count(%u) != counted_clofork(%u)",
	        self->hm_clofork_count, counted_clofork);
}
#endif /* !NDEBUG */


PUBLIC NOBLOCK void
NOTHROW(KCALL handle_manager_destroy)(struct handle_manager *__restrict self) {
	unsigned int i;
	struct handle *vec = self->hm_linear.hm_vector;
	/* Close all handles that are still opened. */
	for (i = 0; i < self->hm_linear.hm_alloc; ++i) {
		assert(vec[i].h_type < HANDLE_TYPE_COUNT);
		if (vec[i].h_type != HANDLE_TYPE_UNDEFINED)
			decref(vec[i]);
	}
	/* Free data. */
	kfree(vec);
	if (self->hm_mode == HANDLE_MANAGER_MODE_HASHVECTOR)
		kfree(self->hm_hashvector.hm_hashvec);
	kfree(self);
}

#if HANDLE_TYPE_UNDEFINED == 0
LOCAL void KCALL
clear_unused_but_allocated_handle_vector_tail(struct handle *__restrict vector,
                                              unsigned int alloc) {
	size_t alloc_size, used_size;
	used_size  = alloc * sizeof(struct handle);
	alloc_size = kmalloc_usable_size(vector);
	assert(used_size <= alloc_size);
	/* The  handle manager relies  on the fact  that trailing memory within
	 * the handle  vector is  zero-initialized,  so that  future  realloc()
	 * calls  are  able to  extend  the vector,  and  already have  the new
	 * area   pre-initialized   by   passing   GFP_CALLOC   to   krealloc()
	 * However, if GFP_CALLOC wasn't passed during the original  allocation
	 * of the vector, then there might be some hidden portion of the vector
	 * that still contains  undefined memory  when kmalloc()  overallocated
	 * by a tiny amount.
	 * In this case, manually zero-initialize that portion of memory during
	 * the initial init.
	 * NOTE: This is only required when GFP_CALLOC wasn't used to allocate
	 *       the  original handle  vector, as  is the  case within CLONE() */
	bzero((byte_t *)vector + used_size, alloc_size - used_size);
}
#else /* HANDLE_TYPE_UNDEFINED == 0 */
#define clear_unused_but_allocated_handle_vector_tail(vector, alloc) (void)0
#endif /* HANDLE_TYPE_UNDEFINED != 0 */


/* Copy the given handle manager (exclusing `IO_CLOFORK' handles) */
PUBLIC ATTR_MALLOC ATTR_RETNONNULL REF struct handle_manager *KCALL
handle_manager_clone(struct handle_manager *__restrict self) THROWS(E_BADALLOC, E_WOULDBLOCK) {
	REF struct handle_manager *result;
	unsigned int cloexec_subtract; /* # of handles with both CLOFORK and CLOEXEC */
	result = (REF struct handle_manager *)kmalloc(sizeof(struct handle_manager),
	                                              GFP_NORMAL);
	result->hm_refcnt = 1;
	atomic_rwlock_init(&result->hm_lock);
	TRY {
		sync_read(&self->hm_lock);
	} EXCEPT {
		kfree(result);
		RETHROW();
	}
	assert(self->hm_minfree <= self->hm_count);
	assert(self->hm_clofork_count <= self->hm_count);
	assert(self->hm_cloexec_count <= self->hm_count);
	if (self->hm_clofork_count >= self->hm_count) {
set_empty_copy:
		cloexec_subtract            = 0;
		result->hm_mode             = HANDLE_MANAGER_MODE_LINEAR;
		result->hm_linear.hm_alloc  = 0;
		result->hm_linear.hm_vector = NULL;
		result->hm_minfree          = 0;
	} else {
		unsigned int i, minfree;
		unsigned int alloc;
		struct handle *vec, *srcvec;
		result->hm_hashvector.hm_hashvec = NULL;
again_check_changed:
		result->hm_mode  = self->hm_mode;
		alloc            = self->hm_linear.hm_alloc;
		cloexec_subtract = 0;
		for (;;) {
			assert(alloc != 0);
			if (self->hm_linear.hm_vector[alloc - 1].h_type != HANDLE_TYPE_UNDEFINED) {
				if (!(self->hm_linear.hm_vector[alloc - 1].h_mode & IO_CLOFORK))
					break;
				if (self->hm_linear.hm_vector[alloc - 1].h_mode & IO_CLOEXEC)
					++cloexec_subtract;
			}
			assert(alloc != 0);
			--alloc;
		}
		assert(alloc >= (self->hm_count - self->hm_clofork_count));
		vec = (struct handle *)kmalloc_nx(alloc * sizeof(struct handle),
		                                  GFP_PREFLT | GFP_ATOMIC);
		if (!vec) {
			unsigned int new_alloc;
			sync_endread(&self->hm_lock);
			TRY {
				vec = (struct handle *)kmalloc(alloc * sizeof(struct handle), GFP_PREFLT);
				TRY {
					sync_read(&self->hm_lock);
				} EXCEPT {
					kfree(vec);
					RETHROW();
				}
			} EXCEPT {
				kfree(result->hm_hashvector.hm_hashvec);
				kfree(result);
				RETHROW();
			}
check_new_alloc_linear:
			COMPILER_READ_BARRIER();
			if unlikely(self->hm_clofork_count >= self->hm_count) {
				kfree(result->hm_hashvector.hm_hashvec);
				DBG_memset(&result->hm_hashvector.hm_hashvec, 0xcc, sizeof(void *));
				kfree(vec);
				goto set_empty_copy;
			}
			cloexec_subtract = 0;
			new_alloc        = self->hm_linear.hm_alloc;
			for (;;) {
				assert(new_alloc != 0);
				if (self->hm_linear.hm_vector[new_alloc - 1].h_type != HANDLE_TYPE_UNDEFINED) {
					if (!(self->hm_linear.hm_vector[new_alloc - 1].h_mode & IO_CLOFORK))
						break;
					if (self->hm_linear.hm_vector[new_alloc - 1].h_mode & IO_CLOEXEC)
						++cloexec_subtract;
				}
				--new_alloc;
			}
			assert(new_alloc >= (self->hm_count - self->hm_clofork_count));
			if unlikely(new_alloc > alloc) {
				struct handle *new_vec;
				new_vec = (struct handle *)krealloc_nx(vec,
				                                       new_alloc * sizeof(struct handle),
				                                       GFP_PREFLT | GFP_ATOMIC);
				if unlikely(!new_vec) {
					sync_endread(&self->hm_lock);
					TRY {
						new_vec = (struct handle *)krealloc(vec,
						                                    new_alloc * sizeof(struct handle),
						                                    GFP_PREFLT);
						TRY {
							sync_read(&self->hm_lock);
						} EXCEPT {
							kfree(vec);
							RETHROW();
						}
					} EXCEPT {
						kfree(result->hm_hashvector.hm_hashvec);
						kfree(result);
						RETHROW();
					}
					vec   = new_vec;
					alloc = new_alloc;
					goto check_new_alloc_linear;
				}
				vec   = new_vec;
				alloc = new_alloc;
			}
		}

		clear_unused_but_allocated_handle_vector_tail(vec, alloc);
		result->hm_linear.hm_alloc  = alloc;
		result->hm_linear.hm_vector = vec;

		/* Copy all of the handles, and incref each of them. */
		srcvec  = self->hm_linear.hm_vector;
		minfree = alloc;
		for (i = 0; i < alloc; ++i) {
			vec[i] = srcvec[i];
			if (vec[i].h_mode & IO_CLOFORK) {
				if (vec[i].h_mode & IO_CLOEXEC)
					++cloexec_subtract;
				vec[i].h_type = HANDLE_TYPE_UNDEFINED;
				if (minfree > i)
					minfree = i;
			} else {
				incref(vec[i]);
			}
		}
		/* Check for hash-vector mode. */
		if (self->hm_mode != HANDLE_MANAGER_MODE_HASHVECTOR) {
			if (minfree > self->hm_minfree)
				minfree = self->hm_minfree;
			result->hm_minfree = minfree;
			DBG_memset(&result->hm_hashvector.hm_hashvec, 0xcc, sizeof(void *));
		} else {
			struct handle_hashent *map;
			unsigned int count;
			/* Must also copy `hm_hashvecs' */
			count                            = self->hm_hashvector.hm_hashmsk;
			result->hm_hashvector.hm_hashuse = self->hm_hashvector.hm_hashuse;
			if (minfree > self->hm_hashvector.hm_vecfree)
				minfree = self->hm_hashvector.hm_vecfree;
			result->hm_hashvector.hm_vecfree = minfree;
			if (result->hm_hashvector.hm_hashvec &&
			    count <= result->hm_hashvector.hm_hashmsk) {
				map = result->hm_hashvector.hm_hashvec;
				krealloc_in_place_nx(map, (count + 1) * sizeof(struct handle_hashent),
				                     GFP_PREFLT | GFP_ATOMIC);
			} else {
				count = self->hm_hashvector.hm_hashmsk;
				map = (struct handle_hashent *)krealloc_nx(result->hm_hashvector.hm_hashvec,
				                                           (count + 1) * sizeof(struct handle_hashent),
				                                           GFP_PREFLT | GFP_ATOMIC);
				if (!map) {
					/* Cannot allocate the map atomically (need to release the manager-lock, and allocate manually!) */
					sync_endread(&self->hm_lock);
					alloc = result->hm_linear.hm_alloc;
					vec   = result->hm_linear.hm_vector;
					DBG_memset(&result->hm_linear.hm_vector, 0xcc, sizeof(void *));
					while (alloc--)
						decref(vec[alloc]);
					kfree(vec);
					TRY {
						map = (struct handle_hashent *)krealloc(result->hm_hashvector.hm_hashvec,
						                                        (count + 1) * sizeof(struct handle_hashent),
						                                        GFP_PREFLT);
					} EXCEPT {
						kfree(result->hm_hashvector.hm_hashvec);
						kfree(result);
						RETHROW();
					}
					result->hm_hashvector.hm_hashvec = map;
					result->hm_hashvector.hm_hashmsk = count;
					goto again_check_changed;
				}
				result->hm_hashvector.hm_hashvec = map;
			}
			result->hm_hashvector.hm_hashmsk = count;
			memcpy(map,
			       self->hm_hashvector.hm_hashvec,
			       (size_t)count + 1,
			       sizeof(struct handle_hashent));
			result->hm_hashvector.hm_hashvec = map;
			result->hm_hashvector.hm_hashmsk = count;
			result->hm_minfree               = self->hm_minfree;
			if (self->hm_clofork_count) {
				/* Delete all entries referring to handles
				 * that  were  closed   due  to   forking. */
				for (i = 0; i <= count; ++i) {
					unsigned int vecid;
					if (map[i].hh_handle_id == HANDLE_HASHENT_SENTINEL_ID)
						continue;
					vecid = map[i].hh_vector_index;
					if (vecid == (unsigned int)-1) /* Already deleted. */
						continue;
					assertf(vecid < result->hm_hashvector.hm_alloc,
					        "vecid                          = %u\n"
					        "result->hm_hashvector.hm_alloc = %u\n"
					        "self->hm_hashvector.hm_alloc   = %u\n",
					        vecid, result->hm_hashvector.hm_alloc,
					        self->hm_hashvector.hm_alloc);
					if (result->hm_hashvector.hm_vector[vecid].h_type == HANDLE_TYPE_UNDEFINED) {
						if (result->hm_minfree > map[i].hh_handle_id)
							result->hm_minfree = map[i].hh_handle_id;
						/* Must delete this one! */
						map[i].hh_vector_index = (unsigned int)-1;
					}
				}
			}
		}
	}
	assert(cloexec_subtract <= self->hm_clofork_count);
	assert(cloexec_subtract <= self->hm_cloexec_count);
	result->hm_count         = self->hm_count - self->hm_clofork_count;
	result->hm_cloexec_count = self->hm_cloexec_count - cloexec_subtract;
	result->hm_cntlimit      = self->hm_cntlimit;
	result->hm_maxlimit      = self->hm_maxlimit;
	assert(self->hm_count <= self->hm_linear.hm_alloc);
	assert(result->hm_count <= result->hm_linear.hm_alloc);
	sync_endread(&self->hm_lock);
	result->hm_clofork_count = 0;
	clear_unused_but_allocated_handle_vector_tail(result->hm_linear.hm_vector,
	                                              result->hm_linear.hm_alloc);
	handle_manager_assert_integrity(result);
	return result;
}


/* The handle manager of the kernel itself. */
PUBLIC struct handle_manager handle_manager_kernel = {
	.hm_refcnt        = 4, /* `handle_manager_kernel', boottask, asyncwork, bootidle */
	.hm_lock          = ATOMIC_RWLOCK_INIT,
	.hm_cntlimit      = (unsigned int)-2,
	.hm_maxlimit      = (unsigned int)-2,
	.hm_count         = 0,
	.hm_minfree       = 0,
	.hm_mode          = HANDLE_MANAGER_MODE_LINEAR,
	.hm_clofork_count = 0,
	.hm_cloexec_count = 0,
	{
		.hm_linear = {
			.hm_alloc  = 0,
			.hm_vector = NULL
		}
	}
};
DEFINE_DBG_BZERO_OBJECT(handle_manager_kernel.hm_lock);
DEFINE_DBG_BZERO_IF(THIS_HANDLE_MANAGER != NULL,
                    &THIS_HANDLE_MANAGER->hm_lock,
                    sizeof(handle_manager_kernel.hm_lock));


/* [1..1][lock(PRIVATE(THIS_TASK))] Handle manager of the calling thread.
 * NOTE: Initialize changed to `NULL' in `kernel_initialize_scheduler_after_smp()' */
PUBLIC ATTR_PERTASK ATTR_ALIGN(struct handle_manager *)
this_handle_manager = &handle_manager_kernel;

DEFINE_PERTASK_FINI(fini_this_handle_manager);
INTERN NOBLOCK NONNULL((1)) void
NOTHROW(KCALL fini_this_handle_manager)(struct task *__restrict self) {
	xdecref(FORTASK(self, this_handle_manager));
}


#ifndef CONFIG_NO_SMP
/* Lock for accessing any remote thread's this_handle_manager field */
PRIVATE struct atomic_rwlock handle_manager_change_lock = ATOMIC_RWLOCK_INIT;
#endif /* !CONFIG_NO_SMP */

/* Return the handle manager of the given thread. */
PUBLIC NOBLOCK ATTR_RETNONNULL WUNUSED NONNULL((1)) REF struct handle_manager *
NOTHROW(FCALL task_gethandlemanager)(struct task *__restrict thread) {
	pflag_t was;
	REF struct handle_manager *result;
	was = PREEMPTION_PUSHOFF();
#ifndef CONFIG_NO_SMP
	while unlikely(!sync_tryread(&handle_manager_change_lock))
		task_pause();
#endif /* !CONFIG_NO_SMP */
	assert(FORTASK(thread, this_handle_manager));
	result = incref(FORTASK(thread, this_handle_manager));
#ifndef CONFIG_NO_SMP
	sync_endread(&handle_manager_change_lock);
#endif /* !CONFIG_NO_SMP */
	PREEMPTION_POP(was);
	return result;
}

/* Exchange the handle manager of the calling thread. */
PUBLIC ATTR_RETNONNULL WUNUSED NONNULL((1)) REF struct handle_manager *
NOTHROW(FCALL task_sethandlemanager)(struct handle_manager *__restrict newman) {
	pflag_t was;
	REF struct handle_manager *result;
	was = PREEMPTION_PUSHOFF();
#ifndef CONFIG_NO_SMP
	while unlikely(!sync_trywrite(&handle_manager_change_lock))
		task_pause();
#endif /* !CONFIG_NO_SMP */
	result = PERTASK_GET(this_handle_manager);
	incref(newman);
	PERTASK_SET(this_handle_manager, newman);
#ifndef CONFIG_NO_SMP
	sync_endwrite(&handle_manager_change_lock);
#endif /* !CONFIG_NO_SMP */
	PREEMPTION_POP(was);
	assert(result);
	return result;
}



DEFINE_PERMMAN_ONEXEC(handler_manager_onexec);
PRIVATE ATTR_USED void KCALL handler_manager_onexec(void) {
	handle_manager_cloexec(THIS_HANDLE_MANAGER);
}

/* Close all handles with the `IO_FCLOEXEC' flag set.
 * @throw: E_WOULDBLOCK: Preemption was disabled, and the operation would have blocked. */
PUBLIC NONNULL((1)) void FCALL
handle_manager_cloexec(struct handle_manager *__restrict self)
		THROWS(E_WOULDBLOCK) {
	unsigned int i, cloexec_count = 0;
	unsigned int minfree         = (unsigned int)-1;
	struct handle *delete_vector = NULL;
	struct handle *vec;
	/* TODO:
	 * """
	 *    If a process sharing a file descriptor table calls
	 *    execve(2), its file descriptor table is duplicated
	 *    (unshared).
	 * """
	 */

	if (!ATOMIC_READ(self->hm_cloexec_count))
		return;
	sync_write(&self->hm_lock);
	if (!ATOMIC_READ(self->hm_cloexec_count))
		goto done;
	handle_manager_assert_integrity(self);
	cloexec_count = self->hm_cloexec_count;
	if unlikely(cloexec_count >= self->hm_count) {
		unsigned int alloc;
		struct handle_hashent *hashvec = NULL;
		assert(self->hm_clofork_count <= self->hm_cloexec_count);
		/* We an just close everything! */
		vec   = self->hm_linear.hm_vector;
		alloc = self->hm_linear.hm_alloc;
		self->hm_cloexec_count    = 0;
		self->hm_clofork_count    = 0;
		self->hm_count            = 0;
		self->hm_minfree          = 0;
		self->hm_linear.hm_vector = NULL;
		self->hm_linear.hm_alloc  = 0;
		if (self->hm_mode == HANDLE_MANAGER_MODE_HASHVECTOR) {
			hashvec = self->hm_hashvector.hm_hashvec;
			DBG_memset(&self->hm_hashvector.hm_hashvec, 0xcc, sizeof(void *));
			DBG_memset(&self->hm_hashvector.hm_hashmsk, 0xcc, sizeof(unsigned int));
			DBG_memset(&self->hm_hashvector.hm_hashuse, 0xcc, sizeof(unsigned int));
			DBG_memset(&self->hm_hashvector.hm_vecfree, 0xcc, sizeof(unsigned int));
			self->hm_mode = HANDLE_MANAGER_MODE_LINEAR;
		}
		sync_endwrite(&self->hm_lock);
		kfree(hashvec);
		/* Close all handles that are still opened. */
		for (i = 0; i < alloc; ++i) {
			assert(vec[i].h_type < HANDLE_TYPE_COUNT);
			if (vec[i].h_type != HANDLE_TYPE_UNDEFINED)
				decref(vec[i]);
		}
		/* Free the handle vector. */
		kfree(vec);
		return;
	}

	/* NOTE: It's OK if this allocation fails. - decref() must be NOBLOCK, so  we
	 *       can theoretically even invoke it whilst holding a lock to `hm_lock'.
	 *       However, it may be less efficient to do so, so we try not to... */
	delete_vector = (struct handle *)kmalloc_nx(cloexec_count * sizeof(struct handle),
	                                            GFP_PREFLT | GFP_ATOMIC);
	cloexec_count = 0;
	vec   = self->hm_linear.hm_vector;
	for (i = 0; i < self->hm_linear.hm_alloc; ++i) {
		if (!(vec[i].h_mode & IO_CLOEXEC))
			continue;
		if (vec[i].h_type == HANDLE_TYPE_UNDEFINED)
			continue;
		if likely(delete_vector) {
			assert(cloexec_count < self->hm_cloexec_count);
			delete_vector[cloexec_count] = vec[i];
		} else {
			decref(vec[i]);
		}
		vec[i].h_type = HANDLE_TYPE_UNDEFINED;
		if (minfree > i)
			minfree = i;
		++cloexec_count;
	}
	assert(cloexec_count == self->hm_cloexec_count);
	if (self->hm_mode != HANDLE_MANAGER_MODE_HASHVECTOR) {
		if (self->hm_minfree > minfree)
			self->hm_minfree = minfree;
	} else {
		if (self->hm_hashvector.hm_vecfree > minfree)
			self->hm_hashvector.hm_vecfree = minfree;
		/* Delete hash-vector entries for closed handles. */
		for (i = 0; i <= self->hm_hashvector.hm_hashmsk; ++i) {
			struct handle_hashent *ent;
			unsigned int idx;
			ent = &self->hm_hashvector.hm_hashvec[i];
			if (ent->hh_handle_id == HANDLE_HASHENT_SENTINEL_ID)
				continue;
			idx = ent->hh_vector_index;
			if (idx == (unsigned int)-1)
				continue; /* Already deleted. */
			if (self->hm_hashvector.hm_vector[idx].h_type == HANDLE_TYPE_UNDEFINED) {
				if (self->hm_minfree > ent->hh_handle_id)
					self->hm_minfree = ent->hh_handle_id;
				ent->hh_vector_index = (unsigned int)-1; /* This one _we_ just closed! */
			}
		}
	}
	assert(cloexec_count == self->hm_cloexec_count);
	self->hm_count -= cloexec_count;
	self->hm_cloexec_count = 0;
done:
	handle_manager_assert_integrity(self);
	sync_endwrite(&self->hm_lock);
	if (delete_vector) {
		while (cloexec_count--)
			decref(delete_vector[cloexec_count]);
		kfree(delete_vector);
	}
}


PRIVATE NOBLOCK void
NOTHROW(FCALL handle_manager_rebind_indirect)(struct handle_manager *__restrict self,
                                              unsigned int old_ind_index,
                                              unsigned int new_ind_index) {
	unsigned int i;
	assert(self->hm_mode == HANDLE_MANAGER_MODE_HASHVECTOR);
	for (i = 0;; ++i) {
		assertf(i <= self->hm_hashvector.hm_hashmsk,
		        "Indirection not found (%u -> %u)",
		        old_ind_index, new_ind_index);
		if (self->hm_hashvector.hm_hashvec[i].hh_handle_id == HANDLE_HASHENT_SENTINEL_ID)
			continue;
		if (self->hm_hashvector.hm_hashvec[i].hh_vector_index != old_ind_index)
			continue;
		/* Found it! */
		self->hm_hashvector.hm_hashvec[i].hh_vector_index = new_ind_index;
		break;
	}
}

PRIVATE NOBLOCK void
NOTHROW(FCALL handle_manager_flatten_handle_vector)(struct handle_manager *__restrict self) {
	/* Try to re-bind handle mappings, so-as not to leave any unused entries. */
	unsigned int dst_index = 0; /* Target index. */
	unsigned int src_index = 0; /* Origin index. */
	struct handle *vec;
	vec = self->hm_hashvector.hm_vector;
	for (;;) {
		while (src_index < self->hm_hashvector.hm_alloc &&
		       vec[src_index].h_type == HANDLE_TYPE_UNDEFINED)
			++src_index;
		if (src_index >= self->hm_hashvector.hm_alloc)
			break;
		if (dst_index != src_index) {
			vec[dst_index] = vec[src_index];
			handle_manager_rebind_indirect(self, src_index, dst_index);
		}
		++dst_index;
	}
	/* Free unused trailing memory. */
	assertf(dst_index == self->hm_count,
	        "dst_index      = %u\n"
	        "self->hm_count = %u\n",
	        dst_index, self->hm_count);
	assert(dst_index != 0);
	assert(src_index <= self->hm_hashvector.hm_alloc);
	vec = (struct handle *)krealloc_nx(vec, dst_index * sizeof(struct handle),
	                                   GFP_PREFLT | GFP_ATOMIC
#if HANDLE_TYPE_UNDEFINED == 0
	                                   |
	                                   GFP_CALLOC
#endif /* HANDLE_TYPE_UNDEFINED == 0 */
	                                   );
	if likely(vec) {
		self->hm_hashvector.hm_vector = vec;
		self->hm_hashvector.hm_alloc  = dst_index;
	} else {
		vec = self->hm_hashvector.hm_vector;
		memset(&vec[dst_index], HANDLE_TYPE_UNDEFINED & 0xff,
		       (self->hm_hashvector.hm_alloc - dst_index) *
		       sizeof(struct handle));
	}
	self->hm_hashvector.hm_vecfree = dst_index;
}


PRIVATE NOBLOCK void
NOTHROW(FCALL handle_manager_try_downhash)(struct handle_manager *__restrict self) {
	unsigned int new_mask;
	assert(self->hm_mode == HANDLE_MANAGER_MODE_HASHVECTOR);
	assert(self->hm_count != 0);
	new_mask = self->hm_hashvector.hm_hashmsk >> 1;
	if (new_mask > (self->hm_count * 3) / 2) {
		/* Yes. - Try to re-hash */
		struct handle_hashent *new_hashvec;
		unsigned int i, j, perturb;
		unsigned int max_fd_number;
		new_hashvec = (struct handle_hashent *)kmalloc_nx((new_mask + 1) *
		                                                  sizeof(struct handle_hashent),
		                                                  GFP_PREFLT | GFP_ATOMIC);
		if (!new_hashvec)
			goto check_truncate_hashvec;
		/* Fill the new hash-vector with all 0xff (which causes all handle ids
		 * to become  `HANDLE_HASHENT_SENTINEL_ID',  indicating  availability) */
		memset(new_hashvec, 0xff, (new_mask + 1) * sizeof(struct handle_hashent));

		/* Re-hash the current handle vector. */
		max_fd_number = 0;
		for (i = 0; i <= self->hm_hashvector.hm_hashmsk; ++i) {
			struct handle_hashent ent;
			ent = self->hm_hashvector.hm_hashvec[i];
			if (ent.hh_handle_id == HANDLE_HASHENT_SENTINEL_ID)
				continue; /* Unused entry. */
			if (ent.hh_vector_index == (unsigned int)-1)
				continue; /* Deleted entry. */
			/* Keep track of the max FD number, so we can decide
			 * if  we  wish  to  switch  over  to  linear  mode. */
			if (max_fd_number < ent.hh_vector_index)
				max_fd_number = ent.hh_vector_index;
			j = perturb = ent.hh_vector_index & new_mask;
			for (;; handle_manager_hashnext(j, perturb)) {
				struct handle_hashent *destent;
				destent = &new_hashvec[j & new_mask];
				if (destent->hh_handle_id != HANDLE_HASHENT_SENTINEL_ID)
					continue;
				*destent = ent;
				break;
			}
		}

		if (max_fd_number <= self->hm_hashvector.hm_alloc + 31) {
			/* We should totally try to switch over to linear mode! */
			struct handle *linvec;
			linvec = (struct handle *)krealloc_nx(new_hashvec,
			                                      (max_fd_number + 1) * sizeof(struct handle),
			                                      GFP_PREFLT | GFP_ATOMIC
#if HANDLE_TYPE_UNDEFINED == 0
			                                      |
			                                      GFP_CALLOC
#endif
			                                      );
			if likely(linvec) {
				unsigned int i;
				/* Fill this vector with all of the used handles. */
				for (i = 0; i <= max_fd_number; ++i) {
					j = perturb = i & self->hm_hashvector.hm_hashmsk;
					for (;; handle_manager_hashnext(j, perturb)) {
						struct handle_hashent ent;
						ent = self->hm_hashvector.hm_hashvec[j & self->hm_hashvector.hm_hashmsk];
						if (ent.hh_handle_id == HANDLE_HASHENT_SENTINEL_ID)
							continue;
						if (ent.hh_vector_index == (unsigned int)-1) {
							linvec[i].h_type = HANDLE_TYPE_UNDEFINED;
						} else {
							linvec[i] = self->hm_hashvector.hm_vector[ent.hh_vector_index];
						}
						break;
					}
				}
				kfree(self->hm_hashvector.hm_hashvec);
				DBG_memset(&self->hm_hashvector.hm_hashvec, 0xcc, sizeof(void *));
				kfree(self->hm_hashvector.hm_vector);
				self->hm_mode             = HANDLE_MANAGER_MODE_LINEAR;
				self->hm_linear.hm_alloc  = max_fd_number + 1;
				self->hm_linear.hm_vector = linvec;
				return;
			}
		}
		kfree(self->hm_hashvector.hm_hashvec);
		self->hm_hashvector.hm_hashvec = new_hashvec;
		self->hm_hashvector.hm_hashmsk = new_mask;
		/* All of the deleted handles have been removed, meaning  that
		 * the amount of used entries now matches the amount of mapped
		 * handles. */
		self->hm_hashvector.hm_hashuse = self->hm_count;
	}
check_truncate_hashvec:
	assert(self->hm_hashvector.hm_alloc >= self->hm_count);
	/* Try to re-bind handle mappings, so-as not to leave any unused entries. */
	if (self->hm_hashvector.hm_alloc >= self->hm_count + 32)
		handle_manager_flatten_handle_vector(self);
}



/* Try to close the handle associated with `fd'.
 * @return: true:  The handle under `fd' was closed.
 * @return: false: No handle was associated with `fd'.
 * @throw: E_WOULDBLOCK: Preemption was disabled, and the operation would have blocked. */
PUBLIC NONNULL((2)) bool FCALL
handle_tryclose_nosym(unsigned int fd,
                      struct handle_manager *__restrict self)
		THROWS(E_WOULDBLOCK) {
	bool result = false;
	struct handle *ent;
	struct handle delete_handle;
	sync_write(&self->hm_lock);
	if (self->hm_mode == HANDLE_MANAGER_MODE_LINEAR) {
		if (fd < self->hm_linear.hm_alloc) {
			ent = &self->hm_linear.hm_vector[fd];
			if (ent->h_type != HANDLE_TYPE_UNDEFINED) {
				delete_handle = *ent;
				ent->h_type   = HANDLE_TYPE_UNDEFINED;
do_delete_handle:
				/* Update handle counters. */
				assert(self->hm_count);
				--self->hm_count;
				if (delete_handle.h_mode & IO_CLOEXEC) {
					assert(self->hm_cloexec_count);
					--self->hm_cloexec_count;
				}
				if (delete_handle.h_mode & IO_CLOFORK) {
					assert(self->hm_clofork_count);
					--self->hm_clofork_count;
				}
				if unlikely(!self->hm_count) {
					assert(self->hm_clofork_count == 0);
					assert(self->hm_cloexec_count == 0);
					/* Free the vector if all elements are now gone. */
					if (self->hm_mode == HANDLE_MANAGER_MODE_HASHVECTOR) {
						kfree(self->hm_hashvector.hm_hashvec);
						DBG_memset(&self->hm_hashvector.hm_hashvec, 0xcc, sizeof(void *));
						self->hm_mode = HANDLE_MANAGER_MODE_LINEAR;
					}
					kfree(self->hm_linear.hm_vector);
					self->hm_linear.hm_alloc  = 0;
					self->hm_linear.hm_vector = NULL;
				} else if (self->hm_mode == HANDLE_MANAGER_MODE_LINEAR) {
					assert(self->hm_linear.hm_alloc >= self->hm_count);
					if (self->hm_linear.hm_alloc >= self->hm_count + 16) {
						/* Check if we can free trailing entries. */
						unsigned int new_alloc = self->hm_linear.hm_alloc;
						while (self->hm_linear.hm_vector[new_alloc - 1].h_type == HANDLE_TYPE_UNDEFINED) {
							assert(new_alloc != 0);
							--new_alloc;
						}
						if (new_alloc != self->hm_linear.hm_alloc) {
							struct handle *new_vec;
							assert(self->hm_count <= new_alloc);
							/* Try to free trailing memory. */
							new_vec = (struct handle *)krealloc_nx(self->hm_linear.hm_vector,
							                                       new_alloc * sizeof(struct handle),
							                                       GFP_PREFLT | GFP_ATOMIC
#if HANDLE_TYPE_UNDEFINED == 0
							                                       |
							                                       GFP_CALLOC
#endif
							                                       );
							if (new_vec) {
								self->hm_linear.hm_vector = new_vec;
								self->hm_linear.hm_alloc  = new_alloc;
							}
						}
					}
				}
				/* Keep track of the lowest free handle slot. */
				if (self->hm_minfree > fd)
					self->hm_minfree = fd;
				assert(self->hm_count <= self->hm_linear.hm_alloc);
				sync_endwrite(&self->hm_lock);
				decref(delete_handle);
				result = true;
				goto done;
			}
		}
	} else {
		unsigned int i, perturb;
		assert(self->hm_mode == HANDLE_MANAGER_MODE_HASHVECTOR);
		assert(self->hm_hashvector.hm_hashvec);
		i = perturb = fd & self->hm_hashvector.hm_hashmsk;
		for (;; handle_manager_hashnext(i, perturb)) {
			struct handle_hashent *hashent;
			unsigned int vecid;
			hashent = &self->hm_hashvector.hm_hashvec[i & self->hm_hashvector.hm_hashmsk];
			if (hashent->hh_handle_id == HANDLE_HASHENT_SENTINEL_ID)
				break; /* Unbound handle. */
			if (hashent->hh_handle_id != fd)
				continue; /* Some other handle. */
			/* Found it! */
			vecid = hashent->hh_vector_index;
			if (vecid == (unsigned int)-1) {
				/* Handle has already been deleted! */
			} else {
				ent = &self->hm_hashvector.hm_vector[vecid];
				assert(ent->h_type != HANDLE_TYPE_UNDEFINED);
				hashent->hh_vector_index = (unsigned int)-1;
				assert(self->hm_hashvector.hm_hashuse != 0);
				--self->hm_hashvector.hm_hashuse;
				delete_handle = *ent;
				ent->h_type   = HANDLE_TYPE_UNDEFINED;
				if (self->hm_hashvector.hm_vecfree > vecid)
					self->hm_hashvector.hm_vecfree = vecid;
				handle_manager_try_downhash(self);
				goto do_delete_handle;
			}
			break;
		}
	}
	sync_endwrite(&self->hm_lock);
done:
	return result;
}

PRIVATE NOBLOCK ATTR_NOINLINE ATTR_PURE WUNUSED NONNULL((1)) unsigned int
NOTHROW(FCALL handle_manager_get_max_linear_fd_plus_one)(struct handle_manager const *__restrict self) {
	unsigned int result = self->hm_linear.hm_alloc;
	while (result && self->hm_linear.hm_vector[result - 1].h_type == HANDLE_TYPE_UNDEFINED)
		--result;
	return result;
}

PRIVATE NOBLOCK ATTR_NOINLINE ATTR_PURE WUNUSED NONNULL((1)) unsigned int
NOTHROW(FCALL handle_manager_get_max_hashvector_fd_plus_one)(struct handle_manager const *__restrict self) {
	unsigned int result = 0;
	unsigned int i, mask;
	struct handle_hashent *map;
	map  = self->hm_hashvector.hm_hashvec;
	mask = self->hm_hashvector.hm_hashmsk;
	for (i = 0; i <= mask; ++i) {
		unsigned int fdno;
		if (map[i].hh_handle_id == HANDLE_HASHENT_SENTINEL_ID)
			continue;
		fdno = map[i].hh_vector_index;
		if (fdno != (unsigned int)-1) {
			if (result <= fdno)
				result = fdno + 1;
		}
	}
	return result;
}

PRIVATE NOBLOCK ATTR_PURE WUNUSED NONNULL((1)) bool
NOTHROW(FCALL handle_manager_hashvector_isvalid)(struct handle_manager const *__restrict self,
                                                 unsigned int fd,
                                                 struct handle *p_hand) {
	unsigned int i, perturb;
	assert(self->hm_mode == HANDLE_MANAGER_MODE_HASHVECTOR);
	assert(self->hm_hashvector.hm_hashvec);
	i = perturb = fd & self->hm_hashvector.hm_hashmsk;
	for (;; handle_manager_hashnext(i, perturb)) {
		struct handle_hashent *hashent;
		hashent = &self->hm_hashvector.hm_hashvec[i & self->hm_hashvector.hm_hashmsk];
		if (hashent->hh_handle_id == HANDLE_HASHENT_SENTINEL_ID)
			break; /* end-of-chain */
		if (hashent->hh_handle_id != fd)
			continue; /* Some other handle. */
		if (p_hand)
			*p_hand = self->hm_hashvector.hm_vector[hashent->hh_vector_index];
		/* Found it! */
		return true;
	}
	return false;
}


/* Same as `handle_tryclose()', but throw an error if the given `fd' is invalid */
PUBLIC NONNULL((2)) void FCALL
handle_close_nosym(unsigned int fd,
                   struct handle_manager *__restrict self)
		THROWS(E_WOULDBLOCK, E_INVALID_HANDLE_FILE) {
	struct handle *ent;
	struct handle delete_handle;
	sync_write(&self->hm_lock);
	handle_manager_assert_integrity(self);
	if (self->hm_mode == HANDLE_MANAGER_MODE_LINEAR) {
		if unlikely(fd >= self->hm_linear.hm_alloc) {
			unsigned int fd_max   = handle_manager_get_max_linear_fd_plus_one(self);
			unsigned int fd_limit = self->hm_maxlimit;
			COMPILER_READ_BARRIER();
			sync_endwrite(&self->hm_lock);
			THROW(E_INVALID_HANDLE_FILE,
			      fd,
			      fd > fd_limit ? E_INVALID_HANDLE_FILE_ILLEGAL
			                    : E_INVALID_HANDLE_FILE_UNALLOCATED,
			      fd_max, fd_limit);
		}
		ent = &self->hm_linear.hm_vector[fd];
		if unlikely(ent->h_type == HANDLE_TYPE_UNDEFINED) {
			unsigned int fd_max   = handle_manager_get_max_linear_fd_plus_one(self);
			unsigned int fd_limit = self->hm_maxlimit;
			COMPILER_READ_BARRIER();
			sync_endwrite(&self->hm_lock);
			THROW(E_INVALID_HANDLE_FILE,
			      fd,
			      E_INVALID_HANDLE_FILE_UNBOUND,
			      fd_max, fd_limit);
		}
		delete_handle = *ent;
		ent->h_type   = HANDLE_TYPE_UNDEFINED;
do_delete_handle:
		/* Update handle counters. */
		assert(self->hm_count);
		--self->hm_count;
		if (delete_handle.h_mode & IO_CLOEXEC) {
			assert(self->hm_cloexec_count);
			--self->hm_cloexec_count;
		}
		if (delete_handle.h_mode & IO_CLOFORK) {
			assert(self->hm_clofork_count);
			--self->hm_clofork_count;
		}
		if unlikely(!self->hm_count) {
			assert(self->hm_clofork_count == 0);
			assert(self->hm_cloexec_count == 0);
			/* Free the vector if all elements are now gone. */
			if (self->hm_mode == HANDLE_MANAGER_MODE_HASHVECTOR) {
				kfree(self->hm_hashvector.hm_hashvec);
				DBG_memset(&self->hm_hashvector.hm_hashvec, 0xcc, sizeof(void *));
				self->hm_mode = HANDLE_MANAGER_MODE_LINEAR;
			}
			kfree(self->hm_linear.hm_vector);
			self->hm_linear.hm_alloc  = 0;
			self->hm_linear.hm_vector = NULL;
		} else if (self->hm_mode == HANDLE_MANAGER_MODE_LINEAR) {
			assert(self->hm_count != 0);
			assert(self->hm_linear.hm_alloc >= self->hm_count);
			if (self->hm_linear.hm_alloc >= self->hm_count + 16) {
				/* Check if we can free trailing entries. */
				unsigned int new_alloc = self->hm_linear.hm_alloc;
				while (self->hm_linear.hm_vector[new_alloc - 1].h_type == HANDLE_TYPE_UNDEFINED) {
					assert(new_alloc != 0);
					--new_alloc;
				}
				if (new_alloc != self->hm_linear.hm_alloc) {
					struct handle *new_vec;
					assert(self->hm_count <= new_alloc);
					/* Try to free trailing memory. */
					new_vec = (struct handle *)krealloc_nx(self->hm_linear.hm_vector,
					                                       new_alloc * sizeof(struct handle),
					                                       GFP_ATOMIC);
					if (new_vec) {
						self->hm_linear.hm_vector = new_vec;
						self->hm_linear.hm_alloc  = new_alloc;
					}
				}
			}
		}
		/* Keep track of the lowest free handle slot. */
		if (self->hm_minfree > fd)
			self->hm_minfree = fd;
		handle_manager_assert_integrity(self);
		sync_endwrite(&self->hm_lock);
		decref(delete_handle);
	} else {
		unsigned int i, perturb;
		assert(self->hm_mode == HANDLE_MANAGER_MODE_HASHVECTOR);
		assert(self->hm_hashvector.hm_hashvec);
		i = perturb = fd & self->hm_hashvector.hm_hashmsk;
		for (;; handle_manager_hashnext(i, perturb)) {
			struct handle_hashent *hashent;
			unsigned int vecid;
			hashent = &self->hm_hashvector.hm_hashvec[i & self->hm_hashvector.hm_hashmsk];
			if (hashent->hh_handle_id == HANDLE_HASHENT_SENTINEL_ID) {
				unsigned int fd_max, fd_limit;
				fd_limit = self->hm_maxlimit;
				fd_max   = handle_manager_get_max_hashvector_fd_plus_one(self);
				COMPILER_READ_BARRIER();
				sync_endwrite(&self->hm_lock);
				/* Unbound handle. */
				THROW(E_INVALID_HANDLE_FILE,
				      fd,
				      fd > fd_limit ? E_INVALID_HANDLE_FILE_ILLEGAL : fd >= fd_max ? E_INVALID_HANDLE_FILE_UNALLOCATED : E_INVALID_HANDLE_FILE_UNBOUND,
				      fd_max,
				      fd_limit);
			}
			if (hashent->hh_handle_id != fd)
				continue; /* Some other handle. */
			/* Found it! */
			vecid = hashent->hh_vector_index;
			if (vecid == (unsigned int)-1) {
				/* Handle has already been deleted! */
				unsigned int fd_max, fd_limit;
				fd_limit = self->hm_maxlimit;
				fd_max   = handle_manager_get_max_hashvector_fd_plus_one(self);
				COMPILER_READ_BARRIER();
				sync_endwrite(&self->hm_lock);
				THROW(E_INVALID_HANDLE_FILE,
				      fd,
				      fd > fd_limit ? E_INVALID_HANDLE_FILE_ILLEGAL
				                    : E_INVALID_HANDLE_FILE_UNBOUND,
				      fd_max,
				      fd_limit);
			} else {
				ent = &self->hm_hashvector.hm_vector[vecid];
				assert(ent->h_type != HANDLE_TYPE_UNDEFINED);
				hashent->hh_vector_index = (unsigned int)-1;
				delete_handle = *ent;
				ent->h_type   = HANDLE_TYPE_UNDEFINED;
				if (self->hm_hashvector.hm_vecfree > vecid)
					self->hm_hashvector.hm_vecfree = vecid;
				handle_manager_try_downhash(self);
				goto do_delete_handle;
			}
			__builtin_unreachable();
		}
		__builtin_unreachable();
	}
}

/* Close all open file handles `>= startfd' and return how many were actually closed.
 * If  nothing  was closed  at  all (i.e.  what  would be  `return == 0'),  then this
 * function  returns  by  throwing  an  `E_INVALID_HANDLE_FILE'  (-EBADF)  exception. */
PUBLIC NONNULL((2)) unsigned int FCALL
handle_closefrom_nosym(unsigned int startfd,
                       struct handle_manager *__restrict self)
		THROWS(E_WOULDBLOCK, E_INVALID_HANDLE_FILE) {
	unsigned int result;
	struct handle *vec;
	struct handle_hashent *hashvec = NULL;
	unsigned int cnt;
	sync_write(&self->hm_lock);
	/* Special case: No files are open */
	if unlikely(!self->hm_count) {
		unsigned int fd_limit;
		fd_limit = self->hm_maxlimit;
		sync_endwrite(&self->hm_lock);
		THROW(E_INVALID_HANDLE_FILE,
		      startfd,
		      E_INVALID_HANDLE_FILE_UNALLOCATED,
		      0,
		      fd_limit);
	}
	if unlikely(startfd == 0) {
		/* Simple (but special) case: Close _all_ _files_ */
		vec = self->hm_linear.hm_vector;
		cnt = self->hm_linear.hm_alloc;
		if (self->hm_mode != HANDLE_MANAGER_MODE_LINEAR)
			hashvec = self->hm_hashvector.hm_hashvec;
		result = self->hm_count;
		self->hm_count            = 0;
		self->hm_minfree          = 0;
		self->hm_clofork_count    = 0;
		self->hm_cloexec_count    = 0;
		self->hm_mode             = HANDLE_MANAGER_MODE_LINEAR;
		self->hm_linear.hm_alloc  = 0;
		self->hm_linear.hm_vector = NULL;
		sync_endwrite(&self->hm_lock);
	} else {
		/* Only close files after a certain point. */
		sync_endwrite(&self->hm_lock);
#if 1 /* Really ugly implementation. - An atomic approach would be better... */
		cnt    = 0;
		vec    = NULL;
		result = 0;
		for (;;) {
			unsigned int fd;
again_scan:
			fd = startfd;
			for (;;) {
				unsigned int next;
				TRY {
					/* Find the next open fd >= startfd */
					next = handle_nextfd(fd, self);
				} EXCEPT {
					if (!was_thrown(E_INVALID_HANDLE)) {
						if (fd == startfd)
							goto done; /* No more handles >= startfd */
						/* Check again  if we're  missed something,  or
						 * if another thread  created a  new handle  in
						 * the mean time (this is the part I don't like
						 * about the current implementation: it's  non-
						 * atomic when it could actually be atomic) */
						goto again_scan;
					}
					RETHROW();
				}
				/* Try to close the handle */
				if (handle_tryclose_nosym(next, self))
					++result;
				/* Continue by trying to close the next handle. */
				fd = next + 1;
			}
		}
done:
		;
#endif
	}
	assert(!cnt || vec);
	while (cnt) {
		--cnt;
		decref(vec[cnt]);
	}
	kfree(vec);
	kfree(hashvec);
	return result;
}

/* Return the next valid FD that is `>= startfd'
 * If no such FD exists, throw an `E_INVALID_HANDLE_FILE' exception */
PUBLIC NONNULL((2)) unsigned int FCALL
handle_nextfd(unsigned int startfd,
              struct handle_manager *__restrict self)
		THROWS(E_WOULDBLOCK, E_INVALID_HANDLE_FILE) {
	unsigned int result;
	sync_read(&self->hm_lock);
	if (self->hm_mode == HANDLE_MANAGER_MODE_LINEAR) {
		result = startfd;
		for (;;) {
			if unlikely(result >= self->hm_linear.hm_alloc) {
				unsigned int fd_limit;
throw_f_next_unallocated:
				fd_limit = self->hm_maxlimit;
				sync_endread(&self->hm_lock);
				THROW(E_INVALID_HANDLE_FILE,
				      0,
				      E_INVALID_HANDLE_FILE_UNALLOCATED,
				      result,
				      fd_limit);
			}
			if (self->hm_linear.hm_vector[result].h_type != HANDLE_TYPE_UNDEFINED)
				break; /* This one's in use! */
			++result;
		}
	} else if (handle_manager_hashvector_isvalid(self, startfd, NULL)) {
		/* Simple (and  pretty likely)  case: the  given FD  exists.
		 * Given  the use case  of this fcntl  to iterate over one's
		 * file descriptor table to find  open files, and given  the
		 * possibility that `fd - 1' had already been tested before,
		 * then it stands to reason  that some cluster of  allocated
		 * files has a size that is greater than 1:
		 * >> int fd = -1;
		 * >> while ((fd = fcntl(fd + 1, F_NEXT)) >= 0) {
		 * >>     printf("open fd: %d\n", fd);
		 * >> }
		 * Possible output:
		 *    open fd: 0
		 *    open fd: 1
		 *    open fd: 2
		 *    open fd: 3
		 *    open fd: 4
		 */
		result = startfd;
	} else {
		unsigned int i, mask, max_fd;
		struct handle_hashent *map;
		/* The slow case: Must scan the entire hash-table to find:
		 *  - The lowest valid handle `>= fd'
		 *  - The greatest valid fd, period. (needed if we end up throwing an `E_INVALID_HANDLE_FILE')
		 */
		result = (unsigned int)-1;
		max_fd = 0;
		map  = self->hm_hashvector.hm_hashvec;
		mask = self->hm_hashvector.hm_hashmsk;
		/* Go through the FD table and  */
		for (i = 0; i <= mask; ++i) {
			if (map[i].hh_handle_id == HANDLE_HASHENT_SENTINEL_ID)
				continue;
			if (map[i].hh_vector_index != (unsigned int)-1) {
				unsigned int fdno = map[i].hh_handle_id;
				if (max_fd <= fdno)
					max_fd = fdno + 1;
				if (fdno >= startfd && fdno < result)
					result = fdno;
			}
		}
		if unlikely(result == (unsigned int)-1) {
			/* No valid handle found... */
			result = max_fd;
			goto throw_f_next_unallocated;
		}
	}
	sync_endread(&self->hm_lock);
	return result;
}

/* Same as `handle_nextfd()', but return `(unsigned int)-1' instead of throwing `E_INVALID_HANDLE_FILE'
 * @param: p_data: Filled with `HANDLE.h_data' (used for ino numbers in procfs) */
PUBLIC NONNULL((2, 3)) unsigned int FCALL
handle_trynextfd(unsigned int startfd,
                 struct handle_manager *__restrict self,
                 void **__restrict p_data)
		THROWS(E_WOULDBLOCK) {
	unsigned int result;
	struct handle hand;
	sync_read(&self->hm_lock);
	result = handle_trynextfd_locked(startfd, self, &hand);
	if (result != (unsigned int)-1)
		*p_data = hand.h_data;
	sync_endread(&self->hm_lock);
	return result;
}

PUBLIC NONNULL((2, 3)) unsigned int
NOTHROW(FCALL handle_trynextfd_locked)(unsigned int startfd,
                                       struct handle_manager *__restrict self,
                                       struct handle *__restrict phand) {
	unsigned int result;
	if (self->hm_mode == HANDLE_MANAGER_MODE_LINEAR) {
		result = startfd;
		for (;;) {
			if unlikely(result >= self->hm_linear.hm_alloc)
				return (unsigned int)-1;
			if (self->hm_linear.hm_vector[result].h_type != HANDLE_TYPE_UNDEFINED) {
				*phand = self->hm_linear.hm_vector[result];
				break; /* This one's in use! */
			}
			++result;
		}
	} else if (handle_manager_hashvector_isvalid(self, startfd, phand)) {
		result = startfd;
	} else {
		unsigned int i, mask;
		struct handle_hashent *map;
		/* The slow case: Must scan the entire hash-table to find:
		 *  - The lowest valid handle `>= fd'
		 *  - The greatest valid fd, period. (needed if we end up throwing an `E_INVALID_HANDLE_FILE')
		 */
		result = (unsigned int)-1;
		map  = self->hm_hashvector.hm_hashvec;
		mask = self->hm_hashvector.hm_hashmsk;
		/* Go through the FD table and  */
		for (i = 0; i <= mask; ++i) {
			if (map[i].hh_handle_id == HANDLE_HASHENT_SENTINEL_ID)
				continue;
			if (map[i].hh_vector_index != (unsigned int)-1) {
				unsigned int fdno = map[i].hh_handle_id;
				if (fdno >= startfd && fdno < result) {
					result = fdno;
					*phand = self->hm_hashvector.hm_vector[map[i].hh_vector_index];
				}
			}
		}
	}
	return result;
}




/* The manager is kept in linear mode (the caller's lock is also kept) */
#define HANDLE_MANAGE_SWITCH_TO_HASHMODE_FOR_HANDLE_NOT_CHANGED_LOCKED   0 /* The caller's lock was kept the entire time */
#define HANDLE_MANAGE_SWITCH_TO_HASHMODE_FOR_HANDLE_NOT_CHANGED_UNLOCKED 1 /* The caller's lock was lost temporarily */
/* The manager was switched to hash-vector mode */
#define HANDLE_MANAGE_SWITCH_TO_HASHMODE_FOR_HANDLE_CHANGED_LOCKED       2 /* The caller's lock was kept the entire time */
#define HANDLE_MANAGE_SWITCH_TO_HASHMODE_FOR_HANDLE_CHANGED_UNLOCKED     3 /* The caller's lock was lost temporarily */


/* Switch operations mode to hash-vector for `self'
 * The caller is required to be holding a write-lock before calling this function.
 * The given `handle_number' is the handle which caused the question of change  to
 * be brought up, and it is this function's decision if the change should happen.
 * @return: * : One of `HANDLE_MANAGE_SWITCH_TO_HASHMODE_FOR_HANDLE_*'
 * NOTE: When this function returns by throwing an exception, the caller's lock
 *       will have already been lost! */
PRIVATE unsigned int FCALL
handle_manage_switch_to_hashmode_for_handle(struct handle_manager *__restrict self,
                                            unsigned int handle_number)
		THROWS(E_WOULDBLOCK, E_BADALLOC) {
	assert(sync_writing(&self->hm_lock));
	assert(self->hm_mode == HANDLE_MANAGER_MODE_LINEAR);
	/* Check if the switch is actually necessary to prevent wasting memory. */
	if likely((handle_number <= self->hm_linear.hm_alloc + 64) &&
	          (self->hm_count + 1) > (handle_number / 4)) {
		return HANDLE_MANAGE_SWITCH_TO_HASHMODE_FOR_HANDLE_NOT_CHANGED_LOCKED;
	} else {
		/* Figure out how large the hash-vector needs to be. */
		unsigned int used_mask, threshold;
		struct handle_hashent *map;
		unsigned int result, count, i, j, perturb;
		struct handle *vec;
		result    = HANDLE_MANAGE_SWITCH_TO_HASHMODE_FOR_HANDLE_CHANGED_LOCKED;
		count     = self->hm_count;
		used_mask = 1;
		threshold = (count * 3) / 2;
		while (used_mask <= threshold)
			used_mask = (used_mask << 1) | 1;
		/* Allocate the hash-vector. */
		map = (struct handle_hashent *)kmalloc_nx((used_mask + 1) *
		                                          sizeof(struct handle_hashent),
		                                          GFP_PREFLT | GFP_ATOMIC);
		if unlikely(!map) {
			/* Must unlock the manager to allocate the map. */
			sync_endwrite(&self->hm_lock);
			map = (struct handle_hashent *)kmalloc((used_mask + 1) *
			                                       sizeof(struct handle_hashent),
			                                       GFP_PREFLT);
			sync_write(&self->hm_lock);
			if unlikely(self->hm_mode != HANDLE_MANAGER_MODE_LINEAR ||
			            count < self->hm_count) {
				kfree(map);
				return HANDLE_MANAGE_SWITCH_TO_HASHMODE_FOR_HANDLE_NOT_CHANGED_UNLOCKED;
			}
			result = HANDLE_MANAGE_SWITCH_TO_HASHMODE_FOR_HANDLE_CHANGED_UNLOCKED;
		}
		/* With the map now allocated, initialize it. */
		memset(map, 0xff, (used_mask + 1) * sizeof(struct handle_hashent));
		vec = self->hm_linear.hm_vector;
		assert(self->hm_count <= self->hm_linear.hm_alloc);
		for (i = 0; i < self->hm_linear.hm_alloc; ++i) {
			if (vec[i].h_type == HANDLE_TYPE_UNDEFINED)
				continue; /* Unused handle. */
			j = perturb = i;
			for (;; handle_manager_hashnext(j, perturb)) {
				if (map[i].hh_handle_id == HANDLE_HASHENT_SENTINEL_ID)
					break;
			}
			/* Initially, all existing linear handles map onto themself 1-to-1
			 * This is only distorted later when by `handle_manager_flatten_handle_vector()',
			 * or by future  use of the  handle manager  for the purpose  of allocating  more
			 * handles. */
			map[i].hh_handle_id    = i;
			map[i].hh_vector_index = i;
		}
		self->hm_mode                  = HANDLE_MANAGER_MODE_HASHVECTOR;
		self->hm_hashvector.hm_hashvec = map;
		self->hm_hashvector.hm_hashmsk = used_mask;
		self->hm_hashvector.hm_hashuse = self->hm_count;
		self->hm_hashvector.hm_vecfree = self->hm_minfree;
		/* Try to re-bind handle mappings, so-as not to leave any unused entries. */
		if (self->hm_hashvector.hm_alloc >= self->hm_count + 32)
			handle_manager_flatten_handle_vector(self);
		return result;
	}
}


/* The hash-vector was kept at its current size */
#define HANDLE_MANAGE_REHASH_UNCHANGED_LOCKED   0 /* The caller's lock was kept the entire time */
#define HANDLE_MANAGE_REHASH_UNCHANGED_UNLOCKED 1 /* The caller's lock was lost temporarily */
/* The hash-vector was increased */
#define HANDLE_MANAGE_REHASH_REHASHED_LOCKED    2 /* The caller's lock was kept the entire time */
#define HANDLE_MANAGE_REHASH_REHASHED_UNLOCKED  3 /* The caller's lock was lost temporarily */

/* Try to re-hash the hash vector of `self'
 * The caller is required to be holding a write-lock before calling this function.
 * @return: * : One of `HANDLE_MANAGE_REHASH_*'
 * NOTE: When this function returns by throwing an exception, the caller's lock
 *       will have already been lost! */
PRIVATE unsigned int FCALL
handle_manage_rehash(struct handle_manager *__restrict self)
		THROWS(E_WOULDBLOCK, E_BADALLOC) {
	struct handle_hashent *new_map;
	unsigned int used_mask;
	unsigned int result;
	unsigned int threshold;
	unsigned int count;
	assert(sync_writing(&self->hm_lock));
	assert(self->hm_mode == HANDLE_MANAGER_MODE_HASHVECTOR);
	/* Check if rehashing is even required, as opposed to the hash-table
	 * already being large enough to easily house an additional  handle. */
	if (!(self->hm_hashvector.hm_hashmsk <= ((self->hm_hashvector.hm_hashuse + 1) * 3) / 2))
		return HANDLE_MANAGE_REHASH_UNCHANGED_LOCKED;
	result = HANDLE_MANAGE_REHASH_REHASHED_LOCKED;
	/* Try to re-hash the hash vector. */
	count     = self->hm_count;
	used_mask = 1;
	threshold = (count * 3) / 2;
	while (used_mask <= threshold)
		used_mask = (used_mask << 1) | 1;
	new_map = (struct handle_hashent *)kmalloc_nx((used_mask + 1) *
	                                              sizeof(struct handle_hashent),
	                                              GFP_ATOMIC | GFP_PREFLT);
	if (!new_map) {
		/* Must unlock the handle-manager, then try to allocate while blocking */
		sync_endwrite(&self->hm_lock);
		new_map = (struct handle_hashent *)kmalloc((used_mask + 1) *
		                                           sizeof(struct handle_hashent),
		                                           GFP_PREFLT);
		sync_write(&self->hm_lock);
		if unlikely(self->hm_mode != HANDLE_MANAGER_MODE_HASHVECTOR ||
		            self->hm_count > count) {
			kfree(new_map);
			return HANDLE_MANAGE_REHASH_UNCHANGED_UNLOCKED;
		}
		result = HANDLE_MANAGE_REHASH_REHASHED_UNLOCKED;
	}
	memset(new_map, 0xff, (used_mask + 1) * sizeof(struct handle_hashent));
	assert(self->hm_count <= self->hm_hashvector.hm_alloc);
	if likely(self->hm_hashvector.hm_hashvec) {
		unsigned int i, j, perturb;
		for (i = 0; i <= self->hm_hashvector.hm_hashmsk; ++i) {
			struct handle_hashent ent;
			ent = self->hm_hashvector.hm_hashvec[i];
			if (ent.hh_handle_id == HANDLE_HASHENT_SENTINEL_ID)
				continue; /* Unused */
			if (ent.hh_vector_index == (unsigned int)-1)
				continue; /* Deleted */
			j = perturb = ent.hh_vector_index & used_mask;
			for (;; handle_manager_hashnext(j, perturb)) {
				struct handle_hashent *dstent;
				dstent = &new_map[j & used_mask];
				if (dstent->hh_handle_id != HANDLE_HASHENT_SENTINEL_ID)
					continue;
				*dstent = ent;
				break;
			}
		}
		kfree(self->hm_hashvector.hm_hashvec);
	}
	self->hm_hashvector.hm_hashvec = new_map;
	self->hm_hashvector.hm_hashmsk = used_mask;
	/* All deleted entries have been removed, so HASHUSE is set to COUNT */
	self->hm_hashvector.hm_hashuse = self->hm_count;
	return result;
}



/* Place the given handle into the specified handle slot `dst_fd'.
 * @throw: E_BADALLOC: Insufficient kernel memory to allocate more handle slots
 * @throw: E_BADALLOC_INSUFFICIENT_HANDLE_NUMBERS: Too many open handles
 * @throw: E_BADALLOC_INSUFFICIENT_HANDLE_RANGE: `dst_fd' is outside the allowed handle range.
 * @throw: E_WOULDBLOCK: Preemption was disabled, and the operation would have blocked */
PUBLIC NONNULL((1, 3)) void FCALL
handle_installinto(struct handle_manager *__restrict self,
                   unsigned int dst_fd,
                   struct handle const *__restrict hnd)
		THROWS(E_WOULDBLOCK, E_BADALLOC,
		       E_BADALLOC_INSUFFICIENT_HANDLE_NUMBERS,
		       E_BADALLOC_INSUFFICIENT_HANDLE_RANGE) {
	struct handle old_handle;
	old_handle = handle_installxchg(self, dst_fd, hnd);
	decref(old_handle);
}



/* Lookup a given fd-number and return the associated handle.
 * NOTE: When `fd' doesn't refer to a valid handle, the returned
 *       handle  has  its type  set  to `HANDLE_TYPE_UNDEFINED'.
 * NOTE: This function also handles symbolic file descriptors!
 * @throw: E_WOULDBLOCK: Preemption was disabled, and the operation would have blocked */
PUBLIC WUNUSED REF struct handle FCALL
handle_trylookup(struct handle_manager *__restrict self,
                 unsigned int fd)
		THROWS(E_WOULDBLOCK) {
	REF struct handle result;
	sync_read(&self->hm_lock);
	if (self->hm_mode == HANDLE_MANAGER_MODE_LINEAR) {
		assert(self->hm_count <= self->hm_linear.hm_alloc);
		if (fd >= self->hm_linear.hm_alloc)
			goto err_unbound;
		result = incref(self->hm_linear.hm_vector[fd]);
	} else {
		unsigned int i, perturb;
		assert(self->hm_count <= self->hm_hashvector.hm_alloc);
		i = perturb = fd & self->hm_hashvector.hm_hashmsk;
		for (;; handle_manager_hashnext(i, perturb)) {
			struct handle_hashent ent;
			unsigned int vecid;
			ent = self->hm_hashvector.hm_hashvec[i & self->hm_hashvector.hm_hashmsk];
			if (ent.hh_handle_id == HANDLE_HASHENT_SENTINEL_ID)
				goto err_unbound; /* Unbound */
			if (ent.hh_handle_id != fd)
				continue; /* Some other handle. */
			vecid = ent.hh_vector_index;
			if (vecid == (unsigned int)-1)
				goto err_unbound; /* Deleted */
			result = incref(self->hm_hashvector.hm_vector[vecid]);
		}
	}
	sync_endread(&self->hm_lock);
	return result;
err_unbound:
	sync_endread(&self->hm_lock);
	result.h_type = HANDLE_TYPE_UNDEFINED;
	result.h_mode = IO_GENERIC;
	result.h_data = NULL;
	return result;
}

PRIVATE ATTR_NORETURN NONNULL((2)) void FCALL
throw_unbound_handle(unsigned int fd, struct handle_manager *__restrict self)
		THROWS(E_INVALID_HANDLE_FILE) {
	unsigned int fd_max, fd_limit;
	sync_read(&self->hm_lock);
	fd_limit = self->hm_maxlimit;
	fd_max   = self->hm_mode == HANDLE_MANAGER_MODE_LINEAR
	         ? handle_manager_get_max_linear_fd_plus_one(self)
	         : handle_manager_get_max_hashvector_fd_plus_one(self);
	sync_endread(&self->hm_lock);
	THROW(E_INVALID_HANDLE_FILE,
	      fd,
	      E_INVALID_HANDLE_FILE_UNBOUND,
	      fd_max,
	      fd_limit);
}

/* Same as `handle_trylookup()', but throw an error when `fd' is invalid. */
PUBLIC WUNUSED REF struct handle FCALL
handle_lookupin(unsigned int fd, struct handle_manager *__restrict self)
		THROWS(E_WOULDBLOCK, E_INVALID_HANDLE_FILE) {
	REF struct handle result;
	sync_read(&self->hm_lock);
	if (self->hm_mode == HANDLE_MANAGER_MODE_LINEAR) {
		assert(self->hm_count <= self->hm_linear.hm_alloc);
		if unlikely(fd >= self->hm_linear.hm_alloc) {
			unsigned int fd_max, fd_limit;
			fd_max   = handle_manager_get_max_linear_fd_plus_one(self);
			fd_limit = self->hm_maxlimit;
			COMPILER_READ_BARRIER();
			sync_endread(&self->hm_lock);
			THROW(E_INVALID_HANDLE_FILE,
			      fd,
			      fd > fd_limit ? E_INVALID_HANDLE_FILE_ILLEGAL
			                    : E_INVALID_HANDLE_FILE_UNALLOCATED,
			      fd_max,
			      fd_limit);
		}
		result = incref(self->hm_linear.hm_vector[fd]);
		if unlikely(result.h_type == HANDLE_TYPE_UNDEFINED) {
			unsigned int fd_max, fd_limit;
			fd_max   = handle_manager_get_max_linear_fd_plus_one(self);
			fd_limit = self->hm_maxlimit;
			COMPILER_READ_BARRIER();
			sync_endread(&self->hm_lock);
			THROW(E_INVALID_HANDLE_FILE,
			      fd,
			      E_INVALID_HANDLE_FILE_UNBOUND,
			      fd_max,
			      fd_limit);
		}
	} else {
		unsigned int i, perturb;
		assert(self->hm_mode == HANDLE_MANAGER_MODE_HASHVECTOR);
		assert(self->hm_hashvector.hm_hashvec);
		assert(self->hm_count <= self->hm_hashvector.hm_alloc);
		i = perturb = fd & self->hm_hashvector.hm_hashmsk;
		for (;; handle_manager_hashnext(i, perturb)) {
			struct handle_hashent *hashent;
			unsigned int vecid;
			hashent = &self->hm_hashvector.hm_hashvec[i & self->hm_hashvector.hm_hashmsk];
			if (hashent->hh_handle_id == HANDLE_HASHENT_SENTINEL_ID) {
				unsigned int fd_max, fd_limit;
				fd_limit = self->hm_maxlimit;
				fd_max   = handle_manager_get_max_hashvector_fd_plus_one(self);
				COMPILER_READ_BARRIER();
				sync_endread(&self->hm_lock);
				/* Unbound handle. */
				THROW(E_INVALID_HANDLE_FILE,
				      fd,
				      fd > fd_limit ? E_INVALID_HANDLE_FILE_ILLEGAL : fd >= fd_max ? E_INVALID_HANDLE_FILE_UNALLOCATED : E_INVALID_HANDLE_FILE_UNBOUND,
				      fd_max,
				      fd_limit);
			}
			if (hashent->hh_handle_id != fd)
				continue; /* Some other handle. */
			/* Found it! */
			vecid = hashent->hh_vector_index;
			if (vecid == (unsigned int)-1) {
				/* Handle has already been deleted! */
				unsigned int fd_max;
				unsigned int fd_limit = self->hm_maxlimit;
				fd_max                = handle_manager_get_max_hashvector_fd_plus_one(self);
				COMPILER_READ_BARRIER();
				sync_endread(&self->hm_lock);
				THROW(E_INVALID_HANDLE_FILE,
				      fd,
				      fd > fd_limit ? E_INVALID_HANDLE_FILE_ILLEGAL
				                    : E_INVALID_HANDLE_FILE_UNBOUND,
				      fd_max,
				      fd_limit);
			}
			result = incref(self->hm_hashvector.hm_vector[vecid]);
			break;
		}
	}
	sync_endread(&self->hm_lock);
	return result;
}

PUBLIC WUNUSED REF struct handle FCALL
handle_lookup_nosym(unsigned int fd)
		THROWS(E_WOULDBLOCK, E_INVALID_HANDLE_FILE) {
	return handle_lookupin(fd, THIS_HANDLE_MANAGER);
}

/* Lookup the pointer to a given handle.
 * NOTE: The  caller required to acquire a read/write-lock before
 *       calling this function. When an exception is thrown, that
 *       lock will have already been released.
 * NOTE: Upon success, that lock is kept. */
PRIVATE ATTR_RETNONNULL struct handle *FCALL
handle_lookup_ptr(unsigned int fd, struct handle_manager *__restrict self)
		THROWS(E_WOULDBLOCK, E_INVALID_HANDLE_FILE) {
	REF struct handle *result;
	assert(sync_reading(&self->hm_lock));
	if (self->hm_mode == HANDLE_MANAGER_MODE_LINEAR) {
		assert(self->hm_count <= self->hm_linear.hm_alloc);
		if unlikely(fd >= self->hm_linear.hm_alloc) {
			unsigned int fd_max   = handle_manager_get_max_linear_fd_plus_one(self);
			unsigned int fd_limit = self->hm_maxlimit;
			COMPILER_READ_BARRIER();
			sync_end(&self->hm_lock);
			THROW(E_INVALID_HANDLE_FILE,
			      fd,
			      fd > fd_limit ? E_INVALID_HANDLE_FILE_ILLEGAL
			                    : E_INVALID_HANDLE_FILE_UNALLOCATED,
			      fd_max,
			      fd_limit);
		}
		result = &self->hm_linear.hm_vector[fd];
		if unlikely(result->h_type == HANDLE_TYPE_UNDEFINED) {
			unsigned int fd_max, fd_limit;
			fd_max   = handle_manager_get_max_linear_fd_plus_one(self);
			fd_limit = self->hm_maxlimit;
			COMPILER_READ_BARRIER();
			sync_end(&self->hm_lock);
			THROW(E_INVALID_HANDLE_FILE,
			      fd,
			      E_INVALID_HANDLE_FILE_UNBOUND,
			      fd_max,
			      fd_limit);
		}
	} else {
		unsigned int i, perturb;
		assert(self->hm_mode == HANDLE_MANAGER_MODE_HASHVECTOR);
		assert(self->hm_hashvector.hm_hashvec);
		assert(self->hm_count <= self->hm_hashvector.hm_alloc);
		i = perturb = fd & self->hm_hashvector.hm_hashmsk;
		for (;; handle_manager_hashnext(i, perturb)) {
			struct handle_hashent *hashent;
			unsigned int vecid;
			hashent = &self->hm_hashvector.hm_hashvec[i & self->hm_hashvector.hm_hashmsk];
			if (hashent->hh_handle_id == HANDLE_HASHENT_SENTINEL_ID) {
				unsigned int fd_max, fd_limit;
				fd_limit = self->hm_maxlimit;
				fd_max   = handle_manager_get_max_hashvector_fd_plus_one(self);
				COMPILER_READ_BARRIER();
				sync_end(&self->hm_lock);
				/* Unbound handle. */
				THROW(E_INVALID_HANDLE_FILE,
				      fd,
				      fd > fd_limit ? E_INVALID_HANDLE_FILE_ILLEGAL : fd >= fd_max ? E_INVALID_HANDLE_FILE_UNALLOCATED : E_INVALID_HANDLE_FILE_UNBOUND,
				      fd_max,
				      fd_limit);
			}
			if (hashent->hh_handle_id != fd)
				continue; /* Some other handle. */
			/* Found it! */
			vecid = hashent->hh_vector_index;
			if (vecid == (unsigned int)-1) {
				/* Handle has already been deleted! */
				unsigned int fd_max, fd_limit;
				fd_limit = self->hm_maxlimit;
				fd_max   = handle_manager_get_max_hashvector_fd_plus_one(self);
				COMPILER_READ_BARRIER();
				sync_end(&self->hm_lock);
				THROW(E_INVALID_HANDLE_FILE,
				      fd,
				      fd > fd_limit ? E_INVALID_HANDLE_FILE_ILLEGAL
				                    : E_INVALID_HANDLE_FILE_UNBOUND,
				      fd_max,
				      fd_limit);
			}
			result = &self->hm_hashvector.hm_vector[vecid];
			assert(result->h_type != HANDLE_TYPE_UNDEFINED);
			break;
		}
	}
	return result;
}

PRIVATE ATTR_RETNONNULL WUNUSED NONNULL((1)) REF struct path *KCALL
handle_as_path_noinherit(struct handle const *__restrict hnd) {
	/* TODO: Invoke the tryas operator */
	REF struct path *result;
	switch (hnd->h_type) {

	case HANDLE_TYPE_FILEHANDLE:
	case HANDLE_TYPE_TEMPHANDLE:
	case HANDLE_TYPE_FIFOHANDLE:
	case HANDLE_TYPE_DIRHANDLE:
		result = incref(((struct filehandle *)hnd->h_data)->fh_path);
		break;

	case HANDLE_TYPE_PATH:
		result = incref((struct path *)hnd->h_data);
		break;

	default:
		THROW(E_INVALID_HANDLE_FILETYPE,
		      -1,
		      HANDLE_TYPE_PATH,
		      hnd->h_type,
		      HANDLE_TYPEKIND_GENERIC,
		      handle_typekind(hnd));
	}
	return result;
}



PRIVATE bool FCALL
handle_tryclose_symolic(unsigned int fd)
		THROWS(E_WOULDBLOCK) {
	switch (fd) {

	case (unsigned int)AT_FDCWD: {
		REF struct path *oldp;
		struct fs *f;
		f = THIS_FS;
		fs_pathlock_write(f);
		oldp      = f->fs_cwd;
		f->fs_cwd = incref(f->fs_root);
		fs_pathlock_endwrite(f);
		decref(oldp);
	}	break;

	case (unsigned int)AT_FDDRIVE_CWD(AT_DOS_DRIVEMIN) ...
	     (unsigned int)AT_FDDRIVE_CWD(AT_DOS_DRIVEMAX): {
		REF struct path *p, *oldp;
		unsigned int id;
		struct fs *f;
		id = (fd - (unsigned int)AT_FDDRIVE_CWD(AT_DOS_DRIVEMIN));
		f = THIS_FS;
		vfs_driveslock_read(f->fs_vfs);
		p = xincref(f->fs_vfs->vf_drives[id]);
		vfs_driveslock_endread(f->fs_vfs);
		TRY {
			fs_pathlock_write(f);
		} EXCEPT {
			decref(p);
			RETHROW();
		}
		oldp = f->fs_dcwd[id];
		f->fs_dcwd[id] = p; /* Inherit reference */
		fs_pathlock_endwrite(f);
		xdecref(oldp);
		if unlikely(!p && !oldp)
			throw_unbound_handle(fd, THIS_HANDLE_MANAGER);
	}	break;

	case (unsigned int)AT_FDDRIVE_ROOT(AT_DOS_DRIVEMIN) ...
	     (unsigned int)AT_FDDRIVE_ROOT(AT_DOS_DRIVEMAX): {
		struct vfs *myvfs = THIS_VFS;
		unsigned int id;
		REF struct path *oldp;
		id = (fd - (unsigned int)AT_FDDRIVE_ROOT(AT_DOS_DRIVEMIN));
		require(CAP_MOUNT_DRIVES);
		vfs_driveslock_write(myvfs);
		oldp = myvfs->vf_drives[id]; /* Inherit reference */
		if unlikely(!oldp) {
			vfs_driveslock_endwrite(myvfs);
			throw_unbound_handle(fd, THIS_HANDLE_MANAGER);
		}
		myvfs->vf_drives[id] = NULL;

		/* Check if `oldp' is still a drive root. */
		{
			bool isdrive = false;
			for (id = 0; id < COMPILER_LENOF(myvfs->vf_drives); ++id) {
				if (myvfs->vf_drives[id] == oldp) {
					isdrive = true;
					break;
				}
			}
			if (!isdrive)
				ATOMIC_AND(oldp->p_flags, ~PATH_F_ISDRIVE);
		}
		vfs_driveslock_endwrite(myvfs);
		decref_unlikely(oldp); /* Old reference from `myvfs->vf_drives[id];' */
	}	break;

	default:
		break;
	}
	return false;
}

PUBLIC bool FCALL
handle_tryclose(unsigned int fd)
		THROWS(E_WOULDBLOCK) {
	if (handle_tryclose_symolic(fd))
		return true;
	return handle_tryclose_nosym(fd, THIS_HANDLE_MANAGER);
}

PUBLIC void FCALL
handle_close(unsigned int fd)
		THROWS(E_WOULDBLOCK) {
	if (handle_tryclose_symolic(fd))
		return;
	handle_close_nosym(fd, THIS_HANDLE_MANAGER);
}




/* Same as `handle_installinto()', but allow `dst_fd' to be a writable, symbolic handle.
 * @throw: E_BADALLOC: Insufficient kernel memory to allocate more handle slots
 * @throw: E_BADALLOC_INSUFFICIENT_HANDLE_NUMBERS: Too many open handles
 * @throw: E_BADALLOC_INSUFFICIENT_HANDLE_RANGE: `dst_fd' is outside the allowed handle range.
 * @throw: E_WOULDBLOCK: Preemption was disabled, and the operation would have blocked */
PUBLIC NONNULL((2)) void FCALL
handle_installinto_sym(unsigned int dst_fd, struct handle const *__restrict hnd)
		THROWS(E_WOULDBLOCK, E_BADALLOC,
		       E_BADALLOC_INSUFFICIENT_HANDLE_NUMBERS,
		       E_BADALLOC_INSUFFICIENT_HANDLE_RANGE) {
	/* Symbolic handles */
	switch (dst_fd) {

	case (unsigned int)AT_FDCWD: {
		REF struct path *p, *oldp;
		struct fs *f;
		p = handle_as_path_noinherit(hnd);
		f = THIS_FS;
		TRY {
			fs_pathlock_write(f);
		} EXCEPT {
			decref(p);
			RETHROW();
		}
		oldp      = f->fs_cwd;
		f->fs_cwd = p; /* Inherit reference */
		fs_pathlock_endwrite(f);
		decref(oldp);
	}	break;

	case (unsigned int)AT_FDROOT: {
		REF struct path *p, *oldp;
		struct fs *f;
		p = handle_as_path_noinherit(hnd);
		f = THIS_FS;
		TRY {
			fs_pathlock_write(f);
		} EXCEPT {
			decref(p);
			RETHROW();
		}
		oldp      = f->fs_root;
		f->fs_root = p; /* Inherit reference */
		fs_pathlock_endwrite(f);
		decref(oldp);
	}	break;

	case (unsigned int)AT_FDDRIVE_CWD(AT_DOS_DRIVEMIN) ...
	     (unsigned int)AT_FDDRIVE_CWD(AT_DOS_DRIVEMAX): {
		REF struct path *p, *oldp;
		unsigned int id;
		struct fs *f;
		/* Bind DOS per-drive current working directories */
		id = (dst_fd - (unsigned int)AT_FDDRIVE_CWD(AT_DOS_DRIVEMIN));
		p = handle_as_path_noinherit(hnd);
		f = THIS_FS;
		TRY {
			fs_pathlock_write(f);
		} EXCEPT {
			decref(p);
			RETHROW();
		}
		oldp = f->fs_dcwd[id];
		f->fs_dcwd[id] = p; /* Inherit reference */
		fs_pathlock_endwrite(f);
		decref(oldp);
	}	break;

	case (unsigned int)AT_FDDRIVE_ROOT(AT_DOS_DRIVEMIN) ...
	     (unsigned int)AT_FDDRIVE_ROOT(AT_DOS_DRIVEMAX): {
		REF struct path *newp, *oldp;
		struct vfs *myvfs = THIS_VFS;
		unsigned int id;
		require(CAP_MOUNT_DRIVES);
		/* Bind DOS drives */
		id   = (dst_fd - (unsigned int)AT_FDDRIVE_ROOT(AT_DOS_DRIVEMIN));
		newp = handle_as_path_noinherit(hnd);
		TRY {
			vfs_driveslock_write(myvfs);
		} EXCEPT {
			decref_unlikely(newp);
			RETHROW();
		}
		oldp = myvfs->vf_drives[id];
		myvfs->vf_drives[id] = newp; /* Inherit reference */
		ATOMIC_OR(newp->p_flags, PATH_F_ISDRIVE);
		/* Check if `oldp' is still a drive root. */
		if (oldp) {
			bool isdrive = false;
			for (id = 0; id < COMPILER_LENOF(myvfs->vf_drives); ++id) {
				if (myvfs->vf_drives[id] == oldp) {
					isdrive = true;
					break;
				}
			}
			if (!isdrive)
				ATOMIC_AND(oldp->p_flags, ~PATH_F_ISDRIVE);
		}
		vfs_driveslock_endwrite(myvfs);
		xdecref_unlikely(oldp);
	}	break;

	default:
		/* Fallback: Install a regular handle */
		handle_installinto(THIS_HANDLE_MANAGER,
		                   dst_fd,
		                   hnd);
		break;
	}
}

/* Same as `handle_lookup()', but also allow for symbolic handles. */
PUBLIC WUNUSED REF struct handle FCALL
handle_lookup(unsigned int fd)
		THROWS(E_WOULDBLOCK, E_INVALID_HANDLE_FILE) {
	REF struct handle result;
	switch (fd) {

	/* Symbolic handles */

	case (unsigned int)AT_FDCWD: {
		struct fs *f;
		f             = THIS_FS;
		result.h_type = HANDLE_TYPE_PATH;
		result.h_mode = IO_RDONLY;
		fs_pathlock_read(f);
		result.h_data = incref(f->fs_cwd);
		fs_pathlock_endread(f);
	}	break;

	case (unsigned int)AT_FDROOT: {
		struct fs *f;
		f             = THIS_FS;
		result.h_type = HANDLE_TYPE_PATH;
		result.h_mode = IO_RDONLY;
		fs_pathlock_read(f);
		result.h_data = incref(f->fs_root);
		fs_pathlock_endread(f);
	}	break;

	case (unsigned int)AT_FDDRIVE_CWD(AT_DOS_DRIVEMIN) ...
	     (unsigned int)AT_FDDRIVE_CWD(AT_DOS_DRIVEMAX): {
		struct fs *f;
		f             = THIS_FS;
		result.h_type = HANDLE_TYPE_PATH;
		result.h_mode = IO_RDONLY;
		fs_pathlock_read(f);
		result.h_data = xincref(f->fs_dcwd[fd - (unsigned int)AT_FDDRIVE_CWD(AT_DOS_DRIVEMIN)]);
		fs_pathlock_endread(f);
		if (!result.h_data) {
			struct vfs *v = f->fs_vfs;
			vfs_driveslock_read(v);
			result.h_data = xincref(v->vf_drives[fd - (unsigned int)AT_FDDRIVE_CWD(AT_DOS_DRIVEMIN)]);
			vfs_driveslock_endread(v);
			if unlikely(!result.h_data)
				throw_unbound_handle(fd, THIS_HANDLE_MANAGER);
		}
	}	break;

	case (unsigned int)AT_FDDRIVE_ROOT(AT_DOS_DRIVEMIN) ...
	     (unsigned int)AT_FDDRIVE_ROOT(AT_DOS_DRIVEMAX): {
		struct vfs *v;
		v = THIS_FS->fs_vfs;
		vfs_driveslock_read(v);
		result.h_data = xincref(v->vf_drives[fd - (unsigned int)AT_FDDRIVE_ROOT(AT_DOS_DRIVEMIN)]);
		vfs_driveslock_endread(v);
		if unlikely(!result.h_data)
			throw_unbound_handle(fd, THIS_HANDLE_MANAGER);
	}	break;

	case (unsigned int)AT_THIS_TASK:
		result.h_type = HANDLE_TYPE_PIDFD;
		result.h_mode = IO_RDONLY;
		result.h_data = incref(THIS_TASKPID);
		break;

	case (unsigned int)AT_THIS_PROCESS:
		result.h_type = HANDLE_TYPE_PIDFD;
		result.h_mode = IO_RDONLY;
		result.h_data = incref(task_getprocesspid());
		break;

	case (unsigned int)AT_PARENT_PROCESS:
		result.h_type = HANDLE_TYPE_PIDFD;
		result.h_mode = IO_RDONLY;
		result.h_data = task_getparentprocesspid();
		break;

	default:
		result = handle_lookupin(fd, THIS_HANDLE_MANAGER);
		break;
	}
	return result;
}




/* Modify the I/O-flags of a given file handle
 * The new I/O flags are calculated as `(old_flags & mask) | flag'
 * @return: * :  The handle's old I/O-flags */
PUBLIC NONNULL((1)) iomode_t FCALL
handle_chflags(struct handle_manager *__restrict self,
               unsigned int fd, iomode_t mask, iomode_t flag)
		THROWS(E_WOULDBLOCK, E_INVALID_HANDLE_FILE) {
	iomode_t result;
	struct handle *p;
	sync_write(&self->hm_lock);
	p = handle_lookup_ptr(fd, self);
	result = p->h_mode;
	p->h_mode &= mask;
	p->h_mode |= flag;
	if ((result & IO_CLOEXEC) != (p->h_mode & IO_CLOEXEC)) {
		if (!(result & IO_CLOEXEC))
			++self->hm_cloexec_count;
		else {
			assert(self->hm_cloexec_count);
			--self->hm_cloexec_count;
		}
	}
	if ((result & IO_CLOFORK) != (p->h_mode & IO_CLOFORK)) {
		if (!(result & IO_CLOFORK))
			++self->hm_clofork_count;
		else {
			assert(self->hm_clofork_count);
			--self->hm_clofork_count;
		}
	}
	sync_endwrite(&self->hm_lock);
	return result;
}


INTDEF size_t KCALL /* from "misc/pipe.c" */
ringbuffer_set_pipe_limit(struct ringbuffer *__restrict self,
                          size_t new_lim);

/* The kernel-space equivalent of the user-space `fcntl()' function. */
PUBLIC NONNULL((1)) syscall_ulong_t KCALL
handle_fcntl(struct handle_manager *__restrict self,
             unsigned int fd, fcntl_t cmd,
             UNCHECKED USER void *arg)
		THROWS(E_INVALID_ARGUMENT_UNKNOWN_COMMAND,
		       E_BADALLOC_INSUFFICIENT_HANDLE_NUMBERS,
		       E_BADALLOC_INSUFFICIENT_HANDLE_RANGE,
		       E_WOULDBLOCK, E_BADALLOC, ...) {
	/* fcntl() implementation */
	syscall_ulong_t result;
	struct handle temp;
	switch (cmd) {

	case F_DUPFD: {
		temp = handle_lookupin(fd, self);
		RAII_FINALLY { decref_unlikely(temp); };
		temp.h_mode &= ~(IO_CLOEXEC | IO_CLOFORK);
		result = handle_install(self, temp);
	}	break;

	case F_DUPFD_CLOEXEC: {
		temp = handle_lookupin(fd, self);
		RAII_FINALLY { decref_unlikely(temp); };
		temp.h_mode &= ~(IO_CLOEXEC | IO_CLOFORK);
		temp.h_mode |= IO_CLOEXEC;
		result = handle_install(self, temp);
	}	break;

	case F_DUP2FD: {
		result = (syscall_ulong_t)arg;
		temp   = handle_lookupin(fd, self);
		RAII_FINALLY { decref_unlikely(temp); };
		temp.h_mode &= ~(IO_CLOEXEC | IO_CLOFORK);
		handle_installinto_sym((unsigned int)result, temp);
	}	break;

	case F_DUP2FD_CLOEXEC: {
		result = (syscall_ulong_t)arg;
		temp   = handle_lookupin(fd, self);
		RAII_FINALLY { decref_unlikely(temp); };
		temp.h_mode &= ~(IO_CLOEXEC | IO_CLOFORK);
		temp.h_mode |= IO_CLOEXEC;
		handle_installinto_sym((unsigned int)result, temp);
	}	break;

	case F_GETFD: {
		struct handle *p;
		sync_read(&self->hm_lock);
		p      = handle_lookup_ptr(fd, self);
		result = IO_HANDLE_FTO_FD(p->h_mode);
		sync_endread(&self->hm_lock);
	}	break;

	case F_SETFD: {
		struct handle *p;
		VALIDATE_FLAGSET((uintptr_t)arg,
		                 FD_CLOEXEC | FD_CLOFORK,
		                 E_INVALID_ARGUMENT_CONTEXT_F_SETFD_FDFLAGS);
		sync_write(&self->hm_lock);
		p = handle_lookup_ptr(fd, self);
		/* Account for old handle flags. */
		if (p->h_mode & IO_CLOEXEC) {
			assert(self->hm_cloexec_count);
			--self->hm_cloexec_count;
		}
		if (p->h_mode & IO_CLOFORK) {
			assert(self->hm_clofork_count);
			--self->hm_clofork_count;
		}
		/* Delete old flags. */
		p->h_mode &= ~(IO_CLOEXEC | IO_CLOFORK);
		/* Apply new flags. */
		if ((uintptr_t)arg & FD_CLOEXEC) {
			p->h_mode |= IO_CLOEXEC;
			++self->hm_cloexec_count;
		}
		if ((uintptr_t)arg & FD_CLOFORK) {
			p->h_mode |= IO_CLOFORK;
			++self->hm_clofork_count;
		}
		sync_endwrite(&self->hm_lock);
		result = 0;
	}	break;

	case F_GETFL: {
		struct handle *p;
		sync_read(&self->hm_lock);
		p      = handle_lookup_ptr(fd, self);
		result = IO_TO_OPENFLAG_NOHANDLE(p->h_mode & IO_SETFL_MASK);
		sync_endread(&self->hm_lock);
	}	break;

	case F_SETFL:
	case F_SETFL_XCH: {
		struct handle *p;
		VALIDATE_FLAGSET((uintptr_t)arg,
		                 IO_SETFL_MASK,
		                 E_INVALID_ARGUMENT_CONTEXT_F_SETFL_OFLAGS);
		sync_write(&self->hm_lock);
		p      = handle_lookup_ptr(fd, self);
		result = IO_TO_OPENFLAG_NOHANDLE(p->h_mode & IO_SETFL_MASK);
		p->h_mode &= ~IO_SETFL_MASK;
		p->h_mode |= IO_FROM_OPENFLAG_NOHANDLE((oflag_t)(uintptr_t)arg);
		sync_endwrite(&self->hm_lock);
		if (cmd == F_SETFL)
			result = 0;
	}	break;

	//TODO:case F_GETLK32:
	//TODO:case F_SETLK32:
	//TODO:case F_SETLKW32:
	//TODO:case F_SETOWN:
	//TODO:case F_GETOWN:
	//TODO:case F_SETSIG:
	//TODO:case F_GETSIG:
	//TODO:case F_GETLK64:
	//TODO:case F_SETLK64:
	//TODO:case F_SETLKW64:
	//TODO:case F_SETOWN_EX:
	//TODO:case F_GETOWN_EX:
	//TODO:case F_SETLEASE:
	//TODO:case F_GETLEASE:
	//TODO:case F_NOTIFY:

	case F_SETPIPE_SZ: {
		struct ringbuffer *rb;
		size_t newsize;
		temp = handle_lookupin(fd, self);
		RAII_FINALLY { decref_unlikely(temp); };
		if (temp.h_type == HANDLE_TYPE_PIPE_READER ||
		    temp.h_type == HANDLE_TYPE_PIPE_WRITER) {
			struct pipe_reader *me;
			me = (struct pipe_reader *)temp.h_data;
			rb = &me->pr_pipe->p_buffer;
		} else if (temp.h_type == HANDLE_TYPE_PIPE) {
			struct pipe *me;
			me = (struct pipe *)temp.h_data;
			rb = &me->p_buffer;
		} else if (temp.h_type == HANDLE_TYPE_FIFOHANDLE) {
			struct fifohandle *me;
			me = (struct fifohandle *)temp.h_data;
			rb = &me->fu_fifo->ff_buffer;
		} else {
			THROW(E_INVALID_HANDLE_FILETYPE, fd,
			      HANDLE_TYPE_PIPE, temp.h_type,
			      HANDLE_TYPEKIND_GENERIC,
			      handle_typekind(&temp));
		}
		newsize = (size_t)arg;
		if unlikely(newsize < 1) {
			/* Linux requires PAGESIZE here... */
			THROW(E_INVALID_ARGUMENT_BAD_VALUE,
			      E_INVALID_ARGUMENT_CONTEXT_F_SETPIPE_SZ_TOO_SMALL,
			      newsize);
		}
		/* Permissions checking is done in `ringbuffer_set_pipe_limit()' */
		ringbuffer_set_pipe_limit(rb, newsize);
		result = 0;
	}	break;

	case F_GETPIPE_SZ: {
		struct ringbuffer *rb;
		temp = handle_lookupin(fd, self);
		RAII_FINALLY { decref_unlikely(temp); };
		if (temp.h_type == HANDLE_TYPE_PIPE_READER ||
		    temp.h_type == HANDLE_TYPE_PIPE_WRITER) {
			struct pipe_reader *me;
			me = (struct pipe_reader *)temp.h_data;
			rb = &me->pr_pipe->p_buffer;
		} else if (temp.h_type == HANDLE_TYPE_PIPE) {
			struct pipe *me;
			me = (struct pipe *)temp.h_data;
			rb = &me->p_buffer;
		} else if (temp.h_type == HANDLE_TYPE_FIFOHANDLE) {
			struct fifohandle *me;
			me = (struct fifohandle *)temp.h_data;
			rb = &me->fu_fifo->ff_buffer;
		} else {
			THROW(E_INVALID_HANDLE_FILETYPE, fd,
			      HANDLE_TYPE_PIPE, temp.h_type,
			      HANDLE_TYPEKIND_GENERIC,
			      handle_typekind(&temp));
		}
		result = ATOMIC_READ(rb->rb_limit);
	}	break;

	case F_NEXT:
		/* Find the first valid FD >= the given one. */
		result = handle_nextfd(fd, self);
		break;

	case F_CLOSEM:
		/* Close all handles `>= fd'
		 * KOS returns the  actual number of  closed files, however  given
		 * that this fcntl doesn't have very large support, this  behavior
		 * may differ on those few other platforms that actually implement
		 * this command. */
		result = handle_closefrom_nosym(fd, self);
		break;

	case F_MAXFD:
		(void)fd; /* Unused by this fcntl() command */
		sync_read(&self->hm_lock);
		if (self->hm_mode == HANDLE_MANAGER_MODE_LINEAR) {
			result = handle_manager_get_max_linear_fd_plus_one(self);
		} else {
			result = handle_manager_get_max_hashvector_fd_plus_one(self);
		}
		/* Special case: There aren't any handles in use... */
		if unlikely(result == 0) {
			unsigned int fd_limit;
			fd_limit = self->hm_maxlimit;
			sync_endread(&self->hm_lock);
			THROW(E_INVALID_HANDLE_FILE,
			      0,
			      E_INVALID_HANDLE_FILE_UNALLOCATED,
			      0,
			      fd_limit);
		}
		sync_endread(&self->hm_lock);
		--result; /* Return the actual greatest FD currently in use (not that fd +1) */
		break;

	default:
		THROW(E_INVALID_ARGUMENT_UNKNOWN_COMMAND,
		      E_INVALID_ARGUMENT_CONTEXT_FCNTL_COMMAND,
		      cmd);
		break;
	}
	return result;
}





/* Do everything required to install a handle via a open openfd
 * command data  packet that  has been  passed via  user-space. */
PUBLIC NONNULL((2)) unsigned int FCALL
handle_installopenfd(USER UNCHECKED struct openfd *data,
                     struct handle const *__restrict hnd)
		THROWS(E_WOULDBLOCK, E_BADALLOC,
		       E_BADALLOC_INSUFFICIENT_HANDLE_NUMBERS,
		       E_BADALLOC_INSUFFICIENT_HANDLE_RANGE,
		       E_SEGFAULT, E_INVALID_ARGUMENT) {
	u16 mode, flags;
	unsigned int result_fd;
	struct handle_manager *man;
	struct handle used_hnd;
	man = THIS_HANDLE_MANAGER;
	validate_readwrite(data, sizeof(*data));
	COMPILER_READ_BARRIER();
	mode  = data->of_mode;
	flags = data->of_flags;
	COMPILER_READ_BARRIER();
	if (flags & ~(IO_CLOEXEC | IO_CLOFORK)) {
		THROW(E_INVALID_ARGUMENT_UNKNOWN_FLAG,
		      E_INVALID_ARGUMENT_CONTEXT_OPENFD_FLAGS,
		      flags,
		      ~(IO_CLOEXEC | IO_CLOFORK),
		      0);
	}
	used_hnd = *hnd;
	used_hnd.h_mode |= flags;
	switch (mode) {

	case OPENFD_MODE_AUTO:
		result_fd = handle_install(man, used_hnd);
		break;

	case OPENFD_MODE_HINT:
		COMPILER_READ_BARRIER();
		result_fd = (unsigned int)data->of_hint;
		COMPILER_READ_BARRIER();
		result_fd = handle_installat(man, result_fd, used_hnd);
		break;

	case OPENFD_MODE_INTO:
		COMPILER_READ_BARRIER();
		result_fd = (unsigned int)data->of_hint;
		COMPILER_READ_BARRIER();
		/* Allow for symbolic handle assignments. */
		handle_installinto_sym(result_fd, used_hnd);
		return result_fd;

	case OPENFD_MODE_INTO_EXACT:
		COMPILER_READ_BARRIER();
		result_fd = (unsigned int)data->of_hint;
		COMPILER_READ_BARRIER();
		/* Don't allow for symbolic handle assignments. */
		handle_installinto(man, result_fd, used_hnd);
		return result_fd;

	default:
		THROW(E_INVALID_ARGUMENT_UNKNOWN_COMMAND,
		      E_INVALID_ARGUMENT_CONTEXT_OPENFD_MODE,
		      mode);
		break;
	}
	COMPILER_WRITE_BARRIER();
	data->of_hint = result_fd;
	COMPILER_WRITE_BARRIER();
	return result_fd;
}




DECL_END

#ifndef __INTELLISENSE__
#define INSTALL_IN 1
#include "handle-install.c.inl"
#define INSTALL_AT 1
#include "handle-install.c.inl"
/**/
#include "handle-install.c.inl"
#endif /* !__INTELLISENSE__ */
#endif /* !CONFIG_USE_NEW_HANDMAN */

#endif /* !GUARD_KERNEL_SRC_FD_HANDLE_C */