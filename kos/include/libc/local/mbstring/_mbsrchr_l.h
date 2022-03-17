/* HASH CRC-32:0x9c770488 */
/* Copyright (c) 2019-2022 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2022 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local__mbsrchr_l_defined
#define __local__mbsrchr_l_defined
#include <__crt.h>
#if defined(__CRT_HAVE__ismbblead_l) || defined(__CRT_HAVE__mbctype) || defined(__CRT_HAVE___p__mbctype)
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__ismbblead_l_defined
#define __local___localdep__ismbblead_l_defined
#ifdef __CRT_HAVE__ismbblead_l
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED,int,__NOTHROW_NCX,__localdep__ismbblead_l,(unsigned int __ch, __locale_t __locale),_ismbblead_l,(__ch,__locale))
#elif defined(__CRT_HAVE__mbctype) || defined(__CRT_HAVE___p__mbctype)
__NAMESPACE_LOCAL_END
#include <libc/local/mbctype/_ismbblead_l.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__ismbblead_l __LIBC_LOCAL_NAME(_ismbblead_l)
#else /* ... */
#undef __local___localdep__ismbblead_l_defined
#endif /* !... */
#endif /* !__local___localdep__ismbblead_l_defined */
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(_mbsrchr_l) __ATTR_PURE __ATTR_WUNUSED __ATTR_NONNULL((1)) unsigned char *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_mbsrchr_l))(unsigned char const *__haystack, unsigned int __needle, __locale_t __locale) {
	unsigned char *__result = __NULLPTR;
	for (;;) {
		unsigned char const *__temp;
		__UINT16_TYPE__ __hay;
		__temp = __haystack;
		__hay  = *__haystack++;
		if ((__NAMESPACE_LOCAL_SYM __localdep__ismbblead_l)(__hay, __locale))
			__hay = *__haystack ? (__hay << 8) | *__haystack++ : 0;
		if (__hay == 0)
			break;
		if (__hay == (__UINT16_TYPE__)(unsigned int)__needle)
			__result = (unsigned char *)__temp;
	}
	return __result;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__mbsrchr_l_defined
#define __local___localdep__mbsrchr_l_defined
#define __localdep__mbsrchr_l __LIBC_LOCAL_NAME(_mbsrchr_l)
#endif /* !__local___localdep__mbsrchr_l_defined */
#else /* __CRT_HAVE__ismbblead_l || __CRT_HAVE__mbctype || __CRT_HAVE___p__mbctype */
#undef __local__mbsrchr_l_defined
#endif /* !__CRT_HAVE__ismbblead_l && !__CRT_HAVE__mbctype && !__CRT_HAVE___p__mbctype */
#endif /* !__local__mbsrchr_l_defined */