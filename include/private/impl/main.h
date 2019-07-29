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

int main(int argc, const char** argv)
{
    (void)(argc);
    (void)(argv);

    nbpSchedulerRunEnabled = 0;

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->init != 0x0) {
            nbpPrinterInterfaces[i]->init();
        }
    }

    if (nbpSchedulerInterface->run == 0x0) {
        NBP_HANDLE_ERROR(NBP_ERROR_SCHEDULER_NO_RUN_FUNC);
        return -1;
    }
    if (nbpSchedulerInterface->addTest == 0x0) {
        NBP_HANDLE_ERROR(NBP_ERROR_SCHEDULER_NO_ADD_TEST_FUNC);
        return -2;
    }

    if (nbpSchedulerInterface->init != 0x0) {
        nbpSchedulerInterface->init();
    }

    nbp_call_module(nbpMainModule, 0x0);

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

    if (nbpSchedulerInterface->uninit != 0x0) {
        nbpSchedulerInterface->uninit();
    }

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->uninit != 0x0) {
            nbpPrinterInterfaces[i]->uninit();
        }
    }

    if (NBP_MODULE_GET_STATE(nbpMainModule) == NBP_MODULE_STATE_PASSED) {
        return NBP_EXIT_STATUS_PASSED;
    }

    return NBP_EXIT_STATUS_FAILED;
}

#endif // end if NBP_PRIVATE_IMPL_MAIN_H
