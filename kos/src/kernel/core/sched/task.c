/* Copyright (c) 2019-2021 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2021 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef GUARD_KERNEL_SRC_SCHED_TASK_C
#define GUARD_KERNEL_SRC_SCHED_TASK_C 1
#define _KOS_SOURCE 1

#include <kernel/compiler.h>

#include <debugger/config.h>
#include <debugger/hook.h>
#include <fs/vfs.h>
#include <kernel/except.h>
#include <kernel/handle.h>
#include <kernel/heap.h>
#include <kernel/panic.h>
#include <kernel/syscall.h>
#include <kernel/types.h>
#include <kernel/vm.h>
#include <kernel/vm/phys.h>
#include <sched/async.h>
#include <sched/cpu.h>
#include <sched/cred.h>
#include <sched/scheduler.h>
#include <sched/task.h>

#include <hybrid/align.h>
#include <hybrid/atomic.h>
#include <hybrid/minmax.h>

#include <asm/farptr.h>
#include <sys/wait.h>

#include <assert.h>
#include <stddef.h>
#include <string.h>

#ifdef CONFIG_HAVE_DEBUGGER
#include "../memory/vm/vm-nodeapi.h"
#endif /* CONFIG_HAVE_DEBUGGER */

DECL_BEGIN

INTDEF byte_t __kernel_pertask_start[];
INTDEF byte_t __kernel_pertask_size[];

#define HINT_ADDR(x, y) x
#define HINT_MODE(x, y) y
#define HINT_GETADDR(x) HINT_ADDR x
#define HINT_GETMODE(x) HINT_MODE x


PRIVATE ATTR_USED ATTR_SECTION(".data.pertask.head")
struct task task_header = {
	/* .t_self     = */ NULL, /* Filled in by the initializer. */
	/* .t_refcnt   = */ 1,
	/* .t_flags    = */ TASK_FNORMAL,
	/* .t_cpu      = */ &_bootcpu,
	/* .t_vm       = */ &vm_kernel,
	/* .t_vm_tasks = */ LLIST_INITNODE,
	/* .t_heapsz   = */ (size_t)__kernel_pertask_size,
	/* .t_state    = */ NULL
};

INTDEF byte_t __kernel_boottask_stack_pageid[];
INTDEF byte_t __kernel_boottask_stack_pageptr[];
INTDEF byte_t __kernel_bootidle_stack_pageid[];
INTDEF byte_t __kernel_bootidle_stack_pageptr[];
INTDEF byte_t __kernel_asyncwork_stack_pageid[];
INTDEF byte_t __kernel_asyncwork_stack_pageptr[];

PUBLIC ATTR_PERTASK struct vm_datapart
this_kernel_stackpart_ ASMNAME("this_kernel_stackpart") = {
	/* .dp_refcnt = */ 1,
	/* .dp_lock   = */ SHARED_RWLOCK_INIT,
	{
		/* .dp_tree = */ { NULL, NULL, 0, CEILDIV(KERNEL_STACKSIZE, PAGESIZE) - 1 }
	},
	/* .dp_crefs = */ LLIST_INIT,
	/* .dp_srefs = */ (struct vm_node *)&this_kernel_stacknode,
	/* .dp_stale = */ NULL,
	/* .dp_block = */ &vm_datablock_anonymous,
#if CEILDIV(KERNEL_STACKSIZE, PAGESIZE) > (BITS_PER_POINTER / VM_DATAPART_PPP_BITS)
	/* .dp_flags = */ VM_DATAPART_FLAG_HEAPPPP,
#else
	/* .dp_flags = */ VM_DATAPART_FLAG_NORMAL,
#endif
	/* .dp_state = */ VM_DATAPART_STATE_LOCKED,
	{
		/* .dp_ramdata = */ {
			/* .rd_blockv = */ &this_kernel_stackpart_.dp_ramdata.rd_block0,
			{
				/* .rd_block0 = */ {
					/* .rb_start = */ 0, /* Filled later. */
					/* .rb_size  = */ CEILDIV(KERNEL_STACKSIZE, PAGESIZE)
				}
			}
		}
	},
	{
#if CEILDIV(KERNEL_STACKSIZE, PAGESIZE) > (BITS_PER_POINTER / VM_DATAPART_PPP_BITS)
		/* .dp_pprop = */ 0,
#else
		/* .dp_pprop = */ (uintptr_t)-1,
#endif
	},
};

PUBLIC ATTR_PERTASK struct vm_node
this_kernel_stacknode_ ASMNAME("this_kernel_stacknode") = {
	/* .vn_node      = */ { NULL, NULL, 0, 0 },
	/* .vn_byaddr    = */ LLIST_INITNODE,
	/* .vn_prot      = */ VM_PROT_READ | VM_PROT_WRITE | VM_PROT_SHARED,
	/* .vn_flags     = */ VM_NODE_FLAG_NOMERGE | VM_NODE_FLAG_PREPARED,
	/* .vn_vm        = */ &vm_kernel,
	/* .vn_part      = */ &this_kernel_stackpart_,
	/* .vn_block     = */ &vm_datablock_anonymous,
	/* .vn_fspath    = */ NULL,
	/* .vn_fsname    = */ NULL,
	/* .vn_link      = */ { NULL, &LLIST_HEAD(this_kernel_stackpart_.dp_srefs) },
	/* .vn_guard     = */ 0
};

#ifdef CONFIG_HAVE_KERNEL_STACK_GUARD
PUBLIC ATTR_PERTASK struct vm_node
this_kernel_stackguard_ ASMNAME("this_kernel_stackguard") = {
	/* .vn_node      = */ { NULL, NULL, 0, 0 },
	/* .vn_byaddr    = */ LLIST_INITNODE,
	/* .vn_prot      = */ VM_PROT_SHARED,
	/* .vn_flags     = */ VM_NODE_FLAG_NOMERGE | VM_NODE_FLAG_PREPARED,
	/* .vn_vm        = */ &vm_kernel,
	/* .vn_part      = */ NULL, /* Reservation */
	/* .vn_block     = */ NULL, /* Reservation */
	/* .vn_fspath    = */ NULL,
	/* .vn_fsname    = */ NULL,
	/* .vn_link      = */ { NULL, NULL },
	/* .vn_guard     = */ 0
};
#endif /* CONFIG_HAVE_KERNEL_STACK_GUARD */





typedef void (KCALL *pertask_init_t)(struct task *__restrict self);
INTDEF pertask_init_t __kernel_pertask_init_start[];
INTDEF pertask_init_t __kernel_pertask_init_end[];
INTDEF FREE void NOTHROW(KCALL kernel_initialize_scheduler_arch)(void);

LOCAL ATTR_FREETEXT void
NOTHROW(KCALL initialize_predefined_vm_trampoline)(struct task *__restrict self,
                                                   pageid_t vpage) {
	FORTASK(self, this_trampoline_node).vn_node.a_vmin = vpage;
	FORTASK(self, this_trampoline_node).vn_node.a_vmax = vpage;
	/* Load the trampoline node into the kernel VM. */
	assert(FORTASK(self, this_trampoline_node).vn_vm == &vm_kernel);
	vm_node_insert(&FORTASK(self, this_trampoline_node));
}

#ifdef ARCH_PAGEDIR_NEED_PERPARE_FOR_KERNELSPACE
/* Prepare 2 consecutive (and 2-page aligned) pages of virtual
 * memory for the purpose of doing the initial prepare required
 * for `THIS_TRAMPOLINE_PAGE' of `_boottask' and also `_bootidle' */
INTDEF NOBLOCK FREE void *
NOTHROW(FCALL kernel_initialize_boot_trampolines)(void);
#endif /* ARCH_PAGEDIR_NEED_PERPARE_FOR_KERNELSPACE */

PUBLIC ATTR_PERTASK struct exception_info this_exception_info = {};


#ifdef CONFIG_HAVE_KERNEL_STACK_GUARD
INTDEF byte_t __kernel_boottask_stack_guard_pageid[];
INTDEF byte_t __kernel_asyncwork_stack_guard_pageid[];
INTDEF byte_t __kernel_bootidle_stack_guard_pageid[];
#endif /* CONFIG_HAVE_KERNEL_STACK_GUARD */


INTERN ATTR_FREETEXT void
NOTHROW(KCALL kernel_initialize_scheduler)(void) {
	void *boot_trampoline_pages;
	DEFINE_PUBLIC_SYMBOL(this_task, offsetof(struct task, t_self), sizeof(struct task));
	DEFINE_PUBLIC_SYMBOL(this_cpu, offsetof(struct task, t_cpu), sizeof(struct cpu *));
	DEFINE_PUBLIC_SYMBOL(this_vm, offsetof(struct task, t_vm), sizeof(struct vm *));
	DEFINE_PUBLIC_SYMBOL(this_sstate, offsetof(struct task, t_state), sizeof(struct scpustate *));
	DEFINE_PUBLIC_SYMBOL(this_exception_code, &this_exception_info.ei_code, sizeof(this_exception_info.ei_code));
	DEFINE_PUBLIC_SYMBOL(this_exception_data, &this_exception_info.ei_data, sizeof(this_exception_info.ei_data));
	DEFINE_PUBLIC_SYMBOL(this_exception_state, &this_exception_info.ei_state, sizeof(this_exception_info.ei_state));
	DEFINE_PUBLIC_SYMBOL(this_exception_class, &this_exception_info.ei_class, sizeof(this_exception_info.ei_class));
	DEFINE_PUBLIC_SYMBOL(this_exception_subclass, &this_exception_info.ei_subclass, sizeof(this_exception_info.ei_subclass));
	DEFINE_PUBLIC_SYMBOL(this_exception_args, &this_exception_info.ei_data.e_args, sizeof(this_exception_info.ei_data.e_args));
	DEFINE_PUBLIC_SYMBOL(this_exception_flags, &this_exception_info.ei_flags, sizeof(this_exception_info.ei_flags));
	DEFINE_PUBLIC_SYMBOL(this_exception_faultaddr, &this_exception_info.ei_data.e_faultaddr, sizeof(this_exception_info.ei_data.e_faultaddr));
#if EXCEPT_BACKTRACE_SIZE != 0
	DEFINE_PUBLIC_SYMBOL(this_exception_trace, &this_exception_info.ei_trace[0], sizeof(this_exception_info.ei_trace));
#else /* EXCEPT_BACKTRACE_SIZE != 0 */
	DEFINE_PUBLIC_SYMBOL(this_exception_trace, 0, 0);
#endif /* EXCEPT_BACKTRACE_SIZE == 0 */
	DEFINE_PUBLIC_SYMBOL(thiscpu_id, offsetof(struct cpu, c_id), sizeof(unsigned int));
#ifndef CONFIG_NO_SMP
	DEFINE_PUBLIC_SYMBOL(thiscpu_pdir, offsetof(struct cpu, c_pdir), sizeof(pagedir_phys_t));
#else /* !CONFIG_NO_SMP */
	DEFINE_PUBLIC_SYMBOL(thiscpu_pdir, 0, 0);
#endif /* CONFIG_NO_SMP */
	DEFINE_PUBLIC_SYMBOL(thiscpu_state, offsetof(struct cpu, c_state), sizeof(u16));
	DEFINE_PUBLIC_SYMBOL(thisvm_pdir_phys, offsetof(struct vm, v_pdir_phys), sizeof(physaddr_t));

	assert(_boottask.t_refcnt == 1);
	assert(_bootidle.t_refcnt == 1);
	assert(_asyncwork.t_refcnt == 1);

	/* Figure out where to put the initial trampolines for _boottask and _bootidle */
#ifdef ARCH_PAGEDIR_NEED_PERPARE_FOR_KERNELSPACE
	boot_trampoline_pages = kernel_initialize_boot_trampolines();
#else /* ARCH_PAGEDIR_NEED_PERPARE_FOR_KERNELSPACE */
	boot_trampoline_pages = vm_getfree(&vm_kernel,
	                                   HINT_GETADDR(KERNEL_VMHINT_TRAMPOLINE),
	                                   /* num_pages: */ 2 * PAGESIZE,
	                                   /* alignment: */ 1 * PAGESIZE,
	                                   HINT_GETMODE(KERNEL_VMHINT_TRAMPOLINE));
#endif /* !ARCH_PAGEDIR_NEED_PERPARE_FOR_KERNELSPACE */

	/* Construct the trampoline node for the predefined tasks. */
	initialize_predefined_vm_trampoline(&_boottask, PAGEID_ENCODE((byte_t *)boot_trampoline_pages + 0 * PAGESIZE));
	initialize_predefined_vm_trampoline(&_bootidle, PAGEID_ENCODE((byte_t *)boot_trampoline_pages + 1 * PAGESIZE));
	initialize_predefined_vm_trampoline(&_asyncwork, PAGEID_ENCODE((byte_t *)boot_trampoline_pages + 2 * PAGESIZE));

#define REL(x, offset) ((x) = (__typeof__(x))(uintptr_t)((byte_t *)(x) + (uintptr_t)(offset)))
	/* _boottask */
	REL(FORTASK(&_boottask, this_kernel_stacknode_).vn_part, &_boottask);
	REL(FORTASK(&_boottask, this_kernel_stacknode_).vn_link.ln_pself, &_boottask);
	REL(FORTASK(&_boottask, this_kernel_stackpart_).dp_srefs, &_boottask);
	REL(FORTASK(&_boottask, this_kernel_stackpart_).dp_ramdata.rd_blockv, &_boottask);
	{
		pageid_t boottask_stack_pageid = (pageid_t)loadfarptr(__kernel_boottask_stack_pageid);
		FORTASK(&_boottask, this_kernel_stacknode_).vn_node.a_vmin = boottask_stack_pageid;
		FORTASK(&_boottask, this_kernel_stacknode_).vn_node.a_vmax = boottask_stack_pageid + CEILDIV(KERNEL_STACKSIZE, PAGESIZE) - 1;
	}
	FORTASK(&_boottask, this_kernel_stackpart_).dp_ramdata.rd_block0.rb_start = (physpage_t)loadfarptr(__kernel_boottask_stack_pageptr);
#ifdef CONFIG_HAVE_KERNEL_STACK_GUARD
	{
		pageid_t boottask_stack_guard_pageid = (pageid_t)loadfarptr(__kernel_boottask_stack_guard_pageid);
		FORTASK(&_boottask, this_kernel_stackguard_).vn_node.a_vmin = boottask_stack_guard_pageid;
		FORTASK(&_boottask, this_kernel_stackguard_).vn_node.a_vmax = boottask_stack_guard_pageid;
	}
#endif /* CONFIG_HAVE_KERNEL_STACK_GUARD */


	/* _asyncwork */
	REL(FORTASK(&_asyncwork, this_kernel_stacknode_).vn_part, &_asyncwork);
	REL(FORTASK(&_asyncwork, this_kernel_stacknode_).vn_link.ln_pself, &_asyncwork);
	REL(FORTASK(&_asyncwork, this_kernel_stackpart_).dp_srefs, &_asyncwork);
	REL(FORTASK(&_asyncwork, this_kernel_stackpart_).dp_ramdata.rd_blockv, &_asyncwork);
	{
		pageid_t asyncwork_stack_pageid = (pageid_t)loadfarptr(__kernel_asyncwork_stack_pageid);
		FORTASK(&_asyncwork, this_kernel_stacknode_).vn_node.a_vmin = asyncwork_stack_pageid;
		FORTASK(&_asyncwork, this_kernel_stacknode_).vn_node.a_vmax = asyncwork_stack_pageid + CEILDIV(KERNEL_STACKSIZE, PAGESIZE) - 1;
	}
	FORTASK(&_asyncwork, this_kernel_stackpart_).dp_ramdata.rd_block0.rb_start = (physpage_t)loadfarptr(__kernel_asyncwork_stack_pageptr);
#ifdef CONFIG_HAVE_KERNEL_STACK_GUARD
	{
		pageid_t asyncwork_stack_guard_pageid = (pageid_t)loadfarptr(__kernel_asyncwork_stack_guard_pageid);
		FORTASK(&_asyncwork, this_kernel_stackguard_).vn_node.a_vmin = asyncwork_stack_guard_pageid;
		FORTASK(&_asyncwork, this_kernel_stackguard_).vn_node.a_vmax = asyncwork_stack_guard_pageid;
	}
#endif /* CONFIG_HAVE_KERNEL_STACK_GUARD */

	/* _bootidle */
	REL(FORTASK(&_bootidle, this_kernel_stacknode_).vn_part, &_bootidle);
	REL(FORTASK(&_bootidle, this_kernel_stacknode_).vn_link.ln_pself, &_bootidle);
	REL(FORTASK(&_bootidle, this_kernel_stackpart_).dp_srefs, &_bootidle);
	REL(FORTASK(&_bootidle, this_kernel_stackpart_).dp_ramdata.rd_blockv, &_bootidle);
	{
		pageid_t bootidle_stack_pageid = (pageid_t)loadfarptr(__kernel_bootidle_stack_pageid);
		FORTASK(&_bootidle, this_kernel_stacknode_).vn_node.a_vmin = bootidle_stack_pageid;
		FORTASK(&_bootidle, this_kernel_stacknode_).vn_node.a_vmax = bootidle_stack_pageid + CEILDIV(KERNEL_IDLE_STACKSIZE, PAGESIZE) - 1;
	}
	FORTASK(&_bootidle, this_kernel_stackpart_).dp_ramdata.rd_block0.rb_start = (physpage_t)loadfarptr(__kernel_bootidle_stack_pageptr);
	FORTASK(&_bootidle, this_kernel_stackpart_).dp_ramdata.rd_block0.rb_size  = CEILDIV(KERNEL_IDLE_STACKSIZE, PAGESIZE);
	FORTASK(&_bootidle, this_kernel_stackpart_).dp_tree.a_vmax                = (datapage_t)(CEILDIV(KERNEL_IDLE_STACKSIZE, PAGESIZE) - 1);
#ifdef CONFIG_HAVE_KERNEL_STACK_GUARD
	{
		pageid_t bootidle_stack_guard_pageid = (pageid_t)loadfarptr(__kernel_bootidle_stack_guard_pageid);
		FORTASK(&_bootidle, this_kernel_stackguard_).vn_node.a_vmin = bootidle_stack_guard_pageid;
		FORTASK(&_bootidle, this_kernel_stackguard_).vn_node.a_vmax = bootidle_stack_guard_pageid;
	}
#endif /* CONFIG_HAVE_KERNEL_STACK_GUARD */
#undef REL

	FORTASK(&_boottask, this_fs) = &fs_kernel;
	FORTASK(&_bootidle, this_fs) = &fs_kernel;
#ifndef CONFIG_EVERYONE_IS_ROOT
	FORTASK(&_boottask, this_cred) = &cred_kernel;
	FORTASK(&_bootidle, this_cred) = &cred_kernel;
#endif /* !CONFIG_EVERYONE_IS_ROOT */
	FORTASK(&_boottask, this_handle_manager) = &handle_manager_kernel;
	FORTASK(&_bootidle, this_handle_manager) = &handle_manager_kernel;

	/* The stack of IDLE threads is executable in order to allow for hacking around .free restrictions. */
	FORTASK(&_bootidle, this_kernel_stacknode_).vn_prot = (VM_PROT_EXEC | VM_PROT_WRITE | VM_PROT_READ);

	vm_kernel.v_tasks              = &_boottask;
	_boottask.t_vm_tasks.ln_pself  = &vm_kernel.v_tasks;
	_boottask.t_vm_tasks.ln_next   = &_asyncwork;
	_asyncwork.t_vm_tasks.ln_pself = &_boottask.t_vm_tasks.ln_next;
	_asyncwork.t_vm_tasks.ln_next  = &_bootidle;
	_bootidle.t_vm_tasks.ln_pself  = &_asyncwork.t_vm_tasks.ln_next;
	assert(_bootidle.t_vm_tasks.ln_next == NULL);

	_boottask.t_refcnt  = 2; /* +1: scheduler chain, +1: public symbol `_boottask' */
	_asyncwork.t_refcnt = 2; /* +1: scheduler chain, +1: intern symbol `_asyncwork' */
	_bootidle.t_refcnt  = 2; /* +1: scheduler chain, +1: public symbol `_bootidle' */

	_boottask.t_flags  = TASK_FCRITICAL | TASK_FSTARTED | TASK_FRUNNING;
	_asyncwork.t_flags = TASK_FCRITICAL | TASK_FSTARTED | TASK_FRUNNING | TASK_FKERNTHREAD;
	_bootidle.t_flags  = TASK_FCRITICAL | TASK_FSTARTED | TASK_FKEEPCORE | TASK_FKERNTHREAD;

	/* Initialize the boot CPU's scheduler. */
	FORTASK(&_boottask, this_sched_link).le_prev  = &FORCPU(&_bootcpu, thiscpu_scheduler).s_running.lh_first;
	FORTASK(&_boottask, this_sched_link).le_next  = &_asyncwork;
	FORTASK(&_asyncwork, this_sched_link).le_prev = &FORTASK(&_boottask, this_sched_link).le_next;
	/*FORTASK(&_asyncwork, this_sched_link).ln_next = NULL;*/
	FORCPU(&_bootcpu, thiscpu_scheduler).s_running.lh_first = &_boottask;
	FORCPU(&_bootcpu, thiscpu_scheduler).s_running_last     = &_asyncwork;
	FORCPU(&_bootcpu, thiscpu_scheduler).s_runcount         = 2;

	_boottask.t_self  = &_boottask;
	_bootidle.t_self  = &_bootidle;
	_asyncwork.t_self = &_asyncwork;

	FORCPU(&_bootcpu, thiscpu_sched_current) = &_boottask;

	kernel_initialize_scheduler_arch();
}

INTERN ATTR_FREETEXT void
NOTHROW(KCALL kernel_initialize_scheduler_callbacks)(void) {
	/* Execute initializers for the boot & idle thread. */
	pertask_init_t *iter;
	iter = __kernel_pertask_init_start;
	for (; iter < __kernel_pertask_init_end; ++iter) {
		(**iter)(&_boottask);
		(**iter)(&_bootidle);
		(**iter)(&_asyncwork);
	}
}











DATDEF ATTR_PERTASK struct vm_datapart this_kernel_stackpart_ ASMNAME("this_kernel_stackpart");
DATDEF ATTR_PERTASK struct vm_node this_kernel_stacknode_ ASMNAME("this_kernel_stacknode");

/* Called with a lock to the kernel VM's treelock held. */
PRIVATE NOBLOCK void
NOTHROW(KCALL task_destroy_raw_impl)(struct task *__restrict self) {
	struct vm_node *node;
	void *addr;
	size_t size;
	assertf(self != &_boottask &&
	        self != &_bootidle &&
	        self != &_asyncwork,
	        "Cannot destroy the BOOT or IDLE task of CPU0\n"
	        "self        = %p\n"
	        "&_boottask  = %p\n"
	        "&_bootidle  = %p\n"
	        "&_asyncwork = %p\n",
	        self, &_boottask, &_bootidle, &_asyncwork);
	assert(sync_writing(&vm_kernel.v_treelock));
	assert((self->t_flags & TASK_FTERMINATED) || !(self->t_flags & TASK_FSTARTED));

	/* Unlink + unmap the trampoline node. */
	node = vm_paged_node_remove(&vm_kernel, FORTASK(self, this_trampoline_node).vn_node.a_vmin);
	assertf(node == &FORTASK(self, this_trampoline_node),
	        "node                                 = %p\n"
	        "&FORTASK(self, this_trampoline_node) = %p\n"
	        "self                                 = %p\n",
	        node, &FORTASK(self, this_trampoline_node), self);
	addr = vm_node_getstart(node);
	pagedir_unmapone(addr);
	vm_supersyncone(addr);
#ifdef ARCH_PAGEDIR_NEED_PERPARE_FOR_KERNELSPACE
	pagedir_unprepare_mapone(addr);
#endif /* ARCH_PAGEDIR_NEED_PERPARE_FOR_KERNELSPACE */

	/* Unlink + unmap the stack node. */
#ifdef CONFIG_HAVE_KERNEL_STACK_GUARD
	node = vm_paged_node_remove(&vm_kernel, FORTASK(self, this_kernel_stackguard_).vn_node.a_vmin);
	assertf(node == &FORTASK(self, this_kernel_stackguard_),
	        "node                                   = %p\n"
	        "&FORTASK(self, this_kernel_stackguard) = %p\n"
	        "self                                   = %p\n",
	        node, &FORTASK(self, this_kernel_stackguard_), self);
#endif /* CONFIG_HAVE_KERNEL_STACK_GUARD */
	node = vm_paged_node_remove(&vm_kernel, FORTASK(self, this_kernel_stacknode_).vn_node.a_vmin);
	assertf(node == &FORTASK(self, this_kernel_stacknode_),
	        "node                                  = %p\n"
	        "&FORTASK(self, this_kernel_stacknode) = %p\n"
	        "self                                  = %p\n",
	        node, &FORTASK(self, this_kernel_stacknode_), self);
	addr = vm_node_getstart(node);
	size = vm_node_getsize(node);
	pagedir_unmap(addr, size);
	vm_supersync(addr, size);
#ifdef ARCH_PAGEDIR_NEED_PERPARE_FOR_KERNELSPACE
	pagedir_unprepare_map(addr, size);
#endif /* ARCH_PAGEDIR_NEED_PERPARE_FOR_KERNELSPACE */

	/* Deallocate the kernel stack. */
	vm_datapart_do_freeram(&FORTASK(self, this_kernel_stackpart_));

	{
		REF struct vm *myvm = self->t_vm;
		COMPILER_READ_BARRIER();
		if (self->t_vm_tasks.ln_pself) {
			struct task *next;
			if (vm_tasklock_trywrite(myvm)) {
				LLIST_REMOVE(self, t_vm_tasks);
				vm_tasklock_endwrite(myvm);
				goto do_free_self;
			}
			/* Truncate the task structure so that it will only still
			 * contain the per-vm task chain, as well as the next link. */
			self->t_heapsz = heap_truncate(&kernel_locked_heap,
			                               self,
			                               self->t_heapsz,
			                               MAX(MAX(COMPILER_OFFSETAFTER(struct task, t_vm_tasks),
			                                       KEY_task_vm_dead__next_offsetafter),
			                                   COMPILER_OFFSETAFTER(struct task, t_heapsz)),
			                               GFP_NORMAL);
			/* Schedule our task for pending removal within its associated VM.
			 * The next time someone acquires a lock to the VM's task-chain,
			 * we will be removed automatically, and finally freed. */
			do {
				next = ATOMIC_READ(myvm->v_deltasks);
				ATOMIC_WRITE(KEY_task_vm_dead__next(self), next);
			} while (!ATOMIC_CMPXCH_WEAK(myvm->v_deltasks, next, self));
			vm_tasklock_tryservice(myvm);
		} else {
do_free_self:
			heap_free(&kernel_locked_heap, self, self->t_heapsz, GFP_NORMAL);
		}
		decref(myvm);
	}
}


typedef void (KCALL *pertask_fini_t)(struct task *__restrict self);
INTDEF pertask_fini_t __kernel_pertask_fini_start[];
INTDEF pertask_fini_t __kernel_pertask_fini_end[];

PUBLIC NOBLOCK NONNULL((1)) void
NOTHROW(KCALL task_destroy)(struct task *__restrict self) {
	pertask_fini_t *iter;
	assert(self->t_refcnt == 0);
	assert(self->t_self == self);
	assert((self->t_flags & TASK_FTERMINATED) || !(self->t_flags & TASK_FSTARTED));

	/* Run task finalizers. */
	iter = __kernel_pertask_fini_start;
	for (; iter < __kernel_pertask_fini_end; ++iter)
		(**iter)(self);
	if (vm_kernel_treelock_trywrite()) {
		task_destroy_raw_impl(self);
		vm_kernel_treelock_endwrite();
	} else {
		struct vm_kernel_pending_operation *mine, *next;
		/* Schedule the task to-be destroyed later. */
		mine = (struct vm_kernel_pending_operation *)self;
		mine->vkpo_exec = (vm_kernel_pending_cb_t)&task_destroy_raw_impl;
		do {
			next = ATOMIC_READ(vm_kernel_pending_operations);
			mine->vkpo_next = next;
			COMPILER_WRITE_BARRIER();
		} while (!ATOMIC_CMPXCH_WEAK(vm_kernel_pending_operations,
		                             next, mine));
		vm_kernel_treelock_tryservice();
	}
}

PUBLIC ATTR_MALLOC WUNUSED ATTR_RETNONNULL REF struct task *
(KCALL task_alloc)(struct vm *__restrict task_vm) THROWS(E_WOULDBLOCK, E_BADALLOC) {
	REF struct task *result;
	struct heapptr resptr;
	/* Allocate a new task structure. */
	resptr = heap_alloc(&kernel_locked_heap,
	                    (size_t)__kernel_pertask_size,
	                    GFP_LOCKED | GFP_PREFLT);
	result = (REF struct task *)resptr.hp_ptr;
	/* Copy the per-task initialization template. */
	memcpy(result, __kernel_pertask_start, (size_t)__kernel_pertask_size);
	result->t_heapsz = resptr.hp_siz;
	result->t_self   = result;
	incref(&vm_datablock_anonymous); /* FORTASK(result,this_kernel_stacknode_).vn_block */
	incref(&vm_datablock_anonymous); /* FORTASK(result,this_kernel_stackpart_).dp_block */
#define REL(x) ((x) = (__typeof__(x))(uintptr_t)((byte_t *)(x) + (uintptr_t)(result)))
	REL(FORTASK(result, this_kernel_stacknode_).vn_part);
	REL(FORTASK(result, this_kernel_stacknode_).vn_link.ln_pself);
	REL(FORTASK(result, this_kernel_stackpart_).dp_srefs);
#undef REL
	TRY {
		vm_datapart_do_allocram(&FORTASK(result, this_kernel_stackpart_));
		TRY {
			void *stack_addr;
			void *trampoline_addr;
			uintptr_t version = 0;
again_lock_vm:
			vm_kernel_treelock_write();
#ifdef CONFIG_HAVE_KERNEL_STACK_GUARD
			stack_addr = vm_getfree(&vm_kernel,
			                        HINT_GETADDR(KERNEL_VMHINT_KERNSTACK),
			                        CEIL_ALIGN(KERNEL_STACKSIZE, PAGESIZE) + PAGESIZE,
			                        PAGESIZE,
			                        HINT_GETMODE(KERNEL_VMHINT_KERNSTACK));
#else /* CONFIG_HAVE_KERNEL_STACK_GUARD */
			stack_addr = vm_getfree(&vm_kernel,
			                        HINT_GETADDR(KERNEL_VMHINT_KERNSTACK),
			                        CEIL_ALIGN(KERNEL_STACKSIZE, PAGESIZE),
			                        PAGESIZE,
			                        HINT_GETMODE(KERNEL_VMHINT_KERNSTACK));
#endif /* !CONFIG_HAVE_KERNEL_STACK_GUARD */
			if unlikely(stack_addr == VM_GETFREE_ERROR) {
				vm_kernel_treelock_endwrite();
				if (system_clearcaches_s(&version))
					goto again_lock_vm;
				THROW(E_BADALLOC_INSUFFICIENT_VIRTUAL_MEMORY,
				      CEIL_ALIGN(KERNEL_STACKSIZE, PAGESIZE));
			}
			{
				pageid_t stackpage;
				stackpage = PAGEID_ENCODE((byte_t *)stack_addr);
#ifdef CONFIG_HAVE_KERNEL_STACK_GUARD
				FORTASK(result, this_kernel_stackguard_).vn_node.a_vmin = stackpage;
				FORTASK(result, this_kernel_stackguard_).vn_node.a_vmax = stackpage;
				FORTASK(result, this_kernel_stacknode_).vn_node.a_vmin  = stackpage + 1;
				FORTASK(result, this_kernel_stacknode_).vn_node.a_vmax  = stackpage + 1 + CEILDIV(KERNEL_STACKSIZE, PAGESIZE) - 1;
				stack_addr = (byte_t *)stack_addr + PAGESIZE;
#else  /* CONFIG_HAVE_KERNEL_STACK_GUARD */
				FORTASK(result, this_kernel_stacknode_).vn_node.a_vmin = stackpage;
				FORTASK(result, this_kernel_stacknode_).vn_node.a_vmax = stackpage + CEILDIV(KERNEL_STACKSIZE, PAGESIZE) - 1;
#endif /* !CONFIG_HAVE_KERNEL_STACK_GUARD */
			}
#ifdef ARCH_PAGEDIR_NEED_PERPARE_FOR_KERNELSPACE
			if unlikely(!pagedir_prepare_map(stack_addr, CEIL_ALIGN(KERNEL_STACKSIZE, PAGESIZE))) {
				vm_kernel_treelock_endwrite();
				THROW(E_BADALLOC_INSUFFICIENT_PHYSICAL_MEMORY, PAGESIZE);
			}
#endif /* ARCH_PAGEDIR_NEED_PERPARE_FOR_KERNELSPACE */

			/* Map the trampoline node. */
			trampoline_addr = vm_getfree(&vm_kernel,
			                             HINT_GETADDR(KERNEL_VMHINT_TRAMPOLINE),
			                             PAGESIZE, PAGESIZE,
			                             HINT_GETMODE(KERNEL_VMHINT_TRAMPOLINE));
			if unlikely(trampoline_addr == VM_GETFREE_ERROR) {
				vm_kernel_treelock_endwrite();
				if (system_clearcaches_s(&version))
					goto again_lock_vm;
				THROW(E_BADALLOC_INSUFFICIENT_VIRTUAL_MEMORY, PAGESIZE);
			}
			FORTASK(result, this_trampoline_node).vn_node.a_vmin = PAGEID_ENCODE(trampoline_addr);
			FORTASK(result, this_trampoline_node).vn_node.a_vmax = PAGEID_ENCODE(trampoline_addr);
#ifdef ARCH_PAGEDIR_NEED_PERPARE_FOR_KERNELSPACE
			if unlikely(!pagedir_prepare_mapone(trampoline_addr))
				THROW(E_BADALLOC_INSUFFICIENT_PHYSICAL_MEMORY, PAGESIZE);
#endif /* ARCH_PAGEDIR_NEED_PERPARE_FOR_KERNELSPACE */
			/* Load nodes into the kernel VM. */
			vm_node_insert(&FORTASK(result, this_trampoline_node));
			vm_node_insert(&FORTASK(result, this_kernel_stacknode_));
#ifdef CONFIG_HAVE_KERNEL_STACK_GUARD
			vm_node_insert(&FORTASK(result, this_kernel_stackguard_));
#endif /* CONFIG_HAVE_KERNEL_STACK_GUARD */

			/* Map the stack into memory */
			vm_datapart_map_ram(&FORTASK(result, this_kernel_stackpart_), stack_addr,
			                    PAGEDIR_MAP_FREAD | PAGEDIR_MAP_FWRITE);
			vm_kernel_treelock_endwrite();
		} EXCEPT {
			vm_datapart_do_ccfreeram(&FORTASK(result, this_kernel_stackpart_));
			RETHROW();
		}
	} EXCEPT {
		decref_nokill(&vm_datablock_anonymous); /* FORTASK(result,this_kernel_stackpart_).dp_block */
		decref_nokill(&vm_datablock_anonymous); /* FORTASK(result,this_kernel_stacknode_).vn_block */
		heap_free(&kernel_locked_heap,
		          resptr.hp_ptr,
		          resptr.hp_siz,
		          GFP_NORMAL);
		RETHROW();
	}

	result->t_vm = task_vm;
	incref(task_vm);

	/* Run custom initializers. */
	TRY {
		pertask_init_t *iter;
		assert(!result->t_vm_tasks.ln_pself);

		/* Insert the new task into the VM */
		vm_tasklock_write(task_vm);
		LLIST_INSERT(task_vm->v_tasks, result, t_vm_tasks);
		vm_tasklock_endwrite(task_vm);

		iter = __kernel_pertask_init_start;
		for (; iter < __kernel_pertask_init_end; ++iter)
			(**iter)(result);
	} EXCEPT {
		ATOMIC_WRITE(result->t_refcnt, 0);
		/* Destroy the task if an initializer threw another exception. */
		task_destroy(result);
		RETHROW();
	}
	return result;
}


#if 0
typedef void (KCALL *pertask_clone_t)(struct task *__restrict new_thread, uintptr_t flags);
INTDEF pertask_clone_t __kernel_pertask_clone_start[];
INTDEF pertask_clone_t __kernel_pertask_clone_end[];


/* High-level kernel interface for the clone(2) system call.
 * @param: clone_flags: Set of `TASK_CLONE_*' */
PUBLIC ATTR_RETNONNULL WUNUSED NONNULL((1, 2)) REF struct task *
(KCALL task_clone)(uintptr_t clone_flags)
		THROWS(E_BADALLOC, E_WOULDBLOCK) {
	REF struct task *result;
	if (clone_flags & TASK_CLONE_VM) {
		result = task_alloc(THIS_VM);
	} else {
		REF struct vm *result_vm;
		result_vm = vm_clone(THIS_VM, false);
		FINALLY_DECREF_UNLIKELY(result_vm);
		result = task_alloc(result_vm);
	}
	TRY {
		/* Invoke additional callbacks. */
		{
			pertask_clone_t *iter;
			for (iter = __kernel_pertask_clone_start;
			     iter < __kernel_pertask_clone_end; ++iter)
				(**iter)(result, clone_flags);
		}
	} EXCEPT {
		decref_likely(result);
		RETHROW();
	}
	return result;
}
#endif



/************************************************************************/
/* exit(), exit_group()                                                 */
/************************************************************************/
#ifdef __ARCH_WANT_SYSCALL_EXIT
DEFINE_SYSCALL1(void, exit, syscall_ulong_t, exit_code) {
	COMPILER_IMPURE();
	THROW(E_EXIT_THREAD, W_EXITCODE(exit_code & 0xff, 0));
}
#endif /* __ARCH_WANT_SYSCALL_EXIT */

#ifdef __ARCH_WANT_SYSCALL_EXIT_GROUP
DEFINE_SYSCALL1(void, exit_group, syscall_ulong_t, exit_code) {
	COMPILER_IMPURE();
	THROW(E_EXIT_PROCESS, W_EXITCODE(exit_code & 0xff, 0));
}
#endif /* __ARCH_WANT_SYSCALL_EXIT_GROUP */

DECL_END

#endif /* !GUARD_KERNEL_SRC_SCHED_TASK_C */
