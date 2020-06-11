/* HASH CRC-32:0x8477e49a */
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
#ifndef __local___mempmoveupw_chk_defined
#define __local___mempmoveupw_chk_defined 1
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: mempmoveupw from string */
#ifndef __local___localdep_mempmoveupw_defined
#define __local___localdep_mempmoveupw_defined 1
#ifdef __fast_mempmoveupw_defined
/* Same as `memmovew', but return `DST + N_WORDS', rather than `DST' (assumes that `DST >= SRC || !N_WORDS') */
__NAMESPACE_FAST_USING(mempmoveupw)
#define __localdep_mempmoveupw __LIBC_FAST_NAME(mempmoveupw)
#elif defined(__CRT_HAVE_mempmoveupw)
/* Same as `memmovew', but return `DST + N_WORDS', rather than `DST' (assumes that `DST >= SRC || !N_WORDS') */
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),__UINT16_TYPE__ *,__NOTHROW_NCX,__localdep_mempmoveupw,(void *__dst, void const *__src, __SIZE_TYPE__ __n_words),mempmoveupw,(__dst,__src,__n_words))
#elif defined(__CRT_HAVE_mempmovew)
/* Same as `memmovew', but return `DST + N_WORDS', rather than `DST' (assumes that `DST >= SRC || !N_WORDS') */
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),__UINT16_TYPE__ *,__NOTHROW_NCX,__localdep_mempmoveupw,(void *__dst, void const *__src, __SIZE_TYPE__ __n_words),mempmovew,(__dst,__src,__n_words))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <local/string/mempmoveupw.h>
__NAMESPACE_LOCAL_BEGIN
/* Same as `memmovew', but return `DST + N_WORDS', rather than `DST' (assumes that `DST >= SRC || !N_WORDS') */
#define __localdep_mempmoveupw __LIBC_LOCAL_NAME(mempmoveupw)
#endif /* !... */
#endif /* !__local___localdep_mempmoveupw_defined */
__NAMESPACE_LOCAL_END
#include <ssp/chk.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(__mempmoveupw_chk) __ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)) __UINT16_TYPE__ *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(__mempmoveupw_chk))(void *__dst, void const *__src, __SIZE_TYPE__ __n_words, __SIZE_TYPE__ __dst_objsize) {
	__ssp_chk_dstbuf("mempmoveupw", __dst, __n_words * 2, __dst_objsize);
	return __localdep_mempmoveupw(__dst, __src, __n_words);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep___mempmoveupw_chk_defined
#define __local___localdep___mempmoveupw_chk_defined 1
#define __localdep___mempmoveupw_chk __LIBC_LOCAL_NAME(__mempmoveupw_chk)
#endif /* !__local___localdep___mempmoveupw_chk_defined */
#endif /* !__local___mempmoveupw_chk_defined */
