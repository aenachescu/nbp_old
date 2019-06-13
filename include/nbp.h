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

#ifndef NBP_LIBRARY_H
#define NBP_LIBRARY_H

/*
 * Make sure there is only one defined scheduler
 */
#undef NBP_PRIVATE_SCHEDULER_TYPE

#ifdef NBP_CUSTOM_SCHEDULER
#define NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_CUSTOM_SCHEDULER

#ifdef NBP_FIFO_MT_SCHEDULER
#ifdef NBP_PRIVATE_SCHEDULER_TYPE
#error "Cannot enabe NBP_FIFO_MT_SCHEDULER because another scheduler is enabled"
#else // NBP_PRIVATE_SCHEDULER_TYPE not defined
#define NBP_PRIVATE_SCHEDULER_TYPE
#define NBP_MT_SUPPORT
#endif // end if NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_FIFO_MT_SCHEDULER

#ifdef NBP_SCHEDULER
#ifdef NBP_PRIVATE_SCHEDULER_TYPE
#error "Cannot enabe NBP_SCHEDULER because another scheduler is enabled"
#else // NBP_PRIVATE_SCHEDULER_TYPE not defined
#define NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_SCHEDULER

/*
 * If no scheduler is defined then define the default scheduler
 */
#ifndef NBP_PRIVATE_SCHEDULER_TYPE
#define NBP_SCHEDULER
#endif // end if NBP_PRIVATE_SCHEDULER_TYPE

#undef NBP_PRIVATE_SCHEDULER_TYPE

/******************************************************************************
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                           Structures definition                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

#define NBP_TEST_STATE_NOT_INITIALIZED  0
#define NBP_TEST_STATE_READY            1
#define NBP_TEST_STATE_RUNNING          2
#define NBP_TEST_STATE_COMPLETED        3
#define NBP_TEST_STATE_SKIPPED          4

#define NBP_MODULE_STATE_NOT_INITIALIZED  0
#define NBP_MODULE_STATE_READY            1
#define NBP_MODULE_STATE_RUNNING          2
#define NBP_MODULE_STATE_COMPLETED        3
#define NBP_MODULE_STATE_SKIPPED          4

struct nbp_test_details_t;
struct nbp_module_details_t;

typedef void (*nbp_before_test_pfn_t)(
    void
);
typedef void (*nbp_after_test_pfn_t)(
    void
);

typedef void(*nbp_setup_module_pfn_t)(
    void
);
typedef void(*nbp_teardown_module_pfn_t)(
    void
);

typedef void (*nbp_test_pfn_t)(
    struct nbp_test_details_t*
);

typedef void (*nbp_module_pfn_t)(
    struct nbp_module_details_t*,
    nbp_before_test_pfn_t,
    nbp_after_test_pfn_t
);

struct nbp_test_details_t {
    const char* testName;
    nbp_test_pfn_t testFunc;
    nbp_before_test_pfn_t beforeTestFunc;
    nbp_after_test_pfn_t afterTestFunc;
    struct nbp_module_details_t* module;
    unsigned int passedChecks;
    unsigned int failedChecks;
    unsigned int passedTestAsserts;
    unsigned int failedTestAsserts;
    unsigned int passedModuleAsserts;
    unsigned int failedModuleAsserts;
    unsigned int passedAsserts;
    unsigned int failedAsserts;
    unsigned int testState;
    struct nbp_test_details_t* next;
    struct nbp_test_details_t* prev;
};
typedef struct nbp_test_details_t nbp_test_details_t;

struct nbp_module_details_t {
    const char* moduleName;
    nbp_module_pfn_t moduleFunc;
    nbp_setup_module_pfn_t setup;
    nbp_teardown_module_pfn_t teardown;
    struct nbp_test_details_t* firstTest;
    struct nbp_test_details_t* lastTest;
    struct nbp_module_details_t* parent;
    struct nbp_module_details_t* firstSubmodule;
    struct nbp_module_details_t* lastSubmodule;
    struct nbp_module_details_t* next;
    struct nbp_module_details_t* prev;
    unsigned int numTests;
    unsigned int numCompletedTests;
    unsigned int numSubmodules;
    unsigned int numCompletedSubmodules;
    unsigned int moduleState;
    unsigned int deepth;
};
typedef struct nbp_module_details_t nbp_module_details_t;

typedef void (*nbp_scheduler_init_pfn_t)(void);
typedef void (*nbp_scheduler_uninit_pfn_t)(void);
typedef void (*nbp_scheduler_run_pfn_t)(void);
typedef void (*nbp_scheduler_add_test_pfn_t)(nbp_test_details_t*);
struct nbp_scheduler_interface_t {
    nbp_scheduler_init_pfn_t init;
    nbp_scheduler_uninit_pfn_t uninit;
    nbp_scheduler_run_pfn_t run;
    nbp_scheduler_add_test_pfn_t addTest;
};
typedef struct nbp_scheduler_interface_t nbp_scheduler_interface_t;

typedef void (*nbp_printer_init_pfn_t)(
    void
);
typedef void (*nbp_printer_uninit_pfn_t)(
    void
);
typedef void (*nbp_printer_test_begin_pfn_t)(
    nbp_test_details_t*
);
typedef void (*nbp_printer_test_end_pfn_t)(
    nbp_test_details_t*
);
typedef void (*nbp_printer_module_begin_pfn_t)(
    nbp_module_details_t*
);
typedef void (*nbp_printer_module_end_pfn_t)(
    nbp_module_details_t*
);
typedef void (*nbp_printer_check_result_pfn_t)(
    nbp_test_details_t*
);
struct nbp_printer_interface_t {
    nbp_printer_init_pfn_t init;
    nbp_printer_uninit_pfn_t uninit;
    nbp_printer_test_begin_pfn_t testBegin;
    nbp_printer_test_end_pfn_t testEnd;
    nbp_printer_module_begin_pfn_t moduleBegin;
    nbp_printer_module_end_pfn_t moduleEnd;
    nbp_printer_check_result_pfn_t checkResult;
};
typedef struct nbp_printer_interface_t nbp_printer_interface_t;

void nbp_call_test(
    nbp_test_details_t*,
    nbp_module_details_t*,
    nbp_before_test_pfn_t,
    nbp_after_test_pfn_t
);

void nbp_call_module(
    nbp_module_details_t*,
    nbp_module_details_t*
);

void nbp_notify_printer_test_begin(
    nbp_test_details_t*
);

void nbp_notify_printer_test_end(
    nbp_test_details_t*
);

void nbp_notify_printer_module_begin(
    nbp_module_details_t*
);

void nbp_notify_printer_module_end(
    nbp_module_details_t*
);

/******************************************************************************
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                 Public API                                 *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_CHECK(cond)                                                        \
    if (cond) {                                                                \
        testDetails->passedChecks++;                                           \
    } else {                                                                   \
        testDetails->failedChecks++;                                           \
    }

/*
 * TODO: add docs
 */
#define NBP_ASSERT(cond)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT(cond)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT(cond)

/*
 * TODO: add docs
 */
#define NBP_TEST(name)                                                         \
    void name(                                                                 \
        nbp_test_details_t*                                                    \
    );                                                                         \
    nbp_test_details_t nbpTestDetails ## name = {                              \
        .testName               = #name,                                       \
        .testFunc               = name,                                        \
        .beforeTestFunc         = 0x0,                                         \
        .afterTestFunc          = 0x0,                                         \
        .module                 = 0x0,                                         \
        .passedChecks           = 0,                                           \
        .failedChecks           = 0,                                           \
        .passedTestAsserts      = 0,                                           \
        .failedTestAsserts      = 0,                                           \
        .passedModuleAsserts    = 0,                                           \
        .failedModuleAsserts    = 0,                                           \
        .passedAsserts          = 0,                                           \
        .failedAsserts          = 0,                                           \
        .testState              = NBP_TEST_STATE_NOT_INITIALIZED,              \
        .next                   = 0x0,                                         \
        .prev                   = 0x0                                          \
    };                                                                         \
    void name(                                                                 \
        nbp_test_details_t* testDetails                                        \
    )

/*
 * TODO: add docs
 */
#define NBP_CALL_TEST(name)                                                    \
    extern nbp_test_details_t nbpTestDetails ## name;                          \
    nbp_call_test(                                                             \
        & nbpTestDetails ## name,                                              \
        moduleDetails,                                                         \
        beforeTest,                                                            \
        afterTest                                                              \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE(name)                                                       \
    void name(                                                                 \
        nbp_module_details_t*,                                                 \
        nbp_before_test_pfn_t,                                                 \
        nbp_after_test_pfn_t                                                   \
    );                                                                         \
    nbp_module_details_t nbpModuleDetails ## name = {                          \
        .moduleName             = #name,                                       \
        .moduleFunc             = name,                                        \
        .setup                  = 0x0,                                         \
        .teardown               = 0x0,                                         \
        .firstTest              = 0x0,                                         \
        .lastTest               = 0x0,                                         \
        .parent                 = 0x0,                                         \
        .firstSubmodule         = 0x0,                                         \
        .lastSubmodule          = 0x0,                                         \
        .next                   = 0x0,                                         \
        .prev                   = 0x0,                                         \
        .numTests               = 0,                                           \
        .numCompletedTests      = 0,                                           \
        .numSubmodules          = 0,                                           \
        .numCompletedSubmodules = 0,                                           \
        .moduleState            = NBP_MODULE_STATE_NOT_INITIALIZED,            \
        .deepth                 = 0,                                           \
    };                                                                         \
    void name(                                                                 \
        nbp_module_details_t* moduleDetails,                                   \
        nbp_before_test_pfn_t beforeTest,                                      \
        nbp_after_test_pfn_t afterTest                                         \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE_METHODS(name, setupFunc, teardownFunc)                      \
    void name(                                                                 \
        nbp_module_details_t*,                                                 \
        nbp_before_test_pfn_t,                                                 \
        nbp_after_test_pfn_t                                                   \
    );                                                                         \
    nbp_module_details_t nbpModuleDetails ## name = {                          \
        .moduleName             = #name,                                       \
        .moduleFunc             = name,                                        \
        .setup                  = setupFunc,                                   \
        .teardown               = teardownFunc,                                \
        .firstTest              = 0x0,                                         \
        .lastTest               = 0x0,                                         \
        .parent                 = 0x0,                                         \
        .firstSubmodule         = 0x0,                                         \
        .lastSubmodule          = 0x0,                                         \
        .next                   = 0x0,                                         \
        .prev                   = 0x0,                                         \
        .numTests               = 0,                                           \
        .numCompletedTests      = 0,                                           \
        .numSubmodules          = 0,                                           \
        .numCompletedSubmodules = 0,                                           \
        .moduleState            = NBP_MODULE_STATE_NOT_INITIALIZED,            \
        .deepth                 = 0,                                           \
    };                                                                         \
    void name(                                                                 \
        nbp_module_details_t* moduleDetails,                                   \
        nbp_before_test_pfn_t beforeTest,                                      \
        nbp_after_test_pfn_t afterTest                                         \
    )

/*
 * TODO: add docs
 */
#define NBP_CALL_MODULE(name)                                                  \
    extern nbp_module_details_t nbpModuleDetails ## name;                      \
    (void)(beforeTest);                                                        \
    (void)(afterTest);                                                         \
    nbp_call_module(                                                           \
        & nbpModuleDetails ## name,                                            \
        moduleDetails                                                          \
    )

/*
 * TODO: add docs
 */
#define NBP_CALL_BEFORE_TEST(func)                                             \
    beforeTest = func

/*
 * TODO: add docs
 */
#define NBP_CALL_AFTER_TEST(func)                                              \
    afterTest = func

/*
 * TODO: add docs
 */
#define NBP_BEFORE_TEST(name)                                                  \
    void name(void)

/*
 * TODO: add docs
 */
#define NBP_AFTER_TEST(name)                                                   \
    void name(void)

/*
 * TODO: add docs
 */
#define NBP_SETUP_MODULE(name)                                                 \
    void name(void)

/*
 * TODO: add docs
 */
#define NBP_TEARDOWN_MODULE(name)                                              \
    void name(void)

/*
 * TODO: add docs
 */
#ifdef NBP_LIBRARY_MAIN

/******************************************************************************
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                              Memory allocator                              *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#ifndef NBP_CUSTOM_MEMORY_ALLOCATOR

#include <stdlib.h>
#define NBP_ALLOC malloc
#define NBP_FREE free

#else // if custom memory allocator is enabled

#ifndef NBP_ALLOC
#error "Custom memory allocator is enabled but no alloc function is provided"
#endif // end if NBP_ALLOC

#ifndef NBP_FREE
#error "Custom memory allocator is enabled but no free function is provided"
#endif // end if NBP_FREE

#endif // end if NBP_CUSTOM_MEMORY_ALLOCATOR

/******************************************************************************
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                 Scheduler                                  *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#ifdef NBP_CUSTOM_SCHEDULER
#error "Not supported"
#endif // end if NBP_CUSTOM_SCHEDULER

/*
 * TODO: add docs
 */
#ifdef NBP_FIFO_MT_SCHEDULER
#error "Not supported"
#endif // end if NBP_FIFO_MT_SCHEDULER

/*
 * TODO: add docs
 */
#ifdef NBP_SCHEDULER

struct nbp_scheduler_data_t {
    nbp_test_details_t* test;
    struct nbp_scheduler_data_t* next;
};
typedef struct nbp_scheduler_data_t nbp_schedular_data_t;

nbp_schedular_data_t nbpSchedulerData;
nbp_schedular_data_t* nbpSchedulerDataLast;

void nbp_basic_scheduler_setup_module(nbp_module_details_t* module)
{
    if (module == 0x0) {
        return;
    }

    if (module->moduleState == NBP_MODULE_STATE_RUNNING) {
        return;
    }

    nbp_basic_scheduler_setup_module(module->parent);

    module->moduleState = NBP_MODULE_STATE_RUNNING;
    nbp_notify_printer_module_begin(module);
    if (module->setup) {
        module->setup();
    }
}

void nbp_basic_scheduler_run_test(nbp_test_details_t* test)
{
    test->testState = NBP_TEST_STATE_RUNNING;

    nbp_notify_printer_test_begin(test);

    if (test->beforeTestFunc) {
        test->beforeTestFunc();
    }

    test->testFunc(test);

    if (test->afterTestFunc) {
        test->afterTestFunc();
    }

    nbp_notify_printer_test_end(test);

    test->testState = NBP_TEST_STATE_COMPLETED;

    test->module->numCompletedTests++;
}

void nbp_basic_scheduler_teardown_module(nbp_module_details_t* module)
{
    while (module->numTests == module->numCompletedTests &&
        module->numSubmodules == module->numCompletedSubmodules) {
        if (module->teardown) {
            module->teardown();
        }
        nbp_notify_printer_module_end(module);
        module->moduleState = NBP_MODULE_STATE_COMPLETED;

        module = module->parent;
        module->numCompletedSubmodules++;
    }
}

void nbp_basic_scheduler_init(void)
{
    nbpSchedulerData.test = 0x0;
    nbpSchedulerData.next = 0x0;
    nbpSchedulerDataLast = &nbpSchedulerData;
}

void nbp_basic_scheduler_uninit(void)
{
    nbp_schedular_data_t* data = nbpSchedulerData.next;
    nbp_schedular_data_t* tmp = 0x0;
    while (data != 0x0) {
        tmp = data;
        data = data->next;
        NBP_FREE(tmp);
    }
}

void nbp_basic_scheduler_run(void)
{
    nbp_schedular_data_t* data = &nbpSchedulerData;
    while (data->test != 0x0) {
        nbp_basic_scheduler_setup_module(data->test->module);
        nbp_basic_scheduler_run_test(data->test);
        nbp_basic_scheduler_teardown_module(data->test->module);
        data = data->next;
    }
}

void nbp_basic_scheduler_add_test(nbp_test_details_t* test)
{
    // TODO: check if alloc failed
    nbpSchedulerDataLast->test = test;
    nbpSchedulerDataLast->next = NBP_ALLOC(sizeof(nbp_schedular_data_t));
    nbpSchedulerDataLast = nbpSchedulerDataLast->next;
    nbpSchedulerDataLast->next = 0x0;
    nbpSchedulerDataLast->test = 0x0;
}

nbp_scheduler_interface_t nbpScheduler = {
    .init = nbp_basic_scheduler_init,
    .uninit = nbp_basic_scheduler_uninit,
    .run = nbp_basic_scheduler_run,
    .addTest = nbp_basic_scheduler_add_test
};

#endif // end if NBP_SCHEDULER

/******************************************************************************
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                  Printer                                   *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#ifdef NBP_CUSTOM_PRINTER

#error "Not supported"

#else // NBP_CUSTOM_PRINTER not defined

/*
 * If no printer is defined then enable NBP_MT_PRINTER when NPB_MT_SUPPORT
 * is enabled or enable NBP_PRINTER when NBP_MT_SUPPORT is disabled
 */
#if !defined NBP_MT_PRINTER && !defined NBP_PRINTER
#ifdef NBP_MT_SUPPORT
#define NBP_MT_PRINTER
#else // NBP_MT_SUPPORT not defined
#define NBP_PRINTER
#endif // end if NBP_MT_SUPPORT
#endif // end if ! NBP_MT_PRINTER && ! NBP_PRINTER

#endif // end if NBP_CUSTOM_PRINTER

/*
 * TODO: add docs
 */
#ifdef NBP_MT_PRINTER

/*
 * Check if NBP_MT_SUPPORT is enabled because NBP_MT_PRINTER can be enabled
 * by integrator and NBP_MT_PRINTER is multi thread.
 */
#ifndef NBP_MT_SUPPORT
#error "Cannot enable NBP_MT_PRINTER if NBP_MT_SUPPORT is not enabled"
#endif // end if NBP_MT_SUPPORT

#error "Not supported"

#endif // end if NBP_MT_PRINTER

/*
 * TODO: add docs
 */
#ifdef NBP_PRINTER

/*
 * Check if NBP_MT_SUPPORT is not enabled because NBP_PRINTER can be enabled
 * by integrator and NBP_PRINTER is single thread.
 */
#ifdef NBP_MT_SUPPORT
#error "Cannot enable NBP_PRINTER if NBP_MT_SUPPORT is enabled"
#endif // end if NBP_MT_SUPPORT

#include <stdio.h>

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"

void nbp_printer_print_deepth(unsigned int deepth)
{
    while (deepth-- > 0) {
        printf("    ");
    }
}

void nbp_printer_init()
{
    return;
}

void nbp_printer_uninit()
{
    return;
}

void nbp_printer_test_begin(nbp_test_details_t* test)
{
    nbp_printer_print_deepth(test->module->deepth + 1);
    printf(KBLU "%s\n" KNRM, test->testName);
}

void nbp_printer_test_end(nbp_test_details_t* test)
{
    nbp_printer_print_deepth(test->module->deepth + 1);
    printf(KGRN "%s\n" KNRM, test->testName);
}

void nbp_printer_module_begin(nbp_module_details_t* module)
{
    nbp_printer_print_deepth(module->deepth);
    printf("%s\n", module->moduleName);
    return;
}

void nbp_printer_module_end(nbp_module_details_t* module)
{
    (void)(module);
    return;
}

void nbp_printer_check_result(nbp_test_details_t* test)
{
    (void)(test);
    return;
}

nbp_printer_interface_t nbpPrinter = {
    .init = nbp_printer_init,
    .uninit = nbp_printer_uninit,
    .testBegin = nbp_printer_test_begin,
    .testEnd = nbp_printer_test_end,
    .moduleBegin = nbp_printer_module_begin,
    .moduleEnd = nbp_printer_module_end,
    .checkResult = nbp_printer_check_result,
};

#undef KNRM
#undef KRED
#undef KGRN
#undef KYEL
#undef KBLU

#endif // end if NBP_PRINTER

/******************************************************************************
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                Main module                                 *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

#define NBP_PRIVATE_MAIN_MODULE(name, scheduler, printers, setupFunc,          \
    teardownFunc)                                                              \
    void name(                                                                 \
        nbp_module_details_t*,                                                 \
        nbp_before_test_pfn_t,                                                 \
        nbp_after_test_pfn_t                                                   \
    );                                                                         \
    nbp_scheduler_interface_t* nbpSchedulerPtr = 0x0;                          \
    nbp_printer_interface_t* nbpPrinters[] = printers;                         \
    int nbpPrintersSize = sizeof(nbpPrinters) / sizeof(nbpPrinters[0]);        \
    int main(int argc, const char** argv)                                      \
    {                                                                          \
        (void)(argc);                                                          \
        (void)(argv);                                                          \
        nbpSchedulerPtr = &scheduler;                                          \
        if (scheduler.init == 0x0 || scheduler.uninit == 0x0 ||                \
            scheduler.run == 0x0 || scheduler.addTest == 0x0) {                \
                return -1;                                                     \
        }                                                                      \
        nbpSchedulerPtr->init();                                               \
        extern nbp_module_details_t nbpModuleDetails ## name;                  \
        nbp_call_module(& nbpModuleDetails ## name, 0x0);                      \
        nbpSchedulerPtr->run();                                                \
        nbpSchedulerPtr->uninit();                                             \
        return 0;                                                              \
    }                                                                          \
    NBP_MODULE_METHODS(name, setupFunc, teardownFunc)

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE(name)                                                  \
    NBP_PRIVATE_MAIN_MODULE(                                                   \
        name,                                                                  \
        nbpScheduler,                                                          \
        { &nbpPrinter },                                                       \
        0x0,                                                                   \
        0x0                                                                    \
    )

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE_METHODS(name, setupFunc, teardownFunc)                 \
    NBP_PRIVATE_MAIN_MODULE(                                                   \
        name,                                                                  \
        nbpScheduler,                                                          \
        { &nbpPrinter },                                                       \
        setupFunc,                                                             \
        teardownFunc                                                           \
    )

/******************************************************************************
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                     Internal functions implementation                      *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

void nbp_call_test(nbp_test_details_t* test, nbp_module_details_t* module,
    nbp_before_test_pfn_t beforeTest, nbp_after_test_pfn_t afterTest)
{
    test->testState = NBP_TEST_STATE_READY;
    test->module = module;
    test->beforeTestFunc = beforeTest;
    test->afterTestFunc = afterTest;
    test->module->numTests++;

    if (module->firstTest == 0x0) {
        module->firstTest = test;
        module->lastTest = test;
    } else {
        test->prev = module->lastTest;
        module->lastTest->next = test;
        module->lastTest = test;
    }

    if (module->moduleState == NBP_MODULE_STATE_SKIPPED) {
        test->testState = NBP_TEST_STATE_SKIPPED;
    }

    extern nbp_scheduler_interface_t* nbpSchedulerPtr;
    nbpSchedulerPtr->addTest(test);
}

void nbp_call_module(nbp_module_details_t* module, nbp_module_details_t* parent)
{
    module->moduleState = NBP_MODULE_STATE_READY;
    module->parent = parent;

    if (parent != 0x0) {
        if (parent->firstSubmodule == 0x0) {
            parent->firstSubmodule = module;
            parent->lastSubmodule = module;
        } else {
            module->prev = parent->lastSubmodule;
            parent->lastSubmodule->next = module;
            parent->lastSubmodule = module;
        }

        if (parent->moduleState == NBP_MODULE_STATE_SKIPPED) {
            module->moduleState = NBP_MODULE_STATE_SKIPPED;
        }

        module->deepth = parent->deepth + 1;
    }

    module->moduleFunc(module, 0x0, 0x0);
}

extern nbp_printer_interface_t* nbpPrinters[];
extern int nbpPrintersSize;

void nbp_notify_printer_test_begin(nbp_test_details_t* test)
{
    for (int i = 0; i < nbpPrintersSize; i++) {
        nbpPrinters[i]->testBegin(test);
    }
}

void nbp_notify_printer_test_end(nbp_test_details_t* test)
{
    for (int i = 0; i < nbpPrintersSize; i++) {
        nbpPrinters[i]->testEnd(test);
    }
}

void nbp_notify_printer_module_begin(nbp_module_details_t* module)
{
    for (int i = 0; i < nbpPrintersSize; i++) {
        nbpPrinters[i]->moduleBegin(module);
    }
}

void nbp_notify_printer_module_end(nbp_module_details_t* module)
{
    for (int i = 0; i < nbpPrintersSize; i++) {
        nbpPrinters[i]->moduleEnd(module);
    }
}

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_LIBRARY_H

