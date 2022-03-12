/* HASH CRC-32:0x98412263 */
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
#ifndef __local__mbccpy_s_defined
#define __local__mbccpy_s_defined
#include <__crt.h>
#ifdef __CRT_HAVE__mbccpy_s_l
#include <hybrid/typecore.h>
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__mbccpy_s_l_defined
#define __local___localdep__mbccpy_s_l_defined
__CREDIRECT(__ATTR_NONNULL((1, 4)),__errno_t,__NOTHROW_NCX,__localdep__mbccpy_s_l,(unsigned char *__buf, __SIZE_TYPE__ __bufsize, int *__p_copied, unsigned char const *__src, __locale_t __locale),_mbccpy_s_l,(__buf,__bufsize,__p_copied,__src,__locale))
#endif /* !__local___localdep__mbccpy_s_l_defined */
__LOCAL_LIBC(_mbccpy_s) __ATTR_NONNULL((1, 4)) __errno_t
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_mbccpy_s))(unsigned char *__buf, __SIZE_TYPE__ __bufsize, int *__p_copied, unsigned char const *__src) {
	return (__NAMESPACE_LOCAL_SYM __localdep__mbccpy_s_l)(__buf, __bufsize, __p_copied, __src, __NULLPTR);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__mbccpy_s_defined
#define __local___localdep__mbccpy_s_defined
#define __localdep__mbccpy_s __LIBC_LOCAL_NAME(_mbccpy_s)
#endif /* !__local___localdep__mbccpy_s_defined */
#else /* __CRT_HAVE__mbccpy_s_l */
#undef __local__mbccpy_s_defined
#endif /* !__CRT_HAVE__mbccpy_s_l */
#endif /* !__local__mbccpy_s_defined */