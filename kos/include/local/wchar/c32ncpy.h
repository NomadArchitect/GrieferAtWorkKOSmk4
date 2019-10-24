/* HASH CRC-32:0x89ff4be2 */
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
#ifndef __local_c32ncpy_defined
#define __local_c32ncpy_defined 1
/* Dependency: "wcsnlen" from "wchar" */
#ifndef ____localdep_c32nlen_defined
#define ____localdep_c32nlen_defined 1
#if defined(__CRT_HAVE_wcsnlen) && (__SIZEOF_WCHAR_T__ == 4)
/* Same as `c32len', but don't exceed `MAX_CHARS' characters (Same as `memlen[...](STR, '\0', MAX_CHARS)´) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_PURE __ATTR_NONNULL((1)),__SIZE_TYPE__,__NOTHROW_NCX,__localdep_c32nlen,(__CHAR32_TYPE__ const *__restrict __string, __SIZE_TYPE__ __maxlen),wcsnlen,(__string,__maxlen))
#elif __SIZEOF_WCHAR_T__ == 4
#include <local/wchar/wcsnlen.h>
/* Same as `c32len', but don't exceed `MAX_CHARS' characters (Same as `memlen[...](STR, '\0', MAX_CHARS)´) */
#define __localdep_c32nlen(string, maxlen) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wcsnlen))((__WCHAR_TYPE__ const *)(string), maxlen)
#else /* LIBC: c32nlen */
#include <local/wchar/c32nlen.h>
/* Same as `c32len', but don't exceed `MAX_CHARS' characters (Same as `memlen[...](STR, '\0', MAX_CHARS)´) */
#define __localdep_c32nlen (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32nlen))
#endif /* c32nlen... */
#endif /* !____localdep_c32nlen_defined */

/* Dependency: "wmemcpy" from "wchar" */
#ifndef ____localdep_c32memcpy_defined
#define ____localdep_c32memcpy_defined 1
#if defined(__CRT_HAVE_wmemcpy) && (__SIZEOF_WCHAR_T__ == 4)
__CREDIRECT(__ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),__CHAR32_TYPE__ *,__NOTHROW_NCX,__localdep_c32memcpy,(__CHAR32_TYPE__ *__restrict __dst, __CHAR32_TYPE__ const *__restrict __src, __SIZE_TYPE__ __num_chars),wmemcpy,(__dst,__src,__num_chars))
#elif defined(__CRT_HAVE_memcpyl)
__CREDIRECT(__ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),__CHAR32_TYPE__ *,__NOTHROW_NCX,__localdep_c32memcpy,(__CHAR32_TYPE__ *__restrict __dst, __CHAR32_TYPE__ const *__restrict __src, __SIZE_TYPE__ __num_chars),memcpyl,(__dst,__src,__num_chars))
#elif __SIZEOF_WCHAR_T__ == 4
#include <local/wchar/wmemcpy.h>
#define __localdep_c32memcpy(dst, src, num_chars) (__CHAR32_TYPE__ *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wmemcpy))((__WCHAR_TYPE__ *)(dst), (__WCHAR_TYPE__ const *)(src), num_chars)
#else /* LIBC: c32memcpy */
#include <local/wchar/c32memcpy.h>
#define __localdep_c32memcpy (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32memcpy))
#endif /* c32memcpy... */
#endif /* !____localdep_c32memcpy_defined */

/* Dependency: "wmemset" from "wchar" */
#ifndef ____localdep_c32memset_defined
#define ____localdep_c32memset_defined 1
#if defined(__CRT_HAVE_wmemset) && (__SIZEOF_WCHAR_T__ == 4)
__CREDIRECT(__ATTR_RETNONNULL __ATTR_NONNULL((1)),__CHAR32_TYPE__ *,__NOTHROW_NCX,__localdep_c32memset,(__CHAR32_TYPE__ *__dst, __CHAR32_TYPE__ __filler, __SIZE_TYPE__ __num_chars),wmemset,(__dst,__filler,__num_chars))
#elif defined(__CRT_HAVE_memsetl)
__CREDIRECT(__ATTR_RETNONNULL __ATTR_NONNULL((1)),__CHAR32_TYPE__ *,__NOTHROW_NCX,__localdep_c32memset,(__CHAR32_TYPE__ *__dst, __CHAR32_TYPE__ __filler, __SIZE_TYPE__ __num_chars),memsetl,(__dst,__filler,__num_chars))
#elif __SIZEOF_WCHAR_T__ == 4
#include <local/wchar/wmemset.h>
#define __localdep_c32memset(dst, filler, num_chars) (__CHAR32_TYPE__ *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wmemset))((__WCHAR_TYPE__ *)(dst), (__WCHAR_TYPE__)(filler), num_chars)
#else /* LIBC: c32memset */
#include <local/wchar/c32memset.h>
#define __localdep_c32memset (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32memset))
#endif /* c32memset... */
#endif /* !____localdep_c32memset_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(c32ncpy) __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)) __CHAR32_TYPE__ *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(c32ncpy))(__CHAR32_TYPE__ *__restrict __buf,
                                                     __CHAR32_TYPE__ const *__restrict __src,
                                                     __SIZE_TYPE__ __buflen) {
#line 347 "kos/src/libc/magic/wchar.c"
	__SIZE_TYPE__ __srclen = __localdep_c32nlen(__src, __buflen);
	__localdep_c32memcpy(__buf, __src, __srclen);
	__localdep_c32memset(__buf+__srclen, '\0', __buflen - __srclen);
	return __buf;
}
__NAMESPACE_LOCAL_END
#endif /* !__local_c32ncpy_defined */
