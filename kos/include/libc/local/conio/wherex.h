/* HASH CRC-32:0x9d924bfc */
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
#ifndef __local_wherex_defined
#define __local_wherex_defined
#include <__crt.h>
#include <features.h>
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if (defined(__KOS__) && defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl))) || (((defined(__CRT_HAVE__getch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getch_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetc_unlocked) || defined(__CRT_HAVE_getc_unlocked) || defined(__CRT_HAVE__getc_nolock) || defined(__CRT_HAVE__fgetc_nolock) || (defined(__CRT_HAVE_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE_fgetc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE__IO_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__filbuf) || defined(__CRT_HAVE___uflow) || defined(__CRT_HAVE___underflow))) || defined(__CRT_HAVE_fread) || defined(__CRT_HAVE__IO_fread) || defined(__CRT_HAVE_fread_unlocked) || defined(__CRT_HAVE__fread_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetc) || defined(__CRT_HAVE__IO_ungetc) || defined(__CRT_HAVE_ungetc_unlocked) || defined(__CRT_HAVE__ungetc_nolock)))) && (defined(__CRT_HAVE__cscanf) || defined(__CRT_HAVE__vcscanf) || defined(__CRT_HAVE__vcscanf_l) || defined(__CRT_HAVE___conio_common_vcscanf) || (((defined(__CRT_HAVE__getwche_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getwche) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getwche_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetwch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetwch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))))
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__conio_wherexy_defined
#define __local___localdep__conio_wherexy_defined
__NAMESPACE_LOCAL_END
#include <libc/local/conio/_conio_wherexy.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__conio_wherexy __LIBC_LOCAL_NAME(_conio_wherexy)
#endif /* !__local___localdep__conio_wherexy_defined */
__LOCAL_LIBC(wherex) int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(wherex))(void) {
	__UINT16_TYPE__ __xy[2];
	if ((__NAMESPACE_LOCAL_SYM __localdep__conio_wherexy)(__xy))
		return -1;
	return __xy[0] + 1;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_wherex_defined
#define __local___localdep_wherex_defined
#define __localdep_wherex __LIBC_LOCAL_NAME(wherex)
#endif /* !__local___localdep_wherex_defined */
#else /* (__KOS__ && __CRT_HAVE_stdtty && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl)) || (((__CRT_HAVE__getch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getch || (__CRT_HAVE_stdtty && (__CRT_HAVE__getch_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetc_unlocked || __CRT_HAVE_getc_unlocked || __CRT_HAVE__getc_nolock || __CRT_HAVE__fgetc_nolock || (__CRT_HAVE_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE_fgetc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE__IO_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_DOS && (__CRT_HAVE__filbuf || __CRT_HAVE___uflow || __CRT_HAVE___underflow)) || __CRT_HAVE_fread || __CRT_HAVE__IO_fread || __CRT_HAVE_fread_unlocked || __CRT_HAVE__fread_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetc || __CRT_HAVE__IO_ungetc || __CRT_HAVE_ungetc_unlocked || __CRT_HAVE__ungetc_nolock))) && (__CRT_HAVE__cscanf || __CRT_HAVE__vcscanf || __CRT_HAVE__vcscanf_l || __CRT_HAVE___conio_common_vcscanf || (((__CRT_HAVE__getwche_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getwche || (__CRT_HAVE_stdtty && (__CRT_HAVE__getwche_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked || __CRT_HAVE__getwc_nolock || __CRT_HAVE__fgetwc_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetwch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetwch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked)))))) */
#undef __local_wherex_defined
#endif /* (!__KOS__ || !__CRT_HAVE_stdtty || (!__CRT_HAVE_fileno && !__CRT_HAVE__fileno && !__CRT_HAVE_fileno_unlocked) || (!__CRT_HAVE_ioctl && !__CRT_HAVE___ioctl && !__CRT_HAVE___libc_ioctl)) && (((!__CRT_HAVE__getch_nolock || !__USE_STDIO_UNLOCKED) && !__CRT_HAVE__getch && (!__CRT_HAVE_stdtty || (!__CRT_HAVE__getch_nolock && (!__ECHO || !__TCSANOW || (!__CRT_HAVE_fileno && !__CRT_HAVE__fileno && !__CRT_HAVE_fileno_unlocked) || (!__CRT_HAVE_fgetc_unlocked && !__CRT_HAVE_getc_unlocked && !__CRT_HAVE__getc_nolock && !__CRT_HAVE__fgetc_nolock && (!__CRT_HAVE_getc || (__CRT_DOS && __CRT_HAVE__filbuf)) && (!__CRT_HAVE_fgetc || (__CRT_DOS && __CRT_HAVE__filbuf)) && (!__CRT_HAVE__IO_getc || (__CRT_DOS && __CRT_HAVE__filbuf)) && (!__CRT_DOS || (!__CRT_HAVE__filbuf && !__CRT_HAVE___uflow && !__CRT_HAVE___underflow)) && !__CRT_HAVE_fread && !__CRT_HAVE__IO_fread && !__CRT_HAVE_fread_unlocked && !__CRT_HAVE__fread_nolock) || (!__CRT_HAVE_tcgetattr && !__CRT_HAVE___tcgetattr && ((!__CRT_HAVE_ioctl && !__CRT_HAVE___ioctl && !__CRT_HAVE___libc_ioctl) || !__TCGETA)) || (!__CRT_HAVE_tcsetattr && !__CRT_HAVE_ioctl && !__CRT_HAVE___ioctl && !__CRT_HAVE___libc_ioctl))))) || ((!__CRT_HAVE__ungetch_nolock || !__USE_STDIO_UNLOCKED) && !__CRT_HAVE__ungetch && (!__CRT_HAVE_stdtty || (!__CRT_HAVE_ungetc && !__CRT_HAVE__IO_ungetc && !__CRT_HAVE_ungetc_unlocked && !__CRT_HAVE__ungetc_nolock))) || (!__CRT_HAVE__cscanf && !__CRT_HAVE__vcscanf && !__CRT_HAVE__vcscanf_l && !__CRT_HAVE___conio_common_vcscanf && (((!__CRT_HAVE__getwche_nolock || !__USE_STDIO_UNLOCKED) && !__CRT_HAVE__getwche && (!__CRT_HAVE_stdtty || (!__CRT_HAVE__getwche_nolock && (!__ECHO || !__TCSANOW || (!__CRT_HAVE_fileno && !__CRT_HAVE__fileno && !__CRT_HAVE_fileno_unlocked) || (!__CRT_HAVE_fgetwc_unlocked && !__CRT_HAVE_getwc_unlocked && !__CRT_HAVE__getwc_nolock && !__CRT_HAVE__fgetwc_nolock) || (!__CRT_HAVE_tcgetattr && !__CRT_HAVE___tcgetattr && ((!__CRT_HAVE_ioctl && !__CRT_HAVE___ioctl && !__CRT_HAVE___libc_ioctl) || !__TCGETA)) || (!__CRT_HAVE_tcsetattr && !__CRT_HAVE_ioctl && !__CRT_HAVE___ioctl && !__CRT_HAVE___libc_ioctl))))) || ((!__CRT_HAVE__ungetwch_nolock || !__USE_STDIO_UNLOCKED) && !__CRT_HAVE__ungetwch && (!__CRT_HAVE_stdtty || (!__CRT_HAVE_ungetwc && !__CRT_HAVE_ungetwc_unlocked)))))) */
#endif /* !__local_wherex_defined */