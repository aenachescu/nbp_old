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

int main(int argc, const char** argv)
{
    (void)(argc);
    (void)(argv);

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->init != 0x0) {
            nbpPrinterInterfaces[i]->init();
        }
    }

    if (nbpSchedulerInterface->init == 0x0) {
        nbp_notify_printer_handle_error(NBP_ERROR_SCHEDULER_NO_INIT_FUNC);
        return -1;
    }
    if (nbpSchedulerInterface->uninit == 0x0) {
        nbp_notify_printer_handle_error(NBP_ERROR_SCHEDULER_NO_UNINIT_FUNC);
        return -2;
    }
    if (nbpSchedulerInterface->run == 0x0) {
        nbp_notify_printer_handle_error(NBP_ERROR_SCHEDULER_NO_RUN_FUNC);
        return -3;
    }
    if (nbpSchedulerInterface->addTest == 0x0) {
        nbp_notify_printer_handle_error(NBP_ERROR_SCHEDULER_NO_ADD_TEST_FUNC);
        return -4;
    }

    nbpSchedulerInterface->init();

    nbp_call_module(nbpMainModule, 0x0);

    nbpSchedulerInterface->run();
    nbpSchedulerInterface->uninit();

    int ret = 0;
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->uninit != 0x0) {
            ret += nbpPrinterInterfaces[i]->uninit();
        }
    }

    return ret;
}

#endif // end if NBP_PRIVATE_IMPL_MAIN_H
