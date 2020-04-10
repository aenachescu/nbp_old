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

#ifndef NBP_PRIVATE_IMPL_MAIN_H
#define NBP_PRIVATE_IMPL_MAIN_H

extern nbp_module_details_t* nbpMainModule;
extern nbp_scheduler_interface_t* nbpSchedulerInterface;
extern nbp_printer_interface_t* nbpPrinterInterfaces[];
extern unsigned int nbpPrinterInterfacesSize;

int nbpSchedulerRunEnabled;

int nbp_string_equal(const char* a, const char* b)
{
    while (*a == *b && *a != '\0') {
        a++;
        b++;
    }

    return *a != *b ? 0 : 1;
}

int nbp_command_run_all()
{
    nbpSchedulerRunEnabled = 0;

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->init != NBP_NULL_POINTER) {
            nbpPrinterInterfaces[i]->init();
        }
    }

    if (nbpSchedulerInterface->run == NBP_NULL_POINTER) {
        NBP_HANDLE_ERROR(NBP_ERROR_SCHEDULER_NO_RUN_FUNC);
        NBP_EXIT(NBP_EXIT_STATUS_INVALID_SCHEDULER);
    }

    if (nbpSchedulerInterface->init != NBP_NULL_POINTER) {
        nbpSchedulerInterface->init();
    }

    nbp_call_module(nbpMainModule, NBP_NULL_POINTER);

    nbp_notify_printer_before_run(
        NBP_MODULE_GET_MODULES_NUM(nbpMainModule) + 1,
        NBP_MODULE_GET_TESTS_NUM(nbpMainModule)
    );

    nbpSchedulerRunEnabled = 1;
    nbpSchedulerInterface->run();
    nbpSchedulerRunEnabled = 0;

    nbp_notify_printer_after_run(
        NBP_MODULE_GET_STATE(nbpMainModule) == NBP_MODULE_STATE_PASSED ?
            NBP_MODULE_GET_PASSED_MODULES_NUM(nbpMainModule) + 1 :
            NBP_MODULE_GET_PASSED_MODULES_NUM(nbpMainModule),
        NBP_MODULE_GET_STATE(nbpMainModule) == NBP_MODULE_STATE_FAILED ?
            NBP_MODULE_GET_FAILED_MODULES_NUM(nbpMainModule) + 1 :
            NBP_MODULE_GET_FAILED_MODULES_NUM(nbpMainModule),
        NBP_MODULE_GET_STATE(nbpMainModule) == NBP_MODULE_STATE_SKIPPED ?
            NBP_MODULE_GET_SKIPPED_MODULES_NUM(nbpMainModule) + 1 :
            NBP_MODULE_GET_SKIPPED_MODULES_NUM(nbpMainModule),
        NBP_MODULE_GET_PASSED_TESTS_NUM(nbpMainModule),
        NBP_MODULE_GET_FAILED_TESTS_NUM(nbpMainModule),
        NBP_MODULE_GET_SKIPPED_TESTS_NUM(nbpMainModule),
        NBP_MODULE_GET_CHECKS_NUM(nbpMainModule),
        NBP_MODULE_GET_PASSED_CHECKS_NUM(nbpMainModule),
        NBP_MODULE_GET_FAILED_CHECKS_NUM(nbpMainModule),
        NBP_MODULE_GET_TEST_ASSERTS_NUM(nbpMainModule),
        NBP_MODULE_GET_PASSED_TEST_ASSERTS_NUM(nbpMainModule),
        NBP_MODULE_GET_FAILED_TEST_ASSERTS_NUM(nbpMainModule),
        NBP_MODULE_GET_MODULE_ASSERTS_NUM(nbpMainModule),
        NBP_MODULE_GET_PASSED_MODULE_ASSERTS_NUM(nbpMainModule),
        NBP_MODULE_GET_FAILED_MODULE_ASSERTS_NUM(nbpMainModule),
        NBP_MODULE_GET_ASSERTS_NUM(nbpMainModule),
        NBP_MODULE_GET_PASSED_ASSERTS_NUM(nbpMainModule),
        NBP_MODULE_GET_FAILED_ASSERTS_NUM(nbpMainModule)
    );

    if (nbpSchedulerInterface->uninit != NBP_NULL_POINTER) {
        nbpSchedulerInterface->uninit();
    }

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->uninit != NBP_NULL_POINTER) {
            nbpPrinterInterfaces[i]->uninit();
        }
    }

    if (NBP_MODULE_GET_STATE(nbpMainModule) == NBP_MODULE_STATE_PASSED) {
        return NBP_EXIT_STATUS_PASSED;
    }

    return NBP_EXIT_STATUS_FAILED;
}

int nbp_command_version()
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->init != NBP_NULL_POINTER) {
            nbpPrinterInterfaces[i]->init();
        }
    }

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->handleVersionCommand != NBP_NULL_POINTER) {
            nbpPrinterInterfaces[i]->handleVersionCommand();
        }
    }

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->uninit != NBP_NULL_POINTER) {
            nbpPrinterInterfaces[i]->uninit();
        }
    }

    return NBP_EXIT_STATUS_PASSED;
}

int main(int argc, const char** argv)
{
    if (argc < 1) {
        return NBP_EXIT_STATUS_INVALID_CMDLINE;
    }

    if (argc == 1) {
        return nbp_command_run_all();
    }

    if (nbp_string_equal(argv[1], "--version") == 1) {
        return nbp_command_version();
    }

    return NBP_EXIT_STATUS_INVALID_CMDLINE;
}

#endif // end if NBP_PRIVATE_IMPL_MAIN_H
