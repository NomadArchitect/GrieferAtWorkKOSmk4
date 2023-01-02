/* HASH CRC-32:0x48da9efc */
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
#ifndef __local_memeq_nopf_defined
#define __local_memeq_nopf_defined
#include <__crt.h>
#include <kos/bits/nopf.h>
#if defined(__arch_readb_nopf) || defined(__CRT_HAVE_readb_nopf) || defined(__arch_memcpy_nopf) || defined(__CRT_HAVE_memcpy_nopf) || defined(__arch_readw_nopf) || defined(__CRT_HAVE_readw_nopf) || defined(__arch_readl_nopf) || defined(__CRT_HAVE_readl_nopf) || defined(__arch_readq_nopf) || defined(__CRT_HAVE_readq_nopf)
#include <kos/anno.h>
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_readb_nopf_defined
#define __local___localdep_readb_nopf_defined
#ifdef __arch_readb_nopf
__FORCELOCAL __ATTR_WUNUSED __NOBLOCK __ATTR_IN_OPT(1) __ATTR_OUT(2) __BOOL __NOTHROW(__LIBCCALL __localdep_readb_nopf)(void const *__addr, __UINT8_TYPE__ *__presult) { return __arch_readb_nopf(__addr, __presult); }
#elif defined(__CRT_HAVE_readb_nopf)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_WUNUSED __NOBLOCK __ATTR_IN_OPT(1) __ATTR_OUT(2),__BOOL,__NOTHROW,__localdep_readb_nopf,(void const *__addr, __UINT8_TYPE__ *__presult),readb_nopf,(__addr,__presult))
#elif defined(__arch_memcpy_nopf) || defined(__CRT_HAVE_memcpy_nopf) || defined(__arch_readw_nopf) || defined(__CRT_HAVE_readw_nopf) || defined(__arch_readl_nopf) || defined(__CRT_HAVE_readl_nopf) || defined(__arch_readq_nopf) || defined(__CRT_HAVE_readq_nopf)
__NAMESPACE_LOCAL_END
#include <libc/local/kos.nopf/readb_nopf.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_readb_nopf __LIBC_LOCAL_NAME(readb_nopf)
#else /* ... */
#undef __local___localdep_readb_nopf_defined
#endif /* !... */
#endif /* !__local___localdep_readb_nopf_defined */
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(memeq_nopf) __ATTR_WUNUSED __NOBLOCK __ATTR_INS(1, 3) __ATTR_INS(2, 3) __SSIZE_TYPE__
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(memeq_nopf))(void const *__lhs, void const *__rhs, __SIZE_TYPE__ __num_bytes) {
	while (__num_bytes) {
		__UINT8_TYPE__ __lhs_byte, __rhs_byte;
		if __unlikely(!(__NAMESPACE_LOCAL_SYM __localdep_readb_nopf)(__lhs, &__lhs_byte))
			return -1; /* #PF error */
		if __unlikely(!(__NAMESPACE_LOCAL_SYM __localdep_readb_nopf)(__rhs, &__rhs_byte))
			return -1; /* #PF error */

		if (__lhs_byte != __rhs_byte)
			return 1; /* Blobs differ */

		--__num_bytes;
		__lhs = (__BYTE_TYPE__ const *)__lhs + 1;
		__rhs = (__BYTE_TYPE__ const *)__rhs + 1;
	}
	return 0;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_memeq_nopf_defined
#define __local___localdep_memeq_nopf_defined
#define __localdep_memeq_nopf __LIBC_LOCAL_NAME(memeq_nopf)
#endif /* !__local___localdep_memeq_nopf_defined */
#else /* __arch_readb_nopf || __CRT_HAVE_readb_nopf || __arch_memcpy_nopf || __CRT_HAVE_memcpy_nopf || __arch_readw_nopf || __CRT_HAVE_readw_nopf || __arch_readl_nopf || __CRT_HAVE_readl_nopf || __arch_readq_nopf || __CRT_HAVE_readq_nopf */
#undef __local_memeq_nopf_defined
#endif /* !__arch_readb_nopf && !__CRT_HAVE_readb_nopf && !__arch_memcpy_nopf && !__CRT_HAVE_memcpy_nopf && !__arch_readw_nopf && !__CRT_HAVE_readw_nopf && !__arch_readl_nopf && !__CRT_HAVE_readl_nopf && !__arch_readq_nopf && !__CRT_HAVE_readq_nopf */
#endif /* !__local_memeq_nopf_defined */
