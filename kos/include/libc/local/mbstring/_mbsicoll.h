/* HASH CRC-32:0xd2b3426c */
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
#ifndef __local__mbsicoll_defined
#define __local__mbsicoll_defined
#include <__crt.h>
#if defined(__CRT_HAVE__mbsicoll_l) || defined(__CRT_HAVE__mbsicmp_l) || ((defined(__CRT_HAVE__ismbblead_l) || defined(__CRT_HAVE__mbctype) || defined(__CRT_HAVE___p__mbctype)) && (defined(__CRT_HAVE__mbctolower_l) || (defined(__CRT_HAVE__mbctouni_l) && defined(__CRT_HAVE__unitombc_l) && defined(__CRT_HAVE___unicode_descriptor)) || ((defined(__CRT_HAVE__mbctype) || defined(__CRT_HAVE___p__mbctype)) && (defined(__CRT_HAVE__mbcasemap) || defined(__CRT_HAVE___p__mbcasemap)))))
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__mbsicoll_l_defined
#define __local___localdep__mbsicoll_l_defined
#ifdef __CRT_HAVE__mbsicoll_l
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep__mbsicoll_l,(unsigned char const *__lhs, unsigned char const *__rhs, __locale_t __locale),_mbsicoll_l,(__lhs,__rhs,__locale))
#elif defined(__CRT_HAVE__mbsicmp_l) || ((defined(__CRT_HAVE__ismbblead_l) || defined(__CRT_HAVE__mbctype) || defined(__CRT_HAVE___p__mbctype)) && (defined(__CRT_HAVE__mbctolower_l) || (defined(__CRT_HAVE__mbctouni_l) && defined(__CRT_HAVE__unitombc_l) && defined(__CRT_HAVE___unicode_descriptor)) || ((defined(__CRT_HAVE__mbctype) || defined(__CRT_HAVE___p__mbctype)) && (defined(__CRT_HAVE__mbcasemap) || defined(__CRT_HAVE___p__mbcasemap)))))
__NAMESPACE_LOCAL_END
#include <libc/local/mbstring/_mbsicoll_l.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__mbsicoll_l __LIBC_LOCAL_NAME(_mbsicoll_l)
#else /* ... */
#undef __local___localdep__mbsicoll_l_defined
#endif /* !... */
#endif /* !__local___localdep__mbsicoll_l_defined */
__LOCAL_LIBC(_mbsicoll) __ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_mbsicoll))(unsigned char const *__lhs, unsigned char const *__rhs) {
	return (__NAMESPACE_LOCAL_SYM __localdep__mbsicoll_l)(__lhs, __rhs, __NULLPTR);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__mbsicoll_defined
#define __local___localdep__mbsicoll_defined
#define __localdep__mbsicoll __LIBC_LOCAL_NAME(_mbsicoll)
#endif /* !__local___localdep__mbsicoll_defined */
#else /* __CRT_HAVE__mbsicoll_l || __CRT_HAVE__mbsicmp_l || ((__CRT_HAVE__ismbblead_l || __CRT_HAVE__mbctype || __CRT_HAVE___p__mbctype) && (__CRT_HAVE__mbctolower_l || (__CRT_HAVE__mbctouni_l && __CRT_HAVE__unitombc_l && __CRT_HAVE___unicode_descriptor) || ((__CRT_HAVE__mbctype || __CRT_HAVE___p__mbctype) && (__CRT_HAVE__mbcasemap || __CRT_HAVE___p__mbcasemap)))) */
#undef __local__mbsicoll_defined
#endif /* !__CRT_HAVE__mbsicoll_l && !__CRT_HAVE__mbsicmp_l && ((!__CRT_HAVE__ismbblead_l && !__CRT_HAVE__mbctype && !__CRT_HAVE___p__mbctype) || (!__CRT_HAVE__mbctolower_l && (!__CRT_HAVE__mbctouni_l || !__CRT_HAVE__unitombc_l || !__CRT_HAVE___unicode_descriptor) && ((!__CRT_HAVE__mbctype && !__CRT_HAVE___p__mbctype) || (!__CRT_HAVE__mbcasemap && !__CRT_HAVE___p__mbcasemap)))) */
#endif /* !__local__mbsicoll_defined */
