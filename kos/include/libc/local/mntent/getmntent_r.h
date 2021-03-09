/* HASH CRC-32:0x46d6bf0d */
/* Copyright (c) 2019-2021 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2021 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_getmntent_r_defined
#define __local_getmntent_r_defined 1
#include <__crt.h>
#include <features.h>
#if defined(__CRT_HAVE_fgets) || defined(__CRT_HAVE_fgets_unlocked) || ((defined(__CRT_HAVE_fgetc) || defined(__CRT_HAVE_getc) || defined(__CRT_HAVE__IO_getc) || defined(__CRT_HAVE_fgetc_unlocked) || defined(__CRT_HAVE_getc_unlocked) || (defined(__CRT_DOS) && defined(__CRT_HAVE__filbuf)) || defined(__CRT_HAVE_fread) || defined(__CRT_HAVE__IO_fread) || defined(__CRT_HAVE_fread_unlocked) || defined(__CRT_HAVE__fread_nolock)) && (defined(__CRT_HAVE_ungetc) || defined(__CRT_HAVE__IO_ungetc) || defined(__CRT_HAVE_ungetc_unlocked) || defined(__CRT_HAVE__ungetc_nolock)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked)))
#include <bits/crt/db/mntent.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: fgets from stdio */
#ifndef __local___localdep_fgets_defined
#define __local___localdep_fgets_defined 1
#if defined(__CRT_HAVE_fgets_unlocked) && defined(__USE_STDIO_UNLOCKED)
__NAMESPACE_LOCAL_END
#include <kos/anno.h>
__NAMESPACE_LOCAL_BEGIN
/* Read up to `BUFSIZE - 1' bytes of data from `STREAM', storing them into `BUF' stopped when
 * the buffer is full or a line-feed was read (in this case, the line-feed is also written to `BUF')
 * Afterwards, append a trailing NUL-character and re-return `BUF', or return `NULL' if an error occurred. */
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 3)),char *,__THROWING,__localdep_fgets,(char *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),fgets_unlocked,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_fgets)
__NAMESPACE_LOCAL_END
#include <kos/anno.h>
__NAMESPACE_LOCAL_BEGIN
/* Read up to `BUFSIZE - 1' bytes of data from `STREAM', storing them into `BUF' stopped when
 * the buffer is full or a line-feed was read (in this case, the line-feed is also written to `BUF')
 * Afterwards, append a trailing NUL-character and re-return `BUF', or return `NULL' if an error occurred. */
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 3)),char *,__THROWING,__localdep_fgets,(char *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),fgets,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_fgets_unlocked)
__NAMESPACE_LOCAL_END
#include <kos/anno.h>
__NAMESPACE_LOCAL_BEGIN
/* Read up to `BUFSIZE - 1' bytes of data from `STREAM', storing them into `BUF' stopped when
 * the buffer is full or a line-feed was read (in this case, the line-feed is also written to `BUF')
 * Afterwards, append a trailing NUL-character and re-return `BUF', or return `NULL' if an error occurred. */
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 3)),char *,__THROWING,__localdep_fgets,(char *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),fgets_unlocked,(__buf,__bufsize,__stream))
#elif (defined(__CRT_HAVE_fgetc) || defined(__CRT_HAVE_getc) || defined(__CRT_HAVE__IO_getc) || defined(__CRT_HAVE_fgetc_unlocked) || defined(__CRT_HAVE_getc_unlocked) || (defined(__CRT_DOS) && defined(__CRT_HAVE__filbuf)) || defined(__CRT_HAVE_fread) || defined(__CRT_HAVE__IO_fread) || defined(__CRT_HAVE_fread_unlocked) || defined(__CRT_HAVE__fread_nolock)) && (defined(__CRT_HAVE_ungetc) || defined(__CRT_HAVE__IO_ungetc) || defined(__CRT_HAVE_ungetc_unlocked) || defined(__CRT_HAVE__ungetc_nolock)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked))
__NAMESPACE_LOCAL_END
#include <libc/local/stdio/fgets.h>
__NAMESPACE_LOCAL_BEGIN
/* Read up to `BUFSIZE - 1' bytes of data from `STREAM', storing them into `BUF' stopped when
 * the buffer is full or a line-feed was read (in this case, the line-feed is also written to `BUF')
 * Afterwards, append a trailing NUL-character and re-return `BUF', or return `NULL' if an error occurred. */
#define __localdep_fgets __LIBC_LOCAL_NAME(fgets)
#else /* ... */
#undef __local___localdep_fgets_defined
#endif /* !... */
#endif /* !__local___localdep_fgets_defined */
/* Dependency: isdigit from ctype */
#ifndef __local___localdep_isdigit_defined
#define __local___localdep_isdigit_defined 1
#if __has_builtin(__builtin_isdigit) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_isdigit)
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_isdigit,(int __ch),isdigit,{ return __builtin_isdigit(__ch); })
#elif defined(__CRT_HAVE_isdigit)
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_isdigit,(int __ch),isdigit,(__ch))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/ctype/isdigit.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_isdigit __LIBC_LOCAL_NAME(isdigit)
#endif /* !... */
#endif /* !__local___localdep_isdigit_defined */
/* Dependency: isspace from ctype */
#ifndef __local___localdep_isspace_defined
#define __local___localdep_isspace_defined 1
#if __has_builtin(__builtin_isspace) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_isspace)
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_isspace,(int __ch),isspace,{ return __builtin_isspace(__ch); })
#elif defined(__CRT_HAVE_isspace)
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_isspace,(int __ch),isspace,(__ch))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/ctype/isspace.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_isspace __LIBC_LOCAL_NAME(isspace)
#endif /* !... */
#endif /* !__local___localdep_isspace_defined */
/* >> getmntent(3), getmntent_r(3) */
__LOCAL_LIBC(getmntent_r) __ATTR_NONNULL((1, 2, 3)) struct mntent *
__NOTHROW_RPC(__LIBCCALL __LIBC_LOCAL_NAME(getmntent_r))(__FILE *__restrict __stream, struct mntent *__restrict __result, char *__restrict __buffer, __STDC_INT_AS_SIZE_T __bufsize) {
	char *__line;
	do {
		__line = __localdep_fgets(__buffer, __bufsize, __stream);
		if (!__line)
			goto __err;
		while (*__line && __localdep_isspace(*__line))
			++__line;
	} while (*__line == '#');

	__result->mnt_fsname = __line;
	while (*__line && !__localdep_isspace(*__line))
		++__line;
	if (!*__line)
		goto __err;
	*__line++ = '\0';
	while (*__line && __localdep_isspace(*__line))
		++__line;

	__result->mnt_dir = __line;
	while (*__line && !__localdep_isspace(*__line))
		++__line;
	if (!*__line)
		goto __err;
	*__line++ = '\0';
	while (*__line && __localdep_isspace(*__line))
		++__line;

	__result->mnt_type = __line;
	while (*__line && !__localdep_isspace(*__line))
		++__line;
	if (!*__line)
		goto __err;
	*__line++ = '\0';
	while (*__line && __localdep_isspace(*__line))
		++__line;

	__result->mnt_opts = __line;
	while (*__line && !__localdep_isspace(*__line))
		++__line;
	if (!*__line)
		goto __err;
	*__line++ = '\0';
	while (*__line && __localdep_isspace(*__line))
		++__line;

	__result->mnt_freq = 0;
	while (*__line && __localdep_isdigit(*__line)) {
		__result->mnt_freq *= 10;
		__result->mnt_freq += *__line - '0';
		++__line;
	}
	if (!*__line)
		goto __err;
	while (*__line && __localdep_isspace(*__line))
		++__line;

	__result->mnt_passno = 0;
	while (*__line && __localdep_isdigit(*__line)) {
		__result->mnt_passno *= 10;
		__result->mnt_passno += *__line - '0';
		++__line;
	}
	return __result;
__err:
	return __NULLPTR;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_getmntent_r_defined
#define __local___localdep_getmntent_r_defined 1
#define __localdep_getmntent_r __LIBC_LOCAL_NAME(getmntent_r)
#endif /* !__local___localdep_getmntent_r_defined */
#else /* __CRT_HAVE_fgets || __CRT_HAVE_fgets_unlocked || ((__CRT_HAVE_fgetc || __CRT_HAVE_getc || __CRT_HAVE__IO_getc || __CRT_HAVE_fgetc_unlocked || __CRT_HAVE_getc_unlocked || (__CRT_DOS && __CRT_HAVE__filbuf) || __CRT_HAVE_fread || __CRT_HAVE__IO_fread || __CRT_HAVE_fread_unlocked || __CRT_HAVE__fread_nolock) && (__CRT_HAVE_ungetc || __CRT_HAVE__IO_ungetc || __CRT_HAVE_ungetc_unlocked || __CRT_HAVE__ungetc_nolock) && (__CRT_HAVE_ferror || __CRT_HAVE__IO_ferror || __CRT_HAVE_ferror_unlocked)) */
#undef __local_getmntent_r_defined
#endif /* !__CRT_HAVE_fgets && !__CRT_HAVE_fgets_unlocked && ((!__CRT_HAVE_fgetc && !__CRT_HAVE_getc && !__CRT_HAVE__IO_getc && !__CRT_HAVE_fgetc_unlocked && !__CRT_HAVE_getc_unlocked && (!__CRT_DOS || !__CRT_HAVE__filbuf) && !__CRT_HAVE_fread && !__CRT_HAVE__IO_fread && !__CRT_HAVE_fread_unlocked && !__CRT_HAVE__fread_nolock) || (!__CRT_HAVE_ungetc && !__CRT_HAVE__IO_ungetc && !__CRT_HAVE_ungetc_unlocked && !__CRT_HAVE__ungetc_nolock) || (!__CRT_HAVE_ferror && !__CRT_HAVE__IO_ferror && !__CRT_HAVE_ferror_unlocked)) */
#endif /* !__local_getmntent_r_defined */