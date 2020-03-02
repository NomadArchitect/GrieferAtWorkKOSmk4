/* HASH CRC-32:0x445ed050 */
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
#ifndef __local_fmodl_defined
#include <ieee754.h>
#if defined(__IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) || defined(__CRT_HAVE_fmod) || defined(__CRT_HAVE___fmod)
#define __local_fmodl_defined 1
#include <libm/isinf.h>

#include <libm/fcomp.h>

#include <libm/matherr.h>

#include <libm/fmod.h>
/* Dependency: "fmod" from "math" */
#ifndef ____localdep_fmod_defined
#define ____localdep_fmod_defined 1
#if __has_builtin(__builtin_fmod) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_fmod)
/* Floating-point modulo remainder of X/Y */
__CEIREDIRECT(__ATTR_WUNUSED,double,__NOTHROW,__localdep_fmod,(double __x, double __y),fmod,{ return __builtin_fmod(__x, __y); })
#elif defined(__CRT_HAVE_fmod)
/* Floating-point modulo remainder of X/Y */
__CREDIRECT(__ATTR_WUNUSED,double,__NOTHROW,__localdep_fmod,(double __x, double __y),fmod,(__x,__y))
#elif defined(__CRT_HAVE___fmod)
/* Floating-point modulo remainder of X/Y */
__CREDIRECT(__ATTR_WUNUSED,double,__NOTHROW,__localdep_fmod,(double __x, double __y),__fmod,(__x,__y))
#else /* LIBC: fmod */
#include <ieee754.h>
#if defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)
#include <local/math/fmod.h>
/* Floating-point modulo remainder of X/Y */
#define __localdep_fmod (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fmod))
#else /* CUSTOM: fmod */
#undef ____localdep_fmod_defined
#endif /* fmod... */
#endif /* fmod... */
#endif /* !____localdep_fmod_defined */

__NAMESPACE_LOCAL_BEGIN
/* Floating-point modulo remainder of X/Y */
__LOCAL_LIBC(fmodl) __ATTR_CONST __ATTR_WUNUSED __LONGDOUBLE
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(fmodl))(__LONGDOUBLE __x,
                                               __LONGDOUBLE __y) {
#line 708 "kos/src/libc/magic/math.c"
#ifdef __LIBM_MATHFUN2L
	if (__LIBM_LIB_VERSION != __LIBM_IEEE &&
	    (__LIBM_MATHFUNL(isinf, __x) || __y == 0.0L) &&
	    !__LIBM_MATHFUN2L(isunordered, __x, __y))
		return __kernel_standard_l(__x, __y, __y, __LIBM_KMATHERR_FMOD); /* fmod(+-Inf,y) or fmod(x,0) */
	return __LIBM_MATHFUN2L(fmod, __x, __y);
#else /* __LIBM_MATHFUN2L */
	return (__LONGDOUBLE)__localdep_fmod((double)__x, (double)__y);
#endif /* !__LIBM_MATHFUN2L */
}
__NAMESPACE_LOCAL_END
#endif /* __IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__ || __IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__ || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ || __CRT_HAVE_fmod || __CRT_HAVE___fmod */
#endif /* !__local_fmodl_defined */
