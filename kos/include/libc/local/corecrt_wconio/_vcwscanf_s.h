/* HASH CRC-32:0x2c37e616 */
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
#ifndef __local__vcwscanf_s_defined
#define __local__vcwscanf_s_defined
#include <__crt.h>
#if defined(__CRT_HAVE__vcwscanf_s_l) || defined(__CRT_HAVE___conio_common_vcwscanf)
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__vcwscanf_s_l_defined
#define __local___localdep__vcwscanf_s_l_defined
#ifdef __CRT_HAVE__vcwscanf_s_l
__CREDIRECT(__ATTR_WUNUSED __ATTR_LIBC_WSCANF(1, 0) __ATTR_NONNULL((1)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__localdep__vcwscanf_s_l,(__WCHAR_TYPE__ const *__format, __locale_t __locale, __builtin_va_list __args),_vcwscanf_s_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE___conio_common_vcwscanf)
__NAMESPACE_LOCAL_END
#include <libc/local/corecrt_wconio/_vcwscanf_s_l.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__vcwscanf_s_l __LIBC_LOCAL_NAME(_vcwscanf_s_l)
#else /* ... */
#undef __local___localdep__vcwscanf_s_l_defined
#endif /* !... */
#endif /* !__local___localdep__vcwscanf_s_l_defined */
__LOCAL_LIBC(_vcwscanf_s) __ATTR_WUNUSED __ATTR_LIBC_WSCANF(1, 0) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_vcwscanf_s))(__WCHAR_TYPE__ const *__format, __builtin_va_list __args) {
	return (__NAMESPACE_LOCAL_SYM __localdep__vcwscanf_s_l)(__format, __NULLPTR, __args);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__vcwscanf_s_defined
#define __local___localdep__vcwscanf_s_defined
#define __localdep__vcwscanf_s __LIBC_LOCAL_NAME(_vcwscanf_s)
#endif /* !__local___localdep__vcwscanf_s_defined */
#else /* __CRT_HAVE__vcwscanf_s_l || __CRT_HAVE___conio_common_vcwscanf */
#undef __local__vcwscanf_s_defined
#endif /* !__CRT_HAVE__vcwscanf_s_l && !__CRT_HAVE___conio_common_vcwscanf */
#endif /* !__local__vcwscanf_s_defined */