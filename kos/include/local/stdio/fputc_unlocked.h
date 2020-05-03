/* HASH CRC-32:0x1bdc73e7 */
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
#ifndef __local_fputc_unlocked_defined
#if (defined(__CRT_DOS) && defined(__CRT_HAVE__flsbuf)) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE_fwrite_s)
#define __local_fputc_unlocked_defined 1
#include <__crt.h>
#include <kos/anno.h>
/* Dependency: "_flsbuf" */
#ifndef ____localdep__flsbuf_defined
#define ____localdep__flsbuf_defined 1
#ifdef __CRT_HAVE__flsbuf
__CREDIRECT(__ATTR_NONNULL((2)),int,,__localdep__flsbuf,(int __ch, __FILE *__restrict __stream),_flsbuf,(__ch,__stream)) __THROWS(...)
#else /* LIBC: _flsbuf */
#undef ____localdep__flsbuf_defined
#endif /* _flsbuf... */
#endif /* !____localdep__flsbuf_defined */

/* Dependency: "crt_fwrite_unlocked" from "stdio" */
#ifndef ____localdep_crt_fwrite_unlocked_defined
#define ____localdep_crt_fwrite_unlocked_defined 1
#ifdef __CRT_HAVE_fwrite_unlocked
__CREDIRECT(__ATTR_NONNULL((1, 4)),__SIZE_TYPE__,,__localdep_crt_fwrite_unlocked,(void const *__restrict __buf, __SIZE_TYPE__ __elemsize, __SIZE_TYPE__ __elemcount, __FILE *__restrict __stream),fwrite_unlocked,(__buf,__elemsize,__elemcount,__stream)) __THROWS(...)
#elif defined(__CRT_HAVE__fwrite_nolock)
__CREDIRECT(__ATTR_NONNULL((1, 4)),__SIZE_TYPE__,,__localdep_crt_fwrite_unlocked,(void const *__restrict __buf, __SIZE_TYPE__ __elemsize, __SIZE_TYPE__ __elemcount, __FILE *__restrict __stream),_fwrite_nolock,(__buf,__elemsize,__elemcount,__stream)) __THROWS(...)
#elif defined(__CRT_HAVE__IO_fwrite)
__CREDIRECT(__ATTR_NONNULL((1, 4)),__SIZE_TYPE__,,__localdep_crt_fwrite_unlocked,(void const *__restrict __buf, __SIZE_TYPE__ __elemsize, __SIZE_TYPE__ __elemcount, __FILE *__restrict __stream),_IO_fwrite,(__buf,__elemsize,__elemcount,__stream)) __THROWS(...)
#elif defined(__CRT_HAVE_fwrite)
__CREDIRECT(__ATTR_NONNULL((1, 4)),__SIZE_TYPE__,,__localdep_crt_fwrite_unlocked,(void const *__restrict __buf, __SIZE_TYPE__ __elemsize, __SIZE_TYPE__ __elemcount, __FILE *__restrict __stream),fwrite,(__buf,__elemsize,__elemcount,__stream)) __THROWS(...)
#elif defined(__CRT_HAVE_fwrite_s)
__CREDIRECT(__ATTR_NONNULL((1, 4)),__SIZE_TYPE__,,__localdep_crt_fwrite_unlocked,(void const *__restrict __buf, __SIZE_TYPE__ __elemsize, __SIZE_TYPE__ __elemcount, __FILE *__restrict __stream),fwrite_s,(__buf,__elemsize,__elemcount,__stream)) __THROWS(...)
#else /* LIBC: fwrite_unlocked */
#undef ____localdep_crt_fwrite_unlocked_defined
#endif /* crt_fwrite_unlocked... */
#endif /* !____localdep_crt_fwrite_unlocked_defined */

__NAMESPACE_LOCAL_BEGIN
/* Same as `fputc()', but performs I/O without acquiring a lock to `STREAM' */
__LOCAL_LIBC(fputc_unlocked) __ATTR_NONNULL((2)) int
(__LIBCCALL __LIBC_LOCAL_NAME(fputc_unlocked))(int __ch,
                                               __FILE *__restrict __stream) __THROWS(...) {
#line 1219 "kos/src/libc/magic/stdio.c"
#if defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf))
	return --__stream->__f_cnt >= 0 ? (int)((__UINT8_TYPE__)(*__stream->__f_ptr++ = (char)__ch)) : __localdep__flsbuf(__ch, __stream);
#else
	unsigned char __byte = (unsigned char)(unsigned int)__ch;
	if (!__localdep_crt_fwrite_unlocked(&__byte, sizeof(unsigned char), 1, __stream))
		return __EOF;
	return __ch;
#endif
}
__NAMESPACE_LOCAL_END
#endif /* (__CRT_DOS && __CRT_HAVE__flsbuf) || __CRT_HAVE_fwrite_unlocked || __CRT_HAVE__fwrite_nolock || __CRT_HAVE__IO_fwrite || __CRT_HAVE_fwrite || __CRT_HAVE_fwrite_s */
#endif /* !__local_fputc_unlocked_defined */
