/* HASH CRC-32:0x16c00002 */
/* Copyright (c) 2019-2025 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2025 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef GUARD_LIBC_AUTO_LOCK_INTERN_C
#define GUARD_LIBC_AUTO_LOCK_INTERN_C 1

#include "../api.h"
#include <hybrid/typecore.h>
#include <kos/types.h>
#include "lock-intern.h"
#include "kos.sched.shared-lock.h"

DECL_BEGIN

#ifndef __KERNEL__
#include <stdalign.h>
#include <assert.h>
#include <kos/sched/shared-lock.h>
static_assert(sizeof(__spin_lock_t) == sizeof(struct shared_lock));
static_assert(alignof(__spin_lock_t) == alignof(struct shared_lock));
#endif /* !__KERNEL__ */
#ifndef __KERNEL__
INTERN ATTR_SECTION(".text.crt.compat.hurd.futex") ATTR_OUT(1) void
NOTHROW_NCX(LIBCCALL libc___spin_lock_init)(__spin_lock_t *lock) {
	*lock = 0;
}
#include <kos/bits/shared-lock.h>
INTERN ATTR_SECTION(".text.crt.compat.hurd.futex") ATTR_INOUT(1) void
NOTHROW_NCX(LIBCCALL libc___spin_lock_solid)(__spin_lock_t *lock) {
	libc_shared_lock_acquire((struct shared_lock *)lock);
}
#include <kos/bits/shared-lock.h>
INTERN ATTR_SECTION(".text.crt.compat.hurd.futex") ATTR_INOUT(1) void
NOTHROW_NCX(LIBCCALL libc___spin_unlock)(__spin_lock_t *lock) {
	libc_shared_lock_release_ex((struct shared_lock *)lock);
}
#include <kos/bits/shared-lock.h>
INTERN ATTR_SECTION(".text.crt.compat.hurd.futex") ATTR_INOUT(1) int
NOTHROW_NCX(LIBCCALL libc___spin_try_lock)(__spin_lock_t *lock) {
	return libc_shared_lock_tryacquire((struct shared_lock *)lock);
}
#include <kos/bits/shared-lock.h>
INTERN ATTR_SECTION(".text.crt.compat.hurd.futex") ATTR_IN(1) int
NOTHROW_NCX(LIBCCALL libc___spin_lock_locked)(__spin_lock_t __KOS_FIXED_CONST *lock) {
	return !__shared_lock_available((struct shared_lock *)lock);
}
#include <kos/bits/shared-lock.h>
INTERN ATTR_SECTION(".text.crt.compat.hurd.futex") ATTR_INOUT(1) void
NOTHROW_NCX(LIBCCALL libc___mutex_unlock_solid)(void *lock) {
	libc_shared_lock_waitfor((struct shared_lock *)lock);
}
#endif /* !__KERNEL__ */

DECL_END

#ifndef __KERNEL__
DEFINE_PUBLIC_ALIAS_P_VOID(__mutex_init,libc___spin_lock_init,ATTR_OUT(1),NOTHROW_NCX,LIBCCALL,(__spin_lock_t *lock),(lock));
DEFINE_PUBLIC_ALIAS_P_VOID(__spin_lock_init,libc___spin_lock_init,ATTR_OUT(1),NOTHROW_NCX,LIBCCALL,(__spin_lock_t *lock),(lock));
DEFINE_PUBLIC_ALIAS_P_VOID(__spin_lock,libc___spin_lock_solid,ATTR_INOUT(1),NOTHROW_NCX,LIBCCALL,(__spin_lock_t *lock),(lock));
DEFINE_PUBLIC_ALIAS_P_VOID(__mutex_lock,libc___spin_lock_solid,ATTR_INOUT(1),NOTHROW_NCX,LIBCCALL,(__spin_lock_t *lock),(lock));
DEFINE_PUBLIC_ALIAS_P_VOID(__mutex_lock_solid,libc___spin_lock_solid,ATTR_INOUT(1),NOTHROW_NCX,LIBCCALL,(__spin_lock_t *lock),(lock));
DEFINE_PUBLIC_ALIAS_P_VOID(mutex_wait_lock,libc___spin_lock_solid,ATTR_INOUT(1),NOTHROW_NCX,LIBCCALL,(__spin_lock_t *lock),(lock));
DEFINE_PUBLIC_ALIAS_P_VOID(__spin_lock_solid,libc___spin_lock_solid,ATTR_INOUT(1),NOTHROW_NCX,LIBCCALL,(__spin_lock_t *lock),(lock));
DEFINE_PUBLIC_ALIAS_P_VOID(__mutex_unlock,libc___spin_unlock,ATTR_INOUT(1),NOTHROW_NCX,LIBCCALL,(__spin_lock_t *lock),(lock));
DEFINE_PUBLIC_ALIAS_P_VOID(mutex_unlock,libc___spin_unlock,ATTR_INOUT(1),NOTHROW_NCX,LIBCCALL,(__spin_lock_t *lock),(lock));
DEFINE_PUBLIC_ALIAS_P_VOID(__spin_unlock,libc___spin_unlock,ATTR_INOUT(1),NOTHROW_NCX,LIBCCALL,(__spin_lock_t *lock),(lock));
DEFINE_PUBLIC_ALIAS_P(__mutex_trylock,libc___spin_try_lock,ATTR_INOUT(1),int,NOTHROW_NCX,LIBCCALL,(__spin_lock_t *lock),(lock));
DEFINE_PUBLIC_ALIAS_P(__spin_try_lock,libc___spin_try_lock,ATTR_INOUT(1),int,NOTHROW_NCX,LIBCCALL,(__spin_lock_t *lock),(lock));
DEFINE_PUBLIC_ALIAS_P(__spin_lock_locked,libc___spin_lock_locked,ATTR_IN(1),int,NOTHROW_NCX,LIBCCALL,(__spin_lock_t __KOS_FIXED_CONST *lock),(lock));
DEFINE_PUBLIC_ALIAS_P_VOID(__mutex_unlock_solid,libc___mutex_unlock_solid,ATTR_INOUT(1),NOTHROW_NCX,LIBCCALL,(void *lock),(lock));
#endif /* !__KERNEL__ */

#endif /* !GUARD_LIBC_AUTO_LOCK_INTERN_C */
