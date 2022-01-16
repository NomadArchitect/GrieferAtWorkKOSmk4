/* HASH CRC-32:0x53f756ca */
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
#ifndef __local__lrotl_defined
#define __local__lrotl_defined
#include <__crt.h>
#include <hybrid/__rotate.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(_lrotl) __ATTR_CONST unsigned long
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(_lrotl))(unsigned long __val, int __shift) {
	return __hybrid_rol(__val, (__SHIFT_TYPE__)(unsigned int)__shift);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__lrotl_defined
#define __local___localdep__lrotl_defined
#define __localdep__lrotl __LIBC_LOCAL_NAME(_lrotl)
#endif /* !__local___localdep__lrotl_defined */
#endif /* !__local__lrotl_defined */
