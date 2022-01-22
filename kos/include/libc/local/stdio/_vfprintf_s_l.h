/* HASH CRC-32:0xafe0242b */
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
#ifndef __local__vfprintf_s_l_defined
#define __local__vfprintf_s_l_defined
#include <__crt.h>
#include <features.h>
#if defined(__CRT_HAVE___stdio_common_vfprintf_s) || defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE_putc_unlocked) || (defined(__CRT_DOS) && defined(__CRT_HAVE__flsbuf)) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep___stdio_common_vfprintf_s_defined
#define __local___localdep___stdio_common_vfprintf_s_defined
#ifdef __CRT_HAVE___stdio_common_vfprintf_s
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_NONNULL((2, 3)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__localdep___stdio_common_vfprintf_s,(__UINT64_TYPE__ __options, __FILE *__stream, char const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vfprintf_s,(__options,__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE_putc_unlocked) || (defined(__CRT_DOS) && defined(__CRT_HAVE__flsbuf)) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)
__NAMESPACE_LOCAL_END
#include <libc/local/stdio/__stdio_common_vfprintf_s.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep___stdio_common_vfprintf_s __LIBC_LOCAL_NAME(__stdio_common_vfprintf_s)
#else /* ... */
#undef __local___localdep___stdio_common_vfprintf_s_defined
#endif /* !... */
#endif /* !__local___localdep___stdio_common_vfprintf_s_defined */
__NAMESPACE_LOCAL_END
#include <corecrt_stdio_config.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(_vfprintf_s_l) __ATTR_NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_vfprintf_s_l))(__FILE *__stream, char const *__format, __locale_t __locale, __builtin_va_list __args) {
	return (__NAMESPACE_LOCAL_SYM __localdep___stdio_common_vfprintf_s)(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, __stream, __format, __locale, __args);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__vfprintf_s_l_defined
#define __local___localdep__vfprintf_s_l_defined
#define __localdep__vfprintf_s_l __LIBC_LOCAL_NAME(_vfprintf_s_l)
#endif /* !__local___localdep__vfprintf_s_l_defined */
#else /* __CRT_HAVE___stdio_common_vfprintf_s || __CRT_HAVE___stdio_common_vfprintf || __CRT_HAVE_vfprintf || __CRT_HAVE_vfprintf_s || __CRT_HAVE__IO_vfprintf || __CRT_HAVE_vfprintf_unlocked || __CRT_HAVE_file_printer || __CRT_HAVE_file_printer_unlocked || __CRT_HAVE_fputc || __CRT_HAVE_putc || __CRT_HAVE__IO_putc || __CRT_HAVE_fputc_unlocked || __CRT_HAVE_putc_unlocked || (__CRT_DOS && __CRT_HAVE__flsbuf) || __CRT_HAVE_fwrite || __CRT_HAVE__IO_fwrite || __CRT_HAVE_fwrite_s || __CRT_HAVE_fwrite_unlocked || __CRT_HAVE__fwrite_nolock */
#undef __local__vfprintf_s_l_defined
#endif /* !__CRT_HAVE___stdio_common_vfprintf_s && !__CRT_HAVE___stdio_common_vfprintf && !__CRT_HAVE_vfprintf && !__CRT_HAVE_vfprintf_s && !__CRT_HAVE__IO_vfprintf && !__CRT_HAVE_vfprintf_unlocked && !__CRT_HAVE_file_printer && !__CRT_HAVE_file_printer_unlocked && !__CRT_HAVE_fputc && !__CRT_HAVE_putc && !__CRT_HAVE__IO_putc && !__CRT_HAVE_fputc_unlocked && !__CRT_HAVE_putc_unlocked && (!__CRT_DOS || !__CRT_HAVE__flsbuf) && !__CRT_HAVE_fwrite && !__CRT_HAVE__IO_fwrite && !__CRT_HAVE_fwrite_s && !__CRT_HAVE_fwrite_unlocked && !__CRT_HAVE__fwrite_nolock */
#endif /* !__local__vfprintf_s_l_defined */