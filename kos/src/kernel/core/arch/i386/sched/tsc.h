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
#ifndef GUARD_KERNEL_CORE_ARCH_I386_SCHED_TSC_H
#define GUARD_KERNEL_CORE_ARCH_I386_SCHED_TSC_H 1

#include <kernel/compiler.h>

/*[[[config CONFIG_HAVE_KERNEL_X86_TSC_ASSERT_FORWARD: bool = !defined(NDEBUG)
 * Enable some sanity checks to assert that `tsc_get()' never runs backwards.
 * ]]]*/
#ifdef CONFIG_NO_KERNEL_X86_TSC_ASSERT_FORWARD
#undef CONFIG_HAVE_KERNEL_X86_TSC_ASSERT_FORWARD
#elif !defined(CONFIG_HAVE_KERNEL_X86_TSC_ASSERT_FORWARD)
#ifndef NDEBUG
#define CONFIG_HAVE_KERNEL_X86_TSC_ASSERT_FORWARD
#else /* !NDEBUG */
#define CONFIG_NO_KERNEL_X86_TSC_ASSERT_FORWARD
#endif /* NDEBUG */
#elif (-CONFIG_HAVE_KERNEL_X86_TSC_ASSERT_FORWARD - 1) == -1
#undef CONFIG_HAVE_KERNEL_X86_TSC_ASSERT_FORWARD
#define CONFIG_NO_KERNEL_X86_TSC_ASSERT_FORWARD
#endif /* ... */
/*[[[end]]]*/

#endif /* !GUARD_KERNEL_CORE_ARCH_I386_SCHED_TSC_H */
