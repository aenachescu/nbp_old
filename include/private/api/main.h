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

#ifndef NBP_PRIVATE_API_MAIN_H
#define NBP_PRIVATE_API_MAIN_H

#ifdef NBP_LIBRARY_MAIN

#define NBP_PRIVATE_MAIN_MODULE(func, scheduler, printers)                     \
    void func(                                                                 \
        nbp_module_details_t*,                                                 \
        nbp_before_test_pfn_t,                                                 \
        nbp_after_test_pfn_t                                                   \
    );                                                                         \
    extern nbp_module_details_t NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func); \
    nbp_module_details_t* nbpMainModule =                                      \
        & NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func);                       \
    nbp_scheduler_interface_t* nbpSchedulerInterface = &scheduler;             \
    nbp_printer_interface_t* nbpPrinterInterfaces[] = printers;                \
    unsigned int nbpPrinterInterfacesSize =                                    \
        sizeof(nbpPrinterInterfaces) / sizeof(nbpPrinterInterfaces[0]);

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE(func)                                                  \
    extern nbp_printer_interface_t nbpPrinter;                                 \
    extern nbp_scheduler_interface_t nbpScheduler;                             \
    NBP_PRIVATE_MAIN_MODULE(                                                   \
        func,                                                                  \
        nbpScheduler,                                                          \
        { &nbpPrinter }                                                        \
    );                                                                         \
    NBP_MODULE(func)

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE_NAME(func, name)                                       \
    extern nbp_printer_interface_t nbpPrinter;                                 \
    extern nbp_scheduler_interface_t nbpScheduler;                             \
    NBP_PRIVATE_MAIN_MODULE(                                                   \
        func,                                                                  \
        nbpScheduler,                                                          \
        { &nbpPrinter }                                                        \
    );                                                                         \
    NBP_MODULE_NAME(func, name)

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE_FIXTURES(func, setupFunc, teardownFunc)                \
    extern nbp_printer_interface_t nbpPrinter;                                 \
    extern nbp_scheduler_interface_t nbpScheduler;                             \
    NBP_PRIVATE_MAIN_MODULE(                                                   \
        func,                                                                  \
        nbpScheduler,                                                          \
        { &nbpPrinter }                                                        \
    );                                                                         \
    NBP_MODULE_FIXTURES(func, setupFunc, teardownFunc)

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE_NAME_FIXTURES(func, name, setupFunc, teardownFunc)     \
    extern nbp_printer_interface_t nbpPrinter;                                 \
    extern nbp_scheduler_interface_t nbpScheduler;                             \
    NBP_PRIVATE_MAIN_MODULE(                                                   \
        func,                                                                  \
        nbpScheduler,                                                          \
        { &nbpPrinter }                                                        \
    );                                                                         \
    NBP_MODULE_NAME_FIXTURES(func, name, setupFunc, teardownFunc)

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_PRIVATE_API_MAIN_H
