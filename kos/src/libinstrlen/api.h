/* Copyright (c) 2019-2023 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2023 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef GUARD_LIBINSTRLEN_API_H
#define GUARD_LIBINSTRLEN_API_H 1

#include <hybrid/compiler.h>

#include <hybrid/host.h>

#include <kos/config/config.h> /* Pull in config-specific macro overrides */

#include <libinstrlen/api.h>

#define CC LIBINSTRLEN_CC


/* #define ARCH_HAVE_INSTRUCTION_LENGTH 1 */
/* #define ARCH_HAVE_INSTRUCTION_SUCC 1 */
/* #define ARCH_HAVE_INSTRUCTION_PRED 1 */
/* #define ARCH_HAVE_INSTRUCTION_SUCC_NX 1 */
/* #define ARCH_HAVE_INSTRUCTION_PRED_NX 1 */
/* #define ARCH_HAVE_INSTRUCTION_TRYSUCC 1 */
/* #define ARCH_HAVE_INSTRUCTION_TRYPRED 1 */

#if defined(__i386__) || defined(__x86_64__)
#include "arch/i386/config.h"
#elif defined(__arm__)
#include "arch/arm/config.h"
#endif /* ... */

#endif /* !GUARD_LIBINSTRLEN_API_H */
