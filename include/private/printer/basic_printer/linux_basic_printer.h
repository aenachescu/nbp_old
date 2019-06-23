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

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"

struct NbpPrinterPassMsgList {
    char* msg;
    char* cond;
    int line;
    struct NbpPrinterPassMsgList* next;
};

int nbpPrinterRet;
int nbpPrinterTestFailed;
struct NbpPrinterPassMsgList* nbpPrinterFirstPassMsg;
struct NbpPrinterPassMsgList* nbpPrinterLastPassMsg;

void nbp_printer_print_deepth(unsigned int deepth)
{
    printf("\r");
    while (deepth-- > 0) {
        printf("    ");
    }
}

char* nbp_printer_duplicate_str(const char* str)
{
    char* dup = (char*) NBP_ALLOC(strlen(str));
    if (dup != 0x0) {
        strcpy(dup, str);
    }
    return dup;
}

void nbp_printer_add_pass_msg(const char* cond, const char* msg, int line)
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

void nbp_printer_print_pass_msg(nbp_test_details_t* test)
{
    struct NbpPrinterPassMsgList* tmp = 0x0;

    while (nbpPrinterFirstPassMsg != 0x0) {
        nbp_printer_print_deepth(test->module->deepth + 2);
        printf(KGRN "%s passed (%s) (%d)" KNRM "\n",
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

void nbp_printer_init(void)
{
    nbpPrinterRet           = 0;
    nbpPrinterTestFailed    = 0;
    nbpPrinterFirstPassMsg  = 0x0;
    nbpPrinterLastPassMsg   = 0x0;
}

int nbp_printer_uninit(void)
{
    return nbpPrinterRet;
}

void nbp_printer_test_end(nbp_test_details_t* test)
{
    if (nbpPrinterTestFailed == 0) {
        nbp_printer_print_deepth(test->module->deepth + 1);
        printf(KGRN "%s" KNRM "\n", test->testName);
        nbp_printer_print_pass_msg(test);
    } else {
        nbpPrinterTestFailed = 0;
    }
}

void nbp_printer_module_begin(nbp_module_details_t* module)
{
    nbp_printer_print_deepth(module->deepth);
    printf("%s\n", module->moduleName);
}

void nbp_printer_check_result(nbp_test_details_t* test, const char* cond,
    int passed, int line, const char* failMsg, const char* passMsg)
{
    if (passed == 1) {
        if (passMsg == 0x0) {
            return;
        }

        if (nbpPrinterTestFailed == 1) {
            nbp_printer_print_deepth(test->module->deepth + 2);
            printf(KGRN "%s passed (%s) (%d)" KNRM "\n", cond, passMsg, line);
        } else {
            nbp_printer_add_pass_msg(cond, passMsg, line);
        }
        return;
    }

    if (nbpPrinterTestFailed == 0) {
        nbpPrinterTestFailed = 1;
        nbpPrinterRet        = 1;

        nbp_printer_print_deepth(test->module->deepth + 1);
        printf(KRED "%s" KNRM "\n", test->testName);

        nbp_printer_print_pass_msg(test);
    }

    if (failMsg != 0x0) {
        nbp_printer_print_deepth(test->module->deepth + 2);
        printf(KRED "%s failed (%s) (%d)" KNRM "\n", cond, failMsg, line);
    } else {
        nbp_printer_print_deepth(test->module->deepth + 2);
        printf(KRED "%s failed (%d)" KNRM "\n", cond, line);
    }
}

nbp_printer_interface_t nbpPrinter = {
    .init           = nbp_printer_init,
    .uninit         = nbp_printer_uninit,
    .handleError    = 0x0,
    .testBegin      = 0x0,
    .testEnd        = nbp_printer_test_end,
    .moduleBegin    = nbp_printer_module_begin,
    .moduleEnd      = 0x0,
    .checkResult    = nbp_printer_check_result,
};

#undef KNRM
#undef KRED
#undef KGRN
#undef KYEL

#endif // end if NBP_PRIVATE_PRINTER_LINUX_BASIC_PRINTER_H
