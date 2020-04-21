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
        if (nbpPrinterInterfaces[i]->init != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->init();
        }
    }

    if (nbpSchedulerInterface->run == NBP_MEMORY_NULL_POINTER) {
        NBP_ERROR_REPORT(NBP_ERROR_SCHEDULER_NO_RUN_FUNC);
        NBP_EXIT(NBP_EXIT_STATUS_INVALID_SCHEDULER);
    }

    if (nbpSchedulerInterface->init != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->init();
    }

    nbp_module_run(nbpMainModule, NBP_MEMORY_NULL_POINTER);

    nbp_printer_notify_before_run(
        NBP_MODULE_GET_NUMBER_OF_MODULES(nbpMainModule) + 1,
        NBP_MODULE_GET_NUMBER_OF_TESTS(nbpMainModule)
    );

    nbpSchedulerRunEnabled = 1;
    nbpSchedulerInterface->run();
    nbpSchedulerRunEnabled = 0;

    extern NBP_SYNC_ATOMIC_UINT_TYPE nbpNumberOfRanTests;
    extern unsigned int nbpTotalNumberOfTests;

    if (NBP_SYNC_ATOMIC_UINT_LOAD(&nbpNumberOfRanTests) != nbpTotalNumberOfTests) {
        NBP_ERROR_REPORT(NBP_ERROR_NOT_ALL_TESTS_RAN);
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    nbp_scheduler_complete_empty_modules(nbpMainModule);

    nbp_printer_notify_after_run(
        NBP_MODULE_GET_STATE(nbpMainModule) == NBP_MODULE_STATE_PASSED ?
            NBP_MODULE_GET_NUMBER_OF_PASSED_MODULES(nbpMainModule) + 1 :
            NBP_MODULE_GET_NUMBER_OF_PASSED_MODULES(nbpMainModule),
        NBP_MODULE_GET_STATE(nbpMainModule) == NBP_MODULE_STATE_FAILED ?
            NBP_MODULE_GET_NUMBER_OF_FAILED_MODULES(nbpMainModule) + 1 :
            NBP_MODULE_GET_NUMBER_OF_FAILED_MODULES(nbpMainModule),
        NBP_MODULE_GET_STATE(nbpMainModule) == NBP_MODULE_STATE_SKIPPED ?
            NBP_MODULE_GET_NUMBER_OF_SKIPPED_MODULES(nbpMainModule) + 1 :
            NBP_MODULE_GET_NUMBER_OF_SKIPPED_MODULES(nbpMainModule),
        NBP_MODULE_GET_NUMBER_OF_PASSED_TESTS(nbpMainModule),
        NBP_MODULE_GET_NUMBER_OF_FAILED_TESTS(nbpMainModule),
        NBP_MODULE_GET_NUMBER_OF_SKIPPED_TESTS(nbpMainModule),
        NBP_MODULE_GET_NUMBER_OF_CHECKS(nbpMainModule),
        NBP_MODULE_GET_NUMBER_OF_PASSED_CHECKS(nbpMainModule),
        NBP_MODULE_GET_NUMBER_OF_FAILED_CHECKS(nbpMainModule),
        NBP_MODULE_GET_NUMBER_OF_TEST_ASSERTS(nbpMainModule),
        NBP_MODULE_GET_NUMBER_OF_PASSED_TEST_ASSERTS(nbpMainModule),
        NBP_MODULE_GET_NUMBER_OF_FAILED_TEST_ASSERTS(nbpMainModule),
        NBP_MODULE_GET_NUMBER_OF_MODULE_ASSERTS(nbpMainModule),
        NBP_MODULE_GET_NUMBER_OF_PASSED_MODULE_ASSERTS(nbpMainModule),
        NBP_MODULE_GET_NUMBER_OF_FAILED_MODULE_ASSERTS(nbpMainModule),
        NBP_MODULE_GET_NUMBER_OF_ASSERTS(nbpMainModule),
        NBP_MODULE_GET_NUMBER_OF_PASSED_ASSERTS(nbpMainModule),
        NBP_MODULE_GET_NUMBER_OF_FAILED_ASSERTS(nbpMainModule)
    );

    if (nbpSchedulerInterface->uninit != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->uninit();
    }

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->uninit != NBP_MEMORY_NULL_POINTER) {
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
        if (nbpPrinterInterfaces[i]->init != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->init();
        }
    }

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->handleVersionCommand != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->handleVersionCommand();
        }
    }

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->uninit != NBP_MEMORY_NULL_POINTER) {
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
