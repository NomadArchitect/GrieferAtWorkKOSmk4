/* HASH CRC-32:0xf6ad19ac */
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
#ifndef __local__c16scanf_l_defined
#define __local__c16scanf_l_defined
#include <__crt.h>
#include <libc/template/stdstreams.h>
#include <features.h>
#if (defined(__CRT_HAVE__vwscanf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vwscanf_l) || ((defined(__CRT_HAVE_vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)))))
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__vc16scanf_l_defined
#define __local___localdep__vc16scanf_l_defined
#if defined(__CRT_HAVE__vwscanf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__localdep__vc16scanf_l,(__CHAR16_TYPE__ const *__format, __locale_t __locale, __builtin_va_list __args),_vwscanf_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vwscanf_l)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__localdep__vc16scanf_l,(__CHAR16_TYPE__ const *__format, __locale_t __locale, __builtin_va_list __args),_vwscanf_l,(__format,__locale,__args))
#elif (defined(__CRT_HAVE_vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))) && __SIZEOF_WCHAR_T__ == 2
__NAMESPACE_LOCAL_END
#include <libc/local/corecrt_wstdio/_vwscanf_l.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__vc16scanf_l __NAMESPACE_LOCAL_TYPEHAX(__STDC_INT_AS_SSIZE_T(__LIBDCALL*)(__CHAR16_TYPE__ const *,__locale_t,__builtin_va_list),__STDC_INT_AS_SSIZE_T(__LIBDCALL&)(__CHAR16_TYPE__ const *,__locale_t,__builtin_va_list),_vwscanf_l)
#elif (defined(__CRT_HAVE_vwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)))))
__NAMESPACE_LOCAL_END
#include <libc/local/parts.uchar.stdio/_vc16scanf_l.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__vc16scanf_l __LIBC_LOCAL_NAME(_vc16scanf_l)
#else /* ... */
#undef __local___localdep__vc16scanf_l_defined
#endif /* !... */
#endif /* !__local___localdep__vc16scanf_l_defined */
__LOCAL_LIBC(_c16scanf_l) __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 3) __STDC_INT_AS_SSIZE_T
__NOTHROW_NCX(__VLIBDCALL __LIBC_LOCAL_NAME(_c16scanf_l))(__CHAR16_TYPE__ const *__format, __locale_t __locale, ...) {
	__STDC_INT_AS_SSIZE_T __result;
	__builtin_va_list __args;
	__builtin_va_start(__args, __locale);
	__result = (__NAMESPACE_LOCAL_SYM __localdep__vc16scanf_l)(__format, __locale, __args);
	__builtin_va_end(__args);
	return __result;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__c16scanf_l_defined
#define __local___localdep__c16scanf_l_defined
#define __localdep__c16scanf_l __LIBC_LOCAL_NAME(_c16scanf_l)
#endif /* !__local___localdep__c16scanf_l_defined */
#else /* (__CRT_HAVE__vwscanf_l && __SIZEOF_WCHAR_T__ == 2 && __LIBCCALL_IS_LIBDCALL) || __CRT_HAVE_DOS$_vwscanf_l || ((__CRT_HAVE_vwscanf || (__LOCAL_stdin && (__CRT_HAVE_vfwscanf || __CRT_HAVE_vfwscanf_unlocked || ((__CRT_HAVE_fgetwc || __CRT_HAVE_getwc || __CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked) && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked))))) && __SIZEOF_WCHAR_T__ == 2) || (__CRT_HAVE_vwscanf && __SIZEOF_WCHAR_T__ == 2 && __LIBCCALL_IS_LIBDCALL) || __CRT_HAVE_DOS$vwscanf || (__LOCAL_stdin && (__CRT_HAVE_vfwscanf || __CRT_HAVE_vfwscanf_unlocked || ((__CRT_HAVE_fgetwc || __CRT_HAVE_getwc || __CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked) && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked))) && __SIZEOF_WCHAR_T__ == 2) || (__LOCAL_stdin && ((__CRT_HAVE_vfwscanf && __SIZEOF_WCHAR_T__ == 2 && __LIBCCALL_IS_LIBDCALL) || __CRT_HAVE_DOS$vfwscanf || (__CRT_HAVE_vfwscanf_unlocked && __SIZEOF_WCHAR_T__ == 2 && __LIBCCALL_IS_LIBDCALL) || __CRT_HAVE_DOS$vfwscanf_unlocked || ((__CRT_HAVE_fgetwc || __CRT_HAVE_getwc || __CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked) && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2) || (((__CRT_HAVE_fgetwc && __SIZEOF_WCHAR_T__ == 2 && __LIBCCALL_IS_LIBDCALL) || __CRT_HAVE_DOS$fgetwc || (__CRT_HAVE_getwc && __SIZEOF_WCHAR_T__ == 2 && __LIBCCALL_IS_LIBDCALL) || __CRT_HAVE_DOS$getwc || (__CRT_HAVE_fgetwc_unlocked && __SIZEOF_WCHAR_T__ == 2 && __LIBCCALL_IS_LIBDCALL) || __CRT_HAVE_DOS$fgetwc_unlocked || (__CRT_HAVE_getwc_unlocked && __SIZEOF_WCHAR_T__ == 2 && __LIBCCALL_IS_LIBDCALL) || __CRT_HAVE_DOS$getwc_unlocked) && ((__CRT_HAVE_ungetwc && __SIZEOF_WCHAR_T__ == 2 && __LIBCCALL_IS_LIBDCALL) || __CRT_HAVE_DOS$ungetwc || (__CRT_HAVE_ungetwc_unlocked && __SIZEOF_WCHAR_T__ == 2 && __LIBCCALL_IS_LIBDCALL) || __CRT_HAVE_DOS$ungetwc_unlocked)))) */
#undef __local__c16scanf_l_defined
#endif /* (!__CRT_HAVE__vwscanf_l || __SIZEOF_WCHAR_T__ != 2 || !__LIBCCALL_IS_LIBDCALL) && !__CRT_HAVE_DOS$_vwscanf_l && ((!__CRT_HAVE_vwscanf && (!__LOCAL_stdin || (!__CRT_HAVE_vfwscanf && !__CRT_HAVE_vfwscanf_unlocked && ((!__CRT_HAVE_fgetwc && !__CRT_HAVE_getwc && !__CRT_HAVE_fgetwc_unlocked && !__CRT_HAVE_getwc_unlocked) || (!__CRT_HAVE_ungetwc && !__CRT_HAVE_ungetwc_unlocked))))) || __SIZEOF_WCHAR_T__ != 2) && (!__CRT_HAVE_vwscanf || __SIZEOF_WCHAR_T__ != 2 || !__LIBCCALL_IS_LIBDCALL) && !__CRT_HAVE_DOS$vwscanf && (!__LOCAL_stdin || (!__CRT_HAVE_vfwscanf && !__CRT_HAVE_vfwscanf_unlocked && ((!__CRT_HAVE_fgetwc && !__CRT_HAVE_getwc && !__CRT_HAVE_fgetwc_unlocked && !__CRT_HAVE_getwc_unlocked) || (!__CRT_HAVE_ungetwc && !__CRT_HAVE_ungetwc_unlocked))) || __SIZEOF_WCHAR_T__ != 2) && (!__LOCAL_stdin || ((!__CRT_HAVE_vfwscanf || __SIZEOF_WCHAR_T__ != 2 || !__LIBCCALL_IS_LIBDCALL) && !__CRT_HAVE_DOS$vfwscanf && (!__CRT_HAVE_vfwscanf_unlocked || __SIZEOF_WCHAR_T__ != 2 || !__LIBCCALL_IS_LIBDCALL) && !__CRT_HAVE_DOS$vfwscanf_unlocked && ((!__CRT_HAVE_fgetwc && !__CRT_HAVE_getwc && !__CRT_HAVE_fgetwc_unlocked && !__CRT_HAVE_getwc_unlocked) || (!__CRT_HAVE_ungetwc && !__CRT_HAVE_ungetwc_unlocked) || __SIZEOF_WCHAR_T__ != 2) && (((!__CRT_HAVE_fgetwc || __SIZEOF_WCHAR_T__ != 2 || !__LIBCCALL_IS_LIBDCALL) && !__CRT_HAVE_DOS$fgetwc && (!__CRT_HAVE_getwc || __SIZEOF_WCHAR_T__ != 2 || !__LIBCCALL_IS_LIBDCALL) && !__CRT_HAVE_DOS$getwc && (!__CRT_HAVE_fgetwc_unlocked || __SIZEOF_WCHAR_T__ != 2 || !__LIBCCALL_IS_LIBDCALL) && !__CRT_HAVE_DOS$fgetwc_unlocked && (!__CRT_HAVE_getwc_unlocked || __SIZEOF_WCHAR_T__ != 2 || !__LIBCCALL_IS_LIBDCALL) && !__CRT_HAVE_DOS$getwc_unlocked) || ((!__CRT_HAVE_ungetwc || __SIZEOF_WCHAR_T__ != 2 || !__LIBCCALL_IS_LIBDCALL) && !__CRT_HAVE_DOS$ungetwc && (!__CRT_HAVE_ungetwc_unlocked || __SIZEOF_WCHAR_T__ != 2 || !__LIBCCALL_IS_LIBDCALL) && !__CRT_HAVE_DOS$ungetwc_unlocked)))) */
#endif /* !__local__c16scanf_l_defined */
