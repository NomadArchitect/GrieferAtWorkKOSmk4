/* HASH CRC-32:0xd9fede7 */
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
 *    in a product, an acknowledgement in the product documentation would be  *
 *    appreciated but is not required.                                        *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local__ultow_defined
#define __local__ultow_defined 1
/* Dependency: "_ultow_s" from "stdlib" */
#ifndef ____localdep__ultow_s_defined
#define ____localdep__ultow_s_defined 1
#ifdef __CRT_HAVE__ultow_s
__CREDIRECT(,__errno_t,__NOTHROW_NCX,__localdep__ultow_s,(unsigned long __val, __WCHAR_TYPE__ *__buf, __SIZE_TYPE__ __buflen, int __radix),_ultow_s,(__val,__buf,__buflen,__radix))
#else /* LIBC: _ultow_s */
#include <local/stdlib/_ultow_s.h>
#define __localdep__ultow_s (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ultow_s))
#endif /* _ultow_s... */
#endif /* !____localdep__ultow_s_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(_ultow) __ATTR_NONNULL((2)) __WCHAR_TYPE__ *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_ultow))(unsigned long __val,
                                                    __WCHAR_TYPE__ *__buf,
                                                    int __radix) {
#line 3126 "kos/src/libc/magic/stdlib.c"
	__localdep__ultow_s(__val, __buf, (__SIZE_TYPE__)-1, __radix);
	return __buf;
}
__NAMESPACE_LOCAL_END
#endif /* !__local__ultow_defined */
