/* HASH CRC-32:0xd4871f23 */
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
/* (#) Portability: DJGPP        (/include/conio.h) */
/* (#) Portability: EMX kLIBC    (/libc/include/conio.h) */
/* (#) Portability: MinGW        (/mingw-w64-headers/crt/conio.h) */
/* (#) Portability: Windows Kits (/ucrt/conio.h) */
#ifndef _CONIO_H
#define _CONIO_H 1

#include "__stdinc.h"
#include "__crt.h"

#ifdef __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER
#pragma GCC system_header
#endif /* __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER */

#include <features.h>
#include <bits/types.h>
#include <hybrid/typecore.h>

#ifdef __USE_DOS
#include <crtdefs.h>
#ifndef __USE_DOS_CLEAN
#include <corecrt_wconio.h> /* Include <wchar.h> instead */
#endif /* !__USE_DOS_CLEAN */
#endif /* __USE_DOS */

#ifdef __CC__
__SYSDECL_BEGIN

#ifndef __size_t_defined
#define __size_t_defined
typedef __size_t size_t;
#endif /* !__size_t_defined */

#ifndef __errno_t_defined
#define __errno_t_defined
typedef __errno_t errno_t; /* Errno code (one of `E*' from <errno.h>) */
#endif /* !__errno_t_defined */

/* KOS-extension: standard file stream for `/dev/tty' */
#if defined(__USE_KOS) && !defined(stdtty)
#ifdef __CRT_HAVE_stdtty
__LIBC FILE *stdtty;
#define stdtty stdtty
#endif /* __CRT_HAVE_stdtty */
#endif /* __USE_KOS && !stdtty */

__CDECLARE_OPT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_kbhit,(void),())
#if defined(__CRT_HAVE__getch_nolock) && defined(__USE_STDIO_UNLOCKED)
/* >> _getch(3), _getch_nolock(3)
 * Read a character from the console, without echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__CREDIRECT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_getch,(void),_getch_nolock,())
#elif defined(__CRT_HAVE__getch)
/* >> _getch(3), _getch_nolock(3)
 * Read a character from the console, without echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_getch,(void),())
#else /* ... */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getch_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetc_unlocked) || defined(__CRT_HAVE_getc_unlocked) || defined(__CRT_HAVE__getc_nolock) || defined(__CRT_HAVE__fgetc_nolock) || (defined(__CRT_HAVE_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE_fgetc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE__IO_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__filbuf) || defined(__CRT_HAVE___uflow) || defined(__CRT_HAVE___underflow))) || defined(__CRT_HAVE_fread) || defined(__CRT_HAVE__IO_fread) || defined(__CRT_HAVE_fread_unlocked) || defined(__CRT_HAVE__fread_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl))))
#include <libc/local/conio/_getch.h>
/* >> _getch(3), _getch_nolock(3)
 * Read a character from the console, without echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__NAMESPACE_LOCAL_USING_OR_IMPL(_getch, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _getch)(void) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_getch))(); })
#endif /* __CRT_HAVE_stdtty && (__CRT_HAVE__getch_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetc_unlocked || __CRT_HAVE_getc_unlocked || __CRT_HAVE__getc_nolock || __CRT_HAVE__fgetc_nolock || (__CRT_HAVE_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE_fgetc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE__IO_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_DOS && (__CRT_HAVE__filbuf || __CRT_HAVE___uflow || __CRT_HAVE___underflow)) || __CRT_HAVE_fread || __CRT_HAVE__IO_fread || __CRT_HAVE_fread_unlocked || __CRT_HAVE__fread_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))) */
#endif /* !... */
#ifdef __CRT_HAVE__getch_nolock
/* >> _getch(3), _getch_nolock(3)
 * Read a character from the console, without echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_getch_nolock,(void),())
#elif defined(__CRT_HAVE__getch)
/* >> _getch(3), _getch_nolock(3)
 * Read a character from the console, without echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__CREDIRECT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_getch_nolock,(void),_getch,())
#else /* ... */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__ECHO) && defined(__TCSANOW) && defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetc_unlocked) || defined(__CRT_HAVE_getc_unlocked) || defined(__CRT_HAVE__getc_nolock) || defined(__CRT_HAVE__fgetc_nolock) || (defined(__CRT_HAVE_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE_fgetc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE__IO_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__filbuf) || defined(__CRT_HAVE___uflow) || defined(__CRT_HAVE___underflow))) || defined(__CRT_HAVE_fread) || defined(__CRT_HAVE__IO_fread) || defined(__CRT_HAVE_fread_unlocked) || defined(__CRT_HAVE__fread_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl))
#include <libc/local/conio/_getch_nolock.h>
/* >> _getch(3), _getch_nolock(3)
 * Read a character from the console, without echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__NAMESPACE_LOCAL_USING_OR_IMPL(_getch_nolock, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _getch_nolock)(void) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_getch_nolock))(); })
#endif /* __ECHO && __TCSANOW && __CRT_HAVE_stdtty && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetc_unlocked || __CRT_HAVE_getc_unlocked || __CRT_HAVE__getc_nolock || __CRT_HAVE__fgetc_nolock || (__CRT_HAVE_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE_fgetc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE__IO_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_DOS && (__CRT_HAVE__filbuf || __CRT_HAVE___uflow || __CRT_HAVE___underflow)) || __CRT_HAVE_fread || __CRT_HAVE__IO_fread || __CRT_HAVE_fread_unlocked || __CRT_HAVE__fread_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) */
#endif /* !... */
#if defined(__CRT_HAVE__getche_nolock) && defined(__USE_STDIO_UNLOCKED)
/* >> _getche(3), _getche_nolock(3)
 * Read a character from the console, whilst also echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__CREDIRECT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_getche,(void),_getche_nolock,())
#elif defined(__CRT_HAVE__getche)
/* >> _getche(3), _getche_nolock(3)
 * Read a character from the console, whilst also echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_getche,(void),())
#else /* ... */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getche_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetc_unlocked) || defined(__CRT_HAVE_getc_unlocked) || defined(__CRT_HAVE__getc_nolock) || defined(__CRT_HAVE__fgetc_nolock) || (defined(__CRT_HAVE_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE_fgetc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE__IO_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__filbuf) || defined(__CRT_HAVE___uflow) || defined(__CRT_HAVE___underflow))) || defined(__CRT_HAVE_fread) || defined(__CRT_HAVE__IO_fread) || defined(__CRT_HAVE_fread_unlocked) || defined(__CRT_HAVE__fread_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl))))
#include <libc/local/conio/_getche.h>
/* >> _getche(3), _getche_nolock(3)
 * Read a character from the console, whilst also echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__NAMESPACE_LOCAL_USING_OR_IMPL(_getche, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _getche)(void) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_getche))(); })
#endif /* __CRT_HAVE_stdtty && (__CRT_HAVE__getche_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetc_unlocked || __CRT_HAVE_getc_unlocked || __CRT_HAVE__getc_nolock || __CRT_HAVE__fgetc_nolock || (__CRT_HAVE_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE_fgetc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE__IO_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_DOS && (__CRT_HAVE__filbuf || __CRT_HAVE___uflow || __CRT_HAVE___underflow)) || __CRT_HAVE_fread || __CRT_HAVE__IO_fread || __CRT_HAVE_fread_unlocked || __CRT_HAVE__fread_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))) */
#endif /* !... */
#ifdef __CRT_HAVE__getche_nolock
/* >> _getche(3), _getche_nolock(3)
 * Read a character from the console, whilst also echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__CDECLARE(__ATTR_WUNUSED,int,__NOTHROW_NCX,_getche_nolock,(void),())
#elif defined(__CRT_HAVE__getche)
/* >> _getche(3), _getche_nolock(3)
 * Read a character from the console, whilst also echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__CREDIRECT(__ATTR_WUNUSED,int,__NOTHROW_NCX,_getche_nolock,(void),_getche,())
#else /* ... */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__ECHO) && defined(__TCSANOW) && defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetc_unlocked) || defined(__CRT_HAVE_getc_unlocked) || defined(__CRT_HAVE__getc_nolock) || defined(__CRT_HAVE__fgetc_nolock) || (defined(__CRT_HAVE_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE_fgetc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE__IO_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__filbuf) || defined(__CRT_HAVE___uflow) || defined(__CRT_HAVE___underflow))) || defined(__CRT_HAVE_fread) || defined(__CRT_HAVE__IO_fread) || defined(__CRT_HAVE_fread_unlocked) || defined(__CRT_HAVE__fread_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl))
#include <libc/local/conio/_getche_nolock.h>
/* >> _getche(3), _getche_nolock(3)
 * Read a character from the console, whilst also echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__NAMESPACE_LOCAL_USING_OR_IMPL(_getche_nolock, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL _getche_nolock)(void) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_getche_nolock))(); })
#endif /* __ECHO && __TCSANOW && __CRT_HAVE_stdtty && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetc_unlocked || __CRT_HAVE_getc_unlocked || __CRT_HAVE__getc_nolock || __CRT_HAVE__fgetc_nolock || (__CRT_HAVE_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE_fgetc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE__IO_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_DOS && (__CRT_HAVE__filbuf || __CRT_HAVE___uflow || __CRT_HAVE___underflow)) || __CRT_HAVE_fread || __CRT_HAVE__IO_fread || __CRT_HAVE_fread_unlocked || __CRT_HAVE__fread_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) */
#endif /* !... */
#if defined(__CRT_HAVE__putch_nolock) && defined(__USE_STDIO_UNLOCKED)
__CREDIRECT(,int,__NOTHROW_NCX,_putch,(int __ch),_putch_nolock,(__ch))
#elif defined(__CRT_HAVE__putch)
__CDECLARE(,int,__NOTHROW_NCX,_putch,(int __ch),(__ch))
#elif defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock))
#include <libc/local/conio/_putch.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_putch, __FORCELOCAL __ATTR_ARTIFICIAL int __NOTHROW_NCX(__LIBCCALL _putch)(int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_putch))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__putch_nolock
__CDECLARE(,int,__NOTHROW_NCX,_putch_nolock,(int __ch),(__ch))
#elif defined(__CRT_HAVE__putch)
__CREDIRECT(,int,__NOTHROW_NCX,_putch_nolock,(int __ch),_putch,(__ch))
#elif defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_HAVE_putc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__flsbuf))) || (defined(__CRT_HAVE_fputc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__flsbuf))) || (defined(__CRT_HAVE__IO_putc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__flsbuf))) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock))
#include <libc/local/conio/_putch_nolock.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_putch_nolock, __FORCELOCAL __ATTR_ARTIFICIAL int __NOTHROW_NCX(__LIBCCALL _putch_nolock)(int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_putch_nolock))(__ch); })
#endif /* ... */
#if defined(__CRT_HAVE__ungetch_nolock) && defined(__USE_STDIO_UNLOCKED)
__CREDIRECT(,int,__NOTHROW_NCX,_ungetch,(int __ch),_ungetch_nolock,(__ch))
#elif defined(__CRT_HAVE__ungetch)
__CDECLARE(,int,__NOTHROW_NCX,_ungetch,(int __ch),(__ch))
#elif defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetc) || defined(__CRT_HAVE__IO_ungetc) || defined(__CRT_HAVE_ungetc_unlocked) || defined(__CRT_HAVE__ungetc_nolock))
#include <libc/local/conio/_ungetch.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ungetch, __FORCELOCAL __ATTR_ARTIFICIAL int __NOTHROW_NCX(__LIBCCALL _ungetch)(int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ungetch))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__ungetch_nolock
__CDECLARE(,int,__NOTHROW_NCX,_ungetch_nolock,(int __ch),(__ch))
#elif defined(__CRT_HAVE__ungetch)
__CREDIRECT(,int,__NOTHROW_NCX,_ungetch_nolock,(int __ch),_ungetch,(__ch))
#elif defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetc) || defined(__CRT_HAVE__IO_ungetc) || defined(__CRT_HAVE_ungetc_unlocked) || defined(__CRT_HAVE__ungetc_nolock))
#include <libc/local/conio/_ungetch_nolock.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_ungetch_nolock, __FORCELOCAL __ATTR_ARTIFICIAL int __NOTHROW_NCX(__LIBCCALL _ungetch_nolock)(int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ungetch_nolock))(__ch); })
#endif /* ... */
#ifdef __CRT_HAVE__cgets
__CDECLARE(__ATTR_NONNULL((1)),char *,__NOTHROW_NCX,_cgets,(char *__restrict __buf),(__buf))
#else /* __CRT_HAVE__cgets */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__CRT_HAVE__cgets_s) || (((defined(__CRT_HAVE__getch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getch_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetc_unlocked) || defined(__CRT_HAVE_getc_unlocked) || defined(__CRT_HAVE__getc_nolock) || defined(__CRT_HAVE__fgetc_nolock) || (defined(__CRT_HAVE_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE_fgetc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE__IO_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__filbuf) || defined(__CRT_HAVE___uflow) || defined(__CRT_HAVE___underflow))) || defined(__CRT_HAVE_fread) || defined(__CRT_HAVE__IO_fread) || defined(__CRT_HAVE_fread_unlocked) || defined(__CRT_HAVE__fread_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetc) || defined(__CRT_HAVE__IO_ungetc) || defined(__CRT_HAVE_ungetc_unlocked) || defined(__CRT_HAVE__ungetc_nolock)))))
#include <libc/local/conio/_cgets.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_cgets, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) char *__NOTHROW_NCX(__LIBCCALL _cgets)(char *__restrict __buf) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cgets))(__buf); })
#endif /* __CRT_HAVE__cgets_s || (((__CRT_HAVE__getch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getch || (__CRT_HAVE_stdtty && (__CRT_HAVE__getch_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetc_unlocked || __CRT_HAVE_getc_unlocked || __CRT_HAVE__getc_nolock || __CRT_HAVE__fgetc_nolock || (__CRT_HAVE_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE_fgetc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE__IO_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_DOS && (__CRT_HAVE__filbuf || __CRT_HAVE___uflow || __CRT_HAVE___underflow)) || __CRT_HAVE_fread || __CRT_HAVE__IO_fread || __CRT_HAVE_fread_unlocked || __CRT_HAVE__fread_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetc || __CRT_HAVE__IO_ungetc || __CRT_HAVE_ungetc_unlocked || __CRT_HAVE__ungetc_nolock)))) */
#endif /* !__CRT_HAVE__cgets */
#ifdef __CRT_HAVE__cgets_s
__CDECLARE(__ATTR_NONNULL((1, 3)),errno_t,__NOTHROW_NCX,_cgets_s,(char *__buf, size_t __bufsize, size_t *__restrict __p_readsize),(__buf,__bufsize,__p_readsize))
#else /* __CRT_HAVE__cgets_s */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if ((defined(__CRT_HAVE__getch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getch_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetc_unlocked) || defined(__CRT_HAVE_getc_unlocked) || defined(__CRT_HAVE__getc_nolock) || defined(__CRT_HAVE__fgetc_nolock) || (defined(__CRT_HAVE_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE_fgetc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE__IO_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__filbuf) || defined(__CRT_HAVE___uflow) || defined(__CRT_HAVE___underflow))) || defined(__CRT_HAVE_fread) || defined(__CRT_HAVE__IO_fread) || defined(__CRT_HAVE_fread_unlocked) || defined(__CRT_HAVE__fread_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetc) || defined(__CRT_HAVE__IO_ungetc) || defined(__CRT_HAVE_ungetc_unlocked) || defined(__CRT_HAVE__ungetc_nolock))))
#include <libc/local/conio/_cgets_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_cgets_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 3)) errno_t __NOTHROW_NCX(__LIBCCALL _cgets_s)(char *__buf, size_t __bufsize, size_t *__restrict __p_readsize) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cgets_s))(__buf, __bufsize, __p_readsize); })
#endif /* ((__CRT_HAVE__getch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getch || (__CRT_HAVE_stdtty && (__CRT_HAVE__getch_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetc_unlocked || __CRT_HAVE_getc_unlocked || __CRT_HAVE__getc_nolock || __CRT_HAVE__fgetc_nolock || (__CRT_HAVE_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE_fgetc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE__IO_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_DOS && (__CRT_HAVE__filbuf || __CRT_HAVE___uflow || __CRT_HAVE___underflow)) || __CRT_HAVE_fread || __CRT_HAVE__IO_fread || __CRT_HAVE_fread_unlocked || __CRT_HAVE__fread_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetc || __CRT_HAVE__IO_ungetc || __CRT_HAVE_ungetc_unlocked || __CRT_HAVE__ungetc_nolock))) */
#endif /* !__CRT_HAVE__cgets_s */
#ifdef __CRT_HAVE__cputs
__CDECLARE(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,_cputs,(char const *__restrict __str),(__str))
#elif (defined(__CRT_HAVE__putch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__putch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/_cputs.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_cputs, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBCCALL _cputs)(char const *__restrict __str) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cputs))(__str); })
#endif /* ... */
#ifdef __CRT_HAVE___conio_common_vcprintf
__CDECLARE(__ATTR_LIBC_PRINTF(2, 0) __ATTR_NONNULL((2)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__conio_common_vcprintf,(__UINT64_TYPE__ __options, char const *__format, __locale_t __locale, __builtin_va_list __args),(__options,__format,__locale,__args))
#elif defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock))
#include <libc/local/conio/__conio_common_vcprintf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__conio_common_vcprintf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_LIBC_PRINTF(2, 0) __ATTR_NONNULL((2)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBCCALL __conio_common_vcprintf)(__UINT64_TYPE__ __options, char const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__conio_common_vcprintf))(__options, __format, __locale, __args); })
#endif /* ... */
#ifdef __CRT_HAVE___conio_common_vcprintf_s
__CDECLARE(__ATTR_LIBC_PRINTF(2, 0) __ATTR_NONNULL((2)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__conio_common_vcprintf_s,(__UINT64_TYPE__ __options, char const *__format, __locale_t __locale, __builtin_va_list __args),(__options,__format,__locale,__args))
#elif defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf_s) || defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock))
#include <libc/local/conio/__conio_common_vcprintf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__conio_common_vcprintf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_LIBC_PRINTF(2, 0) __ATTR_NONNULL((2)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBCCALL __conio_common_vcprintf_s)(__UINT64_TYPE__ __options, char const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__conio_common_vcprintf_s))(__options, __format, __locale, __args); })
#endif /* ... */
#ifdef __CRT_HAVE___conio_common_vcprintf_p
__CDECLARE(__ATTR_LIBC_PRINTF_P(2, 0) __ATTR_NONNULL((2)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__conio_common_vcprintf_p,(__UINT64_TYPE__ __options, char const *__format, __locale_t __locale, __builtin_va_list __args),(__options,__format,__locale,__args))
#elif defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf_p) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock))
#include <libc/local/conio/__conio_common_vcprintf_p.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__conio_common_vcprintf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_LIBC_PRINTF_P(2, 0) __ATTR_NONNULL((2)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBCCALL __conio_common_vcprintf_p)(__UINT64_TYPE__ __options, char const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__conio_common_vcprintf_p))(__options, __format, __locale, __args); })
#endif /* ... */
#ifdef __CRT_HAVE___conio_common_vcscanf
__CDECLARE(__ATTR_WUNUSED __ATTR_LIBC_SCANF(2, 0) __ATTR_NONNULL((2)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__conio_common_vcscanf,(__UINT64_TYPE__ __options, char const *__format, __locale_t __locale, __builtin_va_list __args),(__options,__format,__locale,__args))
#else /* __CRT_HAVE___conio_common_vcscanf */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if ((defined(__CRT_HAVE__getwche_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getwche) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getwche_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetwch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetwch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked))))
#include <libc/local/conio/__conio_common_vcscanf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__conio_common_vcscanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_LIBC_SCANF(2, 0) __ATTR_NONNULL((2)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBCCALL __conio_common_vcscanf)(__UINT64_TYPE__ __options, char const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__conio_common_vcscanf))(__options, __format, __locale, __args); })
#endif /* ((__CRT_HAVE__getwche_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getwche || (__CRT_HAVE_stdtty && (__CRT_HAVE__getwche_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked || __CRT_HAVE__getwc_nolock || __CRT_HAVE__fgetwc_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetwch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetwch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked))) */
#endif /* !__CRT_HAVE___conio_common_vcscanf */
#ifdef __CRT_HAVE__vcprintf_l
__CDECLARE(__ATTR_LIBC_PRINTF(1, 0) __ATTR_NONNULL((1)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vcprintf_l,(char const *__format, __locale_t __locale, __builtin_va_list __args),(__format,__locale,__args))
#elif defined(__CRT_HAVE___conio_common_vcprintf) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/_vcprintf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vcprintf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_LIBC_PRINTF(1, 0) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBCCALL _vcprintf_l)(char const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vcprintf_l))(__format, __locale, __args); })
#endif /* ... */
#ifdef __CRT_HAVE__vcprintf_s_l
__CDECLARE(__ATTR_LIBC_PRINTF(1, 0) __ATTR_NONNULL((1)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vcprintf_s_l,(char const *__format, __locale_t __locale, __builtin_va_list __args),(__format,__locale,__args))
#elif defined(__CRT_HAVE___conio_common_vcprintf_s) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf_s) || defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/_vcprintf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vcprintf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_LIBC_PRINTF(1, 0) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBCCALL _vcprintf_s_l)(char const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vcprintf_s_l))(__format, __locale, __args); })
#endif /* ... */
#ifdef __CRT_HAVE__vcprintf_p_l
__CDECLARE(__ATTR_LIBC_PRINTF_P(1, 0) __ATTR_NONNULL((1)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vcprintf_p_l,(char const *__format, __locale_t __locale, __builtin_va_list __args),(__format,__locale,__args))
#elif defined(__CRT_HAVE___conio_common_vcprintf_p) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf_p) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/_vcprintf_p_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vcprintf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_LIBC_PRINTF_P(1, 0) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBCCALL _vcprintf_p_l)(char const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vcprintf_p_l))(__format, __locale, __args); })
#endif /* ... */
#ifdef __CRT_HAVE__vcscanf_l
__CDECLARE(__ATTR_WUNUSED __ATTR_LIBC_SCANF(1, 0) __ATTR_NONNULL((1)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vcscanf_l,(char const *__format, __locale_t __locale, __builtin_va_list __args),(__format,__locale,__args))
#else /* __CRT_HAVE__vcscanf_l */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__CRT_HAVE___conio_common_vcscanf) || (((defined(__CRT_HAVE__getwche_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getwche) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getwche_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetwch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetwch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))
#include <libc/local/conio/_vcscanf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vcscanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_LIBC_SCANF(1, 0) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBCCALL _vcscanf_l)(char const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vcscanf_l))(__format, __locale, __args); })
#endif /* __CRT_HAVE___conio_common_vcscanf || (((__CRT_HAVE__getwche_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getwche || (__CRT_HAVE_stdtty && (__CRT_HAVE__getwche_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked || __CRT_HAVE__getwc_nolock || __CRT_HAVE__fgetwc_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetwch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetwch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked)))) */
#endif /* !__CRT_HAVE__vcscanf_l */
#ifdef __CRT_HAVE__vcscanf_s_l
__CDECLARE(__ATTR_WUNUSED __ATTR_LIBC_SCANF(1, 0) __ATTR_NONNULL((1)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vcscanf_s_l,(char const *__format, __locale_t __locale, __builtin_va_list __args),(__format,__locale,__args))
#else /* __CRT_HAVE__vcscanf_s_l */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__CRT_HAVE___conio_common_vcscanf) || (((defined(__CRT_HAVE__getwche_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getwche) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getwche_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetwch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetwch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))
#include <libc/local/conio/_vcscanf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vcscanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_LIBC_SCANF(1, 0) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBCCALL _vcscanf_s_l)(char const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vcscanf_s_l))(__format, __locale, __args); })
#endif /* __CRT_HAVE___conio_common_vcscanf || (((__CRT_HAVE__getwche_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getwche || (__CRT_HAVE_stdtty && (__CRT_HAVE__getwche_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked || __CRT_HAVE__getwc_nolock || __CRT_HAVE__fgetwc_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetwch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetwch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked)))) */
#endif /* !__CRT_HAVE__vcscanf_s_l */
#ifdef __CRT_HAVE__vcprintf
__CDECLARE(__ATTR_LIBC_PRINTF(1, 0) __ATTR_NONNULL((1)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vcprintf,(char const *__format, __builtin_va_list __args),(__format,__args))
#elif defined(__CRT_HAVE__vcprintf_l) || defined(__CRT_HAVE___conio_common_vcprintf) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/_vcprintf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vcprintf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_LIBC_PRINTF(1, 0) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBCCALL _vcprintf)(char const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vcprintf))(__format, __args); })
#endif /* ... */
#ifdef __CRT_HAVE__vcprintf_s
__CDECLARE(__ATTR_LIBC_PRINTF(1, 0) __ATTR_NONNULL((1)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vcprintf_s,(char const *__format, __builtin_va_list __args),(__format,__args))
#elif defined(__CRT_HAVE__vcprintf_s_l) || defined(__CRT_HAVE___conio_common_vcprintf_s) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf_s) || defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/_vcprintf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vcprintf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_LIBC_PRINTF(1, 0) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBCCALL _vcprintf_s)(char const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vcprintf_s))(__format, __args); })
#endif /* ... */
#ifdef __CRT_HAVE__vcprintf_p
__CDECLARE(__ATTR_LIBC_PRINTF_P(1, 0) __ATTR_NONNULL((1)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vcprintf_p,(char const *__format, __builtin_va_list __args),(__format,__args))
#elif defined(__CRT_HAVE__vcprintf_p_l) || defined(__CRT_HAVE___conio_common_vcprintf_p) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf_p) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/_vcprintf_p.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vcprintf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_LIBC_PRINTF_P(1, 0) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBCCALL _vcprintf_p)(char const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vcprintf_p))(__format, __args); })
#endif /* ... */
#ifdef __CRT_HAVE__vcscanf
__CDECLARE(__ATTR_WUNUSED __ATTR_LIBC_SCANF(1, 0) __ATTR_NONNULL((1)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vcscanf,(char const *__format, __builtin_va_list __args),(__format,__args))
#else /* __CRT_HAVE__vcscanf */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__CRT_HAVE__vcscanf_l) || defined(__CRT_HAVE___conio_common_vcscanf) || (((defined(__CRT_HAVE__getwche_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getwche) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getwche_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetwch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetwch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))
#include <libc/local/conio/_vcscanf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vcscanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_LIBC_SCANF(1, 0) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBCCALL _vcscanf)(char const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vcscanf))(__format, __args); })
#endif /* __CRT_HAVE__vcscanf_l || __CRT_HAVE___conio_common_vcscanf || (((__CRT_HAVE__getwche_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getwche || (__CRT_HAVE_stdtty && (__CRT_HAVE__getwche_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked || __CRT_HAVE__getwc_nolock || __CRT_HAVE__fgetwc_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetwch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetwch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked)))) */
#endif /* !__CRT_HAVE__vcscanf */
#ifdef __CRT_HAVE__vcscanf_s
__CDECLARE(__ATTR_WUNUSED __ATTR_LIBC_SCANF(1, 0) __ATTR_NONNULL((1)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vcscanf_s,(char const *__format, __builtin_va_list __args),(__format,__args))
#else /* __CRT_HAVE__vcscanf_s */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__CRT_HAVE__vcscanf_s_l) || defined(__CRT_HAVE___conio_common_vcscanf) || (((defined(__CRT_HAVE__getwche_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getwche) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getwche_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetwch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetwch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))
#include <libc/local/conio/_vcscanf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vcscanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_LIBC_SCANF(1, 0) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBCCALL _vcscanf_s)(char const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vcscanf_s))(__format, __args); })
#endif /* __CRT_HAVE__vcscanf_s_l || __CRT_HAVE___conio_common_vcscanf || (((__CRT_HAVE__getwche_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getwche || (__CRT_HAVE_stdtty && (__CRT_HAVE__getwche_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked || __CRT_HAVE__getwc_nolock || __CRT_HAVE__fgetwc_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetwch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetwch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked)))) */
#endif /* !__CRT_HAVE__vcscanf_s */
#ifdef __CRT_HAVE__cprintf
__LIBC __ATTR_LIBC_PRINTF(1, 2) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cprintf)(char const *__format, ...) __CASMNAME_SAME("_cprintf");
#elif defined(__CRT_HAVE__vcprintf) || defined(__CRT_HAVE__vcprintf_l) || defined(__CRT_HAVE___conio_common_vcprintf) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/_cprintf.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_cprintf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_LIBC_PRINTF(1, 2) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cprintf)(char const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cprintf))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _cprintf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cprintf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#ifdef __CRT_HAVE__cprintf_l
__LIBC __ATTR_LIBC_PRINTF(1, 3) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cprintf_l)(char const *__format, __locale_t __locale, ...) __CASMNAME_SAME("_cprintf_l");
#elif defined(__CRT_HAVE__vcprintf_l) || defined(__CRT_HAVE___conio_common_vcprintf) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/_cprintf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_cprintf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_LIBC_PRINTF(1, 3) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cprintf_l)(char const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cprintf_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _cprintf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cprintf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#ifdef __CRT_HAVE__cprintf_s
__LIBC __ATTR_LIBC_PRINTF(1, 2) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cprintf_s)(char const *__format, ...) __CASMNAME_SAME("_cprintf_s");
#elif defined(__CRT_HAVE__vcprintf_s) || defined(__CRT_HAVE__vcprintf_s_l) || defined(__CRT_HAVE___conio_common_vcprintf_s) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf_s) || defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/_cprintf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_cprintf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_LIBC_PRINTF(1, 2) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cprintf_s)(char const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cprintf_s))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _cprintf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cprintf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#ifdef __CRT_HAVE__cprintf_s_l
__LIBC __ATTR_LIBC_PRINTF(1, 3) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cprintf_s_l)(char const *__format, __locale_t __locale, ...) __CASMNAME_SAME("_cprintf_s_l");
#elif defined(__CRT_HAVE__vcprintf_s_l) || defined(__CRT_HAVE___conio_common_vcprintf_s) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf_s) || defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/_cprintf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_cprintf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_LIBC_PRINTF(1, 3) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cprintf_s_l)(char const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cprintf_s_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _cprintf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cprintf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#ifdef __CRT_HAVE__cprintf_p
__LIBC __ATTR_LIBC_PRINTF_P(1, 2) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cprintf_p)(char const *__format, ...) __CASMNAME_SAME("_cprintf_p");
#elif defined(__CRT_HAVE__vcprintf_p) || defined(__CRT_HAVE__vcprintf_p_l) || defined(__CRT_HAVE___conio_common_vcprintf_p) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf_p) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/_cprintf_p.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_cprintf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_LIBC_PRINTF_P(1, 2) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cprintf_p)(char const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cprintf_p))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _cprintf_p(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cprintf_p))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#ifdef __CRT_HAVE__cprintf_p_l
__LIBC __ATTR_LIBC_PRINTF_P(1, 3) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cprintf_p_l)(char const *__format, __locale_t __locale, ...) __CASMNAME_SAME("_cprintf_p_l");
#elif defined(__CRT_HAVE__vcprintf_p_l) || defined(__CRT_HAVE___conio_common_vcprintf_p) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf_p) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/_cprintf_p_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_cprintf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_LIBC_PRINTF_P(1, 3) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cprintf_p_l)(char const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cprintf_p_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _cprintf_p_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cprintf_p_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#ifdef __CRT_HAVE__cscanf
__LIBC __ATTR_WUNUSED __ATTR_LIBC_SCANF(1, 2) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cscanf)(char const *__format, ...) __CASMNAME_SAME("_cscanf");
#else /* __CRT_HAVE__cscanf */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__CRT_HAVE__vcscanf) || defined(__CRT_HAVE__vcscanf_l) || defined(__CRT_HAVE___conio_common_vcscanf) || (((defined(__CRT_HAVE__getwche_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getwche) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getwche_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetwch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetwch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))
#include <libc/local/conio/_cscanf.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_cscanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_LIBC_SCANF(1, 2) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cscanf)(char const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cscanf))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _cscanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cscanf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* __CRT_HAVE__vcscanf || __CRT_HAVE__vcscanf_l || __CRT_HAVE___conio_common_vcscanf || (((__CRT_HAVE__getwche_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getwche || (__CRT_HAVE_stdtty && (__CRT_HAVE__getwche_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked || __CRT_HAVE__getwc_nolock || __CRT_HAVE__fgetwc_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetwch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetwch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked)))) */
#endif /* !__CRT_HAVE__cscanf */
#ifdef __CRT_HAVE__cscanf_l
__LIBC __ATTR_WUNUSED __ATTR_LIBC_SCANF(1, 3) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cscanf_l)(char const *__format, __locale_t __locale, ...) __CASMNAME_SAME("_cscanf_l");
#else /* __CRT_HAVE__cscanf_l */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__CRT_HAVE__vcscanf_l) || defined(__CRT_HAVE___conio_common_vcscanf) || (((defined(__CRT_HAVE__getwche_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getwche) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getwche_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetwch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetwch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))
#include <libc/local/conio/_cscanf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_cscanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_LIBC_SCANF(1, 3) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cscanf_l)(char const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cscanf_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _cscanf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cscanf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* __CRT_HAVE__vcscanf_l || __CRT_HAVE___conio_common_vcscanf || (((__CRT_HAVE__getwche_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getwche || (__CRT_HAVE_stdtty && (__CRT_HAVE__getwche_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked || __CRT_HAVE__getwc_nolock || __CRT_HAVE__fgetwc_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetwch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetwch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked)))) */
#endif /* !__CRT_HAVE__cscanf_l */
#ifdef __CRT_HAVE__cscanf_s
__LIBC __ATTR_WUNUSED __ATTR_LIBC_SCANF(1, 2) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cscanf_s)(char const *__format, ...) __CASMNAME_SAME("_cscanf_s");
#else /* __CRT_HAVE__cscanf_s */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__CRT_HAVE__vcscanf_s) || defined(__CRT_HAVE__vcscanf_s_l) || defined(__CRT_HAVE___conio_common_vcscanf) || (((defined(__CRT_HAVE__getwche_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getwche) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getwche_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetwch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetwch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))
#include <libc/local/conio/_cscanf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_cscanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_LIBC_SCANF(1, 2) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cscanf_s)(char const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cscanf_s))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _cscanf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cscanf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* __CRT_HAVE__vcscanf_s || __CRT_HAVE__vcscanf_s_l || __CRT_HAVE___conio_common_vcscanf || (((__CRT_HAVE__getwche_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getwche || (__CRT_HAVE_stdtty && (__CRT_HAVE__getwche_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked || __CRT_HAVE__getwc_nolock || __CRT_HAVE__fgetwc_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetwch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetwch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked)))) */
#endif /* !__CRT_HAVE__cscanf_s */
#ifdef __CRT_HAVE__cscanf_s_l
__LIBC __ATTR_WUNUSED __ATTR_LIBC_SCANF(1, 3) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cscanf_s_l)(char const *__format, __locale_t __locale, ...) __CASMNAME_SAME("_cscanf_s_l");
#else /* __CRT_HAVE__cscanf_s_l */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__CRT_HAVE__vcscanf_s_l) || defined(__CRT_HAVE___conio_common_vcscanf) || (((defined(__CRT_HAVE__getwche_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getwche) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getwche_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetwch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetwch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))
#include <libc/local/conio/_cscanf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_cscanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_LIBC_SCANF(1, 3) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL _cscanf_s_l)(char const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cscanf_s_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _cscanf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cscanf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* __CRT_HAVE__vcscanf_s_l || __CRT_HAVE___conio_common_vcscanf || (((__CRT_HAVE__getwche_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getwche || (__CRT_HAVE_stdtty && (__CRT_HAVE__getwche_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked || __CRT_HAVE__getwc_nolock || __CRT_HAVE__fgetwc_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetwch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetwch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked)))) */
#endif /* !__CRT_HAVE__cscanf_s_l */
#ifdef __CRT_HAVE__cgets
__CREDIRECT(__ATTR_NONNULL((1)),char *,__NOTHROW_NCX,cgets,(char *__restrict __buf),_cgets,(__buf))
#else /* __CRT_HAVE__cgets */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__CRT_HAVE__cgets_s) || (((defined(__CRT_HAVE__getch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getch_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetc_unlocked) || defined(__CRT_HAVE_getc_unlocked) || defined(__CRT_HAVE__getc_nolock) || defined(__CRT_HAVE__fgetc_nolock) || (defined(__CRT_HAVE_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE_fgetc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE__IO_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__filbuf) || defined(__CRT_HAVE___uflow) || defined(__CRT_HAVE___underflow))) || defined(__CRT_HAVE_fread) || defined(__CRT_HAVE__IO_fread) || defined(__CRT_HAVE_fread_unlocked) || defined(__CRT_HAVE__fread_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetc) || defined(__CRT_HAVE__IO_ungetc) || defined(__CRT_HAVE_ungetc_unlocked) || defined(__CRT_HAVE__ungetc_nolock)))))
#include <libc/local/conio/_cgets.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) char *__NOTHROW_NCX(__LIBCCALL cgets)(char *__restrict __buf) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cgets))(__buf); }
#endif /* __CRT_HAVE__cgets_s || (((__CRT_HAVE__getch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getch || (__CRT_HAVE_stdtty && (__CRT_HAVE__getch_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetc_unlocked || __CRT_HAVE_getc_unlocked || __CRT_HAVE__getc_nolock || __CRT_HAVE__fgetc_nolock || (__CRT_HAVE_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE_fgetc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE__IO_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_DOS && (__CRT_HAVE__filbuf || __CRT_HAVE___uflow || __CRT_HAVE___underflow)) || __CRT_HAVE_fread || __CRT_HAVE__IO_fread || __CRT_HAVE_fread_unlocked || __CRT_HAVE__fread_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetc || __CRT_HAVE__IO_ungetc || __CRT_HAVE_ungetc_unlocked || __CRT_HAVE__ungetc_nolock)))) */
#endif /* !__CRT_HAVE__cgets */
#ifdef __CRT_HAVE__cputs
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,cputs,(char const *__restrict __str),_cputs,(__str))
#elif (defined(__CRT_HAVE__putch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__putch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/_cputs.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBCCALL cputs)(char const *__restrict __str) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cputs))(__str); }
#endif /* ... */
#if defined(__CRT_HAVE__getch_nolock) && defined(__USE_STDIO_UNLOCKED)
/* >> _getch(3), _getch_nolock(3)
 * Read a character from the console, without echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__CREDIRECT(__ATTR_WUNUSED,int,__NOTHROW_NCX,getch,(void),_getch_nolock,())
#elif defined(__CRT_HAVE__getch)
/* >> _getch(3), _getch_nolock(3)
 * Read a character from the console, without echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__CREDIRECT(__ATTR_WUNUSED,int,__NOTHROW_NCX,getch,(void),_getch,())
#else /* ... */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getch_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetc_unlocked) || defined(__CRT_HAVE_getc_unlocked) || defined(__CRT_HAVE__getc_nolock) || defined(__CRT_HAVE__fgetc_nolock) || (defined(__CRT_HAVE_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE_fgetc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE__IO_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__filbuf) || defined(__CRT_HAVE___uflow) || defined(__CRT_HAVE___underflow))) || defined(__CRT_HAVE_fread) || defined(__CRT_HAVE__IO_fread) || defined(__CRT_HAVE_fread_unlocked) || defined(__CRT_HAVE__fread_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl))))
#include <libc/local/conio/_getch.h>
/* >> _getch(3), _getch_nolock(3)
 * Read a character from the console, without echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL getch)(void) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_getch))(); }
#endif /* __CRT_HAVE_stdtty && (__CRT_HAVE__getch_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetc_unlocked || __CRT_HAVE_getc_unlocked || __CRT_HAVE__getc_nolock || __CRT_HAVE__fgetc_nolock || (__CRT_HAVE_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE_fgetc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE__IO_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_DOS && (__CRT_HAVE__filbuf || __CRT_HAVE___uflow || __CRT_HAVE___underflow)) || __CRT_HAVE_fread || __CRT_HAVE__IO_fread || __CRT_HAVE_fread_unlocked || __CRT_HAVE__fread_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))) */
#endif /* !... */
#if defined(__CRT_HAVE__getche_nolock) && defined(__USE_STDIO_UNLOCKED)
/* >> _getche(3), _getche_nolock(3)
 * Read a character from the console, whilst also echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__CREDIRECT(__ATTR_WUNUSED,int,__NOTHROW_NCX,getche,(void),_getche_nolock,())
#elif defined(__CRT_HAVE__getche)
/* >> _getche(3), _getche_nolock(3)
 * Read a character from the console, whilst also echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__CREDIRECT(__ATTR_WUNUSED,int,__NOTHROW_NCX,getche,(void),_getche,())
#else /* ... */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getche_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetc_unlocked) || defined(__CRT_HAVE_getc_unlocked) || defined(__CRT_HAVE__getc_nolock) || defined(__CRT_HAVE__fgetc_nolock) || (defined(__CRT_HAVE_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE_fgetc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE__IO_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__filbuf) || defined(__CRT_HAVE___uflow) || defined(__CRT_HAVE___underflow))) || defined(__CRT_HAVE_fread) || defined(__CRT_HAVE__IO_fread) || defined(__CRT_HAVE_fread_unlocked) || defined(__CRT_HAVE__fread_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl))))
#include <libc/local/conio/_getche.h>
/* >> _getche(3), _getche_nolock(3)
 * Read a character from the console, whilst also echoing it on-screen
 * @return: * : The character read from the console
 * @return: -1: End-of-file on console */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED int __NOTHROW_NCX(__LIBCCALL getche)(void) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_getche))(); }
#endif /* __CRT_HAVE_stdtty && (__CRT_HAVE__getche_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetc_unlocked || __CRT_HAVE_getc_unlocked || __CRT_HAVE__getc_nolock || __CRT_HAVE__fgetc_nolock || (__CRT_HAVE_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE_fgetc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE__IO_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_DOS && (__CRT_HAVE__filbuf || __CRT_HAVE___uflow || __CRT_HAVE___underflow)) || __CRT_HAVE_fread || __CRT_HAVE__IO_fread || __CRT_HAVE_fread_unlocked || __CRT_HAVE__fread_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))) */
#endif /* !... */
#ifdef __CRT_HAVE__kbhit
__CREDIRECT(__ATTR_WUNUSED,int,__NOTHROW_NCX,kbhit,(void),_kbhit,())
#endif /* __CRT_HAVE__kbhit */
#if defined(__CRT_HAVE__putch_nolock) && defined(__USE_STDIO_UNLOCKED)
__CREDIRECT(,int,__NOTHROW_NCX,putch,(int __ch),_putch_nolock,(__ch))
#elif defined(__CRT_HAVE__putch)
__CREDIRECT(,int,__NOTHROW_NCX,putch,(int __ch),_putch,(__ch))
#elif defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock))
#include <libc/local/conio/_putch.h>
__FORCELOCAL __ATTR_ARTIFICIAL int __NOTHROW_NCX(__LIBCCALL putch)(int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_putch))(__ch); }
#endif /* ... */
#if defined(__CRT_HAVE__ungetch_nolock) && defined(__USE_STDIO_UNLOCKED)
__CREDIRECT(,int,__NOTHROW_NCX,ungetch,(int __ch),_ungetch_nolock,(__ch))
#elif defined(__CRT_HAVE__ungetch)
__CREDIRECT(,int,__NOTHROW_NCX,ungetch,(int __ch),_ungetch,(__ch))
#elif defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetc) || defined(__CRT_HAVE__IO_ungetc) || defined(__CRT_HAVE_ungetc_unlocked) || defined(__CRT_HAVE__ungetc_nolock))
#include <libc/local/conio/_ungetch.h>
__FORCELOCAL __ATTR_ARTIFICIAL int __NOTHROW_NCX(__LIBCCALL ungetch)(int __ch) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_ungetch))(__ch); }
#endif /* ... */
#ifdef __CRT_HAVE__cprintf
__LIBC __ATTR_LIBC_PRINTF(1, 2) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL cprintf)(char const *__format, ...) __CASMNAME("_cprintf");
#elif defined(__CRT_HAVE__vcprintf) || defined(__CRT_HAVE__vcprintf_l) || defined(__CRT_HAVE___conio_common_vcprintf) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/_cprintf.h>
#define cprintf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cprintf))(__VA_ARGS__)
#endif /* ... */
#ifdef __CRT_HAVE__cscanf
__LIBC __ATTR_WUNUSED __ATTR_LIBC_SCANF(1, 2) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBCCALL cscanf)(char const *__format, ...) __CASMNAME("_cscanf");
#else /* __CRT_HAVE__cscanf */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__CRT_HAVE__vcscanf) || defined(__CRT_HAVE__vcscanf_l) || defined(__CRT_HAVE___conio_common_vcscanf) || (((defined(__CRT_HAVE__getwche_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getwche) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getwche_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetwch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetwch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))
#include <libc/local/conio/_cscanf.h>
#define cscanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_cscanf))(__VA_ARGS__)
#endif /* __CRT_HAVE__vcscanf || __CRT_HAVE__vcscanf_l || __CRT_HAVE___conio_common_vcscanf || (((__CRT_HAVE__getwche_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getwche || (__CRT_HAVE_stdtty && (__CRT_HAVE__getwche_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked || __CRT_HAVE__getwc_nolock || __CRT_HAVE__fgetwc_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetwch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetwch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked)))) */
#endif /* !__CRT_HAVE__cscanf */






/* Functions also defined by DJGPP */

#ifdef __CRT_HAVE_clreol
/* >> clreol(3)
 * Clear all cells from the cursor (inclusive) until the end
 * of the  current  line.  (s.a.  `AC_EL(ANSITTY_EL_AFTER)') */
__CDECLARE_VOID(,__NOTHROW_NCX,clreol,(void),())
#elif defined(__CRT_HAVE__cputs) || (defined(__CRT_HAVE__putch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__putch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/clreol.h>
/* >> clreol(3)
 * Clear all cells from the cursor (inclusive) until the end
 * of the  current  line.  (s.a.  `AC_EL(ANSITTY_EL_AFTER)') */
__NAMESPACE_LOCAL_USING_OR_IMPL(clreol, __FORCELOCAL __ATTR_ARTIFICIAL void __NOTHROW_NCX(__LIBCCALL clreol)(void) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(clreol))(); })
#endif /* ... */
#ifdef __CRT_HAVE_clrscr
/* >> clrscr(3)
 * Clear the entire screen (s.a. `AC_ED(ANSITTY_CLS_ALL)') */
__CDECLARE_VOID(,__NOTHROW_NCX,clrscr,(void),())
#elif defined(__CRT_HAVE__cputs) || (defined(__CRT_HAVE__putch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__putch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/clrscr.h>
/* >> clrscr(3)
 * Clear the entire screen (s.a. `AC_ED(ANSITTY_CLS_ALL)') */
__NAMESPACE_LOCAL_USING_OR_IMPL(clrscr, __FORCELOCAL __ATTR_ARTIFICIAL void __NOTHROW_NCX(__LIBCCALL clrscr)(void) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(clrscr))(); })
#endif /* ... */
#ifdef __CRT_HAVE_gotoxy
/* >> gotoxy(3)
 * Set the cursor {x,y} position (s.a. `AC_CUP(y, x)') */
__CDECLARE_VOID(,__NOTHROW_NCX,gotoxy,(int __x, int __y),(__x,__y))
#elif defined(__CRT_HAVE__cprintf) || defined(__CRT_HAVE__vcprintf) || defined(__CRT_HAVE__vcprintf_l) || defined(__CRT_HAVE___conio_common_vcprintf) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/gotoxy.h>
/* >> gotoxy(3)
 * Set the cursor {x,y} position (s.a. `AC_CUP(y, x)') */
__NAMESPACE_LOCAL_USING_OR_IMPL(gotoxy, __FORCELOCAL __ATTR_ARTIFICIAL void __NOTHROW_NCX(__LIBCCALL gotoxy)(int __x, int __y) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(gotoxy))(__x, __y); })
#endif /* ... */
#ifdef __CRT_HAVE_delline
/* >> delline(3)
 * Delete the line at the current cursor position, moving  the
 * screen contents underneath up one line. (s.a. `AC_DL("1")') */
__CDECLARE_VOID(,__NOTHROW_NCX,delline,(void),())
#elif defined(__CRT_HAVE__cputs) || (defined(__CRT_HAVE__putch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__putch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/delline.h>
/* >> delline(3)
 * Delete the line at the current cursor position, moving  the
 * screen contents underneath up one line. (s.a. `AC_DL("1")') */
__NAMESPACE_LOCAL_USING_OR_IMPL(delline, __FORCELOCAL __ATTR_ARTIFICIAL void __NOTHROW_NCX(__LIBCCALL delline)(void) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(delline))(); })
#endif /* ... */
#ifdef __CRT_HAVE_insline
/* >> insline(3)
 * Insert a blank line at the current cursor position, moving the
 * screen  contents underneath down one line. (s.a. `AC_IL("1")') */
__CDECLARE_VOID(,__NOTHROW_NCX,insline,(void),())
#elif defined(__CRT_HAVE__cputs) || (defined(__CRT_HAVE__putch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__putch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/insline.h>
/* >> insline(3)
 * Insert a blank line at the current cursor position, moving the
 * screen  contents underneath down one line. (s.a. `AC_IL("1")') */
__NAMESPACE_LOCAL_USING_OR_IMPL(insline, __FORCELOCAL __ATTR_ARTIFICIAL void __NOTHROW_NCX(__LIBCCALL insline)(void) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(insline))(); })
#endif /* ... */
#ifdef __CRT_HAVE_highvideo
/* >> highvideo(3)
 * Brighten text foreground color (s.a. `AC_FGBRIGHT') */
__CDECLARE_VOID(,__NOTHROW_NCX,highvideo,(void),())
#elif defined(__CRT_HAVE__cputs) || (defined(__CRT_HAVE__putch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__putch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/highvideo.h>
/* >> highvideo(3)
 * Brighten text foreground color (s.a. `AC_FGBRIGHT') */
__NAMESPACE_LOCAL_USING_OR_IMPL(highvideo, __FORCELOCAL __ATTR_ARTIFICIAL void __NOTHROW_NCX(__LIBCCALL highvideo)(void) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(highvideo))(); })
#endif /* ... */
#ifdef __CRT_HAVE_lowvideo
/* >> lowvideo(3)
 * Darken text foreground color (s.a. `AC_FGDARK') */
__CDECLARE_VOID(,__NOTHROW_NCX,lowvideo,(void),())
#elif defined(__CRT_HAVE__cputs) || (defined(__CRT_HAVE__putch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__putch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/lowvideo.h>
/* >> lowvideo(3)
 * Darken text foreground color (s.a. `AC_FGDARK') */
__NAMESPACE_LOCAL_USING_OR_IMPL(lowvideo, __FORCELOCAL __ATTR_ARTIFICIAL void __NOTHROW_NCX(__LIBCCALL lowvideo)(void) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(lowvideo))(); })
#endif /* ... */
#ifdef __CRT_HAVE_normvideo
/* >> normvideo(3)
 * Reset all graphics attributes to normal (s.a. `AC_DEFATTR') */
__CDECLARE_VOID(,__NOTHROW_NCX,normvideo,(void),())
#elif defined(__CRT_HAVE__cputs) || (defined(__CRT_HAVE__putch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__putch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/normvideo.h>
/* >> normvideo(3)
 * Reset all graphics attributes to normal (s.a. `AC_DEFATTR') */
__NAMESPACE_LOCAL_USING_OR_IMPL(normvideo, __FORCELOCAL __ATTR_ARTIFICIAL void __NOTHROW_NCX(__LIBCCALL normvideo)(void) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(normvideo))(); })
#endif /* ... */
#ifdef __COMPILER_HAVE_PRAGMA_PUSHMACRO
#pragma push_macro("COLORS")
#pragma push_macro("BLACK")
#pragma push_macro("BLUE")
#pragma push_macro("GREEN")
#pragma push_macro("CYAN")
#pragma push_macro("RED")
#pragma push_macro("MAGENTA")
#pragma push_macro("BROWN")
#pragma push_macro("LIGHTGRAY")
#pragma push_macro("DARKGRA")
#pragma push_macro("LIGHTBLUE")
#pragma push_macro("LIGHTGREEN")
#pragma push_macro("LIGHTCYAN")
#pragma push_macro("LIGHTRED")
#pragma push_macro("LIGHTMAGENTA")
#pragma push_macro("YELLOW")
#pragma push_macro("WHITE")
#endif /* __COMPILER_HAVE_PRAGMA_PUSHMACRO */
#undef COLORS
#undef BLACK
#undef BLUE
#undef GREEN
#undef CYAN
#undef RED
#undef MAGENTA
#undef BROWN
#undef LIGHTGRAY
#undef DARKGRA
#undef LIGHTBLUE
#undef LIGHTGREEN
#undef LIGHTCYAN
#undef LIGHTRED
#undef LIGHTMAGENTA
#undef YELLOW
#undef WHITE

/* CONIO color codes for `textcolor(3)' and `textbackground(3)' */
enum COLORS {
	BLACK        = 0x0,
	BLUE         = 0x1,
	GREEN        = 0x2,
	CYAN         = 0x3,
	RED          = 0x4,
	MAGENTA      = 0x5,
	BROWN        = 0x6,
	LIGHTGRAY    = 0x7,
	DARKGRAY     = 0x8,
	LIGHTBLUE    = 0x9,
	LIGHTGREEN   = 0xa,
	LIGHTCYAN    = 0xb,
	LIGHTRED     = 0xc,
	LIGHTMAGENTA = 0xd,
	YELLOW       = 0xe,
	WHITE        = 0xf
};
#ifdef __COMPILER_HAVE_PRAGMA_PUSHMACRO
#pragma pop_macro("WHITE")
#pragma pop_macro("YELLOW")
#pragma pop_macro("LIGHTMAGENTA")
#pragma pop_macro("LIGHTRED")
#pragma pop_macro("LIGHTCYAN")
#pragma pop_macro("LIGHTGREEN")
#pragma pop_macro("LIGHTBLUE")
#pragma pop_macro("DARKGRA")
#pragma pop_macro("LIGHTGRAY")
#pragma pop_macro("BROWN")
#pragma pop_macro("MAGENTA")
#pragma pop_macro("RED")
#pragma pop_macro("CYAN")
#pragma pop_macro("GREEN")
#pragma pop_macro("BLUE")
#pragma pop_macro("BLACK")
#pragma pop_macro("COLORS")
#endif /* __COMPILER_HAVE_PRAGMA_PUSHMACRO */
#ifdef __CRT_HAVE_textcolor
/* >> textcolor(3)
 * @param: color: Color code (s.a. constants in `<conio.h>') */
__CDECLARE_VOID(,__NOTHROW_NCX,textcolor,(int __color),(__color))
#elif defined(__CRT_HAVE__cprintf) || defined(__CRT_HAVE__vcprintf) || defined(__CRT_HAVE__vcprintf_l) || defined(__CRT_HAVE___conio_common_vcprintf) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/textcolor.h>
/* >> textcolor(3)
 * @param: color: Color code (s.a. constants in `<conio.h>') */
__NAMESPACE_LOCAL_USING_OR_IMPL(textcolor, __FORCELOCAL __ATTR_ARTIFICIAL void __NOTHROW_NCX(__LIBCCALL textcolor)(int __color) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(textcolor))(__color); })
#endif /* ... */
#ifdef __CRT_HAVE_textbackground
/* >> textbackground(3)
 * @param: color: Color code (s.a. constants in `<conio.h>') */
__CDECLARE_VOID(,__NOTHROW_NCX,textbackground,(int __color),(__color))
#elif defined(__CRT_HAVE__cprintf) || defined(__CRT_HAVE__vcprintf) || defined(__CRT_HAVE__vcprintf_l) || defined(__CRT_HAVE___conio_common_vcprintf) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/textbackground.h>
/* >> textbackground(3)
 * @param: color: Color code (s.a. constants in `<conio.h>') */
__NAMESPACE_LOCAL_USING_OR_IMPL(textbackground, __FORCELOCAL __ATTR_ARTIFICIAL void __NOTHROW_NCX(__LIBCCALL textbackground)(int __color) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(textbackground))(__color); })
#endif /* ... */
#ifdef __CRT_HAVE_textattr
/* >> textattr(3)
 * Set text attributes: `textcolor(attr & 0x0f)' and `textbackground((attr & 0xf0) >> 8)' */
__CDECLARE_VOID(,__NOTHROW_NCX,textattr,(int __attr),(__attr))
#elif (defined(__CRT_HAVE_textcolor) || defined(__CRT_HAVE__cprintf) || defined(__CRT_HAVE__vcprintf) || defined(__CRT_HAVE__vcprintf_l) || defined(__CRT_HAVE___conio_common_vcprintf) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))) && (defined(__CRT_HAVE_textbackground) || defined(__CRT_HAVE__cprintf) || defined(__CRT_HAVE__vcprintf) || defined(__CRT_HAVE__vcprintf_l) || defined(__CRT_HAVE___conio_common_vcprintf) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock))))
#include <libc/local/conio/textattr.h>
/* >> textattr(3)
 * Set text attributes: `textcolor(attr & 0x0f)' and `textbackground((attr & 0xf0) >> 8)' */
__NAMESPACE_LOCAL_USING_OR_IMPL(textattr, __FORCELOCAL __ATTR_ARTIFICIAL void __NOTHROW_NCX(__LIBCCALL textattr)(int __attr) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(textattr))(__attr); })
#endif /* ... */
#ifdef __CRT_HAVE_clearkeybuf
/* >> clearkeybuf(3)
 * Flush all unread input (usually keyboard) data pending on the terminal */
__CDECLARE_VOID(,__NOTHROW_NCX,clearkeybuf,(void),())
#else /* __CRT_HAVE_clearkeybuf */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if defined(__TCSADRAIN) && defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___fpurge) || defined(__CRT_HAVE_fpurge)) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetc_unlocked) || defined(__CRT_HAVE_getc_unlocked) || defined(__CRT_HAVE__getc_nolock) || defined(__CRT_HAVE__fgetc_nolock) || (defined(__CRT_HAVE_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE_fgetc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE__IO_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__filbuf) || defined(__CRT_HAVE___uflow) || defined(__CRT_HAVE___underflow))) || defined(__CRT_HAVE_fread) || defined(__CRT_HAVE__IO_fread) || defined(__CRT_HAVE_fread_unlocked) || defined(__CRT_HAVE__fread_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl))
#include <libc/local/conio/clearkeybuf.h>
/* >> clearkeybuf(3)
 * Flush all unread input (usually keyboard) data pending on the terminal */
__NAMESPACE_LOCAL_USING_OR_IMPL(clearkeybuf, __FORCELOCAL __ATTR_ARTIFICIAL void __NOTHROW_NCX(__LIBCCALL clearkeybuf)(void) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(clearkeybuf))(); })
#endif /* __TCSADRAIN && __CRT_HAVE_stdtty && (__CRT_HAVE___fpurge || __CRT_HAVE_fpurge) && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetc_unlocked || __CRT_HAVE_getc_unlocked || __CRT_HAVE__getc_nolock || __CRT_HAVE__fgetc_nolock || (__CRT_HAVE_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE_fgetc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE__IO_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_DOS && (__CRT_HAVE__filbuf || __CRT_HAVE___uflow || __CRT_HAVE___underflow)) || __CRT_HAVE_fread || __CRT_HAVE__IO_fread || __CRT_HAVE_fread_unlocked || __CRT_HAVE__fread_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) */
#endif /* !__CRT_HAVE_clearkeybuf */
#ifndef __getpass_defined
#define __getpass_defined
#ifdef __CRT_HAVE__conio_getpass
/* >> _conio_getpass(3)
 * CONIO version of getpass(3). But note the slightly different variant from `<unistd.h>' */
__CREDIRECT(__ATTR_NONNULL((1, 2)),char *,__NOTHROW_NCX,getpass,(const char *__prompt, char *__str),_conio_getpass,(__prompt,__str))
#else /* __CRT_HAVE__conio_getpass */
#include <asm/os/stdio.h>
#if defined(__CRT_HAVE_getpass_r) || defined(__CRT_HAVE_getpassfd) || defined(__CRT_HAVE_read) || defined(__CRT_HAVE__read) || defined(__CRT_HAVE___read) || defined(__CRT_HAVE___libc_read) || defined(__CRT_HAVE_readpassphrase)
#include <libc/local/conio/_conio_getpass.h>
/* >> _conio_getpass(3)
 * CONIO version of getpass(3). But note the slightly different variant from `<unistd.h>' */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1, 2)) char *__NOTHROW_NCX(__LIBCCALL getpass)(const char *__prompt, char *__str) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_conio_getpass))(__prompt, __str); }
#else /* __CRT_HAVE_getpass_r || __CRT_HAVE_getpassfd || __CRT_HAVE_read || __CRT_HAVE__read || __CRT_HAVE___read || __CRT_HAVE___libc_read || __CRT_HAVE_readpassphrase */
#undef __getpass_defined
#endif /* !__CRT_HAVE_getpass_r && !__CRT_HAVE_getpassfd && !__CRT_HAVE_read && !__CRT_HAVE__read && !__CRT_HAVE___read && !__CRT_HAVE___libc_read && !__CRT_HAVE_readpassphrase */
#endif /* !__CRT_HAVE__conio_getpass */
#endif /* !__getpass_defined */
#ifdef __CRT_HAVE_cputsxy
/* >> cputsxy(3)
 * Combination of `gotoxy(3)' and `cputs(3)' */
__CDECLARE_VOID(,__NOTHROW_NCX,cputsxy,(int __x, int __y, char __KOS_FIXED_CONST *__str),(__x,__y,__str))
#elif (defined(__CRT_HAVE_gotoxy) || defined(__CRT_HAVE__cprintf) || defined(__CRT_HAVE__vcprintf) || defined(__CRT_HAVE__vcprintf_l) || defined(__CRT_HAVE___conio_common_vcprintf) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))) && (defined(__CRT_HAVE__cputs) || (defined(__CRT_HAVE__putch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__putch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock))))
#include <libc/local/conio/cputsxy.h>
/* >> cputsxy(3)
 * Combination of `gotoxy(3)' and `cputs(3)' */
__NAMESPACE_LOCAL_USING_OR_IMPL(cputsxy, __FORCELOCAL __ATTR_ARTIFICIAL void __NOTHROW_NCX(__LIBCCALL cputsxy)(int __x, int __y, char __KOS_FIXED_CONST *__str) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(cputsxy))(__x, __y, __str); })
#endif /* ... */
#ifdef __CRT_HAVE_putchxy
/* >> putchxy(3)
 * Combination of `gotoxy(3)' and `putch(3)' */
__CDECLARE_VOID(,__NOTHROW_NCX,putchxy,(int __x, int __y, char __ch),(__x,__y,__ch))
#elif (defined(__CRT_HAVE_gotoxy) || defined(__CRT_HAVE__cprintf) || defined(__CRT_HAVE__vcprintf) || defined(__CRT_HAVE__vcprintf_l) || defined(__CRT_HAVE___conio_common_vcprintf) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))) && ((defined(__CRT_HAVE__putch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__putch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock))))
#include <libc/local/conio/putchxy.h>
/* >> putchxy(3)
 * Combination of `gotoxy(3)' and `putch(3)' */
__NAMESPACE_LOCAL_USING_OR_IMPL(putchxy, __FORCELOCAL __ATTR_ARTIFICIAL void __NOTHROW_NCX(__LIBCCALL putchxy)(int __x, int __y, char __ch) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(putchxy))(__x, __y, __ch); })
#endif /* ... */
#ifndef __delay_defined
#define __delay_defined
#ifdef __CRT_HAVE__sleep
/* >> _sleep(3)
 * Sleep for `milli' milliseconds (1/1.000 seconds) */
__CREDIRECT_VOID(,__NOTHROW_RPC,delay,(__UINT32_TYPE__ __milli),_sleep,(__milli))
#elif defined(__CRT_HAVE___crtSleep)
/* >> _sleep(3)
 * Sleep for `milli' milliseconds (1/1.000 seconds) */
__CREDIRECT_VOID(,__NOTHROW_RPC,delay,(__UINT32_TYPE__ __milli),__crtSleep,(__milli))
#elif defined(__CRT_HAVE_nanosleep64) || defined(__CRT_HAVE_nanosleep) || defined(__CRT_HAVE___nanosleep) || defined(__CRT_HAVE___libc_nanosleep)
#include <libc/local/stdlib/_sleep.h>
/* >> _sleep(3)
 * Sleep for `milli' milliseconds (1/1.000 seconds) */
__FORCELOCAL __ATTR_ARTIFICIAL void __NOTHROW_RPC(__LIBCCALL delay)(__UINT32_TYPE__ __milli) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sleep))(__milli); }
#else /* ... */
#undef __delay_defined
#endif /* !... */
#endif /* !__delay_defined */
#ifdef __CRT_HAVE_wherex
/* >> wherex(3)
 * Return the current cursor 'X' position (1-based) */
__CDECLARE(,int,__NOTHROW_NCX,wherex,(void),())
#else /* __CRT_HAVE_wherex */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if (defined(__KOS__) && defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl))) || (((defined(__CRT_HAVE__getch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getch_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetc_unlocked) || defined(__CRT_HAVE_getc_unlocked) || defined(__CRT_HAVE__getc_nolock) || defined(__CRT_HAVE__fgetc_nolock) || (defined(__CRT_HAVE_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE_fgetc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE__IO_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__filbuf) || defined(__CRT_HAVE___uflow) || defined(__CRT_HAVE___underflow))) || defined(__CRT_HAVE_fread) || defined(__CRT_HAVE__IO_fread) || defined(__CRT_HAVE_fread_unlocked) || defined(__CRT_HAVE__fread_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetc) || defined(__CRT_HAVE__IO_ungetc) || defined(__CRT_HAVE_ungetc_unlocked) || defined(__CRT_HAVE__ungetc_nolock)))) && (defined(__CRT_HAVE__cscanf) || defined(__CRT_HAVE__vcscanf) || defined(__CRT_HAVE__vcscanf_l) || defined(__CRT_HAVE___conio_common_vcscanf) || (((defined(__CRT_HAVE__getwche_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getwche) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getwche_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetwch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetwch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))))
#include <libc/local/conio/wherex.h>
/* >> wherex(3)
 * Return the current cursor 'X' position (1-based) */
__NAMESPACE_LOCAL_USING_OR_IMPL(wherex, __FORCELOCAL __ATTR_ARTIFICIAL int __NOTHROW_NCX(__LIBCCALL wherex)(void) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wherex))(); })
#endif /* (__KOS__ && __CRT_HAVE_stdtty && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl)) || (((__CRT_HAVE__getch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getch || (__CRT_HAVE_stdtty && (__CRT_HAVE__getch_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetc_unlocked || __CRT_HAVE_getc_unlocked || __CRT_HAVE__getc_nolock || __CRT_HAVE__fgetc_nolock || (__CRT_HAVE_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE_fgetc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE__IO_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_DOS && (__CRT_HAVE__filbuf || __CRT_HAVE___uflow || __CRT_HAVE___underflow)) || __CRT_HAVE_fread || __CRT_HAVE__IO_fread || __CRT_HAVE_fread_unlocked || __CRT_HAVE__fread_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetc || __CRT_HAVE__IO_ungetc || __CRT_HAVE_ungetc_unlocked || __CRT_HAVE__ungetc_nolock))) && (__CRT_HAVE__cscanf || __CRT_HAVE__vcscanf || __CRT_HAVE__vcscanf_l || __CRT_HAVE___conio_common_vcscanf || (((__CRT_HAVE__getwche_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getwche || (__CRT_HAVE_stdtty && (__CRT_HAVE__getwche_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked || __CRT_HAVE__getwc_nolock || __CRT_HAVE__fgetwc_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetwch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetwch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked)))))) */
#endif /* !__CRT_HAVE_wherex */
#ifdef __CRT_HAVE_wherey
/* >> wherey(3)
 * Return the current cursor 'Y' position (1-based) */
__CDECLARE(,int,__NOTHROW_NCX,wherey,(void),())
#else /* __CRT_HAVE_wherey */
#include <asm/os/termios.h>
#include <asm/os/tty.h>
#if (defined(__KOS__) && defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl))) || (((defined(__CRT_HAVE__getch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getch_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetc_unlocked) || defined(__CRT_HAVE_getc_unlocked) || defined(__CRT_HAVE__getc_nolock) || defined(__CRT_HAVE__fgetc_nolock) || (defined(__CRT_HAVE_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE_fgetc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_HAVE__IO_getc) && (!defined(__CRT_DOS) || !defined(__CRT_HAVE__filbuf))) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__filbuf) || defined(__CRT_HAVE___uflow) || defined(__CRT_HAVE___underflow))) || defined(__CRT_HAVE_fread) || defined(__CRT_HAVE__IO_fread) || defined(__CRT_HAVE_fread_unlocked) || defined(__CRT_HAVE__fread_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetc) || defined(__CRT_HAVE__IO_ungetc) || defined(__CRT_HAVE_ungetc_unlocked) || defined(__CRT_HAVE__ungetc_nolock)))) && (defined(__CRT_HAVE__cscanf) || defined(__CRT_HAVE__vcscanf) || defined(__CRT_HAVE__vcscanf_l) || defined(__CRT_HAVE___conio_common_vcscanf) || (((defined(__CRT_HAVE__getwche_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__getwche) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE__getwche_nolock) || (defined(__ECHO) && defined(__TCSANOW) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock)) && (defined(__CRT_HAVE_tcgetattr) || defined(__CRT_HAVE___tcgetattr) || ((defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)) && defined(__TCGETA))) && (defined(__CRT_HAVE_tcsetattr) || defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl)))))) && ((defined(__CRT_HAVE__ungetwch_nolock) && defined(__USE_STDIO_UNLOCKED)) || defined(__CRT_HAVE__ungetwch) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))))
#include <libc/local/conio/wherey.h>
/* >> wherey(3)
 * Return the current cursor 'Y' position (1-based) */
__NAMESPACE_LOCAL_USING_OR_IMPL(wherey, __FORCELOCAL __ATTR_ARTIFICIAL int __NOTHROW_NCX(__LIBCCALL wherey)(void) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wherey))(); })
#endif /* (__KOS__ && __CRT_HAVE_stdtty && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl)) || (((__CRT_HAVE__getch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getch || (__CRT_HAVE_stdtty && (__CRT_HAVE__getch_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetc_unlocked || __CRT_HAVE_getc_unlocked || __CRT_HAVE__getc_nolock || __CRT_HAVE__fgetc_nolock || (__CRT_HAVE_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE_fgetc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_HAVE__IO_getc && (!__CRT_DOS || !__CRT_HAVE__filbuf)) || (__CRT_DOS && (__CRT_HAVE__filbuf || __CRT_HAVE___uflow || __CRT_HAVE___underflow)) || __CRT_HAVE_fread || __CRT_HAVE__IO_fread || __CRT_HAVE_fread_unlocked || __CRT_HAVE__fread_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetc || __CRT_HAVE__IO_ungetc || __CRT_HAVE_ungetc_unlocked || __CRT_HAVE__ungetc_nolock))) && (__CRT_HAVE__cscanf || __CRT_HAVE__vcscanf || __CRT_HAVE__vcscanf_l || __CRT_HAVE___conio_common_vcscanf || (((__CRT_HAVE__getwche_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__getwche || (__CRT_HAVE_stdtty && (__CRT_HAVE__getwche_nolock || (__ECHO && __TCSANOW && (__CRT_HAVE_fileno || __CRT_HAVE__fileno || __CRT_HAVE_fileno_unlocked) && (__CRT_HAVE_fgetwc_unlocked || __CRT_HAVE_getwc_unlocked || __CRT_HAVE__getwc_nolock || __CRT_HAVE__fgetwc_nolock) && (__CRT_HAVE_tcgetattr || __CRT_HAVE___tcgetattr || ((__CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl) && __TCGETA)) && (__CRT_HAVE_tcsetattr || __CRT_HAVE_ioctl || __CRT_HAVE___ioctl || __CRT_HAVE___libc_ioctl))))) && ((__CRT_HAVE__ungetwch_nolock && __USE_STDIO_UNLOCKED) || __CRT_HAVE__ungetwch || (__CRT_HAVE_stdtty && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked)))))) */
#endif /* !__CRT_HAVE_wherey */
#ifdef __CRT_HAVE_window
/* >> window(3)
 * Set scroll range and margains to the specified rectangle (1-based) */
__CDECLARE_VOID(,__NOTHROW_NCX,window,(int __left, int __top, int __right, int __bottom),(__left,__top,__right,__bottom))
#elif defined(__CRT_HAVE__cprintf) || defined(__CRT_HAVE__vcprintf) || defined(__CRT_HAVE__vcprintf_l) || defined(__CRT_HAVE___conio_common_vcprintf) || (defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE___stdio_common_vfprintf) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)))
#include <libc/local/conio/window.h>
/* >> window(3)
 * Set scroll range and margains to the specified rectangle (1-based) */
__NAMESPACE_LOCAL_USING_OR_IMPL(window, __FORCELOCAL __ATTR_ARTIFICIAL void __NOTHROW_NCX(__LIBCCALL window)(int __left, int __top, int __right, int __bottom) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(window))(__left, __top, __right, __bottom); })
#endif /* ... */
#ifdef __CRT_HAVE_movetext
/* >> movetext(3)
 * Duplicate a  given rectangle  (1-based)  of on-screen  text  at
 * another location. Overlapping rectangles are handled correctly. */
__CDECLARE(,int,__NOTHROW_NCX,movetext,(int __left, int __top, int __right, int __bottom, int __destleft, int __desttop),(__left,__top,__right,__bottom,__destleft,__desttop))
#elif defined(__KOS__) && defined(__CRT_HAVE_stdtty) && (defined(__CRT_HAVE_fileno) || defined(__CRT_HAVE__fileno) || defined(__CRT_HAVE_fileno_unlocked)) && (defined(__CRT_HAVE_ioctl) || defined(__CRT_HAVE___ioctl) || defined(__CRT_HAVE___libc_ioctl))
#include <libc/local/conio/movetext.h>
/* >> movetext(3)
 * Duplicate a  given rectangle  (1-based)  of on-screen  text  at
 * another location. Overlapping rectangles are handled correctly. */
__NAMESPACE_LOCAL_USING_OR_IMPL(movetext, __FORCELOCAL __ATTR_ARTIFICIAL int __NOTHROW_NCX(__LIBCCALL movetext)(int __left, int __top, int __right, int __bottom, int __destleft, int __desttop) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(movetext))(__left, __top, __right, __bottom, __destleft, __desttop); })
#endif /* ... */

__SYSDECL_END
#endif /* __CC__ */

#endif /* !_CONIO_H */
