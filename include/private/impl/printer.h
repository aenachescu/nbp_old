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

#ifndef NBP_PRIVATE_IMPL_PRINTER_H
#define NBP_PRIVATE_IMPL_PRINTER_H

void nbp_notify_printer_handle_error(int errCode)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->handleError != 0x0) {
            nbpPrinterInterfaces[i]->handleError(errCode);
        }
    }
}

void nbp_notify_printer_test_begin(nbp_test_details_t* test)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testBegin != 0x0) {
            nbpPrinterInterfaces[i]->testBegin(test);
        }
    }
}

void nbp_notify_printer_test_end(nbp_test_details_t* test)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testEnd != 0x0) {
            nbpPrinterInterfaces[i]->testEnd(test);
        }
    }
}

void nbp_notify_printer_module_begin(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleBegin != 0x0) {
            nbpPrinterInterfaces[i]->moduleBegin(module);
        }
    }
}

void nbp_notify_printer_module_end(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleEnd != 0x0) {
            nbpPrinterInterfaces[i]->moduleEnd(module);
        }
    }
}

void nbp_notify_printer_check_result(nbp_test_details_t* test, const char* cond,
    int passed, int line, const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkResult != 0x0) {
            nbpPrinterInterfaces[i]->checkResult(
                test,
                cond,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_notify_printer_check_op_result( nbp_test_details_t* test,
    const char* a, const char* b, int op, int passed, int line,
    const char* failMsg, const char* passMsg )
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkOpResult != 0x0) {
            nbpPrinterInterfaces[i]->checkOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_notify_printer_check_char_op_result(nbp_test_details_t* test, char a,
    char b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkCharOpResult != 0x0) {
            nbpPrinterInterfaces[i]->checkCharOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_notify_printer_check_short_op_result(nbp_test_details_t* test,
    short int a, short int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkShortOpResult != 0x0) {
            nbpPrinterInterfaces[i]->checkShortOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_notify_printer_check_ushort_op_result(nbp_test_details_t* test,
    unsigned short int a, unsigned short int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkUShortOpResult != 0x0) {
            nbpPrinterInterfaces[i]->checkUShortOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_notify_printer_check_int_op_result(nbp_test_details_t* test, int a,
    int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkIntOpResult != 0x0) {
            nbpPrinterInterfaces[i]->checkIntOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_notify_printer_check_uint_op_result(nbp_test_details_t* test,
    unsigned int a, unsigned int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkUIntOpResult != 0x0) {
            nbpPrinterInterfaces[i]->checkUIntOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_notify_printer_check_long_op_result(nbp_test_details_t* test,
    long int a, long int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkLongOpResult != 0x0) {
            nbpPrinterInterfaces[i]->checkLongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_notify_printer_check_ulong_op_result(nbp_test_details_t* test,
    unsigned long int a, unsigned long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkULongOpResult != 0x0) {
            nbpPrinterInterfaces[i]->checkULongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_notify_printer_check_llong_op_result(nbp_test_details_t* test,
    long long int a, long long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkLLongOpResult != 0x0) {
            nbpPrinterInterfaces[i]->checkLLongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_notify_printer_check_ullong_op_result(nbp_test_details_t* test,
    unsigned long long int a, unsigned long long int b, int op, int passed,
    int line, const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkULLongOpResult != 0x0) {
            nbpPrinterInterfaces[i]->checkULLongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_notify_printer_check_float_op_result(nbp_test_details_t* test,
    float a, float b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkFloatOpResult != 0x0) {
            nbpPrinterInterfaces[i]->checkFloatOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_notify_printer_check_double_op_result(nbp_test_details_t* test,
    double a, double b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkDoubleOpResult != 0x0) {
            nbpPrinterInterfaces[i]->checkDoubleOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_notify_printer_check_ldouble_op_result(nbp_test_details_t* test,
    long double a, long double b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkLDoubleOpResult != 0x0) {
            nbpPrinterInterfaces[i]->checkLDoubleOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

#endif // end if NBP_PRIVATE_IMPL_PRINTER_H
