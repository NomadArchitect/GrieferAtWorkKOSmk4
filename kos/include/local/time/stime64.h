/* HASH CRC-32:0x15297f05 */
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
#ifndef __local_stime64_defined
#if defined(__CRT_HAVE_stime)
#define __local_stime64_defined 1
/* Dependency: "stime32" from "time" */
#ifndef ____localdep_stime32_defined
#define ____localdep_stime32_defined 1
#if defined(__CRT_HAVE_stime)
/* Set the system time to *WHEN. This call is restricted to the superuser */
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,__localdep_stime32,(__time32_t const *__when),stime,(__when))
#else /* LIBC: stime */
#undef ____localdep_stime32_defined
#endif /* stime32... */
#endif /* !____localdep_stime32_defined */

__NAMESPACE_LOCAL_BEGIN
/* Set the system time to *WHEN. This call is restricted to the superuser */
__LOCAL_LIBC(stime64) __ATTR_NONNULL((1)) int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(stime64))(__time64_t const *__when) {
#line 901 "kos/src/libc/magic/time.c"
	__time32_t __tms = (__time32_t)*__when;
	return __localdep_stime32(&__tms);
}
__NAMESPACE_LOCAL_END
#endif /* defined(__CRT_HAVE_stime) */
#endif /* !__local_stime64_defined */
