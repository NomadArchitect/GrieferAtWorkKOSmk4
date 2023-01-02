/* HASH CRC-32:0xe83f4743 */
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
#ifndef __local_c16casecoll_l_defined
#define __local_c16casecoll_l_defined
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_c16casecmp_l_defined
#define __local___localdep_c16casecmp_l_defined
#if defined(__CRT_HAVE_wcscasecmp_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_c16casecmp_l,(__CHAR16_TYPE__ const *__s1, __CHAR16_TYPE__ const *__s2, __locale_t __locale),wcscasecmp_l,(__s1,__s2,__locale))
#elif defined(__CRT_HAVE_DOS$wcscasecmp_l)
__CREDIRECT_DOS(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_c16casecmp_l,(__CHAR16_TYPE__ const *__s1, __CHAR16_TYPE__ const *__s2, __locale_t __locale),wcscasecmp_l,(__s1,__s2,__locale))
#elif defined(__CRT_HAVE__wcsicmp_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_c16casecmp_l,(__CHAR16_TYPE__ const *__s1, __CHAR16_TYPE__ const *__s2, __locale_t __locale),_wcsicmp_l,(__s1,__s2,__locale))
#elif defined(__CRT_HAVE_DOS$_wcsicmp_l)
__CREDIRECT_DOS(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_c16casecmp_l,(__CHAR16_TYPE__ const *__s1, __CHAR16_TYPE__ const *__s2, __locale_t __locale),_wcsicmp_l,(__s1,__s2,__locale))
#elif defined(__CRT_HAVE___wcscasecmp_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_c16casecmp_l,(__CHAR16_TYPE__ const *__s1, __CHAR16_TYPE__ const *__s2, __locale_t __locale),__wcscasecmp_l,(__s1,__s2,__locale))
#elif defined(__CRT_HAVE_DOS$__wcscasecmp_l)
__CREDIRECT_DOS(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_c16casecmp_l,(__CHAR16_TYPE__ const *__s1, __CHAR16_TYPE__ const *__s2, __locale_t __locale),__wcscasecmp_l,(__s1,__s2,__locale))
#elif __SIZEOF_WCHAR_T__ == 2
__NAMESPACE_LOCAL_END
#include <libc/local/wchar/wcscasecmp_l.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c16casecmp_l __NAMESPACE_LOCAL_TYPEHAX(int(__LIBDCALL*)(__CHAR16_TYPE__ const *,__CHAR16_TYPE__ const *,__locale_t),int(__LIBDCALL&)(__CHAR16_TYPE__ const *,__CHAR16_TYPE__ const *,__locale_t),wcscasecmp_l)
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/parts.uchar.string/c16casecmp_l.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c16casecmp_l __LIBC_LOCAL_NAME(c16casecmp_l)
#endif /* !... */
#endif /* !__local___localdep_c16casecmp_l_defined */
__LOCAL_LIBC(c16casecoll_l) __ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) int
__NOTHROW_NCX(__LIBDCALL __LIBC_LOCAL_NAME(c16casecoll_l))(__CHAR16_TYPE__ const *__s1, __CHAR16_TYPE__ const *__s2, __locale_t __locale) {
	/* XXX: Implement properly? */
	return (__NAMESPACE_LOCAL_SYM __localdep_c16casecmp_l)(__s1, __s2, __locale);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_c16casecoll_l_defined
#define __local___localdep_c16casecoll_l_defined
#define __localdep_c16casecoll_l __LIBC_LOCAL_NAME(c16casecoll_l)
#endif /* !__local___localdep_c16casecoll_l_defined */
#endif /* !__local_c16casecoll_l_defined */
