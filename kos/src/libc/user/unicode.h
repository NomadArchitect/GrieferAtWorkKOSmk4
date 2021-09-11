/* HASH CRC-32:0x36371426 */
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
#ifndef GUARD_LIBC_USER_UNICODE_H
#define GUARD_LIBC_USER_UNICODE_H 1

#include "../api.h"
#include "../auto/unicode.h"

#include <hybrid/typecore.h>
#include <kos/types.h>
#include <unicode.h>

DECL_BEGIN

#ifndef __KERNEL__
/* Return the internal descriptor for the given `ch' */
INTDEF ATTR_CONST ATTR_RETNONNULL struct __unitraits const *NOTHROW(LIBCCALL libc___unicode_descriptor)(char32_t ch);
/* Return the integer constant associated with a given digit index
 * Returns `0' if the given index is invalid
 * @param: digit_idx: As read from `__unitraits::__ut_digit_idx' */
INTDEF ATTR_CONST uint8_t NOTHROW(LIBCCALL libc___unicode_descriptor_digit)(uint8_t digit_idx);
/* Return the integer constant associated with a given digit index
 * Returns `0' if the given index is invalid
 * @param: digit_idx: As read from `__unitraits::__ut_digit_idx' */
INTDEF ATTR_CONST uint64_t NOTHROW(LIBCCALL libc___unicode_descriptor_digit64)(uint8_t digit_idx);
/* Return the floating-point constant associated with a given digit index
 * Returns `0.0' if the given index is invalid
 * @param: digit_idx: As read from `__unitraits::__ut_digit_idx' */
INTDEF ATTR_CONST double NOTHROW(LIBCCALL libc___unicode_descriptor_digitd)(uint8_t digit_idx);
/* Return the floating-point constant associated with a given digit index
 * Returns `0.0' if the given index is invalid
 * @param: digit_idx: As read from `__unitraits::__ut_digit_idx' */
INTDEF ATTR_CONST __LONGDOUBLE NOTHROW(LIBCCALL libc___unicode_descriptor_digitld)(uint8_t digit_idx);
/* Fold the given unicode character `ch' */
INTDEF ATTR_RETNONNULL NONNULL((2)) char32_t *NOTHROW_NCX(LIBCCALL libc_unicode_fold)(char32_t ch, char32_t buf[3]);
#endif /* !__KERNEL__ */

DECL_END

#endif /* !GUARD_LIBC_USER_UNICODE_H */
