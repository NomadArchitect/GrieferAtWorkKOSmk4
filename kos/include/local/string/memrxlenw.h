/* HASH CRC-32:0x4c4575e4 */
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
#ifndef __local_memrxlenw_defined
#define __local_memrxlenw_defined 1
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: memrxendw from string */
#ifndef __local___localdep_memrxendw_defined
#define __local___localdep_memrxendw_defined 1
#ifdef __CRT_HAVE_memrxendw
/* Same as `memrendw', but search for non-matching locations. */
__CREDIRECT(__ATTR_PURE __ATTR_RETNONNULL __ATTR_WUNUSED __ATTR_NONNULL((1)),__UINT16_TYPE__ *,__NOTHROW_NCX,__localdep_memrxendw,(void const *__restrict __haystack, __UINT16_TYPE__ __word, __SIZE_TYPE__ __n_words),memrxendw,(__haystack,__word,__n_words))
#else /* __CRT_HAVE_memrxendw */
__NAMESPACE_LOCAL_END
#include <local/string/memrxendw.h>
__NAMESPACE_LOCAL_BEGIN
/* Same as `memrendw', but search for non-matching locations. */
#define __localdep_memrxendw __LIBC_LOCAL_NAME(memrxendw)
#endif /* !__CRT_HAVE_memrxendw */
#endif /* !__local___localdep_memrxendw_defined */
/* Same as `memrlenw', but search for non-matching locations. */
__LOCAL_LIBC(memrxlenw) __ATTR_PURE __ATTR_WUNUSED __ATTR_NONNULL((1)) __SIZE_TYPE__
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(memrxlenw))(void const *__restrict __haystack, __UINT16_TYPE__ __word, __SIZE_TYPE__ __n_words) {
	return (__SIZE_TYPE__)(__localdep_memrxendw(__haystack, __word, __n_words) - (__UINT16_TYPE__ *)__haystack);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_memrxlenw_defined
#define __local___localdep_memrxlenw_defined 1
#define __localdep_memrxlenw __LIBC_LOCAL_NAME(memrxlenw)
#endif /* !__local___localdep_memrxlenw_defined */
#endif /* !__local_memrxlenw_defined */
