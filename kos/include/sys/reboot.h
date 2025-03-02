/* HASH CRC-32:0xce1b976d */
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
/* (#) Portability: DragonFly BSD (/sys/sys/reboot.h) */
/* (#) Portability: FreeBSD       (/sys/sys/reboot.h) */
/* (#) Portability: GNU C Library (/sysdeps/unix/sysv/linux/sys/reboot.h) */
/* (#) Portability: NetBSD        (/sys/sys/reboot.h) */
/* (#) Portability: OpenBSD       (/sys/sys/reboot.h) */
/* (#) Portability: OpenSolaris   (/usr/src/uts/common/sys/reboot.h) */
/* (#) Portability: diet libc     (/include/sys/reboot.h) */
/* (#) Portability: mintlib       (/include/sys/reboot.h) */
/* (#) Portability: musl libc     (/include/sys/reboot.h) */
/* (#) Portability: uClibc        (/include/sys/reboot.h) */
#ifndef _SYS_REBOOT_H
#define _SYS_REBOOT_H 1

#include <__stdinc.h>
#include <__crt.h>

#ifdef __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER
#pragma GCC system_header
#endif /* __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER */

#include <features.h>
#include <asm/os/reboot.h>


/* Linux compatibility header */
#ifdef __RB_AUTOBOOT
#define RB_AUTOBOOT __RB_AUTOBOOT /* Do a hard reset immediately. */
#endif /* __RB_AUTOBOOT */
#ifdef __RB_HALT_SYSTEM
#define RB_HALT_SYSTEM __RB_HALT_SYSTEM /* Halt the system. */
#endif /* __RB_HALT_SYSTEM */
#ifdef __RB_ENABLE_CAD
#define RB_ENABLE_CAD __RB_ENABLE_CAD /* Enable reboot with Ctrl-Alt-Delete. */
#endif /* __RB_ENABLE_CAD */
#ifdef __RB_DISABLE_CAD
#define RB_DISABLE_CAD __RB_DISABLE_CAD /* Disable reboot with Ctrl-Alt-Delete. */
#endif /* __RB_DISABLE_CAD */
#ifdef __RB_POWER_OFF
#define RB_POWER_OFF __RB_POWER_OFF /* halt and switch off power (if possible). */
#endif /* __RB_POWER_OFF */
#ifdef __RB_SW_SUSPEND
#define RB_SW_SUSPEND __RB_SW_SUSPEND /* Suspend the system using a software suspend. */
#endif /* __RB_SW_SUSPEND */
#ifdef __RB_KEXEC
#define RB_KEXEC __RB_KEXEC /* Reboot into new kernel (not supported currently). */
#endif /* __RB_KEXEC */

#ifdef __CC__
__SYSDECL_BEGIN

#ifdef __CRT_HAVE_reboot
/* Reboot or halt the system
 * @param: howto: One of the `RB_*' constants above */
__CDECLARE(,int,__NOTHROW_NCX,reboot,(__STDC_INT_AS_UINT_T __howto),(__howto))
#elif defined(__CRT_HAVE___reboot)
/* Reboot or halt the system
 * @param: howto: One of the `RB_*' constants above */
__CREDIRECT(,int,__NOTHROW_NCX,reboot,(__STDC_INT_AS_UINT_T __howto),__reboot,(__howto))
#elif defined(__CRT_HAVE___libc_reboot)
/* Reboot or halt the system
 * @param: howto: One of the `RB_*' constants above */
__CREDIRECT(,int,__NOTHROW_NCX,reboot,(__STDC_INT_AS_UINT_T __howto),__libc_reboot,(__howto))
#endif /* ... */

__SYSDECL_END
#endif /* __CC__ */

#endif /* !_SYS_REBOOT_H */
