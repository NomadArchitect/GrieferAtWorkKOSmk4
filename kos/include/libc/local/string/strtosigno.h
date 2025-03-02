/* HASH CRC-32:0xb48fba08 */
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
#ifndef __local_strtosigno_defined
#define __local_strtosigno_defined
#include <__crt.h>
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_isupper_defined
#define __local___localdep_isupper_defined
__NAMESPACE_LOCAL_END
#include <bits/crt/ctype.h>
__NAMESPACE_LOCAL_BEGIN
#if defined(__crt_isupper) && defined(__CRT_HAVE_isupper)
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_isupper,(int __ch),isupper,{ return __crt_isupper(__ch); })
#elif defined(__crt_isupper)
__LOCAL __ATTR_CONST __ATTR_WUNUSED int __NOTHROW(__LIBCCALL __localdep_isupper)(int __ch) { return __crt_isupper(__ch); }
#elif __has_builtin(__builtin_isupper) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_isupper)
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_isupper,(int __ch),isupper,{ return __builtin_isupper(__ch); })
#elif defined(__CRT_HAVE_isupper)
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_isupper,(int __ch),isupper,(__ch))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/ctype/isupper.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_isupper __LIBC_LOCAL_NAME(isupper)
#endif /* !... */
#endif /* !__local___localdep_isupper_defined */
#ifndef __local___localdep_signalnumber_defined
#define __local___localdep_signalnumber_defined
#ifdef __CRT_HAVE_signalnumber
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1),__signo_t,__NOTHROW_NCX,__localdep_signalnumber,(const char *__name),signalnumber,(__name))
#else /* __CRT_HAVE_signalnumber */
__NAMESPACE_LOCAL_END
#include <libc/local/signal/signalnumber.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_signalnumber __LIBC_LOCAL_NAME(signalnumber)
#endif /* !__CRT_HAVE_signalnumber */
#endif /* !__local___localdep_signalnumber_defined */
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
#include <asm/os/signal.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(strtosigno) __ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __signo_t
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(strtosigno))(const char *__name) {
	__SIZE_TYPE__ __i;
	if (__name[0] != 'S' || __name[1] != 'I' || __name[2] != 'G')
		return 0;
	__name += 3;
	for (__i = 0; __name[__i]; ++__i) {
		if (!(__NAMESPACE_LOCAL_SYM __localdep_isupper)(__name[__i]))
			return 0;
	}
	return (__NAMESPACE_LOCAL_SYM __localdep_signalnumber)(__name);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_strtosigno_defined
#define __local___localdep_strtosigno_defined
#define __localdep_strtosigno __LIBC_LOCAL_NAME(strtosigno)
#endif /* !__local___localdep_strtosigno_defined */
#endif /* !__local_strtosigno_defined */
