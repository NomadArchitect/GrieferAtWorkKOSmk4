/* HASH CRC-32:0xe4bb4fa6 */
/* Copyright (c) 2019-2020 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2020 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_sigdelset_defined
#define __local_sigdelset_defined 1
#include <__crt.h>
#include <bits/sigset.h>
__NAMESPACE_LOCAL_BEGIN
/* @param signo: One of `SIG*' */
__LOCAL_LIBC(sigdelset) __ATTR_NONNULL((1)) int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(sigdelset))(struct __sigset_struct *__set, int __signo) {
	__ULONGPTR_TYPE__ __mask = __sigmask(__signo);
	__ULONGPTR_TYPE__ __word = __sigword(__signo);
	__set->__val[__word] &= ~__mask;
	return 0;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_sigdelset_defined
#define __local___localdep_sigdelset_defined 1
#define __localdep_sigdelset __LIBC_LOCAL_NAME(sigdelset)
#endif /* !__local___localdep_sigdelset_defined */
#endif /* !__local_sigdelset_defined */
