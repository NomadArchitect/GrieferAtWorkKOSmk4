/* HASH CRC-32:0x914c54d2 */
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
#ifndef __local__ismbcpunct_l_defined
#define __local__ismbcpunct_l_defined
#include <__crt.h>
#if (defined(__CRT_HAVE__mbctouni_l) && defined(__CRT_HAVE___unicode_descriptor)) || defined(__CRT_HAVE__ismbbpunct_l) || defined(__CRT_HAVE__ismbbkpunct_l) || defined(__CRT_HAVE__mbctype) || defined(__CRT_HAVE___p__mbctype)
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__ismbbpunct_l_defined
#define __local___localdep__ismbbpunct_l_defined
#ifdef __CRT_HAVE__ismbbpunct_l
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED,int,__NOTHROW_NCX,__localdep__ismbbpunct_l,(unsigned int __ch, __locale_t __locale),_ismbbpunct_l,(__ch,__locale))
#elif defined(__CRT_HAVE__ismbbkpunct_l) || defined(__CRT_HAVE__mbctype) || defined(__CRT_HAVE___p__mbctype)
__NAMESPACE_LOCAL_END
#include <libc/local/mbctype/_ismbbpunct_l.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__ismbbpunct_l __LIBC_LOCAL_NAME(_ismbbpunct_l)
#else /* ... */
#undef __local___localdep__ismbbpunct_l_defined
#endif /* !... */
#endif /* !__local___localdep__ismbbpunct_l_defined */
#if !defined(__local___localdep__mbctouni_l_defined) && defined(__CRT_HAVE__mbctouni_l)
#define __local___localdep__mbctouni_l_defined
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED,__CHAR32_TYPE__,__NOTHROW_NCX,__localdep__mbctouni_l,(unsigned int __ch, __locale_t __locale),_mbctouni_l,(__ch,__locale))
#endif /* !__local___localdep__mbctouni_l_defined && __CRT_HAVE__mbctouni_l */
__NAMESPACE_LOCAL_END
#include <libc/unicode.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(_ismbcpunct_l) __ATTR_PURE __ATTR_WUNUSED int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_ismbcpunct_l))(unsigned int __ch, __locale_t __locale) {
#if defined(__CRT_HAVE__mbctouni_l) && defined(__CRT_HAVE___unicode_descriptor)
	__CHAR32_TYPE__ __uni = (__NAMESPACE_LOCAL_SYM __localdep__mbctouni_l)(__ch, __locale);
	return __libc_unicode_ispunct(__uni);
#else /* __CRT_HAVE__mbctouni_l && __CRT_HAVE___unicode_descriptor */
	if (__ch <= 0xff)
		return (__NAMESPACE_LOCAL_SYM __localdep__ismbbpunct_l)(__ch, __locale);
	return 0;
#endif /* !__CRT_HAVE__mbctouni_l || !__CRT_HAVE___unicode_descriptor */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__ismbcpunct_l_defined
#define __local___localdep__ismbcpunct_l_defined
#define __localdep__ismbcpunct_l __LIBC_LOCAL_NAME(_ismbcpunct_l)
#endif /* !__local___localdep__ismbcpunct_l_defined */
#else /* (__CRT_HAVE__mbctouni_l && __CRT_HAVE___unicode_descriptor) || __CRT_HAVE__ismbbpunct_l || __CRT_HAVE__ismbbkpunct_l || __CRT_HAVE__mbctype || __CRT_HAVE___p__mbctype */
#undef __local__ismbcpunct_l_defined
#endif /* (!__CRT_HAVE__mbctouni_l || !__CRT_HAVE___unicode_descriptor) && !__CRT_HAVE__ismbbpunct_l && !__CRT_HAVE__ismbbkpunct_l && !__CRT_HAVE__mbctype && !__CRT_HAVE___p__mbctype */
#endif /* !__local__ismbcpunct_l_defined */
