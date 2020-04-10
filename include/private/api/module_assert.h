/*
No Bugs in Production (NBP)
Copyright (C) 2019-present Alin Enachescu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NBP_PRIVATE_API_MODULE_ASSERT_H
#define NBP_PRIVATE_API_MODULE_ASSERT_H

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_STATUS_PASSED 1

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_STATUS_FAILED 0

#define NBP_PRIVATE_MODULE_ASSERT_BASE(cond, failMsg, passMsg)                 \
    if (cond) {                                                                \
        NBP_ATOMIC_UINT_ADD_AND_FETCH(&test->moduleAsserts.numPassed, 1);      \
        nbp_notify_printer_module_assert_result(                               \
            test,                                                              \
            #cond,                                                             \
            NBP_MODULE_ASSERT_STATUS_PASSED,                                   \
            __LINE__,                                                          \
            NBP_NULL_POINTER,                                                  \
            passMsg                                                            \
        );                                                                     \
    } else {                                                                   \
        NBP_ATOMIC_UINT_ADD_AND_FETCH(&test->moduleAsserts.numFailed, 1);      \
        nbp_notify_printer_module_assert_result(                               \
            test,                                                              \
            #cond,                                                             \
            NBP_MODULE_ASSERT_STATUS_FAILED,                                   \
            __LINE__,                                                          \
            failMsg,                                                           \
            NBP_NULL_POINTER                                                   \
        );                                                                     \
        return;                                                                \
    }

#define NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, op, printerOp, failMsg,        \
    passMsg)                                                                   \
    if (a op b) {                                                              \
        NBP_ATOMIC_UINT_ADD_AND_FETCH(&test->moduleAsserts.numPassed, 1);      \
        nbp_notify_printer_module_assert_op_result(                            \
            test,                                                              \
            #a,                                                                \
            #b,                                                                \
            printerOp,                                                         \
            NBP_MODULE_ASSERT_STATUS_PASSED,                                   \
            __LINE__,                                                          \
            NBP_NULL_POINTER,                                                  \
            passMsg                                                            \
        );                                                                     \
    } else {                                                                   \
        NBP_ATOMIC_UINT_ADD_AND_FETCH(&test->moduleAsserts.numFailed, 1);      \
        nbp_notify_printer_module_assert_op_result(                            \
            test,                                                              \
            #a,                                                                \
            #b,                                                                \
            printerOp,                                                         \
            NBP_MODULE_ASSERT_STATUS_FAILED,                                   \
            __LINE__,                                                          \
            failMsg,                                                           \
            NBP_NULL_POINTER                                                   \
        );                                                                     \
        return;                                                                \
    }

#define NBP_PRIVATE_NOTIFY_PRINTER_MODULE_ASSERT_TYPE_OP(type)                 \
    NBP_PRIVATE_PP_CONCAT(                                                     \
        NBP_PRIVATE_PP_CONCAT(nbp_notify_printer_module_assert_, type),        \
        _op_result                                                             \
    )

#define NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, op, printerOp, type,      \
    typeStr, failMsg, passMsg)                                                 \
    do {                                                                       \
        type tmpA = a, tmpB = b;                                               \
        if (tmpA op tmpB) {                                                    \
            NBP_ATOMIC_UINT_ADD_AND_FETCH(&test->moduleAsserts.numPassed, 1);  \
            NBP_PRIVATE_NOTIFY_PRINTER_MODULE_ASSERT_TYPE_OP(typeStr)(         \
                test,                                                          \
                tmpA,                                                          \
                tmpB,                                                          \
                printerOp,                                                     \
                NBP_MODULE_ASSERT_STATUS_PASSED,                               \
                __LINE__,                                                      \
                NBP_NULL_POINTER,                                              \
                passMsg                                                        \
            );                                                                 \
        } else {                                                               \
            NBP_ATOMIC_UINT_ADD_AND_FETCH(&test->moduleAsserts.numFailed, 1);  \
            NBP_PRIVATE_NOTIFY_PRINTER_MODULE_ASSERT_TYPE_OP(typeStr)(         \
                test,                                                          \
                tmpA,                                                          \
                tmpB,                                                          \
                printerOp,                                                     \
                NBP_MODULE_ASSERT_STATUS_FAILED,                               \
                __LINE__,                                                      \
                failMsg,                                                       \
                NBP_NULL_POINTER                                               \
            );                                                                 \
            return;                                                            \
        }                                                                      \
    } while (0);


/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT(cond)                                                \
    NBP_PRIVATE_MODULE_ASSERT_BASE(cond, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FAIL_MSG(cond, msg)                                  \
    NBP_PRIVATE_MODULE_ASSERT_BASE(cond, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_PASS_MSG(cond, msg)                                  \
    NBP_PRIVATE_MODULE_ASSERT_BASE(cond, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_MSG(cond, failMsg, passMsg)                          \
    NBP_PRIVATE_MODULE_ASSERT_BASE(cond, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_MODULE_ASSERT_<operator>                                               *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_EQ(a, b)                                             \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,       \
        NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_EQ_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,       \
        msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_EQ_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,       \
        NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_EQ_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,       \
        failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_NE(a, b)                                             \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,       \
        NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_NE_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,       \
        msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_NE_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,       \
        NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_NE_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,       \
        failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_GT(a, b)                                             \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,        \
        NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_GT_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,        \
        msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_GT_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,        \
        NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_GT_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,        \
        failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_GE(a, b)                                             \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,       \
        NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_GE_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,       \
        msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_GE_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,       \
        NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_GE_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,       \
        failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LT(a, b)                                             \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,        \
        NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LT_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,        \
        msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LT_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,        \
        NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LT_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,        \
        failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LE(a, b)                                             \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,       \
        NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LE_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,       \
        msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LE_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,       \
        NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LE_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_MODULE_ASSERT_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,       \
        failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_MODULE_ASSERT_CHAR_<operator>                                          *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_EQ(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        char, char, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_EQ_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        char, char, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_EQ_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        char, char, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_EQ_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        char, char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_NE(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        char, char, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_NE_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        char, char, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_NE_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        char, char, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_NE_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        char, char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_GT(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        char, char, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_GT_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        char, char, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_GT_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        char, char, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_GT_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        char, char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_GE(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        char, char, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_GE_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        char, char, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_GE_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        char, char, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_GE_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        char, char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_LT(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        char, char, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_LT_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        char, char, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_LT_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        char, char, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_LT_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        char, char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_LE(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        char, char, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_LE_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        char, char, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_LE_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        char, char, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_CHAR_LE_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        char, char, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_MODULE_ASSERT_SHORT_<operator>                                         *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_EQ(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        short int, short, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_EQ_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        short int, short, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_EQ_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        short int, short, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_EQ_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        short int, short, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_NE(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        short int, short, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_NE_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        short int, short, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_NE_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        short int, short, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_NE_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        short int, short, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_GT(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        short int, short, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_GT_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        short int, short, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_GT_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        short int, short, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_GT_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        short int, short, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_GE(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        short int, short, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_GE_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        short int, short, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_GE_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        short int, short, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_GE_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        short int, short, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_LT(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        short int, short, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_LT_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        short int, short, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_LT_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        short int, short, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_LT_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        short int, short, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_LE(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        short int, short, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_LE_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        short int, short, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_LE_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        short int, short, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_SHORT_LE_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        short int, short, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_MODULE_ASSERT_USHORT_<operator>                                        *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_EQ(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        unsigned short int, ushort, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_EQ_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        unsigned short int, ushort, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_EQ_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        unsigned short int, ushort, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_EQ_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        unsigned short int, ushort, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_NE(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        unsigned short int, ushort, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_NE_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        unsigned short int, ushort, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_NE_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        unsigned short int, ushort, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_NE_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        unsigned short int, ushort, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_GT(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        unsigned short int, ushort, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_GT_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        unsigned short int, ushort, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_GT_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        unsigned short int, ushort, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_GT_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        unsigned short int, ushort, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_GE(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        unsigned short int, ushort, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_GE_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        unsigned short int, ushort, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_GE_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        unsigned short int, ushort, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_GE_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        unsigned short int, ushort, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_LT(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        unsigned short int, ushort, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_LT_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        unsigned short int, ushort, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_LT_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        unsigned short int, ushort, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_LT_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        unsigned short int, ushort, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_LE(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        unsigned short int, ushort, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_LE_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        unsigned short int, ushort, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_LE_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        unsigned short int, ushort, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_USHORT_LE_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        unsigned short int, ushort, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_MODULE_ASSERT_INT_<operator>                                           *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_EQ(a, b)                                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        int, int, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_EQ_FAIL_MSG(a, b, msg)                           \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        int, int, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_EQ_PASS_MSG(a, b, msg)                           \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        int, int, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_EQ_MSG(a, b, failMsg, passMsg)                   \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        int, int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_NE(a, b)                                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        int, int, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_NE_FAIL_MSG(a, b, msg)                           \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        int, int, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_NE_PASS_MSG(a, b, msg)                           \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        int, int, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_NE_MSG(a, b, failMsg, passMsg)                   \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        int, int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_GT(a, b)                                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        int, int, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_GT_FAIL_MSG(a, b, msg)                           \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        int, int, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_GT_PASS_MSG(a, b, msg)                           \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        int, int, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_GT_MSG(a, b, failMsg, passMsg)                   \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        int, int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_GE(a, b)                                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        int, int, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_GE_FAIL_MSG(a, b, msg)                           \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        int, int, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_GE_PASS_MSG(a, b, msg)                           \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        int, int, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_GE_MSG(a, b, failMsg, passMsg)                   \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        int, int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_LT(a, b)                                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        int, int, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_LT_FAIL_MSG(a, b, msg)                           \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        int, int, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_LT_PASS_MSG(a, b, msg)                           \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        int, int, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_LT_MSG(a, b, failMsg, passMsg)                   \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        int, int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_LE(a, b)                                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        int, int, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_LE_FAIL_MSG(a, b, msg)                           \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        int, int, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_LE_PASS_MSG(a, b, msg)                           \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        int, int, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_INT_LE_MSG(a, b, failMsg, passMsg)                   \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        int, int, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_MODULE_ASSERT_UINT_<operator>                                          *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_EQ(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        unsigned int, uint, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_EQ_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        unsigned int, uint, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_EQ_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        unsigned int, uint, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_EQ_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        unsigned int, uint, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_NE(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        unsigned int, uint, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_NE_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        unsigned int, uint, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_NE_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        unsigned int, uint, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_NE_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        unsigned int, uint, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_GT(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        unsigned int, uint, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_GT_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        unsigned int, uint, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_GT_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        unsigned int, uint, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_GT_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        unsigned int, uint, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_GE(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        unsigned int, uint, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_GE_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        unsigned int, uint, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_GE_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        unsigned int, uint, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_GE_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        unsigned int, uint, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_LT(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        unsigned int, uint, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_LT_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        unsigned int, uint, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_LT_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        unsigned int, uint, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_LT_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        unsigned int, uint, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_LE(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        unsigned int, uint, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_LE_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        unsigned int, uint, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_LE_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        unsigned int, uint, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_UINT_LE_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        unsigned int, uint, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_MODULE_ASSERT_LONG_<operator>                                          *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_EQ(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        long int, long, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_EQ_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        long int, long, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_EQ_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        long int, long, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_EQ_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        long int, long, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_NE(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        long int, long, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_NE_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        long int, long, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_NE_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        long int, long, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_NE_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        long int, long, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_GT(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        long int, long, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_GT_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        long int, long, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_GT_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        long int, long, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_GT_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        long int, long, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_GE(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        long int, long, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_GE_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        long int, long, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_GE_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        long int, long, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_GE_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        long int, long, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_LT(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        long int, long, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_LT_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        long int, long, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_LT_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        long int, long, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_LT_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        long int, long, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_LE(a, b)                                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        long int, long, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_LE_FAIL_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        long int, long, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_LE_PASS_MSG(a, b, msg)                          \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        long int, long, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LONG_LE_MSG(a, b, failMsg, passMsg)                  \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        long int, long, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_MODULE_ASSERT_ULONG_<operator>                                         *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_EQ(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        unsigned long int, ulong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_EQ_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        unsigned long int, ulong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_EQ_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        unsigned long int, ulong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_EQ_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        unsigned long int, ulong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_NE(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        unsigned long int, ulong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_NE_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        unsigned long int, ulong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_NE_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        unsigned long int, ulong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_NE_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        unsigned long int, ulong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_GT(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        unsigned long int, ulong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_GT_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        unsigned long int, ulong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_GT_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        unsigned long int, ulong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_GT_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        unsigned long int, ulong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_GE(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        unsigned long int, ulong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_GE_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        unsigned long int, ulong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_GE_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        unsigned long int, ulong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_GE_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        unsigned long int, ulong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_LT(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        unsigned long int, ulong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_LT_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        unsigned long int, ulong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_LT_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        unsigned long int, ulong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_LT_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        unsigned long int, ulong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_LE(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        unsigned long int, ulong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_LE_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        unsigned long int, ulong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_LE_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        unsigned long int, ulong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULONG_LE_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        unsigned long int, ulong, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_MODULE_ASSERT_LLONG_<operator>                                         *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_EQ(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        long long int, llong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_EQ_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        long long int, llong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_EQ_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        long long int, llong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_EQ_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        long long int, llong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_NE(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        long long int, llong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_NE_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        long long int, llong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_NE_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        long long int, llong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_NE_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        long long int, llong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_GT(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        long long int, llong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_GT_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        long long int, llong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_GT_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        long long int, llong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_GT_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        long long int, llong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_GE(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        long long int, llong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_GE_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        long long int, llong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_GE_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        long long int, llong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_GE_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        long long int, llong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_LT(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        long long int, llong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_LT_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        long long int, llong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_LT_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        long long int, llong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_LT_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        long long int, llong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_LE(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        long long int, llong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_LE_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        long long int, llong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_LE_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        long long int, llong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LLONG_LE_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        long long int, llong, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_MODULE_ASSERT_ULLONG_<operator>                                        *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_EQ(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        unsigned long long int, ullong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_EQ_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        unsigned long long int, ullong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_EQ_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        unsigned long long int, ullong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_EQ_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        unsigned long long int, ullong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_NE(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        unsigned long long int, ullong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_NE_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        unsigned long long int, ullong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_NE_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        unsigned long long int, ullong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_NE_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        unsigned long long int, ullong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_GT(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        unsigned long long int, ullong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_GT_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        unsigned long long int, ullong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_GT_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        unsigned long long int, ullong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_GT_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        unsigned long long int, ullong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_GE(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        unsigned long long int, ullong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_GE_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        unsigned long long int, ullong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_GE_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        unsigned long long int, ullong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_GE_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        unsigned long long int, ullong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_LT(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        unsigned long long int, ullong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_LT_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        unsigned long long int, ullong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_LT_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        unsigned long long int, ullong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_LT_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        unsigned long long int, ullong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_LE(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        unsigned long long int, ullong, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_LE_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        unsigned long long int, ullong, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_LE_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        unsigned long long int, ullong, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_ULLONG_LE_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        unsigned long long int, ullong, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_MODULE_ASSERT_FLOAT_<operator>                                         *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_EQ(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        float, float, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_EQ_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        float, float, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_EQ_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        float, float, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_EQ_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        float, float, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_NE(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        float, float, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_NE_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        float, float, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_NE_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        float, float, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_NE_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        float, float, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_GT(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        float, float, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_GT_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        float, float, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_GT_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        float, float, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_GT_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        float, float, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_GE(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        float, float, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_GE_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        float, float, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_GE_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        float, float, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_GE_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        float, float, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_LT(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        float, float, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_LT_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        float, float, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_LT_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        float, float, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_LT_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        float, float, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_LE(a, b)                                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        float, float, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_LE_FAIL_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        float, float, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_LE_PASS_MSG(a, b, msg)                         \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        float, float, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_FLOAT_LE_MSG(a, b, failMsg, passMsg)                 \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        float, float, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_MODULE_ASSERT_DOUBLE_<operator>                                        *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_EQ(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        double, double, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_EQ_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        double, double, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_EQ_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        double, double, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_EQ_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        double, double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_NE(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        double, double, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_NE_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        double, double, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_NE_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        double, double, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_NE_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        double, double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_GT(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        double, double, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_GT_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        double, double, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_GT_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        double, double, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_GT_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        double, double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_GE(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        double, double, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_GE_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        double, double, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_GE_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        double, double, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_GE_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        double, double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_LT(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        double, double, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_LT_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        double, double, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_LT_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        double, double, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_LT_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        double, double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_LE(a, b)                                      \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        double, double, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_LE_FAIL_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        double, double, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_LE_PASS_MSG(a, b, msg)                        \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        double, double, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_DOUBLE_LE_MSG(a, b, failMsg, passMsg)                \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        double, double, failMsg, passMsg)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_MODULE_ASSERT_LDOUBLE_<operator>                                       *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_EQ(a, b)                                     \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        long double, ldouble, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_EQ_FAIL_MSG(a, b, msg)                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        long double, ldouble, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_EQ_PASS_MSG(a, b, msg)                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        long double, ldouble, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_EQ_MSG(a, b, failMsg, passMsg)               \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,  \
        long double, ldouble, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_NE(a, b)                                     \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        long double, ldouble, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_NE_FAIL_MSG(a, b, msg)                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        long double, ldouble, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_NE_PASS_MSG(a, b, msg)                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        long double, ldouble, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_NE_MSG(a, b, failMsg, passMsg)               \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,  \
        long double, ldouble, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_GT(a, b)                                     \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        long double, ldouble, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_GT_FAIL_MSG(a, b, msg)                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        long double, ldouble, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_GT_PASS_MSG(a, b, msg)                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        long double, ldouble, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_GT_MSG(a, b, failMsg, passMsg)               \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,   \
        long double, ldouble, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_GE(a, b)                                     \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        long double, ldouble, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_GE_FAIL_MSG(a, b, msg)                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        long double, ldouble, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_GE_PASS_MSG(a, b, msg)                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        long double, ldouble, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_GE_MSG(a, b, failMsg, passMsg)               \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,  \
        long double, ldouble, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_LT(a, b)                                     \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        long double, ldouble, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_LT_FAIL_MSG(a, b, msg)                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        long double, ldouble, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_LT_PASS_MSG(a, b, msg)                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        long double, ldouble, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_LT_MSG(a, b, failMsg, passMsg)               \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,   \
        long double, ldouble, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_LE(a, b)                                     \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        long double, ldouble, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_LE_FAIL_MSG(a, b, msg)                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        long double, ldouble, msg, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_LE_PASS_MSG(a, b, msg)                       \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        long double, ldouble, NBP_NULL_POINTER, msg)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT_LDOUBLE_LE_MSG(a, b, failMsg, passMsg)               \
    NBP_PRIVATE_MODULE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,  \
        long double, ldouble, failMsg, passMsg)

#endif // end if NBP_PRIVATE_API_MODULE_ASSERT_H
