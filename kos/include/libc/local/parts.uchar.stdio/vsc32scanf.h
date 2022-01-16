/* HASH CRC-32:0x9b93f85d */
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
#ifndef __local_vsc32scanf_defined
#define __local_vsc32scanf_defined
#include <__crt.h>
#include <features.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(vsc32scanf) __ATTR_WUNUSED __ATTR_LIBC_WSCANF(2, 0) __ATTR_NONNULL((1, 2)) __STDC_INT_AS_SIZE_T
__NOTHROW_NCX(__LIBKCALL __LIBC_LOCAL_NAME(vsc32scanf))(__CHAR32_TYPE__ const *__restrict __src, __CHAR32_TYPE__ const *__restrict __format, __builtin_va_list __args) {
	/* TODO: format_wscanf() */
	(void)__src;
	(void)__format;
	(void)__args;
	__COMPILER_IMPURE();
	return 0;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_vsc32scanf_defined
#define __local___localdep_vsc32scanf_defined
#define __localdep_vsc32scanf __LIBC_LOCAL_NAME(vsc32scanf)
#endif /* !__local___localdep_vsc32scanf_defined */
#endif /* !__local_vsc32scanf_defined */
