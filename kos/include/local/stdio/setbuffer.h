/* HASH CRC-32:0x126652a3 */
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
#ifndef __local_setbuffer_defined
#define __local_setbuffer_defined 1
#include <__crt.h>
#if defined(__CRT_HAVE_setvbuf) || defined(__CRT_HAVE__IO_setvbuf) || defined(__CRT_HAVE_setvbuf_unlocked)
__NAMESPACE_LOCAL_BEGIN
/* Dependency: setvbuf from stdio */
#ifndef __local___localdep_setvbuf_defined
#define __local___localdep_setvbuf_defined 1
#if defined(__CRT_HAVE_setvbuf_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* Set the buffer and buffer-mode to-be used by the given `STREAM'
 * @param modes: One of `_IOFBF', `_IOLBF' or `_IONBF' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,__localdep_setvbuf,(__FILE *__restrict __stream, char *__restrict __buf, int __modes, __SIZE_TYPE__ __bufsize),setvbuf_unlocked,(__stream,__buf,__modes,__bufsize))
#elif defined(__CRT_HAVE_setvbuf)
/* Set the buffer and buffer-mode to-be used by the given `STREAM'
 * @param modes: One of `_IOFBF', `_IOLBF' or `_IONBF' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,__localdep_setvbuf,(__FILE *__restrict __stream, char *__restrict __buf, int __modes, __SIZE_TYPE__ __bufsize),setvbuf,(__stream,__buf,__modes,__bufsize))
#elif defined(__CRT_HAVE__IO_setvbuf)
/* Set the buffer and buffer-mode to-be used by the given `STREAM'
 * @param modes: One of `_IOFBF', `_IOLBF' or `_IONBF' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,__localdep_setvbuf,(__FILE *__restrict __stream, char *__restrict __buf, int __modes, __SIZE_TYPE__ __bufsize),_IO_setvbuf,(__stream,__buf,__modes,__bufsize))
#elif defined(__CRT_HAVE_setvbuf_unlocked)
/* Set the buffer and buffer-mode to-be used by the given `STREAM'
 * @param modes: One of `_IOFBF', `_IOLBF' or `_IONBF' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,__localdep_setvbuf,(__FILE *__restrict __stream, char *__restrict __buf, int __modes, __SIZE_TYPE__ __bufsize),setvbuf_unlocked,(__stream,__buf,__modes,__bufsize))
#else /* ... */
#undef __local___localdep_setvbuf_defined
#endif /* !... */
#endif /* !__local___localdep_setvbuf_defined */
/* Specify the location and size for the buffer to-be used by `STREAM' */
__LOCAL_LIBC(setbuffer) __ATTR_NONNULL((1)) void
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(setbuffer))(__FILE *__restrict __stream, char *__buf, __SIZE_TYPE__ __bufsize) {
	__localdep_setvbuf(__stream,
	        __buf,
	        __buf ? ___IOFBF : ___IONBF,
	        __buf ? __bufsize : (__SIZE_TYPE__)0);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_setbuffer_defined
#define __local___localdep_setbuffer_defined 1
#define __localdep_setbuffer __LIBC_LOCAL_NAME(setbuffer)
#endif /* !__local___localdep_setbuffer_defined */
#else /* __CRT_HAVE_setvbuf || __CRT_HAVE__IO_setvbuf || __CRT_HAVE_setvbuf_unlocked */
#undef __local_setbuffer_defined
#endif /* !__CRT_HAVE_setvbuf && !__CRT_HAVE__IO_setvbuf && !__CRT_HAVE_setvbuf_unlocked */
#endif /* !__local_setbuffer_defined */
