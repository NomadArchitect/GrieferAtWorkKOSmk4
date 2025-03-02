/* HASH CRC-32:0x4e100a05 */
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
#ifndef GUARD_LIBC_AUTO_CONIO_C
#define GUARD_LIBC_AUTO_CONIO_C 1

#include "../api.h"
#include <hybrid/typecore.h>
#include <kos/types.h>
#include "../user/conio.h"
#include "format-printer.h"
#include "../user/stdio.h"
#include "../user/stdio_ext.h"
#include "string.h"
#include "../user/sys.ioctl.h"
#include "termios.h"
#include "../user/unistd.h"

DECL_BEGIN

#include "../libc/globals.h"
#ifndef __KERNEL__
#include <libc/template/stdtty.h>
/* >> _getch(3), _getch_nolock(3)
 * Read a character from the console, without echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
INTERN ATTR_SECTION(".text.crt.dos.conio") WUNUSED int
NOTHROW_RPC(LIBCCALL libc__getch)(void) {
	int result;

	FILE *fp = stdtty;
	libc_flockfile(fp);

	result = libc__getch_nolock();

	libc_funlockfile(fp);

	return result;
}
#include <bits/types.h>
#include <asm/os/termios.h>
#include <bits/os/termios.h>
#include <libc/template/stdtty.h>
/* >> _getch(3), _getch_nolock(3)
 * Read a character from the console, without echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
INTERN ATTR_SECTION(".text.crt.dos.conio") WUNUSED int
NOTHROW_RPC(LIBCCALL libc__getch_nolock)(void) {
	int result;
	struct termios oios, nios;
	FILE *fp = stdtty;
	fd_t fd  = libc_fileno(fp);
	if unlikely(libc_tcgetattr(fd, &oios) != 0)
		libc_bzero(&oios, sizeof(oios));
	libc_memcpy(&nios, &oios, sizeof(nios));
	nios.c_lflag &= ~__ECHO;
	(void)libc_tcsetattr(fd, __TCSANOW, &nios);
	result = libc_fgetc_unlocked(fp);
	(void)libc_tcsetattr(fd, __TCSANOW, &oios);
	return result;
}
#include <libc/template/stdtty.h>
/* >> _getche(3), _getche_nolock(3)
 * Read a character from the console, whilst also echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
INTERN ATTR_SECTION(".text.crt.dos.conio") WUNUSED int
NOTHROW_RPC(LIBCCALL libc__getche)(void) {
	int result;

	FILE *fp = stdtty;
	libc_flockfile(fp);

	result = libc__getche_nolock();

	libc_funlockfile(fp);

	return result;
}
#include <bits/types.h>
#include <asm/os/termios.h>
#include <bits/os/termios.h>
#include <libc/template/stdtty.h>
/* >> _getche(3), _getche_nolock(3)
 * Read a character from the console, whilst also echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
INTERN ATTR_SECTION(".text.crt.dos.conio") WUNUSED int
NOTHROW_RPC(LIBCCALL libc__getche_nolock)(void) {
	int result;
	struct termios oios, nios;
	FILE *fp = stdtty;
	fd_t fd  = libc_fileno(fp);
	if unlikely(libc_tcgetattr(fd, &oios) != 0)
		libc_bzero(&oios, sizeof(oios));
	libc_memcpy(&nios, &oios, sizeof(nios));
	nios.c_lflag |= __ECHO;
	(void)libc_tcsetattr(fd, __TCSANOW, &nios);
	result = libc_fgetc_unlocked(fp);
	(void)libc_tcsetattr(fd, __TCSANOW, &oios);
	return result;
}
#include <libc/template/stdtty.h>
INTERN ATTR_SECTION(".text.crt.dos.conio") int
NOTHROW_RPC(LIBCCALL libc__putch)(int ch) {
	return libc_fputc(ch, stdtty);
}
#include <libc/template/stdtty.h>
INTERN ATTR_SECTION(".text.crt.dos.conio") int
NOTHROW_RPC(LIBCCALL libc__putch_nolock)(int ch) {
	return libc_fputc_unlocked(ch, stdtty);
}
#include <libc/template/stdtty.h>
INTERN ATTR_SECTION(".text.crt.dos.conio") int
NOTHROW_NCX(LIBCCALL libc__ungetch)(int ch) {
	return libc_ungetc(ch, stdtty);
}
#include <libc/template/stdtty.h>
INTERN ATTR_SECTION(".text.crt.dos.conio") int
NOTHROW_NCX(LIBCCALL libc__ungetch_nolock)(int ch) {
	return libc_ungetc_unlocked(ch, stdtty);
}
INTERN ATTR_SECTION(".text.crt.dos.conio") ATTR_INOUT(1) char *
NOTHROW_RPC(LIBCCALL libc__cgets)(char *__restrict buf) {
	char *result = buf + 2;
	size_t readsize;
	if (libc__cgets_s(result, buf[0], &readsize) != 0)
		result = NULL;
	buf[1] = (char)(unsigned char)readsize;
	return result;
}
INTERN ATTR_SECTION(".text.crt.dos.conio") ATTR_OUT(3) ATTR_OUTS(1, 2) errno_t
NOTHROW_RPC(LIBCCALL libc__cgets_s)(char *buf,
                                    size_t bufsize,
                                    size_t *__restrict p_readsize) {
	int ch;
	if unlikely(!bufsize)
		return 28;
	buf[0]      = '\0';
	*p_readsize = 0;
	--bufsize;
	while (bufsize && (ch = libc__getche()) != -1) {
		if (ch == '\r') {
			ch = libc__getche();
			if (ch != -1 && ch != '\n')
				libc__ungetch(ch);
			break;
		}
		if (ch == '\n')
			break;
		*buf++ = (char)(unsigned char)(unsigned int)ch;
		*buf   = '\0';
		++*p_readsize;
		--bufsize;
	}
	return 0;
}
#include <libc/template/stdtty.h>
INTERN ATTR_SECTION(".text.crt.dos.conio") ATTR_IN(1) int
NOTHROW_RPC(LIBCCALL libc__cputs)(char const *__restrict str) {





	int result = 0;
	do {
		char ch = *str++;
		if (!ch)
			break;
		result = libc__putch(ch);
	} while (result != -1);
	return result;

}
#include <libc/template/stdtty.h>
INTERN ATTR_SECTION(".text.crt.dos.conio") ATTR_IN(2) ATTR_LIBC_PRINTF(2, 0) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(LIBCCALL libc___conio_common_vcprintf)(uint64_t options,
                                                   char const *format,
                                                   locale_t locale,
                                                   va_list args) {
	return libc___stdio_common_vfprintf(options, stdtty, format, locale, args);
}
#include <libc/template/stdtty.h>
INTERN ATTR_SECTION(".text.crt.dos.conio") ATTR_IN(2) ATTR_LIBC_PRINTF(2, 0) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(LIBCCALL libc___conio_common_vcprintf_s)(uint64_t options,
                                                     char const *format,
                                                     locale_t locale,
                                                     va_list args) {
	return libc___stdio_common_vfprintf_s(options, stdtty, format, locale, args);
}
DEFINE_INTERN_ALIAS_P(libc___conio_common_vcprintf_p,libc___conio_common_vcprintf,ATTR_IN(2) ATTR_LIBC_PRINTF_P(2, 0),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(uint64_t options, char const *format, locale_t locale, va_list args),(options,format,locale,args));
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(conio_common_vcscanf_getc) __format_word_t
(__FORMATPRINTER_CC conio_common_vcscanf_getc)(void *__UNUSED(arg)) {
	return (__format_word_t)libc__getche();
}
__LOCAL_LIBC(conio_common_vcscanf_ungetc) ssize_t
(__FORMATPRINTER_CC conio_common_vcscanf_ungetc)(void *__UNUSED(arg), __format_word_t word) {
	return libc__ungetch((int)(unsigned char)(unsigned int)word);
}
__NAMESPACE_LOCAL_END
INTERN ATTR_SECTION(".text.crt.dos.conio") WUNUSED ATTR_IN(2) ATTR_LIBC_SCANF(2, 0) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(LIBCCALL libc___conio_common_vcscanf)(uint64_t options,
                                                  char const *format,
                                                  locale_t locale,
                                                  va_list args) {
	(void)options;
	(void)locale;
	return libc_format_vscanf(&__NAMESPACE_LOCAL_SYM conio_common_vcscanf_getc,
	                     &__NAMESPACE_LOCAL_SYM conio_common_vcscanf_ungetc,
	                     NULL, format, args);
}
#include <corecrt_stdio_config.h>
INTERN ATTR_SECTION(".text.crt.dos.conio") ATTR_IN(1) ATTR_LIBC_PRINTF(1, 0) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(LIBCCALL libc__vcprintf_l)(char const *format,
                                       locale_t locale,
                                       va_list args) {
	return libc___conio_common_vcprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, format, locale, args);
}
#include <corecrt_stdio_config.h>
INTERN ATTR_SECTION(".text.crt.dos.conio") ATTR_IN(1) ATTR_LIBC_PRINTF(1, 0) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(LIBCCALL libc__vcprintf_s_l)(char const *format,
                                         locale_t locale,
                                         va_list args) {
	return libc___conio_common_vcprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, format, locale, args);
}
DEFINE_INTERN_ALIAS_P(libc__vcprintf_p_l,libc__vcprintf_l,ATTR_IN(1) ATTR_LIBC_PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(char const *format, locale_t locale, va_list args),(format,locale,args));
#include <corecrt_stdio_config.h>
INTERN ATTR_SECTION(".text.crt.dos.conio") WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 0) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(LIBCCALL libc__vcscanf_l)(char const *format,
                                      locale_t locale,
                                      va_list args) {
	return libc___conio_common_vcscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, format, locale, args);
}
#include <corecrt_stdio_config.h>
INTERN ATTR_SECTION(".text.crt.dos.conio") WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 0) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(LIBCCALL libc__vcscanf_s_l)(char const *format,
                                        locale_t locale,
                                        va_list args) {
	return libc___conio_common_vcscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS |
	                              1,
	                              format, locale, args);
}
INTERN ATTR_SECTION(".text.crt.dos.conio") ATTR_IN(1) ATTR_LIBC_PRINTF(1, 0) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(LIBCCALL libc__vcprintf)(char const *format,
                                     va_list args) {
	return libc__vcprintf_l(format, NULL, args);
}
INTERN ATTR_SECTION(".text.crt.dos.conio") ATTR_IN(1) ATTR_LIBC_PRINTF(1, 0) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(LIBCCALL libc__vcprintf_s)(char const *format,
                                       va_list args) {
	return libc__vcprintf_s_l(format, NULL, args);
}
DEFINE_INTERN_ALIAS_P(libc__vcprintf_p,libc__vcprintf,ATTR_IN(1) ATTR_LIBC_PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(char const *format, va_list args),(format,args));
INTERN ATTR_SECTION(".text.crt.dos.conio") WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 0) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(LIBCCALL libc__vcscanf)(char const *format,
                                    va_list args) {
	return libc__vcscanf_l(format, NULL, args);
}
INTERN ATTR_SECTION(".text.crt.dos.conio") WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 0) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(LIBCCALL libc__vcscanf_s)(char const *format,
                                      va_list args) {
	return libc__vcscanf_s_l(format, NULL, args);
}
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
INTERN ATTR_OPTIMIZE_SIZE ATTR_SECTION(".text.crt.dos.conio") ATTR_IN(1) ATTR_LIBC_PRINTF(1, 2) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(VLIBDCALL libd__cprintf)(char const *format,
                                     ...) {
	__STDC_INT_AS_SSIZE_T result;
	va_list args;
	va_start(args, format);
	result = libc__vcprintf(format, args);
	va_end(args);
	return result;
}
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
INTERN ATTR_SECTION(".text.crt.dos.conio") ATTR_IN(1) ATTR_LIBC_PRINTF(1, 2) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(VLIBCCALL libc__cprintf)(char const *format,
                                     ...) {
	__STDC_INT_AS_SSIZE_T result;
	va_list args;
	va_start(args, format);
	result = libc__vcprintf(format, args);
	va_end(args);
	return result;
}
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
INTERN ATTR_OPTIMIZE_SIZE ATTR_SECTION(".text.crt.dos.conio") ATTR_IN(1) ATTR_LIBC_PRINTF(1, 3) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(VLIBDCALL libd__cprintf_l)(char const *format,
                                       locale_t locale,
                                       ...) {
	__STDC_INT_AS_SSIZE_T result;
	va_list args;
	va_start(args, locale);
	result = libc__vcprintf_l(format, locale, args);
	va_end(args);
	return result;
}
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
INTERN ATTR_SECTION(".text.crt.dos.conio") ATTR_IN(1) ATTR_LIBC_PRINTF(1, 3) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(VLIBCCALL libc__cprintf_l)(char const *format,
                                       locale_t locale,
                                       ...) {
	__STDC_INT_AS_SSIZE_T result;
	va_list args;
	va_start(args, locale);
	result = libc__vcprintf_l(format, locale, args);
	va_end(args);
	return result;
}
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
INTERN ATTR_OPTIMIZE_SIZE ATTR_SECTION(".text.crt.dos.conio") ATTR_IN(1) ATTR_LIBC_PRINTF(1, 2) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(VLIBDCALL libd__cprintf_s)(char const *format,
                                       ...) {
	__STDC_INT_AS_SSIZE_T result;
	va_list args;
	va_start(args, format);
	result = libc__vcprintf_s(format, args);
	va_end(args);
	return result;
}
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
INTERN ATTR_SECTION(".text.crt.dos.conio") ATTR_IN(1) ATTR_LIBC_PRINTF(1, 2) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(VLIBCCALL libc__cprintf_s)(char const *format,
                                       ...) {
	__STDC_INT_AS_SSIZE_T result;
	va_list args;
	va_start(args, format);
	result = libc__vcprintf_s(format, args);
	va_end(args);
	return result;
}
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
INTERN ATTR_OPTIMIZE_SIZE ATTR_SECTION(".text.crt.dos.conio") ATTR_IN(1) ATTR_LIBC_PRINTF(1, 3) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(VLIBDCALL libd__cprintf_s_l)(char const *format,
                                         locale_t locale,
                                         ...) {
	__STDC_INT_AS_SSIZE_T result;
	va_list args;
	va_start(args, locale);
	result = libc__vcprintf_s_l(format, locale, args);
	va_end(args);
	return result;
}
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
INTERN ATTR_SECTION(".text.crt.dos.conio") ATTR_IN(1) ATTR_LIBC_PRINTF(1, 3) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(VLIBCCALL libc__cprintf_s_l)(char const *format,
                                         locale_t locale,
                                         ...) {
	__STDC_INT_AS_SSIZE_T result;
	va_list args;
	va_start(args, locale);
	result = libc__vcprintf_s_l(format, locale, args);
	va_end(args);
	return result;
}
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
DEFINE_INTERN_ALIAS_P(libd__cprintf_p,libd__cprintf,ATTR_IN(1) ATTR_LIBC_PRINTF_P(1, 2),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBDCALL,(char const *format, ...),(format,));
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
DEFINE_INTERN_ALIAS_P(libc__cprintf_p,libc__cprintf,ATTR_IN(1) ATTR_LIBC_PRINTF_P(1, 2),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBCCALL,(char const *format, ...),(format,));
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
DEFINE_INTERN_ALIAS_P(libd__cprintf_p_l,libd__cprintf_l,ATTR_IN(1) ATTR_LIBC_PRINTF_P(1, 3),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBDCALL,(char const *format, locale_t locale, ...),(format,locale,));
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
DEFINE_INTERN_ALIAS_P(libc__cprintf_p_l,libc__cprintf_l,ATTR_IN(1) ATTR_LIBC_PRINTF_P(1, 3),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBCCALL,(char const *format, locale_t locale, ...),(format,locale,));
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
INTERN ATTR_OPTIMIZE_SIZE ATTR_SECTION(".text.crt.dos.conio") WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 2) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(VLIBDCALL libd__cscanf)(char const *format,
                                    ...) {
	__STDC_INT_AS_SSIZE_T result;
	va_list args;
	va_start(args, format);
	result = libc__vcscanf(format, args);
	va_end(args);
	return result;
}
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
INTERN ATTR_SECTION(".text.crt.dos.conio") WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 2) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(VLIBCCALL libc__cscanf)(char const *format,
                                    ...) {
	__STDC_INT_AS_SSIZE_T result;
	va_list args;
	va_start(args, format);
	result = libc__vcscanf(format, args);
	va_end(args);
	return result;
}
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
INTERN ATTR_OPTIMIZE_SIZE ATTR_SECTION(".text.crt.dos.conio") WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 3) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(VLIBDCALL libd__cscanf_l)(char const *format,
                                      locale_t locale,
                                      ...) {
	__STDC_INT_AS_SSIZE_T result;
	va_list args;
	va_start(args, locale);
	result = libc__vcscanf_l(format, locale, args);
	va_end(args);
	return result;
}
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
INTERN ATTR_SECTION(".text.crt.dos.conio") WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 3) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(VLIBCCALL libc__cscanf_l)(char const *format,
                                      locale_t locale,
                                      ...) {
	__STDC_INT_AS_SSIZE_T result;
	va_list args;
	va_start(args, locale);
	result = libc__vcscanf_l(format, locale, args);
	va_end(args);
	return result;
}
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
INTERN ATTR_OPTIMIZE_SIZE ATTR_SECTION(".text.crt.dos.conio") WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 2) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(VLIBDCALL libd__cscanf_s)(char const *format,
                                      ...) {
	__STDC_INT_AS_SSIZE_T result;
	va_list args;
	va_start(args, format);
	result = libc__vcscanf_s(format, args);
	va_end(args);
	return result;
}
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
INTERN ATTR_SECTION(".text.crt.dos.conio") WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 2) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(VLIBCCALL libc__cscanf_s)(char const *format,
                                      ...) {
	__STDC_INT_AS_SSIZE_T result;
	va_list args;
	va_start(args, format);
	result = libc__vcscanf_s(format, args);
	va_end(args);
	return result;
}
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
INTERN ATTR_OPTIMIZE_SIZE ATTR_SECTION(".text.crt.dos.conio") WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 3) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(VLIBDCALL libd__cscanf_s_l)(char const *format,
                                        locale_t locale,
                                        ...) {
	__STDC_INT_AS_SSIZE_T result;
	va_list args;
	va_start(args, locale);
	result = libc__vcscanf_s_l(format, locale, args);
	va_end(args);
	return result;
}
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
INTERN ATTR_SECTION(".text.crt.dos.conio") WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 3) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(VLIBCCALL libc__cscanf_s_l)(char const *format,
                                        locale_t locale,
                                        ...) {
	__STDC_INT_AS_SSIZE_T result;
	va_list args;
	va_start(args, locale);
	result = libc__vcscanf_s_l(format, locale, args);
	va_end(args);
	return result;
}
/* >> clreol(3)
 * Clear all cells from the cursor (inclusive) until the end
 * of the  current  line.  (s.a.  `AC_EL(ANSITTY_EL_AFTER)') */
INTERN ATTR_SECTION(".text.crt.dos.conio") void
NOTHROW_RPC(LIBCCALL libc_clreol)(void) {
	libc__cputs("\033[K"); /* AC_EL(ANSITTY_EL_AFTER) */
}
/* >> clrscr(3)
 * Clear the entire screen (s.a. `AC_ED(ANSITTY_CLS_ALL)') */
INTERN ATTR_SECTION(".text.crt.dos.conio") void
NOTHROW_RPC(LIBCCALL libc_clrscr)(void) {
	libc__cputs("\033[2J"); /* AC_ED(ANSITTY_CLS_ALL) */
}
/* >> gotoxy(3)
 * Set the cursor {x,y} position (s.a. `AC_CUP(y, x)') */
INTERN ATTR_SECTION(".text.crt.dos.conio") void
NOTHROW_RPC(LIBCCALL libc_gotoxy)(int x,
                                  int y) {
	libc__cprintf("\033[%d;%dH", y, x); /* AC_CUP(y, x) */
}
/* >> delline(3)
 * Delete the line at the current cursor position, moving  the
 * screen contents underneath up one line. (s.a. `AC_DL("1")') */
INTERN ATTR_SECTION(".text.crt.dos.conio") void
NOTHROW_RPC(LIBCCALL libc_delline)(void) {
	libc__cputs("\033[M"); /* AC_DL("1") */
}
/* >> insline(3)
 * Insert a blank line at the current cursor position, moving the
 * screen  contents underneath down one line. (s.a. `AC_IL("1")') */
INTERN ATTR_SECTION(".text.crt.dos.conio") void
NOTHROW_RPC(LIBCCALL libc_insline)(void) {
	libc__cputs("\033[L"); /* AC_IL("1") */
}
/* >> highvideo(3)
 * Brighten text foreground color (s.a. `AC_FGBRIGHT') */
INTERN ATTR_SECTION(".text.crt.dos.conio") void
NOTHROW_RPC(LIBCCALL libc_highvideo)(void) {
	libc__cputs("\033[1m"); /* AC_FGBRIGHT */
}
/* >> lowvideo(3)
 * Darken text foreground color (s.a. `AC_FGDARK') */
INTERN ATTR_SECTION(".text.crt.dos.conio") void
NOTHROW_RPC(LIBCCALL libc_lowvideo)(void) {
	libc__cputs("\033[2m"); /* AC_FGDARK */
}
/* >> normvideo(3)
 * Reset all graphics attributes to normal (s.a. `AC_DEFATTR') */
INTERN ATTR_SECTION(".text.crt.dos.conio") void
NOTHROW_RPC(LIBCCALL libc_normvideo)(void) {
	libc__cputs("\033[m"); /* AC_DEFATTR */
}
/* >> textcolor(3)
 * @param: color: Color code (s.a. constants in `<conio.h>') */
INTERN ATTR_SECTION(".text.crt.dos.conio") void
NOTHROW_RPC(LIBCCALL libc_textcolor)(int color) {
	switch (color) {
	case 0x0:        color = 30; break; /* AC_FG_BLACK   */
	case 0x1:         color = 34; break; /* AC_FG_NAVY    */
	case 0x2:        color = 32; break; /* AC_FG_GREEN   */
	case 0x3:         color = 36; break; /* AC_FG_TEAL    */
	case 0x4:          color = 31; break; /* AC_FG_MAROON  */
	case 0x5:      color = 35; break; /* AC_FG_PURPLE  */
	case 0x6:        color = 33; break; /* AC_FG_OLIVE   */
	case 0x7:    color = 37; break; /* AC_FG_SILVER  */
	case 0x8:     color = 90; break; /* AC_FG_GREY    */
	case 0x9:    color = 94; break; /* AC_FG_BLUE    */
	case 0xa:   color = 92; break; /* AC_FG_LIME    */
	case 0xb:    color = 96; break; /* AC_FG_AQUA    */
	case 0xc:     color = 91; break; /* AC_FG_RED     */
	case 0xd: color = 95; break; /* AC_FG_FUCHSIA */
	case 0xe:       color = 93; break; /* AC_FG_YELLOW  */
	case 0xf:        color = 97; break; /* AC_FG_WHITE   */
	default: break;
	}
	libc__cprintf("\033[%dm", color);
}
/* >> textbackground(3)
 * @param: color: Color code (s.a. constants in `<conio.h>') */
INTERN ATTR_SECTION(".text.crt.dos.conio") void
NOTHROW_RPC(LIBCCALL libc_textbackground)(int color) {
	switch (color) {
	case 0x0:        color = 40;  break; /* AC_BG_BLACK   */
	case 0x1:         color = 44;  break; /* AC_BG_NAVY    */
	case 0x2:        color = 42;  break; /* AC_BG_GREEN   */
	case 0x3:         color = 46;  break; /* AC_BG_TEAL    */
	case 0x4:          color = 41;  break; /* AC_BG_MAROON  */
	case 0x5:      color = 45;  break; /* AC_BG_PURPLE  */
	case 0x6:        color = 43;  break; /* AC_BG_OLIVE   */
	case 0x7:    color = 47;  break; /* AC_BG_SILVER  */
	case 0x8:     color = 100; break; /* AC_BG_GREY    */
	case 0x9:    color = 104; break; /* AC_BG_BLUE    */
	case 0xa:   color = 102; break; /* AC_BG_LIME    */
	case 0xb:    color = 106; break; /* AC_BG_AQUA    */
	case 0xc:     color = 101; break; /* AC_BG_RED     */
	case 0xd: color = 105; break; /* AC_BG_FUCHSIA */
	case 0xe:       color = 103; break; /* AC_BG_YELLOW  */
	case 0xf:        color = 107; break; /* AC_BG_WHITE   */
	default: break;
	}
	libc__cprintf("\033[%dm", color);
}
/* >> textattr(3)
 * Set text attributes: `textcolor(attr & 0x0f)' and `textbackground((attr & 0xf0) >> 8)' */
INTERN ATTR_SECTION(".text.crt.dos.conio") void
NOTHROW_RPC(LIBCCALL libc_textattr)(int attr) {
	libc_textcolor(attr & 0x0f);
	libc_textbackground((attr & 0xf0) >> 8);
}
#include <bits/types.h>
#include <asm/os/termios.h>
#include <bits/os/termios.h>
#include <libc/template/stdtty.h>
/* >> clearkeybuf(3)
 * Flush all unread input (usually keyboard) data pending on the terminal */
INTERN ATTR_SECTION(".text.crt.dos.conio") void
NOTHROW(LIBCCALL libc_clearkeybuf)(void) {
	struct termios ios;
	FILE *fp = stdtty;
	fd_t fd  = libc_fileno(fp);

	/* Flush (read: "drain") kernel-space buffer. */
	if likely(libc_tcgetattr(fd, &ios) == 0)
		(void)libc_tcsetattr(fd, __TCSADRAIN, &ios);

	/* Flush (read: "purge") user-space buffer. */
	libc___fpurge(fp);
}
/* >> _conio_getpass(3)
 * CONIO version of getpass(3). But note the slightly different variant from `<unistd.h>' */
INTERN ATTR_SECTION(".text.crt.dos.conio") ATTR_IN(1) ATTR_INOUT(2) char *
NOTHROW_RPC(LIBCCALL libc__conio_getpass)(const char *prompt,
                                          char *str) {
	unsigned char buflen = (unsigned char)str[0];
	char *result = libc_getpass_r(prompt, &str[2], buflen);
	if (result != NULL) {
		str[1] = (unsigned char)libc_strlen(result);
		result = str;
	}
	return result;
}
/* >> cputsxy(3)
 * Combination of `gotoxy(3)' and `cputs(3)' */
INTERN ATTR_SECTION(".text.crt.dos.conio") ATTR_IN(3) void
NOTHROW_RPC(LIBCCALL libc_cputsxy)(int x,
                                   int y,
                                   char __KOS_FIXED_CONST *str) {
	libc_gotoxy(x, y);
	libc__cputs(str);
}
/* >> putchxy(3)
 * Combination of `gotoxy(3)' and `putch(3)' */
INTERN ATTR_SECTION(".text.crt.dos.conio") void
NOTHROW_RPC(LIBCCALL libc_putchxy)(int x,
                                   int y,
                                   char ch) {
	libc_gotoxy(x, y);
	libc__putch(ch);
}
#include <libc/template/stdtty.h>
#include <kos/ioctl/video.h>
#include <bits/crt/inttypes.h>
INTERN ATTR_SECTION(".text.crt.dos.conio") ATTR_OUT(1) int
NOTHROW_RPC(LIBCCALL libc__conio_wherexy)(uint16_t xy[2]) {



	char putback[64];
	unsigned int i;
	int result;
	libc__cputs("\033[6n"); /* DSR */
	for (i = 0; i < 64; ++i) {
		int ch = libc__getch();
		if (ch == '\033')
			break;
		putback[i] = ch;
	}
	result = libc__cscanf("[%" __SCA2_PREFIX "u"
	                 ";%" __SCA2_PREFIX "uR",
	                 &xy[1], &xy[0]) == 2
	         ? 0
	         : -1;
	while (i) {
		--i;
		libc__ungetch(putback[i]);
	}
	return result;

}
/* >> wherex(3)
 * Return the current cursor 'X' position (1-based) */
INTERN ATTR_SECTION(".text.crt.dos.conio") int
NOTHROW_RPC(LIBCCALL libc_wherex)(void) {
	uint16_t xy[2];
	if (libc__conio_wherexy(xy))
		return -1;
	return xy[0] + 1;
}
/* >> wherey(3)
 * Return the current cursor 'Y' position (1-based) */
INTERN ATTR_SECTION(".text.crt.dos.conio") int
NOTHROW_RPC(LIBCCALL libc_wherey)(void) {
	uint16_t xy[2];
	if (libc__conio_wherexy(xy))
		return -1;
	return xy[1] + 1;
}
/* >> window(3)
 * Set scroll range and margains to the specified rectangle (1-based) */
INTERN ATTR_SECTION(".text.crt.dos.conio") void
NOTHROW_RPC(LIBCCALL libc_window)(int left,
                                  int top,
                                  int right,
                                  int bottom) {
	libc__cprintf("\033[?69h"    /* DECLRMM  (enable scroll margins) */
	         "\033[%d;%ds"  /* DECSLRM  (set scroll margins) */
	         "\033[%d;%dr", /* DECSTBM  (set scroll region; iow: top/bottom) */
	         left, right, top, bottom);
}
#include <bits/types.h>
#include <libc/template/stdtty.h>
#include <kos/ioctl/video.h>
#include <parts/malloca.h>
/* >> movetext(3)
 * Duplicate a  given rectangle  (1-based)  of on-screen  text  at
 * another location. Overlapping rectangles are handled correctly. */
INTERN ATTR_SECTION(".text.crt.dos.conio") int
NOTHROW_RPC(LIBCCALL libc_movetext)(int left,
                                    int top,
                                    int right,
                                    int bottom,
                                    int destleft,
                                    int desttop) {
	struct vidttyinfo info;
	struct vidttycelldata data;
	fd_t fd = libc_fileno(stdtty);
	uint16_t args[6], i, error;
	if (libc_ioctl(fd, VID_IOC_GETTTYINFO, &info) != 0)
		goto err;
	args[0] = (uint16_t)(unsigned int)left;
	args[1] = (uint16_t)(unsigned int)right;
	args[2] = (uint16_t)(unsigned int)destleft;
	args[3] = (uint16_t)(unsigned int)top;
	args[4] = (uint16_t)(unsigned int)bottom;
	args[5] = (uint16_t)(unsigned int)desttop;
	for (i = 0; i < 6; ++i) {
		uint16_t v = args[i] - 1;
		if (v < 0) {
			v = 0;
		} else {
			uint16_t maxval;
			maxval = i >= 3 ? info.vti_cellh : info.vti_cellw;
			if (v > maxval)
				v = maxval;
		}
		args[i] = v;
	}
	if (args[0]/*left*/ >= args[1]/*right*/)
		goto done;
	if (args[3]/*top*/ >= args[4]/*bottom*/)
		goto done;
	libc_bzero(&data, sizeof(data));
	data.vcd_x = args[0]/*left*/;
	data.vcd_y = args[3]/*top*/;
	data.vcd_w = args[1]/*right*/ - args[0]/*left*/;
	data.vcd_h = args[4]/*bottom*/ - args[3]/*top*/;
	data.vcd_dat = (byte_t *)__malloca(data.vcd_w * data.vcd_h * info.vti_cellsize);
	if unlikely(!data.vcd_dat)
		goto err;
	error = libc_ioctl(fd, VID_IOC_GETCELLDATA, &data);
	if likely(error == 0) {
		data.vcd_x = args[2]/*destleft*/;
		data.vcd_y = args[5]/*desttop*/;
		error = libc_ioctl(fd, VID_IOC_SETCELLDATA, &data);
	}
	__freea(data.vcd_dat);
	if unlikely(error != 0)
		goto err;
done:
	return 0;
err:
	return 1;
}
#endif /* !__KERNEL__ */

DECL_END

#ifndef __KERNEL__
DEFINE_PUBLIC_ALIAS_P(_getch,libc__getch,WUNUSED,int,NOTHROW_RPC,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P(_getch_nolock,libc__getch_nolock,WUNUSED,int,NOTHROW_RPC,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P(_getche,libc__getche,WUNUSED,int,NOTHROW_RPC,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P(_getche_nolock,libc__getche_nolock,WUNUSED,int,NOTHROW_RPC,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P(_putch,libc__putch,,int,NOTHROW_RPC,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(_putch_nolock,libc__putch_nolock,,int,NOTHROW_RPC,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(_ungetch,libc__ungetch,,int,NOTHROW_NCX,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(_ungetch_nolock,libc__ungetch_nolock,,int,NOTHROW_NCX,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(_cgets,libc__cgets,ATTR_INOUT(1),char *,NOTHROW_RPC,LIBCCALL,(char *__restrict buf),(buf));
DEFINE_PUBLIC_ALIAS_P(_cgets_s,libc__cgets_s,ATTR_OUT(3) ATTR_OUTS(1, 2),errno_t,NOTHROW_RPC,LIBCCALL,(char *buf, size_t bufsize, size_t *__restrict p_readsize),(buf,bufsize,p_readsize));
DEFINE_PUBLIC_ALIAS_P(_cputs,libc__cputs,ATTR_IN(1),int,NOTHROW_RPC,LIBCCALL,(char const *__restrict str),(str));
DEFINE_PUBLIC_ALIAS_P(__conio_common_vcprintf,libc___conio_common_vcprintf,ATTR_IN(2) ATTR_LIBC_PRINTF(2, 0),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(uint64_t options, char const *format, locale_t locale, va_list args),(options,format,locale,args));
DEFINE_PUBLIC_ALIAS_P(__conio_common_vcprintf_s,libc___conio_common_vcprintf_s,ATTR_IN(2) ATTR_LIBC_PRINTF(2, 0),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(uint64_t options, char const *format, locale_t locale, va_list args),(options,format,locale,args));
DEFINE_PUBLIC_ALIAS_P(__conio_common_vcprintf_p,libc___conio_common_vcprintf_p,ATTR_IN(2) ATTR_LIBC_PRINTF_P(2, 0),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(uint64_t options, char const *format, locale_t locale, va_list args),(options,format,locale,args));
DEFINE_PUBLIC_ALIAS_P(__conio_common_vcscanf,libc___conio_common_vcscanf,WUNUSED ATTR_IN(2) ATTR_LIBC_SCANF(2, 0),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(uint64_t options, char const *format, locale_t locale, va_list args),(options,format,locale,args));
DEFINE_PUBLIC_ALIAS_P(_vcprintf_l,libc__vcprintf_l,ATTR_IN(1) ATTR_LIBC_PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(char const *format, locale_t locale, va_list args),(format,locale,args));
DEFINE_PUBLIC_ALIAS_P(_vcprintf_s_l,libc__vcprintf_s_l,ATTR_IN(1) ATTR_LIBC_PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(char const *format, locale_t locale, va_list args),(format,locale,args));
DEFINE_PUBLIC_ALIAS_P(_vcprintf_p_l,libc__vcprintf_p_l,ATTR_IN(1) ATTR_LIBC_PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(char const *format, locale_t locale, va_list args),(format,locale,args));
DEFINE_PUBLIC_ALIAS_P(_vcscanf_l,libc__vcscanf_l,WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 0),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(char const *format, locale_t locale, va_list args),(format,locale,args));
DEFINE_PUBLIC_ALIAS_P(_vcscanf_s_l,libc__vcscanf_s_l,WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 0),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(char const *format, locale_t locale, va_list args),(format,locale,args));
DEFINE_PUBLIC_ALIAS_P(_vcprintf,libc__vcprintf,ATTR_IN(1) ATTR_LIBC_PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(char const *format, va_list args),(format,args));
DEFINE_PUBLIC_ALIAS_P(_vcprintf_s,libc__vcprintf_s,ATTR_IN(1) ATTR_LIBC_PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(char const *format, va_list args),(format,args));
DEFINE_PUBLIC_ALIAS_P(_vcprintf_p,libc__vcprintf_p,ATTR_IN(1) ATTR_LIBC_PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(char const *format, va_list args),(format,args));
DEFINE_PUBLIC_ALIAS_P(_vcscanf,libc__vcscanf,WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 0),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(char const *format, va_list args),(format,args));
DEFINE_PUBLIC_ALIAS_P(_vcscanf_s,libc__vcscanf_s,WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 0),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(char const *format, va_list args),(format,args));
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
DEFINE_PUBLIC_ALIAS_P(DOS$_cprintf,libd__cprintf,ATTR_IN(1) ATTR_LIBC_PRINTF(1, 2),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBDCALL,(char const *format, ...),(format,));
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
DEFINE_PUBLIC_ALIAS_P(_cprintf,libc__cprintf,ATTR_IN(1) ATTR_LIBC_PRINTF(1, 2),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBCCALL,(char const *format, ...),(format,));
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
DEFINE_PUBLIC_ALIAS_P(DOS$_cprintf_l,libd__cprintf_l,ATTR_IN(1) ATTR_LIBC_PRINTF(1, 3),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBDCALL,(char const *format, locale_t locale, ...),(format,locale,));
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
DEFINE_PUBLIC_ALIAS_P(_cprintf_l,libc__cprintf_l,ATTR_IN(1) ATTR_LIBC_PRINTF(1, 3),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBCCALL,(char const *format, locale_t locale, ...),(format,locale,));
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
DEFINE_PUBLIC_ALIAS_P(DOS$_cprintf_s,libd__cprintf_s,ATTR_IN(1) ATTR_LIBC_PRINTF(1, 2),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBDCALL,(char const *format, ...),(format,));
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
DEFINE_PUBLIC_ALIAS_P(_cprintf_s,libc__cprintf_s,ATTR_IN(1) ATTR_LIBC_PRINTF(1, 2),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBCCALL,(char const *format, ...),(format,));
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
DEFINE_PUBLIC_ALIAS_P(DOS$_cprintf_s_l,libd__cprintf_s_l,ATTR_IN(1) ATTR_LIBC_PRINTF(1, 3),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBDCALL,(char const *format, locale_t locale, ...),(format,locale,));
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
DEFINE_PUBLIC_ALIAS_P(_cprintf_s_l,libc__cprintf_s_l,ATTR_IN(1) ATTR_LIBC_PRINTF(1, 3),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBCCALL,(char const *format, locale_t locale, ...),(format,locale,));
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
DEFINE_PUBLIC_ALIAS_P(DOS$_cprintf_p,libd__cprintf_p,ATTR_IN(1) ATTR_LIBC_PRINTF_P(1, 2),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBDCALL,(char const *format, ...),(format,));
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
DEFINE_PUBLIC_ALIAS_P(_cprintf_p,libc__cprintf_p,ATTR_IN(1) ATTR_LIBC_PRINTF_P(1, 2),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBCCALL,(char const *format, ...),(format,));
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
DEFINE_PUBLIC_ALIAS_P(DOS$_cprintf_p_l,libd__cprintf_p_l,ATTR_IN(1) ATTR_LIBC_PRINTF_P(1, 3),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBDCALL,(char const *format, locale_t locale, ...),(format,locale,));
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
DEFINE_PUBLIC_ALIAS_P(_cprintf_p_l,libc__cprintf_p_l,ATTR_IN(1) ATTR_LIBC_PRINTF_P(1, 3),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBCCALL,(char const *format, locale_t locale, ...),(format,locale,));
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
DEFINE_PUBLIC_ALIAS_P(DOS$_cscanf,libd__cscanf,WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 2),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBDCALL,(char const *format, ...),(format,));
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
DEFINE_PUBLIC_ALIAS_P(_cscanf,libc__cscanf,WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 2),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBCCALL,(char const *format, ...),(format,));
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
DEFINE_PUBLIC_ALIAS_P(DOS$_cscanf_l,libd__cscanf_l,WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 3),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBDCALL,(char const *format, locale_t locale, ...),(format,locale,));
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
DEFINE_PUBLIC_ALIAS_P(_cscanf_l,libc__cscanf_l,WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 3),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBCCALL,(char const *format, locale_t locale, ...),(format,locale,));
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
DEFINE_PUBLIC_ALIAS_P(DOS$_cscanf_s,libd__cscanf_s,WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 2),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBDCALL,(char const *format, ...),(format,));
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
DEFINE_PUBLIC_ALIAS_P(_cscanf_s,libc__cscanf_s,WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 2),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBCCALL,(char const *format, ...),(format,));
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
DEFINE_PUBLIC_ALIAS_P(DOS$_cscanf_s_l,libd__cscanf_s_l,WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 3),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBDCALL,(char const *format, locale_t locale, ...),(format,locale,));
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
DEFINE_PUBLIC_ALIAS_P(_cscanf_s_l,libc__cscanf_s_l,WUNUSED ATTR_IN(1) ATTR_LIBC_SCANF(1, 3),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,VLIBCCALL,(char const *format, locale_t locale, ...),(format,locale,));
DEFINE_PUBLIC_ALIAS_P_VOID(clreol,libc_clreol,,NOTHROW_RPC,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P_VOID(clrscr,libc_clrscr,,NOTHROW_RPC,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P_VOID(gotoxy,libc_gotoxy,,NOTHROW_RPC,LIBCCALL,(int x, int y),(x,y));
DEFINE_PUBLIC_ALIAS_P_VOID(delline,libc_delline,,NOTHROW_RPC,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P_VOID(insline,libc_insline,,NOTHROW_RPC,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P_VOID(highvideo,libc_highvideo,,NOTHROW_RPC,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P_VOID(lowvideo,libc_lowvideo,,NOTHROW_RPC,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P_VOID(normvideo,libc_normvideo,,NOTHROW_RPC,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P_VOID(textcolor,libc_textcolor,,NOTHROW_RPC,LIBCCALL,(int color),(color));
DEFINE_PUBLIC_ALIAS_P_VOID(textbackground,libc_textbackground,,NOTHROW_RPC,LIBCCALL,(int color),(color));
DEFINE_PUBLIC_ALIAS_P_VOID(textattr,libc_textattr,,NOTHROW_RPC,LIBCCALL,(int attr),(attr));
DEFINE_PUBLIC_ALIAS_P_VOID(clearkeybuf,libc_clearkeybuf,,NOTHROW,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P(_conio_getpass,libc__conio_getpass,ATTR_IN(1) ATTR_INOUT(2),char *,NOTHROW_RPC,LIBCCALL,(const char *prompt, char *str),(prompt,str));
DEFINE_PUBLIC_ALIAS_P_VOID(cputsxy,libc_cputsxy,ATTR_IN(3),NOTHROW_RPC,LIBCCALL,(int x, int y, char __KOS_FIXED_CONST *str),(x,y,str));
DEFINE_PUBLIC_ALIAS_P_VOID(putchxy,libc_putchxy,,NOTHROW_RPC,LIBCCALL,(int x, int y, char ch),(x,y,ch));
DEFINE_PUBLIC_ALIAS_P(wherex,libc_wherex,,int,NOTHROW_RPC,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P(wherey,libc_wherey,,int,NOTHROW_RPC,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P_VOID(window,libc_window,,NOTHROW_RPC,LIBCCALL,(int left, int top, int right, int bottom),(left,top,right,bottom));
DEFINE_PUBLIC_ALIAS_P(movetext,libc_movetext,,int,NOTHROW_RPC,LIBCCALL,(int left, int top, int right, int bottom, int destleft, int desttop),(left,top,right,bottom,destleft,desttop));
#endif /* !__KERNEL__ */

#endif /* !GUARD_LIBC_AUTO_CONIO_C */
