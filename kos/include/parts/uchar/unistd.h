/* HASH CRC-32:0xa4bcd7cc */
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
#ifndef _PARTS_UCHAR_UNISTD_H
#define _PARTS_UCHAR_UNISTD_H 1

#include <__stdinc.h>
#include <__crt.h>

#ifdef __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER
#pragma GCC system_header
#endif /* __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER */

#include <features.h>
#ifndef _UNISTD_H
#include <unistd.h>
#endif /* !_UNISTD_H */
#ifndef _UCHAR_H
#include <uchar.h>
#endif /* !_UCHAR_H */
#ifndef _PARTS_UCHAR_PROCESS_H
#include <parts/uchar/process.h>
#endif /* !_PARTS_UCHAR_PROCESS_H */

#ifdef __CC__
__SYSDECL_BEGIN

/************************************************************************/
/* WARNING: UTF-16 functions use DOS paths under `DOSFS_ENABLED'        */
/*          s.a. `dosfs_setenabled(3)'                                  */
/************************************************************************/

#if defined(__CRT_HAVE_wttyname) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> ttyname(3)
 * Return the name of a TTY given its file descriptor */
__CREDIRECT(__ATTR_WUNUSED,char16_t *,__NOTHROW_RPC,c16ttyname,(__fd_t __fd),wttyname,(__fd))
#elif defined(__CRT_HAVE_DOS$wttyname)
/* >> ttyname(3)
 * Return the name of a TTY given its file descriptor */
__CREDIRECT_DOS(__ATTR_WUNUSED,char16_t *,__NOTHROW_RPC,c16ttyname,(__fd_t __fd),wttyname,(__fd))
#elif defined(__CRT_HAVE_wttyname_r) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.unistd/wttyname.h>
/* >> ttyname(3)
 * Return the name of a TTY given its file descriptor */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED char16_t *__NOTHROW_RPC(__LIBDCALL c16ttyname)(__fd_t __fd) { return (__CHAR16_TYPE__ *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wttyname))(__fd); }
#elif defined(__CRT_HAVE_DOS$wttyname_r)
#include <libc/local/parts.uchar.unistd/c16ttyname.h>
/* >> ttyname(3)
 * Return the name of a TTY given its file descriptor */
__NAMESPACE_LOCAL_USING_OR_IMPL(c16ttyname, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED char16_t *__NOTHROW_RPC(__LIBDCALL c16ttyname)(__fd_t __fd) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16ttyname))(__fd); })
#endif /* ... */
#if defined(__CRT_HAVE_wttyname) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> ttyname(3)
 * Return the name of a TTY given its file descriptor */
__CREDIRECT(__ATTR_WUNUSED,char32_t *,__NOTHROW_RPC,c32ttyname,(__fd_t __fd),wttyname,(__fd))
#elif defined(__CRT_HAVE_KOS$wttyname)
/* >> ttyname(3)
 * Return the name of a TTY given its file descriptor */
__CREDIRECT_KOS(__ATTR_WUNUSED,char32_t *,__NOTHROW_RPC,c32ttyname,(__fd_t __fd),wttyname,(__fd))
#elif defined(__CRT_HAVE_wttyname_r) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.unistd/wttyname.h>
/* >> ttyname(3)
 * Return the name of a TTY given its file descriptor */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED char32_t *__NOTHROW_RPC(__LIBKCALL c32ttyname)(__fd_t __fd) { return (__CHAR32_TYPE__ *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wttyname))(__fd); }
#elif defined(__CRT_HAVE_KOS$wttyname_r)
#include <libc/local/parts.uchar.unistd/c32ttyname.h>
/* >> ttyname(3)
 * Return the name of a TTY given its file descriptor */
__NAMESPACE_LOCAL_USING_OR_IMPL(c32ttyname, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED char32_t *__NOTHROW_RPC(__LIBKCALL c32ttyname)(__fd_t __fd) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32ttyname))(__fd); })
#endif /* ... */
#if defined(__CRT_HAVE_wttyname_r) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> ttyname_r(3)
 * Return the name of a TTY given its file descriptor */
__CREDIRECT(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,c16ttyname_r,(__fd_t __fd, char16_t *__buf, size_t __buflen),wttyname_r,(__fd,__buf,__buflen))
#elif defined(__CRT_HAVE_DOS$wttyname_r)
/* >> ttyname_r(3)
 * Return the name of a TTY given its file descriptor */
__CREDIRECT_DOS(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,c16ttyname_r,(__fd_t __fd, char16_t *__buf, size_t __buflen),wttyname_r,(__fd,__buf,__buflen))
#endif /* ... */
#if defined(__CRT_HAVE_wttyname_r) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> ttyname_r(3)
 * Return the name of a TTY given its file descriptor */
__CREDIRECT(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,c32ttyname_r,(__fd_t __fd, char32_t *__buf, size_t __buflen),wttyname_r,(__fd,__buf,__buflen))
#elif defined(__CRT_HAVE_KOS$wttyname_r)
/* >> ttyname_r(3)
 * Return the name of a TTY given its file descriptor */
__CREDIRECT_KOS(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,c32ttyname_r,(__fd_t __fd, char32_t *__buf, size_t __buflen),wttyname_r,(__fd,__buf,__buflen))
#endif /* ... */
#if defined(__CRT_HAVE_wchown) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16chown,(char16_t const *__file, __uid_t __owner, __gid_t __group),wchown,(__file,__owner,__group))
#elif defined(__CRT_HAVE_DOS$wchown)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16chown,(char16_t const *__file, __uid_t __owner, __gid_t __group),wchown,(__file,__owner,__group))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wfchownat) || (defined(__CRT_HAVE_fchownat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_chown) || defined(__CRT_HAVE___chown) || defined(__CRT_HAVE___libc_chown) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_fchownat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2)
#include <libc/local/parts.wchar.unistd/wchown.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16chown)(char16_t const *__file, __uid_t __owner, __gid_t __group) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wchown))((__WCHAR_TYPE__ const *)__file, __owner, __group); }
#elif (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wfchownat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$wfchownat) || (defined(__CRT_HAVE_fchownat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fchownat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_chown) || defined(__CRT_HAVE___chown) || defined(__CRT_HAVE___libc_chown) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_fchownat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c16chown.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16chown, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16chown)(char16_t const *__file, __uid_t __owner, __gid_t __group) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16chown))(__file, __owner, __group); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wchown) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32chown,(char32_t const *__file, __uid_t __owner, __gid_t __group),wchown,(__file,__owner,__group))
#elif defined(__CRT_HAVE_KOS$wchown)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32chown,(char32_t const *__file, __uid_t __owner, __gid_t __group),wchown,(__file,__owner,__group))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wfchownat) || (defined(__CRT_HAVE_fchownat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_chown) || defined(__CRT_HAVE___chown) || defined(__CRT_HAVE___libc_chown) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_fchownat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4)
#include <libc/local/parts.wchar.unistd/wchown.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32chown)(char32_t const *__file, __uid_t __owner, __gid_t __group) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wchown))((__WCHAR_TYPE__ const *)__file, __owner, __group); }
#elif (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wfchownat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$wfchownat) || (defined(__CRT_HAVE_fchownat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fchownat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_chown) || defined(__CRT_HAVE___chown) || defined(__CRT_HAVE___libc_chown) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_fchownat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c32chown.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32chown, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32chown)(char32_t const *__file, __uid_t __owner, __gid_t __group) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32chown))(__file, __owner, __group); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wpathconf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),__LONGPTR_TYPE__,__NOTHROW_RPC,c16pathconf,(char16_t const *__path, __STDC_INT_AS_UINT_T __name),wpathconf,(__path,__name))
#elif defined(__CRT_HAVE_DOS$wpathconf)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),__LONGPTR_TYPE__,__NOTHROW_RPC,c16pathconf,(char16_t const *__path, __STDC_INT_AS_UINT_T __name),wpathconf,(__path,__name))
#else /* ... */
#include <asm/os/oflags.h>
#include <asm/os/fcntl.h>
#if (defined(__CRT_HAVE_pathconf) || defined(__CRT_HAVE___pathconf) || ((defined(__CRT_HAVE_fpathconf) || defined(__CRT_HAVE___fpathconf)) && (defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_openat64) || defined(__CRT_HAVE_openat)))) && defined(__O_RDONLY))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.unistd/wpathconf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) __LONGPTR_TYPE__ __NOTHROW_RPC(__LIBDCALL c16pathconf)(char16_t const *__path, __STDC_INT_AS_UINT_T __name) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wpathconf))((__WCHAR_TYPE__ const *)__path, __name); }
#elif (defined(__CRT_HAVE_pathconf) || defined(__CRT_HAVE___pathconf) || ((defined(__CRT_HAVE_fpathconf) || defined(__CRT_HAVE___fpathconf)) && (defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_openat64) || defined(__CRT_HAVE_openat)))) && defined(__O_RDONLY))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c16pathconf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16pathconf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) __LONGPTR_TYPE__ __NOTHROW_RPC(__LIBDCALL c16pathconf)(char16_t const *__path, __STDC_INT_AS_UINT_T __name) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16pathconf))(__path, __name); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wpathconf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),__LONGPTR_TYPE__,__NOTHROW_RPC,c32pathconf,(char32_t const *__path, __STDC_INT_AS_UINT_T __name),wpathconf,(__path,__name))
#elif defined(__CRT_HAVE_KOS$wpathconf)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),__LONGPTR_TYPE__,__NOTHROW_RPC,c32pathconf,(char32_t const *__path, __STDC_INT_AS_UINT_T __name),wpathconf,(__path,__name))
#else /* ... */
#include <asm/os/oflags.h>
#include <asm/os/fcntl.h>
#if (defined(__CRT_HAVE_pathconf) || defined(__CRT_HAVE___pathconf) || ((defined(__CRT_HAVE_fpathconf) || defined(__CRT_HAVE___fpathconf)) && (defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_openat64) || defined(__CRT_HAVE_openat)))) && defined(__O_RDONLY))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.unistd/wpathconf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) __LONGPTR_TYPE__ __NOTHROW_RPC(__LIBKCALL c32pathconf)(char32_t const *__path, __STDC_INT_AS_UINT_T __name) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wpathconf))((__WCHAR_TYPE__ const *)__path, __name); }
#elif (defined(__CRT_HAVE_pathconf) || defined(__CRT_HAVE___pathconf) || ((defined(__CRT_HAVE_fpathconf) || defined(__CRT_HAVE___fpathconf)) && (defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_openat64) || defined(__CRT_HAVE_openat)))) && defined(__O_RDONLY))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c32pathconf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32pathconf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) __LONGPTR_TYPE__ __NOTHROW_RPC(__LIBKCALL c32pathconf)(char32_t const *__path, __STDC_INT_AS_UINT_T __name) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32pathconf))(__path, __name); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wlink) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1, 2)),int,__NOTHROW_RPC,c16link,(char16_t const *__from, char16_t const *__to),wlink,(__from,__to))
#elif defined(__CRT_HAVE_DOS$wlink)
__CREDIRECT_DOS(__ATTR_NONNULL((1, 2)),int,__NOTHROW_RPC,c16link,(char16_t const *__from, char16_t const *__to),wlink,(__from,__to))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wlinkat) || ((defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && defined(__CRT_HAVE_linkat)))) || ((defined(__CRT_HAVE_link) || defined(__CRT_HAVE___link) || defined(__CRT_HAVE___libc_link) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_linkat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2)
#include <libc/local/parts.wchar.unistd/wlink.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 2)) int __NOTHROW_RPC(__LIBDCALL c16link)(char16_t const *__from, char16_t const *__to) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wlink))((__WCHAR_TYPE__ const *)__from, (__WCHAR_TYPE__ const *)__to); }
#elif (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wlinkat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$wlinkat) || ((defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && defined(__CRT_HAVE_linkat) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && defined(__CRT_HAVE_linkat)))) || ((defined(__CRT_HAVE_link) || defined(__CRT_HAVE___link) || defined(__CRT_HAVE___libc_link) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_linkat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c16link.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16link, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 2)) int __NOTHROW_RPC(__LIBDCALL c16link)(char16_t const *__from, char16_t const *__to) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16link))(__from, __to); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wlink) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1, 2)),int,__NOTHROW_RPC,c32link,(char32_t const *__from, char32_t const *__to),wlink,(__from,__to))
#elif defined(__CRT_HAVE_KOS$wlink)
__CREDIRECT_KOS(__ATTR_NONNULL((1, 2)),int,__NOTHROW_RPC,c32link,(char32_t const *__from, char32_t const *__to),wlink,(__from,__to))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wlinkat) || ((defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && defined(__CRT_HAVE_linkat)))) || ((defined(__CRT_HAVE_link) || defined(__CRT_HAVE___link) || defined(__CRT_HAVE___libc_link) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_linkat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4)
#include <libc/local/parts.wchar.unistd/wlink.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 2)) int __NOTHROW_RPC(__LIBKCALL c32link)(char32_t const *__from, char32_t const *__to) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wlink))((__WCHAR_TYPE__ const *)__from, (__WCHAR_TYPE__ const *)__to); }
#elif (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wlinkat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$wlinkat) || ((defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && defined(__CRT_HAVE_linkat) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && defined(__CRT_HAVE_linkat)))) || ((defined(__CRT_HAVE_link) || defined(__CRT_HAVE___link) || defined(__CRT_HAVE___libc_link) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_linkat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c32link.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32link, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 2)) int __NOTHROW_RPC(__LIBKCALL c32link)(char32_t const *__from, char32_t const *__to) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32link))(__from, __to); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_waccess) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16access,(char16_t const *__file, __STDC_INT_AS_UINT_T __type),waccess,(__file,__type))
#elif defined(__CRT_HAVE_DOS$waccess)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16access,(char16_t const *__file, __STDC_INT_AS_UINT_T __type),waccess,(__file,__type))
#elif defined(__CRT_HAVE__waccess) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16access,(char16_t const *__file, __STDC_INT_AS_UINT_T __type),_waccess,(__file,__type))
#elif defined(__CRT_HAVE_DOS$_waccess)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16access,(char16_t const *__file, __STDC_INT_AS_UINT_T __type),_waccess,(__file,__type))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_access) || defined(__CRT_HAVE__access) || defined(__CRT_HAVE___access) || defined(__CRT_HAVE___libc_access) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_faccessat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2)
#include <libc/local/parts.wchar.unistd/waccess.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16access)(char16_t const *__file, __STDC_INT_AS_UINT_T __type) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(waccess))((__WCHAR_TYPE__ const *)__file, __type); }
#elif (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wfaccessat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_faccessat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_access) || defined(__CRT_HAVE__access) || defined(__CRT_HAVE___access) || defined(__CRT_HAVE___libc_access) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_faccessat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c16access.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16access, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16access)(char16_t const *__file, __STDC_INT_AS_UINT_T __type) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16access))(__file, __type); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_waccess) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32access,(char32_t const *__file, __STDC_INT_AS_UINT_T __type),waccess,(__file,__type))
#elif defined(__CRT_HAVE_KOS$waccess)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32access,(char32_t const *__file, __STDC_INT_AS_UINT_T __type),waccess,(__file,__type))
#elif defined(__CRT_HAVE__waccess) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32access,(char32_t const *__file, __STDC_INT_AS_UINT_T __type),_waccess,(__file,__type))
#elif defined(__CRT_HAVE_KOS$_waccess)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32access,(char32_t const *__file, __STDC_INT_AS_UINT_T __type),_waccess,(__file,__type))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_access) || defined(__CRT_HAVE__access) || defined(__CRT_HAVE___access) || defined(__CRT_HAVE___libc_access) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_faccessat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4)
#include <libc/local/parts.wchar.unistd/waccess.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32access)(char32_t const *__file, __STDC_INT_AS_UINT_T __type) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(waccess))((__WCHAR_TYPE__ const *)__file, __type); }
#elif (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wfaccessat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_faccessat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_access) || defined(__CRT_HAVE__access) || defined(__CRT_HAVE___access) || defined(__CRT_HAVE___libc_access) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_faccessat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c32access.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32access, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32access)(char32_t const *__file, __STDC_INT_AS_UINT_T __type) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32access))(__file, __type); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wchdir) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16chdir,(char16_t const *__path),wchdir,(__path))
#elif defined(__CRT_HAVE_DOS$wchdir)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16chdir,(char16_t const *__path),wchdir,(__path))
#elif defined(__CRT_HAVE__wchdir) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16chdir,(char16_t const *__path),_wchdir,(__path))
#elif defined(__CRT_HAVE_DOS$_wchdir)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16chdir,(char16_t const *__path),_wchdir,(__path))
#elif (defined(__CRT_HAVE_chdir) || defined(__CRT_HAVE__chdir) || defined(__CRT_HAVE___chdir) || defined(__CRT_HAVE___libc_chdir)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.unistd/wchdir.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16chdir)(char16_t const *__path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wchdir))((__WCHAR_TYPE__ const *)__path); }
#elif (defined(__CRT_HAVE_chdir) || defined(__CRT_HAVE__chdir) || defined(__CRT_HAVE___chdir) || defined(__CRT_HAVE___libc_chdir)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c16chdir.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16chdir, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16chdir)(char16_t const *__path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16chdir))(__path); })
#endif /* ... */
#if defined(__CRT_HAVE_wchdir) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32chdir,(char32_t const *__path),wchdir,(__path))
#elif defined(__CRT_HAVE_KOS$wchdir)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32chdir,(char32_t const *__path),wchdir,(__path))
#elif defined(__CRT_HAVE__wchdir) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32chdir,(char32_t const *__path),_wchdir,(__path))
#elif defined(__CRT_HAVE_KOS$_wchdir)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32chdir,(char32_t const *__path),_wchdir,(__path))
#elif (defined(__CRT_HAVE_chdir) || defined(__CRT_HAVE__chdir) || defined(__CRT_HAVE___chdir) || defined(__CRT_HAVE___libc_chdir)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.unistd/wchdir.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32chdir)(char32_t const *__path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wchdir))((__WCHAR_TYPE__ const *)__path); }
#elif (defined(__CRT_HAVE_chdir) || defined(__CRT_HAVE__chdir) || defined(__CRT_HAVE___chdir) || defined(__CRT_HAVE___libc_chdir)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c32chdir.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32chdir, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32chdir)(char32_t const *__path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32chdir))(__path); })
#endif /* ... */
#if defined(__CRT_HAVE_wgetcwd) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(,char16_t *,__NOTHROW_RPC,c16getcwd,(char16_t *__buf, size_t __bufsize),wgetcwd,(__buf,__bufsize))
#elif defined(__CRT_HAVE_DOS$wgetcwd)
__CREDIRECT_DOS(,char16_t *,__NOTHROW_RPC,c16getcwd,(char16_t *__buf, size_t __bufsize),wgetcwd,(__buf,__bufsize))
#elif defined(__CRT_HAVE__wgetcwd) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(,char16_t *,__NOTHROW_RPC,c16getcwd,(char16_t *__buf, size_t __bufsize),_wgetcwd,(__buf,__bufsize))
#elif defined(__CRT_HAVE_DOS$_wgetcwd)
__CREDIRECT_DOS(,char16_t *,__NOTHROW_RPC,c16getcwd,(char16_t *__buf, size_t __bufsize),_wgetcwd,(__buf,__bufsize))
#elif (defined(__CRT_HAVE_getcwd) || defined(__CRT_HAVE__getcwd)) && (defined(__CRT_HAVE_convert_mbstowcs) || defined(__CRT_HAVE_convert_mbstowcsn) || ((defined(__CRT_HAVE_format_waprintf_printer) || defined(__CRT_HAVE_format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_format_waprintf_pack) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.unistd/wgetcwd.h>
__FORCELOCAL __ATTR_ARTIFICIAL char16_t *__NOTHROW_RPC(__LIBDCALL c16getcwd)(char16_t *__buf, size_t __bufsize) { return (__CHAR16_TYPE__ *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wgetcwd))((__WCHAR_TYPE__ *)__buf, __bufsize); }
#elif (defined(__CRT_HAVE_getcwd) || defined(__CRT_HAVE__getcwd)) && ((defined(__CRT_HAVE_convert_mbstowcs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_mbstowcs) || ((defined(__CRT_HAVE_convert_mbstowcsn) || ((defined(__CRT_HAVE_format_waprintf_printer) || defined(__CRT_HAVE_format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_format_waprintf_pack) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_convert_mbstowcsn) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_mbstowcsn) || ((defined(__CRT_HAVE_format_waprintf_printer) || defined(__CRT_HAVE_format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_format_waprintf_pack) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_format_waprintf_printer) && __SIZEOF_WCHAR_T__ == 2 && defined(__C16FORMATPRINTER_CC_IS_WFORMATPRINTER_CC)) || (defined(__CRT_HAVE_format_waprintf_alloc) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && ((defined(__CRT_HAVE_format_waprintf_pack) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$format_waprintf_pack) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))
#include <libc/local/parts.uchar.unistd/c16getcwd.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16getcwd, __FORCELOCAL __ATTR_ARTIFICIAL char16_t *__NOTHROW_RPC(__LIBDCALL c16getcwd)(char16_t *__buf, size_t __bufsize) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16getcwd))(__buf, __bufsize); })
#endif /* ... */
#if defined(__CRT_HAVE_wgetcwd) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(,char32_t *,__NOTHROW_RPC,c32getcwd,(char32_t *__buf, size_t __bufsize),wgetcwd,(__buf,__bufsize))
#elif defined(__CRT_HAVE_KOS$wgetcwd)
__CREDIRECT_KOS(,char32_t *,__NOTHROW_RPC,c32getcwd,(char32_t *__buf, size_t __bufsize),wgetcwd,(__buf,__bufsize))
#elif defined(__CRT_HAVE__wgetcwd) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(,char32_t *,__NOTHROW_RPC,c32getcwd,(char32_t *__buf, size_t __bufsize),_wgetcwd,(__buf,__bufsize))
#elif defined(__CRT_HAVE_KOS$_wgetcwd)
__CREDIRECT_KOS(,char32_t *,__NOTHROW_RPC,c32getcwd,(char32_t *__buf, size_t __bufsize),_wgetcwd,(__buf,__bufsize))
#elif (defined(__CRT_HAVE_getcwd) || defined(__CRT_HAVE__getcwd)) && (defined(__CRT_HAVE_convert_mbstowcs) || defined(__CRT_HAVE_convert_mbstowcsn) || ((defined(__CRT_HAVE_format_waprintf_printer) || defined(__CRT_HAVE_format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_format_waprintf_pack) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.unistd/wgetcwd.h>
__FORCELOCAL __ATTR_ARTIFICIAL char32_t *__NOTHROW_RPC(__LIBKCALL c32getcwd)(char32_t *__buf, size_t __bufsize) { return (__CHAR32_TYPE__ *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wgetcwd))((__WCHAR_TYPE__ *)__buf, __bufsize); }
#elif (defined(__CRT_HAVE_getcwd) || defined(__CRT_HAVE__getcwd)) && ((defined(__CRT_HAVE_convert_mbstowcs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_mbstowcs) || ((defined(__CRT_HAVE_convert_mbstowcsn) || ((defined(__CRT_HAVE_format_waprintf_printer) || defined(__CRT_HAVE_format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_format_waprintf_pack) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_convert_mbstowcsn) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_mbstowcsn) || ((defined(__CRT_HAVE_format_waprintf_printer) || defined(__CRT_HAVE_format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_format_waprintf_pack) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_format_waprintf_printer) && __SIZEOF_WCHAR_T__ == 4 && defined(__C32FORMATPRINTER_CC_IS_WFORMATPRINTER_CC)) || (defined(__CRT_HAVE_format_waprintf_alloc) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && ((defined(__CRT_HAVE_format_waprintf_pack) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$format_waprintf_pack) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))
#include <libc/local/parts.uchar.unistd/c32getcwd.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32getcwd, __FORCELOCAL __ATTR_ARTIFICIAL char32_t *__NOTHROW_RPC(__LIBKCALL c32getcwd)(char32_t *__buf, size_t __bufsize) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32getcwd))(__buf, __bufsize); })
#endif /* ... */
#if defined(__CRT_HAVE_wunlink) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16unlink,(char16_t const *__file),wunlink,(__file))
#elif defined(__CRT_HAVE_DOS$wunlink)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16unlink,(char16_t const *__file),wunlink,(__file))
#elif defined(__CRT_HAVE__wunlink) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16unlink,(char16_t const *__file),_wunlink,(__file))
#elif defined(__CRT_HAVE_DOS$_wunlink)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16unlink,(char16_t const *__file),_wunlink,(__file))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wunlinkat) || (defined(__CRT_HAVE_unlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_unlink) || defined(__CRT_HAVE__unlink) || defined(__CRT_HAVE___unlink) || defined(__CRT_HAVE___libc_unlink) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_unlinkat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2)
#include <libc/local/parts.wchar.unistd/wunlink.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16unlink)(char16_t const *__file) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wunlink))((__WCHAR_TYPE__ const *)__file); }
#elif (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wunlinkat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$wunlinkat) || (defined(__CRT_HAVE_unlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_unlinkat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_unlink) || defined(__CRT_HAVE__unlink) || defined(__CRT_HAVE___unlink) || defined(__CRT_HAVE___libc_unlink) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_unlinkat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c16unlink.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16unlink, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16unlink)(char16_t const *__file) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16unlink))(__file); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wunlink) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32unlink,(char32_t const *__file),wunlink,(__file))
#elif defined(__CRT_HAVE_KOS$wunlink)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32unlink,(char32_t const *__file),wunlink,(__file))
#elif defined(__CRT_HAVE__wunlink) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32unlink,(char32_t const *__file),_wunlink,(__file))
#elif defined(__CRT_HAVE_KOS$_wunlink)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32unlink,(char32_t const *__file),_wunlink,(__file))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wunlinkat) || (defined(__CRT_HAVE_unlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_unlink) || defined(__CRT_HAVE__unlink) || defined(__CRT_HAVE___unlink) || defined(__CRT_HAVE___libc_unlink) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_unlinkat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4)
#include <libc/local/parts.wchar.unistd/wunlink.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32unlink)(char32_t const *__file) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wunlink))((__WCHAR_TYPE__ const *)__file); }
#elif (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wunlinkat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$wunlinkat) || (defined(__CRT_HAVE_unlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_unlinkat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_unlink) || defined(__CRT_HAVE__unlink) || defined(__CRT_HAVE___unlink) || defined(__CRT_HAVE___libc_unlink) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_unlinkat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c32unlink.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32unlink, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32unlink)(char32_t const *__file) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32unlink))(__file); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wrmdir) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16rmdir,(char16_t const *__path),wrmdir,(__path))
#elif defined(__CRT_HAVE_DOS$wrmdir)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16rmdir,(char16_t const *__path),wrmdir,(__path))
#elif defined(__CRT_HAVE__wrmdir) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16rmdir,(char16_t const *__path),_wrmdir,(__path))
#elif defined(__CRT_HAVE_DOS$_wrmdir)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16rmdir,(char16_t const *__path),_wrmdir,(__path))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && defined(__AT_REMOVEDIR) && (defined(__CRT_HAVE_wunlinkat) || (defined(__CRT_HAVE_unlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_rmdir) || defined(__CRT_HAVE__rmdir) || defined(__CRT_HAVE___rmdir) || defined(__CRT_HAVE___libc_rmdir) || (defined(__AT_FDCWD) && defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2)
#include <libc/local/parts.wchar.unistd/wrmdir.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16rmdir)(char16_t const *__path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wrmdir))((__WCHAR_TYPE__ const *)__path); }
#elif (defined(__AT_FDCWD) && defined(__AT_REMOVEDIR) && ((defined(__CRT_HAVE_wunlinkat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$wunlinkat) || (defined(__CRT_HAVE_unlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_unlinkat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_rmdir) || defined(__CRT_HAVE__rmdir) || defined(__CRT_HAVE___rmdir) || defined(__CRT_HAVE___libc_rmdir) || (defined(__AT_FDCWD) && defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c16rmdir.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16rmdir, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16rmdir)(char16_t const *__path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16rmdir))(__path); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wrmdir) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32rmdir,(char32_t const *__path),wrmdir,(__path))
#elif defined(__CRT_HAVE_KOS$wrmdir)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32rmdir,(char32_t const *__path),wrmdir,(__path))
#elif defined(__CRT_HAVE__wrmdir) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32rmdir,(char32_t const *__path),_wrmdir,(__path))
#elif defined(__CRT_HAVE_KOS$_wrmdir)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32rmdir,(char32_t const *__path),_wrmdir,(__path))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && defined(__AT_REMOVEDIR) && (defined(__CRT_HAVE_wunlinkat) || (defined(__CRT_HAVE_unlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_rmdir) || defined(__CRT_HAVE__rmdir) || defined(__CRT_HAVE___rmdir) || defined(__CRT_HAVE___libc_rmdir) || (defined(__AT_FDCWD) && defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4)
#include <libc/local/parts.wchar.unistd/wrmdir.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32rmdir)(char32_t const *__path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wrmdir))((__WCHAR_TYPE__ const *)__path); }
#elif (defined(__AT_FDCWD) && defined(__AT_REMOVEDIR) && ((defined(__CRT_HAVE_wunlinkat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$wunlinkat) || (defined(__CRT_HAVE_unlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_unlinkat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_rmdir) || defined(__CRT_HAVE__rmdir) || defined(__CRT_HAVE___rmdir) || defined(__CRT_HAVE___libc_rmdir) || (defined(__AT_FDCWD) && defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c32rmdir.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32rmdir, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32rmdir)(char32_t const *__path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32rmdir))(__path); })
#endif /* ... */
#endif /* !... */
#ifdef __USE_GNU
#if defined(__CRT_HAVE_weuidaccess) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16euidaccess,(char16_t const *__file, __STDC_INT_AS_UINT_T __type),weuidaccess,(__file,__type))
#elif defined(__CRT_HAVE_DOS$weuidaccess)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16euidaccess,(char16_t const *__file, __STDC_INT_AS_UINT_T __type),weuidaccess,(__file,__type))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && defined(__AT_EACCESS) && (defined(__CRT_HAVE_wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_euidaccess) || defined(__CRT_HAVE_eaccess) || (defined(__CRT_HAVE__access) && defined(__CRT_DOS)) || (defined(__AT_FDCWD) && defined(__AT_EACCESS) && defined(__CRT_HAVE_faccessat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2)
#include <libc/local/parts.wchar.unistd/weuidaccess.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16euidaccess)(char16_t const *__file, __STDC_INT_AS_UINT_T __type) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(weuidaccess))((__WCHAR_TYPE__ const *)__file, __type); }
#elif (defined(__AT_FDCWD) && defined(__AT_EACCESS) && ((defined(__CRT_HAVE_wfaccessat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_faccessat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_euidaccess) || defined(__CRT_HAVE_eaccess) || (defined(__CRT_HAVE__access) && defined(__CRT_DOS)) || (defined(__AT_FDCWD) && defined(__AT_EACCESS) && defined(__CRT_HAVE_faccessat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c16euidaccess.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16euidaccess, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16euidaccess)(char16_t const *__file, __STDC_INT_AS_UINT_T __type) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16euidaccess))(__file, __type); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_weuidaccess) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32euidaccess,(char32_t const *__file, __STDC_INT_AS_UINT_T __type),weuidaccess,(__file,__type))
#elif defined(__CRT_HAVE_KOS$weuidaccess)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32euidaccess,(char32_t const *__file, __STDC_INT_AS_UINT_T __type),weuidaccess,(__file,__type))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && defined(__AT_EACCESS) && (defined(__CRT_HAVE_wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_euidaccess) || defined(__CRT_HAVE_eaccess) || (defined(__CRT_HAVE__access) && defined(__CRT_DOS)) || (defined(__AT_FDCWD) && defined(__AT_EACCESS) && defined(__CRT_HAVE_faccessat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4)
#include <libc/local/parts.wchar.unistd/weuidaccess.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32euidaccess)(char32_t const *__file, __STDC_INT_AS_UINT_T __type) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(weuidaccess))((__WCHAR_TYPE__ const *)__file, __type); }
#elif (defined(__AT_FDCWD) && defined(__AT_EACCESS) && ((defined(__CRT_HAVE_wfaccessat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_faccessat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_euidaccess) || defined(__CRT_HAVE_eaccess) || (defined(__CRT_HAVE__access) && defined(__CRT_DOS)) || (defined(__AT_FDCWD) && defined(__AT_EACCESS) && defined(__CRT_HAVE_faccessat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c32euidaccess.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32euidaccess, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32euidaccess)(char32_t const *__file, __STDC_INT_AS_UINT_T __type) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32euidaccess))(__file, __type); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_weuidaccess) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16eaccess,(char16_t const *__file, __STDC_INT_AS_UINT_T __type),weuidaccess,(__file,__type))
#elif defined(__CRT_HAVE_DOS$weuidaccess)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16eaccess,(char16_t const *__file, __STDC_INT_AS_UINT_T __type),weuidaccess,(__file,__type))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && defined(__AT_EACCESS) && (defined(__CRT_HAVE_wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_euidaccess) || defined(__CRT_HAVE_eaccess) || (defined(__CRT_HAVE__access) && defined(__CRT_DOS)) || (defined(__AT_FDCWD) && defined(__AT_EACCESS) && defined(__CRT_HAVE_faccessat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2)
#include <libc/local/parts.wchar.unistd/weuidaccess.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16eaccess)(char16_t const *__file, __STDC_INT_AS_UINT_T __type) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(weuidaccess))((__WCHAR_TYPE__ const *)__file, __type); }
#elif (defined(__AT_FDCWD) && defined(__AT_EACCESS) && ((defined(__CRT_HAVE_wfaccessat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_faccessat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_euidaccess) || defined(__CRT_HAVE_eaccess) || (defined(__CRT_HAVE__access) && defined(__CRT_DOS)) || (defined(__AT_FDCWD) && defined(__AT_EACCESS) && defined(__CRT_HAVE_faccessat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c16euidaccess.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16eaccess)(char16_t const *__file, __STDC_INT_AS_UINT_T __type) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16euidaccess))(__file, __type); }
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_weuidaccess) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32eaccess,(char32_t const *__file, __STDC_INT_AS_UINT_T __type),weuidaccess,(__file,__type))
#elif defined(__CRT_HAVE_KOS$weuidaccess)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32eaccess,(char32_t const *__file, __STDC_INT_AS_UINT_T __type),weuidaccess,(__file,__type))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && defined(__AT_EACCESS) && (defined(__CRT_HAVE_wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_euidaccess) || defined(__CRT_HAVE_eaccess) || (defined(__CRT_HAVE__access) && defined(__CRT_DOS)) || (defined(__AT_FDCWD) && defined(__AT_EACCESS) && defined(__CRT_HAVE_faccessat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4)
#include <libc/local/parts.wchar.unistd/weuidaccess.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32eaccess)(char32_t const *__file, __STDC_INT_AS_UINT_T __type) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(weuidaccess))((__WCHAR_TYPE__ const *)__file, __type); }
#elif (defined(__AT_FDCWD) && defined(__AT_EACCESS) && ((defined(__CRT_HAVE_wfaccessat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_faccessat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_euidaccess) || defined(__CRT_HAVE_eaccess) || (defined(__CRT_HAVE__access) && defined(__CRT_DOS)) || (defined(__AT_FDCWD) && defined(__AT_EACCESS) && defined(__CRT_HAVE_faccessat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c32euidaccess.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32eaccess)(char32_t const *__file, __STDC_INT_AS_UINT_T __type) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32euidaccess))(__file, __type); }
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wget_current_dir_name) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_MALLOC __ATTR_WUNUSED,char16_t *,__NOTHROW_RPC,c16get_current_dir_name,(void),wget_current_dir_name,())
#elif defined(__CRT_HAVE_DOS$wget_current_dir_name)
__CREDIRECT_DOS(__ATTR_MALLOC __ATTR_WUNUSED,char16_t *,__NOTHROW_RPC,c16get_current_dir_name,(void),wget_current_dir_name,())
#elif (defined(__CRT_HAVE_get_current_dir_name) || defined(__CRT_HAVE_getcwd) || defined(__CRT_HAVE__getcwd)) && (defined(__CRT_HAVE_convert_mbstowcs) || defined(__CRT_HAVE_convert_mbstowcsn) || ((defined(__CRT_HAVE_format_waprintf_printer) || defined(__CRT_HAVE_format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_format_waprintf_pack) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.unistd/wget_current_dir_name.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_MALLOC __ATTR_WUNUSED char16_t *__NOTHROW_RPC(__LIBDCALL c16get_current_dir_name)(void) { return (__CHAR16_TYPE__ *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wget_current_dir_name))(); }
#elif (defined(__CRT_HAVE_get_current_dir_name) || defined(__CRT_HAVE_getcwd) || defined(__CRT_HAVE__getcwd)) && ((defined(__CRT_HAVE_convert_mbstowcs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_mbstowcs) || ((defined(__CRT_HAVE_convert_mbstowcsn) || ((defined(__CRT_HAVE_format_waprintf_printer) || defined(__CRT_HAVE_format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_format_waprintf_pack) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_convert_mbstowcsn) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_mbstowcsn) || ((defined(__CRT_HAVE_format_waprintf_printer) || defined(__CRT_HAVE_format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_format_waprintf_pack) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_format_waprintf_printer) && __SIZEOF_WCHAR_T__ == 2 && defined(__C16FORMATPRINTER_CC_IS_WFORMATPRINTER_CC)) || (defined(__CRT_HAVE_format_waprintf_alloc) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && ((defined(__CRT_HAVE_format_waprintf_pack) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$format_waprintf_pack) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))
#include <libc/local/parts.uchar.unistd/c16get_current_dir_name.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16get_current_dir_name, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_MALLOC __ATTR_WUNUSED char16_t *__NOTHROW_RPC(__LIBDCALL c16get_current_dir_name)(void) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16get_current_dir_name))(); })
#endif /* ... */
#if defined(__CRT_HAVE_wget_current_dir_name) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_MALLOC __ATTR_WUNUSED,char32_t *,__NOTHROW_RPC,c32get_current_dir_name,(void),wget_current_dir_name,())
#elif defined(__CRT_HAVE_KOS$wget_current_dir_name)
__CREDIRECT_KOS(__ATTR_MALLOC __ATTR_WUNUSED,char32_t *,__NOTHROW_RPC,c32get_current_dir_name,(void),wget_current_dir_name,())
#elif (defined(__CRT_HAVE_get_current_dir_name) || defined(__CRT_HAVE_getcwd) || defined(__CRT_HAVE__getcwd)) && (defined(__CRT_HAVE_convert_mbstowcs) || defined(__CRT_HAVE_convert_mbstowcsn) || ((defined(__CRT_HAVE_format_waprintf_printer) || defined(__CRT_HAVE_format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_format_waprintf_pack) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.unistd/wget_current_dir_name.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_MALLOC __ATTR_WUNUSED char32_t *__NOTHROW_RPC(__LIBKCALL c32get_current_dir_name)(void) { return (__CHAR32_TYPE__ *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wget_current_dir_name))(); }
#elif (defined(__CRT_HAVE_get_current_dir_name) || defined(__CRT_HAVE_getcwd) || defined(__CRT_HAVE__getcwd)) && ((defined(__CRT_HAVE_convert_mbstowcs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_mbstowcs) || ((defined(__CRT_HAVE_convert_mbstowcsn) || ((defined(__CRT_HAVE_format_waprintf_printer) || defined(__CRT_HAVE_format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_format_waprintf_pack) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_convert_mbstowcsn) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_mbstowcsn) || ((defined(__CRT_HAVE_format_waprintf_printer) || defined(__CRT_HAVE_format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_format_waprintf_pack) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_format_waprintf_printer) && __SIZEOF_WCHAR_T__ == 4 && defined(__C32FORMATPRINTER_CC_IS_WFORMATPRINTER_CC)) || (defined(__CRT_HAVE_format_waprintf_alloc) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && ((defined(__CRT_HAVE_format_waprintf_pack) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$format_waprintf_pack) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))
#include <libc/local/parts.uchar.unistd/c32get_current_dir_name.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32get_current_dir_name, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_MALLOC __ATTR_WUNUSED char32_t *__NOTHROW_RPC(__LIBKCALL c32get_current_dir_name)(void) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32get_current_dir_name))(); })
#endif /* ... */
#endif /* __USE_GNU */
#ifdef __USE_ATFILE
#if defined(__CRT_HAVE_wfaccessat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,c16faccessat,(__fd_t __dfd, char16_t const *__file, __STDC_INT_AS_UINT_T __type, __atflag_t __flags),wfaccessat,(__dfd,__file,__type,__flags))
#elif defined(__CRT_HAVE_DOS$wfaccessat)
__CREDIRECT_DOS(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,c16faccessat,(__fd_t __dfd, char16_t const *__file, __STDC_INT_AS_UINT_T __type, __atflag_t __flags),wfaccessat,(__dfd,__file,__type,__flags))
#elif defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.unistd/wfaccessat.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((2)) int __NOTHROW_RPC(__LIBDCALL c16faccessat)(__fd_t __dfd, char16_t const *__file, __STDC_INT_AS_UINT_T __type, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wfaccessat))(__dfd, (__WCHAR_TYPE__ const *)__file, __type, __flags); }
#elif defined(__CRT_HAVE_faccessat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c16faccessat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16faccessat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((2)) int __NOTHROW_RPC(__LIBDCALL c16faccessat)(__fd_t __dfd, char16_t const *__file, __STDC_INT_AS_UINT_T __type, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16faccessat))(__dfd, __file, __type, __flags); })
#endif /* ... */
#if defined(__CRT_HAVE_wfaccessat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,c32faccessat,(__fd_t __dfd, char32_t const *__file, __STDC_INT_AS_UINT_T __type, __atflag_t __flags),wfaccessat,(__dfd,__file,__type,__flags))
#elif defined(__CRT_HAVE_KOS$wfaccessat)
__CREDIRECT_KOS(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,c32faccessat,(__fd_t __dfd, char32_t const *__file, __STDC_INT_AS_UINT_T __type, __atflag_t __flags),wfaccessat,(__dfd,__file,__type,__flags))
#elif defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.unistd/wfaccessat.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((2)) int __NOTHROW_RPC(__LIBKCALL c32faccessat)(__fd_t __dfd, char32_t const *__file, __STDC_INT_AS_UINT_T __type, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wfaccessat))(__dfd, (__WCHAR_TYPE__ const *)__file, __type, __flags); }
#elif defined(__CRT_HAVE_faccessat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c32faccessat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32faccessat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((2)) int __NOTHROW_RPC(__LIBKCALL c32faccessat)(__fd_t __dfd, char32_t const *__file, __STDC_INT_AS_UINT_T __type, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32faccessat))(__dfd, __file, __type, __flags); })
#endif /* ... */
#if defined(__CRT_HAVE_wfchownat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,c16fchownat,(__fd_t __dfd, char16_t const *__file, __uid_t __owner, __gid_t __group, __atflag_t __flags),wfchownat,(__dfd,__file,__owner,__group,__flags))
#elif defined(__CRT_HAVE_DOS$wfchownat)
__CREDIRECT_DOS(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,c16fchownat,(__fd_t __dfd, char16_t const *__file, __uid_t __owner, __gid_t __group, __atflag_t __flags),wfchownat,(__dfd,__file,__owner,__group,__flags))
#elif defined(__CRT_HAVE_fchownat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.unistd/wfchownat.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((2)) int __NOTHROW_RPC(__LIBDCALL c16fchownat)(__fd_t __dfd, char16_t const *__file, __uid_t __owner, __gid_t __group, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wfchownat))(__dfd, (__WCHAR_TYPE__ const *)__file, __owner, __group, __flags); }
#elif defined(__CRT_HAVE_fchownat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c16fchownat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16fchownat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((2)) int __NOTHROW_RPC(__LIBDCALL c16fchownat)(__fd_t __dfd, char16_t const *__file, __uid_t __owner, __gid_t __group, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16fchownat))(__dfd, __file, __owner, __group, __flags); })
#endif /* ... */
#if defined(__CRT_HAVE_wfchownat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,c32fchownat,(__fd_t __dfd, char32_t const *__file, __uid_t __owner, __gid_t __group, __atflag_t __flags),wfchownat,(__dfd,__file,__owner,__group,__flags))
#elif defined(__CRT_HAVE_KOS$wfchownat)
__CREDIRECT_KOS(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,c32fchownat,(__fd_t __dfd, char32_t const *__file, __uid_t __owner, __gid_t __group, __atflag_t __flags),wfchownat,(__dfd,__file,__owner,__group,__flags))
#elif defined(__CRT_HAVE_fchownat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.unistd/wfchownat.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((2)) int __NOTHROW_RPC(__LIBKCALL c32fchownat)(__fd_t __dfd, char32_t const *__file, __uid_t __owner, __gid_t __group, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wfchownat))(__dfd, (__WCHAR_TYPE__ const *)__file, __owner, __group, __flags); }
#elif defined(__CRT_HAVE_fchownat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c32fchownat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32fchownat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((2)) int __NOTHROW_RPC(__LIBKCALL c32fchownat)(__fd_t __dfd, char32_t const *__file, __uid_t __owner, __gid_t __group, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32fchownat))(__dfd, __file, __owner, __group, __flags); })
#endif /* ... */
#if defined(__CRT_HAVE_wlinkat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((2, 4)),int,__NOTHROW_RPC,c16linkat,(__fd_t __fromfd, char16_t const *__from, __fd_t __tofd, char16_t const *__to, __atflag_t __flags),wlinkat,(__fromfd,__from,__tofd,__to,__flags))
#elif defined(__CRT_HAVE_DOS$wlinkat)
__CREDIRECT_DOS(__ATTR_NONNULL((2, 4)),int,__NOTHROW_RPC,c16linkat,(__fd_t __fromfd, char16_t const *__from, __fd_t __tofd, char16_t const *__to, __atflag_t __flags),wlinkat,(__fromfd,__from,__tofd,__to,__flags))
#elif (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && defined(__CRT_HAVE_linkat) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.unistd/wlinkat.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((2, 4)) int __NOTHROW_RPC(__LIBDCALL c16linkat)(__fd_t __fromfd, char16_t const *__from, __fd_t __tofd, char16_t const *__to, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wlinkat))(__fromfd, (__WCHAR_TYPE__ const *)__from, __tofd, (__WCHAR_TYPE__ const *)__to, __flags); }
#elif ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && defined(__CRT_HAVE_linkat)
#include <libc/local/parts.uchar.unistd/c16linkat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16linkat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((2, 4)) int __NOTHROW_RPC(__LIBDCALL c16linkat)(__fd_t __fromfd, char16_t const *__from, __fd_t __tofd, char16_t const *__to, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16linkat))(__fromfd, __from, __tofd, __to, __flags); })
#endif /* ... */
#if defined(__CRT_HAVE_wlinkat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((2, 4)),int,__NOTHROW_RPC,c32linkat,(__fd_t __fromfd, char32_t const *__from, __fd_t __tofd, char32_t const *__to, __atflag_t __flags),wlinkat,(__fromfd,__from,__tofd,__to,__flags))
#elif defined(__CRT_HAVE_KOS$wlinkat)
__CREDIRECT_KOS(__ATTR_NONNULL((2, 4)),int,__NOTHROW_RPC,c32linkat,(__fd_t __fromfd, char32_t const *__from, __fd_t __tofd, char32_t const *__to, __atflag_t __flags),wlinkat,(__fromfd,__from,__tofd,__to,__flags))
#elif (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && defined(__CRT_HAVE_linkat) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.unistd/wlinkat.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((2, 4)) int __NOTHROW_RPC(__LIBKCALL c32linkat)(__fd_t __fromfd, char32_t const *__from, __fd_t __tofd, char32_t const *__to, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wlinkat))(__fromfd, (__WCHAR_TYPE__ const *)__from, __tofd, (__WCHAR_TYPE__ const *)__to, __flags); }
#elif ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && defined(__CRT_HAVE_linkat)
#include <libc/local/parts.uchar.unistd/c32linkat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32linkat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((2, 4)) int __NOTHROW_RPC(__LIBKCALL c32linkat)(__fd_t __fromfd, char32_t const *__from, __fd_t __tofd, char32_t const *__to, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32linkat))(__fromfd, __from, __tofd, __to, __flags); })
#endif /* ... */
#if defined(__CRT_HAVE_wsymlinkat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1, 3)),int,__NOTHROW_RPC,c16symlinkat,(char16_t const *__link_text, __fd_t __tofd, char16_t const *__target_path),wsymlinkat,(__link_text,__tofd,__target_path))
#elif defined(__CRT_HAVE_DOS$wsymlinkat)
__CREDIRECT_DOS(__ATTR_NONNULL((1, 3)),int,__NOTHROW_RPC,c16symlinkat,(char16_t const *__link_text, __fd_t __tofd, char16_t const *__target_path),wsymlinkat,(__link_text,__tofd,__target_path))
#elif defined(__CRT_HAVE_wfsymlinkat) || (defined(__CRT_HAVE_fsymlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || ((defined(__CRT_HAVE_symlinkat) || defined(__CRT_HAVE_fsymlinkat)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2)
#include <libc/local/parts.wchar.unistd/wsymlinkat.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 3)) int __NOTHROW_RPC(__LIBDCALL c16symlinkat)(char16_t const *__link_text, __fd_t __tofd, char16_t const *__target_path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wsymlinkat))((__WCHAR_TYPE__ const *)__link_text, __tofd, (__WCHAR_TYPE__ const *)__target_path); }
#elif defined(__CRT_HAVE_DOS$wfsymlinkat) || (defined(__CRT_HAVE_fsymlinkat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || ((defined(__CRT_HAVE_symlinkat) || defined(__CRT_HAVE_fsymlinkat)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c16symlinkat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16symlinkat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 3)) int __NOTHROW_RPC(__LIBDCALL c16symlinkat)(char16_t const *__link_text, __fd_t __tofd, char16_t const *__target_path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16symlinkat))(__link_text, __tofd, __target_path); })
#endif /* ... */
#if defined(__CRT_HAVE_wsymlinkat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1, 3)),int,__NOTHROW_RPC,c32symlinkat,(char32_t const *__link_text, __fd_t __tofd, char32_t const *__target_path),wsymlinkat,(__link_text,__tofd,__target_path))
#elif defined(__CRT_HAVE_KOS$wsymlinkat)
__CREDIRECT_KOS(__ATTR_NONNULL((1, 3)),int,__NOTHROW_RPC,c32symlinkat,(char32_t const *__link_text, __fd_t __tofd, char32_t const *__target_path),wsymlinkat,(__link_text,__tofd,__target_path))
#elif defined(__CRT_HAVE_wfsymlinkat) || (defined(__CRT_HAVE_fsymlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || ((defined(__CRT_HAVE_symlinkat) || defined(__CRT_HAVE_fsymlinkat)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4)
#include <libc/local/parts.wchar.unistd/wsymlinkat.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 3)) int __NOTHROW_RPC(__LIBKCALL c32symlinkat)(char32_t const *__link_text, __fd_t __tofd, char32_t const *__target_path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wsymlinkat))((__WCHAR_TYPE__ const *)__link_text, __tofd, (__WCHAR_TYPE__ const *)__target_path); }
#elif defined(__CRT_HAVE_KOS$wfsymlinkat) || (defined(__CRT_HAVE_fsymlinkat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || ((defined(__CRT_HAVE_symlinkat) || defined(__CRT_HAVE_fsymlinkat)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c32symlinkat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32symlinkat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 3)) int __NOTHROW_RPC(__LIBKCALL c32symlinkat)(char32_t const *__link_text, __fd_t __tofd, char32_t const *__target_path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32symlinkat))(__link_text, __tofd, __target_path); })
#endif /* ... */
#if defined(__CRT_HAVE_wreadlinkat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((2, 3)),ssize_t,__NOTHROW_RPC,c16readlinkat,(__fd_t __dfd, char16_t const *__path, char16_t *__buf, size_t __buflen),wreadlinkat,(__dfd,__path,__buf,__buflen))
#elif defined(__CRT_HAVE_DOS$wreadlinkat)
__CREDIRECT_DOS(__ATTR_NONNULL((2, 3)),ssize_t,__NOTHROW_RPC,c16readlinkat,(__fd_t __dfd, char16_t const *__path, char16_t *__buf, size_t __buflen),wreadlinkat,(__dfd,__path,__buf,__buflen))
#endif /* ... */
#if defined(__CRT_HAVE_wreadlinkat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((2, 3)),ssize_t,__NOTHROW_RPC,c32readlinkat,(__fd_t __dfd, char32_t const *__path, char32_t *__buf, size_t __buflen),wreadlinkat,(__dfd,__path,__buf,__buflen))
#elif defined(__CRT_HAVE_KOS$wreadlinkat)
__CREDIRECT_KOS(__ATTR_NONNULL((2, 3)),ssize_t,__NOTHROW_RPC,c32readlinkat,(__fd_t __dfd, char32_t const *__path, char32_t *__buf, size_t __buflen),wreadlinkat,(__dfd,__path,__buf,__buflen))
#endif /* ... */
#ifdef __USE_KOS
#if defined(__CRT_HAVE_wfsymlinkat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1, 3)),int,__NOTHROW_RPC,c16fsymlinkat,(char16_t const *__link_text, __fd_t __tofd, char16_t const *__target_path, __atflag_t __flags),wfsymlinkat,(__link_text,__tofd,__target_path,__flags))
#elif defined(__CRT_HAVE_DOS$wfsymlinkat)
__CREDIRECT_DOS(__ATTR_NONNULL((1, 3)),int,__NOTHROW_RPC,c16fsymlinkat,(char16_t const *__link_text, __fd_t __tofd, char16_t const *__target_path, __atflag_t __flags),wfsymlinkat,(__link_text,__tofd,__target_path,__flags))
#elif defined(__CRT_HAVE_fsymlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.unistd/wfsymlinkat.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 3)) int __NOTHROW_RPC(__LIBDCALL c16fsymlinkat)(char16_t const *__link_text, __fd_t __tofd, char16_t const *__target_path, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wfsymlinkat))((__WCHAR_TYPE__ const *)__link_text, __tofd, (__WCHAR_TYPE__ const *)__target_path, __flags); }
#elif defined(__CRT_HAVE_fsymlinkat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c16fsymlinkat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16fsymlinkat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 3)) int __NOTHROW_RPC(__LIBDCALL c16fsymlinkat)(char16_t const *__link_text, __fd_t __tofd, char16_t const *__target_path, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16fsymlinkat))(__link_text, __tofd, __target_path, __flags); })
#endif /* ... */
#if defined(__CRT_HAVE_wfsymlinkat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1, 3)),int,__NOTHROW_RPC,c32fsymlinkat,(char32_t const *__link_text, __fd_t __tofd, char32_t const *__target_path, __atflag_t __flags),wfsymlinkat,(__link_text,__tofd,__target_path,__flags))
#elif defined(__CRT_HAVE_KOS$wfsymlinkat)
__CREDIRECT_KOS(__ATTR_NONNULL((1, 3)),int,__NOTHROW_RPC,c32fsymlinkat,(char32_t const *__link_text, __fd_t __tofd, char32_t const *__target_path, __atflag_t __flags),wfsymlinkat,(__link_text,__tofd,__target_path,__flags))
#elif defined(__CRT_HAVE_fsymlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.unistd/wfsymlinkat.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 3)) int __NOTHROW_RPC(__LIBKCALL c32fsymlinkat)(char32_t const *__link_text, __fd_t __tofd, char32_t const *__target_path, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wfsymlinkat))((__WCHAR_TYPE__ const *)__link_text, __tofd, (__WCHAR_TYPE__ const *)__target_path, __flags); }
#elif defined(__CRT_HAVE_fsymlinkat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c32fsymlinkat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32fsymlinkat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 3)) int __NOTHROW_RPC(__LIBKCALL c32fsymlinkat)(char32_t const *__link_text, __fd_t __tofd, char32_t const *__target_path, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32fsymlinkat))(__link_text, __tofd, __target_path, __flags); })
#endif /* ... */
#if defined(__CRT_HAVE_wfreadlinkat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((2, 3)),ssize_t,__NOTHROW_RPC,c16freadlinkat,(__fd_t __dfd, char16_t const *__path, char16_t *__buf, size_t __buflen, __atflag_t __flags),wfreadlinkat,(__dfd,__path,__buf,__buflen,__flags))
#elif defined(__CRT_HAVE_DOS$wfreadlinkat)
__CREDIRECT_DOS(__ATTR_NONNULL((2, 3)),ssize_t,__NOTHROW_RPC,c16freadlinkat,(__fd_t __dfd, char16_t const *__path, char16_t *__buf, size_t __buflen, __atflag_t __flags),wfreadlinkat,(__dfd,__path,__buf,__buflen,__flags))
#endif /* ... */
#if defined(__CRT_HAVE_wfreadlinkat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((2, 3)),ssize_t,__NOTHROW_RPC,c32freadlinkat,(__fd_t __dfd, char32_t const *__path, char32_t *__buf, size_t __buflen, __atflag_t __flags),wfreadlinkat,(__dfd,__path,__buf,__buflen,__flags))
#elif defined(__CRT_HAVE_KOS$wfreadlinkat)
__CREDIRECT_KOS(__ATTR_NONNULL((2, 3)),ssize_t,__NOTHROW_RPC,c32freadlinkat,(__fd_t __dfd, char32_t const *__path, char32_t *__buf, size_t __buflen, __atflag_t __flags),wfreadlinkat,(__dfd,__path,__buf,__buflen,__flags))
#endif /* ... */
#endif /* __USE_KOS */
#if defined(__CRT_HAVE_wunlinkat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,c16unlinkat,(__fd_t __dfd, char16_t const *__file, __atflag_t __flags),wunlinkat,(__dfd,__file,__flags))
#elif defined(__CRT_HAVE_DOS$wunlinkat)
__CREDIRECT_DOS(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,c16unlinkat,(__fd_t __dfd, char16_t const *__file, __atflag_t __flags),wunlinkat,(__dfd,__file,__flags))
#elif defined(__CRT_HAVE_unlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.unistd/wunlinkat.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((2)) int __NOTHROW_RPC(__LIBDCALL c16unlinkat)(__fd_t __dfd, char16_t const *__file, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wunlinkat))(__dfd, (__WCHAR_TYPE__ const *)__file, __flags); }
#elif defined(__CRT_HAVE_unlinkat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c16unlinkat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16unlinkat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((2)) int __NOTHROW_RPC(__LIBDCALL c16unlinkat)(__fd_t __dfd, char16_t const *__file, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16unlinkat))(__dfd, __file, __flags); })
#endif /* ... */
#if defined(__CRT_HAVE_wunlinkat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,c32unlinkat,(__fd_t __dfd, char32_t const *__file, __atflag_t __flags),wunlinkat,(__dfd,__file,__flags))
#elif defined(__CRT_HAVE_KOS$wunlinkat)
__CREDIRECT_KOS(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,c32unlinkat,(__fd_t __dfd, char32_t const *__file, __atflag_t __flags),wunlinkat,(__dfd,__file,__flags))
#elif defined(__CRT_HAVE_unlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.unistd/wunlinkat.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((2)) int __NOTHROW_RPC(__LIBKCALL c32unlinkat)(__fd_t __dfd, char32_t const *__file, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wunlinkat))(__dfd, (__WCHAR_TYPE__ const *)__file, __flags); }
#elif defined(__CRT_HAVE_unlinkat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c32unlinkat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32unlinkat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((2)) int __NOTHROW_RPC(__LIBKCALL c32unlinkat)(__fd_t __dfd, char32_t const *__file, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32unlinkat))(__dfd, __file, __flags); })
#endif /* ... */
#endif /* __USE_ATFILE */
#if defined(__CRT_HAVE_wlchown) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16lchown,(char16_t const *__file, __uid_t __owner, __gid_t __group),wlchown,(__file,__owner,__group))
#elif defined(__CRT_HAVE_DOS$wlchown)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16lchown,(char16_t const *__file, __uid_t __owner, __gid_t __group),wlchown,(__file,__owner,__group))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && defined(__AT_SYMLINK_NOFOLLOW) && (defined(__CRT_HAVE_wfchownat) || (defined(__CRT_HAVE_fchownat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_lchown) || (defined(__AT_FDCWD) && defined(__AT_SYMLINK_NOFOLLOW) && defined(__CRT_HAVE_fchownat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2)
#include <libc/local/parts.wchar.unistd/wlchown.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16lchown)(char16_t const *__file, __uid_t __owner, __gid_t __group) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wlchown))((__WCHAR_TYPE__ const *)__file, __owner, __group); }
#elif (defined(__AT_FDCWD) && defined(__AT_SYMLINK_NOFOLLOW) && ((defined(__CRT_HAVE_wfchownat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$wfchownat) || (defined(__CRT_HAVE_fchownat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fchownat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_lchown) || (defined(__AT_FDCWD) && defined(__AT_SYMLINK_NOFOLLOW) && defined(__CRT_HAVE_fchownat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c16lchown.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16lchown, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16lchown)(char16_t const *__file, __uid_t __owner, __gid_t __group) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16lchown))(__file, __owner, __group); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wlchown) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32lchown,(char32_t const *__file, __uid_t __owner, __gid_t __group),wlchown,(__file,__owner,__group))
#elif defined(__CRT_HAVE_KOS$wlchown)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32lchown,(char32_t const *__file, __uid_t __owner, __gid_t __group),wlchown,(__file,__owner,__group))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && defined(__AT_SYMLINK_NOFOLLOW) && (defined(__CRT_HAVE_wfchownat) || (defined(__CRT_HAVE_fchownat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_lchown) || (defined(__AT_FDCWD) && defined(__AT_SYMLINK_NOFOLLOW) && defined(__CRT_HAVE_fchownat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4)
#include <libc/local/parts.wchar.unistd/wlchown.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32lchown)(char32_t const *__file, __uid_t __owner, __gid_t __group) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wlchown))((__WCHAR_TYPE__ const *)__file, __owner, __group); }
#elif (defined(__AT_FDCWD) && defined(__AT_SYMLINK_NOFOLLOW) && ((defined(__CRT_HAVE_wfchownat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$wfchownat) || (defined(__CRT_HAVE_fchownat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fchownat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_lchown) || (defined(__AT_FDCWD) && defined(__AT_SYMLINK_NOFOLLOW) && defined(__CRT_HAVE_fchownat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c32lchown.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32lchown, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32lchown)(char32_t const *__file, __uid_t __owner, __gid_t __group) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32lchown))(__file, __owner, __group); })
#endif /* ... */
#endif /* !... */
#if defined(__USE_XOPEN_EXTENDED) || defined(__USE_XOPEN2K8)
#ifndef __PIO_OFFSET
#ifdef __USE_KOS_ALTERATIONS
#define __PIO_OFFSET   __FS_TYPE(pos)
#define __PIO_OFFSET64 __pos64_t
#else /* __USE_KOS_ALTERATIONS */
#define __PIO_OFFSET   __FS_TYPE(off)
#define __PIO_OFFSET64 __off64_t
#endif /* !__USE_KOS_ALTERATIONS */
#endif /* !__PIO_OFFSET */
#include <bits/types.h>
#if defined(__CRT_HAVE_wtruncate) && (!defined(__USE_FILE_OFFSET64) || __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16truncate,(char16_t const *__file, __PIO_OFFSET __length),wtruncate,(__file,__length))
#elif defined(__CRT_HAVE_DOS$wtruncate) && (!defined(__USE_FILE_OFFSET64) || __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16truncate,(char16_t const *__file, __PIO_OFFSET __length),wtruncate,(__file,__length))
#elif defined(__CRT_HAVE_wtruncate64) && (defined(__USE_FILE_OFFSET64) || __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16truncate,(char16_t const *__file, __PIO_OFFSET __length),wtruncate64,(__file,__length))
#elif defined(__CRT_HAVE_DOS$wtruncate64) && (defined(__USE_FILE_OFFSET64) || __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16truncate,(char16_t const *__file, __PIO_OFFSET __length),wtruncate64,(__file,__length))
#else /* ... */
#include <asm/os/oflags.h>
#include <asm/os/fcntl.h>
#if defined(__CRT_HAVE_wtruncate64) || defined(__CRT_HAVE_wtruncate) || ((defined(__CRT_HAVE_truncate64) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open)) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize))) || defined(__CRT_HAVE_truncate) || defined(__CRT_HAVE___truncate) || defined(__CRT_HAVE___libc_truncate) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_openat64) || defined(__CRT_HAVE_openat)))) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize)))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2)
#include <libc/local/parts.wchar.unistd/wtruncate.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBDCALL c16truncate)(char16_t const *__file, __PIO_OFFSET __length) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wtruncate))((__WCHAR_TYPE__ const *)__file, __length); }
#elif defined(__CRT_HAVE_DOS$wtruncate64) || defined(__CRT_HAVE_DOS$wtruncate) || ((defined(__CRT_HAVE_truncate64) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open)) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize))) || defined(__CRT_HAVE_truncate) || defined(__CRT_HAVE___truncate) || defined(__CRT_HAVE___libc_truncate) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_openat64) || defined(__CRT_HAVE_openat)))) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize)))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c16truncate.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16truncate, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBDCALL c16truncate)(char16_t const *__file, __PIO_OFFSET __length) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16truncate))(__file, __length); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wtruncate) && (!defined(__USE_FILE_OFFSET64) || __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32truncate,(char32_t const *__file, __PIO_OFFSET __length),wtruncate,(__file,__length))
#elif defined(__CRT_HAVE_KOS$wtruncate) && (!defined(__USE_FILE_OFFSET64) || __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32truncate,(char32_t const *__file, __PIO_OFFSET __length),wtruncate,(__file,__length))
#elif defined(__CRT_HAVE_wtruncate64) && (defined(__USE_FILE_OFFSET64) || __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32truncate,(char32_t const *__file, __PIO_OFFSET __length),wtruncate64,(__file,__length))
#elif defined(__CRT_HAVE_KOS$wtruncate64) && (defined(__USE_FILE_OFFSET64) || __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32truncate,(char32_t const *__file, __PIO_OFFSET __length),wtruncate64,(__file,__length))
#else /* ... */
#include <asm/os/oflags.h>
#include <asm/os/fcntl.h>
#if defined(__CRT_HAVE_wtruncate64) || defined(__CRT_HAVE_wtruncate) || ((defined(__CRT_HAVE_truncate64) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open)) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize))) || defined(__CRT_HAVE_truncate) || defined(__CRT_HAVE___truncate) || defined(__CRT_HAVE___libc_truncate) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_openat64) || defined(__CRT_HAVE_openat)))) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize)))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4)
#include <libc/local/parts.wchar.unistd/wtruncate.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBKCALL c32truncate)(char32_t const *__file, __PIO_OFFSET __length) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wtruncate))((__WCHAR_TYPE__ const *)__file, __length); }
#elif defined(__CRT_HAVE_KOS$wtruncate64) || defined(__CRT_HAVE_KOS$wtruncate) || ((defined(__CRT_HAVE_truncate64) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open)) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize))) || defined(__CRT_HAVE_truncate) || defined(__CRT_HAVE___truncate) || defined(__CRT_HAVE___libc_truncate) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_openat64) || defined(__CRT_HAVE_openat)))) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize)))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c32truncate.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32truncate, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBKCALL c32truncate)(char32_t const *__file, __PIO_OFFSET __length) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32truncate))(__file, __length); })
#endif /* ... */
#endif /* !... */
#ifdef __USE_LARGEFILE64
#if defined(__CRT_HAVE_wtruncate) && __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__ && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16truncate64,(char16_t const *__file, __PIO_OFFSET64 __length),wtruncate,(__file,__length))
#elif defined(__CRT_HAVE_DOS$wtruncate) && __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16truncate64,(char16_t const *__file, __PIO_OFFSET64 __length),wtruncate,(__file,__length))
#elif defined(__CRT_HAVE_wtruncate64) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16truncate64,(char16_t const *__file, __PIO_OFFSET64 __length),wtruncate64,(__file,__length))
#elif defined(__CRT_HAVE_DOS$wtruncate64)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16truncate64,(char16_t const *__file, __PIO_OFFSET64 __length),wtruncate64,(__file,__length))
#else /* ... */
#include <asm/os/oflags.h>
#if ((defined(__CRT_HAVE_truncate64) || defined(__CRT_HAVE_truncate) || defined(__CRT_HAVE___truncate) || defined(__CRT_HAVE___libc_truncate) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open)) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize)))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || (defined(__CRT_HAVE_wtruncate) && __SIZEOF_WCHAR_T__ == 2)
#include <libc/local/parts.wchar.unistd/wtruncate64.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBDCALL c16truncate64)(char16_t const *__file, __PIO_OFFSET64 __length) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wtruncate64))((__WCHAR_TYPE__ const *)__file, __length); }
#elif ((defined(__CRT_HAVE_truncate64) || defined(__CRT_HAVE_truncate) || defined(__CRT_HAVE___truncate) || defined(__CRT_HAVE___libc_truncate) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open)) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize)))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || defined(__CRT_HAVE_DOS$wtruncate)
#include <libc/local/parts.uchar.unistd/c16truncate64.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16truncate64, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBDCALL c16truncate64)(char16_t const *__file, __PIO_OFFSET64 __length) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16truncate64))(__file, __length); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wtruncate) && __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__ && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32truncate64,(char32_t const *__file, __PIO_OFFSET64 __length),wtruncate,(__file,__length))
#elif defined(__CRT_HAVE_KOS$wtruncate) && __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32truncate64,(char32_t const *__file, __PIO_OFFSET64 __length),wtruncate,(__file,__length))
#elif defined(__CRT_HAVE_wtruncate64) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32truncate64,(char32_t const *__file, __PIO_OFFSET64 __length),wtruncate64,(__file,__length))
#elif defined(__CRT_HAVE_KOS$wtruncate64)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32truncate64,(char32_t const *__file, __PIO_OFFSET64 __length),wtruncate64,(__file,__length))
#else /* ... */
#include <asm/os/oflags.h>
#if ((defined(__CRT_HAVE_truncate64) || defined(__CRT_HAVE_truncate) || defined(__CRT_HAVE___truncate) || defined(__CRT_HAVE___libc_truncate) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open)) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize)))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || (defined(__CRT_HAVE_wtruncate) && __SIZEOF_WCHAR_T__ == 4)
#include <libc/local/parts.wchar.unistd/wtruncate64.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBKCALL c32truncate64)(char32_t const *__file, __PIO_OFFSET64 __length) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wtruncate64))((__WCHAR_TYPE__ const *)__file, __length); }
#elif ((defined(__CRT_HAVE_truncate64) || defined(__CRT_HAVE_truncate) || defined(__CRT_HAVE___truncate) || defined(__CRT_HAVE___libc_truncate) || ((defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open)) && (defined(__CRT_HAVE_ftruncate64) || defined(__CRT_HAVE__chsize_s) || defined(__CRT_HAVE_ftruncate) || defined(__CRT_HAVE___ftruncate) || defined(__CRT_HAVE___libc_ftruncate) || defined(__CRT_HAVE__chsize) || defined(__CRT_HAVE_chsize)))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || defined(__CRT_HAVE_KOS$wtruncate)
#include <libc/local/parts.uchar.unistd/c32truncate64.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32truncate64, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBKCALL c32truncate64)(char32_t const *__file, __PIO_OFFSET64 __length) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32truncate64))(__file, __length); })
#endif /* ... */
#endif /* !... */
#endif /* __USE_LARGEFILE64 */
#endif /* __USE_XOPEN_EXTENDED || __USE_XOPEN2K8 */
#if defined(__USE_XOPEN_EXTENDED) || defined(__USE_XOPEN2K)
#if defined(__CRT_HAVE_wsymlink) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1, 2)),int,__NOTHROW_RPC,c16symlink,(char16_t const *__link_text, char16_t const *__target_path),wsymlink,(__link_text,__target_path))
#elif defined(__CRT_HAVE_DOS$wsymlink)
__CREDIRECT_DOS(__ATTR_NONNULL((1, 2)),int,__NOTHROW_RPC,c16symlink,(char16_t const *__link_text, char16_t const *__target_path),wsymlink,(__link_text,__target_path))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wsymlinkat) || defined(__CRT_HAVE_wfsymlinkat) || (defined(__CRT_HAVE_fsymlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || ((defined(__CRT_HAVE_symlinkat) || defined(__CRT_HAVE_fsymlinkat)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_symlink) || defined(__CRT_HAVE___symlink) || defined(__CRT_HAVE___libc_symlink) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_symlinkat) || defined(__CRT_HAVE_fsymlinkat)))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2)
#include <libc/local/parts.wchar.unistd/wsymlink.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 2)) int __NOTHROW_RPC(__LIBDCALL c16symlink)(char16_t const *__link_text, char16_t const *__target_path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wsymlink))((__WCHAR_TYPE__ const *)__link_text, (__WCHAR_TYPE__ const *)__target_path); }
#elif (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wsymlinkat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$wsymlinkat) || defined(__CRT_HAVE_wfsymlinkat) || (defined(__CRT_HAVE_fsymlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || ((defined(__CRT_HAVE_symlinkat) || defined(__CRT_HAVE_fsymlinkat)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$wfsymlinkat) || (defined(__CRT_HAVE_fsymlinkat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || ((defined(__CRT_HAVE_symlinkat) || defined(__CRT_HAVE_fsymlinkat)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_symlink) || defined(__CRT_HAVE___symlink) || defined(__CRT_HAVE___libc_symlink) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_symlinkat) || defined(__CRT_HAVE_fsymlinkat)))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c16symlink.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16symlink, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 2)) int __NOTHROW_RPC(__LIBDCALL c16symlink)(char16_t const *__link_text, char16_t const *__target_path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16symlink))(__link_text, __target_path); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wsymlink) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1, 2)),int,__NOTHROW_RPC,c32symlink,(char32_t const *__link_text, char32_t const *__target_path),wsymlink,(__link_text,__target_path))
#elif defined(__CRT_HAVE_KOS$wsymlink)
__CREDIRECT_KOS(__ATTR_NONNULL((1, 2)),int,__NOTHROW_RPC,c32symlink,(char32_t const *__link_text, char32_t const *__target_path),wsymlink,(__link_text,__target_path))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wsymlinkat) || defined(__CRT_HAVE_wfsymlinkat) || (defined(__CRT_HAVE_fsymlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || ((defined(__CRT_HAVE_symlinkat) || defined(__CRT_HAVE_fsymlinkat)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_symlink) || defined(__CRT_HAVE___symlink) || defined(__CRT_HAVE___libc_symlink) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_symlinkat) || defined(__CRT_HAVE_fsymlinkat)))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4)
#include <libc/local/parts.wchar.unistd/wsymlink.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 2)) int __NOTHROW_RPC(__LIBKCALL c32symlink)(char32_t const *__link_text, char32_t const *__target_path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wsymlink))((__WCHAR_TYPE__ const *)__link_text, (__WCHAR_TYPE__ const *)__target_path); }
#elif (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wsymlinkat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$wsymlinkat) || defined(__CRT_HAVE_wfsymlinkat) || (defined(__CRT_HAVE_fsymlinkat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || ((defined(__CRT_HAVE_symlinkat) || defined(__CRT_HAVE_fsymlinkat)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$wfsymlinkat) || (defined(__CRT_HAVE_fsymlinkat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || ((defined(__CRT_HAVE_symlinkat) || defined(__CRT_HAVE_fsymlinkat)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_symlink) || defined(__CRT_HAVE___symlink) || defined(__CRT_HAVE___libc_symlink) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_symlinkat) || defined(__CRT_HAVE_fsymlinkat)))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.unistd/c32symlink.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32symlink, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 2)) int __NOTHROW_RPC(__LIBKCALL c32symlink)(char32_t const *__link_text, char32_t const *__target_path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32symlink))(__link_text, __target_path); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wreadlink) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1, 2)),ssize_t,__NOTHROW_RPC,c16readlink,(char16_t const *__path, char16_t *__buf, size_t __buflen),wreadlink,(__path,__buf,__buflen))
#elif defined(__CRT_HAVE_DOS$wreadlink)
__CREDIRECT_DOS(__ATTR_NONNULL((1, 2)),ssize_t,__NOTHROW_RPC,c16readlink,(char16_t const *__path, char16_t *__buf, size_t __buflen),wreadlink,(__path,__buf,__buflen))
#endif /* ... */
#if defined(__CRT_HAVE_wreadlink) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1, 2)),ssize_t,__NOTHROW_RPC,c32readlink,(char32_t const *__path, char32_t *__buf, size_t __buflen),wreadlink,(__path,__buf,__buflen))
#elif defined(__CRT_HAVE_KOS$wreadlink)
__CREDIRECT_KOS(__ATTR_NONNULL((1, 2)),ssize_t,__NOTHROW_RPC,c32readlink,(char32_t const *__path, char32_t *__buf, size_t __buflen),wreadlink,(__path,__buf,__buflen))
#endif /* ... */
#endif /* __USE_XOPEN_EXTENDED || __USE_XOPEN2K */

#if defined(__USE_UNIX98) || defined(__USE_XOPEN2K)
#if defined(__CRT_HAVE_wgethostname) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16gethostname,(char16_t *__name, size_t __buflen),wgethostname,(__name,__buflen))
#elif defined(__CRT_HAVE_DOS$wgethostname)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16gethostname,(char16_t *__name, size_t __buflen),wgethostname,(__name,__buflen))
#elif (defined(__CRT_HAVE_uname) || defined(__CRT_HAVE___uname) || defined(__CRT_HAVE___libc_uname)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.unistd/wgethostname.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBDCALL c16gethostname)(char16_t *__name, size_t __buflen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wgethostname))((__WCHAR_TYPE__ *)__name, __buflen); }
#elif defined(__CRT_HAVE_uname) || defined(__CRT_HAVE___uname) || defined(__CRT_HAVE___libc_uname)
#include <libc/local/parts.uchar.unistd/c16gethostname.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16gethostname, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBDCALL c16gethostname)(char16_t *__name, size_t __buflen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16gethostname))(__name, __buflen); })
#endif /* ... */
#if defined(__CRT_HAVE_wgethostname) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32gethostname,(char32_t *__name, size_t __buflen),wgethostname,(__name,__buflen))
#elif defined(__CRT_HAVE_KOS$wgethostname)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32gethostname,(char32_t *__name, size_t __buflen),wgethostname,(__name,__buflen))
#elif (defined(__CRT_HAVE_uname) || defined(__CRT_HAVE___uname) || defined(__CRT_HAVE___libc_uname)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.unistd/wgethostname.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBKCALL c32gethostname)(char32_t *__name, size_t __buflen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wgethostname))((__WCHAR_TYPE__ *)__name, __buflen); }
#elif defined(__CRT_HAVE_uname) || defined(__CRT_HAVE___uname) || defined(__CRT_HAVE___libc_uname)
#include <libc/local/parts.uchar.unistd/c32gethostname.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32gethostname, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBKCALL c32gethostname)(char32_t *__name, size_t __buflen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32gethostname))(__name, __buflen); })
#endif /* ... */
#endif /* __USE_UNIX98 || __USE_XOPEN2K */
#ifdef __USE_MISC
#if defined(__CRT_HAVE_wsetlogin) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16setlogin,(char16_t const *__name),wsetlogin,(__name))
#elif defined(__CRT_HAVE_DOS$wsetlogin)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16setlogin,(char16_t const *__name),wsetlogin,(__name))
#elif defined(__CRT_HAVE_setlogin) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.unistd/wsetlogin.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBDCALL c16setlogin)(char16_t const *__name) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wsetlogin))((__WCHAR_TYPE__ const *)__name); }
#elif defined(__CRT_HAVE_setlogin) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c16setlogin.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16setlogin, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBDCALL c16setlogin)(char16_t const *__name) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16setlogin))(__name); })
#endif /* ... */
#if defined(__CRT_HAVE_wsetlogin) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32setlogin,(char32_t const *__name),wsetlogin,(__name))
#elif defined(__CRT_HAVE_KOS$wsetlogin)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32setlogin,(char32_t const *__name),wsetlogin,(__name))
#elif defined(__CRT_HAVE_setlogin) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.unistd/wsetlogin.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBKCALL c32setlogin)(char32_t const *__name) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wsetlogin))((__WCHAR_TYPE__ const *)__name); }
#elif defined(__CRT_HAVE_setlogin) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c32setlogin.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32setlogin, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBKCALL c32setlogin)(char32_t const *__name) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32setlogin))(__name); })
#endif /* ... */
#if defined(__CRT_HAVE_wsethostname) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16sethostname,(char16_t const *__name, size_t __len),wsethostname,(__name,__len))
#elif defined(__CRT_HAVE_DOS$wsethostname)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16sethostname,(char16_t const *__name, size_t __len),wsethostname,(__name,__len))
#elif (defined(__CRT_HAVE_sethostname) || defined(__CRT_HAVE___sethostname) || defined(__CRT_HAVE___libc_sethostname)) && (defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.unistd/wsethostname.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBDCALL c16sethostname)(char16_t const *__name, size_t __len) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wsethostname))((__WCHAR_TYPE__ const *)__name, __len); }
#elif (defined(__CRT_HAVE_sethostname) || defined(__CRT_HAVE___sethostname) || defined(__CRT_HAVE___libc_sethostname)) && ((defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c16sethostname.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16sethostname, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBDCALL c16sethostname)(char16_t const *__name, size_t __len) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16sethostname))(__name, __len); })
#endif /* ... */
#if defined(__CRT_HAVE_wsethostname) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32sethostname,(char32_t const *__name, size_t __len),wsethostname,(__name,__len))
#elif defined(__CRT_HAVE_KOS$wsethostname)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32sethostname,(char32_t const *__name, size_t __len),wsethostname,(__name,__len))
#elif (defined(__CRT_HAVE_sethostname) || defined(__CRT_HAVE___sethostname) || defined(__CRT_HAVE___libc_sethostname)) && (defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.unistd/wsethostname.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBKCALL c32sethostname)(char32_t const *__name, size_t __len) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wsethostname))((__WCHAR_TYPE__ const *)__name, __len); }
#elif (defined(__CRT_HAVE_sethostname) || defined(__CRT_HAVE___sethostname) || defined(__CRT_HAVE___libc_sethostname)) && ((defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c32sethostname.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32sethostname, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBKCALL c32sethostname)(char32_t const *__name, size_t __len) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32sethostname))(__name, __len); })
#endif /* ... */
#if defined(__CRT_HAVE_wgetdomainname) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16getdomainname,(char16_t *__name, size_t __buflen),wgetdomainname,(__name,__buflen))
#elif defined(__CRT_HAVE_DOS$wgetdomainname)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16getdomainname,(char16_t *__name, size_t __buflen),wgetdomainname,(__name,__buflen))
#elif (defined(__CRT_HAVE_uname) || defined(__CRT_HAVE___uname) || defined(__CRT_HAVE___libc_uname)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.unistd/wgetdomainname.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBDCALL c16getdomainname)(char16_t *__name, size_t __buflen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wgetdomainname))((__WCHAR_TYPE__ *)__name, __buflen); }
#elif defined(__CRT_HAVE_uname) || defined(__CRT_HAVE___uname) || defined(__CRT_HAVE___libc_uname)
#include <libc/local/parts.uchar.unistd/c16getdomainname.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16getdomainname, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBDCALL c16getdomainname)(char16_t *__name, size_t __buflen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16getdomainname))(__name, __buflen); })
#endif /* ... */
#if defined(__CRT_HAVE_wgetdomainname) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32getdomainname,(char32_t *__name, size_t __buflen),wgetdomainname,(__name,__buflen))
#elif defined(__CRT_HAVE_KOS$wgetdomainname)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32getdomainname,(char32_t *__name, size_t __buflen),wgetdomainname,(__name,__buflen))
#elif (defined(__CRT_HAVE_uname) || defined(__CRT_HAVE___uname) || defined(__CRT_HAVE___libc_uname)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.unistd/wgetdomainname.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBKCALL c32getdomainname)(char32_t *__name, size_t __buflen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wgetdomainname))((__WCHAR_TYPE__ *)__name, __buflen); }
#elif defined(__CRT_HAVE_uname) || defined(__CRT_HAVE___uname) || defined(__CRT_HAVE___libc_uname)
#include <libc/local/parts.uchar.unistd/c32getdomainname.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32getdomainname, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBKCALL c32getdomainname)(char32_t *__name, size_t __buflen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32getdomainname))(__name, __buflen); })
#endif /* ... */
#if defined(__CRT_HAVE_wsetdomainname) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16setdomainname,(char16_t const *__name, size_t __len),wsetdomainname,(__name,__len))
#elif defined(__CRT_HAVE_DOS$wsetdomainname)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c16setdomainname,(char16_t const *__name, size_t __len),wsetdomainname,(__name,__len))
#elif (defined(__CRT_HAVE_setdomainname) || defined(__CRT_HAVE___setdomainname) || defined(__CRT_HAVE___libc_setdomainname)) && (defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.unistd/wsetdomainname.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBDCALL c16setdomainname)(char16_t const *__name, size_t __len) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wsetdomainname))((__WCHAR_TYPE__ const *)__name, __len); }
#elif (defined(__CRT_HAVE_setdomainname) || defined(__CRT_HAVE___setdomainname) || defined(__CRT_HAVE___libc_setdomainname)) && ((defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c16setdomainname.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16setdomainname, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBDCALL c16setdomainname)(char16_t const *__name, size_t __len) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16setdomainname))(__name, __len); })
#endif /* ... */
#if defined(__CRT_HAVE_wsetdomainname) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32setdomainname,(char32_t const *__name, size_t __len),wsetdomainname,(__name,__len))
#elif defined(__CRT_HAVE_KOS$wsetdomainname)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,c32setdomainname,(char32_t const *__name, size_t __len),wsetdomainname,(__name,__len))
#elif (defined(__CRT_HAVE_setdomainname) || defined(__CRT_HAVE___setdomainname) || defined(__CRT_HAVE___libc_setdomainname)) && (defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.unistd/wsetdomainname.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBKCALL c32setdomainname)(char32_t const *__name, size_t __len) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wsetdomainname))((__WCHAR_TYPE__ const *)__name, __len); }
#elif (defined(__CRT_HAVE_setdomainname) || defined(__CRT_HAVE___setdomainname) || defined(__CRT_HAVE___libc_setdomainname)) && ((defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c32setdomainname.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32setdomainname, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBKCALL c32setdomainname)(char32_t const *__name, size_t __len) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32setdomainname))(__name, __len); })
#endif /* ... */
#endif /* __USE_MISC */
#if defined(__USE_MISC) || \
   (defined(__USE_XOPEN) && !defined(__USE_XOPEN2K))
#if defined(__CRT_HAVE_wchroot) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16chroot,(char16_t const *__path),wchroot,(__path))
#elif defined(__CRT_HAVE_DOS$wchroot)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c16chroot,(char16_t const *__path),wchroot,(__path))
#elif (defined(__CRT_HAVE_chroot) || defined(__CRT_HAVE___chroot) || defined(__CRT_HAVE___libc_chroot)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.unistd/wchroot.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16chroot)(char16_t const *__path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wchroot))((__WCHAR_TYPE__ const *)__path); }
#elif (defined(__CRT_HAVE_chroot) || defined(__CRT_HAVE___chroot) || defined(__CRT_HAVE___libc_chroot)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c16chroot.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16chroot, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBDCALL c16chroot)(char16_t const *__path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16chroot))(__path); })
#endif /* ... */
#if defined(__CRT_HAVE_wchroot) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32chroot,(char32_t const *__path),wchroot,(__path))
#elif defined(__CRT_HAVE_KOS$wchroot)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,c32chroot,(char32_t const *__path),wchroot,(__path))
#elif (defined(__CRT_HAVE_chroot) || defined(__CRT_HAVE___chroot) || defined(__CRT_HAVE___libc_chroot)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.unistd/wchroot.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32chroot)(char32_t const *__path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wchroot))((__WCHAR_TYPE__ const *)__path); }
#elif (defined(__CRT_HAVE_chroot) || defined(__CRT_HAVE___chroot) || defined(__CRT_HAVE___libc_chroot)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.unistd/c32chroot.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32chroot, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBKCALL c32chroot)(char32_t const *__path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32chroot))(__path); })
#endif /* ... */
#endif /* ... */

__SYSDECL_END
#endif /* __CC__ */

#endif /* !_PARTS_UCHAR_UNISTD_H */
