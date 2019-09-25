/* HASH CRC-32:0xb5856c0a */
/* Copyright (c) 2019 Griefer@Work                                            *
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
 *    in a product, an acknowledgement in the product documentation would be  *
 *    appreciated but is not required.                                        *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_wcscasecoll_l_defined
#define __local_wcscasecoll_l_defined 1
/* Dependency: "wcscasecmp_l" from "wchar" */
#ifndef ____localdep_wcscasecmp_l_defined
#define ____localdep_wcscasecmp_l_defined 1
#if defined(__CRT_HAVE_wcscasecmp_l)
__CREDIRECT(__ATTR_WUNUSED __ATTR_PURE __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_wcscasecmp_l,(__WCHAR_TYPE__ const *__s1, __WCHAR_TYPE__ const *__s2, __locale_t __locale),wcscasecmp_l,(__s1,__s2,__locale))
#elif defined(__CRT_HAVE__wcsicmp_l)
__CREDIRECT(__ATTR_WUNUSED __ATTR_PURE __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_wcscasecmp_l,(__WCHAR_TYPE__ const *__s1, __WCHAR_TYPE__ const *__s2, __locale_t __locale),_wcsicmp_l,(__s1,__s2,__locale))
#elif defined(__CRT_HAVE_wcsicmp_l)
__CREDIRECT(__ATTR_WUNUSED __ATTR_PURE __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_wcscasecmp_l,(__WCHAR_TYPE__ const *__s1, __WCHAR_TYPE__ const *__s2, __locale_t __locale),wcsicmp_l,(__s1,__s2,__locale))
#else /* LIBC: wcscasecmp_l */
#include <local/wchar/wcscasecmp_l.h>
#define __localdep_wcscasecmp_l (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wcscasecmp_l))
#endif /* wcscasecmp_l... */
#endif /* !____localdep_wcscasecmp_l_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(wcscasecoll_l) __ATTR_WUNUSED __ATTR_PURE __ATTR_NONNULL((1, 2)) int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(wcscasecoll_l))(__WCHAR_TYPE__ const *__s1,
                                                           __WCHAR_TYPE__ const *__s2,
                                                           __locale_t __locale) {
#line 4073 "kos/src/libc/magic/string.c"
	return __localdep_wcscasecmp_l(__s1, __s2, __locale);
}
__NAMESPACE_LOCAL_END
#endif /* !__local_wcscasecoll_l_defined */
