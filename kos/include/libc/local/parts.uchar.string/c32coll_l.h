/* HASH CRC-32:0xed205378 */
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
#ifndef __local_c32coll_l_defined
#define __local_c32coll_l_defined
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_c32coll_defined
#define __local___localdep_c32coll_defined
#if defined(__CRT_HAVE_wcscoll) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_c32coll,(__CHAR32_TYPE__ const *__s1, __CHAR32_TYPE__ const *__s2),wcscoll,(__s1,__s2))
#elif defined(__CRT_HAVE_KOS$wcscoll)
__CREDIRECT_KOS(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_c32coll,(__CHAR32_TYPE__ const *__s1, __CHAR32_TYPE__ const *__s2),wcscoll,(__s1,__s2))
#elif __SIZEOF_WCHAR_T__ == 4
__NAMESPACE_LOCAL_END
#include <libc/local/wchar/wcscoll.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c32coll __NAMESPACE_LOCAL_TYPEHAX(int(__LIBKCALL*)(__CHAR32_TYPE__ const *,__CHAR32_TYPE__ const *),int(__LIBKCALL&)(__CHAR32_TYPE__ const *,__CHAR32_TYPE__ const *),wcscoll)
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/parts.uchar.string/c32coll.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c32coll __LIBC_LOCAL_NAME(c32coll)
#endif /* !... */
#endif /* !__local___localdep_c32coll_defined */
__LOCAL_LIBC(c32coll_l) __ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) int
__NOTHROW_NCX(__LIBKCALL __LIBC_LOCAL_NAME(c32coll_l))(__CHAR32_TYPE__ const *__s1, __CHAR32_TYPE__ const *__s2, __locale_t __locale) {
	/* XXX: Implement properly? */
	(void)__locale;
	return (__NAMESPACE_LOCAL_SYM __localdep_c32coll)(__s1, __s2);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_c32coll_l_defined
#define __local___localdep_c32coll_l_defined
#define __localdep_c32coll_l __LIBC_LOCAL_NAME(c32coll_l)
#endif /* !__local___localdep_c32coll_l_defined */
#endif /* !__local_c32coll_l_defined */
