/* HASH CRC-32:0x8e704038 */
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
#ifndef __local_wcsnset_defined
#define __local_wcsnset_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(wcsnset) __ATTR_RETNONNULL __ATTR_INOUTS(1, 3) __WCHAR_TYPE__ *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(wcsnset))(__WCHAR_TYPE__ *__restrict __str, __WCHAR_TYPE__ __ch, __SIZE_TYPE__ __maxlen) {
	__WCHAR_TYPE__ *__iter;
	for (__iter = __str; __maxlen-- && *__iter; ++__iter)
		*__iter = (__WCHAR_TYPE__)__ch;
	return __str;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_wcsnset_defined
#define __local___localdep_wcsnset_defined
#define __localdep_wcsnset __LIBC_LOCAL_NAME(wcsnset)
#endif /* !__local___localdep_wcsnset_defined */
#endif /* !__local_wcsnset_defined */
