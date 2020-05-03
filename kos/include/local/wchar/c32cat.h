/* HASH CRC-32:0xc04dd6e1 */
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
#ifndef __local_c32cat_defined
#define __local_c32cat_defined 1
#include <__crt.h>
/* Dependency: "wmemcpy" from "wchar" */
#ifndef ____localdep_c32memcpy_defined
#define ____localdep_c32memcpy_defined 1
#if defined(__CRT_HAVE_wmemcpy) && (__SIZEOF_WCHAR_T__ == 4)
__CREDIRECT(__ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),__CHAR32_TYPE__ *,__NOTHROW_NCX,__localdep_c32memcpy,(__CHAR32_TYPE__ *__restrict __dst, __CHAR32_TYPE__ const *__restrict __src, __SIZE_TYPE__ __num_chars),wmemcpy,(__dst,__src,__num_chars))
#elif defined(__CRT_HAVE_memcpyl)
__CREDIRECT(__ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),__CHAR32_TYPE__ *,__NOTHROW_NCX,__localdep_c32memcpy,(__CHAR32_TYPE__ *__restrict __dst, __CHAR32_TYPE__ const *__restrict __src, __SIZE_TYPE__ __num_chars),memcpyl,(__dst,__src,__num_chars))
#elif __SIZEOF_WCHAR_T__ == 4
#include <local/wchar/wmemcpy.h>
#define __localdep_c32memcpy (*(__CHAR32_TYPE__ *(__LIBCCALL*)(__CHAR32_TYPE__ *__restrict, __CHAR32_TYPE__ const *__restrict, __SIZE_TYPE__))&(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wmemcpy)))
#else /* LIBC: c32memcpy */
#include <local/wchar/c32memcpy.h>
#define __localdep_c32memcpy (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32memcpy))
#endif /* c32memcpy... */
#endif /* !____localdep_c32memcpy_defined */

/* Dependency: "wcsend" from "wchar" */
#ifndef ____localdep_c32end_defined
#define ____localdep_c32end_defined 1
#if defined(__CRT_HAVE_wcsend) && (__SIZEOF_WCHAR_T__ == 4)
/* Same as `STR+c32len(STR)' */
__CREDIRECT(__ATTR_PURE __ATTR_RETNONNULL __ATTR_WUNUSED __ATTR_NONNULL((1)),__CHAR32_TYPE__ *,__NOTHROW_NCX,__localdep_c32end,(__CHAR32_TYPE__ const *__restrict __string),wcsend,(__string))
#elif __SIZEOF_WCHAR_T__ == 4
#include <local/wchar/wcsend.h>
/* Same as `STR+c32len(STR)' */
#define __localdep_c32end (*(__CHAR32_TYPE__ *(__LIBCCALL*)(__CHAR32_TYPE__ const *__restrict))&(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wcsend)))
#else /* LIBC: c32end */
#include <local/wchar/c32end.h>
/* Same as `STR+c32len(STR)' */
#define __localdep_c32end (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32end))
#endif /* c32end... */
#endif /* !____localdep_c32end_defined */

/* Dependency: "wcslen" from "wchar" */
#ifndef ____localdep_c32len_defined
#define ____localdep_c32len_defined 1
#if defined(__CRT_HAVE_wcslen) && (__SIZEOF_WCHAR_T__ == 4)
/* Return the length of the string in characters (Same as `rawmemlen[...](STR, '\0')') */
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_NONNULL((1)),__SIZE_TYPE__,__NOTHROW_NCX,__localdep_c32len,(__CHAR32_TYPE__ const *__restrict __string),wcslen,(__string))
#elif __SIZEOF_WCHAR_T__ == 4
#include <local/wchar/wcslen.h>
/* Return the length of the string in characters (Same as `rawmemlen[...](STR, '\0')') */
#define __localdep_c32len (*(__SIZE_TYPE__(__LIBCCALL*)(__CHAR32_TYPE__ const *__restrict))&(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wcslen)))
#else /* LIBC: c32len */
#include <local/wchar/c32len.h>
/* Return the length of the string in characters (Same as `rawmemlen[...](STR, '\0')') */
#define __localdep_c32len (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32len))
#endif /* c32len... */
#endif /* !____localdep_c32len_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(c32cat) __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)) __CHAR32_TYPE__ *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(c32cat))(__CHAR32_TYPE__ *__restrict __buf,
                                                    __CHAR32_TYPE__ const *__restrict __src) {
#line 444 "kos/src/libc/magic/wchar.c"
	__localdep_c32memcpy(__localdep_c32end(__buf), __src, __localdep_c32len(__src) + 1);
	return __buf;
}
__NAMESPACE_LOCAL_END
#endif /* !__local_c32cat_defined */
