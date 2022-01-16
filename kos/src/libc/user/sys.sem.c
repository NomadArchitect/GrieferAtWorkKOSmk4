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
#ifndef GUARD_LIBC_USER_SYS_SEM_C
#define GUARD_LIBC_USER_SYS_SEM_C 1

#include "../api.h"
#include "sys.sem.h"

DECL_BEGIN







/*[[[head:libd_semctl,hash:CRC-32=0xc28f7352]]]*/
#ifndef __LIBCCALL_IS_LIBDCALL
/* Semaphore control operation. */
INTERN ATTR_SECTION(".text.crt.dos.io.poll") int
NOTHROW_NCX(VLIBDCALL libd_semctl)(int semid,
                                   __STDC_INT_AS_UINT_T semnum,
                                   __STDC_INT_AS_UINT_T cmd,
                                   ...)
/*[[[body:libd_semctl]]]*/
/*AUTO*/{
	(void)semid;
	(void)semnum;
	(void)cmd;
	CRT_UNIMPLEMENTED("semctl"); /* TODO */
	libc_seterrno(ENOSYS);
	return 0;
}
#endif /* MAGIC:impl_if */
/*[[[end:libd_semctl]]]*/

/*[[[head:libc_semctl,hash:CRC-32=0xfd05428e]]]*/
/* Semaphore control operation. */
INTERN ATTR_SECTION(".text.crt.io.poll") int
NOTHROW_NCX(VLIBCCALL libc_semctl)(int semid,
                                   __STDC_INT_AS_UINT_T semnum,
                                   __STDC_INT_AS_UINT_T cmd,
                                   ...)
/*[[[body:libc_semctl]]]*/
/*AUTO*/{
	(void)semid;
	(void)semnum;
	(void)cmd;
	CRT_UNIMPLEMENTED("semctl"); /* TODO */
	libc_seterrno(ENOSYS);
	return 0;
}
/*[[[end:libc_semctl]]]*/

/*[[[head:libc_semget,hash:CRC-32=0xf7f7c12d]]]*/
/* Get semaphore */
INTERN ATTR_SECTION(".text.crt.io.poll") int
NOTHROW_NCX(LIBCCALL libc_semget)(key_t key,
                                  __STDC_INT_AS_UINT_T nsems,
                                  __STDC_INT_AS_UINT_T semflg)
/*[[[body:libc_semget]]]*/
/*AUTO*/{
	(void)key;
	(void)nsems;
	(void)semflg;
	CRT_UNIMPLEMENTEDF("semget(%" PRIxN(__SIZEOF_KEY_T__) ", %x, %x)", key, nsems, semflg); /* TODO */
	libc_seterrno(ENOSYS);
	return 0;
}
/*[[[end:libc_semget]]]*/

/*[[[head:libc_semop,hash:CRC-32=0xbe8fb9d6]]]*/
/* Operate on semaphore */
INTERN ATTR_SECTION(".text.crt.io.poll") int
NOTHROW_NCX(LIBCCALL libc_semop)(int semid,
                                 struct sembuf *sops,
                                 size_t nsops)
/*[[[body:libc_semop]]]*/
/*AUTO*/{
	(void)semid;
	(void)sops;
	(void)nsops;
	CRT_UNIMPLEMENTEDF("semop(%x, %p, %Ix)", semid, sops, nsops); /* TODO */
	libc_seterrno(ENOSYS);
	return 0;
}
/*[[[end:libc_semop]]]*/

/*[[[head:libc_semtimedop,hash:CRC-32=0x54f2b6d7]]]*/
/* Operate on semaphore with timeout */
INTERN ATTR_SECTION(".text.crt.io.poll") int
NOTHROW_NCX(LIBCCALL libc_semtimedop)(int semid,
                                      struct sembuf *sops,
                                      size_t nsops,
                                      struct timespec const *timeout)
/*[[[body:libc_semtimedop]]]*/
/*AUTO*/{
	(void)semid;
	(void)sops;
	(void)nsops;
	(void)timeout;
	CRT_UNIMPLEMENTEDF("semtimedop(%x, %p, %Ix, %p)", semid, sops, nsops, timeout); /* TODO */
	libc_seterrno(ENOSYS);
	return 0;
}
/*[[[end:libc_semtimedop]]]*/





/*[[[start:exports,hash:CRC-32=0x879137b2]]]*/
#ifndef __LIBCCALL_IS_LIBDCALL
DEFINE_PUBLIC_ALIAS(DOS$semctl, libd_semctl);
#endif /* !__LIBCCALL_IS_LIBDCALL */
DEFINE_PUBLIC_ALIAS(semctl, libc_semctl);
DEFINE_PUBLIC_ALIAS(semget, libc_semget);
DEFINE_PUBLIC_ALIAS(semop, libc_semop);
DEFINE_PUBLIC_ALIAS(semtimedop, libc_semtimedop);
/*[[[end:exports]]]*/

DECL_END

#endif /* !GUARD_LIBC_USER_SYS_SEM_C */
