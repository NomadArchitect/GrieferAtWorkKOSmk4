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
#ifndef GUARD_KERNEL_INCLUDE_KERNEL_MMAN_MM_LOCKOP_H
#define GUARD_KERNEL_INCLUDE_KERNEL_MMAN_MM_LOCKOP_H 1

#include <kernel/compiler.h>

#include <kernel/paging.h>
#include <kernel/types.h>

#include <hybrid/sequence/list.h>

#ifdef __CC__
DECL_BEGIN

struct mman;
struct mlockop;

#ifndef __gfp_t_defined
#define __gfp_t_defined 1
typedef unsigned int gfp_t;
#endif /* !__gfp_t_defined */


/* Callback prototype for mman pending locked operations.
 * NOTE: This callback is allowed to assume that `self->mlo_link.sle_next == NULL'
 * @param: flags: A set of `GFP_*' flags that must be used in dynamic allocations.
 *                Callbacks of this type may assume that this set always contains
 *                at least `GFP_ATOMIC', and doesn't contain `GFP_CALLOC'.
 * @return: NULL: Discard this lock operation.
 * @return: * :   A chain of lock operations that should be re-scheduled
 *                to be performed the next time the mman's lock is released.
 *                Note that unlike the initial attempt, this next attempt
 *                may happen at an arbitrary point in the future, and is
 *                not guarantied to actually happen in the near future.
 *                Use this mechanism is you have to schedule a lock operation
 *                that may fail arbitrarily, and will continue to fail if one
 *                were to keep attempting it without going away to do something
 *                else before.
 *                The return value will (eventually) be re-queued as through it
 *                had been passed in a call to `mman_kernel_lockop_many()' */
typedef NOBLOCK NONNULL((1)) struct mlockop *
/*NOTHROW*/ (FCALL *mlockop_callback_t)(struct mlockop *__restrict self, gfp_t flags);

/* Memory-manager locked operation.
 * This struct describes a pending operation that should be executed
 * while holding a lock to the associated memory manager the next time
 * that someone releases its `mm_lock' */
struct mlockop {
	SLIST_ENTRY(mlockop) mlo_link; /* [lock(ATOMIC)] Next dead-ram area. */
	mlockop_callback_t   mlo_func; /* [1..1][const] Operation to perform. */
};

#ifndef __mlockop_slist_defined
#define __mlockop_slist_defined 1
SLIST_HEAD(mlockop_slist, mlockop);
#endif /* !__mlockop_slist_defined */

/* Aliasing symbol: `== FORMMAN(&mman_kernel, thismman_lockops)' */
#ifndef __mman_kernel_lockops_defined
#define __mman_kernel_lockops_defined 1
DATDEF struct mlockop_slist mman_kernel_lockops;
#endif /* !__mman_kernel_lockops_defined */

/* Run `op->mlo_func' in the context of holding a lock to the kernel VM at some
 * point in the future. The given `op->mlo_func' is responsible for freeing the
 * backing memory of `op' during its invocation. */
FUNDEF NOBLOCK NONNULL((1)) void
NOTHROW(FCALL mman_kernel_lockop)(struct mlockop *__restrict op, gfp_t flags DFL(0x0400 /*GFP_ATOMIC*/));

/* Same as `mman_kernel_lockop()', but `op->mlo_link' may point to another lock
 * op that should also be enqueued, which may point to another, and so on...
 * Additionally, `op' may be `NULL', in which case the call is a no-op */
FUNDEF NOBLOCK void
NOTHROW(FCALL mman_kernel_lockop_many)(struct mlockop *op, gfp_t flags DFL(0x0400 /*GFP_ATOMIC*/));

#ifdef __cplusplus
extern "C++" {
template<class T> FORCELOCAL NOBLOCK NONNULL((1)) void
NOTHROW(mman_kernel_lockop)(T *__restrict obj,
                            NOBLOCK struct mlockop *
                            /*NOTHROW*/ (FCALL *cb)(T *__restrict self, gfp_t flags)) {
	struct mlockop *pend;
	pend           = (struct mlockop *)obj;
	pend->mlo_func = (mlockop_callback_t)cb;
	mman_kernel_lockop(pend);
}
} /* extern "C++" */
#endif /* __cplusplus */



DECL_END
#endif /* __CC__ */

#endif /* !GUARD_KERNEL_INCLUDE_KERNEL_MMAN_MM_LOCKOP_H */