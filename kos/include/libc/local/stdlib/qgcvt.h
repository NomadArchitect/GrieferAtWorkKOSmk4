/* HASH CRC-32:0x1c4087ce */
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
#ifndef __local_qgcvt_defined
#define __local_qgcvt_defined
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_sprintf_defined
#define __local___localdep_sprintf_defined
#if __has_builtin(__builtin_sprintf) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_sprintf) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
__CEIREDIRECT(__ATTR_LIBC_PRINTF(2, 3) __ATTR_NONNULL((1, 2)),__STDC_INT_AS_SIZE_T,__NOTHROW_NCX,__localdep_sprintf,(char *__restrict __buf, char const *__restrict __format, ...),sprintf,{ return __builtin_sprintf(__buf, __format, __builtin_va_arg_pack()); })
#elif defined(__CRT_HAVE_sprintf)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
__LIBC __ATTR_LIBC_PRINTF(2, 3) __ATTR_NONNULL((1, 2)) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__VLIBCCALL __localdep_sprintf)(char *__restrict __buf, char const *__restrict __format, ...) __CASMNAME("sprintf");
#elif defined(__CRT_HAVE__IO_sprintf)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
__LIBC __ATTR_LIBC_PRINTF(2, 3) __ATTR_NONNULL((1, 2)) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__VLIBCCALL __localdep_sprintf)(char *__restrict __buf, char const *__restrict __format, ...) __CASMNAME("_IO_sprintf");
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/stdio/sprintf.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_sprintf __LIBC_LOCAL_NAME(sprintf)
#endif /* !... */
#endif /* !__local___localdep_sprintf_defined */
__NAMESPACE_LOCAL_END
#include <hybrid/floatcore.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(qgcvt) __ATTR_NONNULL((3)) char *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(qgcvt))(__LONGDOUBLE __val, int __ndigit, char *__buf) {
#ifndef __LDBG_NDIGIT_MAX
#if __LDBL_MANT_DIG__ == 53
#define __LDBG_NDIGIT_MAX 17
#elif __LDBL_MANT_DIG__ == 24
#define __LDBG_NDIGIT_MAX 9
#elif __LDBL_MANT_DIG__ == 56
#define __LDBG_NDIGIT_MAX 18
#else /* ... */
	/* ceil(M_LN2 / M_LN10 * DBL_MANT_DIG + 1.0) */
#define __LDBG_NDIGIT_MAX (__LDBL_MANT_DIG__ / 4)
#endif /* !... */
#endif /* !__LDBG_NDIGIT_MAX */
	if (__ndigit > __LDBG_NDIGIT_MAX)
		__ndigit = __LDBG_NDIGIT_MAX;
	(__NAMESPACE_LOCAL_SYM __localdep_sprintf)(__buf, "%.*Lg", __ndigit, __val);
	return __buf;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_qgcvt_defined
#define __local___localdep_qgcvt_defined
#define __localdep_qgcvt __LIBC_LOCAL_NAME(qgcvt)
#endif /* !__local___localdep_qgcvt_defined */
#endif /* !__local_qgcvt_defined */
