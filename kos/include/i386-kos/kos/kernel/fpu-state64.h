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
#ifndef _I386_KOS_KOS_KERNEL_FPU_STATE64_H
#define _I386_KOS_KOS_KERNEL_FPU_STATE64_H 1

#include <__stdinc.h>

#include <bits/types.h>

#include <ieee754.h>

#include "fpu-sstate.h"

__SYSDECL_BEGIN

#ifdef __x86_64__
#define OFFSET_XFPUSTATE_FCW        OFFSET_XFPUSTATE64_FCW
#define OFFSET_XFPUSTATE_FSW        OFFSET_XFPUSTATE64_FSW
#define OFFSET_XFPUSTATE_FTW        OFFSET_XFPUSTATE64_FTW
#define OFFSET_XFPUSTATE_FOP        OFFSET_XFPUSTATE64_FOP
#define OFFSET_XFPUSTATE_FPUIP      OFFSET_XFPUSTATE64_FPUIP
#define OFFSET_XFPUSTATE_FPUDP      OFFSET_XFPUSTATE64_FPUDP
#define OFFSET_XFPUSTATE_MXCSR      OFFSET_XFPUSTATE64_MXCSR
#define OFFSET_XFPUSTATE_MXCSR_MASK OFFSET_XFPUSTATE64_MXCSR_MASK
#define OFFSET_XFPUSTATE_ST         OFFSET_XFPUSTATE64_ST
#define OFFSET_XFPUSTATE_MM         OFFSET_XFPUSTATE64_MM
#define OFFSET_XFPUSTATE_XMM        OFFSET_XFPUSTATE64_XMM
#define SIZEOF_XFPUSTATE            SIZEOF_XFPUSTATE64
#define ALIGNOF_XFPUSTATE           ALIGNOF_XFPUSTATE64
#define xfpustate64                 xfpustate

#define SIZEOF_FPUSTATE    SIZEOF_FPUSTATE64
#define ALIGNOF_FPUSTATE   ALIGNOF_FPUSTATE64
#define fpustate64         fpustate
#endif /* __x86_64__ */

#define OFFSET_XFPUSTATE64_FCW        0
#define OFFSET_XFPUSTATE64_FSW        2
#define OFFSET_XFPUSTATE64_FTW        4
#define OFFSET_XFPUSTATE64_FOP        6
#define OFFSET_XFPUSTATE64_FPUIP      8
#define OFFSET_XFPUSTATE64_FPUDP      16
#define OFFSET_XFPUSTATE64_MXCSR      24
#define OFFSET_XFPUSTATE64_MXCSR_MASK 28
#define OFFSET_XFPUSTATE64_ST(i)     (32 + (i) * 16)
#define OFFSET_XFPUSTATE64_MM(i)     (32 + (i) * 16)
#define OFFSET_XFPUSTATE64_XMM(i)    (160 + (i) * 16)
#define SIZEOF_XFPUSTATE64            512
#define ALIGNOF_XFPUSTATE64           16
#ifdef __CC__
#undef fs_fcw
#undef fs_fsw
#undef fs_ftw
#undef fs_fop
#undef fs_fpuip
#undef fs_fpucs
#undef fs_fpudp
#undef fs_fpuds
struct __ATTR_ALIGNED(ALIGNOF_XFPUSTATE64) __ATTR_PACKED xfpustate64 /*[PREFIX(fs_)]*/ {
	/* FPU context structure, as described here:
	 *   - http://asm.inightmare.org/opcodelst/index.php?op=FXSAVE
	 *   - http://x86.renejeschke.de/html/file_module_x86_id_128.html */
#ifndef __COMPILER_HAVE_TRANSPARENT_UNION
	union __ATTR_PACKED {
#endif /* !__COMPILER_HAVE_TRANSPARENT_UNION */
#ifndef __COMPILER_HAVE_TRANSPARENT_STRUCT
	struct __ATTR_PACKED {
#endif /* !__COMPILER_HAVE_TRANSPARENT_STRUCT */
	__u16                     fs_fcw;        /* Floating point control word. (Set of `FCW_*') */
	__u16                     fs_fsw;        /* Floating point status word. (Set of `FSW_*') */
	__u8                      fs_ftw;        /* Compressed floating point tag word. (0 << i: FTW_EMPTY(i), 1 << i: FTW_(VALID|ZERO|SPEC)(i) (based on actually loaded value)) */
	__u8                    __fs_pad1;       /* ... */
	__u16                     fs_fop;        /* Lower 11-bit f.p. opcode. */
	__u64                     fs_fpuip;      /* FPU instruction pointer. */
	__u64                     fs_fpudp;      /* FPU data pointer. */
#ifndef __COMPILER_HAVE_TRANSPARENT_STRUCT
	} _fs_env_struct;
#endif /* !__COMPILER_HAVE_TRANSPARENT_STRUCT */
#ifndef __COMPILER_HAVE_TRANSPARENT_UNION
	} _fs_env_union;
#endif /* !__COMPILER_HAVE_TRANSPARENT_UNION */
	__u32                     fs_mxcsr;      /* MXCSR (SSE only) (Set of `MXCSR_') */
	__u32                     fs_mxcsr_mask; /* MXCSR mask (SSE only) (Set of `MXCSR_', used to identify available features -- 11.6.6) */
	union ieee854_long_double fs_regs[8];    /* ST(i) / MMi */
	union ieee854_long_double fs_xmm[16];    /* XMMi */
	__u8                    __fs_pad4[96];
};

#if !defined(__COMPILER_HAVE_TRANSPARENT_STRUCT) && !defined(__COMPILER_HAVE_TRANSPARENT_UNION)
#define fs_fcw        _fs_env_union._fs_env_struct.fs_fcw
#define fs_fsw        _fs_env_union._fs_env_struct.fs_fsw
#define fs_ftw        _fs_env_union._fs_env_struct.fs_ftw
#define fs_fop        _fs_env_union._fs_env_struct.fs_fop
#define fs_fpuip      _fs_env_union._fs_env_struct.fs_fpuip
#define fs_fpucs      _fs_env_union._fs_env_struct.fs_fpucs
#define fs_fpudp      _fs_env_union._fs_env_struct.fs_fpudp
#define fs_fpuds      _fs_env_union._fs_env_struct.fs_fpuds
#elif !defined(__COMPILER_HAVE_TRANSPARENT_UNION)
#define fs_fcw        _fs_env_union.fs_fcw
#define fs_fsw        _fs_env_union.fs_fsw
#define fs_ftw        _fs_env_union.fs_ftw
#define fs_fop        _fs_env_union.fs_fop
#define fs_fpuip      _fs_env_union.fs_fpuip
#define fs_fpucs      _fs_env_union.fs_fpucs
#define fs_fpudp      _fs_env_union.fs_fpudp
#define fs_fpuds      _fs_env_union.fs_fpuds
#elif !defined(__COMPILER_HAVE_TRANSPARENT_STRUCT)
#define fs_fcw        _fs_env_struct.fs_fcw
#define fs_fsw        _fs_env_struct.fs_fsw
#define fs_ftw        _fs_env_struct.fs_ftw
#define fs_fop        _fs_env_struct.fs_fop
#define fs_fpuip      _fs_env_struct.fs_fpuip
#define fs_fpucs      _fs_env_struct.fs_fpucs
#define fs_fpudp      _fs_env_struct.fs_fpudp
#define fs_fpuds      _fs_env_struct.fs_fpuds
#endif

#endif /* __CC__ */


#define SIZEOF_FPUSTATE64   512
#define ALIGNOF_FPUSTATE64  16
#ifdef __CC__
#undef f_ssave
#undef f_xsave
struct __ATTR_ALIGNED(ALIGNOF_FPUSTATE64) __ATTR_PACKED fpustate64 /*[PREFIX(f_)]*/ {
	union __ATTR_PACKED {
		struct sfpustate   f_ssave; /* State saved by `fsave' / `fnsave' */
		struct xfpustate64 f_xsave; /* State saved by `fxsave' */
	}
#ifndef __COMPILER_HAVE_TRANSPARENT_UNION
	_f_kind
#define f_ssave _f_kind.f_ssave
#define f_xsave _f_kind.f_xsave
#endif /* !__COMPILER_HAVE_TRANSPARENT_UNION */
	;
};
#endif /* __CC__ */

__SYSDECL_END

#endif /* !_I386_KOS_KOS_KERNEL_FPU_STATE64_H */
