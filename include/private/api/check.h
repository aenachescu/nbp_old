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

#ifndef NBP_PRIVATE_API_CHECK_H
#define NBP_PRIVATE_API_CHECK_H

#define NBP_PRIVATE_CHECK_BASE(cond, failMsg, passMsg)                         \
    if (cond) {                                                                \
        test->passedChecks++;                                                  \
        nbp_notify_printer_check_result(                                       \
            test,                                                              \
            #cond,                                                             \
            1,                                                                 \
            __LINE__,                                                          \
            0x0,                                                               \
            passMsg                                                            \
        );                                                                     \
    } else {                                                                   \
        test->failedChecks++;                                                  \
        nbp_notify_printer_check_result(                                       \
            test,                                                              \
            #cond,                                                             \
            0,                                                                 \
            __LINE__,                                                          \
            failMsg,                                                           \
            0x0                                                                \
        );                                                                     \
    }

#define NBP_PRIVATE_CHECK_OP_BASE(a, b, op, printerOp, failMsg, passMsg)       \
    if (a op b) {                                                              \
        test->passedChecks++;                                                  \
        nbp_notify_printer_check_op_result(                                    \
            test,                                                              \
            #a,                                                                \
            #b,                                                                \
            printerOp,                                                         \
            1,                                                                 \
            __LINE__,                                                          \
            0x0,                                                               \
            passMsg                                                            \
        );                                                                     \
    } else {                                                                   \
        test->failedChecks++;                                                  \
        nbp_notify_printer_check_op_result(                                    \
            test,                                                              \
            #a,                                                                \
            #b,                                                                \
            printerOp,                                                         \
            0,                                                                 \
            __LINE__,                                                          \
            failMsg,                                                           \
            0x0                                                                \
        );                                                                     \
    }

#define NBP_PRIVATE_NOTIFY_PRINTER_CHECK_TYPE_OP(type)                         \
    NBP_PRIVATE_PP_CONCAT(                                                     \
        NBP_PRIVATE_PP_CONCAT(nbp_notify_printer_check_, type),                \
        _op_result                                                             \
    )

#define NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, op, printerOp, type, typeStr,     \
    failMsg, passMsg)                                                          \
    do {                                                                       \
        type tmpA = a, tmpB = b;                                               \
        if (tmpA op tmpB) {                                                    \
            test->passedChecks++;                                              \
            NBP_PRIVATE_NOTIFY_PRINTER_CHECK_TYPE_OP(typeStr)(                 \
                test,                                                          \
                tmpA,                                                          \
                tmpB,                                                          \
                printerOp,                                                     \
                1,                                                             \
                __LINE__,                                                      \
                0x0,                                                           \
                passMsg                                                        \
            );                                                                 \
        } else {                                                               \
            test->failedChecks++;                                              \
            NBP_PRIVATE_NOTIFY_PRINTER_CHECK_TYPE_OP(typeStr)(                 \
                test,                                                          \
                tmpA,                                                          \
                tmpB,                                                          \
                printerOp,                                                     \
                0,                                                             \
                __LINE__,                                                      \
                failMsg,                                                       \
                0x0                                                            \
            );                                                                 \
        }                                                                      \
    } while (0);

/*
 * TODO: add docs
 */
#define NBP_CHECK(cond)                                                        \
    NBP_PRIVATE_CHECK_BASE(cond, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_FAIL_MSG(cond, msg)                                          \
    NBP_PRIVATE_CHECK_BASE(cond, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_PASS_MSG(cond, msg)                                          \
    NBP_PRIVATE_CHECK_BASE(cond, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_MSG(cond, failMsg, passMsg)                                  \
    NBP_PRIVATE_CHECK_BASE(cond, failMsg, passMsg)

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
#define NBP_CHECK_EQ(a, b)                                                     \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_EQ_FAIL_MSG(a, b, msg)                                       \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_EQ_PASS_MSG(a, b, msg)                                       \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_EQ_MSG(a, b, failMsg, passMsg)                               \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ, failMsg,      \
        passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_NE(a, b)                                                     \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_NE_FAIL_MSG(a, b, msg)                                       \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_NE_PASS_MSG(a, b, msg)                                       \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_NE_MSG(a, b, failMsg, passMsg)                               \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE, failMsg,      \
        passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_GT(a, b)                                                     \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_GT_FAIL_MSG(a, b, msg)                                       \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_GT_PASS_MSG(a, b, msg)                                       \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_GT_MSG(a, b, failMsg, passMsg)                               \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT, failMsg,       \
        passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_GE(a, b)                                                     \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_GE_FAIL_MSG(a, b, msg)                                       \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_GE_PASS_MSG(a, b, msg)                                       \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_GE_MSG(a, b, failMsg, passMsg)                               \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE, failMsg,      \
        passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LT(a, b)                                                     \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LT_FAIL_MSG(a, b, msg)                                       \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LT_PASS_MSG(a, b, msg)                                       \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LT_MSG(a, b, failMsg, passMsg)                               \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT, failMsg,       \
        passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LE(a, b)                                                     \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LE_FAIL_MSG(a, b, msg)                                       \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LE_PASS_MSG(a, b, msg)                                       \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LE_MSG(a, b, failMsg, passMsg)                               \
    NBP_PRIVATE_CHECK_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE, failMsg,      \
        passMsg)

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
#define NBP_CHECK_CHAR_EQ(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        char, char, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_EQ_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        char, char, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_EQ_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        char, char, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_EQ_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        char, char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_NE(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        char, char, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_NE_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        char, char, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_NE_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        char, char, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_NE_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        char, char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GT(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        char, char, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GT_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        char, char, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GT_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        char, char, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GT_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        char, char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GE(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        char, char, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GE_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        char, char, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GE_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        char, char, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GE_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        char, char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LT(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        char, char, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LT_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        char, char, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LT_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        char, char, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LT_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        char, char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LE(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        char, char, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LE_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        char, char, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LE_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        char, char, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LE_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        char, char, failMsg, passMsg)

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
#define NBP_CHECK_SHORT_EQ(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        short int, short, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_EQ_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        short int, short, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_EQ_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        short int, short, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_EQ_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        short int, short, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_NE(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        short int, short, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_NE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        short int, short, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_NE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        short int, short, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_NE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        short int, short, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_GT(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        short int, short, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_GT_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        short int, short, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_GT_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        short int, short, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_GT_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        short int, short, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_GE(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        short int, short, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_GE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        short int, short, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_GE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        short int, short, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_GE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        short int, short, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_LT(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        short int, short, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_LT_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        short int, short, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_LT_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        short int, short, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_LT_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        short int, short, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_LE(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        short int, short, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_LE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        short int, short, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_LE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        short int, short, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_SHORT_LE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        short int, short, failMsg, passMsg)

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
#define NBP_CHECK_USHORT_EQ(a, b)                                              \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        unsigned short int, ushort, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_EQ_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        unsigned short int, ushort, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_EQ_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        unsigned short int, ushort, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_EQ_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        unsigned short int, ushort, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_NE(a, b)                                              \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        unsigned short int, ushort, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_NE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        unsigned short int, ushort, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_NE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        unsigned short int, ushort, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_NE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        unsigned short int, ushort, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_GT(a, b)                                              \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        unsigned short int, ushort, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_GT_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        unsigned short int, ushort, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_GT_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        unsigned short int, ushort, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_GT_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        unsigned short int, ushort, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_GE(a, b)                                              \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        unsigned short int, ushort, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_GE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        unsigned short int, ushort, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_GE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        unsigned short int, ushort, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_GE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        unsigned short int, ushort, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_LT(a, b)                                              \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        unsigned short int, ushort, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_LT_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        unsigned short int, ushort, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_LT_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        unsigned short int, ushort, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_LT_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        unsigned short int, ushort, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_LE(a, b)                                              \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        unsigned short int, ushort, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_LE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        unsigned short int, ushort, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_LE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        unsigned short int, ushort, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_USHORT_LE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        unsigned short int, ushort, failMsg, passMsg)

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
#define NBP_CHECK_INT_EQ(a, b)                                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        int, int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_EQ_FAIL_MSG(a, b, msg)                                   \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        int, int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_EQ_PASS_MSG(a, b, msg)                                   \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        int, int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_EQ_MSG(a, b, failMsg, passMsg)                           \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        int, int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_NE(a, b)                                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        int, int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_NE_FAIL_MSG(a, b, msg)                                   \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        int, int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_NE_PASS_MSG(a, b, msg)                                   \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        int, int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_NE_MSG(a, b, failMsg, passMsg)                           \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        int, int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_GT(a, b)                                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        int, int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_GT_FAIL_MSG(a, b, msg)                                   \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        int, int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_GT_PASS_MSG(a, b, msg)                                   \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        int, int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_GT_MSG(a, b, failMsg, passMsg)                           \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        int, int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_GE(a, b)                                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        int, int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_GE_FAIL_MSG(a, b, msg)                                   \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        int, int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_GE_PASS_MSG(a, b, msg)                                   \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        int, int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_GE_MSG(a, b, failMsg, passMsg)                           \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        int, int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_LT(a, b)                                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        int, int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_LT_FAIL_MSG(a, b, msg)                                   \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        int, int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_LT_PASS_MSG(a, b, msg)                                   \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        int, int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_LT_MSG(a, b, failMsg, passMsg)                           \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        int, int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_LE(a, b)                                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        int, int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_LE_FAIL_MSG(a, b, msg)                                   \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        int, int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_LE_PASS_MSG(a, b, msg)                                   \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        int, int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_INT_LE_MSG(a, b, failMsg, passMsg)                           \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        int, int, failMsg, passMsg)

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
#define NBP_CHECK_UINT_EQ(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        unsigned int, uint, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_EQ_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        unsigned int, uint, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_EQ_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        unsigned int, uint, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_EQ_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        unsigned int, uint, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_NE(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        unsigned int, uint, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_NE_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        unsigned int, uint, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_NE_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        unsigned int, uint, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_NE_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        unsigned int, uint, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_GT(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        unsigned int, uint, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_GT_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        unsigned int, uint, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_GT_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        unsigned int, uint, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_GT_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        unsigned int, uint, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_GE(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        unsigned int, uint, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_GE_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        unsigned int, uint, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_GE_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        unsigned int, uint, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_GE_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        unsigned int, uint, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_LT(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        unsigned int, uint, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_LT_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        unsigned int, uint, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_LT_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        unsigned int, uint, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_LT_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        unsigned int, uint, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_LE(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        unsigned int, uint, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_LE_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        unsigned int, uint, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_LE_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        unsigned int, uint, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_UINT_LE_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        unsigned int, uint, failMsg, passMsg)

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
#define NBP_CHECK_LONG_EQ(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        long int, long, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_EQ_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        long int, long, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_EQ_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        long int, long, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_EQ_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        long int, long, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_NE(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        long int, long, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_NE_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        long int, long, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_NE_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        long int, long, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_NE_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        long int, long, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_GT(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        long int, long, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_GT_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        long int, long, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_GT_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        long int, long, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_GT_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        long int, long, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_GE(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        long int, long, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_GE_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        long int, long, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_GE_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        long int, long, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_GE_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        long int, long, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_LT(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        long int, long, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_LT_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        long int, long, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_LT_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        long int, long, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_LT_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        long int, long, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_LE(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        long int, long, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_LE_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        long int, long, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_LE_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        long int, long, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LONG_LE_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        long int, long, failMsg, passMsg)

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
#define NBP_CHECK_ULONG_EQ(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        unsigned long int, ulong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_EQ_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        unsigned long int, ulong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_EQ_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        unsigned long int, ulong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_EQ_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        unsigned long int, ulong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_NE(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        unsigned long int, ulong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_NE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        unsigned long int, ulong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_NE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        unsigned long int, ulong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_NE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        unsigned long int, ulong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_GT(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        unsigned long int, ulong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_GT_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        unsigned long int, ulong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_GT_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        unsigned long int, ulong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_GT_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        unsigned long int, ulong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_GE(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        unsigned long int, ulong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_GE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        unsigned long int, ulong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_GE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        unsigned long int, ulong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_GE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        unsigned long int, ulong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_LT(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        unsigned long int, ulong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_LT_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        unsigned long int, ulong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_LT_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        unsigned long int, ulong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_LT_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        unsigned long int, ulong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_LE(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        unsigned long int, ulong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_LE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        unsigned long int, ulong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_LE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        unsigned long int, ulong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULONG_LE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        unsigned long int, ulong, failMsg, passMsg)

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
#define NBP_CHECK_LLONG_EQ(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        long long int, llong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_EQ_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        long long int, llong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_EQ_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        long long int, llong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_EQ_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        long long int, llong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_NE(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        long long int, llong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_NE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        long long int, llong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_NE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        long long int, llong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_NE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        long long int, llong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_GT(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        long long int, llong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_GT_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        long long int, llong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_GT_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        long long int, llong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_GT_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        long long int, llong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_GE(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        long long int, llong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_GE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        long long int, llong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_GE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        long long int, llong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_GE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        long long int, llong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_LT(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        long long int, llong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_LT_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        long long int, llong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_LT_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        long long int, llong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_LT_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        long long int, llong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_LE(a, b)                                               \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        long long int, llong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_LE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        long long int, llong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_LE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        long long int, llong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_LLONG_LE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        long long int, llong, failMsg, passMsg)

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
#define NBP_CHECK_ULLONG_EQ(a, b)                                              \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        unsigned long long int, ullong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_EQ_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        unsigned long long int, ullong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_EQ_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        unsigned long long int, ullong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_EQ_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,          \
        unsigned long long int, ullong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_NE(a, b)                                              \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        unsigned long long int, ullong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_NE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        unsigned long long int, ullong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_NE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        unsigned long long int, ullong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_NE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,          \
        unsigned long long int, ullong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_GT(a, b)                                              \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        unsigned long long int, ullong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_GT_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        unsigned long long int, ullong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_GT_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        unsigned long long int, ullong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_GT_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,           \
        unsigned long long int, ullong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_GE(a, b)                                              \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        unsigned long long int, ullong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_GE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        unsigned long long int, ullong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_GE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        unsigned long long int, ullong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_GE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,          \
        unsigned long long int, ullong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_LT(a, b)                                              \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        unsigned long long int, ullong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_LT_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        unsigned long long int, ullong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_LT_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        unsigned long long int, ullong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_LT_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,           \
        unsigned long long int, ullong, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_LE(a, b)                                              \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        unsigned long long int, ullong, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_LE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        unsigned long long int, ullong, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_LE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        unsigned long long int, ullong, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_ULLONG_LE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,          \
        unsigned long long int, ullong, failMsg, passMsg)

#endif // end if NBP_PRIVATE_API_CHECK_H