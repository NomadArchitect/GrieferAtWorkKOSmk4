/* HASH CRC-32:0xc53b096a */
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
#ifndef __local__ismbcgraph_defined
#define __local__ismbcgraph_defined
#include <__crt.h>
#ifdef __CRT_HAVE__ismbcgraph_l
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__ismbcgraph_l_defined
#define __local___localdep__ismbcgraph_l_defined
__CREDIRECT(__ATTR_WUNUSED,int,__NOTHROW_NCX,__localdep__ismbcgraph_l,(unsigned int __ch, __locale_t __locale),_ismbcgraph_l,(__ch,__locale))
#endif /* !__local___localdep__ismbcgraph_l_defined */
__LOCAL_LIBC(_ismbcgraph) __ATTR_WUNUSED int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_ismbcgraph))(unsigned int __ch) {
	return (__NAMESPACE_LOCAL_SYM __localdep__ismbcgraph_l)(__ch, __NULLPTR);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__ismbcgraph_defined
#define __local___localdep__ismbcgraph_defined
#define __localdep__ismbcgraph __LIBC_LOCAL_NAME(_ismbcgraph)
#endif /* !__local___localdep__ismbcgraph_defined */
#else /* __CRT_HAVE__ismbcgraph_l */
#undef __local__ismbcgraph_defined
#endif /* !__CRT_HAVE__ismbcgraph_l */
#endif /* !__local__ismbcgraph_defined */