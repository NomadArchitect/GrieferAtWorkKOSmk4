/* HASH CRC-32:0xe80a7942 */
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
#ifndef __local_wcsto32_l_defined
#define __local_wcsto32_l_defined 1
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: wcsto32 from wchar */
#ifndef __local___localdep_wcsto32_defined
#define __local___localdep_wcsto32_defined 1
#ifdef __CRT_HAVE_wcsto32
__CREDIRECT(__ATTR_LEAF __ATTR_WUNUSED __ATTR_NONNULL((1)),__INT32_TYPE__,__NOTHROW_NCX,__localdep_wcsto32,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcsto32,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcsto32) && __SIZEOF_WCHAR_T__ == 4
__CREDIRECT_KOS(__ATTR_LEAF __ATTR_WUNUSED __ATTR_NONNULL((1)),__INT32_TYPE__,__NOTHROW_NCX,__localdep_wcsto32,(__CHAR32_TYPE__ const *__restrict __nptr, __CHAR32_TYPE__ **__endptr, int __base),wcsto32,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcsto32) && __SIZEOF_WCHAR_T__ == 2
__CREDIRECT_DOS(__ATTR_LEAF __ATTR_WUNUSED __ATTR_NONNULL((1)),__INT32_TYPE__,__NOTHROW_NCX,__localdep_wcsto32,(__CHAR16_TYPE__ const *__restrict __nptr, __CHAR16_TYPE__ **__endptr, int __base),wcsto32,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcstol) && (__SIZEOF_LONG__ == 4)
__CREDIRECT(__ATTR_LEAF __ATTR_WUNUSED __ATTR_NONNULL((1)),__INT32_TYPE__,__NOTHROW_NCX,__localdep_wcsto32,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcstol,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcstol) && (__SIZEOF_LONG__ == 4) && __SIZEOF_WCHAR_T__ == 4
__CREDIRECT_KOS(__ATTR_LEAF __ATTR_WUNUSED __ATTR_NONNULL((1)),__INT32_TYPE__,__NOTHROW_NCX,__localdep_wcsto32,(__CHAR32_TYPE__ const *__restrict __nptr, __CHAR32_TYPE__ **__endptr, int __base),wcstol,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcstol) && (__SIZEOF_LONG__ == 4) && __SIZEOF_WCHAR_T__ == 2
__CREDIRECT_DOS(__ATTR_LEAF __ATTR_WUNUSED __ATTR_NONNULL((1)),__INT32_TYPE__,__NOTHROW_NCX,__localdep_wcsto32,(__CHAR16_TYPE__ const *__restrict __nptr, __CHAR16_TYPE__ **__endptr, int __base),wcstol,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcstoll) && (__SIZEOF_LONG_LONG__ == 4)
__CREDIRECT(__ATTR_LEAF __ATTR_WUNUSED __ATTR_NONNULL((1)),__INT32_TYPE__,__NOTHROW_NCX,__localdep_wcsto32,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcstoll,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcstoll) && (__SIZEOF_LONG_LONG__ == 4) && __SIZEOF_WCHAR_T__ == 4
__CREDIRECT_KOS(__ATTR_LEAF __ATTR_WUNUSED __ATTR_NONNULL((1)),__INT32_TYPE__,__NOTHROW_NCX,__localdep_wcsto32,(__CHAR32_TYPE__ const *__restrict __nptr, __CHAR32_TYPE__ **__endptr, int __base),wcstoll,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcstoll) && (__SIZEOF_LONG_LONG__ == 4) && __SIZEOF_WCHAR_T__ == 2
__CREDIRECT_DOS(__ATTR_LEAF __ATTR_WUNUSED __ATTR_NONNULL((1)),__INT32_TYPE__,__NOTHROW_NCX,__localdep_wcsto32,(__CHAR16_TYPE__ const *__restrict __nptr, __CHAR16_TYPE__ **__endptr, int __base),wcstoll,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcstoq) && (__SIZEOF_LONG_LONG__ == 4)
__CREDIRECT(__ATTR_LEAF __ATTR_WUNUSED __ATTR_NONNULL((1)),__INT32_TYPE__,__NOTHROW_NCX,__localdep_wcsto32,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcstoq,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcstoq) && (__SIZEOF_LONG_LONG__ == 4) && __SIZEOF_WCHAR_T__ == 4
__CREDIRECT_KOS(__ATTR_LEAF __ATTR_WUNUSED __ATTR_NONNULL((1)),__INT32_TYPE__,__NOTHROW_NCX,__localdep_wcsto32,(__CHAR32_TYPE__ const *__restrict __nptr, __CHAR32_TYPE__ **__endptr, int __base),wcstoq,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcstoq) && (__SIZEOF_LONG_LONG__ == 4) && __SIZEOF_WCHAR_T__ == 2
__CREDIRECT_DOS(__ATTR_LEAF __ATTR_WUNUSED __ATTR_NONNULL((1)),__INT32_TYPE__,__NOTHROW_NCX,__localdep_wcsto32,(__CHAR16_TYPE__ const *__restrict __nptr, __CHAR16_TYPE__ **__endptr, int __base),wcstoq,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcstoimax) && (__SIZEOF_INTMAX_T__ == 4)
__CREDIRECT(__ATTR_LEAF __ATTR_WUNUSED __ATTR_NONNULL((1)),__INT32_TYPE__,__NOTHROW_NCX,__localdep_wcsto32,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcstoimax,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcstoimax) && (__SIZEOF_INTMAX_T__ == 4) && __SIZEOF_WCHAR_T__ == 4
__CREDIRECT_KOS(__ATTR_LEAF __ATTR_WUNUSED __ATTR_NONNULL((1)),__INT32_TYPE__,__NOTHROW_NCX,__localdep_wcsto32,(__CHAR32_TYPE__ const *__restrict __nptr, __CHAR32_TYPE__ **__endptr, int __base),wcstoimax,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcstoimax) && (__SIZEOF_INTMAX_T__ == 4) && __SIZEOF_WCHAR_T__ == 2
__CREDIRECT_DOS(__ATTR_LEAF __ATTR_WUNUSED __ATTR_NONNULL((1)),__INT32_TYPE__,__NOTHROW_NCX,__localdep_wcsto32,(__CHAR16_TYPE__ const *__restrict __nptr, __CHAR16_TYPE__ **__endptr, int __base),wcstoimax,(__nptr,__endptr,__base))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <local/wchar/wcsto32.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_wcsto32 __LIBC_LOCAL_NAME(wcsto32)
#endif /* !... */
#endif /* !__local___localdep_wcsto32_defined */
__LOCAL_LIBC(wcsto32_l) __ATTR_LEAF __ATTR_WUNUSED __ATTR_NONNULL((1)) __INT32_TYPE__
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(wcsto32_l))(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale) {
	(void)__locale;
	return __localdep_wcsto32(__nptr, __endptr, __base);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_wcsto32_l_defined
#define __local___localdep_wcsto32_l_defined 1
#define __localdep_wcsto32_l __LIBC_LOCAL_NAME(wcsto32_l)
#endif /* !__local___localdep_wcsto32_l_defined */
#endif /* !__local_wcsto32_l_defined */
