/* HASH CRC-32:0x17d1d045 */
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
#ifndef __local_nextdownf_defined
#define __local_nextdownf_defined
#include <__crt.h>
#ifdef __CRT_HAVE_nextdown
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_nextdown_defined
#define __local___localdep_nextdown_defined
__CREDIRECT(__ATTR_WUNUSED,double,__NOTHROW_NCX,__localdep_nextdown,(double __x),nextdown,(__x))
#endif /* !__local___localdep_nextdown_defined */
__LOCAL_LIBC(nextdownf) __ATTR_WUNUSED float
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(nextdownf))(float __x) {
	return (float)(__NAMESPACE_LOCAL_SYM __localdep_nextdown)((double)__x);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_nextdownf_defined
#define __local___localdep_nextdownf_defined
#define __localdep_nextdownf __LIBC_LOCAL_NAME(nextdownf)
#endif /* !__local___localdep_nextdownf_defined */
#else /* __CRT_HAVE_nextdown */
#undef __local_nextdownf_defined
#endif /* !__CRT_HAVE_nextdown */
#endif /* !__local_nextdownf_defined */
