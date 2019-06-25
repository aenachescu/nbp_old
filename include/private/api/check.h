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

#define NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, op, printerOp, type, failMsg,     \
    passMsg)                                                                   \
    do {                                                                       \
        type tmpA = a, tmpB = b;                                               \
        if (tmpA op tmpB) {                                                    \
            test->passedChecks++;                                              \
            NBP_PRIVATE_NOTIFY_PRINTER_CHECK_TYPE_OP(type)(                    \
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
            NBP_PRIVATE_NOTIFY_PRINTER_CHECK_TYPE_OP(type)(                    \
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
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ, char,    \
        0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_EQ_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ, char,    \
        msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_EQ_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ, char,    \
        0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_EQ_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ, char,    \
        failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_NE(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE, char,    \
        0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_NE_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE, char,    \
        msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_NE_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE, char,    \
        0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_NE_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE, char,    \
        failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GT(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT, char,    \
        0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GT_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT, char,     \
        msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GT_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT, char,     \
        0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GT_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT, char,     \
        failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GE(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE, char,    \
        0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GE_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE, char,    \
        msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GE_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE, char,    \
        0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_GE_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE, char,    \
        failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LT(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT, char,     \
        0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LT_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT, char,     \
        msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LT_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT, char,     \
        0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LT_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT, char,     \
        failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LE(a, b)                                                \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE, char,    \
        0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LE_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE, char,    \
        msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LE_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE, char,    \
        0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_CHAR_LE_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_CHECK_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE, char,    \
        failMsg, passMsg)

#endif // end if NBP_PRIVATE_API_CHECK_H
