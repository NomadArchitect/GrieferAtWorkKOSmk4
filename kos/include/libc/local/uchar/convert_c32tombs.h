/* HASH CRC-32:0x446ac1c0 */
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
#ifndef __local_convert_c32tombs_defined
#define __local_convert_c32tombs_defined
#include <__crt.h>
#if (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_c32len_defined
#define __local___localdep_c32len_defined
#if defined(__CRT_HAVE_wcslen) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1),__SIZE_TYPE__,__NOTHROW_NCX,__localdep_c32len,(__CHAR32_TYPE__ const *__restrict __str),wcslen,(__str))
#elif defined(__CRT_HAVE_KOS$wcslen)
__CREDIRECT_KOS(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1),__SIZE_TYPE__,__NOTHROW_NCX,__localdep_c32len,(__CHAR32_TYPE__ const *__restrict __str),wcslen,(__str))
#elif __SIZEOF_WCHAR_T__ == 4
__NAMESPACE_LOCAL_END
#include <libc/local/wchar/wcslen.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c32len __NAMESPACE_LOCAL_TYPEHAX(__SIZE_TYPE__(__LIBKCALL*)(__CHAR32_TYPE__ const *__restrict),__SIZE_TYPE__(__LIBKCALL&)(__CHAR32_TYPE__ const *__restrict),wcslen)
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/parts.uchar.string/c32len.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c32len __LIBC_LOCAL_NAME(c32len)
#endif /* !... */
#endif /* !__local___localdep_c32len_defined */
#ifndef __local___localdep_convert_c32tombsn_defined
#define __local___localdep_convert_c32tombsn_defined
#if defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_MALLOC __ATTR_WUNUSED __ATTR_INS(1, 2) __ATTR_OUT_OPT(3),char *,__NOTHROW_NCX,__localdep_convert_c32tombsn,(__CHAR32_TYPE__ const *__restrict __str, __SIZE_TYPE__ __len, __SIZE_TYPE__ *__preslen),convert_wcstombsn,(__str,__len,__preslen))
#elif defined(__CRT_HAVE_KOS$convert_wcstombsn)
__CREDIRECT_KOS(__ATTR_MALLOC __ATTR_WUNUSED __ATTR_INS(1, 2) __ATTR_OUT_OPT(3),char *,__NOTHROW_NCX,__localdep_convert_c32tombsn,(__CHAR32_TYPE__ const *__restrict __str, __SIZE_TYPE__ __len, __SIZE_TYPE__ *__preslen),convert_wcstombsn,(__str,__len,__preslen))
#elif (defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
__NAMESPACE_LOCAL_END
#include <libc/local/uchar/convert_wcstombsn.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_convert_c32tombsn __NAMESPACE_LOCAL_TYPEHAX(char *(__LIBKCALL*)(__CHAR32_TYPE__ const *__restrict,__SIZE_TYPE__,__SIZE_TYPE__ *),char *(__LIBKCALL&)(__CHAR32_TYPE__ const *__restrict,__SIZE_TYPE__,__SIZE_TYPE__ *),convert_wcstombsn)
#elif defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)
__NAMESPACE_LOCAL_END
#include <libc/local/uchar/convert_c32tombsn.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_convert_c32tombsn __LIBC_LOCAL_NAME(convert_c32tombsn)
#else /* ... */
#undef __local___localdep_convert_c32tombsn_defined
#endif /* !... */
#endif /* !__local___localdep_convert_c32tombsn_defined */
__NAMESPACE_LOCAL_END
#include <libc/errno.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(convert_c32tombs) __ATTR_MALLOC __ATTR_WUNUSED __ATTR_IN_OPT(1) char *
__NOTHROW_NCX(__LIBKCALL __LIBC_LOCAL_NAME(convert_c32tombs))(__CHAR32_TYPE__ const *__str) {
	if __unlikely(!__str) {
#ifdef __EINVAL
		(void)__libc_seterrno(__EINVAL);
#endif /* __EINVAL */
		return __NULLPTR;
	}
	return (__NAMESPACE_LOCAL_SYM __localdep_convert_c32tombsn)(__str, (__NAMESPACE_LOCAL_SYM __localdep_c32len)(__str), __NULLPTR);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_convert_c32tombs_defined
#define __local___localdep_convert_c32tombs_defined
#define __localdep_convert_c32tombs __LIBC_LOCAL_NAME(convert_c32tombs)
#endif /* !__local___localdep_convert_c32tombs_defined */
#else /* (__CRT_HAVE_convert_wcstombsn && __SIZEOF_WCHAR_T__ == 4 && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_KOS$convert_wcstombsn || __CRT_HAVE_format_aprintf_printer || __CRT_HAVE_format_aprintf_alloc || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc */
#undef __local_convert_c32tombs_defined
#endif /* (!__CRT_HAVE_convert_wcstombsn || __SIZEOF_WCHAR_T__ != 4 || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_KOS$convert_wcstombsn && !__CRT_HAVE_format_aprintf_printer && !__CRT_HAVE_format_aprintf_alloc && !__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc */
#endif /* !__local_convert_c32tombs_defined */
