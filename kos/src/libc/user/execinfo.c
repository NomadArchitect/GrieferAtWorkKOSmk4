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
 *    in a product, an acknowledgement in the product documentation would be  *
 *    appreciated but is not required.                                        *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef GUARD_LIBC_USER_EXECINFO_C
#define GUARD_LIBC_USER_EXECINFO_C 1

#include "../api.h"
/**/

#include <hybrid/align.h>
#include <hybrid/atomic.h>

#include <kos/kernel/cpu-state-helpers.h>
#include <kos/kernel/cpu-state.h>

#include <format-printer.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include <libdebuginfo/addr2line.h>
#include <libunwind/unwind.h>

#include "../libc/dl.h"
#include "execinfo.h"

DECL_BEGIN

#define SECTION_DEBUG_TEXT(x)   ATTR_SECTION(".text.crt.debug" x)
#define SECTION_DEBUG_BSS(x)    ATTR_SECTION(".bss.crt.debug" x)
#define SECTION_DEBUG_STRING(x) ATTR_SECTION(".rodata.crt.debug" x)

INTDEF void *pdyn_libunwind; /* From `../libc/except.c' */
INTDEF void LIBCCALL initialize_libunwind(void); /* From `../libc/except.c' */

PRIVATE SECTION_DEBUG_BSS("pdyn_unwind") PUNWIND pdyn_unwind = NULL;
PRIVATE SECTION_DEBUG_BSS("pdyn_unwind_getreg_lcpustate") PUNWIND_GETREG_LCPUSTATE pdyn_unwind_getreg_lcpustate = NULL;
PRIVATE SECTION_DEBUG_BSS("pdyn_unwind_setreg_lcpustate") PUNWIND_SETREG_LCPUSTATE pdyn_unwind_setreg_lcpustate = NULL;
PRIVATE SECTION_DEBUG_STRING("name_unwind") char const name_unwind[] = "unwind";
PRIVATE SECTION_DEBUG_STRING("name_unwind_getreg_lcpustate") char const name_unwind_getreg_lcpustate[] = "unwind_getreg_lcpustate";
PRIVATE SECTION_DEBUG_STRING("name_unwind_setreg_lcpustate") char const name_unwind_setreg_lcpustate[] = "unwind_setreg_lcpustate";

PRIVATE bool LIBCCALL initialize_libunwind_debug(void) {
	initialize_libunwind();
#define BIND(func, name)                                                 \
	if unlikely((*(void **)&func = dlsym(pdyn_libunwind, name)) == NULL) \
		goto err_init_failed
	BIND(pdyn_unwind, name_unwind);
	BIND(pdyn_unwind_getreg_lcpustate, name_unwind_getreg_lcpustate);
	BIND(pdyn_unwind_setreg_lcpustate, name_unwind_setreg_lcpustate);
#undef BIND
	return true;
err_init_failed:
	return false;
}

#define unwind                   (*pdyn_unwind)
#define unwind_getreg_lcpustate  (*pdyn_unwind_getreg_lcpustate)
#define unwind_setreg_lcpustate  (*pdyn_unwind_setreg_lcpustate)

#define ENSURE_LIBUNWIND_LOADED() \
	(ATOMIC_READ(pdyn_unwind) != NULL || initialize_libunwind_debug())


PRIVATE SECTION_DEBUG_BSS("pdyn_libdebuginfo") void *pdyn_libdebuginfo = NULL;
PRIVATE SECTION_DEBUG_BSS("pdyn_debug_dllocksections")     PDEBUG_DLLOCKSECTIONS     pdyn_debug_dllocksections     = NULL;
PRIVATE SECTION_DEBUG_BSS("pdyn_debug_dlunlocksections")   PDEBUG_DLUNLOCKSECTIONS   pdyn_debug_dlunlocksections   = NULL;
PRIVATE SECTION_DEBUG_BSS("pdyn_debug_sections_addr2line") PDEBUG_SECTIONS_ADDR2LINE pdyn_debug_sections_addr2line = NULL;

#define debug_dllocksections     (*pdyn_debug_dllocksections)
#define debug_dlunlocksections   (*pdyn_debug_dlunlocksections)
#define debug_sections_addr2line (*pdyn_debug_sections_addr2line)

PRIVATE ATTR_NOINLINE WUNUSED SECTION_DEBUG_TEXT("get_libdebuginfo")
void *LIBCCALL get_libdebuginfo(void) {
	void *result;
again:
	result = ATOMIC_READ(pdyn_libdebuginfo);
	if (result == (void *)-1)
		return NULL;
	if (!result) {
		result = dlopen(LIBDEBUGINFO_LIBRARY_NAME, RTLD_LOCAL);
		if (!result)
			result = (void *)-1;
		if (!ATOMIC_CMPXCH(pdyn_libdebuginfo, NULL, result)) {
			if (result != (void *)-1)
				dlclose(result);
			goto again;
		}
	}
	return result;
}

PRIVATE ATTR_NOINLINE WUNUSED SECTION_DEBUG_TEXT("init_libdebuginfo")
bool LIBCCALL init_libdebuginfo(void) {
	void *lib;
	if (pdyn_debug_dllocksections)
		return true;
	lib = get_libdebuginfo();
	if (!lib)
		return false;
	*(void **)&pdyn_debug_sections_addr2line = dlsym(lib, "debug_sections_addr2line");
	if unlikely(!pdyn_debug_sections_addr2line)
		return false;
	*(void **)&pdyn_debug_dlunlocksections = dlsym(lib, "debug_dlunlocksections");
	if unlikely(!pdyn_debug_dlunlocksections)
		return false;
	COMPILER_WRITE_BARRIER();
	*(void **)&pdyn_debug_dllocksections = dlsym(lib, "debug_dllocksections");
	if unlikely(!pdyn_debug_dllocksections)
		return false;
	return true;
}



/*[[[start:implementation]]]*/

/*[[[head:backtrace,hash:CRC-32=0xfdb608de]]]*/
/* Store up to SIZE return address of the current program state
 * in ARRAY and return the exact number of values stored */
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.debug.backtrace") int
NOTHROW_NCX(LIBCCALL libc_backtrace)(void **array,
                                     int size)
/*[[[body:backtrace]]]*/
{
	unsigned int result;
	struct lcpustate ost, st;
	if unlikely(size < 0) {
		libc_seterrno(EINVAL);
		return -1;
	}
	if (!ENSURE_LIBUNWIND_LOADED()) {
		libc_seterrno(ENOENT);
		return -1;
	}
	lcpustate_current(&st);
	for (result = 0; result < (unsigned int)size; ++result) {
		unsigned int error;
		memcpy(&ost, &st, sizeof(struct lcpustate));
		error = unwind((void *)lcpustate_getpc(&ost),
		               &unwind_getreg_lcpustate, &ost,
		               &unwind_setreg_lcpustate, &st);
		if (error != UNWIND_SUCCESS)
			break;
		array[result] = (void *)lcpustate_getpc(&st);
	}
	return (int)result;
}
/*[[[end:backtrace]]]*/

PRIVATE ATTR_SECTION(".text.crt.debug.print_function_name") ssize_t
NOTHROW_NCX(LIBCCALL print_function_name)(void *pc,
                                          pformatprinter printer,
                                          void *arg) {
	void *mod;
	ssize_t result;
	di_debug_sections_t sections;
    di_dl_debug_sections_t dl_sections;
	di_debug_addr2line_t a2l;
	/* Figure out the module mapped at the given program counter. */
	mod = dlgethandle(pc, DLGETHANDLE_FINCREF);
	if unlikely(!mod)
		goto err0;
	/* Load debug sections for that module. */
	if (debug_dllocksections(mod, &sections, &dl_sections) != DEBUG_INFO_ERROR_SUCCESS)
		goto err0_handle;
	/* Try to extract debug information about the given address. */
	if (debug_sections_addr2line(&sections, &a2l,
	                             (uintptr_t)pc - (uintptr_t)dlmodulebase(mod),
	                             DEBUG_ADDR2LINE_LEVEL_SOURCE,
	                             DEBUG_ADDR2LINE_FNORMAL) != DEBUG_INFO_ERROR_SUCCESS)
		goto err0_sect;
	if (!a2l.al_rawname)
		a2l.al_rawname = a2l.al_name;
	if (!a2l.al_rawname)
		goto err0_sect;
	/* Print the function's name. */
	result = (*printer)(arg, a2l.al_rawname, strlen(a2l.al_rawname));
	/* Release references to acquired data. */
	debug_dlunlocksections(&dl_sections);
	dlclose(mod);
	return result;
err0_sect:
	debug_dlunlocksections(&dl_sections);
err0_handle:
	dlclose(mod);
err0:
	return 0;
}

/*[[[head:backtrace_symbols,hash:CRC-32=0xe737224e]]]*/
/* Return names of functions from the backtrace list
 * in ARRAY in a newly malloc()ed memory block */
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.debug.backtrace_symbols") char **
NOTHROW_NCX(LIBCCALL libc_backtrace_symbols)(void *const *array,
                                             int size)
/*[[[body:backtrace_symbols]]]*/
{
	char **result;
	unsigned int i;
	struct format_aprintf_data data;
	if unlikely(size < 0) {
		libc_seterrno(EINVAL);
		return NULL;
	}
	if (!init_libdebuginfo()) {
		libc_seterrno(ENOENT);
		return NULL;
	}
	format_aprintf_data_init(&data);
	/* Make space for the string array itself. */
	if unlikely(!format_aprintf_alloc(&data, CEILDIV(((unsigned int)size + 1) * sizeof(char *), sizeof(char))))
		goto err;
	for (i = 0; i < (unsigned int)size; ++i) {
		PRIVATE SECTION_DEBUG_STRING("debug_empty_string") char const debug_empty_string[1] = { 0 };
		if unlikely(print_function_name(array[i], &format_aprintf_printer, &data) < 0)
			goto err;
		if unlikely(format_aprintf_printer(array[i], debug_empty_string, 1) < 0)
			goto err;
	}
	result = (char **)format_aprintf_pack(&data, NULL);
	if likely(result) {
		char *name = (char *)result + CEILDIV(((unsigned int)size + 1) * sizeof(char *), sizeof(char));
		for (i = 0; i < (unsigned int)size; ++i, name = strend(name) + 1)
			result[i] = name;
		result[i] = NULL;
	}
	return result;
err:
	format_aprintf_data_fini(&data);
	return NULL;
}
/*[[[end:backtrace_symbols]]]*/

/*[[[head:backtrace_symbols_fd,hash:CRC-32=0x6bfe21b0]]]*/
/* This function is similar to backtrace_symbols()
 * but it writes the result immediately to a file */
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.debug.backtrace_symbols_fd") void
NOTHROW_NCX(LIBCCALL libc_backtrace_symbols_fd)(void *const *array,
                                                int size,
                                                fd_t fd)
/*[[[body:backtrace_symbols_fd]]]*/
{
	ssize_t error;
	unsigned int i;
	if unlikely(size < 0)
		return;
	if (!init_libdebuginfo())
		return;
	for (i = 0; i < (unsigned int)size; ++i) {
		PRIVATE SECTION_DEBUG_STRING("debug_lf") char const debug_lf[1] = { '\n' };
		PRIVATE SECTION_DEBUG_STRING("debug_unknown_name") char const debug_unknown_name[1] = { '?' };
		error = print_function_name(array[i],
		                            (pformatprinter)(void *)&write,
		                            (void *)(uintptr_t)(unsigned int)fd);
		if unlikely(error < 0)
			break;
		if (!error)
			write(fd, debug_unknown_name, sizeof(debug_unknown_name));
		write(fd, debug_lf, sizeof(debug_lf));
	}
}
/*[[[end:backtrace_symbols_fd]]]*/

/*[[[end:implementation]]]*/



/*[[[start:exports,hash:CRC-32=0x7322107e]]]*/
DEFINE_PUBLIC_WEAK_ALIAS(backtrace, libc_backtrace);
DEFINE_PUBLIC_WEAK_ALIAS(__backtrace, libc_backtrace);
DEFINE_PUBLIC_WEAK_ALIAS(backtrace_symbols, libc_backtrace_symbols);
DEFINE_PUBLIC_WEAK_ALIAS(__backtrace_symbols, libc_backtrace_symbols);
DEFINE_PUBLIC_WEAK_ALIAS(backtrace_symbols_fd, libc_backtrace_symbols_fd);
DEFINE_PUBLIC_WEAK_ALIAS(__backtrace_symbols_fd, libc_backtrace_symbols_fd);
/*[[[end:exports]]]*/

DECL_END

#endif /* !GUARD_LIBC_USER_EXECINFO_C */
