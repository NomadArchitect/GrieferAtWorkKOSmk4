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
#ifndef _I386_KOS_ASM_DEFSYM_H
#define _I386_KOS_ASM_DEFSYM_H 1

#include <__stdinc.h>

/* Helper macros to define linker symbols from C expressions. */
#ifdef __CC__
#define __PRIVATE_DEFINE_SYMBOL_COMMON(name, value, size, ...) \
	__asm__(".type " #name ", \"object\"\n\t"                  \
	        __VA_ARGS__                                        \
	        ".set " #name ",%p0\n\t"                           \
	        ".size " #name ",%p1"                              \
	        :                                                  \
	        : "X" (value)                                      \
	        , "X" (size))
#include "../../asm/defsym.h"
#endif /* __CC__ */

#endif /* !_I386_KOS_ASM_DEFSYM_H */