/* HASH CRC-32:0xc788ef09 */
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
#ifndef __local_log1pf_defined
#define __local_log1pf_defined
#include <__crt.h>
#if defined(__CRT_HAVE_log1p) || defined(__CRT_HAVE___log1p)
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_log1p_defined
#define __local___localdep_log1p_defined
#if __has_builtin(__builtin_log1p) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_log1p)
__CEIREDIRECT(__ATTR_WUNUSED,double,__NOTHROW,__localdep_log1p,(double __x),log1p,{ return __builtin_log1p(__x); })
#elif defined(__CRT_HAVE_log1p)
__CREDIRECT(__ATTR_WUNUSED,double,__NOTHROW,__localdep_log1p,(double __x),log1p,(__x))
#elif defined(__CRT_HAVE___log1p)
__CREDIRECT(__ATTR_WUNUSED,double,__NOTHROW,__localdep_log1p,(double __x),__log1p,(__x))
#else /* ... */
#undef __local___localdep_log1p_defined
#endif /* !... */
#endif /* !__local___localdep_log1p_defined */
__LOCAL_LIBC(log1pf) __ATTR_WUNUSED float
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(log1pf))(float __x) {
	return (float)(__NAMESPACE_LOCAL_SYM __localdep_log1p)((double)__x);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_log1pf_defined
#define __local___localdep_log1pf_defined
#define __localdep_log1pf __LIBC_LOCAL_NAME(log1pf)
#endif /* !__local___localdep_log1pf_defined */
#else /* __CRT_HAVE_log1p || __CRT_HAVE___log1p */
#undef __local_log1pf_defined
#endif /* !__CRT_HAVE_log1p && !__CRT_HAVE___log1p */
#endif /* !__local_log1pf_defined */
