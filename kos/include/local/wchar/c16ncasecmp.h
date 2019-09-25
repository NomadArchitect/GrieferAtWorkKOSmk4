/* HASH CRC-32:0xb2e7c0c0 */
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
#ifndef __local_c16ncasecmp_defined
#define __local_c16ncasecmp_defined 1
/* Dependency: "towlower" from "wctype" */
#ifndef ____localdep_towlower_defined
#define ____localdep_towlower_defined 1
#if __has_builtin(__builtin_towlower) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_towlower)
__FORCELOCAL __ATTR_WUNUSED __ATTR_CONST __WINT_TYPE__ __NOTHROW(__LIBCCALL __localdep_towlower)(__WINT_TYPE__ __wc) { return __builtin_towlower(__wc); }
#elif defined(__CRT_HAVE_towlower)
__CREDIRECT(__ATTR_WUNUSED __ATTR_CONST,__WINT_TYPE__,__NOTHROW,__localdep_towlower,(__WINT_TYPE__ __wc),towlower,(__wc))
#else /* LIBC: towlower */
#include <local/wctype/towlower.h>
#define __localdep_towlower (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(towlower))
#endif /* towlower... */
#endif /* !____localdep_towlower_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(c16ncasecmp) __ATTR_WUNUSED __ATTR_PURE __ATTR_NONNULL((1, 2)) int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(c16ncasecmp))(__CHAR16_TYPE__ const *__s1,
                                                         __CHAR16_TYPE__ const *__s2,
                                                         __SIZE_TYPE__ __maxlen) {
#line 775 "kos/src/libc/magic/string.c"
	__CHAR16_TYPE__ __c1, __c2;
	do {
		if (!__maxlen--)
			break;
		if ((__c1 = *__s1++) != (__c2 = *__s2++) && ((__c1 = (__CHAR16_TYPE__)__localdep_towlower(__c1)) != (__c2 = (__CHAR16_TYPE__)__localdep_towlower(__c2))))
			return (int)((__CHAR16_TYPE__)__c1 - (__CHAR16_TYPE__)__c2);
	} while (__c1);
	return 0;
}
__NAMESPACE_LOCAL_END
#endif /* !__local_c16ncasecmp_defined */
