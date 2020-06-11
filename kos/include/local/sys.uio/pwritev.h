/* HASH CRC-32:0x5aebfac8 */
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
#ifndef __local_pwritev_defined
#define __local_pwritev_defined 1
#include <__crt.h>
#if defined(__CRT_HAVE_pwritev) || defined(__CRT_HAVE_pwritev64)
#include <features.h>
#include <bits/uio.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: pwritev32 from sys.uio */
#if !defined(__local___localdep_pwritev32_defined) && defined(__CRT_HAVE_pwritev)
#define __local___localdep_pwritev32_defined 1
__CREDIRECT(__ATTR_NONNULL((2)),__SSIZE_TYPE__,__NOTHROW_RPC,__localdep_pwritev32,(__fd_t __fd, struct iovec const *__iov, __STDC_INT_AS_SIZE_T __count, __off32_t __offset),pwritev,(__fd,__iov,__count,__offset))
#endif /* !__local___localdep_pwritev32_defined && __CRT_HAVE_pwritev */
/* Dependency: pwritev64 from sys.uio */
#ifndef __local___localdep_pwritev64_defined
#define __local___localdep_pwritev64_defined 1
#ifdef __CRT_HAVE_pwritev64
__CREDIRECT(__ATTR_NONNULL((2)),__SSIZE_TYPE__,__NOTHROW_RPC,__localdep_pwritev64,(__fd_t __fd, struct iovec const *__iov, __STDC_INT_AS_SIZE_T __count, __off64_t __offset),pwritev64,(__fd,__iov,__count,__offset))
#elif defined(__CRT_HAVE_pwritev) && (__SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__)
__CREDIRECT(__ATTR_NONNULL((2)),__SSIZE_TYPE__,__NOTHROW_RPC,__localdep_pwritev64,(__fd_t __fd, struct iovec const *__iov, __STDC_INT_AS_SIZE_T __count, __off64_t __offset),pwritev,(__fd,__iov,__count,__offset))
#elif defined(__CRT_HAVE_pwritev)
__NAMESPACE_LOCAL_END
#include <local/sys.uio/pwritev64.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_pwritev64 __LIBC_LOCAL_NAME(pwritev64)
#else /* ... */
#undef __local___localdep_pwritev64_defined
#endif /* !... */
#endif /* !__local___localdep_pwritev64_defined */
__LOCAL_LIBC(pwritev) __ATTR_NONNULL((2)) __SSIZE_TYPE__
__NOTHROW_RPC(__LIBCCALL __LIBC_LOCAL_NAME(pwritev))(__fd_t __fd, struct iovec const *__iov, __STDC_INT_AS_SIZE_T __count, __FS_TYPE(off) __offset) {
#if defined(__CRT_HAVE_pwritev64) || defined(__CRT_HAVE_pwritev)
	return __localdep_pwritev64(__fd, __iov, __count, (__off64_t)__offset);
#else /* __CRT_HAVE_pwritev64 || __CRT_HAVE_pwritev */
	return __localdep_pwritev32(__fd, __iov, __count, (__off32_t)__offset);
#endif /* !__CRT_HAVE_pwritev64 && !__CRT_HAVE_pwritev */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_pwritev_defined
#define __local___localdep_pwritev_defined 1
#define __localdep_pwritev __LIBC_LOCAL_NAME(pwritev)
#endif /* !__local___localdep_pwritev_defined */
#else /* __CRT_HAVE_pwritev || __CRT_HAVE_pwritev64 */
#undef __local_pwritev_defined
#endif /* !__CRT_HAVE_pwritev && !__CRT_HAVE_pwritev64 */
#endif /* !__local_pwritev_defined */
