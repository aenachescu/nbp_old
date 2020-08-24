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

#ifndef NBP_PRIVATE_API_TEST_ASSERT_H
#define NBP_PRIVATE_API_TEST_ASSERT_H

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_STATUS_PASSED 1

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_STATUS_FAILED 0

#define NBP_TEST_ASSERT_PRIVATE_IMPL(cond, failMsg, passMsg)                   \
    if (cond) {                                                                \
        nbpParamTest->testAsserts.numPassed++;                                 \
        nbp_printer_notify_test_assert_result(                                 \
            nbpParamTest,                                                      \
            #cond,                                                             \
            NBP_TEST_ASSERT_STATUS_PASSED,                                     \
            __LINE__,                                                          \
            NBP_MEMORY_NULL_POINTER,                                           \
            passMsg                                                            \
        );                                                                     \
    } else {                                                                   \
        nbpParamTest->testAsserts.numFailed++;                                 \
        nbp_printer_notify_test_assert_result(                                 \
            nbpParamTest,                                                      \
            #cond,                                                             \
            NBP_TEST_ASSERT_STATUS_FAILED,                                     \
            __LINE__,                                                          \
            failMsg,                                                           \
            NBP_MEMORY_NULL_POINTER                                            \
        );                                                                     \
        return;                                                                \
    }

#define NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, op, printerOp, failMsg, passMsg) \
    if (a op b) {                                                              \
        nbp_printer_type_value_t tmpA, tmpB;                                   \
        tmpA.stringValue = #a; tmpB.stringValue = #b;                          \
        nbpParamTest->testAsserts.numPassed++;                                 \
        nbp_printer_notify_test_assert_type_op_result(                         \
            nbpParamTest,                                                      \
            tmpA,                                                              \
            tmpB,                                                              \
            NBP_PRINTER_TYPE_NONE,                                             \
            printerOp,                                                         \
            NBP_TEST_ASSERT_STATUS_PASSED,                                     \
            __LINE__,                                                          \
            NBP_MEMORY_NULL_POINTER,                                           \
            passMsg                                                            \
        );                                                                     \
    } else {                                                                   \
        nbp_printer_type_value_t tmpA, tmpB;                                   \
        tmpA.stringValue = #a; tmpB.stringValue = #b;                          \
        nbpParamTest->testAsserts.numFailed++;                                 \
        nbp_printer_notify_test_assert_type_op_result(                         \
            nbpParamTest,                                                      \
            tmpA,                                                              \
            tmpB,                                                              \
            NBP_PRINTER_TYPE_NONE,                                             \
            printerOp,                                                         \
            NBP_TEST_ASSERT_STATUS_FAILED,                                     \
            __LINE__,                                                          \
            failMsg,                                                           \
            NBP_MEMORY_NULL_POINTER                                            \
        );                                                                     \
        return;                                                                \
    }

#define NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, op, printerOp, type,        \
    valuePrefix, failMsg, passMsg)                                             \
    do {                                                                       \
        nbp_printer_type_value_t tmpA, tmpB;                                   \
        tmpA.valuePrefix ## Value = a; tmpB.valuePrefix ## Value = b;          \
        if (tmpA.valuePrefix ## Value op tmpB.valuePrefix ## Value) {          \
            nbpParamTest->testAsserts.numPassed++;                             \
            nbp_printer_notify_test_assert_type_op_result(                     \
                nbpParamTest,                                                  \
                tmpA,                                                          \
                tmpB,                                                          \
                type,                                                          \
                printerOp,                                                     \
                NBP_TEST_ASSERT_STATUS_PASSED,                                 \
                __LINE__,                                                      \
                NBP_MEMORY_NULL_POINTER,                                       \
                passMsg                                                        \
            );                                                                 \
        } else {                                                               \
            nbpParamTest->testAsserts.numFailed++;                             \
            nbp_printer_notify_test_assert_type_op_result(                     \
                nbpParamTest,                                                  \
                tmpA,                                                          \
                tmpB,                                                          \
                type,                                                          \
                printerOp,                                                     \
                NBP_TEST_ASSERT_STATUS_FAILED,                                 \
                __LINE__,                                                      \
                failMsg,                                                       \
                NBP_MEMORY_NULL_POINTER                                        \
            );                                                                 \
            return;                                                            \
        }                                                                      \
    } while (0);

#define NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, op, printerOp, failMsg,  \
    passMsg)                                                                   \
    do {                                                                       \
        long double ldA, ldB;                                                  \
        nbp_printer_type_value_t tmpA, tmpB;                                   \
        ldA = a; ldB = b;                                                      \
        tmpA.ldoubleValue = &ldA; tmpB.ldoubleValue = &ldB;                    \
        if (ldA op ldB) {                                                      \
            nbpParamTest->testAsserts.numPassed++;                             \
            nbp_printer_notify_test_assert_type_op_result(                     \
                nbpParamTest,                                                  \
                tmpA,                                                          \
                tmpB,                                                          \
                NBP_PRINTER_TYPE_LDOUBLE,                                      \
                printerOp,                                                     \
                NBP_TEST_ASSERT_STATUS_PASSED,                                 \
                __LINE__,                                                      \
                NBP_MEMORY_NULL_POINTER,                                       \
                passMsg                                                        \
            );                                                                 \
        } else {                                                               \
            nbpParamTest->testAsserts.numFailed++;                             \
            nbp_printer_notify_test_assert_type_op_result(                     \
                nbpParamTest,                                                  \
                tmpA,                                                          \
                tmpB,                                                          \
                NBP_PRINTER_TYPE_LDOUBLE,                                      \
                printerOp,                                                     \
                NBP_TEST_ASSERT_STATUS_FAILED,                                 \
                __LINE__,                                                      \
                failMsg,                                                       \
                NBP_MEMORY_NULL_POINTER                                        \
            );                                                                 \
            return;                                                            \
        }                                                                      \
    } while (0);

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT(cond)                                                  \
    NBP_TEST_ASSERT_PRIVATE_IMPL(cond, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FAIL_MSG(cond, msg)                                    \
    NBP_TEST_ASSERT_PRIVATE_IMPL(cond, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_PASS_MSG(cond, msg)                                    \
    NBP_TEST_ASSERT_PRIVATE_IMPL(cond, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_MSG(cond, failMsg, passMsg)                            \
    NBP_TEST_ASSERT_PRIVATE_IMPL(cond, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_TEST_ASSERT_<operator>                                                 *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_EQ(a, b)                                               \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_MEMORY_NULL_POINTER, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_EQ_FAIL_MSG(a, b, msg)                                 \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ, msg,    \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_EQ_PASS_MSG(a, b, msg)                                 \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_EQ_MSG(a, b, failMsg, passMsg)                         \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ, failMsg,\
        passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_NE(a, b)                                               \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_MEMORY_NULL_POINTER, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_NE_FAIL_MSG(a, b, msg)                                 \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE, msg,    \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_NE_PASS_MSG(a, b, msg)                                 \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_NE_MSG(a, b, failMsg, passMsg)                         \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE, failMsg,\
        passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_GT(a, b)                                               \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_MEMORY_NULL_POINTER, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_GT_FAIL_MSG(a, b, msg)                                 \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT, msg, \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_GT_PASS_MSG(a, b, msg)                                 \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_GT_MSG(a, b, failMsg, passMsg)                         \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT, failMsg, \
        passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_GE(a, b)                                               \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_MEMORY_NULL_POINTER, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_GE_FAIL_MSG(a, b, msg)                                 \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE, msg,    \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_GE_PASS_MSG(a, b, msg)                                 \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_GE_MSG(a, b, failMsg, passMsg)                         \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE, failMsg,\
        passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LT(a, b)                                               \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_MEMORY_NULL_POINTER, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LT_FAIL_MSG(a, b, msg)                                 \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT, msg, \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LT_PASS_MSG(a, b, msg)                                 \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LT_MSG(a, b, failMsg, passMsg)                         \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT, failMsg, \
        passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LE(a, b)                                               \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_MEMORY_NULL_POINTER, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LE_FAIL_MSG(a, b, msg)                                 \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE, msg,    \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LE_PASS_MSG(a, b, msg)                                 \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LE_MSG(a, b, failMsg, passMsg)                         \
    NBP_TEST_ASSERT_PRIVATE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE, failMsg,\
        passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_TEST_ASSERT_CHAR_<operator>                                            *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_EQ(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_CHAR, char, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_EQ_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_CHAR, char, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_EQ_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_CHAR, char, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_EQ_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_CHAR, char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_NE(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_CHAR, char, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_NE_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_CHAR, char, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_NE_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_CHAR, char, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_NE_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_CHAR, char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_GT(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_CHAR, char, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_GT_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_CHAR, char, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_GT_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_CHAR, char, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_GT_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_CHAR, char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_GE(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_CHAR, char, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_GE_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_CHAR, char, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_GE_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_CHAR, char, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_GE_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_CHAR, char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_LT(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_CHAR, char, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_LT_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_CHAR, char, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_LT_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_CHAR, char, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_LT_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_CHAR, char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_LE(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_CHAR, char, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_LE_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_CHAR, char, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_LE_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_CHAR, char, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_CHAR_LE_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_CHAR, char, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_TEST_ASSERT_SHORT_<operator>                                           *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_EQ(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_SHORT, short, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_EQ_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_SHORT, short, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_EQ_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_SHORT, short, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_EQ_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_SHORT, short, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_NE(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_SHORT, short, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_NE_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_SHORT, short, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_NE_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_SHORT, short, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_NE_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_SHORT, short, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_GT(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_SHORT, short, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_GT_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_SHORT, short, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_GT_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_SHORT, short, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_GT_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_SHORT, short, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_GE(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_SHORT, short, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_GE_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_SHORT, short, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_GE_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_SHORT, short, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_GE_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_SHORT, short, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_LT(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_SHORT, short, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_LT_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_SHORT, short, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_LT_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_SHORT, short, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_LT_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_SHORT, short, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_LE(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_SHORT, short, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_LE_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_SHORT, short, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_LE_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_SHORT, short, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_SHORT_LE_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_SHORT, short, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_TEST_ASSERT_USHORT_<operator>                                          *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_EQ(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_USHORT, ushort, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_EQ_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_USHORT, ushort, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_EQ_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_USHORT, ushort, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_EQ_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_USHORT, ushort, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_NE(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_USHORT, ushort, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_NE_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_USHORT, ushort, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_NE_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_USHORT, ushort, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_NE_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_USHORT, ushort, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_GT(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_USHORT, ushort, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_GT_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_USHORT, ushort, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_GT_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_USHORT, ushort, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_GT_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_USHORT, ushort, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_GE(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_USHORT, ushort, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_GE_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_USHORT, ushort, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_GE_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_USHORT, ushort, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_GE_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_USHORT, ushort, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_LT(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_USHORT, ushort, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_LT_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_USHORT, ushort, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_LT_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_USHORT, ushort, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_LT_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_USHORT, ushort, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_LE(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_USHORT, ushort, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_LE_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_USHORT, ushort, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_LE_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_USHORT, ushort, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_USHORT_LE_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_USHORT, ushort, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_TEST_ASSERT_INT_<operator>                                             *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_EQ(a, b)                                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_INT, int, NBP_MEMORY_NULL_POINTER,                    \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_EQ_FAIL_MSG(a, b, msg)                             \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_INT, int, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_EQ_PASS_MSG(a, b, msg)                             \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_INT, int, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_EQ_MSG(a, b, failMsg, passMsg)                     \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_INT, int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_NE(a, b)                                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_INT, int, NBP_MEMORY_NULL_POINTER,                    \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_NE_FAIL_MSG(a, b, msg)                             \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_INT, int, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_NE_PASS_MSG(a, b, msg)                             \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_INT, int, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_NE_MSG(a, b, failMsg, passMsg)                     \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_INT, int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_GT(a, b)                                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_INT, int, NBP_MEMORY_NULL_POINTER,                    \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_GT_FAIL_MSG(a, b, msg)                             \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_INT, int, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_GT_PASS_MSG(a, b, msg)                             \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_INT, int, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_GT_MSG(a, b, failMsg, passMsg)                     \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_INT, int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_GE(a, b)                                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_INT, int, NBP_MEMORY_NULL_POINTER,                    \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_GE_FAIL_MSG(a, b, msg)                             \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_INT, int, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_GE_PASS_MSG(a, b, msg)                             \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_INT, int, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_GE_MSG(a, b, failMsg, passMsg)                     \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_INT, int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_LT(a, b)                                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_INT, int, NBP_MEMORY_NULL_POINTER,                    \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_LT_FAIL_MSG(a, b, msg)                             \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_INT, int, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_LT_PASS_MSG(a, b, msg)                             \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_INT, int, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_LT_MSG(a, b, failMsg, passMsg)                     \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_INT, int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_LE(a, b)                                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_INT, int, NBP_MEMORY_NULL_POINTER,                    \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_LE_FAIL_MSG(a, b, msg)                             \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_INT, int, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_LE_PASS_MSG(a, b, msg)                             \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_INT, int, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_INT_LE_MSG(a, b, failMsg, passMsg)                     \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_INT, int, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_TEST_ASSERT_UINT_<operator>                                            *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_EQ(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_UINT, uint, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_EQ_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_UINT, uint, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_EQ_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_UINT, uint, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_EQ_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_UINT, uint, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_NE(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_UINT, uint, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_NE_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_UINT, uint, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_NE_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_UINT, uint, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_NE_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_UINT, uint, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_GT(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_UINT, uint, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_GT_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_UINT, uint, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_GT_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_UINT, uint, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_GT_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_UINT, uint, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_GE(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_UINT, uint, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_GE_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_UINT, uint, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_GE_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_UINT, uint, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_GE_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_UINT, uint, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_LT(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_UINT, uint, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_LT_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_UINT, uint, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_LT_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_UINT, uint, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_LT_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_UINT, uint, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_LE(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_UINT, uint, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_LE_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_UINT, uint, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_LE_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_UINT, uint, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_UINT_LE_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_UINT, uint, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_TEST_ASSERT_LONG_<operator>                                            *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_EQ(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_LONG, long, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_EQ_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_LONG, long, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_EQ_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_LONG, long, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_EQ_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_LONG, long, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_NE(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_LONG, long, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_NE_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_LONG, long, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_NE_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_LONG, long, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_NE_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_LONG, long, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_GT(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_LONG, long, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_GT_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_LONG, long, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_GT_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_LONG, long, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_GT_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_LONG, long, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_GE(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_LONG, long, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_GE_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_LONG, long, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_GE_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_LONG, long, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_GE_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_LONG, long, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_LT(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_LONG, long, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_LT_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_LONG, long, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_LT_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_LONG, long, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_LT_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_LONG, long, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_LE(a, b)                                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_LONG, long, NBP_MEMORY_NULL_POINTER,                  \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_LE_FAIL_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_LONG, long, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_LE_PASS_MSG(a, b, msg)                            \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_LONG, long, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LONG_LE_MSG(a, b, failMsg, passMsg)                    \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_LONG, long, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_TEST_ASSERT_ULONG_<operator>                                           *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_EQ(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_ULONG, ulong, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_EQ_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_ULONG, ulong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_EQ_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_ULONG, ulong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_EQ_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_ULONG, ulong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_NE(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_ULONG, ulong, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_NE_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_ULONG, ulong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_NE_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_ULONG, ulong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_NE_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_ULONG, ulong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_GT(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_ULONG, ulong, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_GT_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_ULONG, ulong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_GT_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_ULONG, ulong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_GT_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_ULONG, ulong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_GE(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_ULONG, ulong, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_GE_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_ULONG, ulong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_GE_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_ULONG, ulong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_GE_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_ULONG, ulong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_LT(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_ULONG, ulong, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_LT_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_ULONG, ulong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_LT_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_ULONG, ulong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_LT_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_ULONG, ulong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_LE(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_ULONG, ulong, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_LE_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_ULONG, ulong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_LE_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_ULONG, ulong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULONG_LE_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_ULONG, ulong, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_TEST_ASSERT_LLONG_<operator>                                           *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_EQ(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_LLONG, llong, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_EQ_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_LLONG, llong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_EQ_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_LLONG, llong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_EQ_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_LLONG, llong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_NE(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_LLONG, llong, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_NE_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_LLONG, llong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_NE_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_LLONG, llong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_NE_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_LLONG, llong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_GT(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_LLONG, llong, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_GT_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_LLONG, llong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_GT_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_LLONG, llong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_GT_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_LLONG, llong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_GE(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_LLONG, llong, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_GE_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_LLONG, llong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_GE_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_LLONG, llong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_GE_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_LLONG, llong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_LT(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_LLONG, llong, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_LT_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_LLONG, llong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_LT_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_LLONG, llong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_LT_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_LLONG, llong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_LE(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_LLONG, llong, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_LE_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_LLONG, llong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_LE_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_LLONG, llong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LLONG_LE_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_LLONG, llong, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_TEST_ASSERT_ULLONG_<operator>                                          *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_EQ(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_ULLONG, ullong, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_EQ_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_ULLONG, ullong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_EQ_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_ULLONG, ullong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_EQ_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_ULLONG, ullong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_NE(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_ULLONG, ullong, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_NE_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_ULLONG, ullong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_NE_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_ULLONG, ullong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_NE_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_ULLONG, ullong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_GT(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_ULLONG, ullong, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_GT_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_ULLONG, ullong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_GT_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_ULLONG, ullong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_GT_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_ULLONG, ullong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_GE(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_ULLONG, ullong, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_GE_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_ULLONG, ullong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_GE_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_ULLONG, ullong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_GE_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_ULLONG, ullong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_LT(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_ULLONG, ullong, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_LT_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_ULLONG, ullong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_LT_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_ULLONG, ullong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_LT_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_ULLONG, ullong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_LE(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_ULLONG, ullong, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_LE_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_ULLONG, ullong, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_LE_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_ULLONG, ullong, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_ULLONG_LE_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_ULLONG, ullong, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_TEST_ASSERT_FLOAT_<operator>                                           *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_EQ(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_FLOAT, float, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_EQ_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_FLOAT, float, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_EQ_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_FLOAT, float, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_EQ_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_FLOAT, float, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_NE(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_FLOAT, float, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_NE_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_FLOAT, float, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_NE_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_FLOAT, float, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_NE_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_FLOAT, float, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_GT(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_FLOAT, float, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_GT_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_FLOAT, float, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_GT_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_FLOAT, float, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_GT_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_FLOAT, float, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_GE(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_FLOAT, float, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_GE_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_FLOAT, float, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_GE_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_FLOAT, float, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_GE_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_FLOAT, float, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_LT(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_FLOAT, float, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_LT_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_FLOAT, float, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_LT_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_FLOAT, float, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_LT_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_FLOAT, float, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_LE(a, b)                                         \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_FLOAT, float, NBP_MEMORY_NULL_POINTER,                \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_LE_FAIL_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_FLOAT, float, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_LE_PASS_MSG(a, b, msg)                           \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_FLOAT, float, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_FLOAT_LE_MSG(a, b, failMsg, passMsg)                   \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_FLOAT, float, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_TEST_ASSERT_DOUBLE_<operator>                                          *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_EQ(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_DOUBLE, double, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_EQ_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_DOUBLE, double, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_EQ_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_DOUBLE, double, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_EQ_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,    \
        NBP_PRINTER_TYPE_DOUBLE, double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_NE(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_DOUBLE, double, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_NE_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_DOUBLE, double, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_NE_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_DOUBLE, double, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_NE_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,    \
        NBP_PRINTER_TYPE_DOUBLE, double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_GT(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_DOUBLE, double, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_GT_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_DOUBLE, double, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_GT_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_DOUBLE, double, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_GT_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,     \
        NBP_PRINTER_TYPE_DOUBLE, double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_GE(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_DOUBLE, double, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_GE_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_DOUBLE, double, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_GE_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_DOUBLE, double, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_GE_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,    \
        NBP_PRINTER_TYPE_DOUBLE, double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_LT(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_DOUBLE, double, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_LT_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_DOUBLE, double, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_LT_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_DOUBLE, double, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_LT_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,     \
        NBP_PRINTER_TYPE_DOUBLE, double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_LE(a, b)                                        \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_DOUBLE, double, NBP_MEMORY_NULL_POINTER,              \
        NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_LE_FAIL_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_DOUBLE, double, msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_LE_PASS_MSG(a, b, msg)                          \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_DOUBLE, double, NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_DOUBLE_LE_MSG(a, b, failMsg, passMsg)                  \
    NBP_TEST_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,    \
        NBP_PRINTER_TYPE_DOUBLE, double, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_TEST_ASSERT_LDOUBLE_<operator>                                         *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_EQ(a, b)                                       \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ, \
        NBP_MEMORY_NULL_POINTER, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_EQ_FAIL_MSG(a, b, msg)                         \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ, \
        msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_EQ_PASS_MSG(a, b, msg)                         \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ, \
        NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_EQ_MSG(a, b, failMsg, passMsg)                 \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ, \
        failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_NE(a, b)                                       \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE, \
        NBP_MEMORY_NULL_POINTER, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_NE_FAIL_MSG(a, b, msg)                         \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE, \
        msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_NE_PASS_MSG(a, b, msg)                         \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE, \
        NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_NE_MSG(a, b, failMsg, passMsg)                 \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE, \
        failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_GT(a, b)                                       \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,  \
        NBP_MEMORY_NULL_POINTER, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_GT_FAIL_MSG(a, b, msg)                         \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,  \
        msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_GT_PASS_MSG(a, b, msg)                         \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,  \
        NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_GT_MSG(a, b, failMsg, passMsg)                 \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,  \
        failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_GE(a, b)                                       \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE, \
        NBP_MEMORY_NULL_POINTER, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_GE_FAIL_MSG(a, b, msg)                         \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE, \
        msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_GE_PASS_MSG(a, b, msg)                         \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE, \
        NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_GE_MSG(a, b, failMsg, passMsg)                 \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE, \
        failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_LT(a, b)                                       \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,  \
        NBP_MEMORY_NULL_POINTER, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_LT_FAIL_MSG(a, b, msg)                         \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,  \
        msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_LT_PASS_MSG(a, b, msg)                         \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,  \
        NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_LT_MSG(a, b, failMsg, passMsg)                 \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,  \
        failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_LE(a, b)                                       \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE, \
        NBP_MEMORY_NULL_POINTER, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_LE_FAIL_MSG(a, b, msg)                         \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE, \
        msg, NBP_MEMORY_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_LE_PASS_MSG(a, b, msg)                         \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE, \
        NBP_MEMORY_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT_LDOUBLE_LE_MSG(a, b, failMsg, passMsg)                 \
    NBP_TEST_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE, \
        failMsg, passMsg)

#endif // end if NBP_PRIVATE_API_TEST_ASSERT_H
