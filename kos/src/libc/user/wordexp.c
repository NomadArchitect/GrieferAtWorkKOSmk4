/* Copyright (c) 2019-2022 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2022 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef GUARD_LIBC_USER_WORDEXP_C
#define GUARD_LIBC_USER_WORDEXP_C 1
#define _KOS_SOURCE 1

#include "../api.h"
/**/

#include <hybrid/wordbits.h>

#include <sys/wait.h>

#include <assert.h>
#include <ctype.h>
#include <fcntl.h>
#include <fnmatch.h>
#include <malloc.h>
#include <malloca.h>
#include <paths.h>
#include <pwd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../libc/globals.h"
#include "wordexp.h"

#ifndef FCALL
#define FCALL __FCALL
#endif /* !FCALL */

#if !defined(NDEBUG) && 1
#include <syslog.h>
#define WX_DEBUG(format, ...) \
	syslog(LOG_DEBUG, "[libc][wordexp][%d] " format, __LINE__, ##__VA_ARGS__)
#else /* ... */
#define WX_DEBUG(format, ...) (void)0
#endif /* !... */

#ifndef WX_SYNTAX
#define WX_SYNTAX() (WX_DEBUG("Syntax error\n"), WRDE_SYNTAX)
#endif /* !WX_SYNTAX */

DECL_BEGIN

/*
 * NOTE: This implementation (should) be logic-compatible with gLibc.
 *
 * However, this is NOT the implementation from gLibc. The  implementation
 * found in here has  been written from  scratch to best  fit KOS and  its
 * conventions, as well as because I really wanted to write my own wordexp
 * processor =P
 *
 */


#if !defined(NDEBUG) && !defined(NDEBUG_FINI)
#define DBG_memset memset
#else /* !NDEBUG && !NDEBUG_FINI */
#define DBG_memset(...) (void)0
#endif /* NDEBUG || NDEBUG_FINI */

struct wxparser {
	char const  *wxp_flush;   /* [1..1] Flush start pointer (points before `wxp_input') */
	char const  *wxp_input;   /* [1..1] Pointer to next input character */
	char const  *wxp_ifs;     /* [1..1] InputFieldSeparators (defaults to " \t\n") */
	union {
		char     wxp_wifs[4]; /* Whitespace InputFieldSeparators (subset of " \t\n") */
		uint32_t _wxp_wifsi;  /* ... */
	};
	unsigned int wxp_flags;   /* Word expansion flags (set of `WRDE_*' from <wordexp.h>) */
	size_t       wxp_wordc;   /* # of output words */
	char       **wxp_wordv;   /* [0..1][owned][0..wxp_wordc][owned] Vector of output words */
	char        *wxp_word;    /* [0..wxp_wordlen][owned] Word currently being constructed.
	                           * Set to `NULL' if no word is currently under construction. */
	size_t       wxp_wordlen; /* Length of the current word. (or `0' when `wxp_word == NULL') */
};

/* Finish the current word. */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(LIBCCALL wxparser_finishword)(struct wxparser *__restrict self) {
	char **words;
	assert(self->wxp_word);
	self->wxp_word[self->wxp_wordlen] = '\0';
	WX_DEBUG("Finish word %$q\n", self->wxp_wordlen, self->wxp_word);
	words = (char **)realloc(self->wxp_wordv,
	                         self->wxp_wordc + 2, /* +1: new word; +1: trailing NULL */
	                         sizeof(char *));
	if unlikely(!words)
		return WRDE_NOSPACE;
	self->wxp_wordv        = words;
	words[self->wxp_wordc] = self->wxp_word;
	++self->wxp_wordc;
	DBG_memset(&self->wxp_word, 0xcc, sizeof(self->wxp_word));
	DBG_memset(&self->wxp_wordlen, 0xcc, sizeof(self->wxp_wordlen));
	return 0;
}

/* Begin a new word (and append the word previously under construction, should it exist) */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(LIBCCALL wxparser_newword)(struct wxparser *__restrict self) {
	int result;
	if (!self->wxp_word)
		return 0; /* No word under construction */
	result = wxparser_finishword(self);
	if likely(result == 0) {
		self->wxp_word    = NULL;
		self->wxp_wordlen = 0;
	}
	return result;
}

/* Append the given `text...+=len' to the current word.
 * NOTE: Even when `len == 0', a previously NULL-word will become non-NULL,
 *       and  thus will eventually  be added to the  array of result words.
 *       -> Important detail needed to construct empty words with '""'. */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1, 2)) int
NOTHROW_NCX(LIBCCALL wxparser_wordappend)(struct wxparser *__restrict self,
                                          char const *text, size_t len) {
	size_t reqlen = self->wxp_wordlen + len + 1;
	char *word    = (char *)realloc(self->wxp_word, reqlen, sizeof(char));
	if unlikely(!word)
		return WRDE_NOSPACE;
	self->wxp_word = word;
	memcpy(word + self->wxp_wordlen, text, len, sizeof(char));
	self->wxp_wordlen += len;
	return 0;
}


/* Forward declarations */
PRIVATE NONNULL((1)) int
NOTHROW_NCX(LIBCCALL wxparser_parse_dollar)(struct wxparser *__restrict self, bool quoted);


PRIVATE ATTR_NOINLINE int
NOTHROW_NCX(LIBCCALL shexec_fixedlength)(char const *cmdline, size_t cmdline_len) {
	/* Can't use malloca() because we musn't use the heap here. */
	char *dup = (char *)alloca((cmdline_len + 1) * sizeof(char));
	*(char *)mempcpy(dup, cmdline, cmdline_len, sizeof(char)) = '\0';
	return shexec(dup);
}


/* Execute the given command and append its STDOUT output to the current word.
 * @param: quoted: Set to true if invoked from a "quoted" context. */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(LIBCCALL wxparser_insert_command)(struct wxparser *__restrict self,
                                              char const *cmdline, size_t cmdline_len,
                                              bool quoted) {
	int result;
	pid_t cpid;
	fd_t pipes[2];
	unsigned int state = (unsigned int)quoted;
#define STATE_FIELDSTART               (unsigned int)false /* Searching for first character of a field. */
#define STATE_QUOTED                   (unsigned int)true
#define STATE_COPYING_FIELD            2 /* Copying a field's text */
#define STATE_SEARCH_NONSPACE_IFS      3 /* Searching for non-space $IFS */
#define STATE_SEARCH_NONLF_AFTER_FIELD 4 /* Searching for non-\n after field */
	WX_DEBUG("wxparser_insert_command(%$q, quoted: %d)\n", cmdline_len, cmdline, (int)quoted);

	/* Check if program substitution has been disabled. */
	if (self->wxp_flags & WRDE_NOCMD)
		return WRDE_CMDSUB;
	if unlikely(cmdline_len == 0)
		return 0; /* Simple case: empty commandline does nothing */

	/* Construct pipes for child-process communication */
	result = pipe2(pipes, O_CLOEXEC);
	if unlikely(result != 0)
		return WRDE_NOSPACE;

	cpid = vfork();
	if unlikely(cpid < 0) {
		close(pipes[0]);
		close(pipes[1]);
		return WRDE_NOSPACE;
	}
	if (cpid == 0) {
		/* In child process. */
		dup2(pipes[1], STDOUT_FILENO);
		if (!(self->wxp_flags & WRDE_SHOWERR)) {
			/* Redirect stderr to /dev/null
			 * NOTE: Because we're using O_CLOEXEC, the kernel
			         will close this once we call the shell. */
			fd_t null = open(_PATH_DEVNULL, O_WRONLY | O_CLOEXEC);
			dup2(null, STDERR_FILENO);
		}
		shexec_fixedlength(cmdline, cmdline_len);
		_Exit(127);
	}
	/* In parent */
	close(pipes[1]);
	for (;;) {
		size_t buflen;
		char buf[512];
		buflen = (size_t)read(pipes[0], buf, sizeof(buf));
		if ((size_t)buflen < 0) {
			if (libc_geterrno() == EINTR)
				continue;
			result = WRDE_NOSPACE;
			goto err;
		}

		/* Process `buflen' bytes of output from child process. */
		switch (state) {

		case STATE_QUOTED:
			/* Simple case: always append to current word. */
			result = wxparser_wordappend(self, buf, buflen);
			if unlikely(result != 0)
				goto err;
			break;

		case STATE_FIELDSTART:
		case STATE_COPYING_FIELD:
		case STATE_SEARCH_NONSPACE_IFS:
		case STATE_SEARCH_NONLF_AFTER_FIELD: {
			/* TODO: like the `!quoted' insert-path in `wxparser_parse_dollar_param()' */
			result = WRDE_NOSYS;
			goto err;
		}	break;

		default: __builtin_unreachable();
		}
		if (quoted) {


		} else {
		}
	}
	close(pipes[0]);

	/* Join (reap) child process */
	while (waitpid(cpid, &result, 0) != cpid) {
		if (libc_geterrno() != EINTR) {
			result = WRDE_NOSPACE;
			goto err;
		}
	}
	return 0;
err:
	kill(cpid, SIGKILL);
	while (waitpid(cpid, &result, 0) != cpid) {
		if (libc_geterrno() != EINTR)
			break; /* Huh? How did we get here? */
	}
	close(pipes[0]);
	return result;
}

/* WordexpeXPRessionPARSER */
struct wxpr_parser {
	intmax_t    wxpr_val;  /* [out] Expression value */
	char const *wxpr_pos;  /* [1..1] Pointer to (potential) first character of next token. */
	char const *wxpr_end;  /* [1..1] Pointer to expression end. */
	char        wxpr_tok;  /* Current token */
	bool        wxpr_dead; /* True if inside of a dead branch. (disable runtime errors) */
};

PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) char
NOTHROW_NCX(FCALL wxpr_next)(struct wxpr_parser *__restrict self) {
	for (;;) {
		char tok;
		if (self->wxpr_pos >= self->wxpr_end) {
			self->wxpr_tok = '\0';
			break;
		}
		tok = *self->wxpr_pos++;
		if (isspace(tok))
			continue;
		self->wxpr_tok = tok;
		break;
	}
	return self->wxpr_tok;
}

/* Forward declaration */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(FCALL wxpr_eval_ifelse)(struct wxpr_parser *__restrict self);

/* Unary expression */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(FCALL wxpr_eval_unary)(struct wxpr_parser *__restrict self) {
	int result;
again:
	switch (self->wxpr_tok) {

	case '-': {
		/* KOS-extension: negative. */
		wxpr_next(self);
		result = wxpr_eval_unary(self);
		self->wxpr_val = -self->wxpr_val;
	}	break;

	case '+':
		/* KOS-extension: positive. */
		wxpr_next(self);
		goto again;

	case '(':
		wxpr_next(self);
		result = wxpr_eval_ifelse(self);
		if likely(result == 0) {
			if likely(self->wxpr_tok == ')') {
				wxpr_next(self);
			} else {
				result = WX_SYNTAX();
			}
		}
		break;

	default: {
		/* Parse an integer.
		 * NOTE: We pass `0' for `base', thus allowing use of octal and hex numbers.
		 *       Apparently, supporting them  here is something  mandated by  POSIX.
		 *
		 * WARNING: This assumes that input is always (eventually) terminated by
		 *          '\0'. Our caller  guaranties that this  is always the  case! */
		char const *newpos;
		--self->wxpr_pos; /* Rewind to include the leading digit character. */
		self->wxpr_val = strtoimax_r(self->wxpr_pos, (char **)&newpos, 0, NULL);
		WX_DEBUG("strtoimax_r: parsed %$q as %" PRIdMAX "\n",
		         (size_t)(newpos - self->wxpr_pos),
		         self->wxpr_pos, self->wxpr_val);

		/* Verify that `newpos' has proper bounds. */
		if (newpos <= self->wxpr_pos || newpos > self->wxpr_end)
			return WX_SYNTAX(); /* Nothing was parsed, or number extends beyond buffer? */

		/* Load the next token */
		self->wxpr_pos = newpos;
		wxpr_next(self);

		/* Success! */
		result = 0;
	}	break;

	}
	return result;
}

/* Product expression */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(FCALL wxpr_eval_prod)(struct wxpr_parser *__restrict self) {
	char tok;
	int result = wxpr_eval_unary(self);
	if unlikely(result != 0)
		goto done;
again_switch_tok:
	tok = self->wxpr_tok;
	switch (tok) {

	case '%': /* KOS extension! (modulo) */
	case '*':
	case '/': {
		intptr_t lhs;
		lhs = self->wxpr_val;
		wxpr_next(self);
		result = wxpr_eval_unary(self);
		if unlikely(result != 0)
			goto done;
		if (tok == '*') {
			self->wxpr_val = lhs * self->wxpr_val;
		} else {
			if unlikely(self->wxpr_val == 0) {
				if unlikely(self->wxpr_dead)
					goto again_switch_tok; /* Ignore runtime errors */
				return WX_SYNTAX(); /* gLibc also returns this error for divide-by-zero */
			}
			if (tok == '/') {
				self->wxpr_val = lhs / self->wxpr_val;
			} else {
				self->wxpr_val = lhs % self->wxpr_val;
			}
		}
		goto again_switch_tok;
	}	break;

	default:
		break;
	}
done:
	return result;
}

/* Sum expression */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(FCALL wxpr_eval_sum)(struct wxpr_parser *__restrict self) {
	char tok;
	int result = wxpr_eval_prod(self);
	if unlikely(result != 0)
		goto done;
again_switch_tok:
	tok = self->wxpr_tok;
	switch (tok) {

	case '+':
	case '-': {
		intptr_t lhs;
		lhs = self->wxpr_val;
		wxpr_next(self);
		result = wxpr_eval_prod(self);
		if unlikely(result != 0)
			goto done;
		if (tok == '+') {
			self->wxpr_val = lhs + self->wxpr_val;
		} else {
			self->wxpr_val = lhs - self->wxpr_val;
		}
		goto again_switch_tok;
	}	break;

	default:
		break;
	}
done:
	return result;
}

/* Compare equal/non-zero expression */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(FCALL wxpr_eval_cmpeq)(struct wxpr_parser *__restrict self) {
	/* KOS extension: C-style compare-equal/non-equal (`10 != 20') */
	char tok;
	int result = wxpr_eval_sum(self);
	if unlikely(result != 0)
		goto done;
again_switch_tok:
	tok = self->wxpr_tok;
	switch (tok) {

	case '!':
	case '=': {
		intptr_t lhs;
		if (self->wxpr_pos >= self->wxpr_end)
			break;
		if (*self->wxpr_pos != '=')
			break;
		++self->wxpr_pos;
		lhs = self->wxpr_val;
		wxpr_next(self);
		result = wxpr_eval_sum(self);
		if unlikely(result != 0)
			goto done;
		if (tok == '!') {
			self->wxpr_val = lhs != self->wxpr_val ? 1 : 0;
		} else {
			self->wxpr_val = lhs == self->wxpr_val ? 1 : 0;
		}
		goto again_switch_tok;
	}	break;

	default:
		break;
	}
done:
	return result;
}

/* Compare expression */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(FCALL wxpr_eval_cmp)(struct wxpr_parser *__restrict self) {
	/* KOS extension: C-style compare (`30 > 20') */
	char tok;
	int result = wxpr_eval_cmpeq(self);
	if unlikely(result != 0)
		goto done;
again_switch_tok:
	tok = self->wxpr_tok;
	switch (tok) {

	case '>':
	case '<': {
		bool cmp;
		intptr_t lhs;
		if (self->wxpr_pos < self->wxpr_end && *self->wxpr_pos == '=') {
			tok <<= 1;
			++self->wxpr_pos;
		}
		lhs = self->wxpr_val;
		wxpr_next(self);
		result = wxpr_eval_cmpeq(self);
		if unlikely(result != 0)
			goto done;
		switch ((unsigned char)tok) {
		case (unsigned char)'>':
			cmp = lhs > self->wxpr_val;
			break;
		case (unsigned char)'>' << 1:
			cmp = lhs >= self->wxpr_val;
			break;
		case (unsigned char)'<':
			cmp = lhs < self->wxpr_val;
			break;
		case (unsigned char)'<' << 1:
			cmp = lhs <= self->wxpr_val;
			break;
		default: __builtin_unreachable();
		}
		self->wxpr_val = cmp ? 1 : 0;
		goto again_switch_tok;
	}	break;

	default:
		break;
	}
done:
	return result;
}

/* Compare expression */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(FCALL wxpr_eval_ifelse)(struct wxpr_parser *__restrict self) {
	/* KOS extension: C-style if/else expression (`foo ? bar : baz') */
	int result = wxpr_eval_cmp(self);
	if unlikely(result != 0)
		goto done;
	if (self->wxpr_tok == '?') {
		bool cond = self->wxpr_val != 0;
		bool dead = self->wxpr_dead;
		intmax_t lhs;
		wxpr_next(self);
		if (self->wxpr_tok == ':') {
			/* GCC-style `foo ?: bar' expression (same as `foo ? foo : bar') */
			lhs = self->wxpr_val;
		} else {
			self->wxpr_dead = dead | !cond;
			result = wxpr_eval_cmp(self);
			if unlikely(result != 0)
				goto done;
			lhs = self->wxpr_val;
			if (self->wxpr_tok != ':')
				return WX_SYNTAX();
		}
		wxpr_next(self);
		self->wxpr_dead = dead | cond;
		result = wxpr_eval_ifelse(self);
		if unlikely(result != 0)
			goto done;
		if (cond)
			self->wxpr_val = lhs;
		self->wxpr_dead = dead;
	}
done:
	return result;
}


/* Evaluate a mathematical expression and append its (decimal) result. */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(LIBCCALL wxparser_parse_expr)(struct wxparser *__restrict self,
                                          char const *expr, size_t expr_len) {
	/* Simplified arithmetic parser (e.g. "(10+20)*2" --> "60") */
	int result;
	struct wxpr_parser wxpr;
	char buf[COMPILER_LENOF(PRIMAXdMAX)];
	size_t len;
	WX_DEBUG("wxparser_parse_expr(%$q)\n", expr_len, expr);

	wxpr.wxpr_pos = expr;
	wxpr.wxpr_end = expr + expr_len;

	/* Evaluate the expression */
	wxpr_next(&wxpr);
	result = wxpr_eval_ifelse(&wxpr);
	if unlikely(result != 0)
		return result;

	/* Ensure that all tokens were consumed. */
	if (wxpr.wxpr_tok != '\0')
		return WX_SYNTAX();

	/* Convert the expression result into a (decimal) string */
	len = sprintf(buf, "%" PRIdMAX, wxpr.wxpr_val);

	/* And finally: append the expression's string representation onto the current word. */
	return wxparser_wordappend(self, buf, len);
}

/* Parse what comes after a '\\' output of quoted context
 * - `self->wxp_input' must point _AFTER_ '\\'
 * - Returns with `self->wxp_input' pointing _AFTER_ the operand
 * - Returns with `self->wxp_flush' undefined
 * - No leading flushing is done by this function */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(LIBCCALL wxparser_parse_backslash)(struct wxparser *__restrict self) {
	int result = 0;
	switch (*self->wxp_input) {

	case '\r':
		/* Escaped linefeed (delete) */
		++self->wxp_input;
		if (*self->wxp_input == '\n')
			++self->wxp_input;
		break;

	case '\n':
		/* Escaped linefeed (delete) */
		++self->wxp_input;
		break;

	default:
		/* Fallback: Only emit whatever comes after '\\' */
		result = wxparser_wordappend(self, self->wxp_input, 1);
		++self->wxp_input;
		break;
	}
	return result;
}

/* Parse what comes after a '\\' in a quoted context
 * - `self->wxp_input' must point _AFTER_ '\\'
 * - Returns with `self->wxp_input' pointing _AFTER_ the operand
 * - Returns with `self->wxp_flush' undefined
 * - No leading flushing is done by this function */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(LIBCCALL wxparser_parse_quoted_backslash)(struct wxparser *__restrict self) {
	int result = 0;
	switch (*self->wxp_input) {

	case '\r':
		/* Escaped linefeed (delete) */
		++self->wxp_input;
		if (*self->wxp_input == '\n')
			++self->wxp_input;
		break;

	case '\n':
		/* Escaped linefeed (delete) */
		++self->wxp_input;
		break;

	case '$':
	case '`':
	case '\"':
	case '\\':
		/* Escaped character */
		result = wxparser_wordappend(self, self->wxp_input, 1);
		++self->wxp_input;
		break;

	default:
		/* Fallback: re-emit both the '\' and whatever comes after */
		result = wxparser_wordappend(self, self->wxp_input - 1, 2);
		++self->wxp_input;
		break;
	}
	return result;
}

/* Parse what comes after a '~'
 * - `self->wxp_input' must point _AFTER_ '~'
 * - Returns with `self->wxp_input' pointing _AFTER_ the operand
 * - Returns with `self->wxp_flush' undefined
 * - No leading flushing is done by this function */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(LIBCCALL wxparser_parse_tilde)(struct wxparser *__restrict self,
                                           bool pretend_first_word) {
	char const *homedir;
	int result;
	char const *username_start, *username_end;
	/* Special handling for situation where '~' should _NOT_ be expanded. */
	if (self->wxp_wordlen == 0)
		goto do_expand_tilde;
	if (pretend_first_word || self->wxp_wordc == 0) {
		if (self->wxp_word[self->wxp_wordlen - 1] == '=')
			goto do_expand_tilde;
		if (self->wxp_word[self->wxp_wordlen - 1] == ':' &&
		    memchr(self->wxp_word, '=', self->wxp_wordlen - 1))
			goto do_expand_tilde;
	}
	/* Don't expand the tilde. (but append the '~' character as-is) */
dont_expand_tilde:
	return wxparser_wordappend(self, self->wxp_input - 1, 1);
do_expand_tilde:
	username_start = self->wxp_input;
	username_end   = self->wxp_input;
	/* Scan for an (optional) username
	 * >> "~"          -->  `getpwuid(getuid())->pw_dir'
	 * >> "~cool_guy"  -->  `getpwnam("cool_guy")->pw_dir' */
	for (;;) {
		char ch = *username_end;
		switch (ch) {

		case ':': case '/': case ' ':
		case '\t': case '\0':
			goto done_username;

		case '\\':
			goto dont_expand_tilde;

		default:
			break;
		}
		++username_end;
	}
done_username:
	if (username_start >= username_end) {
		homedir = getenv("HOME");
		if (!homedir) {
			struct passwd *pwd;
			pwd = getpwuid(getuid());
			if (pwd != NULL)
				homedir = pwd->pw_dir;
		}
	} else {
		struct passwd *pwd;
		char *namebuf;
		size_t namelen;
		namelen = (size_t)(username_end - username_start);
		namebuf = (char *)malloca(namelen + 1, sizeof(char));
		if unlikely(!namebuf)
			return WRDE_NOSPACE;
		*(char *)mempcpy(namebuf, username_start, namelen, sizeof(char)) = '\0';
		/* Lookup the password entry. */
		pwd = getpwnam(namebuf);
		freea(namebuf);
		homedir = NULL;
		if (pwd != NULL)
			homedir = pwd->pw_dir;
	}
	if (homedir == NULL)
		homedir = "~"; /* Fallback */
	result = wxparser_wordappend(self, homedir, strlen(homedir));
	self->wxp_input = username_end;
	return result;
}


/* XXX: Make this a proper functions in <string.h> (and implement
 *      it  without alloca() or having it stop on the first '\0') */
PRIVATE ATTR_NOINLINE ATTR_PURE WUNUSED ATTR_SECTION(".text.crt.wordexp") int
NOTHROW_NCX(LIBCCALL wildmemcmp)(void const *lhs, size_t lhs_size,
                                 void const *rhs, size_t rhs_size) {
	/* FIXME: we need to use `fnmatch(lhs, rhs, 0)', because this
	 *        doesn't set `FNM_NOESCAPE', thus causing '\\' to be
	 *        treated differently!
	 * Thus, we need a KOS-specific `fnmemmatch(3)' function! */
	void *lhs_dup = alloca(lhs_size + sizeof(char));
	void *rhs_dup = alloca(rhs_size + sizeof(char));
	*(char *)mempcpy(lhs_dup, lhs, lhs_size) = '\0';
	*(char *)mempcpy(rhs_dup, rhs, rhs_size) = '\0';
	return wildstrcmp((char *)lhs_dup, (char *)rhs_dup);
}


/* Same as `strspn()', but operates on a fixed-length `haystack'. */
PRIVATE ATTR_PURE WUNUSED NONNULL((3)) size_t
NOTHROW_NCX(LIBCCALL memspn)(void const *haystack, size_t haystack_len,
                             char const *accept) {
	char const *iter = (char const *)haystack;
	while (haystack_len && strchr(accept, *iter)) {
		++iter;
		--haystack_len;
	}
	return (size_t)(iter - (char const *)haystack);
}

/* Same as `strcspn()', but operates on a fixed-length `haystack'. */
PRIVATE ATTR_PURE WUNUSED NONNULL((3)) size_t
NOTHROW_NCX(LIBCCALL memcspn)(void const *haystack, size_t haystack_len,
                              char const *reject) {
	char const *iter = (char const *)haystack;
	while (haystack_len && !strchr(reject, *iter)) {
		++iter;
		--haystack_len;
	}
	return (size_t)(iter - (char const *)haystack);
}


/* Parse a dollar-parameter
 * - `self->wxp_input' must point at the start of the parameter name
 * - Returns with `self->wxp_input' pointing _AFTER_ the expression (_AFTER_ the trailing '}')
 * - Returns with `self->wxp_flush' undefined
 * - No leading flushing is done by this function */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(LIBCCALL wxparser_parse_dollar_param)(struct wxparser *__restrict self,
                                                  bool quoted, bool curlyd) {
	int result;
	char _local_buf[COMPILER_LENOF(PRIMAXdMAX)];
	char const *env_start = self->wxp_input;
	char ch;
	char const *value_str;
	size_t value_len;
	bool got_pound = false;
	char *value_freeme = NULL;

again_input:
	ch = *self->wxp_input;
	switch (ch) {

	case '#':
		if (!curlyd) {
			/* "$#" expands to `argc - 1' (as passed to `main()') */
			++self->wxp_input;
set_value_as_argc_minus_one:
			value_str = _local_buf;
			value_len = sprintf(_local_buf, "%d", __argc - 1);
			break;
		}
		got_pound = true;
		env_start = ++self->wxp_input;
		goto again_input;

	case '$':
		/* "$$" (and "${$}") expands to the caller's PID */
		value_str = _local_buf;
		value_len = sprintf(_local_buf, "%d", getpid());
		++self->wxp_input;
		break;

	case '*':
	case '@': {
		unsigned int argc;
		char **argv;
		++self->wxp_input;
		if (got_pound) {
			/* "${#*}" or "${#@}" --> Same as "$#" */
			goto set_value_as_argc_minus_one;
		}
		argc = (unsigned int)__argc;
		argv = __argv;
		if (ch == '*' || (ch == '@' && !quoted)) {
			unsigned int i;
			char *dst;
			/* Use a space-separated list of all main()-arguments (except `0') as value.
			 * >> value = " ".join(argv[1:]); */
			value_len = 0;
			for (i = 0; i < argc; ++i) {
				char const *arg = argv[i];
				if (!arg)
					arg = "";
				value_len = strlen(arg) + 1;
			}
			value_freeme = (char *)malloc(value_len, sizeof(char));
			if unlikely(!value_freeme) {
				result = WRDE_NOSPACE;
				goto done;
			}
			dst = value_freeme;
			for (i = 0; i < argc; ++i) {
				char const *arg = argv[i];
				if (!arg)
					arg = "";
				dst    = stpcpy(dst, arg);
				*dst++ = ' ';
			}
			assert(dst == value_freeme + value_len);
			dst[-1] = '\0';
			value_str = value_freeme;
		} else {
			/* Insert every main()-argument (except `0') as its own word.
			 *  - The first argument is appended to the currently in-progress word
			 *  - The last argument is loaded as the start of a new in-progress word
			 *  - All other (intermediate) arguments are loaded as-is
			 * Special cases:
			 *  - When `argc == 1', `value' becomes an empty string
			 *  - When `argc == 2', `value' becomes `argv[1]' */
			if (argc <= 1) {
				value_str = "";
				value_len = 0;
			} else {
				value_str = argv[1];
				if (argc > 2) {
					unsigned int i;
					for (i = 2;; ++i) {
						if unlikely(!value_str)
							value_str = ""; /* Shouldn't happen. */
						result = wxparser_wordappend(self, value_str, strlen(value_str));
						if unlikely(result != 0)
							goto done;
						result = wxparser_newword(self);
						if unlikely(result != 0)
							goto done;
						value_str = argv[i];
						if ((unsigned int)i >= (unsigned int)argc - 1)
							break;
					}
				}
				goto set_value_len_with_strlen;
			}
		}
	}	break;

	default:
		if (isalpha(ch)) {
			char *envname_temp;
			char const *envname_start;
			size_t envname_len;
	case '_':
			envname_start = self->wxp_input;
			for (;;) {
				char ch;
				ch = *++self->wxp_input;
				if (isalnum(ch))
					continue;
				if (ch == '_')
					continue;
				break;
			}
			/* Environment variable name. */
			envname_len  = (size_t)(self->wxp_input - envname_start);
			envname_temp = (char *)malloca(envname_len + 1, sizeof(char));
			*(char *)mempcpy(envname_temp, envname_start, envname_len, sizeof(char)) = '\0';
			value_str = getenv(envname_temp);
			freea(envname_temp);
			goto set_value_len_with_strlen;
		} else if (isdigit(ch)) {
			/* Index into program arguments. */
			unsigned long index;
			index = strtoul_r(self->wxp_input, (char **)&self->wxp_input, 10, NULL);
			value_str = NULL;
			if (index < (unsigned long)__argc)
				value_str = __argv[index];
			goto set_value_len_with_strlen;
		} else {
			if (curlyd) {
				result = WX_SYNTAX();
				goto done;
			}
			/* Just a lonely '$'... (re-insert as-is) */
			result = wxparser_wordappend(self, self->wxp_input, 1);
			++self->wxp_input;
			goto done;
		}
set_value_len_with_strlen:
		value_len = value_str ? strlen(value_str) : 0;
		break;
	} /* switch (...) */

	/* Inside of "${...}", we also accept extended actions, like ${HOME:-/home/me} */
	if (curlyd) {
		char const *action_start = self->wxp_input;
		unsigned char action;
		bool got_colon = false;
		bool expand_pattern = false;
		char *pattern_freeme;
		char const *pattern_str;
		size_t pattern_len;
		char *saved_wxp_word;
		size_t saved_wxp_wordlen;
		unsigned int pattern_quoted;
		unsigned int pattern_brace_recursion;
again_switch_curlied_action:
		action = (unsigned char)*self->wxp_input++;
		switch ((char)action) {

		case '}':
			goto done_action;

		case ':':
			got_colon = true;
			ch        = *self->wxp_input;
			if unlikely(!strchr("-=?+", ch))
				goto err_syntax;
			goto again_switch_curlied_action;

		case '#': /* Include "##" */
		case '%': /* Include "%%" */
			if ((unsigned char)*self->wxp_input == action) {
				action <<= 1;
				++self->wxp_input;
			}
			expand_pattern = true;
			break;

		case '?':
		case '-':
		case '=':
			if (value_str == NULL || (value_len == 0 && got_colon))
				expand_pattern = true;
			break;

		case '+':
			if (value_str == NULL && (value_len != 0 || got_colon))
				expand_pattern = true;
			break;

		default:
err_syntax:
			result = WX_SYNTAX();
			goto done;
		}

		/* Parse the action's pattern argument. */
		saved_wxp_word          = self->wxp_word;
		saved_wxp_wordlen       = self->wxp_wordlen;
		self->wxp_word          = NULL;
		self->wxp_wordlen       = 0;
		self->wxp_flush         = self->wxp_input;
		pattern_quoted          = 0;
		pattern_brace_recursion = 0;
continue_pattern_input:
		switch (*self->wxp_input++) {

		case '\0':
err_syntax_pattern_restore:
			result = WX_SYNTAX();
			goto err_pattern_restore;

		case '{':
			if (pattern_quoted == 0)
				++pattern_brace_recursion;
			goto continue_pattern_input;

		case '}':
			if (pattern_quoted == 0) {
				if (pattern_brace_recursion == 0) {
					--self->wxp_input;
					break;
				}
				--pattern_brace_recursion;
			}
			goto continue_pattern_input;

		case '\\':
			if (pattern_quoted != 0)
				goto continue_pattern_input;
			if (expand_pattern && *self->wxp_input == '\\') {
				/* In an expanded pattern, any remaining '\' (which could only appear  as
				 * the result of a  '\\' in the original  string) is once again  replaced
				 * with two consecutive '\\'. As such, we can merge the 2 steps by simply
				 * keeping 2 consecutive '\'-characters as-is in an expanded pattern. */
				++self->wxp_input;
				goto continue_pattern_input;
			}
			/* Insert next character as-is into the pattern string */
			result = wxparser_wordappend(self, self->wxp_flush,
			                             (size_t)((self->wxp_input - 1) -
			                                      (self->wxp_flush)));
			if unlikely(result != 0)
				goto err_pattern_restore;
			self->wxp_flush = self->wxp_input; /* Set flush to start _at_ the escaped character */
			if unlikely(*self->wxp_input == '\0')
				goto err_syntax_pattern_restore;
			++self->wxp_input;
			goto continue_pattern_input;

		case '\"':
			if (pattern_quoted == 0) {
				pattern_quoted = 1;
			} else if (pattern_quoted == 1) {
				pattern_quoted = 0;
			}
maybe_dont_include_quote_in_pattern:
			if (expand_pattern) {
				/* Don't include the '"' in the pattern string. */
				result = wxparser_wordappend(self, self->wxp_flush,
				                             (size_t)((self->wxp_input - 1) -
				                                      (self->wxp_flush)));
				if unlikely(result != 0)
					goto err_pattern_restore;
				self->wxp_flush = self->wxp_input;
			}
			goto continue_pattern_input;

		case '\'':
			if (pattern_quoted == 0) {
				pattern_quoted = 2;
			} else if (pattern_quoted == 2) {
				pattern_quoted = 0;
			}
			goto maybe_dont_include_quote_in_pattern;

		case '*':
		case '?':
			if (pattern_quoted != 0 && expand_pattern) {
				/* Insert a '\\' before this character */
				result = wxparser_wordappend(self, self->wxp_flush,
				                             (size_t)((self->wxp_input - 1) -
				                                      (self->wxp_flush)));
				if unlikely(result != 0)
					goto err_pattern_restore;
				result = wxparser_wordappend(self, "\\", 1);
				if unlikely(result != 0)
					goto err_pattern_restore;
				self->wxp_flush = self->wxp_input - 1;
			}
			goto continue_pattern_input;

		case '$':
			if (expand_pattern) {
				/* Recursively parse another dollar-operand. */
				result = wxparser_wordappend(self, self->wxp_flush,
				                             (size_t)((self->wxp_input - 1) -
				                                      (self->wxp_flush)));
				if unlikely(result != 0)
					goto err_pattern_restore;
				result = wxparser_parse_dollar(self, true);
				if unlikely(result != 0)
					goto err_pattern_restore;
				self->wxp_flush = self->wxp_input;
			}
			goto continue_pattern_input;

		case '~':
			if (expand_pattern) {
				/* Expand a tilde if it appears at the start of the pattern string. */
				if (pattern_quoted)
					goto continue_pattern_input;
				if (self->wxp_wordlen != 0)
					goto continue_pattern_input;
				if (self->wxp_flush < self->wxp_input - 1)
					goto continue_pattern_input;
				result = wxparser_wordappend(self, self->wxp_flush,
				                             (size_t)((self->wxp_input - 1) -
				                                      (self->wxp_flush)));
				if unlikely(result != 0)
					goto err_pattern_restore;
				result = wxparser_parse_tilde(self, true);
				if unlikely(result != 0)
					goto err_pattern_restore;
				self->wxp_flush = self->wxp_input;
			}
			goto continue_pattern_input;

		default:
			goto continue_pattern_input;
		}

		/* Load the (expanded) pattern argument. */
		if (self->wxp_word) {
			result = wxparser_wordappend(self, self->wxp_flush,
			                             (size_t)(self->wxp_input -
			                                      self->wxp_flush));
			if unlikely(result != 0) {
err_pattern_restore:
				self->wxp_word    = saved_wxp_word;
				self->wxp_wordlen = saved_wxp_wordlen;
				goto done;
			}
			pattern_freeme = self->wxp_word;
			pattern_str    = self->wxp_word;
			pattern_len    = self->wxp_wordlen;
			pattern_freeme[pattern_len] = '\0';
		} else {
			pattern_freeme = NULL;
			pattern_str    = self->wxp_flush;
			pattern_len    = (size_t)(self->wxp_input - pattern_str);
		}
		self->wxp_word    = saved_wxp_word;
		self->wxp_wordlen = saved_wxp_wordlen;

		/* Consume the trailing '}' (the only path through which we can
		 * get here is the "case '}'" above, and to be safe, we  simply
		 * assert that the next character still is a '}') */
		assert(*self->wxp_input == '}');
		++self->wxp_input;

		/* Perform the requested action. */
		switch (action) {

		case (unsigned char)'#':
		case (unsigned char)'#' << 1:
		case (unsigned char)'%':
		case (unsigned char)'%' << 1: {
			ssize_t test_direction;
			ssize_t test_value_length;
			ssize_t test_value_length_end;
			if (value_len == 0 || pattern_len == 0)
				break;
			if (action == (unsigned char)'#') {
				/* for (test_value_length = 0; test_value_length <= value_len; ++test_value_length) */
				test_value_length     = 0;
				test_value_length_end = value_len + 1;
				test_direction        = 1;
			} else {
				/* for (test_value_length = value_len; p >= 0; --test_value_length) */
				test_value_length     = value_len;
				test_value_length_end = -1;
				test_direction        = -1;
			}
			for (; test_value_length != test_value_length_end;
			     test_value_length += test_direction) {
				int match;
				match = wildmemcmp(pattern_str, pattern_len,
				                   value_str, test_value_length);
				if (match == 0) {
					if (action == ((unsigned char)'%') ||
					    action == ((unsigned char)'%' << 1)) {
						value_len -= test_value_length;
					} else {
						value_str += value_len;
						value_str -= test_value_length;
						value_len = test_value_length;
					}
					break;
				}
			}
		}	break;

		case (unsigned char)'?':
			if (value_len != 0)
				break; /* Non-empty parameter --> keep as-is */
			free(value_freeme);
			value_freeme = NULL;
			if (got_colon || value_str == NULL) {
				/* NULL-value --> print a message to stderr */
				if (pattern_len == 0) {
					pattern_str = "parameter null or not set";
					pattern_len = strlen(pattern_str);
				}
				fprintf(stderr, "%$s: %$s\n",
				        (size_t)(action_start - env_start), env_start,
				        pattern_len, pattern_str);
			}
insert_nothing:
			result = 0;
			goto done;

		case (unsigned char)'-':
			if (value_len != 0)
				break; /* Non-empty parameter --> keep as-is */
			if (!got_colon && value_str != NULL)
				goto insert_nothing; /* Empty, but non-NULL value --> keep as is (if no ':' was given) */
			/* Re-use the pattern as value. */
do_use_pattern_as_value:
			free(value_freeme);
			value_str    = pattern_str;
			value_len    = pattern_len;
			value_freeme = pattern_freeme;
			/*pattern_freeme = NULL;*/
			goto done_action;

		case (unsigned char)'+':
			if (value_str == NULL || (value_len == 0 && !got_colon))
				goto insert_nothing;
			/* Re-use the pattern as value. */
			goto do_use_pattern_as_value;

		case (unsigned char)'=': {
			char *envname;
			size_t envlen;
			if (value_len != 0)
				break; /* Non-empty parameter --> keep as-is */
			if (!got_colon && value_str != NULL)
				goto insert_nothing; /* Empty, but non-NULL value --> keep as is (if no ':' was given) */
			/* Re-use the pattern as value. */
			free(value_freeme);
			value_str    = pattern_str;
			value_len    = pattern_len;
			value_freeme = pattern_freeme;
			/*pattern_freeme = NULL;*/
			/* Also write the pattern back into environ(3), thus making it persistent. */
			envlen  = (size_t)(action_start - env_start);
			envname = (char *)malloca(envlen + 1, sizeof(char));
			if unlikely(!envname) {
err_nospace_pattern_freeme:
				result = WRDE_NOSPACE;
/*err_pattern_freeme:*/
				free(pattern_freeme);
				goto done;
			}
			*(char *)mempcpy(envname, env_start, envlen, sizeof(char)) = '\0';
			if (value_str[value_len] == 0) {
				setenv(envname, value_str, 1);
			} else {
				char *valstr;
				valstr = (char *)malloca(value_len + 1, sizeof(char));
				if unlikely(!valstr)
					goto err_nospace_pattern_freeme;
				*(char *)mempcpy(valstr, value_str, value_len, sizeof(char)) = '\0';
				setenv(envname, valstr, 1);
				freea(valstr);
			}
			freea(envname);
			goto done_action;
		}	break;

		default: __builtin_unreachable();
		}
		free(pattern_freeme);
	}
done_action:

	/* If requested to, return an error for NULL values. */
	if (value_str == NULL && (self->wxp_flags & WRDE_UNDEF)) {
		result = WRDE_BADVAL;
		goto done;
	}

	/* The '#' expands to the _length_ of the variable's value */
	if (got_pound) {
		value_len = sprintf(_local_buf, "%" PRIuSIZ, value_len);
		value_str = _local_buf;
#ifndef __OPTIMIZE_SIZE__
		free(value_freeme);
		value_freeme = NULL;
#endif /* !__OPTIMIZE_SIZE__ */
	}

	/* Insert the expansion `value' into the current word. */
	if (quoted) {
		/* Quoted, so fields won't be split! */
		result = wxparser_wordappend(self, value_str, value_len);
	} else {
		/* No quotes, so need to need to split fields. */
		char const *field_start = value_str;
		char const *value_end   = value_str + value_len;
		bool found_nonspace_ifs = false;
		for (;;) {
			char const *field_end;
			char const *next_start;
			if (field_start > value_str) {
				/* Start a new output word */
				result = wxparser_newword(self);
				if unlikely(result != 0)
					goto done;
			}

			/* Skip $IFS whitespace preceding the field */
			field_start += memspn(field_start, (size_t)(value_end - field_start), self->wxp_wifs);
			if (!found_nonspace_ifs && field_start >= value_end)
				break; /* Only whitespace */

			/* Figure out where this field ends. */
			field_end = field_start;
			field_end += memcspn(field_end, (size_t)(value_end - field_end), self->wxp_ifs);

			/* Skip whitespace after field. */
			next_start = field_end;
			next_start += memcspn(next_start, (size_t)(value_end - next_start), self->wxp_wifs);

			/* Skip up to 1 non-space $IFS after the field. */
			found_nonspace_ifs = false;
			if (next_start < value_end && strchr(self->wxp_ifs, *next_start) != NULL) {
				found_nonspace_ifs = true;
				++next_start;
			}

			/* Append the discovered field to the current word. */
			result = wxparser_wordappend(self, field_start, (size_t)(field_end - field_start));
			if unlikely(result != 0)
				goto done;

			/* Move on to the next field. */
			field_start = next_start;

			/* Check if should stop */
			if (found_nonspace_ifs)
				continue;
			if (field_start >= value_end)
				break;
		}
	}
done:
	free(value_freeme);
	return result;
}

/* Parse what comes after a '`'
 * - `self->wxp_input' must point _AFTER_ '`'
 * - Returns with `self->wxp_input' pointing _AFTER_ the trailing '`'
 * - Returns with `self->wxp_flush' undefined
 * - No leading flushing is done by this function */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(LIBCCALL wxparser_parse_backtick)(struct wxparser *__restrict self, bool quoted) {
	int result;
	char *saved_wxp_word;
	size_t saved_wxp_wordlen;
	bool is_single_quoted = false;

	/* Re-use the parser's word buffer for the commandline. */
	saved_wxp_word    = self->wxp_word;
	saved_wxp_wordlen = self->wxp_wordlen;
	self->wxp_word    = NULL;
	self->wxp_wordlen = 0;
	self->wxp_flush   = self->wxp_input;

continue_input:
	switch (*self->wxp_input) {

	case '\0':
		result = WX_SYNTAX();
		break;

	case '`': {
		char *cmdline;
		size_t cmdline_len;
		++self->wxp_input;
		if (!self->wxp_word) {
			self->wxp_word    = saved_wxp_word;
			self->wxp_wordlen = saved_wxp_wordlen;
			/* Nothing was ever flushed. --> Can re-use input line as-is. */
			result = wxparser_insert_command(self, self->wxp_flush,
			                                 (size_t)((self->wxp_input - 1) - self->wxp_flush),
			                                 quoted);
			return result;
		}

		/* Flush remaining data. */
		result = wxparser_wordappend(self, self->wxp_flush,
		                             (size_t)((self->wxp_input - 1) - self->wxp_flush));
		if unlikely(result != 0)
			break;

		/* Steal the current word as the commandline to-be used. */
		cmdline              = self->wxp_word;
		cmdline_len          = self->wxp_wordlen;
		cmdline[cmdline_len] = '\0';
		self->wxp_word       = saved_wxp_word;
		self->wxp_wordlen    = saved_wxp_wordlen;

		/* Run the commandline. */
		result = wxparser_insert_command(self, cmdline, cmdline_len, quoted);
		free(cmdline);
		return result;
	}	break;

	case '\\':
		/* Flush leading data. */
		result = wxparser_wordappend(self, self->wxp_flush,
		                             (size_t)(self->wxp_input -
		                                      self->wxp_flush));
		if unlikely(result != 0)
			break;
		++self->wxp_input;
		/* Handle the backslash. */
		result = is_single_quoted ? wxparser_parse_quoted_backslash(self)
		                          : wxparser_parse_backslash(self);
		if unlikely(result != 0)
			break;
		self->wxp_flush = self->wxp_input;
		goto continue_input;

	case '\'':
		is_single_quoted = !is_single_quoted;
		ATTR_FALLTHROUGH
	default:
		++self->wxp_input;
		goto continue_input;
	}

	/* Restore stuff */
	free(self->wxp_word);
	self->wxp_word    = saved_wxp_word;
	self->wxp_wordlen = saved_wxp_wordlen;
	return result;
}

/* Parse what comes after a '$('
 * - `self->wxp_input' must point _AFTER_ '$('
 * - Returns with `self->wxp_input' pointing _AFTER_ the trailing ')'
 * - Returns with `self->wxp_flush' undefined
 * - No leading flushing is done by this function */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(LIBCCALL wxparser_parse_subshell)(struct wxparser *__restrict self, bool quoted) {
	char ch;
	char const *comm_start;
	/* 0: No quotes
	 * 1: In "-quotes
	 * 2: In '-quotes */
	unsigned int quote_context   = 0;
	unsigned int paren_recursion = 0;

	/* Remember the command's start */
	comm_start = self->wxp_input;
continue_input:
	ch = *self->wxp_input;
	switch (ch) {

	case '\0':
		return WX_SYNTAX();

	case '\"':
		if (quote_context == 0) {
			quote_context = 1;
		} else if (quote_context == 1) {
			quote_context = 0;
		}
		break;

	case '\'':
		if (quote_context == 0) {
			quote_context = 2;
		} else if (quote_context == 2) {
			quote_context = 0;
		}
		break;

	case '(':
		if (quote_context != 0)
			break;
		++paren_recursion;
		break;

	case ')':
		if (quote_context != 0)
			break;
		if (paren_recursion == 0) {
			int result;
			/* Reached the end of the command. -> Run it and insert its output! */
			result = wxparser_insert_command(self, comm_start,
			                                 (size_t)(self->wxp_input - comm_start),
			                                 quoted);
			++self->wxp_input;
			return result;
		}
		--paren_recursion;
		break;

	default:
		break;
	}
	++self->wxp_input;
	goto continue_input;
}

/* Parse arithmetic
 * - `self->wxp_input' must point at the start of the arithmetic expression
 * - Returns with `self->wxp_input' pointing _AT_ what comes after the expression (the trailing "))" or "]")
 * - Returns with `self->wxp_flush' undefined
 * - No leading flushing is done by this function */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(LIBCCALL wxparser_parse_arith)(struct wxparser *__restrict self,
                                           bool brackets) {
	int result;
	char *saved_wxp_word;
	size_t saved_wxp_wordlen;
	unsigned int paren_recursion = 0;

	/* Re-use the parser's word buffer for the arith expression. */
	saved_wxp_word    = self->wxp_word;
	saved_wxp_wordlen = self->wxp_wordlen;
	self->wxp_word    = NULL;
	self->wxp_wordlen = 0;
	self->wxp_flush   = self->wxp_input;
continue_input:
	switch (*self->wxp_input) {

	case '\0':
err_syntax:
		result = WX_SYNTAX();
		goto done;

	case '$':
	case '`':
	case '\\':
		result = wxparser_wordappend(self, self->wxp_flush,
		                             (size_t)(self->wxp_input -
		                                      self->wxp_flush));
		if unlikely(result != 0)
			goto done;
		switch (*self->wxp_input++) {
		case '$':
			result = wxparser_parse_dollar(self, true);
			break;
		case '`':
			result = wxparser_parse_backtick(self, true);
			break;
		case '\\':
			result = wxparser_parse_quoted_backslash(self);
			break;
		default: __builtin_unreachable();
		}
		if unlikely(result != 0)
			goto done;
		self->wxp_flush = self->wxp_input;
		goto continue_input;

	case '(':
		++paren_recursion;
		++self->wxp_input;
		goto continue_input;

	case ')':
		if (paren_recursion == 0) {
			char *expr;
			size_t expr_len;
			if (!brackets)
				goto err_syntax;
end_of_expression:
			if (!self->wxp_wordlen) {
				self->wxp_word    = saved_wxp_word;
				self->wxp_wordlen = saved_wxp_wordlen;
				/* Nothing was ever flushed. --> Just eval the raw input string. */
				return wxparser_parse_expr(self, self->wxp_flush,
				                           (size_t)(self->wxp_input -
				                                    self->wxp_flush));
			}
			/* Flush remaining text. */
			result = wxparser_wordappend(self, self->wxp_flush,
			                             (size_t)(self->wxp_input -
			                                      self->wxp_flush));
			if unlikely(result != 0)
				goto done;
			/* Steal the expression to execute and restore the old word. */
			expr              = self->wxp_word;
			expr_len          = self->wxp_wordlen;
			self->wxp_word    = saved_wxp_word;
			self->wxp_wordlen = saved_wxp_wordlen;
			expr[expr_len]    = '\0'; /* Required for `strtoimax_r()' in `wxpr_eval_unary()' */

			/* Eval the expression */
			result = wxparser_parse_expr(self, expr, expr_len);
			free(expr);
			return result;
		}
		--paren_recursion;
		++self->wxp_input;
		goto continue_input;

	case ']':
		if (brackets && paren_recursion == 0)
			goto end_of_expression;
		ATTR_FALLTHROUGH

	default:
		++self->wxp_input;
		goto continue_input;
	}
done:
	/* Restore stuff */
	free(self->wxp_word);
	self->wxp_word    = saved_wxp_word;
	self->wxp_wordlen = saved_wxp_wordlen;
	return result;
}

/* Parse what comes after a '$'
 * - `self->wxp_input' must point _AFTER_ '$'
 * - Returns with `self->wxp_input' pointing _AFTER_ the operand
 * - Returns with `self->wxp_flush' undefined
 * - No leading flushing is done by this function */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(LIBCCALL wxparser_parse_dollar)(struct wxparser *__restrict self, bool quoted) {
	int result;
	switch (*self->wxp_input) {

	case '\"':
	case '\'':
	case '\0':
		/* Append the initial "$" and don't do anything else. */
		result = wxparser_wordappend(self, self->wxp_input - 1, 1);
		break;

	case '(':
		/* Sub-shell or arithmetic expression. */
		++self->wxp_input;
		if (*self->wxp_input == '(') {
			/* Could be an arithmetic expression. */
			unsigned int recursion = 0;
			char const *iter;
			for (iter = self->wxp_input + 1;;) {
				char ch = *iter++;
				if (ch == '(') {
					++recursion;
				} else if (ch == ')') {
					if (recursion == 0)
						break;
					--recursion;
				} else if (ch == '\0') {
					--iter;
					break;
				}
			}
			if (*iter == ')') {
				/* Input is something like "$((10 + 20))" */
				++self->wxp_input;
				result = wxparser_parse_arith(self, true);
				if (self->wxp_input[0] == ')' && self->wxp_input[1] == ')') {
					self->wxp_input += 2;
				} else if (result == 0) {
					result = WX_SYNTAX();
				}
				break;
			}
		}
		result = wxparser_parse_subshell(self, quoted);
		break;

	case '[':
		++self->wxp_input;
		result = wxparser_parse_arith(self, true);
		if (*self->wxp_input == ']') {
			++self->wxp_input;
		} else if (result == 0) {
			result = WX_SYNTAX();
		}
		break;

	case '{':
		++self->wxp_input;
		result = wxparser_parse_dollar_param(self, quoted, true);
		break;

	default:
		result = wxparser_parse_dollar_param(self, quoted, false);
		break;
	}
	return result;
}



/* Parse what comes after a '\''
 * - `self->wxp_input' must point _AFTER_ '\''
 * - Returns with `self->wxp_input' pointing _AFTER_ the closing '\''
 * - Returns with `self->wxp_flush' undefined
 * - No leading flushing is done by this function */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(LIBCCALL wxparser_parse_singlequote)(struct wxparser *__restrict self) {
	char const *flush_start = self->wxp_input;
	size_t flush_size;
	for (;;) {
		char ch = *self->wxp_input++;
		if (ch == '\'')
			break;
		if (ch == '\0')
			return WX_SYNTAX();
	}
	flush_size = (size_t)((self->wxp_input - 1) - flush_start);
	return wxparser_wordappend(self, flush_start, flush_size);
}


/* Parse what comes after a '"'
 * - `self->wxp_input' must point _AFTER_ '"'
 * - Returns with `self->wxp_input' pointing _AFTER_ the closing '"'
 * - Returns with `self->wxp_flush' undefined
 * - No leading flushing is done by this function */
PRIVATE ATTR_SECTION(".text.crt.wordexp") NONNULL((1)) int
NOTHROW_NCX(LIBCCALL wxparser_parse_doublequote)(struct wxparser *__restrict self) {
	int result;
	char ch;
	self->wxp_flush = self->wxp_input;
continue_input:
	ch = *self->wxp_input;
	switch (ch) {

	case '"':
		/* End of quoted area. */
		result = wxparser_wordappend(self, self->wxp_flush,
		                             (size_t)(self->wxp_input -
		                                      self->wxp_flush));
		++self->wxp_input;
		goto done;

	case '\0':
		return WX_SYNTAX();

	case '$':
		result = wxparser_wordappend(self, self->wxp_flush,
		                             (size_t)(self->wxp_input -
		                                      self->wxp_flush));
		if unlikely(result != 0)
			goto done;
		++self->wxp_input;
		result = wxparser_parse_dollar(self, true);
		if unlikely(result != 0)
			goto done;
		self->wxp_flush = self->wxp_input;
		goto continue_input;

	case '`':
		result = wxparser_wordappend(self, self->wxp_flush,
		                             (size_t)(self->wxp_input -
		                                      self->wxp_flush));
		if unlikely(result != 0)
			goto done;
		++self->wxp_input;
		result = wxparser_parse_backtick(self, true);
		if unlikely(result != 0)
			goto done;
		self->wxp_flush = self->wxp_input;
		goto continue_input;

	case '\\':
		result = wxparser_wordappend(self, self->wxp_flush,
		                             (size_t)(self->wxp_input -
		                                      self->wxp_flush));
		if unlikely(result != 0)
			goto done;
		++self->wxp_input;
		result = wxparser_parse_quoted_backslash(self);
		if unlikely(result != 0)
			goto done;
		self->wxp_flush = self->wxp_input;
		goto continue_input;

	default:
		++self->wxp_input;
		goto continue_input;
	}
done:
	return result;
}



/*[[[head:libc_wordexp,hash:CRC-32=0x6ec91b0]]]*/
/* >> wordexp(3)
 * Do shell-like expansion of `string'
 * @param: string: The string to expand
 * @param: self:   The word-expansion controller (and result container)
 * @param: flags:  Expansion flags (set of `WRDE_*' from <wordexp.h>)
 * @return: 0 : Success
 * @return: * : Error (return value is one of `WRDE_*' from <wordexp.h>) */
INTERN ATTR_SECTION(".text.crt.wordexp") NONNULL((1, 2)) int
NOTHROW_NCX(LIBCCALL libc_wordexp)(char const *__restrict string,
                                   wordexp_t *__restrict self,
                                   __STDC_INT_AS_UINT_T flags)
/*[[[body:libc_wordexp]]]*/
{
	struct wxparser parser;
	size_t _oldcount;
	int error;

	/* Set-up our parser. */
	parser.wxp_flush   = string;
	parser.wxp_input   = string;
	parser.wxp_flags   = flags;
	parser.wxp_wordc   = self->we_wordc;
	parser.wxp_wordv   = self->we_wordv;
	parser.wxp_word    = NULL;
	parser.wxp_wordlen = 0;

	/* Setup the initial buffer */
	if (parser.wxp_flags & WRDE_APPEND) {
		parser.wxp_flags |= WRDE_REUSE;
		_oldcount = self->we_offs + parser.wxp_wordc;
	} else {
		_oldcount        = 0;
		parser.wxp_wordc = 0;
		if (!(parser.wxp_flags & WRDE_REUSE))
			parser.wxp_wordv = NULL; /* No pre-existing buffer */
		if (!(parser.wxp_flags & WRDE_DOOFFS))
			self->we_offs = 0; /* Don't insert leading NULL-entries. */
	}

	/* For simplicity, we include leading NULLs for the duration of our implementation */
	parser.wxp_wordc += self->we_offs;

	/* Allocate the initial buffer */
	{
		char **words;
		words = (char **)realloc(parser.wxp_wordv,
		                         parser.wxp_wordc + 1,
		                         sizeof(char *));
		if unlikely(!words) {
			error = WRDE_NOSPACE;
			goto err;
		}
		/* NULL-initialize leading entries if we're not doing an append. */
		if (!(flags & WRDE_APPEND))
			bzeroc(words, self->we_offs, sizeof(char *));
		parser.wxp_wordv = words;
	}

	/* Load IFS string
	 * TODO: Do this lazily upon first use. */
	parser.wxp_ifs = getenv("IFS");
	if (parser.wxp_ifs == NULL) {
		parser._wxp_wifsi = ENCODE_INT32(' ', '\t', '\n', '\0');
		parser.wxp_ifs    = parser.wxp_wifs;
	} else {
		char *dst = parser.wxp_wifs;
		char const *scanner;
		/* Only that subset of " \t\n" that actually appears in $IFS may be used. */
		*dst = '\0';
		for (scanner = parser.wxp_ifs; *scanner; ++scanner) {
			char ch = *scanner;
			if (strchr(" \t\n", ch) && !strchr(parser.wxp_wifs, ch)) {
				*dst++ = ch;
				*dst   = '\0';
			}
		}
	}

	/* All of the setup is now done. -- We can now do the actual work! */
continue_input:
	switch (*parser.wxp_input) {

	case ' ':
	case '\t':
		/* Word separator. */
		WX_DEBUG("At word boundary\n");
		if (parser.wxp_flush < parser.wxp_input) {
			/* Flush the current word */
			error = wxparser_wordappend(&parser, parser.wxp_flush,
			                            (size_t)(parser.wxp_input -
			                                     parser.wxp_flush));
			if unlikely(error != 0)
				goto err;
		}
		/* Begin a new word */
		error = wxparser_newword(&parser);
		if unlikely(error != 0)
			goto err;
		parser.wxp_flush = ++parser.wxp_input;
		goto continue_input;

	case '\0':
		goto done;

	case '\r': case '\n': case '|': case '&':
	case ';': case '<': case '>': case '(':
	case ')': case '{': case '}':
		/* Illegal character */
		error = WRDE_BADCHAR;
		goto err;

	case '\\': case '$': case '`': case '\"':
	case '\'': case '~': case '*': case '[':
	case '?':
		/* Special control character. */
		if (parser.wxp_flush < parser.wxp_input) {
			/* Flush the current word */
			error = wxparser_wordappend(&parser, parser.wxp_flush,
			                            (size_t)(parser.wxp_input - parser.wxp_flush));
			if unlikely(error != 0)
				goto err;
		}
		++parser.wxp_input;
		switch (parser.wxp_input[-1]) {

		case '$':
			error = wxparser_parse_dollar(&parser, false);
			break;

		case '`':
			error = wxparser_parse_backtick(&parser, false);
			break;

		case '\"':
			error = wxparser_parse_doublequote(&parser);
			break;

		case '\'':
			error = wxparser_parse_singlequote(&parser);
			break;

		case '\\':
			error = wxparser_parse_backslash(&parser);
			break;

		case '~':
			error = wxparser_parse_tilde(&parser, false);
			break;

		case '*':
		case '[':
		case '?':
			/* TODO: glob pattern matching */
			error = WRDE_NOSYS;
			break;

		default:
			__builtin_unreachable();
			break;
		}
		if unlikely(error != 0)
			goto err;
		parser.wxp_flush = parser.wxp_input;
		goto continue_input;

	default:
		/* Normal character */
		++parser.wxp_input;
		goto continue_input;
	}
done:

	/* Flush the current word (but only if there is something _TO_ flush) */
	if (parser.wxp_flush < parser.wxp_input) {
		error = wxparser_wordappend(&parser, parser.wxp_flush,
		                            (size_t)(parser.wxp_input -
		                                     parser.wxp_flush));
		if unlikely(error != 0)
			goto err;
	}

	/* If still under construction, append the last-built word */
	if (parser.wxp_word) {
		error = wxparser_finishword(&parser);
		if unlikely(error != 0)
			goto err;
	}

	/* Fill in the trailing NULL entry. */
	parser.wxp_wordv[parser.wxp_wordc] = NULL;

	/* Specs don't want us to include leading NULLs in the word counter. */
	self->we_wordc = parser.wxp_wordc - self->we_offs;
	self->we_wordv = parser.wxp_wordv;
	return 0;
err:
	/* Delete data / restore the state prior to this call being made. */
	free(parser.wxp_word);
	if (flags & WRDE_APPEND) {
		assert(parser.wxp_wordc >= _oldcount);
		while (parser.wxp_wordc > _oldcount) {
			--parser.wxp_wordc;
			free(parser.wxp_wordv[parser.wxp_wordc]);
		}
		parser.wxp_wordv[_oldcount] = NULL;
		if (_oldcount == 0) {
			free(parser.wxp_wordv);
			parser.wxp_wordv = NULL;
		} else {
			char **words;
			words = (char **)realloc(parser.wxp_wordv,
			                         _oldcount + 1,
			                         sizeof(char *));
			if likely(words != NULL)
				parser.wxp_wordv = words;
		}
	} else {
		/* Just free everything. */
		while (parser.wxp_wordc) {
			--parser.wxp_wordc;
			free(parser.wxp_wordv[parser.wxp_wordc]);
		}
		free(parser.wxp_wordv);
		self->we_offs = 0;
	}
	self->we_wordv = parser.wxp_wordv;
	self->we_wordc = parser.wxp_wordc - self->we_offs;
	return error;
}
/*[[[end:libc_wordexp]]]*/


/*[[[start:exports,hash:CRC-32=0x182c4d42]]]*/
DEFINE_PUBLIC_ALIAS(wordexp, libc_wordexp);
/*[[[end:exports]]]*/

DECL_END

#endif /* !GUARD_LIBC_USER_WORDEXP_C */