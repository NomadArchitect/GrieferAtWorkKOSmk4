/* HASH CRC-32:0x52dc2a53 */
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
#ifndef __local_fminmagl_defined
#define __local_fminmagl_defined
#include <__crt.h>
#ifdef __CRT_HAVE_fminmag
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_fminmag_defined
#define __local___localdep_fminmag_defined
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,double,__NOTHROW_NCX,__localdep_fminmag,(double __x, double __y),fminmag,(__x,__y))
#endif /* !__local___localdep_fminmag_defined */
__LOCAL_LIBC(fminmagl) __ATTR_CONST __ATTR_WUNUSED __LONGDOUBLE
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(fminmagl))(__LONGDOUBLE __x, __LONGDOUBLE __y) {
	return (__LONGDOUBLE)(__NAMESPACE_LOCAL_SYM __localdep_fminmag)((double)__x, (double)__y);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_fminmagl_defined
#define __local___localdep_fminmagl_defined
#define __localdep_fminmagl __LIBC_LOCAL_NAME(fminmagl)
#endif /* !__local___localdep_fminmagl_defined */
#else /* __CRT_HAVE_fminmag */
#undef __local_fminmagl_defined
#endif /* !__CRT_HAVE_fminmag */
#endif /* !__local_fminmagl_defined */
