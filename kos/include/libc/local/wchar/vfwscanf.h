/* HASH CRC-32:0xd01f156d */
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
#ifndef __local_vfwscanf_defined
#define __local_vfwscanf_defined
#include <__crt.h>
#include <features.h>
#if (defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked))
#include <kos/anno.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_fgetwc_defined
#define __local___localdep_fgetwc_defined
#if defined(__CRT_HAVE_fgetwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
__CREDIRECT(__ATTR_NONNULL((1)),__WINT_TYPE__,__THROWING,__localdep_fgetwc,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
__CREDIRECT(__ATTR_NONNULL((1)),__WINT_TYPE__,__THROWING,__localdep_fgetwc,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_fgetwc)
__CREDIRECT(__ATTR_NONNULL((1)),__WINT_TYPE__,__THROWING,__localdep_fgetwc,(__FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_getwc)
__CREDIRECT(__ATTR_NONNULL((1)),__WINT_TYPE__,__THROWING,__localdep_fgetwc,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_fgetwc_unlocked)
__CREDIRECT(__ATTR_NONNULL((1)),__WINT_TYPE__,__THROWING,__localdep_fgetwc,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked)
__CREDIRECT(__ATTR_NONNULL((1)),__WINT_TYPE__,__THROWING,__localdep_fgetwc,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#else /* ... */
#undef __local___localdep_fgetwc_defined
#endif /* !... */
#endif /* !__local___localdep_fgetwc_defined */
#ifndef __local___localdep_format_vwscanf_defined
#define __local___localdep_format_vwscanf_defined
#ifdef __CRT_HAVE_format_vwscanf
__NAMESPACE_LOCAL_END
#include <bits/crt/format-printer.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_LIBC_WSCANF(4, 0) __ATTR_NONNULL((1, 2, 4)),__SSIZE_TYPE__,__THROWING,__localdep_format_vwscanf,(__pformatgetc __pgetc, __pformatungetc __pungetc, void *__arg, __WCHAR_TYPE__ const *__restrict __format, __builtin_va_list __args),format_vwscanf,(__pgetc,__pungetc,__arg,__format,__args))
#else /* __CRT_HAVE_format_vwscanf */
__NAMESPACE_LOCAL_END
#include <libc/local/parts.wchar.format-printer/format_vwscanf.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_format_vwscanf __LIBC_LOCAL_NAME(format_vwscanf)
#endif /* !__CRT_HAVE_format_vwscanf */
#endif /* !__local___localdep_format_vwscanf_defined */
#ifndef __local___localdep_ungetwc_defined
#define __local___localdep_ungetwc_defined
#if defined(__CRT_HAVE_ungetwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
__CREDIRECT(__ATTR_NONNULL((2)),__WINT_TYPE__,__NOTHROW_NCX,__localdep_ungetwc,(__WINT_TYPE__ __wc, __FILE *__stream),ungetwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_ungetwc)
__CREDIRECT(__ATTR_NONNULL((2)),__WINT_TYPE__,__NOTHROW_NCX,__localdep_ungetwc,(__WINT_TYPE__ __wc, __FILE *__stream),ungetwc,(__wc,__stream))
#elif defined(__CRT_HAVE_ungetwc_unlocked)
__CREDIRECT(__ATTR_NONNULL((2)),__WINT_TYPE__,__NOTHROW_NCX,__localdep_ungetwc,(__WINT_TYPE__ __wc, __FILE *__stream),ungetwc_unlocked,(__wc,__stream))
#else /* ... */
#undef __local___localdep_ungetwc_defined
#endif /* !... */
#endif /* !__local___localdep_ungetwc_defined */
__NAMESPACE_LOCAL_END
#ifndef ____vfwscanf_getc_defined
#define ____vfwscanf_getc_defined
__NAMESPACE_LOCAL_BEGIN
#if !defined(__LIBCCALL_IS_FORMATPRINTER_CC) || __SIZEOF_FORMAT_WORD_T__ != __SIZEOF_INT__
__LOCAL_LIBC(vfwscanf_getc) __format_word_t
(__FORMATPRINTER_CC __vfwscanf_getc)(void *__arg) {
	return (__format_word_t)(__NAMESPACE_LOCAL_SYM __localdep_fgetwc)((__FILE *)__arg);
}
#endif /* !__LIBCCALL_IS_FORMATPRINTER_CC || __SIZEOF_FORMAT_WORD_T__ != __SIZEOF_INT__ */
__LOCAL_LIBC(vfwscanf_ungetc) __SSIZE_TYPE__
(__FORMATPRINTER_CC __vfwscanf_ungetc)(void *__arg, __format_word_t __word) {
	return (__NAMESPACE_LOCAL_SYM __localdep_ungetwc)((__WINT_TYPE__)__word, (__FILE *)__arg);
}
__NAMESPACE_LOCAL_END
#endif /* !____vfwscanf_getc_defined */
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(vfwscanf) __ATTR_WUNUSED __ATTR_LIBC_WSCANF(2, 0) __ATTR_NONNULL((1, 2)) __STDC_INT_AS_SIZE_T
(__LIBCCALL __LIBC_LOCAL_NAME(vfwscanf))(__FILE *__restrict __stream, __WCHAR_TYPE__ const *__restrict __format, __builtin_va_list __args) __THROWS(...) {
#if defined(__LIBCCALL_IS_FORMATPRINTER_CC) && __SIZEOF_FORMAT_WORD_T__ == __SIZEOF_INT__
	return (__NAMESPACE_LOCAL_SYM __localdep_format_vwscanf)((__pformatgetc)(void *)&(__NAMESPACE_LOCAL_SYM __localdep_fgetwc),
	                      &__NAMESPACE_LOCAL_SYM __vfwscanf_ungetc,
	                      (void *)__stream,
	                      __format, __args);
#else /* __LIBCCALL_IS_FORMATPRINTER_CC && __SIZEOF_FORMAT_WORD_T__ == __SIZEOF_INT__ */
	return (__NAMESPACE_LOCAL_SYM __localdep_format_vwscanf)(&__NAMESPACE_LOCAL_SYM __vfwscanf_getc,
	                      &__NAMESPACE_LOCAL_SYM __vfwscanf_ungetc,
	                      (void *)__stream,
	                      __format, __args);
#endif /* !__LIBCCALL_IS_FORMATPRINTER_CC || __SIZEOF_FORMAT_WORD_T__ != __SIZEOF_INT__ */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_vfwscanf_defined
#define __local___localdep_vfwscanf_defined
#define __localdep_vfwscanf __LIBC_LOCAL_NAME(vfwscanf)
#endif /* !__local___localdep_vfwscanf_defined */
#else /* (__CRT_HAVE_fgetwc || __CRT_HAVE_getwc || __CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked) && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked) */
#undef __local_vfwscanf_defined
#endif /* (!__CRT_HAVE_fgetwc && !__CRT_HAVE_getwc && !__CRT_HAVE_fgetwc_unlocked && !__CRT_HAVE_getwc_unlocked) || (!__CRT_HAVE_ungetwc && !__CRT_HAVE_ungetwc_unlocked) */
#endif /* !__local_vfwscanf_defined */