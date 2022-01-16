/* HASH CRC-32:0x4f4091fe */
/* Copyright (c) 2019-2022 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2022 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_c16rtombs_defined
#define __local_c16rtombs_defined
#include <__crt.h>
#include <bits/crt/mbstate.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_mempcpy_defined
#define __local___localdep_mempcpy_defined
#ifdef __CRT_HAVE_mempcpy
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),void *,__NOTHROW_NCX,__localdep_mempcpy,(void *__restrict __dst, void const *__restrict __src, __SIZE_TYPE__ __n_bytes),mempcpy,(__dst,__src,__n_bytes))
#elif defined(__CRT_HAVE___mempcpy)
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),void *,__NOTHROW_NCX,__localdep_mempcpy,(void *__restrict __dst, void const *__restrict __src, __SIZE_TYPE__ __n_bytes),__mempcpy,(__dst,__src,__n_bytes))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/string/mempcpy.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_mempcpy __LIBC_LOCAL_NAME(mempcpy)
#endif /* !... */
#endif /* !__local___localdep_mempcpy_defined */
#ifndef __local___localdep_uchar_c16rtomb_defined
#define __local___localdep_uchar_c16rtomb_defined
#if defined(__CRT_HAVE_wcrtomb) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(,__SIZE_TYPE__,__NOTHROW_NCX,__localdep_uchar_c16rtomb,(char *__restrict __str, __CHAR16_TYPE__ __wc, struct __mbstate *__mbs),wcrtomb,(__str,__wc,__mbs))
#elif defined(__CRT_HAVE_DOS$wcrtomb)
__CREDIRECT_DOS(,__SIZE_TYPE__,__NOTHROW_NCX,__localdep_uchar_c16rtomb,(char *__restrict __str, __CHAR16_TYPE__ __wc, struct __mbstate *__mbs),wcrtomb,(__str,__wc,__mbs))
#elif defined(__CRT_HAVE_c16rtomb) && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(,__SIZE_TYPE__,__NOTHROW_NCX,__localdep_uchar_c16rtomb,(char *__restrict __str, __CHAR16_TYPE__ __wc, struct __mbstate *__mbs),c16rtomb,(__str,__wc,__mbs))
#elif defined(__CRT_HAVE_DOS$c16rtomb)
__CREDIRECT_DOS(,__SIZE_TYPE__,__NOTHROW_NCX,__localdep_uchar_c16rtomb,(char *__restrict __str, __CHAR16_TYPE__ __wc, struct __mbstate *__mbs),c16rtomb,(__str,__wc,__mbs))
#elif __SIZEOF_WCHAR_T__ == 2
__NAMESPACE_LOCAL_END
#include <libc/local/wchar/wcrtomb.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_uchar_c16rtomb __NAMESPACE_LOCAL_TYPEHAX(__SIZE_TYPE__(__LIBDCALL*)(char *__restrict,__CHAR16_TYPE__,struct __mbstate *),__SIZE_TYPE__(__LIBDCALL&)(char *__restrict,__CHAR16_TYPE__,struct __mbstate *),wcrtomb)
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/uchar/uchar_c16rtomb.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_uchar_c16rtomb __LIBC_LOCAL_NAME(uchar_c16rtomb)
#endif /* !... */
#endif /* !__local___localdep_uchar_c16rtomb_defined */
__LOCAL_LIBC(c16rtombs) __ATTR_NONNULL((1, 2)) __SIZE_TYPE__
__NOTHROW_NCX(__LIBDCALL __LIBC_LOCAL_NAME(c16rtombs))(char *__dst, __CHAR16_TYPE__ const **__restrict __psrc, __SIZE_TYPE__ __dstlen, struct __mbstate *__mbs) {
	__SIZE_TYPE__ __result = 0;
	__CHAR16_TYPE__ const *__src = *__psrc;
	while (__dstlen) {
		__SIZE_TYPE__ __error;
		char __buf[7];
		__error = (__NAMESPACE_LOCAL_SYM __localdep_uchar_c16rtomb)(__buf, *__src, __mbs);
		if (!__error)
			break;
		if (__error == (__SIZE_TYPE__)-1)
			return (__SIZE_TYPE__)-1; /* EILSEQ */
		if (__error > __dstlen)
			break;
		__dst = (char *)(__NAMESPACE_LOCAL_SYM __localdep_mempcpy)(__dst, __buf, __error);
		__result += __error;
		__dstlen -= __error;
		++__src;
	}
	*__psrc = __src;
	return __result;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_c16rtombs_defined
#define __local___localdep_c16rtombs_defined
#define __localdep_c16rtombs __LIBC_LOCAL_NAME(c16rtombs)
#endif /* !__local___localdep_c16rtombs_defined */
#endif /* !__local_c16rtombs_defined */
