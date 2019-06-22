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

#define NBP_ERROR_ALLOC                                         (int) 1
#define NBP_ERROR_TEST_ALREADY_CALLED                           (int) 2
#define NBP_ERROR_MODULE_ALREADY_CALLED                         (int) 3
#define NBP_ERROR_SCHEDULER_NO_INIT_FUNC                        (int) 4
#define NBP_ERROR_SCHEDULER_NO_UNINIT_FUNC                      (int) 5
#define NBP_ERROR_SCHEDULER_NO_RUN_FUNC                         (int) 6
#define NBP_ERROR_SCHEDULER_NO_ADD_TEST_FUNC                    (int) 7

struct nbp_test_details_t;
struct nbp_module_details_t;

typedef void (*nbp_before_test_pfn_t)(
    struct nbp_test_details_t*
);
typedef void (*nbp_after_test_pfn_t)(
    struct nbp_test_details_t*
);

typedef void(*nbp_setup_module_pfn_t)(
    struct nbp_module_details_t*
);
typedef void(*nbp_teardown_module_pfn_t)(
    struct nbp_module_details_t*
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
typedef int (*nbp_printer_uninit_pfn_t)(
    void
);
typedef void (*nbp_printer_handle_error_pfn_t)(
    int
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
    nbp_test_details_t*,
    const char*,
    int,
    int,
    const char*,
    const char*
);
struct nbp_printer_interface_t {
    nbp_printer_init_pfn_t init;
    nbp_printer_uninit_pfn_t uninit;
    nbp_printer_handle_error_pfn_t handleError;
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

void nbp_notify_printer_handle_error(
    int
);

void nbp_notify_printer_check_result(
    nbp_test_details_t*,
    const char*,
    int,
    int,
    const char*,
    const char*
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

#define NBP_PRIVATE_CHECK_BASE(cond, failMsg, passMsg)                         \
    if (cond) {                                                                \
        test->passedChecks++;                                                  \
        nbp_notify_printer_check_result(                                       \
            test,                                                              \
            #cond,                                                             \
            1,                                                                 \
            __LINE__,                                                          \
            0x0,                                                               \
            passMsg                                                            \
        );                                                                     \
    } else {                                                                   \
        test->failedChecks++;                                                  \
        nbp_notify_printer_check_result(                                       \
            test,                                                              \
            #cond,                                                             \
            0,                                                                 \
            __LINE__,                                                          \
            failMsg,                                                           \
            0x0                                                                \
        );                                                                     \
    }

/*
 * TODO: add docs
 */
#define NBP_CHECK(cond)                                                        \
    NBP_PRIVATE_CHECK_BASE(cond, 0x0, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_FAIL_MSG(cond, msg)                                          \
    NBP_PRIVATE_CHECK_BASE(cond, msg, 0x0)

/*
 * TODO: add docs
 */
#define NBP_CHECK_PASS_MSG(cond, msg)                                          \
    NBP_PRIVATE_CHECK_BASE(cond, 0x0, msg)

/*
 * TODO: add docs
 */
#define NBP_CHECK_MSG(cond, failMsg, passMsg)                                  \
    NBP_PRIVATE_CHECK_BASE(cond, failMsg, passMsg)

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
#define NBP_BEFORE_TEST(name)                                                  \
    void name(nbp_test_details_t* test)

/*
 * TODO: add docs
 */
#define NBP_CALL_BEFORE_TEST(func)                                             \
    NBP_BEFORE_TEST(func);                                                     \
    beforeTest = func

/*
 * TODO: add docs
 */
#define NBP_RESET_BEFORE_TEST()                                                \
    beforeTest = 0x0

/*
 * TODO: add docs
 */
#define NBP_AFTER_TEST(name)                                                   \
    void name(nbp_test_details_t* test)

/*
 * TODO: add docs
 */
#define NBP_CALL_AFTER_TEST(func)                                              \
    NBP_AFTER_TEST(func);                                                      \
    afterTest = func

/*
 * TODO: add docs
 */
#define NBP_RESET_AFTER_TEST()                                                 \
    afterTest = 0x0

/*
 * TODO: add docs
 */
#define NBP_NO_SETUP_FUNC                                                      \
    nbp_empty_setup_func

/*
 * TODO: add docs
 */
#define NBP_SETUP_MODULE(name)                                                 \
    void name(nbp_module_details_t* module)

/*
 * TODO: add docs
 */
#define NBP_NO_TEARDOWN_FUNC                                                   \
    nbp_empty_teardown_func

/*
 * TODO: add docs
 */
#define NBP_TEARDOWN_MODULE(name)                                              \
    void name(nbp_module_details_t* module)

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
        nbp_test_details_t* test                                               \
    )

/*
 * TODO: add docs
 */
#define NBP_CALL_TEST(name)                                                    \
    extern nbp_test_details_t nbpTestDetails ## name;                          \
    nbp_call_test(                                                             \
        & nbpTestDetails ## name,                                              \
        module,                                                                \
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
        nbp_module_details_t* module,                                          \
        nbp_before_test_pfn_t beforeTest,                                      \
        nbp_after_test_pfn_t afterTest                                         \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE_FIXTURES(name, setupFunc, teardownFunc)                     \
    void name(                                                                 \
        nbp_module_details_t*,                                                 \
        nbp_before_test_pfn_t,                                                 \
        nbp_after_test_pfn_t                                                   \
    );                                                                         \
    NBP_SETUP_MODULE(setupFunc);                                               \
    NBP_TEARDOWN_MODULE(teardownFunc);                                         \
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
        nbp_module_details_t* module,                                          \
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
        module                                                                 \
    )

/*
 * TODO: add docs
 */
#define NBP_THIS_TEST test

/*
 * TODO: add docs
 */
#define NBP_THIS_MODULE module

/*
 * TODO: add docs
 */
#define NBP_GET_TEST_NAME(test) test->testName

/*
 * TODO: add docs
 */
#define NBP_GET_MODULE_NAME(module) module->moduleName

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
typedef struct nbp_scheduler_data_t nbp_scheduler_data_t;

nbp_scheduler_data_t nbpSchedulerData;
nbp_scheduler_data_t* nbpSchedulerDataLast;

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
        module->setup(module);
    }
}

void nbp_basic_scheduler_run_test(nbp_test_details_t* test)
{
    test->testState = NBP_TEST_STATE_RUNNING;

    nbp_notify_printer_test_begin(test);

    if (test->beforeTestFunc) {
        test->beforeTestFunc(test);
    }

    test->testFunc(test);

    if (test->afterTestFunc) {
        test->afterTestFunc(test);
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
            module->teardown(module);
        }
        nbp_notify_printer_module_end(module);
        module->moduleState = NBP_MODULE_STATE_COMPLETED;

        module = module->parent;
        if (module == 0x0) {
            break;
        }

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
    nbp_scheduler_data_t* data = nbpSchedulerData.next;
    nbp_scheduler_data_t* tmp = 0x0;
    while (data != 0x0) {
        tmp = data;
        data = data->next;
        NBP_FREE(tmp);
    }
}

void nbp_basic_scheduler_run(void)
{
    nbp_scheduler_data_t* data = &nbpSchedulerData;
    while (data->test != 0x0) {
        nbp_basic_scheduler_setup_module(data->test->module);
        nbp_basic_scheduler_run_test(data->test);
        nbp_basic_scheduler_teardown_module(data->test->module);
        data = data->next;
    }
}

void nbp_basic_scheduler_add_test(nbp_test_details_t* test)
{
    nbpSchedulerDataLast->test = test;
    nbpSchedulerDataLast->next =
        (nbp_scheduler_data_t*) NBP_ALLOC(sizeof(nbp_scheduler_data_t));

    if (nbpSchedulerDataLast->next == 0x0) {
        nbp_notify_printer_handle_error(NBP_ERROR_ALLOC);
        return;
    }

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

/*
 * Default nbp printer for Linux
 */
#ifdef NBP_OS_LINUX

#include <stdio.h>
#include <string.h>

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"

struct NbpPrinterPassMsgList {
    char* msg;
    char* cond;
    int line;
    struct NbpPrinterPassMsgList* next;
};

int nbpPrinterRet;
int nbpPrinterTestFailed;
struct NbpPrinterPassMsgList* nbpPrinterFirstPassMsg;
struct NbpPrinterPassMsgList* nbpPrinterLastPassMsg;

void nbp_printer_print_deepth(unsigned int deepth)
{
    printf("\r");
    while (deepth-- > 0) {
        printf("    ");
    }
}

char* nbp_printer_duplicate_str(const char* str)
{
    char* dup = (char*) NBP_ALLOC(strlen(str));
    if (dup != 0x0) {
        strcpy(dup, str);
    }
    return dup;
}

void nbp_printer_add_pass_msg(const char* cond, const char* msg, int line)
{
    struct NbpPrinterPassMsgList* tmp = (struct NbpPrinterPassMsgList*)
        NBP_ALLOC(sizeof(struct NbpPrinterPassMsgList));

    do {
        if (tmp == 0x0) {
            nbp_notify_printer_handle_error(NBP_ERROR_ALLOC);
            break;
        }

        tmp->cond = nbp_printer_duplicate_str(cond);
        if (tmp->cond == 0x0) {
            nbp_notify_printer_handle_error(NBP_ERROR_ALLOC);
            break;
        }

        tmp->msg = nbp_printer_duplicate_str(msg);
        if (tmp->msg == 0x0) {
            nbp_notify_printer_handle_error(NBP_ERROR_ALLOC);
        }

        tmp->line = line;
        tmp->next = 0x0;

        if (nbpPrinterLastPassMsg == 0x0) {
            nbpPrinterFirstPassMsg = tmp;
            nbpPrinterLastPassMsg  = tmp;
        } else {
            nbpPrinterLastPassMsg->next = tmp;
            nbpPrinterLastPassMsg       = tmp;
        }

        return;
    } while (0);

    if (tmp != 0x0) {
        if (tmp->cond != 0x0) {
            NBP_FREE(tmp->cond);
        }
        if (tmp->msg != 0x0) {
            NBP_FREE(tmp->msg);
        }
        NBP_FREE(tmp);
    }
}

void nbp_printer_print_pass_msg(nbp_test_details_t* test)
{
    struct NbpPrinterPassMsgList* tmp = 0x0;

    while (nbpPrinterFirstPassMsg != 0x0) {
        nbp_printer_print_deepth(test->module->deepth + 2);
        printf(KGRN "%s passed (%s) (%d)" KNRM "\n",
            nbpPrinterFirstPassMsg->cond,
            nbpPrinterFirstPassMsg->msg,
            nbpPrinterFirstPassMsg->line
        );

        tmp = nbpPrinterFirstPassMsg;
        nbpPrinterFirstPassMsg = nbpPrinterFirstPassMsg->next;

        NBP_FREE(tmp->cond);
        NBP_FREE(tmp->msg);
        NBP_FREE(tmp);
    }

    nbpPrinterLastPassMsg = 0x0;
}

void nbp_printer_init(void)
{
    nbpPrinterRet           = 0;
    nbpPrinterTestFailed    = 0;
    nbpPrinterFirstPassMsg  = 0x0;
    nbpPrinterLastPassMsg   = 0x0;
}

int nbp_printer_uninit(void)
{
    return nbpPrinterRet;
}

void nbp_printer_test_end(nbp_test_details_t* test)
{
    if (nbpPrinterTestFailed == 0) {
        nbp_printer_print_deepth(test->module->deepth + 1);
        printf(KGRN "%s" KNRM "\n", test->testName);
        nbp_printer_print_pass_msg(test);
    } else {
        nbpPrinterTestFailed = 0;
    }
}

void nbp_printer_module_begin(nbp_module_details_t* module)
{
    nbp_printer_print_deepth(module->deepth);
    printf("%s\n", module->moduleName);
}

void nbp_printer_check_result(nbp_test_details_t* test, const char* cond,
    int passed, int line, const char* failMsg, const char* passMsg)
{
    if (passed == 1) {
        if (passMsg == 0x0) {
            return;
        }

        if (nbpPrinterTestFailed == 1) {
            nbp_printer_print_deepth(test->module->deepth + 2);
            printf(KGRN "%s passed (%s) (%d)" KNRM "\n", cond, passMsg, line);
        } else {
            nbp_printer_add_pass_msg(cond, passMsg, line);
        }
        return;
    }

    if (nbpPrinterTestFailed == 0) {
        nbpPrinterTestFailed = 1;
        nbpPrinterRet        = 1;

        nbp_printer_print_deepth(test->module->deepth + 1);
        printf(KRED "%s" KNRM "\n", test->testName);

        nbp_printer_print_pass_msg(test);
    }

    if (failMsg != 0x0) {
        nbp_printer_print_deepth(test->module->deepth + 2);
        printf(KRED "%s failed (%s) (%d)" KNRM "\n", cond, failMsg, line);
    } else {
        nbp_printer_print_deepth(test->module->deepth + 2);
        printf(KRED "%s failed (%d)" KNRM "\n", cond, line);
    }
}

nbp_printer_interface_t nbpPrinter = {
    .init           = nbp_printer_init,
    .uninit         = nbp_printer_uninit,
    .handleError    = 0x0,
    .testBegin      = 0x0,
    .testEnd        = nbp_printer_test_end,
    .moduleBegin    = nbp_printer_module_begin,
    .moduleEnd      = 0x0,
    .checkResult    = nbp_printer_check_result,
};

#elif defined NBP_OS_WINDOWS
/*
 * Default nbp printer for Windows
 */

#error "Not supported"

#elif defined NBP_OS_MAC
/*
 * Default nbp printer for Mac
 */

#error "Not supported"

#endif // end if NBP_OS_MAC

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

#define NBP_PRIVATE_MAIN_MODULE(name, scheduler, printers, setupFunc,          \
    teardownFunc)                                                              \
    void name(                                                                 \
        nbp_module_details_t*,                                                 \
        nbp_before_test_pfn_t,                                                 \
        nbp_after_test_pfn_t                                                   \
    );                                                                         \
    extern nbp_module_details_t nbpModuleDetails ## name;                      \
    nbp_module_details_t* nbpMainModule = & nbpModuleDetails ## name;          \
    nbp_scheduler_interface_t* nbpSchedulerInterface = &scheduler;             \
    nbp_printer_interface_t* nbpPrinterInterfaces[] = printers;                \
    unsigned int nbpPrinterInterfacesSize =                                    \
        sizeof(nbpPrinterInterfaces) / sizeof(nbpPrinterInterfaces[0]);        \
    NBP_MODULE_FIXTURES(name, setupFunc, teardownFunc)

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE(name)                                                  \
    NBP_PRIVATE_MAIN_MODULE(                                                   \
        name,                                                                  \
        nbpScheduler,                                                          \
        { &nbpPrinter },                                                       \
        nbp_empty_setup_func,                                                  \
        nbp_empty_teardown_func                                                \
    )

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE_FIXTURES(name, setupFunc, teardownFunc)                \
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
    if (test->testState != NBP_TEST_STATE_NOT_INITIALIZED) {
        nbp_notify_printer_handle_error(NBP_ERROR_TEST_ALREADY_CALLED);
        return;
    }

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

    nbpSchedulerInterface->addTest(test);
}

void nbp_call_module(nbp_module_details_t* module, nbp_module_details_t* parent)
{
    if (module->moduleState != NBP_MODULE_STATE_NOT_INITIALIZED) {
        nbp_notify_printer_handle_error(NBP_ERROR_MODULE_ALREADY_CALLED);
        return;
    }

    module->moduleState = NBP_MODULE_STATE_READY;
    module->parent = parent;

    if (parent != 0x0) {
        parent->numSubmodules++;
        if (parent->firstSubmodule == 0x0) {
            parent->firstSubmodule = module;
            parent->lastSubmodule = module;
        } else {
            module->prev = parent->lastSubmodule;
            parent->lastSubmodule->next = module;
            parent->lastSubmodule = module;
        }

        module->deepth = parent->deepth + 1;
    }

    module->moduleFunc(module, 0x0, 0x0);
}

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

NBP_SETUP_MODULE(nbp_empty_setup_func)
{
    (void)(NBP_THIS_MODULE);
}

NBP_TEARDOWN_MODULE(nbp_empty_teardown_func)
{
    (void)(NBP_THIS_MODULE);
}

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_LIBRARY_H

