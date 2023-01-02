/* HASH CRC-32:0x153ba320 */
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
#ifndef __local__vscc16printf_defined
#define __local__vscc16printf_defined
#include <__crt.h>
#include <features.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__vscc16printf_l_defined
#define __local___localdep__vscc16printf_l_defined
#if defined(__CRT_HAVE__vscwprintf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__localdep__vscc16printf_l,(__CHAR16_TYPE__ const *__format, __locale_t __locale, __builtin_va_list __args),_vscwprintf_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vscwprintf_l)
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__localdep__vscc16printf_l,(__CHAR16_TYPE__ const *__format, __locale_t __locale, __builtin_va_list __args),_vscwprintf_l,(__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
__NAMESPACE_LOCAL_END
#include <libc/local/corecrt_wstdio/_vscwprintf_l.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__vscc16printf_l __NAMESPACE_LOCAL_TYPEHAX(__STDC_INT_AS_SSIZE_T(__LIBDCALL*)(__CHAR16_TYPE__ const *,__locale_t,__builtin_va_list),__STDC_INT_AS_SSIZE_T(__LIBDCALL&)(__CHAR16_TYPE__ const *,__locale_t,__builtin_va_list),_vscwprintf_l)
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/parts.uchar.stdio/_vscc16printf_l.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__vscc16printf_l __LIBC_LOCAL_NAME(_vscc16printf_l)
#endif /* !... */
#endif /* !__local___localdep__vscc16printf_l_defined */
__LOCAL_LIBC(_vscc16printf) __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0) __STDC_INT_AS_SSIZE_T
__NOTHROW_NCX(__LIBDCALL __LIBC_LOCAL_NAME(_vscc16printf))(__CHAR16_TYPE__ const *__format, __builtin_va_list __args) {
	return (__NAMESPACE_LOCAL_SYM __localdep__vscc16printf_l)(__format, __NULLPTR, __args);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__vscc16printf_defined
#define __local___localdep__vscc16printf_defined
#define __localdep__vscc16printf __LIBC_LOCAL_NAME(_vscc16printf)
#endif /* !__local___localdep__vscc16printf_defined */
#endif /* !__local__vscc16printf_defined */
