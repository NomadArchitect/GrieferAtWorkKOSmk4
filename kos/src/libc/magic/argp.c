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
%(c_prefix){
/* (#) Portability: EMX kLIBC     (/libc/include/argp.h) */
/* (#) Portability: GNU C Library (/argp/argp.h) */
/* (#) Portability: GNU Hurd      (/usr/include/argp.h) */
/* (#) Portability: libc6         (/include/argp.h) */
/* (#) Portability: mintlib       (/include/argp.h) */
}

%[default:section(".text.crt{|.dos}.compat.glibc.string.argp")]
%[define_partial_replacement(argc = ___argc)]
%[define_partial_replacement(argv = ___argv)]

%[define_decl_include("<bits/crt/argp.h>": [
	"struct argp",
	"struct argp_state",
	"struct argp_child",
	"struct argp_option",
	"__argp_parser_t",
])]

%(auto_header){
#include <stdio.h> /* FILE */
}

%(auto_source){
#include "../libc/globals.h"
#include <sysexits.h> /* for `EX_USAGE' */
}

%[insert:prefix(
#include <features.h>
)]%[insert:prefix(
#include <bits/types.h>
)]%[insert:prefix(
#include <bits/crt/argp.h>
)]%{

#ifdef __USE_GLIBC_BLOAT
#include <ctype.h>
#include <errno.h>
#include <getopt.h>
#include <limits.h>
#include <stdio.h>
#endif /* __USE_GLIBC_BLOAT */

/* ??? */
#if !defined(OPTION_ARG_OPTIONAL) && defined(__OPTION_ARG_OPTIONAL)
#define OPTION_ARG_OPTIONAL __OPTION_ARG_OPTIONAL /* ??? */
#endif /* !OPTION_ARG_OPTIONAL && __OPTION_ARG_OPTIONAL */
#if !defined(OPTION_HIDDEN) && defined(__OPTION_HIDDEN)
#define OPTION_HIDDEN __OPTION_HIDDEN /* Hide from `--help' */
#endif /* !OPTION_HIDDEN && __OPTION_HIDDEN */
#if !defined(OPTION_ALIAS) && defined(__OPTION_ALIAS)
#define OPTION_ALIAS __OPTION_ALIAS /* Alias for the last preceding non-OPTION_ALIAS option. */
#endif /* !OPTION_ALIAS && __OPTION_ALIAS */
#if !defined(OPTION_DOC) && defined(__OPTION_DOC)
#define OPTION_DOC __OPTION_DOC /* ??? */
#endif /* !OPTION_DOC && __OPTION_DOC */
#if !defined(OPTION_NO_USAGE) && defined(__OPTION_NO_USAGE)
#define OPTION_NO_USAGE __OPTION_NO_USAGE /* ??? */
#endif /* !OPTION_NO_USAGE && __OPTION_NO_USAGE */

/* ??? */
#if !defined(ARGP_ERR_UNKNOWN) && defined(__ARGP_ERR_UNKNOWN)
#define ARGP_ERR_UNKNOWN __ARGP_ERR_UNKNOWN /* ??? */
#endif /* !ARGP_ERR_UNKNOWN && __ARGP_ERR_UNKNOWN */

/* ??? */
#if !defined(ARGP_KEY_ARG) && defined(__ARGP_KEY_ARG)
#define ARGP_KEY_ARG __ARGP_KEY_ARG /* ??? */
#endif /* !ARGP_KEY_ARG && __ARGP_KEY_ARG */
#if !defined(ARGP_KEY_END) && defined(__ARGP_KEY_END)
#define ARGP_KEY_END __ARGP_KEY_END /* ??? */
#endif /* !ARGP_KEY_END && __ARGP_KEY_END */
#if !defined(ARGP_KEY_NO_ARGS) && defined(__ARGP_KEY_NO_ARGS)
#define ARGP_KEY_NO_ARGS __ARGP_KEY_NO_ARGS /* ??? */
#endif /* !ARGP_KEY_NO_ARGS && __ARGP_KEY_NO_ARGS */
#if !defined(ARGP_KEY_INIT) && defined(__ARGP_KEY_INIT)
#define ARGP_KEY_INIT __ARGP_KEY_INIT /* ??? */
#endif /* !ARGP_KEY_INIT && __ARGP_KEY_INIT */
#if !defined(ARGP_KEY_SUCCESS) && defined(__ARGP_KEY_SUCCESS)
#define ARGP_KEY_SUCCESS __ARGP_KEY_SUCCESS /* ??? */
#endif /* !ARGP_KEY_SUCCESS && __ARGP_KEY_SUCCESS */
#if !defined(ARGP_KEY_ERROR) && defined(__ARGP_KEY_ERROR)
#define ARGP_KEY_ERROR __ARGP_KEY_ERROR /* ??? */
#endif /* !ARGP_KEY_ERROR && __ARGP_KEY_ERROR */
#if !defined(ARGP_KEY_ARGS) && defined(__ARGP_KEY_ARGS)
#define ARGP_KEY_ARGS __ARGP_KEY_ARGS /* ??? */
#endif /* !ARGP_KEY_ARGS && __ARGP_KEY_ARGS */
#if !defined(ARGP_KEY_FINI) && defined(__ARGP_KEY_FINI)
#define ARGP_KEY_FINI __ARGP_KEY_FINI /* ??? */
#endif /* !ARGP_KEY_FINI && __ARGP_KEY_FINI */

/* ??? */
#if !defined(ARGP_KEY_HELP_PRE_DOC) && defined(__ARGP_KEY_HELP_PRE_DOC)
#define ARGP_KEY_HELP_PRE_DOC __ARGP_KEY_HELP_PRE_DOC /* ??? */
#endif /* !ARGP_KEY_HELP_PRE_DOC && __ARGP_KEY_HELP_PRE_DOC */
#if !defined(ARGP_KEY_HELP_POST_DOC) && defined(__ARGP_KEY_HELP_POST_DOC)
#define ARGP_KEY_HELP_POST_DOC __ARGP_KEY_HELP_POST_DOC /* ??? */
#endif /* !ARGP_KEY_HELP_POST_DOC && __ARGP_KEY_HELP_POST_DOC */
#if !defined(ARGP_KEY_HELP_HEADER) && defined(__ARGP_KEY_HELP_HEADER)
#define ARGP_KEY_HELP_HEADER __ARGP_KEY_HELP_HEADER /* ??? */
#endif /* !ARGP_KEY_HELP_HEADER && __ARGP_KEY_HELP_HEADER */
#if !defined(ARGP_KEY_HELP_EXTRA) && defined(__ARGP_KEY_HELP_EXTRA)
#define ARGP_KEY_HELP_EXTRA __ARGP_KEY_HELP_EXTRA /* ??? */
#endif /* !ARGP_KEY_HELP_EXTRA && __ARGP_KEY_HELP_EXTRA */
#if !defined(ARGP_KEY_HELP_DUP_ARGS_NOTE) && defined(__ARGP_KEY_HELP_DUP_ARGS_NOTE)
#define ARGP_KEY_HELP_DUP_ARGS_NOTE __ARGP_KEY_HELP_DUP_ARGS_NOTE /* ??? */
#endif /* !ARGP_KEY_HELP_DUP_ARGS_NOTE && __ARGP_KEY_HELP_DUP_ARGS_NOTE */
#if !defined(ARGP_KEY_HELP_ARGS_DOC) && defined(__ARGP_KEY_HELP_ARGS_DOC)
#define ARGP_KEY_HELP_ARGS_DOC __ARGP_KEY_HELP_ARGS_DOC /* ??? */
#endif /* !ARGP_KEY_HELP_ARGS_DOC && __ARGP_KEY_HELP_ARGS_DOC */

/* Possible flags for `argp_parse::flags' */
#if !defined(ARGP_PARSE_ARGV0) && defined(__ARGP_PARSE_ARGV0)
#define ARGP_PARSE_ARGV0 __ARGP_PARSE_ARGV0 /* Don't skip over `argv[0]' */
#endif /* !ARGP_PARSE_ARGV0 && __ARGP_PARSE_ARGV0 */
#if !defined(ARGP_NO_ERRS) && defined(__ARGP_NO_ERRS)
#define ARGP_NO_ERRS __ARGP_NO_ERRS /* Don't print error messages about unknown options to stderr. Implies `ARGP_NO_EXIT' */
#endif /* !ARGP_NO_ERRS && __ARGP_NO_ERRS */
#if !defined(ARGP_NO_ARGS) && defined(__ARGP_NO_ARGS)
#define ARGP_NO_ARGS __ARGP_NO_ARGS /* Don't parse non-option arguments (iow: ones that don't start with `-'). Else, invoke `argp::parser' with `key=ARGP_KEY_ARG' for non-option arguments. */
#endif /* !ARGP_NO_ARGS && __ARGP_NO_ARGS */
#if !defined(ARGP_IN_ORDER) && defined(__ARGP_IN_ORDER)
#define ARGP_IN_ORDER __ARGP_IN_ORDER /* Parse in command-line order, rather than parsing options before arguments. */
#endif /* !ARGP_IN_ORDER && __ARGP_IN_ORDER */
#if !defined(ARGP_NO_HELP) && defined(__ARGP_NO_HELP)
#define ARGP_NO_HELP __ARGP_NO_HELP /* Disable support for a standard `--help' option */
#endif /* !ARGP_NO_HELP && __ARGP_NO_HELP */
#if !defined(ARGP_NO_EXIT) && defined(__ARGP_NO_EXIT)
#define ARGP_NO_EXIT __ARGP_NO_EXIT /* Don't exit on error */
#endif /* !ARGP_NO_EXIT && __ARGP_NO_EXIT */
#if !defined(ARGP_LONG_ONLY) && defined(__ARGP_LONG_ONLY)
#define ARGP_LONG_ONLY __ARGP_LONG_ONLY /* Long options may be written with a single leading "-" */
#endif /* !ARGP_LONG_ONLY && __ARGP_LONG_ONLY */
#if !defined(ARGP_SILENT) && defined(__ARGP_SILENT)
#define ARGP_SILENT __ARGP_SILENT /* Disable extras */
#endif /* !ARGP_SILENT && __ARGP_SILENT */

/* Possible flags for `argp_help::flags' */
#if !defined(ARGP_HELP_USAGE) && defined(__ARGP_HELP_USAGE)
#define ARGP_HELP_USAGE __ARGP_HELP_USAGE /* ??? */
#endif /* !ARGP_HELP_USAGE && __ARGP_HELP_USAGE */
#if !defined(ARGP_HELP_SHORT_USAGE) && defined(__ARGP_HELP_SHORT_USAGE)
#define ARGP_HELP_SHORT_USAGE __ARGP_HELP_SHORT_USAGE /* ??? */
#endif /* !ARGP_HELP_SHORT_USAGE && __ARGP_HELP_SHORT_USAGE */
#if !defined(ARGP_HELP_SEE) && defined(__ARGP_HELP_SEE)
#define ARGP_HELP_SEE __ARGP_HELP_SEE /* ??? */
#endif /* !ARGP_HELP_SEE && __ARGP_HELP_SEE */
#if !defined(ARGP_HELP_LONG) && defined(__ARGP_HELP_LONG)
#define ARGP_HELP_LONG __ARGP_HELP_LONG /* ??? */
#endif /* !ARGP_HELP_LONG && __ARGP_HELP_LONG */
#if !defined(ARGP_HELP_PRE_DOC) && defined(__ARGP_HELP_PRE_DOC)
#define ARGP_HELP_PRE_DOC __ARGP_HELP_PRE_DOC /* ??? */
#endif /* !ARGP_HELP_PRE_DOC && __ARGP_HELP_PRE_DOC */
#if !defined(ARGP_HELP_POST_DOC) && defined(__ARGP_HELP_POST_DOC)
#define ARGP_HELP_POST_DOC __ARGP_HELP_POST_DOC /* ??? */
#endif /* !ARGP_HELP_POST_DOC && __ARGP_HELP_POST_DOC */
#if !defined(ARGP_HELP_DOC) && defined(__ARGP_HELP_DOC)
#define ARGP_HELP_DOC __ARGP_HELP_DOC /* ??? */
#endif /* !ARGP_HELP_DOC && __ARGP_HELP_DOC */
#if !defined(ARGP_HELP_BUG_ADDR) && defined(__ARGP_HELP_BUG_ADDR)
#define ARGP_HELP_BUG_ADDR __ARGP_HELP_BUG_ADDR /* ??? */
#endif /* !ARGP_HELP_BUG_ADDR && __ARGP_HELP_BUG_ADDR */
#if !defined(ARGP_HELP_LONG_ONLY) && defined(__ARGP_HELP_LONG_ONLY)
#define ARGP_HELP_LONG_ONLY __ARGP_HELP_LONG_ONLY /* ??? */
#endif /* !ARGP_HELP_LONG_ONLY && __ARGP_HELP_LONG_ONLY */
#if !defined(ARGP_HELP_EXIT_ERR) && defined(__ARGP_HELP_EXIT_ERR)
#define ARGP_HELP_EXIT_ERR __ARGP_HELP_EXIT_ERR /* ??? */
#endif /* !ARGP_HELP_EXIT_ERR && __ARGP_HELP_EXIT_ERR */
#if !defined(ARGP_HELP_EXIT_OK) && defined(__ARGP_HELP_EXIT_OK)
#define ARGP_HELP_EXIT_OK __ARGP_HELP_EXIT_OK /* ??? */
#endif /* !ARGP_HELP_EXIT_OK && __ARGP_HELP_EXIT_OK */
#if !defined(ARGP_HELP_STD_ERR) && defined(__ARGP_HELP_STD_ERR)
#define ARGP_HELP_STD_ERR __ARGP_HELP_STD_ERR /* ??? */
#endif /* !ARGP_HELP_STD_ERR && __ARGP_HELP_STD_ERR */
#if !defined(ARGP_HELP_STD_USAGE) && defined(__ARGP_HELP_STD_USAGE)
#define ARGP_HELP_STD_USAGE __ARGP_HELP_STD_USAGE /* ??? */
#endif /* !ARGP_HELP_STD_USAGE && __ARGP_HELP_STD_USAGE */
#if !defined(ARGP_HELP_STD_HELP) && defined(__ARGP_HELP_STD_HELP)
#define ARGP_HELP_STD_HELP __ARGP_HELP_STD_HELP /* ??? */
#endif /* !ARGP_HELP_STD_HELP && __ARGP_HELP_STD_HELP */


#ifdef __CC__
__SYSDECL_BEGIN

#ifndef __error_t_defined
#define __error_t_defined
typedef __errno_t error_t;
#endif /* !__error_t_defined */

typedef __argp_parser_t argp_parser_t;

/* Globals... */
#ifndef argp_program_version
#ifdef __LOCAL_argp_program_version
#define argp_program_version __LOCAL_argp_program_version
#elif defined(__CRT_HAVE_argp_program_version)
__CSDECLARE(, char const *, argp_program_version)
#define argp_program_version argp_program_version
#endif /* ... */
#endif /* !argp_program_version */

#ifndef argp_program_version_hook
#ifdef __LOCAL_argp_program_version_hook
#define argp_program_version_hook __LOCAL_argp_program_version_hook
#elif defined(__CRT_HAVE_argp_program_version_hook)
__CSDECLARE(, __argp_program_version_hook_t, argp_program_version_hook)
#define argp_program_version_hook argp_program_version_hook
#endif /* ... */
#endif /* !argp_program_version_hook */

#ifndef argp_program_bug_address
#ifdef __LOCAL_argp_program_bug_address
#define argp_program_bug_address __LOCAL_argp_program_bug_address
#elif defined(__CRT_HAVE_argp_program_bug_address)
__CSDECLARE(, char const *, argp_program_bug_address)
#define argp_program_bug_address argp_program_bug_address
#endif /* ... */
#endif /* !argp_program_bug_address */

#ifndef argp_err_exit_status
#ifdef __LOCAL_argp_err_exit_status
#define argp_err_exit_status __LOCAL_argp_err_exit_status
#elif defined(__CRT_HAVE_argp_err_exit_status)
__CSDECLARE(, int, argp_err_exit_status)
#define argp_err_exit_status argp_err_exit_status
#endif /* ... */
#endif /* !argp_err_exit_status */

}

%[define_replacement(error_t = __errno_t)]

%[define_replacement(OPTION_ARG_OPTIONAL = __OPTION_ARG_OPTIONAL)]
%[define_replacement(OPTION_HIDDEN = __OPTION_HIDDEN)]
%[define_replacement(OPTION_ALIAS = __OPTION_ALIAS)]
%[define_replacement(OPTION_DOC = __OPTION_DOC)]
%[define_replacement(OPTION_NO_USAGE = __OPTION_NO_USAGE)]

%[define_replacement(ARGP_ERR_UNKNOWN = __ARGP_ERR_UNKNOWN)]

%[define_replacement(ARGP_KEY_ARG = __ARGP_KEY_ARG)]
%[define_replacement(ARGP_KEY_END = __ARGP_KEY_END)]
%[define_replacement(ARGP_KEY_NO_ARGS = __ARGP_KEY_NO_ARGS)]
%[define_replacement(ARGP_KEY_INIT = __ARGP_KEY_INIT)]
%[define_replacement(ARGP_KEY_SUCCESS = __ARGP_KEY_SUCCESS)]
%[define_replacement(ARGP_KEY_ERROR = __ARGP_KEY_ERROR)]
%[define_replacement(ARGP_KEY_ARGS = __ARGP_KEY_ARGS)]
%[define_replacement(ARGP_KEY_FINI = __ARGP_KEY_FINI)]

%[define_replacement(ARGP_KEY_HELP_PRE_DOC = __ARGP_KEY_HELP_PRE_DOC)]
%[define_replacement(ARGP_KEY_HELP_POST_DOC = __ARGP_KEY_HELP_POST_DOC)]
%[define_replacement(ARGP_KEY_HELP_HEADER = __ARGP_KEY_HELP_HEADER)]
%[define_replacement(ARGP_KEY_HELP_EXTRA = __ARGP_KEY_HELP_EXTRA)]
%[define_replacement(ARGP_KEY_HELP_DUP_ARGS_NOTE = __ARGP_KEY_HELP_DUP_ARGS_NOTE)]
%[define_replacement(ARGP_KEY_HELP_ARGS_DOC = __ARGP_KEY_HELP_ARGS_DOC)]

%[define_replacement(ARGP_PARSE_ARGV0 = __ARGP_PARSE_ARGV0)]
%[define_replacement(ARGP_NO_ERRS = __ARGP_NO_ERRS)]
%[define_replacement(ARGP_NO_ARGS = __ARGP_NO_ARGS)]
%[define_replacement(ARGP_IN_ORDER = __ARGP_IN_ORDER)]
%[define_replacement(ARGP_NO_HELP = __ARGP_NO_HELP)]
%[define_replacement(ARGP_NO_EXIT = __ARGP_NO_EXIT)]
%[define_replacement(ARGP_LONG_ONLY = __ARGP_LONG_ONLY)]
%[define_replacement(ARGP_SILENT = __ARGP_SILENT)]

%[define_replacement(ARGP_HELP_USAGE = __ARGP_HELP_USAGE)]
%[define_replacement(ARGP_HELP_SHORT_USAGE = __ARGP_HELP_SHORT_USAGE)]
%[define_replacement(ARGP_HELP_SEE = __ARGP_HELP_SEE)]
%[define_replacement(ARGP_HELP_LONG = __ARGP_HELP_LONG)]
%[define_replacement(ARGP_HELP_PRE_DOC = __ARGP_HELP_PRE_DOC)]
%[define_replacement(ARGP_HELP_POST_DOC = __ARGP_HELP_POST_DOC)]
%[define_replacement(ARGP_HELP_DOC = __ARGP_HELP_DOC)]
%[define_replacement(ARGP_HELP_BUG_ADDR = __ARGP_HELP_BUG_ADDR)]
%[define_replacement(ARGP_HELP_LONG_ONLY = __ARGP_HELP_LONG_ONLY)]
%[define_replacement(ARGP_HELP_EXIT_ERR = __ARGP_HELP_EXIT_ERR)]
%[define_replacement(ARGP_HELP_EXIT_OK = __ARGP_HELP_EXIT_OK)]
%[define_replacement(ARGP_HELP_STD_ERR = __ARGP_HELP_STD_ERR)]
%[define_replacement(ARGP_HELP_STD_USAGE = __ARGP_HELP_STD_USAGE)]
%[define_replacement(ARGP_HELP_STD_HELP = __ARGP_HELP_STD_HELP)]



%(auto_source){
#ifndef __KERNEL__
#undef argp_program_version
#undef argp_program_version_hook
#undef argp_program_bug_address
#undef argp_err_exit_status
INTERN ATTR_SECTION(".bss.crt.compat.glibc.string.argp") char const *libc_argp_program_version = NULL;
INTERN ATTR_SECTION(".bss.crt.compat.glibc.string.argp") __argp_program_version_hook_t libc_argp_program_version_hook = NULL;
INTERN ATTR_SECTION(".bss.crt.compat.glibc.string.argp") char const *libc_argp_program_bug_address = NULL;
INTERN ATTR_SECTION(".data.crt.compat.glibc.string.argp") int libc_argp_err_exit_status = EX_USAGE;
DEFINE_PUBLIC_ALIAS(argp_program_version, libc_argp_program_version);
DEFINE_PUBLIC_ALIAS(argp_program_version_hook, libc_argp_program_version_hook);
DEFINE_PUBLIC_ALIAS(argp_program_bug_address, libc_argp_program_bug_address);
DEFINE_PUBLIC_ALIAS(argp_err_exit_status, libc_argp_err_exit_status);
#define argp_program_version      GET_NOREL_GLOBAL(argp_program_version)
#define argp_program_version_hook GET_NOREL_GLOBAL(argp_program_version_hook)
#define argp_program_bug_address  GET_NOREL_GLOBAL(argp_program_bug_address)
#define argp_err_exit_status      GET_NOREL_GLOBAL(argp_err_exit_status)
#endif /* !__KERNEL__ */
}


@@>> argp_parse(3)
@@@param: flags: Set  of  `ARGP_PARSE_ARGV0  | ARGP_NO_ERRS  |  ARGP_NO_ARGS |
@@               ARGP_IN_ORDER | ARGP_NO_HELP | ARGP_NO_EXIT | ARGP_LONG_ONLY'
[[export_alias("__argp_parse")]]
[[decl_include("<bits/crt/argp.h>", "<bits/types.h>")]]
error_t argp_parse([[in]] struct argp const *__restrict ap,
                   int argc, [[in(argc)]] char **__restrict argv,
                   unsigned int flags, [[out]] int *__restrict arg_index,
                   void *input);

%[define_c_language_keyword(__KOS_FIXED_CONST)]

@@>> argp_parse(3)
@@@param: flags: Set of `ARGP_HELP_*'
[[export_alias("__argp_parse")]]
[[decl_include("<features.h>", "<bits/crt/argp.h>")]]
void argp_help([[in]] struct argp const *__restrict ap,
               [[inout]] $FILE *__restrict stream, unsigned int flags,
               [[in]] char __KOS_FIXED_CONST *__restrict name);


@@>> argp_state_help(3)
@@@param: flags: Set of `ARGP_HELP_*'
[[export_alias("__argp_state_help")]]
[[decl_include("<features.h>", "<bits/crt/argp.h>")]]
void argp_state_help([[in_opt]] struct argp_state const *__restrict state,
                     [[inout_opt]] $FILE *__restrict stream, unsigned int flags) /*{
	unsigned int state_flags = 0;
	if unlikely(!stream)
		return;
	if likely(state)
		state_flags = state->@flags@;
	if unlikely(state_flags & ARGP_NO_ERRS)
		return;
	if (state_flags & ARGP_LONG_ONLY)
		flags |= ARGP_HELP_LONG_ONLY;
	// TODO
}*/;


[[export_alias("__argp_usage")]]
[[decl_include("<bits/crt/argp.h>")]]
[[requires_include("<bits/crt/argp.h>", "<libc/template/stdstreams.h>")]]
[[requires($has_function(argp_state_help) && defined(__LOCAL_stderr) &&
           defined(__ARGP_HELP_STD_USAGE))]]
void argp_usage([[in]] struct argp_state const *state) {
	argp_state_help(state, stderr, ARGP_HELP_STD_USAGE);
}

[[static, decl_include("<bits/crt/argp.h>")]]
[[impl_include("<libc/template/stdstreams.h>")]]
[[impl_include("<libc/template/program_invocation_name.h>")]]
[[requires($has_function(/*fputc_unlocked, fprintf_unlocked,*/ vfprintf_unlocked, argp_state_help) &&
           defined(__ARGP_HELP_STD_ERR))]]
void argp_verror([[in_opt]] struct argp_state const *__restrict state,
                 [[in, format("printf")]] char const *__restrict format,
                 va_list args) {
	FILE *out;
	char const *appname;
	if unlikely(state && (state->@flags@ & ARGP_NO_ERRS))
		return;
	out = NULL;
	if likely(state)
		out = state->@err_stream@;
@@pp_ifdef stderr@@
	if unlikely(!out)
		out = stderr;
@@pp_endif@@
	if unlikely(!out)
		return;
	appname = NULL;
	if likely(state)
		appname = state->@name@;
@@pp_ifdef program_invocation_name@@
	if unlikely(!appname)
		appname = program_invocation_name;
@@pp_endif@@
	if unlikely(!appname)
		appname = "?";

	/* Print the message. */
@@pp_if $has_function(flockfile, funlockfile)@@
	(void)flockfile(out);
@@pp_endif@@
	(void)fprintf_unlocked(out, "%s: ", appname);
	(void)vfprintf_unlocked(out, format, args);
@@pp_if $has_function(fputc_unlocked)@@
	(void)fputc_unlocked('\n', out);
@@pp_else@@
	(void)fprintf_unlocked(out, "\n");
@@pp_endif@@
	(void)argp_state_help(state, out, ARGP_HELP_STD_ERR);
@@pp_if $has_function(flockfile, funlockfile)@@
	(void)funlockfile(out);
@@pp_endif@@
}

[[static, decl_include("<bits/types.h>", "<bits/crt/argp.h>")]]
[[impl_include("<libc/template/stdstreams.h>")]]
[[impl_include("<libc/template/program_invocation_name.h>")]]
[[requires_function(/*fprintf_unlocked, fputc_unlocked, fputs_unlocked,*/ vfprintf_unlocked, exit)]]
void argp_vfailure([[in_opt]] struct argp_state const *__restrict state, int exit_status, $errno_t errnum,
                   [[in_opt, format("printf")]] char const *__restrict format, va_list args) {
	FILE *out;
	char const *appname;
	if unlikely(state && (state->@flags@ & ARGP_NO_ERRS))
		return;
	out = NULL;
	if likely(state)
		out = state->@err_stream@;
@@pp_ifdef stderr@@
	if unlikely(!out)
		out = stderr;
@@pp_endif@@
	if unlikely(!out)
		return;
	appname = NULL;
	if likely(state)
		appname = state->@name@;
@@pp_ifdef program_invocation_name@@
	if unlikely(!appname)
		appname = program_invocation_name;
@@pp_endif@@
	if unlikely(!appname)
		appname = "?";

	/* Print the message. */
@@pp_if $has_function(flockfile, funlockfile)@@
	(void)flockfile(out);
@@pp_endif@@
@@pp_if $has_function(fputs_unlocked)@@
	(void)fputs_unlocked(appname, out);
@@pp_else@@
	(void)fprintf_unlocked(out, "%s", appname);
@@pp_endif@@
	if (format) {
@@pp_if $has_function(fputs_unlocked)@@
		(void)fputs_unlocked(": ", out);
@@pp_else@@
		(void)fprintf_unlocked(out, ": ");
@@pp_endif@@
		(void)vfprintf_unlocked(out, format, args);
	}
	if (errnum) {
@@pp_if $has_function(fputs_unlocked)@@
		(void)fputs_unlocked(": ", out);
		(void)fputs_unlocked(strerror(errnum), out);
@@pp_else@@
		(void)fprintf_unlocked(out, ": %s", strerror(errnum));
@@pp_endif@@
	}
@@pp_if $has_function(fputc_unlocked)@@
	(void)fputc_unlocked('\n', out);
@@pp_else@@
	(void)fprintf_unlocked(out, "\n");
@@pp_endif@@
	(void)argp_state_help(state, out, ARGP_HELP_STD_ERR);
@@pp_if $has_function(flockfile, funlockfile)@@
	(void)funlockfile(out);
@@pp_endif@@

	/* Exit the program (if need be) */
	if (exit_status && (!state || !(state->@flags@ & ARGP_NO_EXIT)))
		exit(exit_status);
}

[[export_alias("__argp_error")]]
[[decl_include("<bits/crt/argp.h>")]]
void argp_error([[in_opt]] struct argp_state const *__restrict state,
                [[in, format("printf")]] char const *__restrict format, ...)
	%{printf("argp_verror")}

[[export_alias("__argp_failure")]]
[[decl_include("<bits/types.h>", "<bits/crt/argp.h>")]]
void argp_failure([[in_opt]] struct argp_state const *__restrict state, int status, $errno_t errnum,
                  [[in, format("printf")]] char const *__restrict format, ...)
	%{printf("argp_vfailure")}

[[export_alias("__option_is_short")]]
[[decl_include("<bits/crt/argp.h>")]]
[[impl_include("<bits/crt/argp.h>")]]
[[requires_include("<bits/crt/argp.h>")]]
[[requires(defined(__OPTION_DOC))]]
int _option_is_short([[in]] struct argp_option const *opt) {
	int opt_key;
	if (opt->@flags@ & __OPTION_DOC)
		return 0;
	opt_key = opt->@key@;
	return opt_key > 0 && opt_key <= 0xff && isprint(opt_key);
}


@@>> _option_is_end(3)
@@Check if `opt' represents the end of an option-chain
[[export_alias("__option_is_end")]]
[[decl_include("<bits/crt/argp.h>")]]
[[impl_include("<bits/crt/argp.h>")]]
int _option_is_end([[in]] struct argp_option const *opt) {
	return !opt->@name@ && !opt->@key@ && !opt->@doc@ && !opt->@group@;
}

[[export_alias("__argp_input")]]
[[decl_include("<bits/crt/argp.h>")]]
void *_argp_input([[in_opt]] struct argp const *__restrict ap,
                  [[in_opt]] struct argp_state const *__restrict state);





/* Aliases (no idea why these need to be declared/exposed...) */
%[insert:function(__argp_parse = argp_parse)]
%[insert:function(__argp_help = argp_help)]
%[insert:function(__argp_state_help = argp_state_help)]
%[insert:function(__argp_usage = argp_usage)]
%[insert:function(__argp_error = argp_error)]
%[insert:function(__argp_failure = argp_failure)]
%[insert:function(__option_is_short = _option_is_short)]
%[insert:function(__option_is_end = _option_is_end)]
%[insert:function(__argp_input = _argp_input)]


%{

__SYSDECL_END
#endif /* __CC__ */

}
