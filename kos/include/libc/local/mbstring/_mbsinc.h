/* HASH CRC-32:0xbc59f48b */
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
#ifndef __local__mbsinc_defined
#define __local__mbsinc_defined
#include <__crt.h>
#ifdef __CRT_HAVE__mbsinc_l
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__mbsinc_l_defined
#define __local___localdep__mbsinc_l_defined
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),unsigned char *,__NOTHROW_NCX,__localdep__mbsinc_l,(unsigned char const *__ptr, __locale_t __locale),_mbsinc_l,(__ptr,__locale))
#endif /* !__local___localdep__mbsinc_l_defined */
__LOCAL_LIBC(_mbsinc) __ATTR_WUNUSED __ATTR_NONNULL((1)) unsigned char *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_mbsinc))(unsigned char const *__ptr) {
	return (__NAMESPACE_LOCAL_SYM __localdep__mbsinc_l)(__ptr, __NULLPTR);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__mbsinc_defined
#define __local___localdep__mbsinc_defined
#define __localdep__mbsinc __LIBC_LOCAL_NAME(_mbsinc)
#endif /* !__local___localdep__mbsinc_defined */
#else /* __CRT_HAVE__mbsinc_l */
#undef __local__mbsinc_defined
#endif /* !__CRT_HAVE__mbsinc_l */
#endif /* !__local__mbsinc_defined */