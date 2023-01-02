/* HASH CRC-32:0x80f85223 */
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

/* Enumerate known system calls by name */
#ifndef __SYSCALL
#define __SYSCALL(name) /* nothing */
#endif /* !__SYSCALL */

/* Enumerate unused system calls IDs */
#ifndef __SYSCALL_UNUSED
#define __SYSCALL_UNUSED(sysno) /* nothing */
#endif /* !__SYSCALL_UNUSED */

/* Enumerate used system calls */
#ifndef __TSYSCALL
#define __TSYSCALL(table_id, name, table_index, table_index_without_unused_leading) __SYSCALL(name)
#endif /* !__TSYSCALL */

/* Enumerate unused system calls */
#ifndef __TSYSCALL_UNUSED
#define __TSYSCALL_UNUSED(table_id, sysno, table_index, table_index_without_unused_leading) __SYSCALL_UNUSED(sysno)
#endif /* !__TSYSCALL_UNUSED */

/* Enumerate unused system calls at the start of a table */
#ifndef __TSYSCALL_UNUSED_LEADING
#define __TSYSCALL_UNUSED_LEADING(table_id, sysno, table_index) __SYSCALL_UNUSED(sysno)
#endif /* !__TSYSCALL_UNUSED_LEADING */

/* Enumerate unused system calls at the end of a table */
#ifndef __TSYSCALL_UNUSED_TRAILING
#define __TSYSCALL_UNUSED_TRAILING(table_id, sysno, table_index, table_index_without_unused_leading, index_in_unused_trailing) __SYSCALL_UNUSED(sysno)
#endif /* !__TSYSCALL_UNUSED_TRAILING */

/* Invoked at the start of a system call table */
#ifndef __TSYSCALL_TABLE_BEGIN
#define __TSYSCALL_TABLE_BEGIN(table_id, minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding) /* nothing */
#endif /* !__TSYSCALL_TABLE_BEGIN */

/* Invoked at the end of a system call table */
#ifndef __TSYSCALL_TABLE_END
#define __TSYSCALL_TABLE_END(table_id, minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding) /* nothing */
#endif /* !__TSYSCALL_TABLE_END */

/* Enumerate used system calls in the 1st system call */
#ifndef __TSYSCALL0
#define __TSYSCALL0(name, index, index_without_unused_leading) __TSYSCALL(0, name, index, index_without_unused_leading)
#endif /* !__TSYSCALL0 */

/* Enumerate unused system calls in the middle of the 1st system call table*/
#ifndef __TSYSCALL0_UNUSED
#define __TSYSCALL0_UNUSED(sysno, index, index_without_unused_leading) __TSYSCALL_UNUSED(0, sysno, index, index_without_unused_leading)
#endif /* !__TSYSCALL0_UNUSED */

/* Enumerate unused system calls at the start of the 1st system call table */
#ifndef __TSYSCALL0_UNUSED_LEADING
#define __TSYSCALL0_UNUSED_LEADING(sysno, index) __TSYSCALL_UNUSED_LEADING(0, sysno, index)
#endif /* !__TSYSCALL0_UNUSED_LEADING */

/* Enumerate unused system calls at the end of the 1st system call table */
#ifndef __TSYSCALL0_UNUSED_TRAILING
#define __TSYSCALL0_UNUSED_TRAILING(sysno, index, index_without_unused_leading, index_in_unused_trailing) __TSYSCALL_UNUSED_TRAILING(0, sysno, index, index_without_unused_leading, index_in_unused_trailing)
#endif /* !__TSYSCALL0_UNUSED_TRAILING */

/* Invoked at the start of the 1st system call table */
#ifndef __TSYSCALL0_TABLE_BEGIN
#define __TSYSCALL0_TABLE_BEGIN(minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding) \
	__TSYSCALL_TABLE_BEGIN(0, minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding)
#endif /* !__TSYSCALL0_TABLE_BEGIN */

/* Invoked at the end of the 1st system call table */
#ifndef __TSYSCALL0_TABLE_END
#define __TSYSCALL0_TABLE_END(minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding) \
	__TSYSCALL_TABLE_END(0, minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding)
#endif /* !__TSYSCALL0_TABLE_END */

/* Enumerate used system calls in the 2nd system call */
#ifndef __TSYSCALL1
#define __TSYSCALL1(name, index, index_without_unused_leading) __TSYSCALL(1, name, index, index_without_unused_leading)
#endif /* !__TSYSCALL1 */

/* Enumerate unused system calls in the middle of the 2nd system call table*/
#ifndef __TSYSCALL1_UNUSED
#define __TSYSCALL1_UNUSED(sysno, index, index_without_unused_leading) __TSYSCALL_UNUSED(1, sysno, index, index_without_unused_leading)
#endif /* !__TSYSCALL1_UNUSED */

/* Enumerate unused system calls at the start of the 2nd system call table */
#ifndef __TSYSCALL1_UNUSED_LEADING
#define __TSYSCALL1_UNUSED_LEADING(sysno, index) __TSYSCALL_UNUSED_LEADING(1, sysno, index)
#endif /* !__TSYSCALL1_UNUSED_LEADING */

/* Enumerate unused system calls at the end of the 2nd system call table */
#ifndef __TSYSCALL1_UNUSED_TRAILING
#define __TSYSCALL1_UNUSED_TRAILING(sysno, index, index_without_unused_leading, index_in_unused_trailing) __TSYSCALL_UNUSED_TRAILING(1, sysno, index, index_without_unused_leading, index_in_unused_trailing)
#endif /* !__TSYSCALL1_UNUSED_TRAILING */

/* Invoked at the start of the 2nd system call table */
#ifndef __TSYSCALL1_TABLE_BEGIN
#define __TSYSCALL1_TABLE_BEGIN(minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding) \
	__TSYSCALL_TABLE_BEGIN(1, minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding)
#endif /* !__TSYSCALL1_TABLE_BEGIN */

/* Invoked at the end of the 2nd system call table */
#ifndef __TSYSCALL1_TABLE_END
#define __TSYSCALL1_TABLE_END(minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding) \
	__TSYSCALL_TABLE_END(1, minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding)
#endif /* !__TSYSCALL1_TABLE_END */

/************************************************************************/
/* Contents of the 1st table                                            */
/************************************************************************/
__TSYSCALL0_TABLE_BEGIN(0x0, 0x1b7, 0x1b8, 0x0, 0x1b7, 0x1b8)
__TSYSCALL0(read, 0x0, 0x0)
__TSYSCALL0(write, 0x1, 0x1)
__TSYSCALL0(open, 0x2, 0x2)
__TSYSCALL0(close, 0x3, 0x3)
__TSYSCALL0(stat, 0x4, 0x4)
__TSYSCALL0(fstat, 0x5, 0x5)
__TSYSCALL0(lstat, 0x6, 0x6)
__TSYSCALL0(poll, 0x7, 0x7)
__TSYSCALL0(lseek, 0x8, 0x8)
__TSYSCALL0(mmap, 0x9, 0x9)
__TSYSCALL0(mprotect, 0xa, 0xa)
__TSYSCALL0(munmap, 0xb, 0xb)
__TSYSCALL0(brk, 0xc, 0xc)
__TSYSCALL0(rt_sigaction, 0xd, 0xd)
__TSYSCALL0(rt_sigprocmask, 0xe, 0xe)
__TSYSCALL0(rt_sigreturn, 0xf, 0xf)
__TSYSCALL0(ioctl, 0x10, 0x10)
__TSYSCALL0(pread64, 0x11, 0x11)
__TSYSCALL0(pwrite64, 0x12, 0x12)
__TSYSCALL0(readv, 0x13, 0x13)
__TSYSCALL0(writev, 0x14, 0x14)
__TSYSCALL0(access, 0x15, 0x15)
__TSYSCALL0(pipe, 0x16, 0x16)
__TSYSCALL0(select, 0x17, 0x17)
__TSYSCALL0(sched_yield, 0x18, 0x18)
__TSYSCALL0(mremap, 0x19, 0x19)
__TSYSCALL0(msync, 0x1a, 0x1a)
__TSYSCALL0(mincore, 0x1b, 0x1b)
__TSYSCALL0(madvise, 0x1c, 0x1c)
__TSYSCALL0(shmget, 0x1d, 0x1d)
__TSYSCALL0(shmat, 0x1e, 0x1e)
__TSYSCALL0(shmctl, 0x1f, 0x1f)
__TSYSCALL0(dup, 0x20, 0x20)
__TSYSCALL0(dup2, 0x21, 0x21)
__TSYSCALL0(pause, 0x22, 0x22)
__TSYSCALL0(nanosleep, 0x23, 0x23)
__TSYSCALL0(getitimer, 0x24, 0x24)
__TSYSCALL0(alarm, 0x25, 0x25)
__TSYSCALL0(setitimer, 0x26, 0x26)
__TSYSCALL0(getpid, 0x27, 0x27)
__TSYSCALL0(sendfile, 0x28, 0x28)
__TSYSCALL0(socket, 0x29, 0x29)
__TSYSCALL0(connect, 0x2a, 0x2a)
__TSYSCALL0(accept, 0x2b, 0x2b)
__TSYSCALL0(sendto, 0x2c, 0x2c)
__TSYSCALL0(recvfrom, 0x2d, 0x2d)
__TSYSCALL0(sendmsg, 0x2e, 0x2e)
__TSYSCALL0(recvmsg, 0x2f, 0x2f)
__TSYSCALL0(shutdown, 0x30, 0x30)
__TSYSCALL0(bind, 0x31, 0x31)
__TSYSCALL0(listen, 0x32, 0x32)
__TSYSCALL0(getsockname, 0x33, 0x33)
__TSYSCALL0(getpeername, 0x34, 0x34)
__TSYSCALL0(socketpair, 0x35, 0x35)
__TSYSCALL0(setsockopt, 0x36, 0x36)
__TSYSCALL0(getsockopt, 0x37, 0x37)
__TSYSCALL0(clone, 0x38, 0x38)
__TSYSCALL0(fork, 0x39, 0x39)
__TSYSCALL0(vfork, 0x3a, 0x3a)
__TSYSCALL0(execve, 0x3b, 0x3b)
__TSYSCALL0(exit, 0x3c, 0x3c)
__TSYSCALL0(wait4, 0x3d, 0x3d)
__TSYSCALL0(kill, 0x3e, 0x3e)
__TSYSCALL0(uname, 0x3f, 0x3f)
__TSYSCALL0(semget, 0x40, 0x40)
__TSYSCALL0(semop, 0x41, 0x41)
__TSYSCALL0(semctl, 0x42, 0x42)
__TSYSCALL0(shmdt, 0x43, 0x43)
__TSYSCALL0(msgget, 0x44, 0x44)
__TSYSCALL0(msgsnd, 0x45, 0x45)
__TSYSCALL0(msgrcv, 0x46, 0x46)
__TSYSCALL0(msgctl, 0x47, 0x47)
__TSYSCALL0(fcntl, 0x48, 0x48)
__TSYSCALL0(flock, 0x49, 0x49)
__TSYSCALL0(fsync, 0x4a, 0x4a)
__TSYSCALL0(fdatasync, 0x4b, 0x4b)
__TSYSCALL0(truncate, 0x4c, 0x4c)
__TSYSCALL0(ftruncate, 0x4d, 0x4d)
__TSYSCALL0(getdents, 0x4e, 0x4e)
__TSYSCALL0(getcwd, 0x4f, 0x4f)
__TSYSCALL0(chdir, 0x50, 0x50)
__TSYSCALL0(fchdir, 0x51, 0x51)
__TSYSCALL0(rename, 0x52, 0x52)
__TSYSCALL0(mkdir, 0x53, 0x53)
__TSYSCALL0(rmdir, 0x54, 0x54)
__TSYSCALL0(creat, 0x55, 0x55)
__TSYSCALL0(link, 0x56, 0x56)
__TSYSCALL0(unlink, 0x57, 0x57)
__TSYSCALL0(symlink, 0x58, 0x58)
__TSYSCALL0(readlink, 0x59, 0x59)
__TSYSCALL0(chmod, 0x5a, 0x5a)
__TSYSCALL0(fchmod, 0x5b, 0x5b)
__TSYSCALL0(chown, 0x5c, 0x5c)
__TSYSCALL0(fchown, 0x5d, 0x5d)
__TSYSCALL0(lchown, 0x5e, 0x5e)
__TSYSCALL0(umask, 0x5f, 0x5f)
__TSYSCALL0(gettimeofday, 0x60, 0x60)
__TSYSCALL0(getrlimit, 0x61, 0x61)
__TSYSCALL0(getrusage, 0x62, 0x62)
__TSYSCALL0(sysinfo, 0x63, 0x63)
__TSYSCALL0(times, 0x64, 0x64)
__TSYSCALL0(ptrace, 0x65, 0x65)
__TSYSCALL0(getuid, 0x66, 0x66)
__TSYSCALL0(syslog, 0x67, 0x67)
__TSYSCALL0(getgid, 0x68, 0x68)
__TSYSCALL0(setuid, 0x69, 0x69)
__TSYSCALL0(setgid, 0x6a, 0x6a)
__TSYSCALL0(geteuid, 0x6b, 0x6b)
__TSYSCALL0(getegid, 0x6c, 0x6c)
__TSYSCALL0(setpgid, 0x6d, 0x6d)
__TSYSCALL0(getppid, 0x6e, 0x6e)
__TSYSCALL0(getpgrp, 0x6f, 0x6f)
__TSYSCALL0(setsid, 0x70, 0x70)
__TSYSCALL0(setreuid, 0x71, 0x71)
__TSYSCALL0(setregid, 0x72, 0x72)
__TSYSCALL0(getgroups, 0x73, 0x73)
__TSYSCALL0(setgroups, 0x74, 0x74)
__TSYSCALL0(setresuid, 0x75, 0x75)
__TSYSCALL0(getresuid, 0x76, 0x76)
__TSYSCALL0(setresgid, 0x77, 0x77)
__TSYSCALL0(getresgid, 0x78, 0x78)
__TSYSCALL0(getpgid, 0x79, 0x79)
__TSYSCALL0(setfsuid, 0x7a, 0x7a)
__TSYSCALL0(setfsgid, 0x7b, 0x7b)
__TSYSCALL0(getsid, 0x7c, 0x7c)
__TSYSCALL0(capget, 0x7d, 0x7d)
__TSYSCALL0(capset, 0x7e, 0x7e)
__TSYSCALL0(rt_sigpending, 0x7f, 0x7f)
__TSYSCALL0(rt_sigtimedwait, 0x80, 0x80)
__TSYSCALL0(rt_sigqueueinfo, 0x81, 0x81)
__TSYSCALL0(rt_sigsuspend, 0x82, 0x82)
__TSYSCALL0(sigaltstack, 0x83, 0x83)
__TSYSCALL0(utime, 0x84, 0x84)
__TSYSCALL0(mknod, 0x85, 0x85)
__TSYSCALL0(uselib, 0x86, 0x86)
__TSYSCALL0(personality, 0x87, 0x87)
__TSYSCALL0(ustat, 0x88, 0x88)
__TSYSCALL0(statfs, 0x89, 0x89)
__TSYSCALL0(fstatfs, 0x8a, 0x8a)
__TSYSCALL0(sysfs, 0x8b, 0x8b)
__TSYSCALL0(getpriority, 0x8c, 0x8c)
__TSYSCALL0(setpriority, 0x8d, 0x8d)
__TSYSCALL0(sched_setparam, 0x8e, 0x8e)
__TSYSCALL0(sched_getparam, 0x8f, 0x8f)
__TSYSCALL0(sched_setscheduler, 0x90, 0x90)
__TSYSCALL0(sched_getscheduler, 0x91, 0x91)
__TSYSCALL0(sched_get_priority_max, 0x92, 0x92)
__TSYSCALL0(sched_get_priority_min, 0x93, 0x93)
__TSYSCALL0(sched_rr_get_interval, 0x94, 0x94)
__TSYSCALL0(mlock, 0x95, 0x95)
__TSYSCALL0(munlock, 0x96, 0x96)
__TSYSCALL0(mlockall, 0x97, 0x97)
__TSYSCALL0(munlockall, 0x98, 0x98)
__TSYSCALL0(vhangup, 0x99, 0x99)
__TSYSCALL0(modify_ldt, 0x9a, 0x9a)
__TSYSCALL0(pivot_root, 0x9b, 0x9b)
__TSYSCALL0(_sysctl, 0x9c, 0x9c)
__TSYSCALL0(prctl, 0x9d, 0x9d)
__TSYSCALL0(arch_prctl, 0x9e, 0x9e)
__TSYSCALL0(adjtimex, 0x9f, 0x9f)
__TSYSCALL0(setrlimit, 0xa0, 0xa0)
__TSYSCALL0(chroot, 0xa1, 0xa1)
__TSYSCALL0(sync, 0xa2, 0xa2)
__TSYSCALL0(acct, 0xa3, 0xa3)
__TSYSCALL0(settimeofday, 0xa4, 0xa4)
__TSYSCALL0(mount, 0xa5, 0xa5)
__TSYSCALL0(umount2, 0xa6, 0xa6)
__TSYSCALL0(swapon, 0xa7, 0xa7)
__TSYSCALL0(swapoff, 0xa8, 0xa8)
__TSYSCALL0(reboot, 0xa9, 0xa9)
__TSYSCALL0(sethostname, 0xaa, 0xaa)
__TSYSCALL0(setdomainname, 0xab, 0xab)
__TSYSCALL0(iopl, 0xac, 0xac)
__TSYSCALL0(ioperm, 0xad, 0xad)
__TSYSCALL0(create_module, 0xae, 0xae)
__TSYSCALL0(init_module, 0xaf, 0xaf)
__TSYSCALL0(delete_module, 0xb0, 0xb0)
__TSYSCALL0(get_kernel_syms, 0xb1, 0xb1)
__TSYSCALL0(query_module, 0xb2, 0xb2)
__TSYSCALL0(quotactl, 0xb3, 0xb3)
__TSYSCALL0(nfsservctl, 0xb4, 0xb4)
__TSYSCALL0(getpmsg, 0xb5, 0xb5)
__TSYSCALL0(putpmsg, 0xb6, 0xb6)
__TSYSCALL0(afs_syscall, 0xb7, 0xb7)
__TSYSCALL0(tuxcall, 0xb8, 0xb8)
__TSYSCALL0(security, 0xb9, 0xb9)
__TSYSCALL0(gettid, 0xba, 0xba)
__TSYSCALL0(readahead, 0xbb, 0xbb)
__TSYSCALL0(setxattr, 0xbc, 0xbc)
__TSYSCALL0(lsetxattr, 0xbd, 0xbd)
__TSYSCALL0(fsetxattr, 0xbe, 0xbe)
__TSYSCALL0(getxattr, 0xbf, 0xbf)
__TSYSCALL0(lgetxattr, 0xc0, 0xc0)
__TSYSCALL0(fgetxattr, 0xc1, 0xc1)
__TSYSCALL0(listxattr, 0xc2, 0xc2)
__TSYSCALL0(llistxattr, 0xc3, 0xc3)
__TSYSCALL0(flistxattr, 0xc4, 0xc4)
__TSYSCALL0(removexattr, 0xc5, 0xc5)
__TSYSCALL0(lremovexattr, 0xc6, 0xc6)
__TSYSCALL0(fremovexattr, 0xc7, 0xc7)
__TSYSCALL0(tkill, 0xc8, 0xc8)
__TSYSCALL0(time, 0xc9, 0xc9)
__TSYSCALL0(futex, 0xca, 0xca)
__TSYSCALL0(sched_setaffinity, 0xcb, 0xcb)
__TSYSCALL0(sched_getaffinity, 0xcc, 0xcc)
__TSYSCALL0(set_thread_area, 0xcd, 0xcd)
__TSYSCALL0(io_setup, 0xce, 0xce)
__TSYSCALL0(io_destroy, 0xcf, 0xcf)
__TSYSCALL0(io_getevents, 0xd0, 0xd0)
__TSYSCALL0(io_submit, 0xd1, 0xd1)
__TSYSCALL0(io_cancel, 0xd2, 0xd2)
__TSYSCALL0(get_thread_area, 0xd3, 0xd3)
__TSYSCALL0(lookup_dcookie, 0xd4, 0xd4)
__TSYSCALL0(epoll_create, 0xd5, 0xd5)
__TSYSCALL0(epoll_ctl_old, 0xd6, 0xd6)
__TSYSCALL0(epoll_wait_old, 0xd7, 0xd7)
__TSYSCALL0(remap_file_pages, 0xd8, 0xd8)
__TSYSCALL0(getdents64, 0xd9, 0xd9)
__TSYSCALL0(set_tid_address, 0xda, 0xda)
__TSYSCALL0(restart_syscall, 0xdb, 0xdb)
__TSYSCALL0(semtimedop, 0xdc, 0xdc)
__TSYSCALL0(fadvise64, 0xdd, 0xdd)
__TSYSCALL0(timer_create, 0xde, 0xde)
__TSYSCALL0(timer_settime, 0xdf, 0xdf)
__TSYSCALL0(timer_gettime, 0xe0, 0xe0)
__TSYSCALL0(timer_getoverrun, 0xe1, 0xe1)
__TSYSCALL0(timer_delete, 0xe2, 0xe2)
__TSYSCALL0(clock_settime, 0xe3, 0xe3)
__TSYSCALL0(clock_gettime, 0xe4, 0xe4)
__TSYSCALL0(clock_getres, 0xe5, 0xe5)
__TSYSCALL0(clock_nanosleep, 0xe6, 0xe6)
__TSYSCALL0(exit_group, 0xe7, 0xe7)
__TSYSCALL0(epoll_wait, 0xe8, 0xe8)
__TSYSCALL0(epoll_ctl, 0xe9, 0xe9)
__TSYSCALL0(tgkill, 0xea, 0xea)
__TSYSCALL0(utimes, 0xeb, 0xeb)
__TSYSCALL0(vserver, 0xec, 0xec)
__TSYSCALL0(mbind, 0xed, 0xed)
__TSYSCALL0(set_mempolicy, 0xee, 0xee)
__TSYSCALL0(get_mempolicy, 0xef, 0xef)
__TSYSCALL0(mq_open, 0xf0, 0xf0)
__TSYSCALL0(mq_unlink, 0xf1, 0xf1)
__TSYSCALL0(mq_timedsend, 0xf2, 0xf2)
__TSYSCALL0(mq_timedreceive, 0xf3, 0xf3)
__TSYSCALL0(mq_notify, 0xf4, 0xf4)
__TSYSCALL0(mq_getsetattr, 0xf5, 0xf5)
__TSYSCALL0(kexec_load, 0xf6, 0xf6)
__TSYSCALL0(waitid, 0xf7, 0xf7)
__TSYSCALL0(add_key, 0xf8, 0xf8)
__TSYSCALL0(request_key, 0xf9, 0xf9)
__TSYSCALL0(keyctl, 0xfa, 0xfa)
__TSYSCALL0(ioprio_set, 0xfb, 0xfb)
__TSYSCALL0(ioprio_get, 0xfc, 0xfc)
__TSYSCALL0(inotify_init, 0xfd, 0xfd)
__TSYSCALL0(inotify_add_watch, 0xfe, 0xfe)
__TSYSCALL0(inotify_rm_watch, 0xff, 0xff)
__TSYSCALL0(migrate_pages, 0x100, 0x100)
__TSYSCALL0(openat, 0x101, 0x101)
__TSYSCALL0(mkdirat, 0x102, 0x102)
__TSYSCALL0(mknodat, 0x103, 0x103)
__TSYSCALL0(fchownat, 0x104, 0x104)
__TSYSCALL0(futimesat, 0x105, 0x105)
__TSYSCALL0(newfstatat, 0x106, 0x106)
__TSYSCALL0(unlinkat, 0x107, 0x107)
__TSYSCALL0(renameat, 0x108, 0x108)
__TSYSCALL0(linkat, 0x109, 0x109)
__TSYSCALL0(symlinkat, 0x10a, 0x10a)
__TSYSCALL0(readlinkat, 0x10b, 0x10b)
__TSYSCALL0(fchmodat, 0x10c, 0x10c)
__TSYSCALL0(faccessat, 0x10d, 0x10d)
__TSYSCALL0(pselect6, 0x10e, 0x10e)
__TSYSCALL0(ppoll, 0x10f, 0x10f)
__TSYSCALL0(unshare, 0x110, 0x110)
__TSYSCALL0(set_robust_list, 0x111, 0x111)
__TSYSCALL0(get_robust_list, 0x112, 0x112)
__TSYSCALL0(splice, 0x113, 0x113)
__TSYSCALL0(tee, 0x114, 0x114)
__TSYSCALL0(sync_file_range, 0x115, 0x115)
__TSYSCALL0(vmsplice, 0x116, 0x116)
__TSYSCALL0(move_pages, 0x117, 0x117)
__TSYSCALL0(utimensat, 0x118, 0x118)
__TSYSCALL0(epoll_pwait, 0x119, 0x119)
__TSYSCALL0(signalfd, 0x11a, 0x11a)
__TSYSCALL0(timerfd_create, 0x11b, 0x11b)
__TSYSCALL0(eventfd, 0x11c, 0x11c)
__TSYSCALL0(fallocate, 0x11d, 0x11d)
__TSYSCALL0(timerfd_settime, 0x11e, 0x11e)
__TSYSCALL0(timerfd_gettime, 0x11f, 0x11f)
__TSYSCALL0(accept4, 0x120, 0x120)
__TSYSCALL0(signalfd4, 0x121, 0x121)
__TSYSCALL0(eventfd2, 0x122, 0x122)
__TSYSCALL0(epoll_create1, 0x123, 0x123)
__TSYSCALL0(dup3, 0x124, 0x124)
__TSYSCALL0(pipe2, 0x125, 0x125)
__TSYSCALL0(inotify_init1, 0x126, 0x126)
__TSYSCALL0(preadv, 0x127, 0x127)
__TSYSCALL0(pwritev, 0x128, 0x128)
__TSYSCALL0(rt_tgsigqueueinfo, 0x129, 0x129)
__TSYSCALL0(perf_event_open, 0x12a, 0x12a)
__TSYSCALL0(recvmmsg, 0x12b, 0x12b)
__TSYSCALL0(fanotify_init, 0x12c, 0x12c)
__TSYSCALL0(fanotify_mark, 0x12d, 0x12d)
__TSYSCALL0(prlimit64, 0x12e, 0x12e)
__TSYSCALL0(name_to_handle_at, 0x12f, 0x12f)
__TSYSCALL0(open_by_handle_at, 0x130, 0x130)
__TSYSCALL0(clock_adjtime, 0x131, 0x131)
__TSYSCALL0(syncfs, 0x132, 0x132)
__TSYSCALL0(sendmmsg, 0x133, 0x133)
__TSYSCALL0(setns, 0x134, 0x134)
__TSYSCALL0(getcpu, 0x135, 0x135)
__TSYSCALL0(process_vm_readv, 0x136, 0x136)
__TSYSCALL0(process_vm_writev, 0x137, 0x137)
__TSYSCALL0(kcmp, 0x138, 0x138)
__TSYSCALL0(finit_module, 0x139, 0x139)
__TSYSCALL0(sched_setattr, 0x13a, 0x13a)
__TSYSCALL0(sched_getattr, 0x13b, 0x13b)
__TSYSCALL0(renameat2, 0x13c, 0x13c)
__TSYSCALL0(seccomp, 0x13d, 0x13d)
__TSYSCALL0(getrandom, 0x13e, 0x13e)
__TSYSCALL0(memfd_create, 0x13f, 0x13f)
__TSYSCALL0(kexec_file_load, 0x140, 0x140)
__TSYSCALL0(bpf, 0x141, 0x141)
__TSYSCALL0(execveat, 0x142, 0x142)
__TSYSCALL0(userfaultfd, 0x143, 0x143)
__TSYSCALL0(membarrier, 0x144, 0x144)
__TSYSCALL0(mlock2, 0x145, 0x145)
__TSYSCALL0(copy_file_range, 0x146, 0x146)
__TSYSCALL0(preadv2, 0x147, 0x147)
__TSYSCALL0(pwritev2, 0x148, 0x148)
__TSYSCALL0(pkey_mprotect, 0x149, 0x149)
__TSYSCALL0(pkey_alloc, 0x14a, 0x14a)
__TSYSCALL0(pkey_free, 0x14b, 0x14b)
__TSYSCALL0(statx, 0x14c, 0x14c)
__TSYSCALL0(io_pgetevents, 0x14d, 0x14d)
__TSYSCALL0(rseq, 0x14e, 0x14e)
__TSYSCALL0_UNUSED(0x14f, 0x14f, 0x14f)
__TSYSCALL0_UNUSED(0x150, 0x150, 0x150)
__TSYSCALL0_UNUSED(0x151, 0x151, 0x151)
__TSYSCALL0_UNUSED(0x152, 0x152, 0x152)
__TSYSCALL0_UNUSED(0x153, 0x153, 0x153)
__TSYSCALL0_UNUSED(0x154, 0x154, 0x154)
__TSYSCALL0_UNUSED(0x155, 0x155, 0x155)
__TSYSCALL0_UNUSED(0x156, 0x156, 0x156)
__TSYSCALL0_UNUSED(0x157, 0x157, 0x157)
__TSYSCALL0_UNUSED(0x158, 0x158, 0x158)
__TSYSCALL0_UNUSED(0x159, 0x159, 0x159)
__TSYSCALL0_UNUSED(0x15a, 0x15a, 0x15a)
__TSYSCALL0_UNUSED(0x15b, 0x15b, 0x15b)
__TSYSCALL0_UNUSED(0x15c, 0x15c, 0x15c)
__TSYSCALL0_UNUSED(0x15d, 0x15d, 0x15d)
__TSYSCALL0_UNUSED(0x15e, 0x15e, 0x15e)
__TSYSCALL0_UNUSED(0x15f, 0x15f, 0x15f)
__TSYSCALL0_UNUSED(0x160, 0x160, 0x160)
__TSYSCALL0_UNUSED(0x161, 0x161, 0x161)
__TSYSCALL0_UNUSED(0x162, 0x162, 0x162)
__TSYSCALL0_UNUSED(0x163, 0x163, 0x163)
__TSYSCALL0_UNUSED(0x164, 0x164, 0x164)
__TSYSCALL0_UNUSED(0x165, 0x165, 0x165)
__TSYSCALL0_UNUSED(0x166, 0x166, 0x166)
__TSYSCALL0_UNUSED(0x167, 0x167, 0x167)
__TSYSCALL0_UNUSED(0x168, 0x168, 0x168)
__TSYSCALL0_UNUSED(0x169, 0x169, 0x169)
__TSYSCALL0_UNUSED(0x16a, 0x16a, 0x16a)
__TSYSCALL0_UNUSED(0x16b, 0x16b, 0x16b)
__TSYSCALL0_UNUSED(0x16c, 0x16c, 0x16c)
__TSYSCALL0_UNUSED(0x16d, 0x16d, 0x16d)
__TSYSCALL0_UNUSED(0x16e, 0x16e, 0x16e)
__TSYSCALL0_UNUSED(0x16f, 0x16f, 0x16f)
__TSYSCALL0_UNUSED(0x170, 0x170, 0x170)
__TSYSCALL0_UNUSED(0x171, 0x171, 0x171)
__TSYSCALL0_UNUSED(0x172, 0x172, 0x172)
__TSYSCALL0_UNUSED(0x173, 0x173, 0x173)
__TSYSCALL0_UNUSED(0x174, 0x174, 0x174)
__TSYSCALL0_UNUSED(0x175, 0x175, 0x175)
__TSYSCALL0_UNUSED(0x176, 0x176, 0x176)
__TSYSCALL0_UNUSED(0x177, 0x177, 0x177)
__TSYSCALL0_UNUSED(0x178, 0x178, 0x178)
__TSYSCALL0_UNUSED(0x179, 0x179, 0x179)
__TSYSCALL0_UNUSED(0x17a, 0x17a, 0x17a)
__TSYSCALL0_UNUSED(0x17b, 0x17b, 0x17b)
__TSYSCALL0_UNUSED(0x17c, 0x17c, 0x17c)
__TSYSCALL0_UNUSED(0x17d, 0x17d, 0x17d)
__TSYSCALL0_UNUSED(0x17e, 0x17e, 0x17e)
__TSYSCALL0_UNUSED(0x17f, 0x17f, 0x17f)
__TSYSCALL0_UNUSED(0x180, 0x180, 0x180)
__TSYSCALL0_UNUSED(0x181, 0x181, 0x181)
__TSYSCALL0_UNUSED(0x182, 0x182, 0x182)
__TSYSCALL0_UNUSED(0x183, 0x183, 0x183)
__TSYSCALL0_UNUSED(0x184, 0x184, 0x184)
__TSYSCALL0_UNUSED(0x185, 0x185, 0x185)
__TSYSCALL0_UNUSED(0x186, 0x186, 0x186)
__TSYSCALL0_UNUSED(0x187, 0x187, 0x187)
__TSYSCALL0_UNUSED(0x188, 0x188, 0x188)
__TSYSCALL0_UNUSED(0x189, 0x189, 0x189)
__TSYSCALL0_UNUSED(0x18a, 0x18a, 0x18a)
__TSYSCALL0_UNUSED(0x18b, 0x18b, 0x18b)
__TSYSCALL0_UNUSED(0x18c, 0x18c, 0x18c)
__TSYSCALL0_UNUSED(0x18d, 0x18d, 0x18d)
__TSYSCALL0_UNUSED(0x18e, 0x18e, 0x18e)
__TSYSCALL0_UNUSED(0x18f, 0x18f, 0x18f)
__TSYSCALL0_UNUSED(0x190, 0x190, 0x190)
__TSYSCALL0_UNUSED(0x191, 0x191, 0x191)
__TSYSCALL0_UNUSED(0x192, 0x192, 0x192)
__TSYSCALL0_UNUSED(0x193, 0x193, 0x193)
__TSYSCALL0_UNUSED(0x194, 0x194, 0x194)
__TSYSCALL0_UNUSED(0x195, 0x195, 0x195)
__TSYSCALL0_UNUSED(0x196, 0x196, 0x196)
__TSYSCALL0_UNUSED(0x197, 0x197, 0x197)
__TSYSCALL0_UNUSED(0x198, 0x198, 0x198)
__TSYSCALL0_UNUSED(0x199, 0x199, 0x199)
__TSYSCALL0_UNUSED(0x19a, 0x19a, 0x19a)
__TSYSCALL0_UNUSED(0x19b, 0x19b, 0x19b)
__TSYSCALL0_UNUSED(0x19c, 0x19c, 0x19c)
__TSYSCALL0_UNUSED(0x19d, 0x19d, 0x19d)
__TSYSCALL0_UNUSED(0x19e, 0x19e, 0x19e)
__TSYSCALL0_UNUSED(0x19f, 0x19f, 0x19f)
__TSYSCALL0_UNUSED(0x1a0, 0x1a0, 0x1a0)
__TSYSCALL0_UNUSED(0x1a1, 0x1a1, 0x1a1)
__TSYSCALL0_UNUSED(0x1a2, 0x1a2, 0x1a2)
__TSYSCALL0_UNUSED(0x1a3, 0x1a3, 0x1a3)
__TSYSCALL0_UNUSED(0x1a4, 0x1a4, 0x1a4)
__TSYSCALL0_UNUSED(0x1a5, 0x1a5, 0x1a5)
__TSYSCALL0_UNUSED(0x1a6, 0x1a6, 0x1a6)
__TSYSCALL0_UNUSED(0x1a7, 0x1a7, 0x1a7)
__TSYSCALL0(pidfd_send_signal, 0x1a8, 0x1a8)
__TSYSCALL0(io_uring_setup, 0x1a9, 0x1a9)
__TSYSCALL0(io_uring_enter, 0x1aa, 0x1aa)
__TSYSCALL0(io_uring_register, 0x1ab, 0x1ab)
__TSYSCALL0(open_tree, 0x1ac, 0x1ac)
__TSYSCALL0(move_mount, 0x1ad, 0x1ad)
__TSYSCALL0(fsopen, 0x1ae, 0x1ae)
__TSYSCALL0(fsconfig, 0x1af, 0x1af)
__TSYSCALL0(fsmount, 0x1b0, 0x1b0)
__TSYSCALL0(fspick, 0x1b1, 0x1b1)
__TSYSCALL0(pidfd_open, 0x1b2, 0x1b2)
__TSYSCALL0(clone3, 0x1b3, 0x1b3)
__TSYSCALL0(close_range, 0x1b4, 0x1b4)
__TSYSCALL0(openat2, 0x1b5, 0x1b5)
__TSYSCALL0(pidfd_getfd, 0x1b6, 0x1b6)
__TSYSCALL0(faccessat2, 0x1b7, 0x1b7)
__TSYSCALL0_TABLE_END(0x0, 0x1b7, 0x1b8, 0x0, 0x1b7, 0x1b8)

/************************************************************************/
/* Contents of the 2nd table                                            */
/************************************************************************/
__TSYSCALL1_TABLE_BEGIN(0xfffffffffffffed8, 0xffffffffffffffff, 0x128, 0xfffffffffffffed8, 0xffffffffffffffff, 0x128)
__TSYSCALL1(pwritevf, 0x0, 0x0)
__TSYSCALL1(preadvf, 0x1, 0x1)
__TSYSCALL1_UNUSED(0xfffffffffffffeda, 0x2, 0x2)
__TSYSCALL1_UNUSED(0xfffffffffffffedb, 0x3, 0x3)
__TSYSCALL1_UNUSED(0xfffffffffffffedc, 0x4, 0x4)
__TSYSCALL1_UNUSED(0xfffffffffffffedd, 0x5, 0x5)
__TSYSCALL1_UNUSED(0xfffffffffffffede, 0x6, 0x6)
__TSYSCALL1_UNUSED(0xfffffffffffffedf, 0x7, 0x7)
__TSYSCALL1_UNUSED(0xfffffffffffffee0, 0x8, 0x8)
__TSYSCALL1_UNUSED(0xfffffffffffffee1, 0x9, 0x9)
__TSYSCALL1_UNUSED(0xfffffffffffffee2, 0xa, 0xa)
__TSYSCALL1_UNUSED(0xfffffffffffffee3, 0xb, 0xb)
__TSYSCALL1_UNUSED(0xfffffffffffffee4, 0xc, 0xc)
__TSYSCALL1_UNUSED(0xfffffffffffffee5, 0xd, 0xd)
__TSYSCALL1_UNUSED(0xfffffffffffffee6, 0xe, 0xe)
__TSYSCALL1_UNUSED(0xfffffffffffffee7, 0xf, 0xf)
__TSYSCALL1_UNUSED(0xfffffffffffffee8, 0x10, 0x10)
__TSYSCALL1_UNUSED(0xfffffffffffffee9, 0x11, 0x11)
__TSYSCALL1_UNUSED(0xfffffffffffffeea, 0x12, 0x12)
__TSYSCALL1_UNUSED(0xfffffffffffffeeb, 0x13, 0x13)
__TSYSCALL1_UNUSED(0xfffffffffffffeec, 0x14, 0x14)
__TSYSCALL1_UNUSED(0xfffffffffffffeed, 0x15, 0x15)
__TSYSCALL1_UNUSED(0xfffffffffffffeee, 0x16, 0x16)
__TSYSCALL1_UNUSED(0xfffffffffffffeef, 0x17, 0x17)
__TSYSCALL1_UNUSED(0xfffffffffffffef0, 0x18, 0x18)
__TSYSCALL1_UNUSED(0xfffffffffffffef1, 0x19, 0x19)
__TSYSCALL1_UNUSED(0xfffffffffffffef2, 0x1a, 0x1a)
__TSYSCALL1_UNUSED(0xfffffffffffffef3, 0x1b, 0x1b)
__TSYSCALL1_UNUSED(0xfffffffffffffef4, 0x1c, 0x1c)
__TSYSCALL1(freadlinkat, 0x1d, 0x1d)
__TSYSCALL1(fsymlinkat, 0x1e, 0x1e)
__TSYSCALL1_UNUSED(0xfffffffffffffef7, 0x1f, 0x1f)
__TSYSCALL1_UNUSED(0xfffffffffffffef8, 0x20, 0x20)
__TSYSCALL1_UNUSED(0xfffffffffffffef9, 0x21, 0x21)
__TSYSCALL1(kfstatat, 0x22, 0x22)
__TSYSCALL1_UNUSED(0xfffffffffffffefb, 0x23, 0x23)
__TSYSCALL1_UNUSED(0xfffffffffffffefc, 0x24, 0x24)
__TSYSCALL1(fmknodat, 0x25, 0x25)
__TSYSCALL1(fmkdirat, 0x26, 0x26)
__TSYSCALL1_UNUSED(0xfffffffffffffeff, 0x27, 0x27)
__TSYSCALL1_UNUSED(0xffffffffffffff00, 0x28, 0x28)
__TSYSCALL1_UNUSED(0xffffffffffffff01, 0x29, 0x29)
__TSYSCALL1(inotify_add_watch_at, 0x2a, 0x2a)
__TSYSCALL1_UNUSED(0xffffffffffffff03, 0x2b, 0x2b)
__TSYSCALL1_UNUSED(0xffffffffffffff04, 0x2c, 0x2c)
__TSYSCALL1_UNUSED(0xffffffffffffff05, 0x2d, 0x2d)
__TSYSCALL1_UNUSED(0xffffffffffffff06, 0x2e, 0x2e)
__TSYSCALL1_UNUSED(0xffffffffffffff07, 0x2f, 0x2f)
__TSYSCALL1_UNUSED(0xffffffffffffff08, 0x30, 0x30)
__TSYSCALL1_UNUSED(0xffffffffffffff09, 0x31, 0x31)
__TSYSCALL1_UNUSED(0xffffffffffffff0a, 0x32, 0x32)
__TSYSCALL1_UNUSED(0xffffffffffffff0b, 0x33, 0x33)
__TSYSCALL1_UNUSED(0xffffffffffffff0c, 0x34, 0x34)
__TSYSCALL1_UNUSED(0xffffffffffffff0d, 0x35, 0x35)
__TSYSCALL1_UNUSED(0xffffffffffffff0e, 0x36, 0x36)
__TSYSCALL1_UNUSED(0xffffffffffffff0f, 0x37, 0x37)
__TSYSCALL1_UNUSED(0xffffffffffffff10, 0x38, 0x38)
__TSYSCALL1_UNUSED(0xffffffffffffff11, 0x39, 0x39)
__TSYSCALL1_UNUSED(0xffffffffffffff12, 0x3a, 0x3a)
__TSYSCALL1_UNUSED(0xffffffffffffff13, 0x3b, 0x3b)
__TSYSCALL1_UNUSED(0xffffffffffffff14, 0x3c, 0x3c)
__TSYSCALL1_UNUSED(0xffffffffffffff15, 0x3d, 0x3d)
__TSYSCALL1_UNUSED(0xffffffffffffff16, 0x3e, 0x3e)
__TSYSCALL1_UNUSED(0xffffffffffffff17, 0x3f, 0x3f)
__TSYSCALL1_UNUSED(0xffffffffffffff18, 0x40, 0x40)
__TSYSCALL1_UNUSED(0xffffffffffffff19, 0x41, 0x41)
__TSYSCALL1_UNUSED(0xffffffffffffff1a, 0x42, 0x42)
__TSYSCALL1_UNUSED(0xffffffffffffff1b, 0x43, 0x43)
__TSYSCALL1_UNUSED(0xffffffffffffff1c, 0x44, 0x44)
__TSYSCALL1_UNUSED(0xffffffffffffff1d, 0x45, 0x45)
__TSYSCALL1_UNUSED(0xffffffffffffff1e, 0x46, 0x46)
__TSYSCALL1_UNUSED(0xffffffffffffff1f, 0x47, 0x47)
__TSYSCALL1_UNUSED(0xffffffffffffff20, 0x48, 0x48)
__TSYSCALL1_UNUSED(0xffffffffffffff21, 0x49, 0x49)
__TSYSCALL1_UNUSED(0xffffffffffffff22, 0x4a, 0x4a)
__TSYSCALL1_UNUSED(0xffffffffffffff23, 0x4b, 0x4b)
__TSYSCALL1_UNUSED(0xffffffffffffff24, 0x4c, 0x4c)
__TSYSCALL1_UNUSED(0xffffffffffffff25, 0x4d, 0x4d)
__TSYSCALL1_UNUSED(0xffffffffffffff26, 0x4e, 0x4e)
__TSYSCALL1_UNUSED(0xffffffffffffff27, 0x4f, 0x4f)
__TSYSCALL1_UNUSED(0xffffffffffffff28, 0x50, 0x50)
__TSYSCALL1_UNUSED(0xffffffffffffff29, 0x51, 0x51)
__TSYSCALL1_UNUSED(0xffffffffffffff2a, 0x52, 0x52)
__TSYSCALL1_UNUSED(0xffffffffffffff2b, 0x53, 0x53)
__TSYSCALL1_UNUSED(0xffffffffffffff2c, 0x54, 0x54)
__TSYSCALL1_UNUSED(0xffffffffffffff2d, 0x55, 0x55)
__TSYSCALL1_UNUSED(0xffffffffffffff2e, 0x56, 0x56)
__TSYSCALL1_UNUSED(0xffffffffffffff2f, 0x57, 0x57)
__TSYSCALL1_UNUSED(0xffffffffffffff30, 0x58, 0x58)
__TSYSCALL1_UNUSED(0xffffffffffffff31, 0x59, 0x59)
__TSYSCALL1_UNUSED(0xffffffffffffff32, 0x5a, 0x5a)
__TSYSCALL1_UNUSED(0xffffffffffffff33, 0x5b, 0x5b)
__TSYSCALL1_UNUSED(0xffffffffffffff34, 0x5c, 0x5c)
__TSYSCALL1_UNUSED(0xffffffffffffff35, 0x5d, 0x5d)
__TSYSCALL1_UNUSED(0xffffffffffffff36, 0x5e, 0x5e)
__TSYSCALL1_UNUSED(0xffffffffffffff37, 0x5f, 0x5f)
__TSYSCALL1_UNUSED(0xffffffffffffff38, 0x60, 0x60)
__TSYSCALL1_UNUSED(0xffffffffffffff39, 0x61, 0x61)
__TSYSCALL1_UNUSED(0xffffffffffffff3a, 0x62, 0x62)
__TSYSCALL1_UNUSED(0xffffffffffffff3b, 0x63, 0x63)
__TSYSCALL1_UNUSED(0xffffffffffffff3c, 0x64, 0x64)
__TSYSCALL1_UNUSED(0xffffffffffffff3d, 0x65, 0x65)
__TSYSCALL1_UNUSED(0xffffffffffffff3e, 0x66, 0x66)
__TSYSCALL1_UNUSED(0xffffffffffffff3f, 0x67, 0x67)
__TSYSCALL1_UNUSED(0xffffffffffffff40, 0x68, 0x68)
__TSYSCALL1_UNUSED(0xffffffffffffff41, 0x69, 0x69)
__TSYSCALL1_UNUSED(0xffffffffffffff42, 0x6a, 0x6a)
__TSYSCALL1_UNUSED(0xffffffffffffff43, 0x6b, 0x6b)
__TSYSCALL1_UNUSED(0xffffffffffffff44, 0x6c, 0x6c)
__TSYSCALL1_UNUSED(0xffffffffffffff45, 0x6d, 0x6d)
__TSYSCALL1_UNUSED(0xffffffffffffff46, 0x6e, 0x6e)
__TSYSCALL1_UNUSED(0xffffffffffffff47, 0x6f, 0x6f)
__TSYSCALL1_UNUSED(0xffffffffffffff48, 0x70, 0x70)
__TSYSCALL1_UNUSED(0xffffffffffffff49, 0x71, 0x71)
__TSYSCALL1_UNUSED(0xffffffffffffff4a, 0x72, 0x72)
__TSYSCALL1_UNUSED(0xffffffffffffff4b, 0x73, 0x73)
__TSYSCALL1_UNUSED(0xffffffffffffff4c, 0x74, 0x74)
__TSYSCALL1_UNUSED(0xffffffffffffff4d, 0x75, 0x75)
__TSYSCALL1_UNUSED(0xffffffffffffff4e, 0x76, 0x76)
__TSYSCALL1_UNUSED(0xffffffffffffff4f, 0x77, 0x77)
__TSYSCALL1_UNUSED(0xffffffffffffff50, 0x78, 0x78)
__TSYSCALL1_UNUSED(0xffffffffffffff51, 0x79, 0x79)
__TSYSCALL1_UNUSED(0xffffffffffffff52, 0x7a, 0x7a)
__TSYSCALL1_UNUSED(0xffffffffffffff53, 0x7b, 0x7b)
__TSYSCALL1_UNUSED(0xffffffffffffff54, 0x7c, 0x7c)
__TSYSCALL1_UNUSED(0xffffffffffffff55, 0x7d, 0x7d)
__TSYSCALL1_UNUSED(0xffffffffffffff56, 0x7e, 0x7e)
__TSYSCALL1_UNUSED(0xffffffffffffff57, 0x7f, 0x7f)
__TSYSCALL1_UNUSED(0xffffffffffffff58, 0x80, 0x80)
__TSYSCALL1_UNUSED(0xffffffffffffff59, 0x81, 0x81)
__TSYSCALL1_UNUSED(0xffffffffffffff5a, 0x82, 0x82)
__TSYSCALL1_UNUSED(0xffffffffffffff5b, 0x83, 0x83)
__TSYSCALL1_UNUSED(0xffffffffffffff5c, 0x84, 0x84)
__TSYSCALL1_UNUSED(0xffffffffffffff5d, 0x85, 0x85)
__TSYSCALL1_UNUSED(0xffffffffffffff5e, 0x86, 0x86)
__TSYSCALL1_UNUSED(0xffffffffffffff5f, 0x87, 0x87)
__TSYSCALL1_UNUSED(0xffffffffffffff60, 0x88, 0x88)
__TSYSCALL1_UNUSED(0xffffffffffffff61, 0x89, 0x89)
__TSYSCALL1_UNUSED(0xffffffffffffff62, 0x8a, 0x8a)
__TSYSCALL1_UNUSED(0xffffffffffffff63, 0x8b, 0x8b)
__TSYSCALL1(ksysctl, 0x8c, 0x8c)
__TSYSCALL1_UNUSED(0xffffffffffffff65, 0x8d, 0x8d)
__TSYSCALL1_UNUSED(0xffffffffffffff66, 0x8e, 0x8e)
__TSYSCALL1_UNUSED(0xffffffffffffff67, 0x8f, 0x8f)
__TSYSCALL1_UNUSED(0xffffffffffffff68, 0x90, 0x90)
__TSYSCALL1_UNUSED(0xffffffffffffff69, 0x91, 0x91)
__TSYSCALL1_UNUSED(0xffffffffffffff6a, 0x92, 0x92)
__TSYSCALL1_UNUSED(0xffffffffffffff6b, 0x93, 0x93)
__TSYSCALL1_UNUSED(0xffffffffffffff6c, 0x94, 0x94)
__TSYSCALL1_UNUSED(0xffffffffffffff6d, 0x95, 0x95)
__TSYSCALL1_UNUSED(0xffffffffffffff6e, 0x96, 0x96)
__TSYSCALL1_UNUSED(0xffffffffffffff6f, 0x97, 0x97)
__TSYSCALL1_UNUSED(0xffffffffffffff70, 0x98, 0x98)
__TSYSCALL1_UNUSED(0xffffffffffffff71, 0x99, 0x99)
__TSYSCALL1_UNUSED(0xffffffffffffff72, 0x9a, 0x9a)
__TSYSCALL1_UNUSED(0xffffffffffffff73, 0x9b, 0x9b)
__TSYSCALL1_UNUSED(0xffffffffffffff74, 0x9c, 0x9c)
__TSYSCALL1_UNUSED(0xffffffffffffff75, 0x9d, 0x9d)
__TSYSCALL1_UNUSED(0xffffffffffffff76, 0x9e, 0x9e)
__TSYSCALL1_UNUSED(0xffffffffffffff77, 0x9f, 0x9f)
__TSYSCALL1_UNUSED(0xffffffffffffff78, 0xa0, 0xa0)
__TSYSCALL1_UNUSED(0xffffffffffffff79, 0xa1, 0xa1)
__TSYSCALL1(maplibrary, 0xa2, 0xa2)
__TSYSCALL1_UNUSED(0xffffffffffffff7b, 0xa3, 0xa3)
__TSYSCALL1_UNUSED(0xffffffffffffff7c, 0xa4, 0xa4)
__TSYSCALL1_UNUSED(0xffffffffffffff7d, 0xa5, 0xa5)
__TSYSCALL1_UNUSED(0xffffffffffffff7e, 0xa6, 0xa6)
__TSYSCALL1_UNUSED(0xffffffffffffff7f, 0xa7, 0xa7)
__TSYSCALL1_UNUSED(0xffffffffffffff80, 0xa8, 0xa8)
__TSYSCALL1_UNUSED(0xffffffffffffff81, 0xa9, 0xa9)
__TSYSCALL1_UNUSED(0xffffffffffffff82, 0xaa, 0xaa)
__TSYSCALL1_UNUSED(0xffffffffffffff83, 0xab, 0xab)
__TSYSCALL1_UNUSED(0xffffffffffffff84, 0xac, 0xac)
__TSYSCALL1_UNUSED(0xffffffffffffff85, 0xad, 0xad)
__TSYSCALL1_UNUSED(0xffffffffffffff86, 0xae, 0xae)
__TSYSCALL1_UNUSED(0xffffffffffffff87, 0xaf, 0xaf)
__TSYSCALL1_UNUSED(0xffffffffffffff88, 0xb0, 0xb0)
__TSYSCALL1_UNUSED(0xffffffffffffff89, 0xb1, 0xb1)
__TSYSCALL1_UNUSED(0xffffffffffffff8a, 0xb2, 0xb2)
__TSYSCALL1_UNUSED(0xffffffffffffff8b, 0xb3, 0xb3)
__TSYSCALL1_UNUSED(0xffffffffffffff8c, 0xb4, 0xb4)
__TSYSCALL1_UNUSED(0xffffffffffffff8d, 0xb5, 0xb5)
__TSYSCALL1_UNUSED(0xffffffffffffff8e, 0xb6, 0xb6)
__TSYSCALL1_UNUSED(0xffffffffffffff8f, 0xb7, 0xb7)
__TSYSCALL1_UNUSED(0xffffffffffffff90, 0xb8, 0xb8)
__TSYSCALL1_UNUSED(0xffffffffffffff91, 0xb9, 0xb9)
__TSYSCALL1_UNUSED(0xffffffffffffff92, 0xba, 0xba)
__TSYSCALL1_UNUSED(0xffffffffffffff93, 0xbb, 0xbb)
__TSYSCALL1_UNUSED(0xffffffffffffff94, 0xbc, 0xbc)
__TSYSCALL1_UNUSED(0xffffffffffffff95, 0xbd, 0xbd)
__TSYSCALL1_UNUSED(0xffffffffffffff96, 0xbe, 0xbe)
__TSYSCALL1_UNUSED(0xffffffffffffff97, 0xbf, 0xbf)
__TSYSCALL1_UNUSED(0xffffffffffffff98, 0xc0, 0xc0)
__TSYSCALL1_UNUSED(0xffffffffffffff99, 0xc1, 0xc1)
__TSYSCALL1_UNUSED(0xffffffffffffff9a, 0xc2, 0xc2)
__TSYSCALL1_UNUSED(0xffffffffffffff9b, 0xc3, 0xc3)
__TSYSCALL1_UNUSED(0xffffffffffffff9c, 0xc4, 0xc4)
__TSYSCALL1_UNUSED(0xffffffffffffff9d, 0xc5, 0xc5)
__TSYSCALL1_UNUSED(0xffffffffffffff9e, 0xc6, 0xc6)
__TSYSCALL1_UNUSED(0xffffffffffffff9f, 0xc7, 0xc7)
__TSYSCALL1_UNUSED(0xffffffffffffffa0, 0xc8, 0xc8)
__TSYSCALL1(fsmode, 0xc9, 0xc9)
__TSYSCALL1_UNUSED(0xffffffffffffffa2, 0xca, 0xca)
__TSYSCALL1_UNUSED(0xffffffffffffffa3, 0xcb, 0xcb)
__TSYSCALL1_UNUSED(0xffffffffffffffa4, 0xcc, 0xcc)
__TSYSCALL1_UNUSED(0xffffffffffffffa5, 0xcd, 0xcd)
__TSYSCALL1_UNUSED(0xffffffffffffffa6, 0xce, 0xce)
__TSYSCALL1_UNUSED(0xffffffffffffffa7, 0xcf, 0xcf)
__TSYSCALL1_UNUSED(0xffffffffffffffa8, 0xd0, 0xd0)
__TSYSCALL1_UNUSED(0xffffffffffffffa9, 0xd1, 0xd1)
__TSYSCALL1_UNUSED(0xffffffffffffffaa, 0xd2, 0xd2)
__TSYSCALL1_UNUSED(0xffffffffffffffab, 0xd3, 0xd3)
__TSYSCALL1_UNUSED(0xffffffffffffffac, 0xd4, 0xd4)
__TSYSCALL1_UNUSED(0xffffffffffffffad, 0xd5, 0xd5)
__TSYSCALL1_UNUSED(0xffffffffffffffae, 0xd6, 0xd6)
__TSYSCALL1_UNUSED(0xffffffffffffffaf, 0xd7, 0xd7)
__TSYSCALL1(fchdirat, 0xd8, 0xd8)
__TSYSCALL1(kreaddirf, 0xd9, 0xd9)
__TSYSCALL1(kreaddir, 0xda, 0xda)
__TSYSCALL1_UNUSED(0xffffffffffffffb3, 0xdb, 0xdb)
__TSYSCALL1_UNUSED(0xffffffffffffffb4, 0xdc, 0xdc)
__TSYSCALL1_UNUSED(0xffffffffffffffb5, 0xdd, 0xdd)
__TSYSCALL1_UNUSED(0xffffffffffffffb6, 0xde, 0xde)
__TSYSCALL1_UNUSED(0xffffffffffffffb7, 0xdf, 0xdf)
__TSYSCALL1_UNUSED(0xffffffffffffffb8, 0xe0, 0xe0)
__TSYSCALL1_UNUSED(0xffffffffffffffb9, 0xe1, 0xe1)
__TSYSCALL1_UNUSED(0xffffffffffffffba, 0xe2, 0xe2)
__TSYSCALL1_UNUSED(0xffffffffffffffbb, 0xe3, 0xe3)
__TSYSCALL1_UNUSED(0xffffffffffffffbc, 0xe4, 0xe4)
__TSYSCALL1_UNUSED(0xffffffffffffffbd, 0xe5, 0xe5)
__TSYSCALL1_UNUSED(0xffffffffffffffbe, 0xe6, 0xe6)
__TSYSCALL1_UNUSED(0xffffffffffffffbf, 0xe7, 0xe7)
__TSYSCALL1_UNUSED(0xffffffffffffffc0, 0xe8, 0xe8)
__TSYSCALL1_UNUSED(0xffffffffffffffc1, 0xe9, 0xe9)
__TSYSCALL1_UNUSED(0xffffffffffffffc2, 0xea, 0xea)
__TSYSCALL1_UNUSED(0xffffffffffffffc3, 0xeb, 0xeb)
__TSYSCALL1_UNUSED(0xffffffffffffffc4, 0xec, 0xec)
__TSYSCALL1_UNUSED(0xffffffffffffffc5, 0xed, 0xed)
__TSYSCALL1_UNUSED(0xffffffffffffffc6, 0xee, 0xee)
__TSYSCALL1_UNUSED(0xffffffffffffffc7, 0xef, 0xef)
__TSYSCALL1_UNUSED(0xffffffffffffffc8, 0xf0, 0xf0)
__TSYSCALL1_UNUSED(0xffffffffffffffc9, 0xf1, 0xf1)
__TSYSCALL1_UNUSED(0xffffffffffffffca, 0xf2, 0xf2)
__TSYSCALL1_UNUSED(0xffffffffffffffcb, 0xf3, 0xf3)
__TSYSCALL1_UNUSED(0xffffffffffffffcc, 0xf4, 0xf4)
__TSYSCALL1_UNUSED(0xffffffffffffffcd, 0xf5, 0xf5)
__TSYSCALL1_UNUSED(0xffffffffffffffce, 0xf6, 0xf6)
__TSYSCALL1_UNUSED(0xffffffffffffffcf, 0xf7, 0xf7)
__TSYSCALL1_UNUSED(0xffffffffffffffd0, 0xf8, 0xf8)
__TSYSCALL1_UNUSED(0xffffffffffffffd1, 0xf9, 0xf9)
__TSYSCALL1_UNUSED(0xffffffffffffffd2, 0xfa, 0xfa)
__TSYSCALL1_UNUSED(0xffffffffffffffd3, 0xfb, 0xfb)
__TSYSCALL1_UNUSED(0xffffffffffffffd4, 0xfc, 0xfc)
__TSYSCALL1_UNUSED(0xffffffffffffffd5, 0xfd, 0xfd)
__TSYSCALL1_UNUSED(0xffffffffffffffd6, 0xfe, 0xfe)
__TSYSCALL1_UNUSED(0xffffffffffffffd7, 0xff, 0xff)
__TSYSCALL1_UNUSED(0xffffffffffffffd8, 0x100, 0x100)
__TSYSCALL1(set_exception_handler, 0x101, 0x101)
__TSYSCALL1(get_exception_handler, 0x102, 0x102)
__TSYSCALL1(rpc_serve_sysret, 0x103, 0x103)
__TSYSCALL1(set_userprocmask_address, 0x104, 0x104)
__TSYSCALL1(rtm_test, 0x105, 0x105)
__TSYSCALL1(rtm_abort, 0x106, 0x106)
__TSYSCALL1(rtm_end, 0x107, 0x107)
__TSYSCALL1(rtm_begin, 0x108, 0x108)
__TSYSCALL1(userviofd, 0x109, 0x109)
__TSYSCALL1_UNUSED(0xffffffffffffffe2, 0x10a, 0x10a)
__TSYSCALL1(coredump, 0x10b, 0x10b)
__TSYSCALL1_UNUSED(0xffffffffffffffe4, 0x10c, 0x10c)
__TSYSCALL1(mktty, 0x10d, 0x10d)
__TSYSCALL1(lfutexexpr, 0x10e, 0x10e)
__TSYSCALL1_UNUSED(0xffffffffffffffe7, 0x10f, 0x10f)
__TSYSCALL1(lfutex, 0x110, 0x110)
__TSYSCALL1(rpc_serve, 0x111, 0x111)
__TSYSCALL1(debugtrap, 0x112, 0x112)
__TSYSCALL1_UNUSED(0xffffffffffffffeb, 0x113, 0x113)
__TSYSCALL1(writevf, 0x114, 0x114)
__TSYSCALL1(readvf, 0x115, 0x115)
__TSYSCALL1(pwrite64f, 0x116, 0x116)
__TSYSCALL1(pread64f, 0x117, 0x117)
__TSYSCALL1(ioctlf, 0x118, 0x118)
__TSYSCALL1(ksigreturn, 0x119, 0x119)
__TSYSCALL1_UNUSED(0xfffffffffffffff2, 0x11a, 0x11a)
__TSYSCALL1(openpty, 0x11b, 0x11b)
__TSYSCALL1(rpc_schedule, 0x11c, 0x11c)
__TSYSCALL1(frealpathat, 0x11d, 0x11d)
__TSYSCALL1(frealpath4, 0x11e, 0x11e)
__TSYSCALL1(getdrives, 0x11f, 0x11f)
__TSYSCALL1(detach, 0x120, 0x120)
__TSYSCALL1(readf, 0x121, 0x121)
__TSYSCALL1(klstat, 0x122, 0x122)
__TSYSCALL1(kfstat, 0x123, 0x123)
__TSYSCALL1(kstat, 0x124, 0x124)
__TSYSCALL1_UNUSED(0xfffffffffffffffd, 0x125, 0x125)
__TSYSCALL1_UNUSED(0xfffffffffffffffe, 0x126, 0x126)
__TSYSCALL1(writef, 0x127, 0x127)
__TSYSCALL1_TABLE_END(0xfffffffffffffed8, 0xffffffffffffffff, 0x128, 0xfffffffffffffed8, 0xffffffffffffffff, 0x128)

#undef __TSYSCALL1_TABLE_END
#undef __TSYSCALL1_TABLE_BEGIN
#undef __TSYSCALL1_UNUSED_TRAILING
#undef __TSYSCALL1_UNUSED_LEADING
#undef __TSYSCALL1_UNUSED
#undef __TSYSCALL1
#undef __TSYSCALL0_TABLE_END
#undef __TSYSCALL0_TABLE_BEGIN
#undef __TSYSCALL0_UNUSED_TRAILING
#undef __TSYSCALL0_UNUSED_LEADING
#undef __TSYSCALL0_UNUSED
#undef __TSYSCALL0
#undef __TSYSCALL_TABLE_END
#undef __TSYSCALL_TABLE_BEGIN
#undef __TSYSCALL_UNUSED_TRAILING
#undef __TSYSCALL_UNUSED_LEADING
#undef __TSYSCALL_UNUSED
#undef __TSYSCALL
#undef __SYSCALL_UNUSED
#undef __SYSCALL
