/* HASH CRC-32:0x6a03434e */
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
#ifndef __local_mtx_lock_defined
#define __local_mtx_lock_defined 1
#include <__crt.h>
#ifdef __CRT_HAVE_pthread_mutex_lock
#include <bits/threads.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: pthread_mutex_lock from pthread */
#if !defined(__local___localdep_pthread_mutex_lock_defined) && defined(__CRT_HAVE_pthread_mutex_lock)
#define __local___localdep_pthread_mutex_lock_defined 1
/* Lock a mutex */
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,__localdep_pthread_mutex_lock,(__pthread_mutex_t *__mutex),pthread_mutex_lock,(__mutex))
#endif /* !__local___localdep_pthread_mutex_lock_defined && __CRT_HAVE_pthread_mutex_lock */
__NAMESPACE_LOCAL_END
#include <asm/threads.h>
#include <bits/pthreadtypes.h>
__NAMESPACE_LOCAL_BEGIN
/* Block the current thread until the mutex pointed to by MUTEX is
 * unlocked.  In that case current thread will not be blocked
 * s.a. `pthread_mutex_lock()' */
__LOCAL_LIBC(mtx_lock) __ATTR_NONNULL((1)) int
__NOTHROW_RPC(__LIBCCALL __LIBC_LOCAL_NAME(mtx_lock))(__mtx_t *__restrict __mutex) {
	int __error;
	__error = __localdep_pthread_mutex_lock((__pthread_mutex_t *)__mutex);
	if __likely(!__error)
		return __thrd_success;
	return __thrd_error;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_mtx_lock_defined
#define __local___localdep_mtx_lock_defined 1
#define __localdep_mtx_lock __LIBC_LOCAL_NAME(mtx_lock)
#endif /* !__local___localdep_mtx_lock_defined */
#else /* __CRT_HAVE_pthread_mutex_lock */
#undef __local_mtx_lock_defined
#endif /* !__CRT_HAVE_pthread_mutex_lock */
#endif /* !__local_mtx_lock_defined */
