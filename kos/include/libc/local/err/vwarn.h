/* HASH CRC-32:0x188dd867 */
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
#ifndef __local_vwarn_defined
#define __local_vwarn_defined 1
#include <__crt.h>
#include <libc/local/program_invocation_name.h>
#if defined(__CRT_HAVE_vwarnc) || (!defined(__NO_STDSTREAMS) && defined(__LOCAL_program_invocation_short_name) && (defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE_putc_unlocked) || (defined(__CRT_DOS) && defined(__CRT_HAVE__flsbuf)) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <kos/anno.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: vwarnc from err */
#ifndef __local___localdep_vwarnc_defined
#define __local___localdep_vwarnc_defined 1
#ifdef __CRT_HAVE_vwarnc
__NAMESPACE_LOCAL_END
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
/* Print to stderr: `<program_invocation_short_name>: <format...>: strerror(used_errno)\n' */
__CREDIRECT_VOID(__ATTR_LIBC_PRINTF(1, 0),__THROWING,__localdep_vwarnc,(__errno_t __used_errno, char const *__format, __builtin_va_list __args),vwarnc,(__used_errno,__format,__args))
#elif !defined(__NO_STDSTREAMS) && defined(__LOCAL_program_invocation_short_name) && (defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE_putc_unlocked) || (defined(__CRT_DOS) && defined(__CRT_HAVE__flsbuf)) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock))
__NAMESPACE_LOCAL_END
#include <libc/local/err/vwarnc.h>
__NAMESPACE_LOCAL_BEGIN
/* Print to stderr: `<program_invocation_short_name>: <format...>: strerror(used_errno)\n' */
#define __localdep_vwarnc __LIBC_LOCAL_NAME(vwarnc)
#else /* ... */
#undef __local___localdep_vwarnc_defined
#endif /* !... */
#endif /* !__local___localdep_vwarnc_defined */
__NAMESPACE_LOCAL_END
#include <libc/errno.h>
__NAMESPACE_LOCAL_BEGIN
/* Print to stderr: `<program_invocation_short_name>: <format...>: strerror(errno)\n' */
__LOCAL_LIBC(vwarn) __ATTR_LIBC_PRINTF(1, 0) void
(__LIBCCALL __LIBC_LOCAL_NAME(vwarn))(char const *__format, __builtin_va_list __args) __THROWS(...) {
	__localdep_vwarnc(__libc_geterrno_or(0), __format, __args);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_vwarn_defined
#define __local___localdep_vwarn_defined 1
#define __localdep_vwarn __LIBC_LOCAL_NAME(vwarn)
#endif /* !__local___localdep_vwarn_defined */
#else /* __CRT_HAVE_vwarnc || (!__NO_STDSTREAMS && __LOCAL_program_invocation_short_name && (__CRT_HAVE_vfprintf || __CRT_HAVE_vfprintf_s || __CRT_HAVE__IO_vfprintf || __CRT_HAVE_vfprintf_unlocked || __CRT_HAVE_file_printer || __CRT_HAVE_file_printer_unlocked || __CRT_HAVE_fputc || __CRT_HAVE_putc || __CRT_HAVE__IO_putc || __CRT_HAVE_fputc_unlocked || __CRT_HAVE_putc_unlocked || (__CRT_DOS && __CRT_HAVE__flsbuf) || __CRT_HAVE_fwrite || __CRT_HAVE__IO_fwrite || __CRT_HAVE_fwrite_s || __CRT_HAVE_fwrite_unlocked || __CRT_HAVE__fwrite_nolock)) */
#undef __local_vwarn_defined
#endif /* !__CRT_HAVE_vwarnc && (__NO_STDSTREAMS || !__LOCAL_program_invocation_short_name || (!__CRT_HAVE_vfprintf && !__CRT_HAVE_vfprintf_s && !__CRT_HAVE__IO_vfprintf && !__CRT_HAVE_vfprintf_unlocked && !__CRT_HAVE_file_printer && !__CRT_HAVE_file_printer_unlocked && !__CRT_HAVE_fputc && !__CRT_HAVE_putc && !__CRT_HAVE__IO_putc && !__CRT_HAVE_fputc_unlocked && !__CRT_HAVE_putc_unlocked && (!__CRT_DOS || !__CRT_HAVE__flsbuf) && !__CRT_HAVE_fwrite && !__CRT_HAVE__IO_fwrite && !__CRT_HAVE_fwrite_s && !__CRT_HAVE_fwrite_unlocked && !__CRT_HAVE__fwrite_nolock)) */
#endif /* !__local_vwarn_defined */
