/* HASH CRC-32:0xac3a8238 */
/* Copyright (c) 2019-2020 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2020 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_FDataSync_defined
#define __local_FDataSync_defined 1
#include <__crt.h>
#include <kos/anno.h>
__NAMESPACE_LOCAL_BEGIN
/* >> fdatasync(2)
 * Synchronize only the data of a file (not its descriptor which contains
 * timestamps, and its size), meaning that changes are written to disk */
__LOCAL_LIBC(FDataSync) void
(__LIBCCALL __LIBC_LOCAL_NAME(FDataSync))(__fd_t __fd) __THROWS(...) {
	(void)__fd;
	/* No-Op */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_FDataSync_defined
#define __local___localdep_FDataSync_defined 1
#define __localdep_FDataSync __LIBC_LOCAL_NAME(FDataSync)
#endif /* !__local___localdep_FDataSync_defined */
#endif /* !__local_FDataSync_defined */
