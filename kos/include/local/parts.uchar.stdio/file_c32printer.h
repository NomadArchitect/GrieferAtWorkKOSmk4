/* HASH CRC-32:0xc0234185 */
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
#ifndef __local_file_c32printer_defined
#define __local_file_c32printer_defined 1
#include <__crt.h>
#if (defined(__CRT_HAVE_fputwc) && (__SIZEOF_WCHAR_T__ == 4) && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && (__SIZEOF_WCHAR_T__ == 4) && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_DOS$putwc)
__NAMESPACE_LOCAL_BEGIN
/* Dependency: fputc32 from parts.uchar.stdio */
#ifndef __local___localdep_fputc32_defined
#define __local___localdep_fputc32_defined 1
#if defined(__CRT_HAVE_fputwc) && (__SIZEOF_WCHAR_T__ == 4) && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((2)),__WINT_TYPE__,__THROWING,__localdep_fputc32,(__CHAR32_TYPE__ __wc, __FILE *__stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$fputwc)
__CREDIRECT_KOS(__ATTR_NONNULL((2)),__WINT_TYPE__,__THROWING,__localdep_fputc32,(__CHAR32_TYPE__ __wc, __FILE *__stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc) && (__SIZEOF_WCHAR_T__ == 4) && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((2)),__WINT_TYPE__,__THROWING,__localdep_fputc32,(__CHAR32_TYPE__ __wc, __FILE *__stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$putwc)
__CREDIRECT_KOS(__ATTR_NONNULL((2)),__WINT_TYPE__,__THROWING,__localdep_fputc32,(__CHAR32_TYPE__ __wc, __FILE *__stream),putwc,(__wc,__stream))
#else /* ... */
#undef __local___localdep_fputc32_defined
#endif /* !... */
#endif /* !__local___localdep_fputc32_defined */
__NAMESPACE_LOCAL_END
#include <asm/stdio.h>
__NAMESPACE_LOCAL_BEGIN
/* For use with `format_printf()' and friends: Prints to a `FILE *' closure argument */
__LOCAL_LIBC(file_c32printer) __ATTR_NONNULL((1, 2)) __SSIZE_TYPE__
(__LIBKCALL __LIBC_LOCAL_NAME(file_c32printer))(void *__arg, __CHAR32_TYPE__ const *__restrict __data, __SIZE_TYPE__ __datalen) __THROWS(...) {
	__SIZE_TYPE__ __i;
	for (__i = 0; __i < __datalen; ++__i) {
		if (__localdep_fputc32(__data[__i], (__FILE *)__arg) == __WEOF32)
			break;
	}
	return (__SSIZE_TYPE__)__i;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_file_c32printer_defined
#define __local___localdep_file_c32printer_defined 1
#define __localdep_file_c32printer __LIBC_LOCAL_NAME(file_c32printer)
#endif /* !__local___localdep_file_c32printer_defined */
#else /* (__CRT_HAVE_fputwc && (__SIZEOF_WCHAR_T__ == 4) && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_DOS$fputwc || (__CRT_HAVE_putwc && (__SIZEOF_WCHAR_T__ == 4) && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_DOS$putwc */
#undef __local_file_c32printer_defined
#endif /* (!__CRT_HAVE_fputwc || !(__SIZEOF_WCHAR_T__ == 4) || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_DOS$fputwc && (!__CRT_HAVE_putwc || !(__SIZEOF_WCHAR_T__ == 4) || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_DOS$putwc */
#endif /* !__local_file_c32printer_defined */
