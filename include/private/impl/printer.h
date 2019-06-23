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


#endif // end if NBP_PRIVATE_IMPL_PRINTER_H
