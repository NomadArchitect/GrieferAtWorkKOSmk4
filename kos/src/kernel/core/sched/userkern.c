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
#ifndef GUARD_KERNEL_SRC_SCHED_USERKERN_C
#define GUARD_KERNEL_SRC_SCHED_USERKERN_C 1
#define __WANT_MPART_INIT

#include <kernel/compiler.h>

#include <sched/userkern.h>
#ifndef CONFIG_NO_USERKERN_SEGMENT

#include <kernel/except.h>
#include <kernel/paging.h>
#include <kernel/printk.h>
#include <kernel/syscall.h>
#include <kernel/vm.h>
#include <sched/cred.h>
#include <sched/pertask.h>
#include <sched/pid.h>

#include <compat/config.h>
#include <kos/bits/ukern-struct.h>
#include <kos/except/reason/inval.h>
#include <kos/kernel/cpu-state-helpers.h>
#include <kos/kernel/cpu-state.h>
#include <kos/ukern.h>

#include <stddef.h>

#include <libvio/vio.h>

#ifdef __ARCH_HAVE_COMPAT
#include <hybrid/byteorder.h>

#include <kos/bits/ukern-struct32.h>
#include <kos/bits/ukern-struct64.h>
#endif /* __ARCH_HAVE_COMPAT */


#ifdef KERNELSPACE_HIGHMEM
#define KS_MINADDR ((uintptr_t)KERNELSPACE_BASE)
#define KS_MAXADDR ((uintptr_t)-1)
#elif defined(KERNELSPACE_LOWMEM)
#define KS_MINADDR ((uintptr_t)0)
#define KS_MAXADDR ((uintptr_t)(KERNELSPACE_END - 1))
#else /* KERNELSPACE_...MEM */
#define KS_MINADDR ((uintptr_t)KERNELSPACE_BASE)
#define KS_MAXADDR ((uintptr_t)(KERNELSPACE_END - 1))
#endif /* !KERNELSPACE_...MEM */

DECL_BEGIN

/* These 2 functions must be overwritten to implement arch-specific behavior.
 * Mainly: To implement access to the register identity map structure. */
INTDEF NONNULL((1)) bool KCALL userkern_get_arch_specific_field(struct vioargs *__restrict args, uintptr_t offset, uintptr_t *__restrict presult);
INTDEF NONNULL((1)) bool KCALL userkern_set_arch_specific_field(struct vioargs *__restrict args, uintptr_t offset, uintptr_t value);
#ifdef __ARCH_HAVE_COMPAT
INTDEF NONNULL((1)) bool KCALL userkern_get_arch_specific_field_compat(struct vioargs *__restrict args, uintptr_t offset, __ARCH_COMPAT_UINTPTR_TYPE *__restrict presult);
INTDEF NONNULL((1)) bool KCALL userkern_set_arch_specific_field_compat(struct vioargs *__restrict args, uintptr_t offset, __ARCH_COMPAT_UINTPTR_TYPE value);
#endif /* __ARCH_HAVE_COMPAT */

#ifdef __INTELLISENSE__
#if __SIZEOF_POINTER__ == 4 || defined(__ARCH_HAVE_COMPAT)
PRIVATE NONNULL((1)) u32 KCALL userkern_segment_readl(struct vioargs *__restrict args, vio_addr_t addr);
PRIVATE NONNULL((1)) void KCALL userkern_segment_writel(struct vioargs *__restrict args, vio_addr_t addr, u32 value);
#endif /* __SIZEOF_POINTER__ == 4 || __ARCH_HAVE_COMPAT */
#if __SIZEOF_POINTER__ == 8 || defined(__ARCH_HAVE_COMPAT)
PRIVATE NONNULL((1)) u64 KCALL userkern_segment_readq(struct vioargs *__restrict args, vio_addr_t addr);
PRIVATE NONNULL((1)) void KCALL userkern_segment_writeq(struct vioargs *__restrict args, vio_addr_t addr, u64 value);
#endif /* __SIZEOF_POINTER__ == 8 || __ARCH_HAVE_COMPAT */
#else /* __INTELLISENSE__ */
DECL_END

#if __SIZEOF_POINTER__ == 4 || defined(__ARCH_HAVE_COMPAT)
#ifdef __ARCH_HAVE_COMPAT
#define USERKERN_STRUCT struct userkern32
#endif /* __ARCH_HAVE_COMPAT */
#define DEFINE_IO_READ 1
#define USERKERN_WIDTH 4
#include "userkern-rw.c.inl"
#ifdef __ARCH_HAVE_COMPAT
#define USERKERN_STRUCT struct userkern32
#endif /* __ARCH_HAVE_COMPAT */
#define DEFINE_IO_WRITE 1
#define USERKERN_WIDTH 4
#include "userkern-rw.c.inl"
#endif /* __SIZEOF_POINTER__ == 4 || __ARCH_HAVE_COMPAT */

#if __SIZEOF_POINTER__ == 8 || defined(__ARCH_HAVE_COMPAT)
#ifdef __ARCH_HAVE_COMPAT
#define USERKERN_STRUCT struct userkern64
#endif /* __ARCH_HAVE_COMPAT */
#define DEFINE_IO_READ 1
#define USERKERN_WIDTH 8
#include "userkern-rw.c.inl"
#ifdef __ARCH_HAVE_COMPAT
#define USERKERN_STRUCT struct userkern64
#endif /* __ARCH_HAVE_COMPAT */
#define DEFINE_IO_WRITE 1
#define USERKERN_WIDTH 8
#include "userkern-rw.c.inl"
#endif /* __SIZEOF_POINTER__ == 8 || __ARCH_HAVE_COMPAT */

DECL_BEGIN
#endif /* !__INTELLISENSE__ */


PRIVATE void KCALL
userkern_segment_call(struct vioargs *__restrict args,
                      vio_addr_t addr) {
	uintptr_t reladdr;
	uintptr_t base = get_userkern_base();
	if (!ADDR_ISKERN(base))
		goto err_invalid_addr;
#ifdef KERNELSPACE_HIGHMEM
	base -= KERNELSPACE_BASE;
#endif /* KERNELSPACE_HIGHMEM */
	if ((uintptr_t)addr < base)
		goto err_invalid_addr;
	reladdr = (uintptr_t)addr - base;
	if (!USERKERN_SYSCALL_ISVALID(reladdr))
		goto err_invalid_addr;
	/* System call invocation. */
	args->va_state = syscall_emulate_callback(args->va_state,
	                                          USERKERN_SYSCALL_DECODE(reladdr),
	                                          (reladdr & USERKERN_SYSCALL_EXCEPTBIT) != 0);
	return;
err_invalid_addr:
	THROW(E_SEGFAULT_UNMAPPED,
	      vioargs_faultaddr(args, addr),
	      E_SEGFAULT_CONTEXT_FAULT |
	      E_SEGFAULT_CONTEXT_EXEC |
	      E_SEGFAULT_CONTEXT_USERCODE);
}



#if __SIZEOF_POINTER__ >= 8
#ifndef LIBVIO_CONFIG_HAVE_QWORD
#error "Invalid configuration"
#endif /* !LIBVIO_CONFIG_HAVE_QWORD */
#define INIT_OPERATION_PTR(name) \
	{ NULL, NULL, NULL, &userkern_segment_##name##q }
#elif defined(LIBVIO_CONFIG_HAVE_QWORD)
#define INIT_OPERATION_PTR(name) \
	{ NULL, NULL, &userkern_segment_##name##l, NULL }
#else
#define INIT_OPERATION_PTR(name) \
	{ NULL, NULL, &userkern_segment_##name##l }
#endif
#ifdef LIBVIO_CONFIG_HAVE_QWORD
#define INIT_OPERATION_PTR_NULL { NULL, NULL, NULL, NULL }
#else /* LIBVIO_CONFIG_HAVE_QWORD */
#define INIT_OPERATION_PTR_NULL { NULL, NULL, NULL }
#endif /* !LIBVIO_CONFIG_HAVE_QWORD */

/* VIO bindings for the kernel-reserve segment of user-space VMs */
PUBLIC struct vio_operators userkern_segment_vio =
VIO_OPERATORS_INIT_EX(INIT_OPERATION_PTR(read),
                      INIT_OPERATION_PTR(write),
                      VIO_CALLBACK_INIT_CMPXCH(NULL, NULL, NULL, NULL, NULL),
                      VIO_CALLBACK_INIT_XCH(NULL, NULL, NULL, NULL),
                      VIO_CALLBACK_INIT_ADD(NULL, NULL, NULL, NULL),
                      VIO_CALLBACK_INIT_SUB(NULL, NULL, NULL, NULL),
                      VIO_CALLBACK_INIT_AND(NULL, NULL, NULL, NULL),
                      VIO_CALLBACK_INIT_OR(NULL, NULL, NULL, NULL),
                      VIO_CALLBACK_INIT_XOR(NULL, NULL, NULL, NULL),
                      &userkern_segment_call);
#undef INIT_OPERATION_PTR_NULL
#undef INIT_OPERATION_PTR

PUBLIC struct mpart userkern_segment_part = {
#ifdef CONFIG_USE_NEW_VM
	MPART_INIT_mp_refcnt(1),
	MPART_INIT_mp_flags(MPART_F_NO_GLOBAL_REF | MPART_F_CHANGED |
	                    MPART_F_NOSPLIT | MPART_F_NOMERGE |
	                    MPART_F_MLOCK_FROZEN | MPART_F_MLOCK),
	MPART_INIT_mp_state(MPART_ST_VIO),
	MPART_INIT_mp_file(&userkern_segment_file),
	MPART_INIT_mp_copy(LIST_HEAD_INITIALIZER(userkern_segment_part.mp_copy)),
	MPART_INIT_mp_share(LIST_HEAD_INITIALIZER(userkern_segment_part.mp_share)),
	MPART_INIT_mp_lockops(SLIST_HEAD_INITIALIZER(userkern_segment_part.mp_lockops)),
	MPART_INIT_mp_allparts(LIST_ENTRY_UNBOUND_INITIALIZER),
	MPART_INIT_mp_minaddr(0),
	MPART_INIT_mp_maxaddr(KS_MAXADDR - KS_MINADDR),
	MPART_INIT_mp_changed({}),
	MPART_INIT_mp_filent({}),
	MPART_INIT_mp_blkst_ptr(NULL),
	MPART_INIT_mp_mem(0, 0),
	MPART_INIT_mp_meta(NULL)
#else /* CONFIG_USE_NEW_VM */
	/* .dp_refcnt = */ 1,
	/* .dp_lock   = */ SHARED_RWLOCK_INIT,
	{
		/* .dp_tree_ptr = */ {
			/* .a_min = */ NULL,
			/* .a_max = */ NULL,
			{
				/* .a_vmin_ptr = */ 0
			},
			{
				/* .a_vmax_ptr = */ (KERNELSPACE_MAXPAGEID - KERNELSPACE_MINPAGEID)
			},
		}
	},
	/* .dp_crefs  = */ LLIST_INIT,
	/* .dp_srefs  = */ LLIST_INIT,
	/* .dp_stale  = */ NULL,
	/* .dp_block  = */ &userkern_segment_file,
	/* .dp_flags  = */ (VM_DATAPART_FLAG_LOCKED | VM_DATAPART_FLAG_CHANGED |
	                    VM_DATAPART_FLAG_KEEPRAM | VM_DATAPART_FLAG_HEAPPPP |
	                    VM_DATAPART_FLAG_KERNPRT),
	/* .dp_state  = */ VM_DATAPART_STATE_VIOPRT,
	{
		/* .dp_ramdata = */ {
			/* .rd_blockv = */ NULL,
			{
				/* .rd_block0 = */ {
					/* .rb_start = */ 0,
					/* .rb_size  = */ 0
				}
			}
		}
	},
	{
		/* .dp_pprop_p = */ 0
	},
	/* .dp_futex = */ NULL
#endif /* !CONFIG_USE_NEW_VM */
};


PUBLIC struct mfile userkern_segment_file = {
#ifdef CONFIG_USE_NEW_VM
	/* .mf_refcnt     = */ 2, /* +1: `userkern_segment_file', +1: `userkern_segment_part.mn_file' */
	/* .mf_ops        = */ &mfile_ndef_ops,
	/* .mf_vio        = */ &userkern_segment_vio,
	/* .mf_lock       = */ ATOMIC_RWLOCK_INIT,
	/* .mf_parts      = */ &userkern_segment_part,
	/* .mf_initdone   = */ SIG_INIT,
	/* .mf_deadparts  = */ SLIST_HEAD_INITIALIZER(~),
	/* .mf_changed    = */ SLIST_HEAD_INITIALIZER(~),
	/* .mf_blockshift = */ PAGESHIFT,
	/* .mf_part_amask = */ PAGEMASK,
#else /* CONFIG_USE_NEW_VM */
	/* .db_refcnt = */ 2,
	/* .db_lock   = */ RWLOCK_INIT,
	/* .db_type   = */ &vm_datablock_anonymous_type,
	/* .db_vio    = */ &userkern_segment_vio,
	/* .db_parts  = */ &userkern_segment_part,
	VM_DATABLOCK_INIT_PAGEINFO(0)
#endif /* !CONFIG_USE_NEW_VM */
};



#ifdef __ARCH_HAVE_COMPAT
#if __ARCH_COMPAT_SIZEOF_POINTER >= 8
#ifndef LIBVIO_CONFIG_HAVE_QWORD
#error "Invalid configuration"
#endif /* !LIBVIO_CONFIG_HAVE_QWORD */
#define INIT_OPERATION_PTR(name) \
	{ NULL, NULL, NULL, &userkern_segment_##name##q }
#elif defined(LIBVIO_CONFIG_HAVE_QWORD)
#define INIT_OPERATION_PTR(name) \
	{ NULL, NULL, &userkern_segment_##name##l, NULL }
#else
#define INIT_OPERATION_PTR(name) \
	{ NULL, NULL, &userkern_segment_##name##l }
#endif
#ifdef LIBVIO_CONFIG_HAVE_QWORD
#define INIT_OPERATION_PTR_NULL { NULL, NULL, NULL, NULL }
#else /* LIBVIO_CONFIG_HAVE_QWORD */
#define INIT_OPERATION_PTR_NULL { NULL, NULL, NULL }
#endif /* !LIBVIO_CONFIG_HAVE_QWORD */

#ifdef KERNELSPACE_HIGHMEM
#define COMPAT_ADDR_ISKERN(addr) (__CCAST(uintptr_t)(addr) >= COMPAT_KERNELSPACE_BASE)
#define COMPAT_KERNELSPACE_MINPAGEID PAGEID_ENCODE(COMPAT_KERNELSPACE_BASE)
#define COMPAT_KERNELSPACE_MAXPAGEID __ARCH_PAGEID_MAX
#elif defined(KERNELSPACE_LOWMEM)
#define COMPAT_ADDR_ISKERN(addr) (__CCAST(uintptr_t)(addr) < COMPAT_KERNELSPACE_END)
#define COMPAT_KERNELSPACE_MINPAGEID 0
#define COMPAT_KERNELSPACE_MAXPAGEID (PAGEID_ENCODE(COMPAT_KERNELSPACE_END) - 1)
#else /* KERNELSPACE_...MEM */
#define COMPAT_ADDR_ISKERN(addr) (__CCAST(uintptr_t)(addr) >= COMPAT_KERNELSPACE_BASE && __CCAST(uintptr_t)(addr) < COMPAT_KERNELSPACE_END)
#define COMPAT_KERNELSPACE_MINPAGEID PAGEID_ENCODE(COMPAT_KERNELSPACE_BASE)
#define COMPAT_KERNELSPACE_MAXPAGEID (PAGEID_ENCODE(COMPAT_KERNELSPACE_END) - 1)
#endif /* !KERNELSPACE_...MEM */



PRIVATE void KCALL
userkern_segment_call_compat(struct vioargs *__restrict args,
                             vio_addr_t addr) {
	uintptr_t reladdr;
	uintptr_t base = get_compat_userkern_base();
	if (!COMPAT_ADDR_ISKERN(base))
		goto err_invalid_addr;
#ifdef KERNELSPACE_HIGHMEM
	base -= COMPAT_KERNELSPACE_BASE;
#endif /* KERNELSPACE_HIGHMEM */
	if ((uintptr_t)addr < base)
		goto err_invalid_addr;
	reladdr = (uintptr_t)addr - base;
	if (!USERKERN_SYSCALL_ISVALID(reladdr))
		goto err_invalid_addr;
	/* System call invocation. */
	args->va_state = syscall_emulate_callback_compat(args->va_state,
	                                                 USERKERN_SYSCALL_DECODE(reladdr),
	                                                 (reladdr & USERKERN_SYSCALL_EXCEPTBIT) != 0);
	return;
err_invalid_addr:
	THROW(E_SEGFAULT_UNMAPPED,
	      vioargs_faultaddr(args, addr),
	      E_SEGFAULT_CONTEXT_FAULT |
	      E_SEGFAULT_CONTEXT_USERCODE);
}

PUBLIC struct vio_operators userkern_segment_vio_compat =
VIO_OPERATORS_INIT_EX(INIT_OPERATION_PTR(read),
                      INIT_OPERATION_PTR(write),
                      VIO_CALLBACK_INIT_CMPXCH(NULL, NULL, NULL, NULL, NULL),
                      VIO_CALLBACK_INIT_XCH(NULL, NULL, NULL, NULL),
                      VIO_CALLBACK_INIT_ADD(NULL, NULL, NULL, NULL),
                      VIO_CALLBACK_INIT_SUB(NULL, NULL, NULL, NULL),
                      VIO_CALLBACK_INIT_AND(NULL, NULL, NULL, NULL),
                      VIO_CALLBACK_INIT_OR(NULL, NULL, NULL, NULL),
                      VIO_CALLBACK_INIT_XOR(NULL, NULL, NULL, NULL),
                      &userkern_segment_call_compat);
#undef INIT_OPERATION_PTR_NULL
#undef INIT_OPERATION_PTR

PUBLIC struct vm_datapart userkern_segment_part_compat = {
#ifdef CONFIG_USE_NEW_VM
	MPART_INIT_mp_refcnt(1),
	MPART_INIT_mp_flags(MPART_F_NO_GLOBAL_REF | MPART_F_CHANGED |
	                    MPART_F_NOSPLIT | MPART_F_NOMERGE |
	                    MPART_F_MLOCK_FROZEN | MPART_F_MLOCK),
	MPART_INIT_mp_state(MPART_ST_VIO),
	MPART_INIT_mp_file(&userkern_segment_file_compat),
	MPART_INIT_mp_copy(LIST_HEAD_INITIALIZER(userkern_segment_part_compat.mp_copy)),
	MPART_INIT_mp_share(LIST_HEAD_INITIALIZER(userkern_segment_part_compat.mp_share)),
	MPART_INIT_mp_lockops(SLIST_HEAD_INITIALIZER(userkern_segment_part_compat.mp_lockops)),
	MPART_INIT_mp_allparts(LIST_ENTRY_UNBOUND_INITIALIZER),
	MPART_INIT_mp_minaddr(0),
	MPART_INIT_mp_maxaddr((((COMPAT_KERNELSPACE_MAXPAGEID - COMPAT_KERNELSPACE_MINPAGEID) + 1) * PAGESIZE) - 1),
	MPART_INIT_mp_changed({}),
	MPART_INIT_mp_filent({}),
	MPART_INIT_mp_blkst_ptr(NULL),
	MPART_INIT_mp_mem(0, 0),
	MPART_INIT_mp_meta(NULL)
#else /* CONFIG_USE_NEW_VM */
	/* .dp_refcnt = */ 1,
	/* .dp_lock   = */ SHARED_RWLOCK_INIT,
	{
		/* .dp_tree_ptr = */ {
			/* .a_min = */ NULL,
			/* .a_max = */ NULL,
			{
				/* .a_vmin_ptr = */ 0
			},
			{
				/* .a_vmax_ptr = */ (COMPAT_KERNELSPACE_MAXPAGEID - COMPAT_KERNELSPACE_MINPAGEID)
			},
		}
	},
	/* .dp_crefs  = */ LLIST_INIT,
	/* .dp_srefs  = */ LLIST_INIT,
	/* .dp_stale  = */ NULL,
	/* .dp_block  = */ &userkern_segment_file_compat,
	/* .dp_flags  = */ (VM_DATAPART_FLAG_LOCKED | VM_DATAPART_FLAG_CHANGED |
	                    VM_DATAPART_FLAG_KEEPRAM | VM_DATAPART_FLAG_HEAPPPP |
	                    VM_DATAPART_FLAG_KERNPRT),
	/* .dp_state  = */ VM_DATAPART_STATE_VIOPRT,
	{
		/* .dp_ramdata = */ {
			/* .rd_blockv = */ NULL,
			{
				/* .rd_block0 = */ {
					/* .rb_start = */ 0,
					/* .rb_size  = */ 0
				}
			}
		}
	},
	{
		/* .dp_pprop_p = */ 0
	},
	/* .dp_futex = */ NULL
#endif /* !CONFIG_USE_NEW_VM */
};

PUBLIC struct vm_datablock userkern_segment_file_compat = {
#ifdef CONFIG_USE_NEW_VM
	/* .mf_refcnt     = */ 2, /* +1: `userkern_segment_file', +1: `userkern_segment_part.mn_file' */
	/* .mf_ops        = */ &mfile_ndef_ops,
	/* .mf_vio        = */ &userkern_segment_vio_compat,
	/* .mf_lock       = */ ATOMIC_RWLOCK_INIT,
	/* .mf_parts      = */ &userkern_segment_part_compat,
	/* .mf_initdone   = */ SIG_INIT,
	/* .mf_deadparts  = */ SLIST_HEAD_INITIALIZER(~),
	/* .mf_changed    = */ SLIST_HEAD_INITIALIZER(~),
	/* .mf_blockshift = */ PAGESHIFT,
	/* .mf_part_amask = */ PAGEMASK,
#else /* CONFIG_USE_NEW_VM */
	/* .db_refcnt = */ 2,
	/* .db_lock   = */ RWLOCK_INIT,
	/* .db_type   = */ &vm_datablock_anonymous_type,
	/* .db_vio    = */ &userkern_segment_vio_compat,
	/* .db_parts  = */ &userkern_segment_part_compat,
	VM_DATABLOCK_INIT_PAGEINFO(0)
#endif /* !CONFIG_USE_NEW_VM */
};
#endif /* __ARCH_HAVE_COMPAT */


DECL_END

#endif /* !CONFIG_NO_USERKERN_SEGMENT */


#endif /* !GUARD_KERNEL_SRC_SCHED_USERKERN_C */
