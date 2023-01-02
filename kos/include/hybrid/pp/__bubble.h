/* Copyright (c) 2019-2023 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2023 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __GUARD_HYBRID_PP___BUBBLE_H
#define __GUARD_HYBRID_PP___BUBBLE_H 1

#include "../../__stdinc.h"

#ifdef __PREPROCESSOR_HAVE_VA_ARGS
#define __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_1(...)
#define __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_2(...) __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_1
#define __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_3(...) __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_2
#define __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_4(...) __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_3
#define __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_5(...) __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_4
#define __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_6(...) __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_5
#define __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_7(...) __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_6
#define __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_8(...) __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_7
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_0_1(...)  __VA_ARGS__
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_0_2(...)  __VA_ARGS__ __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_1
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_0_3(...)  __VA_ARGS__ __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_2
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_0_4(...)  __VA_ARGS__ __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_3
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_0_5(...)  __VA_ARGS__ __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_4
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_0_6(...)  __VA_ARGS__ __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_5
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_0_7(...)  __VA_ARGS__ __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_6
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_0_8(...)  __VA_ARGS__ __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_7
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_0_9(...)  __VA_ARGS__ __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_8
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_1_2(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_0_1
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_1_3(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_0_2
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_1_4(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_0_3
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_1_5(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_0_4
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_1_6(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_0_5
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_1_7(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_0_6
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_1_8(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_0_7
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_1_9(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_0_8
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_2_3(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_1_2
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_2_4(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_1_3
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_2_5(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_1_4
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_2_6(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_1_5
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_2_7(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_1_6
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_2_8(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_1_7
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_2_9(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_1_8
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_3_4(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_2_3
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_3_5(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_2_4
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_3_6(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_2_5
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_3_7(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_2_6
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_3_8(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_2_7
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_3_9(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_2_8
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_4_5(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_3_4
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_4_6(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_3_5
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_4_7(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_3_6
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_4_8(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_3_7
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_4_9(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_3_8
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_5_6(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_4_5
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_5_7(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_4_6
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_5_8(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_4_7
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_5_9(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_4_8
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_6_7(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_5_6
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_6_8(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_5_7
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_6_9(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_5_8
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_7_8(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_6_7
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_7_9(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_6_8
#define __HYBRID_PP_PRIVATE_BUBBLE_GET_8_9(...)  __HYBRID_PP_PRIVATE_BUBBLE_GET_7_8

#define __HYBRID_PP_BUBBLE_FORCE_EXPAND0(...) __VA_ARGS__
#define __HYBRID_PP_BUBBLE_FORCE_EXPAND1(...) __HYBRID_PP_BUBBLE_FORCE_EXPAND0(__VA_ARGS__)
#define __HYBRID_PP_BUBBLE_FORCE_EXPAND2(...) __HYBRID_PP_BUBBLE_FORCE_EXPAND1(__VA_ARGS__)
#define __HYBRID_PP_BUBBLE_FORCE_EXPAND3(...) __HYBRID_PP_BUBBLE_FORCE_EXPAND2(__VA_ARGS__)
#define __HYBRID_PP_BUBBLE_FORCE_EXPAND4(...) __HYBRID_PP_BUBBLE_FORCE_EXPAND3(__VA_ARGS__)
#define __HYBRID_PP_BUBBLE_FORCE_EXPAND5(...) __HYBRID_PP_BUBBLE_FORCE_EXPAND4(__VA_ARGS__)
#define __HYBRID_PP_BUBBLE_FORCE_EXPAND6(...) __HYBRID_PP_BUBBLE_FORCE_EXPAND5(__VA_ARGS__)
#define __HYBRID_PP_BUBBLE_FORCE_EXPAND7(...) __HYBRID_PP_BUBBLE_FORCE_EXPAND6(__VA_ARGS__)
#define __HYBRID_PP_BUBBLE_FORCE_EXPAND8(...) __HYBRID_PP_BUBBLE_FORCE_EXPAND7(__VA_ARGS__)
#define __HYBRID_PP_BUBBLE_FORCE_EXPAND9(...) __HYBRID_PP_BUBBLE_FORCE_EXPAND8(__VA_ARGS__)

#define __HYBRID_PP_PRIVATE_BUBBLE_ISSTOP_ARG_PLACEHOLDER___STOP__    ,
#define __HYBRID_PP_PRIVATE_BUBBLE_ISSTOP_TAKE_SECOND_ARG_IMPL(x,val,...) val
#define __HYBRID_PP_PRIVATE_BUBBLE_ISSTOP_EXPAND0(x) x
#define __HYBRID_PP_PRIVATE_BUBBLE_ISSTOP_TAKE_SECOND_ARG(x) __HYBRID_PP_PRIVATE_BUBBLE_ISSTOP_EXPAND0(__HYBRID_PP_PRIVATE_BUBBLE_ISSTOP_TAKE_SECOND_ARG_IMPL x)
#define __HYBRID_PP_PRIVATE_BUBBLE_ISSTOP2(x) __HYBRID_PP_PRIVATE_BUBBLE_ISSTOP_TAKE_SECOND_ARG((x 1,0))
#define __HYBRID_PP_PRIVATE_BUBBLE_ISSTOP(...) __HYBRID_PP_PRIVATE_BUBBLE_ISSTOP2(__HYBRID_PP_PRIVATE_BUBBLE_ISSTOP_ARG_PLACEHOLDER_##__VA_ARGS__)

#define __HYBRID_PP_PRIVATE_BUBBLE_CONTINUE2_0(sz,i) __HYBRID_PP_PRIVATE_BUBBLE_SIZE_##i
#define __HYBRID_PP_PRIVATE_BUBBLE_CONTINUE2_1(sz,i) sz
#define __HYBRID_PP_PRIVATE_BUBBLE_CONTINUE2(should,sz,i) __HYBRID_PP_PRIVATE_BUBBLE_CONTINUE2_##should(sz,i)
#define __HYBRID_PP_PRIVATE_BUBBLE_CONTINUE(should,sz,i) __HYBRID_PP_PRIVATE_BUBBLE_CONTINUE2(should,sz,i)
#define __HYBRID_PP_PRIVATE_BUBBLE_SIZE_9(...)   9 __HYBRID_PP_PRIVATE_BUBBLE_CONSUME_1
#define __HYBRID_PP_PRIVATE_BUBBLE_SIZE_8(...)   __HYBRID_PP_PRIVATE_BUBBLE_CONTINUE(__HYBRID_PP_PRIVATE_BUBBLE_ISSTOP(__VA_ARGS__),8,9)
#define __HYBRID_PP_PRIVATE_BUBBLE_SIZE_7(...)   __HYBRID_PP_PRIVATE_BUBBLE_CONTINUE(__HYBRID_PP_PRIVATE_BUBBLE_ISSTOP(__VA_ARGS__),7,8)
#define __HYBRID_PP_PRIVATE_BUBBLE_SIZE_6(...)   __HYBRID_PP_PRIVATE_BUBBLE_CONTINUE(__HYBRID_PP_PRIVATE_BUBBLE_ISSTOP(__VA_ARGS__),6,7)
#define __HYBRID_PP_PRIVATE_BUBBLE_SIZE_5(...)   __HYBRID_PP_PRIVATE_BUBBLE_CONTINUE(__HYBRID_PP_PRIVATE_BUBBLE_ISSTOP(__VA_ARGS__),5,6)
#define __HYBRID_PP_PRIVATE_BUBBLE_SIZE_4(...)   __HYBRID_PP_PRIVATE_BUBBLE_CONTINUE(__HYBRID_PP_PRIVATE_BUBBLE_ISSTOP(__VA_ARGS__),4,5)
#define __HYBRID_PP_PRIVATE_BUBBLE_SIZE_3(...)   __HYBRID_PP_PRIVATE_BUBBLE_CONTINUE(__HYBRID_PP_PRIVATE_BUBBLE_ISSTOP(__VA_ARGS__),3,4)
#define __HYBRID_PP_PRIVATE_BUBBLE_SIZE_2(...)   __HYBRID_PP_PRIVATE_BUBBLE_CONTINUE(__HYBRID_PP_PRIVATE_BUBBLE_ISSTOP(__VA_ARGS__),2,3)
#define __HYBRID_PP_PRIVATE_BUBBLE_SIZE_1(...)   __HYBRID_PP_PRIVATE_BUBBLE_CONTINUE(__HYBRID_PP_PRIVATE_BUBBLE_ISSTOP(__VA_ARGS__),1,2)
#define __HYBRID_PP_PRIVATE_BUBBLE_SIZE_0(...)   __HYBRID_PP_PRIVATE_BUBBLE_SIZE_1
#define __HYBRID_PP_PRIVATE_BUBBLE_GET2(x,i,sz) __HYBRID_PP_BUBBLE_FORCE_EXPAND##sz(__HYBRID_PP_PRIVATE_BUBBLE_GET_##i##_##sz x)
#define __HYBRID_PP_PRIVATE_BUBBLE_GET(x,i,sz)  __HYBRID_PP_PRIVATE_BUBBLE_GET2(x,i,sz)

#define __HYBRID_PP_BUBBLE_SIZE(x)   __HYBRID_PP_BUBBLE_FORCE_EXPAND0(__HYBRID_PP_PRIVATE_BUBBLE_SIZE_0 x (__STOP__))
#define __HYBRID_PP_BUBBLE_GET(x,i)  __HYBRID_PP_PRIVATE_BUBBLE_GET(x,i,__HYBRID_PP_BUBBLE_SIZE(x))
#endif /* __PREPROCESSOR_HAVE_VA_ARGS */

#endif /* !__GUARD_HYBRID_PP___BUBBLE_H */
