/* HASH CRC-32:0xb470721 */
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
#ifndef __local_memset_defined
#define __local_memset_defined 1
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
/* Fill memory with a given byte
 * @return: * : Always re-returns `dst' */
__LOCAL_LIBC(memset) __ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1)) void *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(memset))(void *__restrict __dst, int __byte, __SIZE_TYPE__ __n_bytes) {
	__BYTE_TYPE__ *__pdst = (__BYTE_TYPE__ *)__dst;
	while (__n_bytes--)
		*__pdst++ = (__BYTE_TYPE__)__byte;
	return __dst;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_memset_defined
#define __local___localdep_memset_defined 1
#define __localdep_memset __LIBC_LOCAL_NAME(memset)
#endif /* !__local___localdep_memset_defined */
#endif /* !__local_memset_defined */
