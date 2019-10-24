/* HASH CRC-32:0x254cd1ed */
/* Copyright (c) 2019 Griefer@Work                                            *
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
#ifndef __local_memrevl_defined
#define __local_memrevl_defined 1
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(memrevl) __ATTR_RETNONNULL __ATTR_NONNULL((1)) __UINT32_TYPE__ *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(memrevl))(void *__restrict __base,
                                                     __SIZE_TYPE__ __n_dwords) {
#line 4199 "kos/src/libc/magic/string.c"
	__UINT32_TYPE__ *__iter, *__end;
	__end = (__iter = (__UINT32_TYPE__ *)__base) + __n_dwords;
	while (__iter < __end) {
		__UINT32_TYPE__ __temp = *__iter;
		*__iter++ = *--__end;
		*__end = __temp;
	}
	return (__UINT32_TYPE__ *)__base;
}
__NAMESPACE_LOCAL_END
#endif /* !__local_memrevl_defined */
