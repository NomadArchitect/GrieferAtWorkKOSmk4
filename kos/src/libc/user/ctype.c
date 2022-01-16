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
#ifndef GUARD_LIBC_USER_CTYPE_C
#define GUARD_LIBC_USER_CTYPE_C 1

#include "../api.h"
/**/

#include <hybrid/byteorder.h>

#include <kos/exec/idata.h>

#include "ctype.h"

DECL_BEGIN


#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define CTB_LOC_ISUPPER  (1 << 0)
#define CTB_LOC_ISLOWER  (1 << 1)
#define CTB_LOC_ISALPHA  (1 << 2)
#define CTB_LOC_ISDIGIT  (1 << 3)
#define CTB_LOC_ISXDIGIT (1 << 4)
#define CTB_LOC_ISSPACE  (1 << 5)
#define CTB_LOC_ISPRINT  (1 << 6)
#define CTB_LOC_ISGRAPH  (1 << 7)
#define CTB_LOC_ISBLANK  (1 << 8)
#define CTB_LOC_ISCNTRL  (1 << 9)
#define CTB_LOC_ISPUNCT  (1 << 10)
#define CTB_LOC_ISALNUM  (1 << 11)
#else /* __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ */
#define CTB_LOC_ISUPPER  (1 << 8)
#define CTB_LOC_ISLOWER  (1 << 9)
#define CTB_LOC_ISALPHA  (1 << 10)
#define CTB_LOC_ISDIGIT  (1 << 11)
#define CTB_LOC_ISXDIGIT (1 << 12)
#define CTB_LOC_ISSPACE  (1 << 13)
#define CTB_LOC_ISPRINT  (1 << 14)
#define CTB_LOC_ISGRAPH  (1 << 15)
#define CTB_LOC_ISBLANK  (1 << 0)
#define CTB_LOC_ISCNTRL  (1 << 1)
#define CTB_LOC_ISPUNCT  (1 << 2)
#define CTB_LOC_ISALNUM  (1 << 3)
#endif /* __BYTE_ORDER__ != __ORDER_BIG_ENDIAN__ */


#define ASCII_ISCNTRL(ch)  ((ch) <= 0x1f || (ch) == 0x7f)
#define ASCII_ISSPACE(ch)  (((ch) >= 0x09 && (ch) <= 0x0d) || (ch) == 0x20)
#define ASCII_ISUPPER(ch)  ((ch) >= 0x41 && (ch) <= 0x5a)
#define ASCII_ISLOWER(ch)  ((ch) >= 0x61 && (ch) <= 0x7a)
#define ASCII_ISALPHA(ch)  (ASCII_ISUPPER(ch) || ASCII_ISLOWER(ch))
#define ASCII_ISDIGIT(ch)  ((ch) >= 0x30 && (ch) <= 0x39)
#define ASCII_ISXDIGIT(ch) (ASCII_ISDIGIT(ch) || ((ch) >= 0x41 && (ch) <= 0x46) || ((ch) >= 0x61 && (ch) <= 0x66))
#define ASCII_ISALNUM(ch)  (ASCII_ISUPPER(ch) || ASCII_ISLOWER(ch) || ASCII_ISDIGIT(ch))
#define ASCII_ISPUNCT(ch)  (((ch) >= 0x21 && (ch) <= 0x2f) || ((ch) >= 0x3a && (ch) <= 0x40) || ((ch) >= 0x5b && (ch) <= 0x60) || ((ch) >= 0x7b && (ch) <= 0x7e))
#define ASCII_ISGRAPH(ch)  ((ch) >= 0x21 && (ch) <= 0x7e)
#define ASCII_ISPRINT(ch)  ((ch) >= 0x20 && (ch) <= 0x7e)
#define ASCII_ISBLANK(ch)  ((ch) == 0x09 || (ch) == 0x20)
#define ASCII_TOLOWER(ch)  (ASCII_ISUPPER(ch) ? ((ch) + 0x20) : (ch))
#define ASCII_TOUPPER(ch)  (ASCII_ISLOWER(ch) ? ((ch)-0x20) : (ch))


PRIVATE ATTR_SECTION(".rodata.crt.unicode.static.ctype")
uint16_t const libc___ctype_b_loc_matrix[384] = {
/*[[[deemon

final local known_flags = {
	("CTB_LOC_ISUPPER",  [](ch) -> ASCII_ISUPPER(ch)),
	("CTB_LOC_ISLOWER",  [](ch) -> ASCII_ISLOWER(ch)),
	("CTB_LOC_ISALPHA",  [](ch) -> ASCII_ISALPHA(ch)),
	("CTB_LOC_ISDIGIT",  [](ch) -> ASCII_ISDIGIT(ch)),
	("CTB_LOC_ISXDIGIT", [](ch) -> ASCII_ISXDIGIT(ch)),
	("CTB_LOC_ISSPACE",  [](ch) -> ASCII_ISSPACE(ch)),
	("CTB_LOC_ISPRINT",  [](ch) -> ASCII_ISPRINT(ch)),
	("CTB_LOC_ISGRAPH",  [](ch) -> ASCII_ISGRAPH(ch)),
	("CTB_LOC_ISBLANK",  [](ch) -> ASCII_ISBLANK(ch)),
	("CTB_LOC_ISCNTRL",  [](ch) -> ASCII_ISCNTRL(ch)),
	("CTB_LOC_ISPUNCT",  [](ch) -> ASCII_ISPUNCT(ch)),
	("CTB_LOC_ISALNUM",  [](ch) -> ASCII_ISALNUM(ch))
};

for (local x: [-128: 255+1]) {
	local ord = x.unsigned8;
	local flags = [];
	for (local f, chk: known_flags) {
		if (chk(ord))
			flags.append(f);
	}
	print "\t/" "* [{}] = *" "/ {},".format({ str(x).rjust(4), flags ? " | ".join(flags) : "0" });
}
]]]*/
	/* [-128] = */ 0,
	/* [-127] = */ 0,
	/* [-126] = */ 0,
	/* [-125] = */ 0,
	/* [-124] = */ 0,
	/* [-123] = */ 0,
	/* [-122] = */ 0,
	/* [-121] = */ 0,
	/* [-120] = */ 0,
	/* [-119] = */ 0,
	/* [-118] = */ 0,
	/* [-117] = */ 0,
	/* [-116] = */ 0,
	/* [-115] = */ 0,
	/* [-114] = */ 0,
	/* [-113] = */ 0,
	/* [-112] = */ 0,
	/* [-111] = */ 0,
	/* [-110] = */ 0,
	/* [-109] = */ 0,
	/* [-108] = */ 0,
	/* [-107] = */ 0,
	/* [-106] = */ 0,
	/* [-105] = */ 0,
	/* [-104] = */ 0,
	/* [-103] = */ 0,
	/* [-102] = */ 0,
	/* [-101] = */ 0,
	/* [-100] = */ 0,
	/* [ -99] = */ 0,
	/* [ -98] = */ 0,
	/* [ -97] = */ 0,
	/* [ -96] = */ 0,
	/* [ -95] = */ 0,
	/* [ -94] = */ 0,
	/* [ -93] = */ 0,
	/* [ -92] = */ 0,
	/* [ -91] = */ 0,
	/* [ -90] = */ 0,
	/* [ -89] = */ 0,
	/* [ -88] = */ 0,
	/* [ -87] = */ 0,
	/* [ -86] = */ 0,
	/* [ -85] = */ 0,
	/* [ -84] = */ 0,
	/* [ -83] = */ 0,
	/* [ -82] = */ 0,
	/* [ -81] = */ 0,
	/* [ -80] = */ 0,
	/* [ -79] = */ 0,
	/* [ -78] = */ 0,
	/* [ -77] = */ 0,
	/* [ -76] = */ 0,
	/* [ -75] = */ 0,
	/* [ -74] = */ 0,
	/* [ -73] = */ 0,
	/* [ -72] = */ 0,
	/* [ -71] = */ 0,
	/* [ -70] = */ 0,
	/* [ -69] = */ 0,
	/* [ -68] = */ 0,
	/* [ -67] = */ 0,
	/* [ -66] = */ 0,
	/* [ -65] = */ 0,
	/* [ -64] = */ 0,
	/* [ -63] = */ 0,
	/* [ -62] = */ 0,
	/* [ -61] = */ 0,
	/* [ -60] = */ 0,
	/* [ -59] = */ 0,
	/* [ -58] = */ 0,
	/* [ -57] = */ 0,
	/* [ -56] = */ 0,
	/* [ -55] = */ 0,
	/* [ -54] = */ 0,
	/* [ -53] = */ 0,
	/* [ -52] = */ 0,
	/* [ -51] = */ 0,
	/* [ -50] = */ 0,
	/* [ -49] = */ 0,
	/* [ -48] = */ 0,
	/* [ -47] = */ 0,
	/* [ -46] = */ 0,
	/* [ -45] = */ 0,
	/* [ -44] = */ 0,
	/* [ -43] = */ 0,
	/* [ -42] = */ 0,
	/* [ -41] = */ 0,
	/* [ -40] = */ 0,
	/* [ -39] = */ 0,
	/* [ -38] = */ 0,
	/* [ -37] = */ 0,
	/* [ -36] = */ 0,
	/* [ -35] = */ 0,
	/* [ -34] = */ 0,
	/* [ -33] = */ 0,
	/* [ -32] = */ 0,
	/* [ -31] = */ 0,
	/* [ -30] = */ 0,
	/* [ -29] = */ 0,
	/* [ -28] = */ 0,
	/* [ -27] = */ 0,
	/* [ -26] = */ 0,
	/* [ -25] = */ 0,
	/* [ -24] = */ 0,
	/* [ -23] = */ 0,
	/* [ -22] = */ 0,
	/* [ -21] = */ 0,
	/* [ -20] = */ 0,
	/* [ -19] = */ 0,
	/* [ -18] = */ 0,
	/* [ -17] = */ 0,
	/* [ -16] = */ 0,
	/* [ -15] = */ 0,
	/* [ -14] = */ 0,
	/* [ -13] = */ 0,
	/* [ -12] = */ 0,
	/* [ -11] = */ 0,
	/* [ -10] = */ 0,
	/* [  -9] = */ 0,
	/* [  -8] = */ 0,
	/* [  -7] = */ 0,
	/* [  -6] = */ 0,
	/* [  -5] = */ 0,
	/* [  -4] = */ 0,
	/* [  -3] = */ 0,
	/* [  -2] = */ 0,
	/* [  -1] = */ 0,
	/* [   0] = */ CTB_LOC_ISCNTRL,
	/* [   1] = */ CTB_LOC_ISCNTRL,
	/* [   2] = */ CTB_LOC_ISCNTRL,
	/* [   3] = */ CTB_LOC_ISCNTRL,
	/* [   4] = */ CTB_LOC_ISCNTRL,
	/* [   5] = */ CTB_LOC_ISCNTRL,
	/* [   6] = */ CTB_LOC_ISCNTRL,
	/* [   7] = */ CTB_LOC_ISCNTRL,
	/* [   8] = */ CTB_LOC_ISCNTRL,
	/* [   9] = */ CTB_LOC_ISSPACE | CTB_LOC_ISBLANK | CTB_LOC_ISCNTRL,
	/* [  10] = */ CTB_LOC_ISSPACE | CTB_LOC_ISCNTRL,
	/* [  11] = */ CTB_LOC_ISSPACE | CTB_LOC_ISCNTRL,
	/* [  12] = */ CTB_LOC_ISSPACE | CTB_LOC_ISCNTRL,
	/* [  13] = */ CTB_LOC_ISSPACE | CTB_LOC_ISCNTRL,
	/* [  14] = */ CTB_LOC_ISCNTRL,
	/* [  15] = */ CTB_LOC_ISCNTRL,
	/* [  16] = */ CTB_LOC_ISCNTRL,
	/* [  17] = */ CTB_LOC_ISCNTRL,
	/* [  18] = */ CTB_LOC_ISCNTRL,
	/* [  19] = */ CTB_LOC_ISCNTRL,
	/* [  20] = */ CTB_LOC_ISCNTRL,
	/* [  21] = */ CTB_LOC_ISCNTRL,
	/* [  22] = */ CTB_LOC_ISCNTRL,
	/* [  23] = */ CTB_LOC_ISCNTRL,
	/* [  24] = */ CTB_LOC_ISCNTRL,
	/* [  25] = */ CTB_LOC_ISCNTRL,
	/* [  26] = */ CTB_LOC_ISCNTRL,
	/* [  27] = */ CTB_LOC_ISCNTRL,
	/* [  28] = */ CTB_LOC_ISCNTRL,
	/* [  29] = */ CTB_LOC_ISCNTRL,
	/* [  30] = */ CTB_LOC_ISCNTRL,
	/* [  31] = */ CTB_LOC_ISCNTRL,
	/* [  32] = */ CTB_LOC_ISSPACE | CTB_LOC_ISPRINT | CTB_LOC_ISBLANK,
	/* [  33] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  34] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  35] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  36] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  37] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  38] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  39] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  40] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  41] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  42] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  43] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  44] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  45] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  46] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  47] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  48] = */ CTB_LOC_ISDIGIT | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  49] = */ CTB_LOC_ISDIGIT | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  50] = */ CTB_LOC_ISDIGIT | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  51] = */ CTB_LOC_ISDIGIT | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  52] = */ CTB_LOC_ISDIGIT | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  53] = */ CTB_LOC_ISDIGIT | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  54] = */ CTB_LOC_ISDIGIT | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  55] = */ CTB_LOC_ISDIGIT | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  56] = */ CTB_LOC_ISDIGIT | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  57] = */ CTB_LOC_ISDIGIT | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  58] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  59] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  60] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  61] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  62] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  63] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  64] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  65] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  66] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  67] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  68] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  69] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  70] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  71] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  72] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  73] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  74] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  75] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  76] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  77] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  78] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  79] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  80] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  81] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  82] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  83] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  84] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  85] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  86] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  87] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  88] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  89] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  90] = */ CTB_LOC_ISUPPER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  91] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  92] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  93] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  94] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  95] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  96] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [  97] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  98] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [  99] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 100] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 101] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 102] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISXDIGIT | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 103] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 104] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 105] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 106] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 107] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 108] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 109] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 110] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 111] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 112] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 113] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 114] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 115] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 116] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 117] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 118] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 119] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 120] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 121] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 122] = */ CTB_LOC_ISLOWER | CTB_LOC_ISALPHA | CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISALNUM,
	/* [ 123] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [ 124] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [ 125] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [ 126] = */ CTB_LOC_ISPRINT | CTB_LOC_ISGRAPH | CTB_LOC_ISPUNCT,
	/* [ 127] = */ CTB_LOC_ISCNTRL,
	/* [ 128] = */ 0,
	/* [ 129] = */ 0,
	/* [ 130] = */ 0,
	/* [ 131] = */ 0,
	/* [ 132] = */ 0,
	/* [ 133] = */ 0,
	/* [ 134] = */ 0,
	/* [ 135] = */ 0,
	/* [ 136] = */ 0,
	/* [ 137] = */ 0,
	/* [ 138] = */ 0,
	/* [ 139] = */ 0,
	/* [ 140] = */ 0,
	/* [ 141] = */ 0,
	/* [ 142] = */ 0,
	/* [ 143] = */ 0,
	/* [ 144] = */ 0,
	/* [ 145] = */ 0,
	/* [ 146] = */ 0,
	/* [ 147] = */ 0,
	/* [ 148] = */ 0,
	/* [ 149] = */ 0,
	/* [ 150] = */ 0,
	/* [ 151] = */ 0,
	/* [ 152] = */ 0,
	/* [ 153] = */ 0,
	/* [ 154] = */ 0,
	/* [ 155] = */ 0,
	/* [ 156] = */ 0,
	/* [ 157] = */ 0,
	/* [ 158] = */ 0,
	/* [ 159] = */ 0,
	/* [ 160] = */ 0,
	/* [ 161] = */ 0,
	/* [ 162] = */ 0,
	/* [ 163] = */ 0,
	/* [ 164] = */ 0,
	/* [ 165] = */ 0,
	/* [ 166] = */ 0,
	/* [ 167] = */ 0,
	/* [ 168] = */ 0,
	/* [ 169] = */ 0,
	/* [ 170] = */ 0,
	/* [ 171] = */ 0,
	/* [ 172] = */ 0,
	/* [ 173] = */ 0,
	/* [ 174] = */ 0,
	/* [ 175] = */ 0,
	/* [ 176] = */ 0,
	/* [ 177] = */ 0,
	/* [ 178] = */ 0,
	/* [ 179] = */ 0,
	/* [ 180] = */ 0,
	/* [ 181] = */ 0,
	/* [ 182] = */ 0,
	/* [ 183] = */ 0,
	/* [ 184] = */ 0,
	/* [ 185] = */ 0,
	/* [ 186] = */ 0,
	/* [ 187] = */ 0,
	/* [ 188] = */ 0,
	/* [ 189] = */ 0,
	/* [ 190] = */ 0,
	/* [ 191] = */ 0,
	/* [ 192] = */ 0,
	/* [ 193] = */ 0,
	/* [ 194] = */ 0,
	/* [ 195] = */ 0,
	/* [ 196] = */ 0,
	/* [ 197] = */ 0,
	/* [ 198] = */ 0,
	/* [ 199] = */ 0,
	/* [ 200] = */ 0,
	/* [ 201] = */ 0,
	/* [ 202] = */ 0,
	/* [ 203] = */ 0,
	/* [ 204] = */ 0,
	/* [ 205] = */ 0,
	/* [ 206] = */ 0,
	/* [ 207] = */ 0,
	/* [ 208] = */ 0,
	/* [ 209] = */ 0,
	/* [ 210] = */ 0,
	/* [ 211] = */ 0,
	/* [ 212] = */ 0,
	/* [ 213] = */ 0,
	/* [ 214] = */ 0,
	/* [ 215] = */ 0,
	/* [ 216] = */ 0,
	/* [ 217] = */ 0,
	/* [ 218] = */ 0,
	/* [ 219] = */ 0,
	/* [ 220] = */ 0,
	/* [ 221] = */ 0,
	/* [ 222] = */ 0,
	/* [ 223] = */ 0,
	/* [ 224] = */ 0,
	/* [ 225] = */ 0,
	/* [ 226] = */ 0,
	/* [ 227] = */ 0,
	/* [ 228] = */ 0,
	/* [ 229] = */ 0,
	/* [ 230] = */ 0,
	/* [ 231] = */ 0,
	/* [ 232] = */ 0,
	/* [ 233] = */ 0,
	/* [ 234] = */ 0,
	/* [ 235] = */ 0,
	/* [ 236] = */ 0,
	/* [ 237] = */ 0,
	/* [ 238] = */ 0,
	/* [ 239] = */ 0,
	/* [ 240] = */ 0,
	/* [ 241] = */ 0,
	/* [ 242] = */ 0,
	/* [ 243] = */ 0,
	/* [ 244] = */ 0,
	/* [ 245] = */ 0,
	/* [ 246] = */ 0,
	/* [ 247] = */ 0,
	/* [ 248] = */ 0,
	/* [ 249] = */ 0,
	/* [ 250] = */ 0,
	/* [ 251] = */ 0,
	/* [ 252] = */ 0,
	/* [ 253] = */ 0,
	/* [ 254] = */ 0,
	/* [ 255] = */ 0,
//[[[end]]]
};


PRIVATE ATTR_SECTION(".rodata.crt.unicode.static.ctype")
int32_t const libc___ctype_tolower_loc_matrix[384] = {
/*[[[deemon
import * from deemon;

for (local x: [-128: 255+1]) {
	local result = ASCII_TOLOWER(x);
	print "\t/" "* [{}] = *" "/ {},".format({ str(x).rjust(4), result });
}
]]]*/
	/* [-128] = */ -128,
	/* [-127] = */ -127,
	/* [-126] = */ -126,
	/* [-125] = */ -125,
	/* [-124] = */ -124,
	/* [-123] = */ -123,
	/* [-122] = */ -122,
	/* [-121] = */ -121,
	/* [-120] = */ -120,
	/* [-119] = */ -119,
	/* [-118] = */ -118,
	/* [-117] = */ -117,
	/* [-116] = */ -116,
	/* [-115] = */ -115,
	/* [-114] = */ -114,
	/* [-113] = */ -113,
	/* [-112] = */ -112,
	/* [-111] = */ -111,
	/* [-110] = */ -110,
	/* [-109] = */ -109,
	/* [-108] = */ -108,
	/* [-107] = */ -107,
	/* [-106] = */ -106,
	/* [-105] = */ -105,
	/* [-104] = */ -104,
	/* [-103] = */ -103,
	/* [-102] = */ -102,
	/* [-101] = */ -101,
	/* [-100] = */ -100,
	/* [ -99] = */ -99,
	/* [ -98] = */ -98,
	/* [ -97] = */ -97,
	/* [ -96] = */ -96,
	/* [ -95] = */ -95,
	/* [ -94] = */ -94,
	/* [ -93] = */ -93,
	/* [ -92] = */ -92,
	/* [ -91] = */ -91,
	/* [ -90] = */ -90,
	/* [ -89] = */ -89,
	/* [ -88] = */ -88,
	/* [ -87] = */ -87,
	/* [ -86] = */ -86,
	/* [ -85] = */ -85,
	/* [ -84] = */ -84,
	/* [ -83] = */ -83,
	/* [ -82] = */ -82,
	/* [ -81] = */ -81,
	/* [ -80] = */ -80,
	/* [ -79] = */ -79,
	/* [ -78] = */ -78,
	/* [ -77] = */ -77,
	/* [ -76] = */ -76,
	/* [ -75] = */ -75,
	/* [ -74] = */ -74,
	/* [ -73] = */ -73,
	/* [ -72] = */ -72,
	/* [ -71] = */ -71,
	/* [ -70] = */ -70,
	/* [ -69] = */ -69,
	/* [ -68] = */ -68,
	/* [ -67] = */ -67,
	/* [ -66] = */ -66,
	/* [ -65] = */ -65,
	/* [ -64] = */ -64,
	/* [ -63] = */ -63,
	/* [ -62] = */ -62,
	/* [ -61] = */ -61,
	/* [ -60] = */ -60,
	/* [ -59] = */ -59,
	/* [ -58] = */ -58,
	/* [ -57] = */ -57,
	/* [ -56] = */ -56,
	/* [ -55] = */ -55,
	/* [ -54] = */ -54,
	/* [ -53] = */ -53,
	/* [ -52] = */ -52,
	/* [ -51] = */ -51,
	/* [ -50] = */ -50,
	/* [ -49] = */ -49,
	/* [ -48] = */ -48,
	/* [ -47] = */ -47,
	/* [ -46] = */ -46,
	/* [ -45] = */ -45,
	/* [ -44] = */ -44,
	/* [ -43] = */ -43,
	/* [ -42] = */ -42,
	/* [ -41] = */ -41,
	/* [ -40] = */ -40,
	/* [ -39] = */ -39,
	/* [ -38] = */ -38,
	/* [ -37] = */ -37,
	/* [ -36] = */ -36,
	/* [ -35] = */ -35,
	/* [ -34] = */ -34,
	/* [ -33] = */ -33,
	/* [ -32] = */ -32,
	/* [ -31] = */ -31,
	/* [ -30] = */ -30,
	/* [ -29] = */ -29,
	/* [ -28] = */ -28,
	/* [ -27] = */ -27,
	/* [ -26] = */ -26,
	/* [ -25] = */ -25,
	/* [ -24] = */ -24,
	/* [ -23] = */ -23,
	/* [ -22] = */ -22,
	/* [ -21] = */ -21,
	/* [ -20] = */ -20,
	/* [ -19] = */ -19,
	/* [ -18] = */ -18,
	/* [ -17] = */ -17,
	/* [ -16] = */ -16,
	/* [ -15] = */ -15,
	/* [ -14] = */ -14,
	/* [ -13] = */ -13,
	/* [ -12] = */ -12,
	/* [ -11] = */ -11,
	/* [ -10] = */ -10,
	/* [  -9] = */ -9,
	/* [  -8] = */ -8,
	/* [  -7] = */ -7,
	/* [  -6] = */ -6,
	/* [  -5] = */ -5,
	/* [  -4] = */ -4,
	/* [  -3] = */ -3,
	/* [  -2] = */ -2,
	/* [  -1] = */ -1,
	/* [   0] = */ 0,
	/* [   1] = */ 1,
	/* [   2] = */ 2,
	/* [   3] = */ 3,
	/* [   4] = */ 4,
	/* [   5] = */ 5,
	/* [   6] = */ 6,
	/* [   7] = */ 7,
	/* [   8] = */ 8,
	/* [   9] = */ 9,
	/* [  10] = */ 10,
	/* [  11] = */ 11,
	/* [  12] = */ 12,
	/* [  13] = */ 13,
	/* [  14] = */ 14,
	/* [  15] = */ 15,
	/* [  16] = */ 16,
	/* [  17] = */ 17,
	/* [  18] = */ 18,
	/* [  19] = */ 19,
	/* [  20] = */ 20,
	/* [  21] = */ 21,
	/* [  22] = */ 22,
	/* [  23] = */ 23,
	/* [  24] = */ 24,
	/* [  25] = */ 25,
	/* [  26] = */ 26,
	/* [  27] = */ 27,
	/* [  28] = */ 28,
	/* [  29] = */ 29,
	/* [  30] = */ 30,
	/* [  31] = */ 31,
	/* [  32] = */ 32,
	/* [  33] = */ 33,
	/* [  34] = */ 34,
	/* [  35] = */ 35,
	/* [  36] = */ 36,
	/* [  37] = */ 37,
	/* [  38] = */ 38,
	/* [  39] = */ 39,
	/* [  40] = */ 40,
	/* [  41] = */ 41,
	/* [  42] = */ 42,
	/* [  43] = */ 43,
	/* [  44] = */ 44,
	/* [  45] = */ 45,
	/* [  46] = */ 46,
	/* [  47] = */ 47,
	/* [  48] = */ 48,
	/* [  49] = */ 49,
	/* [  50] = */ 50,
	/* [  51] = */ 51,
	/* [  52] = */ 52,
	/* [  53] = */ 53,
	/* [  54] = */ 54,
	/* [  55] = */ 55,
	/* [  56] = */ 56,
	/* [  57] = */ 57,
	/* [  58] = */ 58,
	/* [  59] = */ 59,
	/* [  60] = */ 60,
	/* [  61] = */ 61,
	/* [  62] = */ 62,
	/* [  63] = */ 63,
	/* [  64] = */ 64,
	/* [  65] = */ 97,
	/* [  66] = */ 98,
	/* [  67] = */ 99,
	/* [  68] = */ 100,
	/* [  69] = */ 101,
	/* [  70] = */ 102,
	/* [  71] = */ 103,
	/* [  72] = */ 104,
	/* [  73] = */ 105,
	/* [  74] = */ 106,
	/* [  75] = */ 107,
	/* [  76] = */ 108,
	/* [  77] = */ 109,
	/* [  78] = */ 110,
	/* [  79] = */ 111,
	/* [  80] = */ 112,
	/* [  81] = */ 113,
	/* [  82] = */ 114,
	/* [  83] = */ 115,
	/* [  84] = */ 116,
	/* [  85] = */ 117,
	/* [  86] = */ 118,
	/* [  87] = */ 119,
	/* [  88] = */ 120,
	/* [  89] = */ 121,
	/* [  90] = */ 122,
	/* [  91] = */ 91,
	/* [  92] = */ 92,
	/* [  93] = */ 93,
	/* [  94] = */ 94,
	/* [  95] = */ 95,
	/* [  96] = */ 96,
	/* [  97] = */ 97,
	/* [  98] = */ 98,
	/* [  99] = */ 99,
	/* [ 100] = */ 100,
	/* [ 101] = */ 101,
	/* [ 102] = */ 102,
	/* [ 103] = */ 103,
	/* [ 104] = */ 104,
	/* [ 105] = */ 105,
	/* [ 106] = */ 106,
	/* [ 107] = */ 107,
	/* [ 108] = */ 108,
	/* [ 109] = */ 109,
	/* [ 110] = */ 110,
	/* [ 111] = */ 111,
	/* [ 112] = */ 112,
	/* [ 113] = */ 113,
	/* [ 114] = */ 114,
	/* [ 115] = */ 115,
	/* [ 116] = */ 116,
	/* [ 117] = */ 117,
	/* [ 118] = */ 118,
	/* [ 119] = */ 119,
	/* [ 120] = */ 120,
	/* [ 121] = */ 121,
	/* [ 122] = */ 122,
	/* [ 123] = */ 123,
	/* [ 124] = */ 124,
	/* [ 125] = */ 125,
	/* [ 126] = */ 126,
	/* [ 127] = */ 127,
	/* [ 128] = */ 128,
	/* [ 129] = */ 129,
	/* [ 130] = */ 130,
	/* [ 131] = */ 131,
	/* [ 132] = */ 132,
	/* [ 133] = */ 133,
	/* [ 134] = */ 134,
	/* [ 135] = */ 135,
	/* [ 136] = */ 136,
	/* [ 137] = */ 137,
	/* [ 138] = */ 138,
	/* [ 139] = */ 139,
	/* [ 140] = */ 140,
	/* [ 141] = */ 141,
	/* [ 142] = */ 142,
	/* [ 143] = */ 143,
	/* [ 144] = */ 144,
	/* [ 145] = */ 145,
	/* [ 146] = */ 146,
	/* [ 147] = */ 147,
	/* [ 148] = */ 148,
	/* [ 149] = */ 149,
	/* [ 150] = */ 150,
	/* [ 151] = */ 151,
	/* [ 152] = */ 152,
	/* [ 153] = */ 153,
	/* [ 154] = */ 154,
	/* [ 155] = */ 155,
	/* [ 156] = */ 156,
	/* [ 157] = */ 157,
	/* [ 158] = */ 158,
	/* [ 159] = */ 159,
	/* [ 160] = */ 160,
	/* [ 161] = */ 161,
	/* [ 162] = */ 162,
	/* [ 163] = */ 163,
	/* [ 164] = */ 164,
	/* [ 165] = */ 165,
	/* [ 166] = */ 166,
	/* [ 167] = */ 167,
	/* [ 168] = */ 168,
	/* [ 169] = */ 169,
	/* [ 170] = */ 170,
	/* [ 171] = */ 171,
	/* [ 172] = */ 172,
	/* [ 173] = */ 173,
	/* [ 174] = */ 174,
	/* [ 175] = */ 175,
	/* [ 176] = */ 176,
	/* [ 177] = */ 177,
	/* [ 178] = */ 178,
	/* [ 179] = */ 179,
	/* [ 180] = */ 180,
	/* [ 181] = */ 181,
	/* [ 182] = */ 182,
	/* [ 183] = */ 183,
	/* [ 184] = */ 184,
	/* [ 185] = */ 185,
	/* [ 186] = */ 186,
	/* [ 187] = */ 187,
	/* [ 188] = */ 188,
	/* [ 189] = */ 189,
	/* [ 190] = */ 190,
	/* [ 191] = */ 191,
	/* [ 192] = */ 192,
	/* [ 193] = */ 193,
	/* [ 194] = */ 194,
	/* [ 195] = */ 195,
	/* [ 196] = */ 196,
	/* [ 197] = */ 197,
	/* [ 198] = */ 198,
	/* [ 199] = */ 199,
	/* [ 200] = */ 200,
	/* [ 201] = */ 201,
	/* [ 202] = */ 202,
	/* [ 203] = */ 203,
	/* [ 204] = */ 204,
	/* [ 205] = */ 205,
	/* [ 206] = */ 206,
	/* [ 207] = */ 207,
	/* [ 208] = */ 208,
	/* [ 209] = */ 209,
	/* [ 210] = */ 210,
	/* [ 211] = */ 211,
	/* [ 212] = */ 212,
	/* [ 213] = */ 213,
	/* [ 214] = */ 214,
	/* [ 215] = */ 215,
	/* [ 216] = */ 216,
	/* [ 217] = */ 217,
	/* [ 218] = */ 218,
	/* [ 219] = */ 219,
	/* [ 220] = */ 220,
	/* [ 221] = */ 221,
	/* [ 222] = */ 222,
	/* [ 223] = */ 223,
	/* [ 224] = */ 224,
	/* [ 225] = */ 225,
	/* [ 226] = */ 226,
	/* [ 227] = */ 227,
	/* [ 228] = */ 228,
	/* [ 229] = */ 229,
	/* [ 230] = */ 230,
	/* [ 231] = */ 231,
	/* [ 232] = */ 232,
	/* [ 233] = */ 233,
	/* [ 234] = */ 234,
	/* [ 235] = */ 235,
	/* [ 236] = */ 236,
	/* [ 237] = */ 237,
	/* [ 238] = */ 238,
	/* [ 239] = */ 239,
	/* [ 240] = */ 240,
	/* [ 241] = */ 241,
	/* [ 242] = */ 242,
	/* [ 243] = */ 243,
	/* [ 244] = */ 244,
	/* [ 245] = */ 245,
	/* [ 246] = */ 246,
	/* [ 247] = */ 247,
	/* [ 248] = */ 248,
	/* [ 249] = */ 249,
	/* [ 250] = */ 250,
	/* [ 251] = */ 251,
	/* [ 252] = */ 252,
	/* [ 253] = */ 253,
	/* [ 254] = */ 254,
	/* [ 255] = */ 255,
//[[[end]]]
};

PRIVATE ATTR_SECTION(".rodata.crt.unicode.static.ctype")
int32_t const libc___ctype_toupper_loc_matrix[384] = {
/*[[[deemon
import * from deemon;

for (local x: [-128: 255+1]) {
	local result = ASCII_TOUPPER(x);
	print "\t/" "* [{}] = *" "/ {},".format({ str(x).rjust(4), result });
}
]]]*/
	/* [-128] = */ -128,
	/* [-127] = */ -127,
	/* [-126] = */ -126,
	/* [-125] = */ -125,
	/* [-124] = */ -124,
	/* [-123] = */ -123,
	/* [-122] = */ -122,
	/* [-121] = */ -121,
	/* [-120] = */ -120,
	/* [-119] = */ -119,
	/* [-118] = */ -118,
	/* [-117] = */ -117,
	/* [-116] = */ -116,
	/* [-115] = */ -115,
	/* [-114] = */ -114,
	/* [-113] = */ -113,
	/* [-112] = */ -112,
	/* [-111] = */ -111,
	/* [-110] = */ -110,
	/* [-109] = */ -109,
	/* [-108] = */ -108,
	/* [-107] = */ -107,
	/* [-106] = */ -106,
	/* [-105] = */ -105,
	/* [-104] = */ -104,
	/* [-103] = */ -103,
	/* [-102] = */ -102,
	/* [-101] = */ -101,
	/* [-100] = */ -100,
	/* [ -99] = */ -99,
	/* [ -98] = */ -98,
	/* [ -97] = */ -97,
	/* [ -96] = */ -96,
	/* [ -95] = */ -95,
	/* [ -94] = */ -94,
	/* [ -93] = */ -93,
	/* [ -92] = */ -92,
	/* [ -91] = */ -91,
	/* [ -90] = */ -90,
	/* [ -89] = */ -89,
	/* [ -88] = */ -88,
	/* [ -87] = */ -87,
	/* [ -86] = */ -86,
	/* [ -85] = */ -85,
	/* [ -84] = */ -84,
	/* [ -83] = */ -83,
	/* [ -82] = */ -82,
	/* [ -81] = */ -81,
	/* [ -80] = */ -80,
	/* [ -79] = */ -79,
	/* [ -78] = */ -78,
	/* [ -77] = */ -77,
	/* [ -76] = */ -76,
	/* [ -75] = */ -75,
	/* [ -74] = */ -74,
	/* [ -73] = */ -73,
	/* [ -72] = */ -72,
	/* [ -71] = */ -71,
	/* [ -70] = */ -70,
	/* [ -69] = */ -69,
	/* [ -68] = */ -68,
	/* [ -67] = */ -67,
	/* [ -66] = */ -66,
	/* [ -65] = */ -65,
	/* [ -64] = */ -64,
	/* [ -63] = */ -63,
	/* [ -62] = */ -62,
	/* [ -61] = */ -61,
	/* [ -60] = */ -60,
	/* [ -59] = */ -59,
	/* [ -58] = */ -58,
	/* [ -57] = */ -57,
	/* [ -56] = */ -56,
	/* [ -55] = */ -55,
	/* [ -54] = */ -54,
	/* [ -53] = */ -53,
	/* [ -52] = */ -52,
	/* [ -51] = */ -51,
	/* [ -50] = */ -50,
	/* [ -49] = */ -49,
	/* [ -48] = */ -48,
	/* [ -47] = */ -47,
	/* [ -46] = */ -46,
	/* [ -45] = */ -45,
	/* [ -44] = */ -44,
	/* [ -43] = */ -43,
	/* [ -42] = */ -42,
	/* [ -41] = */ -41,
	/* [ -40] = */ -40,
	/* [ -39] = */ -39,
	/* [ -38] = */ -38,
	/* [ -37] = */ -37,
	/* [ -36] = */ -36,
	/* [ -35] = */ -35,
	/* [ -34] = */ -34,
	/* [ -33] = */ -33,
	/* [ -32] = */ -32,
	/* [ -31] = */ -31,
	/* [ -30] = */ -30,
	/* [ -29] = */ -29,
	/* [ -28] = */ -28,
	/* [ -27] = */ -27,
	/* [ -26] = */ -26,
	/* [ -25] = */ -25,
	/* [ -24] = */ -24,
	/* [ -23] = */ -23,
	/* [ -22] = */ -22,
	/* [ -21] = */ -21,
	/* [ -20] = */ -20,
	/* [ -19] = */ -19,
	/* [ -18] = */ -18,
	/* [ -17] = */ -17,
	/* [ -16] = */ -16,
	/* [ -15] = */ -15,
	/* [ -14] = */ -14,
	/* [ -13] = */ -13,
	/* [ -12] = */ -12,
	/* [ -11] = */ -11,
	/* [ -10] = */ -10,
	/* [  -9] = */ -9,
	/* [  -8] = */ -8,
	/* [  -7] = */ -7,
	/* [  -6] = */ -6,
	/* [  -5] = */ -5,
	/* [  -4] = */ -4,
	/* [  -3] = */ -3,
	/* [  -2] = */ -2,
	/* [  -1] = */ -1,
	/* [   0] = */ 0,
	/* [   1] = */ 1,
	/* [   2] = */ 2,
	/* [   3] = */ 3,
	/* [   4] = */ 4,
	/* [   5] = */ 5,
	/* [   6] = */ 6,
	/* [   7] = */ 7,
	/* [   8] = */ 8,
	/* [   9] = */ 9,
	/* [  10] = */ 10,
	/* [  11] = */ 11,
	/* [  12] = */ 12,
	/* [  13] = */ 13,
	/* [  14] = */ 14,
	/* [  15] = */ 15,
	/* [  16] = */ 16,
	/* [  17] = */ 17,
	/* [  18] = */ 18,
	/* [  19] = */ 19,
	/* [  20] = */ 20,
	/* [  21] = */ 21,
	/* [  22] = */ 22,
	/* [  23] = */ 23,
	/* [  24] = */ 24,
	/* [  25] = */ 25,
	/* [  26] = */ 26,
	/* [  27] = */ 27,
	/* [  28] = */ 28,
	/* [  29] = */ 29,
	/* [  30] = */ 30,
	/* [  31] = */ 31,
	/* [  32] = */ 32,
	/* [  33] = */ 33,
	/* [  34] = */ 34,
	/* [  35] = */ 35,
	/* [  36] = */ 36,
	/* [  37] = */ 37,
	/* [  38] = */ 38,
	/* [  39] = */ 39,
	/* [  40] = */ 40,
	/* [  41] = */ 41,
	/* [  42] = */ 42,
	/* [  43] = */ 43,
	/* [  44] = */ 44,
	/* [  45] = */ 45,
	/* [  46] = */ 46,
	/* [  47] = */ 47,
	/* [  48] = */ 48,
	/* [  49] = */ 49,
	/* [  50] = */ 50,
	/* [  51] = */ 51,
	/* [  52] = */ 52,
	/* [  53] = */ 53,
	/* [  54] = */ 54,
	/* [  55] = */ 55,
	/* [  56] = */ 56,
	/* [  57] = */ 57,
	/* [  58] = */ 58,
	/* [  59] = */ 59,
	/* [  60] = */ 60,
	/* [  61] = */ 61,
	/* [  62] = */ 62,
	/* [  63] = */ 63,
	/* [  64] = */ 64,
	/* [  65] = */ 65,
	/* [  66] = */ 66,
	/* [  67] = */ 67,
	/* [  68] = */ 68,
	/* [  69] = */ 69,
	/* [  70] = */ 70,
	/* [  71] = */ 71,
	/* [  72] = */ 72,
	/* [  73] = */ 73,
	/* [  74] = */ 74,
	/* [  75] = */ 75,
	/* [  76] = */ 76,
	/* [  77] = */ 77,
	/* [  78] = */ 78,
	/* [  79] = */ 79,
	/* [  80] = */ 80,
	/* [  81] = */ 81,
	/* [  82] = */ 82,
	/* [  83] = */ 83,
	/* [  84] = */ 84,
	/* [  85] = */ 85,
	/* [  86] = */ 86,
	/* [  87] = */ 87,
	/* [  88] = */ 88,
	/* [  89] = */ 89,
	/* [  90] = */ 90,
	/* [  91] = */ 91,
	/* [  92] = */ 92,
	/* [  93] = */ 93,
	/* [  94] = */ 94,
	/* [  95] = */ 95,
	/* [  96] = */ 96,
	/* [  97] = */ 65,
	/* [  98] = */ 66,
	/* [  99] = */ 67,
	/* [ 100] = */ 68,
	/* [ 101] = */ 69,
	/* [ 102] = */ 70,
	/* [ 103] = */ 71,
	/* [ 104] = */ 72,
	/* [ 105] = */ 73,
	/* [ 106] = */ 74,
	/* [ 107] = */ 75,
	/* [ 108] = */ 76,
	/* [ 109] = */ 77,
	/* [ 110] = */ 78,
	/* [ 111] = */ 79,
	/* [ 112] = */ 80,
	/* [ 113] = */ 81,
	/* [ 114] = */ 82,
	/* [ 115] = */ 83,
	/* [ 116] = */ 84,
	/* [ 117] = */ 85,
	/* [ 118] = */ 86,
	/* [ 119] = */ 87,
	/* [ 120] = */ 88,
	/* [ 121] = */ 89,
	/* [ 122] = */ 90,
	/* [ 123] = */ 123,
	/* [ 124] = */ 124,
	/* [ 125] = */ 125,
	/* [ 126] = */ 126,
	/* [ 127] = */ 127,
	/* [ 128] = */ 128,
	/* [ 129] = */ 129,
	/* [ 130] = */ 130,
	/* [ 131] = */ 131,
	/* [ 132] = */ 132,
	/* [ 133] = */ 133,
	/* [ 134] = */ 134,
	/* [ 135] = */ 135,
	/* [ 136] = */ 136,
	/* [ 137] = */ 137,
	/* [ 138] = */ 138,
	/* [ 139] = */ 139,
	/* [ 140] = */ 140,
	/* [ 141] = */ 141,
	/* [ 142] = */ 142,
	/* [ 143] = */ 143,
	/* [ 144] = */ 144,
	/* [ 145] = */ 145,
	/* [ 146] = */ 146,
	/* [ 147] = */ 147,
	/* [ 148] = */ 148,
	/* [ 149] = */ 149,
	/* [ 150] = */ 150,
	/* [ 151] = */ 151,
	/* [ 152] = */ 152,
	/* [ 153] = */ 153,
	/* [ 154] = */ 154,
	/* [ 155] = */ 155,
	/* [ 156] = */ 156,
	/* [ 157] = */ 157,
	/* [ 158] = */ 158,
	/* [ 159] = */ 159,
	/* [ 160] = */ 160,
	/* [ 161] = */ 161,
	/* [ 162] = */ 162,
	/* [ 163] = */ 163,
	/* [ 164] = */ 164,
	/* [ 165] = */ 165,
	/* [ 166] = */ 166,
	/* [ 167] = */ 167,
	/* [ 168] = */ 168,
	/* [ 169] = */ 169,
	/* [ 170] = */ 170,
	/* [ 171] = */ 171,
	/* [ 172] = */ 172,
	/* [ 173] = */ 173,
	/* [ 174] = */ 174,
	/* [ 175] = */ 175,
	/* [ 176] = */ 176,
	/* [ 177] = */ 177,
	/* [ 178] = */ 178,
	/* [ 179] = */ 179,
	/* [ 180] = */ 180,
	/* [ 181] = */ 181,
	/* [ 182] = */ 182,
	/* [ 183] = */ 183,
	/* [ 184] = */ 184,
	/* [ 185] = */ 185,
	/* [ 186] = */ 186,
	/* [ 187] = */ 187,
	/* [ 188] = */ 188,
	/* [ 189] = */ 189,
	/* [ 190] = */ 190,
	/* [ 191] = */ 191,
	/* [ 192] = */ 192,
	/* [ 193] = */ 193,
	/* [ 194] = */ 194,
	/* [ 195] = */ 195,
	/* [ 196] = */ 196,
	/* [ 197] = */ 197,
	/* [ 198] = */ 198,
	/* [ 199] = */ 199,
	/* [ 200] = */ 200,
	/* [ 201] = */ 201,
	/* [ 202] = */ 202,
	/* [ 203] = */ 203,
	/* [ 204] = */ 204,
	/* [ 205] = */ 205,
	/* [ 206] = */ 206,
	/* [ 207] = */ 207,
	/* [ 208] = */ 208,
	/* [ 209] = */ 209,
	/* [ 210] = */ 210,
	/* [ 211] = */ 211,
	/* [ 212] = */ 212,
	/* [ 213] = */ 213,
	/* [ 214] = */ 214,
	/* [ 215] = */ 215,
	/* [ 216] = */ 216,
	/* [ 217] = */ 217,
	/* [ 218] = */ 218,
	/* [ 219] = */ 219,
	/* [ 220] = */ 220,
	/* [ 221] = */ 221,
	/* [ 222] = */ 222,
	/* [ 223] = */ 223,
	/* [ 224] = */ 224,
	/* [ 225] = */ 225,
	/* [ 226] = */ 226,
	/* [ 227] = */ 227,
	/* [ 228] = */ 228,
	/* [ 229] = */ 229,
	/* [ 230] = */ 230,
	/* [ 231] = */ 231,
	/* [ 232] = */ 232,
	/* [ 233] = */ 233,
	/* [ 234] = */ 234,
	/* [ 235] = */ 235,
	/* [ 236] = */ 236,
	/* [ 237] = */ 237,
	/* [ 238] = */ 238,
	/* [ 239] = */ 239,
	/* [ 240] = */ 240,
	/* [ 241] = */ 241,
	/* [ 242] = */ 242,
	/* [ 243] = */ 243,
	/* [ 244] = */ 244,
	/* [ 245] = */ 245,
	/* [ 246] = */ 246,
	/* [ 247] = */ 247,
	/* [ 248] = */ 248,
	/* [ 249] = */ 249,
	/* [ 250] = */ 250,
	/* [ 251] = */ 251,
	/* [ 252] = */ 252,
	/* [ 253] = */ 253,
	/* [ 254] = */ 254,
	/* [ 255] = */ 255,
//[[[end]]]
};


PRIVATE ATTR_SECTION(".bss.crt.unicode.static.ctype") uint16_t const *libc___ctype_b_loc_pointer = NULL;
PRIVATE ATTR_SECTION(".bss.crt.unicode.static.ctype") int32_t const *libc___ctype_tolower_loc_pointer = NULL;
PRIVATE ATTR_SECTION(".bss.crt.unicode.static.ctype") int32_t const *libc___ctype_toupper_loc_pointer = NULL;

DEFINE_PUBLIC_IDATA_G(__ctype_b, libc___ctype_b_loc, __SIZEOF_POINTER__);             /* >> extern uint16_t const *__ctype_b; */
DEFINE_PUBLIC_IDATA_G(__ctype_tolower, libc___ctype_tolower_loc, __SIZEOF_POINTER__); /* >> extern int32_t const *__ctype_tolower; */
DEFINE_PUBLIC_IDATA_G(__ctype_toupper, libc___ctype_toupper_loc, __SIZEOF_POINTER__); /* >> extern int32_t const *__ctype_toupper; */

/*[[[head:libc___ctype_b_loc,hash:CRC-32=0xde267e1c]]]*/
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_PURE WUNUSED uint16_t const **
NOTHROW(LIBCCALL libc___ctype_b_loc)(void)
/*[[[body:libc___ctype_b_loc]]]*/
{
	if (!libc___ctype_b_loc_pointer)
		libc___ctype_b_loc_pointer = libc___ctype_b_loc_matrix + 128;
	return &libc___ctype_b_loc_pointer;
}
/*[[[end:libc___ctype_b_loc]]]*/

/*[[[head:libc___ctype_tolower_loc,hash:CRC-32=0x285bc49d]]]*/
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_PURE WUNUSED int32_t const **
NOTHROW(LIBCCALL libc___ctype_tolower_loc)(void)
/*[[[body:libc___ctype_tolower_loc]]]*/
{
	if (!libc___ctype_tolower_loc_pointer)
		libc___ctype_tolower_loc_pointer = libc___ctype_tolower_loc_matrix + 128;
	return &libc___ctype_tolower_loc_pointer;
}
/*[[[end:libc___ctype_tolower_loc]]]*/

/*[[[head:libc___ctype_toupper_loc,hash:CRC-32=0xad708f83]]]*/
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_PURE WUNUSED int32_t const **
NOTHROW(LIBCCALL libc___ctype_toupper_loc)(void)
/*[[[body:libc___ctype_toupper_loc]]]*/
{
	if (!libc___ctype_toupper_loc_pointer)
		libc___ctype_toupper_loc_pointer = libc___ctype_toupper_loc_matrix + 128;
	return &libc___ctype_toupper_loc_pointer;
}
/*[[[end:libc___ctype_toupper_loc]]]*/


/*[[[head:libc___locale_ctype_ptr,hash:CRC-32=0xed204c59]]]*/
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED char const *
NOTHROW(LIBCCALL libc___locale_ctype_ptr)(void)
/*[[[body:libc___locale_ctype_ptr]]]*/
/*AUTO*/{
	CRT_UNIMPLEMENTED("__locale_ctype_ptr"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:libc___locale_ctype_ptr]]]*/

/*[[[head:libc___locale_ctype_ptr_l,hash:CRC-32=0x90d435e7]]]*/
INTERN ATTR_SECTION(".text.crt.unicode.locale.ctype") ATTR_PURE WUNUSED char const *
NOTHROW_NCX(LIBCCALL libc___locale_ctype_ptr_l)(locale_t locale)
/*[[[body:libc___locale_ctype_ptr_l]]]*/
/*AUTO*/{
	(void)locale;
	CRT_UNIMPLEMENTEDF("__locale_ctype_ptr_l(%p)", locale); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:libc___locale_ctype_ptr_l]]]*/







/*[[[start:exports,hash:CRC-32=0xe57a21f9]]]*/
DEFINE_PUBLIC_ALIAS(__locale_ctype_ptr, libc___locale_ctype_ptr);
DEFINE_PUBLIC_ALIAS(__locale_ctype_ptr_l, libc___locale_ctype_ptr_l);
DEFINE_PUBLIC_ALIAS(__ctype_b_loc, libc___ctype_b_loc);
DEFINE_PUBLIC_ALIAS(__ctype_tolower_loc, libc___ctype_tolower_loc);
DEFINE_PUBLIC_ALIAS(__ctype_toupper_loc, libc___ctype_toupper_loc);
/*[[[end:exports]]]*/

DECL_END

#endif /* !GUARD_LIBC_USER_CTYPE_C */
