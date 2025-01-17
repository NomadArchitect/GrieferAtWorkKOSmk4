/* HASH CRC-32:0xdcbd9d94 */
/* Copyright (c) 2019-2025 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2025 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_wcsnchr_defined
#define __local_wcsnchr_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(wcsnchr) __ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_NONNULL((1)) __WCHAR_TYPE__ *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(wcsnchr))(__WCHAR_TYPE__ const *__restrict __haystack, __WCHAR_TYPE__ __needle, __SIZE_TYPE__ __maxlen) {
	for (; __maxlen-- && *__haystack; ++__haystack) {
		if __unlikely((__WCHAR_TYPE__)*__haystack == (__WCHAR_TYPE__)__needle)
			return (__WCHAR_TYPE__ *)__haystack;
	}
	return __NULLPTR;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_wcsnchr_defined
#define __local___localdep_wcsnchr_defined
#define __localdep_wcsnchr __LIBC_LOCAL_NAME(wcsnchr)
#endif /* !__local___localdep_wcsnchr_defined */
#endif /* !__local_wcsnchr_defined */
