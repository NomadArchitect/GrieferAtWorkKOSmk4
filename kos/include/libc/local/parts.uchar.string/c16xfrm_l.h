/* HASH CRC-32:0x59f4c729 */
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
#ifndef __local_c16xfrm_l_defined
#define __local_c16xfrm_l_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_c16xfrm_defined
#define __local___localdep_c16xfrm_defined
#if defined(__CRT_HAVE_wcsxfrm) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_INS(2, 3) __ATTR_OUTS(1, 3),__SIZE_TYPE__,__NOTHROW_NCX,__localdep_c16xfrm,(__CHAR16_TYPE__ *__dst, __CHAR16_TYPE__ const *__restrict __src, __SIZE_TYPE__ __buflen),wcsxfrm,(__dst,__src,__buflen))
#elif defined(__CRT_HAVE_DOS$wcsxfrm)
__CREDIRECT_DOS(__ATTR_INS(2, 3) __ATTR_OUTS(1, 3),__SIZE_TYPE__,__NOTHROW_NCX,__localdep_c16xfrm,(__CHAR16_TYPE__ *__dst, __CHAR16_TYPE__ const *__restrict __src, __SIZE_TYPE__ __buflen),wcsxfrm,(__dst,__src,__buflen))
#elif __SIZEOF_WCHAR_T__ == 2
__NAMESPACE_LOCAL_END
#include <libc/local/wchar/wcsxfrm.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c16xfrm __NAMESPACE_LOCAL_TYPEHAX(__SIZE_TYPE__(__LIBDCALL*)(__CHAR16_TYPE__ *,__CHAR16_TYPE__ const *__restrict,__SIZE_TYPE__),__SIZE_TYPE__(__LIBDCALL&)(__CHAR16_TYPE__ *,__CHAR16_TYPE__ const *__restrict,__SIZE_TYPE__),wcsxfrm)
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/parts.uchar.string/c16xfrm.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c16xfrm __LIBC_LOCAL_NAME(c16xfrm)
#endif /* !... */
#endif /* !__local___localdep_c16xfrm_defined */
__LOCAL_LIBC(c16xfrm_l) __ATTR_INS(2, 3) __ATTR_OUTS(1, 3) __SIZE_TYPE__
__NOTHROW_NCX(__LIBDCALL __LIBC_LOCAL_NAME(c16xfrm_l))(__CHAR16_TYPE__ *__dst, __CHAR16_TYPE__ const *__restrict __src, __SIZE_TYPE__ __buflen, __locale_t __locale) {
	(void)__locale;
	return (__NAMESPACE_LOCAL_SYM __localdep_c16xfrm)(__dst, __src, __buflen);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_c16xfrm_l_defined
#define __local___localdep_c16xfrm_l_defined
#define __localdep_c16xfrm_l __LIBC_LOCAL_NAME(c16xfrm_l)
#endif /* !__local___localdep_c16xfrm_l_defined */
#endif /* !__local_c16xfrm_l_defined */
