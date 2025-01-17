/* HASH CRC-32:0x7b8c6f1f */
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
#ifndef __local_c16truncate_defined
#define __local_c16truncate_defined
#include <__crt.h>
#include <features.h>
#include <bits/types.h>
#include <asm/os/oflags.h>
#include <asm/os/fcntl.h>
#if (defined(__CRT_HAVE_wtruncate64) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$wtruncate64) || (defined(__CRT_HAVE_wtruncate) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$wtruncate) || ((defined(__CRT_HAVE_truncate64) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open)) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize))) || defined(__CRT_HAVE_truncate) || defined(__CRT_HAVE___truncate) || defined(__CRT_HAVE___libc_truncate) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_openat64) || defined(__CRT_HAVE_openat)))) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize)) && defined(__O_WRONLY))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#ifndef __PIO_OFFSET
#ifdef __USE_KOS_ALTERATIONS
#define __PIO_OFFSET   __pos_t
#define __PIO_OFFSET64 __pos64_t
#else /* __USE_KOS_ALTERATIONS */
#define __PIO_OFFSET   __off_t
#define __PIO_OFFSET64 __off64_t
#endif /* !__USE_KOS_ALTERATIONS */
#endif /* !__PIO_OFFSET */
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_c16truncate64_defined
#define __local___localdep_c16truncate64_defined
#if defined(__CRT_HAVE_wtruncate) && __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__ && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1),int,__NOTHROW_NCX,__localdep_c16truncate64,(__CHAR16_TYPE__ const *__file, __PIO_OFFSET64 __length),wtruncate,(__file,__length))
#elif defined(__CRT_HAVE_DOS$wtruncate) && __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__
__CREDIRECT_DOS(__ATTR_IN(1),int,__NOTHROW_NCX,__localdep_c16truncate64,(__CHAR16_TYPE__ const *__file, __PIO_OFFSET64 __length),wtruncate,(__file,__length))
#elif defined(__CRT_HAVE_wtruncate64) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1),int,__NOTHROW_NCX,__localdep_c16truncate64,(__CHAR16_TYPE__ const *__file, __PIO_OFFSET64 __length),wtruncate64,(__file,__length))
#elif defined(__CRT_HAVE_DOS$wtruncate64)
__CREDIRECT_DOS(__ATTR_IN(1),int,__NOTHROW_NCX,__localdep_c16truncate64,(__CHAR16_TYPE__ const *__file, __PIO_OFFSET64 __length),wtruncate64,(__file,__length))
#elif ((defined(__CRT_HAVE_truncate64) || defined(__CRT_HAVE_truncate) || defined(__CRT_HAVE___truncate) || defined(__CRT_HAVE___libc_truncate) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open)) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize)))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || (defined(__CRT_HAVE_wtruncate) && __SIZEOF_WCHAR_T__ == 2)
__NAMESPACE_LOCAL_END
#include <libc/local/parts.wchar.unistd/wtruncate64.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c16truncate64 __NAMESPACE_LOCAL_TYPEHAX(int(__LIBDCALL*)(__CHAR16_TYPE__ const *,__PIO_OFFSET64),int(__LIBDCALL&)(__CHAR16_TYPE__ const *,__PIO_OFFSET64),wtruncate64)
#elif ((defined(__CRT_HAVE_truncate64) || defined(__CRT_HAVE_truncate) || defined(__CRT_HAVE___truncate) || defined(__CRT_HAVE___libc_truncate) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open)) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize)))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || defined(__CRT_HAVE_DOS$wtruncate)
__NAMESPACE_LOCAL_END
#include <libc/local/parts.uchar.unistd/c16truncate64.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c16truncate64 __LIBC_LOCAL_NAME(c16truncate64)
#else /* ... */
#undef __local___localdep_c16truncate64_defined
#endif /* !... */
#endif /* !__local___localdep_c16truncate64_defined */
#ifndef __local___localdep_convert_c16tombs_defined
#define __local___localdep_convert_c16tombs_defined
#if defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_MALLOC __ATTR_WUNUSED __ATTR_IN_OPT(1),char *,__NOTHROW_NCX,__localdep_convert_c16tombs,(__CHAR16_TYPE__ const *__str),convert_wcstombs,(__str))
#elif defined(__CRT_HAVE_DOS$convert_wcstombs)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT_DOS(__ATTR_MALLOC __ATTR_WUNUSED __ATTR_IN_OPT(1),char *,__NOTHROW_NCX,__localdep_convert_c16tombs,(__CHAR16_TYPE__ const *__str),convert_wcstombs,(__str))
#elif (defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
__NAMESPACE_LOCAL_END
#include <libc/local/uchar/convert_wcstombs.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_convert_c16tombs __NAMESPACE_LOCAL_TYPEHAX(char *(__LIBDCALL*)(__CHAR16_TYPE__ const *),char *(__LIBDCALL&)(__CHAR16_TYPE__ const *),convert_wcstombs)
#elif (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)
__NAMESPACE_LOCAL_END
#include <libc/local/uchar/convert_c16tombs.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_convert_c16tombs __LIBC_LOCAL_NAME(convert_c16tombs)
#else /* ... */
#undef __local___localdep_convert_c16tombs_defined
#endif /* !... */
#endif /* !__local___localdep_convert_c16tombs_defined */
#ifndef __local___localdep_crt_c16truncate32_defined
#define __local___localdep_crt_c16truncate32_defined
#if defined(__CRT_HAVE_wtruncate) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1),int,__NOTHROW_NCX,__localdep_crt_c16truncate32,(__CHAR16_TYPE__ const *__file, __pos32_t __length),wtruncate,(__file,__length))
#elif defined(__CRT_HAVE_DOS$wtruncate)
__CREDIRECT_DOS(__ATTR_IN(1),int,__NOTHROW_NCX,__localdep_crt_c16truncate32,(__CHAR16_TYPE__ const *__file, __pos32_t __length),wtruncate,(__file,__length))
#else /* ... */
#undef __local___localdep_crt_c16truncate32_defined
#endif /* !... */
#endif /* !__local___localdep_crt_c16truncate32_defined */
#ifndef __local___localdep_free_defined
#define __local___localdep_free_defined
#if __has_builtin(__builtin_free) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_free)
__CEIREDIRECT(,void,__NOTHROW_NCX,__localdep_free,(void *__mallptr),free,{ __builtin_free(__mallptr); })
#elif defined(__CRT_HAVE_free)
__CREDIRECT_VOID(,__NOTHROW_NCX,__localdep_free,(void *__mallptr),free,(__mallptr))
#elif defined(__CRT_HAVE_cfree)
__CREDIRECT_VOID(,__NOTHROW_NCX,__localdep_free,(void *__mallptr),cfree,(__mallptr))
#elif defined(__CRT_HAVE___libc_free)
__CREDIRECT_VOID(,__NOTHROW_NCX,__localdep_free,(void *__mallptr),__libc_free,(__mallptr))
#else /* ... */
#undef __local___localdep_free_defined
#endif /* !... */
#endif /* !__local___localdep_free_defined */
#ifndef __local___localdep_truncate_defined
#define __local___localdep_truncate_defined
#if defined(__CRT_HAVE_truncate) && (!defined(__USE_FILE_OFFSET64) || __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__)
__CREDIRECT(__ATTR_IN(1),int,__NOTHROW_NCX,__localdep_truncate,(char const *__file, __PIO_OFFSET __length),truncate,(__file,__length))
#elif defined(__CRT_HAVE___truncate) && (!defined(__USE_FILE_OFFSET64) || __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__)
__CREDIRECT(__ATTR_IN(1),int,__NOTHROW_NCX,__localdep_truncate,(char const *__file, __PIO_OFFSET __length),__truncate,(__file,__length))
#elif defined(__CRT_HAVE___libc_truncate) && (!defined(__USE_FILE_OFFSET64) || __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__)
__CREDIRECT(__ATTR_IN(1),int,__NOTHROW_NCX,__localdep_truncate,(char const *__file, __PIO_OFFSET __length),__libc_truncate,(__file,__length))
#elif defined(__CRT_HAVE_truncate64) && (defined(__USE_FILE_OFFSET64) || __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__)
__CREDIRECT(__ATTR_IN(1),int,__NOTHROW_NCX,__localdep_truncate,(char const *__file, __PIO_OFFSET __length),truncate64,(__file,__length))
#elif defined(__CRT_HAVE_truncate64) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open)) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize))) || defined(__CRT_HAVE_truncate) || defined(__CRT_HAVE___truncate) || defined(__CRT_HAVE___libc_truncate) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_openat64) || defined(__CRT_HAVE_openat)))) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize)) && defined(__O_WRONLY))
__NAMESPACE_LOCAL_END
#include <libc/local/unistd/truncate.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_truncate __LIBC_LOCAL_NAME(truncate)
#else /* ... */
#undef __local___localdep_truncate_defined
#endif /* !... */
#endif /* !__local___localdep_truncate_defined */
__LOCAL_LIBC(c16truncate) __ATTR_IN(1) int
__NOTHROW_NCX(__LIBDCALL __LIBC_LOCAL_NAME(c16truncate))(__CHAR16_TYPE__ const *__file, __PIO_OFFSET __length) {
#if (defined(__CRT_HAVE_wtruncate) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$wtruncate)
	return (__NAMESPACE_LOCAL_SYM __localdep_crt_c16truncate32)(__file, (__pos32_t)__length);
#elif (defined(__CRT_HAVE_wtruncate64) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$wtruncate64)
	return (__NAMESPACE_LOCAL_SYM __localdep_c16truncate64)(__file, (__PIO_OFFSET64)__length);
#else /* ... */
	int __result;
	char *__utf8_file;
	__utf8_file = (__NAMESPACE_LOCAL_SYM __localdep_convert_c16tombs)(__file);
	if __unlikely(!__utf8_file)
		return -1;
	__result = (__NAMESPACE_LOCAL_SYM __localdep_truncate)(__utf8_file, __length);
#if defined(__CRT_HAVE_free) || defined(__CRT_HAVE_cfree) || defined(__CRT_HAVE___libc_free)
	(__NAMESPACE_LOCAL_SYM __localdep_free)(__utf8_file);
#endif /* __CRT_HAVE_free || __CRT_HAVE_cfree || __CRT_HAVE___libc_free */
	return __result;
#endif /* !... */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_c16truncate_defined
#define __local___localdep_c16truncate_defined
#define __localdep_c16truncate __LIBC_LOCAL_NAME(c16truncate)
#endif /* !__local___localdep_c16truncate_defined */
#else /* (__CRT_HAVE_wtruncate64 && __SIZEOF_WCHAR_T__ == 2 && __LIBCCALL_IS_LIBDCALL) || __CRT_HAVE_DOS$wtruncate64 || (__CRT_HAVE_wtruncate && __SIZEOF_WCHAR_T__ == 2 && __LIBCCALL_IS_LIBDCALL) || __CRT_HAVE_DOS$wtruncate || ((__CRT_HAVE_truncate64 || ((__CRT_HAVE_open64 || __CRT_HAVE___open64 || __CRT_HAVE_open || __CRT_HAVE__open || __CRT_HAVE___open || __CRT_HAVE___libc_open) && (__CRT_HAVE_ftruncate64 || __CRT_HAVE__chsize_s || __CRT_HAVE_ftruncate || __CRT_HAVE___ftruncate || __CRT_HAVE___libc_ftruncate || __CRT_HAVE__chsize || __CRT_HAVE_chsize)) || __CRT_HAVE_truncate || __CRT_HAVE___truncate || __CRT_HAVE___libc_truncate || ((__CRT_HAVE_open64 || __CRT_HAVE___open64 || __CRT_HAVE_open || __CRT_HAVE__open || __CRT_HAVE___open || __CRT_HAVE___libc_open || (__AT_FDCWD && (__CRT_HAVE_openat64 || __CRT_HAVE_openat))) && (__CRT_HAVE_ftruncate64 || __CRT_HAVE__chsize_s || __CRT_HAVE_ftruncate || __CRT_HAVE___ftruncate || __CRT_HAVE___libc_ftruncate || __CRT_HAVE__chsize || __CRT_HAVE_chsize) && __O_WRONLY)) && ((__CRT_HAVE_convert_wcstombs && __SIZEOF_WCHAR_T__ == 2 && __LIBCCALL_IS_LIBDCALL) || __CRT_HAVE_DOS$convert_wcstombs || (__CRT_HAVE_convert_wcstombsn && __SIZEOF_WCHAR_T__ == 2) || __CRT_HAVE_DOS$convert_wcstombsn || __CRT_HAVE_format_aprintf_printer || __CRT_HAVE_format_aprintf_alloc || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc)) */
#undef __local_c16truncate_defined
#endif /* (!__CRT_HAVE_wtruncate64 || __SIZEOF_WCHAR_T__ != 2 || !__LIBCCALL_IS_LIBDCALL) && !__CRT_HAVE_DOS$wtruncate64 && (!__CRT_HAVE_wtruncate || __SIZEOF_WCHAR_T__ != 2 || !__LIBCCALL_IS_LIBDCALL) && !__CRT_HAVE_DOS$wtruncate && ((!__CRT_HAVE_truncate64 && ((!__CRT_HAVE_open64 && !__CRT_HAVE___open64 && !__CRT_HAVE_open && !__CRT_HAVE__open && !__CRT_HAVE___open && !__CRT_HAVE___libc_open) || (!__CRT_HAVE_ftruncate64 && !__CRT_HAVE__chsize_s && !__CRT_HAVE_ftruncate && !__CRT_HAVE___ftruncate && !__CRT_HAVE___libc_ftruncate && !__CRT_HAVE__chsize && !__CRT_HAVE_chsize)) && !__CRT_HAVE_truncate && !__CRT_HAVE___truncate && !__CRT_HAVE___libc_truncate && ((!__CRT_HAVE_open64 && !__CRT_HAVE___open64 && !__CRT_HAVE_open && !__CRT_HAVE__open && !__CRT_HAVE___open && !__CRT_HAVE___libc_open && (!__AT_FDCWD || (!__CRT_HAVE_openat64 && !__CRT_HAVE_openat))) || (!__CRT_HAVE_ftruncate64 && !__CRT_HAVE__chsize_s && !__CRT_HAVE_ftruncate && !__CRT_HAVE___ftruncate && !__CRT_HAVE___libc_ftruncate && !__CRT_HAVE__chsize && !__CRT_HAVE_chsize) || !__O_WRONLY)) || ((!__CRT_HAVE_convert_wcstombs || __SIZEOF_WCHAR_T__ != 2 || !__LIBCCALL_IS_LIBDCALL) && !__CRT_HAVE_DOS$convert_wcstombs && (!__CRT_HAVE_convert_wcstombsn || __SIZEOF_WCHAR_T__ != 2) && !__CRT_HAVE_DOS$convert_wcstombsn && !__CRT_HAVE_format_aprintf_printer && !__CRT_HAVE_format_aprintf_alloc && !__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc)) */
#endif /* !__local_c16truncate_defined */
