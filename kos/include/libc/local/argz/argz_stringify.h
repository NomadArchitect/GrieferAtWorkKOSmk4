/* HASH CRC-32:0xa00f2c56 */
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
#ifndef __local_argz_stringify_defined
#define __local_argz_stringify_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_strlen_defined
#define __local___localdep_strlen_defined
#ifdef __CRT_HAVE_strlen
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1),__SIZE_TYPE__,__NOTHROW_NCX,__localdep_strlen,(char const *__restrict __str),strlen,(__str))
#else /* __CRT_HAVE_strlen */
__NAMESPACE_LOCAL_END
#include <libc/local/string/strlen.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_strlen __LIBC_LOCAL_NAME(strlen)
#endif /* !__CRT_HAVE_strlen */
#endif /* !__local___localdep_strlen_defined */
__LOCAL_LIBC(argz_stringify) __ATTR_INOUTS(1, 2) void
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(argz_stringify))(char *__argz, __SIZE_TYPE__ __len, int __sep) {
	/* replace(base: argz, count: len - 1, old: '\0', new: sep); */
	if __unlikely(!__len)
		return;
	for (;;) {
		__SIZE_TYPE__ __temp;
		__temp = (__NAMESPACE_LOCAL_SYM __localdep_strlen)(__argz) + 1;
		if (__temp >= __len)
			break;
		__len  -= __temp;
		__argz += __temp;
		__argz[-1] = (char)(unsigned char)(unsigned int)__sep;
	}
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_argz_stringify_defined
#define __local___localdep_argz_stringify_defined
#define __localdep_argz_stringify __LIBC_LOCAL_NAME(argz_stringify)
#endif /* !__local___localdep_argz_stringify_defined */
#endif /* !__local_argz_stringify_defined */
