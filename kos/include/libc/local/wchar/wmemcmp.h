/* HASH CRC-32:0x94e0ec76 */
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
#ifndef __local_wmemcmp_defined
#define __local_wmemcmp_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_memcmpc_defined
#define __local___localdep_memcmpc_defined
#ifdef __CRT_HAVE_memcmpc
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_memcmpc,(void const *__s1, void const *__s2, __SIZE_TYPE__ __elem_count, __SIZE_TYPE__ __elem_size),memcmpc,(__s1,__s2,__elem_count,__elem_size))
#else /* __CRT_HAVE_memcmpc */
__NAMESPACE_LOCAL_END
#include <libc/local/string/memcmpc.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_memcmpc __LIBC_LOCAL_NAME(memcmpc)
#endif /* !__CRT_HAVE_memcmpc */
#endif /* !__local___localdep_memcmpc_defined */
#ifndef __local___localdep_memcmpl_defined
#define __local___localdep_memcmpl_defined
#ifdef __CRT_HAVE_memcmpl
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_memcmpl,(void const *__s1, void const *__s2, __SIZE_TYPE__ __n_dwords),memcmpl,(__s1,__s2,__n_dwords))
#elif defined(__CRT_HAVE_wmemcmp) && __SIZEOF_WCHAR_T__ == 4
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_memcmpl,(void const *__s1, void const *__s2, __SIZE_TYPE__ __n_dwords),wmemcmp,(__s1,__s2,__n_dwords))
#elif defined(__CRT_HAVE_KOS$wmemcmp) && defined(__LIBCCALL_IS_LIBKCALL)
__COMPILER_CREDIRECT(__LIBC,__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__LIBCCALL,__localdep_memcmpl,(void const *__s1, void const *__s2, __SIZE_TYPE__ __n_dwords),KOS$wmemcmp,(__s1,__s2,__n_dwords))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/string/memcmpl.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_memcmpl __LIBC_LOCAL_NAME(memcmpl)
#endif /* !... */
#endif /* !__local___localdep_memcmpl_defined */
#ifndef __local___localdep_memcmpw_defined
#define __local___localdep_memcmpw_defined
#ifdef __CRT_HAVE_memcmpw
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_memcmpw,(void const *__s1, void const *__s2, __SIZE_TYPE__ __n_words),memcmpw,(__s1,__s2,__n_words))
#elif defined(__CRT_HAVE_wmemcmp) && __SIZEOF_WCHAR_T__ == 2
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_memcmpw,(void const *__s1, void const *__s2, __SIZE_TYPE__ __n_words),wmemcmp,(__s1,__s2,__n_words))
#elif defined(__CRT_HAVE_DOS$wmemcmp) && defined(__LIBCCALL_IS_LIBDCALL)
__COMPILER_CREDIRECT(__LIBC,__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__LIBCCALL,__localdep_memcmpw,(void const *__s1, void const *__s2, __SIZE_TYPE__ __n_words),DOS$wmemcmp,(__s1,__s2,__n_words))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/string/memcmpw.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_memcmpw __LIBC_LOCAL_NAME(memcmpw)
#endif /* !... */
#endif /* !__local___localdep_memcmpw_defined */
__LOCAL_LIBC(wmemcmp) __ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_INS(2, 3) __ATTR_NONNULL((1, 2)) int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(wmemcmp))(__WCHAR_TYPE__ const *__s1, __WCHAR_TYPE__ const *__s2, __SIZE_TYPE__ __num_chars) {
#if __SIZEOF_WCHAR_T__ == 2
	return (__NAMESPACE_LOCAL_SYM __localdep_memcmpw)(__s1, __s2, __num_chars);
#elif __SIZEOF_WCHAR_T__ == 4
	return (__NAMESPACE_LOCAL_SYM __localdep_memcmpl)(__s1, __s2, __num_chars);
#else /* ... */
	return (__NAMESPACE_LOCAL_SYM __localdep_memcmpc)(__s1, __s2, __num_chars, sizeof(__WCHAR_TYPE__));
#endif /* !... */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_wmemcmp_defined
#define __local___localdep_wmemcmp_defined
#define __localdep_wmemcmp __LIBC_LOCAL_NAME(wmemcmp)
#endif /* !__local___localdep_wmemcmp_defined */
#endif /* !__local_wmemcmp_defined */
