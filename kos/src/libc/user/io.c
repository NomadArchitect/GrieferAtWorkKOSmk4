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
#ifndef GUARD_LIBC_USER_IO_C
#define GUARD_LIBC_USER_IO_C 1

#include "../api.h"
/**/

#include <hybrid/minmax.h>

#include <kos/syscalls.h>
#include <sys/stat.h>

#include <alloca.h>
#include <dirent.h>
#include <fcntl.h>
#include <io.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "../libc/errno.h"
#include "../libc/compat.h"
#include "io.h"

DECL_BEGIN

struct dfind {
	DIR  *df_dir;   /* [1..1][owned] The underlying directory stream. */
	char *df_query; /* [1..1][owned] The wildcard-enabled query pattern. */
};

#define DFIND_INVALID ((struct dfind *)-1)

DEFINE_PUBLIC_ALIAS(__find_open, dfind_open);
INTERN WUNUSED ATTR_SECTION(".text.crt.dos.fs.dir") struct dfind *LIBCCALL
dfind_open(char const *__restrict filename, oflag_t oflags) {
	char const *pathend;
	struct dfind *result;
	result = (struct dfind *)malloc(sizeof(struct dfind));
	if unlikely(!result)
		goto err;
	pathend = strend(filename);
	while (pathend > filename &&
	       (pathend[-1] != '/' &&
	        (pathend[-1] != '\\' && (oflags & O_DOSPATH))))
		--pathend;
	if unlikely(pathend <= filename) {
		PRIVATE ATTR_SECTION(".rodata.crt.dos.fs.dir") char const pwd[] = ".";
		result->df_dir = fopendirat(AT_FDCWD, pwd, oflags);
	} else {
		char *path;
		size_t pathlen;
		pathlen = (size_t)(pathend - filename);
		path    = (char *)alloca((pathlen + 1) * sizeof(char));
		memcpy(path, filename, pathlen, sizeof(char));
		path[pathlen] = '\0';
		result->df_dir = fopendirat(AT_FDCWD, path, oflags);
	}
	if unlikely(!result->df_dir)
		goto err_r;
	result->df_query = strdup(pathend);
	if unlikely(!result->df_query)
		goto err_r_dir;
done:
	return result;
err_r_dir:
	closedir(result->df_dir);
err_r:
	free(result);
err:
	result = DFIND_INVALID;
	goto done;
}

PRIVATE ATTR_SECTION(".text.crt.dos.fs.dir") void LIBCCALL
dfind_close(struct dfind *__restrict self) {
	closedir(self->df_dir);
	free(self->df_query);
	free(self);
}

DEFINE_PUBLIC_ALIAS(__find_readdir, dfind_readdir);
INTERN WUNUSED ATTR_SECTION(".text.crt.dos.fs.dir") struct dirent *LIBCCALL
dfind_readdir(struct dfind *__restrict self) {
	struct dirent *result;
	while ((result = readdir(self->df_dir)) != NULL) {
		if (wildstrcasecmp(self->df_query, result->d_name) == 0)
			break;
	}
	return result;
}

#define dfind_attrib(ent, st)                            \
	(((ent)->d_type == DT_DIR ? _A_SUBDIR : _A_NORMAL) | \
	 (((st)->st_mode & 0222) ? 0 : _A_RDONLY) |          \
	 ((ent)->d_name[0] == '.' ? _A_HIDDEN : 0))

PRIVATE WUNUSED ATTR_SECTION(".text.crt.dos.fs.dir") int LIBCCALL
dfind_read32(struct dfind *__restrict self,
             struct _finddata32_t *__restrict finddata) {
	struct stat st;
	struct dirent *ent;
	ent = dfind_readdir(self);
	if (!ent)
		goto err;
	if (fstatat(dirfd(self->df_dir), ent->d_name, &st, AT_SYMLINK_NOFOLLOW))
		goto err;
	finddata->attrib      = dfind_attrib(ent, &st);
	finddata->time_create = (s32)st.st_ctime32;
	finddata->time_access = (s32)st.st_atime32;
	finddata->time_write  = (s32)st.st_mtime32;
	finddata->size        = (_fsize_t)st.st_size;
	memcpy(finddata->name, ent->d_name,
	       MIN(ent->d_namlen, COMPILER_LENOF(finddata->name)),
	       sizeof(char));
	finddata->name[COMPILER_LENOF(finddata->name) - 1] = 0;
	return 0;
err:
	return -1;
}

PRIVATE WUNUSED ATTR_SECTION(".text.crt.dos.fs.dir") int LIBCCALL
dfind_read32i64(struct dfind *__restrict self,
                struct _finddata32i64_t *__restrict finddata) {
	struct stat st;
	struct dirent *ent;
	ent = dfind_readdir(self);
	if (!ent)
		goto err;
	if (fstatat(dirfd(self->df_dir), ent->d_name, &st,
	            AT_DOSPATH | AT_SYMLINK_NOFOLLOW))
		goto err;
	finddata->attrib      = dfind_attrib(ent, &st);
	finddata->time_create = (s32)st.st_ctime32;
	finddata->time_access = (s32)st.st_atime32;
	finddata->time_write  = (s32)st.st_mtime32;
	finddata->size        = (s64)st.st_size64;
	memcpy(finddata->name, ent->d_name,
	       MIN(ent->d_namlen, COMPILER_LENOF(finddata->name)),
	       sizeof(char));
	finddata->name[COMPILER_LENOF(finddata->name) - 1] = 0;
	return 0;
err:
	return -1;
}

PRIVATE WUNUSED ATTR_SECTION(".text.crt.dos.fs.dir") int LIBCCALL
dfind_read64(struct dfind *__restrict self,
             struct __finddata64_t *__restrict finddata) {
	struct stat st;
	struct dirent *ent;
	ent = dfind_readdir(self);
	if (!ent)
		goto err;
	if (fstatat(dirfd(self->df_dir), ent->d_name, &st,
	            AT_DOSPATH | AT_SYMLINK_NOFOLLOW))
		goto err;
	finddata->attrib      = dfind_attrib(ent, &st);
	finddata->time_create = (s64)st.st_ctime64;
	finddata->time_access = (s64)st.st_atime64;
	finddata->time_write  = (s64)st.st_mtime64;
	finddata->size        = (s64)st.st_size64;
	memcpy(finddata->name, ent->d_name,
	       MIN(ent->d_namlen, COMPILER_LENOF(finddata->name)),
	       sizeof(char));
	finddata->name[COMPILER_LENOF(finddata->name) - 1] = 0;
	return 0;
err:
	return -1;
}







/*[[[head:libd__access_s,hash:CRC-32=0x79d8bca9]]]*/
INTERN ATTR_SECTION(".text.crt.dos.fs.property") NONNULL((1)) errno_t
NOTHROW_RPC(LIBDCALL libd__access_s)(char const *filename,
                                     int type)
/*[[[body:libd__access_s]]]*/
{
	return libd_errno_kos2dos(libc__access_s(filename, type));
}
/*[[[end:libd__access_s]]]*/

/*[[[head:libc__access_s,hash:CRC-32=0x467308b4]]]*/
INTERN ATTR_SECTION(".text.crt.dos.fs.property") NONNULL((1)) errno_t
NOTHROW_RPC(LIBCCALL libc__access_s)(char const *filename,
                                     int type)
/*[[[body:libc__access_s]]]*/
{
	return -sys_access(filename, (syscall_ulong_t)(unsigned int)type);
}
/*[[[end:libc__access_s]]]*/

/*[[[head:libc__findclose,hash:CRC-32=0xd06b2791]]]*/
INTERN ATTR_SECTION(".text.crt.dos.fs.dir") int
NOTHROW_NCX(LIBCCALL libc__findclose)(intptr_t findfd)
/*[[[body:libc__findclose]]]*/
{
	struct dfind *f;
	f = (struct dfind *)(uintptr_t)findfd;
	if unlikely(f == DFIND_INVALID)
		return libd_seterrno(DOS_EINVAL);
	dfind_close(f);
	return 0;
}
/*[[[end:libc__findclose]]]*/

PRIVATE ATTR_SECTION(".text.crt.dos.fs.dir") WUNUSED NONNULL((1, 2)) intptr_t
NOTHROW_RPC(LIBCCALL libc__findfirst32_impl)(char const *__restrict filename,
                                             struct _finddata32_t *__restrict finddata,
                                             oflag_t oflags) {
	struct dfind *result;
	result = dfind_open(filename, oflags);
	if likely(result != DFIND_INVALID) {
		if (dfind_read32(result, finddata) != 0) {
			dfind_close(result);
			result = DFIND_INVALID;
		}
	}
	return (intptr_t)(uintptr_t)result;
}

/*[[[head:libd__findfirst32,hash:CRC-32=0xc6fe465b]]]*/
INTERN ATTR_SECTION(".text.crt.dos.fs.dir") WUNUSED NONNULL((1, 2)) intptr_t
NOTHROW_RPC(LIBDCALL libd__findfirst32)(char const *__restrict filename,
                                        struct _finddata32_t *__restrict finddata)
/*[[[body:libd__findfirst32]]]*/
{
	return libc__findfirst32_impl(filename, finddata, O_DOSPATH);
}
/*[[[end:libd__findfirst32]]]*/

/*[[[head:libc__findfirst32,hash:CRC-32=0xfe0b33e5]]]*/
INTERN ATTR_SECTION(".text.crt.dos.fs.dir") WUNUSED NONNULL((1, 2)) intptr_t
NOTHROW_RPC(LIBCCALL libc__findfirst32)(char const *__restrict filename,
                                        struct _finddata32_t *__restrict finddata)
/*[[[body:libc__findfirst32]]]*/
{
	return libc__findfirst32_impl(filename, finddata, 0);
}
/*[[[end:libc__findfirst32]]]*/


PRIVATE ATTR_SECTION(".text.crt.dos.fs.dir") WUNUSED NONNULL((1, 2)) intptr_t
NOTHROW_RPC(LIBCCALL libc__findfirst32i64_impl)(char const *__restrict filename,
                                                struct _finddata32i64_t *__restrict finddata,
                                                oflag_t oflags) {
	struct dfind *result;
	result = dfind_open(filename, oflags);
	if likely(result != DFIND_INVALID) {
		if (dfind_read32i64(result, finddata) != 0) {
			dfind_close(result);
			result = DFIND_INVALID;
		}
	}
	return (intptr_t)(uintptr_t)result;
}

/*[[[head:libd__findfirst32i64,hash:CRC-32=0x2d574651]]]*/
INTERN ATTR_SECTION(".text.crt.dos.fs.dir") WUNUSED NONNULL((1, 2)) intptr_t
NOTHROW_RPC(LIBDCALL libd__findfirst32i64)(char const *__restrict filename,
                                           struct _finddata32i64_t *__restrict finddata)
/*[[[body:libd__findfirst32i64]]]*/
{
	return libc__findfirst32i64_impl(filename, finddata, O_DOSPATH);
}
/*[[[end:libd__findfirst32i64]]]*/

/*[[[head:libc__findfirst32i64,hash:CRC-32=0x972e5214]]]*/
INTERN ATTR_SECTION(".text.crt.dos.fs.dir") WUNUSED NONNULL((1, 2)) intptr_t
NOTHROW_RPC(LIBCCALL libc__findfirst32i64)(char const *__restrict filename,
                                           struct _finddata32i64_t *__restrict finddata)
/*[[[body:libc__findfirst32i64]]]*/
{
	return libc__findfirst32i64_impl(filename, finddata, 0);
}
/*[[[end:libc__findfirst32i64]]]*/


PRIVATE ATTR_SECTION(".text.crt.dos.fs.dir") WUNUSED NONNULL((1, 2)) intptr_t
NOTHROW_RPC(LIBCCALL libc__findfirst64_impl)(char const *__restrict filename,
                                             struct __finddata64_t *__restrict finddata,
                                             oflag_t oflags) {
	struct dfind *result;
	result = dfind_open(filename, oflags);
	if likely(result != DFIND_INVALID) {
		if (dfind_read64(result, finddata) != 0) {
			dfind_close(result);
			result = DFIND_INVALID;
		}
	}
	return (intptr_t)(uintptr_t)result;
}

/*[[[head:libd__findfirst64,hash:CRC-32=0xb6da98d2]]]*/
INTERN ATTR_SECTION(".text.crt.dos.fs.dir") WUNUSED NONNULL((1, 2)) intptr_t
NOTHROW_RPC(LIBDCALL libd__findfirst64)(char const *__restrict filename,
                                        struct __finddata64_t *__restrict finddata)
/*[[[body:libd__findfirst64]]]*/
{
	return libc__findfirst64_impl(filename, finddata, O_DOSPATH);
}
/*[[[end:libd__findfirst64]]]*/

/*[[[head:libc__findfirst64,hash:CRC-32=0x9a3bf32c]]]*/
INTERN ATTR_SECTION(".text.crt.dos.fs.dir") WUNUSED NONNULL((1, 2)) intptr_t
NOTHROW_RPC(LIBCCALL libc__findfirst64)(char const *__restrict filename,
                                        struct __finddata64_t *__restrict finddata)
/*[[[body:libc__findfirst64]]]*/
{
	return libc__findfirst64_impl(filename, finddata, 0);
}
/*[[[end:libc__findfirst64]]]*/


/*[[[head:libc__findnext32,hash:CRC-32=0xc2f9d86d]]]*/
INTERN ATTR_SECTION(".text.crt.dos.fs.dir") NONNULL((2)) int
NOTHROW_RPC(LIBCCALL libc__findnext32)(intptr_t findfd,
                                       struct _finddata32_t *__restrict finddata)
/*[[[body:libc__findnext32]]]*/
{
	int result;
	struct dfind *f;
	f = (struct dfind *)(uintptr_t)findfd;
	if unlikely(f == DFIND_INVALID)
		return libd_seterrno(DOS_EINVAL);
	result = dfind_read32(f, finddata);
	return result;
}
/*[[[end:libc__findnext32]]]*/

/*[[[head:libc__findnext32i64,hash:CRC-32=0x59d01bfd]]]*/
INTERN ATTR_SECTION(".text.crt.dos.fs.dir") NONNULL((2)) int
NOTHROW_RPC(LIBCCALL libc__findnext32i64)(intptr_t findfd,
                                          struct _finddata32i64_t *__restrict finddata)
/*[[[body:libc__findnext32i64]]]*/
{
	int result;
	struct dfind *f;
	f = (struct dfind *)(uintptr_t)findfd;
	if unlikely(f == DFIND_INVALID)
		return libd_seterrno(DOS_EINVAL);
	result = dfind_read32i64(f, finddata);
	return result;
}
/*[[[end:libc__findnext32i64]]]*/

/*[[[head:libc__findnext64,hash:CRC-32=0x4ce65c58]]]*/
INTERN ATTR_SECTION(".text.crt.dos.fs.dir") NONNULL((2)) int
NOTHROW_RPC(LIBCCALL libc__findnext64)(intptr_t findfd,
                                       struct __finddata64_t *__restrict finddata)
/*[[[body:libc__findnext64]]]*/
{
	int result;
	struct dfind *f;
	f = (struct dfind *)(uintptr_t)findfd;
	if unlikely(f == DFIND_INVALID)
		return libd_seterrno(DOS_EINVAL);
	result = dfind_read64(f, finddata);
	return result;
}
/*[[[end:libc__findnext64]]]*/

/*[[[head:libd__sopen_s,hash:CRC-32=0xfabc2763]]]*/
INTERN ATTR_SECTION(".text.crt.dos.fs.io") NONNULL((1, 2)) errno_t
NOTHROW_RPC(LIBDCALL libd__sopen_s)(fd_t *fd,
                                    char const *filename,
                                    oflag_t oflags,
                                    int sflags,
                                    mode_t mode)
/*[[[body:libd__sopen_s]]]*/
{
	fd_t resfd;
	if unlikely(!fd)
		return EINVAL;
	(void)sflags; /* XXX: Share-mode? */
	resfd = sys_open(filename, oflags | O_DOSPATH, mode);
	if (E_ISERR(resfd))
		return -(errno_t)resfd;
	*fd = resfd;
	return EOK;
}
/*[[[end:libd__sopen_s]]]*/

/*[[[head:libc__sopen_s,hash:CRC-32=0x5885d95b]]]*/
INTERN ATTR_SECTION(".text.crt.dos.fs.io") NONNULL((1, 2)) errno_t
NOTHROW_RPC(LIBCCALL libc__sopen_s)(fd_t *fd,
                                    char const *filename,
                                    oflag_t oflags,
                                    int sflags,
                                    mode_t mode)
/*[[[body:libc__sopen_s]]]*/
{
	fd_t resfd;
	if unlikely(!fd)
		return EINVAL;
	(void)sflags; /* XXX: Share-mode? */
	resfd = sys_open(filename, oflags, mode);
	if (E_ISERR(resfd))
		return -(errno_t)resfd;
	*fd = resfd;
	return EOK;
}
/*[[[end:libc__sopen_s]]]*/

/*[[[head:libc__mktemp_s,hash:CRC-32=0x7a5599fd]]]*/
INTERN ATTR_SECTION(".text.crt.dos.fs.utility") NONNULL((1)) errno_t
NOTHROW_NCX(LIBCCALL libc__mktemp_s)(char *template_,
                                     size_t size)
/*[[[body:libc__mktemp_s]]]*/
/*AUTO*/{
	(void)template_;
	(void)size;
	CRT_UNIMPLEMENTEDF("_mktemp_s(%q, %Ix)", template_, size); /* TODO */
	return ENOSYS;
}
/*[[[end:libc__mktemp_s]]]*/






#undef _findfirst
#undef _findfirsti64
#undef _findnext
#undef _findnexti64

/*[[[start:exports,hash:CRC-32=0x63f78a07]]]*/
DEFINE_PUBLIC_ALIAS(DOS$_access_s, libd__access_s);
DEFINE_PUBLIC_ALIAS(_access_s, libc__access_s);
DEFINE_PUBLIC_ALIAS(_findclose, libc__findclose);
DEFINE_PUBLIC_ALIAS(DOS$_findfirst, libd__findfirst32);
DEFINE_PUBLIC_ALIAS(DOS$_findfirst32, libd__findfirst32);
DEFINE_PUBLIC_ALIAS(_findfirst, libc__findfirst32);
DEFINE_PUBLIC_ALIAS(_findfirst32, libc__findfirst32);
DEFINE_PUBLIC_ALIAS(DOS$_findfirsti64, libd__findfirst32i64);
DEFINE_PUBLIC_ALIAS(DOS$_findfirst32i64, libd__findfirst32i64);
DEFINE_PUBLIC_ALIAS(_findfirsti64, libc__findfirst32i64);
DEFINE_PUBLIC_ALIAS(_findfirst32i64, libc__findfirst32i64);
DEFINE_PUBLIC_ALIAS(DOS$_findfirst64i32, libd__findfirst64);
DEFINE_PUBLIC_ALIAS(DOS$_findfirst64, libd__findfirst64);
DEFINE_PUBLIC_ALIAS(_findfirst64i32, libc__findfirst64);
DEFINE_PUBLIC_ALIAS(_findfirst64, libc__findfirst64);
DEFINE_PUBLIC_ALIAS(_findnext, libc__findnext32);
DEFINE_PUBLIC_ALIAS(_findnext32, libc__findnext32);
DEFINE_PUBLIC_ALIAS(_findnexti64, libc__findnext32i64);
DEFINE_PUBLIC_ALIAS(_findnext32i64, libc__findnext32i64);
DEFINE_PUBLIC_ALIAS(_findnext64i32, libc__findnext64);
DEFINE_PUBLIC_ALIAS(_findnext64, libc__findnext64);
DEFINE_PUBLIC_ALIAS(DOS$_sopen_s_nolock, libd__sopen_s);
DEFINE_PUBLIC_ALIAS(DOS$_sopen_s, libd__sopen_s);
DEFINE_PUBLIC_ALIAS(_sopen_s_nolock, libc__sopen_s);
DEFINE_PUBLIC_ALIAS(_sopen_s, libc__sopen_s);
DEFINE_PUBLIC_ALIAS(_mktemp_s, libc__mktemp_s);
/*[[[end:exports]]]*/

DECL_END

#endif /* !GUARD_LIBC_USER_IO_C */
