/* HASH CRC-32:0x87ed3fc0 */
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
#ifndef __local__c32strdate_s_defined
#define __local__c32strdate_s_defined
#include <__crt.h>
#include <bits/types.h>
#if (defined(__CRT_HAVE__wstrdate) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_wstrdate) || defined(__CRT_HAVE__strdate) || defined(__CRT_HAVE_time64) || defined(__CRT_HAVE__time64) || defined(__CRT_HAVE___time64) || defined(__CRT_HAVE_time) || defined(__CRT_HAVE___time) || defined(__CRT_HAVE___libc_time) || defined(__CRT_HAVE__time32)
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__c32strdate_defined
#define __local___localdep__c32strdate_defined
#if defined(__CRT_HAVE__wstrdate) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_OUT(1),__CHAR32_TYPE__ *,__NOTHROW_NCX,__localdep__c32strdate,(__CHAR32_TYPE__ __buf[9]),_wstrdate,(__buf))
#elif defined(__CRT_HAVE_KOS$_wstrdate)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT_KOS(__ATTR_OUT(1),__CHAR32_TYPE__ *,__NOTHROW_NCX,__localdep__c32strdate,(__CHAR32_TYPE__ __buf[9]),_wstrdate,(__buf))
#elif (defined(__CRT_HAVE__strdate) || defined(__CRT_HAVE_time64) || defined(__CRT_HAVE__time64) || defined(__CRT_HAVE___time64) || defined(__CRT_HAVE_time) || defined(__CRT_HAVE___time) || defined(__CRT_HAVE___libc_time) || defined(__CRT_HAVE__time32)) && __SIZEOF_WCHAR_T__ == 4
__NAMESPACE_LOCAL_END
#include <libc/local/corecrt_wtime/_wstrdate.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__c32strdate __NAMESPACE_LOCAL_TYPEHAX(__CHAR32_TYPE__ *(__LIBKCALL*)(__CHAR32_TYPE__[9]),__CHAR32_TYPE__ *(__LIBKCALL&)(__CHAR32_TYPE__[9]),_wstrdate)
#elif defined(__CRT_HAVE__strdate) || defined(__CRT_HAVE_time64) || defined(__CRT_HAVE__time64) || defined(__CRT_HAVE___time64) || defined(__CRT_HAVE_time) || defined(__CRT_HAVE___time) || defined(__CRT_HAVE___libc_time) || defined(__CRT_HAVE__time32)
__NAMESPACE_LOCAL_END
#include <libc/local/parts.uchar.time/_c32strdate.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__c32strdate __LIBC_LOCAL_NAME(_c32strdate)
#else /* ... */
#undef __local___localdep__c32strdate_defined
#endif /* !... */
#endif /* !__local___localdep__c32strdate_defined */
__NAMESPACE_LOCAL_END
#include <libc/errno.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(_c32strdate_s) __ATTR_OUTS(1, 2) __errno_t
__NOTHROW_NCX(__LIBKCALL __LIBC_LOCAL_NAME(_c32strdate_s))(__CHAR32_TYPE__ *__buf, __SIZE_TYPE__ __buflen) {
	if __unlikely(__buflen < 9)
		return __ERANGE;



	if (!(__NAMESPACE_LOCAL_SYM __localdep__c32strdate)(__buf))
		return __libc_geterrno_or(1);

	return 0;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__c32strdate_s_defined
#define __local___localdep__c32strdate_s_defined
#define __localdep__c32strdate_s __LIBC_LOCAL_NAME(_c32strdate_s)
#endif /* !__local___localdep__c32strdate_s_defined */
#else /* (__CRT_HAVE__wstrdate && __SIZEOF_WCHAR_T__ == 4 && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_KOS$_wstrdate || __CRT_HAVE__strdate || __CRT_HAVE_time64 || __CRT_HAVE__time64 || __CRT_HAVE___time64 || __CRT_HAVE_time || __CRT_HAVE___time || __CRT_HAVE___libc_time || __CRT_HAVE__time32 */
#undef __local__c32strdate_s_defined
#endif /* (!__CRT_HAVE__wstrdate || __SIZEOF_WCHAR_T__ != 4 || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_KOS$_wstrdate && !__CRT_HAVE__strdate && !__CRT_HAVE_time64 && !__CRT_HAVE__time64 && !__CRT_HAVE___time64 && !__CRT_HAVE_time && !__CRT_HAVE___time && !__CRT_HAVE___libc_time && !__CRT_HAVE__time32 */
#endif /* !__local__c32strdate_s_defined */
