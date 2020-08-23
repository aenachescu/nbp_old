/*
No Bugs in Production (NBP)
https://github.com/aenachescu/nbp

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2019-2020 Alin Enachescu <https://github.com/aenachescu>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef NBP_PRIVATE_UTILS_PREPROCESSOR_H
#define NBP_PRIVATE_UTILS_PREPROCESSOR_H

#define NBP_PP_PRIVATE_CONCAT_HELPER(a, b) a ## b

#define NBP_PP_CONCAT(a, b) NBP_PP_PRIVATE_CONCAT_HELPER(a, b)

#define NBP_PP_PRIVATE_VARCOUNT_HELPER(                                        \
    _, _32, _31, _30, _29, _28, _27, _26, _25, _24, _23, _22, _21, _20, _19,   \
    _18, _17, _16, _15, _14, _13, _12, _11, _10, _9, _8, _7, _6, _5, _4, _3,   \
    _2, _n, ...) _n

#define NBP_PP_VARCOUNT(...)                                                   \
    NBP_PP_PRIVATE_VARCOUNT_HELPER(                                            \
        P ## __VA_ARGS__,                                                      \
        32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15,\
        14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1,                         \
    )

// This macro is generated when a variadic macro is used with no parameters
#define NBP_PP_EAT_PP_

#define NBP_PP_PROCESSING_PARAM_1(param)                                       \
    NBP_PP_EAT_ ## param
#define NBP_PP_PROCESSING_PARAM_2(param, ...)                                  \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_1(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_3(param, ...)                                  \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_4(param, ...)                                  \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_3(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_5(param, ...)                                  \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_4(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_6(param, ...)                                  \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_5(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_7(param, ...)                                  \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_6(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_8(param, ...)                                  \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_7(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_9(param, ...)                                  \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_8(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_10(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_9(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_11(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_10(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_12(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_11(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_13(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_12(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_14(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_13(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_15(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_14(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_16(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_15(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_17(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_16(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_18(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_17(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_19(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_18(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_20(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_19(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_21(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_20(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_22(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_21(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_23(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_22(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_24(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_23(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_25(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_24(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_26(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_25(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_27(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_26(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_28(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_27(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_29(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_28(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_30(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_29(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_31(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_30(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_32(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_31(PP_ ## __VA_ARGS__)

#define NBP_PP_PROCESSING_PARAM_2_1(param)                                     \
    NBP_PP_EAT_ ## param
#define NBP_PP_PROCESSING_PARAM_2_2(param, ...)                                \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_1(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_3(param, ...)                                \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_2(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_4(param, ...)                                \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_3(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_5(param, ...)                                \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_4(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_6(param, ...)                                \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_5(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_7(param, ...)                                \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_6(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_8(param, ...)                                \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_7(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_9(param, ...)                                \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_8(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_10(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_9(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_11(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_10(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_12(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_11(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_13(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_12(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_14(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_13(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_15(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_14(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_16(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_15(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_17(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_16(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_18(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_17(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_19(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_18(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_20(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_19(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_21(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_20(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_22(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_21(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_23(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_22(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_24(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_23(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_25(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_24(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_26(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_25(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_27(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_26(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_28(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_27(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_29(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_28(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_30(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_29(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_31(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_30(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_32(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_31(PP_ ## __VA_ARGS__)

#endif // end if NBP_PRIVATE_UTILS_PREPROCESSOR_H
