/* HASH CRC-32:0xc11f5209 */
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
#ifndef __local__getwch_nolock_defined
#define __local__getwch_nolock_defined
#include <__crt.h>
#include <asm/os/termios.h>
#include <features.h>
#include <asm/os/tty.h>
#include <bits/types.h>
#if defined(__ECHO) && defined(__TCSANOW) && defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl) || defined(__CRT_HAVE___ioctl_time64)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl) || defined(__CRT_HAVE___ioctl_time64))
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_bzero_defined
#define __local___localdep_bzero_defined
#ifdef __CRT_HAVE_bzero
__CREDIRECT_VOID(__ATTR_OUTS(1, 2),__NOTHROW_NCX,__localdep_bzero,(void *__restrict __dst, __SIZE_TYPE__ __num_bytes),bzero,(__dst,__num_bytes))
#elif defined(__CRT_HAVE___bzero)
__CREDIRECT_VOID(__ATTR_OUTS(1, 2),__NOTHROW_NCX,__localdep_bzero,(void *__restrict __dst, __SIZE_TYPE__ __num_bytes),__bzero,(__dst,__num_bytes))
#elif defined(__CRT_HAVE_explicit_bzero)
__CREDIRECT_VOID(__ATTR_OUTS(1, 2),__NOTHROW_NCX,__localdep_bzero,(void *__restrict __dst, __SIZE_TYPE__ __num_bytes),explicit_bzero,(__dst,__num_bytes))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/string/bzero.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_bzero __LIBC_LOCAL_NAME(bzero)
#endif /* !... */
#endif /* !__local___localdep_bzero_defined */
#ifndef __local___localdep_fgetwc_unlocked_defined
#define __local___localdep_fgetwc_unlocked_defined
#ifdef __CRT_HAVE_fgetwc_unlocked
__CREDIRECT(__ATTR_INOUT(1),__WINT_TYPE__,__NOTHROW_CB_NCX,__localdep_fgetwc_unlocked,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked)
__CREDIRECT(__ATTR_INOUT(1),__WINT_TYPE__,__NOTHROW_CB_NCX,__localdep_fgetwc_unlocked,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE__getwc_nolock)
__CREDIRECT(__ATTR_INOUT(1),__WINT_TYPE__,__NOTHROW_CB_NCX,__localdep_fgetwc_unlocked,(__FILE *__restrict __stream),_getwc_nolock,(__stream))
#elif defined(__CRT_HAVE__fgetwc_nolock)
__CREDIRECT(__ATTR_INOUT(1),__WINT_TYPE__,__NOTHROW_CB_NCX,__localdep_fgetwc_unlocked,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#elif defined(__CRT_HAVE_getwc)
__CREDIRECT(__ATTR_INOUT(1),__WINT_TYPE__,__NOTHROW_CB_NCX,__localdep_fgetwc_unlocked,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_fgetwc)
__CREDIRECT(__ATTR_INOUT(1),__WINT_TYPE__,__NOTHROW_CB_NCX,__localdep_fgetwc_unlocked,(__FILE *__restrict __stream),fgetwc,(__stream))
#else /* ... */
#undef __local___localdep_fgetwc_unlocked_defined
#endif /* !... */
#endif /* !__local___localdep_fgetwc_unlocked_defined */
#ifndef __local___localdep_fileno_defined
#define __local___localdep_fileno_defined
#if defined(__CRT_HAVE_fileno_unlocked) && defined(__USE_STDIO_UNLOCKED)
__CREDIRECT(__ATTR_WUNUSED __ATTR_INOUT(1),__fd_t,__NOTHROW_NCX,__localdep_fileno,(__FILE *__restrict __stream),fileno_unlocked,(__stream))
#elif defined(__CRT_HAVE_fileno)
__CREDIRECT(__ATTR_WUNUSED __ATTR_INOUT(1),__fd_t,__NOTHROW_NCX,__localdep_fileno,(__FILE *__restrict __stream),fileno,(__stream))
#elif defined(__CRT_HAVE__fileno)
__CREDIRECT(__ATTR_WUNUSED __ATTR_INOUT(1),__fd_t,__NOTHROW_NCX,__localdep_fileno,(__FILE *__restrict __stream),_fileno,(__stream))
#elif defined(__CRT_HAVE_fileno_unlocked)
__CREDIRECT(__ATTR_WUNUSED __ATTR_INOUT(1),__fd_t,__NOTHROW_NCX,__localdep_fileno,(__FILE *__restrict __stream),fileno_unlocked,(__stream))
#else /* ... */
#undef __local___localdep_fileno_defined
#endif /* !... */
#endif /* !__local___localdep_fileno_defined */
#ifndef __local___localdep_memcpy_defined
#define __local___localdep_memcpy_defined
#ifdef __CRT_HAVE_memcpy
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_INS(2, 3) __ATTR_OUTS(1, 3) __ATTR_NONNULL((1, 2)),void *,__NOTHROW_NCX,__localdep_memcpy,(void *__restrict __dst, void const *__restrict __src, __SIZE_TYPE__ __n_bytes),memcpy,(__dst,__src,__n_bytes))
#else /* __CRT_HAVE_memcpy */
__NAMESPACE_LOCAL_END
#include <libc/local/string/memcpy.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_memcpy __LIBC_LOCAL_NAME(memcpy)
#endif /* !__CRT_HAVE_memcpy */
#endif /* !__local___localdep_memcpy_defined */
#ifndef __local___localdep_tcgetattr_defined
#define __local___localdep_tcgetattr_defined
#ifdef __CRT_HAVE_tcgetattr
__NAMESPACE_LOCAL_END
#include <bits/os/termios.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_FDARG(1) __ATTR_OUT(2),int,__NOTHROW_NCX,__localdep_tcgetattr,(__fd_t __fd, struct termios *__restrict __termios_p),tcgetattr,(__fd,__termios_p))
#elif defined(__CRT_HAVE___tcgetattr)
__NAMESPACE_LOCAL_END
#include <bits/os/termios.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_FDARG(1) __ATTR_OUT(2),int,__NOTHROW_NCX,__localdep_tcgetattr,(__fd_t __fd, struct termios *__restrict __termios_p),__tcgetattr,(__fd,__termios_p))
#elif (defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl) || defined(__CRT_HAVE___ioctl_time64)) && defined(__TCGETA)
__NAMESPACE_LOCAL_END
#include <libc/local/termios/tcgetattr.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_tcgetattr __LIBC_LOCAL_NAME(tcgetattr)
#else /* ... */
#undef __local___localdep_tcgetattr_defined
#endif /* !... */
#endif /* !__local___localdep_tcgetattr_defined */
#ifndef __local___localdep_tcsetattr_defined
#define __local___localdep_tcsetattr_defined
#ifdef __CRT_HAVE_tcsetattr
__NAMESPACE_LOCAL_END
#include <bits/os/termios.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_FDARG(1) __ATTR_IN(3),int,__NOTHROW_NCX,__localdep_tcsetattr,(__fd_t __fd, __STDC_INT_AS_UINT_T __optional_actions, struct termios const *__restrict __termios_p),tcsetattr,(__fd,__optional_actions,__termios_p))
#elif defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl) || defined(__CRT_HAVE___ioctl_time64)
__NAMESPACE_LOCAL_END
#include <libc/local/termios/tcsetattr.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_tcsetattr __LIBC_LOCAL_NAME(tcsetattr)
#else /* ... */
#undef __local___localdep_tcsetattr_defined
#endif /* !... */
#endif /* !__local___localdep_tcsetattr_defined */
__NAMESPACE_LOCAL_END
#include <bits/os/termios.h>
#include <libc/template/stdtty.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(_getwch_nolock) __ATTR_WUNUSED __WINT_TYPE__
__NOTHROW_RPC(__LIBCCALL __LIBC_LOCAL_NAME(_getwch_nolock))(void) {
	__WINT_TYPE__ __result;
	struct termios __oios, __nios;
	__FILE *__fp = __LOCAL_stdtty;
	__fd_t __fd  = (__NAMESPACE_LOCAL_SYM __localdep_fileno)(__fp);
	if __unlikely((__NAMESPACE_LOCAL_SYM __localdep_tcgetattr)(__fd, &__oios) != 0)
		(__NAMESPACE_LOCAL_SYM __localdep_bzero)(&__oios, sizeof(__oios));
	(__NAMESPACE_LOCAL_SYM __localdep_memcpy)(&__nios, &__oios, sizeof(__nios));
	__nios.c_lflag &= ~__ECHO;
	(void)(__NAMESPACE_LOCAL_SYM __localdep_tcsetattr)(__fd, __TCSANOW, &__nios);
	__result = (__NAMESPACE_LOCAL_SYM __localdep_fgetwc_unlocked)(__fp);
	(void)(__NAMESPACE_LOCAL_SYM __localdep_tcsetattr)(__fd, __TCSANOW, &__oios);
	return __result;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__getwch_nolock_defined
#define __local___localdep__getwch_nolock_defined
#define __localdep__getwch_nolock __LIBC_LOCAL_NAME(_getwch_nolock)
#endif /* !__local___localdep__getwch_nolock_defined */
#else /* __ECHO && __TCSANOW && __CRT_HAVE_stdtty && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked || __CRT_HAVE__getwc_nolock || __CRT_HAVE__fgetwc_nolock || __CRT_HAVE_getwc || __CRT_HAVE_fgetwc) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl || __CRT_HAVE___ioctl_time64) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl || __CRT_HAVE___ioctl_time64) */
#undef __local__getwch_nolock_defined
#endif /* !__ECHO || !__TCSANOW || !__CRT_HAVE_stdtty || (!__CRT_HAVE_fileno && !__CRT_HAVE__fileno && !__CRT_HAVE_fileno_unlocked) || (!__CRT_HAVE_fgetwc_unlocked && !__CRT_HAVE_getwc_unlocked && !__CRT_HAVE__getwc_nolock && !__CRT_HAVE__fgetwc_nolock && !__CRT_HAVE_getwc && !__CRT_HAVE_fgetwc) || (!__CRT_HAVE_tcgetattr && !__CRT_HAVE___tcgetattr && ((!__CRT_HAVE_ioctl && !__CRT_HAVE___ioctl && !__CRT_HAVE___libc_ioctl && !__CRT_HAVE___ioctl_time64) || !__TCGETA)) || (!__CRT_HAVE_tcsetattr && !__CRT_HAVE_ioctl && !__CRT_HAVE___ioctl && !__CRT_HAVE___libc_ioctl && !__CRT_HAVE___ioctl_time64) */
#endif /* !__local__getwch_nolock_defined */
