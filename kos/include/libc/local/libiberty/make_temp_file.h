/* HASH CRC-32:0xd89dd628 */
/* Copyright (c) 2019-2023 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2023 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_make_temp_file_defined
#define __local_make_temp_file_defined
#include <__crt.h>
#include <libc/template/stdstreams.h>
#include <asm/os/fcntl.h>
#include <features.h>
#include <asm/os/oflags.h>
#if defined(__CRT_HAVE_make_temp_file_with_prefix) || ((defined(__CRT_HAVE_choose_tmpdir) || ((defined(__CRT_HAVE_access) || defined(__CRT_HAVE__access) || defined(__CRT_HAVE___access) || defined(__CRT_HAVE___libc_access) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_faccessat))) && !defined(_WIN32) && defined(__X_OK) && defined(__W_OK) && defined(__R_OK))) && (defined(__CRT_HAVE_xmalloc) || defined(__CRT_HAVE_xrealloc) || defined(__CRT_HAVE_xcalloc) || ((defined(__CRT_HAVE_malloc) || defined(__CRT_HAVE___libc_malloc) || defined(__CRT_HAVE_calloc) || defined(__CRT_HAVE___libc_calloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc) || defined(__CRT_HAVE_memalign) || defined(__CRT_HAVE_aligned_alloc) || defined(__CRT_HAVE___libc_memalign) || defined(__CRT_HAVE_posix_memalign)) && defined(__CRT_HAVE_xmalloc_failed))) && (defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_openat64) || defined(__CRT_HAVE_openat)))) && (defined(__CRT_HAVE_fprintf) || defined(__CRT_HAVE__IO_fprintf) || defined(__CRT_HAVE_fprintf_s) || defined(__CRT_HAVE_fprintf_unlocked) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)) && (defined(__CRT_HAVE_abort) || defined(__CRT_HAVE__ZSt9terminatev) || defined(__CRT_HAVE_terminate) || defined(__CRT_HAVE___chk_fail) || defined(__CRT_HAVE_$Qterminate$A$AYAXXZ) || defined(__CRT_HAVE__Exit) || defined(__CRT_HAVE__exit) || defined(__CRT_HAVE_quick_exit) || defined(__CRT_HAVE_exit)) && defined(__LOCAL_stderr))
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_make_temp_file_with_prefix_defined
#define __local___localdep_make_temp_file_with_prefix_defined
#ifdef __CRT_HAVE_make_temp_file_with_prefix
__CREDIRECT(__ATTR_MALLOC __ATTR_MALL_DEFAULT_ALIGNED __ATTR_RETNONNULL __ATTR_WUNUSED __ATTR_IN_OPT(1) __ATTR_IN_OPT(2),char *,__NOTHROW_NCX,__localdep_make_temp_file_with_prefix,(char const *__prefix, char const *__suffix),make_temp_file_with_prefix,(__prefix,__suffix))
#elif (defined(__CRT_HAVE_choose_tmpdir) || ((defined(__CRT_HAVE_access) || defined(__CRT_HAVE__access) || defined(__CRT_HAVE___access) || defined(__CRT_HAVE___libc_access) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_faccessat))) && !defined(_WIN32) && defined(__X_OK) && defined(__W_OK) && defined(__R_OK))) && (defined(__CRT_HAVE_xmalloc) || defined(__CRT_HAVE_xrealloc) || defined(__CRT_HAVE_xcalloc) || ((defined(__CRT_HAVE_malloc) || defined(__CRT_HAVE___libc_malloc) || defined(__CRT_HAVE_calloc) || defined(__CRT_HAVE___libc_calloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc) || defined(__CRT_HAVE_memalign) || defined(__CRT_HAVE_aligned_alloc) || defined(__CRT_HAVE___libc_memalign) || defined(__CRT_HAVE_posix_memalign)) && defined(__CRT_HAVE_xmalloc_failed))) && (defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_openat64) || defined(__CRT_HAVE_openat)))) && (defined(__CRT_HAVE_fprintf) || defined(__CRT_HAVE__IO_fprintf) || defined(__CRT_HAVE_fprintf_s) || defined(__CRT_HAVE_fprintf_unlocked) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)) && (defined(__CRT_HAVE_abort) || defined(__CRT_HAVE__ZSt9terminatev) || defined(__CRT_HAVE_terminate) || defined(__CRT_HAVE___chk_fail) || defined(__CRT_HAVE_$Qterminate$A$AYAXXZ) || defined(__CRT_HAVE__Exit) || defined(__CRT_HAVE__exit) || defined(__CRT_HAVE_quick_exit) || defined(__CRT_HAVE_exit)) && defined(__LOCAL_stderr)
__NAMESPACE_LOCAL_END
#include <libc/local/libiberty/make_temp_file_with_prefix.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_make_temp_file_with_prefix __LIBC_LOCAL_NAME(make_temp_file_with_prefix)
#else /* ... */
#undef __local___localdep_make_temp_file_with_prefix_defined
#endif /* !... */
#endif /* !__local___localdep_make_temp_file_with_prefix_defined */
__LOCAL_LIBC(make_temp_file) __ATTR_MALLOC __ATTR_MALL_DEFAULT_ALIGNED __ATTR_RETNONNULL __ATTR_WUNUSED __ATTR_IN_OPT(1) char *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(make_temp_file))(char const *__suffix) {
	return (__NAMESPACE_LOCAL_SYM __localdep_make_temp_file_with_prefix)(__NULLPTR, __suffix);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_make_temp_file_defined
#define __local___localdep_make_temp_file_defined
#define __localdep_make_temp_file __LIBC_LOCAL_NAME(make_temp_file)
#endif /* !__local___localdep_make_temp_file_defined */
#else /* __CRT_HAVE_make_temp_file_with_prefix || ((__CRT_HAVE_choose_tmpdir || ((__CRT_HAVE_access || __CRT_HAVE__access || __CRT_HAVE___access || __CRT_HAVE___libc_access || (__AT_FDCWD && __CRT_HAVE_faccessat)) && !_WIN32 && __X_OK && __W_OK && __R_OK)) && (__CRT_HAVE_xmalloc || __CRT_HAVE_xrealloc || __CRT_HAVE_xcalloc || ((__CRT_HAVE_malloc || __CRT_HAVE___libc_malloc || __CRT_HAVE_calloc || __CRT_HAVE___libc_calloc || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc || __CRT_HAVE_memalign || __CRT_HAVE_aligned_alloc || __CRT_HAVE___libc_memalign || __CRT_HAVE_posix_memalign) && __CRT_HAVE_xmalloc_failed)) && (__CRT_HAVE_open64 || __CRT_HAVE___open64 || __CRT_HAVE_open || __CRT_HAVE__open || __CRT_HAVE___open || __CRT_HAVE___libc_open || (__AT_FDCWD && (__CRT_HAVE_openat64 || __CRT_HAVE_openat))) && (__CRT_HAVE_fprintf || __CRT_HAVE__IO_fprintf || __CRT_HAVE_fprintf_s || __CRT_HAVE_fprintf_unlocked || __CRT_HAVE_vfprintf || __CRT_HAVE__IO_vfprintf || __CRT_HAVE_vfprintf_s || __CRT_HAVE_vfprintf_unlocked || __CRT_HAVE_file_printer || __CRT_HAVE_file_printer_unlocked || __CRT_HAVE_putc || __CRT_HAVE_fputc || __CRT_HAVE__IO_putc || __CRT_HAVE_putc_unlocked || __CRT_HAVE_fputc_unlocked || __CRT_HAVE__putc_nolock || __CRT_HAVE__fputc_nolock || (__CRT_DOS && (__CRT_HAVE__flsbuf || __CRT_HAVE___swbuf)) || __CRT_HAVE_fwrite || __CRT_HAVE__IO_fwrite || __CRT_HAVE_fwrite_s || __CRT_HAVE_fwrite_unlocked || __CRT_HAVE__fwrite_nolock) && (__CRT_HAVE_abort || __CRT_HAVE__ZSt9terminatev || __CRT_HAVE_terminate || __CRT_HAVE___chk_fail || __CRT_HAVE_$Qterminate$A$AYAXXZ || __CRT_HAVE__Exit || __CRT_HAVE__exit || __CRT_HAVE_quick_exit || __CRT_HAVE_exit) && __LOCAL_stderr) */
#undef __local_make_temp_file_defined
#endif /* !__CRT_HAVE_make_temp_file_with_prefix && ((!__CRT_HAVE_choose_tmpdir && ((!__CRT_HAVE_access && !__CRT_HAVE__access && !__CRT_HAVE___access && !__CRT_HAVE___libc_access && (!__AT_FDCWD || !__CRT_HAVE_faccessat)) || _WIN32 || !__X_OK || !__W_OK || !__R_OK)) || (!__CRT_HAVE_xmalloc && !__CRT_HAVE_xrealloc && !__CRT_HAVE_xcalloc && ((!__CRT_HAVE_malloc && !__CRT_HAVE___libc_malloc && !__CRT_HAVE_calloc && !__CRT_HAVE___libc_calloc && !__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc && !__CRT_HAVE_memalign && !__CRT_HAVE_aligned_alloc && !__CRT_HAVE___libc_memalign && !__CRT_HAVE_posix_memalign) || !__CRT_HAVE_xmalloc_failed)) || (!__CRT_HAVE_open64 && !__CRT_HAVE___open64 && !__CRT_HAVE_open && !__CRT_HAVE__open && !__CRT_HAVE___open && !__CRT_HAVE___libc_open && (!__AT_FDCWD || (!__CRT_HAVE_openat64 && !__CRT_HAVE_openat))) || (!__CRT_HAVE_fprintf && !__CRT_HAVE__IO_fprintf && !__CRT_HAVE_fprintf_s && !__CRT_HAVE_fprintf_unlocked && !__CRT_HAVE_vfprintf && !__CRT_HAVE__IO_vfprintf && !__CRT_HAVE_vfprintf_s && !__CRT_HAVE_vfprintf_unlocked && !__CRT_HAVE_file_printer && !__CRT_HAVE_file_printer_unlocked && !__CRT_HAVE_putc && !__CRT_HAVE_fputc && !__CRT_HAVE__IO_putc && !__CRT_HAVE_putc_unlocked && !__CRT_HAVE_fputc_unlocked && !__CRT_HAVE__putc_nolock && !__CRT_HAVE__fputc_nolock && (!__CRT_DOS || (!__CRT_HAVE__flsbuf && !__CRT_HAVE___swbuf)) && !__CRT_HAVE_fwrite && !__CRT_HAVE__IO_fwrite && !__CRT_HAVE_fwrite_s && !__CRT_HAVE_fwrite_unlocked && !__CRT_HAVE__fwrite_nolock) || (!__CRT_HAVE_abort && !__CRT_HAVE__ZSt9terminatev && !__CRT_HAVE_terminate && !__CRT_HAVE___chk_fail && !__CRT_HAVE_$Qterminate$A$AYAXXZ && !__CRT_HAVE__Exit && !__CRT_HAVE__exit && !__CRT_HAVE_quick_exit && !__CRT_HAVE_exit) || !__LOCAL_stderr) */
#endif /* !__local_make_temp_file_defined */
