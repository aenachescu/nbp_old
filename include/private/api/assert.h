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

#ifndef NBP_PRIVATE_API_ASSERT_H
#define NBP_PRIVATE_API_ASSERT_H

/*
 * TODO: add docs
 */
#define NBP_SUCCESS_MESSAGE(msg)

/*
 * TODO: add docs
 */
#define NBP_FAILURE_MESSAGE(msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT(cond, ...)                                                  \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_IMPL(cond)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_<operator>                                                      *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_EQ(a, b, ...)                                               \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_NE(a, b, ...)                                               \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_GT(a, b, ...)                                               \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_GE(a, b, ...)                                               \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LT(a, b, ...)                                               \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LE(a, b, ...)                                               \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_CHAR_<operator>                                                 *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_EQ(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_CHAR, char)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_NE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_CHAR, char)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_GT(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_CHAR, char)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_GE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_CHAR, char)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_LT(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_CHAR, char)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_LE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_CHAR, char)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_SHORT_<operator>                                                *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_EQ(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_SHORT, short)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_NE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_SHORT, short)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_GT(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_SHORT, short)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_GE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_SHORT, short)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_LT(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_SHORT, short)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_LE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_SHORT, short)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_USHORT_<operator>                                               *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_EQ(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_USHORT, ushort)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_NE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_USHORT, ushort)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_GT(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_USHORT, ushort)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_GE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_USHORT, ushort)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_LT(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_USHORT, ushort)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_LE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_USHORT, ushort)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_INT_<operator>                                                  *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_EQ(a, b, ...)                                           \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_INT, int)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_NE(a, b, ...)                                           \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_INT, int)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_GT(a, b, ...)                                           \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_INT, int)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_GE(a, b, ...)                                           \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_INT, int)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_LT(a, b, ...)                                           \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_INT, int)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_LE(a, b, ...)                                           \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_INT, int)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_UINT_<operator>                                                 *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_EQ(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_UINT, uint)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_NE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_UINT, uint)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_GT(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_UINT, uint)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_GE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_UINT, uint)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_LT(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_UINT, uint)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_LE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_UINT, uint)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_LONG_<operator>                                                 *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_EQ(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_LONG, long)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_NE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_LONG, long)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_GT(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_LONG, long)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_GE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_LONG, long)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_LT(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_LONG, long)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_LE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_LONG, long)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_ULONG_<operator>                                                *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_EQ(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_ULONG, ulong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_NE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_ULONG, ulong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_GT(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_ULONG, ulong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_GE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_ULONG, ulong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_LT(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_ULONG, ulong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_LE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_ULONG, ulong)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_LLONG_<operator>                                                *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_EQ(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_LLONG, llong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_NE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_LLONG, llong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_GT(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_LLONG, llong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_GE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_LLONG, llong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_LT(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_LLONG, llong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_LE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_LLONG, llong)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_ULLONG_<operator>                                               *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_EQ(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_NE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_GT(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_GE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_LT(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_LE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_FLOAT_<operator>                                                *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_EQ(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_FLOAT, float)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_NE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_FLOAT, float)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_GT(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_FLOAT, float)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_GE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_FLOAT, float)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_LT(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_FLOAT, float)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_LE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_FLOAT, float)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_DOUBLE_<operator>                                               *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_EQ(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_DOUBLE, double)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_NE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_DOUBLE, double)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_GT(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_DOUBLE, double)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_GE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_DOUBLE, double)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_LT(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_DOUBLE, double)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_LE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_DOUBLE, double)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_LDOUBLE_<operator>                                              *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_EQ(a, b, ...)                                       \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_NE(a, b, ...)                                       \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_GT(a, b, ...)                                       \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_GE(a, b, ...)                                       \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_LT(a, b, ...)                                       \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_LE(a, b, ...)                                       \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE)

#define NBP_ASSERT_PRIVATE_IMPL(cond)                                          \
    if (cond) {                                                                \
        nbp_test_increment_asserts_stats(                                      \
            nbpParamTest,                                                      \
            NBP_ASSERT_STATUS_PASSED,                                          \
            nbpParamAssertType                                                 \
        );                                                                     \
        nbp_printer_notify_assert_result(                                      \
            nbpParamTest,                                                      \
            #cond,                                                             \
            nbpParamAssertType,                                                \
            NBP_ASSERT_STATUS_PASSED,                                          \
            __LINE__,                                                          \
            NBP_MEMORY_NULL_POINTER,                                           \
            nbpParamSuccessMessage                                             \
        );                                                                     \
    } else {                                                                   \
        nbp_test_increment_asserts_stats(                                      \
            nbpParamTest,                                                      \
            NBP_ASSERT_STATUS_FAILED,                                          \
            nbpParamAssertType                                                 \
        );                                                                     \
        nbp_printer_notify_assert_result(                                      \
            nbpParamTest,                                                      \
            #cond,                                                             \
            nbpParamAssertType,                                                \
            NBP_ASSERT_STATUS_FAILED,                                          \
            __LINE__,                                                          \
            nbpParamFailureMessage,                                            \
            NBP_MEMORY_NULL_POINTER                                            \
        );                                                                     \
        if (nbpParamAssertType != NBP_ASSERT_NON_FATAL) {                      \
            return;                                                            \
        }                                                                      \
    }                                                                          \
    nbpParamAssertType      = NBP_ASSERT_NON_FATAL;                            \
    nbpParamSuccessMessage  = NBP_MEMORY_NULL_POINTER;                         \
    nbpParamFailureMessage  = NBP_MEMORY_NULL_POINTER;

#define NBP_ASSERT_PRIVATE_OP_IMPL(a, b, op, printerOp)                        \
    if (a op b) {                                                              \
        nbp_printer_type_value_t tmpA, tmpB;                                   \
        tmpA.stringValue = #a; tmpB.stringValue = #b;                          \
        nbp_test_increment_asserts_stats(                                      \
            nbpParamTest,                                                      \
            NBP_ASSERT_STATUS_PASSED,                                          \
            nbpParamAssertType                                                 \
        );                                                                     \
        nbp_printer_notify_assert_type_op_result(                              \
            nbpParamTest,                                                      \
            tmpA,                                                              \
            tmpB,                                                              \
            NBP_PRINTER_TYPE_NONE,                                             \
            printerOp,                                                         \
            nbpParamAssertType,                                                \
            NBP_ASSERT_STATUS_PASSED,                                          \
            __LINE__,                                                          \
            NBP_MEMORY_NULL_POINTER,                                           \
            nbpParamSuccessMessage                                             \
        );                                                                     \
    } else {                                                                   \
        nbp_printer_type_value_t tmpA, tmpB;                                   \
        tmpA.stringValue = #a; tmpB.stringValue = #b;                          \
        nbp_test_increment_asserts_stats(                                      \
            nbpParamTest,                                                      \
            NBP_ASSERT_STATUS_FAILED,                                          \
            nbpParamAssertType                                                 \
        );                                                                     \
        nbp_printer_notify_assert_type_op_result(                              \
            nbpParamTest,                                                      \
            tmpA,                                                              \
            tmpB,                                                              \
            NBP_PRINTER_TYPE_NONE,                                             \
            printerOp,                                                         \
            nbpParamAssertType,                                                \
            NBP_ASSERT_STATUS_FAILED,                                          \
            __LINE__,                                                          \
            nbpParamFailureMessage,                                            \
            NBP_MEMORY_NULL_POINTER                                            \
        );                                                                     \
        if (nbpParamAssertType != NBP_ASSERT_NON_FATAL) {                      \
            return;                                                            \
        }                                                                      \
    }                                                                          \
    nbpParamAssertType      = NBP_ASSERT_NON_FATAL;                            \
    nbpParamSuccessMessage  = NBP_MEMORY_NULL_POINTER;                         \
    nbpParamFailureMessage  = NBP_MEMORY_NULL_POINTER;

#define NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, op, printerOp, type, valuePrefix)\
    do {                                                                       \
        nbp_printer_type_value_t tmpA, tmpB;                                   \
        tmpA.valuePrefix ## Value = a; tmpB.valuePrefix ## Value = b;          \
        if (tmpA.valuePrefix ## Value op tmpB.valuePrefix ## Value) {          \
            nbp_test_increment_asserts_stats(                                  \
                nbpParamTest,                                                  \
                NBP_ASSERT_STATUS_PASSED,                                      \
                nbpParamAssertType                                             \
            );                                                                 \
            nbp_printer_notify_assert_type_op_result(                          \
                nbpParamTest,                                                  \
                tmpA,                                                          \
                tmpB,                                                          \
                type,                                                          \
                printerOp,                                                     \
                nbpParamAssertType,                                            \
                NBP_ASSERT_STATUS_PASSED,                                      \
                __LINE__,                                                      \
                NBP_MEMORY_NULL_POINTER,                                       \
                nbpParamSuccessMessage                                         \
            );                                                                 \
        } else {                                                               \
            nbp_test_increment_asserts_stats(                                  \
                nbpParamTest,                                                  \
                NBP_ASSERT_STATUS_FAILED,                                      \
                nbpParamAssertType                                             \
            );                                                                 \
            nbp_printer_notify_assert_type_op_result(                          \
                nbpParamTest,                                                  \
                tmpA,                                                          \
                tmpB,                                                          \
                type,                                                          \
                printerOp,                                                     \
                nbpParamAssertType,                                            \
                NBP_ASSERT_STATUS_FAILED,                                      \
                __LINE__,                                                      \
                nbpParamFailureMessage,                                        \
                NBP_MEMORY_NULL_POINTER                                        \
            );                                                                 \
            if (nbpParamAssertType != NBP_ASSERT_NON_FATAL) {                  \
                return;                                                        \
            }                                                                  \
        }                                                                      \
        nbpParamAssertType      = NBP_ASSERT_NON_FATAL;                        \
        nbpParamSuccessMessage  = NBP_MEMORY_NULL_POINTER;                     \
        nbpParamFailureMessage  = NBP_MEMORY_NULL_POINTER;                     \
    } while (0);

#define NBP_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, op, printerOp)                \
    do {                                                                       \
        long double ldA, ldB;                                                  \
        nbp_printer_type_value_t tmpA, tmpB;                                   \
        ldA = a; ldB = b;                                                      \
        tmpA.ldoubleValue = &ldA; tmpB.ldoubleValue = &ldB;                    \
        if (ldA op ldB) {                                                      \
            nbp_test_increment_asserts_stats(                                  \
                nbpParamTest,                                                  \
                NBP_ASSERT_STATUS_PASSED,                                      \
                nbpParamAssertType                                             \
            );                                                                 \
            nbp_printer_notify_assert_type_op_result(                          \
                nbpParamTest,                                                  \
                tmpA,                                                          \
                tmpB,                                                          \
                NBP_PRINTER_TYPE_LDOUBLE,                                      \
                printerOp,                                                     \
                nbpParamAssertType,                                            \
                NBP_ASSERT_STATUS_PASSED,                                      \
                __LINE__,                                                      \
                NBP_MEMORY_NULL_POINTER,                                       \
                nbpParamSuccessMessage                                         \
            );                                                                 \
        } else {                                                               \
            nbp_test_increment_asserts_stats(                                  \
                nbpParamTest,                                                  \
                NBP_ASSERT_STATUS_FAILED,                                      \
                nbpParamAssertType                                             \
            );                                                                 \
            nbp_printer_notify_assert_type_op_result(                          \
                nbpParamTest,                                                  \
                tmpA,                                                          \
                tmpB,                                                          \
                NBP_PRINTER_TYPE_LDOUBLE,                                      \
                printerOp,                                                     \
                nbpParamAssertType,                                            \
                NBP_ASSERT_STATUS_FAILED,                                      \
                __LINE__,                                                      \
                nbpParamFailureMessage,                                        \
                NBP_MEMORY_NULL_POINTER                                        \
            );                                                                 \
            if (nbpParamAssertType != NBP_ASSERT_NON_FATAL) {                  \
                return;                                                        \
            }                                                                  \
        }                                                                      \
        nbpParamAssertType      = NBP_ASSERT_NON_FATAL;                        \
        nbpParamSuccessMessage  = NBP_MEMORY_NULL_POINTER;                     \
        nbpParamFailureMessage  = NBP_MEMORY_NULL_POINTER;                     \
    } while (0);

#define NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(...)                        \
    NBP_PP_CONCAT(                                                             \
        NBP_PP_PROCESSING_PARAM_,                                              \
        NBP_PP_VARCOUNT(P ## __VA_ARGS__)                                      \
    )(P ## __VA_ARGS__)

#define NBP_PP_EAT_PP_NBP_SUCCESS_MESSAGE(msg) nbpParamSuccessMessage = msg;

#define NBP_PP_EAT_PP_NBP_FAILURE_MESSAGE(msg) nbpParamFailureMessage = msg;

#define NBP_PP_EAT_PP_NBP_ASSERT_NON_FATAL                                     \
    nbpParamAssertType = NBP_ASSERT_NON_FATAL;
#define NBP_PP_EAT_PP_NBP_ASSERT_FATAL                                         \
    nbpParamAssertType = NBP_ASSERT_FATAL;
#define NBP_PP_EAT_PP_NBP_ASSERT_FATAL_FOR_TEST                                \
    nbpParamAssertType = NBP_ASSERT_FATAL_FOR_TEST;
#define NBP_PP_EAT_PP_NBP_ASSERT_FATAL_FOR_MODULE                              \
    nbpParamAssertType = NBP_ASSERT_FATAL_FOR_MODULE;

#endif // end if NBP_PRIVATE_API_ASSERT_H
