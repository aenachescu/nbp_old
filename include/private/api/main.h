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

#define NBP_MAIN_PRIVATE_MODULE_IMPL(func, scheduler, printers)                \
    extern nbp_module_details_t NBP_PP_CONCAT(nbpModuleDetails, func);         \
    nbp_module_details_t* nbpMainModule =                                      \
        & NBP_PP_CONCAT(nbpModuleDetails, func);                               \
    nbp_scheduler_interface_t* nbpSchedulerInterface = scheduler;              \
    nbp_printer_interface_t* nbpPrinterInterfaces[] = printers;                \
    unsigned int nbpPrinterInterfacesSize =                                    \
        sizeof(nbpPrinterInterfaces) / sizeof(nbpPrinterInterfaces[0]);

#ifdef NBP_CUSTOM_SCHEDULER

#error "Not supported"

#else // NBP_CUSTOM_SCHEDULER not defined

#ifdef NBP_BASIC_SCHEDULER
#define NBP_MAIN_PRIVATE_SCHEDULER_NAME nbpBasicScheduler
#endif // end if NBP_BASIC_SCHEDULER

#ifdef NBP_MT_SCHEDULER
#define NBP_MAIN_PRIVATE_SCHEDULER_NAME nbpMtScheduler
#endif // end if NBP_MT_SCHEDULER

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE(func)                                                  \
    NBP_PRINTER_INCLUDE(nbpDefaultPrinter);                                    \
    NBP_SCHEDULER_INCLUDE(NBP_MAIN_PRIVATE_SCHEDULER_NAME);                    \
    NBP_MAIN_PRIVATE_MODULE_IMPL(                                              \
        func,                                                                  \
        NBP_SCHEDULER_GET_PTR(NBP_MAIN_PRIVATE_SCHEDULER_NAME),                \
        { NBP_PRINTER_GET_PTR(nbpDefaultPrinter) }                             \
    );                                                                         \
    NBP_MODULE(func)

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE_NAME(func, name)                                       \
    NBP_PRINTER_INCLUDE(nbpDefaultPrinter);                                    \
    NBP_SCHEDULER_INCLUDE(NBP_MAIN_PRIVATE_SCHEDULER_NAME);                    \
    NBP_MAIN_PRIVATE_MODULE_IMPL(                                              \
        func,                                                                  \
        NBP_SCHEDULER_GET_PTR(NBP_MAIN_PRIVATE_SCHEDULER_NAME),                \
        { NBP_PRINTER_GET_PTR(nbpDefaultPrinter) }                             \
    );                                                                         \
    NBP_MODULE_NAME(func, name)

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE_FIXTURES(func, setupFunc, teardownFunc)                \
    NBP_PRINTER_INCLUDE(nbpDefaultPrinter);                                    \
    NBP_SCHEDULER_INCLUDE(NBP_MAIN_PRIVATE_SCHEDULER_NAME);                    \
    NBP_MAIN_PRIVATE_MODULE_IMPL(                                              \
        func,                                                                  \
        NBP_SCHEDULER_GET_PTR(NBP_MAIN_PRIVATE_SCHEDULER_NAME),                \
        { NBP_PRINTER_GET_PTR(nbpDefaultPrinter) }                             \
    );                                                                         \
    NBP_MODULE_FIXTURES(func, setupFunc, teardownFunc)

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE_NAME_FIXTURES(func, name, setupFunc, teardownFunc)     \
    NBP_PRINTER_INCLUDE(nbpDefaultPrinter);                                    \
    NBP_SCHEDULER_INCLUDE(NBP_MAIN_PRIVATE_SCHEDULER_NAME);                    \
    NBP_MAIN_PRIVATE_MODULE_IMPL(                                              \
        func,                                                                  \
        NBP_SCHEDULER_GET_PTR(NBP_MAIN_PRIVATE_SCHEDULER_NAME),                \
        { NBP_PRINTER_GET_PTR(nbpDefaultPrinter) }                             \
    );                                                                         \
    NBP_MODULE_NAME_FIXTURES(func, name, setupFunc, teardownFunc)

#endif // end if NBP_CUSTOM_SCHEDULER

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_PRIVATE_API_MAIN_H
