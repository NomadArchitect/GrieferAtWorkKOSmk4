/* HASH CRC-32:0x2a1ace86 */
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
#ifndef __local_wctrans_l_defined
#define __local_wctrans_l_defined
#include <__crt.h>
#if defined(__CRT_HAVE_wctrans) || defined(__CRT_KOS)
#include <bits/crt/wctype.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_wctrans_defined
#define __local___localdep_wctrans_defined
#ifdef __CRT_HAVE_wctrans
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1),__wctrans_t,__NOTHROW_NCX,__localdep_wctrans,(char const *__prop),wctrans,(__prop))
#elif defined(__CRT_KOS)
__NAMESPACE_LOCAL_END
#include <libc/local/wctype/wctrans.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_wctrans __LIBC_LOCAL_NAME(wctrans)
#else /* ... */
#undef __local___localdep_wctrans_defined
#endif /* !... */
#endif /* !__local___localdep_wctrans_defined */
__LOCAL_LIBC(wctrans_l) __ATTR_WUNUSED __ATTR_IN(1) __wctrans_t
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(wctrans_l))(char const *__prop, __locale_t __locale) {
	__COMPILER_IMPURE();
	(void)__locale;
	return (__NAMESPACE_LOCAL_SYM __localdep_wctrans)(__prop);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_wctrans_l_defined
#define __local___localdep_wctrans_l_defined
#define __localdep_wctrans_l __LIBC_LOCAL_NAME(wctrans_l)
#endif /* !__local___localdep_wctrans_l_defined */
#else /* __CRT_HAVE_wctrans || __CRT_KOS */
#undef __local_wctrans_l_defined
#endif /* !__CRT_HAVE_wctrans && !__CRT_KOS */
#endif /* !__local_wctrans_l_defined */
