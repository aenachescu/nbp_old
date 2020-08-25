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

#ifndef NBP_PRIVATE_API_CHECK_H
#define NBP_PRIVATE_API_CHECK_H

/*
 * TODO: add docs
 */
#define NBP_CHECK_STATUS_PASSED 1

/*
 * TODO: add docs
 */
#define NBP_CHECK_STATUS_FAILED 0

#define NBP_CHECK_PRIVATE_IMPL(cond)                                           \
    if (cond) {                                                                \
        nbpParamTest->checks.numPassed++;                                      \
        nbp_printer_notify_check_result(                                       \
            nbpParamTest,                                                      \
            #cond,                                                             \
            NBP_CHECK_STATUS_PASSED,                                           \
            __LINE__,                                                          \
            NBP_MEMORY_NULL_POINTER,                                           \
            nbpParamSuccessMessage                                             \
        );                                                                     \
    } else {                                                                   \
        nbpParamTest->checks.numFailed++;                                      \
        nbp_printer_notify_check_result(                                       \
            nbpParamTest,                                                      \
            #cond,                                                             \
            NBP_CHECK_STATUS_FAILED,                                           \
            __LINE__,                                                          \
            nbpParamFailureMessage,                                            \
            NBP_MEMORY_NULL_POINTER                                            \
        );                                                                     \
    }                                                                          \
    nbpParamSuccessMessage = NBP_MEMORY_NULL_POINTER;                          \
    nbpParamFailureMessage = NBP_MEMORY_NULL_POINTER;

#define NBP_CHECK_PRIVATE_OP_IMPL(a, b, op, printerOp)                         \
    if (a op b) {                                                              \
        nbp_printer_type_value_t tmpA, tmpB;                                   \
        tmpA.stringValue = #a; tmpB.stringValue = #b;                          \
        nbpParamTest->checks.numPassed++;                                      \
        nbp_printer_notify_check_type_op_result(                               \
            nbpParamTest,                                                      \
            tmpA,                                                              \
            tmpB,                                                              \
            NBP_PRINTER_TYPE_NONE,                                             \
            printerOp,                                                         \
            NBP_CHECK_STATUS_PASSED,                                           \
            __LINE__,                                                          \
            NBP_MEMORY_NULL_POINTER,                                           \
            nbpParamSuccessMessage                                             \
        );                                                                     \
    } else {                                                                   \
        nbp_printer_type_value_t tmpA, tmpB;                                   \
        tmpA.stringValue = #a; tmpB.stringValue = #b;                          \
        nbpParamTest->checks.numFailed++;                                      \
        nbp_printer_notify_check_type_op_result(                               \
            nbpParamTest,                                                      \
            tmpA,                                                              \
            tmpB,                                                              \
            NBP_PRINTER_TYPE_NONE,                                             \
            printerOp,                                                         \
            NBP_CHECK_STATUS_FAILED,                                           \
            __LINE__,                                                          \
            nbpParamFailureMessage,                                            \
            NBP_MEMORY_NULL_POINTER                                            \
        );                                                                     \
    }                                                                          \
    nbpParamSuccessMessage = NBP_MEMORY_NULL_POINTER;                          \
    nbpParamFailureMessage = NBP_MEMORY_NULL_POINTER;

#define NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, op, printerOp, type, valuePrefix) \
    do {                                                                       \
        nbp_printer_type_value_t tmpA, tmpB;                                   \
        tmpA.valuePrefix ## Value = a; tmpB.valuePrefix ## Value = b;          \
        if (tmpA.valuePrefix ## Value op tmpB.valuePrefix ## Value) {          \
            nbpParamTest->checks.numPassed++;                                  \
            nbp_printer_notify_check_type_op_result(                           \
                nbpParamTest,                                                  \
                tmpA,                                                          \
                tmpB,                                                          \
                type,                                                          \
                printerOp,                                                     \
                NBP_CHECK_STATUS_PASSED,                                       \
                __LINE__,                                                      \
                NBP_MEMORY_NULL_POINTER,                                       \
                nbpParamSuccessMessage                                         \
            );                                                                 \
        } else {                                                               \
            nbpParamTest->checks.numFailed++;                                  \
            nbp_printer_notify_check_type_op_result(                           \
                nbpParamTest,                                                  \
                tmpA,                                                          \
                tmpB,                                                          \
                type,                                                          \
                printerOp,                                                     \
                NBP_CHECK_STATUS_FAILED,                                       \
                __LINE__,                                                      \
                nbpParamFailureMessage,                                        \
                NBP_MEMORY_NULL_POINTER                                        \
            );                                                                 \
        }                                                                      \
        nbpParamSuccessMessage = NBP_MEMORY_NULL_POINTER;                      \
        nbpParamFailureMessage = NBP_MEMORY_NULL_POINTER;                      \
    } while (0);

#define NBP_CHECK_PRIVATE_LDOUBLE_OP_IMPL(a, b, op, printerOp)                 \
    do {                                                                       \
        long double ldA, ldB;                                                  \
        nbp_printer_type_value_t tmpA, tmpB;                                   \
        ldA = a; ldB = b;                                                      \
        tmpA.ldoubleValue = &ldA; tmpB.ldoubleValue = &ldB;                    \
        if (ldA op ldB) {                                                      \
            nbpParamTest->checks.numPassed++;                                  \
            nbp_printer_notify_check_type_op_result(                           \
                nbpParamTest,                                                  \
                tmpA,                                                          \
                tmpB,                                                          \
                NBP_PRINTER_TYPE_LDOUBLE,                                      \
                printerOp,                                                     \
                NBP_CHECK_STATUS_PASSED,                                       \
                __LINE__,                                                      \
                NBP_MEMORY_NULL_POINTER,                                       \
                nbpParamSuccessMessage                                         \
            );                                                                 \
        } else {                                                               \
            nbpParamTest->checks.numFailed++;                                  \
            nbp_printer_notify_check_type_op_result(                           \
                nbpParamTest,                                                  \
                tmpA,                                                          \
                tmpB,                                                          \
                NBP_PRINTER_TYPE_LDOUBLE,                                      \
                printerOp,                                                     \
                NBP_CHECK_STATUS_FAILED,                                       \
                __LINE__,                                                      \
                nbpParamFailureMessage,                                        \
                NBP_MEMORY_NULL_POINTER                                        \
            );                                                                 \
        }                                                                      \
        nbpParamSuccessMessage = NBP_MEMORY_NULL_POINTER;                      \
        nbpParamFailureMessage = NBP_MEMORY_NULL_POINTER;                      \
    } while (0);

/*
 * TODO: add docs
 */
#define NBP_CHECK(cond, ...)                                                   \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_IMPL(cond)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_CHECK_<operator>                                                       *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_CHECK_EQ(a, b, ...)                                                \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ)

/*
 * TODO: add docs
 */
#define NBP_CHECK_NE(a, b, ...)                                                \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE)

/*
 * TODO: add docs
 */
#define NBP_CHECK_GT(a, b, ...)                                                \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT)

/*
 * TODO: add docs
 */
#define NBP_CHECK_GE(a, b, ...)                                                \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LT(a, b, ...)                                                \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LE(a, b, ...)                                                \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_CHECK_CHAR_<operator>                                                  *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_EQ(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        NBP_PRINTER_TYPE_CHAR, char)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_NE(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        NBP_PRINTER_TYPE_CHAR, char)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GT(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        NBP_PRINTER_TYPE_CHAR, char)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GE(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        NBP_PRINTER_TYPE_CHAR, char)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LT(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        NBP_PRINTER_TYPE_CHAR, char)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LE(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        NBP_PRINTER_TYPE_CHAR, char)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_CHECK_SHORT_<operator>                                                 *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_EQ(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        NBP_PRINTER_TYPE_SHORT, short)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_NE(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        NBP_PRINTER_TYPE_SHORT, short)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_GT(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        NBP_PRINTER_TYPE_SHORT, short)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_GE(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        NBP_PRINTER_TYPE_SHORT, short)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_LT(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        NBP_PRINTER_TYPE_SHORT, short)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_LE(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        NBP_PRINTER_TYPE_SHORT, short)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_CHECK_USHORT_<operator>                                                *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_EQ(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        NBP_PRINTER_TYPE_USHORT, ushort)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_NE(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        NBP_PRINTER_TYPE_USHORT, ushort)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_GT(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        NBP_PRINTER_TYPE_USHORT, ushort)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_GE(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        NBP_PRINTER_TYPE_USHORT, ushort)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_LT(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        NBP_PRINTER_TYPE_USHORT, ushort)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_LE(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        NBP_PRINTER_TYPE_USHORT, ushort)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_CHECK_INT_<operator>                                                   *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_EQ(a, b, ...)                                            \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        NBP_PRINTER_TYPE_INT, int)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_NE(a, b, ...)                                            \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        NBP_PRINTER_TYPE_INT, int)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_GT(a, b, ...)                                            \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        NBP_PRINTER_TYPE_INT, int)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_GE(a, b, ...)                                            \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        NBP_PRINTER_TYPE_INT, int)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_LT(a, b, ...)                                            \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        NBP_PRINTER_TYPE_INT, int)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_LE(a, b, ...)                                            \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        NBP_PRINTER_TYPE_INT, int)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_CHECK_UINT_<operator>                                                  *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_EQ(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        NBP_PRINTER_TYPE_UINT, uint)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_NE(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        NBP_PRINTER_TYPE_UINT, uint)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_GT(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        NBP_PRINTER_TYPE_UINT, uint)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_GE(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        NBP_PRINTER_TYPE_UINT, uint)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_LT(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        NBP_PRINTER_TYPE_UINT, uint)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_LE(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        NBP_PRINTER_TYPE_UINT, uint)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_CHECK_LONG_<operator>                                                  *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_EQ(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        NBP_PRINTER_TYPE_LONG, long)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_NE(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        NBP_PRINTER_TYPE_LONG, long)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_GT(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        NBP_PRINTER_TYPE_LONG, long)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_GE(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        NBP_PRINTER_TYPE_LONG, long)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_LT(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        NBP_PRINTER_TYPE_LONG, long)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_LE(a, b, ...)                                           \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        NBP_PRINTER_TYPE_LONG, long)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_CHECK_ULONG_<operator>                                                 *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_EQ(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        NBP_PRINTER_TYPE_ULONG, ulong)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_NE(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        NBP_PRINTER_TYPE_ULONG, ulong)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_GT(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        NBP_PRINTER_TYPE_ULONG, ulong)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_GE(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        NBP_PRINTER_TYPE_ULONG, ulong)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_LT(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        NBP_PRINTER_TYPE_ULONG, ulong)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_LE(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        NBP_PRINTER_TYPE_ULONG, ulong)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_CHECK_LLONG_<operator>                                                 *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_EQ(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        NBP_PRINTER_TYPE_LLONG, llong)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_NE(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        NBP_PRINTER_TYPE_LLONG, llong)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_GT(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        NBP_PRINTER_TYPE_LLONG, llong)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_GE(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        NBP_PRINTER_TYPE_LLONG, llong)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_LT(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        NBP_PRINTER_TYPE_LLONG, llong)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_LE(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        NBP_PRINTER_TYPE_LLONG, llong)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_CHECK_ULLONG_<operator>                                                *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_EQ(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_NE(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_GT(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_GE(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_LT(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_LE(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_CHECK_FLOAT_<operator>                                                 *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_CHECK_FLOAT_EQ(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        NBP_PRINTER_TYPE_FLOAT, float)

/*
 * TODO: add docs
 */
#define NBP_CHECK_FLOAT_NE(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        NBP_PRINTER_TYPE_FLOAT, float)

/*
 * TODO: add docs
 */
#define NBP_CHECK_FLOAT_GT(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        NBP_PRINTER_TYPE_FLOAT, float)

/*
 * TODO: add docs
 */
#define NBP_CHECK_FLOAT_GE(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        NBP_PRINTER_TYPE_FLOAT, float)

/*
 * TODO: add docs
 */
#define NBP_CHECK_FLOAT_LT(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        NBP_PRINTER_TYPE_FLOAT, float)

/*
 * TODO: add docs
 */
#define NBP_CHECK_FLOAT_LE(a, b, ...)                                          \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        NBP_PRINTER_TYPE_FLOAT, float)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_CHECK_DOUBLE_<operator>                                                *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_CHECK_DOUBLE_EQ(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        NBP_PRINTER_TYPE_DOUBLE, double)

/*
 * TODO: add docs
 */
#define NBP_CHECK_DOUBLE_NE(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        NBP_PRINTER_TYPE_DOUBLE, double)

/*
 * TODO: add docs
 */
#define NBP_CHECK_DOUBLE_GT(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        NBP_PRINTER_TYPE_DOUBLE, double)

/*
 * TODO: add docs
 */
#define NBP_CHECK_DOUBLE_GE(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        NBP_PRINTER_TYPE_DOUBLE, double)

/*
 * TODO: add docs
 */
#define NBP_CHECK_DOUBLE_LT(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        NBP_PRINTER_TYPE_DOUBLE, double)

/*
 * TODO: add docs
 */
#define NBP_CHECK_DOUBLE_LE(a, b, ...)                                         \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        NBP_PRINTER_TYPE_DOUBLE, double)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_CHECK_LDOUBLE_<operator>                                               *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_CHECK_LDOUBLE_EQ(a, b, ...)                                        \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_LDOUBLE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LDOUBLE_NE(a, b, ...)                                        \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_LDOUBLE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LDOUBLE_GT(a, b, ...)                                        \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_LDOUBLE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LDOUBLE_GE(a, b, ...)                                        \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_LDOUBLE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LDOUBLE_LT(a, b, ...)                                        \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_LDOUBLE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LDOUBLE_LE(a, b, ...)                                        \
    NBP_ASSERTION_PRIVATE_PARSE_ASSERTION_PARAMETERS(P_ ## __VA_ARGS__)        \
    NBP_CHECK_PRIVATE_LDOUBLE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE)

#endif // end if NBP_PRIVATE_API_CHECK_H
