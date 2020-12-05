/* HASH CRC-32:0x2176d66c */
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
#ifndef __local_ctermid_defined
#define __local_ctermid_defined 1
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: strcpy from string */
#ifndef __local___localdep_strcpy_defined
#define __local___localdep_strcpy_defined 1
#if __has_builtin(__builtin_strcpy) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_strcpy)
/* >> strcpy(3)
 * Copy a NUL-terminated string `str' to `dst', and re-return `dst'.
 * The exact # of characters copied is `strlen(src) + 1' (+1 because
 * the trailing NUL-character is also copied) */
__CEIREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),char *,__NOTHROW_NCX,__localdep_strcpy,(char *__restrict __dst, char const *__restrict __src),strcpy,{ return __builtin_strcpy(__dst, __src); })
#elif defined(__CRT_HAVE_strcpy)
/* >> strcpy(3)
 * Copy a NUL-terminated string `str' to `dst', and re-return `dst'.
 * The exact # of characters copied is `strlen(src) + 1' (+1 because
 * the trailing NUL-character is also copied) */
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),char *,__NOTHROW_NCX,__localdep_strcpy,(char *__restrict __dst, char const *__restrict __src),strcpy,(__dst,__src))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/string/strcpy.h>
__NAMESPACE_LOCAL_BEGIN
/* >> strcpy(3)
 * Copy a NUL-terminated string `str' to `dst', and re-return `dst'.
 * The exact # of characters copied is `strlen(src) + 1' (+1 because
 * the trailing NUL-character is also copied) */
#define __localdep_strcpy __LIBC_LOCAL_NAME(strcpy)
#endif /* !... */
#endif /* !__local___localdep_strcpy_defined */
/* >> ctermid(3)
 * Writes the string "/dev/tty" to `s', or returns a pointer to
 * a writable data location that contains that same string. */
__LOCAL_LIBC(ctermid) __ATTR_RETNONNULL char *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(ctermid))(char *__s) {
	static char __buf[9];
	if (__s == __NULLPTR)
		__s = __buf;
	return __localdep_strcpy(__s, "/dev/tty");
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_ctermid_defined
#define __local___localdep_ctermid_defined 1
#define __localdep_ctermid __LIBC_LOCAL_NAME(ctermid)
#endif /* !__local___localdep_ctermid_defined */
#endif /* !__local_ctermid_defined */