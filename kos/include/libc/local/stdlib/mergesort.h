/* HASH CRC-32:0xc5d95601 */
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
#ifndef __local_mergesort_defined
#define __local_mergesort_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_qsort_defined
#define __local___localdep_qsort_defined
#ifdef __CRT_HAVE_qsort
__CREDIRECT_VOID(__ATTR_INOUT_OPT(1) __ATTR_NONNULL((4)),__NOTHROW_CB_NCX,__localdep_qsort,(void *__pbase, __SIZE_TYPE__ __item_count, __SIZE_TYPE__ __item_size, int (__LIBCCALL *__compar)(void const *__a, void const *__b)),qsort,(__pbase,__item_count,__item_size,__compar))
#else /* __CRT_HAVE_qsort */
__NAMESPACE_LOCAL_END
#include <libc/local/stdlib/qsort.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_qsort __LIBC_LOCAL_NAME(qsort)
#endif /* !__CRT_HAVE_qsort */
#endif /* !__local___localdep_qsort_defined */
__LOCAL_LIBC(mergesort) __ATTR_INOUT_OPT(1) __ATTR_NONNULL((4)) int
__NOTHROW_CB_NCX(__LIBCCALL __LIBC_LOCAL_NAME(mergesort))(void *__pbase, __SIZE_TYPE__ __item_count, __SIZE_TYPE__ __item_size, int (__LIBCCALL *__compar)(void const *__a, void const *__b)) {
	/* TODO: Actually do merge-sort! */
	(__NAMESPACE_LOCAL_SYM __localdep_qsort)(__pbase, __item_count, __item_size, __compar);
	return 0;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_mergesort_defined
#define __local___localdep_mergesort_defined
#define __localdep_mergesort __LIBC_LOCAL_NAME(mergesort)
#endif /* !__local___localdep_mergesort_defined */
#endif /* !__local_mergesort_defined */
