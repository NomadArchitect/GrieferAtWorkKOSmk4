/* HASH CRC-32:0x38988e08 */
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
#ifndef __local_fmax_defined
#define __local_fmax_defined
#include <__crt.h>
#include <ieee754.h>
#include <libm/fcomp.h>
#include <libm/isnan.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(fmax) __ATTR_CONST __ATTR_WUNUSED double
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(fmax))(double __x, double __y) {
#if defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)
	if (__LIBM_MATHFUNI2(isgreaterequal, __x, __y))
		return __x;
	if (__LIBM_MATHFUNI(isnan, __y))
		return __x;
#else /* __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ */
	if (__x >= __y)
		return __x;
#endif /* !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ */
	return __y;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_fmax_defined
#define __local___localdep_fmax_defined
#define __localdep_fmax __LIBC_LOCAL_NAME(fmax)
#endif /* !__local___localdep_fmax_defined */
#endif /* !__local_fmax_defined */
