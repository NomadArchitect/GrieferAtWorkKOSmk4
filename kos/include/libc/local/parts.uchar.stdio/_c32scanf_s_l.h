/* HASH CRC-32:0x1268de3a */
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
#ifndef __local__c32scanf_s_l_defined
#define __local__c32scanf_s_l_defined
#include <__crt.h>
#include <features.h>
#if (defined(__CRT_HAVE__vwscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vwscanf_s_l) || ((defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc)) && !defined(__NO_STDSTREAMS) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc)) && !defined(__NO_STDSTREAMS))
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__vc32scanf_s_l_defined
#define __local___localdep__vc32scanf_s_l_defined
#if defined(__CRT_HAVE__vwscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((1)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__localdep__vc32scanf_s_l,(__CHAR32_TYPE__ const *__format, __locale_t __locale, __builtin_va_list __args),_vwscanf_s_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vwscanf_s_l)
__CREDIRECT_KOS(__ATTR_NONNULL((1)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__localdep__vc32scanf_s_l,(__CHAR32_TYPE__ const *__format, __locale_t __locale, __builtin_va_list __args),_vwscanf_s_l,(__format,__locale,__args))
#elif (defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc)) && !defined(__NO_STDSTREAMS) && __SIZEOF_WCHAR_T__ == 4
__NAMESPACE_LOCAL_END
#include <libc/local/corecrt_wstdio/_vwscanf_s_l.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__vc32scanf_s_l __NAMESPACE_LOCAL_TYPEHAX(__STDC_INT_AS_SSIZE_T(__LIBKCALL*)(__CHAR32_TYPE__ const *,__locale_t,__builtin_va_list),__STDC_INT_AS_SSIZE_T(__LIBKCALL&)(__CHAR32_TYPE__ const *,__locale_t,__builtin_va_list),_vwscanf_s_l)
#elif ((defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc)) && !defined(__NO_STDSTREAMS)
__NAMESPACE_LOCAL_END
#include <libc/local/parts.uchar.stdio/_vc32scanf_s_l.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__vc32scanf_s_l __LIBC_LOCAL_NAME(_vc32scanf_s_l)
#else /* ... */
#undef __local___localdep__vc32scanf_s_l_defined
#endif /* !... */
#endif /* !__local___localdep__vc32scanf_s_l_defined */
__LOCAL_LIBC(_c32scanf_s_l) __ATTR_WUNUSED __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T
__NOTHROW_NCX(__VLIBKCALL __LIBC_LOCAL_NAME(_c32scanf_s_l))(__CHAR32_TYPE__ const *__format, __locale_t __locale, ...) {
	__STDC_INT_AS_SSIZE_T __result;
	__builtin_va_list __args;
	__builtin_va_start(__args, __locale);
	__result = (__NAMESPACE_LOCAL_SYM __localdep__vc32scanf_s_l)(__format, __locale, __args);
	__builtin_va_end(__args);
	return __result;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__c32scanf_s_l_defined
#define __local___localdep__c32scanf_s_l_defined
#define __localdep__c32scanf_s_l __LIBC_LOCAL_NAME(_c32scanf_s_l)
#endif /* !__local___localdep__c32scanf_s_l_defined */
#else /* (__CRT_HAVE__vwscanf_s_l && __SIZEOF_WCHAR_T__ == 4 && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_KOS$_vwscanf_s_l || ((__CRT_HAVE__vfwprintf_s_l || __CRT_HAVE___stdio_common_vfwprintf_s || __CRT_HAVE___stdio_common_vfwprintf || __CRT_HAVE_vfwprintf || __CRT_HAVE_file_wprinter || __CRT_HAVE_file_wprinter_unlocked || __CRT_HAVE_fputwc || __CRT_HAVE_putwc) && !__NO_STDSTREAMS && __SIZEOF_WCHAR_T__ == 4) || (((__CRT_HAVE__vfwprintf_s_l && __SIZEOF_WCHAR_T__ == 4 && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_KOS$_vfwprintf_s_l || ((__CRT_HAVE___stdio_common_vfwprintf_s || __CRT_HAVE___stdio_common_vfwprintf || __CRT_HAVE_vfwprintf || __CRT_HAVE_file_wprinter || __CRT_HAVE_file_wprinter_unlocked || __CRT_HAVE_fputwc || __CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4) || (__CRT_HAVE___stdio_common_vfwprintf_s && __SIZEOF_WCHAR_T__ == 4 && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_KOS$__stdio_common_vfwprintf_s || ((__CRT_HAVE___stdio_common_vfwprintf || __CRT_HAVE_vfwprintf || __CRT_HAVE_file_wprinter || __CRT_HAVE_file_wprinter_unlocked || __CRT_HAVE_fputwc || __CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4) || (__CRT_HAVE___stdio_common_vfwprintf && __SIZEOF_WCHAR_T__ == 4 && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_KOS$__stdio_common_vfwprintf || ((__CRT_HAVE_vfwprintf || __CRT_HAVE_file_wprinter || __CRT_HAVE_file_wprinter_unlocked || __CRT_HAVE_fputwc || __CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4) || (__CRT_HAVE_vfwprintf && __SIZEOF_WCHAR_T__ == 4 && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_KOS$vfwprintf || ((__CRT_HAVE_file_wprinter || __CRT_HAVE_file_wprinter_unlocked || __CRT_HAVE_fputwc || __CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4) || (__CRT_HAVE_file_wprinter && __SIZEOF_WCHAR_T__ == 4 && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_KOS$file_wprinter || (__CRT_HAVE_file_wprinter_unlocked && __SIZEOF_WCHAR_T__ == 4 && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_KOS$file_wprinter_unlocked || ((__CRT_HAVE_fputwc || __CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4) || (__CRT_HAVE_fputwc && __SIZEOF_WCHAR_T__ == 4 && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_KOS$fputwc || (__CRT_HAVE_putwc && __SIZEOF_WCHAR_T__ == 4 && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_KOS$putwc) && !__NO_STDSTREAMS) */
#undef __local__c32scanf_s_l_defined
#endif /* (!__CRT_HAVE__vwscanf_s_l || __SIZEOF_WCHAR_T__ != 4 || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_KOS$_vwscanf_s_l && ((!__CRT_HAVE__vfwprintf_s_l && !__CRT_HAVE___stdio_common_vfwprintf_s && !__CRT_HAVE___stdio_common_vfwprintf && !__CRT_HAVE_vfwprintf && !__CRT_HAVE_file_wprinter && !__CRT_HAVE_file_wprinter_unlocked && !__CRT_HAVE_fputwc && !__CRT_HAVE_putwc) || __NO_STDSTREAMS || __SIZEOF_WCHAR_T__ != 4) && (((!__CRT_HAVE__vfwprintf_s_l || __SIZEOF_WCHAR_T__ != 4 || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_KOS$_vfwprintf_s_l && ((!__CRT_HAVE___stdio_common_vfwprintf_s && !__CRT_HAVE___stdio_common_vfwprintf && !__CRT_HAVE_vfwprintf && !__CRT_HAVE_file_wprinter && !__CRT_HAVE_file_wprinter_unlocked && !__CRT_HAVE_fputwc && !__CRT_HAVE_putwc) || __SIZEOF_WCHAR_T__ != 4) && (!__CRT_HAVE___stdio_common_vfwprintf_s || __SIZEOF_WCHAR_T__ != 4 || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_KOS$__stdio_common_vfwprintf_s && ((!__CRT_HAVE___stdio_common_vfwprintf && !__CRT_HAVE_vfwprintf && !__CRT_HAVE_file_wprinter && !__CRT_HAVE_file_wprinter_unlocked && !__CRT_HAVE_fputwc && !__CRT_HAVE_putwc) || __SIZEOF_WCHAR_T__ != 4) && (!__CRT_HAVE___stdio_common_vfwprintf || __SIZEOF_WCHAR_T__ != 4 || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_KOS$__stdio_common_vfwprintf && ((!__CRT_HAVE_vfwprintf && !__CRT_HAVE_file_wprinter && !__CRT_HAVE_file_wprinter_unlocked && !__CRT_HAVE_fputwc && !__CRT_HAVE_putwc) || __SIZEOF_WCHAR_T__ != 4) && (!__CRT_HAVE_vfwprintf || __SIZEOF_WCHAR_T__ != 4 || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_KOS$vfwprintf && ((!__CRT_HAVE_file_wprinter && !__CRT_HAVE_file_wprinter_unlocked && !__CRT_HAVE_fputwc && !__CRT_HAVE_putwc) || __SIZEOF_WCHAR_T__ != 4) && (!__CRT_HAVE_file_wprinter || __SIZEOF_WCHAR_T__ != 4 || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_KOS$file_wprinter && (!__CRT_HAVE_file_wprinter_unlocked || __SIZEOF_WCHAR_T__ != 4 || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_KOS$file_wprinter_unlocked && ((!__CRT_HAVE_fputwc && !__CRT_HAVE_putwc) || __SIZEOF_WCHAR_T__ != 4) && (!__CRT_HAVE_fputwc || __SIZEOF_WCHAR_T__ != 4 || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_KOS$fputwc && (!__CRT_HAVE_putwc || __SIZEOF_WCHAR_T__ != 4 || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_KOS$putwc) || __NO_STDSTREAMS) */
#endif /* !__local__c32scanf_s_l_defined */