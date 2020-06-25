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

%[define_ccompat_header("csignal")]
%[define_replacement(longptr_t    = __LONGPTR_TYPE__)]
%[define_replacement(ulongptr_t   = __ULONGPTR_TYPE__)]
%[define_replacement(sighandler_t = __sighandler_t)]
%[define_replacement(siginfo_t    = "struct __siginfo_struct")]
%[define_replacement(sigset_t     = "struct __sigset_struct")]
%[define_replacement(pid_t        = __pid_t)]
%[define_replacement(timespec32   = __timespec32)]
%[define_replacement(sig_atomic_t = __sig_atomic_t)]
%[define_replacement(sig_t        = __sighandler_t)]
%[define_replacement(timespec64   = __timespec64)]
%[define_type_class(__sighandler_t = "TP")]
%[default:section(".text.crt{|.dos}.sched.signal")]

%(auto_header,user){
DECL_END
#include <bits/sigaction.h>
#include <pthread.h>
DECL_BEGIN

#ifndef __sighandler_t_defined
#define __sighandler_t_defined 1
typedef __sighandler_t sighandler_t;
#endif /* !__sighandler_t_defined */

}

%{
#include <features.h>
#include <bits/types.h>
#include <bits/signum.h>
#include <bits/sigset.h>

#ifdef __USE_POSIX199309
#include <bits/timespec.h>
#endif /* __USE_POSIX199309 */

#if defined(__USE_POSIX199309) || defined(__USE_XOPEN_EXTENDED) || defined(__USE_KOS)
#include <bits/siginfo.h>
#endif /* __USE_POSIX199309 || __USE_XOPEN_EXTENDED || __USE_KOS */

#ifdef __USE_POSIX
#include <bits/sigaction.h>
#endif /* __USE_POSIX */

#ifdef __USE_MISC
#include <bits/sigcontext.h>
#endif /* __USE_MISC */

#if defined(__USE_XOPEN_EXTENDED) || defined(__USE_XOPEN2K8)
#include <bits/sigstack.h>
#if defined(__USE_XOPEN) || defined(__USE_XOPEN2K8)
#include <sys/ucontext.h>
#endif /* __USE_XOPEN || __USE_XOPEN2K8 */
#endif /* __USE_XOPEN_EXTENDED || __USE_XOPEN2K8 */

#if defined(__USE_POSIX199506) || defined(__USE_UNIX98)
#include <bits/crt/pthreadtypes.h>
#include <bits/sigval.h> /* union sigval */
#endif /* __USE_POSIX199506 || __USE_UNIX98 */

__SYSDECL_BEGIN

#ifdef __CC__

#ifndef __std_sig_atomic_t_defined
#define __std_sig_atomic_t_defined 1
__NAMESPACE_STD_BEGIN
/* An integral type that can be modified atomically, without the
 * possibility of a signal arriving in the middle of the operation.  */
typedef __sig_atomic_t sig_atomic_t;
__NAMESPACE_STD_END
#endif /* !__std_sig_atomic_t_defined */
#ifndef __CXX_SYSTEM_HEADER
}%(c, ccompat){
#ifndef __sig_atomic_t_defined
#define __sig_atomic_t_defined 1
__NAMESPACE_STD_USING(sig_atomic_t)
#endif /* !__sig_atomic_t_defined */
}%{
#endif /* !__CXX_SYSTEM_HEADER */

#ifdef __USE_POSIX
#ifndef __sigset_t_defined
#define __sigset_t_defined 1
typedef __sigset_t sigset_t;
#endif /* !__sigset_t_defined */
#endif /* __USE_POSIX */

#if defined(__USE_XOPEN) || defined(__USE_XOPEN2K)
#ifndef __pid_t_defined
#define __pid_t_defined 1
typedef __pid_t pid_t;
#endif /* !__pid_t_defined */
#ifndef __uid_t_defined
#define __uid_t_defined 1
typedef __uid_t uid_t;
#endif /* !__uid_t_defined */
#endif /* __USE_XOPEN || __USE_XOPEN2K */

#ifndef ____sighandler_t_defined
#define ____sighandler_t_defined 1
typedef void (__LIBCCALL *__sighandler_t)(int __signo);
#endif /* !____sighandler_t_defined */

#ifdef __USE_GNU
#ifndef __sighandler_t_defined
#define __sighandler_t_defined 1
typedef __sighandler_t sighandler_t;
#endif /* !__sighandler_t_defined */
#endif /* __USE_GNU */

#ifdef __USE_MISC
#ifndef NSIG
#define NSIG    _NSIG
#endif /* !NSIG */
typedef __sighandler_t sig_t;
#endif /* __USE_MISC */

}%(c, ccompat){
#if defined(__USE_XOPEN_EXTENDED) || defined(__USE_XOPEN2K8)
}%{
#ifndef __std_size_t_defined
#define __std_size_t_defined 1
__NAMESPACE_STD_BEGIN
typedef __SIZE_TYPE__ size_t;
__NAMESPACE_STD_END
#endif /* !__std_size_t_defined */

#ifndef __CXX_SYSTEM_HEADER
}%(c, ccompat){
#ifndef __size_t_defined
#define __size_t_defined 1
__NAMESPACE_STD_USING(size_t)
#endif /* !__size_t_defined */
}%{
#endif /* !__CXX_SYSTEM_HEADER */
}%(c, ccompat){
#endif /* __USE_XOPEN_EXTENDED || __USE_XOPEN2K8 */
}%{

}

%[insert:std]

[[std, crt_dos_variant, decl_include("<bits/types.h>")]]
int raise($signo_t signo);

%[insert:function(__sysv_signal = sysv_signal)]

%#ifdef __USE_GNU
[[decl_include("<bits/types.h>", "<bits/sigaction.h>")]]
[[export_alias("__sysv_signal"), crt_dos_variant]]
$sighandler_t sysv_signal($signo_t signo, $sighandler_t handler);
%#endif /* __USE_GNU */


[[std, no_crt_self_import, crt_dos_variant]]
[[if(defined(__USE_MISC)), preferred_alias("signal", "_signal")]]
[[alias("sysv_signal"), dos_export_as("DOS$_signal")]]
[[decl_include("<bits/types.h>", "<bits/sigaction.h>")]]
$sighandler_t signal($signo_t signo, $sighandler_t handler);

%#ifdef __USE_MISC
%#define sigmask(signo) __sigmask(signo)

[[decl_include("<bits/types.h>", "<bits/sigaction.h>"), crt_dos_variant]]
$sighandler_t ssignal($signo_t signo, $sighandler_t handler);

[[decl_include("<bits/types.h>"), crt_dos_variant]]
int gsignal($signo_t signo);

/*[[deprecated("Using `sigprocmask()' instead")]]*/ int sigblock(int mask);
/*[[deprecated("Using `sigprocmask()' instead")]]*/ int sigsetmask(int mask);
/*[[deprecated("Using `sigprocmask()' instead")]]*/ int siggetmask(void);


%
%{
#ifndef sys_siglist
#ifdef _sys_siglist
#define sys_siglist _sys_siglist
#else /* _sys_siglist */
}
[[guard, nothrow, wunused, ATTR_CONST, nonnull]]
char const *const *__p_sys_siglist();
%{
#ifdef ____p_sys_siglist_defined
#define sys_siglist  __p_sys_siglist()
#define _sys_siglist __p_sys_siglist()
#endif /* ____p_sys_siglist_defined */
#ifndef _sys_siglist
#ifdef __CRT_HAVE_sys_siglist
__LIBC char const *const sys_siglist[_NSIG];
#define sys_siglist  sys_siglist
#define _sys_siglist sys_siglist
#elif defined(__CRT_HAVE__sys_siglist)
__LIBC char const *const _sys_siglist[_NSIG];
#define sys_siglist  _sys_siglist
#define _sys_siglist _sys_siglist
#endif /* sys_siglist... */
#endif /* !_sys_siglist */
#endif /* !_sys_siglist */
#endif /* !sys_siglist */

#if !defined(_sys_siglist) && defined(sys_siglist)
#define _sys_siglist sys_siglist
#endif /* !_sys_siglist && sys_siglist */
}

%struct sigcontext;
[[ATTR_NORETURN, decl_prefix(struct sigcontext;)]]
void sigreturn(struct sigcontext const *scp);

%#endif /* __USE_MISC */
%
%#ifdef __USE_XOPEN

[[decl_include("<bits/types.h>", "<bits/sigaction.h>"), crt_dos_variant]]
$sighandler_t bsd_signal($signo_t signo, $sighandler_t handler);

[[crt_name("__xpg_sigpause")]]
[[decl_include("<bits/types.h>")]]
int sigpause($signo_t signo);

%#endif /* __USE_XOPEN */
%
%#ifdef __USE_POSIX

[[decl_include("<bits/types.h>")]]
int kill($pid_t pid, $signo_t signo);

[[decl_include("<bits/sigset.h>")]]
int sigemptyset([[nonnull]] sigset_t *set) {
	size_t cnt;
	cnt = sizeof(__sigset_t) / sizeof(ulongptr_t);
	while (cnt--)
		set->@__val@[cnt] = 0;
	return 0;
}

[[decl_include("<bits/sigset.h>")]]
int sigfillset([[nonnull]] sigset_t *set) {
	size_t cnt;
	cnt = sizeof(__sigset_t) / sizeof(ulongptr_t);
	while (cnt--)
		set->@__val@[cnt] = ~(ulongptr_t)0;
	return 0;
}

[[decl_include("<bits/types.h>", "<bits/sigset.h>"), export_alias("__sigaddset")]]
int sigaddset([[nonnull]] sigset_t *set, $signo_t signo) {
	ulongptr_t mask = @__sigmask@(signo);
	ulongptr_t word = @__sigword@(signo);
	set->@__val@[word] |= mask;
	return 0;
}

[[decl_include("<bits/types.h>", "<bits/sigset.h>"), export_alias("__sigdelset")]]
int sigdelset([[nonnull]] sigset_t *set, $signo_t signo) {
	ulongptr_t mask = @__sigmask@(signo);
	ulongptr_t word = @__sigword@(signo);
	set->@__val@[word] &= ~mask;
	return 0;
}

[[wunused, ATTR_PURE, export_alias("__sigismember")]]
[[decl_include("<bits/types.h>", "<bits/sigset.h>")]]
int sigismember([[nonnull]] sigset_t const *set, $signo_t signo) {
	ulongptr_t mask = @__sigmask@(signo);
	ulongptr_t word = @__sigword@(signo);
	return (set->@__val@[word] & mask) != 0;
}

@@@param how: One of `SIG_BLOCK', `SIG_UNBLOCK' or `SIG_SETMASK'
[[decl_include("<features.h>")]]
int sigprocmask(__STDC_INT_AS_UINT_T how, sigset_t const *set, sigset_t *oset);

[[cp, export_alias("__sigsuspend")]]
int sigsuspend([[nonnull]] sigset_t const *set);

[[decl_include("<bits/types.h>")]]
[[export_alias("__sigaction"), decl_prefix(struct sigaction;)]]
int sigaction($signo_t signo, struct sigaction const *act, struct sigaction *oact);

int sigpending([[nonnull]] sigset_t *__restrict set);

[[cp, decl_include("<bits/types.h>")]]
int sigwait([[nonnull]] sigset_t const *__restrict set,
            [[nonnull]] $signo_t *__restrict signo);

%#ifdef __USE_GNU
[[wunused, ATTR_PURE, decl_include("<bits/sigset.h>")]]
int sigisemptyset([[nonnull]] sigset_t const *__restrict set) {
	size_t i;
	for (i = 0; i < sizeof(sigset_t) / sizeof(ulongptr_t); ++i)
		if (set->@__val@[i])
			return 0;
	return 1;
}

[[decl_include("<bits/sigset.h>")]]
int sigandset([[nonnull]] sigset_t *set,
              [[nonnull]] sigset_t const *left,
              [[nonnull]] sigset_t const *right) {
	size_t i;
	for (i = 0; i < sizeof(__sigset_t) / sizeof(ulongptr_t); ++i)
		set->@__val@[i] = left->@__val@[i] & right->@__val@[i];
	return 0;
}

[[decl_include("<bits/sigset.h>")]]
int sigorset([[nonnull]] sigset_t *set,
             [[nonnull]] sigset_t const *left,
             [[nonnull]] sigset_t const *right) {
	size_t i;
	for (i = 0; i < sizeof(__sigset_t) / sizeof(ulongptr_t); ++i)
		set->@__val@[i] = left->@__val@[i] | right->@__val@[i];
	return 0;
}
%#endif /* __USE_GNU */

%#ifdef __USE_POSIX199309
[[cp]]
int sigwaitinfo([[nonnull]] sigset_t const *__restrict set,
                [[nullable]] siginfo_t *__restrict info);

[[cp, ignore, nocrt, alias("sigtimedwait"), doc_alias("sigtimedwait")]]
int sigtimedwait32([[nonnull]] sigset_t const *__restrict set,
                   [[nullable]] siginfo_t *__restrict info,
                   [[nullable]] struct $timespec32 const *timeout);

[[cp, no_crt_self_import]]
[[if(defined(__USE_TIME_BITS64)), preferred_alias("sigtimedwait64")]]
[[if(!defined(__USE_TIME_BITS64)), preferred_alias("sigtimedwait")]]
[[userimpl, requires($has_function(sigtimedwait32) || $has_function(sigtimedwait64))]]
int sigtimedwait([[nonnull]] sigset_t const *__restrict set,
                 [[nullable]] siginfo_t *__restrict info,
                 [[nullable]] struct timespec const *timeout) {
@@pp_if $has_function(sigtimedwait64)@@
	struct timespec64 tmv;
	if (!timeout)
		return sigtimedwait64(set, info, NULL);
	tmv.tv_sec  = (__time64_t)timeout->tv_sec;
	tmv.tv_nsec = timeout->tv_nsec;
	return sigtimedwait64(set, info, NULL);
@@pp_else@@
	struct timespec32 tmv;
	if (!timeout)
		return sigtimedwait32(set, info, NULL);
	tmv.tv_sec  = (__time32_t)timeout->tv_sec;
	tmv.tv_nsec = timeout->tv_nsec;
	return sigtimedwait32(set, info, NULL);
@@pp_endif@@
}

[[decl_include("<bits/types.h>")]]
int sigqueue($pid_t pid, $signo_t signo, union sigval const val);

%#ifdef __USE_TIME64

[[time64_variant_of(sigtimedwait), doc_alias("sigtimedwait")]]
[[cp, userimpl, requires_function(sigtimedwait32)]]
int sigtimedwait64([[nonnull]] sigset_t const *__restrict set,
                   [[nullable]] siginfo_t *__restrict info,
                   [[nullable]] struct $timespec64 const *timeout) {
	struct timespec32 tmv;
	if (!timeout)
		return sigtimedwait32(set, info, NULL);
	tmv.tv_sec  = (__time32_t)timeout->tv_sec;
	tmv.tv_nsec = timeout->tv_nsec;
	return sigtimedwait32(set, info, NULL);
}

%#endif /* __USE_TIME64 */
%#endif /* __USE_POSIX199309 */
%#endif /* __USE_POSIX */

%
%#ifdef __USE_KOS
[[decl_include("<bits/types.h>")]]
int sigqueueinfo($pid_t tgid, $signo_t signo,
                 [[nonnull]] siginfo_t const *uinfo);

[[decl_include("<bits/types.h>")]]
int tgsigqueueinfo($pid_t tgid, $pid_t tid, $signo_t signo,
                   [[nonnull]] siginfo_t const *uinfo);
%#endif /* __USE_KOS */

%
%#if defined(__USE_MISC) || defined(__USE_XOPEN_EXTENDED)
[[decl_include("<bits/types.h>")]]
int killpg($pid_t pgrp, $signo_t signo);
%#endif /* __USE_MISC || __USE_XOPEN_EXTENDED */

%
%#ifdef __USE_XOPEN2K8
[[decl_include("<bits/types.h>")]]
void psignal($signo_t signo, [[nullable]] char const *s);

void psiginfo([[nonnull]] siginfo_t const *pinfo,
              [[nullable]] char const *s);
%#endif /* __USE_XOPEN2K8 */

%
%#if defined(__USE_XOPEN_EXTENDED) || defined(__USE_XOPEN2K8)
[[decl_include("<features.h>", "<bits/types.h>")]]
int siginterrupt($signo_t signo, __STDC_INT_AS_UINT_T interrupt);

int sigstack([[nullable]] struct sigstack *ss,
             [[nullable]] struct sigstack *oss);

int sigaltstack([[nullable]] struct sigaltstack const *ss,
                [[nullable]] struct sigaltstack *oss);
%#endif /* __USE_XOPEN_EXTENDED || __USE_XOPEN2K8 */

%
%#ifdef __USE_XOPEN_EXTENDED
[[decl_include("<bits/types.h>")]]
int sighold($signo_t signo);

[[decl_include("<bits/types.h>")]]
int sigrelse($signo_t signo);

[[decl_include("<bits/types.h>")]]
int sigignore($signo_t signo);

[[decl_include("<bits/types.h>")]]
$sighandler_t sigset($signo_t signo, $sighandler_t disp);

%#endif /* __USE_XOPEN_EXTENDED */
%


[[ATTR_CONST, wunused]]
[[requires_include("<bits/signum-values.h>")]]
[[requires(defined(__SIGRTMIN))]]
[[decl_include("<bits/types.h>")]]
$signo_t __libc_current_sigrtmin() {
	return __SIGRTMIN;
}

[[ATTR_CONST, wunused]]
[[requires_include("<bits/signum-values.h>")]]
[[requires(defined(__SIGRTMAX))]]
[[decl_include("<bits/types.h>")]]
$signo_t __libc_current_sigrtmax() {
	return __SIGRTMAX;
}

%
%#if defined(__USE_POSIX199506) || defined(__USE_UNIX98)
[[guard, decl_include("<features.h>", "<bits/sigset.h>")]]
int pthread_sigmask(__STDC_INT_AS_UINT_T how,
                    [[nullable]] $sigset_t const *newmask,
                    [[nullable]] $sigset_t *oldmask);

[[guard, decl_include("<bits/types.h>", "<bits/crt/pthreadtypes.h>")]]
int pthread_kill($pthread_t threadid, $signo_t signo);

%#ifdef __USE_GNU
[[guard, decl_include("<bits/types.h>", "<bits/crt/pthreadtypes.h>", "<bits/sigval.h>")]]
int pthread_sigqueue($pthread_t threadid,
                     $signo_t signo,
                     union sigval const value);
%#endif /* __USE_GNU */

%#endif /* __USE_POSIX199506 || __USE_UNIX98 */


%{

#endif /* __CC__ */

__SYSDECL_END

}