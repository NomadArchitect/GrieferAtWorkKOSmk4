/* HASH CRC-32:0x99d808c0 */
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
#ifndef __local__lrotr_defined
#define __local__lrotr_defined 1
#include <hybrid/__rotate.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(_lrotr) __ATTR_CONST unsigned long
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(_lrotr))(unsigned long __val,
                                                int __shift) {
#line 2845 "kos/src/libc/magic/stdlib.c"
	return __hybrid_ror(__val, __shift);
}
__NAMESPACE_LOCAL_END
#endif /* !__local__lrotr_defined */
