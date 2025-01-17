/* HASH CRC-32:0xa0f64475 */
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
#ifndef __local_fwscanf_s_defined
#define __local_fwscanf_s_defined
#include <__crt.h>
#include <features.h>
#if defined(__CRT_HAVE_vfwscanf_s) || defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_vfwscanf_s_defined
#define __local___localdep_vfwscanf_s_defined
#ifdef __CRT_HAVE_vfwscanf_s
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_WSCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__localdep_vfwscanf_s,(__FILE *__stream, __WCHAR_TYPE__ const *__format, __builtin_va_list __args),vfwscanf_s,(__stream,__format,__args))
#elif defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))
__NAMESPACE_LOCAL_END
#include <libc/local/corecrt_wstdio/vfwscanf_s.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_vfwscanf_s __LIBC_LOCAL_NAME(vfwscanf_s)
#else /* ... */
#undef __local___localdep_vfwscanf_s_defined
#endif /* !... */
#endif /* !__local___localdep_vfwscanf_s_defined */
__LOCAL_LIBC(fwscanf_s) __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_WSCANF(2, 3) __STDC_INT_AS_SSIZE_T
__NOTHROW_NCX(__VLIBCCALL __LIBC_LOCAL_NAME(fwscanf_s))(__FILE *__stream, __WCHAR_TYPE__ const *__format, ...) {
	__STDC_INT_AS_SSIZE_T __result;
	__builtin_va_list __args;
	__builtin_va_start(__args, __format);
	__result = (__NAMESPACE_LOCAL_SYM __localdep_vfwscanf_s)(__stream, __format, __args);
	__builtin_va_end(__args);
	return __result;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_fwscanf_s_defined
#define __local___localdep_fwscanf_s_defined
#define __localdep_fwscanf_s __LIBC_LOCAL_NAME(fwscanf_s)
#endif /* !__local___localdep_fwscanf_s_defined */
#else /* __CRT_HAVE_vfwscanf_s || __CRT_HAVE__vfwscanf_s_l || __CRT_HAVE___stdio_common_vfwscanf || __CRT_HAVE_vfwscanf || __CRT_HAVE_vfwscanf_unlocked || ((__CRT_HAVE_fgetwc || __CRT_HAVE_getwc || __CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked) && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked)) */
#undef __local_fwscanf_s_defined
#endif /* !__CRT_HAVE_vfwscanf_s && !__CRT_HAVE__vfwscanf_s_l && !__CRT_HAVE___stdio_common_vfwscanf && !__CRT_HAVE_vfwscanf && !__CRT_HAVE_vfwscanf_unlocked && ((!__CRT_HAVE_fgetwc && !__CRT_HAVE_getwc && !__CRT_HAVE_fgetwc_unlocked && !__CRT_HAVE_getwc_unlocked) || (!__CRT_HAVE_ungetwc && !__CRT_HAVE_ungetwc_unlocked)) */
#endif /* !__local_fwscanf_s_defined */
