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
/* (#) Portability: NetBSD (/sys/sys/common_int_const.h) */
#ifndef _SYS_COMMON_INT_CONST_H
#define _SYS_COMMON_INT_CONST_H 1

#include <__stdinc.h>

#include <hybrid/typecore.h>

#ifdef __PREPROCESSOR_HAVE_CAT
#define __int_join_(c, suffix) c##suffix
#else /* __PREPROCESSOR_HAVE_CAT */
#define __int_join_(c, suffix) c/**/suffix
#endif /* !__PREPROCESSOR_HAVE_CAT */
#define __int_join(c, suffix)  __int_join_(c, suffix)

/* From <hybrid/typecore.h>:
 * >> #define __INT8_C_SUFFIX__    ...
 * >> #define __INT16_C_SUFFIX__   ...
 * >> #define __INT32_C_SUFFIX__   ...
 * >> #define __INT64_C_SUFFIX__   ...
 * >> #define __UINT8_C_SUFFIX__   ...
 * >> #define __UINT16_C_SUFFIX__  ...
 * >> #define __UINT32_C_SUFFIX__  ...
 * >> #define __UINT64_C_SUFFIX__  ...
 * >> #define __INTMAX_C_SUFFIX__  ...
 * >> #define __UINTMAX_C_SUFFIX__ ...
 */

#ifndef INTMAX_C
#define INTMAX_C  __INTMAX_C
#endif /* !INTMAX_C */
#ifndef UINTMAX_C
#define UINTMAX_C __UINTMAX_C
#endif /* !UINTMAX_C */
#ifndef INT8_C
#define INT8_C    __INT8_C
#endif /* !INT8_C */
#ifndef INT16_C
#define INT16_C   __INT16_C
#endif /* !INT16_C */
#ifndef INT32_C
#define INT32_C   __INT32_C
#endif /* !INT32_C */
#ifndef INT64_C
#define INT64_C   __INT64_C
#endif /* !INT64_C */
#ifndef UINT8_C
#define UINT8_C   __UINT8_C
#endif /* !UINT8_C */
#ifndef UINT16_C
#define UINT16_C  __UINT16_C
#endif /* !UINT16_C */
#ifndef UINT32_C
#define UINT32_C  __UINT32_C
#endif /* !UINT32_C */
#ifndef UINT64_C
#define UINT64_C  __UINT64_C
#endif /* !UINT64_C */

#endif /* !_SYS_COMMON_INT_CONST_H */
