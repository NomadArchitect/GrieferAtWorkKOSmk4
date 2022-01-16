/* HASH CRC-32:0xf9abda17 */
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
#ifndef __local_strtod_defined
#define __local_strtod_defined
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_format_scanf_defined
#define __local___localdep_format_scanf_defined
#ifdef __CRT_HAVE_format_scanf
__NAMESPACE_LOCAL_END
#include <kos/anno.h>
#include <bits/crt/format-printer.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__LIBC __ATTR_LIBC_SCANF(4, 5) __ATTR_NONNULL((1, 2, 4)) __SSIZE_TYPE__ (__VLIBCCALL __localdep_format_scanf)(__pformatgetc __pgetc, __pformatungetc __pungetc, void *__arg, char const *__restrict __format, ...) __THROWS(...) __CASMNAME("format_scanf");
#else /* __CRT_HAVE_format_scanf */
__NAMESPACE_LOCAL_END
#include <libc/local/format-printer/format_scanf.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_format_scanf __LIBC_LOCAL_NAME(format_scanf)
#endif /* !__CRT_HAVE_format_scanf */
#endif /* !__local___localdep_format_scanf_defined */
#ifndef __local___localdep_unicode_readutf8_defined
#define __local___localdep_unicode_readutf8_defined
#ifdef __CRT_HAVE_unicode_readutf8
__CREDIRECT(__ATTR_NONNULL((1)),__CHAR32_TYPE__,__NOTHROW_NCX,__localdep_unicode_readutf8,(char const **__restrict __ptext),unicode_readutf8,(__ptext))
#else /* __CRT_HAVE_unicode_readutf8 */
__NAMESPACE_LOCAL_END
#include <libc/local/unicode/unicode_readutf8.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_unicode_readutf8 __LIBC_LOCAL_NAME(unicode_readutf8)
#endif /* !__CRT_HAVE_unicode_readutf8 */
#endif /* !__local___localdep_unicode_readutf8_defined */
#ifndef __local___localdep_unicode_readutf8_rev_defined
#define __local___localdep_unicode_readutf8_rev_defined
#ifdef __CRT_HAVE_unicode_readutf8_rev
__CREDIRECT(__ATTR_NONNULL((1)),__CHAR32_TYPE__,__NOTHROW_NCX,__localdep_unicode_readutf8_rev,(char const **__restrict __ptext),unicode_readutf8_rev,(__ptext))
#else /* __CRT_HAVE_unicode_readutf8_rev */
__NAMESPACE_LOCAL_END
#include <libc/local/unicode/unicode_readutf8_rev.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_unicode_readutf8_rev __LIBC_LOCAL_NAME(unicode_readutf8_rev)
#endif /* !__CRT_HAVE_unicode_readutf8_rev */
#endif /* !__local___localdep_unicode_readutf8_rev_defined */
__NAMESPACE_LOCAL_END
#include <asm/crt/stdio.h>
#if __SIZEOF_CHAR__ == 1
#ifndef ____vsscanf_getc_defined
#define ____vsscanf_getc_defined
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(vsscanf_getc) __SSIZE_TYPE__
(__FORMATPRINTER_CC __vsscanf_getc)(void *__arg) {
	char const *__reader = *(char const **)__arg;
	__CHAR32_TYPE__ __result = (__NAMESPACE_LOCAL_SYM __localdep_unicode_readutf8)(&__reader);
	if (!__result)
		return __EOF;
	*(char const **)__arg = __reader;
	return __result;
}
__LOCAL_LIBC(vsscanf_ungetc) __SSIZE_TYPE__
(__FORMATPRINTER_CC __vsscanf_ungetc)(void *__arg, __CHAR32_TYPE__ __UNUSED(__ch)) {
	(__NAMESPACE_LOCAL_SYM __localdep_unicode_readutf8_rev)((char const **)__arg);
	return 0;
}
__NAMESPACE_LOCAL_END
#endif /* !____vsscanf_getc_defined */

#elif __SIZEOF_CHAR__ == 2
#ifndef ____vsc16scanf_getc_defined
#define ____vsc16scanf_getc_defined
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(vsc16scanf_getc) __SSIZE_TYPE__
(__FORMATPRINTER_CC __vsc16scanf_getc)(void *__arg) {
	__CHAR16_TYPE__ const *__reader = *(__CHAR16_TYPE__ const **)__arg;
	__CHAR32_TYPE__ __result = __unicode_readutf16(&__reader);
	if (!__result)
		return __EOF;
	*(__CHAR16_TYPE__ const **)__arg = __reader;
	return __result;
}
__LOCAL_LIBC(vsc16scanf_ungetc) __SSIZE_TYPE__
(__FORMATPRINTER_CC __vsc16scanf_ungetc)(void *__arg, __CHAR32_TYPE__ __UNUSED(__ch)) {
	__unicode_readutf16_rev((__CHAR16_TYPE__ const **)__arg);
	return 0;
}
__NAMESPACE_LOCAL_END
#endif /* !____vsc16scanf_getc_defined */

#else /* ... */
#ifndef ____vsc32scanf_getc_defined
#define ____vsc32scanf_getc_defined
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(vsc32scanf_getc) __SSIZE_TYPE__
(__FORMATPRINTER_CC __vsc32scanf_getc)(void *__arg) {
	__CHAR32_TYPE__ const *__reader = *(__CHAR32_TYPE__ const **)__arg;
	__CHAR32_TYPE__ __result = *__reader++;
	if (!__result)
		return __EOF;
	*(__CHAR32_TYPE__ const **)__arg = __reader;
	return __result;
}
__LOCAL_LIBC(vsc32scanf_ungetc) __SSIZE_TYPE__
(__FORMATPRINTER_CC __vsc32scanf_ungetc)(void *__arg, __CHAR32_TYPE__ __UNUSED(__ch)) {
	--*(__CHAR32_TYPE__ const **)__arg;
	return 0;
}
__NAMESPACE_LOCAL_END
#endif /* !____vsc32scanf_getc_defined */

#endif /* !... */
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(strtod) __ATTR_LEAF __ATTR_NONNULL((1)) double
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(strtod))(char const *__restrict __nptr, char **__endptr) {
	double __result;
	char const *__text_pointer = __nptr;

	if (!(__NAMESPACE_LOCAL_SYM __localdep_format_scanf)(&__NAMESPACE_LOCAL_SYM __vsscanf_getc,
	                  &__NAMESPACE_LOCAL_SYM __vsscanf_ungetc,
	                  (void *)&__text_pointer, "%lf", &__result))
		__result = 0.0;











	if (__endptr)
		*__endptr = (char *)__text_pointer;
	return __result;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_strtod_defined
#define __local___localdep_strtod_defined
#define __localdep_strtod __LIBC_LOCAL_NAME(strtod)
#endif /* !__local___localdep_strtod_defined */
#endif /* !__local_strtod_defined */
