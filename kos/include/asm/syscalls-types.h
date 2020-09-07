/* HASH CRC-32:0x3e756e13 */
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

#ifndef __SYSCALL_REPR
#define __SYSCALL_REPR(id) /* nothing */
#endif /* !__SYSCALL_REPR */

#ifdef __WANT_HAVE_SYSCALL_ARGUMENT_REPR_TYPES
#define HAVE_SC_REPR_ACCEPT4_FLAGS 1
#define HAVE_SC_REPR_ACCESS_TYPE 1
#define HAVE_SC_REPR_ATFLAG__EMPTY_PATH__SYMLINK_FOLLOW__DOSPATH 1
#define HAVE_SC_REPR_ATFLAG__EMPTY_PATH__SYMLINK_NOFOLLOW__DOSPATH 1
#define HAVE_SC_REPR_ATFLAG__REMOVEDIR__REMOVEREG__DOSPATH 1
#define HAVE_SC_REPR_ATFLAG__SYMLINK_NOFOLLOW__CHANGE_CTIME__DOSPATH 1
#define HAVE_SC_REPR_ATFLAG__SYMLINK_NOFOLLOW__DOSPATH 1
#define HAVE_SC_REPR_ATFLAG__SYMLINK_NOFOLLOW__EACCESS__DOSPATH 1
#define HAVE_SC_REPR_BUFFER 1
#define HAVE_SC_REPR_CLOCKID_T 1
#define HAVE_SC_REPR_CLONE_FLAGS 1
#define HAVE_SC_REPR_CLONE_FLAGS_SETNS 1
#define HAVE_SC_REPR_CLONE_FLAGS_UNSHARE 1
#define HAVE_SC_REPR_CPUSET 1
#define HAVE_SC_REPR_DEV_BLK 1
#define HAVE_SC_REPR_DEV_T 1
#define HAVE_SC_REPR_EPOLL_OP 1
#define HAVE_SC_REPR_EVENTFD2_FLAGS 1
#define HAVE_SC_REPR_EXIT_STATUS 1
#define HAVE_SC_REPR_FALLOCATE_MODE 1
#define HAVE_SC_REPR_FCNTL_ARG 1
#define HAVE_SC_REPR_FCNTL_COMMAND 1
#define HAVE_SC_REPR_FD_T 1
#define HAVE_SC_REPR_FILENAME 1
#define HAVE_SC_REPR_FUTEX_OP 1
#define HAVE_SC_REPR_GETRANDOM_FLAGS 1
#define HAVE_SC_REPR_GETRUSAGE_WHO 1
#define HAVE_SC_REPR_GID_T 1
#define HAVE_SC_REPR_GID_VECTOR 1
#define HAVE_SC_REPR_IDTYPE_T 1
#define HAVE_SC_REPR_ID_T 1
#define HAVE_SC_REPR_INT 1
#define HAVE_SC_REPR_IOCTL_ARG 1
#define HAVE_SC_REPR_IOCTL_COMMAND 1
#define HAVE_SC_REPR_IOPRIO_ID 1
#define HAVE_SC_REPR_IOPRIO_VALUE 1
#define HAVE_SC_REPR_IOPRIO_WHO 1
#define HAVE_SC_REPR_ITIMER_WHICH 1
#define HAVE_SC_REPR_KCMP_TYPE 1
#define HAVE_SC_REPR_MEMFD_CREATE_FLAGS 1
#define HAVE_SC_REPR_MLOCKALL_FLAGS 1
#define HAVE_SC_REPR_MMAP_FLAGS 1
#define HAVE_SC_REPR_MMAP_PROT 1
#define HAVE_SC_REPR_MODE_T 1
#define HAVE_SC_REPR_MOUNT_FLAGS 1
#define HAVE_SC_REPR_MREMAP_FLAGS 1
#define HAVE_SC_REPR_OFLAG_T 1
#define HAVE_SC_REPR_OFLAG__CLOEXEC__CLOFORK 1
#define HAVE_SC_REPR_OFLAG__CLOEXEC__CLOFORK__NONBLOCK__DIRECT 1
#define HAVE_SC_REPR_PID_T 1
#define HAVE_SC_REPR_POINTER 1
#define HAVE_SC_REPR_REBOOT_HOW 1
#define HAVE_SC_REPR_RENAMEAT2_FLAGS 1
#define HAVE_SC_REPR_RLIMIT_RESOURCE 1
#define HAVE_SC_REPR_SCHED_POLICY 1
#define HAVE_SC_REPR_SCHED_PRIORITY_WHICH 1
#define HAVE_SC_REPR_SEEK_WHENCE 1
#define HAVE_SC_REPR_SIGHANDLER_T 1
#define HAVE_SC_REPR_SIGNALFD4_FLAGS 1
#define HAVE_SC_REPR_SIGNO_T 1
#define HAVE_SC_REPR_SIGPROCMASK_HOW 1
#define HAVE_SC_REPR_SIZE_T 1
#define HAVE_SC_REPR_SOCKET_DOMAIN 1
#define HAVE_SC_REPR_SOCKET_PROTOCOL 1
#define HAVE_SC_REPR_SOCKET_RECVMSG_FLAGS 1
#define HAVE_SC_REPR_SOCKET_RECVMSG_FLAGS2 1
#define HAVE_SC_REPR_SOCKET_RECVMSG_FLAGS3 1
#define HAVE_SC_REPR_SOCKET_SENDMSG_FLAGS 1
#define HAVE_SC_REPR_SOCKET_SHUTDOWN_HOW 1
#define HAVE_SC_REPR_SOCKET_TYPE 1
#define HAVE_SC_REPR_SOCKLEN_T 1
#define HAVE_SC_REPR_SOCKOPT_LEVEL 1
#define HAVE_SC_REPR_SOCKOPT_OPTNAME 1
#define HAVE_SC_REPR_SOCKOPT_OPTVAL 1
#define HAVE_SC_REPR_SPLICE_FLAGS 1
#define HAVE_SC_REPR_STRING 1
#define HAVE_SC_REPR_STRING_VECTOR 1
#define HAVE_SC_REPR_STRUCT_FDSET 1
#define HAVE_SC_REPR_STRUCT_FILE_HANDLE 1
#define HAVE_SC_REPR_STRUCT_FPUSTATE 1
#define HAVE_SC_REPR_STRUCT_IOVEC 1
#define HAVE_SC_REPR_STRUCT_IOVEC_C 1
#define HAVE_SC_REPR_STRUCT_ITIMERSPEC 1
#define HAVE_SC_REPR_STRUCT_ITIMERVAL 1
#define HAVE_SC_REPR_STRUCT_MMSGHDR 1
#define HAVE_SC_REPR_STRUCT_MQ_ATTR 1
#define HAVE_SC_REPR_STRUCT_MSGHDR 1
#define HAVE_SC_REPR_STRUCT_POLLFD 1
#define HAVE_SC_REPR_STRUCT_RLIMIT 1
#define HAVE_SC_REPR_STRUCT_RLIMIT64 1
#define HAVE_SC_REPR_STRUCT_RPC_SYSCALL_INFO 1
#define HAVE_SC_REPR_STRUCT_SCHED_PARAM 1
#define HAVE_SC_REPR_STRUCT_SIGACTION 1
#define HAVE_SC_REPR_STRUCT_SIGALTSTACK 1
#define HAVE_SC_REPR_STRUCT_SIGEVENT 1
#define HAVE_SC_REPR_STRUCT_SIGINFO 1
#define HAVE_SC_REPR_STRUCT_SIGMASK_SIGSET_AND_LEN 1
#define HAVE_SC_REPR_STRUCT_SIGSET 1
#define HAVE_SC_REPR_STRUCT_SOCKADDR 1
#define HAVE_SC_REPR_STRUCT_TIMESPEC 1
#define HAVE_SC_REPR_STRUCT_TIMESPEC_OR_UINT32 1
#define HAVE_SC_REPR_STRUCT_TIMESPEC_VEC2_OR_3 1
#define HAVE_SC_REPR_STRUCT_TIMEVAL 1
#define HAVE_SC_REPR_STRUCT_TIMEVAL_VEC2 1
#define HAVE_SC_REPR_STRUCT_TIMEZONE 1
#define HAVE_SC_REPR_STRUCT_UCPUSTATE 1
#define HAVE_SC_REPR_STRUCT_UTIMBUF 1
#define HAVE_SC_REPR_SWAPFLAGS 1
#define HAVE_SC_REPR_SYNC_FILE_RANGE_FLAGS 1
#define HAVE_SC_REPR_SYSCALL_SLONG_T 1
#define HAVE_SC_REPR_SYSCALL_ULONG_T 1
#define HAVE_SC_REPR_SYSLOG_LEVEL 1
#define HAVE_SC_REPR_TIMERFD_FLAGS 1
#define HAVE_SC_REPR_TIMERFD_TIMER_FLAGS 1
#define HAVE_SC_REPR_TIMER_FLAGS 1
#define HAVE_SC_REPR_TIMER_T 1
#define HAVE_SC_REPR_UID_T 1
#define HAVE_SC_REPR_UINT32_T 1
#define HAVE_SC_REPR_UINT64_T 1
#define HAVE_SC_REPR_WAITFLAG 1
#define HAVE_SC_REPR_WAITID_OPTIONS 1
#define HAVE_SC_REPR_XATTR_FLAGS 1
#endif /* __WANT_HAVE_SYSCALL_ARGUMENT_REPR_TYPES */

#ifdef __WANT_HAVE_SYSCALL_RETURN_REPR_TYPES
#define HAVE_SC_REPR_ERRNO_T 1
#define HAVE_SC_REPR_SSIZE_T 1
#define HAVE_SC_REPR_TIME_T 1
#endif /* __WANT_HAVE_SYSCALL_RETURN_REPR_TYPES */

#ifdef __WANT_SYSCALL_ARGUMENT_REPR_TYPES
__SYSCALL_REPR(SC_REPR_ACCEPT4_FLAGS)
__SYSCALL_REPR(SC_REPR_ACCESS_TYPE)
__SYSCALL_REPR(SC_REPR_ATFLAG__EMPTY_PATH__SYMLINK_FOLLOW__DOSPATH)
__SYSCALL_REPR(SC_REPR_ATFLAG__EMPTY_PATH__SYMLINK_NOFOLLOW__DOSPATH)
__SYSCALL_REPR(SC_REPR_ATFLAG__REMOVEDIR__REMOVEREG__DOSPATH)
__SYSCALL_REPR(SC_REPR_ATFLAG__SYMLINK_NOFOLLOW__CHANGE_CTIME__DOSPATH)
__SYSCALL_REPR(SC_REPR_ATFLAG__SYMLINK_NOFOLLOW__DOSPATH)
__SYSCALL_REPR(SC_REPR_ATFLAG__SYMLINK_NOFOLLOW__EACCESS__DOSPATH)
__SYSCALL_REPR(SC_REPR_BUFFER)
__SYSCALL_REPR(SC_REPR_CLOCKID_T)
__SYSCALL_REPR(SC_REPR_CLONE_FLAGS)
__SYSCALL_REPR(SC_REPR_CLONE_FLAGS_SETNS)
__SYSCALL_REPR(SC_REPR_CLONE_FLAGS_UNSHARE)
__SYSCALL_REPR(SC_REPR_CPUSET)
__SYSCALL_REPR(SC_REPR_DEV_BLK)
__SYSCALL_REPR(SC_REPR_DEV_T)
__SYSCALL_REPR(SC_REPR_EPOLL_OP)
__SYSCALL_REPR(SC_REPR_EVENTFD2_FLAGS)
__SYSCALL_REPR(SC_REPR_EXIT_STATUS)
__SYSCALL_REPR(SC_REPR_FALLOCATE_MODE)
__SYSCALL_REPR(SC_REPR_FCNTL_ARG)
__SYSCALL_REPR(SC_REPR_FCNTL_COMMAND)
__SYSCALL_REPR(SC_REPR_FD_T)
__SYSCALL_REPR(SC_REPR_FILENAME)
__SYSCALL_REPR(SC_REPR_FUTEX_OP)
__SYSCALL_REPR(SC_REPR_GETRANDOM_FLAGS)
__SYSCALL_REPR(SC_REPR_GETRUSAGE_WHO)
__SYSCALL_REPR(SC_REPR_GID_T)
__SYSCALL_REPR(SC_REPR_GID_VECTOR)
__SYSCALL_REPR(SC_REPR_IDTYPE_T)
__SYSCALL_REPR(SC_REPR_ID_T)
__SYSCALL_REPR(SC_REPR_INT)
__SYSCALL_REPR(SC_REPR_IOCTL_ARG)
__SYSCALL_REPR(SC_REPR_IOCTL_COMMAND)
__SYSCALL_REPR(SC_REPR_IOPRIO_ID)
__SYSCALL_REPR(SC_REPR_IOPRIO_VALUE)
__SYSCALL_REPR(SC_REPR_IOPRIO_WHO)
__SYSCALL_REPR(SC_REPR_ITIMER_WHICH)
__SYSCALL_REPR(SC_REPR_KCMP_TYPE)
__SYSCALL_REPR(SC_REPR_MEMFD_CREATE_FLAGS)
__SYSCALL_REPR(SC_REPR_MLOCKALL_FLAGS)
__SYSCALL_REPR(SC_REPR_MMAP_FLAGS)
__SYSCALL_REPR(SC_REPR_MMAP_PROT)
__SYSCALL_REPR(SC_REPR_MODE_T)
__SYSCALL_REPR(SC_REPR_MOUNT_FLAGS)
__SYSCALL_REPR(SC_REPR_MREMAP_FLAGS)
__SYSCALL_REPR(SC_REPR_OFLAG_T)
__SYSCALL_REPR(SC_REPR_OFLAG__CLOEXEC__CLOFORK)
__SYSCALL_REPR(SC_REPR_OFLAG__CLOEXEC__CLOFORK__NONBLOCK__DIRECT)
__SYSCALL_REPR(SC_REPR_PID_T)
__SYSCALL_REPR(SC_REPR_POINTER)
__SYSCALL_REPR(SC_REPR_REBOOT_HOW)
__SYSCALL_REPR(SC_REPR_RENAMEAT2_FLAGS)
__SYSCALL_REPR(SC_REPR_RLIMIT_RESOURCE)
__SYSCALL_REPR(SC_REPR_SCHED_POLICY)
__SYSCALL_REPR(SC_REPR_SCHED_PRIORITY_WHICH)
__SYSCALL_REPR(SC_REPR_SEEK_WHENCE)
__SYSCALL_REPR(SC_REPR_SIGHANDLER_T)
__SYSCALL_REPR(SC_REPR_SIGNALFD4_FLAGS)
__SYSCALL_REPR(SC_REPR_SIGNO_T)
__SYSCALL_REPR(SC_REPR_SIGPROCMASK_HOW)
__SYSCALL_REPR(SC_REPR_SIZE_T)
__SYSCALL_REPR(SC_REPR_SOCKET_DOMAIN)
__SYSCALL_REPR(SC_REPR_SOCKET_PROTOCOL)
__SYSCALL_REPR(SC_REPR_SOCKET_RECVMSG_FLAGS)
__SYSCALL_REPR(SC_REPR_SOCKET_RECVMSG_FLAGS2)
__SYSCALL_REPR(SC_REPR_SOCKET_RECVMSG_FLAGS3)
__SYSCALL_REPR(SC_REPR_SOCKET_SENDMSG_FLAGS)
__SYSCALL_REPR(SC_REPR_SOCKET_SHUTDOWN_HOW)
__SYSCALL_REPR(SC_REPR_SOCKET_TYPE)
__SYSCALL_REPR(SC_REPR_SOCKLEN_T)
__SYSCALL_REPR(SC_REPR_SOCKOPT_LEVEL)
__SYSCALL_REPR(SC_REPR_SOCKOPT_OPTNAME)
__SYSCALL_REPR(SC_REPR_SOCKOPT_OPTVAL)
__SYSCALL_REPR(SC_REPR_SPLICE_FLAGS)
__SYSCALL_REPR(SC_REPR_STRING)
__SYSCALL_REPR(SC_REPR_STRING_VECTOR)
__SYSCALL_REPR(SC_REPR_STRUCT_FDSET)
__SYSCALL_REPR(SC_REPR_STRUCT_FILE_HANDLE)
__SYSCALL_REPR(SC_REPR_STRUCT_FPUSTATE)
__SYSCALL_REPR(SC_REPR_STRUCT_IOVEC)
__SYSCALL_REPR(SC_REPR_STRUCT_IOVEC_C)
__SYSCALL_REPR(SC_REPR_STRUCT_ITIMERSPEC)
__SYSCALL_REPR(SC_REPR_STRUCT_ITIMERVAL)
__SYSCALL_REPR(SC_REPR_STRUCT_MMSGHDR)
__SYSCALL_REPR(SC_REPR_STRUCT_MQ_ATTR)
__SYSCALL_REPR(SC_REPR_STRUCT_MSGHDR)
__SYSCALL_REPR(SC_REPR_STRUCT_POLLFD)
__SYSCALL_REPR(SC_REPR_STRUCT_RLIMIT)
__SYSCALL_REPR(SC_REPR_STRUCT_RLIMIT64)
__SYSCALL_REPR(SC_REPR_STRUCT_RPC_SYSCALL_INFO)
__SYSCALL_REPR(SC_REPR_STRUCT_SCHED_PARAM)
__SYSCALL_REPR(SC_REPR_STRUCT_SIGACTION)
__SYSCALL_REPR(SC_REPR_STRUCT_SIGALTSTACK)
__SYSCALL_REPR(SC_REPR_STRUCT_SIGEVENT)
__SYSCALL_REPR(SC_REPR_STRUCT_SIGINFO)
__SYSCALL_REPR(SC_REPR_STRUCT_SIGMASK_SIGSET_AND_LEN)
__SYSCALL_REPR(SC_REPR_STRUCT_SIGSET)
__SYSCALL_REPR(SC_REPR_STRUCT_SOCKADDR)
__SYSCALL_REPR(SC_REPR_STRUCT_TIMESPEC)
__SYSCALL_REPR(SC_REPR_STRUCT_TIMESPEC_OR_UINT32)
__SYSCALL_REPR(SC_REPR_STRUCT_TIMESPEC_VEC2_OR_3)
__SYSCALL_REPR(SC_REPR_STRUCT_TIMEVAL)
__SYSCALL_REPR(SC_REPR_STRUCT_TIMEVAL_VEC2)
__SYSCALL_REPR(SC_REPR_STRUCT_TIMEZONE)
__SYSCALL_REPR(SC_REPR_STRUCT_UCPUSTATE)
__SYSCALL_REPR(SC_REPR_STRUCT_UTIMBUF)
__SYSCALL_REPR(SC_REPR_SWAPFLAGS)
__SYSCALL_REPR(SC_REPR_SYNC_FILE_RANGE_FLAGS)
__SYSCALL_REPR(SC_REPR_SYSCALL_SLONG_T)
__SYSCALL_REPR(SC_REPR_SYSCALL_ULONG_T)
__SYSCALL_REPR(SC_REPR_SYSLOG_LEVEL)
__SYSCALL_REPR(SC_REPR_TIMERFD_FLAGS)
__SYSCALL_REPR(SC_REPR_TIMERFD_TIMER_FLAGS)
__SYSCALL_REPR(SC_REPR_TIMER_FLAGS)
__SYSCALL_REPR(SC_REPR_TIMER_T)
__SYSCALL_REPR(SC_REPR_UID_T)
__SYSCALL_REPR(SC_REPR_UINT32_T)
__SYSCALL_REPR(SC_REPR_UINT64_T)
__SYSCALL_REPR(SC_REPR_WAITFLAG)
__SYSCALL_REPR(SC_REPR_WAITID_OPTIONS)
__SYSCALL_REPR(SC_REPR_XATTR_FLAGS)
#endif /* __WANT_SYSCALL_ARGUMENT_REPR_TYPES */

#ifdef __WANT_SYSCALL_RETURN_REPR_TYPES
__SYSCALL_REPR(SC_REPR_ERRNO_T)
__SYSCALL_REPR(SC_REPR_SSIZE_T)
__SYSCALL_REPR(SC_REPR_TIME_T)
#endif /* __WANT_SYSCALL_RETURN_REPR_TYPES */

#undef __SYSCALL_REPR

