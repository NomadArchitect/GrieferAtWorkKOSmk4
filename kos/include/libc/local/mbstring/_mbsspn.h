/* HASH CRC-32:0x11ba7b6f */
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
#ifndef __local__mbsspn_defined
#define __local__mbsspn_defined
#include <__crt.h>
#ifdef __CRT_HAVE__mbsspn_l
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__mbsspn_l_defined
#define __local___localdep__mbsspn_l_defined
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),__SIZE_TYPE__,__NOTHROW_NCX,__localdep__mbsspn_l,(unsigned char const *__haystack, unsigned char const *__accept, __locale_t __locale),_mbsspn_l,(__haystack,__accept,__locale))
#endif /* !__local___localdep__mbsspn_l_defined */
__LOCAL_LIBC(_mbsspn) __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) __SIZE_TYPE__
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_mbsspn))(unsigned char const *__haystack, unsigned char const *__accept) {
	return (__NAMESPACE_LOCAL_SYM __localdep__mbsspn_l)(__haystack, __accept, __NULLPTR);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__mbsspn_defined
#define __local___localdep__mbsspn_defined
#define __localdep__mbsspn __LIBC_LOCAL_NAME(_mbsspn)
#endif /* !__local___localdep__mbsspn_defined */
#else /* __CRT_HAVE__mbsspn_l */
#undef __local__mbsspn_defined
#endif /* !__CRT_HAVE__mbsspn_l */
#endif /* !__local__mbsspn_defined */