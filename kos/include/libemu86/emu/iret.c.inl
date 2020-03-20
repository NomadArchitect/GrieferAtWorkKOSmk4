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
#ifdef __INTELLISENSE__
#include "../emulate.c.inl"
#endif /* __INTELLISENSE__ */

EMU86_INTELLISENSE_BEGIN(iret) {

#if CONFIG_LIBEMU86_WANT_32BIT && CONFIG_LIBEMU86_WANT_16BIT
#ifndef EMU86_SETCS_VM86
#define EMU86_SETCS_VM86 EMU86_SETCS
#endif /* !EMU86_SETCS_VM86 */
#ifndef EMU86_SETEIP_VM86
#define EMU86_SETEIP_VM86 EMU86_EMULATE_SETIP
#endif /* !EMU86_SETEIP_VM86 */
#ifndef EMU86_SETESP_VM86
#define EMU86_SETESP_VM86 EMU86_SETESP
#endif /* !EMU86_SETESP_VM86 */
#ifndef EMU86_SETSS_VM86
#define EMU86_SETSS_VM86 EMU86_SETSS
#endif /* !EMU86_SETSS_VM86 */
#ifndef EMU86_SETES_VM86
#define EMU86_SETES_VM86 EMU86_SETES
#endif /* !EMU86_SETES_VM86 */
#ifndef EMU86_SETDS_VM86
#define EMU86_SETDS_VM86 EMU86_SETDS
#endif /* !EMU86_SETDS_VM86 */
#ifndef EMU86_SETFS_VM86
#define EMU86_SETFS_VM86 EMU86_SETFS
#endif /* !EMU86_SETFS_VM86 */
#ifndef EMU86_SETGS_VM86
#define EMU86_SETGS_VM86 EMU86_SETGS
#endif /* !EMU86_SETGS_VM86 */
#endif /* CONFIG_LIBEMU86_WANT_32BIT && CONFIG_LIBEMU86_WANT_16BIT */

#if CONFIG_LIBEMU86_WANT_64BIT
#define REG_UTYPE u64
#define REG_STYPE s64
#else /* CONFIG_LIBEMU86_WANT_64BIT */
#define REG_UTYPE u32
#define REG_STYPE s32
#endif /* !CONFIG_LIBEMU86_WANT_64BIT */


case 0xcf: {
	/* CF     IRET     ZO     Valid     Valid     Interrupt return (16-bit operand size).
	 * CF     IRETD    ZO     Valid     Valid     Interrupt return (32-bit operand size).
	 * CF     IRETQ    ZO     Valid     Valid     Interrupt return (64-bit operand size). */
	byte_t *sp = (byte_t *)EMU86_GETSP();
	REG_UTYPE new_ip;
	u16 new_cs;
	u32 new_eflags;
	IF_64BIT(if (IS_64BIT()) {
		EMU86_EMULATE_POP(sp, 40);
		EMU86_READ_USER_MEMORY(sp, 40);
		new_ip     = EMU86_EMULATE_READQ(sp + 0);
		new_cs     = EMU86_EMULATE_READQASW(sp + 8);
		new_eflags = EMU86_EMULATE_READQASL(sp + 16);
		sp += 24;
	} else) if (!IS_16BIT()) {
		EMU86_EMULATE_POP(sp, 12);
		EMU86_READ_USER_MEMORY(sp, 12);
		new_ip     = EMU86_EMULATE_READL(sp + 0);
		new_cs     = EMU86_EMULATE_READLASW(sp + 4);
		new_eflags = EMU86_EMULATE_READL(sp + 8);
		sp += 12;
	} else {
		EMU86_EMULATE_POP(sp, 6);
		EMU86_READ_USER_MEMORY(sp, 6);
		new_ip     = EMU86_EMULATE_READW(sp + 0);
		new_cs     = EMU86_EMULATE_READW(sp + 2);
		new_eflags = EMU86_EMULATE_READW(sp + 4);
		sp += 6;
	}
#if CONFIG_LIBEMU86_WANT_32BIT && CONFIG_LIBEMU86_WANT_16BIT
	if (!EMU86_F_IS64(op_flags)) {
		u32 old_eflags = EMU86_GETFLAGS();
		if (old_eflags & EFLAGS_VM) {
			/* return from vm86 (to vm86) */
#define VM86_KEEPMASK (EFLAGS_VM | EFLAGS_IOPLMASK | EFLAGS_VIP | EFLAGS_VIF)
			new_eflags &= ~(VM86_KEEPMASK);
			new_eflags |= old_eflags & VM86_KEEPMASK;
#undef VM86_KEEPMASK
			COMPILER_READ_BARRIER();
			EMU86_SETFLAGS(new_eflags);
			EMU86_SETCS_VM86(new_cs);
			EMU86_SETEIP_VM86((u32)new_ip);
			EMU86_SETSP(sp);
			goto done_dont_set_pc;
		}
	}
	if (EMU86_F_IS32(op_flags) && (new_eflags & EFLAGS_VM) && !EMU86_ISUSER()) {
		/* return to vm86 (from 32-bit mode) */
		u32 new_esp;
		u16 new_ss, new_es, new_ds, new_fs, new_gs;
		EMU86_EMULATE_POP(sp, 24);
		EMU86_READ_USER_MEMORY(sp, 24);
		new_esp = EMU86_EMULATE_READL(sp + 0);
		new_ss  = EMU86_EMULATE_READLASW(sp + 4);
		new_es  = EMU86_EMULATE_READLASW(sp + 8);
		new_ds  = EMU86_EMULATE_READLASW(sp + 12);
		new_fs  = EMU86_EMULATE_READLASW(sp + 16);
		new_gs  = EMU86_EMULATE_READLASW(sp + 20);
		COMPILER_READ_BARRIER();
		EMU86_SETFLAGS(new_eflags);
		EMU86_SETCS_VM86(new_cs);
		EMU86_SETEIP_VM86((u32)new_ip);
		EMU86_SETESP_VM86(new_esp);
		EMU86_SETSS_VM86(new_ss);
		EMU86_SETES_VM86(new_es);
		EMU86_SETDS_VM86(new_ds);
		EMU86_SETFS_VM86(new_fs);
		EMU86_SETGS_VM86(new_gs);
		goto done_dont_set_pc;
	}
#endif /* CONFIG_LIBEMU86_WANT_32BIT && CONFIG_LIBEMU86_WANT_16BIT */

	/* Restrict user-space IRET EFLAGS to only update this mask */
#define USERIRET_EFLAGS_MASK                                     \
	(EFLAGS_CF | EFLAGS_PF | EFLAGS_AF | EFLAGS_ZF | EFLAGS_SF | \
	 EFLAGS_TF | EFLAGS_DF | EFLAGS_OF | EFLAGS_NT)

	/* Return to outer privilege level, or return from 64-bit mode.
	 * In this case, always pop (|E|R)SP and SS as well! */
#if CONFIG_LIBEMU86_WANT_32BIT || CONFIG_LIBEMU86_WANT_16BIT
	if (EMU86_F_IS64(op_flags) || ((new_cs & 3) && !EMU86_ISUSER()))
#endif /* CONFIG_LIBEMU86_WANT_32BIT || CONFIG_LIBEMU86_WANT_16BIT */
	{
		REG_UTYPE new_sp;
		u16 new_ss;
		IF_64BIT(if (IS_64BIT()) {
			EMU86_EMULATE_POP(sp, 16);
			EMU86_READ_USER_MEMORY(sp, 16);
			new_sp = EMU86_EMULATE_READQ(sp + 0);
			new_ss = EMU86_EMULATE_READQASW(sp + 8);
		} else) if (!IS_16BIT()) {
			EMU86_EMULATE_POP(sp, 8);
			EMU86_READ_USER_MEMORY(sp, 8);
			new_sp = EMU86_EMULATE_READL(sp + 0);
			new_ss = EMU86_EMULATE_READLASW(sp + 4);
		} else {
			EMU86_EMULATE_POP(sp, 4);
			EMU86_READ_USER_MEMORY(sp, 4);
			new_sp = EMU86_EMULATE_READW(sp + 0);
			new_ss = EMU86_EMULATE_READW(sp + 2);
		}
#if EMU86_EMULATE_CHECKUSER && CONFIG_LIBEMU86_WANT_64BIT
		/* Verify segment registers.
		 * NOTE: We can only get here with `EMU86_ISUSER() == true'
		 *       when the calling code is running in 64-bit mode,
		 *       so these checks aren't necessary otherwise! */
		if (EMU86_ISUSER()) {
			if (!SEGMENT_IS_VALID_USERCODE(new_cs)) {
				THROW(E_INVALID_ARGUMENT_BAD_VALUE,
				      E_INVALID_ARGUMENT_CONTEXT_SIGRETURN_REGISTER,
				      X86_REGISTER_SEGMENT_CS, new_cs);
			}
			if (!SEGMENT_IS_VALID_USERDATA(new_ss)) {
				THROW(E_INVALID_ARGUMENT_BAD_VALUE,
				      E_INVALID_ARGUMENT_CONTEXT_SIGRETURN_REGISTER,
				      X86_REGISTER_SEGMENT_SS, new_ss);
			}
			new_eflags &= USERIRET_EFLAGS_MASK;
			new_eflags |= EMU86_GETFLAGS() & ~USERIRET_EFLAGS_MASK;
		}
#endif /* EMU86_EMULATE_CHECKUSER && CONFIG_LIBEMU86_WANT_64BIT */
		EMU86_SETFLAGS(new_eflags);
		EMU86_SETCS(new_cs);
		EMU86_EMULATE_SETIP((u32)new_ip);
#if CONFIG_LIBEMU86_WANT_64BIT
		EMU86_SETRSP(new_sp);
#else /* CONFIG_LIBEMU86_WANT_64BIT */
		EMU86_SETESP(new_sp);
#endif /* !CONFIG_LIBEMU86_WANT_64BIT */
		EMU86_SETSS(new_ss);
		goto done_dont_set_pc;
	}
#if CONFIG_LIBEMU86_WANT_32BIT || CONFIG_LIBEMU86_WANT_16BIT
	/* Return to same privilege level. */
#if EMU86_EMULATE_CHECKUSER
	/* Verify segment registers. */
	if (EMU86_ISUSER()) {
		if (!SEGMENT_IS_VALID_USERCODE(new_cs)) {
			THROW(E_INVALID_ARGUMENT_BAD_VALUE,
			      E_INVALID_ARGUMENT_CONTEXT_SIGRETURN_REGISTER,
			      X86_REGISTER_SEGMENT_CS, new_cs);
		}
		/* Restrict EFLAGS to only update this mask */
		new_eflags &= USERIRET_EFLAGS_MASK;
		new_eflags |= EMU86_GETFLAGS() & ~USERIRET_EFLAGS_MASK;
	}
#endif /* EMU86_EMULATE_CHECKUSER */
	EMU86_SETFLAGS(new_eflags);
	EMU86_SETCS(new_cs);
	EMU86_EMULATE_SETIP((u32)new_ip);
	goto done_dont_set_pc;
#endif /* CONFIG_LIBEMU86_WANT_32BIT || CONFIG_LIBEMU86_WANT_16BIT */
#undef USERIRET_EFLAGS_MASK
}

#undef REG_UTYPE
#undef REG_STYPE

}
EMU86_INTELLISENSE_END
