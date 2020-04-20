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

#define NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_UNKNOWN      (int) 0
#define NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_TEST         (int) 1
#define NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_MODULE       (int) 2

#ifdef NBP_MT_SUPPORT

#include <pthread.h>

static inline NBP_ERROR_TYPE nbp_linux_printer_mutex_init(
    pthread_mutex_t* mutex)
{
    return pthread_mutex_init(mutex, NULL) == 0
        ? NBP_NO_ERROR
        : NBP_ERROR_FAILED_TO_INIT_MUTEX;
}

static inline NBP_ERROR_TYPE nbp_linux_printer_mutex_uninit(
    pthread_mutex_t* mutex)
{
    return pthread_mutex_destroy(mutex) == 0
        ? NBP_NO_ERROR
        : NBP_ERROR_FAILED_TO_UNINIT_MUTEX;
}

static inline NBP_ERROR_TYPE nbp_linux_printer_mutex_lock(
    pthread_mutex_t* mutex)
{
    return pthread_mutex_lock(mutex) == 0
        ? NBP_NO_ERROR
        : NBP_ERROR_FAILED_TO_LOCK_MUTEX;
}

static inline NBP_ERROR_TYPE nbp_linux_printer_mutex_unlock(
    pthread_mutex_t* mutex)
{
    return pthread_mutex_unlock(mutex) == 0
        ? NBP_NO_ERROR
        : NBP_ERROR_FAILED_TO_UNLOCK_MUTEX;
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

static inline NBP_ERROR_TYPE nbp_linux_printer_mutex_init()
{
    return NBP_NO_ERROR;
}

static inline NBP_ERROR_TYPE nbp_linux_printer_mutex_uninit()
{
    return NBP_NO_ERROR;
}

static inline NBP_ERROR_TYPE nbp_linux_printer_mutex_lock()
{
    return NBP_NO_ERROR;
}

static inline NBP_ERROR_TYPE nbp_linux_printer_mutex_unlock()
{
    return NBP_NO_ERROR;
}

#define NBP_LINUX_PRINTER_PRIVATE_DECLARE_MUTEX(name)

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_INIT(name)                             \
    nbp_linux_printer_mutex_init()

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNINIT(name)                           \
    nbp_linux_printer_mutex_uninit()

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_LOCK(name)                             \
    nbp_linux_printer_mutex_lock()

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNLOCK(name)                           \
    nbp_linux_printer_mutex_unlock()

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
    int type;
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
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_ALLOC,
                "could not allocate nbp_linux_printer_data_t struct from test"
            );
            break;
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
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_ALLOC,
                "could not allocate nbp_linux_printer_data_t struct from module"
            );
            break;
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
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_ALLOC,
                "could not allocate nbp_linux_printer_messages_list_t struct"
            );
            break;
        }

        message->next = NBP_MEMORY_NULL_POINTER;
        message->message = nbp_linux_printer_duplicate_str(msg);

        if (message->message == NBP_MEMORY_NULL_POINTER) {
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_ALLOC,
                "could not duplicate the message"
            );
            break;
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
        char errMsg[1024];
        snprintf(errMsg, 1024, "test [%s] not found", NBP_GET_TEST_NAME(test));
        NBP_ERROR_REPORT_CTX_STRING(NBP_ERROR_TEST_NOT_FOUND, errMsg);
        return;
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

static void nbp_linux_printer_add_check_result(nbp_test_details_t* test,
    const char* cond, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    char buffer[1024] = { 0 };

    if (passed == NBP_CHECK_STATUS_PASSED) {
        if (passMsg == NBP_PRINTER_NO_PASS_MSG) {
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
        if (failMsg == NBP_PRINTER_NO_FAIL_MSG) {
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

static void nbp_linux_printer_add_test_assert_result(nbp_test_details_t* test,
    const char* cond, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    char buffer[1024] = { 0 };

    if (passed == NBP_TEST_ASSERT_STATUS_PASSED) {
        if (passMsg == NBP_PRINTER_NO_PASS_MSG) {
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
        if (failMsg == NBP_PRINTER_NO_FAIL_MSG) {
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

static void nbp_linux_printer_add_module_assert_result(nbp_test_details_t* test,
    const char* cond, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    char buffer[1024] = { 0 };

    if (passed == NBP_MODULE_ASSERT_STATUS_PASSED) {
        if (passMsg == NBP_PRINTER_NO_PASS_MSG) {
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
        if (failMsg == NBP_PRINTER_NO_FAIL_MSG) {
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

static void nbp_linux_printer_add_assert_result(nbp_test_details_t* test,
    const char* cond, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    char buffer[1024] = { 0 };

    if (passed == NBP_ASSERT_STATUS_PASSED) {
        if (passMsg == NBP_PRINTER_NO_PASS_MSG) {
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
        if (failMsg == NBP_PRINTER_NO_FAIL_MSG) {
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
    unsigned int state = NBP_GET_TEST_STATE(test->test);
    unsigned int depth = NBP_GET_TEST_DEPTH(test->test);

    nbp_linux_printer_print_depth(depth);
    if (state == NBP_TEST_STATE_PASSED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_GET_TEST_NAME(test->test)
        );
    } else if (state == NBP_TEST_STATE_FAILED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_GET_TEST_NAME(test->test)
        );
    } else if (state == NBP_TEST_STATE_SKIPPED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_YELLOW
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_GET_TEST_NAME(test->test)
        );
    } else {
        printf("%s\n", NBP_GET_TEST_NAME(test->test));
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
    unsigned int state = NBP_GET_MODULE_STATE(module->module);

    nbp_linux_printer_print_depth(NBP_GET_MODULE_DEPTH(module->module));
    if (state == NBP_MODULE_STATE_PASSED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_GET_MODULE_NAME(module->module)
        );
    } else if (state == NBP_MODULE_STATE_FAILED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_GET_MODULE_NAME(module->module)
        );
    } else if (state == NBP_MODULE_STATE_SKIPPED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_YELLOW
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_GET_MODULE_NAME(module->module)
        );
    } else {
        printf("%s\n", NBP_GET_MODULE_NAME(module->module));
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

NBP_PRINTER_FUNC_INIT(nbp_linux_printer_init)
{
    nbpLinuxPrinterData                 = NBP_MEMORY_NULL_POINTER;
    nbpLinuxPrinterDataLast             = NBP_MEMORY_NULL_POINTER;
    nbpLinuxPrinterModulesNum           = 0;
    nbpLinuxPrinterTestsNum             = 0;
    nbpLinuxPrinterCompletedTestsNum    = 0;
    NBP_LINUX_PRINTER_PRIVATE_MUTEX_INIT(nbpLinuxPrinterMutex);
}

NBP_PRINTER_FUNC_UNINIT(nbp_linux_printer_uninit)
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

NBP_PRINTER_FUNC_REPORT_ERROR(nbp_linux_printer_report_error)
{
    NBP_LINUX_PRINTER_PRIVATE_MUTEX_LOCK(nbpLinuxPrinterMutex);

    switch (NBP_ERROR_GET_CONTEXT_TYPE(NBP_PRINTER_GET_ERROR())) {
        case NBP_ERROR_CONTEXT_STRING:
            printf(
                "\n" NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
                    "[error] code = %d, message = %s"
                NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
                NBP_ERROR_GET_CODE(NBP_PRINTER_GET_ERROR()),
                NBP_ERROR_GET_CONTEXT_STRING(NBP_PRINTER_GET_ERROR())
            );
            break;
        case NBP_ERROR_CONTEXT_EMPTY:
        case NBP_ERROR_CONTEXT_CUSTOM:
        default:
            printf(
                "\n" NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
                    "[error] code = %d"
                NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
                NBP_ERROR_GET_CODE(NBP_PRINTER_GET_ERROR())
            );
            break;
    }

    NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNLOCK(nbpLinuxPrinterMutex);
}

NBP_PRINTER_FUNC_HANDLE_VERSION_COMMAND(nbp_linux_printer_handle_version_command)
{
    printf("%s\n", NBP_VERSION_STR);
}

NBP_PRINTER_FUNC_TEST_COMPLETED(nbp_linux_printer_test_completed)
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

NBP_PRINTER_FUNC_BEFORE_RUN(nbp_linux_printer_before_run)
{
    nbpLinuxPrinterModulesNum = NBP_PRINTER_GET_NUMBER_OF_MODULES();
    nbpLinuxPrinterTestsNum   = NBP_PRINTER_GET_NUMBER_OF_TESTS();

    printf("Running...");
    fflush(stdout);
}

NBP_PRINTER_FUNC_AFTER_RUN(nbp_linux_printer_after_run)
{
    printf(NBP_LINUX_PRINTER_PRIVATE_CLEAR_LINE);
    nbp_linux_printer_print_data();

    // print modules stats
    printf(
        "Passed  modules: %s%u%s/%u\n"
        "Failed  modules: %s%u%s/%u\n"
        "Skipped modules: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        NBP_PRINTER_GET_NUMBER_OF_PASSED_MODULES(),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterModulesNum,

        NBP_PRINTER_GET_NUMBER_OF_FAILED_MODULES() == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        NBP_PRINTER_GET_NUMBER_OF_FAILED_MODULES(),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterModulesNum,

        NBP_PRINTER_GET_NUMBER_OF_SKIPPED_MODULES() == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_YELLOW,
        NBP_PRINTER_GET_NUMBER_OF_SKIPPED_MODULES(),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterModulesNum
    );

    // print tests stats
    printf(
        "Passed  tests: %s%u%s/%u\n"
        "Failed  tests: %s%u%s/%u\n"
        "Skipped tests: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        NBP_PRINTER_GET_NUMBER_OF_PASSED_TESTS(),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterTestsNum,

        NBP_PRINTER_GET_NUMBER_OF_FAILED_TESTS() == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        NBP_PRINTER_GET_NUMBER_OF_FAILED_TESTS(),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterTestsNum,

        NBP_PRINTER_GET_NUMBER_OF_SKIPPED_TESTS() == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_YELLOW,
        NBP_PRINTER_GET_NUMBER_OF_SKIPPED_TESTS(),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterTestsNum
    );

    // print checks stats
    printf(
        "Passed checks: %s%u%s/%u\n"
        "Failed checks: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        NBP_PRINTER_GET_NUMBER_OF_PASSED_CHECKS(),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        NBP_PRINTER_GET_NUMBER_OF_CHECKS(),

        NBP_PRINTER_GET_NUMBER_OF_FAILED_CHECKS() == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        NBP_PRINTER_GET_NUMBER_OF_FAILED_CHECKS(),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        NBP_PRINTER_GET_NUMBER_OF_CHECKS()
    );

    // print test asserts stats
    printf(
        "Passed test asserts: %s%u%s/%u\n"
        "Failed test asserts: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        NBP_PRINTER_GET_NUMBER_OF_PASSED_TEST_ASSERTS(),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        NBP_PRINTER_GET_NUMBER_OF_TEST_ASSERTS(),

        NBP_PRINTER_GET_NUMBER_OF_FAILED_TEST_ASSERTS() == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        NBP_PRINTER_GET_NUMBER_OF_FAILED_TEST_ASSERTS(),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        NBP_PRINTER_GET_NUMBER_OF_TEST_ASSERTS()
    );

    // print module asserts stats
    printf(
        "Passed module asserts: %s%u%s/%u\n"
        "Failed module asserts: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        NBP_PRINTER_GET_NUMBER_OF_PASSED_MODULE_ASSERTS(),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        NBP_PRINTER_GET_NUMBER_OF_MODULE_ASSERTS(),

        NBP_PRINTER_GET_NUMBER_OF_FAILED_MODULE_ASSERTS() == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        NBP_PRINTER_GET_NUMBER_OF_FAILED_MODULE_ASSERTS(),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        NBP_PRINTER_GET_NUMBER_OF_MODULE_ASSERTS()
    );

    // print asserts stats
    printf(
        "Passed asserts: %s%u%s/%u\n"
        "Failed asserts: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        NBP_PRINTER_GET_NUMBER_OF_PASSED_ASSERTS(),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        NBP_PRINTER_GET_NUMBER_OF_ASSERTS(),

        NBP_PRINTER_GET_NUMBER_OF_FAILED_ASSERTS() == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        NBP_PRINTER_GET_NUMBER_OF_FAILED_ASSERTS(),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        NBP_PRINTER_GET_NUMBER_OF_ASSERTS()
    );
}

NBP_PRINTER_FUNC_SCHEDULING_TEST(nbp_linux_printer_scheduling_test)
{
    if (nbpLinuxPrinterData == NBP_MEMORY_NULL_POINTER) {
        nbpLinuxPrinterData = nbp_linux_printer_create_data_from_test(
            NBP_THIS_TEST
        );
        nbpLinuxPrinterDataLast = nbpLinuxPrinterData;
    } else {
        nbpLinuxPrinterDataLast->next = nbp_linux_printer_create_data_from_test(
            NBP_THIS_TEST
        );
        if (nbpLinuxPrinterDataLast->next != NBP_MEMORY_NULL_POINTER) {
            nbpLinuxPrinterDataLast = nbpLinuxPrinterDataLast->next;
        }
    }
}

NBP_PRINTER_FUNC_BEFORE_SCHEDULING_MODULE(
    nbp_linux_printer_before_scheduling_module)
{
    if (nbpLinuxPrinterData == NBP_MEMORY_NULL_POINTER) {
        nbpLinuxPrinterData = nbp_linux_printer_create_data_from_module(
            NBP_THIS_MODULE
        );
        nbpLinuxPrinterDataLast = nbpLinuxPrinterData;
    } else {
        nbpLinuxPrinterDataLast->next = nbp_linux_printer_create_data_from_module(
            NBP_THIS_MODULE
        );
        if (nbpLinuxPrinterDataLast->next != NBP_MEMORY_NULL_POINTER) {
            nbpLinuxPrinterDataLast = nbpLinuxPrinterDataLast->next;
        }
    }
}

NBP_PRINTER_FUNC_CHECK_RESULT(nbp_linux_printer_check_result)
{
    nbp_linux_printer_add_check_result(
        NBP_THIS_TEST,
        NBP_PRINTER_GET_CONDITION(),
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_OP_RESULT(nbp_linux_printer_check_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%s %s %s",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_CHAR_OP_RESULT(nbp_linux_printer_check_char_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%c %s %c",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_SHORT_OP_RESULT(nbp_linux_printer_check_short_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%hd %s %hd",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_USHORT_OP_RESULT(
    nbp_linux_printer_check_ushort_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%hu %s %hu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_INT_OP_RESULT(nbp_linux_printer_check_int_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%d %s %d",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_UINT_OP_RESULT(nbp_linux_printer_check_uint_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%u %s %u",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_LONG_OP_RESULT(nbp_linux_printer_check_long_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%ld %s %ld",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_ULONG_OP_RESULT(nbp_linux_printer_check_ulong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%lu %s %lu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_LLONG_OP_RESULT(nbp_linux_printer_check_llong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%lld %s %lld",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_ULLONG_OP_RESULT(
    nbp_linux_printer_check_ullong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%llu %s %llu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_FLOAT_OP_RESULT(nbp_linux_printer_check_float_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%f %s %f",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_DOUBLE_OP_RESULT(
    nbp_linux_printer_check_double_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%f %s %f",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_LDOUBLE_OP_RESULT(
    nbp_linux_printer_check_ldouble_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%Lf %s %Lf",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_RESULT(
    nbp_linux_printer_test_assert_result)
{
    nbp_linux_printer_add_test_assert_result(
        NBP_THIS_TEST,
        NBP_PRINTER_GET_CONDITION(),
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_OP_RESULT(
    nbp_linux_printer_test_assert_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%s %s %s",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_CHAR_OP_RESULT(
    nbp_linux_printer_test_assert_char_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%c %s %c",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_SHORT_OP_RESULT(
    nbp_linux_printer_test_assert_short_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%hd %s %hd",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_USHORT_OP_RESULT(
    nbp_linux_printer_test_assert_ushort_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%hu %s %hu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_INT_OP_RESULT(
    nbp_linux_printer_test_assert_int_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%d %s %d",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_UINT_OP_RESULT(
    nbp_linux_printer_test_assert_uint_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%u %s %u",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_LONG_OP_RESULT(
    nbp_linux_printer_test_assert_long_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%ld %s %ld",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_ULONG_OP_RESULT(
    nbp_linux_printer_test_assert_ulong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%lu %s %lu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_LLONG_OP_RESULT(
    nbp_linux_printer_test_assert_llong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%lld %s %lld",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_ULLONG_OP_RESULT(
    nbp_linux_printer_test_assert_ullong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%llu %s %llu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_FLOAT_OP_RESULT(
    nbp_linux_printer_test_assert_float_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%f %s %f",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_DOUBLE_OP_RESULT(
    nbp_linux_printer_test_assert_double_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%f %s %f",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_LDOUBLE_OP_RESULT(
    nbp_linux_printer_test_assert_ldouble_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%Lf %s %Lf",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_RESULT(
    nbp_linux_printer_module_assert_result)
{
    nbp_linux_printer_add_module_assert_result(
        NBP_THIS_TEST,
        NBP_PRINTER_GET_CONDITION(),
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_OP_RESULT(
    nbp_linux_printer_module_assert_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%s %s %s",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_CHAR_OP_RESULT(
    nbp_linux_printer_module_assert_char_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%c %s %c",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_SHORT_OP_RESULT(
    nbp_linux_printer_module_assert_short_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%hd %s %hd",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_USHORT_OP_RESULT(
    nbp_linux_printer_module_assert_ushort_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%hu %s %hu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_INT_OP_RESULT(
    nbp_linux_printer_module_assert_int_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%d %s %d",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_UINT_OP_RESULT(
    nbp_linux_printer_module_assert_uint_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%u %s %u",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_LONG_OP_RESULT(
    nbp_linux_printer_module_assert_long_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%ld %s %ld",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_ULONG_OP_RESULT(
    nbp_linux_printer_module_assert_ulong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%lu %s %lu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_LLONG_OP_RESULT(
    nbp_linux_printer_module_assert_llong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%lld %s %lld",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_ULLONG_OP_RESULT(
    nbp_linux_printer_module_assert_ullong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%llu %s %llu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_FLOAT_OP_RESULT(
    nbp_linux_printer_module_assert_float_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%f %s %f",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_DOUBLE_OP_RESULT(
    nbp_linux_printer_module_assert_double_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%f %s %f",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_LDOUBLE_OP_RESULT(
    nbp_linux_printer_module_assert_ldouble_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%Lf %s %Lf",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_RESULT(nbp_linux_printer_assert_result)
{
    nbp_linux_printer_add_assert_result(
        NBP_THIS_TEST,
        NBP_PRINTER_GET_CONDITION(),
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_OP_RESULT(nbp_linux_printer_assert_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%s %s %s",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_CHAR_OP_RESULT(nbp_linux_printer_assert_char_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%c %s %c",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_SHORT_OP_RESULT(
    nbp_linux_printer_assert_short_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%hd %s %hd",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_USHORT_OP_RESULT(
    nbp_linux_printer_assert_ushort_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%hu %s %hu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_INT_OP_RESULT(nbp_linux_printer_assert_int_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%d %s %d",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_UINT_OP_RESULT(nbp_linux_printer_assert_uint_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%u %s %u",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_LONG_OP_RESULT(nbp_linux_printer_assert_long_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%ld %s %ld",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_ULONG_OP_RESULT(
    nbp_linux_printer_assert_ulong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%lu %s %lu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_LLONG_OP_RESULT(
    nbp_linux_printer_assert_llong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%lld %s %lld",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_ULLONG_OP_RESULT(
    nbp_linux_printer_assert_ullong_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%llu %s %llu",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_FLOAT_OP_RESULT(
    nbp_linux_printer_assert_float_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%f %s %f",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_DOUBLE_OP_RESULT(
    nbp_linux_printer_assert_double_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%f %s %f",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_LDOUBLE_OP_RESULT(
    nbp_linux_printer_assert_ldouble_op_result)
{
    char buff[1024];
    snprintf(
        buff,
        1024,
        "%Lf %s %Lf",
        NBP_PRINTER_GET_FIRST_VALUE(),
        NBP_PRINTER_GET_OPERATOR_STR(),
        NBP_PRINTER_GET_SECOND_VALUE()
    );
    nbp_linux_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_DEFINE_PRINTER(
    // printer name
    nbpDefaultPrinter,

    // init/uninit callbacks
    NBP_PRINTER_USE_FUNC_INIT(
        nbp_linux_printer_init
    ),
    NBP_PRINTER_USE_FUNC_UNINIT(
        nbp_linux_printer_uninit
    ),

    // report error callback
    NBP_PRINTER_USE_FUNC_REPORT_ERROR(
        nbp_linux_printer_report_error
    ),

    // handle version command
    NBP_PRINTER_USE_FUNC_HANDLE_VERSION_COMMAND(
        nbp_linux_printer_handle_version_command
    ),

    // test callbacks
    NBP_PRINTER_NO_FUNC_TEST_STARTED,
    NBP_PRINTER_USE_FUNC_TEST_COMPLETED(
        nbp_linux_printer_test_completed
    ),

    // module callbacks
    NBP_PRINTER_NO_FUNC_MODULE_STARTED,
    NBP_PRINTER_NO_FUNC_MODULE_COMPLETED,

    // stats callbacks
    NBP_PRINTER_USE_FUNC_BEFORE_RUN(
        nbp_linux_printer_before_run
    ),
    NBP_PRINTER_USE_FUNC_AFTER_RUN(
        nbp_linux_printer_after_run
    ),

    // scheduling callbacks
    NBP_PRINTER_USE_FUNC_SCHEDULING_TEST(
        nbp_linux_printer_scheduling_test
    ),
    NBP_PRINTER_USE_FUNC_BEFORE_SCHEDULING_MODULE(
        nbp_linux_printer_before_scheduling_module
    ),
    NBP_PRINTER_NO_FUNC_AFTER_SCHEDULING_MODULE,

    // callbacks for NBP_CHECK_* macros
    NBP_PRINTER_USE_FUNC_CHECK_RESULT(
        nbp_linux_printer_check_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_OP_RESULT(
        nbp_linux_printer_check_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_CHAR_OP_RESULT(
        nbp_linux_printer_check_char_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_SHORT_OP_RESULT(
        nbp_linux_printer_check_short_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_USHORT_OP_RESULT(
        nbp_linux_printer_check_ushort_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_INT_OP_RESULT(
        nbp_linux_printer_check_int_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_UINT_OP_RESULT(
        nbp_linux_printer_check_uint_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_LONG_OP_RESULT(
        nbp_linux_printer_check_long_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_ULONG_OP_RESULT(
        nbp_linux_printer_check_ulong_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_LLONG_OP_RESULT(
        nbp_linux_printer_check_llong_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_ULLONG_OP_RESULT(
        nbp_linux_printer_check_ullong_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_FLOAT_OP_RESULT(
        nbp_linux_printer_check_float_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_DOUBLE_OP_RESULT(
        nbp_linux_printer_check_double_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_LDOUBLE_OP_RESULT(
        nbp_linux_printer_check_ldouble_op_result
    ),

    // callbacks for NBP_TEST_ASSERT_* macros
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_RESULT(
        nbp_linux_printer_test_assert_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_OP_RESULT(
        nbp_linux_printer_test_assert_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_CHAR_OP_RESULT(
        nbp_linux_printer_test_assert_char_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_SHORT_OP_RESULT(
        nbp_linux_printer_test_assert_short_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_USHORT_OP_RESULT(
        nbp_linux_printer_test_assert_ushort_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_INT_OP_RESULT(
        nbp_linux_printer_test_assert_int_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_UINT_OP_RESULT(
        nbp_linux_printer_test_assert_uint_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_LONG_OP_RESULT(
        nbp_linux_printer_test_assert_long_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_ULONG_OP_RESULT(
        nbp_linux_printer_test_assert_ulong_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_LLONG_OP_RESULT(
        nbp_linux_printer_test_assert_llong_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_ULLONG_OP_RESULT(
        nbp_linux_printer_test_assert_ullong_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_FLOAT_OP_RESULT(
        nbp_linux_printer_test_assert_float_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_DOUBLE_OP_RESULT(
        nbp_linux_printer_test_assert_double_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_LDOUBLE_OP_RESULT(
        nbp_linux_printer_test_assert_ldouble_op_result
    ),

    // callbacks for NBP_MODULE_ASSERT_* macros
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_RESULT(
        nbp_linux_printer_module_assert_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_OP_RESULT(
        nbp_linux_printer_module_assert_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_CHAR_OP_RESULT(
        nbp_linux_printer_module_assert_char_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_SHORT_OP_RESULT(
        nbp_linux_printer_module_assert_short_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_USHORT_OP_RESULT(
        nbp_linux_printer_module_assert_ushort_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_INT_OP_RESULT(
        nbp_linux_printer_module_assert_int_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_UINT_OP_RESULT(
        nbp_linux_printer_module_assert_uint_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_LONG_OP_RESULT(
        nbp_linux_printer_module_assert_long_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_ULONG_OP_RESULT(
        nbp_linux_printer_module_assert_ulong_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_LLONG_OP_RESULT(
        nbp_linux_printer_module_assert_llong_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_ULLONG_OP_RESULT(
        nbp_linux_printer_module_assert_ullong_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_FLOAT_OP_RESULT(
        nbp_linux_printer_module_assert_float_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_DOUBLE_OP_RESULT(
        nbp_linux_printer_module_assert_double_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_LDOUBLE_OP_RESULT(
        nbp_linux_printer_module_assert_ldouble_op_result
    ),

    // callbacks for NBP_ASSERT_* macros
    NBP_PRINTER_USE_FUNC_ASSERT_RESULT(
        nbp_linux_printer_assert_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_OP_RESULT(
        nbp_linux_printer_assert_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_CHAR_OP_RESULT(
        nbp_linux_printer_assert_char_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_SHORT_OP_RESULT(
        nbp_linux_printer_assert_short_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_USHORT_OP_RESULT(
        nbp_linux_printer_assert_ushort_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_INT_OP_RESULT(
        nbp_linux_printer_assert_int_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_UINT_OP_RESULT(
        nbp_linux_printer_assert_uint_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_LONG_OP_RESULT(
        nbp_linux_printer_assert_long_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_ULONG_OP_RESULT(
        nbp_linux_printer_assert_ulong_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_LLONG_OP_RESULT(
        nbp_linux_printer_assert_llong_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_ULLONG_OP_RESULT(
        nbp_linux_printer_assert_ullong_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_FLOAT_OP_RESULT(
        nbp_linux_printer_assert_float_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_DOUBLE_OP_RESULT(
        nbp_linux_printer_assert_double_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_LDOUBLE_OP_RESULT(
        nbp_linux_printer_assert_ldouble_op_result
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

#undef NBP_LINUX_PRINTER_PRIVATE_DECLARE_MUTEX
#undef NBP_LINUX_PRINTER_PRIVATE_MUTEX_INIT
#undef NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNINIT
#undef NBP_LINUX_PRINTER_PRIVATE_MUTEX_LOCK
#undef NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNLOCK

#endif // end if NBP_LINUX_PRINTER_PRIVATE_PRINTER_LINUX_PRINTER_H

