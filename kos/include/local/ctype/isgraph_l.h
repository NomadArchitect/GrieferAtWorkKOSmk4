/* HASH CRC-32:0x4a927cd2 */
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
#ifndef __local_isgraph_l_defined
#define __local_isgraph_l_defined 1
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: __locale_ctype_ptr_l from ctype */
#if !defined(__local___localdep___locale_ctype_ptr_l_defined) && defined(__CRT_HAVE___locale_ctype_ptr_l)
#define __local___localdep___locale_ctype_ptr_l_defined 1
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED,char const *,__NOTHROW_NCX,__localdep___locale_ctype_ptr_l,(__locale_t __locale),__locale_ctype_ptr_l,(__locale))
#endif /* !__local___localdep___locale_ctype_ptr_l_defined && __CRT_HAVE___locale_ctype_ptr_l */
/* Dependency: _isctype_l from ctype */
#if !defined(__local___localdep__isctype_l_defined) && defined(__CRT_HAVE__isctype_l)
#define __local___localdep__isctype_l_defined 1
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED,int,__NOTHROW_NCX,__localdep__isctype_l,(int __ch, int __mask, __locale_t __locale),_isctype_l,(__ch,__mask,__locale))
#endif /* !__local___localdep__isctype_l_defined && __CRT_HAVE__isctype_l */
/* Dependency: isgraph from ctype */
#ifndef __local___localdep_isgraph_defined
#define __local___localdep_isgraph_defined 1
#if __has_builtin(__builtin_isgraph) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_isgraph)
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_isgraph,(int __ch),isgraph,{ return __builtin_isgraph(__ch); })
#elif defined(__CRT_HAVE_isgraph)
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_isgraph,(int __ch),isgraph,(__ch))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <local/ctype/isgraph.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_isgraph __LIBC_LOCAL_NAME(isgraph)
#endif /* !... */
#endif /* !__local___localdep_isgraph_defined */
__LOCAL_LIBC(isgraph_l) __ATTR_PURE __ATTR_WUNUSED int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(isgraph_l))(int __ch, __locale_t __locale) {





#if defined(__CRT_HAVE___ctype_b_loc) && defined(__CRT_GLC)
#include <hybrid/byteorder.h>
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
	return __locale->__ctype_b[__ch] & (1 << 7);
#else /* __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ */
	return __locale->__ctype_b[__ch] & (1 << 15);
#endif /* __BYTE_ORDER__ != __ORDER_BIG_ENDIAN__ */
#elif defined(__CRT_HAVE___locale_ctype_ptr_l) && defined(__CRT_CYG)
	return ((__localdep___locale_ctype_ptr_l(__locale) + 1)[__ch & 0xff] & 027) != 0;
#elif defined(__CRT_HAVE__isctype_l) && defined(__CRT_DOS)
	return __localdep__isctype_l(__ch, 0x0117, __locale);
#else /* ... */
	(void)__locale;
	__COMPILER_IMPURE();
	return __localdep_isgraph(__ch);
#endif /* !... */

}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_isgraph_l_defined
#define __local___localdep_isgraph_l_defined 1
#define __localdep_isgraph_l __LIBC_LOCAL_NAME(isgraph_l)
#endif /* !__local___localdep_isgraph_l_defined */
#endif /* !__local_isgraph_l_defined */
