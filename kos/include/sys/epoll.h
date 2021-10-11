/* HASH CRC-32:0x25ddf86 */
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
/* (#) Portability: GNU C Library (/sysdeps/unix/sysv/linux/sys/epoll.h) */
/* (#) Portability: diet libc     (/include/sys/epoll.h) */
/* (#) Portability: musl libc     (/include/sys/epoll.h) */
#ifndef _SYS_EPOLL_H
#define _SYS_EPOLL_H 1

#include <__stdinc.h>
#include <__crt.h>

#ifdef __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER
#pragma GCC system_header
#endif /* __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER */

#include <features.h>
#include <kos/anno.h>

#include <asm/os/epoll.h>
#include <bits/os/epoll.h>
#include <bits/os/sigset.h> /* struct __sigset_struct */
#include <bits/types.h>

#ifdef __USE_GLIBC
#include <sys/types.h>
#include <stdint.h>
#endif /* __USE_GLIBC */

__SYSDECL_BEGIN

/* Flags accepted by `epoll_create1(2)'. */
#if defined(__EPOLL_CLOEXEC) || defined(__EPOLL_CLOFORK)
/*[[[enum]]]*/
#ifdef __CC__
enum {
#ifdef __EPOLL_CLOEXEC
	EPOLL_CLOEXEC = __EPOLL_CLOEXEC, /* Set the IO_CLOEXEC flag */
#endif /* __EPOLL_CLOEXEC */
#ifdef __EPOLL_CLOFORK
	EPOLL_CLOFORK = __EPOLL_CLOFORK, /* Set the IO_CLOFORK flag */
#endif /* __EPOLL_CLOFORK */

};
#endif /* __CC__ */
/*[[[AUTO]]]*/
#ifdef __COMPILER_PREFERR_ENUMS
#ifdef __EPOLL_CLOEXEC
#define EPOLL_CLOEXEC EPOLL_CLOEXEC /* Set the IO_CLOEXEC flag */
#endif /* __EPOLL_CLOEXEC */
#ifdef __EPOLL_CLOFORK
#define EPOLL_CLOFORK EPOLL_CLOFORK /* Set the IO_CLOFORK flag */
#endif /* __EPOLL_CLOFORK */
#else /* __COMPILER_PREFERR_ENUMS */
#ifdef __EPOLL_CLOEXEC
#define EPOLL_CLOEXEC __EPOLL_CLOEXEC /* Set the IO_CLOEXEC flag */
#endif /* __EPOLL_CLOEXEC */
#ifdef __EPOLL_CLOFORK
#define EPOLL_CLOFORK __EPOLL_CLOFORK /* Set the IO_CLOFORK flag */
#endif /* __EPOLL_CLOFORK */
#endif /* !__COMPILER_PREFERR_ENUMS */
/*[[[end]]]*/
#endif /* __EPOLL_CLOEXEC || __EPOLL_CLOFORK */

/* EPOLL_EVENTS */
#if (defined(__EPOLLIN) || defined(__EPOLLPRI) ||        \
     defined(__EPOLLOUT) || defined(__EPOLLERR) ||       \
     defined(__EPOLLHUP) || defined(__EPOLLRDNORM) ||    \
     defined(__EPOLLRDBAND) || defined(__EPOLLWRNORM) || \
     defined(__EPOLLWRBAND) || defined(__EPOLLMSG) ||    \
     defined(__EPOLLRDHUP) || defined(__EPOLLWAKEUP) ||  \
     defined(__EPOLLONESHOT) || defined(__EPOLLET))
/*[[[enum]]]*/
#ifdef __CC__
enum EPOLL_EVENTS {
#ifdef __EPOLLIN
	EPOLLIN      = __EPOLLIN,      /* There is data to read. (`read' & friends won't block when invoked) */
#endif /* __EPOLLIN */
#ifdef __EPOLLPRI
	EPOLLPRI     = __EPOLLPRI,     /* There is urgent data to read. */
#endif /* __EPOLLPRI */
#ifdef __EPOLLOUT
	EPOLLOUT     = __EPOLLOUT,     /* Writing now will not block. (`write' & friends won't block when invoked) */
#endif /* __EPOLLOUT */
#ifdef __EPOLLRDNORM
	EPOLLRDNORM  = __EPOLLRDNORM,  /* 100% identical to `POLLIN' (Normal data may be read). */
#endif /* __EPOLLRDNORM */
#ifdef __EPOLLRDBAND
	EPOLLRDBAND  = __EPOLLRDBAND,  /* Priority data may be read. */
#endif /* __EPOLLRDBAND */
#ifdef __EPOLLWRNORM
	EPOLLWRNORM  = __EPOLLWRNORM,  /* 100% identical to `POLLOUT' (Writing now will not block). */
#endif /* __EPOLLWRNORM */
#ifdef __EPOLLWRBAND
	EPOLLWRBAND  = __EPOLLWRBAND,  /* Priority data may be written. */
#endif /* __EPOLLWRBAND */
#ifdef __EPOLLMSG
	EPOLLMSG     = __EPOLLMSG,     /* Documented as unused */
#endif /* __EPOLLMSG */
#ifdef __EPOLLRDHUP
	EPOLLRDHUP   = __EPOLLRDHUP,   /* Socket peer closed connection, or shut down writing half of its connection */
#endif /* __EPOLLRDHUP */
#ifdef __EPOLLWAKEUP
	EPOLLWAKEUP  = __EPOLLWAKEUP,  /* Currently ignored */
#endif /* __EPOLLWAKEUP */
#ifdef __EPOLLONESHOT
	EPOLLONESHOT = __EPOLLONESHOT, /* Automatically stop monitoring the file descriptor once it's condition is met. */
#endif /* __EPOLLONESHOT */
#ifdef __EPOLLET
	EPOLLET      = __EPOLLET,      /* Enable edge-triggered monitoring */
#endif /* __EPOLLET */
/* Event types always implicitly polled for. */
#ifdef __EPOLLERR
	EPOLLERR     = __EPOLLERR,     /* Error condition. */
#endif /* __EPOLLERR */
#ifdef __EPOLLHUP
	EPOLLHUP     = __EPOLLHUP,     /* Hung up. (writes are no longer possible) */
#endif /* __EPOLLHUP */
};
#endif /* __CC__ */
/*[[[AUTO]]]*/
#ifdef __COMPILER_PREFERR_ENUMS
#ifdef __EPOLLIN
#define EPOLLIN      EPOLLIN      /* There is data to read. (`read' & friends won't block when invoked) */
#endif /* __EPOLLIN */
#ifdef __EPOLLPRI
#define EPOLLPRI     EPOLLPRI     /* There is urgent data to read. */
#endif /* __EPOLLPRI */
#ifdef __EPOLLOUT
#define EPOLLOUT     EPOLLOUT     /* Writing now will not block. (`write' & friends won't block when invoked) */
#endif /* __EPOLLOUT */
#ifdef __EPOLLRDNORM
#define EPOLLRDNORM  EPOLLRDNORM  /* 100% identical to `POLLIN' (Normal data may be read). */
#endif /* __EPOLLRDNORM */
#ifdef __EPOLLRDBAND
#define EPOLLRDBAND  EPOLLRDBAND  /* Priority data may be read. */
#endif /* __EPOLLRDBAND */
#ifdef __EPOLLWRNORM
#define EPOLLWRNORM  EPOLLWRNORM  /* 100% identical to `POLLOUT' (Writing now will not block). */
#endif /* __EPOLLWRNORM */
#ifdef __EPOLLWRBAND
#define EPOLLWRBAND  EPOLLWRBAND  /* Priority data may be written. */
#endif /* __EPOLLWRBAND */
#ifdef __EPOLLMSG
#define EPOLLMSG     EPOLLMSG     /* Documented as unused */
#endif /* __EPOLLMSG */
#ifdef __EPOLLRDHUP
#define EPOLLRDHUP   EPOLLRDHUP   /* Socket peer closed connection, or shut down writing half of its connection */
#endif /* __EPOLLRDHUP */
#ifdef __EPOLLWAKEUP
#define EPOLLWAKEUP  EPOLLWAKEUP  /* Currently ignored */
#endif /* __EPOLLWAKEUP */
#ifdef __EPOLLONESHOT
#define EPOLLONESHOT EPOLLONESHOT /* Automatically stop monitoring the file descriptor once it's condition is met. */
#endif /* __EPOLLONESHOT */
#ifdef __EPOLLET
#define EPOLLET      EPOLLET      /* Enable edge-triggered monitoring */
#endif /* __EPOLLET */
/* Event types always implicitly polled for. */
#ifdef __EPOLLERR
#define EPOLLERR     EPOLLERR     /* Error condition. */
#endif /* __EPOLLERR */
#ifdef __EPOLLHUP
#define EPOLLHUP     EPOLLHUP     /* Hung up. (writes are no longer possible) */
#endif /* __EPOLLHUP */
#else /* __COMPILER_PREFERR_ENUMS */
#ifdef __EPOLLIN
#define EPOLLIN      __EPOLLIN      /* There is data to read. (`read' & friends won't block when invoked) */
#endif /* __EPOLLIN */
#ifdef __EPOLLPRI
#define EPOLLPRI     __EPOLLPRI     /* There is urgent data to read. */
#endif /* __EPOLLPRI */
#ifdef __EPOLLOUT
#define EPOLLOUT     __EPOLLOUT     /* Writing now will not block. (`write' & friends won't block when invoked) */
#endif /* __EPOLLOUT */
#ifdef __EPOLLRDNORM
#define EPOLLRDNORM  __EPOLLRDNORM  /* 100% identical to `POLLIN' (Normal data may be read). */
#endif /* __EPOLLRDNORM */
#ifdef __EPOLLRDBAND
#define EPOLLRDBAND  __EPOLLRDBAND  /* Priority data may be read. */
#endif /* __EPOLLRDBAND */
#ifdef __EPOLLWRNORM
#define EPOLLWRNORM  __EPOLLWRNORM  /* 100% identical to `POLLOUT' (Writing now will not block). */
#endif /* __EPOLLWRNORM */
#ifdef __EPOLLWRBAND
#define EPOLLWRBAND  __EPOLLWRBAND  /* Priority data may be written. */
#endif /* __EPOLLWRBAND */
#ifdef __EPOLLMSG
#define EPOLLMSG     __EPOLLMSG     /* Documented as unused */
#endif /* __EPOLLMSG */
#ifdef __EPOLLRDHUP
#define EPOLLRDHUP   __EPOLLRDHUP   /* Socket peer closed connection, or shut down writing half of its connection */
#endif /* __EPOLLRDHUP */
#ifdef __EPOLLWAKEUP
#define EPOLLWAKEUP  __EPOLLWAKEUP  /* Currently ignored */
#endif /* __EPOLLWAKEUP */
#ifdef __EPOLLONESHOT
#define EPOLLONESHOT __EPOLLONESHOT /* Automatically stop monitoring the file descriptor once it's condition is met. */
#endif /* __EPOLLONESHOT */
#ifdef __EPOLLET
#define EPOLLET      __EPOLLET      /* Enable edge-triggered monitoring */
#endif /* __EPOLLET */
/* Event types always implicitly polled for. */
#ifdef __EPOLLERR
#define EPOLLERR     __EPOLLERR     /* Error condition. */
#endif /* __EPOLLERR */
#ifdef __EPOLLHUP
#define EPOLLHUP     __EPOLLHUP     /* Hung up. (writes are no longer possible) */
#endif /* __EPOLLHUP */
#endif /* !__COMPILER_PREFERR_ENUMS */
/*[[[end]]]*/
#endif /* ... */

/* Command codes for the `op' argument of `epoll_ctl(2)'. */
#if (defined(__EPOLL_CTL_ADD) || defined(__EPOLL_CTL_DEL) || \
     defined(__EPOLL_CTL_MOD) || (defined(__USE_KOS_KERNEL) && defined(__EPOLL_CTL_RPC_PROG)))
/*[[[enum]]]*/
#ifdef __CC__
typedef enum __epoll_ctl {
#ifdef __EPOLL_CTL_ADD
	EPOLL_CTL_ADD = __EPOLL_CTL_ADD, /* Add a new file to-be monitored. */
#endif /* __EPOLL_CTL_ADD */
#ifdef __EPOLL_CTL_DEL
	EPOLL_CTL_DEL = __EPOLL_CTL_DEL, /* Stop monitoring a given file. */
#endif /* __EPOLL_CTL_DEL */
#ifdef __EPOLL_CTL_MOD
	EPOLL_CTL_MOD = __EPOLL_CTL_MOD, /* Change the `struct epoll_event' associated with a given file descriptor. */
#endif /* __EPOLL_CTL_MOD */
#if defined(__USE_KOS_KERNEL) && defined(__EPOLL_CTL_RPC_PROG)
	EPOLL_CTL_RPC_PROG = __EPOLL_CTL_RPC_PROG, /* Add  a file monitor that will deliver an RPC (~aka <kos/rpc.h>) once any of
	                                            * the monitored events are triggered  (iow: on the first raising-edge  event,
	                                            * or immediately if any event is already asserted). This mechanism allows for
	                                            * asynchronous  notification of any pollable file event by means of injecting
	                                            * custom callbacks into arbitrary threads/processes.
	                                            *
	                                            * Monitors created by this command cannot be modified by `EPOLL_CTL_MOD', but
	                                            * can be deleted (read: canceled)  by `EPOLL_CTL_DEL'. When canceled in  this
	                                            * manner, a successful monitor deletion  implies that the RPC program  didn't
	                                            * get invoked.
	                                            *
	                                            * When this command is used,  `event->events' should be filled as  normal
	                                            * with the mask of events  to monitor. However, `event->data' must  first
	                                            * be zero- initialized,  before `event->data.ptr' must  be made to  point
	                                            * at a `struct epoll_rpc_program' which contains RPC-related information. */
#endif /* __USE_KOS_KERNEL && __EPOLL_CTL_RPC_PROG */
} __epoll_ctl_t;
#endif /* __CC__ */
/*[[[AUTO]]]*/
#ifdef __COMPILER_PREFERR_ENUMS
#ifdef __EPOLL_CTL_ADD
#define EPOLL_CTL_ADD      EPOLL_CTL_ADD      /* Add a new file to-be monitored. */
#endif /* __EPOLL_CTL_ADD */
#ifdef __EPOLL_CTL_DEL
#define EPOLL_CTL_DEL      EPOLL_CTL_DEL      /* Stop monitoring a given file. */
#endif /* __EPOLL_CTL_DEL */
#ifdef __EPOLL_CTL_MOD
#define EPOLL_CTL_MOD      EPOLL_CTL_MOD      /* Change the `struct epoll_event' associated with a given file descriptor. */
#endif /* __EPOLL_CTL_MOD */
#if defined(__USE_KOS_KERNEL) && defined(__EPOLL_CTL_RPC_PROG)
#define EPOLL_CTL_RPC_PROG EPOLL_CTL_RPC_PROG /* Add  a file monitor that will deliver an RPC (~aka <kos/rpc.h>) once any of
                                               * the monitored events are triggered  (iow: on the first raising-edge  event,
                                               * or immediately if any event is already asserted). This mechanism allows for
                                               * asynchronous  notification of any pollable file event by means of injecting
                                               * custom callbacks into arbitrary threads/processes.
                                               *
                                               * Monitors created by this command cannot be modified by `EPOLL_CTL_MOD', but
                                               * can be deleted (read: canceled)  by `EPOLL_CTL_DEL'. When canceled in  this
                                               * manner, a successful monitor deletion  implies that the RPC program  didn't
                                               * get invoked.
                                               *
                                               * When this command is used,  `event->events' should be filled as  normal
                                               * with the mask of events  to monitor. However, `event->data' must  first
                                               * be zero- initialized,  before `event->data.ptr' must  be made to  point
                                               * at a `struct epoll_rpc_program' which contains RPC-related information. */
#endif /* __USE_KOS_KERNEL && __EPOLL_CTL_RPC_PROG */
#else /* __COMPILER_PREFERR_ENUMS */
#ifdef __EPOLL_CTL_ADD
#define EPOLL_CTL_ADD      __EPOLL_CTL_ADD      /* Add a new file to-be monitored. */
#endif /* __EPOLL_CTL_ADD */
#ifdef __EPOLL_CTL_DEL
#define EPOLL_CTL_DEL      __EPOLL_CTL_DEL      /* Stop monitoring a given file. */
#endif /* __EPOLL_CTL_DEL */
#ifdef __EPOLL_CTL_MOD
#define EPOLL_CTL_MOD      __EPOLL_CTL_MOD      /* Change the `struct epoll_event' associated with a given file descriptor. */
#endif /* __EPOLL_CTL_MOD */
#if defined(__USE_KOS_KERNEL) && defined(__EPOLL_CTL_RPC_PROG)
#define EPOLL_CTL_RPC_PROG __EPOLL_CTL_RPC_PROG /* Add  a file monitor that will deliver an RPC (~aka <kos/rpc.h>) once any of
                                                 * the monitored events are triggered  (iow: on the first raising-edge  event,
                                                 * or immediately if any event is already asserted). This mechanism allows for
                                                 * asynchronous  notification of any pollable file event by means of injecting
                                                 * custom callbacks into arbitrary threads/processes.
                                                 *
                                                 * Monitors created by this command cannot be modified by `EPOLL_CTL_MOD', but
                                                 * can be deleted (read: canceled)  by `EPOLL_CTL_DEL'. When canceled in  this
                                                 * manner, a successful monitor deletion  implies that the RPC program  didn't
                                                 * get invoked.
                                                 *
                                                 * When this command is used,  `event->events' should be filled as  normal
                                                 * with the mask of events  to monitor. However, `event->data' must  first
                                                 * be zero- initialized,  before `event->data.ptr' must  be made to  point
                                                 * at a `struct epoll_rpc_program' which contains RPC-related information. */
#endif /* __USE_KOS_KERNEL && __EPOLL_CTL_RPC_PROG */
#endif /* !__COMPILER_PREFERR_ENUMS */
/*[[[end]]]*/
#elif defined(__CC__)
typedef int __epoll_ctl_t;
#endif /* ... */

#ifdef __CC__

typedef union epoll_data epoll_data_t;

#ifndef __sigset_t_defined
#define __sigset_t_defined
typedef struct __sigset_struct sigset_t;
#endif /* !__sigset_t_defined */

/*
 * PORTABILITY NOTES:
 *
 * The KOS implementation of epoll somewhat differs from the one provided by linux:
 *   >> epfd   = epoll_create();
 *   >> somefd = get_some_fd();
 *   >> epoll_ctl(epfd, EPOLL_CTL_MOD, somefd, { ... });
 *   >> close(somefd);
 *   Linux behavior:
 *    - `somefd' is automatically removed from `epfd'
 *   KOS behavior:
 *    - `somefd'  may  or  may  not   be  automatically  removed  from   `epfd'.
 *      The  actual internal behavior  depends on how  epfd stores its reference
 *      to `somefd'. For this, the KOS kernel has 2 cases: 1 where `epfd' stores
 *      a normal, full  reference to `somefd',  and one where  it stores a  weak
 *      reference (such that  closing and destroying  `somefd' is not  prevented
 *      from doing so by being apart of an epoll fd-set)
 *    - Which of  these 2  behaviors is  used  depends on  the internal  handle  type
 *      associated with `somefd' (one of `HANDLE_TYPE_*' from <kos/kernel/handle.h>),
 *      though  when  which behavior  is  used is  an  implementation detail  that is
 *      subject to change over time.
 *   Recommended behavior for maximum portability:
 *    - As linux documentation  already suggests, relying  on the  auto-removal
 *      behavior  of closing monitored  files isn't something  that ever has to
 *      be used and more often than not only introduces unnecessary complexity.
 *      Furthermore,  often this behavior  can't even be  done reliably since a
 *      monitored handled may get duplicated by any number of events (including
 *      fork(2) calls  made by  other threads).  As such,  explicitly  removing
 *      handles from the  associated epoll  descriptor is always  a good  idea.
 *
 */


/* >> epoll_create(2)
 * Deprecated alias for `epoll_create1(0)' (the `size' argument is ignored)
 * @return: * : The newly created epoll control descriptor.
 * @return: -1: Error (s.a. `errno') */
__CDECLARE_OPT(__ATTR_WUNUSED,__fd_t,__NOTHROW_NCX,epoll_create,(__STDC_INT_AS_SIZE_T __size),(__size))
/* >> epoll_create1(2)
 * Create  a new epoll control descriptor which can be used for
 * monitoring of pollable events happening in registered files.
 * @param: flags: Set of `EPOLL_CLOEXEC | EPOLL_CLOFORK'
 * @return: * :   The newly created epoll control descriptor.
 * @return: -1:   Error (s.a. `errno')
 * @throw: E_INVALID_ARGUMENT_UNKNOWN_FLAG:E_INVALID_ARGUMENT_CONTEXT_EPOLL_CREATE1_FLAGS: [...] */
__CDECLARE_OPT(__ATTR_WUNUSED,__fd_t,__NOTHROW_NCX,epoll_create1,(__STDC_INT_AS_UINT_T __flags),(__flags))
/* >> epoll_ctl(2)
 * Manipulate a given  epoll controller  `epfd', as previously  returned by  `epoll_create1(2)'
 * in order to register (`EPOLL_CTL_ADD'), remove (`EPOLL_CTL_DEL') or modify (`EPOLL_CTL_MOD')
 * the file descriptors being monitored
 * @param: op:    One of `EPOLL_CTL_ADD', `EPOLL_CTL_DEL' or `EPOLL_CTL_MOD'
 * @param: fd:    The file descriptor to add/remove/modify
 * @param: event: The new configuration for `fd' (ignored when `op' is `EPOLL_CTL_DEL')
 * @return: 0 :   Success
 * @return: -1:   [errno=EEXIST][op=EPOLL_CTL_ADD] The given `fd' (and its kernel object) has already been registered
 * @return: -1:   [errno=ENOENT][op=EPOLL_CTL_MOD|EPOLL_CTL_DEL] The given `fd' (and its kernel object) aren't registered
 * @return: -1:   Error (s.a. `errno')
 * @throw: E_ILLEGAL_REFERENCE_LOOP: The  given  `fd'  is  another  epoll  that either
 *                                   forms a loop with `epfd', or has too many nested.
 * @throw: E_INVALID_ARGUMENT_UNKNOWN_COMMAND:E_INVALID_ARGUMENT_CONTEXT_EPOLL_CTL_OP: [...] */
__CDECLARE_OPT(,int,__NOTHROW_NCX,epoll_ctl,(__fd_t __epfd, __epoll_ctl_t __op, __fd_t __fd, struct epoll_event *__event),(__epfd,__op,__fd,__event))
/* >> epoll_wait(2)
 * Wait until at least one of the conditions monitored by `epfd' to be met.
 * @param: epfd:      The epoll controller on which to wait.
 * @param: events:    A buffer where the kernel can store information on the
 *                    events that actually took place.
 * @param: maxevents: The # of events that can be stored in `events' (must be >= 1)
 * @param: timeout:   The max amount of time (in milliseconds) before  returning
 *                    in the case where no event occurred in the mean time. When
 *                    set to `-1', wait indefinitely
 * @return: >= 1:     The # of events that happened (written to the first `return'
 *                    items of `events')
 * @return: 0:        No events happened before `timeout' expired.
 * @return: -1:       Error (s.a. `errno') */
__CDECLARE_OPT(__ATTR_NONNULL((2)),__STDC_INT_AS_SSIZE_T,__NOTHROW_RPC,epoll_wait,(__fd_t __epfd, struct epoll_event *__events, __STDC_INT_AS_SIZE_T __maxevents, int __timeout),(__epfd,__events,__maxevents,__timeout))
/* >> epoll_pwait(2)
 * Same as `epoll_wait(2)', but change the calling thread's signal mask to `ss' while
 * waiting.  Wait until at least one of the conditions monitored by `epfd' to be met.
 * @param: epfd:      The epoll controller on which to wait.
 * @param: events:    A buffer where the kernel can store information on the
 *                    events that actually took place.
 * @param: maxevents: The # of events that can be stored in `events' (must be >= 1)
 * @param: timeout:   The max amount of time (in milliseconds) before  returning
 *                    in the case where no event occurred in the mean time. When
 *                    set to `-1', wait indefinitely
 * @param: ss:        The signal mask to apply while waiting for an event to happen.
 * @return: >= 1:     The # of events that happened (written to the first `return'
 *                    items of `events')
 * @return: 0:        No events happened before `timeout' expired.
 * @return: -1:       Error (s.a. `errno') */
__CDECLARE_OPT(__ATTR_NONNULL((2)),__STDC_INT_AS_SSIZE_T,__NOTHROW_RPC,epoll_pwait,(__fd_t __epfd, struct epoll_event *__events, __STDC_INT_AS_SIZE_T __maxevents, int __timeout, sigset_t const *__ss),(__epfd,__events,__maxevents,__timeout,__ss))

#ifdef __USE_KOS
#ifndef __prpc_exec_callback_t_defined
#define __prpc_exec_callback_t_defined
#ifndef PRPC_EXEC_CALLBACK_CC
#ifdef __KERNEL__
typedef struct icpustate rpc_cpustate_t;
#define PRPC_EXEC_CALLBACK_CC __FCALL
#else /* __KERNEL__ */
typedef struct ucpustate rpc_cpustate_t;
#define PRPC_EXEC_CALLBACK_CC __LIBKCALL
#endif /* !__KERNEL__ */
#endif /* !PRPC_EXEC_CALLBACK_CC */
struct rpc_context;
typedef __ATTR_NONNULL((1)) void
(PRPC_EXEC_CALLBACK_CC *prpc_exec_callback_t)(struct rpc_context *__restrict __ctx, void *__cookie)
		__THROWS(...);
#endif /* !__prpc_exec_callback_t_defined */
/* >> epoll_rpc_exec(3)
 * Helper wrapper for  `EPOLL_CTL_RPC_PROG' that  automatically provides  the
 * necessary arch-specific RPC program to invoke `func(..., event->data.ptr)'
 * as  soon as any of `event->events' become  raised in `fd'. The monitor for
 * this  is associated with `epfd' and the  RPC (if not already delieved) can
 * be cancled by `epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL)'. Not that as soon
 * as  the RPC is  send, the associated monitor  will have automatically been
 * deleted.
 *
 * This function can be used to allow for implement asynchronous notification
 * of file events to be delivered to arbitrary threads. Using this, you could
 * implement  asynchronous, non-blocking I/O by sending RPCs to an I/O worker
 * thread that will perform reads/writes as soon as they become possible.
 * @param: epfd:       Epoll controller file descriptor
 * @param: fd:         The file to monitor for events
 * @param: event:      Epoll event information, including monitored  events,
 *                     and the cookie argument that will be passed to `func'
 * @param: target_tid: The TID of the targeted thread
 * @param: mode:       One of  `RPC_SYNCMODE_*', optionally or'd  with
 *                     one of `RPC_SYSRESTART_*', optionally or'd with
 *                     one of `RPC_DOMAIN_*'
 * @param: func:       The function executed by the RPC
 * @return: 0 :                Success
 * @return: -1: [errno=ESRCH]  The  target  thread has  already  terminated, or
 *                             doesn't exist. Note  though that  if the  target
 *                             thread  exits prior to  any monitored file event
 *                             happening, the epoll  monitor will still  remain
 *                             intact, and the  RPC will be  discarded as  soon
 *                             as an attempt to send it is made, or the monitor
 *                             is manually deleted via `EPOLL_CTL_DEL' */
__CDECLARE_OPT(__ATTR_NONNULL((3, 6)),int,__NOTHROW_NCX,epoll_rpc_exec,(__fd_t __epfd, __fd_t __fd, struct epoll_event *__event, __pid_t __target_tid, unsigned int __mode, prpc_exec_callback_t __func),(__epfd,__fd,__event,__target_tid,__mode,__func))
#endif /* __USE_KOS */
#endif /* __CC__ */

__SYSDECL_END

#endif /* !_SYS_EPOLL_H */
