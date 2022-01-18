/* HASH CRC-32:0x172316d3 */
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
#ifndef __local_c32ttyname_defined
#define __local_c32ttyname_defined
#include <__crt.h>
#if (defined(__CRT_HAVE_wttyname_r) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$wttyname_r)
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_c32ttyname_r_defined
#define __local___localdep_c32ttyname_r_defined
#if defined(__CRT_HAVE_wttyname_r) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,__localdep_c32ttyname_r,(__fd_t __fd, __CHAR32_TYPE__ *__buf, __SIZE_TYPE__ __buflen),wttyname_r,(__fd,__buf,__buflen))
#elif defined(__CRT_HAVE_KOS$wttyname_r)
__CREDIRECT_KOS(__ATTR_NONNULL((2)),int,__NOTHROW_RPC,__localdep_c32ttyname_r,(__fd_t __fd, __CHAR32_TYPE__ *__buf, __SIZE_TYPE__ __buflen),wttyname_r,(__fd,__buf,__buflen))
#else /* ... */
#undef __local___localdep_c32ttyname_r_defined
#endif /* !... */
#endif /* !__local___localdep_c32ttyname_r_defined */
__LOCAL_LIBC(c32ttyname) __ATTR_WUNUSED __CHAR32_TYPE__ *
__NOTHROW_RPC(__LIBKCALL __LIBC_LOCAL_NAME(c32ttyname))(__fd_t __fd) {
	static __CHAR32_TYPE__ __buf[32];
	if __likely((__NAMESPACE_LOCAL_SYM __localdep_c32ttyname_r)(__fd, __buf, sizeof(__buf)) == 0)
		return __buf;
	return __NULLPTR;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_c32ttyname_defined
#define __local___localdep_c32ttyname_defined
#define __localdep_c32ttyname __LIBC_LOCAL_NAME(c32ttyname)
#endif /* !__local___localdep_c32ttyname_defined */
#else /* (__CRT_HAVE_wttyname_r && __SIZEOF_WCHAR_T__ == 4 && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_KOS$wttyname_r */
#undef __local_c32ttyname_defined
#endif /* (!__CRT_HAVE_wttyname_r || __SIZEOF_WCHAR_T__ != 4 || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_KOS$wttyname_r */
#endif /* !__local_c32ttyname_defined */