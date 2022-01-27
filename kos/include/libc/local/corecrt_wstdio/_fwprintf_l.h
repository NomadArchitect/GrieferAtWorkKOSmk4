/* HASH CRC-32:0xa047ef49 */
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
#ifndef __local__fwprintf_l_defined
#define __local__fwprintf_l_defined
#include <__crt.h>
#include <features.h>
#if defined(__CRT_HAVE__vfwprintf_l) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc)
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__vfwprintf_l_defined
#define __local___localdep__vfwprintf_l_defined
#ifdef __CRT_HAVE__vfwprintf_l
__CREDIRECT(__ATTR_NONNULL((1, 2)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__localdep__vfwprintf_l,(__FILE *__stream, __WCHAR_TYPE__ const *__format, __locale_t __locale, __builtin_va_list __args),_vfwprintf_l,(__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc)
__NAMESPACE_LOCAL_END
#include <libc/local/corecrt_wstdio/_vfwprintf_l.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__vfwprintf_l __LIBC_LOCAL_NAME(_vfwprintf_l)
#else /* ... */
#undef __local___localdep__vfwprintf_l_defined
#endif /* !... */
#endif /* !__local___localdep__vfwprintf_l_defined */
__LOCAL_LIBC(_fwprintf_l) __ATTR_NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T
__NOTHROW_NCX(__VLIBCCALL __LIBC_LOCAL_NAME(_fwprintf_l))(__FILE *__stream, __WCHAR_TYPE__ const *__format, __locale_t __locale, ...) {
	__STDC_INT_AS_SSIZE_T __result;
	__builtin_va_list __args;
	__builtin_va_start(__args, __locale);
	__result = (__NAMESPACE_LOCAL_SYM __localdep__vfwprintf_l)(__stream, __format, __locale, __args);
	__builtin_va_end(__args);
	return __result;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__fwprintf_l_defined
#define __local___localdep__fwprintf_l_defined
#define __localdep__fwprintf_l __LIBC_LOCAL_NAME(_fwprintf_l)
#endif /* !__local___localdep__fwprintf_l_defined */
#else /* __CRT_HAVE__vfwprintf_l || __CRT_HAVE_vfwprintf || __CRT_HAVE_file_wprinter || __CRT_HAVE_file_wprinter_unlocked || __CRT_HAVE_fputwc || __CRT_HAVE_putwc */
#undef __local__fwprintf_l_defined
#endif /* !__CRT_HAVE__vfwprintf_l && !__CRT_HAVE_vfwprintf && !__CRT_HAVE_file_wprinter && !__CRT_HAVE_file_wprinter_unlocked && !__CRT_HAVE_fputwc && !__CRT_HAVE_putwc */
#endif /* !__local__fwprintf_l_defined */