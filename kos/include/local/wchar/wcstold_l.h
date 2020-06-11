/* HASH CRC-32:0x585a8c8 */
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
#ifndef __local_wcstold_l_defined
#define __local_wcstold_l_defined 1
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: wcstold from wchar */
#ifndef __local___localdep_wcstold_defined
#define __local___localdep_wcstold_defined 1
#ifdef __wcstold_defined
__NAMESPACE_GLB_USING(wcstold)
#define __localdep_wcstold wcstold
#elif defined(__std_wcstold_defined)
__NAMESPACE_STD_USING(wcstold)
#define __localdep_wcstold wcstold
#elif defined(__CRT_HAVE_wcstold)
__CREDIRECT(__ATTR_PURE __ATTR_NONNULL((1)),__LONGDOUBLE,__NOTHROW_NCX,__localdep_wcstold,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr),wcstold,(__nptr,__endptr))
#elif defined(__CRT_HAVE_DOS$wcstold) && __SIZEOF_WCHAR_T__ == 4
__CREDIRECT_KOS(__ATTR_PURE __ATTR_NONNULL((1)),__LONGDOUBLE,__NOTHROW_NCX,__localdep_wcstold,(__CHAR32_TYPE__ const *__restrict __nptr, __CHAR32_TYPE__ **__endptr),wcstold,(__nptr,__endptr))
#elif defined(__CRT_HAVE_DOS$wcstold) && __SIZEOF_WCHAR_T__ == 2
__CREDIRECT_DOS(__ATTR_PURE __ATTR_NONNULL((1)),__LONGDOUBLE,__NOTHROW_NCX,__localdep_wcstold,(__CHAR16_TYPE__ const *__restrict __nptr, __CHAR16_TYPE__ **__endptr),wcstold,(__nptr,__endptr))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <local/wchar/wcstold.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_wcstold __LIBC_LOCAL_NAME(wcstold)
#endif /* !... */
#endif /* !__local___localdep_wcstold_defined */
__LOCAL_LIBC(wcstold_l) __ATTR_PURE __ATTR_WUNUSED __ATTR_NONNULL((1)) __LONGDOUBLE
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(wcstold_l))(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, __locale_t __locale) {
	(void)__locale;
	return __localdep_wcstold(__nptr, __endptr);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_wcstold_l_defined
#define __local___localdep_wcstold_l_defined 1
#define __localdep_wcstold_l __LIBC_LOCAL_NAME(wcstold_l)
#endif /* !__local___localdep_wcstold_l_defined */
#endif /* !__local_wcstold_l_defined */
