/* HASH CRC-32:0xb78b8894 */
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
#ifndef __local_format_c16printf_defined
#define __local_format_c16printf_defined 1
#include <__crt.h>
#include <bits/wformat-printer.h>
#include <bits/uformat-printer.h>

#include <bits/wformat-printer.h>
#include <bits/uformat-printer.h>



/* Dependency: "format_vwprintf" from "parts.wchar.format-printer" */
#ifndef ____localdep_format_vc16printf_defined
#define ____localdep_format_vc16printf_defined 1
#if defined(__CRT_HAVE_format_vwprintf) && (__SIZEOF_WCHAR_T__ == 2)
/* Generic printf implementation
 * Taking a regular printf-style format string and arguments, these
 * functions will call the given `PRINTER' callback with various strings
 * that, when put together, result in the desired formated text.
 *  - `PRINTER' obviously is called with the text parts in their correct order
 *  - If `PRINTER' returns '< 0', the function returns immediately,
 *    yielding that same value. Otherwise, format_printf() returns
 *    the sum of all return values from `PRINTER'.
 *  - The strings passed to `PRINTER' may not necessarily be zero-terminated, and
 *    a second argument is passed that indicates the absolute length in characters.
 * Supported extensions:
 *  - `%q'-format mode: Semantics equivalent to `%s', this modifier escapes the string using
 *                        `format_c16escape' with flags set of 'FORMAT_ESCAPE_FNONE', or
 *                        `PRINTF_FLAG_PREFIX' when the '#' flag was used (e.g.: `%#q').
 *  - `%.*s'   Instead of reading an `int' and dealing with undefined behavior when negative, an `unsigned int' is read.
 *  - `%.?s'   Similar to `%.*s', but takes a `size_t' from the argument list instead of an `unsigned int', as well as define
 *             a fixed-length buffer size for string/quote formats (thus allowing you to print '\0' characters after quoting)
 *  - `%$s'    Same as `%.?s'
 *  - `%q'     Print an escaped string. (format_printf(..., "a%qb", "foo\nbar")) --> "a\"foo\\nbar\"b"
 *  - `%#q'    Same as %q, without quotes. (format_printf(..., "a%#qb", "foo\nbar")) --> "afoo\\nbarb"
 *  - `%Q'     Print an escaped character. (format_printf(..., "a%Qb", '\n')) --> "a\'\\n\'b"
 *  - `%#Q'    Same as %Q, without quotes. (format_printf(..., "a%#Qb", '\n')) --> "a\\nb"
 *  - `%I'     length modifier: Integral length equivalent to sizeof(size_t)/sizeof(uintptr_t).
 *  - `%I8'    length modifier: Integral length equivalent to sizeof(int8_t).
 *  - `%I16'   length modifier: Integral length equivalent to sizeof(int16_t).
 *  - `%I32'   length modifier: Integral length equivalent to sizeof(int32_t).
 *  - `%I64'   length modifier: Integral length equivalent to sizeof(int64_t).
 *  - `%[...]' Extended formating options, allowing for additional formating options:
 *             - `%$[hex]' / `%$[hex:lLoOpPaAhH]'
 *                 - Invoke `format_c16hexdump(..., va_arg(args, void *))'
 *                 - Integer-length (`%$I32[hex]') flags affect `FORMAT_HEXDUMP_(BYTES|WORDS|DWORDS|QWORDS)'
 *                 - The argument string affect flags (defaults to `0x0000')
 *                    - `0x0001':  yes:l, no:L
 *                    - `0x0004':   yes:o, no:O
 *                    - `0x0002': yes:P, no:p
 *                    - `0x0010':   yes:A, no:a
 *                    - `0x0008':     yes:H, no:h
 *             - `%[gen]'
 *                 - Invoke a custom format printer function pointer passed through args
 *                   >> typedef ssize_t (*PGEN)(pwformatprinter printer, void *arg);
 *                   >> PGEN g = va_arg(args, PGEN);
 *                   >> DO((*g)(printer, arg));
 *             - `%[gen:c]'
 *                 - Same as `%[gen]', but insert an additional argument `T' that depends
 *                   on the integer size prefix (`%I32[gen:c]') and defaults to `void *'
 *                   >> typedef ssize_t (*PGEN)(T a, pwformatprinter printer, void *arg);
 *                   >> PGEN g = va_arg(args, PGEN);
 *                   >> T    a = va_arg(args, T);
 *                   >> DO((*g)(a, printer, arg));
 *             - `%[disasm]' / `%$[disasm]'
 *                 - Print the mnemonic and operands of a single native assembly
 *                   instruction read from `va_arg(args, void *)' (using `libdisasm')
 *                   s.a. `disasm_single()'
 *                 - When the second form (with a fixed buffer size) is used, do a full
 *                   disassembly of that number of bytes, following `DISASSEMBLER_FNORMAL'
 *                   s.a. `disasm()'
 *             - `%[vinfo]' / `%[vinfo:<FORMAT=%f(%l,%c) : %n>]'
 *                 - Print addr2line information for a text address read from `va_arg(args, void *)'
 *                 - The given FORMAT string is a special printf-like format declaration
 *                   that accepts the following substitutions:
 *                   - `%%'   Print a single `%'-character (used for escaping `%')
 *                   - `%p'   Output the queried text address the same way `format_c16printf(..., "%q", addr)' would (as `sizeof(void *) * 2' uppercase hex characters)
 *                   - `%n'   Symbol name of the surrounding symbol (managed), or `???'   `di_debug_addr2line_t::al_name'
 *                   - `%N'   Raw name of the surrounding symbol, or `???'                `di_debug_addr2line_t::al_rawname'
 *                   - `%l'   Source line number (1-based; 0 if unknown)                  `di_debug_addr2line_t::al_srcline'
 *                   - `%c'   Source column number (1-based; 0 if unknown)                `di_debug_addr2line_t::al_srccol'
 *                   - `%f'   Source filename (with path prefix)                          `di_debug_addr2line_t::(al_cubase|al_srcpath|al_srcfile)'
 *                   - `%Rf'  Source filename (without path prefix)                       `di_debug_addr2line_t::al_srcfile'
 *                   - `%<'   Absolute starting address of the associated source location `di_debug_addr2line_t::al_linestart'
 *                   - `%>'   Absolute end address of the associated source location      `di_debug_addr2line_t::al_lineend'
 *                   - `%1>'  Absolute end address of the associated source location - 1  `di_debug_addr2line_t::al_lineend'
 *                   - `%S'   Absolute starting address of the surrounding symbol         `di_debug_addr2line_t::al_symstart'
 *                   - `%E'   Absolute end address of the surrounding symbol              `di_debug_addr2line_t::al_symend'
 *                   - `%1E'  Absolute end address of the surrounding symbol - 1          `di_debug_addr2line_t::al_symend'
 *                   - `%Dl'  Declaration line number (1-based; 0 if unknown)             `di_debug_addr2line_t::al_dclline'
 *                   - `%Dc'  Declaration column number (1-based; 0 if unknown)           `di_debug_addr2line_t::al_dclcol'
 *                   - `%Df'  Declaration filename (with path prefix)                     `di_debug_addr2line_t::(al_cubase|al_dclpath|al_dclfile)'
 *                   - `%RDf' Declaration filename (without path prefix)                  `di_debug_addr2line_t::al_dclfile'
 *                   - Any other character[-sequence] is forwarded as-is
 *             - `%[...]' Other sequences are resered for future usage
 * >>> Possible (and actual) uses:
 *  - printf:           Unbuffered output into any kind of stream/file.
 *  - sprintf/snprintf: Unsafe/Counted string formatting into a user-supplied buffer.
 *  - strdupf:          Output into dynamically allocated heap memory,
 *                      increasing the buffer when it gets filled completely.
 *  - syslog:           Unbuffered system-log output.
 *  - ...               There are a _lot_ more... */
__CREDIRECT(__ATTR_LIBC_PRINTF(3, 0) __ATTR_NONNULL((1, 3)),__SSIZE_TYPE__,__NOTHROW_NCX,__localdep_format_vc16printf,(__pc16formatprinter __printer, void *__arg, __CHAR16_TYPE__ const *__restrict __format, __builtin_va_list __args),format_vwprintf,(__printer,__arg,__format,__args))
#elif defined(__CRT_HAVE_DOS$format_vwprintf)
/* Generic printf implementation
 * Taking a regular printf-style format string and arguments, these
 * functions will call the given `PRINTER' callback with various strings
 * that, when put together, result in the desired formated text.
 *  - `PRINTER' obviously is called with the text parts in their correct order
 *  - If `PRINTER' returns '< 0', the function returns immediately,
 *    yielding that same value. Otherwise, format_printf() returns
 *    the sum of all return values from `PRINTER'.
 *  - The strings passed to `PRINTER' may not necessarily be zero-terminated, and
 *    a second argument is passed that indicates the absolute length in characters.
 * Supported extensions:
 *  - `%q'-format mode: Semantics equivalent to `%s', this modifier escapes the string using
 *                        `format_c16escape' with flags set of 'FORMAT_ESCAPE_FNONE', or
 *                        `PRINTF_FLAG_PREFIX' when the '#' flag was used (e.g.: `%#q').
 *  - `%.*s'   Instead of reading an `int' and dealing with undefined behavior when negative, an `unsigned int' is read.
 *  - `%.?s'   Similar to `%.*s', but takes a `size_t' from the argument list instead of an `unsigned int', as well as define
 *             a fixed-length buffer size for string/quote formats (thus allowing you to print '\0' characters after quoting)
 *  - `%$s'    Same as `%.?s'
 *  - `%q'     Print an escaped string. (format_printf(..., "a%qb", "foo\nbar")) --> "a\"foo\\nbar\"b"
 *  - `%#q'    Same as %q, without quotes. (format_printf(..., "a%#qb", "foo\nbar")) --> "afoo\\nbarb"
 *  - `%Q'     Print an escaped character. (format_printf(..., "a%Qb", '\n')) --> "a\'\\n\'b"
 *  - `%#Q'    Same as %Q, without quotes. (format_printf(..., "a%#Qb", '\n')) --> "a\\nb"
 *  - `%I'     length modifier: Integral length equivalent to sizeof(size_t)/sizeof(uintptr_t).
 *  - `%I8'    length modifier: Integral length equivalent to sizeof(int8_t).
 *  - `%I16'   length modifier: Integral length equivalent to sizeof(int16_t).
 *  - `%I32'   length modifier: Integral length equivalent to sizeof(int32_t).
 *  - `%I64'   length modifier: Integral length equivalent to sizeof(int64_t).
 *  - `%[...]' Extended formating options, allowing for additional formating options:
 *             - `%$[hex]' / `%$[hex:lLoOpPaAhH]'
 *                 - Invoke `format_c16hexdump(..., va_arg(args, void *))'
 *                 - Integer-length (`%$I32[hex]') flags affect `FORMAT_HEXDUMP_(BYTES|WORDS|DWORDS|QWORDS)'
 *                 - The argument string affect flags (defaults to `0x0000')
 *                    - `0x0001':  yes:l, no:L
 *                    - `0x0004':   yes:o, no:O
 *                    - `0x0002': yes:P, no:p
 *                    - `0x0010':   yes:A, no:a
 *                    - `0x0008':     yes:H, no:h
 *             - `%[gen]'
 *                 - Invoke a custom format printer function pointer passed through args
 *                   >> typedef ssize_t (*PGEN)(pwformatprinter printer, void *arg);
 *                   >> PGEN g = va_arg(args, PGEN);
 *                   >> DO((*g)(printer, arg));
 *             - `%[gen:c]'
 *                 - Same as `%[gen]', but insert an additional argument `T' that depends
 *                   on the integer size prefix (`%I32[gen:c]') and defaults to `void *'
 *                   >> typedef ssize_t (*PGEN)(T a, pwformatprinter printer, void *arg);
 *                   >> PGEN g = va_arg(args, PGEN);
 *                   >> T    a = va_arg(args, T);
 *                   >> DO((*g)(a, printer, arg));
 *             - `%[disasm]' / `%$[disasm]'
 *                 - Print the mnemonic and operands of a single native assembly
 *                   instruction read from `va_arg(args, void *)' (using `libdisasm')
 *                   s.a. `disasm_single()'
 *                 - When the second form (with a fixed buffer size) is used, do a full
 *                   disassembly of that number of bytes, following `DISASSEMBLER_FNORMAL'
 *                   s.a. `disasm()'
 *             - `%[vinfo]' / `%[vinfo:<FORMAT=%f(%l,%c) : %n>]'
 *                 - Print addr2line information for a text address read from `va_arg(args, void *)'
 *                 - The given FORMAT string is a special printf-like format declaration
 *                   that accepts the following substitutions:
 *                   - `%%'   Print a single `%'-character (used for escaping `%')
 *                   - `%p'   Output the queried text address the same way `format_c16printf(..., "%q", addr)' would (as `sizeof(void *) * 2' uppercase hex characters)
 *                   - `%n'   Symbol name of the surrounding symbol (managed), or `???'   `di_debug_addr2line_t::al_name'
 *                   - `%N'   Raw name of the surrounding symbol, or `???'                `di_debug_addr2line_t::al_rawname'
 *                   - `%l'   Source line number (1-based; 0 if unknown)                  `di_debug_addr2line_t::al_srcline'
 *                   - `%c'   Source column number (1-based; 0 if unknown)                `di_debug_addr2line_t::al_srccol'
 *                   - `%f'   Source filename (with path prefix)                          `di_debug_addr2line_t::(al_cubase|al_srcpath|al_srcfile)'
 *                   - `%Rf'  Source filename (without path prefix)                       `di_debug_addr2line_t::al_srcfile'
 *                   - `%<'   Absolute starting address of the associated source location `di_debug_addr2line_t::al_linestart'
 *                   - `%>'   Absolute end address of the associated source location      `di_debug_addr2line_t::al_lineend'
 *                   - `%1>'  Absolute end address of the associated source location - 1  `di_debug_addr2line_t::al_lineend'
 *                   - `%S'   Absolute starting address of the surrounding symbol         `di_debug_addr2line_t::al_symstart'
 *                   - `%E'   Absolute end address of the surrounding symbol              `di_debug_addr2line_t::al_symend'
 *                   - `%1E'  Absolute end address of the surrounding symbol - 1          `di_debug_addr2line_t::al_symend'
 *                   - `%Dl'  Declaration line number (1-based; 0 if unknown)             `di_debug_addr2line_t::al_dclline'
 *                   - `%Dc'  Declaration column number (1-based; 0 if unknown)           `di_debug_addr2line_t::al_dclcol'
 *                   - `%Df'  Declaration filename (with path prefix)                     `di_debug_addr2line_t::(al_cubase|al_dclpath|al_dclfile)'
 *                   - `%RDf' Declaration filename (without path prefix)                  `di_debug_addr2line_t::al_dclfile'
 *                   - Any other character[-sequence] is forwarded as-is
 *             - `%[...]' Other sequences are resered for future usage
 * >>> Possible (and actual) uses:
 *  - printf:           Unbuffered output into any kind of stream/file.
 *  - sprintf/snprintf: Unsafe/Counted string formatting into a user-supplied buffer.
 *  - strdupf:          Output into dynamically allocated heap memory,
 *                      increasing the buffer when it gets filled completely.
 *  - syslog:           Unbuffered system-log output.
 *  - ...               There are a _lot_ more... */
__CREDIRECT_DOS(__ATTR_LIBC_PRINTF(3, 0) __ATTR_NONNULL((1, 3)),__SSIZE_TYPE__,__NOTHROW_NCX,__localdep_format_vc16printf,(__pc16formatprinter __printer, void *__arg, __CHAR16_TYPE__ const *__restrict __format, __builtin_va_list __args),format_vwprintf,(__printer,__arg,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <local/parts.wchar.format-printer/format_vwprintf.h>
/* Generic printf implementation
 * Taking a regular printf-style format string and arguments, these
 * functions will call the given `PRINTER' callback with various strings
 * that, when put together, result in the desired formated text.
 *  - `PRINTER' obviously is called with the text parts in their correct order
 *  - If `PRINTER' returns '< 0', the function returns immediately,
 *    yielding that same value. Otherwise, format_printf() returns
 *    the sum of all return values from `PRINTER'.
 *  - The strings passed to `PRINTER' may not necessarily be zero-terminated, and
 *    a second argument is passed that indicates the absolute length in characters.
 * Supported extensions:
 *  - `%q'-format mode: Semantics equivalent to `%s', this modifier escapes the string using
 *                        `format_c16escape' with flags set of 'FORMAT_ESCAPE_FNONE', or
 *                        `PRINTF_FLAG_PREFIX' when the '#' flag was used (e.g.: `%#q').
 *  - `%.*s'   Instead of reading an `int' and dealing with undefined behavior when negative, an `unsigned int' is read.
 *  - `%.?s'   Similar to `%.*s', but takes a `size_t' from the argument list instead of an `unsigned int', as well as define
 *             a fixed-length buffer size for string/quote formats (thus allowing you to print '\0' characters after quoting)
 *  - `%$s'    Same as `%.?s'
 *  - `%q'     Print an escaped string. (format_printf(..., "a%qb", "foo\nbar")) --> "a\"foo\\nbar\"b"
 *  - `%#q'    Same as %q, without quotes. (format_printf(..., "a%#qb", "foo\nbar")) --> "afoo\\nbarb"
 *  - `%Q'     Print an escaped character. (format_printf(..., "a%Qb", '\n')) --> "a\'\\n\'b"
 *  - `%#Q'    Same as %Q, without quotes. (format_printf(..., "a%#Qb", '\n')) --> "a\\nb"
 *  - `%I'     length modifier: Integral length equivalent to sizeof(size_t)/sizeof(uintptr_t).
 *  - `%I8'    length modifier: Integral length equivalent to sizeof(int8_t).
 *  - `%I16'   length modifier: Integral length equivalent to sizeof(int16_t).
 *  - `%I32'   length modifier: Integral length equivalent to sizeof(int32_t).
 *  - `%I64'   length modifier: Integral length equivalent to sizeof(int64_t).
 *  - `%[...]' Extended formating options, allowing for additional formating options:
 *             - `%$[hex]' / `%$[hex:lLoOpPaAhH]'
 *                 - Invoke `format_c16hexdump(..., va_arg(args, void *))'
 *                 - Integer-length (`%$I32[hex]') flags affect `FORMAT_HEXDUMP_(BYTES|WORDS|DWORDS|QWORDS)'
 *                 - The argument string affect flags (defaults to `0x0000')
 *                    - `0x0001':  yes:l, no:L
 *                    - `0x0004':   yes:o, no:O
 *                    - `0x0002': yes:P, no:p
 *                    - `0x0010':   yes:A, no:a
 *                    - `0x0008':     yes:H, no:h
 *             - `%[gen]'
 *                 - Invoke a custom format printer function pointer passed through args
 *                   >> typedef ssize_t (*PGEN)(pwformatprinter printer, void *arg);
 *                   >> PGEN g = va_arg(args, PGEN);
 *                   >> DO((*g)(printer, arg));
 *             - `%[gen:c]'
 *                 - Same as `%[gen]', but insert an additional argument `T' that depends
 *                   on the integer size prefix (`%I32[gen:c]') and defaults to `void *'
 *                   >> typedef ssize_t (*PGEN)(T a, pwformatprinter printer, void *arg);
 *                   >> PGEN g = va_arg(args, PGEN);
 *                   >> T    a = va_arg(args, T);
 *                   >> DO((*g)(a, printer, arg));
 *             - `%[disasm]' / `%$[disasm]'
 *                 - Print the mnemonic and operands of a single native assembly
 *                   instruction read from `va_arg(args, void *)' (using `libdisasm')
 *                   s.a. `disasm_single()'
 *                 - When the second form (with a fixed buffer size) is used, do a full
 *                   disassembly of that number of bytes, following `DISASSEMBLER_FNORMAL'
 *                   s.a. `disasm()'
 *             - `%[vinfo]' / `%[vinfo:<FORMAT=%f(%l,%c) : %n>]'
 *                 - Print addr2line information for a text address read from `va_arg(args, void *)'
 *                 - The given FORMAT string is a special printf-like format declaration
 *                   that accepts the following substitutions:
 *                   - `%%'   Print a single `%'-character (used for escaping `%')
 *                   - `%p'   Output the queried text address the same way `format_c16printf(..., "%q", addr)' would (as `sizeof(void *) * 2' uppercase hex characters)
 *                   - `%n'   Symbol name of the surrounding symbol (managed), or `???'   `di_debug_addr2line_t::al_name'
 *                   - `%N'   Raw name of the surrounding symbol, or `???'                `di_debug_addr2line_t::al_rawname'
 *                   - `%l'   Source line number (1-based; 0 if unknown)                  `di_debug_addr2line_t::al_srcline'
 *                   - `%c'   Source column number (1-based; 0 if unknown)                `di_debug_addr2line_t::al_srccol'
 *                   - `%f'   Source filename (with path prefix)                          `di_debug_addr2line_t::(al_cubase|al_srcpath|al_srcfile)'
 *                   - `%Rf'  Source filename (without path prefix)                       `di_debug_addr2line_t::al_srcfile'
 *                   - `%<'   Absolute starting address of the associated source location `di_debug_addr2line_t::al_linestart'
 *                   - `%>'   Absolute end address of the associated source location      `di_debug_addr2line_t::al_lineend'
 *                   - `%1>'  Absolute end address of the associated source location - 1  `di_debug_addr2line_t::al_lineend'
 *                   - `%S'   Absolute starting address of the surrounding symbol         `di_debug_addr2line_t::al_symstart'
 *                   - `%E'   Absolute end address of the surrounding symbol              `di_debug_addr2line_t::al_symend'
 *                   - `%1E'  Absolute end address of the surrounding symbol - 1          `di_debug_addr2line_t::al_symend'
 *                   - `%Dl'  Declaration line number (1-based; 0 if unknown)             `di_debug_addr2line_t::al_dclline'
 *                   - `%Dc'  Declaration column number (1-based; 0 if unknown)           `di_debug_addr2line_t::al_dclcol'
 *                   - `%Df'  Declaration filename (with path prefix)                     `di_debug_addr2line_t::(al_cubase|al_dclpath|al_dclfile)'
 *                   - `%RDf' Declaration filename (without path prefix)                  `di_debug_addr2line_t::al_dclfile'
 *                   - Any other character[-sequence] is forwarded as-is
 *             - `%[...]' Other sequences are resered for future usage
 * >>> Possible (and actual) uses:
 *  - printf:           Unbuffered output into any kind of stream/file.
 *  - sprintf/snprintf: Unsafe/Counted string formatting into a user-supplied buffer.
 *  - strdupf:          Output into dynamically allocated heap memory,
 *                      increasing the buffer when it gets filled completely.
 *  - syslog:           Unbuffered system-log output.
 *  - ...               There are a _lot_ more... */
#define __localdep_format_vc16printf (*(__SSIZE_TYPE__(__LIBCCALL*)(__pc16formatprinter, void *, __CHAR16_TYPE__ const *__restrict, __builtin_va_list))&(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(format_vwprintf)))
#else /* LIBC: format_vc16printf */
#include <local/parts.wchar.format-printer/format_vc16printf.h>
/* Generic printf implementation
 * Taking a regular printf-style format string and arguments, these
 * functions will call the given `PRINTER' callback with various strings
 * that, when put together, result in the desired formated text.
 *  - `PRINTER' obviously is called with the text parts in their correct order
 *  - If `PRINTER' returns '< 0', the function returns immediately,
 *    yielding that same value. Otherwise, format_printf() returns
 *    the sum of all return values from `PRINTER'.
 *  - The strings passed to `PRINTER' may not necessarily be zero-terminated, and
 *    a second argument is passed that indicates the absolute length in characters.
 * Supported extensions:
 *  - `%q'-format mode: Semantics equivalent to `%s', this modifier escapes the string using
 *                        `format_c16escape' with flags set of 'FORMAT_ESCAPE_FNONE', or
 *                        `PRINTF_FLAG_PREFIX' when the '#' flag was used (e.g.: `%#q').
 *  - `%.*s'   Instead of reading an `int' and dealing with undefined behavior when negative, an `unsigned int' is read.
 *  - `%.?s'   Similar to `%.*s', but takes a `size_t' from the argument list instead of an `unsigned int', as well as define
 *             a fixed-length buffer size for string/quote formats (thus allowing you to print '\0' characters after quoting)
 *  - `%$s'    Same as `%.?s'
 *  - `%q'     Print an escaped string. (format_printf(..., "a%qb", "foo\nbar")) --> "a\"foo\\nbar\"b"
 *  - `%#q'    Same as %q, without quotes. (format_printf(..., "a%#qb", "foo\nbar")) --> "afoo\\nbarb"
 *  - `%Q'     Print an escaped character. (format_printf(..., "a%Qb", '\n')) --> "a\'\\n\'b"
 *  - `%#Q'    Same as %Q, without quotes. (format_printf(..., "a%#Qb", '\n')) --> "a\\nb"
 *  - `%I'     length modifier: Integral length equivalent to sizeof(size_t)/sizeof(uintptr_t).
 *  - `%I8'    length modifier: Integral length equivalent to sizeof(int8_t).
 *  - `%I16'   length modifier: Integral length equivalent to sizeof(int16_t).
 *  - `%I32'   length modifier: Integral length equivalent to sizeof(int32_t).
 *  - `%I64'   length modifier: Integral length equivalent to sizeof(int64_t).
 *  - `%[...]' Extended formating options, allowing for additional formating options:
 *             - `%$[hex]' / `%$[hex:lLoOpPaAhH]'
 *                 - Invoke `format_c16hexdump(..., va_arg(args, void *))'
 *                 - Integer-length (`%$I32[hex]') flags affect `FORMAT_HEXDUMP_(BYTES|WORDS|DWORDS|QWORDS)'
 *                 - The argument string affect flags (defaults to `0x0000')
 *                    - `0x0001':  yes:l, no:L
 *                    - `0x0004':   yes:o, no:O
 *                    - `0x0002': yes:P, no:p
 *                    - `0x0010':   yes:A, no:a
 *                    - `0x0008':     yes:H, no:h
 *             - `%[gen]'
 *                 - Invoke a custom format printer function pointer passed through args
 *                   >> typedef ssize_t (*PGEN)(pwformatprinter printer, void *arg);
 *                   >> PGEN g = va_arg(args, PGEN);
 *                   >> DO((*g)(printer, arg));
 *             - `%[gen:c]'
 *                 - Same as `%[gen]', but insert an additional argument `T' that depends
 *                   on the integer size prefix (`%I32[gen:c]') and defaults to `void *'
 *                   >> typedef ssize_t (*PGEN)(T a, pwformatprinter printer, void *arg);
 *                   >> PGEN g = va_arg(args, PGEN);
 *                   >> T    a = va_arg(args, T);
 *                   >> DO((*g)(a, printer, arg));
 *             - `%[disasm]' / `%$[disasm]'
 *                 - Print the mnemonic and operands of a single native assembly
 *                   instruction read from `va_arg(args, void *)' (using `libdisasm')
 *                   s.a. `disasm_single()'
 *                 - When the second form (with a fixed buffer size) is used, do a full
 *                   disassembly of that number of bytes, following `DISASSEMBLER_FNORMAL'
 *                   s.a. `disasm()'
 *             - `%[vinfo]' / `%[vinfo:<FORMAT=%f(%l,%c) : %n>]'
 *                 - Print addr2line information for a text address read from `va_arg(args, void *)'
 *                 - The given FORMAT string is a special printf-like format declaration
 *                   that accepts the following substitutions:
 *                   - `%%'   Print a single `%'-character (used for escaping `%')
 *                   - `%p'   Output the queried text address the same way `format_c16printf(..., "%q", addr)' would (as `sizeof(void *) * 2' uppercase hex characters)
 *                   - `%n'   Symbol name of the surrounding symbol (managed), or `???'   `di_debug_addr2line_t::al_name'
 *                   - `%N'   Raw name of the surrounding symbol, or `???'                `di_debug_addr2line_t::al_rawname'
 *                   - `%l'   Source line number (1-based; 0 if unknown)                  `di_debug_addr2line_t::al_srcline'
 *                   - `%c'   Source column number (1-based; 0 if unknown)                `di_debug_addr2line_t::al_srccol'
 *                   - `%f'   Source filename (with path prefix)                          `di_debug_addr2line_t::(al_cubase|al_srcpath|al_srcfile)'
 *                   - `%Rf'  Source filename (without path prefix)                       `di_debug_addr2line_t::al_srcfile'
 *                   - `%<'   Absolute starting address of the associated source location `di_debug_addr2line_t::al_linestart'
 *                   - `%>'   Absolute end address of the associated source location      `di_debug_addr2line_t::al_lineend'
 *                   - `%1>'  Absolute end address of the associated source location - 1  `di_debug_addr2line_t::al_lineend'
 *                   - `%S'   Absolute starting address of the surrounding symbol         `di_debug_addr2line_t::al_symstart'
 *                   - `%E'   Absolute end address of the surrounding symbol              `di_debug_addr2line_t::al_symend'
 *                   - `%1E'  Absolute end address of the surrounding symbol - 1          `di_debug_addr2line_t::al_symend'
 *                   - `%Dl'  Declaration line number (1-based; 0 if unknown)             `di_debug_addr2line_t::al_dclline'
 *                   - `%Dc'  Declaration column number (1-based; 0 if unknown)           `di_debug_addr2line_t::al_dclcol'
 *                   - `%Df'  Declaration filename (with path prefix)                     `di_debug_addr2line_t::(al_cubase|al_dclpath|al_dclfile)'
 *                   - `%RDf' Declaration filename (without path prefix)                  `di_debug_addr2line_t::al_dclfile'
 *                   - Any other character[-sequence] is forwarded as-is
 *             - `%[...]' Other sequences are resered for future usage
 * >>> Possible (and actual) uses:
 *  - printf:           Unbuffered output into any kind of stream/file.
 *  - sprintf/snprintf: Unsafe/Counted string formatting into a user-supplied buffer.
 *  - strdupf:          Output into dynamically allocated heap memory,
 *                      increasing the buffer when it gets filled completely.
 *  - syslog:           Unbuffered system-log output.
 *  - ...               There are a _lot_ more... */
#define __localdep_format_vc16printf (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(format_vc16printf))
#endif /* format_vc16printf... */
#endif /* !____localdep_format_vc16printf_defined */

__NAMESPACE_LOCAL_BEGIN
/* Generic printf implementation
 * Taking a regular printf-style format string and arguments, these
 * functions will call the given `PRINTER' callback with various strings
 * that, when put together, result in the desired formated text.
 *  - `PRINTER' obviously is called with the text parts in their correct order
 *  - If `PRINTER' returns '< 0', the function returns immediately,
 *    yielding that same value. Otherwise, format_printf() returns
 *    the sum of all return values from `PRINTER'.
 *  - The strings passed to `PRINTER' may not necessarily be zero-terminated, and
 *    a second argument is passed that indicates the absolute length in characters.
 * Supported extensions:
 *  - `%q'-format mode: Semantics equivalent to `%s', this modifier escapes the string using
 *                        `format_c16escape' with flags set of 'FORMAT_ESCAPE_FNONE', or
 *                        `PRINTF_FLAG_PREFIX' when the '#' flag was used (e.g.: `%#q').
 *  - `%.*s'   Instead of reading an `int' and dealing with undefined behavior when negative, an `unsigned int' is read.
 *  - `%.?s'   Similar to `%.*s', but takes a `size_t' from the argument list instead of an `unsigned int', as well as define
 *             a fixed-length buffer size for string/quote formats (thus allowing you to print '\0' characters after quoting)
 *  - `%$s'    Same as `%.?s'
 *  - `%q'     Print an escaped string. (format_printf(..., "a%qb", "foo\nbar")) --> "a\"foo\\nbar\"b"
 *  - `%#q'    Same as %q, without quotes. (format_printf(..., "a%#qb", "foo\nbar")) --> "afoo\\nbarb"
 *  - `%Q'     Print an escaped character. (format_printf(..., "a%Qb", '\n')) --> "a\'\\n\'b"
 *  - `%#Q'    Same as %Q, without quotes. (format_printf(..., "a%#Qb", '\n')) --> "a\\nb"
 *  - `%I'     length modifier: Integral length equivalent to sizeof(size_t)/sizeof(uintptr_t).
 *  - `%I8'    length modifier: Integral length equivalent to sizeof(int8_t).
 *  - `%I16'   length modifier: Integral length equivalent to sizeof(int16_t).
 *  - `%I32'   length modifier: Integral length equivalent to sizeof(int32_t).
 *  - `%I64'   length modifier: Integral length equivalent to sizeof(int64_t).
 *  - `%[...]' Extended formating options, allowing for additional formating options:
 *             - `%$[hex]' / `%$[hex:lLoOpPaAhH]'
 *                 - Invoke `format_c16hexdump(..., va_arg(args, void *))'
 *                 - Integer-length (`%$I32[hex]') flags affect `FORMAT_HEXDUMP_(BYTES|WORDS|DWORDS|QWORDS)'
 *                 - The argument string affect flags (defaults to `0x0000')
 *                    - `0x0001':  yes:l, no:L
 *                    - `0x0004':   yes:o, no:O
 *                    - `0x0002': yes:P, no:p
 *                    - `0x0010':   yes:A, no:a
 *                    - `0x0008':     yes:H, no:h
 *             - `%[gen]'
 *                 - Invoke a custom format printer function pointer passed through args
 *                   >> typedef ssize_t (*PGEN)(pwformatprinter printer, void *arg);
 *                   >> PGEN g = va_arg(args, PGEN);
 *                   >> DO((*g)(printer, arg));
 *             - `%[gen:c]'
 *                 - Same as `%[gen]', but insert an additional argument `T' that depends
 *                   on the integer size prefix (`%I32[gen:c]') and defaults to `void *'
 *                   >> typedef ssize_t (*PGEN)(T a, pwformatprinter printer, void *arg);
 *                   >> PGEN g = va_arg(args, PGEN);
 *                   >> T    a = va_arg(args, T);
 *                   >> DO((*g)(a, printer, arg));
 *             - `%[disasm]' / `%$[disasm]'
 *                 - Print the mnemonic and operands of a single native assembly
 *                   instruction read from `va_arg(args, void *)' (using `libdisasm')
 *                   s.a. `disasm_single()'
 *                 - When the second form (with a fixed buffer size) is used, do a full
 *                   disassembly of that number of bytes, following `DISASSEMBLER_FNORMAL'
 *                   s.a. `disasm()'
 *             - `%[vinfo]' / `%[vinfo:<FORMAT=%f(%l,%c) : %n>]'
 *                 - Print addr2line information for a text address read from `va_arg(args, void *)'
 *                 - The given FORMAT string is a special printf-like format declaration
 *                   that accepts the following substitutions:
 *                   - `%%'   Print a single `%'-character (used for escaping `%')
 *                   - `%p'   Output the queried text address the same way `format_c16printf(..., "%q", addr)' would (as `sizeof(void *) * 2' uppercase hex characters)
 *                   - `%n'   Symbol name of the surrounding symbol (managed), or `???'   `di_debug_addr2line_t::al_name'
 *                   - `%N'   Raw name of the surrounding symbol, or `???'                `di_debug_addr2line_t::al_rawname'
 *                   - `%l'   Source line number (1-based; 0 if unknown)                  `di_debug_addr2line_t::al_srcline'
 *                   - `%c'   Source column number (1-based; 0 if unknown)                `di_debug_addr2line_t::al_srccol'
 *                   - `%f'   Source filename (with path prefix)                          `di_debug_addr2line_t::(al_cubase|al_srcpath|al_srcfile)'
 *                   - `%Rf'  Source filename (without path prefix)                       `di_debug_addr2line_t::al_srcfile'
 *                   - `%<'   Absolute starting address of the associated source location `di_debug_addr2line_t::al_linestart'
 *                   - `%>'   Absolute end address of the associated source location      `di_debug_addr2line_t::al_lineend'
 *                   - `%1>'  Absolute end address of the associated source location - 1  `di_debug_addr2line_t::al_lineend'
 *                   - `%S'   Absolute starting address of the surrounding symbol         `di_debug_addr2line_t::al_symstart'
 *                   - `%E'   Absolute end address of the surrounding symbol              `di_debug_addr2line_t::al_symend'
 *                   - `%1E'  Absolute end address of the surrounding symbol - 1          `di_debug_addr2line_t::al_symend'
 *                   - `%Dl'  Declaration line number (1-based; 0 if unknown)             `di_debug_addr2line_t::al_dclline'
 *                   - `%Dc'  Declaration column number (1-based; 0 if unknown)           `di_debug_addr2line_t::al_dclcol'
 *                   - `%Df'  Declaration filename (with path prefix)                     `di_debug_addr2line_t::(al_cubase|al_dclpath|al_dclfile)'
 *                   - `%RDf' Declaration filename (without path prefix)                  `di_debug_addr2line_t::al_dclfile'
 *                   - Any other character[-sequence] is forwarded as-is
 *             - `%[...]' Other sequences are resered for future usage
 * >>> Possible (and actual) uses:
 *  - printf:           Unbuffered output into any kind of stream/file.
 *  - sprintf/snprintf: Unsafe/Counted string formatting into a user-supplied buffer.
 *  - strdupf:          Output into dynamically allocated heap memory,
 *                      increasing the buffer when it gets filled completely.
 *  - syslog:           Unbuffered system-log output.
 *  - ...               There are a _lot_ more... */
__LOCAL_LIBC(format_c16printf) __ATTR_LIBC_PRINTF(3, 4) __ATTR_NONNULL((1, 3)) __SSIZE_TYPE__
__NOTHROW_NCX(__VLIBDCALL __LIBC_LOCAL_NAME(format_c16printf))(__pc16formatprinter __printer,
                                                               void *__arg,
                                                               __CHAR16_TYPE__ const *__restrict __format,
                                                               ...) {
#line 904 "kos/src/libc/magic/format-printer.c"
	__SSIZE_TYPE__ __result;
	__builtin_va_list __args;
	__builtin_va_start(__args, __format);
	__result = __localdep_format_vc16printf(__printer, __arg, __format, __args);
	__builtin_va_end(__args);
	return __result;
}
__NAMESPACE_LOCAL_END
#endif /* !__local_format_c16printf_defined */
