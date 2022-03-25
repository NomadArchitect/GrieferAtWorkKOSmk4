/* HASH CRC-32:0x6481f6dd */
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
#ifndef __local_islower16_l_defined
#define __local_islower16_l_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_islower16_defined
#define __local___localdep_islower16_defined
__NAMESPACE_LOCAL_END
#include <bits/crt/wctype.h>
__NAMESPACE_LOCAL_BEGIN
#if defined(__crt_iswlower) && defined(__CRT_HAVE_iswlower) && __SIZEOF_WCHAR_T__ == 2
__COMPILER_CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__LIBDCALL,__localdep_islower16,(__WINT16_TYPE__ __wc),iswlower,{ return __crt_iswlower(__wc); })
#elif defined(__crt_iswlower) && __SIZEOF_WCHAR_T__ == 2
__LOCAL __ATTR_CONST __ATTR_WUNUSED int __NOTHROW(__LIBDCALL __localdep_islower16)(__WINT16_TYPE__ __wc) { return __crt_iswlower(__wc); }
#elif __has_builtin(__builtin_iswlower) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_iswlower) && __SIZEOF_WCHAR_T__ == 2
__COMPILER_CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__LIBDCALL,__localdep_islower16,(__WINT16_TYPE__ __wc),iswlower,{ return __builtin_iswlower(__wc); })
#elif defined(__CRT_HAVE_iswlower) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_islower16,(__WINT16_TYPE__ __wc),iswlower,(__wc))
#elif defined(__CRT_HAVE_DOS$iswlower)
__CREDIRECT_DOS(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_islower16,(__WINT16_TYPE__ __wc),iswlower,(__wc))
#elif __SIZEOF_WCHAR_T__ == 2
__NAMESPACE_LOCAL_END
#include <libc/local/wctype/iswlower.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_islower16 __NAMESPACE_LOCAL_TYPEHAX(int(__LIBDCALL*)(__WINT16_TYPE__),int(__LIBDCALL&)(__WINT16_TYPE__),iswlower)
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/parts.uchar.wctype/islower16.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_islower16 __LIBC_LOCAL_NAME(islower16)
#endif /* !... */
#endif /* !__local___localdep_islower16_defined */
__LOCAL_LIBC(islower16_l) __ATTR_PURE __ATTR_WUNUSED int
__NOTHROW_NCX(__LIBDCALL __LIBC_LOCAL_NAME(islower16_l))(__WINT16_TYPE__ __ch, __locale_t __locale) {
	__COMPILER_IMPURE();
	(void)__locale;
	return (__NAMESPACE_LOCAL_SYM __localdep_islower16)(__ch);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_islower16_l_defined
#define __local___localdep_islower16_l_defined
#define __localdep_islower16_l __LIBC_LOCAL_NAME(islower16_l)
#endif /* !__local___localdep_islower16_l_defined */
#endif /* !__local_islower16_l_defined */
