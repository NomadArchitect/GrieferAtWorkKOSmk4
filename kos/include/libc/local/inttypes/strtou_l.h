/* HASH CRC-32:0x146e2819 */
/* Copyright (c) 2019-2021 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2021 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_strtou_l_defined
#define __local_strtou_l_defined 1
#include <__crt.h>
#include <features.h>
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: strtou from inttypes */
#ifndef __local___localdep_strtou_defined
#define __local___localdep_strtou_defined 1
#ifdef __CRT_HAVE_strtou
/* >> strtoi(3), strtou(3), strtoi_l(3), strtou_l(3)
 * Safely convert `nptr' to an integer which is then returned.
 * If no integer could be read, set `*rstatus' (if non-`NULL') to `ECANCELED'
 * If non-`NULL', `*endptr' is made to point past the read integer, and if
 * it points to a non-'\0'-character, `*rstatus' (if non-`NULL') to `ENOTSUP'
 * Also make sure that the returned integer lies within the
 * bounds of `[lo,hi]' (inclusively). If it does not, clamp it
 * to those bounds and set `*rstatus' (if non-`NULL') to `ERANGE'
 * @param: lo, hi:  Lo/Hi-bounds for the to-be returned integer.
 * @param: rstatus: When non-`NULL', set to a conversion error (if any) */
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,__localdep_strtou,(char const *__restrict __nptr, char **__restrict __endptr, __STDC_INT_AS_UINT_T __base, __UINTMAX_TYPE__ __lo, __UINTMAX_TYPE__ __hi, __errno_t *__rstatus),strtou,(__nptr,__endptr,__base,__lo,__hi,__rstatus))
#else /* __CRT_HAVE_strtou */
__NAMESPACE_LOCAL_END
#include <libc/local/inttypes/strtou.h>
__NAMESPACE_LOCAL_BEGIN
/* >> strtoi(3), strtou(3), strtoi_l(3), strtou_l(3)
 * Safely convert `nptr' to an integer which is then returned.
 * If no integer could be read, set `*rstatus' (if non-`NULL') to `ECANCELED'
 * If non-`NULL', `*endptr' is made to point past the read integer, and if
 * it points to a non-'\0'-character, `*rstatus' (if non-`NULL') to `ENOTSUP'
 * Also make sure that the returned integer lies within the
 * bounds of `[lo,hi]' (inclusively). If it does not, clamp it
 * to those bounds and set `*rstatus' (if non-`NULL') to `ERANGE'
 * @param: lo, hi:  Lo/Hi-bounds for the to-be returned integer.
 * @param: rstatus: When non-`NULL', set to a conversion error (if any) */
#define __localdep_strtou __LIBC_LOCAL_NAME(strtou)
#endif /* !__CRT_HAVE_strtou */
#endif /* !__local___localdep_strtou_defined */
__NAMESPACE_LOCAL_END
#include <libc/errno.h>
__NAMESPACE_LOCAL_BEGIN
/* >> strtoi(3), strtou(3), strtoi_l(3), strtou_l(3)
 * Safely convert `nptr' to an integer which is then returned.
 * If no integer could be read, set `*rstatus' (if non-`NULL') to `ECANCELED'
 * If non-`NULL', `*endptr' is made to point past the read integer, and if
 * it points to a non-'\0'-character, `*rstatus' (if non-`NULL') to `ENOTSUP'
 * Also make sure that the returned integer lies within the
 * bounds of `[lo,hi]' (inclusively). If it does not, clamp it
 * to those bounds and set `*rstatus' (if non-`NULL') to `ERANGE'
 * @param: lo, hi:  Lo/Hi-bounds for the to-be returned integer.
 * @param: rstatus: When non-`NULL', set to a conversion error (if any) */
__LOCAL_LIBC(strtou_l) __ATTR_LEAF __ATTR_NONNULL((1)) __UINTMAX_TYPE__
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(strtou_l))(char const *__restrict __nptr, char **__restrict __endptr, __STDC_INT_AS_UINT_T __base, __UINTMAX_TYPE__ __lo, __UINTMAX_TYPE__ __hi, __errno_t *__rstatus, __locale_t __locale) {
	(void)__locale;
	return __localdep_strtou(__nptr, __endptr, __base, __lo, __hi, __rstatus);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_strtou_l_defined
#define __local___localdep_strtou_l_defined 1
#define __localdep_strtou_l __LIBC_LOCAL_NAME(strtou_l)
#endif /* !__local___localdep_strtou_l_defined */
#endif /* !__local_strtou_l_defined */