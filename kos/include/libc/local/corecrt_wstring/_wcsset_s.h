/* HASH CRC-32:0x3e138f39 */
/* Copyright (c) 2019-2023 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2023 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local__wcsset_s_defined
#define __local__wcsset_s_defined
#include <__crt.h>
#include <bits/types.h>
#include <hybrid/typecore.h>
#include <libc/errno.h>
#include <libc/string.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(_wcsset_s) __ATTR_INOUTS(1, 2) __errno_t
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_wcsset_s))(__WCHAR_TYPE__ *__dst, __SIZE_TYPE__ __dstsize, __WCHAR_TYPE__ __ch) {
	__WCHAR_TYPE__ *__p;
	__SIZE_TYPE__ __remaining;
	if (!__dst && __dstsize != 0)
		return 22;
	__p = __dst;
	__remaining = __dstsize;
	while (*__p && --__remaining != 0)
		*__p++ = (__WCHAR_TYPE__)__ch;
	if (__remaining == 0) {
		__libc_memsetc(__dst, 0, __dstsize, __SIZEOF_WCHAR_T__);
		return 22;
	}
	__libc_memsetc(__p, 0, __remaining, __SIZEOF_WCHAR_T__);
	return 0;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__wcsset_s_defined
#define __local___localdep__wcsset_s_defined
#define __localdep__wcsset_s __LIBC_LOCAL_NAME(_wcsset_s)
#endif /* !__local___localdep__wcsset_s_defined */
#endif /* !__local__wcsset_s_defined */
