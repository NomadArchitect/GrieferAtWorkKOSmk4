/* HASH CRC-32:0x9ccf15a8 */
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
#ifndef __local_c32sto64_r_defined
#define __local_c32sto64_r_defined
#include <__crt.h>
#include <features.h>
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_isspace32_defined
#define __local___localdep_isspace32_defined
__NAMESPACE_LOCAL_END
#include <bits/crt/wctype.h>
__NAMESPACE_LOCAL_BEGIN
#if defined(__crt_iswspace) && defined(__CRT_HAVE_iswspace) && __SIZEOF_WCHAR_T__ == 4
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__COMPILER_CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__LIBKCALL,__localdep_isspace32,(__WINT32_TYPE__ __wc),iswspace,{ return __crt_iswspace(__wc); })
#elif defined(__crt_iswspace) && __SIZEOF_WCHAR_T__ == 4
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL __ATTR_CONST __ATTR_WUNUSED int __NOTHROW(__LIBKCALL __localdep_isspace32)(__WINT32_TYPE__ __wc) { return __crt_iswspace(__wc); }
#elif __has_builtin(__builtin_iswspace) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_iswspace) && __SIZEOF_WCHAR_T__ == 4
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__COMPILER_CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__LIBKCALL,__localdep_isspace32,(__WINT32_TYPE__ __wc),iswspace,{ return __builtin_iswspace(__wc); })
#elif defined(__CRT_HAVE_iswspace) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_isspace32,(__WINT32_TYPE__ __wc),iswspace,(__wc))
#elif defined(__CRT_HAVE_KOS$iswspace)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT_KOS(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_isspace32,(__WINT32_TYPE__ __wc),iswspace,(__wc))
#elif __SIZEOF_WCHAR_T__ == 4
__NAMESPACE_LOCAL_END
#include <libc/local/wctype/iswspace.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_isspace32 __NAMESPACE_LOCAL_TYPEHAX(int(__LIBKCALL*)(__WINT32_TYPE__),int(__LIBKCALL&)(__WINT32_TYPE__),iswspace)
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/parts.uchar.wctype/isspace32.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_isspace32 __LIBC_LOCAL_NAME(isspace32)
#endif /* !... */
#endif /* !__local___localdep_isspace32_defined */
__NAMESPACE_LOCAL_END
#include <asm/os/errno.h>
#include <hybrid/__overflow.h>
#include <hybrid/limitcore.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(c32sto64_r) __ATTR_LEAF __ATTR_NONNULL((1)) __INT64_TYPE__
__NOTHROW_NCX(__LIBKCALL __LIBC_LOCAL_NAME(c32sto64_r))(__CHAR32_TYPE__ const *__restrict __nptr, __CHAR32_TYPE__ **__endptr, __STDC_INT_AS_UINT_T __base, __errno_t *__error) {
	__INT64_TYPE__ __result;
	__CHAR32_TYPE__ __sign;
	__CHAR32_TYPE__ const *__num_start = __nptr;
	__CHAR32_TYPE__ const *__num_iter;
	while ((__NAMESPACE_LOCAL_SYM __localdep_isspace32)(*__num_start))
		++__num_start;
	__sign = *__num_start;
	if (__sign == '-' || __sign == '+')
		++__num_start;
	if (__base == 0) {
		/* Automatically deduce base. */
		if (*__num_start == '0') {
			++__num_start;
			if (*__num_start == 'x' || *__num_start == 'X') {
				__base = 16;
				++__num_start;
			} else if (*__num_start == 'b' || *__num_start == 'B') {
				__base = 2;
				++__num_start;
			} else {
				__base = 8;
				/* Don't  consume the `0',  but handle it implicitly.
				 * That way, we can just always check that the number
				 * part of the integer is non-empty! */
				--__num_start;
			}
		} else {
			__base = 10;
		}
	}
	__num_iter = __num_start;
	__result   = 0;
	for (;;) {
		__UINT8_TYPE__ __digit;
		__CHAR32_TYPE__ __ch;
		__ch = *__num_iter;
		if (__ch >= '0' && __ch <= '9')
			__digit = (__UINT8_TYPE__)(__ch - '0');
		else if (__ch >= 'a' && __ch <= 'z')
			__digit = (__UINT8_TYPE__)(10 + __ch - 'a');
		else if (__ch >= 'A' && __ch <= 'Z')
			__digit = (__UINT8_TYPE__)(10 + __ch - 'A');
		else {
			break;
		}
		if (__digit >= __base)
			break;
		++__num_iter;
		if __unlikely(__hybrid_overflow_smul(__result, (unsigned int)__base, &__result) ||
		            __hybrid_overflow_sadd(__result, __digit, &__result)) {
__handle_overflow:
			/* Integer overflow. */
			if (__error) {
#ifdef __ERANGE
				*__error = __ERANGE;
#else /* __ERANGE */
				*__error = 1;
#endif /* !__ERANGE */
			}
			if (__endptr) {
				for (;;) {
					__ch = *__num_iter;
					if (__ch >= '0' && __ch <= '9')
						__digit = (__UINT8_TYPE__)(__ch - '0');
					else if (__ch >= 'a' && __ch <= 'z')
						__digit = (__UINT8_TYPE__)(10 + __ch - 'a');
					else if (__ch >= 'A' && __ch <= 'Z')
						__digit = (__UINT8_TYPE__)(10 + __ch - 'A');
					else {
						break;
					}
					if (__digit >= __base)
						break;
					++__num_iter;
				}
				*__endptr = (__CHAR32_TYPE__ *)__num_iter;
			}
			if (__sign == '-')
				return __INT64_MIN__;
			return __INT64_MAX__;
		}
	}
	if (__sign == '-') {
		__result = -__result;
		if __unlikely(__result > 0)
			goto __handle_overflow; /* Overflow... */
	}
	if __unlikely(__num_iter == __num_start) {
		/* Check for special case: `0xGARBAGE'.
		 * -> In this case, return `0' and set `endptr' to `x' */
		if ((__base == 16 || __base == 2) && __num_start > __nptr) {
			__CHAR32_TYPE__ const *__nptr_ps = __nptr;
			while ((__NAMESPACE_LOCAL_SYM __localdep_isspace32)(*__nptr_ps))
				++__nptr_ps;
			if (__num_start > __nptr_ps && *__nptr_ps == '0') {
				if (__endptr)
					*__endptr = (__CHAR32_TYPE__ *)__nptr_ps + 1;
				if (__error)
					*__error = 0;
				return 0;
			}
		}

		/* Empty number... */
		if (__error) {
#ifdef __ECANCELED
			*__error = __ECANCELED;
#else /* __ECANCELED */
			*__error = 1;
#endif /* !__ECANCELED */
		}
		/* Set endptr to the original `nptr' (_before_ leading spaces were skipped) */
		if (__endptr)
			*__endptr = (__CHAR32_TYPE__ *)__nptr;
	} else {
		if (__endptr) {
			*__endptr = (__CHAR32_TYPE__ *)__num_iter;
			if (__error)
				*__error = 0;
		} else if (__error) {
			*__error = 0;
			/* Check for `EINVAL' */
			if __unlikely(*__num_iter) {
				while ((__NAMESPACE_LOCAL_SYM __localdep_isspace32)(*__num_iter))
					++__num_iter;
				if (*__num_iter) {
#ifdef __EINVAL
					*__error = __EINVAL;
#else /* __EINVAL */
					*__error = 1;
#endif /* !__EINVAL */
				}
			}
		}
	}
	return __result;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_c32sto64_r_defined
#define __local___localdep_c32sto64_r_defined
#define __localdep_c32sto64_r __LIBC_LOCAL_NAME(c32sto64_r)
#endif /* !__local___localdep_c32sto64_r_defined */
#endif /* !__local_c32sto64_r_defined */
