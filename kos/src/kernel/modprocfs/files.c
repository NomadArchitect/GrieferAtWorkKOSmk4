/* Copyright (c) 2019-2021 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2021 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef GUARD_MODPROCFS_FILES_C
#define GUARD_MODPROCFS_FILES_C 1
#define _KOS_SOURCE 1
#define _GNU_SOURCE 1

#include <kernel/compiler.h>

#include <kernel/fs/filehandle.h>
#include <kernel/fs/filesys.h>
#include <kernel/fs/super.h>
#include <kernel/handle.h>
#include <kernel/malloc.h>
#include <kernel/memory.h>
#include <kernel/mman/driver.h>
#include <kernel/mman/futexfd.h>
#include <kernel/mman/unmapped.h>
#include <kernel/pipe.h>
#include <kernel/uname.h>
#include <kernel/user.h>
#include <sched/cred.h>
#include <sched/pid.h>
#include <sched/task.h>
#include <sched/tsc.h>

#include <hybrid/atomic.h>
#include <hybrid/host.h>
#include <hybrid/overflow.h>
#include <hybrid/unaligned.h>

#include <kos/except.h>
#include <kos/except/reason/inval.h>
#include <kos/ioctl/leaks.h>
#include <network/socket.h>

#include <assert.h>
#include <format-printer.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <unicode.h>

#include <libcmdline/encode.h>

#if defined(__x86_64__) || defined(__i386__)
#include <sched/x86/iopl.h>
#include <sched/x86/eflags-mask.h>
#endif /* __x86_64__ || __i386__ */

/**/
#include "procfs.h"

/* Implementations for I/O on static procfs files (iow: kernel config files) */

#define print(p, len) (*printer)(arg, p, len)
#define printf(...)   format_printf(printer, arg, __VA_ARGS__)
#define PRINT(str)    print(str, COMPILER_STRLEN(str))

DECL_BEGIN

#if !defined(NDEBUG) && !defined(NDEBUG_FINI)
#define DBG_memset memset
#else /* !NDEBUG && !NDEBUG_FINI */
#define DBG_memset(...) (void)0
#endif /* NDEBUG || NDEBUG_FINI */

/* Create forward declarations. (Prevent declaration errors below) */
#define MKDIR_BEGIN(symbol_name, perm) \
	INTDEF struct constdir symbol_name;
#define MKREG_RO(symbol_name, perm, printer)                                          \
	INTDEF void KCALL printer(pformatprinter printer, void *arg, size_t offset_hint); \
	INTDEF struct procfs_regfile symbol_name;
#define MKREG_RW(symbol_name, perm, printer, writer)                                  \
	INTDEF void KCALL printer(pformatprinter printer, void *arg, size_t offset_hint); \
	INTDEF void KCALL writer(USER CHECKED void const *buf, size_t bufsize);           \
	INTDEF struct procfs_regfile symbol_name;
#define MKREG_CONSTSTR(symbol_name, perm, string_ptr) \
	INTDEF struct procfs_txtfile symbol_name;
#define MKLNK(symbol_name, perm, readlink)            \
	INTDEF WUNUSED NONNULL((1)) size_t KCALL          \
	readlink(struct flnknode *__restrict self,        \
	         USER CHECKED /*utf-8*/ char *buf,        \
	         size_t bufsize) THROWS(E_SEGFAULT, ...); \
	INTDEF struct flnknode symbol_name;
#include "procfs.def"





/************************************************************************/
/* /proc/self                                                           */
/************************************************************************/
INTERN WUNUSED NONNULL((1)) size_t KCALL
ProcFS_Self_Printer(struct flnknode *__restrict UNUSED(self),
                    USER CHECKED /*utf-8*/ char *buf, size_t bufsize)
		THROWS(E_SEGFAULT, ...) {
	return snprintf(buf, bufsize, "%" PRIuN(__SIZEOF_PID_T__), task_getpid_s());
}


/************************************************************************/
/* /proc/thread-self                                                    */
/************************************************************************/
INTERN WUNUSED NONNULL((1)) size_t KCALL
ProcFS_ThreadSelf_Printer(struct flnknode *__restrict UNUSED(self),
                          USER CHECKED /*utf-8*/ char *buf, size_t bufsize)
		THROWS(E_SEGFAULT, ...) {
	return snprintf(buf, bufsize, "%" PRIuN(__SIZEOF_PID_T__) "/task/"
	                              "%" PRIuN(__SIZEOF_PID_T__),
	                task_getpid_s(), task_gettid_s());
}


/************************************************************************/
/* /proc/cmdline                                                        */
/************************************************************************/
INTERN NONNULL((1)) void KCALL
ProcFS_Cmdline_Printer(pformatprinter printer, void *arg,
                       size_t UNUSED(offset_hint)) {
	cmdline_encode(printer, arg, kernel_driver.d_argc, kernel_driver.d_argv);
	(*printer)(arg, "\n", 1);
}


/************************************************************************/
/* /proc/filesystems                                                    */
/************************************************************************/
INTERN NONNULL((1)) void KCALL
ProcFS_Filesystems_Printer(pformatprinter printer, void *arg,
                           size_t UNUSED(offset_hint)) {
	REF struct ffilesys *iter;
	iter = ffilesys_next(NULL);
	while (iter) {
		FINALLY_DECREF_UNLIKELY(iter);

		/* Print the filesystem type name in 1 of 2 ways:
		 *     - "        <name>\n"
		 *     - "nodev   <name>\n" */
		PRIVATE char const prefix[2][9] = {
			[0] = "        ",
			[1] = "nodev   ",
		};
		char const *used_prefix;
#if FFILESYS_F_NODEV == 1
		used_prefix = prefix[iter->ffs_flags & FFILESYS_F_NODEV];
#else /*FFILESYS_F_NODEV == 1 */
		used_prefix = prefix[(iter->ffs_flags & FFILESYS_F_NODEV) ? 1 : 0];
#endif /* FFILESYS_F_NODEV != 1 */

		/* Print the info-line */
		if (printf("%s%s\n", used_prefix, iter->ffs_name) < 0)
			break;

		/* Load the next filesystem type. */
		iter = ffilesys_next(iter);
	}
}


/************************************************************************/
/* /proc/mounts                                                         */
/************************************************************************/
INTERN WUNUSED NONNULL((1)) size_t KCALL
ProcFS_Mounts_Printer(struct flnknode *__restrict UNUSED(self),
                      USER CHECKED /*utf-8*/ char *buf, size_t bufsize)
		THROWS(E_SEGFAULT, ...) {
	return snprintf(buf, bufsize, "%" PRIuN(__SIZEOF_PID_T__) "/mounts", task_getpid_s());
}




/************************************************************************/
/* /proc/kcore                                                          */
/************************************************************************/
INTERN NONNULL((1)) void KCALL
ProcFS_KCore_Printer(pformatprinter printer, void *arg,
                     size_t UNUSED(offset_hint)) {
	/* TODO: Print a coredump for the kernel core itself */
	PRINT("TODO");
}


/************************************************************************/
/* /proc/kos/raminfo                                                    */
/************************************************************************/
PRIVATE NONNULL((1)) void KCALL
print_pagecount(pformatprinter printer, void *arg, physpagecnt_t count) {
	physpagecnt_t adjusted_count;
	char const *unit;
	if (count >= (0x100000 / PAGESIZE)) {
		adjusted_count = count / (0x100000 / PAGESIZE);
		unit           = "MiB";
	} else {
		adjusted_count = (count * PAGESIZE) / 1024;
		unit           = "KiB";
	}
	printf("%" PRIuN(__SIZEOF_PHYSPAGE_T__) " (%" PRIuN(__SIZEOF_PHYSPAGE_T__) " %s)",
	       count, adjusted_count, unit);
}

INTERN NONNULL((1)) void KCALL
ProcFS_Kos_RamInfo_Printer(pformatprinter printer, void *arg,
                           size_t UNUSED(offset_hint)) {
	struct pmemstat st;
	unsigned int usage_percent;
	page_stat(&st);
	PRINT("free:");
	print_pagecount(printer, arg, st.ps_free);
	PRINT("\nused:");
	print_pagecount(printer, arg, st.ps_used);
	PRINT("\nzero:");
	print_pagecount(printer, arg, st.ps_zfree);
	usage_percent = (unsigned int)(((u64)st.ps_used * 100 * 100000) / (st.ps_free + st.ps_used));
	printf("\nusage:%u.%.5u%%\n",
	       usage_percent / 100000,
	       usage_percent % 100000);
}




/************************************************************************/
/* /proc/kos/futexfd-maxexpr                                            */
/************************************************************************/
INTERN NONNULL((1)) void KCALL
procfs_kos_futexfd_maxexpr_print(pformatprinter printer, void *arg,
                                 size_t UNUSED(offset_hint)) {
	ProcFS_PrintSize(printer, arg, mfutexfd_maxexpr);
}
INTERN void KCALL
procfs_kos_futexfd_maxexpr_write(USER CHECKED void const *buf,
                                 size_t bufsize) {
	size_t newmax;
	newmax = ProcFS_ParseSize(buf, bufsize, 1, (size_t)-1);
	ATOMIC_WRITE(mfutexfd_maxexpr, newmax);
}




#if defined(__x86_64__) || defined(__i386__)
PRIVATE void KCALL
KeepIopl_Write(USER CHECKED void const *buf, size_t bufsize, bool *pvalue) {
	bool new_value;
	new_value = ProcFS_ParseBool(buf, bufsize);
	for (;;) {
		bool old_value;
		old_value = ATOMIC_READ(*pvalue);
		if (old_value == new_value)
			break; /* Nothing to do here! */

		/* Need sysadmin to change the value. */
		cred_require_sysadmin();

		/* Need hwio to turn one of these on! */
		if (new_value)
			require(CAP_SYS_RAWIO);

		/* Change the value. */
		if (ATOMIC_CMPXCH_WEAK(*pvalue, old_value, new_value))
			break;
	}
}



/************************************************************************/
/* /proc/sys/x86/keepiopl/fork                                          */
/************************************************************************/
INTERN NONNULL((1)) void KCALL
ProcFS_Sys_X86_KeepIopl_Fork_Print(pformatprinter printer, void *arg,
                                   size_t UNUSED(offset_hint)) {
	ProcFS_PrintBool(printer, arg, x86_iopl_keep_after_fork);
}

INTERN void KCALL
ProcFS_Sys_X86_KeepIopl_Fork_Write(USER CHECKED void const *buf,
                                   size_t bufsize) {
	KeepIopl_Write(buf, bufsize, &x86_iopl_keep_after_fork);
}


/************************************************************************/
/* /proc/sys/x86/keepiopl/clone                                         */
/************************************************************************/
INTERN NONNULL((1)) void KCALL
ProcFS_Sys_X86_KeepIopl_Clone_Print(pformatprinter printer, void *arg,
                                    size_t UNUSED(offset_hint)) {
	ProcFS_PrintBool(printer, arg, x86_iopl_keep_after_clone);
}

INTERN void KCALL
ProcFS_Sys_X86_KeepIopl_Clone_Write(USER CHECKED void const *buf,
                                    size_t bufsize) {
	KeepIopl_Write(buf, bufsize, &x86_iopl_keep_after_clone);
}


/************************************************************************/
/* /proc/sys/x86/keepiopl/exec                                          */
/************************************************************************/
INTERN NONNULL((1)) void KCALL
ProcFS_Sys_X86_KeepIopl_Exec_Print(pformatprinter printer, void *arg,
                                   size_t UNUSED(offset_hint)) {
	bool keep;
	union x86_user_eflags_mask_union mask;
	mask.uem_word = atomic64_read(&x86_exec_eflags_mask);
	keep = (mask.uem_mask & EFLAGS_IOPLMASK) == EFLAGS_IOPLMASK;
	ProcFS_PrintBool(printer, arg, keep);
}

INTERN void KCALL
ProcFS_Sys_X86_KeepIopl_Exec_Write(USER CHECKED void const *buf, size_t bufsize) {
	bool keep;
	union x86_user_eflags_mask_union oldmask, newmask;
	KeepIopl_Write(buf, bufsize, &keep);
	for (;;) {
		oldmask.uem_word = atomic64_read(&x86_exec_eflags_mask);
		newmask.uem_word = oldmask.uem_word;
		newmask.uem_mask &= ~EFLAGS_IOPLMASK;
		if (keep)
			newmask.uem_mask |= EFLAGS_IOPLMASK;
		if (oldmask.uem_mask == newmask.uem_mask)
			break; /* Unchanged. */
		if (atomic64_cmpxch(&x86_exec_eflags_mask, oldmask.uem_word, newmask.uem_word))
			break;
	}
}
#endif /* __x86_64__ || __i386__ */


/************************************************************************/
/* /proc/sys/fs/pipe-max-size                                           */
/************************************************************************/
INTERN NONNULL((1)) void KCALL
ProcFS_Sys_Fs_PipeMaxSize_Print(pformatprinter printer, void *arg,
                                size_t UNUSED(offset_hint)) {
	ProcFS_PrintSize(printer, arg, ATOMIC_READ(pipe_max_bufsize_unprivileged));
}

INTERN void KCALL
ProcFS_Sys_Fs_PipeMaxSize_Write(USER CHECKED void const *buf,
                                size_t bufsize) {
	size_t newsize;
	/* Setting  it lower than the default limit  can't be done, since the default
	 * limit is set regardless of what `pipe_max_bufsize_unprivileged' is set to. */
	newsize = ProcFS_ParseSize(buf, bufsize, RINGBUFFER_DEFAULT_LIMIT, (size_t)-1);
	ATOMIC_WRITE(pipe_max_bufsize_unprivileged, newsize);
}


/************************************************************************/
/* /proc/sys/kernel/domainname                                          */
/************************************************************************/
INTERN NONNULL((1)) void KCALL
ProcFS_Sys_Kernel_Domainname_Print(pformatprinter printer, void *arg,
                                   size_t UNUSED(offset_hint)) {
	printf("%s\n", kernel_uname.domainname);
}

INTERN void KCALL
ProcFS_Sys_Kernel_Domainname_Write(USER CHECKED void const *buf,
                                   size_t bufsize) {
	char temp[_UTSNAME_DOMAIN_LENGTH];
	USER CHECKED char const *endp;
	endp = (USER CHECKED char const *)buf + bufsize;
	while (endp > (USER CHECKED char const *)buf &&
	       unicode_islf(endp[-1]))
		--endp;
	bufsize = (size_t)(endp - (USER CHECKED char const *)buf);
	if (bufsize > _UTSNAME_DOMAIN_LENGTH)
		THROW(E_BUFFER_TOO_SMALL, bufsize, _UTSNAME_DOMAIN_LENGTH);
	cred_require_sysadmin();
	memcpy(temp, buf, bufsize, sizeof(char));
	memset(temp + bufsize, 0, _UTSNAME_DOMAIN_LENGTH - bufsize, sizeof(char));
	COMPILER_READ_BARRIER();
	memcpy(kernel_uname.domainname, temp, sizeof(temp));
}


/************************************************************************/
/* /proc/sys/kernel/hostname                                            */
/************************************************************************/
INTERN NONNULL((1)) void KCALL
ProcFS_Sys_Kernel_Hostname_Print(pformatprinter printer, void *arg,
                                 size_t UNUSED(offset_hint)) {
	printf("%s\n", kernel_uname.nodename);
}

INTERN void KCALL
ProcFS_Sys_Kernel_Hostname_Write(USER CHECKED void const *buf,
                                 size_t bufsize) {
	char temp[_UTSNAME_NODENAME_LENGTH];
	USER CHECKED char const *endp;
	endp = (USER CHECKED char const *)buf + bufsize;
	while (endp > (USER CHECKED char const *)buf &&
	       unicode_islf(endp[-1]))
		--endp;
	bufsize = (size_t)(endp - (USER CHECKED char const *)buf);
	if (bufsize > _UTSNAME_NODENAME_LENGTH)
		THROW(E_BUFFER_TOO_SMALL, bufsize, _UTSNAME_NODENAME_LENGTH);
	cred_require_sysadmin();
	memcpy(temp, buf, bufsize, sizeof(char));
	memset(temp + bufsize, 0, _UTSNAME_NODENAME_LENGTH - bufsize, sizeof(char));
	COMPILER_READ_BARRIER();
	memcpy(kernel_uname.nodename, temp, sizeof(temp));
}


/************************************************************************/
/* /proc/sys/kernel/pid_max                                             */
/************************************************************************/
INTERN NONNULL((1)) void KCALL
ProcFS_Sys_Kernel_PidMax_Print(pformatprinter printer, void *arg,
                               size_t UNUSED(offset_hint)) {
	ProcFS_PrintUPid(printer, arg, ATOMIC_READ(pid_recycle_threshold));
}

INTERN void KCALL
ProcFS_Sys_Kernel_PidMax_Write(USER CHECKED void const *buf,
                               size_t bufsize) {
	upid_t newvalue;
	/* Don't allow the value to become larger than the max possible
	 * positive, signed PID. While the kernel could deal with going
	 * up to the max unsigned PID internally, various system  calls
	 * that accept pid values have special behavior when the  given
	 * pid becomes negative, such as for example `kill(2)'
	 *
	 * As such, don't raise the limit such that we'd end up with
	 * the kernel generating negative PIDs! */
	newvalue = ProcFS_ParseUPid(buf, bufsize, PIDNS_FIRST_NONRESERVED_PID + 1,
	                            (upid_t)__PRIVATE_MAX_S(__SIZEOF_PID_T__) + 1);
	ATOMIC_WRITE(pid_recycle_threshold, newvalue);
}


/************************************************************************/
/* /proc/sys/kernel/randomize_va_space                                  */
/************************************************************************/
INTERN NONNULL((1)) void KCALL
ProcFS_Sys_Kernel_RandomizeVaSpace_Print(pformatprinter printer, void *arg,
                                         size_t UNUSED(offset_hint)) {
	ProcFS_PrintUInt(printer, arg, mman_findunmapped_aslr_getenabled() ? 2 : 0);
}

INTERN void KCALL
ProcFS_Sys_Kernel_RandomizeVaSpace_Write(USER CHECKED void const *buf,
                                         size_t bufsize) {
	unsigned int mode;
	mode = ProcFS_ParseUInt(buf, bufsize, 0, 2);
	mman_findunmapped_aslr_setenabled(mode != 0);
}


/************************************************************************/
/* /proc/sys/kernel/sched_child_runs_first                              */
/************************************************************************/
INTERN NONNULL((1)) void KCALL
ProcFS_Sys_Kernel_SchedChildRunsFirst_Print(pformatprinter printer, void *arg,
                                            size_t UNUSED(offset_hint)) {
	ProcFS_PrintBool(printer, arg, (task_start_default_flags & TASK_START_FHIGHPRIO) != 0);
}

INTERN void KCALL
ProcFS_Sys_Kernel_SchedChildRunsFirst_Write(USER CHECKED void const *buf,
                                            size_t bufsize) {
	bool mode;
	mode = ProcFS_ParseBool(buf, bufsize);
	if (mode) {
		ATOMIC_OR(task_start_default_flags, TASK_START_FHIGHPRIO);
	} else {
		ATOMIC_AND(task_start_default_flags, ~TASK_START_FHIGHPRIO);
	}
}


/************************************************************************/
/* /proc/sys/net/core/rmem_default                                      */
/************************************************************************/
INTERN NONNULL((1)) void KCALL
ProcFS_Sys_Net_Core_RmemDefault_Print(pformatprinter printer, void *arg,
                                      size_t UNUSED(offset_hint)) {
	ProcFS_PrintSize(printer, arg, socket_default_rcvbufsiz);
}

INTERN void KCALL
ProcFS_Sys_Net_Core_RmemDefault_Write(USER CHECKED void const *buf, size_t bufsize) {
	size_t newval;
	newval = ProcFS_ParseSize(buf, bufsize, SOCKET_RCVBUFMIN, socket_default_rcvbufmax);
	ATOMIC_WRITE(socket_default_rcvbufsiz, newval);
}


/************************************************************************/
/* /proc/sys/net/core/wmem_default                                      */
/************************************************************************/
INTERN NONNULL((1)) void KCALL
ProcFS_Sys_Net_Core_WmemDefault_Print(pformatprinter printer, void *arg,
                                      size_t UNUSED(offset_hint)) {
	ProcFS_PrintSize(printer, arg, socket_default_sndbufsiz);
}

INTERN void KCALL
ProcFS_Sys_Net_Core_WmemDefault_Write(USER CHECKED void const *buf, size_t bufsize) {
	size_t newval;
	newval = ProcFS_ParseSize(buf, bufsize, SOCKET_SNDBUFMIN, socket_default_sndbufmax);
	ATOMIC_WRITE(socket_default_sndbufsiz, newval);
}


/************************************************************************/
/* /proc/sys/net/core/rmem_max                                          */
/************************************************************************/
INTERN NONNULL((1)) void KCALL
ProcFS_Sys_Net_Core_RmemMax_Print(pformatprinter printer, void *arg,
                                  size_t UNUSED(offset_hint)) {
	ProcFS_PrintSize(printer, arg, socket_default_rcvbufmax);
}

INTERN void KCALL
ProcFS_Sys_Net_Core_RmemMax_Write(USER CHECKED void const *buf, size_t bufsize) {
	size_t newval, old_dfl;
	newval = ProcFS_ParseSize(buf, bufsize, SOCKET_RCVBUFMIN);
	ATOMIC_WRITE(socket_default_rcvbufmax, newval);
	do {
		old_dfl = ATOMIC_READ(socket_default_rcvbufsiz);
		if (old_dfl <= newval)
			break;
	} while (!ATOMIC_CMPXCH_WEAK(socket_default_rcvbufsiz,
	                             old_dfl, newval));
}


/************************************************************************/
/* /proc/sys/net/core/wmem_max                                          */
/************************************************************************/
INTERN NONNULL((1)) void KCALL
ProcFS_Sys_Net_Core_WmemMax_Print(pformatprinter printer, void *arg,
                                  size_t UNUSED(offset_hint)) {
	ProcFS_PrintSize(printer, arg, socket_default_sndbufmax);
}

INTERN void KCALL
ProcFS_Sys_Net_Core_WmemMax_Write(USER CHECKED void const *buf, size_t bufsize) {
	size_t newval, old_dfl;
	newval = ProcFS_ParseSize(buf, bufsize, SOCKET_SNDBUFMIN);
	ATOMIC_WRITE(socket_default_sndbufmax, newval);
	do {
		old_dfl = ATOMIC_READ(socket_default_sndbufsiz);
		if (old_dfl <= newval)
			break;
	} while (!ATOMIC_CMPXCH_WEAK(socket_default_sndbufsiz,
	                             old_dfl, newval));
}


/************************************************************************/
/* /proc/kos/leaks                                                      */
/************************************************************************/
#ifdef CONFIG_TRACE_MALLOC

struct memleaks: printnode {
	kmalloc_leaks_t ml_leaks;   /* [0..1][const] Memory leaks. */
	unsigned int    ml_relmode; /* Memory leaks release mode (one of `KMALLOC_LEAKS_RELEASE_*') */
};

PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(KCALL memleaks_v_destroy)(struct mfile *__restrict self) {
	struct memleaks *me;
	me = (struct memleaks *)mfile_asprintnode(self);
	kmalloc_leaks_release(me->ml_leaks, me->ml_relmode);
	printnode_v_destroy(me);
}

PRIVATE BLOCKING NONNULL((1, 2)) void KCALL
memleaks_v_print(struct printnode *__restrict self,
                 pformatprinter printer, void *arg,
                 size_t UNUSED(offset_hint))
		THROWS(...) {
	struct memleaks *me = (struct memleaks *)self;
	kmalloc_leaks_print(me->ml_leaks, printer, arg);
}

PRIVATE NOBLOCK ATTR_CONST uint32_t
NOTHROW(FCALL encode_release_mode)(unsigned int mode) {
	uint32_t result;
	switch (mode) {
	case KMALLOC_LEAKS_RELEASE_RESTORE: result = LEAKS_ONCLOSE_RESTORE; break;
	case KMALLOC_LEAKS_RELEASE_DISCARD: result = LEAKS_ONCLOSE_DISCARD; break;
	case KMALLOC_LEAKS_RELEASE_FREE:    result = LEAKS_ONCLOSE_FREE; break;
	default:
		__builtin_unreachable();
	}
	return result;
}

PRIVATE unsigned int FCALL
decode_release_mode(uint32_t mode)
		THROWS(E_INVALID_ARGUMENT_UNKNOWN_COMMAND) {
	unsigned int result;
	switch (mode) {
	case LEAKS_ONCLOSE_RESTORE: result = KMALLOC_LEAKS_RELEASE_RESTORE; break;
	case LEAKS_ONCLOSE_DISCARD: result = KMALLOC_LEAKS_RELEASE_DISCARD; break;
	case LEAKS_ONCLOSE_FREE:    result = KMALLOC_LEAKS_RELEASE_FREE; break;
	default:
		THROW(E_INVALID_ARGUMENT_UNKNOWN_COMMAND,
		      E_INVALID_ARGUMENT_CONTEXT_LEAKS_INVALID_CLOSEMODE,
		      mode);
	}
	return result;
}

PRIVATE uintptr_t FCALL
decode_leakattr(uint64_t attr)
		THROWS(E_INVALID_ARGUMENT_UNKNOWN_COMMAND) {
	uintptr_t result;
	switch (attr) {
	case LEAK_ATTR_MINADDR:  result = MEMLEAK_ATTR_MINADDR; break;
	case LEAK_ATTR_MAXADDR:  result = MEMLEAK_ATTR_MAXADDR; break;
	case LEAK_ATTR_LEAKSIZE: result = MEMLEAK_ATTR_LEAKSIZE; break;
	case LEAK_ATTR_MINUSER:  result = MEMLEAK_ATTR_MINUSER; break;
	case LEAK_ATTR_MAXUSER:  result = MEMLEAK_ATTR_MAXUSER; break;
	case LEAK_ATTR_USERSIZE: result = MEMLEAK_ATTR_USERSIZE; break;
	case LEAK_ATTR_TID:      result = MEMLEAK_ATTR_TID; break;
	case LEAK_ATTR_TBSIZE:   result = MEMLEAK_ATTR_TBSIZE; break;
	case LEAK_ATTR_NOWALK:   result = MEMLEAK_ATTR_NOWALK; break;
	default:
		THROW(E_INVALID_ARGUMENT_UNKNOWN_COMMAND,
		      E_INVALID_ARGUMENT_CONTEXT_LEAKS_INVALID_ATTRIB,
		      attr);
	}
	return result;
}

PRIVATE ATTR_RETNONNULL WUNUSED memleak_t FCALL
get_nth_leak(struct memleaks *__restrict self, uint64_t nth)
		THROWS(E_INVALID_ARGUMENT_BAD_VALUE) {
	size_t i = 0, count = 0;
	memleak_t result = memleak_next(self->ml_leaks, NULL);
	for (;;) {
		if (!result) {
			THROW(E_INVALID_ARGUMENT_BAD_VALUE,
			      E_INVALID_ARGUMENT_CONTEXT_LEAKS_INVALID_INDEX,
			      (uintptr_t)nth, count);
		}
		if (i >= nth)
			break;
		result = memleak_next(self->ml_leaks, result);
		++i;
	}
	return result;
}

PRIVATE BLOCKING NONNULL((1)) syscall_slong_t KCALL
memleaks_v_ioctl(struct mfile *__restrict self, syscall_ulong_t cmd,
                 USER UNCHECKED void *arg, iomode_t mode)
		THROWS(E_INVALID_ARGUMENT_UNKNOWN_COMMAND, ...) {
	struct memleaks *me = (struct memleaks *)mfile_asprintnode(self);
	switch (cmd) {

	case LEAKS_IOC_GETONCLOSE: {
		uint32_t mode;
		validate_writable(arg, sizeof(uint32_t));
		mode = encode_release_mode(me->ml_relmode);
		UNALIGNED_SET32((USER CHECKED uint32_t *)arg, mode);
	}	break;

	case LEAKS_IOC_SETONCLOSE: {
		uint32_t mode;
		validate_readable(arg, sizeof(uint32_t));
		mode           = UNALIGNED_GET32((USER CHECKED uint32_t const *)arg);
		me->ml_relmode = decode_release_mode(mode);
	}	break;

	case LEAKS_IOC_GETCOUNT: {
		size_t count;
		validate_writable(arg, sizeof(uint64_t));
		count = kmalloc_leaks_count(me->ml_leaks);
		UNALIGNED_SET64((USER CHECKED uint64_t *)arg, count);
	}	break;

	case LEAKS_IOC_LEAKATTR: {
		memleak_t leak;
		uintptr_t attr, aval;
		USER CHECKED struct leakattr *info;
		validate_writable(arg, sizeof(struct leakattr));
		info = (USER CHECKED struct leakattr *)arg;
		attr = decode_leakattr(info->la_attr);
		leak = get_nth_leak(me, info->la_index);
		aval = (uintptr_t)memleak_getattr(leak, attr);

		/* Write-back the attribute value. */
		info->la_value = (uint64_t)aval;
	}	break;

	case LEAKS_IOC_LEAKTB: {
		memleak_t leak;
		USER CHECKED struct leaktb *info;
		size_t i, count, req;
		USER CHECKED uint64_t *uvec;
		validate_readwrite(arg, sizeof(struct leaktb));
		info  = (USER CHECKED struct leaktb *)arg;
		leak  = get_nth_leak(me, info->lt_index);
		count = (size_t)info->lt_count;
		uvec  = info->lt_elemp;
		COMPILER_READ_BARRIER();
		validate_writablem(uvec, count, sizeof(uint64_t));
		req = (size_t)memleak_getattr(leak, MEMLEAK_ATTR_TBSIZE);
		info->lt_count = req;
		if (req > count)
			req = count;
		for (i = 0; i < req; ++i)
			uvec[i] = (uint64_t)(uintptr_t)memleak_getattr(leak, MEMLEAK_ATTR_TBADDR(i));
	}	break;

	case LEAKS_IOC_READLEAKMEM:
	case LEAKS_IOC_READUSERMEM: {
		byte_t const *leak_addr;
		size_t leak_size;
		memleak_t leak;
		USER CHECKED struct leakmem *info;
		size_t size, offs, _temp;
		USER CHECKED byte_t *ubuf;
		validate_readwrite(arg, sizeof(struct leakmem));
		info = (USER CHECKED struct leakmem *)arg;
		leak = get_nth_leak(me, info->lm_index);
		offs = (size_t)info->lm_offset;
		size = (size_t)info->lm_size;
		ubuf = info->lm_buf;
		COMPILER_READ_BARRIER();

		/* Load leak attributes */
		if (cmd == LEAKS_IOC_READLEAKMEM) {
			leak_addr = (byte_t const *)memleak_getattr(leak, MEMLEAK_ATTR_MINADDR);
			leak_size = (size_t)memleak_getattr(leak, MEMLEAK_ATTR_LEAKSIZE);
		} else {
			leak_addr = (byte_t const *)memleak_getattr(leak, MEMLEAK_ATTR_MINUSER);
			leak_size = (size_t)memleak_getattr(leak, MEMLEAK_ATTR_USERSIZE);
		}

		/* Limit I/O size to relevant leak size. */
		if (OVERFLOW_UADD(offs, size, &_temp) || _temp > leak_size) {
			if (OVERFLOW_USUB(leak_size, offs, &size))
				size = 0;
			info->lm_size = size;
		}

		/* Copy leaked data into userspace. */
		validate_writable(ubuf, size);
		memcpy(ubuf, leak_addr, size);
	}	break;

	default:
		return printnode_v_ioctl(self, cmd, arg, mode);
	}
	return 0;
}


PRIVATE struct mfile_stream_ops const memleaks_v_stream_ops = {
	.mso_pread  = &printnode_v_pread,
	.mso_preadv = &printnode_v_preadv,
	.mso_stat   = &printnode_v_stat,
	.mso_ioctl  = &memleaks_v_ioctl,
	.mso_hop    = &printnode_v_hop,
};
PRIVATE struct printnode_ops const memleaks_ops = {
	.pno_reg = {{
		.no_file = {
			.mo_destroy    = &memleaks_v_destroy,
			.mo_loadblocks = &printnode_v_loadblocks,
			.mo_changed    = &printnode_v_changed,
			.mo_stream     = &memleaks_v_stream_ops,
		},
		.no_wrattr = &printnode_v_wrattr,
	}},
	.pno_print = &memleaks_v_print,
};

/* Allocate a new memleaks file. */
PRIVATE WUNUSED REF struct memleaks *KCALL
memleaks_createfile(void) {
	REF struct memleaks *result;
	result = (struct memleaks *)kmalloc(sizeof(struct memleaks), GFP_NORMAL);
	TRY {
		/* Collect memory leaks. */
		result->ml_leaks = kmalloc_leaks_collect();
	} EXCEPT {
		kfree(result);
		RETHROW();
	}

	/* Fill in other fields. */
	_mfile_init_common(result);
	result->mf_ops   = &memleaks_ops.pno_reg.rno_node.no_file;
	result->mf_parts = NULL;
	SLIST_INIT(&result->mf_changed);
	result->mf_part_amask = PAGEMASK;
	result->mf_blockshift = PAGESHIFT;
	result->mf_iobashift  = PAGESHIFT;
	result->mf_flags      = MFILE_F_NORMAL;
	atomic64_init(&result->mf_filesize, (uint64_t)-1);
	result->mf_atime   = realtime();
	result->mf_mtime   = result->mf_atime;
	result->mf_ctime   = result->mf_atime;
	result->fn_nlink   = 1;
	result->fn_mode    = S_IFREG | 0400;
	result->fn_uid     = 0;
	result->fn_gid     = 0;
	result->fn_ino     = (ino_t)skew_kernel_pointer(result);
	result->fn_super   = incref(&procfs_super);
	LIST_ENTRY_UNBOUND_INIT(&result->fn_changed);
	DBG_memset(&result->fn_supent, 0xcc, sizeof(result->fn_supent));
	result->fn_supent.rb_rhs = FSUPER_NODES_DELETED;
	LIST_ENTRY_UNBOUND_INIT(&result->fn_allnodes);
	result->ml_relmode = KMALLOC_LEAKS_RELEASE_RESTORE;
	return result;
}

PRIVATE BLOCKING NONNULL((1, 2)) void KCALL
procfs_r_kos_leaks_v_open(struct mfile *__restrict self,
                          struct handle *__restrict hand,
                          struct path *access_path,
                          struct fdirent *access_dent) {
	REF struct memleaks *file;
	REF struct filehandle *fh;

	/* Only the sysadmin is allowed to access memory leaks. */
	require(CAP_SYS_ADMIN);

	/* Create the leaks file. */
	file = memleaks_createfile();
	FINALLY_DECREF_UNLIKELY(file);

	/* Construct the filehandle wrapper object. */
	fh = filehandle_new(file, access_path, access_dent);

	/* Write-back the file-handle wrapper. */
	hand->h_type = HANDLE_TYPE_FILEHANDLE;
	hand->h_data = fh;   /* Inherit reference */
	decref_nokill(self); /* Old reference from `hand->h_data' */
}

PRIVATE struct mfile_stream_ops const procfs_r_kos_leaks_v_stream_ops = {
	.mso_open = &procfs_r_kos_leaks_v_open,
};

INTERN_CONST struct fregnode_ops const procfs_r_kos_leaks_ops = {
	.rno_node = {
		.no_file = {
			.mo_destroy = (void (KCALL *)(struct mfile *__restrict))(void *)(uintptr_t)-1,
			.mo_changed = &fnode_v_changed,
			.mo_stream  = &procfs_r_kos_leaks_v_stream_ops,
		},
		.no_free   = (void (KCALL *)(struct fnode *__restrict))(void *)(uintptr_t)-1,
		.no_wrattr = &fnode_v_wrattr_noop,
	},
};
#endif /* CONFIG_TRACE_MALLOC */


DECL_END

#endif /* !GUARD_MODPROCFS_FILES_C */