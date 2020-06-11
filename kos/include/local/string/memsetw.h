/* HASH CRC-32:0xd3c8561c */
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
#ifndef __local_memsetw_defined
#define __local_memsetw_defined 1
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
/* Fill memory with a given word */
__LOCAL_LIBC(memsetw) __ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1)) __UINT16_TYPE__ *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(memsetw))(void *__restrict __dst, __UINT16_TYPE__ __word, __SIZE_TYPE__ __n_words) {
	__UINT16_TYPE__ *__pdst = (__UINT16_TYPE__ *)__dst;
	while (__n_words--)
		*__pdst++ = __word;
	return (__UINT16_TYPE__ *)__dst;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_memsetw_defined
#define __local___localdep_memsetw_defined 1
#define __localdep_memsetw __LIBC_LOCAL_NAME(memsetw)
#endif /* !__local___localdep_memsetw_defined */
#endif /* !__local_memsetw_defined */
