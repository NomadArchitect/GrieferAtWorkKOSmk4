/* HASH CRC-32:0xb9a6d648 */
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
/* (#) Portability: MinGW        (/mingw-w64-headers/crt/mbstring.h) */
/* (#) Portability: Windows Kits (/ucrt/mbstring.h) */
#ifndef _MBSTRING_H
#define _MBSTRING_H 1

#include "__stdinc.h"
#include "__crt.h"

#ifdef __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER
#pragma GCC system_header
#endif /* __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER */

#include <features.h>
#include <bits/types.h>
#include <hybrid/typecore.h>

#ifdef __USE_DOS
#include <crtdefs.h>
#endif /* __USE_DOS */

#ifdef __CC__
__SYSDECL_BEGIN

#ifndef __size_t_defined
#define __size_t_defined
typedef __SIZE_TYPE__ size_t;
#endif /* !__size_t_defined */

#ifndef __ernno_t_defined
#define __ernno_t_defined
typedef __errno_t errno_t;
#endif /* !__ernno_t_defined */

#ifdef __CORRECT_ISO_CPP_STRING_H_PROTO
#define __CORRECT_ISO_CPP_MBSTRING_H_PROTO
#endif /* __CORRECT_ISO_CPP_STRING_H_PROTO */

#if __has_builtin(__builtin_strdup) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_strdup)
__CEIREDIRECT(__ATTR_MALLOC __ATTR_MALL_DEFAULT_ALIGNED __ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsdup,(unsigned char const *__restrict __string),strdup,{ return __builtin_strdup(__string); })
#elif defined(__CRT_HAVE_strdup)
__CREDIRECT(__ATTR_MALLOC __ATTR_MALL_DEFAULT_ALIGNED __ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsdup,(unsigned char const *__restrict __string),strdup,(__string))
#elif defined(__CRT_HAVE__strdup)
__CREDIRECT(__ATTR_MALLOC __ATTR_MALL_DEFAULT_ALIGNED __ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsdup,(unsigned char const *__restrict __string),_strdup,(__string))
#elif defined(__CRT_HAVE__mbsdup)
__CDECLARE(__ATTR_MALLOC __ATTR_MALL_DEFAULT_ALIGNED __ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsdup,(unsigned char const *__restrict __string),(__string))
#elif defined(__CRT_HAVE___strdup)
__CREDIRECT(__ATTR_MALLOC __ATTR_MALL_DEFAULT_ALIGNED __ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsdup,(unsigned char const *__restrict __string),__strdup,(__string))
#elif defined(__CRT_HAVE_malloc) || defined(__CRT_HAVE___libc_malloc) || defined(__CRT_HAVE_calloc) || defined(__CRT_HAVE___libc_calloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc) || defined(__CRT_HAVE_memalign) || defined(__CRT_HAVE_aligned_alloc) || defined(__CRT_HAVE___libc_memalign) || defined(__CRT_HAVE_posix_memalign)
#include <libc/local/string/strdup.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_MALLOC __ATTR_MALL_DEFAULT_ALIGNED __ATTR_WUNUSED __ATTR_NONNULL((1)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsdup)(unsigned char const *__restrict __string) { return (unsigned char *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(strdup))((char const *)__string); }
#endif /* ... */
#ifdef __CRT_HAVE__mbbtombc
__CDECLARE(__ATTR_WUNUSED,unsigned int,__NOTHROW_NCX,_mbbtombc,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__mbbtombc_l)
#include <libc/local/mbstring/_mbbtombc.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbbtombc, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED unsigned int __NOTHROW_NCX(__LIBCCALL _mbbtombc)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbbtombc))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__mbbtype
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_mbbtype,(unsigned char __ch, int __ctype),(__ch,__ctype))
#elif defined(__CRT_HAVE__mbbtype_l)
#include <libc/local/mbstring/_mbbtype.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbbtype, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _mbbtype)(unsigned char __ch, int __ctype) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbbtype))(__ch, __ctype); })
#endif /* ... */
#ifdef __CRT_HAVE__mbctombb
__CDECLARE(__ATTR_WUNUSED,unsigned int,__NOTHROW_NCX,_mbctombb,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__mbctombb_l)
#include <libc/local/mbstring/_mbctombb.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbctombb, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED unsigned int __NOTHROW_NCX(__LIBCCALL _mbctombb)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbctombb))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsbtype
__CDECLARE(,int,__NOTHROW_NCX,_mbsbtype,(unsigned char const *__str, size_t __pos),(__str,__pos))
#elif defined(__CRT_HAVE__mbsbtype_l)
#include <libc/local/mbstring/_mbsbtype.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsbtype, __FORCELOCAL __ATTR_ARTIFICIAL int __NOTHROW_NCX(__LIBCCALL _mbsbtype)(unsigned char const *__str, size_t __pos) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsbtype))(__str, __pos); })
#endif /* ... */
#ifdef __CRT_HAVE__mbscat_s
__CDECLARE(__ATTR_NONNULL((1, 3)),errno_t,__NOTHROW_NCX,_mbscat_s,(unsigned char *__buf, size_t __bufsize, unsigned char const *__src),(__buf,__bufsize,__src))
#elif defined(__CRT_HAVE__mbscat_s_l)
#include <libc/local/mbstring/_mbscat_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbscat_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 3)) errno_t __NOTHROW_NCX(__LIBCCALL _mbscat_s)(unsigned char *__buf, size_t __bufsize, unsigned char const *__src) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbscat_s))(__buf, __bufsize, __src); })
#endif /* ... */
#if __has_builtin(__builtin_strcat) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_strcat)
/* >> strcat(3)
 * Same as `strcpy(3)',  but rather  than copying `src'  ontop of  `dst',
 * append it at the end of `dst', or more precisely copy to `strend(dst)'
 * Always re-returns `dst' */
__CEIREDIRECT(__ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbscat,(unsigned char *__restrict __dst, unsigned char const *__restrict __src),strcat,{ return __builtin_strcat(__dst, __src); })
#elif defined(__CRT_HAVE_strcat)
/* >> strcat(3)
 * Same as `strcpy(3)',  but rather  than copying `src'  ontop of  `dst',
 * append it at the end of `dst', or more precisely copy to `strend(dst)'
 * Always re-returns `dst' */
__CREDIRECT(__ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbscat,(unsigned char *__restrict __dst, unsigned char const *__restrict __src),strcat,(__dst,__src))
#elif defined(__CRT_HAVE__mbscat)
/* >> strcat(3)
 * Same as `strcpy(3)',  but rather  than copying `src'  ontop of  `dst',
 * append it at the end of `dst', or more precisely copy to `strend(dst)'
 * Always re-returns `dst' */
__CDECLARE(__ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbscat,(unsigned char *__restrict __dst, unsigned char const *__restrict __src),(__dst,__src))
#else /* ... */
#include <libc/local/string/strcat.h>
/* >> strcat(3)
 * Same as `strcpy(3)',  but rather  than copying `src'  ontop of  `dst',
 * append it at the end of `dst', or more precisely copy to `strend(dst)'
 * Always re-returns `dst' */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbscat)(unsigned char *__restrict __dst, unsigned char const *__restrict __src) { return (unsigned char *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(strcat))((char *)__dst, (char const *)__src); }
#endif /* !... */
#ifdef __CRT_HAVE__mbschr
#if defined(__cplusplus) && defined(__CORRECT_ISO_CPP_MBSTRING_H_PROTO)
extern "C++" {
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbschr,(unsigned char *__restrict __haystack, int __needle),_mbschr,(__haystack,__needle))
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char const *,__NOTHROW_NCX,_mbschr,(unsigned char const *__restrict __haystack, int __needle),_mbschr,(__haystack,__needle))
} /* extern "C++" */
#else /* __cplusplus && __CORRECT_ISO_CPP_MBSTRING_H_PROTO */
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbschr,(unsigned char const *__restrict __haystack, unsigned int __needle),(__haystack,__needle))
#endif /* !__cplusplus || !__CORRECT_ISO_CPP_MBSTRING_H_PROTO */
#elif defined(__CRT_HAVE__mbschr_l)
#include <libc/local/mbstring/_mbschr.h>
#if defined(__cplusplus) && defined(__CORRECT_ISO_CPP_MBSTRING_H_PROTO)
extern "C++" {
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbschr)(unsigned char *__restrict __haystack, int __needle) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbschr))(__haystack, (unsigned int)__needle); }
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) unsigned char const *__NOTHROW_NCX(__LIBCCALL _mbschr)(unsigned char const *__restrict __haystack, int __needle) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbschr))(__haystack, (unsigned int)__needle); }
} /* extern "C++" */
#else /* __cplusplus && __CORRECT_ISO_CPP_MBSTRING_H_PROTO */
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbschr, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbschr)(unsigned char const *__restrict __haystack, unsigned int __needle) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbschr))(__haystack, __needle); })
#endif /* !__cplusplus || !__CORRECT_ISO_CPP_MBSTRING_H_PROTO */
#endif /* ... */
#ifdef __CRT_HAVE__mbscmp
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbscmp,(unsigned char const *__lhs, unsigned char const *__rhs),(__lhs,__rhs))
#elif defined(__CRT_HAVE__mbscmp_l)
#include <libc/local/mbstring/_mbscmp.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbscmp, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) int __NOTHROW_NCX(__LIBCCALL _mbscmp)(unsigned char const *__lhs, unsigned char const *__rhs) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbscmp))(__lhs, __rhs); })
#endif /* ... */
#ifdef __CRT_HAVE__mbscoll
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbscoll,(unsigned char const *__lhs, unsigned char const *__rhs),(__lhs,__rhs))
#elif defined(__CRT_HAVE__mbscoll_l)
#include <libc/local/mbstring/_mbscoll.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbscoll, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) int __NOTHROW_NCX(__LIBCCALL _mbscoll)(unsigned char const *__lhs, unsigned char const *__rhs) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbscoll))(__lhs, __rhs); })
#endif /* ... */
#ifdef __CRT_HAVE__mbscpy_s
__CDECLARE(__ATTR_NONNULL((1, 3)),errno_t,__NOTHROW_NCX,_mbscpy_s,(unsigned char *__buf, size_t __bufsize, unsigned char const *__src),(__buf,__bufsize,__src))
#elif defined(__CRT_HAVE__mbscpy_s_l)
#include <libc/local/mbstring/_mbscpy_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbscpy_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 3)) errno_t __NOTHROW_NCX(__LIBCCALL _mbscpy_s)(unsigned char *__buf, size_t __bufsize, unsigned char const *__src) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbscpy_s))(__buf, __bufsize, __src); })
#endif /* ... */
#if __has_builtin(__builtin_strcpy) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_strcpy)
/* >> strcpy(3)
 * Copy a NUL-terminated string `str' to `dst', and re-return `dst'.
 * The exact # of characters copied is `strlen(src) + 1' (+1 because
 * the trailing NUL-character is also copied) */
__CEIREDIRECT(__ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbscpy,(unsigned char *__restrict __dst, unsigned char const *__restrict __src),strcpy,{ return __builtin_strcpy(__dst, __src); })
#elif defined(__CRT_HAVE_strcpy)
/* >> strcpy(3)
 * Copy a NUL-terminated string `str' to `dst', and re-return `dst'.
 * The exact # of characters copied is `strlen(src) + 1' (+1 because
 * the trailing NUL-character is also copied) */
__CREDIRECT(__ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbscpy,(unsigned char *__restrict __dst, unsigned char const *__restrict __src),strcpy,(__dst,__src))
#elif defined(__CRT_HAVE__mbscpy)
/* >> strcpy(3)
 * Copy a NUL-terminated string `str' to `dst', and re-return `dst'.
 * The exact # of characters copied is `strlen(src) + 1' (+1 because
 * the trailing NUL-character is also copied) */
__CDECLARE(__ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbscpy,(unsigned char *__restrict __dst, unsigned char const *__restrict __src),(__dst,__src))
#else /* ... */
#include <libc/local/string/strcpy.h>
/* >> strcpy(3)
 * Copy a NUL-terminated string `str' to `dst', and re-return `dst'.
 * The exact # of characters copied is `strlen(src) + 1' (+1 because
 * the trailing NUL-character is also copied) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbscpy)(unsigned char *__restrict __dst, unsigned char const *__restrict __src) { return (unsigned char *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(strcpy))((char *)__dst, (char const *)__src); }
#endif /* !... */
#ifdef __CRT_HAVE__mbscspn
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),size_t,__NOTHROW_NCX,_mbscspn,(unsigned char const *__haystack, unsigned char const *__reject),(__haystack,__reject))
#elif defined(__CRT_HAVE__mbscspn_l)
#include <libc/local/mbstring/_mbscspn.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbscspn, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) size_t __NOTHROW_NCX(__LIBCCALL _mbscspn)(unsigned char const *__haystack, unsigned char const *__reject) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbscspn))(__haystack, __reject); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsdec
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbsdec,(unsigned char const *__start, unsigned char const *__pos),(__start,__pos))
#elif defined(__CRT_HAVE__mbsdec_l)
#include <libc/local/mbstring/_mbsdec.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsdec, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsdec)(unsigned char const *__start, unsigned char const *__pos) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsdec))(__start, __pos); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsicmp
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsicmp,(unsigned char const *__lhs, unsigned char const *__rhs),(__lhs,__rhs))
#elif defined(__CRT_HAVE__mbsicmp_l)
#include <libc/local/mbstring/_mbsicmp.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsicmp, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) int __NOTHROW_NCX(__LIBCCALL _mbsicmp)(unsigned char const *__lhs, unsigned char const *__rhs) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsicmp))(__lhs, __rhs); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsicoll
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsicoll,(unsigned char const *__lhs, unsigned char const *__rhs),(__lhs,__rhs))
#elif defined(__CRT_HAVE__mbsicoll_l)
#include <libc/local/mbstring/_mbsicoll.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsicoll, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) int __NOTHROW_NCX(__LIBCCALL _mbsicoll)(unsigned char const *__lhs, unsigned char const *__rhs) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsicoll))(__lhs, __rhs); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsinc
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsinc,(unsigned char const *__ptr),(__ptr))
#elif defined(__CRT_HAVE__mbsinc_l)
#include <libc/local/mbstring/_mbsinc.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsinc, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsinc)(unsigned char const *__ptr) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsinc))(__ptr); })
#endif /* ... */
#ifdef __CRT_HAVE__mbslen
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1)),size_t,__NOTHROW_NCX,_mbslen,(unsigned char const *__str),(__str))
#elif defined(__CRT_HAVE__mbslen_l)
#include <libc/local/mbstring/_mbslen.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbslen, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) size_t __NOTHROW_NCX(__LIBCCALL _mbslen)(unsigned char const *__str) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbslen))(__str); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnlen
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1)),size_t,__NOTHROW_NCX,_mbsnlen,(unsigned char const *__str, size_t __maxlen),(__str,__maxlen))
#elif defined(__CRT_HAVE__mbsnlen_l)
#include <libc/local/mbstring/_mbsnlen.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnlen, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) size_t __NOTHROW_NCX(__LIBCCALL _mbsnlen)(unsigned char const *__str, size_t __maxlen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnlen))(__str, __maxlen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbslwr_s
__CDECLARE(__ATTR_NONNULL((1)),errno_t,__NOTHROW_NCX,_mbslwr_s,(unsigned char *__buf, size_t __buflen),(__buf,__buflen))
#elif defined(__CRT_HAVE__mbslwr_s_l)
#include <libc/local/mbstring/_mbslwr_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbslwr_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) errno_t __NOTHROW_NCX(__LIBCCALL _mbslwr_s)(unsigned char *__buf, size_t __buflen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbslwr_s))(__buf, __buflen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbslwr
__CDECLARE(__ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbslwr,(unsigned char *__buf),(__buf))
#elif defined(__CRT_HAVE__mbslwr_l)
#include <libc/local/mbstring/_mbslwr.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbslwr, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbslwr)(unsigned char *__buf) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbslwr))(__buf); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnbcat_s
__CDECLARE(__ATTR_NONNULL((1, 3)),errno_t,__NOTHROW_NCX,_mbsnbcat_s,(unsigned char *__buf, size_t __bufsize, unsigned char const *__src, size_t __maxlen),(__buf,__bufsize,__src,__maxlen))
#elif defined(__CRT_HAVE__mbsnbcat_s_l)
#include <libc/local/mbstring/_mbsnbcat_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnbcat_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 3)) errno_t __NOTHROW_NCX(__LIBCCALL _mbsnbcat_s)(unsigned char *__buf, size_t __bufsize, unsigned char const *__src, size_t __maxlen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnbcat_s))(__buf, __bufsize, __src, __maxlen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnbcat
__CDECLARE(__ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbsnbcat,(unsigned char *__buf, unsigned char const *__src, size_t __srclen),(__buf,__src,__srclen))
#elif defined(__CRT_HAVE__mbsnbcat_l)
#include <libc/local/mbstring/_mbsnbcat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnbcat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 2)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsnbcat)(unsigned char *__buf, unsigned char const *__src, size_t __srclen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnbcat))(__buf, __src, __srclen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnbcmp
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsnbcmp,(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen),(__lhs,__rhs,__maxlen))
#elif defined(__CRT_HAVE__mbsnbcmp_l)
#include <libc/local/mbstring/_mbsnbcmp.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnbcmp, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) int __NOTHROW_NCX(__LIBCCALL _mbsnbcmp)(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnbcmp))(__lhs, __rhs, __maxlen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnbcoll
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsnbcoll,(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen),(__lhs,__rhs,__maxlen))
#elif defined(__CRT_HAVE__mbsnbcoll_l)
#include <libc/local/mbstring/_mbsnbcoll.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnbcoll, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) int __NOTHROW_NCX(__LIBCCALL _mbsnbcoll)(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnbcoll))(__lhs, __rhs, __maxlen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnbcnt
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1)),size_t,__NOTHROW_NCX,_mbsnbcnt,(unsigned char const *__str, size_t __maxlen),(__str,__maxlen))
#elif defined(__CRT_HAVE__mbsnbcnt_l)
#include <libc/local/mbstring/_mbsnbcnt.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnbcnt, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) size_t __NOTHROW_NCX(__LIBCCALL _mbsnbcnt)(unsigned char const *__str, size_t __maxlen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnbcnt))(__str, __maxlen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnbcpy_s
__CDECLARE(__ATTR_NONNULL((1, 3)),errno_t,__NOTHROW_NCX,_mbsnbcpy_s,(unsigned char *__buf, size_t __bufsize, unsigned char const *__src, size_t __srclen),(__buf,__bufsize,__src,__srclen))
#elif defined(__CRT_HAVE__mbsnbcpy_s_l)
#include <libc/local/mbstring/_mbsnbcpy_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnbcpy_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 3)) errno_t __NOTHROW_NCX(__LIBCCALL _mbsnbcpy_s)(unsigned char *__buf, size_t __bufsize, unsigned char const *__src, size_t __srclen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnbcpy_s))(__buf, __bufsize, __src, __srclen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnbcpy
__CDECLARE(__ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbsnbcpy,(unsigned char *__buf, unsigned char const *__src, size_t __srclen),(__buf,__src,__srclen))
#elif defined(__CRT_HAVE__mbsnbcpy_l)
#include <libc/local/mbstring/_mbsnbcpy.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnbcpy, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 2)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsnbcpy)(unsigned char *__buf, unsigned char const *__src, size_t __srclen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnbcpy))(__buf, __src, __srclen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnbicmp
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsnbicmp,(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen),(__lhs,__rhs,__maxlen))
#elif defined(__CRT_HAVE__mbsnbicmp_l)
#include <libc/local/mbstring/_mbsnbicmp.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnbicmp, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) int __NOTHROW_NCX(__LIBCCALL _mbsnbicmp)(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnbicmp))(__lhs, __rhs, __maxlen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnbicoll
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsnbicoll,(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen),(__lhs,__rhs,__maxlen))
#elif defined(__CRT_HAVE__mbsnbicoll_l)
#include <libc/local/mbstring/_mbsnbicoll.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnbicoll, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) int __NOTHROW_NCX(__LIBCCALL _mbsnbicoll)(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnbicoll))(__lhs, __rhs, __maxlen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnbset_s
__CDECLARE(__ATTR_NONNULL((1)),errno_t,__NOTHROW_NCX,_mbsnbset_s,(unsigned char *__buf, size_t __bufsize, unsigned int __ch, size_t __num_chars),(__buf,__bufsize,__ch,__num_chars))
#elif defined(__CRT_HAVE__mbsnbset_s_l)
#include <libc/local/mbstring/_mbsnbset_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnbset_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) errno_t __NOTHROW_NCX(__LIBCCALL _mbsnbset_s)(unsigned char *__buf, size_t __bufsize, unsigned int __ch, size_t __num_chars) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnbset_s))(__buf, __bufsize, __ch, __num_chars); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnbset
__CDECLARE(__ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsnbset,(unsigned char *__buf, unsigned int __ch, size_t __buflen),(__buf,__ch,__buflen))
#elif defined(__CRT_HAVE__mbsnbset_l)
#include <libc/local/mbstring/_mbsnbset.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnbset, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsnbset)(unsigned char *__buf, unsigned int __ch, size_t __buflen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnbset))(__buf, __ch, __buflen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsncat_s
__CDECLARE(__ATTR_NONNULL((1, 3)),errno_t,__NOTHROW_NCX,_mbsncat_s,(unsigned char *__buf, size_t __bufsize, unsigned char const *__src, size_t __srclen),(__buf,__bufsize,__src,__srclen))
#elif defined(__CRT_HAVE__mbsncat_s_l)
#include <libc/local/mbstring/_mbsncat_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsncat_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 3)) errno_t __NOTHROW_NCX(__LIBCCALL _mbsncat_s)(unsigned char *__buf, size_t __bufsize, unsigned char const *__src, size_t __srclen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsncat_s))(__buf, __bufsize, __src, __srclen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsncat
__CDECLARE(__ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbsncat,(unsigned char *__buf, unsigned char const *__src, size_t __srclen),(__buf,__src,__srclen))
#elif defined(__CRT_HAVE__mbsncat_l)
#include <libc/local/mbstring/_mbsncat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsncat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 2)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsncat)(unsigned char *__buf, unsigned char const *__src, size_t __srclen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsncat))(__buf, __src, __srclen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnccnt
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1)),size_t,__NOTHROW_NCX,_mbsnccnt,(unsigned char const *__str, size_t __maxlen),(__str,__maxlen))
#elif defined(__CRT_HAVE__mbsnccnt_l)
#include <libc/local/mbstring/_mbsnccnt.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnccnt, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) size_t __NOTHROW_NCX(__LIBCCALL _mbsnccnt)(unsigned char const *__str, size_t __maxlen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnccnt))(__str, __maxlen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsncmp
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsncmp,(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen),(__lhs,__rhs,__maxlen))
#elif defined(__CRT_HAVE__mbsncmp_l)
#include <libc/local/mbstring/_mbsncmp.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsncmp, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) int __NOTHROW_NCX(__LIBCCALL _mbsncmp)(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsncmp))(__lhs, __rhs, __maxlen); })
#endif /* ... */
#if defined(__CRT_HAVE__mbsncmp) || defined(__CRT_HAVE__mbsncmp_l)
#define _mbccmp(lhs, rhs) _mbsncmp(lhs, rhs, 1)
#endif /* __CRT_HAVE__mbsncmp || __CRT_HAVE__mbsncmp_l */
#ifdef __CRT_HAVE__mbsncoll
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsncoll,(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen),(__lhs,__rhs,__maxlen))
#elif defined(__CRT_HAVE__mbsncoll_l)
#include <libc/local/mbstring/_mbsncoll.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsncoll, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) int __NOTHROW_NCX(__LIBCCALL _mbsncoll)(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsncoll))(__lhs, __rhs, __maxlen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsncpy_s
__CDECLARE(__ATTR_NONNULL((1, 3)),errno_t,__NOTHROW_NCX,_mbsncpy_s,(unsigned char *__buf, size_t __bufsize, unsigned char const *__src, size_t __srclen),(__buf,__bufsize,__src,__srclen))
#elif defined(__CRT_HAVE__mbsncpy_s_l)
#include <libc/local/mbstring/_mbsncpy_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsncpy_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 3)) errno_t __NOTHROW_NCX(__LIBCCALL _mbsncpy_s)(unsigned char *__buf, size_t __bufsize, unsigned char const *__src, size_t __srclen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsncpy_s))(__buf, __bufsize, __src, __srclen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsncpy
__CDECLARE(__ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbsncpy,(unsigned char *__buf, unsigned char const *__src, size_t __srclen),(__buf,__src,__srclen))
#elif defined(__CRT_HAVE__mbsncpy_l)
#include <libc/local/mbstring/_mbsncpy.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsncpy, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 2)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsncpy)(unsigned char *__buf, unsigned char const *__src, size_t __srclen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsncpy))(__buf, __src, __srclen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnextc
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned int,__NOTHROW_NCX,_mbsnextc,(unsigned char const *__str),(__str))
#elif defined(__CRT_HAVE__mbsnextc_l)
#include <libc/local/mbstring/_mbsnextc.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnextc, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) unsigned int __NOTHROW_NCX(__LIBCCALL _mbsnextc)(unsigned char const *__str) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnextc))(__str); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnicmp
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsnicmp,(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen),(__lhs,__rhs,__maxlen))
#elif defined(__CRT_HAVE__mbsnicmp_l)
#include <libc/local/mbstring/_mbsnicmp.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnicmp, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) int __NOTHROW_NCX(__LIBCCALL _mbsnicmp)(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnicmp))(__lhs, __rhs, __maxlen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnicoll
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsnicoll,(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen),(__lhs,__rhs,__maxlen))
#elif defined(__CRT_HAVE__mbsnicoll_l)
#include <libc/local/mbstring/_mbsnicoll.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnicoll, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) int __NOTHROW_NCX(__LIBCCALL _mbsnicoll)(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnicoll))(__lhs, __rhs, __maxlen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsninc
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsninc,(unsigned char const *__str, size_t __maxlen),(__str,__maxlen))
#elif defined(__CRT_HAVE__mbsninc_l)
#include <libc/local/mbstring/_mbsninc.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsninc, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsninc)(unsigned char const *__str, size_t __maxlen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsninc))(__str, __maxlen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnset_s
__CDECLARE(__ATTR_NONNULL((1)),errno_t,__NOTHROW_NCX,_mbsnset_s,(unsigned char *__buf, size_t __bufsize, unsigned int __ch, size_t __num_chars),(__buf,__bufsize,__ch,__num_chars))
#elif defined(__CRT_HAVE__mbsnset_s_l)
#include <libc/local/mbstring/_mbsnset_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnset_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) errno_t __NOTHROW_NCX(__LIBCCALL _mbsnset_s)(unsigned char *__buf, size_t __bufsize, unsigned int __ch, size_t __num_chars) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnset_s))(__buf, __bufsize, __ch, __num_chars); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsnset
__CDECLARE(__ATTR_RETNONNULL __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsnset,(unsigned char *__buf, unsigned int __ch, size_t __maxlen),(__buf,__ch,__maxlen))
#elif defined(__CRT_HAVE__mbsnset_l)
#include <libc/local/mbstring/_mbsnset.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsnset, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_RETNONNULL __ATTR_NONNULL((1)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsnset)(unsigned char *__buf, unsigned int __ch, size_t __maxlen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsnset))(__buf, __ch, __maxlen); })
#endif /* ... */
#ifdef __CRT_HAVE__mbspbrk
#if defined(__cplusplus) && defined(__CORRECT_ISO_CPP_MBSTRING_H_PROTO)
extern "C++" {
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbspbrk,(unsigned char *__haystack, unsigned char const *__accept),_mbspbrk,(__haystack,__accept))
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),unsigned char const *,__NOTHROW_NCX,_mbspbrk,(unsigned char const *__haystack, unsigned char const *__accept),_mbspbrk,(__haystack,__accept))
} /* extern "C++" */
#else /* __cplusplus && __CORRECT_ISO_CPP_MBSTRING_H_PROTO */
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbspbrk,(unsigned char const *__haystack, unsigned char const *__accept),(__haystack,__accept))
#endif /* !__cplusplus || !__CORRECT_ISO_CPP_MBSTRING_H_PROTO */
#elif defined(__CRT_HAVE__mbspbrk_l)
#include <libc/local/mbstring/_mbspbrk.h>
#if defined(__cplusplus) && defined(__CORRECT_ISO_CPP_MBSTRING_H_PROTO)
extern "C++" {
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbspbrk)(unsigned char *__haystack, unsigned char const *__accept) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbspbrk))(__haystack, __accept); }
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) unsigned char const *__NOTHROW_NCX(__LIBCCALL _mbspbrk)(unsigned char const *__haystack, unsigned char const *__accept) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbspbrk))(__haystack, __accept); }
} /* extern "C++" */
#else /* __cplusplus && __CORRECT_ISO_CPP_MBSTRING_H_PROTO */
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbspbrk, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbspbrk)(unsigned char const *__haystack, unsigned char const *__accept) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbspbrk))(__haystack, __accept); })
#endif /* !__cplusplus || !__CORRECT_ISO_CPP_MBSTRING_H_PROTO */
#endif /* ... */
#ifdef __CRT_HAVE__mbsrchr
#if defined(__cplusplus) && defined(__CORRECT_ISO_CPP_MBSTRING_H_PROTO)
extern "C++" {
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsrchr,(unsigned char *__restrict __haystack, unsigned int __needle),_mbsrchr,(__haystack,__needle))
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char const *,__NOTHROW_NCX,_mbsrchr,(unsigned char const *__restrict __haystack, unsigned int __needle),_mbsrchr,(__haystack,__needle))
} /* extern "C++" */
#else /* __cplusplus && __CORRECT_ISO_CPP_MBSTRING_H_PROTO */
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsrchr,(unsigned char const *__haystack, unsigned int __needle),(__haystack,__needle))
#endif /* !__cplusplus || !__CORRECT_ISO_CPP_MBSTRING_H_PROTO */
#elif defined(__CRT_HAVE__mbsrchr_l)
#include <libc/local/mbstring/_mbsrchr.h>
#if defined(__cplusplus) && defined(__CORRECT_ISO_CPP_MBSTRING_H_PROTO)
extern "C++" {
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsrchr)(unsigned char *__restrict __haystack, unsigned int __needle) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsrchr))(__haystack, __needle); }
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) unsigned char const *__NOTHROW_NCX(__LIBCCALL _mbsrchr)(unsigned char const *__restrict __haystack, unsigned int __needle) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsrchr))(__haystack, __needle); }
} /* extern "C++" */
#else /* __cplusplus && __CORRECT_ISO_CPP_MBSTRING_H_PROTO */
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsrchr, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsrchr)(unsigned char const *__haystack, unsigned int __needle) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsrchr))(__haystack, __needle); })
#endif /* !__cplusplus || !__CORRECT_ISO_CPP_MBSTRING_H_PROTO */
#endif /* ... */
#ifdef __CRT_HAVE__mbsrev
__CDECLARE(__ATTR_RETNONNULL __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsrev,(unsigned char *__buf),(__buf))
#elif defined(__CRT_HAVE__mbsrev_l)
#include <libc/local/mbstring/_mbsrev.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsrev, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_RETNONNULL __ATTR_NONNULL((1)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsrev)(unsigned char *__buf) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsrev))(__buf); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsset_s
__CDECLARE(__ATTR_NONNULL((1)),errno_t,__NOTHROW_NCX,_mbsset_s,(unsigned char *__buf, size_t __bufsize, unsigned int __ch),(__buf,__bufsize,__ch))
#elif defined(__CRT_HAVE__mbsset_s_l)
#include <libc/local/mbstring/_mbsset_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsset_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) errno_t __NOTHROW_NCX(__LIBCCALL _mbsset_s)(unsigned char *__buf, size_t __bufsize, unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsset_s))(__buf, __bufsize, __ch); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsset
__CDECLARE(__ATTR_RETNONNULL __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsset,(unsigned char *__buf, unsigned int __ch),(__buf,__ch))
#elif defined(__CRT_HAVE__mbsset_l)
#include <libc/local/mbstring/_mbsset.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsset, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_RETNONNULL __ATTR_NONNULL((1)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsset)(unsigned char *__buf, unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsset))(__buf, __ch); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsspn
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),size_t,__NOTHROW_NCX,_mbsspn,(unsigned char const *__haystack, unsigned char const *__accept),(__haystack,__accept))
#elif defined(__CRT_HAVE__mbsspn_l)
#include <libc/local/mbstring/_mbsspn.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsspn, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) size_t __NOTHROW_NCX(__LIBCCALL _mbsspn)(unsigned char const *__haystack, unsigned char const *__accept) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsspn))(__haystack, __accept); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsspnp
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbsspnp,(unsigned char const *__lhs, unsigned char const *__rhs),(__lhs,__rhs))
#elif defined(__CRT_HAVE__mbsspnp_l)
#include <libc/local/mbstring/_mbsspnp.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsspnp, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsspnp)(unsigned char const *__lhs, unsigned char const *__rhs) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsspnp))(__lhs, __rhs); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsstr
#if defined(__cplusplus) && defined(__CORRECT_ISO_CPP_MBSTRING_H_PROTO)
extern "C++" {
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbsstr,(unsigned char *__haystack, unsigned char const *__needle),_mbsstr,(__haystack,__needle))
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),unsigned char const *,__NOTHROW_NCX,_mbsstr,(unsigned char const *__haystack, unsigned char const *__needle),_mbsstr,(__haystack,__needle))
} /* extern "C++" */
#else /* __cplusplus && __CORRECT_ISO_CPP_MBSTRING_H_PROTO */
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbsstr,(unsigned char const *__haystack, unsigned char const *__needle),(__haystack,__needle))
#endif /* !__cplusplus || !__CORRECT_ISO_CPP_MBSTRING_H_PROTO */
#elif defined(__CRT_HAVE__mbsstr_l)
#include <libc/local/mbstring/_mbsstr.h>
#if defined(__cplusplus) && defined(__CORRECT_ISO_CPP_MBSTRING_H_PROTO)
extern "C++" {
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsstr)(unsigned char *__haystack, unsigned char const *__needle) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsstr))(__haystack, __needle); }
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) unsigned char const *__NOTHROW_NCX(__LIBCCALL _mbsstr)(unsigned char const *__haystack, unsigned char const *__needle) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsstr))(__haystack, __needle); }
} /* extern "C++" */
#else /* __cplusplus && __CORRECT_ISO_CPP_MBSTRING_H_PROTO */
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsstr, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsstr)(unsigned char const *__haystack, unsigned char const *__needle) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsstr))(__haystack, __needle); })
#endif /* !__cplusplus || !__CORRECT_ISO_CPP_MBSTRING_H_PROTO */
#endif /* ... */
#ifdef __CRT_HAVE__mbstok
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((2)),unsigned char *,__NOTHROW_NCX,_mbstok,(unsigned char *__str, unsigned char const *__delim),(__str,__delim))
#elif defined(__CRT_HAVE__mbstok_l) || defined(__CRT_HAVE__mbstok_s_l)
#include <libc/local/mbstring/_mbstok.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbstok, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((2)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbstok)(unsigned char *__str, unsigned char const *__delim) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbstok))(__str, __delim); })
#endif /* ... */
#ifdef __CRT_HAVE__mbstok_s
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((2, 3)),unsigned char *,__NOTHROW_NCX,_mbstok_s,(unsigned char *__str, unsigned char const *__delim, unsigned char **__restrict __save_ptr),(__str,__delim,__save_ptr))
#elif defined(__CRT_HAVE__mbstok_s_l)
#include <libc/local/mbstring/_mbstok_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbstok_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((2, 3)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbstok_s)(unsigned char *__str, unsigned char const *__delim, unsigned char **__restrict __save_ptr) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbstok_s))(__str, __delim, __save_ptr); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsupr_s
__CDECLARE(__ATTR_NONNULL((1)),errno_t,__NOTHROW_NCX,_mbsupr_s,(unsigned char *__buf, size_t __bufsize),(__buf,__bufsize))
#elif defined(__CRT_HAVE__mbsupr_s_l)
#include <libc/local/mbstring/_mbsupr_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsupr_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) errno_t __NOTHROW_NCX(__LIBCCALL _mbsupr_s)(unsigned char *__buf, size_t __bufsize) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsupr_s))(__buf, __bufsize); })
#endif /* ... */
#ifdef __CRT_HAVE__mbsupr
__CDECLARE(__ATTR_RETNONNULL __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsupr,(unsigned char *__buf),(__buf))
#elif defined(__CRT_HAVE__mbsupr_l)
#include <libc/local/mbstring/_mbsupr.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbsupr, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_RETNONNULL __ATTR_NONNULL((1)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbsupr)(unsigned char *__buf) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbsupr))(__buf); })
#endif /* ... */
#ifdef __CRT_HAVE__mbclen
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1)),size_t,__NOTHROW_NCX,_mbclen,(unsigned char const *__str),(__str))
#elif defined(__CRT_HAVE__mbclen_l)
#include <libc/local/mbstring/_mbclen.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbclen, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) size_t __NOTHROW_NCX(__LIBCCALL _mbclen)(unsigned char const *__str) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbclen))(__str); })
#endif /* ... */
#ifdef __CRT_HAVE__mbccpy
__CDECLARE_VOID(__ATTR_NONNULL((1, 2)),__NOTHROW_NCX,_mbccpy,(unsigned char *__buf, unsigned char const *__src),(__buf,__src))
#elif defined(__CRT_HAVE__mbccpy_l)
#include <libc/local/mbstring/_mbccpy.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbccpy, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 2)) void __NOTHROW_NCX(__LIBCCALL _mbccpy)(unsigned char *__buf, unsigned char const *__src) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbccpy))(__buf, __src); })
#endif /* ... */
#ifdef __CRT_HAVE__mbccpy_s
__CDECLARE(__ATTR_NONNULL((1, 4)),errno_t,__NOTHROW_NCX,_mbccpy_s,(unsigned char *__buf, size_t __bufsize, int *__p_copied, unsigned char const *__src),(__buf,__bufsize,__p_copied,__src))
#elif defined(__CRT_HAVE__mbccpy_s_l)
#include <libc/local/mbstring/_mbccpy_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbccpy_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 4)) errno_t __NOTHROW_NCX(__LIBCCALL _mbccpy_s)(unsigned char *__buf, size_t __bufsize, int *__p_copied, unsigned char const *__src) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbccpy_s))(__buf, __bufsize, __p_copied, __src); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbcalnum
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcalnum,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbcalnum_l)
#include <libc/local/mbstring/_ismbcalnum.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbcalnum, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbcalnum)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbcalnum))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbcalpha
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcalpha,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbcalpha_l)
#include <libc/local/mbstring/_ismbcalpha.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbcalpha, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbcalpha)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbcalpha))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbcdigit
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcdigit,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbcdigit_l)
#include <libc/local/mbstring/_ismbcdigit.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbcdigit, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbcdigit)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbcdigit))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbcgraph
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcgraph,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbcgraph_l)
#include <libc/local/mbstring/_ismbcgraph.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbcgraph, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbcgraph)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbcgraph))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbclegal
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbclegal,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbclegal_l)
#include <libc/local/mbstring/_ismbclegal.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbclegal, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbclegal)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbclegal))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbclower
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbclower,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbclower_l)
#include <libc/local/mbstring/_ismbclower.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbclower, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbclower)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbclower))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbcprint
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcprint,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbcprint_l)
#include <libc/local/mbstring/_ismbcprint.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbcprint, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbcprint)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbcprint))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbcpunct
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcpunct,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbcpunct_l)
#include <libc/local/mbstring/_ismbcpunct.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbcpunct, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbcpunct)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbcpunct))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbcblank
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcblank,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbcblank_l)
#include <libc/local/mbstring/_ismbcblank.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbcblank, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbcblank)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbcblank))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbcspace
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcspace,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbcspace_l)
#include <libc/local/mbstring/_ismbcspace.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbcspace, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbcspace)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbcspace))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbcupper
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcupper,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbcupper_l)
#include <libc/local/mbstring/_ismbcupper.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbcupper, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbcupper)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbcupper))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__mbctolower
__CDECLARE(__ATTR_WUNUSED,unsigned int,__NOTHROW_NCX,_mbctolower,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__mbctolower_l)
#include <libc/local/mbstring/_mbctolower.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbctolower, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED unsigned int __NOTHROW_NCX(__LIBCCALL _mbctolower)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbctolower))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__mbctoupper
__CDECLARE(__ATTR_WUNUSED,unsigned int,__NOTHROW_NCX,_mbctoupper,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__mbctoupper_l)
#include <libc/local/mbstring/_mbctoupper.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbctoupper, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED unsigned int __NOTHROW_NCX(__LIBCCALL _mbctoupper)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbctoupper))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbchira
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbchira,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbchira_l)
#include <libc/local/mbstring/_ismbchira.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbchira, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbchira)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbchira))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbckata
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbckata,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbckata_l)
#include <libc/local/mbstring/_ismbckata.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbckata, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbckata)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbckata))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbcsymbol
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcsymbol,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbcsymbol_l)
#include <libc/local/mbstring/_ismbcsymbol.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbcsymbol, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbcsymbol)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbcsymbol))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbcl0
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcl0,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbcl0_l)
#include <libc/local/mbstring/_ismbcl0.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbcl0, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbcl0)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbcl0))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbcl1
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcl1,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbcl1_l)
#include <libc/local/mbstring/_ismbcl1.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbcl1, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbcl1)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbcl1))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbcl2
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcl2,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbcl2_l)
#include <libc/local/mbstring/_ismbcl2.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbcl2, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbcl2)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbcl2))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__mbcjistojms
__CDECLARE(__ATTR_WUNUSED,unsigned int,__NOTHROW_NCX,_mbcjistojms,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__mbcjistojms_l)
#include <libc/local/mbstring/_mbcjistojms.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbcjistojms, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED unsigned int __NOTHROW_NCX(__LIBCCALL _mbcjistojms)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbcjistojms))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__mbcjmstojis
__CDECLARE(__ATTR_WUNUSED,unsigned int,__NOTHROW_NCX,_mbcjmstojis,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__mbcjmstojis_l)
#include <libc/local/mbstring/_mbcjmstojis.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbcjmstojis, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED unsigned int __NOTHROW_NCX(__LIBCCALL _mbcjmstojis)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbcjmstojis))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__mbctohira
__CDECLARE(__ATTR_WUNUSED,unsigned int,__NOTHROW_NCX,_mbctohira,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__mbctohira_l)
#include <libc/local/mbstring/_mbctohira.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbctohira, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED unsigned int __NOTHROW_NCX(__LIBCCALL _mbctohira)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbctohira))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__mbctokata
__CDECLARE(__ATTR_WUNUSED,unsigned int,__NOTHROW_NCX,_mbctokata,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__mbctokata_l)
#include <libc/local/mbstring/_mbctokata.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbctokata, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED unsigned int __NOTHROW_NCX(__LIBCCALL _mbctokata)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbctokata))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbblead
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbblead,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbblead_l)
#include <libc/local/mbstring/_ismbblead.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbblead, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbblead)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbblead))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbbtrail
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbbtrail,(unsigned int __ch),(__ch))
#elif defined(__CRT_HAVE__ismbbtrail_l)
#include <libc/local/mbstring/_ismbbtrail.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbbtrail, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _ismbbtrail)(unsigned int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbbtrail))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbslead
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_ismbslead,(unsigned char const *__str, unsigned char const *__pos),(__str,__pos))
#elif defined(__CRT_HAVE__ismbslead_l)
#include <libc/local/mbstring/_ismbslead.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbslead, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) int __NOTHROW_NCX(__LIBCCALL _ismbslead)(unsigned char const *__str, unsigned char const *__pos) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbslead))(__str, __pos); })
#endif /* ... */
#ifdef __CRT_HAVE__ismbstrail
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_ismbstrail,(unsigned char const *__str, unsigned char const *__pos),(__str,__pos))
#elif defined(__CRT_HAVE__ismbstrail_l)
#include <libc/local/mbstring/_ismbstrail.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ismbstrail, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) int __NOTHROW_NCX(__LIBCCALL _ismbstrail)(unsigned char const *__str, unsigned char const *__pos) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ismbstrail))(__str, __pos); })
#endif /* ... */
__CDECLARE_OPT(__ATTR_WUNUSED,unsigned int,__NOTHROW_NCX,_mbbtombc_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_mbbtype_l,(unsigned char __ch, int __ctype, __locale_t __locale),(__ch,__ctype,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,unsigned int,__NOTHROW_NCX,_mbctombb_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(,int,__NOTHROW_NCX,_mbsbtype_l,(unsigned char const *__str, size_t __pos, __locale_t __locale),(__str,__pos,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1, 3)),errno_t,__NOTHROW_NCX,_mbscat_s_l,(unsigned char *__buf, size_t __bufsize, unsigned char const *__src, __locale_t __locale),(__buf,__bufsize,__src,__locale))
#ifdef __CRT_HAVE__mbscat_l
__CDECLARE(__ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbscat_l,(unsigned char *__restrict __dst, unsigned char const *__restrict __src, __locale_t __locale),(__dst,__src,__locale))
#else /* __CRT_HAVE__mbscat_l */
#include <libc/local/mbstring/_mbscat_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbscat_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbscat_l)(unsigned char *__restrict __dst, unsigned char const *__restrict __src, __locale_t __locale) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbscat_l))(__dst, __src, __locale); })
#endif /* !__CRT_HAVE__mbscat_l */
#ifdef __CRT_HAVE__mbschr_l
#if defined(__cplusplus) && defined(__CORRECT_ISO_CPP_MBSTRING_H_PROTO)
extern "C++" {
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbschr_l,(unsigned char *__restrict __haystack, int __needle, __locale_t __locale),_mbschr_l,(__haystack,__needle,__locale))
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char const *,__NOTHROW_NCX,_mbschr_l,(unsigned char const *__restrict __haystack, int __needle, __locale_t __locale),_mbschr_l,(__haystack,__needle,__locale))
} /* extern "C++" */
#else /* __cplusplus && __CORRECT_ISO_CPP_MBSTRING_H_PROTO */
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbschr_l,(unsigned char const *__restrict __haystack, unsigned int __needle, __locale_t __locale),(__haystack,__needle,__locale))
#endif /* !__cplusplus || !__CORRECT_ISO_CPP_MBSTRING_H_PROTO */
#endif /* __CRT_HAVE__mbschr_l */
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbscmp_l,(unsigned char const *__lhs, unsigned char const *__rhs, __locale_t __locale),(__lhs,__rhs,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbscoll_l,(unsigned char const *__lhs, unsigned char const *__rhs, __locale_t __locale),(__lhs,__rhs,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1, 3)),errno_t,__NOTHROW_NCX,_mbscpy_s_l,(unsigned char *__buf, size_t __bufsize, unsigned char const *__src, __locale_t __locale),(__buf,__bufsize,__src,__locale))
#ifdef __CRT_HAVE__mbscpy_l
__CDECLARE(__ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbscpy_l,(unsigned char *__restrict __dst, unsigned char const *__restrict __src, __locale_t __locale),(__dst,__src,__locale))
#else /* __CRT_HAVE__mbscpy_l */
#include <libc/local/mbstring/_mbscpy_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbscpy_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbscpy_l)(unsigned char *__restrict __dst, unsigned char const *__restrict __src, __locale_t __locale) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbscpy_l))(__dst, __src, __locale); })
#endif /* !__CRT_HAVE__mbscpy_l */
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),size_t,__NOTHROW_NCX,_mbscspn_l,(unsigned char const *__haystack, unsigned char const *__reject, __locale_t __locale),(__haystack,__reject,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbsdec_l,(unsigned char const *__start, unsigned char const *__pos, __locale_t __locale),(__start,__pos,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsicmp_l,(unsigned char const *__lhs, unsigned char const *__rhs, __locale_t __locale),(__lhs,__rhs,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsicoll_l,(unsigned char const *__lhs, unsigned char const *__rhs, __locale_t __locale),(__lhs,__rhs,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsinc_l,(unsigned char const *__ptr, __locale_t __locale),(__ptr,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1)),size_t,__NOTHROW_NCX,_mbslen_l,(unsigned char const *__str, __locale_t __locale),(__str,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1)),size_t,__NOTHROW_NCX,_mbsnlen_l,(unsigned char const *__str, size_t __maxlen, __locale_t __locale),(__str,__maxlen,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1)),errno_t,__NOTHROW_NCX,_mbslwr_s_l,(unsigned char *__buf, size_t __buflen, __locale_t __locale),(__buf,__buflen,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbslwr_l,(unsigned char *__buf, __locale_t __locale),(__buf,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1, 3)),errno_t,__NOTHROW_NCX,_mbsnbcat_s_l,(unsigned char *__buf, size_t __bufsize, unsigned char const *__src, size_t __maxlen, __locale_t __locale),(__buf,__bufsize,__src,__maxlen,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbsnbcat_l,(unsigned char *__buf, unsigned char const *__src, size_t __srclen, __locale_t __locale),(__buf,__src,__srclen,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsnbcmp_l,(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen, __locale_t __locale),(__lhs,__rhs,__maxlen,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsnbcoll_l,(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen, __locale_t __locale),(__lhs,__rhs,__maxlen,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1)),size_t,__NOTHROW_NCX,_mbsnbcnt_l,(unsigned char const *__str, size_t __maxlen, __locale_t __locale),(__str,__maxlen,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1, 3)),errno_t,__NOTHROW_NCX,_mbsnbcpy_s_l,(unsigned char *__buf, size_t __bufsize, unsigned char const *__src, size_t __srclen, __locale_t __locale),(__buf,__bufsize,__src,__srclen,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbsnbcpy_l,(unsigned char *__buf, unsigned char const *__src, size_t __srclen, __locale_t __locale),(__buf,__src,__srclen,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsnbicmp_l,(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen, __locale_t __locale),(__lhs,__rhs,__maxlen,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsnbicoll_l,(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen, __locale_t __locale),(__lhs,__rhs,__maxlen,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1)),errno_t,__NOTHROW_NCX,_mbsnbset_s_l,(unsigned char *__buf, size_t __bufsize, unsigned int __ch, size_t __num_chars, __locale_t __locale),(__buf,__bufsize,__ch,__num_chars,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsnbset_l,(unsigned char *__buf, unsigned int __ch, size_t __buflen, __locale_t __locale),(__buf,__ch,__buflen,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1, 3)),errno_t,__NOTHROW_NCX,_mbsncat_s_l,(unsigned char *__buf, size_t __bufsize, unsigned char const *__src, size_t __srclen, __locale_t __locale),(__buf,__bufsize,__src,__srclen,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbsncat_l,(unsigned char *__buf, unsigned char const *__src, size_t __srclen, __locale_t __locale),(__buf,__src,__srclen,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1)),size_t,__NOTHROW_NCX,_mbsnccnt_l,(unsigned char const *__str, size_t __maxlen, __locale_t __locale),(__str,__maxlen,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsncmp_l,(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen, __locale_t __locale),(__lhs,__rhs,__maxlen,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsncoll_l,(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen, __locale_t __locale),(__lhs,__rhs,__maxlen,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1, 3)),errno_t,__NOTHROW_NCX,_mbsncpy_s_l,(unsigned char *__buf, size_t __bufsize, unsigned char const *__src, size_t __maxlen, __locale_t __locale),(__buf,__bufsize,__src,__maxlen,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbsncpy_l,(unsigned char *__buf, unsigned char const *__src, size_t __srclen, __locale_t __locale),(__buf,__src,__srclen,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned int,__NOTHROW_NCX,_mbsnextc_l,(unsigned char const *__str, __locale_t __locale),(__str,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsnicmp_l,(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen, __locale_t __locale),(__lhs,__rhs,__maxlen,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_mbsnicoll_l,(unsigned char const *__lhs, unsigned char const *__rhs, size_t __maxlen, __locale_t __locale),(__lhs,__rhs,__maxlen,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsninc_l,(unsigned char const *__str, size_t __maxlen, __locale_t __locale),(__str,__maxlen,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1)),errno_t,__NOTHROW_NCX,_mbsnset_s_l,(unsigned char *__buf, size_t __bufsize, unsigned int __ch, size_t __maxlen, __locale_t __locale),(__buf,__bufsize,__ch,__maxlen,__locale))
__CDECLARE_OPT(__ATTR_RETNONNULL __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsnset_l,(unsigned char *__buf, unsigned int __ch, size_t __maxlen, __locale_t __locale),(__buf,__ch,__maxlen,__locale))
#ifdef __CRT_HAVE__mbspbrk_l
#if defined(__cplusplus) && defined(__CORRECT_ISO_CPP_MBSTRING_H_PROTO)
extern "C++" {
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbspbrk_l,(unsigned char *__haystack, unsigned char const *__accept, __locale_t __locale),_mbspbrk_l,(__haystack,__accept,__locale))
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),unsigned char const *,__NOTHROW_NCX,_mbspbrk_l,(unsigned char const *__haystack, unsigned char const *__accept, __locale_t __locale),_mbspbrk_l,(__haystack,__accept,__locale))
} /* extern "C++" */
#else /* __cplusplus && __CORRECT_ISO_CPP_MBSTRING_H_PROTO */
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbspbrk_l,(unsigned char const *__haystack, unsigned char const *__accept, __locale_t __locale),(__haystack,__accept,__locale))
#endif /* !__cplusplus || !__CORRECT_ISO_CPP_MBSTRING_H_PROTO */
#endif /* __CRT_HAVE__mbspbrk_l */
#ifdef __CRT_HAVE__mbsrchr_l
#if defined(__cplusplus) && defined(__CORRECT_ISO_CPP_MBSTRING_H_PROTO)
extern "C++" {
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsrchr_l,(unsigned char *__restrict __haystack, unsigned int __needle, __locale_t __locale),_mbsrchr_l,(__haystack,__needle,__locale))
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char const *,__NOTHROW_NCX,_mbsrchr_l,(unsigned char const *__restrict __haystack, unsigned int __needle, __locale_t __locale),_mbsrchr_l,(__haystack,__needle,__locale))
} /* extern "C++" */
#else /* __cplusplus && __CORRECT_ISO_CPP_MBSTRING_H_PROTO */
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsrchr_l,(unsigned char const *__haystack, unsigned int __needle, __locale_t __locale),(__haystack,__needle,__locale))
#endif /* !__cplusplus || !__CORRECT_ISO_CPP_MBSTRING_H_PROTO */
#endif /* __CRT_HAVE__mbsrchr_l */
__CDECLARE_OPT(__ATTR_RETNONNULL __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsrev_l,(unsigned char *__buf, __locale_t __locale),(__buf,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1)),errno_t,__NOTHROW_NCX,_mbsset_s_l,(unsigned char *__buf, size_t __bufsize, unsigned int __ch, __locale_t __locale),(__buf,__bufsize,__ch,__locale))
__CDECLARE_OPT(__ATTR_RETNONNULL __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsset_l,(unsigned char *__buf, unsigned int __ch, __locale_t __locale),(__buf,__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),size_t,__NOTHROW_NCX,_mbsspn_l,(unsigned char const *__haystack, unsigned char const *__accept, __locale_t __locale),(__haystack,__accept,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbsspnp_l,(unsigned char const *__lhs, unsigned char const *__rhs, __locale_t __locale),(__lhs,__rhs,__locale))
#ifdef __CRT_HAVE__mbsstr_l
#if defined(__cplusplus) && defined(__CORRECT_ISO_CPP_MBSTRING_H_PROTO)
extern "C++" {
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbsstr_l,(unsigned char *__haystack, unsigned char const *__needle, __locale_t __locale),_mbsstr_l,(__haystack,__needle,__locale))
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),unsigned char const *,__NOTHROW_NCX,_mbsstr_l,(unsigned char const *__haystack, unsigned char const *__needle, __locale_t __locale),_mbsstr_l,(__haystack,__needle,__locale))
} /* extern "C++" */
#else /* __cplusplus && __CORRECT_ISO_CPP_MBSTRING_H_PROTO */
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),unsigned char *,__NOTHROW_NCX,_mbsstr_l,(unsigned char const *__haystack, unsigned char const *__needle, __locale_t __locale),(__haystack,__needle,__locale))
#endif /* !__cplusplus || !__CORRECT_ISO_CPP_MBSTRING_H_PROTO */
#endif /* __CRT_HAVE__mbsstr_l */
#ifdef __CRT_HAVE__mbstok_l
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((2)),unsigned char *,__NOTHROW_NCX,_mbstok_l,(unsigned char *__str, unsigned char const *__delim, __locale_t __locale),(__str,__delim,__locale))
#elif defined(__CRT_HAVE__mbstok_s_l)
#include <libc/local/mbstring/_mbstok_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_mbstok_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((2)) unsigned char *__NOTHROW_NCX(__LIBCCALL _mbstok_l)(unsigned char *__str, unsigned char const *__delim, __locale_t __locale) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbstok_l))(__str, __delim, __locale); })
#endif /* ... */
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((2, 3)),unsigned char *,__NOTHROW_NCX,_mbstok_s_l,(unsigned char *__str, unsigned char const *__delim, unsigned char **__restrict __save_ptr, __locale_t __locale),(__str,__delim,__save_ptr,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1)),errno_t,__NOTHROW_NCX,_mbsupr_s_l,(unsigned char *__buf, size_t __bufsize, __locale_t __locale),(__buf,__bufsize,__locale))
__CDECLARE_OPT(__ATTR_RETNONNULL __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,_mbsupr_l,(unsigned char *__buf, __locale_t __locale),(__buf,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1)),size_t,__NOTHROW_NCX,_mbclen_l,(unsigned char const *__str, __locale_t __locale),(__str,__locale))
__CDECLARE_VOID_OPT(__ATTR_NONNULL((1, 2)),__NOTHROW_NCX,_mbccpy_l,(unsigned char *__buf, unsigned char const *__src, __locale_t __locale),(__buf,__src,__locale))
__CDECLARE_OPT(__ATTR_NONNULL((1, 4)),errno_t,__NOTHROW_NCX,_mbccpy_s_l,(unsigned char *__buf, size_t __bufsize, int *__p_copied, unsigned char const *__src, __locale_t __locale),(__buf,__bufsize,__p_copied,__src,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcalnum_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcalpha_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcdigit_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcgraph_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbclegal_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbclower_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcprint_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcpunct_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcblank_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcspace_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcupper_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,unsigned int,__NOTHROW_NCX,_mbctolower_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,unsigned int,__NOTHROW_NCX,_mbctoupper_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbchira_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbckata_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcsymbol_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcl0_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcl1_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbcl2_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,unsigned int,__NOTHROW_NCX,_mbcjistojms_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,unsigned int,__NOTHROW_NCX,_mbcjmstojis_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,unsigned int,__NOTHROW_NCX,_mbctohira_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,unsigned int,__NOTHROW_NCX,_mbctokata_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbblead_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_ismbbtrail_l,(unsigned int __ch, __locale_t __locale),(__ch,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_ismbslead_l,(unsigned char const *__str, unsigned char const *__pos, __locale_t __locale),(__str,__pos,__locale))
__CDECLARE_OPT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,_ismbstrail_l,(unsigned char const *__str, unsigned char const *__pos, __locale_t __locale),(__str,__pos,__locale))

__SYSDECL_END
#endif /* __CC__ */

#endif /* !_MBSTRING_H */