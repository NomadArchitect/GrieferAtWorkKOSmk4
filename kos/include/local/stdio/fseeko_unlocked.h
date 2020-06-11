/* HASH CRC-32:0xc43e77c5 */
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
#ifndef __local_fseeko_unlocked_defined
#define __local_fseeko_unlocked_defined 1
#include <__crt.h>
#if defined(__CRT_HAVE_fseeko64) || defined(__CRT_HAVE_fseeko64_unlocked) || defined(__CRT_HAVE__fseeki64_nolock) || defined(__CRT_HAVE__fseeki64) || defined(__CRT_HAVE_fseeko) || defined(__CRT_HAVE_fseeko_unlocked) || defined(__CRT_HAVE_fseek) || defined(__CRT_HAVE_fseek_unlocked) || defined(__CRT_HAVE__fseek_nolock)
__NAMESPACE_LOCAL_BEGIN
/* Dependency: fseeko from stdio */
#ifndef __local___localdep_fseeko_defined
#define __local___localdep_fseeko_defined 1
#if defined(__CRT_HAVE_fseeko64_unlocked) && defined(__USE_STDIO_UNLOCKED) && defined(__USE_FILE_OFFSET64)
/* Change the current in-file position of `STREAM' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__THROWING,__localdep_fseeko,(__FILE *__restrict __stream, __FS_TYPE(off) __off, int __whence),fseeko64_unlocked,(__stream,__off,__whence))
#elif defined(__CRT_HAVE__fseeki64_nolock) && defined(__USE_STDIO_UNLOCKED) && defined(__USE_FILE_OFFSET64)
/* Change the current in-file position of `STREAM' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__THROWING,__localdep_fseeko,(__FILE *__restrict __stream, __FS_TYPE(off) __off, int __whence),_fseeki64_nolock,(__stream,__off,__whence))
#elif defined(__CRT_HAVE_fseeko_unlocked) && defined(__USE_STDIO_UNLOCKED) && !defined(__USE_FILE_OFFSET64)
/* Change the current in-file position of `STREAM' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__THROWING,__localdep_fseeko,(__FILE *__restrict __stream, __FS_TYPE(off) __off, int __whence),fseeko_unlocked,(__stream,__off,__whence))
#elif defined(__CRT_HAVE_fseek_unlocked) && ((defined(__USE_STDIO_UNLOCKED) && defined(__USE_FILE_OFFSET64) && __SIZEOF_OFF64_T__ == __SIZEOF_LONG__) || (!defined(__USE_FILE_OFFSET64) && __SIZEOF_OFF32_T__ == __SIZEOF_LONG__))
/* Change the current in-file position of `STREAM' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__THROWING,__localdep_fseeko,(__FILE *__restrict __stream, __FS_TYPE(off) __off, int __whence),fseek_unlocked,(__stream,__off,__whence))
#elif defined(__CRT_HAVE__fseek_nolock) && ((defined(__USE_STDIO_UNLOCKED) && defined(__USE_FILE_OFFSET64) && __SIZEOF_OFF64_T__ == __SIZEOF_LONG__) || (!defined(__USE_FILE_OFFSET64) && __SIZEOF_OFF32_T__ == __SIZEOF_LONG__))
/* Change the current in-file position of `STREAM' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__THROWING,__localdep_fseeko,(__FILE *__restrict __stream, __FS_TYPE(off) __off, int __whence),_fseek_nolock,(__stream,__off,__whence))
#elif defined(__CRT_HAVE_fseeko64) && defined(__USE_FILE_OFFSET64)
/* Change the current in-file position of `STREAM' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__THROWING,__localdep_fseeko,(__FILE *__restrict __stream, __FS_TYPE(off) __off, int __whence),fseeko64,(__stream,__off,__whence))
#elif defined(__CRT_HAVE__fseeki64) && defined(__USE_FILE_OFFSET64)
/* Change the current in-file position of `STREAM' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__THROWING,__localdep_fseeko,(__FILE *__restrict __stream, __FS_TYPE(off) __off, int __whence),_fseeki64,(__stream,__off,__whence))
#elif defined(__CRT_HAVE_fseeko) && !defined(__USE_FILE_OFFSET64)
/* Change the current in-file position of `STREAM' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__THROWING,__localdep_fseeko,(__FILE *__restrict __stream, __FS_TYPE(off) __off, int __whence),fseeko,(__stream,__off,__whence))
#elif defined(__CRT_HAVE_fseek) && ((defined(__USE_FILE_OFFSET64) && __SIZEOF_OFF64_T__ == __SIZEOF_LONG__) || (!defined(__USE_FILE_OFFSET64) && __SIZEOF_OFF32_T__ == __SIZEOF_LONG__))
/* Change the current in-file position of `STREAM' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__THROWING,__localdep_fseeko,(__FILE *__restrict __stream, __FS_TYPE(off) __off, int __whence),fseek,(__stream,__off,__whence))
#elif defined(__CRT_HAVE_fseek_unlocked) && ((defined(__USE_FILE_OFFSET64) && __SIZEOF_OFF64_T__ == __SIZEOF_LONG__) || (!defined(__USE_FILE_OFFSET64) && __SIZEOF_OFF32_T__ == __SIZEOF_LONG__))
/* Change the current in-file position of `STREAM' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__THROWING,__localdep_fseeko,(__FILE *__restrict __stream, __FS_TYPE(off) __off, int __whence),fseek_unlocked,(__stream,__off,__whence))
#elif defined(__CRT_HAVE__fseek_nolock) && ((defined(__USE_FILE_OFFSET64) && __SIZEOF_OFF64_T__ == __SIZEOF_LONG__) || (!defined(__USE_FILE_OFFSET64) && __SIZEOF_OFF32_T__ == __SIZEOF_LONG__))
/* Change the current in-file position of `STREAM' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__THROWING,__localdep_fseeko,(__FILE *__restrict __stream, __FS_TYPE(off) __off, int __whence),_fseek_nolock,(__stream,__off,__whence))
#elif defined(__CRT_HAVE_fseeko64_unlocked) && defined(__USE_FILE_OFFSET64)
/* Change the current in-file position of `STREAM' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__THROWING,__localdep_fseeko,(__FILE *__restrict __stream, __FS_TYPE(off) __off, int __whence),fseeko64_unlocked,(__stream,__off,__whence))
#elif defined(__CRT_HAVE__fseeki64_nolock) && defined(__USE_FILE_OFFSET64)
/* Change the current in-file position of `STREAM' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__THROWING,__localdep_fseeko,(__FILE *__restrict __stream, __FS_TYPE(off) __off, int __whence),_fseeki64_nolock,(__stream,__off,__whence))
#elif defined(__CRT_HAVE_fseeko_unlocked) && !defined(__USE_FILE_OFFSET64)
/* Change the current in-file position of `STREAM' */
__CREDIRECT(__ATTR_NONNULL((1)),int,__THROWING,__localdep_fseeko,(__FILE *__restrict __stream, __FS_TYPE(off) __off, int __whence),fseeko_unlocked,(__stream,__off,__whence))
#elif defined(__CRT_HAVE_fseeko64) || defined(__CRT_HAVE_fseeko64_unlocked) || defined(__CRT_HAVE__fseeki64_nolock) || defined(__CRT_HAVE__fseeki64) || defined(__CRT_HAVE_fseeko) || defined(__CRT_HAVE_fseeko_unlocked) || defined(__CRT_HAVE_fseek) || defined(__CRT_HAVE_fseek_unlocked) || defined(__CRT_HAVE__fseek_nolock)
__NAMESPACE_LOCAL_END
#include <local/stdio/fseeko.h>
__NAMESPACE_LOCAL_BEGIN
/* Change the current in-file position of `STREAM' */
#define __localdep_fseeko __LIBC_LOCAL_NAME(fseeko)
#else /* ... */
#undef __local___localdep_fseeko_defined
#endif /* !... */
#endif /* !__local___localdep_fseeko_defined */
__LOCAL_LIBC(fseeko_unlocked) __ATTR_NONNULL((1)) int
(__LIBCCALL __LIBC_LOCAL_NAME(fseeko_unlocked))(__FILE *__restrict __stream, __FS_TYPE(off) __off, int __whence) __THROWS(...) {
	return __localdep_fseeko(__stream, __off, __whence);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_fseeko_unlocked_defined
#define __local___localdep_fseeko_unlocked_defined 1
#define __localdep_fseeko_unlocked __LIBC_LOCAL_NAME(fseeko_unlocked)
#endif /* !__local___localdep_fseeko_unlocked_defined */
#else /* __CRT_HAVE_fseeko64 || __CRT_HAVE_fseeko64_unlocked || __CRT_HAVE__fseeki64_nolock || __CRT_HAVE__fseeki64 || __CRT_HAVE_fseeko || __CRT_HAVE_fseeko_unlocked || __CRT_HAVE_fseek || __CRT_HAVE_fseek_unlocked || __CRT_HAVE__fseek_nolock */
#undef __local_fseeko_unlocked_defined
#endif /* !__CRT_HAVE_fseeko64 && !__CRT_HAVE_fseeko64_unlocked && !__CRT_HAVE__fseeki64_nolock && !__CRT_HAVE__fseeki64 && !__CRT_HAVE_fseeko && !__CRT_HAVE_fseeko_unlocked && !__CRT_HAVE_fseek && !__CRT_HAVE_fseek_unlocked && !__CRT_HAVE__fseek_nolock */
#endif /* !__local_fseeko_unlocked_defined */
