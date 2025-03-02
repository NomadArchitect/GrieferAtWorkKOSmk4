/* HASH CRC-32:0x5f82bbe */
/* Copyright (c) 2019-2025 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2025 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef GUARD_LIBC_AUTO_PARTS_WCHAR_FCNTL_C
#define GUARD_LIBC_AUTO_PARTS_WCHAR_FCNTL_C 1

#include "../api.h"
#include <hybrid/typecore.h>
#include <kos/types.h>
#include "parts.wchar.fcntl.h"
#include "../user/fcntl.h"
#include "../user/stdlib.h"
#include "uchar.h"

DECL_BEGIN

#ifndef __KERNEL__
INTERN ATTR_OPTIMIZE_SIZE ATTR_SECTION(".text.crt.dos.wchar.io.utility") WUNUSED ATTR_IN(1) fd_t
NOTHROW_RPC(VLIBDCALL libd_wopen)(char16_t const *filename,
                                  oflag_t oflags,
                                  ...) {
	fd_t result;
	va_list args;
	mode_t mode;
	va_start(args, oflags);
	mode = va_arg(args, mode_t);
	va_end(args);

	result = libd_wopenat(__AT_FDCWD, filename, oflags, mode);














	return result;
}
INTERN ATTR_SECTION(".text.crt.wchar.io.utility") WUNUSED ATTR_IN(1) fd_t
NOTHROW_RPC(VLIBKCALL libc_wopen)(char32_t const *filename,
                                  oflag_t oflags,
                                  ...) {
	fd_t result;
	va_list args;
	mode_t mode;
	va_start(args, oflags);
	mode = va_arg(args, mode_t);
	va_end(args);

	result = libc_wopenat(__AT_FDCWD, filename, oflags, mode);














	return result;
}
#include <asm/os/fcntl.h>
INTERN ATTR_OPTIMIZE_SIZE ATTR_SECTION(".text.crt.dos.wchar.io.utility") WUNUSED ATTR_IN(1) fd_t
NOTHROW_RPC(LIBDCALL libd_wcreat)(char16_t const *filename,
                                  mode_t mode) {

	return libd_wopen(filename, __O_CREAT | __O_WRONLY | __O_TRUNC, mode);












}
#include <asm/os/fcntl.h>
INTERN ATTR_SECTION(".text.crt.wchar.io.utility") WUNUSED ATTR_IN(1) fd_t
NOTHROW_RPC(LIBKCALL libc_wcreat)(char32_t const *filename,
                                  mode_t mode) {

	return libc_wopen(filename, __O_CREAT | __O_WRONLY | __O_TRUNC, mode);












}
#include <asm/os/oflags.h>
INTERN ATTR_OPTIMIZE_SIZE ATTR_SECTION(".text.crt.dos.wchar.io.utility") WUNUSED ATTR_IN(1) fd_t
NOTHROW_RPC(VLIBDCALL libd_wopen64)(char16_t const *filename,
                                    oflag_t oflags,
                                    ...) {
	fd_t result;
	va_list args;
	mode_t mode;
	va_start(args, oflags);
	mode = va_arg(args, mode_t);
	va_end(args);

	result = libd_wopen(filename, oflags | __O_LARGEFILE, mode);


















	return result;
}
#include <asm/os/oflags.h>
#if !__O_LARGEFILE
DEFINE_INTERN_ALIAS_P(libc_wopen64,libc_wopen,WUNUSED ATTR_IN(1),fd_t,NOTHROW_RPC,VLIBKCALL,(char32_t const *filename, oflag_t oflags, ...),(filename,oflags,));
#else /* !__O_LARGEFILE */
INTERN ATTR_SECTION(".text.crt.wchar.io.utility") WUNUSED ATTR_IN(1) fd_t
NOTHROW_RPC(VLIBKCALL libc_wopen64)(char32_t const *filename,
                                    oflag_t oflags,
                                    ...) {
	fd_t result;
	va_list args;
	mode_t mode;
	va_start(args, oflags);
	mode = va_arg(args, mode_t);
	va_end(args);

	result = libc_wopen(filename, oflags | __O_LARGEFILE, mode);


















	return result;
}
#endif /* __O_LARGEFILE */
#include <asm/os/oflags.h>
INTERN ATTR_OPTIMIZE_SIZE ATTR_SECTION(".text.crt.dos.wchar.io.utility") WUNUSED ATTR_IN(1) fd_t
NOTHROW_RPC(LIBDCALL libd_wcreat64)(char16_t const *filename,
                                    mode_t mode) {

	return libd_wopen64(filename, __O_CREAT | __O_WRONLY | __O_TRUNC, mode);












}
#include <asm/os/oflags.h>
#if !__O_LARGEFILE
DEFINE_INTERN_ALIAS_P(libc_wcreat64,libc_wcreat,WUNUSED ATTR_IN(1),fd_t,NOTHROW_RPC,LIBKCALL,(char32_t const *filename, mode_t mode),(filename,mode));
#else /* !__O_LARGEFILE */
INTERN ATTR_SECTION(".text.crt.wchar.io.utility") WUNUSED ATTR_IN(1) fd_t
NOTHROW_RPC(LIBKCALL libc_wcreat64)(char32_t const *filename,
                                    mode_t mode) {

	return libc_wopen64(filename, __O_CREAT | __O_WRONLY | __O_TRUNC, mode);












}
#endif /* __O_LARGEFILE */
INTERN ATTR_OPTIMIZE_SIZE ATTR_SECTION(".text.crt.dos.wchar.io.utility") WUNUSED ATTR_IN(2) fd_t
NOTHROW_RPC(VLIBDCALL libd_wopenat)(fd_t dirfd,
                                    char16_t const *filename,
                                    oflag_t oflags,
                                    ...) {
	fd_t result;
	va_list args;
	mode_t mode;
	va_start(args, oflags);
	mode = va_arg(args, mode_t);
	va_end(args);



	{
		char *utf8_filename;
		utf8_filename = libd_convert_wcstombs(filename);
		if unlikely(!utf8_filename)
			return -1;
		result = libd_openat(dirfd, utf8_filename, oflags, mode);

		libc_free(utf8_filename);

	}

	return result;
}
INTERN ATTR_SECTION(".text.crt.wchar.io.utility") WUNUSED ATTR_IN(2) fd_t
NOTHROW_RPC(VLIBKCALL libc_wopenat)(fd_t dirfd,
                                    char32_t const *filename,
                                    oflag_t oflags,
                                    ...) {
	fd_t result;
	va_list args;
	mode_t mode;
	va_start(args, oflags);
	mode = va_arg(args, mode_t);
	va_end(args);



	{
		char *utf8_filename;
		utf8_filename = libc_convert_wcstombs(filename);
		if unlikely(!utf8_filename)
			return -1;
		result = libc_openat(dirfd, utf8_filename, oflags, mode);

		libc_free(utf8_filename);

	}

	return result;
}
INTERN ATTR_OPTIMIZE_SIZE ATTR_SECTION(".text.crt.dos.wchar.io.utility") WUNUSED ATTR_IN(2) fd_t
NOTHROW_RPC(VLIBDCALL libd_wopenat64)(fd_t dirfd,
                                      char16_t const *filename,
                                      oflag_t oflags,
                                      ...) {
	fd_t result;
	va_list args;
	mode_t mode;
	va_start(args, oflags);
	mode = va_arg(args, mode_t);
	va_end(args);

	result = libd_wopenat(dirfd, filename, oflags | __O_LARGEFILE, mode);


















	return result;
}
#include <asm/os/oflags.h>
#if !__O_LARGEFILE
DEFINE_INTERN_ALIAS_P(libc_wopenat64,libc_wopenat,WUNUSED ATTR_IN(2),fd_t,NOTHROW_RPC,VLIBKCALL,(fd_t dirfd, char32_t const *filename, oflag_t oflags, ...),(dirfd,filename,oflags,));
#else /* !__O_LARGEFILE */
INTERN ATTR_SECTION(".text.crt.wchar.io.utility") WUNUSED ATTR_IN(2) fd_t
NOTHROW_RPC(VLIBKCALL libc_wopenat64)(fd_t dirfd,
                                      char32_t const *filename,
                                      oflag_t oflags,
                                      ...) {
	fd_t result;
	va_list args;
	mode_t mode;
	va_start(args, oflags);
	mode = va_arg(args, mode_t);
	va_end(args);

	result = libc_wopenat(dirfd, filename, oflags | __O_LARGEFILE, mode);


















	return result;
}
#endif /* __O_LARGEFILE */
#endif /* !__KERNEL__ */

DECL_END

#ifndef __KERNEL__
DEFINE_PUBLIC_ALIAS_P(DOS$_wopen,libd_wopen,WUNUSED ATTR_IN(1),fd_t,NOTHROW_RPC,VLIBDCALL,(char16_t const *filename, oflag_t oflags, ...),(filename,oflags,));
DEFINE_PUBLIC_ALIAS_P("?_wopen@@YAHPB_WHH@Z",libd_wopen,WUNUSED ATTR_IN(1),fd_t,NOTHROW_RPC,VLIBDCALL,(char16_t const *filename, oflag_t oflags, ...),(filename,oflags,));
DEFINE_PUBLIC_ALIAS_P(DOS$wopen,libd_wopen,WUNUSED ATTR_IN(1),fd_t,NOTHROW_RPC,VLIBDCALL,(char16_t const *filename, oflag_t oflags, ...),(filename,oflags,));
DEFINE_PUBLIC_ALIAS_P(wopen,libc_wopen,WUNUSED ATTR_IN(1),fd_t,NOTHROW_RPC,VLIBKCALL,(char32_t const *filename, oflag_t oflags, ...),(filename,oflags,));
DEFINE_PUBLIC_ALIAS_P(DOS$_wcreat,libd_wcreat,WUNUSED ATTR_IN(1),fd_t,NOTHROW_RPC,LIBDCALL,(char16_t const *filename, mode_t mode),(filename,mode));
DEFINE_PUBLIC_ALIAS_P(DOS$wcreat,libd_wcreat,WUNUSED ATTR_IN(1),fd_t,NOTHROW_RPC,LIBDCALL,(char16_t const *filename, mode_t mode),(filename,mode));
DEFINE_PUBLIC_ALIAS_P(wcreat,libc_wcreat,WUNUSED ATTR_IN(1),fd_t,NOTHROW_RPC,LIBKCALL,(char32_t const *filename, mode_t mode),(filename,mode));
DEFINE_PUBLIC_ALIAS_P(DOS$wopen64,libd_wopen64,WUNUSED ATTR_IN(1),fd_t,NOTHROW_RPC,VLIBDCALL,(char16_t const *filename, oflag_t oflags, ...),(filename,oflags,));
DEFINE_PUBLIC_ALIAS_P(wopen64,libc_wopen64,WUNUSED ATTR_IN(1),fd_t,NOTHROW_RPC,VLIBKCALL,(char32_t const *filename, oflag_t oflags, ...),(filename,oflags,));
DEFINE_PUBLIC_ALIAS_P(DOS$wcreat64,libd_wcreat64,WUNUSED ATTR_IN(1),fd_t,NOTHROW_RPC,LIBDCALL,(char16_t const *filename, mode_t mode),(filename,mode));
DEFINE_PUBLIC_ALIAS_P(wcreat64,libc_wcreat64,WUNUSED ATTR_IN(1),fd_t,NOTHROW_RPC,LIBKCALL,(char32_t const *filename, mode_t mode),(filename,mode));
DEFINE_PUBLIC_ALIAS_P(DOS$wopenat,libd_wopenat,WUNUSED ATTR_IN(2),fd_t,NOTHROW_RPC,VLIBDCALL,(fd_t dirfd, char16_t const *filename, oflag_t oflags, ...),(dirfd,filename,oflags,));
DEFINE_PUBLIC_ALIAS_P(wopenat,libc_wopenat,WUNUSED ATTR_IN(2),fd_t,NOTHROW_RPC,VLIBKCALL,(fd_t dirfd, char32_t const *filename, oflag_t oflags, ...),(dirfd,filename,oflags,));
DEFINE_PUBLIC_ALIAS_P(DOS$wopenat64,libd_wopenat64,WUNUSED ATTR_IN(2),fd_t,NOTHROW_RPC,VLIBDCALL,(fd_t dirfd, char16_t const *filename, oflag_t oflags, ...),(dirfd,filename,oflags,));
DEFINE_PUBLIC_ALIAS_P(wopenat64,libc_wopenat64,WUNUSED ATTR_IN(2),fd_t,NOTHROW_RPC,VLIBKCALL,(fd_t dirfd, char32_t const *filename, oflag_t oflags, ...),(dirfd,filename,oflags,));
#endif /* !__KERNEL__ */

#endif /* !GUARD_LIBC_AUTO_PARTS_WCHAR_FCNTL_C */
