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

#ifndef NBP_PRIVATE_PRINTER_LINUX_PRINTER_H
#define NBP_PRIVATE_PRINTER_LINUX_PRINTER_H

#include <stdio.h>
#include <string.h>

#define NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL              "\x1B[0m"
#define NBP_LINUX_PRINTER_PRIVATE_COLOR_RED                 "\x1B[31m"
#define NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN               "\x1B[32m"
#define NBP_LINUX_PRINTER_PRIVATE_COLOR_YELLOW              "\x1B[33m"

#define NBP_LINUX_PRINTER_PRIVATE_CLEAR_LINE                "\x1B[2K\r"

#define NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_UNKNOWN      (unsigned int) 0x50000000
#define NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_TEST         (unsigned int) 0x50000001
#define NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_MODULE       (unsigned int) 0x50000002

#define NBP_LINUX_PRINTER_PRIVATE_GENERATE_CONDITION(buff, size)               \

#ifdef NBP_MT_SUPPORT

#include <pthread.h>

static inline NBP_ERROR_CODE_TYPE nbp_linux_printer_mutex_init(
    pthread_mutex_t* mutex)
{
    return pthread_mutex_init(mutex, NULL) == 0
        ? NBP_ERROR_CODE_SUCCESS
        : NBP_ERROR_CODE_SYNC_ERROR;
}

static inline NBP_ERROR_CODE_TYPE nbp_linux_printer_mutex_uninit(
    pthread_mutex_t* mutex)
{
    return pthread_mutex_destroy(mutex) == 0
        ? NBP_ERROR_CODE_SUCCESS
        : NBP_ERROR_CODE_SYNC_ERROR;
}

static inline NBP_ERROR_CODE_TYPE nbp_linux_printer_mutex_lock(
    pthread_mutex_t* mutex)
{
    return pthread_mutex_lock(mutex) == 0
        ? NBP_ERROR_CODE_SUCCESS
        : NBP_ERROR_CODE_SYNC_ERROR;
}

static inline NBP_ERROR_CODE_TYPE nbp_linux_printer_mutex_unlock(
    pthread_mutex_t* mutex)
{
    return pthread_mutex_unlock(mutex) == 0
        ? NBP_ERROR_CODE_SUCCESS
        : NBP_ERROR_CODE_SYNC_ERROR;
}

#define NBP_LINUX_PRINTER_PRIVATE_DECLARE_MUTEX(name)                          \
    pthread_mutex_t name = PTHREAD_MUTEX_INITIALIZER;

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_INIT(name)                             \
    nbp_linux_printer_mutex_init(&name)

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNINIT(name)                           \
    nbp_linux_printer_mutex_uninit(&name)

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_LOCK(name)                             \
    nbp_linux_printer_mutex_lock(&name)

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNLOCK(name)                           \
    nbp_linux_printer_mutex_unlock(&name)

#else // NBP_MT_SUPPORT not defined

static inline NBP_ERROR_CODE_TYPE nbp_linux_printer_mutex_init_empty()
{
    return NBP_ERROR_CODE_SUCCESS;
}

static inline NBP_ERROR_CODE_TYPE nbp_linux_printer_mutex_uninit_empty()
{
    return NBP_ERROR_CODE_SUCCESS;
}

static inline NBP_ERROR_CODE_TYPE nbp_linux_printer_mutex_lock_empty()
{
    return NBP_ERROR_CODE_SUCCESS;
}

static inline NBP_ERROR_CODE_TYPE nbp_linux_printer_mutex_unlock_empty()
{
    return NBP_ERROR_CODE_SUCCESS;
}

#define NBP_LINUX_PRINTER_PRIVATE_DECLARE_MUTEX(name)

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_INIT(name)                             \
    nbp_linux_printer_mutex_init_empty()

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNINIT(name)                           \
    nbp_linux_printer_mutex_uninit_empty()

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_LOCK(name)                             \
    nbp_linux_printer_mutex_lock_empty()

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNLOCK(name)                           \
    nbp_linux_printer_mutex_unlock_empty()

#endif // end if NBP_MT_SUPPORT

struct nbp_linux_printer_messages_list_t {
    char* message;
    struct nbp_linux_printer_messages_list_t* next;
};
typedef struct nbp_linux_printer_messages_list_t nbp_linux_printer_messages_list_t;

struct nbp_linux_printer_test_t {
    nbp_test_details_t* test;
    nbp_linux_printer_messages_list_t* messages;
    nbp_linux_printer_messages_list_t* messagesLast;
};
typedef struct nbp_linux_printer_test_t nbp_linux_printer_test_t;

struct nbp_linux_printer_module_t {
    nbp_module_details_t* module;
};
typedef struct nbp_linux_printer_module_t nbp_linux_printer_module_t;

struct nbp_linux_printer_data_t {
    unsigned int type;
    union {
        nbp_linux_printer_test_t test;
        nbp_linux_printer_module_t module;
    };
    struct nbp_linux_printer_data_t* next;
};
typedef struct nbp_linux_printer_data_t nbp_linux_printer_data_t;

static nbp_linux_printer_data_t* nbpLinuxPrinterData;
static nbp_linux_printer_data_t* nbpLinuxPrinterDataLast;

static unsigned int nbpLinuxPrinterModulesNum;
static unsigned int nbpLinuxPrinterTestsNum;
static unsigned int nbpLinuxPrinterCompletedTestsNum;

NBP_LINUX_PRINTER_PRIVATE_DECLARE_MUTEX(nbpLinuxPrinterMutex);

static char* nbp_linux_printer_duplicate_str(const char* str)
{
    char* dup = (char*) NBP_MEMORY_ALLOC(strlen(str) + 1);
    if (dup != NBP_MEMORY_NULL_POINTER) {
        strcpy(dup, str);
    }
    return dup;
}

static nbp_linux_printer_data_t* nbp_linux_printer_create_data_from_test(
    nbp_test_details_t* test)
{
    nbp_linux_printer_data_t* data = NBP_MEMORY_NULL_POINTER;

    do {
        data = (nbp_linux_printer_data_t*) NBP_MEMORY_ALLOC(sizeof(*data));
        if (data == NBP_MEMORY_NULL_POINTER) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for memory allocation.
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_OUT_OF_MEMORY,
                "could not allocate nbp_linux_printer_data_t struct from test"
            );
            break;
            // LCOV_EXCL_STOP
        }

        data->type              = NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_TEST;
        data->test.test         = test;
        data->test.messages     = NBP_MEMORY_NULL_POINTER;
        data->test.messagesLast = NBP_MEMORY_NULL_POINTER;
        data->next              = NBP_MEMORY_NULL_POINTER;
    } while (0);

    return data;
}

static nbp_linux_printer_data_t* nbp_linux_printer_create_data_from_module(
    nbp_module_details_t* module)
{
    nbp_linux_printer_data_t* data = NBP_MEMORY_NULL_POINTER;

    do {
        data = (nbp_linux_printer_data_t*) NBP_MEMORY_ALLOC(sizeof(*data));
        if (data == NBP_MEMORY_NULL_POINTER) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for memory allocation.
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_OUT_OF_MEMORY,
                "could not allocate nbp_linux_printer_data_t struct from module"
            );
            break;
            // LCOV_EXCL_STOP
        }

        data->type          = NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_MODULE;
        data->module.module = module;
        data->next          = NBP_MEMORY_NULL_POINTER;
    } while (0);

    return data;
}

static nbp_linux_printer_data_t* nbp_linux_printer_find_printer_test(
    nbp_test_details_t* test)
{
    nbp_linux_printer_data_t* data = nbpLinuxPrinterData;
    for ( ; data != NBP_MEMORY_NULL_POINTER; data = data->next) {
        if (data->type != NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_TEST) {
            continue;
        }

        if (data->test.test != test) {
            continue;
        }

        return data;
    }

    return NBP_MEMORY_NULL_POINTER;
}

static void nbp_linux_printer_delete_messages(
    nbp_linux_printer_messages_list_t* msg)
{
    nbp_linux_printer_messages_list_t* tmp = NBP_MEMORY_NULL_POINTER;
    while (msg != NBP_MEMORY_NULL_POINTER) {
        tmp = msg;
        msg = tmp->next;

        tmp->next = NBP_MEMORY_NULL_POINTER;

        NBP_MEMORY_FREE(tmp->message);
        NBP_MEMORY_FREE(tmp);
    }
}

static nbp_linux_printer_messages_list_t* nbp_linux_printer_create_message(
    char* msg)
{
    nbp_linux_printer_messages_list_t* message = NBP_MEMORY_NULL_POINTER;

    do {
        message = (nbp_linux_printer_messages_list_t*)
            NBP_MEMORY_ALLOC(sizeof(nbp_linux_printer_messages_list_t));

        if (message == NBP_MEMORY_NULL_POINTER) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for memory allocation.
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_OUT_OF_MEMORY,
                "could not allocate nbp_linux_printer_messages_list_t struct"
            );
            break;
            // LCOV_EXCL_STOP
        }

        message->next = NBP_MEMORY_NULL_POINTER;
        message->message = nbp_linux_printer_duplicate_str(msg);

        if (message->message == NBP_MEMORY_NULL_POINTER) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for memory allocation.
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_OUT_OF_MEMORY,
                "could not duplicate the message"
            );
            break;
            // LCOV_EXCL_STOP
        }

        return message;
    } while (0);

    if (message != NBP_MEMORY_NULL_POINTER) {
        NBP_MEMORY_FREE(message);
    }

    return NBP_MEMORY_NULL_POINTER;
}

static void nbp_linux_printer_add_message(nbp_test_details_t* test, char* msg)
{
    nbp_linux_printer_data_t* data = nbp_linux_printer_find_printer_test(test);

    if (data == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is impossible to
        // not find a test if there's no bug in nbp core.
        // LCOV_EXCL_START
        char errMsg[1024];
        snprintf(errMsg, 1024, "test [%s] not found", NBP_TEST_GET_NAME(test));
        NBP_ERROR_REPORT_CTX_STRING(NBP_ERROR_CODE_INTERNAL_ERROR, errMsg);
        return;
        // LCOV_EXCL_STOP
    }

    if (data->test.messages == NBP_MEMORY_NULL_POINTER) {
        data->test.messages = nbp_linux_printer_create_message(msg);
        data->test.messagesLast = data->test.messages;
    } else {
        data->test.messagesLast->next = nbp_linux_printer_create_message(msg);
        if (data->test.messagesLast->next != NBP_MEMORY_NULL_POINTER) {
            data->test.messagesLast = data->test.messagesLast->next;
        }
    }
}

static void nbp_linux_printer_add_assert_result(nbp_test_details_t* test,
    const char* cond, unsigned int passed, int line, const char* failMsg,
    const char* passMsg)
{
    char buffer[1024] = { 0 };

    if (passed == NBP_ASSERT_STATUS_PASSED) {
        if (passMsg == NBP_PRINTER_NO_SUCCESS_MESSAGE) {
            return;
        }

        snprintf(
            buffer,
            1024,
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN
                "%s (%s) (%d)"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            cond,
            passMsg,
            line
        );
    } else {
        if (failMsg == NBP_PRINTER_NO_FAILURE_MESSAGE) {
            snprintf(
                buffer,
                1024,
                NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
                    "%s (%d)"
                NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
                cond,
                line
            );
        } else {
            snprintf(
                buffer,
                1024,
                NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
                    "%s (%s) (%d)"
                NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
                cond,
                failMsg,
                line
            );
        }
    }

    nbp_linux_printer_add_message(test, buffer);
}

static void nbp_linux_printer_print_depth(unsigned int depth)
{
    while (depth-- > 0) {
        printf("    ");
    }
}

static void nbp_linux_printer_print_test(nbp_linux_printer_test_t* test)
{
    unsigned int state = NBP_TEST_GET_STATE(test->test);
    unsigned int depth = NBP_TEST_GET_DEPTH(test->test);

    nbp_linux_printer_print_depth(depth);
    if (state == NBP_TEST_STATE_PASSED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_TEST_GET_NAME(test->test)
        );
    } else if (state == NBP_TEST_STATE_FAILED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_TEST_GET_NAME(test->test)
        );
    } else if (state == NBP_TEST_STATE_SKIPPED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_YELLOW
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_TEST_GET_NAME(test->test)
        );
    } else {
        printf("%s\n", NBP_TEST_GET_NAME(test->test));
    }

    nbp_linux_printer_messages_list_t* msg = test->messages;
    depth++;

    while (msg != NBP_MEMORY_NULL_POINTER) {
        nbp_linux_printer_print_depth(depth);
        printf("%s", msg->message);
        msg = msg->next;
    }
}

static void nbp_linux_printer_print_module(nbp_linux_printer_module_t* module)
{
    unsigned int state = NBP_MODULE_GET_STATE(module->module);

    nbp_linux_printer_print_depth(NBP_MODULE_GET_DEPTH(module->module));
    if (state == NBP_MODULE_STATE_PASSED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_MODULE_GET_NAME(module->module)
        );
    } else if (state == NBP_MODULE_STATE_FAILED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_MODULE_GET_NAME(module->module)
        );
    } else if (state == NBP_MODULE_STATE_SKIPPED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_YELLOW
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_MODULE_GET_NAME(module->module)
        );
    } else {
        printf("%s\n", NBP_MODULE_GET_NAME(module->module));
    }
}

static void nbp_linux_printer_print_data()
{
    nbp_linux_printer_data_t* data = nbpLinuxPrinterData;

    while (data != NBP_MEMORY_NULL_POINTER) {
        if (data->type == NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_MODULE) {
            nbp_linux_printer_print_module(&data->module);
        } else if (data->type == NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_TEST) {
            nbp_linux_printer_print_test(&data->test);
        }

        data = data->next;
    }
}

NBP_PRINTER_CALLBACK_INIT(nbp_linux_printer_init)
{
    nbpLinuxPrinterData                 = NBP_MEMORY_NULL_POINTER;
    nbpLinuxPrinterDataLast             = NBP_MEMORY_NULL_POINTER;
    nbpLinuxPrinterModulesNum           = 0;
    nbpLinuxPrinterTestsNum             = 0;
    nbpLinuxPrinterCompletedTestsNum    = 0;
    NBP_LINUX_PRINTER_PRIVATE_MUTEX_INIT(nbpLinuxPrinterMutex);
}

NBP_PRINTER_CALLBACK_UNINIT(nbp_linux_printer_uninit)
{
    nbp_linux_printer_data_t* tmp = NBP_MEMORY_NULL_POINTER;
    while (nbpLinuxPrinterData != NBP_MEMORY_NULL_POINTER) {
        tmp = nbpLinuxPrinterData;
        nbpLinuxPrinterData = tmp->next;

        tmp->next = NBP_MEMORY_NULL_POINTER;

        if (tmp->type == NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_TEST) {
            nbp_linux_printer_delete_messages(tmp->test.messages);
        }

        NBP_MEMORY_FREE(tmp);
    }

    nbpLinuxPrinterDataLast = NBP_MEMORY_NULL_POINTER;

    NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNINIT(nbpLinuxPrinterMutex);
}

NBP_PRINTER_CALLBACK_REPORT_ERROR(nbp_linux_printer_report_error)
{
    NBP_LINUX_PRINTER_PRIVATE_MUTEX_LOCK(nbpLinuxPrinterMutex);

    switch (NBP_ERROR_GET_CONTEXT_TYPE(NBP_PRINTER_GET_ERROR())) {
        case NBP_ERROR_CONTEXT_STRING:
            printf(
                "\n" NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
                    "[error] code = %d, line = %d, file = %s, message = %s"
                NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
                NBP_ERROR_GET_CODE(NBP_PRINTER_GET_ERROR()),
                NBP_ERROR_GET_LINE(NBP_PRINTER_GET_ERROR()),
                NBP_ERROR_GET_FILENAME(NBP_PRINTER_GET_ERROR()),
                NBP_ERROR_GET_CONTEXT_STRING(NBP_PRINTER_GET_ERROR())
            );
            break;
        case NBP_ERROR_CONTEXT_EMPTY:
        case NBP_ERROR_CONTEXT_CUSTOM:
        default:
            printf(
                "\n" NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
                    "[error] code = %d, line = %d, file = %s"
                NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
                NBP_ERROR_GET_CODE(NBP_PRINTER_GET_ERROR()),
                NBP_ERROR_GET_LINE(NBP_PRINTER_GET_ERROR()),
                NBP_ERROR_GET_FILENAME(NBP_PRINTER_GET_ERROR())
            );
            break;
    }

    NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNLOCK(nbpLinuxPrinterMutex);
}

NBP_PRINTER_CALLBACK_HANDLE_VERSION_COMMAND(nbp_linux_printer_handle_version_command)
{
    printf("%s\n", NBP_VERSION_STR);
}

NBP_PRINTER_CALLBACK_TEST_COMPLETED(nbp_linux_printer_test_completed)
{
    NBP_LINUX_PRINTER_PRIVATE_MUTEX_LOCK(nbpLinuxPrinterMutex);

    nbpLinuxPrinterCompletedTestsNum++;

    printf(
        NBP_LINUX_PRINTER_PRIVATE_CLEAR_LINE "Running... %u/%u",
        nbpLinuxPrinterCompletedTestsNum,
        nbpLinuxPrinterTestsNum
    );
    fflush(stdout);

    NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNLOCK(nbpLinuxPrinterMutex);
}

NBP_PRINTER_CALLBACK_BEFORE_RUN(nbp_linux_printer_before_run)
{
    nbpLinuxPrinterTestsNum   = NBP_MODULE_GET_NUMBER_OF_TESTS(NBP_MODULE_THIS);
    nbpLinuxPrinterModulesNum =
        NBP_MODULE_GET_NUMBER_OF_MODULES(NBP_MODULE_THIS) + 1;

    printf("Running...");
    fflush(stdout);
}

NBP_PRINTER_CALLBACK_AFTER_RUN(nbp_linux_printer_after_run)
{
    unsigned int numPassedModules;
    unsigned int numFailedModules;
    unsigned int numSkippedModules;
    unsigned int moduleState;
    unsigned int numAsserts;
    unsigned int numPassedAsserts;
    unsigned int numFailedAsserts;

    printf(NBP_LINUX_PRINTER_PRIVATE_CLEAR_LINE);
    nbp_linux_printer_print_data();

    numPassedModules  = NBP_MODULE_GET_NUMBER_OF_PASSED_MODULES(NBP_MODULE_THIS);
    numFailedModules  = NBP_MODULE_GET_NUMBER_OF_FAILED_MODULES(NBP_MODULE_THIS);
    numSkippedModules = NBP_MODULE_GET_NUMBER_OF_SKIPPED_MODULES(NBP_MODULE_THIS);
    moduleState       = NBP_MODULE_GET_STATE(NBP_MODULE_THIS);

    if (moduleState == NBP_MODULE_STATE_PASSED) {
        numPassedModules++;
    } else if (moduleState == NBP_MODULE_STATE_FAILED) {
        numFailedModules++;
    }

    // print modules stats
    printf(
        "Passed  modules: %s%u%s/%u\n"
        "Failed  modules: %s%u%s/%u\n"
        "Skipped modules: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        numPassedModules,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterModulesNum,

        numFailedModules == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        numFailedModules,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterModulesNum,

        numSkippedModules == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_YELLOW,
        numSkippedModules,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterModulesNum
    );

    // print tests stats
    printf(
        "Passed  tests: %s%u%s/%u\n"
        "Failed  tests: %s%u%s/%u\n"
        "Skipped tests: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        NBP_MODULE_GET_NUMBER_OF_PASSED_TESTS(NBP_MODULE_THIS),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterTestsNum,

        NBP_MODULE_GET_NUMBER_OF_FAILED_TESTS(NBP_MODULE_THIS) == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        NBP_MODULE_GET_NUMBER_OF_FAILED_TESTS(NBP_MODULE_THIS),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterTestsNum,

        NBP_MODULE_GET_NUMBER_OF_SKIPPED_TESTS(NBP_MODULE_THIS) == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_YELLOW,
        NBP_MODULE_GET_NUMBER_OF_SKIPPED_TESTS(NBP_MODULE_THIS),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterTestsNum
    );

    // print checks stats

    numAsserts = NBP_MODULE_GET_NUMBER_OF_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_NON_FATAL
    );
    numPassedAsserts = NBP_MODULE_GET_NUMBER_OF_PASSED_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_NON_FATAL
    );
    numFailedAsserts = NBP_MODULE_GET_NUMBER_OF_FAILED_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_NON_FATAL
    );

    printf(
        "Passed checks: %s%u%s/%u\n"
        "Failed checks: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        numPassedAsserts,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        numAsserts,

        numFailedAsserts == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        numFailedAsserts,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        numAsserts
    );

    // print test asserts stats

    numAsserts = NBP_MODULE_GET_NUMBER_OF_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL_FOR_TEST
    );
    numPassedAsserts = NBP_MODULE_GET_NUMBER_OF_PASSED_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL_FOR_TEST
    );
    numFailedAsserts = NBP_MODULE_GET_NUMBER_OF_FAILED_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL_FOR_TEST
    );

    printf(
        "Passed test asserts: %s%u%s/%u\n"
        "Failed test asserts: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        numPassedAsserts,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        numAsserts,

        numFailedAsserts == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        numFailedAsserts,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        numAsserts
    );

    // print module asserts stats

    numAsserts = NBP_MODULE_GET_NUMBER_OF_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL_FOR_MODULE
    );
    numPassedAsserts = NBP_MODULE_GET_NUMBER_OF_PASSED_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL_FOR_MODULE
    );
    numFailedAsserts = NBP_MODULE_GET_NUMBER_OF_FAILED_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL_FOR_MODULE
    );

    printf(
        "Passed module asserts: %s%u%s/%u\n"
        "Failed module asserts: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        numPassedAsserts,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        numAsserts,

        numFailedAsserts == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        numFailedAsserts,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        numAsserts
    );

    // print asserts stats

    numAsserts = NBP_MODULE_GET_NUMBER_OF_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL
    );
    numPassedAsserts = NBP_MODULE_GET_NUMBER_OF_PASSED_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL
    );
    numFailedAsserts = NBP_MODULE_GET_NUMBER_OF_FAILED_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL
    );

    printf(
        "Passed asserts: %s%u%s/%u\n"
        "Failed asserts: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        numPassedAsserts,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        numAsserts,

        numFailedAsserts == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        numFailedAsserts,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        numAsserts
    );
}

NBP_PRINTER_CALLBACK_RUN_TEST(nbp_linux_printer_run_test)
{
    if (nbpLinuxPrinterData == NBP_MEMORY_NULL_POINTER) {
        nbpLinuxPrinterData = nbp_linux_printer_create_data_from_test(
            NBP_TEST_THIS
        );
        nbpLinuxPrinterDataLast = nbpLinuxPrinterData;
    } else {
        nbpLinuxPrinterDataLast->next = nbp_linux_printer_create_data_from_test(
            NBP_TEST_THIS
        );
        if (nbpLinuxPrinterDataLast->next != NBP_MEMORY_NULL_POINTER) {
            nbpLinuxPrinterDataLast = nbpLinuxPrinterDataLast->next;
        }
    }
}

NBP_PRINTER_CALLBACK_RUN_MODULE(nbp_linux_printer_run_module)
{
    if (nbpLinuxPrinterData == NBP_MEMORY_NULL_POINTER) {
        nbpLinuxPrinterData = nbp_linux_printer_create_data_from_module(
            NBP_MODULE_THIS
        );
        nbpLinuxPrinterDataLast = nbpLinuxPrinterData;
    } else {
        nbpLinuxPrinterDataLast->next = nbp_linux_printer_create_data_from_module(
            NBP_MODULE_THIS
        );
        if (nbpLinuxPrinterDataLast->next != NBP_MEMORY_NULL_POINTER) {
            nbpLinuxPrinterDataLast = nbpLinuxPrinterDataLast->next;
        }
    }
}

NBP_PRINTER_CALLBACK_ASSERT_RESULT(nbp_linux_printer_assert_result)
{
    nbp_linux_printer_add_assert_result(
        NBP_TEST_THIS,
        NBP_PRINTER_GET_CONDITION(),
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_LINE_NUMBER(),
        NBP_PRINTER_GET_FAILURE_MESSAGE(),
        NBP_PRINTER_GET_SUCCESS_MESSAGE()
    );
}

NBP_PRINTER_CALLBACK_ASSERT_TYPE_OP_RESULT(nbp_linux_printer_assert_type_op_result)
{
    char buff[1024] = { 0 };

    switch (NBP_PRINTER_GET_VALUE_TYPE()) {
        case NBP_PRINTER_TYPE_NONE:
            snprintf(
                buff,
                1024,
                "%s %s %s",
                NBP_PRINTER_GET_FIRST_VALUE(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE()
            );
            break;
        case NBP_PRINTER_TYPE_CHAR:
            snprintf(
                buff,
                1024,
                "%c %s %c",
                NBP_PRINTER_GET_FIRST_VALUE_AS_CHAR(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_CHAR()
            );
            break;
        case NBP_PRINTER_TYPE_SHORT:
            snprintf(
                buff,
                1024,
                "%hd %s %hd",
                NBP_PRINTER_GET_FIRST_VALUE_AS_SHORT(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_SHORT()
            );
            break;
        case NBP_PRINTER_TYPE_USHORT:
            snprintf(
                buff,
                1024,
                "%hu %s %hu",
                NBP_PRINTER_GET_FIRST_VALUE_AS_USHORT(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_USHORT()
            );
            break;
        case NBP_PRINTER_TYPE_INT:
            snprintf(
                buff,
                1024,
                "%d %s %d",
                NBP_PRINTER_GET_FIRST_VALUE_AS_INT(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_INT()
            );
            break;
        case NBP_PRINTER_TYPE_UINT:
            snprintf(
                buff,
                1024,
                "%u %s %u",
                NBP_PRINTER_GET_FIRST_VALUE_AS_UINT(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_UINT()
            );
            break;
        case NBP_PRINTER_TYPE_LONG:
            snprintf(
                buff,
                1024,
                "%ld %s %ld",
                NBP_PRINTER_GET_FIRST_VALUE_AS_LONG(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_LONG()
            );
            break;
        case NBP_PRINTER_TYPE_ULONG:
            snprintf(
                buff,
                1024,
                "%lu %s %lu",
                NBP_PRINTER_GET_FIRST_VALUE_AS_ULONG(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_ULONG()
            );
            break;
        case NBP_PRINTER_TYPE_LLONG:
            snprintf(
                buff,
                1024,
                "%lld %s %lld",
                NBP_PRINTER_GET_FIRST_VALUE_AS_LLONG(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_LLONG()
            );
            break;
        case NBP_PRINTER_TYPE_ULLONG:
            snprintf(
                buff,
                1024,
                "%llu %s %llu",
                NBP_PRINTER_GET_FIRST_VALUE_AS_ULLONG(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_ULLONG()
            );
            break;
        case NBP_PRINTER_TYPE_FLOAT:
            snprintf(
                buff,
                1024,
                "%f %s %f",
                NBP_PRINTER_GET_FIRST_VALUE_AS_FLOAT(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_FLOAT()
            );
            break;
        case NBP_PRINTER_TYPE_DOUBLE:
            snprintf(
                buff,
                1024,
                "%f %s %f",
                NBP_PRINTER_GET_FIRST_VALUE_AS_DOUBLE(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_DOUBLE()
            );
            break;
        case NBP_PRINTER_TYPE_LDOUBLE:
            snprintf(
                buff,
                1024,
                "%Lf %s %Lf",
                NBP_PRINTER_GET_FIRST_VALUE_AS_LDOUBLE(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_LDOUBLE()
            );
            break;
        default:
            snprintf(
                buff,
                1024,
                "unknown value type"
            );
            break;
    }

    nbp_linux_printer_add_assert_result(
        NBP_TEST_THIS,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_LINE_NUMBER(),
        NBP_PRINTER_GET_FAILURE_MESSAGE(),
        NBP_PRINTER_GET_SUCCESS_MESSAGE()
    );
}

NBP_PRINTER(
    nbpDefaultPrinter,
    NBP_PRINTER_CALLBACKS(
        NBP_PRINTER_CALLBACK_INIT(nbp_linux_printer_init),
        NBP_PRINTER_CALLBACK_UNINIT(nbp_linux_printer_uninit),
        NBP_PRINTER_CALLBACK_REPORT_ERROR(nbp_linux_printer_report_error),
        NBP_PRINTER_CALLBACK_HANDLE_VERSION_COMMAND(nbp_linux_printer_handle_version_command),
        NBP_PRINTER_CALLBACK_TEST_COMPLETED(nbp_linux_printer_test_completed),
        NBP_PRINTER_CALLBACK_BEFORE_RUN(nbp_linux_printer_before_run),
        NBP_PRINTER_CALLBACK_AFTER_RUN(nbp_linux_printer_after_run),
        NBP_PRINTER_CALLBACK_RUN_TEST(nbp_linux_printer_run_test),
        NBP_PRINTER_CALLBACK_RUN_MODULE(nbp_linux_printer_run_module),
        NBP_PRINTER_CALLBACK_ASSERT_RESULT(nbp_linux_printer_assert_result),
        NBP_PRINTER_CALLBACK_ASSERT_TYPE_OP_RESULT(nbp_linux_printer_assert_type_op_result),
    )
);

#undef NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL
#undef NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
#undef NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN
#undef NBP_LINUX_PRINTER_PRIVATE_COLOR_YELLOW

#undef NBP_LINUX_PRINTER_PRIVATE_CLEAR_LINE

#undef NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_UNKNOWN
#undef NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_TEST
#undef NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_MODULE

#undef NBP_LINUX_PRINTER_PRIVATE_GENERATE_CONDITION

#undef NBP_LINUX_PRINTER_PRIVATE_DECLARE_MUTEX
#undef NBP_LINUX_PRINTER_PRIVATE_MUTEX_INIT
#undef NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNINIT
#undef NBP_LINUX_PRINTER_PRIVATE_MUTEX_LOCK
#undef NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNLOCK

#endif // end if NBP_LINUX_PRINTER_PRIVATE_PRINTER_LINUX_PRINTER_H

