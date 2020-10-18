/* HASH CRC-32:0x3cab2a25 */
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
#ifndef _SYS_EPOLL_H
#define _SYS_EPOLL_H 1

#include <__stdinc.h>
#include <__crt.h>

#ifdef __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER
#pragma GCC system_header
#endif /* __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER */

#include <features.h>

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
#ifdef __EPOLL_CLOEXEC
/*[[[enum]]]*/
#ifdef __CC__
enum {
	EPOLL_CLOEXEC = __EPOLL_CLOEXEC /* Set the IO_CLOEXEC flag */
};
#endif /* __CC__ */
/*[[[AUTO]]]*/
#ifdef __COMPILER_PREFERR_ENUMS
#define EPOLL_CLOEXEC EPOLL_CLOEXEC /* Set the IO_CLOEXEC flag */
#else /* __COMPILER_PREFERR_ENUMS */
#define EPOLL_CLOEXEC __EPOLL_CLOEXEC /* Set the IO_CLOEXEC flag */
#endif /* !__COMPILER_PREFERR_ENUMS */
/*[[[end]]]*/
#endif /* __EPOLL_CLOEXEC */

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
	EPOLLET      = __EPOLLET,      /* Enable edge-triggered monitoring (not supported on KOS) */
#endif /* __EPOLLET */
/* Event types always implicitly polled for. */
#ifdef __EPOLLERR
	EPOLLERR     = __EPOLLERR, /* Error condition. */
#endif /* __EPOLLERR */
#ifdef __EPOLLHUP
	EPOLLHUP     = __EPOLLHUP, /* Hung up. (writes are no longer possible) */
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
#define EPOLLET      EPOLLET      /* Enable edge-triggered monitoring (not supported on KOS) */
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
#define EPOLLET      __EPOLLET      /* Enable edge-triggered monitoring (not supported on KOS) */
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
     defined(__EPOLL_CTL_MOD))
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
	EPOLL_CTL_MOD = __EPOLL_CTL_MOD  /* Change the `struct epoll_event' associated with a given file descriptor. */
#endif /* __EPOLL_CTL_MOD */
} __epoll_ctl_t;
#endif /* __CC__ */
/*[[[AUTO]]]*/
#ifdef __COMPILER_PREFERR_ENUMS
#ifdef __EPOLL_CTL_ADD
#define EPOLL_CTL_ADD EPOLL_CTL_ADD /* Add a new file to-be monitored. */
#endif /* __EPOLL_CTL_ADD */
#ifdef __EPOLL_CTL_DEL
#define EPOLL_CTL_DEL EPOLL_CTL_DEL /* Stop monitoring a given file. */
#endif /* __EPOLL_CTL_DEL */
#ifdef __EPOLL_CTL_MOD
#define EPOLL_CTL_MOD EPOLL_CTL_MOD /* Change the `struct epoll_event' associated with a given file descriptor. */
#endif /* __EPOLL_CTL_MOD */
#else /* __COMPILER_PREFERR_ENUMS */
#ifdef __EPOLL_CTL_ADD
#define EPOLL_CTL_ADD __EPOLL_CTL_ADD /* Add a new file to-be monitored. */
#endif /* __EPOLL_CTL_ADD */
#ifdef __EPOLL_CTL_DEL
#define EPOLL_CTL_DEL __EPOLL_CTL_DEL /* Stop monitoring a given file. */
#endif /* __EPOLL_CTL_DEL */
#ifdef __EPOLL_CTL_MOD
#define EPOLL_CTL_MOD __EPOLL_CTL_MOD /* Change the `struct epoll_event' associated with a given file descriptor. */
#endif /* __EPOLL_CTL_MOD */
#endif /* !__COMPILER_PREFERR_ENUMS */
/*[[[end]]]*/
#elif defined(__CC__)
typedef int __epoll_ctl_t;
#endif /* ... */

#ifdef __CC__

typedef union epoll_data epoll_data_t;

#ifndef __sigset_t_defined
#define __sigset_t_defined 1
typedef struct __sigset_struct sigset_t;
#endif /* !__sigset_t_defined */

/* >> epoll_create(2)
 * Deprecated alias for `epoll_create1(0)' (the `size' argument is ignored)
 * @return: * : The newly created epoll control descriptor.
 * @return: -1: Error (s.a. `errno') */
__CDECLARE_OPT(__ATTR_WUNUSED,__fd_t,__NOTHROW_NCX,epoll_create,(__STDC_INT_AS_SIZE_T __size),(__size))
/* >> epoll_create1(2)
 * Create a new epoll control descriptor which can be used for
 * monitoring of pollable events happening in registered files.
 * @param: flags: Set of `EPOLL_*'
 * @return: * :   The newly created epoll control descriptor.
 * @return: -1:   [errno=EINVAL] Invalid `flags'
 * @return: -1:   Error (s.a. `errno') */
__CDECLARE_OPT(__ATTR_WUNUSED,__fd_t,__NOTHROW_NCX,epoll_create1,(__STDC_INT_AS_UINT_T __flags),(__flags))
/* >> epoll_ctl(2)
 * Manipulate a given epoll controller `epfd', as previously returned by `epoll_create1(2)'
 * in order to register (`EPOLL_CTL_ADD'), remove (`EPOLL_CTL_DEL') or modify (`EPOLL_CTL_MOD')
 * the file descriptors being monitored
 * @param: op:    One of `EPOLL_CTL_ADD', `EPOLL_CTL_DEL' or `EPOLL_CTL_MOD'
 * @param: fd:    The file descriptor to add/remove/modify
 * @param: event: The new configuration for `fd' (ignored when `op' is `EPOLL_CTL_DEL')
 * @return: 0 :   Success
 * @return: -1:   Error (s.a. `errno') */
__CDECLARE_OPT(,int,__NOTHROW_NCX,epoll_ctl,(__fd_t __epfd, __epoll_ctl_t __op, __fd_t __fd, struct epoll_event *__event),(__epfd,__op,__fd,__event))
/* >> epoll_wait(2)
 * Wait until at least one of the conditions monitored by `epfd' to be met.
 * @param: epfd:      The epoll controller on which to wait.
 * @param: events:    A buffer where the kernel can store information on the
 *                    events that actually took place.
 * @param: maxevents: The # of events that can be stored in `events' (must be >= 1)
 * @param: timeout:   The max amount of time (in milliseconds) before returning
 *                    in the case where no event occurred in the mean time. When
 *                    set to `-1', wait indefinitely
 * @return: >= 1:     The # of events that happened (written to the first `return'
 *                    items of `events')
 * @return: 0:        No events happened before `timeout' expired.
 * @return: -1:       Error (s.a. `errno') */
__CDECLARE_OPT(__ATTR_NONNULL((2)),__STDC_INT_AS_SSIZE_T,__NOTHROW_RPC,epoll_wait,(__fd_t __epfd, struct epoll_event *__events, __STDC_INT_AS_SIZE_T __maxevents, int __timeout),(__epfd,__events,__maxevents,__timeout))
/* >> epoll_pwait(2)
 * Same as `epoll_wait(2)', but change the calling thread's signal mask to `ss' while
 * waiting. Wait until at least one of the conditions monitored by `epfd' to be met.
 * @param: epfd:      The epoll controller on which to wait.
 * @param: events:    A buffer where the kernel can store information on the
 *                    events that actually took place.
 * @param: maxevents: The # of events that can be stored in `events' (must be >= 1)
 * @param: timeout:   The max amount of time (in milliseconds) before returning
 *                    in the case where no event occurred in the mean time. When
 *                    set to `-1', wait indefinitely
 * @param: ss:        The signal mask to apply while waiting for an event to happen.
 * @return: >= 1:     The # of events that happened (written to the first `return'
 *                    items of `events')
 * @return: 0:        No events happened before `timeout' expired.
 * @return: -1:       Error (s.a. `errno') */
__CDECLARE_OPT(__ATTR_NONNULL((2)),__STDC_INT_AS_SSIZE_T,__NOTHROW_RPC,epoll_pwait,(__fd_t __epfd, struct epoll_event *__events, __STDC_INT_AS_SIZE_T __maxevents, int __timeout, sigset_t const *__ss),(__epfd,__events,__maxevents,__timeout,__ss))
#endif /* __CC__ */

__SYSDECL_END

#endif /* !_SYS_EPOLL_H */
