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

#ifndef NBP_PRIVATE_API_ASSERT_H
#define NBP_PRIVATE_API_ASSERT_H

/*
 * TODO: add docs
 */
#define NBP_ASSERT_STATUS_PASSED 1

/*
 * TODO: add docs
 */
#define NBP_ASSERT_STATUS_FAILED 0

/*
 * TODO: add docs
 */
#define NBP_ASSERT(cond)                                                       \
    NBP_PRIVATE_ASSERT_BASE(cond, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FAIL_MSG(cond, msg)                                         \
    NBP_PRIVATE_ASSERT_BASE(cond, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_PASS_MSG(cond, msg)                                         \
    NBP_PRIVATE_ASSERT_BASE(cond, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_MSG(cond, failMsg, passMsg)                                 \
    NBP_PRIVATE_ASSERT_BASE(cond, failMsg, passMsg)

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
#define NBP_ASSERT_EQ(a, b)                                                    \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_EQ_FAIL_MSG(a, b, msg)                                      \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_EQ_PASS_MSG(a, b, msg)                                      \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_EQ_MSG(a, b, failMsg, passMsg)                              \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ, failMsg,     \
        passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_NE(a, b)                                                    \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_NE_FAIL_MSG(a, b, msg)                                      \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_NE_PASS_MSG(a, b, msg)                                      \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_NE_MSG(a, b, failMsg, passMsg)                              \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE, failMsg,     \
        passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_GT(a, b)                                                    \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_GT_FAIL_MSG(a, b, msg)                                      \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_GT_PASS_MSG(a, b, msg)                                      \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_GT_MSG(a, b, failMsg, passMsg)                              \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT, failMsg,      \
        passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_GE(a, b)                                                    \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_GE_FAIL_MSG(a, b, msg)                                      \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_GE_PASS_MSG(a, b, msg)                                      \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_GE_MSG(a, b, failMsg, passMsg)                              \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE, failMsg,     \
        passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LT(a, b)                                                    \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LT_FAIL_MSG(a, b, msg)                                      \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LT_PASS_MSG(a, b, msg)                                      \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LT_MSG(a, b, failMsg, passMsg)                              \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT, failMsg,      \
        passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LE(a, b)                                                    \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LE_FAIL_MSG(a, b, msg)                                      \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LE_PASS_MSG(a, b, msg)                                      \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LE_MSG(a, b, failMsg, passMsg)                              \
    NBP_PRIVATE_ASSERT_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE, failMsg,     \
        passMsg)

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
#define NBP_ASSERT_CHAR_EQ(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        char, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_EQ_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        char, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_EQ_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        char, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_EQ_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_NE(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        char, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_NE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        char, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_NE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        char, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_NE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_GT(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        char, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_GT_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        char, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_GT_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        char, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_GT_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_GE(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        char, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_GE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        char, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_GE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        char, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_GE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_LT(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        char, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_LT_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        char, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_LT_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        char, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_LT_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        char, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_LE(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        char, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_LE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        char, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_LE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        char, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_LE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        char, failMsg, passMsg)

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
#define NBP_ASSERT_SHORT_EQ(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        short int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_EQ_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        short int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_EQ_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        short int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_EQ_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        short int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_NE(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        short int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_NE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        short int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_NE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        short int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_NE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        short int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_GT(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        short int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_GT_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        short int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_GT_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        short int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_GT_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        short int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_GE(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        short int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_GE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        short int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_GE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        short int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_GE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        short int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_LT(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        short int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_LT_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        short int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_LT_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        short int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_LT_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        short int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_LE(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        short int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_LE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        short int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_LE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        short int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_LE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        short int, failMsg, passMsg)

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
#define NBP_ASSERT_USHORT_EQ(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        unsigned short int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_EQ_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        unsigned short int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_EQ_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        unsigned short int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_EQ_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        unsigned short int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_NE(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        unsigned short int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_NE_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        unsigned short int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_NE_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        unsigned short int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_NE_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        unsigned short int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_GT(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        unsigned short int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_GT_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        unsigned short int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_GT_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        unsigned short int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_GT_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        unsigned short int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_GE(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        unsigned short int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_GE_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        unsigned short int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_GE_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        unsigned short int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_GE_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        unsigned short int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_LT(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        unsigned short int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_LT_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        unsigned short int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_LT_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        unsigned short int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_LT_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        unsigned short int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_LE(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        unsigned short int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_LE_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        unsigned short int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_LE_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        unsigned short int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_LE_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        unsigned short int, failMsg, passMsg)

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
#define NBP_ASSERT_INT_EQ(a, b)                                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_EQ_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_EQ_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_EQ_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_NE(a, b)                                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_NE_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_NE_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_NE_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_GT(a, b)                                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_GT_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_GT_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_GT_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_GE(a, b)                                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_GE_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_GE_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_GE_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_LT(a, b)                                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_LT_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_LT_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_LT_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_LE(a, b)                                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_LE_FAIL_MSG(a, b, msg)                                  \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_LE_PASS_MSG(a, b, msg)                                  \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_LE_MSG(a, b, failMsg, passMsg)                          \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        int, failMsg, passMsg)

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
#define NBP_ASSERT_UINT_EQ(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        unsigned int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_EQ_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        unsigned int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_EQ_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        unsigned int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_EQ_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        unsigned int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_NE(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        unsigned int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_NE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        unsigned int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_NE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        unsigned int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_NE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        unsigned int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_GT(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        unsigned int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_GT_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        unsigned int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_GT_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        unsigned int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_GT_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        unsigned int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_GE(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        unsigned int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_GE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        unsigned int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_GE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        unsigned int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_GE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        unsigned int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_LT(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        unsigned int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_LT_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        unsigned int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_LT_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        unsigned int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_LT_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        unsigned int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_LE(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        unsigned int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_LE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        unsigned int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_LE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        unsigned int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_LE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        unsigned int, failMsg, passMsg)

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
#define NBP_ASSERT_LONG_EQ(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_EQ_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_EQ_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_EQ_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_NE(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_NE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_NE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_NE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_GT(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_GT_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_GT_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_GT_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_GE(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_GE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_GE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_GE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_LT(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_LT_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_LT_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_LT_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_LE(a, b)                                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_LE_FAIL_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_LE_PASS_MSG(a, b, msg)                                 \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_LE_MSG(a, b, failMsg, passMsg)                         \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        long int, failMsg, passMsg)

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
#define NBP_ASSERT_ULONG_EQ(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        unsigned long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_EQ_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        unsigned long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_EQ_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        unsigned long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_EQ_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        unsigned long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_NE(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        unsigned long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_NE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        unsigned long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_NE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        unsigned long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_NE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        unsigned long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_GT(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        unsigned long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_GT_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        unsigned long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_GT_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        unsigned long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_GT_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        unsigned long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_GE(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        unsigned long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_GE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        unsigned long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_GE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        unsigned long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_GE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        unsigned long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_LT(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        unsigned long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_LT_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        unsigned long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_LT_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        unsigned long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_LT_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        unsigned long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_LE(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        unsigned long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_LE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        unsigned long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_LE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        unsigned long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_LE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        unsigned long int, failMsg, passMsg)

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
#define NBP_ASSERT_LLONG_EQ(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        long long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_EQ_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        long long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_EQ_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        long long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_EQ_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        long long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_NE(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        long long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_NE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        long long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_NE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        long long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_NE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        long long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_GT(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        long long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_GT_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        long long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_GT_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        long long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_GT_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        long long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_GE(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        long long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_GE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        long long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_GE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        long long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_GE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        long long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_LT(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        long long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_LT_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        long long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_LT_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        long long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_LT_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        long long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_LE(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        long long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_LE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        long long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_LE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        long long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_LE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        long long int, failMsg, passMsg)

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
#define NBP_ASSERT_ULLONG_EQ(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        unsigned long long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_EQ_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        unsigned long long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_EQ_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        unsigned long long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_EQ_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        unsigned long long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_NE(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        unsigned long long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_NE_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        unsigned long long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_NE_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        unsigned long long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_NE_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        unsigned long long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_GT(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        unsigned long long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_GT_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        unsigned long long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_GT_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        unsigned long long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_GT_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        unsigned long long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_GE(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        unsigned long long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_GE_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        unsigned long long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_GE_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        unsigned long long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_GE_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        unsigned long long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_LT(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        unsigned long long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_LT_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        unsigned long long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_LT_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        unsigned long long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_LT_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        unsigned long long int, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_LE(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        unsigned long long int, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_LE_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        unsigned long long int, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_LE_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        unsigned long long int, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_LE_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        unsigned long long int, failMsg, passMsg)

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
#define NBP_ASSERT_FLOAT_EQ(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        float, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_EQ_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        float, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_EQ_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        float, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_EQ_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        float, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_NE(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        float, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_NE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        float, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_NE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        float, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_NE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        float, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_GT(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        float, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_GT_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        float, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_GT_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        float, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_GT_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        float, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_GE(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        float, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_GE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        float, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_GE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        float, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_GE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        float, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_LT(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        float, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_LT_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        float, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_LT_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        float, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_LT_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        float, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_LE(a, b)                                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        float, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_LE_FAIL_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        float, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_LE_PASS_MSG(a, b, msg)                                \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        float, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_LE_MSG(a, b, failMsg, passMsg)                        \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        float, failMsg, passMsg)

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
#define NBP_ASSERT_DOUBLE_EQ(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        double, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_EQ_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        double, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_EQ_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        double, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_EQ_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_NE(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        double, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_NE_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        double, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_NE_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        double, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_NE_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_GT(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        double, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_GT_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        double, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_GT_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        double, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_GT_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_GE(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        double, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_GE_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        double, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_GE_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        double, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_GE_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_LT(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        double, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_LT_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        double, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_LT_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        double, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_LT_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_LE(a, b)                                             \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        double, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_LE_FAIL_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        double, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_LE_PASS_MSG(a, b, msg)                               \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        double, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_LE_MSG(a, b, failMsg, passMsg)                       \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        double, failMsg, passMsg)

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
#define NBP_ASSERT_LDOUBLE_EQ(a, b)                                            \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        long double, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_EQ_FAIL_MSG(a, b, msg)                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        long double, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_EQ_PASS_MSG(a, b, msg)                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        long double, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_EQ_MSG(a, b, failMsg, passMsg)                      \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        long double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_NE(a, b)                                            \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        long double, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_NE_FAIL_MSG(a, b, msg)                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        long double, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_NE_PASS_MSG(a, b, msg)                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        long double, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_NE_MSG(a, b, failMsg, passMsg)                      \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        long double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_GT(a, b)                                            \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        long double, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_GT_FAIL_MSG(a, b, msg)                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        long double, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_GT_PASS_MSG(a, b, msg)                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        long double, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_GT_MSG(a, b, failMsg, passMsg)                      \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        long double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_GE(a, b)                                            \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        long double, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_GE_FAIL_MSG(a, b, msg)                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        long double, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_GE_PASS_MSG(a, b, msg)                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        long double, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_GE_MSG(a, b, failMsg, passMsg)                      \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        long double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_LT(a, b)                                            \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        long double, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_LT_FAIL_MSG(a, b, msg)                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        long double, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_LT_PASS_MSG(a, b, msg)                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        long double, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_LT_MSG(a, b, failMsg, passMsg)                      \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        long double, failMsg, passMsg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_LE(a, b)                                            \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        long double, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_LE_FAIL_MSG(a, b, msg)                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        long double, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_LE_PASS_MSG(a, b, msg)                              \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        long double, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_LE_MSG(a, b, failMsg, passMsg)                      \
    NBP_PRIVATE_ASSERT_TYPE_OP_BASE(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        long double, failMsg, passMsg)

#endif // end if NBP_PRIVATE_API_ASSERT_H
