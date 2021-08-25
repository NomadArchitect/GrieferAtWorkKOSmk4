/* HASH CRC-32:0x69806a27 */
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
#ifndef __local_strerror_defined
#define __local_strerror_defined 1
#include <__crt.h>
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: sprintf from stdio */
#ifndef __local___localdep_sprintf_defined
#define __local___localdep_sprintf_defined 1
#if __has_builtin(__builtin_sprintf) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_sprintf) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
/* >> sprintf(3), vsprintf(3)
 * Print a formatted string to a given in-member string buffer `buf'
 * Return the number of written characters, excluding a trailing NUL-character */
__CEIREDIRECT(__ATTR_LIBC_PRINTF(2, 3) __ATTR_NONNULL((1, 2)),__STDC_INT_AS_SIZE_T,__NOTHROW_NCX,__localdep_sprintf,(char *__restrict __buf, char const *__restrict __format, ...),sprintf,{ return __builtin_sprintf(__buf, __format, __builtin_va_arg_pack()); })
#elif defined(__CRT_HAVE_sprintf)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
/* >> sprintf(3), vsprintf(3)
 * Print a formatted string to a given in-member string buffer `buf'
 * Return the number of written characters, excluding a trailing NUL-character */
__LIBC __ATTR_LIBC_PRINTF(2, 3) __ATTR_NONNULL((1, 2)) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__VLIBCCALL __localdep_sprintf)(char *__restrict __buf, char const *__restrict __format, ...) __CASMNAME("sprintf");
#elif defined(__CRT_HAVE__IO_sprintf)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
/* >> sprintf(3), vsprintf(3)
 * Print a formatted string to a given in-member string buffer `buf'
 * Return the number of written characters, excluding a trailing NUL-character */
__LIBC __ATTR_LIBC_PRINTF(2, 3) __ATTR_NONNULL((1, 2)) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__VLIBCCALL __localdep_sprintf)(char *__restrict __buf, char const *__restrict __format, ...) __CASMNAME("_IO_sprintf");
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/stdio/sprintf.h>
__NAMESPACE_LOCAL_BEGIN
/* >> sprintf(3), vsprintf(3)
 * Print a formatted string to a given in-member string buffer `buf'
 * Return the number of written characters, excluding a trailing NUL-character */
#define __localdep_sprintf __LIBC_LOCAL_NAME(sprintf)
#endif /* !... */
#endif /* !__local___localdep_sprintf_defined */
/* Dependency: strerrordesc_np from string */
#ifndef __local___localdep_strerrordesc_np_defined
#define __local___localdep_strerrordesc_np_defined 1
#ifdef __CRT_HAVE_strerrordesc_np
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,char const *,__NOTHROW,__localdep_strerrordesc_np,(__errno_t __errnum),strerrordesc_np,(__errnum))
#else /* __CRT_HAVE_strerrordesc_np */
__NAMESPACE_LOCAL_END
#include <libc/local/string/strerrordesc_np.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_strerrordesc_np __LIBC_LOCAL_NAME(strerrordesc_np)
#endif /* !__CRT_HAVE_strerrordesc_np */
#endif /* !__local___localdep_strerrordesc_np_defined */
/* Dependency: strncpy from string */
#ifndef __local___localdep_strncpy_defined
#define __local___localdep_strncpy_defined 1
#if __has_builtin(__builtin_strncpy) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_strncpy)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
/* >> strncpy(3)
 * Always write exactly `buflen' characters to `buf'. As far as
 * space for doing so is available, up to the `strlen(src)' of
 * the first characters are copied from `src'. All remaining
 * characters are always set to '\0'. Always re-returns `buf' */
__CEIREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),char *,__NOTHROW_NCX,__localdep_strncpy,(char *__restrict __buf, char const *__restrict __src, __SIZE_TYPE__ __buflen),strncpy,{ return __builtin_strncpy(__buf, __src, __buflen); })
#elif defined(__CRT_HAVE_strncpy)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
/* >> strncpy(3)
 * Always write exactly `buflen' characters to `buf'. As far as
 * space for doing so is available, up to the `strlen(src)' of
 * the first characters are copied from `src'. All remaining
 * characters are always set to '\0'. Always re-returns `buf' */
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),char *,__NOTHROW_NCX,__localdep_strncpy,(char *__restrict __buf, char const *__restrict __src, __SIZE_TYPE__ __buflen),strncpy,(__buf,__src,__buflen))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/string/strncpy.h>
__NAMESPACE_LOCAL_BEGIN
/* >> strncpy(3)
 * Always write exactly `buflen' characters to `buf'. As far as
 * space for doing so is available, up to the `strlen(src)' of
 * the first characters are copied from `src'. All remaining
 * characters are always set to '\0'. Always re-returns `buf' */
#define __localdep_strncpy __LIBC_LOCAL_NAME(strncpy)
#endif /* !... */
#endif /* !__local___localdep_strncpy_defined */
__LOCAL_LIBC(strerror) __ATTR_COLD __ATTR_RETNONNULL __ATTR_WUNUSED char *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(strerror))(__errno_t __errnum) {
	static char __strerror_buf[64];
	char *__result;
	char const *__string;
	__result = __strerror_buf;
	__string = __localdep_strerrordesc_np(__errnum);
	if (__string) {
		/* Copy the descriptor text. */
		__result[__COMPILER_LENOF(__strerror_buf) - 1] = '\0';
		__localdep_strncpy(__result, __string, __COMPILER_LENOF(__strerror_buf) - 1);
	} else {
		__localdep_sprintf(__result, "Unknown error %d", __errnum);
	}
	return __result;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_strerror_defined
#define __local___localdep_strerror_defined 1
#define __localdep_strerror __LIBC_LOCAL_NAME(strerror)
#endif /* !__local___localdep_strerror_defined */
#endif /* !__local_strerror_defined */
