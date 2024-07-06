/* Copyright (c) 2019-2024 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2024 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef _KOS_BITS_EXCEPT_REGISTER_STATE_H
#define _KOS_BITS_EXCEPT_REGISTER_STATE_H 1

#include <kos/bits/except.h> /* __EXCEPT_REGISTER_STATE_TYPE */

#ifndef __EXCEPT_REGISTER_STATE_TYPE
#include <bits/os/mcontext.h>
#define __EXCEPT_REGISTER_STATE_TYPE   struct mcontext
#define __SIZEOF_EXCEPT_REGISTER_STATE __SIZEOF_MCONTEXT
#define __EXCEPT_REGISTER_STATE_TYPE_IS_MCONTEXT
#endif /* !__EXCEPT_REGISTER_STATE_TYPE */

#endif /* !_KOS_BITS_EXCEPT_REGISTER_STATE_H */