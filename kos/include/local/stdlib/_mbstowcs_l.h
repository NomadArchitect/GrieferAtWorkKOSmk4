/* HASH CRC-32:0x8f5d6d97 */
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
#ifndef __local__mbstowcs_l_defined
#define __local__mbstowcs_l_defined 1
/* Dependency: "_mbstowcs_s_l" from "stdlib" */
#ifndef ____localdep__mbstowcs_s_l_defined
#define ____localdep__mbstowcs_s_l_defined 1
#ifdef __CRT_HAVE__mbstowcs_s_l
__CREDIRECT(,__errno_t,__NOTHROW_NCX,__localdep__mbstowcs_s_l,(__SIZE_TYPE__ *__presult, __WCHAR_TYPE__ *__buf, __SIZE_TYPE__ __buflen, char const *__src, __SIZE_TYPE__ __maxlen, __locale_t __locale),_mbstowcs_s_l,(__presult,__buf,__buflen,__src,__maxlen,__locale))
#else /* LIBC: _mbstowcs_s_l */
#include <local/stdlib/_mbstowcs_s_l.h>
#define __localdep__mbstowcs_s_l (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_mbstowcs_s_l))
#endif /* _mbstowcs_s_l... */
#endif /* !____localdep__mbstowcs_s_l_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(_mbstowcs_l) __SIZE_TYPE__
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_mbstowcs_l))(__WCHAR_TYPE__ *__buf,
                                                         char const *__src,
                                                         __SIZE_TYPE__ __maxlen,
                                                         __locale_t __locale) {
#line 2289 "kos/src/libc/magic/stdlib.c"
	__SIZE_TYPE__ __result;
	if (__localdep__mbstowcs_s_l(&__result, __buf, (__SIZE_TYPE__)-1, __src, __maxlen, __locale))
		__result = 0;
	return __result;
}
__NAMESPACE_LOCAL_END
#endif /* !__local__mbstowcs_l_defined */
