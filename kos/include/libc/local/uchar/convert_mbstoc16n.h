/* HASH CRC-32:0xff41be37 */
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
#ifndef __local_convert_mbstoc16n_defined
#define __local_convert_mbstoc16n_defined
#include <__crt.h>
#if ((defined(__CRT_HAVE_format_waprintf_printer) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$format_waprintf_printer) || (defined(__CRT_HAVE_format_waprintf_alloc) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && ((defined(__CRT_HAVE_format_waprintf_pack) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$format_waprintf_pack) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_format_8to16_defined
#define __local___localdep_format_8to16_defined
#ifdef __CRT_HAVE_format_8to16
__CREDIRECT(,__SSIZE_TYPE__,__NOTHROW_NCX,__localdep_format_8to16,(void *__arg, char const *__data, __SIZE_TYPE__ __datalen),format_8to16,(__arg,__data,__datalen))
#else /* __CRT_HAVE_format_8to16 */
__NAMESPACE_LOCAL_END
#include <libc/local/unicode/format_8to16.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_format_8to16 __LIBC_LOCAL_NAME(format_8to16)
#endif /* !__CRT_HAVE_format_8to16 */
#endif /* !__local___localdep_format_8to16_defined */
#ifndef __local___localdep_format_8to32_defined
#define __local___localdep_format_8to32_defined
#ifdef __CRT_HAVE_format_8to32
__CREDIRECT(,__SSIZE_TYPE__,__NOTHROW_NCX,__localdep_format_8to32,(void *__arg, char const *__data, __SIZE_TYPE__ __datalen),format_8to32,(__arg,__data,__datalen))
#else /* __CRT_HAVE_format_8to32 */
__NAMESPACE_LOCAL_END
#include <libc/local/unicode/format_8to32.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_format_8to32 __LIBC_LOCAL_NAME(format_8to32)
#endif /* !__CRT_HAVE_format_8to32 */
#endif /* !__local___localdep_format_8to32_defined */
#ifndef __local___localdep_format_c16aprintf_pack_defined
#define __local___localdep_format_c16aprintf_pack_defined
#if defined(__CRT_HAVE_format_waprintf_pack) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__NAMESPACE_LOCAL_END
#ifndef __format_waprintf_data_defined
#define __format_waprintf_data_defined
struct format_waprintf_data {
	__WCHAR_TYPE__      *ap_base;  /* [0..ap_used|ALLOC(ap_used+ap_avail)][owned] Buffer */
	__SIZE_TYPE__ ap_avail; /* Unused buffer size */
	__SIZE_TYPE__ ap_used;  /* Used buffer size */
};
#endif /* !__format_waprintf_data_defined */
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_MALLOC __ATTR_MALL_DEFAULT_ALIGNED __ATTR_WUNUSED __ATTR_NONNULL((1)),__CHAR16_TYPE__ *,__NOTHROW_NCX,__localdep_format_c16aprintf_pack,(struct format_c16aprintf_data *__restrict __self, __SIZE_TYPE__ *__pstrlen),format_waprintf_pack,(__self,__pstrlen))
#elif defined(__CRT_HAVE_DOS$format_waprintf_pack)
__NAMESPACE_LOCAL_END
#ifndef __format_waprintf_data_defined
#define __format_waprintf_data_defined
struct format_waprintf_data {
	__WCHAR_TYPE__      *ap_base;  /* [0..ap_used|ALLOC(ap_used+ap_avail)][owned] Buffer */
	__SIZE_TYPE__ ap_avail; /* Unused buffer size */
	__SIZE_TYPE__ ap_used;  /* Used buffer size */
};
#endif /* !__format_waprintf_data_defined */
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT_DOS(__ATTR_MALLOC __ATTR_MALL_DEFAULT_ALIGNED __ATTR_WUNUSED __ATTR_NONNULL((1)),__CHAR16_TYPE__ *,__NOTHROW_NCX,__localdep_format_c16aprintf_pack,(struct format_c16aprintf_data *__restrict __self, __SIZE_TYPE__ *__pstrlen),format_waprintf_pack,(__self,__pstrlen))
#elif (defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
__NAMESPACE_LOCAL_END
#include <libc/local/parts.wchar.format-printer/format_waprintf_pack.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_format_c16aprintf_pack __NAMESPACE_LOCAL_TYPEHAX(__CHAR16_TYPE__ *(__LIBDCALL*)(struct format_c16aprintf_data *__restrict,__SIZE_TYPE__ *),__CHAR16_TYPE__ *(__LIBDCALL&)(struct format_c16aprintf_data *__restrict,__SIZE_TYPE__ *),format_waprintf_pack)
#elif defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)
__NAMESPACE_LOCAL_END
#include <libc/local/parts.uchar.format-printer/format_c16aprintf_pack.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_format_c16aprintf_pack __LIBC_LOCAL_NAME(format_c16aprintf_pack)
#else /* ... */
#undef __local___localdep_format_c16aprintf_pack_defined
#endif /* !... */
#endif /* !__local___localdep_format_c16aprintf_pack_defined */
#ifndef __local___localdep_format_c16aprintf_printer_defined
#define __local___localdep_format_c16aprintf_printer_defined
#if defined(__CRT_HAVE_format_waprintf_printer) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),__SSIZE_TYPE__,__NOTHROW_NCX,__localdep_format_c16aprintf_printer,(void *__arg, __CHAR16_TYPE__ const *__restrict __data, __SIZE_TYPE__ __datalen),format_waprintf_printer,(__arg,__data,__datalen))
#elif defined(__CRT_HAVE_DOS$format_waprintf_printer)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),__SSIZE_TYPE__,__NOTHROW_NCX,__localdep_format_c16aprintf_printer,(void *__arg, __CHAR16_TYPE__ const *__restrict __data, __SIZE_TYPE__ __datalen),format_waprintf_printer,(__arg,__data,__datalen))
#elif (defined(__CRT_HAVE_format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
__NAMESPACE_LOCAL_END
#include <libc/local/parts.wchar.format-printer/format_waprintf_printer.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_format_c16aprintf_printer __NAMESPACE_LOCAL_TYPEHAX(__SSIZE_TYPE__(__LIBDCALL*)(void *,__CHAR16_TYPE__ const *__restrict,__SIZE_TYPE__),__SSIZE_TYPE__(__LIBDCALL&)(void *,__CHAR16_TYPE__ const *__restrict,__SIZE_TYPE__),format_waprintf_printer)
#elif (defined(__CRT_HAVE_format_waprintf_alloc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$format_waprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)
__NAMESPACE_LOCAL_END
#include <libc/local/parts.uchar.format-printer/format_c16aprintf_printer.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_format_c16aprintf_printer __LIBC_LOCAL_NAME(format_c16aprintf_printer)
#else /* ... */
#undef __local___localdep_format_c16aprintf_printer_defined
#endif /* !... */
#endif /* !__local___localdep_format_c16aprintf_printer_defined */
#ifndef __local___localdep_free_defined
#define __local___localdep_free_defined
#if __has_builtin(__builtin_free) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_free)
__CEIREDIRECT(,void,__NOTHROW_NCX,__localdep_free,(void *__mallptr),free,{ __builtin_free(__mallptr); })
#elif defined(__CRT_HAVE_free)
__CREDIRECT_VOID(,__NOTHROW_NCX,__localdep_free,(void *__mallptr),free,(__mallptr))
#elif defined(__CRT_HAVE_cfree)
__CREDIRECT_VOID(,__NOTHROW_NCX,__localdep_free,(void *__mallptr),cfree,(__mallptr))
#elif defined(__CRT_HAVE___libc_free)
__CREDIRECT_VOID(,__NOTHROW_NCX,__localdep_free,(void *__mallptr),__libc_free,(__mallptr))
#else /* ... */
#undef __local___localdep_free_defined
#endif /* !... */
#endif /* !__local___localdep_free_defined */
__NAMESPACE_LOCAL_END
#include <libc/errno.h>
#include <bits/crt/uformat-printer.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(convert_mbstoc16n) __ATTR_MALLOC __ATTR_WUNUSED __CHAR16_TYPE__ *
__NOTHROW_NCX(__LIBDCALL __LIBC_LOCAL_NAME(convert_mbstoc16n))(char const *__restrict __str, __SIZE_TYPE__ __len, __SIZE_TYPE__ *__preslen) {
	struct __local_format_waprintf_data {
		__CHAR16_TYPE__      *__ap_base;  /* [0..ap_used|ALLOC(ap_used+ap_avail)][owned] Buffer */
		__SIZE_TYPE__ __ap_avail; /* Unused buffer size */
		__SIZE_TYPE__ __ap_used;  /* Used buffer size */
	};
	struct __local_format_8tow_data {
		__pc16formatprinter __fd_printer;    /* [1..1] Inner printer */
		void             *__fd_arg;        /* Argument for `fd_printer' */
		__UINT32_TYPE__   __fd_incomplete; /* Incomplete utf-8 sequence part (initialize to 0) */
	};
	struct __local_format_waprintf_data __printer_data = { __NULLPTR, 0, 0 };
	struct __local_format_8tow_data __convert_data;
	__convert_data.__fd_printer    = &(__NAMESPACE_LOCAL_SYM __localdep_format_c16aprintf_printer);
	__convert_data.__fd_arg        = &__printer_data;
	__convert_data.__fd_incomplete = 0;

	if __unlikely((__NAMESPACE_LOCAL_SYM __localdep_format_8to16)(&__convert_data, __str, __len) < 0)



	{
#if defined(__CRT_HAVE_free) || defined(__CRT_HAVE_cfree) || defined(__CRT_HAVE___libc_free)
		(__NAMESPACE_LOCAL_SYM __localdep_free)(__printer_data.__ap_base);
#endif /* __CRT_HAVE_free || __CRT_HAVE_cfree || __CRT_HAVE___libc_free */
		return __NULLPTR;
	}
	return (__NAMESPACE_LOCAL_SYM __localdep_format_c16aprintf_pack)((struct format_c16aprintf_data *)&__printer_data, __preslen);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_convert_mbstoc16n_defined
#define __local___localdep_convert_mbstoc16n_defined
#define __localdep_convert_mbstoc16n __LIBC_LOCAL_NAME(convert_mbstoc16n)
#endif /* !__local___localdep_convert_mbstoc16n_defined */
#else /* ((__CRT_HAVE_format_waprintf_printer && __SIZEOF_WCHAR_T__ == 2 && __LIBCCALL_IS_LIBDCALL) || __CRT_HAVE_DOS$format_waprintf_printer || (__CRT_HAVE_format_waprintf_alloc && __SIZEOF_WCHAR_T__ == 2) || __CRT_HAVE_DOS$format_waprintf_alloc || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc) && ((__CRT_HAVE_format_waprintf_pack && __SIZEOF_WCHAR_T__ == 2 && __LIBCCALL_IS_LIBDCALL) || __CRT_HAVE_DOS$format_waprintf_pack || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc) */
#undef __local_convert_mbstoc16n_defined
#endif /* ((!__CRT_HAVE_format_waprintf_printer || __SIZEOF_WCHAR_T__ != 2 || !__LIBCCALL_IS_LIBDCALL) && !__CRT_HAVE_DOS$format_waprintf_printer && (!__CRT_HAVE_format_waprintf_alloc || __SIZEOF_WCHAR_T__ != 2) && !__CRT_HAVE_DOS$format_waprintf_alloc && !__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc) || ((!__CRT_HAVE_format_waprintf_pack || __SIZEOF_WCHAR_T__ != 2 || !__LIBCCALL_IS_LIBDCALL) && !__CRT_HAVE_DOS$format_waprintf_pack && !__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc) */
#endif /* !__local_convert_mbstoc16n_defined */