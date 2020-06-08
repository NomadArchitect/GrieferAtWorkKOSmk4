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

%[define_replacement(fd_t       = __fd_t)]
%[define_replacement(off_t      = "__FS_TYPE(off)")]
%[define_replacement(pos_t      = "__FS_TYPE(pos)")]
%[define_replacement(uid_t      = __uid_t)]
%[define_replacement(gid_t      = __gid_t)]
%[define_replacement(pid_t      = __pid_t)]
%[define_replacement(off32_t    = __off32_t)]
%[define_replacement(off64_t    = __off64_t)]
%[define_replacement(pos32_t    = __pos32_t)]
%[define_replacement(pos64_t    = __pos64_t)]
%[define_replacement(atflag_t   = __atflag_t)]
%[define_replacement(useconds_t = __useconds_t)]
%[define_replacement(oflag_t    = __oflag_t)]


%{
#include <features.h>

#include <hybrid/typecore.h>

#include <asm/stdio.h>
#include <bits/confname.h>
#include <bits/posix_opt.h>
#include <bits/types.h>

#if defined(__CRT_GLC) || defined(__CRT_KOS) || defined(__CRT_KOS_KERNEL)
#include <asm/unistd.h>
#endif /* __CRT_GLC || __CRT_KOS || __CRT_KOS_KERNEL */

#if defined(__USE_UNIX98) || defined(__USE_XOPEN2K)
#include <bits/environments.h>
#endif /* __USE_UNIX98 || __USE_XOPEN2K */

__SYSDECL_BEGIN

#ifdef __USE_XOPEN2K8
#define _POSIX_VERSION 200809L
#elif defined(__USE_XOPEN2K)
#define _POSIX_VERSION 200112L
#elif defined(__USE_POSIX199506)
#define _POSIX_VERSION 199506L
#elif defined(__USE_POSIX199309)
#define _POSIX_VERSION 199309L
#else /* ... */
#define _POSIX_VERSION 199009L
#endif /* !... */

#ifdef __USE_XOPEN2K8
#define __POSIX2_THIS_VERSION 200809L
#elif defined(__USE_XOPEN2K)
#define __POSIX2_THIS_VERSION 200112L
#elif defined(__USE_POSIX199506)
#define __POSIX2_THIS_VERSION 199506L
#else /* ... */
#define __POSIX2_THIS_VERSION 199209L
#endif /* !... */

#define _POSIX2_VERSION   __POSIX2_THIS_VERSION
#define _POSIX2_C_VERSION __POSIX2_THIS_VERSION
#define _POSIX2_C_BIND    __POSIX2_THIS_VERSION
#define _POSIX2_C_DEV     __POSIX2_THIS_VERSION
#define _POSIX2_SW_DEV    __POSIX2_THIS_VERSION
#define _POSIX2_LOCALEDEF __POSIX2_THIS_VERSION

#ifdef __USE_XOPEN2K8
#define _XOPEN_VERSION 700
#elif defined(__USE_XOPEN2K)
#define _XOPEN_VERSION 600
#elif defined(__USE_UNIX98)
#define _XOPEN_VERSION 500
#else /* ... */
#define _XOPEN_VERSION 4
#endif /* !... */
#define _XOPEN_XCU_VERSION 4
#define _XOPEN_XPG2        1
#define _XOPEN_XPG3        1
#define _XOPEN_XPG4        1
#define _XOPEN_UNIX        1
#define _XOPEN_CRYPT       1
#define _XOPEN_ENH_I18N    1
#define _XOPEN_LEGACY      1

#define STDIN_FILENO  __STDIN_FILENO  /* Standard input. */
#define STDOUT_FILENO __STDOUT_FILENO /* Standard output. */
#define STDERR_FILENO __STDERR_FILENO /* Standard error output. */

#define F_OK __F_OK /* Test for existence. */
#define X_OK __X_OK /* Test for execute permission. */
#define W_OK __W_OK /* Test for write permission. */
#define R_OK __R_OK /* Test for read permission. */

#ifndef SEEK_SET
#define SEEK_SET __SEEK_SET /* Seek from beginning of file. */
#define SEEK_CUR __SEEK_CUR /* Seek from current position. */
#define SEEK_END __SEEK_END /* Seek from end of file. */
#ifdef __USE_GNU
#ifdef __SEEK_DATA
#define SEEK_DATA __SEEK_DATA /* Seek to next data. */
#endif /* __SEEK_DATA */
#ifdef __SEEK_HOLE
#define SEEK_HOLE __SEEK_HOLE /* Seek to next hole. */
#endif /* __SEEK_HOLE */
#endif /* __USE_GNU */
#endif /* !SEEK_SET */

#ifdef __USE_MISC
#ifndef L_SET
#define L_SET  SEEK_SET
#define L_CURR SEEK_CUR
#define L_INCR SEEK_CUR
#define L_XTND SEEK_END
#endif /* !L_SET */
#endif /* __USE_MISC */

#ifdef __CC__
#ifndef __ssize_t_defined
#define __ssize_t_defined 1
typedef __ssize_t ssize_t;
#endif /* !__ssize_t_defined */

#ifndef __size_t_defined
#define __size_t_defined 1
typedef __SIZE_TYPE__ size_t;
#endif /* !__size_t_defined */

#ifndef NULL
#define NULL __NULLPTR
#endif /* !NULL */

#if defined(__USE_XOPEN) || defined(__USE_XOPEN2K)
#ifndef __gid_t_defined
#define __gid_t_defined 1
typedef __gid_t gid_t;
#endif /* !__gid_t_defined */
#ifndef __uid_t_defined
#define __uid_t_defined 1
typedef __uid_t uid_t;
#endif /* !__uid_t_defined */
#ifndef __off_t_defined
#define __off_t_defined
typedef __typedef_off_t off_t;
#endif /* !__off_t_defined */
#ifndef __useconds_t_defined
#define __useconds_t_defined 1
typedef __useconds_t useconds_t;
#endif /* !__useconds_t_defined */
#ifndef __pid_t_defined
#define __pid_t_defined 1
typedef __pid_t pid_t;
#endif /* !__pid_t_defined */
#ifdef __USE_LARGEFILE64
#ifndef __off64_t_defined
#define __off64_t_defined 1
typedef __off64_t off64_t;
#endif /* !__off64_t_defined */
#endif /* __USE_LARGEFILE64 */
#endif /* __USE_XOPEN || __USE_XOPEN2K */

#if defined(__USE_XOPEN_EXTENDED) || defined(__USE_XOPEN2K)
#ifndef __intptr_t_defined
#define __intptr_t_defined 1
typedef __intptr_t intptr_t;
#endif /* !__intptr_t_defined */
#endif /* __USE_XOPEN_EXTENDED || __USE_XOPEN2K */

#if defined(__USE_MISC) || defined(__USE_XOPEN)
#ifndef __socklen_t_defined
#define __socklen_t_defined 1
typedef __socklen_t socklen_t;
#endif /* !__socklen_t_defined */
#endif /* __USE_MISC || __USE_XOPEN */

#ifndef __TARGV
#ifdef __USE_DOS
#define __TARGV char const *const *___argv
#define __TENVP char const *const *___envp
#else /* __USE_DOS */
#define __TARGV char *const ___argv[__restrict_arr]
#define __TENVP char *const ___envp[__restrict_arr]
#endif /* !__USE_DOS */
#endif /* !__TARGV */

#ifndef ____environ_defined
#define ____environ_defined 1
#undef __environ
#if defined(__CRT_HAVE_environ) && !defined(__NO_ASMNAME)
__LIBC char **__environ __ASMNAME("environ");
#elif defined(__CRT_HAVE__environ) && !defined(__NO_ASMNAME)
__LIBC char **__environ __ASMNAME("_environ");
#define __environ __environ
#define __environ __environ
#elif defined(__CRT_HAVE__environ)
#undef _environ
#ifndef ___environ_defined
#define ___environ_defined 1
__LIBC char **_environ;
#endif /* !___environ_defined */
#define __environ _environ
#elif defined(__CRT_HAVE_environ)
#undef environ
#ifndef __environ_defined
#define __environ_defined 1
__LIBC char **environ;
#endif /* !__environ_defined */
#define __environ environ
#elif defined(__CRT_HAVE___p__environ)
#ifndef ____p__environ_defined
#define ____p__environ_defined 1
__CDECLARE(__ATTR_WUNUSED __ATTR_CONST __ATTR_RETNONNULL,char ***,__NOTHROW,__p__environ,(void),())
#endif /* !____p__environ_defined */
#define __environ (*__p__environ())
#else /* ... */
#undef ____environ_defined
#endif /* !... */
#endif /* !____environ_defined */

}

%(user){
INTDEF WUNUSED ATTR_CONST ATTR_RETNONNULL char ***NOTHROW(LIBCCALL libc_p_environ)(void);
};

%[default_impl_section(".text.crt.fs.exec.exec")];

@@>> execv(3)
@@Replace the calling process with the application image referred to by `PATH' / `FILE'
@@and execute it's `main()' method, passing the given `ARGV', and setting `environ' to `ENVP'
[[cp, guard, export_alias("_execv"), argument_names(path, ___argv), crtbuiltin]]
int execv([[nonnull]] char const *__restrict path, [[nonnull]] __TARGV);

@@>> execve(2)
@@Replace the calling process with the application image referred to by `PATH' / `FILE'
@@and execute it's `main()' method, passing the given `ARGV', and setting `environ' to `ENVP'
[[cp, guard, export_alias("_execve"), argument_names(path, ___argv, ___envp), crtbuiltin]]
int execve([[nonnull]] char const *__restrict path, [[nonnull]] __TARGV, [[nonnull]] __TENVP);

@@>> execvp(3)
@@Replace the calling process with the application image referred to by `PATH' / `FILE'
@@and execute it's `main()' method, passing the given `ARGV', and setting `environ' to `ENVP'
[[cp, guard, export_alias("_execvp"), argument_names(file, ___argv), crtbuiltin]]
int execvp([[nonnull]] char const *__restrict file, [[nonnull]] __TARGV);


@@>> execl(3)
@@Replace the calling process with the application image referred to by `PATH' / `FILE'
@@and execute it's `main()' method, passing the list of NULL-terminated `ARGS'-list
[[cp, guard, ATTR_SENTINEL, export_alias("_execl"), impl_include("<parts/redirect-exec.h>")]]
[[userimpl, requires_dependent_function(execv), allow_macros, crtbuiltin]]
int execl([[nonnull]] char const *__restrict path, char const *args, ... /*, (char *)NULL*/) {
	__REDIRECT_EXECL(char, execv, path, args)
}

@@>> execle(3)
@@Replace the calling process with the application image referred to by `PATH' / `FILE'
@@and execute it's `main()' method, passing the list of NULL-terminated `ARGS'-list,
@@and setting `environ' to a `char **' passed after the NULL sentinel
[[cp, guard, impl_include("<parts/redirect-exec.h>"), export_alias("_execle"), crtbuiltin]]
[[userimpl, requires_dependent_function(execve), ATTR_SENTINEL_O(1), allow_macros]]
int execle([[nonnull]] char const *__restrict path, char const *args, ... /*, (char *)NULL, (char **)environ*/) {
	__REDIRECT_EXECLE(char, execve, path, args)
}

@@>> execlp(3)
@@Replace the calling process with the application image referred to by `PATH' / `FILE'
@@and execute it's `main()' method, passing the list of NULL-terminated `ARGS'-list
[[cp, guard, impl_include("<parts/redirect-exec.h>"), export_alias("_execlp")]]
[[userimpl, requires_dependent_function(execvp), ATTR_SENTINEL, allow_macros, crtbuiltin]]
int execlp([[nonnull]] char const *__restrict file, char const *args, ... /*, (char *)NULL*/) {
	__REDIRECT_EXECL(char, execvp, file, args)
}

%#if defined(__USE_KOS) || defined(__USE_DOS) || defined(__USE_GNU)
@@>> execvpe(3)
@@Replace the calling process with the application image referred to by `FILE'
@@and execute it's `main()' method, passing the given `ARGV', and setting `environ' to `ENVP'
[[cp, guard, export_alias("_execvpe"), argument_names(file, ___argv, ___envp)]]
int execvpe([[nonnull]] char const *__restrict file, [[nonnull]] __TARGV, [[nonnull]] __TENVP);
%#endif /* __USE_KOS || __USE_DOS || __USE_GNU */

%#if defined(__USE_KOS) || defined(__USE_DOS)
@@>> execlpe(3)
@@Replace the calling process with the application image referred to by `PATH' / `FILE'
@@and execute it's `main()' method, passing the list of NULL-terminated `ARGS'-list, and setting `environ' to a `char **' passed after the NULL sentinel
[[cp, guard, impl_include("<parts/redirect-exec.h>"), export_alias("_execlpe")]]
[[userimpl, requires_dependent_function(execvpe), ATTR_SENTINEL_O(1), allow_macros]]
int execlpe([[nonnull]] char const *__restrict file, char const *args, ... /*, (char *)NULL, (char **)environ*/) {
	__REDIRECT_EXECLE(char, execvp, file, args)
}
%#endif /* __USE_KOS || __USE_DOS */

%[default_impl_section(".text.crt.sched.process")]

%
@@>> getpid(2)
@@Return the PID of the calling process (that is the TID of the calling thread group's leader)
@@THIS_THREAD->LEADER->PID
[[guard, ATTR_WUNUSED, export_alias("_getpid", "__getpid")]]
$pid_t getpid();

%
%#ifdef __USE_KOS
@@>> gettid(2)
@@Return the TID of the calling thread
@@THIS_THREAD->PID
[[guard, ATTR_WUNUSED, section(".text.crt.sched.thread")]]
gettid:() -> $pid_t;
%#endif /* __USE_KOS */

[[ignore, nocrt, alias("_pipe")]]
int dos_pipe([[nonnull]] $fd_t pipedes[2],
             $uint32_t pipesize, $oflag_t textmode);

%
@@>> pipe(2)
@@Create a new pair of connected pipes ([0] = reader, [1] = writer)
[[section(".text.crt.io.access"), export_alias("__pipe")]]
[[userimpl, requires_function(dos_pipe)]]
int pipe([[nonnull]] $fd_t pipedes[2]) {
	return dos_pipe(pipedes, 4096, 0x8000); /* O_BINARY */
}

%
@@>> sleep(3)
@@Sleep for up to `SECONDS' seconds
[[cp, guard, section(".text.crt.system.utility")]]
[[userimpl, requires_function(dos_sleep)]]
unsigned int sleep(unsigned int seconds) {
	dos_sleep((uint32_t)seconds);
	return 0;
}

%
@@>> fsync(2)
@@Synchronize a file (including its descriptor which contains timestamps, and its size),
@@meaning that changes to its data and/or descriptor are written to disk
[[cp, export_alias("_commit"), alias("fdatasync")]]
[[userimpl, section(".text.crt.io.sync")]]
int fsync($fd_t fd) {
	(void)fd;
	/* NO-OP */
	return 0;
}


%
@@>> getppid(2)
@@Return the PID of the calling process's parent.
@@(That is the TID of the leader of the parent of the calling thread's leader)
@@THIS_THREAD->LEADER->PARENT->LEADER->PID
[[ATTR_WUNUSED]] getppid:() -> $pid_t;


%
@@>> getpgrp(2)
@@Return the ID of the calling process's process group.
@@(That is the TID of the leader of the process group of the calling thread's leader)
@@THIS_THREAD->LEADER->GROUP_LEADER->PID
[[ATTR_WUNUSED]] getpgrp:() -> $pid_t;

%
__getpgid(*) = getpgid;

%
@@>> setpgid(2)
@@Change the ID of the process group associated with `PID's process.
@@(That is the TID of the leader of the process group of `PID's leader)
@@THREAD[PID]->LEADER->GROUP_LEADER = THREAD[PGID]
@@When `PID' is ZERO(0), use `gettid()' for it instead.
@@When `PGID' is ZERO(0), use `PID' (after it was substituted) for instead
[export_alias("__setpgid")]
int setpgid($pid_t pid, $pid_t pgid);

%
@@>> setsid(2)
@@Make the calling thread's process the leader of its associated
@@process group, before also making it its own session leader.
@@Then return the TID of that new session leader, which is also the PID of the calling process.
@@THIS_THREAD->LEADER->GROUP_LEADER                 = THIS_THREAD->LEADER;
@@THIS_THREAD->LEADER->GROUP_LEADER->SESSION_LEADER = THIS_THREAD->LEADER->GROUP_LEADER;
@@return THIS_THREAD->LEADER->PID;
setsid:() -> $pid_t;

%[default_impl_section(".text.crt.sched.user")]

%
@@>> getuid(2)
@@Return the real user ID of the calling process
[[ATTR_WUNUSED]] getuid:() -> $uid_t;

%
@@>> geteuid(2)
@@Return the effective user ID of the calling process
[[ATTR_WUNUSED]] geteuid:() -> $uid_t;

%
@@>> getgid(2)
@@Return the real group ID of the calling process
[[ATTR_WUNUSED]] getgid:() -> $gid_t;

%
@@>> getegid(2)
@@Return the effective group ID of the calling process
[[ATTR_WUNUSED]] getegid:() -> $gid_t;

%
%/* ... */
getgroups:(int size, $gid_t list[]) -> int;

%
@@>> setuid(2)
@@Set the effective user ID of the calling process
@@@return: 0 : Success
@@@return: -1: [errno=EINVAL] : The given `UID' is invalid
@@@return: -1: [errno=EPERM]  : The current user is not privileged
setuid:($uid_t uid) -> int;

%
@@>> setgid(2)
@@Set the effective group ID of the calling process
@@@return: 0 : Success
@@@return: -1: [errno=EINVAL] : The given `GID' is invalid
@@@return: -1: [errno=EPERM]  : The current user is not privileged
setgid:($gid_t gid) -> int;


%
@@>> fork(2)
@@Clone the calling thread into a second process and return twice, once
@@in the parent process where this function returns the (non-zero) PID
@@of the forked child process, and a second time in the child process
@@itself, where ZERO(0) is returned.
@@The child then usually proceeds by calling `exec(2)' to replace its
@@application image with that of another program that the original
@@parent can then `wait(2)' for
[section(".text.crt.sched.access")][[crtbuiltin]]
[[ATTR_WUNUSED]][export_alias(__fork)]
fork:() -> $pid_t;


%[default_impl_section(".text.crt.system.utility")]

%
@@>> alarm(2)
@@@return: 0 : No alarm was scheduled before.
@@@return: * : The number of seconds yet to pass before a previous alarm would have elapsed.
@@Schedule an to deliver a `SIGALRM' after letting `seconds' elapse.
@@You may pass ZERO(0) for SECONDS to disable a previously scheduled alarm
alarm:(unsigned int seconds) -> unsigned int;

%
@@>> pause(2)
@@Suspend execution until the delivery of a POSIX_SIGNAL
[[cp]] pause:() -> int;

%
@@>> fpathconf(2)
@@@param: NAME: One of `_PC_*' from <bits/confname.h>
@@Return a path configuration value associated with `NAME' for `FD'
@@return: * : The configuration limit associated with `NAME' for `FD'
@@return: -1: [errno=<unchanged>] The configuration specified by `NAME' is unlimited for `FD'
@@return: -1: [errno=EINVAL]      The given `NAME' isn't a recognized config option
[[section(".text.crt.fs.property")]]
[[cp, ATTR_WUNUSED]]
long int fpathconf($fd_t fd, int name);

%[default_impl_section(".text.crt.io.tty")]

%
@@>> ttyname(3)
@@Return the name of a TTY given its file descriptor
[[cp, ATTR_WUNUSED]]
char *ttyname($fd_t fd);

@@>> ttyname_r(3)
@@Return the name of a TTY given its file descriptor
[[cp]]
int ttyname_r($fd_t fd, [[outp(buflen)]] char *buf, size_t buflen);

%
@@>> tcgetpgrp(2)
@@Return the foreground process group of a given TTY file descriptor
[[ATTR_WUNUSED]]
$pid_t tcgetpgrp($fd_t fd);

%
@@>> tcsetpgrp(2)
@@Set the foreground process group of a given TTY file descriptor
int tcsetpgrp($fd_t fd, $pid_t pgrp_id);

%
%/* ... */
[[ATTR_WUNUSED]]
char *getlogin();

%[default_impl_section(".text.crt.fs.modify")]

%
@@>> chown(2)
@@Change the ownership of a given `FILE' to `GROUP:OWNER'
[[cp, userimpl, requires(defined(__CRT_AT_FDCWD) && $has_function(fchownat))]]
int chown([[nonnull]] char const *file, $uid_t owner, $gid_t group) {
	return fchownat(__CRT_AT_FDCWD, file, owner, group, 0);
}

%
@@>> pathconf(2)
@@@param: NAME: One of `_PC_*' from <bits/confname.h>
@@Return a path configuration value associated with `NAME' for `PATH'
@@return: * : The configuration limit associated with `NAME' for `PATH'
@@return: -1: [errno=<unchanged>] The configuration specified by `NAME' is unlimited for `PATH'
@@return: -1: [errno=EINVAL]      The given `NAME' isn't a recognized config option
[[cp]][section(".text.crt.fs.property")]
pathconf:([[nonnull]] char const *path, int name) -> long int;

%
@@>> link(2)
@@Create a hard link from `FROM', leading to `TO'
[[cp]][noexport]
[requires(defined(__CRT_AT_FDCWD) && $has_function(linkat))]
link:([[nonnull]] char const *from, [[nonnull]] char const *to) -> int {
	/* TODO: Header-implementation for `link()' on DOS (using the windows API) */
	return linkat(__CRT_AT_FDCWD, from, __CRT_AT_FDCWD, to, 0);
}

%[default_impl_section(".text.crt.sched.access")]
%[insert:extern(exit)]
%[default_impl_section(".text.crt.fs.modify")]

%
@@>> read(2)
@@Read data from a given file descriptor `FD' and return the number of bytes read.
@@A return value of ZERO(0) is indicative of EOF
[[cp, guard, export_alias(_read, __read), section(".text.crt.io.read")]]
ssize_t read($fd_t fd, [[outp(bufsize)]] void *buf, size_t bufsize);

%
@@>> write(2)
@@Write data to a given file descriptor `FD' and return the number of bytes written
[[cp, guard, export_alias(_write, __write), section(".text.crt.io.write")]]
ssize_t write($fd_t fd, [[inp(bufsize)]] void const *buf, size_t bufsize);

%
%#ifdef __USE_KOS
@@>> readall(3)
@@Same as `read(2)', however keep on reading until `read()' indicates EOF (causing
@@`readall()' to immediately return `0') or the entirety of the given buffer has been
@@filled (in which case `bufsize' is returned).
@@If an error occurrs before all data could be read, try to use SEEK_CUR to rewind
@@the file descriptor by the amount of data that had already been loaded. - Errors
@@during this phase are silently ignored and don't cause `errno' to change
[[cp, guard]][section(".text.crt.io.read")]
[requires($has_function(read) && $has_function(lseek))]
[[impl_include("<parts/errno.h>")]]
readall:($fd_t fd, [[outp(bufsize)]] void *buf, size_t bufsize) -> ssize_t {
	ssize_t result, temp;
	result = read(fd, buf, bufsize);
	if (result > 0 && (size_t)result < bufsize) {
		/* Keep on reading */
		for (;;) {
			temp = read(fd,
			            (byte_t *)buf + (size_t)result,
			            bufsize - (size_t)result);
			if (temp <= 0) {
#ifdef @__errno@
				int old_error = @__errno@;
#endif /* __errno */
				/* Try to un-read data that had already been loaded. */
				lseek(fd, -(off_t)(pos_t)result, SEEK_CUR);
#ifdef @__errno@
				@__errno@ = old_error;
#endif /* __errno */
				result = temp;
				break;
			}
			result += temp;
			if ((size_t)result >= bufsize)
				break;
		}
	}
	return result;
}

@@>> writeall(3)
@@Same as `write(2)', however keep on writing until `write()' indicates EOF (causing
@@`writeall()' to immediately return `0') or the entirety of the given buffer has been
@@written (in which case `bufsize' is returned).
[[cp, guard]][section(".text.crt.io.write")]
[requires($has_function(write) && $has_function(lseek))]
[[impl_include("<parts/errno.h>")]]
writeall:($fd_t fd, [[inp(bufsize)]] void const *buf, size_t bufsize) -> ssize_t {
	ssize_t result, temp;
	result = write(fd, buf, bufsize);
	if (result > 0 && (size_t)result < bufsize) {
		/* Keep on writing */
		for (;;) {
			temp = write(fd,
			             (byte_t *)buf + (size_t)result,
			             bufsize - (size_t)result);
			if (temp <= 0) {
				result = temp;
				break;
			}
			result += temp;
			if ((size_t)result >= bufsize)
				break;
		}
	}
	return result;
}
%#endif /* __USE_KOS */


[[doc_alias("lseek"), ignore, nocrt, alias("lseek", "_lseek", "__lseek")]]
$off32_t lseek32($fd_t fd, $off32_t offset, int whence);

%
@@>> lseek(2)
@@Change the position of the file read/write pointer within a file referred to by `FD'
[[guard, no_crt_self_import]]
[if(defined(__USE_FILE_OFFSET64)), preferred_alias("lseek64", "_lseeki64")]
[if(!defined(__USE_FILE_OFFSET64)), preferred_alias("lseek", "_lseek", "__lseek")]
[[userimpl, requires($has_function(lseek32) || $has_function(lseek64))]]
[[section(".text.crt.io.seek"), export_as("_lseek", "__lseek")]]
$off_t lseek($fd_t fd, $off_t offset, int whence) {
@@pp_if $has_function(lseek32)@@
	return lseek32(fd, ($off32_t)offset, whence);
@@pp_else@@
	return lseek64(fd, ($off64_t)offset, whence);
@@pp_endif@@
}

%
@@>> isatty(2)
@@@return: 1: Is a tty
@@@return: 0: Not a tty
@@Check if the given file handle `FD' refers to a TTY
[[guard, ATTR_WUNUSED, decl_include("<bits/types.h>")]]
[[section(".text.crt.io.tty"), export_alias("_isatty")]]
int isatty($fd_t fd);

%
@@>> dup2(2)
@@@return: NEWFD: Returns the new handle upon success.
@@Duplicate a file referred to by `OLDFD' into `NEWFD'
[[guard, decl_include("<bits/types.h>")]]
[[section(".text.crt.io.access"), export_alias("_dup2", "__dup2")]]
$fd_t dup2($fd_t oldfd, $fd_t newfd);

%
@@>> dup(2)
@@@return: * : Returns the new handle upon success.
@@Duplicate a file referred to by `FD' and return its duplicated handle number
[[guard, ATTR_WUNUSED, decl_include("<bits/types.h>")]]
[[section(".text.crt.io.access"), export_alias("_dup")]]
$fd_t dup($fd_t fd);

%
@@>> close(2)
@@Close a file handle
[[guard, decl_include("<bits/types.h>")]]
[[section(".text.crt.io.access"), export_alias("_close", "__close")]]
int close($fd_t fd);

%
@@>> access(2)
@@@param: TYPE: Set of `X_OK|W_OK|R_OK'
@@Test for access to the specified file `FILE', testing for `TYPE'
[[cp, guard, ATTR_WUNUSED]]
[[export_alias("_access"), section(".text.crt.fs.property")]]
[[userimpl, requires(defined(__CRT_AT_FDCWD) && $has_function(faccessat))]]
int access([[nonnull]] char const *file, int type) {
	return faccessat(__CRT_AT_FDCWD, file, type, 0);
}

%
@@>> chdir(2)
@@Change the current working directory to `PATH'
[[cp, guard, export_alias("_chdir")]]
[[section(".text.crt.fs.basic_property")]]
int chdir([[nonnull]] char const *path);

%
@@>> getcwd(2)
@@Return the path of the current working directory, relative to the filesystem root set by `chdir(2)'
[[cp, guard, export_alias("_getcwd"), section(".text.crt.fs.basic_property")]]
char *getcwd([[outp_opt(bufsize)]] char *buf, size_t bufsize);

%[default_impl_section(".text.crt.fs.modify")]

%
@@>> unlink(2)
@@Remove a file, symbolic link, device or FIFO referred to by `FILE'
[[cp, guard, export_alias("_unlink")]]
[[userimpl, requires(defined(__CRT_AT_FDCWD) && $has_function(unlinkat))]]
int unlink([[nonnull]] char const *file) {
	return unlinkat(__CRT_AT_FDCWD, file, 0);
}

%
@@>> rmdir(2)
@@Remove a directory referred to by `PATH'
[[cp, guard, export_alias("_rmdir")]]
[[userimpl, requires(defined(__CRT_AT_FDCWD) && $has_function(unlinkat))]]
int rmdir([[nonnull]] char const *path) {
	return unlinkat(__CRT_AT_FDCWD, path, 0x0200); /* AT_REMOVEDIR */
}

%[default_impl_section(".text.crt.fs.property")];

%
%#ifdef __USE_GNU
@@>> euidaccess(2)
@@@param: TYPE: Set of `X_OK | W_OK | R_OK'
@@Test for access to the specified file `FILE', testing for `TYPE', using the effective filesystem ids
[[cp, export_alias(eaccess), ATTR_WUNUSED]]
[[if(defined(__CRT_DOS)), alias("_access")]]
[[userimpl, requires(defined(__CRT_AT_FDCWD) && $has_function(faccessat))]]
euidaccess:([[nonnull]] char const *file, int type) -> int {
	return faccessat(__CRT_AT_FDCWD, file, type, 0x0200); /* AT_EACCESS */
}

%
@@>> eaccess(2)
@@@param: TYPE: Set of `X_OK | W_OK | R_OK'
@@Test for access to the specified file `FILE', testing for `TYPE', using the effective filesystem ids
eaccess(*) = euidaccess;

%#endif /* __USE_GNU */

%
%#ifdef __USE_ATFILE
@@>> faccessat(2)
@@@param: TYPE: Set of `X_OK | W_OK | R_OK'
@@Test for access to the specified file `DFD:FILE', testing for `TYPE'
[[cp]]
int faccessat($fd_t dfd, [[nonnull]] char const *file, int type, $atflag_t flags);

%[default_impl_section(".text.crt.fs.modify")];

%
@@>> fchownat(2)
@@Change the ownership of a given `DFD:FILE' to `GROUP:OWNER'
[[cp]]
int fchownat($fd_t dfd, [[nonnull]] char const *file,
             $uid_t owner, $gid_t group, $atflag_t flags);

%
@@>> linkat(2)
@@Create a hard link from `FROMFD:FROM', leading to `TOFD:TO'
[[cp]]
int linkat($fd_t fromfd, [[nonnull]] char const *from,
           $fd_t tofd, [[nonnull]] char const *to, $atflag_t flags);

%
@@>> symlinkat(3)
@@Create a new symbolic link loaded with `LINK_TEXT' as link
@@text, at the filesystem location referred to by `TOFD:TARGET_PATH'
[[cp]]
int symlinkat([[nonnull]] char const *link_text, $fd_t tofd,
              [[nonnull]] char const *target_path);

%[default_impl_section(".text.crt.fs.property")];

%
@@>> readlinkat(2)
@@Read the text of a symbolic link under `DFD:PATH' into the provided buffer.
@@WARNING: This function is badly designed and will neither append a trailing
@@         NUL-character to the buffer, nor will it return the required buffer
@@         size. Instead, it will return the written size, and the caller must
@@         keep on over allocating until the function indicates that it didn't
@@         make use of the buffer in its entirety.
@@When targeting KOS, consider using `freadlinkat(2)' with `AT_READLINK_REQSIZE'.
[[cp]]
ssize_t readlinkat($fd_t dfd, [[nonnull]] char const *__restrict path,
                   [[outp(buflen)]] char *__restrict buf, size_t buflen);

%
%#ifdef __USE_KOS
@@>> freadlinkat(2)
@@Read the text of a symbolic link under `DFD:PATH' into the provided buffer.
@@@param flags: Set of `AT_DOSPATH|AT_READLINK_REQSIZE'
[[cp]]
ssize_t freadlinkat($fd_t dfd, [[nonnull]] char const *__restrict path,
                    [[outp(buflen)]] char *__restrict buf, size_t buflen, $atflag_t flags);
%#endif /* __USE_KOS */

%[default_impl_section(".text.crt.fs.modify")];

%
@@>> unlinkat(2)
@@Remove a file, symbolic link, device or FIFO referred to by `DFD:NAME'
[[cp]]
int unlinkat($fd_t dfd, [[nonnull]] char const *name, $atflag_t flags);
%#endif /* __USE_ATFILE */

%
%
%#ifdef __USE_LARGEFILE64
@@>> lseek64(2)
@@Change the position of the file read/write pointer within a file referred to by `FD'
[[off64_variant_of(lseek), export_alias("_lseeki64")]]
[[section(".text.crt.io.large.seek"), userimpl, requires_function(lseek32)]]
$off64_t lseek64($fd_t fd, $off64_t offset, int whence) {
	return lseek32(fd, (__off32_t)offset, whence);
}
%#endif /* __USE_LARGEFILE64 */

%
%
%#if defined(__USE_UNIX98) || defined(__USE_XOPEN2K8)
%{
#ifndef __PIO_OFFSET
#ifdef __USE_KOS
#define __PIO_OFFSET     __FS_TYPE(pos)
#define __PIO_OFFSET64   __pos64_t
#else /* __USE_KOS */
#define __PIO_OFFSET     __FS_TYPE(off)
#define __PIO_OFFSET64   __off64_t
#endif /* !__USE_KOS */
#endif /* !__PIO_OFFSET */
}

%[define(DEFINE_PIO_OFFSET =
#ifndef __PIO_OFFSET
#ifdef __USE_KOS
#define __PIO_OFFSET     __FS_TYPE(pos)
#define __PIO_OFFSET64   __pos64_t
#else /* __USE_KOS */
#define __PIO_OFFSET     __FS_TYPE(off)
#define __PIO_OFFSET64   __off64_t
#endif /* !__USE_KOS */
#endif /* !__PIO_OFFSET */
)]


%
@@>> pread(2)
@@Read data from a file at a specific offset
[[cp, decl_prefix(DEFINE_PIO_OFFSET), no_crt_self_import]]
[[if(defined(__USE_FILE_OFFSET64)), preferred_alias("pread64")]]
[[if(!defined(__USE_FILE_OFFSET64)), preferred_alias("pread")]]
[[section(".text.crt.io.read"), requires_include("<asm/stdio.h>")]]
[[userimpl, requires($has_function(pread64) || ($has_function(lseek) && $has_function(read) && defined(__SEEK_SET) && defined(__SEEK_CUR)))]]
ssize_t pread($fd_t fd, [[outp(bufsize)]] void *buf, size_t bufsize, __PIO_OFFSET offset) {
@@pp_if $has_function(pread64)@@
	return pread64(fd, buf, bufsize, (@__PIO_OFFSET64@)offset);
@@pp_else@@
	/* It may not be quick, and it may not be SMP-safe, but it'll still do the job! */
	off_t oldpos;
	ssize_t result;
	oldpos = lseek(fd, 0, __SEEK_CUR);
	if __unlikely(oldpos < 0)
		return -1;
	if __unlikely(lseek(fd, (__FS_TYPE(@off@))offset, __SEEK_SET) < 0)
		return -1;
	result = read(fd, buf, bufsize);
	lseek(fd, oldpos, __SEEK_SET);
	return result;
@@pp_endif@@
}

@@>> pwrite(2)
@@Write data to a file at a specific offset
[[cp, decl_prefix(DEFINE_PIO_OFFSET), no_crt_self_import]]
[[if(defined(__USE_FILE_OFFSET64)), preferred_alias("pwrite64")]]
[[if(!defined(__USE_FILE_OFFSET64)), preferred_alias("pwrite")]]
[[section(".text.crt.io.write"), requires_include("<asm/stdio.h>")]]
[[userimpl, requires($has_function(pwrite64) || ($has_function(lseek) && $has_function(write) && defined(__SEEK_SET) && defined(__SEEK_CUR)))]]
ssize_t pwrite($fd_t fd, [[inp(bufsize)]] void const *buf, size_t bufsize, __PIO_OFFSET offset) {
@@pp_if $has_function(pwrite64)@@
	return pwrite64(fd, buf, bufsize, (__PIO_OFFSET64)offset);
@@pp_else@@
	/* It may not be quick, and it may not be SMP-safe, but it'll still do the job! */
	off_t oldpos;
	ssize_t result;
	oldpos = lseek(fd, 0, __SEEK_CUR);
	if __unlikely(oldpos < 0)
		return -1;
	if __unlikely(lseek(fd, (off_t)offset, __SEEK_SET) < 0)
		return -1;
	result = write(fd, buf, bufsize);
	lseek(fd, oldpos, __SEEK_SET);
	return result;
@@pp_endif@@
}


%
%#ifdef __USE_KOS
@@>> preadall(3)
@@Same as `readall(3)', but using `pread(2)' instead of `read()'
[[cp, decl_prefix(DEFINE_PIO_OFFSET), no_crt_self_import]]
[[if(defined(__USE_FILE_OFFSET64)), preferred_alias("preadall64")]]
[[if(!defined(__USE_FILE_OFFSET64)), preferred_alias("preadall")]]
[[section(".text.crt.io.read"), impl_include("<parts/errno.h>")]]
[[userimpl, requires_function(preadall64)]]
ssize_t preadall($fd_t fd, [[outp(bufsize)]] void *buf,
                 size_t bufsize, __PIO_OFFSET offset) {
	return preadall64(fd, buf, bufsize, (__PIO_OFFSET64)offset);
}

@@>> pwriteall(3)
@@Same as `writeall(3)', but using `pwrite(2)' instead of `write()'
[[cp, decl_prefix(DEFINE_PIO_OFFSET), no_crt_self_import]]
[[if(defined(__USE_FILE_OFFSET64)), preferred_alias("pwriteall64")]]
[[if(!defined(__USE_FILE_OFFSET64)), preferred_alias("pwriteall")]]
[[impl_include("<parts/errno.h>"), section(".text.crt.io.write")]]
[[userimpl, requires_function(pwriteall64)]]
ssize_t pwriteall($fd_t fd, [[inp(bufsize)]] void const *buf,
                  size_t bufsize, __PIO_OFFSET offset) {
	return pwriteall64(fd, buf, bufsize, (__PIO_OFFSET64)offset);
}
%#endif /* __USE_KOS */



%
%#ifdef __USE_LARGEFILE64

[[cp, ignore, nocrt, alias("pread")]]
ssize_t pread32($fd_t fd, [[outp(bufsize)]] void *buf,
                size_t bufsize, $pos32_t offset);

[[cp, ignore, nocrt, alias("pwrite")]]
ssize_t pwrite32($fd_t fd, [[inp(bufsize)]] void const *buf,
                 size_t bufsize, $pos32_t offset);

@@>> pread64(2)
@@Read data from a file at a specific offset
[[cp, decl_prefix(DEFINE_PIO_OFFSET), off64_variant_of(pread), section(".text.crt.io.large.read")]]
[[export_alias("__pread64"), requires_include("<asm/stdio.h>")]]
[[userimpl, requires($has_function(pread32) || ($has_function(lseek) && $has_function(read) && defined(__SEEK_CUR) && defined(__SEEK_SET)))]]
ssize_t pread64($fd_t fd, [[outp(bufsize)]] void *buf, size_t bufsize, __PIO_OFFSET64 offset) {
@@pp_if $has_function(pread32)@@
	return pread32(fd, buf, bufsize, (pos32_t)offset);
@@pp_elif $has_function(lseek64)@@
	/* It may not be quick, and it may not be SMP-safe, but it'll still do the job! */
	off64_t oldpos;
	ssize_t result;
	oldpos = lseek64(fd, 0, __SEEK_CUR);
	if __unlikely(oldpos < 0)
		return -1;
	if __unlikely(lseek64(fd, (off64_t)offset, __SEEK_SET) < 0)
		return -1;
	result = read(fd, buf, bufsize);
	lseek64(fd, oldpos, __SEEK_SET);
	return result;
@@pp_else@@
	/* It may not be quick, and it may not be SMP-safe, but it'll still do the job! */
	off32_t oldpos;
	ssize_t result;
	oldpos = lseek32(fd, 0, __SEEK_CUR);
	if __unlikely(oldpos < 0)
		return -1;
	if __unlikely(lseek32(fd, (off32_t)offset, __SEEK_SET) < 0)
		return -1;
	result = read(fd, buf, bufsize);
	lseek32(fd, oldpos, __SEEK_SET);
	return result;
@@pp_endif@@
}

@@>> pwrite64(2)
@@Write data to a file at a specific offset
[[cp, decl_prefix(DEFINE_PIO_OFFSET), off64_variant_of(pwrite), section(".text.crt.io.large.write")]]
[[export_alias("__pwrite64"), requires_include("<asm/stdio.h>")]]
[[userimpl, requires($has_function(pwrite32) || ($has_function(lseek) && $has_function(write) && defined(__SEEK_CUR) && defined(__SEEK_SET)))]]
ssize_t pwrite64($fd_t fd, [[inp(bufsize)]] void const *buf, size_t bufsize, __PIO_OFFSET64 offset) {
@@pp_if $has_function(pwrite32)@@
	return pwrite32(fd, buf, bufsize, (pos32_t)offset);
@@pp_elif $has_function(lseek64)@@
	/* It may not be quick, and it may not be SMP-safe, but it'll still do the job! */
	off64_t oldpos;
	ssize_t result;
	oldpos = lseek64(fd, 0, SEEK_CUR);
	if __unlikely(oldpos < 0)
		return -1;
	if __unlikely(lseek64(fd, (off64_t)offset, SEEK_SET) < 0)
		return -1;
	result = write(fd, buf, bufsize);
	lseek64(fd, oldpos, SEEK_SET);
	return result;
@@pp_else@@
	/* It may not be quick, and it may not be SMP-safe, but it'll still do the job! */
	off32_t oldpos;
	ssize_t result;
	oldpos = lseek32(fd, 0, SEEK_CUR);
	if __unlikely(oldpos < 0)
		return -1;
	if __unlikely(lseek32(fd, (off32_t)offset, SEEK_SET) < 0)
		return -1;
	result = write(fd, buf, bufsize);
	lseek32(fd, oldpos, SEEK_SET);
	return result;
@@pp_endif@@
}

%
%#ifdef __USE_KOS
@@>> preadall64(3)
@@Same as `readall(3)', but using `pread64(2)' instead of `read()'
[[cp, off64_variant_of(preadall), section(".text.crt.io.large.read")]]
[[userimpl, requires_function(pread64)]]
ssize_t preadall64($fd_t fd, [[inp(bufsize)]] void *buf,
                   size_t bufsize, __PIO_OFFSET64 offset) {
	ssize_t result, temp;
	result = pread64(fd, buf, bufsize, offset);
	if (result > 0 && (size_t)result < bufsize) {
		/* Keep on reading */
		for (;;) {
			temp = pread64(fd,
			               (byte_t *)buf + (size_t)result,
			               bufsize - (size_t)result,
			               offset + (size_t)result);
			if (temp <= 0) {
				result = temp;
				break;
			}
			result += temp;
			if ((size_t)result >= bufsize)
				break;
		}
	}
	return result;
}

@@>> pwriteall64(3)
@@Same as `writeall(3)', but using `pwrite64(2)' instead of `write()'
[[cp, off64_variant_of(pwriteall), section(".text.crt.io.large.write")]]
[[userimpl, requires_function(pwrite64)]]
ssize_t pwriteall64($fd_t fd, [[inp(bufsize)]] void *buf, size_t bufsize, __PIO_OFFSET64 offset) {
	ssize_t result, temp;
	result = pwrite64(fd, buf, bufsize, offset);
	if (result > 0 && (size_t)result < bufsize) {
		/* Keep on writing */
		for (;;) {
			temp = pwrite64(fd,
			                (byte_t *)buf + (size_t)result,
			                bufsize - (size_t)result,
			                offset + (size_t)result);
			if (temp <= 0) {
				result = temp;
				break;
			}
			result += temp;
			if ((size_t)result >= bufsize)
				break;
		}
	}
	return result;
}
%#endif /* __USE_KOS */

%#endif /* __USE_LARGEFILE64 */
%#endif /* __USE_UNIX98 || __USE_XOPEN2K8 */

%
%
%#ifdef __USE_GNU
%{
#ifndef __environ_defined
#define __environ_defined 1
#undef environ
#if defined(__CRT_HAVE_environ)
__LIBC char **environ;
#define environ environ
#elif defined(__CRT_HAVE__environ) && !defined(__NO_ASMNAME)
__LIBC char **environ __ASMNAME("_environ");
#define environ environ
#elif defined(__CRT_HAVE__environ)
#undef _environ
#ifndef ___environ_defined
#define ___environ_defined 1
__LIBC char **_environ;
#endif /* !___environ_defined */
#define environ _environ
#elif defined(__CRT_HAVE___p__environ)
#ifndef ____p__environ_defined
#define ____p__environ_defined 1
__CDECLARE(__ATTR_WUNUSED __ATTR_CONST __ATTR_RETNONNULL,char ***,__NOTHROW,__p__environ,(void),())
#endif /* !____p__environ_defined */
#define environ   (*__p__environ())
#else
#undef __environ_defined
#endif
#endif /* !__environ_defined */
}


[[section(".text.crt.io.access")]]
[[userimpl, requires_function(pipe)]]
int pipe2([[nonnull]] $fd_t pipedes[2], $oflag_t flags) {
	(void)flags;
	return pipe(pipedes);
}

[[section(".text.crt.io.access")]]
[[userimpl, requires_function(dup2)]]
$fd_t dup3($fd_t oldfd, $fd_t newfd, $oflag_t flags) {
	(void)flags;
	return newfd != oldfd ? dup2(oldfd, newfd) : -1;
}

[[cp, ATTR_WUNUSED, ATTR_MALLOC]]
[[section(".text.crt.fs.basic_property")]]
[[userimpl, requires_function(getcwd)]]
char *get_current_dir_name() {
	return getcwd(NULL, 0);
}

[[cp, userimpl, section(".text.crt.fs.modify")]]
int syncfs($fd_t fd) {
	(void)fd;
	/* NO-OP */
	return 0;
}

%[default_impl_section(".text.crt.sched.user")];

int group_member($gid_t gid);
int getresuid($uid_t *ruid, $uid_t *euid, $uid_t *suid);
int getresgid($gid_t *rgid, $gid_t *egid, $gid_t *sgid);
int setresuid($uid_t ruid, $uid_t euid, $uid_t suid);
int setresgid($gid_t rgid, $gid_t egid, $gid_t sgid);
%#endif /* __USE_GNU */

%#if (defined(__USE_XOPEN_EXTENDED) && !defined(__USE_XOPEN2K8)) || \
%     defined(__USE_MISC)

@@Hidden function exported by DOS that allows for millisecond precision
[[cp, ignore, nocrt, alias("__crtSleep", "delay")]]
void __crtSleep(__UINT32_TYPE__ msecs);


@@Sleep for `useconds' microseconds (1/1.000.000 seconds)
[[cp, section(".text.crt.system.utility")]]
[[userimpl, requires_function(__crtSleep)]]
int usleep($useconds_t useconds) {
	__crtSleep(useconds / 1000l); /*USEC_PER_MSEC*/
	return 0;
}

[[cp, ATTR_DEPRECATED("Use getcwd()")]]
[[section(".text.crt.fs.basic_property")]]
[[userimpl, requires_function(getcwd)]]
char *getwd([[nonnull]] char *buf) {
	return getcwd(buf, (size_t)-1);
}

[[section(".text.crt.system.utility")]]
$useconds_t ualarm($useconds_t value, $useconds_t interval);

%
@@>> vfork(2)
@@Same as `fork(2)', but possibly suspend the calling process until the
@@child process either calls `exit(2)' or one of the many `exec(2)' functions
[[guard, section(".text.crt.sched.access"), export_alias("__vfork")]]
[[ATTR_RETURNS_TWICE, ATTR_WUNUSED]]
$pid_t vfork();
%#endif /* (__USE_XOPEN_EXTENDED && !__USE_XOPEN2K8) || __USE_MISC */

%
@@>> fchown(2)
@@Change the ownership of a given `FD' to `GROUP:OWNER'
[[cp, section(".text.crt.fs.modify")]]
int fchown($fd_t fd, $uid_t owner, $gid_t group);

%
@@>> chdir(2)
@@Change the current working directory to `PATH'
[[cp, section(".text.crt.fs.basic_property")]]
int fchdir($fd_t fd);

%
@@>> getpgid(2)
@@Return the ID of the process group associated with `PID's process.
@@(That is the TID of the leader of the process group of `PID's leader)
@@THREAD[PID]->LEADER->GROUP_LEADER->PID
@@When `PID' is ZERO(0), use `gettid()' for it instead
[[ATTR_WUNUSED, section(".text.crt.sched.user"), export_alias("__getpgid")]]
$pid_t getpgid($pid_t pid);

%
@@>> getsid(2)
@@Return the ID of the session which a process `PID' is apart of.
@@return THREAD[PID]->LEADER->GROUP_LEADER->SESSION_LEADER->PID;
[[ATTR_WUNUSED, section(".text.crt.sched.process")]]
$pid_t getsid($pid_t pid);

%
@@>> lchown(2)
@@Change the ownership of a given `FILE' to `GROUP:OWNER',
@@but don't reference it if that file is a symbolic link
[[cp, section(".text.crt.fs.modify")]]
[[userimpl, requires(defined(__CRT_AT_FDCWD) && $has_function(fchownat))]]
int lchown([[nonnull]] char const *file, $uid_t owner, $gid_t group) {
	return fchownat(__CRT_AT_FDCWD, file, owner, group, 0x0100); /* AT_SYMLINK_NOFOLLOW */
}


%
%{
#if defined(__USE_XOPEN_EXTENDED) || defined(__USE_XOPEN2K8)
#ifndef __PIO_OFFSET
#ifdef __USE_KOS
#define __PIO_OFFSET     __FS_TYPE(pos)
#define __PIO_OFFSET64   __pos64_t
#else /* __USE_KOS */
#define __PIO_OFFSET     __FS_TYPE(off)
#define __PIO_OFFSET64   __off64_t
#endif /* !__USE_KOS */
#endif /* !__PIO_OFFSET */
}

[[doc_alias("truncate"), ignore, nocrt, alias("truncate")]]
int truncate32([[nonnull]] char const *file, $pos32_t length);


%
@@>> truncate(2)
@@Truncate the given file `FILE' to a length of `LENGTH'
[[decl_prefix(DEFINE_PIO_OFFSET), no_crt_self_import]]
[[if(defined(__USE_FILE_OFFSET64)), preferred_alias("truncate64")]]
[[if(!defined(__USE_FILE_OFFSET64)), preferred_alias("truncate")]]
[[section(".text.crt.fs.modify")]]
[[userimpl, requires($has_function(truncate64) || $has_function(truncate32) || ($has_function(open) && $has_function(ftruncate)))]]
int truncate([[nonnull]] char const *file, __PIO_OFFSET length) {
@@pp_if $has_function(truncate32)@@
	return truncate32(file, (__pos32_t)length);
@@pp_elif $has_function(truncate64)@@
	return truncate64(file, (__PIO_OFFSET64)length);
@@pp_else@@
	int result;
	fd_t fd;
	fd = open(file, 1); /* O_WRONLY */
	if __unlikely(fd < 0)
		return -1;
	result = ftruncate(fd, length);
@@pp_if $has_function(close)@@
	close(fd);
@@pp_endif@@
	return result;
@@pp_endif@@
}

%
%#ifdef __USE_LARGEFILE64
@@>> truncate64(2)
@@Truncate the given file `FILE' to a length of `LENGTH'
[[off64_variant_of(truncate), impl_prefix(DEFINE_PIO_OFFSET), section(".text.crt.fs.modify")]]
[[userimpl, requires($has_function(truncate32) || ($has_function(open64) && $has_function(ftruncate64)))]]
int truncate64([[nonnull]] char const *file, __PIO_OFFSET64 length) {
@@pp_if $has_function(truncate32)@@
	return truncate32(file, (__PIO_OFFSET)length);
@@pp_else@@
	int result;
	$fd_t fd;
	fd = open64(file, 1); /* O_WRONLY */
	if __unlikely(fd < 0)
		return -1;
	result = ftruncate64(fd, length);
@@pp_ $has_function(close)@@
	close(fd);
@@pp_endif@@
	return result;
@@pp_endif@@
}
%#endif /* __USE_LARGEFILE64 */
%#endif /* __USE_XOPEN_EXTENDED || __USE_XOPEN2K8 */
%
%#ifdef __USE_XOPEN2K8

%
@@>> fexecve(2)
@@Replace the calling process with the application image referred to by `FD' and
@@execute it's `main()' method, passing the given `ARGV', and setting `environ' to `ENVP'
[[cp, guard, argument_names(fd, ___argv, ___envp), section(".text.crt.fs.exec.exec")]]
int fexecve($fd_t fd, [[nonnull]] __TARGV, [[nonnull]] __TENVP);

%#endif /* __USE_XOPEN2K8 */

%
%#ifdef __USE_GNU
%[insert:extern(execvpe)]
%#endif /* __USE_GNU */


%
%#if defined(__USE_MISC) || defined(__USE_XOPEN)
[[section(".text.crt.sched.param"), userimpl]]
int nice(int inc) {
	(void)inc;
	/* It should be sufficient to emulate this is a no-op. */
	return 0;
}
%#endif /* __USE_MISC || __USE_XOPEN */

%
%[insert:extern(_exit)]


%
%#ifdef __USE_POSIX2

@@Retrieve a system configuration string specified by `name'
@@@param: name:   One of `_CS_*' from <bits/confname.h>
@@@param: buf:    Target buffer
@@@param: buflen: Available buffer size (including a trailing \0-character)
@@@return: * :    Required buffer size (including a trailing \0-character)
@@@return: 1 :    Empty configuration string.
@@@return: 0 :    [errno=EINVAL] Bad configuration `name'.
[[section(".text.crt.system.configuration")]]
size_t confstr(int name, char *buf, size_t buflen);

%
%[push_macro @undef { optarg optind opterr optopt }]%{
#ifdef __CRT_HAVE_optarg
__LIBC char *optarg;
#endif /* __CRT_HAVE_optarg */
#ifdef __CRT_HAVE_optind
__LIBC int optind;
#endif /* __CRT_HAVE_optind */
#ifdef __CRT_HAVE_opterr
__LIBC int opterr;
#endif /* __CRT_HAVE_opterr */
#ifdef __CRT_HAVE_optopt
__LIBC int optopt;
#endif /* __CRT_HAVE_optopt */
}
%[pop_macro]
%


[[guard, ATTR_WUNUSED, section(".text.crt.application.options")]]
[[if(defined(__USE_POSIX2) && !defined(__USE_POSIX_IMPLICITLY) && !defined(__USE_GNU)), preferred_alias(__posix_getopt)]]
[[crt_name("getopt"), exposed_name("getopt")]]
int unistd_getopt(int argc, char *const argv[], char const *shortopts);

%#endif /* __USE_POSIX2 */

%
%#if defined(__USE_MISC) || defined(__USE_XOPEN_EXTENDED)

%
@@>> sync(2)
@@Synchronize all disk operations of all mounted file systems and flush
@@unwritten buffers down to the hardware layer, ensuring that modifications
@@made become visible on the underlying, persistent media
[[cp, userimpl, section(".text.crt.fs.modify")]] void sync() {
	/* NO-OP */
}

%
@@>> setpgrp(3)
@@Move the calling process into its own process group.
@@Equivalent to `setpgid(0, 0)'
[[section(".text.crt.sched.process")]]
int setpgrp();

%
%/* ... */
[[section(".text.crt.sched.user")]]
int setreuid($uid_t ruid, $uid_t euid);

%
%/* ... */
[[section(".text.crt.sched.user")]]
int setregid($gid_t rgid, $gid_t egid);

%
%/* ... */
[[section(".text.crt.system.configuration")]]
[[ATTR_WUNUSED]] long int gethostid();

%#if defined(__USE_MISC) || !defined(__USE_XOPEN2K)
@@>> getpagesize(3)
@@Return the size of a PAGE (in bytes)
[[ATTR_CONST, ATTR_WUNUSED, export_alias("__getpagesize")]]
[[requires_include("<asm/pagesize.h>"), requires(defined(__ARCH_PAGESIZE))]]
[[section(".text.crt.system.configuration")]]
int getpagesize() {
	return __ARCH_PAGESIZE;
}

%
%/* ... */
[[ATTR_CONST, ATTR_WUNUSED, section(".text.crt.system.configuration")]]
int getdtablesize() {
#if defined(__KOS__)
	return 0x7fffffff; /* INT_MAX */
#elif defined(__linux__) || defined(__linux) || defined(linux)
	return 0x10000;    /* UINT16_MAX + 1 */
#else
	return 256;        /* UINT8_MAX + 1 */
#endif
}

%#endif /* __USE_MISC || !__USE_XOPEN2K */
%#endif /* __USE_MISC || __USE_XOPEN_EXTENDED */

%
%#ifdef __USE_XOPEN2K

@@>> seteuid(2)
@@Set the effective user ID of the calling process
@@@return: 0 : Success
@@@return: -1: [errno=EINVAL] : The given `EUID' is invalid
@@@return: -1: [errno=EPERM]  : The current user is not privileged
[[section(".text.crt.sched.user")]]
int seteuid($uid_t euid);

%
@@>> setegid(2)
@@Set the effective group ID of the calling process
@@@return: 0 : Success
@@@return: -1: [errno=EINVAL] : The given `EGID' is invalid
@@@return: -1: [errno=EPERM]  : The current user is not privileged
[[section(".text.crt.sched.user")]]
int setegid($gid_t egid);

%#endif /* __USE_XOPEN2K */

%
%#if defined(__USE_MISC) || \
%   (defined(__USE_XOPEN_EXTENDED) && !defined(__USE_UNIX98))

%/* ... */
[[ATTR_WUNUSED, section(".text.crt.io.tty")]]
int ttyslot();

%#endif

%
%#if defined(__USE_XOPEN_EXTENDED) || defined(__USE_XOPEN2K)

@@>> symlink(3)
@@Create a new symbolic link loaded with `LINK_TEXT' as link
@@text, at the filesystem location referred to by `TARGET_PATH'.
@@Same as `symlinkat(LINK_TEXT, AT_FDCWD, TARGET_PATH)'
[[cp, section(".text.crt.fs.modify")]]
[[userimpl, requires(defined(__CRT_AT_FDCWD) && $has_function(symlinkat))]]
int symlink([[nonnull]] char const *link_text, [[nonnull]] char const *target_path) {
	/* TODO: Header-implementation for `symlink()' on DOS (using the windows API) */
	return symlinkat(link_text, __CRT_AT_FDCWD, target_path);
}

%
@@>> readlink(3)
@@Read the text of a symbolic link under `PATH' into the provided buffer.
@@Same as `readlinkat(AT_FDCWD, PATH, BUF, BUFLEN)'
@@WARNING: This function is badly designed and will neither append a trailing
@@         NUL-character to the buffer, nor will it return the required buffer
@@         size. Instead, it will return the written size, and the caller must
@@         keep on over allocating until the function indicates that it didn't
@@         make use of the buffer in its entirety.
@@When targeting KOS, consider using `freadlinkat(2)' with `AT_READLINK_REQSIZE'
[[cp, section(".text.crt.fs.property")]]
[[userimpl, requires(defined(__CRT_AT_FDCWD) && $has_function(readlinkat))]]
ssize_t readlink([[nonnull]] char const *__restrict path,
                 [[outp(buflen)]] char *__restrict buf, size_t buflen) {
	return readlinkat(__CRT_AT_FDCWD, path, buf, buflen);
}

%#endif /* __USE_XOPEN_EXTENDED || __USE_XOPEN2K */

%
%#if defined(__USE_REENTRANT) || defined(__USE_POSIX199506)
[[cp, section(".text.crt.io.tty")]]
int getlogin_r([outp(name_len)] char *name, size_t name_len);
%#endif /* __USE_REENTRANT || __USE_POSIX199506 */

%
%#if defined(__USE_UNIX98) || defined(__USE_XOPEN2K)
@@>> gethostname(3)
@@Return the name assigned to the hosting machine, as set by `sethostname(2)'
[[section(".text.crt.system.configuration")]]
int gethostname([[outp(buflen)]] char *name, size_t buflen);
%#endif /* __USE_UNIX98 || __USE_XOPEN2K */

%
%#ifdef __USE_MISC
%/* ... */
[[section(".text.crt.io.tty")]]
int setlogin([[nonnull]] char const *name);

%
@@>> sethostname(2)
@@Set the name of the hosting machine
[[section(".text.crt.system.configuration")]]
int sethostname([[inp(len)]] char const *name, size_t len);


%
%/* ... */
[[section(".text.crt.system.configuration")]]
int sethostid(long int id);

%
@@>> getdomainname(3)
@@Return the name assigned to the hosting machine's domain, as set by `setdomainname(2)'
[[section(".text.crt.system.configuration")]]
int getdomainname([[outp(buflen)]] char *name, size_t buflen);

%
@@>> setdomainname(2)
@@Set the name of the hosting machine's domain
[[section(".text.crt.system.configuration")]]
int setdomainname([[inp(len)]] char const *name, size_t len);

%
%/* ... */
[[section(".text.crt.io.tty")]]
int vhangup();

%
%/* ... */
[[section(".text.crt.system.utility")]]
int profil([[nonnull]] unsigned short int *sample_buffer,
           size_t size, size_t offset, unsigned int scale);

%
%/* ... */
[[cp, ATTR_WUNUSED, section(".text.crt.database.shell")]]
char *getusershell();

%
%/* ... */
[[section(".text.crt.database.shell")]]
void endusershell();

%
%/* ... */
[[cp, section(".text.crt.database.shell")]]
void setusershell();

%
%/* ... */
[[cp, section(".text.crt.system.utility")]]
int daemon(int nochdir, int noclose);

%
%/* ... */
[[cp, section(".text.crt.fs.modify")]]
int revoke([[nonnull]] char const *file);

%
%[insert:extern(acct)]

[[cp, section(".text.crt.system.utility")]]
long int syscall(long int sysno, ...);

%
%#ifdef __USE_KOS
[[cp, section(".text.crt.system.utility"), preferred_alias("syscall")]]
__LONG64_TYPE__ syscall64(__syscall_ulong_t sysno, ...);
%#endif /* __USE_KOS */
%

%[insert:extern(getentropy)]
%#endif /* __USE_MISC */

%
%#if defined(__USE_MISC) || \
%   (defined(__USE_XOPEN) && !defined(__USE_XOPEN2K))
@@>> chroot(2)
@@Change the root directory of the calling `CLONE_FS' group of threads
@@(usually the process) to a path that was previously address by `PATH'
[[cp, section(".text.crt.fs.utility")]]
int chroot([[nonnull]] char const *__restrict path);

%
%/* ... */
[[cp, ATTR_WUNUSED, section(".text.crt.io.tty")]]
char *getpass([[nonnull]] char const *__restrict prompt);
%#endif /* ... */

%
%#if defined(__USE_POSIX199309) || defined(__USE_XOPEN_EXTENDED) || defined(__USE_XOPEN2K)

[[doc_alias(ftruncate), ignore, nocrt, alias("ftruncate")]]
int ftruncate32($fd_t fd, __pos32_t length);

@@>> ftruncate(2)
@@Truncate the given file `FD' to a length of `LENGTH'
[[decl_prefix(DEFINE_PIO_OFFSET), no_crt_self_import]]
[[if(defined(__USE_FILE_OFFSET64)), preferred_alias("ftruncate64", "_chsize_s")]]
[[if(!defined(__USE_FILE_OFFSET64)), preferred_alias("ftruncate", "_chsize", "chsize")]]
[[userimpl, requires($has_function(ftruncate32) || $has_function(ftruncate64))]]
[[export_as("_chsize", "chsize"), section(".text.crt.io.write")]]
int ftruncate($fd_t fd, __PIO_OFFSET length) {
@@pp_if $has_function(ftruncate32)@@
	return ftruncate32(fd, (__pos32_t)length);
@@pp_else@@
	return ftruncate64(fd, (__pos64_t)length);
@@pp_endif@@
}

%
%#ifdef __USE_LARGEFILE64
@@>> ftruncate64(2)
@@Truncate the given file `FD' to a length of `LENGTH'
[[off64_variant_of(ftruncate), decl_prefix(DEFINE_PIO_OFFSET)]]
[[export_alias("_chsize_s"), section(".text.crt.io.large.write")]]
[[userimpl, requires_function(ftruncate32)]]
int ftruncate64($fd_t fd, __PIO_OFFSET64 length) {
	return ftruncate32(fd, (pos32_t)length);
}
%#endif /* __USE_LARGEFILE64 */
%#endif /* __USE_POSIX199309 || __USE_XOPEN_EXTENDED || __USE_XOPEN2K */

%
%#if (defined(__USE_XOPEN_EXTENDED) && !defined(__USE_XOPEN2K)) || \
%     defined(__USE_MISC)
@@>> brk(2), sbrk(2)
@@Change the program break, allowing for a rudimentary implementation of a heap.
@@It is recommended to use the much more advanced functions found in <sys/mman.h> instead
[[section(".text.crt.heap.utility")]]
int brk(void *addr);

[[section(".text.crt.heap.utility"), export_alias("__sbrk")]]
void *sbrk(intptr_t delta);
%#endif

%
%#if defined(__USE_POSIX199309) || defined(__USE_UNIX98)
@@>> fdatasync(2)
@@Synchronize only the data of a file (not its descriptor which contains
@@timestamps, and its size), meaning that changes are written to disk
[[cp, alias("fsync", "_commit"), userimpl, section(".text.crt.io.sync")]]
int fdatasync($fd_t fd) {
	(void)fd;
	/* NO-OP */
	return 0;
}
%#endif /* __USE_POSIX199309 || __USE_UNIX98 */

%
%#ifdef __USE_XOPEN
%[insert:extern(crypt)]
%[insert:extern(encrypt)]

%
@@Copy `n_bytes & ~1' (FLOOR_ALIGN(n_bytes, 2)) from `from' to `to',
@@exchanging the order of even and odd bytes ("123456" --> "214365")
@@When `n_bytes <= 1', don't do anything and return immediately
[[guard, export_alias("_swab"), section(".text.crt.string.memory")]]
void swab([[nonnull]] void const *__restrict from,
          [[nonnull]] void *__restrict to, __STDC_INT_AS_SSIZE_T n_bytes) {
	n_bytes &= ~1;
	while (n_bytes >= 2) {
		byte_t a, b;
		a = ((byte_t *)from)[--n_bytes];
		b = ((byte_t *)from)[--n_bytes];
		((byte_t *)to)[n_bytes+0] = a;
		((byte_t *)to)[n_bytes+1] = b;
	}
}

%#endif /* __USE_XOPEN */

%
%
%#if (defined(_EVERY_SOURCE) || \
%     (defined(__USE_XOPEN) && !defined(__USE_XOPEN2K)))
%/* ... */
[[guard, section(".text.crt.io.tty")]]
char *ctermid(char *s);

%[insert:extern(cuserid)]
%#endif /* _EVERY_SOURCE || (__USE_XOPEN && !__USE_XOPEN2K) */


%
%
%#if (defined(_EVERY_SOURCE) || \
%     (defined(__USE_UNIX98) && !defined(__USE_XOPEN2K)))
%#ifndef ____pthread_atfork_func_t_defined
%#define ____pthread_atfork_func_t_defined 1
%typedef void (__LIBCCALL *__pthread_atfork_func_t)(void);
%#endif /* !____pthread_atfork_func_t_defined */
%
%[insert:extern(pthread_atfork)]
%#endif /* _EVERY_SOURCE || (__USE_UNIX98 && !__USE_XOPEN2K) */


%
%
%#ifdef __USE_REENTRANT
@@Same as `ctermid', but return `NULL' when `S' is `NULL'
[[guard, section(".text.crt.io.tty")]]
[[userimpl, requires($has_function(ctermid))]]
char *ctermid_r([[nullable]] char *s) {
	return s ? ctermid(s) : NULL;
}
%#endif /* __USE_REENTRANT */

%
%
@@>> sysconf(2)
@@@param: NAME: One of `_SC_*' from <bits/confname.h>
@@Return a system configuration value `NAME'
@@return: * : The configuration limit associated with `NAME' for `PATH'
@@return: -1: [errno=<unchanged>] `NAME' referrs to a maximum or minimum
@@                                limit, and that limit is indeterminate
@@return: -1: [errno=EINVAL]      The given `NAME' isn't a recognized config option
[[cp, ATTR_WUNUSED, section(".text.crt.system.configuration")]]
[[export_alias("_sysconf", "__sysconf")]]
long int sysconf(int name);


%
%
%#if defined(__USE_MISC) || (defined(__USE_XOPEN_EXTENDED) && !defined(__USE_POSIX))
%#ifndef F_LOCK
%#define F_ULOCK 0 /* Unlock a previously locked region. */
%#define F_LOCK  1 /* Lock a region for exclusive use. */
%#define F_TLOCK 2 /* Test and lock a region for exclusive use. */
%#define F_TEST  3 /* Test a region for other processes locks. */
%#endif /* !F_LOCK */
%[insert:extern(lockf)]
%#ifdef __USE_LARGEFILE64
%[insert:extern(lockf64)]
%#endif /* __USE_LARGEFILE64 */
%#endif /* __USE_MISC || (__USE_XOPEN_EXTENDED && !__USE_POSIX) */
%
%
%{
#ifdef __USE_GNU
#if defined(__COMPILER_HAVE_AUTOTYPE) && defined(__COMPILER_HAVE_TYPEOF)
#define TEMP_FAILURE_RETRY(expression)                     \
	__XBLOCK({                                             \
		__auto_type __result;                              \
		do {                                               \
			__result = (expression);                       \
		} while (__result == (__typeof__(__result)) - 1 && \
		         errno == EINTR);                          \
		__XRETURN __result;                                \
	})
#elif defined(__COMPILER_HAVE_TYPEOF)
#define TEMP_FAILURE_RETRY(expression)                     \
	__XBLOCK({                                             \
		__typeof__(expression) __result;                   \
		do {                                               \
			__result = (expression);                       \
		} while (__result == (__typeof__(__result)) - 1 && \
		         errno == EINTR);                          \
		__XRETURN __result;                                \
	})
#else /* __COMPILER_HAVE_TYPEOF */
#define TEMP_FAILURE_RETRY(expression)               \
	__XBLOCK({                                       \
		long int __result;                           \
		do {                                         \
			__result = (long int)(expression);       \
		} while (__result == -1L && errno == EINTR); \
		__XRETURN __result;                          \
	})
#endif /* !__COMPILER_HAVE_TYPEOF */
#endif /* __USE_GNU */

#endif /* __CC__ */

__SYSDECL_END

#ifdef __USE_KOS
#if defined(_WCHAR_H) && !defined(_PARTS_WCHAR_UNISTD_H)
#include <parts/wchar/unistd.h>
#endif /* _WCHAR_H && !_PARTS_WCHAR_UNISTD_H */
#endif /* __USE_KOS */

#ifdef __USE_UTF
#if defined(_UCHAR_H) && !defined(_PARTS_UCHAR_UNISTD_H)
#include <parts/uchar/unistd.h>
#endif /* _UCHAR_H && !_PARTS_UCHAR_UNISTD_H */
#endif /* __USE_UTF */

}

