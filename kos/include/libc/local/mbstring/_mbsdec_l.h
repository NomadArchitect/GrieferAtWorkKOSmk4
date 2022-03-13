/* HASH CRC-32:0x6023f631 */
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
#ifndef __local__mbsdec_l_defined
#define __local__mbsdec_l_defined
#include <__crt.h>
#if defined(__CRT_HAVE__mbsinc_l) || defined(__CRT_HAVE__ismbblead_l)
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__mbsinc_l_defined
#define __local___localdep__mbsinc_l_defined
#ifdef __CRT_HAVE__mbsinc_l
__CREDIRECT(__ATTR_RETNONNULL __ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,__localdep__mbsinc_l,(unsigned char const *__ptr, __locale_t __locale),_mbsinc_l,(__ptr,__locale))
#elif defined(__CRT_HAVE__ismbblead_l)
__NAMESPACE_LOCAL_END
#include <libc/local/mbstring/_mbsinc_l.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__mbsinc_l __LIBC_LOCAL_NAME(_mbsinc_l)
#else /* ... */
#undef __local___localdep__mbsinc_l_defined
#endif /* !... */
#endif /* !__local___localdep__mbsinc_l_defined */
__LOCAL_LIBC(_mbsdec_l) __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) unsigned char *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_mbsdec_l))(unsigned char const *__start, unsigned char const *__pos, __locale_t __locale) {
	unsigned char const *__iter;
	if (__start >= __pos)
		return __NULLPTR;
	__iter = __start;
	for (;;) {
		unsigned char const *__next;
		__next = (__NAMESPACE_LOCAL_SYM __localdep__mbsinc_l)(__iter, __locale);
		if (__next >= __pos)
			break;
		__iter = __next;
	}
	return (unsigned char *)__iter;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__mbsdec_l_defined
#define __local___localdep__mbsdec_l_defined
#define __localdep__mbsdec_l __LIBC_LOCAL_NAME(_mbsdec_l)
#endif /* !__local___localdep__mbsdec_l_defined */
#else /* __CRT_HAVE__mbsinc_l || __CRT_HAVE__ismbblead_l */
#undef __local__mbsdec_l_defined
#endif /* !__CRT_HAVE__mbsinc_l && !__CRT_HAVE__ismbblead_l */
#endif /* !__local__mbsdec_l_defined */
