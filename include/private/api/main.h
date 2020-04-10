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

#ifndef NBP_PRIVATE_API_MAIN_H
#define NBP_PRIVATE_API_MAIN_H

#ifdef NBP_LIBRARY_MAIN

#define NBP_PRIVATE_MAIN_MODULE(func, scheduler, printers)                     \
    void func(                                                                 \
        nbp_module_details_t*,                                                 \
        nbp_test_setup_pfn_t,                                                  \
        nbp_test_teardown_pfn_t                                                \
    );                                                                         \
    extern nbp_module_details_t NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func); \
    nbp_module_details_t* nbpMainModule =                                      \
        & NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func);                       \
    nbp_scheduler_interface_t* nbpSchedulerInterface = scheduler;              \
    nbp_printer_interface_t* nbpPrinterInterfaces[] = printers;                \
    unsigned int nbpPrinterInterfacesSize =                                    \
        sizeof(nbpPrinterInterfaces) / sizeof(nbpPrinterInterfaces[0]);

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE(func)                                                  \
    NBP_INCLUDE_PRINTER(nbpDefaultPrinter);                                    \
    NBP_INCLUDE_SCHEDULER(nbpDefaultScheduler);                                \
    NBP_PRIVATE_MAIN_MODULE(                                                   \
        func,                                                                  \
        NBP_USE_SCHEDULER(nbpDefaultScheduler),                                \
        NBP_USE_PRINTERS(NBP_GET_PRINTER(nbpDefaultPrinter))                   \
    );                                                                         \
    NBP_MODULE(func)

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE_NAME(func, name)                                       \
    NBP_INCLUDE_PRINTER(nbpDefaultPrinter);                                    \
    NBP_INCLUDE_SCHEDULER(nbpDefaultScheduler);                                \
    NBP_PRIVATE_MAIN_MODULE(                                                   \
        func,                                                                  \
        NBP_USE_SCHEDULER(nbpDefaultScheduler),                                \
        NBP_USE_PRINTERS(NBP_GET_PRINTER(nbpDefaultPrinter))                   \
    );                                                                         \
    NBP_MODULE_NAME(func, name)

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE_FIXTURES(func, setupFunc, teardownFunc)                \
    NBP_INCLUDE_PRINTER(nbpDefaultPrinter);                                    \
    NBP_INCLUDE_SCHEDULER(nbpDefaultScheduler);                                \
    NBP_PRIVATE_MAIN_MODULE(                                                   \
        func,                                                                  \
        NBP_USE_SCHEDULER(nbpDefaultScheduler),                                \
        NBP_USE_PRINTERS(NBP_GET_PRINTER(nbpDefaultPrinter))                   \
    );                                                                         \
    NBP_MODULE_FIXTURES(func, setupFunc, teardownFunc)

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE_NAME_FIXTURES(func, name, setupFunc, teardownFunc)     \
    NBP_INCLUDE_PRINTER(nbpDefaultPrinter);                                    \
    NBP_INCLUDE_SCHEDULER(nbpDefaultScheduler);                                \
    NBP_PRIVATE_MAIN_MODULE(                                                   \
        func,                                                                  \
        NBP_USE_SCHEDULER(nbpDefaultScheduler),                                \
        NBP_USE_PRINTERS(NBP_GET_PRINTER(nbpDefaultPrinter))                   \
    );                                                                         \
    NBP_MODULE_NAME_FIXTURES(func, name, setupFunc, teardownFunc)

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_PRIVATE_API_MAIN_H
