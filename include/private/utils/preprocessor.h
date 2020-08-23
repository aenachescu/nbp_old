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

#endif // end if NBP_PRIVATE_UTILS_PREPROCESSOR_H
