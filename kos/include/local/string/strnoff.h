/* HASH CRC-32:0x846fe687 */
/* Copyright (c) 2019 Griefer@Work                                            *
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
 *    in a product, an acknowledgement in the product documentation would be  *
 *    appreciated but is not required.                                        *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_strnoff_defined
#define __local_strnoff_defined 1
/* Dependency: "strnchrnul" from "string" */
#ifndef ____localdep_strnchrnul_defined
#define ____localdep_strnchrnul_defined 1
#if defined(__CRT_HAVE_strnchrnul)
/* Same as `strnchr', but return `strnend(STR, MAX_CHARS)', rather than `NULL' if `NEEDLE' wasn't found. */
__CREDIRECT(__ATTR_WUNUSED __ATTR_PURE __ATTR_RETNONNULL __ATTR_NONNULL((1)),char *,__NOTHROW_NCX,__localdep_strnchrnul,(char const *__restrict __haystack, int __needle, __SIZE_TYPE__ __maxlen),strnchrnul,(__haystack,__needle,__maxlen))
#else /* LIBC: strnchrnul */
#include <local/string/strnchrnul.h>
/* Same as `strnchr', but return `strnend(STR, MAX_CHARS)', rather than `NULL' if `NEEDLE' wasn't found. */
#define __localdep_strnchrnul (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(strnchrnul))
#endif /* strnchrnul... */
#endif /* !____localdep_strnchrnul_defined */

__NAMESPACE_LOCAL_BEGIN
/* Same as `strnchrnul', but return the offset from `STR', rather than the actual address */
__LOCAL_LIBC(strnoff) __ATTR_WUNUSED __ATTR_PURE __ATTR_NONNULL((1)) __SIZE_TYPE__
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(strnoff))(char const *__restrict __haystack,
                                                     int __needle,
                                                     __SIZE_TYPE__ __maxlen) {
#line 2187 "kos/src/libc/magic/string.c"
	return (__SIZE_TYPE__)(__localdep_strnchrnul(__haystack, __needle, __maxlen) - __haystack);
}
__NAMESPACE_LOCAL_END
#endif /* !__local_strnoff_defined */
