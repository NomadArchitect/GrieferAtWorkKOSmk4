/* HASH CRC-32:0xd2c6807b */
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
#ifndef __local_rtm_abort_defined
#define __local_rtm_abort_defined
#include <__crt.h>
#include <kos/bits/rtm.h>
#ifdef __arch_rtm_abort
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(rtm_abort) void
__NOTHROW(__FCALL __LIBC_LOCAL_NAME(rtm_abort))(unsigned int __code) {
	__arch_rtm_abort(__code);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_rtm_abort_defined
#define __local___localdep_rtm_abort_defined
#define __localdep_rtm_abort __LIBC_LOCAL_NAME(rtm_abort)
#endif /* !__local___localdep_rtm_abort_defined */
#else /* __arch_rtm_abort */
#undef __local_rtm_abort_defined
#endif /* !__arch_rtm_abort */
#endif /* !__local_rtm_abort_defined */
