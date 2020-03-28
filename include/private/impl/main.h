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
