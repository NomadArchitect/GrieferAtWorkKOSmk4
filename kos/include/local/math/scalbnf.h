/* HASH CRC-32:0x2a71bde8 */
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
#ifndef __local_scalbnf_defined
#include <ieee754.h>
#if defined(__IEEE754_FLOAT_TYPE_IS_FLOAT__) || defined(__IEEE754_DOUBLE_TYPE_IS_FLOAT__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) || defined(__CRT_HAVE_scalbn) || defined(__CRT_HAVE___scalbn) || (defined(__CRT_HAVE_scalbln) && __SIZEOF_INT__ == __SIZEOF_LONG__) || (defined(__CRT_HAVE___scalbln) && __SIZEOF_INT__ == __SIZEOF_LONG__)
#define __local_scalbnf_defined 1
#include <libm/scalbn.h>
/* Dependency: "scalbn" from "math" */
#ifndef ____localdep_scalbn_defined
#define ____localdep_scalbn_defined 1
#if __has_builtin(__builtin_scalbn) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_scalbn)
/* Return X times (2 to the Nth power) */
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,double,__NOTHROW,__localdep_scalbn,(double __x, int __n),scalbn,{ return __builtin_scalbn(__x, __n); })
#elif defined(__CRT_HAVE_scalbn)
/* Return X times (2 to the Nth power) */
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,double,__NOTHROW,__localdep_scalbn,(double __x, int __n),scalbn,(__x,__n))
#elif defined(__CRT_HAVE___scalbn)
/* Return X times (2 to the Nth power) */
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,double,__NOTHROW,__localdep_scalbn,(double __x, int __n),__scalbn,(__x,__n))
#elif defined(__CRT_HAVE_scalbln) && (__SIZEOF_INT__ == __SIZEOF_LONG__)
/* Return X times (2 to the Nth power) */
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,double,__NOTHROW,__localdep_scalbn,(double __x, int __n),scalbln,(__x,__n))
#elif defined(__CRT_HAVE___scalbln) && (__SIZEOF_INT__ == __SIZEOF_LONG__)
/* Return X times (2 to the Nth power) */
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,double,__NOTHROW,__localdep_scalbn,(double __x, int __n),__scalbln,(__x,__n))
#else /* LIBC: scalbn */
#include <ieee754.h>
#if defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)
#include <local/math/scalbn.h>
/* Return X times (2 to the Nth power) */
#define __localdep_scalbn (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(scalbn))
#else /* CUSTOM: scalbn */
#undef ____localdep_scalbn_defined
#endif /* scalbn... */
#endif /* scalbn... */
#endif /* !____localdep_scalbn_defined */

__NAMESPACE_LOCAL_BEGIN
/* Return X times (2 to the Nth power) */
__LOCAL_LIBC(scalbnf) __ATTR_CONST __ATTR_WUNUSED float
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(scalbnf))(float __x,
                                                 int __n) {
#line 1598 "kos/src/libc/magic/math.c"
#ifdef __IEEE754_FLOAT_TYPE_IS_FLOAT__
	return (float)__ieee754_scalbnf((__IEEE754_FLOAT_TYPE__)__x, __n);
#elif defined(__IEEE754_DOUBLE_TYPE_IS_FLOAT__)
	return (float)__ieee754_scalbn((__IEEE754_DOUBLE_TYPE__)__x, __n);
#elif defined(__IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__)
	return (float)__ieee854_scalbnl((__IEEE854_LONG_DOUBLE_TYPE__)__x, __n);
#else /* ... */
	return (float)__localdep_scalbn((double)__x, __n);
#endif /* !... */
}
__NAMESPACE_LOCAL_END
#endif /* __IEEE754_FLOAT_TYPE_IS_FLOAT__ || __IEEE754_DOUBLE_TYPE_IS_FLOAT__ || __IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__ || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ || __CRT_HAVE_scalbn || __CRT_HAVE___scalbn || (__CRT_HAVE_scalbln && __SIZEOF_INT__ == __SIZEOF_LONG__) || (__CRT_HAVE___scalbln && __SIZEOF_INT__ == __SIZEOF_LONG__) */
#endif /* !__local_scalbnf_defined */
