/* HASH CRC-32:0xf26bcbdb */
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
#ifndef __local_Nice_defined
#define __local_Nice_defined
#include <__crt.h>
#include <kos/anno.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(Nice) int
(__LIBCCALL __LIBC_LOCAL_NAME(Nice))(int __inc) __THROWS(...) {
	(void)__inc;
	/* It should be sufficient to emulate this is a no-op. */
	return 0;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_Nice_defined
#define __local___localdep_Nice_defined
#define __localdep_Nice __LIBC_LOCAL_NAME(Nice)
#endif /* !__local___localdep_Nice_defined */
#endif /* !__local_Nice_defined */
