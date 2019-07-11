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

#ifndef NBP_PRIVATE_PRINTER_LINUX_BASIC_PRINTER_H
#define NBP_PRIVATE_PRINTER_LINUX_BASIC_PRINTER_H

#include <stdio.h>
#include <string.h>

#define NBP_PRIVATE_COLOR_NORMAL    "\x1B[0m"
#define NBP_PRIVATE_COLOR_RED       "\x1B[31m"
#define NBP_PRIVATE_COLOR_GREEN     "\x1B[32m"
#define NBP_PRIVATE_COLOR_YELLOW    "\x1B[33m"

struct NbpPrinterPassMsgList {
    char* msg;
    char* cond;
    int line;
    struct NbpPrinterPassMsgList* next;
};

static int nbpPrinterRet;
static int nbpPrinterTestFailed;
static struct NbpPrinterPassMsgList* nbpPrinterFirstPassMsg;
static struct NbpPrinterPassMsgList* nbpPrinterLastPassMsg;

static void nbp_printer_print_depth(unsigned int depth)
{
    printf("\r");
    while (depth-- > 0) {
        printf("    ");
    }
}

static char* nbp_printer_duplicate_str(const char* str)
{
    char* dup = (char*) NBP_ALLOC(strlen(str) + 1);
    if (dup != 0x0) {
        strcpy(dup, str);
    }
    return dup;
}

static void nbp_printer_add_pass_msg(const char* cond, const char* msg,
    int line)
{
    struct NbpPrinterPassMsgList* tmp = (struct NbpPrinterPassMsgList*)
        NBP_ALLOC(sizeof(struct NbpPrinterPassMsgList));

    do {
        if (tmp == 0x0) {
            nbp_notify_printer_handle_error(NBP_ERROR_ALLOC);
            break;
        }

        tmp->cond = nbp_printer_duplicate_str(cond);
        if (tmp->cond == 0x0) {
            nbp_notify_printer_handle_error(NBP_ERROR_ALLOC);
            break;
        }

        tmp->msg = nbp_printer_duplicate_str(msg);
        if (tmp->msg == 0x0) {
            nbp_notify_printer_handle_error(NBP_ERROR_ALLOC);
        }

        tmp->line = line;
        tmp->next = 0x0;

        if (nbpPrinterLastPassMsg == 0x0) {
            nbpPrinterFirstPassMsg = tmp;
            nbpPrinterLastPassMsg  = tmp;
        } else {
            nbpPrinterLastPassMsg->next = tmp;
            nbpPrinterLastPassMsg       = tmp;
        }

        return;
    } while (0);

    if (tmp != 0x0) {
        if (tmp->cond != 0x0) {
            NBP_FREE(tmp->cond);
        }
        if (tmp->msg != 0x0) {
            NBP_FREE(tmp->msg);
        }
        NBP_FREE(tmp);
    }
}

static void nbp_printer_print_pass_msg(unsigned int testDepth)
{
    struct NbpPrinterPassMsgList* tmp = 0x0;

    while (nbpPrinterFirstPassMsg != 0x0) {
        nbp_printer_print_depth(testDepth + 1);
        printf(
            NBP_PRIVATE_COLOR_GREEN
                "%s passed (%s) (%d)"
            NBP_PRIVATE_COLOR_NORMAL "\n",
            nbpPrinterFirstPassMsg->cond,
            nbpPrinterFirstPassMsg->msg,
            nbpPrinterFirstPassMsg->line
        );

        tmp = nbpPrinterFirstPassMsg;
        nbpPrinterFirstPassMsg = nbpPrinterFirstPassMsg->next;

        NBP_FREE(tmp->cond);
        NBP_FREE(tmp->msg);
        NBP_FREE(tmp);
    }

    nbpPrinterLastPassMsg = 0x0;
}

static void nbp_printer_print_result(nbp_test_details_t* test,
    const char* cond, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    if (passed == NBP_CHECK_STATUS_PASSED) {
        if (passMsg == NBP_PRINTER_NO_PASS_MSG) {
            return;
        }

        if (nbpPrinterTestFailed == 1) {
            nbp_printer_print_depth(NBP_GET_TEST_DEPTH(test) + 1);
            printf(
                NBP_PRIVATE_COLOR_GREEN
                    "%s passed (%s) (%d)"
                NBP_PRIVATE_COLOR_NORMAL "\n",
                cond,
                passMsg,
                line
            );
        } else {
            nbp_printer_add_pass_msg(cond, passMsg, line);
        }
        return;
    }

    if (nbpPrinterTestFailed == 0) {
        nbpPrinterTestFailed = 1;
        nbpPrinterRet        = 1;

        nbp_printer_print_depth(NBP_GET_TEST_DEPTH(test));
        printf(
            NBP_PRIVATE_COLOR_RED "%s" NBP_PRIVATE_COLOR_NORMAL "\n",
            NBP_GET_TEST_NAME(test)
        );

        nbp_printer_print_pass_msg(NBP_GET_TEST_DEPTH(test));
    }

    if (failMsg != NBP_PRINTER_NO_FAIL_MSG) {
        nbp_printer_print_depth(NBP_GET_TEST_DEPTH(test) + 1);
        printf(
            NBP_PRIVATE_COLOR_RED
                "%s failed (%s) (%d)"
            NBP_PRIVATE_COLOR_NORMAL "\n",
            cond,
            failMsg,
            line
        );
    } else {
        nbp_printer_print_depth(NBP_GET_TEST_DEPTH(test) + 1);
        printf(
            NBP_PRIVATE_COLOR_RED
                "%s failed (%d)"
            NBP_PRIVATE_COLOR_NORMAL "\n",
            cond,
            line
        );
    }
}

NBP_PRINTER_FUNC_INIT(nbp_basic_printer_init)
{
    nbpPrinterRet           = 0;
    nbpPrinterTestFailed    = 0;
    nbpPrinterFirstPassMsg  = 0x0;
    nbpPrinterLastPassMsg   = 0x0;
}

NBP_PRINTER_FUNC_UNINIT(nbp_basic_printer_uninit)
{
    return nbpPrinterRet;
}

NBP_PRINTER_FUNC_TEST_END(nbp_basic_printer_test_end)
{
    if (nbpPrinterTestFailed == 0) {
        nbp_printer_print_depth(NBP_GET_TEST_DEPTH(NBP_THIS_TEST));
        printf(
            NBP_PRIVATE_COLOR_GREEN "%s" NBP_PRIVATE_COLOR_NORMAL "\n",
            NBP_GET_TEST_NAME(NBP_THIS_TEST)
        );
        nbp_printer_print_pass_msg(NBP_GET_TEST_DEPTH(NBP_THIS_TEST));
    } else {
        nbpPrinterTestFailed = 0;
    }
}

NBP_PRINTER_FUNC_MODULE_BEGIN(nbp_basic_printer_module_begin)
{
    nbp_printer_print_depth(NBP_GET_MODULE_DEPTH(NBP_THIS_MODULE));
    printf("%s\n", NBP_GET_MODULE_NAME(NBP_THIS_MODULE));
}

NBP_PRINTER_FUNC_CHECK_RESULT(nbp_basic_printer_check_result)
{
    nbp_printer_print_result(
        NBP_THIS_TEST,
        NBP_PRINTER_GET_CONDITION(),
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_OP_RESULT(nbp_basic_printer_check_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%s %s %s",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_CHAR_OP_RESULT(nbp_basic_printer_check_char_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%c %s %c",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_SHORT_OP_RESULT(nbp_basic_printer_check_short_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%hd %s %hd",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_USHORT_OP_RESULT(
    nbp_basic_printer_check_ushort_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%hu %s %hu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_INT_OP_RESULT(nbp_basic_printer_check_int_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%d %s %d",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_UINT_OP_RESULT(nbp_basic_printer_check_uint_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%u %s %u",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_LONG_OP_RESULT(nbp_basic_printer_check_long_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%ld %s %ld",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_ULONG_OP_RESULT(nbp_basic_printer_check_ulong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%lu %s %lu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_LLONG_OP_RESULT(nbp_basic_printer_check_llong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%lld %s %lld",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_ULLONG_OP_RESULT(
    nbp_basic_printer_check_ullong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%llu %s %llu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_FLOAT_OP_RESULT(nbp_basic_printer_check_float_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%f %s %f",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_DOUBLE_OP_RESULT(
    nbp_basic_printer_check_double_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%f %s %f",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_LDOUBLE_OP_RESULT(
    nbp_basic_printer_check_ldouble_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%Lf %s %Lf",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_RESULT(
    nbp_basic_printer_test_assert_result)
{
    nbp_printer_print_result(
        NBP_THIS_TEST,
        NBP_PRINTER_GET_CONDITION(),
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_OP_RESULT(
    nbp_basic_printer_test_assert_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%s %s %s",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_CHAR_OP_RESULT(
    nbp_basic_printer_test_assert_char_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%c %s %c",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_SHORT_OP_RESULT(
    nbp_basic_printer_test_assert_short_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%hd %s %hd",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_USHORT_OP_RESULT(
    nbp_basic_printer_test_assert_ushort_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%hu %s %hu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_INT_OP_RESULT(
    nbp_basic_printer_test_assert_int_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%d %s %d",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_UINT_OP_RESULT(
    nbp_basic_printer_test_assert_uint_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%u %s %u",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_LONG_OP_RESULT(
    nbp_basic_printer_test_assert_long_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%ld %s %ld",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_ULONG_OP_RESULT(
    nbp_basic_printer_test_assert_ulong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%lu %s %lu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_LLONG_OP_RESULT(
    nbp_basic_printer_test_assert_llong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%lld %s %lld",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_ULLONG_OP_RESULT(
    nbp_basic_printer_test_assert_ullong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%llu %s %llu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_FLOAT_OP_RESULT(
    nbp_basic_printer_test_assert_float_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%f %s %f",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_DOUBLE_OP_RESULT(
    nbp_basic_printer_test_assert_double_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%f %s %f",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_LDOUBLE_OP_RESULT(
    nbp_basic_printer_test_assert_ldouble_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%Lf %s %Lf",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_RESULT(
    nbp_basic_printer_module_assert_result)
{
    nbp_printer_print_result(
        NBP_THIS_TEST,
        NBP_PRINTER_GET_CONDITION(),
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_OP_RESULT(
    nbp_basic_printer_module_assert_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%s %s %s",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_CHAR_OP_RESULT(
    nbp_basic_printer_module_assert_char_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%c %s %c",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_SHORT_OP_RESULT(
    nbp_basic_printer_module_assert_short_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%hd %s %hd",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_USHORT_OP_RESULT(
    nbp_basic_printer_module_assert_ushort_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%hu %s %hu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_INT_OP_RESULT(
    nbp_basic_printer_module_assert_int_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%d %s %d",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_UINT_OP_RESULT(
    nbp_basic_printer_module_assert_uint_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%u %s %u",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_LONG_OP_RESULT(
    nbp_basic_printer_module_assert_long_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%ld %s %ld",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_ULONG_OP_RESULT(
    nbp_basic_printer_module_assert_ulong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%lu %s %lu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_LLONG_OP_RESULT(
    nbp_basic_printer_module_assert_llong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%lld %s %lld",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_ULLONG_OP_RESULT(
    nbp_basic_printer_module_assert_ullong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%llu %s %llu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_FLOAT_OP_RESULT(
    nbp_basic_printer_module_assert_float_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%f %s %f",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_DOUBLE_OP_RESULT(
    nbp_basic_printer_module_assert_double_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%f %s %f",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_LDOUBLE_OP_RESULT(
    nbp_basic_printer_module_assert_ldouble_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%Lf %s %Lf",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_RESULT(nbp_basic_printer_assert_result)
{
    nbp_printer_print_result(
        NBP_THIS_TEST,
        NBP_PRINTER_GET_CONDITION(),
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_OP_RESULT(nbp_basic_printer_assert_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%s %s %s",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_CHAR_OP_RESULT(nbp_basic_printer_assert_char_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%c %s %c",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_SHORT_OP_RESULT(
    nbp_basic_printer_assert_short_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%hd %s %hd",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_USHORT_OP_RESULT(
    nbp_basic_printer_assert_ushort_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%hu %s %hu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_INT_OP_RESULT(nbp_basic_printer_assert_int_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%d %s %d",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_UINT_OP_RESULT(nbp_basic_printer_assert_uint_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%u %s %u",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_LONG_OP_RESULT(nbp_basic_printer_assert_long_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%ld %s %ld",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_ULONG_OP_RESULT(
    nbp_basic_printer_assert_ulong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%lu %s %lu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_LLONG_OP_RESULT(
    nbp_basic_printer_assert_llong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%lld %s %lld",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_ULLONG_OP_RESULT(
    nbp_basic_printer_assert_ullong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%llu %s %llu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_FLOAT_OP_RESULT(
    nbp_basic_printer_assert_float_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%f %s %f",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_DOUBLE_OP_RESULT(
    nbp_basic_printer_assert_double_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%f %s %f",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_LDOUBLE_OP_RESULT(
    nbp_basic_printer_assert_ldouble_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%Lf %s %Lf",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_printer_print_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_DEFINE_PRINTER(
    nbpDefaultPrinter,
    NBP_PRINTER_USE_FUNC_INIT(
        nbp_basic_printer_init
    ),
    NBP_PRINTER_USE_FUNC_UNINIT(
        nbp_basic_printer_uninit
    ),
    NBP_PRINTER_NO_FUNC_HANDLE_ERROR,
    NBP_PRINTER_NO_FUNC_TEST_BEGIN,
    NBP_PRINTER_USE_FUNC_TEST_END(
        nbp_basic_printer_test_end
    ),
    NBP_PRINTER_USE_FUNC_MODULE_BEGIN(
        nbp_basic_printer_module_begin
    ),
    NBP_PRINTER_NO_FUNC_MODULE_END,

    // callbacks for NBP_CHECK_* macros
    NBP_PRINTER_USE_FUNC_CHECK_RESULT(
        nbp_basic_printer_check_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_OP_RESULT(
        nbp_basic_printer_check_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_CHAR_OP_RESULT(
        nbp_basic_printer_check_char_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_SHORT_OP_RESULT(
        nbp_basic_printer_check_short_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_USHORT_OP_RESULT(
        nbp_basic_printer_check_ushort_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_INT_OP_RESULT(
        nbp_basic_printer_check_int_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_UINT_OP_RESULT(
        nbp_basic_printer_check_uint_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_LONG_OP_RESULT(
        nbp_basic_printer_check_long_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_ULONG_OP_RESULT(
        nbp_basic_printer_check_ulong_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_LLONG_OP_RESULT(
        nbp_basic_printer_check_llong_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_ULLONG_OP_RESULT(
        nbp_basic_printer_check_ullong_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_FLOAT_OP_RESULT(
        nbp_basic_printer_check_float_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_DOUBLE_OP_RESULT(
        nbp_basic_printer_check_double_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_LDOUBLE_OP_RESULT(
        nbp_basic_printer_check_ldouble_op_result
    ),

    // callbacks for NBP_TEST_ASSERT_* macros
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_RESULT(
        nbp_basic_printer_test_assert_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_OP_RESULT(
        nbp_basic_printer_test_assert_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_CHAR_OP_RESULT(
        nbp_basic_printer_test_assert_char_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_SHORT_OP_RESULT(
        nbp_basic_printer_test_assert_short_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_USHORT_OP_RESULT(
        nbp_basic_printer_test_assert_ushort_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_INT_OP_RESULT(
        nbp_basic_printer_test_assert_int_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_UINT_OP_RESULT(
        nbp_basic_printer_test_assert_uint_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_LONG_OP_RESULT(
        nbp_basic_printer_test_assert_long_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_ULONG_OP_RESULT(
        nbp_basic_printer_test_assert_ulong_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_LLONG_OP_RESULT(
        nbp_basic_printer_test_assert_llong_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_ULLONG_OP_RESULT(
        nbp_basic_printer_test_assert_ullong_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_FLOAT_OP_RESULT(
        nbp_basic_printer_test_assert_float_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_DOUBLE_OP_RESULT(
        nbp_basic_printer_test_assert_double_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_LDOUBLE_OP_RESULT(
        nbp_basic_printer_test_assert_ldouble_op_result
    ),

    // callbacks for NBP_MODULE_ASSERT_* macros
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_RESULT(
        nbp_basic_printer_module_assert_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_OP_RESULT(
        nbp_basic_printer_module_assert_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_CHAR_OP_RESULT(
        nbp_basic_printer_module_assert_char_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_SHORT_OP_RESULT(
        nbp_basic_printer_module_assert_short_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_USHORT_OP_RESULT(
        nbp_basic_printer_module_assert_ushort_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_INT_OP_RESULT(
        nbp_basic_printer_module_assert_int_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_UINT_OP_RESULT(
        nbp_basic_printer_module_assert_uint_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_LONG_OP_RESULT(
        nbp_basic_printer_module_assert_long_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_ULONG_OP_RESULT(
        nbp_basic_printer_module_assert_ulong_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_LLONG_OP_RESULT(
        nbp_basic_printer_module_assert_llong_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_ULLONG_OP_RESULT(
        nbp_basic_printer_module_assert_ullong_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_FLOAT_OP_RESULT(
        nbp_basic_printer_module_assert_float_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_DOUBLE_OP_RESULT(
        nbp_basic_printer_module_assert_double_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_LDOUBLE_OP_RESULT(
        nbp_basic_printer_module_assert_ldouble_op_result
    ),

    // callbacks for NBP_ASSERT_* macros
    NBP_PRINTER_USE_FUNC_ASSERT_RESULT(
        nbp_basic_printer_assert_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_OP_RESULT(
        nbp_basic_printer_assert_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_CHAR_OP_RESULT(
        nbp_basic_printer_assert_char_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_SHORT_OP_RESULT(
        nbp_basic_printer_assert_short_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_USHORT_OP_RESULT(
        nbp_basic_printer_assert_ushort_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_INT_OP_RESULT(
        nbp_basic_printer_assert_int_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_UINT_OP_RESULT(
        nbp_basic_printer_assert_uint_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_LONG_OP_RESULT(
        nbp_basic_printer_assert_long_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_ULONG_OP_RESULT(
        nbp_basic_printer_assert_ulong_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_LLONG_OP_RESULT(
        nbp_basic_printer_assert_llong_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_ULLONG_OP_RESULT(
        nbp_basic_printer_assert_ullong_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_FLOAT_OP_RESULT(
        nbp_basic_printer_assert_float_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_DOUBLE_OP_RESULT(
        nbp_basic_printer_assert_double_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_LDOUBLE_OP_RESULT(
        nbp_basic_printer_assert_ldouble_op_result
    )
);

#undef NBP_PRIVATE_COLOR_NORMAL
#undef NBP_PRIVATE_COLOR_RED
#undef NBP_PRIVATE_COLOR_GREEN
#undef NBP_PRIVATE_COLOR_YELLOW

#endif // end if NBP_PRIVATE_PRINTER_LINUX_BASIC_PRINTER_H
