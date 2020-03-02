/* HASH CRC-32:0xda24ec73 */
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
 *    in a product, an acknowledgement (see the following) in the product     *
 *    documentation is required:                                              *
 *    Portions Copyright (c) 2019-2020 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_truncf_defined
#define __local_truncf_defined 1
#include <hybrid/typecore.h>

#include <libm/trunc.h>
/* Dependency: "trunc" from "math" */
#ifndef ____localdep_trunc_defined
#define ____localdep_trunc_defined 1
#if __has_builtin(__builtin_trunc) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_trunc)
/* Round X to the integral value in floating-point
 * format nearest but not larger in magnitude */
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,double,__NOTHROW,__localdep_trunc,(double __x),trunc,{ return __builtin_trunc(__x); })
#elif defined(__CRT_HAVE_trunc)
/* Round X to the integral value in floating-point
 * format nearest but not larger in magnitude */
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,double,__NOTHROW,__localdep_trunc,(double __x),trunc,(__x))
#elif defined(__CRT_HAVE___trunc)
/* Round X to the integral value in floating-point
 * format nearest but not larger in magnitude */
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,double,__NOTHROW,__localdep_trunc,(double __x),__trunc,(__x))
#else /* LIBC: trunc */
#include <local/math/trunc.h>
/* Round X to the integral value in floating-point
 * format nearest but not larger in magnitude */
#define __localdep_trunc (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(trunc))
#endif /* trunc... */
#endif /* !____localdep_trunc_defined */

__NAMESPACE_LOCAL_BEGIN
/* Round X to the integral value in floating-point
 * format nearest but not larger in magnitude */
__LOCAL_LIBC(truncf) __ATTR_CONST __ATTR_WUNUSED float
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(truncf))(float __x) {
#line 1109 "kos/src/libc/magic/math.c"
#ifdef __LIBM_MATHFUNF
	#ifdef __LIBM_MATHFUNF
	return __LIBM_MATHFUNF(trunc, __x);
#else /* __LIBM_MATHFUN */
	return (float)(__INTMAX_TYPE__)__x;
#endif /* !__LIBM_MATHFUN */
#else /* __LIBM_MATHFUNF */
	return (float)__localdep_trunc((double)__x);
#endif /* !__LIBM_MATHFUNF */
}
__NAMESPACE_LOCAL_END
#endif /* !__local_truncf_defined */
