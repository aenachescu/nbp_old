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

#ifndef NBP_PRIVATE_PRINTER_LINUX_BASIC_PRINTER_H
#define NBP_PRIVATE_PRINTER_LINUX_BASIC_PRINTER_H

#include <stdio.h>
#include <string.h>

#define NBP_PRIVATE_COLOR_NORMAL    "\x1B[0m"
#define NBP_PRIVATE_COLOR_RED       "\x1B[31m"
#define NBP_PRIVATE_COLOR_GREEN     "\x1B[32m"
#define NBP_PRIVATE_COLOR_YELLOW    "\x1B[33m"

#define NBP_PRIVATE_CLEAR_LINE      "\x1B[2K\r"

#define NBP_PRIVATE_PRINTER_TYPE_UNKNOWN    (int) 0
#define NBP_PRIVATE_PRINTER_TYPE_TEST       (int) 1
#define NBP_PRIVATE_PRINTER_TYPE_MODULE     (int) 2

#ifdef NBP_MT_SUPPORT

#include <pthread.h>

static inline NBP_ERROR_TYPE nbp_mutex_init(pthread_mutex_t* mutex)
{
    return pthread_mutex_init(mutex, NULL) == 0
        ? NBP_NO_ERROR
        : NBP_ERROR_FAILED_TO_INIT_MUTEX;
}

static inline NBP_ERROR_TYPE nbp_mutex_uninit(pthread_mutex_t* mutex)
{
    return pthread_mutex_destroy(mutex) == 0
        ? NBP_NO_ERROR
        : NBP_ERROR_FAILED_TO_UNINIT_MUTEX;
}

static inline NBP_ERROR_TYPE nbp_mutex_lock(pthread_mutex_t* mutex)
{
    return pthread_mutex_lock(mutex) == 0
        ? NBP_NO_ERROR
        : NBP_ERROR_FAILED_TO_LOCK_MUTEX;
}

static inline NBP_ERROR_TYPE nbp_mutex_unlock(pthread_mutex_t* mutex)
{
    return pthread_mutex_unlock(mutex) == 0
        ? NBP_NO_ERROR
        : NBP_ERROR_FAILED_TO_UNLOCK_MUTEX;
}

#define DECLARE_MUTEX(name) pthread_mutex_t name = PTHREAD_MUTEX_INITIALIZER;
#define MUTEX_INIT(name) nbp_mutex_init(&name)
#define MUTEX_UNINIT(name) nbp_mutex_uninit(&name)
#define MUTEX_LOCK(name) nbp_mutex_lock(&name)
#define MUTEX_UNLOCK(name) nbp_mutex_unlock(&name)

#else // NBP_MT_SUPPORT not defined

static inline NBP_ERROR_TYPE nbp_fake_mutex_init()   { return NBP_NO_ERROR; }
static inline NBP_ERROR_TYPE nbp_fake_mutex_uninit() { return NBP_NO_ERROR; }
static inline NBP_ERROR_TYPE nbp_fake_mutex_lock()   { return NBP_NO_ERROR; }
static inline NBP_ERROR_TYPE nbp_fake_mutex_unlock() { return NBP_NO_ERROR; }

#define DECLARE_MUTEX(name)
#define MUTEX_INIT(name)    nbp_fake_mutex_init()
#define MUTEX_UNINIT(name)  nbp_fake_mutex_uninit()
#define MUTEX_LOCK(name)    nbp_fake_mutex_lock()
#define MUTEX_UNLOCK(name)  nbp_fake_mutex_unlock()

#endif // end if NBP_MT_SUPPORT

struct nbp_printer_messages_list_t {
    char* message;
    struct nbp_printer_messages_list_t* next;
};
typedef struct nbp_printer_messages_list_t nbp_printer_messages_list_t;

struct nbp_printer_test_t {
    nbp_test_details_t* test;
    nbp_printer_messages_list_t* messages;
    nbp_printer_messages_list_t* messagesLast;
};
typedef struct nbp_printer_test_t nbp_printer_test_t;

struct nbp_printer_module_t {
    nbp_module_details_t* module;
};
typedef struct nbp_printer_module_t nbp_printer_module_t;

struct nbp_printer_data_t {
    int type;
    union {
        nbp_printer_test_t test;
        nbp_printer_module_t module;
    };
    struct nbp_printer_data_t* next;
};
typedef struct nbp_printer_data_t nbp_printer_data_t;

static nbp_printer_data_t* printerData;
static nbp_printer_data_t* printerDataLast;

static unsigned int printerModulesNum;
static unsigned int printerTestsNum;
static unsigned int printerCompletedTestsNum;

DECLARE_MUTEX(printerMutex);

static char* nbp_printer_duplicate_str(const char* str)
{
    char* dup = (char*) NBP_ALLOC(strlen(str) + 1);
    if (dup != NBP_NULL_POINTER) {
        strcpy(dup, str);
    }
    return dup;
}

static nbp_printer_data_t* nbp_printer_create_data_from_test(
    nbp_test_details_t* test)
{
    nbp_printer_data_t* data = NBP_NULL_POINTER;

    do {
        data = (nbp_printer_data_t*) NBP_ALLOC(sizeof(*data));
        if (data == NBP_NULL_POINTER) {
            NBP_HANDLE_ERROR_CTX_STRING(
                NBP_ERROR_ALLOC,
                "could not allocate nbp_printer_data_t struct from test"
            );
            break;
        }

        data->type              = NBP_PRIVATE_PRINTER_TYPE_TEST;
        data->test.test         = test;
        data->test.messages     = NBP_NULL_POINTER;
        data->test.messagesLast = NBP_NULL_POINTER;
        data->next              = NBP_NULL_POINTER;
    } while (0);

    return data;
}

static nbp_printer_data_t* nbp_printer_create_data_from_module(
    nbp_module_details_t* module)
{
    nbp_printer_data_t* data = NBP_NULL_POINTER;

    do {
        data = (nbp_printer_data_t*) NBP_ALLOC(sizeof(*data));
        if (data == NBP_NULL_POINTER) {
            NBP_HANDLE_ERROR_CTX_STRING(
                NBP_ERROR_ALLOC,
                "could not allocate nbp_printer_data_t struct from module"
            );
            break;
        }

        data->type          = NBP_PRIVATE_PRINTER_TYPE_MODULE;
        data->module.module = module;
        data->next          = NBP_NULL_POINTER;
    } while (0);

    return data;
}

static nbp_printer_data_t* nbp_printer_find_printer_test(nbp_test_details_t* test)
{
    nbp_printer_data_t* data = NBP_NULL_POINTER;
    for (data = printerData; data != NBP_NULL_POINTER; data = data->next) {
        if (data->type != NBP_PRIVATE_PRINTER_TYPE_TEST) {
            continue;
        }

        if (data->test.test != test) {
            continue;
        }

        return data;
    }

    return NBP_NULL_POINTER;
}

static void nbp_printer_delete_messages(nbp_printer_messages_list_t* msg)
{
    nbp_printer_messages_list_t* tmp = NBP_NULL_POINTER;
    while (msg != NBP_NULL_POINTER) {
        tmp = msg;
        msg = tmp->next;

        tmp->next = NBP_NULL_POINTER;

        NBP_FREE(tmp->message);
        NBP_FREE(tmp);
    }
}

static nbp_printer_messages_list_t* nbp_printer_create_message(char* msg)
{
    nbp_printer_messages_list_t* message = NBP_NULL_POINTER;

    do {
        message = (nbp_printer_messages_list_t*) NBP_ALLOC(sizeof(*message));
        if (message == NBP_NULL_POINTER) {
            NBP_HANDLE_ERROR_CTX_STRING(
                NBP_ERROR_ALLOC,
                "could not allocate nbp_printer_messages_list_t struct"
            );
            break;
        }

        message->next = NBP_NULL_POINTER;
        message->message = nbp_printer_duplicate_str(msg);

        if (message->message == NBP_NULL_POINTER) {
            NBP_HANDLE_ERROR_CTX_STRING(
                NBP_ERROR_ALLOC,
                "could not duplicate the message"
            );
            break;
        }

        return message;
    } while (0);

    if (message != NBP_NULL_POINTER) {
        NBP_FREE(message);
    }

    return NBP_NULL_POINTER;
}

static void nbp_printer_add_message(nbp_test_details_t* test, char* msg)
{
    nbp_printer_data_t* data = nbp_printer_find_printer_test(test);

    if (data == NBP_NULL_POINTER) {
        char errMsg[1024];
        snprintf(errMsg, 1024, "test [%s] not found", NBP_GET_TEST_NAME(test));
        NBP_HANDLE_ERROR_CTX_STRING(NBP_ERROR_TEST_NOT_FOUND, errMsg);
        return;
    }

    if (data->test.messages == NBP_NULL_POINTER) {
        data->test.messages = nbp_printer_create_message(msg);
        data->test.messagesLast = data->test.messages;
    } else {
        data->test.messagesLast->next = nbp_printer_create_message(msg);
        if (data->test.messagesLast->next != NBP_NULL_POINTER) {
            data->test.messagesLast = data->test.messagesLast->next;
        }
    }
}

static void nbp_printer_add_check_result(nbp_test_details_t* test,
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
            NBP_PRIVATE_COLOR_GREEN
                "%s (%s) (%d)"
            NBP_PRIVATE_COLOR_NORMAL "\n",
            cond,
            passMsg,
            line
        );
    } else {
        if (failMsg == NBP_PRINTER_NO_FAIL_MSG) {
            snprintf(
                buffer,
                1024,
                NBP_PRIVATE_COLOR_RED
                    "%s (%d)"
                NBP_PRIVATE_COLOR_NORMAL "\n",
                cond,
                line
            );
        } else {
            snprintf(
                buffer,
                1024,
                NBP_PRIVATE_COLOR_RED
                    "%s (%s) (%d)"
                NBP_PRIVATE_COLOR_NORMAL "\n",
                cond,
                failMsg,
                line
            );
        }
    }

    nbp_printer_add_message(test, buffer);
}

static void nbp_printer_add_test_assert_result(nbp_test_details_t* test,
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
            NBP_PRIVATE_COLOR_GREEN
                "%s (%s) (%d)"
            NBP_PRIVATE_COLOR_NORMAL "\n",
            cond,
            passMsg,
            line
        );
    } else {
        if (failMsg == NBP_PRINTER_NO_FAIL_MSG) {
            snprintf(
                buffer,
                1024,
                NBP_PRIVATE_COLOR_RED
                    "%s (%d)"
                NBP_PRIVATE_COLOR_NORMAL "\n",
                cond,
                line
            );
        } else {
            snprintf(
                buffer,
                1024,
                NBP_PRIVATE_COLOR_RED
                    "%s (%s) (%d)"
                NBP_PRIVATE_COLOR_NORMAL "\n",
                cond,
                failMsg,
                line
            );
        }
    }

    nbp_printer_add_message(test, buffer);
}

static void nbp_printer_add_module_assert_result(nbp_test_details_t* test,
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
            NBP_PRIVATE_COLOR_GREEN
                "%s (%s) (%d)"
            NBP_PRIVATE_COLOR_NORMAL "\n",
            cond,
            passMsg,
            line
        );
    } else {
        if (failMsg == NBP_PRINTER_NO_FAIL_MSG) {
            snprintf(
                buffer,
                1024,
                NBP_PRIVATE_COLOR_RED
                    "%s (%d)"
                NBP_PRIVATE_COLOR_NORMAL "\n",
                cond,
                line
            );
        } else {
            snprintf(
                buffer,
                1024,
                NBP_PRIVATE_COLOR_RED
                    "%s (%s) (%d)"
                NBP_PRIVATE_COLOR_NORMAL "\n",
                cond,
                failMsg,
                line
            );
        }
    }

    nbp_printer_add_message(test, buffer);
}

static void nbp_printer_add_assert_result(nbp_test_details_t* test,
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
            NBP_PRIVATE_COLOR_GREEN
                "%s (%s) (%d)"
            NBP_PRIVATE_COLOR_NORMAL "\n",
            cond,
            passMsg,
            line
        );
    } else {
        if (failMsg == NBP_PRINTER_NO_FAIL_MSG) {
            snprintf(
                buffer,
                1024,
                NBP_PRIVATE_COLOR_RED
                    "%s (%d)"
                NBP_PRIVATE_COLOR_NORMAL "\n",
                cond,
                line
            );
        } else {
            snprintf(
                buffer,
                1024,
                NBP_PRIVATE_COLOR_RED
                    "%s (%s) (%d)"
                NBP_PRIVATE_COLOR_NORMAL "\n",
                cond,
                failMsg,
                line
            );
        }
    }

    nbp_printer_add_message(test, buffer);
}

static void nbp_printer_print_depth(unsigned int depth)
{
    while (depth-- > 0) {
        printf("    ");
    }
}

static void nbp_printer_print_test(nbp_printer_test_t* test)
{
    unsigned int state = NBP_GET_TEST_STATE(test->test);
    unsigned int depth = NBP_GET_TEST_DEPTH(test->test);

    nbp_printer_print_depth(depth);
    if (state == NBP_TEST_STATE_PASSED) {
        printf(
            NBP_PRIVATE_COLOR_GREEN "%s" NBP_PRIVATE_COLOR_NORMAL "\n",
            NBP_GET_TEST_NAME(test->test)
        );
    } else if (state == NBP_TEST_STATE_FAILED) {
        printf(
            NBP_PRIVATE_COLOR_RED "%s" NBP_PRIVATE_COLOR_NORMAL "\n",
            NBP_GET_TEST_NAME(test->test)
        );
    } else if (state == NBP_TEST_STATE_SKIPPED) {
        printf(
            NBP_PRIVATE_COLOR_YELLOW "%s" NBP_PRIVATE_COLOR_NORMAL "\n",
            NBP_GET_TEST_NAME(test->test)
        );
    } else {
        printf("%s\n", NBP_GET_TEST_NAME(test->test));
    }

    nbp_printer_messages_list_t* msg = test->messages;
    depth++;

    while (msg != NBP_NULL_POINTER) {
        nbp_printer_print_depth(depth);
        printf("%s", msg->message);
        msg = msg->next;
    }
}

static void nbp_printer_print_module(nbp_printer_module_t* module)
{
    unsigned int state = NBP_GET_MODULE_STATE(module->module);

    nbp_printer_print_depth(NBP_GET_MODULE_DEPTH(module->module));
    if (state == NBP_MODULE_STATE_PASSED) {
        printf(
            NBP_PRIVATE_COLOR_GREEN "%s" NBP_PRIVATE_COLOR_NORMAL "\n",
            NBP_GET_MODULE_NAME(module->module)
        );
    } else if (state == NBP_MODULE_STATE_FAILED) {
        printf(
            NBP_PRIVATE_COLOR_RED "%s" NBP_PRIVATE_COLOR_NORMAL "\n",
            NBP_GET_MODULE_NAME(module->module)
        );
    } else if (state == NBP_MODULE_STATE_SKIPPED) {
        printf(
            NBP_PRIVATE_COLOR_YELLOW "%s" NBP_PRIVATE_COLOR_NORMAL "\n",
            NBP_GET_MODULE_NAME(module->module)
        );
    } else {
        printf("%s\n", NBP_GET_MODULE_NAME(module->module));
    }
}

static void nbp_printer_print_data()
{
    nbp_printer_data_t* data = printerData;

    while (data != NBP_NULL_POINTER) {
        if (data->type == NBP_PRIVATE_PRINTER_TYPE_MODULE) {
            nbp_printer_print_module(&data->module);
        } else if (data->type == NBP_PRIVATE_PRINTER_TYPE_TEST) {
            nbp_printer_print_test(&data->test);
        }

        data = data->next;
    }
}

NBP_PRINTER_FUNC_INIT(nbp_basic_printer_init)
{
    printerData                 = NBP_NULL_POINTER;
    printerDataLast             = NBP_NULL_POINTER;
    printerModulesNum           = 0;
    printerTestsNum             = 0;
    printerCompletedTestsNum    = 0;
    MUTEX_INIT(printerMutex);
}

NBP_PRINTER_FUNC_UNINIT(nbp_basic_printer_uninit)
{
    nbp_printer_data_t* tmp = NBP_NULL_POINTER;
    while (printerData != NBP_NULL_POINTER) {
        tmp = printerData;
        printerData = tmp->next;

        tmp->next = NBP_NULL_POINTER;

        if (tmp->type == NBP_PRIVATE_PRINTER_TYPE_TEST) {
            nbp_printer_delete_messages(tmp->test.messages);
        }

        NBP_FREE(tmp);
    }

    printerDataLast = NBP_NULL_POINTER;

    MUTEX_UNINIT(printerMutex);
}

NBP_PRINTER_FUNC_HANDLE_ERROR(nbp_basic_printer_handle_error)
{
    MUTEX_LOCK(printerMutex);

    switch (NBP_ERROR_GET_CONTEXT_TYPE(NBP_PRINTER_GET_ERROR())) {
        case NBP_ERROR_CONTEXT_STRING:
            printf(
                "\n" NBP_PRIVATE_COLOR_RED
                    "[error] code = %d, message = %s"
                NBP_PRIVATE_COLOR_NORMAL "\n",
                NBP_ERROR_GET_CODE(NBP_PRINTER_GET_ERROR()),
                NBP_ERROR_GET_CONTEXT_STRING(NBP_PRINTER_GET_ERROR())
            );
            break;
        case NBP_ERROR_CONTEXT_EMPTY:
        case NBP_ERROR_CONTEXT_CUSTOM:
        default:
            printf(
                "\n" NBP_PRIVATE_COLOR_RED
                    "[error] code = %d"
                NBP_PRIVATE_COLOR_NORMAL "\n",
                NBP_ERROR_GET_CODE(NBP_PRINTER_GET_ERROR())
            );
            break;
    }

    MUTEX_UNLOCK(printerMutex);
}

NBP_PRINTER_FUNC_HANDLE_VERSION_COMMAND(nbp_basic_printer_handle_version_command)
{
    printf("%s\n", NBP_VERSION_STR);
}

NBP_PRINTER_FUNC_TEST_COMPLETED(nbp_basic_printer_test_completed)
{
    (void)(NBP_THIS_TEST);

    MUTEX_LOCK(printerMutex);

    printerCompletedTestsNum++;

    printf(
        NBP_PRIVATE_CLEAR_LINE "Running... %u/%u",
        printerCompletedTestsNum,
        printerTestsNum
    );
    fflush(stdout);

    MUTEX_UNLOCK(printerMutex);
}

NBP_PRINTER_FUNC_BEFORE_RUN(nbp_basic_printer_before_run)
{
    printerModulesNum = NBP_PRINTER_GET_MODULES_NUM();
    printerTestsNum   = NBP_PRINTER_GET_TESTS_NUM();

    printf("Running...");
    fflush(stdout);
}

NBP_PRINTER_FUNC_AFTER_RUN(nbp_basic_printer_after_run)
{
    printf(NBP_PRIVATE_CLEAR_LINE);
    nbp_printer_print_data();

    // print modules stats
    printf(
        "Passed  modules: %s%u%s/%u\n"
        "Failed  modules: %s%u%s/%u\n"
        "Skipped modules: %s%u%s/%u\n",

        NBP_PRIVATE_COLOR_GREEN,
        NBP_PRINTER_GET_PASSED_MODULES_NUM(),
        NBP_PRIVATE_COLOR_NORMAL,
        printerModulesNum,

        NBP_PRINTER_GET_FAILED_MODULES_NUM() == 0 ?
            NBP_PRIVATE_COLOR_GREEN :
            NBP_PRIVATE_COLOR_RED,
        NBP_PRINTER_GET_FAILED_MODULES_NUM(),
        NBP_PRIVATE_COLOR_NORMAL,
        printerModulesNum,

        NBP_PRINTER_GET_SKIPPED_MODULES_NUM() == 0 ?
            NBP_PRIVATE_COLOR_GREEN :
            NBP_PRIVATE_COLOR_YELLOW,
        NBP_PRINTER_GET_SKIPPED_MODULES_NUM(),
        NBP_PRIVATE_COLOR_NORMAL,
        printerModulesNum
    );

    // print tests stats
    printf(
        "Passed  tests: %s%u%s/%u\n"
        "Failed  tests: %s%u%s/%u\n"
        "Skipped tests: %s%u%s/%u\n",

        NBP_PRIVATE_COLOR_GREEN,
        NBP_PRINTER_GET_PASSED_TESTS_NUM(),
        NBP_PRIVATE_COLOR_NORMAL,
        printerTestsNum,

        NBP_PRINTER_GET_FAILED_TESTS_NUM() == 0 ?
            NBP_PRIVATE_COLOR_GREEN :
            NBP_PRIVATE_COLOR_RED,
        NBP_PRINTER_GET_FAILED_TESTS_NUM(),
        NBP_PRIVATE_COLOR_NORMAL,
        printerTestsNum,

        NBP_PRINTER_GET_SKIPPED_TESTS_NUM() == 0 ?
            NBP_PRIVATE_COLOR_GREEN :
            NBP_PRIVATE_COLOR_YELLOW,
        NBP_PRINTER_GET_SKIPPED_TESTS_NUM(),
        NBP_PRIVATE_COLOR_NORMAL,
        printerTestsNum
    );

    // print checks stats
    printf(
        "Passed checks: %s%u%s/%u\n"
        "Failed checks: %s%u%s/%u\n",

        NBP_PRIVATE_COLOR_GREEN,
        NBP_PRINTER_GET_PASSED_CHECKS_NUM(),
        NBP_PRIVATE_COLOR_NORMAL,
        NBP_PRINTER_GET_CHECKS_NUM(),

        NBP_PRINTER_GET_FAILED_CHECKS_NUM() == 0 ?
            NBP_PRIVATE_COLOR_GREEN :
            NBP_PRIVATE_COLOR_RED,
        NBP_PRINTER_GET_FAILED_CHECKS_NUM(),
        NBP_PRIVATE_COLOR_NORMAL,
        NBP_PRINTER_GET_CHECKS_NUM()
    );

    // print test asserts stats
    printf(
        "Passed test asserts: %s%u%s/%u\n"
        "Failed test asserts: %s%u%s/%u\n",

        NBP_PRIVATE_COLOR_GREEN,
        NBP_PRINTER_GET_PASSED_TEST_ASSERTS_NUM(),
        NBP_PRIVATE_COLOR_NORMAL,
        NBP_PRINTER_GET_TEST_ASSERTS_NUM(),

        NBP_PRINTER_GET_FAILED_TEST_ASSERTS_NUM() == 0 ?
            NBP_PRIVATE_COLOR_GREEN :
            NBP_PRIVATE_COLOR_RED,
        NBP_PRINTER_GET_FAILED_TEST_ASSERTS_NUM(),
        NBP_PRIVATE_COLOR_NORMAL,
        NBP_PRINTER_GET_TEST_ASSERTS_NUM()
    );

    // print module asserts stats
    printf(
        "Passed module asserts: %s%u%s/%u\n"
        "Failed module asserts: %s%u%s/%u\n",

        NBP_PRIVATE_COLOR_GREEN,
        NBP_PRINTER_GET_PASSED_MODULE_ASSERTS_NUM(),
        NBP_PRIVATE_COLOR_NORMAL,
        NBP_PRINTER_GET_MODULE_ASSERTS_NUM(),

        NBP_PRINTER_GET_FAILED_MODULE_ASSERTS_NUM() == 0 ?
            NBP_PRIVATE_COLOR_GREEN :
            NBP_PRIVATE_COLOR_RED,
        NBP_PRINTER_GET_FAILED_MODULE_ASSERTS_NUM(),
        NBP_PRIVATE_COLOR_NORMAL,
        NBP_PRINTER_GET_MODULE_ASSERTS_NUM()
    );

    // print asserts stats
    printf(
        "Passed asserts: %s%u%s/%u\n"
        "Failed asserts: %s%u%s/%u\n",

        NBP_PRIVATE_COLOR_GREEN,
        NBP_PRINTER_GET_PASSED_ASSERTS_NUM(),
        NBP_PRIVATE_COLOR_NORMAL,
        NBP_PRINTER_GET_ASSERTS_NUM(),

        NBP_PRINTER_GET_FAILED_ASSERTS_NUM() == 0 ?
            NBP_PRIVATE_COLOR_GREEN :
            NBP_PRIVATE_COLOR_RED,
        NBP_PRINTER_GET_FAILED_ASSERTS_NUM(),
        NBP_PRIVATE_COLOR_NORMAL,
        NBP_PRINTER_GET_ASSERTS_NUM()
    );
}

NBP_PRINTER_FUNC_SCHEDULING_TEST(nbp_basic_printer_scheduling_test)
{
    if (printerData == NBP_NULL_POINTER) {
        printerData = nbp_printer_create_data_from_test(NBP_THIS_TEST);
        printerDataLast = printerData;
    } else {
        printerDataLast->next = nbp_printer_create_data_from_test(
            NBP_THIS_TEST
        );
        if (printerDataLast->next != NBP_NULL_POINTER) {
            printerDataLast = printerDataLast->next;
        }
    }
}

NBP_PRINTER_FUNC_BEFORE_SCHEDULING_MODULE(
    nbp_basic_printer_before_scheduling_module)
{
    if (printerData == NBP_NULL_POINTER) {
        printerData = nbp_printer_create_data_from_module(NBP_THIS_MODULE);
        printerDataLast = printerData;
    } else {
        printerDataLast->next = nbp_printer_create_data_from_module(
            NBP_THIS_MODULE
        );
        if (printerDataLast->next != NBP_NULL_POINTER) {
            printerDataLast = printerDataLast->next;
        }
    }
}

NBP_PRINTER_FUNC_CHECK_RESULT(nbp_basic_printer_check_result)
{
    nbp_printer_add_check_result(
        NBP_THIS_TEST,
        NBP_PRINTER_GET_CONDITION(),
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_OP_RESULT(nbp_basic_printer_check_op_result)
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
    nbp_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_CHAR_OP_RESULT(nbp_basic_printer_check_char_op_result)
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
    nbp_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_SHORT_OP_RESULT(nbp_basic_printer_check_short_op_result)
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
    nbp_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_USHORT_OP_RESULT(
    nbp_basic_printer_check_ushort_op_result)
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
    nbp_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_INT_OP_RESULT(nbp_basic_printer_check_int_op_result)
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
    nbp_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_UINT_OP_RESULT(nbp_basic_printer_check_uint_op_result)
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
    nbp_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_LONG_OP_RESULT(nbp_basic_printer_check_long_op_result)
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
    nbp_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_ULONG_OP_RESULT(nbp_basic_printer_check_ulong_op_result)
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
    nbp_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_LLONG_OP_RESULT(nbp_basic_printer_check_llong_op_result)
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
    nbp_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_ULLONG_OP_RESULT(
    nbp_basic_printer_check_ullong_op_result)
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
    nbp_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_FLOAT_OP_RESULT(nbp_basic_printer_check_float_op_result)
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
    nbp_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_DOUBLE_OP_RESULT(
    nbp_basic_printer_check_double_op_result)
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
    nbp_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_CHECK_LDOUBLE_OP_RESULT(
    nbp_basic_printer_check_ldouble_op_result)
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
    nbp_printer_add_check_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_CHECK_STATUS(),
        NBP_PRINTER_GET_CHECK_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_RESULT(
    nbp_basic_printer_test_assert_result)
{
    nbp_printer_add_test_assert_result(
        NBP_THIS_TEST,
        NBP_PRINTER_GET_CONDITION(),
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_OP_RESULT(
    nbp_basic_printer_test_assert_op_result)
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
    nbp_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_CHAR_OP_RESULT(
    nbp_basic_printer_test_assert_char_op_result)
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
    nbp_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_SHORT_OP_RESULT(
    nbp_basic_printer_test_assert_short_op_result)
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
    nbp_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_USHORT_OP_RESULT(
    nbp_basic_printer_test_assert_ushort_op_result)
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
    nbp_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_INT_OP_RESULT(
    nbp_basic_printer_test_assert_int_op_result)
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
    nbp_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_UINT_OP_RESULT(
    nbp_basic_printer_test_assert_uint_op_result)
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
    nbp_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_LONG_OP_RESULT(
    nbp_basic_printer_test_assert_long_op_result)
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
    nbp_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_ULONG_OP_RESULT(
    nbp_basic_printer_test_assert_ulong_op_result)
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
    nbp_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_LLONG_OP_RESULT(
    nbp_basic_printer_test_assert_llong_op_result)
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
    nbp_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_ULLONG_OP_RESULT(
    nbp_basic_printer_test_assert_ullong_op_result)
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
    nbp_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_FLOAT_OP_RESULT(
    nbp_basic_printer_test_assert_float_op_result)
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
    nbp_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_DOUBLE_OP_RESULT(
    nbp_basic_printer_test_assert_double_op_result)
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
    nbp_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_TEST_ASSERT_LDOUBLE_OP_RESULT(
    nbp_basic_printer_test_assert_ldouble_op_result)
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
    nbp_printer_add_test_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_TEST_ASSERT_STATUS(),
        NBP_PRINTER_GET_TEST_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_RESULT(
    nbp_basic_printer_module_assert_result)
{
    nbp_printer_add_module_assert_result(
        NBP_THIS_TEST,
        NBP_PRINTER_GET_CONDITION(),
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_OP_RESULT(
    nbp_basic_printer_module_assert_op_result)
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
    nbp_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_CHAR_OP_RESULT(
    nbp_basic_printer_module_assert_char_op_result)
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
    nbp_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_SHORT_OP_RESULT(
    nbp_basic_printer_module_assert_short_op_result)
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
    nbp_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_USHORT_OP_RESULT(
    nbp_basic_printer_module_assert_ushort_op_result)
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
    nbp_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_INT_OP_RESULT(
    nbp_basic_printer_module_assert_int_op_result)
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
    nbp_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_UINT_OP_RESULT(
    nbp_basic_printer_module_assert_uint_op_result)
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
    nbp_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_LONG_OP_RESULT(
    nbp_basic_printer_module_assert_long_op_result)
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
    nbp_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_ULONG_OP_RESULT(
    nbp_basic_printer_module_assert_ulong_op_result)
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
    nbp_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_LLONG_OP_RESULT(
    nbp_basic_printer_module_assert_llong_op_result)
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
    nbp_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_ULLONG_OP_RESULT(
    nbp_basic_printer_module_assert_ullong_op_result)
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
    nbp_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_FLOAT_OP_RESULT(
    nbp_basic_printer_module_assert_float_op_result)
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
    nbp_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_DOUBLE_OP_RESULT(
    nbp_basic_printer_module_assert_double_op_result)
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
    nbp_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_MODULE_ASSERT_LDOUBLE_OP_RESULT(
    nbp_basic_printer_module_assert_ldouble_op_result)
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
    nbp_printer_add_module_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_MODULE_ASSERT_STATUS(),
        NBP_PRINTER_GET_MODULE_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_RESULT(nbp_basic_printer_assert_result)
{
    nbp_printer_add_assert_result(
        NBP_THIS_TEST,
        NBP_PRINTER_GET_CONDITION(),
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_OP_RESULT(nbp_basic_printer_assert_op_result)
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
    nbp_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_CHAR_OP_RESULT(nbp_basic_printer_assert_char_op_result)
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
    nbp_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_SHORT_OP_RESULT(
    nbp_basic_printer_assert_short_op_result)
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
    nbp_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_USHORT_OP_RESULT(
    nbp_basic_printer_assert_ushort_op_result)
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
    nbp_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_INT_OP_RESULT(nbp_basic_printer_assert_int_op_result)
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
    nbp_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_UINT_OP_RESULT(nbp_basic_printer_assert_uint_op_result)
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
    nbp_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_LONG_OP_RESULT(nbp_basic_printer_assert_long_op_result)
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
    nbp_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_ULONG_OP_RESULT(
    nbp_basic_printer_assert_ulong_op_result)
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
    nbp_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_LLONG_OP_RESULT(
    nbp_basic_printer_assert_llong_op_result)
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
    nbp_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_ULLONG_OP_RESULT(
    nbp_basic_printer_assert_ullong_op_result)
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
    nbp_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_FLOAT_OP_RESULT(
    nbp_basic_printer_assert_float_op_result)
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
    nbp_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_DOUBLE_OP_RESULT(
    nbp_basic_printer_assert_double_op_result)
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
    nbp_printer_add_assert_result(
        NBP_THIS_TEST,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_ASSERT_LINE(),
        NBP_PRINTER_GET_FAIL_MSG(),
        NBP_PRINTER_GET_PASS_MSG()
    );
}

NBP_PRINTER_FUNC_ASSERT_LDOUBLE_OP_RESULT(
    nbp_basic_printer_assert_ldouble_op_result)
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
    nbp_printer_add_assert_result(
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
        nbp_basic_printer_init
    ),
    NBP_PRINTER_USE_FUNC_UNINIT(
        nbp_basic_printer_uninit
    ),

    // handle error callback
    NBP_PRINTER_USE_FUNC_HANDLE_ERROR(
        nbp_basic_printer_handle_error
    ),

    // handle version command
    NBP_PRINTER_USE_FUNC_HANDLE_VERSION_COMMAND(
        nbp_basic_printer_handle_version_command
    ),

    // test callbacks
    NBP_PRINTER_NO_FUNC_TEST_STARTED,
    NBP_PRINTER_USE_FUNC_TEST_COMPLETED(
        nbp_basic_printer_test_completed
    ),

    // module callbacks
    NBP_PRINTER_NO_FUNC_MODULE_STARTED,
    NBP_PRINTER_NO_FUNC_MODULE_COMPLETED,

    // stats callbacks
    NBP_PRINTER_USE_FUNC_BEFORE_RUN(
        nbp_basic_printer_before_run
    ),
    NBP_PRINTER_USE_FUNC_AFTER_RUN(
        nbp_basic_printer_after_run
    ),

    // scheduling callbacks
    NBP_PRINTER_USE_FUNC_SCHEDULING_TEST(
        nbp_basic_printer_scheduling_test
    ),
    NBP_PRINTER_USE_FUNC_BEFORE_SCHEDULING_MODULE(
        nbp_basic_printer_before_scheduling_module
    ),
    NBP_PRINTER_NO_FUNC_AFTER_SCHEDULING_MODULE,

    // callbacks for NBP_CHECK_* macros
    NBP_PRINTER_USE_FUNC_CHECK_RESULT(
        nbp_basic_printer_check_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_OP_RESULT(
        nbp_basic_printer_check_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_CHAR_OP_RESULT(
        nbp_basic_printer_check_char_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_SHORT_OP_RESULT(
        nbp_basic_printer_check_short_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_USHORT_OP_RESULT(
        nbp_basic_printer_check_ushort_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_INT_OP_RESULT(
        nbp_basic_printer_check_int_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_UINT_OP_RESULT(
        nbp_basic_printer_check_uint_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_LONG_OP_RESULT(
        nbp_basic_printer_check_long_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_ULONG_OP_RESULT(
        nbp_basic_printer_check_ulong_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_LLONG_OP_RESULT(
        nbp_basic_printer_check_llong_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_ULLONG_OP_RESULT(
        nbp_basic_printer_check_ullong_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_FLOAT_OP_RESULT(
        nbp_basic_printer_check_float_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_DOUBLE_OP_RESULT(
        nbp_basic_printer_check_double_op_result
    ),
    NBP_PRINTER_USE_FUNC_CHECK_LDOUBLE_OP_RESULT(
        nbp_basic_printer_check_ldouble_op_result
    ),

    // callbacks for NBP_TEST_ASSERT_* macros
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_RESULT(
        nbp_basic_printer_test_assert_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_OP_RESULT(
        nbp_basic_printer_test_assert_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_CHAR_OP_RESULT(
        nbp_basic_printer_test_assert_char_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_SHORT_OP_RESULT(
        nbp_basic_printer_test_assert_short_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_USHORT_OP_RESULT(
        nbp_basic_printer_test_assert_ushort_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_INT_OP_RESULT(
        nbp_basic_printer_test_assert_int_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_UINT_OP_RESULT(
        nbp_basic_printer_test_assert_uint_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_LONG_OP_RESULT(
        nbp_basic_printer_test_assert_long_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_ULONG_OP_RESULT(
        nbp_basic_printer_test_assert_ulong_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_LLONG_OP_RESULT(
        nbp_basic_printer_test_assert_llong_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_ULLONG_OP_RESULT(
        nbp_basic_printer_test_assert_ullong_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_FLOAT_OP_RESULT(
        nbp_basic_printer_test_assert_float_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_DOUBLE_OP_RESULT(
        nbp_basic_printer_test_assert_double_op_result
    ),
    NBP_PRINTER_USE_FUNC_TEST_ASSERT_LDOUBLE_OP_RESULT(
        nbp_basic_printer_test_assert_ldouble_op_result
    ),

    // callbacks for NBP_MODULE_ASSERT_* macros
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_RESULT(
        nbp_basic_printer_module_assert_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_OP_RESULT(
        nbp_basic_printer_module_assert_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_CHAR_OP_RESULT(
        nbp_basic_printer_module_assert_char_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_SHORT_OP_RESULT(
        nbp_basic_printer_module_assert_short_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_USHORT_OP_RESULT(
        nbp_basic_printer_module_assert_ushort_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_INT_OP_RESULT(
        nbp_basic_printer_module_assert_int_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_UINT_OP_RESULT(
        nbp_basic_printer_module_assert_uint_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_LONG_OP_RESULT(
        nbp_basic_printer_module_assert_long_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_ULONG_OP_RESULT(
        nbp_basic_printer_module_assert_ulong_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_LLONG_OP_RESULT(
        nbp_basic_printer_module_assert_llong_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_ULLONG_OP_RESULT(
        nbp_basic_printer_module_assert_ullong_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_FLOAT_OP_RESULT(
        nbp_basic_printer_module_assert_float_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_DOUBLE_OP_RESULT(
        nbp_basic_printer_module_assert_double_op_result
    ),
    NBP_PRINTER_USE_FUNC_MODULE_ASSERT_LDOUBLE_OP_RESULT(
        nbp_basic_printer_module_assert_ldouble_op_result
    ),

    // callbacks for NBP_ASSERT_* macros
    NBP_PRINTER_USE_FUNC_ASSERT_RESULT(
        nbp_basic_printer_assert_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_OP_RESULT(
        nbp_basic_printer_assert_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_CHAR_OP_RESULT(
        nbp_basic_printer_assert_char_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_SHORT_OP_RESULT(
        nbp_basic_printer_assert_short_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_USHORT_OP_RESULT(
        nbp_basic_printer_assert_ushort_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_INT_OP_RESULT(
        nbp_basic_printer_assert_int_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_UINT_OP_RESULT(
        nbp_basic_printer_assert_uint_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_LONG_OP_RESULT(
        nbp_basic_printer_assert_long_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_ULONG_OP_RESULT(
        nbp_basic_printer_assert_ulong_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_LLONG_OP_RESULT(
        nbp_basic_printer_assert_llong_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_ULLONG_OP_RESULT(
        nbp_basic_printer_assert_ullong_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_FLOAT_OP_RESULT(
        nbp_basic_printer_assert_float_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_DOUBLE_OP_RESULT(
        nbp_basic_printer_assert_double_op_result
    ),
    NBP_PRINTER_USE_FUNC_ASSERT_LDOUBLE_OP_RESULT(
        nbp_basic_printer_assert_ldouble_op_result
    )
);

#undef NBP_PRIVATE_COLOR_NORMAL
#undef NBP_PRIVATE_COLOR_RED
#undef NBP_PRIVATE_COLOR_GREEN
#undef NBP_PRIVATE_COLOR_YELLOW

#undef NBP_PRIVATE_PRINTER_TYPE_UNKNOWN
#undef NBP_PRIVATE_PRINTER_TYPE_TEST
#undef NBP_PRIVATE_PRINTER_TYPE_MODULE

#undef DECLARE_MUTEX
#undef MUTEX_INIT
#undef MUTEX_UNINIT
#undef MUTEX_LOCK
#undef MUTEX_UNLOCK

#endif // end if NBP_PRIVATE_PRINTER_LINUX_BASIC_PRINTER_H

