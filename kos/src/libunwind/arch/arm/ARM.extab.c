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
#ifndef GUARD_LIBUNWIND_ARCH_ARM_ARM_EXTAB_C
#define GUARD_LIBUNWIND_ARCH_ARM_ARM_EXTAB_C 1

/* Exception ABI functions exported by libc.so */
#define __CRT_HAVE__Unwind_RaiseException
#define __CRT_HAVE__Unwind_Resume
#define __CRT_HAVE__Unwind_Resume_or_Rethrow
#define __CRT_HAVE__Unwind_DeleteException
#define __CRT_HAVE__Unwind_GetGR
#define __CRT_HAVE__Unwind_SetGR
#define __CRT_HAVE__Unwind_GetIP
#define __CRT_HAVE__Unwind_SetIP
#define __CRT_HAVE__Unwind_GetLanguageSpecificData
#define __CRT_HAVE__Unwind_GetRegionStart
#define __CRT_HAVE__Unwind_GetIPInfo
#define __CRT_HAVE__Unwind_ForcedUnwind
#define __CRT_HAVE__Unwind_Backtrace
#define __CRT_HAVE__Unwind_GetCFA
#define __CRT_HAVE__Unwind_GetDataRelBase
#define __CRT_HAVE__Unwind_GetTextRelBase
#define __CRT_HAVE__Unwind_FindEnclosingFunction
#define __CRT_HAVE__Unwind_VRS_Set
#define __CRT_HAVE__Unwind_VRS_Get
#define __CRT_HAVE__Unwind_VRS_Pop
#define __CRT_HAVE__Unwind_Complete
#define __CRT_HAVE___gnu_unwind_frame
#define __CRT_HAVE___gnu_unwind_execute

#include "../../api.h"
/**/

#include <hybrid/compiler.h>

#include <hybrid/align.h>

#include <assert.h>
#include <stddef.h>

#include <libunwind/except.h>
#include <libunwind/ARM.extab.h>

#include "ARM.extab.h"

DECL_BEGIN

/* Locate the entry corresponding to a given `absolute_pc' within a given `.ARM.exidx' section.
 * @return: * :   Address of `.ARM.exidx' entry corresponding to `absolute_pc'
 * @return: NULL: No unwind entry associated with `absolute_pc' */
INTERN ATTR_PURE WUNUSED NONNULL((1, 2)) struct ARM_exidx_entry const *
NOTHROW_NCX(CC libuw_unwind_ARM_exidx_locate)(byte_t const *ARM_exidx_start,
                                              byte_t const *ARM_exidx_end,
                                              void const *absolute_pc) {
	struct ARM_exidx_entry const *start;
	struct ARM_exidx_entry const *end;
	void const *ent_fbase;
	/* Do a binary search on the table. -- We're allowed to assume that it's sorted. */
	start = (struct ARM_exidx_entry *)ARM_exidx_start;
	end   = (struct ARM_exidx_entry *)ARM_exidx_end;
	while (start < end) {
		struct ARM_exidx_entry const *mid;
		mid       = start + ((size_t)(end - start) / 2);
		ent_fbase = ARM_prel31_decode(&mid->aeie_fbase_prel31);
		if (absolute_pc < ent_fbase) {
			end = mid;
		} else {
			start = mid + 1;
		}
	}
	assert(start == end);
	ent_fbase = ARM_prel31_decode(&start->aeie_fbase_prel31);
	if likely(absolute_pc >= ent_fbase) {
		/* WARNING: We also get here when `absolute_pc > END_OF(((struct ARM_exidx_entry *)ARM_exidx_end)[-1])',
		 *          in which case we have to assume that  `absolute_pc' belongs to the last entry in the  table,
		 *          simply  because we don't actually know where said entry ends, meaning we have to assume that
		 *          it spans into infinity */
		return start;
	}
	/* The case where `absolute_pc' lies before `START_OF(*(struct ARM_exidx_entry *)ARM_exidx_start)'
	 * allows us to simply return  NULL, as we know that  `absolute_pc' doesn't exist anywhere in  the
	 * given table. */
	return NULL;
}


/* ABI runtime support unwind functions.
 *
 * Specs require programs that index these functions in `ARM_extab_entry::aete_perso_prel31'
 * to produce `R_ARM_NONE' relocations against them (even though these relocations don't end
 * up  being acted upon by the RTLD). However, since they're referenced, they have to appear
 * as publicly visible, and must therefor be apart of the public interface.
 *
 * For the sake of simplicity, these functions are implemented by libunwind, however  libc
 * also exports them via IFUNC aliases which in turn will lazily load and link against our
 * library ("libunwind.so"). */
INTERN NONNULL((2, 3)) _Unwind_Reason_Code
NOTHROW_NCX(__LIBKCALL libuw___aeabi_unwind_cpp_pr0)(_Unwind_State state, _Unwind_Control_Block *ucbp,
                                                     _Unwind_Context *context) {
	return libuw___aeabi_unwind_cpp_prN(state, ucbp, context, 0);
}

INTERN NONNULL((2, 3)) _Unwind_Reason_Code
NOTHROW_NCX(__LIBKCALL libuw___aeabi_unwind_cpp_pr1)(_Unwind_State state, _Unwind_Control_Block *ucbp,
                                                     _Unwind_Context *context) {
	return libuw___aeabi_unwind_cpp_prN(state, ucbp, context, 1);
}

INTERN NONNULL((2, 3)) _Unwind_Reason_Code
NOTHROW_NCX(__LIBKCALL libuw___aeabi_unwind_cpp_pr2)(_Unwind_State state, _Unwind_Control_Block *ucbp,
                                                     _Unwind_Context *context) {
	return libuw___aeabi_unwind_cpp_prN(state, ucbp, context, 2);
}

INTERN NONNULL((2, 3)) _Unwind_Reason_Code
NOTHROW_NCX(__LIBKCALL libuw___aeabi_unwind_cpp_prN)(_Unwind_State state, _Unwind_Control_Block *ucbp,
                                                     _Unwind_Context *context, unsigned int n) {
	/* TODO */
	return _URC_FAILURE;
}




DEFINE_PUBLIC_ALIAS(unwind_ARM_exidx_locate, libuw_unwind_ARM_exidx_locate);
DEFINE_PUBLIC_ALIAS(__aeabi_unwind_cpp_pr0, libuw___aeabi_unwind_cpp_pr0);
DEFINE_PUBLIC_ALIAS(__aeabi_unwind_cpp_pr1, libuw___aeabi_unwind_cpp_pr1);
DEFINE_PUBLIC_ALIAS(__aeabi_unwind_cpp_pr2, libuw___aeabi_unwind_cpp_pr2);
DEFINE_PUBLIC_ALIAS(__aeabi_unwind_cpp_prN, libuw___aeabi_unwind_cpp_prN);

DECL_END

#endif /* !GUARD_LIBUNWIND_ARCH_ARM_ARM_EXTAB_C */
