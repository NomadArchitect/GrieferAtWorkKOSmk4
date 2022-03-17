/* HASH CRC-32:0x1d3221be */
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
#ifndef __local__cprintf_s_l_defined
#define __local__cprintf_s_l_defined
#include <__crt.h>
#include <features.h>
#if defined(__CRT_HAVE__vcprintf_s_l) || defined(__CRT_HAVE___conio_common_vcprintf_s) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf_s) || defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__vcprintf_s_l_defined
#define __local___localdep__vcprintf_s_l_defined
#ifdef __CRT_HAVE__vcprintf_s_l
__CREDIRECT(__ATTR_LIBC_PRINTF(1, 0) __ATTR_NONNULL((1)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__localdep__vcprintf_s_l,(char const *__format, __locale_t __locale, __builtin_va_list __args),_vcprintf_s_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE___conio_common_vcprintf_s) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf_s) || defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
__NAMESPACE_LOCAL_END
#include <libc/local/conio/_vcprintf_s_l.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__vcprintf_s_l __LIBC_LOCAL_NAME(_vcprintf_s_l)
#else /* ... */
#undef __local___localdep__vcprintf_s_l_defined
#endif /* !... */
#endif /* !__local___localdep__vcprintf_s_l_defined */
__LOCAL_LIBC(_cprintf_s_l) __ATTR_LIBC_PRINTF(1, 3) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T
__NOTHROW_NCX(__VLIBCCALL __LIBC_LOCAL_NAME(_cprintf_s_l))(char const *__format, __locale_t __locale, ...) {
	__STDC_INT_AS_SSIZE_T __result;
	__builtin_va_list __args;
	__builtin_va_start(__args, __locale);
	__result = (__NAMESPACE_LOCAL_SYM __localdep__vcprintf_s_l)(__format, __locale, __args);
	__builtin_va_end(__args);
	return __result;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__cprintf_s_l_defined
#define __local___localdep__cprintf_s_l_defined
#define __localdep__cprintf_s_l __LIBC_LOCAL_NAME(_cprintf_s_l)
#endif /* !__local___localdep__cprintf_s_l_defined */
#else /* __CRT_HAVE__vcprintf_s_l || __CRT_HAVE___conio_common_vcprintf_s || (__CRT_HAVE_stdtty && (__CRT_HAVE___stdio_common_vfprintf_s || __CRT_HAVE___stdio_common_vfprintf || __CRT_HAVE_vfprintf || __CRT_HAVE_vfprintf_s || __CRT_HAVE__IO_vfprintf || __CRT_HAVE_vfprintf_unlocked || __CRT_HAVE_file_printer || __CRT_HAVE_file_printer_unlocked || __CRT_HAVE_putc || __CRT_HAVE_fputc || __CRT_HAVE__IO_putc || __CRT_HAVE_putc_unlocked || __CRT_HAVE_fputc_unlocked || __CRT_HAVE__putc_nolock || __CRT_HAVE__fputc_nolock || (__CRT_DOS && (__CRT_HAVE__flsbuf || __CRT_HAVE___swbuf)) || __CRT_HAVE_fwrite || __CRT_HAVE__IO_fwrite || __CRT_HAVE_fwrite_s || __CRT_HAVE_fwrite_unlocked || __CRT_HAVE__fwrite_nolock)) */
#undef __local__cprintf_s_l_defined
#endif /* !__CRT_HAVE__vcprintf_s_l && !__CRT_HAVE___conio_common_vcprintf_s && (!__CRT_HAVE_stdtty || (!__CRT_HAVE___stdio_common_vfprintf_s && !__CRT_HAVE___stdio_common_vfprintf && !__CRT_HAVE_vfprintf && !__CRT_HAVE_vfprintf_s && !__CRT_HAVE__IO_vfprintf && !__CRT_HAVE_vfprintf_unlocked && !__CRT_HAVE_file_printer && !__CRT_HAVE_file_printer_unlocked && !__CRT_HAVE_putc && !__CRT_HAVE_fputc && !__CRT_HAVE__IO_putc && !__CRT_HAVE_putc_unlocked && !__CRT_HAVE_fputc_unlocked && !__CRT_HAVE__putc_nolock && !__CRT_HAVE__fputc_nolock && (!__CRT_DOS || (!__CRT_HAVE__flsbuf && !__CRT_HAVE___swbuf)) && !__CRT_HAVE_fwrite && !__CRT_HAVE__IO_fwrite && !__CRT_HAVE_fwrite_s && !__CRT_HAVE_fwrite_unlocked && !__CRT_HAVE__fwrite_nolock)) */
#endif /* !__local__cprintf_s_l_defined */