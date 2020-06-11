/* HASH CRC-32:0x972bac7d */
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
#ifndef __local_getwchar_unlocked_defined
#define __local_getwchar_unlocked_defined 1
#include <__crt.h>
#if (defined(__CRT_HAVE_fgetwc_unlocked) || (defined(__CRT_HAVE_DOS$fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_DOS$_fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 2)) && !defined(__NO_STDSTREAMS)
__NAMESPACE_LOCAL_BEGIN
/* Dependency: fgetwc_unlocked from wchar */
#ifndef __local___localdep_fgetwc_unlocked_defined
#define __local___localdep_fgetwc_unlocked_defined 1
#ifdef __CRT_HAVE_fgetwc_unlocked
__CREDIRECT(__ATTR_NONNULL((1)),__WINT_TYPE__,__THROWING,__localdep_fgetwc_unlocked,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4
__CREDIRECT_KOS(__ATTR_NONNULL((1)),__WINT_TYPE__,__THROWING,__localdep_fgetwc_unlocked,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$_fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 2
__CREDIRECT_DOS(__ATTR_NONNULL((1)),__WINT_TYPE__,__THROWING,__localdep_fgetwc_unlocked,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#else /* ... */
#undef __local___localdep_fgetwc_unlocked_defined
#endif /* !... */
#endif /* !__local___localdep_fgetwc_unlocked_defined */
__LOCAL_LIBC(getwchar_unlocked) __WINT_TYPE__
(__LIBCCALL __LIBC_LOCAL_NAME(getwchar_unlocked))(void) __THROWS(...) {
	return __localdep_fgetwc_unlocked(__LOCAL_stdin);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_getwchar_unlocked_defined
#define __local___localdep_getwchar_unlocked_defined 1
#define __localdep_getwchar_unlocked __LIBC_LOCAL_NAME(getwchar_unlocked)
#endif /* !__local___localdep_getwchar_unlocked_defined */
#else /* (__CRT_HAVE_fgetwc_unlocked || (__CRT_HAVE_DOS$fgetwc_unlocked && __SIZEOF_WCHAR_T__ == 4) || (__CRT_HAVE_DOS$_fgetwc_nolock && __SIZEOF_WCHAR_T__ == 2)) && !__NO_STDSTREAMS */
#undef __local_getwchar_unlocked_defined
#endif /* (!__CRT_HAVE_fgetwc_unlocked && (!__CRT_HAVE_DOS$fgetwc_unlocked || !__SIZEOF_WCHAR_T__ == 4) && (!__CRT_HAVE_DOS$_fgetwc_nolock || !__SIZEOF_WCHAR_T__ == 2)) || __NO_STDSTREAMS */
#endif /* !__local_getwchar_unlocked_defined */
