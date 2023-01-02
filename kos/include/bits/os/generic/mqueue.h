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
#ifndef _BITS_OS_GENERIC_MQUEUE_H
#define _BITS_OS_GENERIC_MQUEUE_H 1

#include <__stdinc.h>

#include <bits/types.h>


#ifdef __CC__
__SYSDECL_BEGIN

typedef __fd_t __mqd_t;

struct mq_attr {
	__syscall_slong_t mq_flags;   /* ... */
	__syscall_slong_t mq_maxmsg;  /* ... */
	__syscall_slong_t mq_msgsize; /* ... */
	__syscall_slong_t mq_curmsgs; /* ... */
	__syscall_slong_t __pad[4];   /* ... */
};

__SYSDECL_END
#endif /* __CC__ */


#endif /* !_BITS_OS_GENERIC_MQUEUE_H */
