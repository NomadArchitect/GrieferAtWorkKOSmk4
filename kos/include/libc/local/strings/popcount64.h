/* HASH CRC-32:0xd4738337 */
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
#ifndef __local_popcount64_defined
#define __local_popcount64_defined
#include <__crt.h>
#include <hybrid/__bit.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(popcount64) __ATTR_CONST __ATTR_WUNUSED unsigned int
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(popcount64))(__UINT64_TYPE__ __i) {
	return __hybrid_popcount(__i);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_popcount64_defined
#define __local___localdep_popcount64_defined
#define __localdep_popcount64 __LIBC_LOCAL_NAME(popcount64)
#endif /* !__local___localdep_popcount64_defined */
#endif /* !__local_popcount64_defined */
