/* Copyright (c) 2019 Griefer@Work                                            *
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
 *    in a product, an acknowledgement in the product documentation would be  *
 *    appreciated but is not required.                                        *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef GUARD_MODPROCFS_FILES_CMDLINE_C
#define GUARD_MODPROCFS_FILES_CMDLINE_C 1
#define _KOS_SOURCE 1 /* snprintf returns size_t */

#include <kernel/compiler.h>
#include <kernel/driver.h>
#include <string.h>
#include <libcmdline/encode.h>

#include "../procfs.h"

DECL_BEGIN

INTERN NONNULL((1, 2)) ssize_t KCALL
ProcFS_Cmdline_Printer(struct inode *__restrict UNUSED(self),
                       pformatprinter printer, void *arg) {
	cmdline_encode(printer,
	               arg,
	               kernel_driver.d_argc,
	               kernel_driver.d_argv);
	return (*printer)(arg, "\n", 1);
}

DECL_END

#endif /* !GUARD_MODPROCFS_FILES_CMDLINE_C */
