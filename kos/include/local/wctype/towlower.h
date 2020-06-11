/* HASH CRC-32:0x24506ce7 */
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
#ifndef __local_towlower_defined
#define __local_towlower_defined 1
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: tolower from ctype */
#ifndef __local___localdep_tolower_defined
#define __local___localdep_tolower_defined 1
#if __has_builtin(__builtin_tolower) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_tolower)
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_tolower,(int __ch),tolower,{ return __builtin_tolower(__ch); })
#elif defined(__CRT_HAVE_tolower)
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_tolower,(int __ch),tolower,(__ch))
#elif defined(__CRT_HAVE__tolower)
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_tolower,(int __ch),_tolower,(__ch))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <local/ctype/tolower.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_tolower __LIBC_LOCAL_NAME(tolower)
#endif /* !... */
#endif /* !__local___localdep_tolower_defined */
__LOCAL_LIBC(towlower) __ATTR_CONST __ATTR_WUNUSED __WINT_TYPE__
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(towlower))(__WINT_TYPE__ __wc) {
	return (__WINT_TYPE__)__localdep_tolower((int)__wc);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_towlower_defined
#define __local___localdep_towlower_defined 1
#define __localdep_towlower __LIBC_LOCAL_NAME(towlower)
#endif /* !__local___localdep_towlower_defined */
#endif /* !__local_towlower_defined */
