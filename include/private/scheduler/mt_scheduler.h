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

#ifndef NBP_PRIVATE_SCHEDULER_MT_SCHEDULER_H
#define NBP_PRIVATE_SCHEDULER_MT_SCHEDULER_H

#define NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_UNKNOWN            (unsigned int) 0x60000000
#define NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_BEFORE             (unsigned int) 0x60000001
#define NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_AFTER              (unsigned int) 0x60000002
#define NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD        (unsigned int) 0x60000003

#define NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_UNKNOWN       (unsigned int) 0x61000000
#define NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_EMPTY         (unsigned int) 0x61000001
#define NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_TEST          (unsigned int) 0x61000002
#define NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_MODULE        (unsigned int) 0x61000003

struct nbp_mt_scheduler_rule_t {
    unsigned int ruleType;
    unsigned int dataType;
    union {
        nbp_test_details_t* test;
        nbp_module_details_t* module;
    };
};
typedef struct nbp_mt_scheduler_rule_t nbp_mt_scheduler_rule_t;

struct nbp_mt_scheduler_context_t {
    unsigned long long numberOfRules;
    nbp_mt_scheduler_rule_t rules[1];
};
typedef struct nbp_mt_scheduler_context_t nbp_mt_scheduler_context_t;

nbp_mt_scheduler_rule_t nbp_mt_schduler_create_rule_from_test(
    unsigned int ruleType,
    nbp_test_details_t* test
);

nbp_mt_scheduler_rule_t nbp_mt_schduler_create_rule_from_module(
    unsigned int ruleType,
    nbp_module_details_t* module
);

nbp_mt_scheduler_rule_t nbp_mt_scheduler_create_empty_rule(
    unsigned int ruleType
);

void* nbp_mt_scheduler_create_ctx(
    unsigned long long numberOfRules,
    ...
);

/*
 * TODO: add docs
 */
#define NBP_MT_SCHEDULER_RUN_BEFORE_TEST(test)                                 \
    nbp_mt_schduler_create_rule_from_test(                                     \
        NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_BEFORE,                             \
        NBP_TEST_GET_PTR(test)                                                 \
    )

/*
 * TODO: add docs
 */
#define NBP_MT_SCHEDULER_RUN_AFTER_TEST(test)                                  \
    nbp_mt_schduler_create_rule_from_test(                                     \
        NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_AFTER,                              \
        NBP_TEST_GET_PTR(test)                                                 \
    )

/*
 * TODO: add docs
 */
#define NBP_MT_SCHEDULER_RUN_BEFORE_MODULE(module)                             \
    nbp_mt_schduler_create_rule_from_module(                                   \
        NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_BEFORE,                             \
        NBP_MODULE_GET_PTR(module)                                             \
    )

/*
 * TODO: add docs
 */
#define NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module)                              \
    nbp_mt_schduler_create_rule_from_module(                                   \
        NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_AFTER,                              \
        NBP_MODULE_GET_PTR(module)                                             \
    )

/*
 * TODO: add docs
 */
#define NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(test)                      \
    nbp_mt_schduler_create_rule_from_test(                                     \
        NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD,                        \
        NBP_TEST_GET_PTR(test)                                                 \
    )

/*
 * TODO: add docs
 */
#define NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_MODULE(module)                  \
    nbp_mt_schduler_create_rule_from_module(                                   \
        NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD,                        \
        NBP_MODULE_GET_PTR(module)                                             \
    )

/*
 * TODO: add docs
 */
#define NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD                                    \
    nbp_mt_scheduler_create_empty_rule(                                        \
        NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD                         \
    )

/*
 * TODO: add docs
 */
#define NBP_MT_SCHEDULER_CTX(...)                                              \
    nbp_mt_scheduler_create_ctx(                                               \
        NBP_MT_SCHEDULER_PRIVATE_GET_NUMBER_OF_RULES(__VA_ARGS__),             \
        ## __VA_ARGS__                                                         \
    )

#define NBP_MT_SCHEDULER_PRIVATE_GET_NUMBER_OF_RULES(...)                      \
    sizeof((nbp_mt_scheduler_rule_t[]){ __VA_ARGS__ }) /                       \
    sizeof(nbp_mt_scheduler_rule_t)

/*
 * NBP_SCHEDULER_PREPROCESSING_CONTEXT implementation
 */

#define NBP_PP_EAT_PP_NBP_MT_SCHEDULER_RUN_AFTER_TEST(name)                    \
    NBP_TEST_INCLUDE(name);

#define NBP_PP_EAT_PP_NBP_MT_SCHEDULER_RUN_BEFORE_TEST(name)                   \
    NBP_TEST_INCLUDE(name);

#define NBP_PP_EAT_PP_NBP_MT_SCHEDULER_RUN_AFTER_MODULE(name)                  \
    NBP_MODULE_INCLUDE(name);

#define NBP_PP_EAT_PP_NBP_MT_SCHEDULER_RUN_BEFORE_MODULE(name)                 \
    NBP_MODULE_INCLUDE(name);

#define NBP_PP_EAT_PP_NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(name)        \
    NBP_TEST_INCLUDE(name);

#define NBP_PP_EAT_PP_NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_MODULE(name)      \
    NBP_MODULE_INCLUDE(name);

#define NBP_PP_EAT_PP_NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD

#define NBP_PP_EAT_PP_NBP_MT_SCHEDULER_CTX(...)                                \
    NBP_PP_CONCAT(                                                             \
        NBP_PP_PROCESSING_PARAM_,                                              \
        NBP_PP_VARCOUNT(PP_ ## __VA_ARGS__)                                    \
    )(PP_ ## __VA_ARGS__)

#define NBP_SCHEDULER_PREPROCESSING_CONTEXT(ctx)                               \
    NBP_PP_EAT_ ## ctx

#ifdef NBP_LIBRARY_MAIN

#include <stdarg.h>

/*
 * nbp_mt_scheduler_get_number_of_threads() implementation
 */
#ifdef NBP_MT_SCHEDULER_NUMBER_OF_THREADS

#if NBP_MT_SCHEDULER_NUMBER_OF_THREADS >= 1

unsigned int nbp_mt_scheduler_get_number_of_threads()
{
    int num = NBP_MT_SCHEDULER_NUMBER_OF_THREADS;
    if (num < 1) {
        // these lines are excluded from coverage because it is impossible to
        // trigger an error
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_GENERIC_ERROR,
            "failed to get the number of threads"
        );
        NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
        return 1;
        // LCOV_EXCL_STOP
    }

    return (unsigned int) num;
}

#else // NBP_MT_SCHEDULER_NUMBER_OF_THREADS is less than 1

#error "Invalid number of threads"

#endif // end if NBP_MT_SCHEDULER_NUMBER_OF_THREADS >= 1

#else // NBP_MT_SCHEDULER_NUMBER_OF_THREADS not defined

#ifdef NBP_OS_LINUX

#include <sys/sysinfo.h>

unsigned int nbp_mt_scheduler_get_number_of_threads()
{
    int num = get_nprocs();
    if (num < 1) {
        // these lines are excluded from coverage because it is impossible to
        // trigger an error for get_nprocs
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_GENERIC_ERROR,
            "failed to get the number of threads"
        );
        NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
        return 1;
        // LCOV_EXCL_STOP
    }

    return (unsigned int) num;
}

#endif // end if NBP_OS_LINUX

#ifdef NBP_OS_WINDOWS
#error "Not supported"
#endif // end if NBP_OS_WINDOWS

#ifdef NBP_OS_MAC
#error "Not supported"
#endif // end if NBP_OS_MAC

#ifdef NBP_OS_CUSTOM
#error "Not supported"
#endif // end if NBP_OS_CUSTOM

#endif // end if NBP_MT_SCHEDULER_NUMBER_OF_THREADS

#ifdef NBP_OS_LINUX

#include <pthread.h>

/*
 * Thread wrapper
 */

#define NBP_MT_SCHEDULER_THREAD_TYPE pthread_t

#define NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE void*

#define NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE_DEFAULT_VALUE NULL

#define NBP_MT_SCHEDULER_THREAD_CREATE(thread, func, param)                    \
    pthread_create(&thread, NULL, func, param) == 0                            \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_GENERIC_ERROR

#define NBP_MT_SCHEDULER_THREAD_JOIN(thread)                                   \
    pthread_join(thread, NULL) == 0                                            \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_GENERIC_ERROR

/*
 * Mutex wrapper
 */

#define NBP_MT_SCHEDULER_MUTEX_TYPE pthread_mutex_t

#define NBP_MT_SCHEDULER_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER

#define NBP_MT_SCHEDULER_MUTEX_INIT(mutex)                                     \
    pthread_mutex_init(&mutex, NULL) == 0                                      \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#define NBP_MT_SCHEDULER_MUTEX_UNINIT(mutex)                                   \
    pthread_mutex_destroy(&mutex) == 0                                         \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#define NBP_MT_SCHEDULER_MUTEX_LOCK(mutex)                                     \
    pthread_mutex_lock(&mutex) == 0                                            \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#define NBP_MT_SCHEDULER_MUTEX_UNLOCK(mutex)                                   \
    pthread_mutex_unlock(&mutex) == 0                                          \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

/*
 * Conditional variable wrapper
 */

#define NBP_MT_SCHEDULER_CONDVAR_TYPE pthread_cond_t

#define NBP_MT_SCHEDULER_CONDVAR_INITIALIZER PTHREAD_COND_INITIALIZER

#define NBP_MT_SCHEDULER_CONDVAR_INIT(condvar)                                 \
    pthread_cond_init(&condvar, NULL) == 0                                     \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#define NBP_MT_SCHEDULER_CONDVAR_UNINIT(condvar)                               \
    pthread_cond_destroy(&condvar) == 0                                        \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#define NBP_MT_SCHEDULER_CONDVAR_WAIT(condvar, mutex)                          \
    pthread_cond_wait(&condvar, &mutex) == 0                                   \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#define NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ONE(condvar)                           \
    pthread_cond_signal(&condvar) == 0                                         \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#define NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ALL(condvar)                           \
    pthread_cond_broadcast(&condvar) == 0                                      \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#endif // end if NBP_OS_LINUX

#ifdef NBP_OS_WINDOWS
#error "Not supported"
#endif // end if NBP_OS_WINDOWS

#ifdef NBP_OS_MAC
#error "Not supported"
#endif // end if NBP_OS_MAC

#ifdef NBP_OS_CUSTOM
#error "Not supported"
#endif // end if NBP_OS_CUSTOM

/*
 * Check if thread wrapper is defined, otherwise define a dummy thread wrapper.
 * If NBP_OS_* is not defined then the thread wrapper will not be defined so the
 * compiler will generate a lot of errors and the error message that says that
 * there is no NBP_OS_* defined is hard to see.
 */

#ifndef NBP_MT_SCHEDULER_THREAD_TYPE
#define NBP_MT_SCHEDULER_THREAD_TYPE int
#endif // end if NBP_MT_SCHEDULER_THREAD_TYPE

#ifndef NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE
#define NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE void*
#endif // end if NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE

#ifndef NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE_DEFAULT_VALUE
#define NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE_DEFAULT_VALUE ((void*) 0x0)
#endif // end if NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE_DEFAULT_VALUE

#ifndef NBP_MT_SCHEDULER_THREAD_CREATE
#define NBP_MT_SCHEDULER_THREAD_CREATE(thread, func, param)                    \
    NBP_ERROR_CODE_GENERIC_ERROR
#endif // end if NBP_MT_SCHEDULER_THREAD_CREATE

#ifndef NBP_MT_SCHEDULER_THREAD_JOIN
#define NBP_MT_SCHEDULER_THREAD_JOIN(thread) NBP_ERROR_CODE_GENERIC_ERROR
#endif // end if NBP_MT_SCHEDULER_THREAD_JOIN

/*
 * Check if mutex wrapper is defined, otherwise define a dummy mutex wrapper.
 * If NBP_OS_* is not defined then the mutex wrapper will not be defined so the
 * compiler will generate a lot of errors and the error message that says that
 * there is no NBP_OS_* defined is hard to see.
 */

#ifndef NBP_MT_SCHEDULER_MUTEX_TYPE
#define NBP_MT_SCHEDULER_MUTEX_TYPE int
#endif // end if NBP_MT_SCHEDULER_MUTEX_TYPE

#ifndef NBP_MT_SCHEDULER_MUTEX_INITIALIZER
#define NBP_MT_SCHEDULER_MUTEX_INITIALIZER 0
#endif // end if NBP_MT_SCHEDULER_MUTEX_INITIALIZER

#ifndef NBP_MT_SCHEDULER_MUTEX_INIT
#define NBP_MT_SCHEDULER_MUTEX_INIT(mutex) mutex++
#endif // end if NBP_MT_SCHEDULER_MUTEX_INIT

#ifndef NBP_MT_SCHEDULER_MUTEX_UNINIT
#define NBP_MT_SCHEDULER_MUTEX_UNINIT(mutex) mutex++
#endif // end if NBP_MT_SCHEDULER_MUTEX_UNINIT

#ifndef NBP_MT_SCHEDULER_MUTEX_LOCK
#define NBP_MT_SCHEDULER_MUTEX_LOCK(mutex) mutex++
#endif // end if NBP_MT_SCHEDULER_MUTEX_LOCK

#ifndef NBP_MT_SCHEDULER_MUTEX_UNLOCK
#define NBP_MT_SCHEDULER_MUTEX_UNLOCK(mutex) mutex++
#endif // end if NBP_MT_SCHEDULER_MUTEX_UNLOCK

/*
 * Check if conditional variable wrapper is defined, otherwise define a dummy
 * conditional variable wrapper.
 * If NBP_OS_* is not defined then the conditional variable wrapper will not be
 * defined so the compiler will generate a lot of errors and the error message
 * that says that there is no NBP_OS_* defined is hard to see.
 */

#ifndef NBP_MT_SCHEDULER_CONDVAR_TYPE
#define NBP_MT_SCHEDULER_CONDVAR_TYPE int
#endif // end if NBP_MT_SCHEDULER_CONDVAR_TYPE

#ifndef NBP_MT_SCHEDULER_CONDVAR_INITIALIZER
#define NBP_MT_SCHEDULER_CONDVAR_INITIALIZER 0
#endif // end if NBP_MT_SCHEDULER_CONDVAR_INITIALIZER

#ifndef NBP_MT_SCHEDULER_CONDVAR_INIT
#define NBP_MT_SCHEDULER_CONDVAR_INIT(condvar) condvar++
#endif // end if NBP_MT_SCHEDULER_CONDVAR_INIT

#ifndef NBP_MT_SCHEDULER_CONDVAR_UNINIT
#define NBP_MT_SCHEDULER_CONDVAR_UNINIT(condvar) condvar++
#endif // end if NBP_MT_SCHEDULER_CONDVAR_UNINIT

#ifndef NBP_MT_SCHEDULER_CONDVAR_WAIT
#define NBP_MT_SCHEDULER_CONDVAR_WAIT(condvar, mutex) condvar++
#endif // end if NBP_MT_SCHEDULER_CONDVAR_WAIT

#ifndef NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ONE
#define NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ONE(condvar) condvar++
#endif // end if NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ONE

#ifndef NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ALL
#define NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ALL(condvar) condvar++
#endif // end if NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ALL

#define NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_UNKNOWN  (unsigned int) 0x62000000
#define NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_TEST     (unsigned int) 0x62000001
#define NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_MODULE   (unsigned int) 0x62000002

#define NBP_MT_SCHEDULER_PRIVATE_INVALID_WORKER_ID  (unsigned int) 0xFFFFFFFF

struct nbp_mt_scheduler_data_t {
    unsigned int dataType;
    union {
        nbp_test_details_t* test;
        nbp_module_details_t* module;
    };
    nbp_mt_scheduler_context_t* ctx;
    struct nbp_mt_scheduler_data_t* next;
};
typedef struct nbp_mt_scheduler_data_t nbp_mt_scheduler_data_t;

struct nbp_mt_scheduler_test_t {
    nbp_test_details_t* test;
    unsigned int numberOfPendingTests;

    unsigned int* requestedWorkerId;
    struct nbp_mt_scheduler_test_t* nextTestOnThisWorker;

    struct nbp_mt_scheduler_test_t* nextInQueue;
};
typedef struct nbp_mt_scheduler_test_t nbp_mt_scheduler_test_t;

struct nbp_mt_scheduler_thread_t {
    NBP_MT_SCHEDULER_THREAD_TYPE thread;
    unsigned int workerId;
};
typedef struct nbp_mt_scheduler_thread_t nbp_mt_scheduler_thread_t;

static nbp_mt_scheduler_data_t* nbpMtSchedulerData = NBP_MEMORY_NULL_POINTER;
static nbp_mt_scheduler_data_t* nbpMtSchedulerDataLast = NBP_MEMORY_NULL_POINTER;

static nbp_mt_scheduler_test_t* nbpMtSchedulerTests = NBP_MEMORY_NULL_POINTER;
static unsigned int nbpMtSchedulerNumberOfTests = 0;
static unsigned int nbpMtSchedulerNumberOfColumns = 0;
static unsigned int* nbpMtSchedulerAdjacencyMatrix = NBP_MEMORY_NULL_POINTER;

static nbp_mt_scheduler_test_t* nbpMtSchedulerQueue = NBP_MEMORY_NULL_POINTER;
static nbp_mt_scheduler_test_t* nbpMtSchedulerQueueLast = NBP_MEMORY_NULL_POINTER;

static NBP_MT_SCHEDULER_MUTEX_TYPE nbpMtSchedulerMutex = NBP_MT_SCHEDULER_MUTEX_INITIALIZER;
static NBP_MT_SCHEDULER_CONDVAR_TYPE nbpMtSchedulerCondVar = NBP_MT_SCHEDULER_CONDVAR_INITIALIZER;

static unsigned int nbpMtSchedulerNumberOfDispatchedTests = 0;

nbp_mt_scheduler_rule_t nbp_mt_schduler_create_rule_from_test(
    unsigned int ruleType, nbp_test_details_t* test)
{
    nbp_mt_scheduler_rule_t rule;

    rule.ruleType   = ruleType;
    rule.dataType   = NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_TEST;
    rule.test       = test;

    return rule;
}

nbp_mt_scheduler_rule_t nbp_mt_schduler_create_rule_from_module(
    unsigned int ruleType, nbp_module_details_t* module)
{
    nbp_mt_scheduler_rule_t rule;

    rule.ruleType   = ruleType;
    rule.dataType   = NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_MODULE;
    rule.module     = module;

    return rule;
}

nbp_mt_scheduler_rule_t nbp_mt_scheduler_create_empty_rule(
    unsigned int ruleType)
{
    nbp_mt_scheduler_rule_t rule;

    rule.ruleType   = ruleType;
    rule.dataType   = NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_EMPTY;
    rule.test       = NBP_MEMORY_NULL_POINTER;

    return rule;
}

void* nbp_mt_scheduler_create_ctx(unsigned long long numberOfRules, ...)
{
    va_list args;

    unsigned long long index;
    unsigned long long size = sizeof(nbp_mt_scheduler_context_t);
    if (numberOfRules > 1) {
        size += ((numberOfRules - 1) * sizeof(nbp_mt_scheduler_rule_t));
    }

    nbp_mt_scheduler_context_t* ctx =
        (nbp_mt_scheduler_context_t*) NBP_MEMORY_ALLOC(size);
    if (ctx == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for memory allocation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_OUT_OF_MEMORY,
            "could not alloc context"
        );
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        return NBP_MEMORY_NULL_POINTER;
        // LCOV_EXCL_STOP
    }

    va_start(args, numberOfRules);

    ctx->numberOfRules = numberOfRules;
    for (index = 0; index < numberOfRules; ++index) {
        ctx->rules[index] = va_arg(args, nbp_mt_scheduler_rule_t);
    }

    va_end(args);

    return (void*) ctx;
}

static void nbp_mt_scheduler_queue_push(unsigned int testId)
{
    if (nbpMtSchedulerQueueLast == NBP_MEMORY_NULL_POINTER) {
        nbpMtSchedulerQueue = &nbpMtSchedulerTests[testId];
        nbpMtSchedulerQueueLast = &nbpMtSchedulerTests[testId];
    } else {
        nbpMtSchedulerQueueLast->nextInQueue = &nbpMtSchedulerTests[testId];
        nbpMtSchedulerQueueLast = &nbpMtSchedulerTests[testId];
    }
}

static nbp_mt_scheduler_test_t* nbp_mt_scheduler_queue_pop(unsigned int workerId)
{
    nbp_mt_scheduler_test_t* prev = NBP_MEMORY_NULL_POINTER;
    nbp_mt_scheduler_test_t* test = nbpMtSchedulerQueue;

    while (test != NBP_MEMORY_NULL_POINTER) {
        if (test->requestedWorkerId == NBP_MEMORY_NULL_POINTER) {
            break;
        }

        if (*test->requestedWorkerId == NBP_MT_SCHEDULER_PRIVATE_INVALID_WORKER_ID ) {
            *test->requestedWorkerId = workerId;
            break;
        }

        if (*test->requestedWorkerId == workerId) {
            break;
        }

        prev = test;
        test = test->nextInQueue;
    }

    // no test found for this worker
    if (test == NBP_MEMORY_NULL_POINTER) {
        return test;
    }

    // test is the first element in queue
    if (test == nbpMtSchedulerQueue) {
        nbpMtSchedulerQueue = test->nextInQueue;

        // test is the only element in queue
        if (test == nbpMtSchedulerQueueLast) {
            nbpMtSchedulerQueueLast = NBP_MEMORY_NULL_POINTER;
        }

        return test;
    }

    // test is the last element in queue
    if (test == nbpMtSchedulerQueueLast) {
        prev->nextInQueue = NBP_MEMORY_NULL_POINTER;
        nbpMtSchedulerQueueLast = prev;

        return test;
    }

    // the is somewhere in queue but it is not the first or last
    prev->nextInQueue = test->nextInQueue;

    return test;
}

static nbp_test_details_t* nbp_mt_scheduler_get_first_test_from_module(
    nbp_module_details_t* module)
{
    nbp_test_details_t* firstTest = NBP_MEMORY_NULL_POINTER;
    nbp_test_details_t* test;
    nbp_module_details_t* submodule;

    NBP_MODULE_FOR_EACH_TEST(module, test) {
        return test;
    }

    NBP_MODULE_FOR_EACH_SUBMODULE(module, submodule) {
        firstTest = nbp_mt_scheduler_get_first_test_from_module(submodule);
        if (firstTest != NBP_MEMORY_NULL_POINTER) {
            return firstTest;
        }
    }

    return NBP_MEMORY_NULL_POINTER;
}

static void nbp_mt_scheduler_set_test_on_same_thread_as_test(
    unsigned int testId1, unsigned int testId2)
{
    nbp_mt_scheduler_test_t* test1;
    nbp_mt_scheduler_test_t* test2;
    nbp_mt_scheduler_test_t* last = NBP_MEMORY_NULL_POINTER;
    nbp_mt_scheduler_test_t* current;

    if (testId1 == testId2) {
        return;
    }

    test1 = &nbpMtSchedulerTests[testId1];
    test2 = &nbpMtSchedulerTests[testId2];

    if (test1->requestedWorkerId == test2->requestedWorkerId) {
        if (test1->requestedWorkerId != NBP_MEMORY_NULL_POINTER) {
            return;
        }

        test1->requestedWorkerId =
            (unsigned int*) NBP_MEMORY_ALLOC(sizeof(unsigned int));
        if (test1->requestedWorkerId == NBP_MEMORY_NULL_POINTER) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for memory allocation
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(NBP_ERROR_CODE_OUT_OF_MEMORY);
            NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
            // LCOV_EXCL_STOP
        }

        *test1->requestedWorkerId = NBP_MT_SCHEDULER_PRIVATE_INVALID_WORKER_ID;

        test2->requestedWorkerId = test1->requestedWorkerId;

        test1->nextTestOnThisWorker = test2;
        test2->nextTestOnThisWorker = test1;

        return;
    }

    if (test1->requestedWorkerId == NBP_MEMORY_NULL_POINTER) {
        test1->requestedWorkerId = test2->requestedWorkerId;

        test1->nextTestOnThisWorker = test2->nextTestOnThisWorker;
        test2->nextTestOnThisWorker = test1;

        return;
    }

    if (test2->requestedWorkerId == NBP_MEMORY_NULL_POINTER) {
        test2->requestedWorkerId = test1->requestedWorkerId;

        test2->nextTestOnThisWorker = test1->nextTestOnThisWorker;
        test1->nextTestOnThisWorker = test2;

        return;
    }

    NBP_MEMORY_FREE(test2->requestedWorkerId);
    test2->requestedWorkerId = test1->requestedWorkerId;

    current = test2->nextTestOnThisWorker;
    while (current != test2) {
        current->requestedWorkerId = test1->requestedWorkerId;

        last = current;
        current = current->nextTestOnThisWorker;
    }

    current = test1->nextTestOnThisWorker;
    test1->nextTestOnThisWorker = test2;
    last->nextTestOnThisWorker = current;
}

static void nbp_mt_scheduler_set_module_on_same_thread_as_test(
    nbp_module_details_t* module, unsigned int testId)
{
    nbp_test_details_t* test;
    nbp_module_details_t* submodule;
    unsigned int testId2;

    NBP_MODULE_FOR_EACH_TEST(module, test) {
        testId2 = NBP_TEST_GET_ID(test);
        nbp_mt_scheduler_set_test_on_same_thread_as_test(testId, testId2);
    }

    NBP_MODULE_FOR_EACH_SUBMODULE(module, submodule) {
        nbp_mt_scheduler_set_module_on_same_thread_as_test(submodule, testId);
    }
}

static void nbp_mt_scheduler_set_module_on_same_thread_as_module(
    nbp_module_details_t* module1, nbp_module_details_t* module2)
{
    nbp_test_details_t* module1FirstTest = NBP_MEMORY_NULL_POINTER;
    nbp_test_details_t* module2FirstTest = NBP_MEMORY_NULL_POINTER;
    unsigned int module1FirstTestId = 0;
    unsigned int module2FirstTestId = 0;

    module1FirstTest = nbp_mt_scheduler_get_first_test_from_module(module1);
    if (module1FirstTest != NBP_MEMORY_NULL_POINTER) {
        module1FirstTestId = NBP_TEST_GET_ID(module1FirstTest);
        nbp_mt_scheduler_set_module_on_same_thread_as_test(
            module1,
            module1FirstTestId
        );
    }

    module2FirstTest = nbp_mt_scheduler_get_first_test_from_module(module2);
    if (module2FirstTest != NBP_MEMORY_NULL_POINTER) {
        module2FirstTestId = NBP_TEST_GET_ID(module2FirstTest);
        nbp_mt_scheduler_set_module_on_same_thread_as_test(
            module2,
            module2FirstTestId
        );
    }

    if (module1FirstTest != NBP_MEMORY_NULL_POINTER &&
        module2FirstTest != NBP_MEMORY_NULL_POINTER) {
        nbp_mt_scheduler_set_test_on_same_thread_as_test(
            module1FirstTestId,
            module2FirstTestId
        );
    }
}

static void nbp_mt_scheduler_set_module_on_same_thread(
    nbp_module_details_t* module)
{
    nbp_test_details_t* firstTest = NBP_MEMORY_NULL_POINTER;
    nbp_test_details_t* test;
    nbp_module_details_t* submodule;
    unsigned int firstTestId;
    unsigned int testId;

    firstTest = nbp_mt_scheduler_get_first_test_from_module(module);
    if (firstTest == NBP_MEMORY_NULL_POINTER) {
        return;
    }

    firstTestId = NBP_TEST_GET_ID(firstTest);

    NBP_MODULE_FOR_EACH_TEST(module, test) {
        testId = NBP_TEST_GET_ID(test);
        nbp_mt_scheduler_set_test_on_same_thread_as_test(firstTestId, testId);
    }

    NBP_MODULE_FOR_EACH_SUBMODULE(module, submodule) {
        nbp_mt_scheduler_set_module_on_same_thread_as_test(
            submodule,
            firstTestId
        );
    }
}

static void nbp_mt_scheduler_add_pending_test_to_test(unsigned int pendingTestId,
    unsigned int testId)
{
    unsigned int bitsPerUint = sizeof(unsigned int) * 8;
    unsigned int rowIndex;
    unsigned int columnIndex;
    unsigned int testIndex;
    unsigned int testBit;
    unsigned int* matrixElement;

    rowIndex = pendingTestId * nbpMtSchedulerNumberOfColumns;
    columnIndex = testId / bitsPerUint;
    matrixElement = nbpMtSchedulerAdjacencyMatrix + rowIndex + columnIndex;

    testIndex = testId % bitsPerUint;
    testBit = ((unsigned int) 1) << testIndex;

    if ((*matrixElement & testBit) == 0) {
        *matrixElement |= testBit;
        nbpMtSchedulerTests[testId].numberOfPendingTests++;
    }
}

static void nbp_mt_scheduler_add_pending_test_to_module(
    unsigned int pendingTestId, nbp_module_details_t* module)
{
    nbp_test_details_t* test;
    nbp_module_details_t* submodule;
    unsigned int testId;

    NBP_MODULE_FOR_EACH_TEST(module, test) {
        testId = NBP_TEST_GET_ID(test);
        nbp_mt_scheduler_add_pending_test_to_test(pendingTestId, testId);
    }

    NBP_MODULE_FOR_EACH_SUBMODULE(module, submodule) {
        nbp_mt_scheduler_add_pending_test_to_module(pendingTestId, submodule);
    }
}

static void nbp_mt_scheduler_add_pending_module_to_test(
    nbp_module_details_t* pendingModule, unsigned int testId)
{
    nbp_test_details_t* test;
    nbp_module_details_t* submodule;
    unsigned int pendingTestId;

    NBP_MODULE_FOR_EACH_TEST(pendingModule, test) {
        pendingTestId = NBP_TEST_GET_ID(test);
        nbp_mt_scheduler_add_pending_test_to_test(pendingTestId, testId);
    }

    NBP_MODULE_FOR_EACH_SUBMODULE(pendingModule, submodule) {
        nbp_mt_scheduler_add_pending_module_to_test(submodule, testId);
    }
}

static void nbp_mt_scheduler_add_pending_module_to_module(
    nbp_module_details_t* pendingModule, nbp_module_details_t* module)
{
    nbp_test_details_t* test;
    nbp_module_details_t* submodule;
    unsigned int testId;

    NBP_MODULE_FOR_EACH_TEST(module, test) {
        testId = NBP_TEST_GET_ID(test);
        nbp_mt_scheduler_add_pending_module_to_test(pendingModule, testId);
    }

    NBP_MODULE_FOR_EACH_SUBMODULE(module, submodule) {
        nbp_mt_scheduler_add_pending_module_to_module(pendingModule, submodule);
    }
}

static int nbp_mt_scheduler_test_completed(unsigned int testId)
{
    unsigned int bitsPerUint = sizeof(unsigned int) * 8;
    unsigned int columnIndex = 0;
    unsigned int rowIndex;
    unsigned int testIndex;
    unsigned int* matrixRowStart;
    int notifyWorkers = 0;

    rowIndex = testId * nbpMtSchedulerNumberOfColumns;
    matrixRowStart = nbpMtSchedulerAdjacencyMatrix + rowIndex;

    for ( ; columnIndex < nbpMtSchedulerNumberOfColumns; columnIndex++) {
        testIndex = columnIndex * bitsPerUint;
        while (matrixRowStart[columnIndex] != 0) {
            if ((matrixRowStart[columnIndex] & 1) != 0) {
                nbpMtSchedulerTests[testIndex].numberOfPendingTests--;
                if (nbpMtSchedulerTests[testIndex].numberOfPendingTests == 0) {
                    nbp_mt_scheduler_queue_push(testIndex);
                    notifyWorkers = 1;
                }
            }

            testIndex++;
            matrixRowStart[columnIndex] >>= 1; /* TODO: portable lzcnt */
        }
    }

    return notifyWorkers;
}

static NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE nbp_mt_scheduler_worker_thread_func(
    void* param)
{
    unsigned int workerId = *((unsigned int*) param);
    nbp_mt_scheduler_test_t* test;
    NBP_ERROR_CODE_TYPE errCode;
    int notifyWorkers = 0;

    (void)(workerId);

    errCode = NBP_MT_SCHEDULER_MUTEX_LOCK(nbpMtSchedulerMutex);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_MT_SCHEDULER_MUTEX_LOCK
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(errCode);
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }

    while (nbpMtSchedulerNumberOfDispatchedTests != nbpMtSchedulerNumberOfTests) {
        test = nbp_mt_scheduler_queue_pop(workerId);
        if (test == NBP_MEMORY_NULL_POINTER) {
            errCode = NBP_MT_SCHEDULER_CONDVAR_WAIT(
                nbpMtSchedulerCondVar,
                nbpMtSchedulerMutex
            );
            if (errCode != NBP_ERROR_CODE_SUCCESS) {
                // these lines are excluded from coverage because it is pretty
                // hard to trigger an error for NBP_MT_SCHEDULER_CONDVAR_WAIT
                // LCOV_EXCL_START
                NBP_ERROR_REPORT(errCode);
                NBP_EXIT(errCode);
                // LCOV_EXCL_STOP
            }

            continue;
        }

        nbpMtSchedulerNumberOfDispatchedTests++;

        errCode = NBP_MT_SCHEDULER_MUTEX_UNLOCK(nbpMtSchedulerMutex);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_MT_SCHEDULER_MUTEX_UNLOCK
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        NBP_SCHEDULER_RUN_TEST(test->test);

        errCode = NBP_MT_SCHEDULER_MUTEX_LOCK(nbpMtSchedulerMutex);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_MT_SCHEDULER_MUTEX_LOCK
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        notifyWorkers = nbp_mt_scheduler_test_completed(
            NBP_TEST_GET_ID(test->test)
        );
        if (notifyWorkers == 0) {
            continue;
        }

        errCode = NBP_MT_SCHEDULER_MUTEX_UNLOCK(nbpMtSchedulerMutex);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_MT_SCHEDULER_MUTEX_UNLOCK
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        errCode = NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ALL(nbpMtSchedulerCondVar);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ALL
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        errCode = NBP_MT_SCHEDULER_MUTEX_LOCK(nbpMtSchedulerMutex);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_MT_SCHEDULER_MUTEX_LOCK
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }
    }

    errCode = NBP_MT_SCHEDULER_MUTEX_UNLOCK(nbpMtSchedulerMutex);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_MT_SCHEDULER_MUTEX_UNLOCK
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(errCode);
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }

    return NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE_DEFAULT_VALUE;
}

static void nbp_mt_scheduler_processing_test_context(unsigned int testId,
    nbp_mt_scheduler_context_t* ctx)
{
    unsigned int ruleDataTestId;
    unsigned long long index;
    nbp_mt_scheduler_rule_t* rule;

    for (index = 0; index < ctx->numberOfRules; index++) {
        rule = &ctx->rules[index];
        if (rule->dataType == NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_TEST) {
            ruleDataTestId = NBP_TEST_GET_ID(rule->test);

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_AFTER) {
                nbp_mt_scheduler_add_pending_test_to_test(ruleDataTestId, testId);
                continue;
            }

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_BEFORE) {
                nbp_mt_scheduler_add_pending_test_to_test(testId, ruleDataTestId);
                continue;
            }

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD) {
                nbp_mt_scheduler_set_test_on_same_thread_as_test(testId, ruleDataTestId);
                continue;
            }

            // these lines are excluded from coverage because it is impossible
            // to use other values if there is no bug in implementation
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_GENERIC_ERROR,
                "unknown rule type"
            );
            NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
            // LCOV_EXCL_STOP
        }

        if (rule->dataType == NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_MODULE) {
            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_AFTER) {
                nbp_mt_scheduler_add_pending_module_to_test(rule->module, testId);
                continue;
            }

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_BEFORE) {
                nbp_mt_scheduler_add_pending_test_to_module(testId, rule->module);
                continue;
            }

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD) {
                nbp_mt_scheduler_set_module_on_same_thread_as_test(rule->module, testId);
                continue;
            }

            // these lines are excluded from coverage because it is impossible
            // to use other values if there is no bug in implementation
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_GENERIC_ERROR,
                "unknown rule type"
            );
            NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
            // LCOV_EXCL_STOP
        }

        // these lines are excluded from coverage because it is impossible to
        // use other values if there is no bug in implementation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_GENERIC_ERROR,
            "unknown rule data type"
        );
        NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
        // LCOV_EXCL_STOP
    }
}

static void nbp_mt_scheduler_processing_module_context(
    nbp_module_details_t* module, nbp_mt_scheduler_context_t* ctx)
{
    unsigned int ruleDataTestId;
    unsigned long long index;
    nbp_mt_scheduler_rule_t* rule;

    for (index = 0; index < ctx->numberOfRules; index++) {
        rule = &ctx->rules[index];
        if (rule->dataType == NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_TEST) {
            ruleDataTestId = NBP_TEST_GET_ID(rule->test);

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_AFTER) {
                nbp_mt_scheduler_add_pending_test_to_module(ruleDataTestId, module);
                continue;
            }

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_BEFORE) {
                nbp_mt_scheduler_add_pending_module_to_test(module, ruleDataTestId);
                continue;
            }

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD) {
                nbp_mt_scheduler_set_module_on_same_thread_as_test(module, ruleDataTestId);
                continue;
            }

            // these lines are excluded from coverage because it is impossible
            // to use other values if there is no bug in implementation
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_GENERIC_ERROR,
                "unknown rule type"
            );
            NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
            // LCOV_EXCL_STOP
        }

        if (rule->dataType == NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_MODULE) {
            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_AFTER) {
                nbp_mt_scheduler_add_pending_module_to_module(rule->module, module);
                continue;
            }

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_BEFORE) {
                nbp_mt_scheduler_add_pending_module_to_module(module, rule->module);
                continue;
            }

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD) {
                nbp_mt_scheduler_set_module_on_same_thread_as_module(module, rule->module);
                continue;
            }

            // these lines are excluded from coverage because it is impossible
            // to use other values if there is no bug in implementation
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_GENERIC_ERROR,
                "unknown rule type"
            );
            NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
            // LCOV_EXCL_STOP
        }

        if (rule->dataType == NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_EMPTY) {
            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD) {
                nbp_mt_scheduler_set_module_on_same_thread(module);
                continue;
            }

            // these lines are excluded from coverage because it is impossible
            // to use other values if there is no bug in implementation
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_GENERIC_ERROR,
                "unknown rule type"
            );
            NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
            // LCOV_EXCL_STOP
        }

        // these lines are excluded from coverage because it is impossible to
        // use other values if there is no bug in implementation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_GENERIC_ERROR,
            "unknown rule data type"
        );
        NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
        // LCOV_EXCL_STOP
    }
}

static void nbp_mt_scheduler_allocate_array_of_tests()
{
    unsigned int index = 0;

    nbpMtSchedulerTests = (nbp_mt_scheduler_test_t*) NBP_MEMORY_ALLOC(
        nbpMtSchedulerNumberOfTests * sizeof(nbp_mt_scheduler_test_t)
    );
    if (nbpMtSchedulerTests == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for memory allocation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_OUT_OF_MEMORY,
            "could not alloc array of tests"
        );
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        // LCOV_EXCL_STOP
    }

    for ( ; index < nbpMtSchedulerNumberOfTests; index++) {
        nbpMtSchedulerTests[index].test = NBP_MEMORY_NULL_POINTER;
        nbpMtSchedulerTests[index].numberOfPendingTests = 0;

        nbpMtSchedulerTests[index].requestedWorkerId = NBP_MEMORY_NULL_POINTER;
        nbpMtSchedulerTests[index].nextTestOnThisWorker = NBP_MEMORY_NULL_POINTER;

        nbpMtSchedulerTests[index].nextInQueue = NBP_MEMORY_NULL_POINTER;
    }
}

static void nbp_mt_scheduler_allocate_adjacency_matrix()
{
    unsigned int bitsPerUint = sizeof(unsigned int) * 8;
    unsigned int index = 0;
    unsigned int numberOfElements;

    nbpMtSchedulerNumberOfColumns = nbpMtSchedulerNumberOfTests / bitsPerUint +
        (nbpMtSchedulerNumberOfTests % bitsPerUint != 0 ? 1 : 0);

    numberOfElements = nbpMtSchedulerNumberOfTests * nbpMtSchedulerNumberOfColumns;

    nbpMtSchedulerAdjacencyMatrix = (unsigned int*) NBP_MEMORY_ALLOC(
        numberOfElements * sizeof(unsigned int)
    );
    if (nbpMtSchedulerAdjacencyMatrix == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for memory allocation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_OUT_OF_MEMORY,
            "could not alloc adjacency matrix"
        );
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        // LCOV_EXCL_STOP
    }

    for ( ; index < numberOfElements; index++) {
        nbpMtSchedulerAdjacencyMatrix[index] = 0;
    }
}

static void nbp_mt_scheduler_processing_data()
{
    unsigned int testId;
    nbp_mt_scheduler_data_t* data = nbpMtSchedulerData;
    nbp_mt_scheduler_data_t* tmp;

    while (data != NBP_MEMORY_NULL_POINTER) {
        if (data->dataType == NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_TEST) {
            testId = NBP_TEST_GET_ID(data->test);
            nbpMtSchedulerTests[testId].test = data->test;

            if (data->ctx != NBP_MEMORY_NULL_POINTER) {
                nbp_mt_scheduler_processing_test_context(testId, data->ctx);
                NBP_MEMORY_FREE(data->ctx);
            }
        } else if (data->dataType == NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_MODULE) {
            if (data->ctx != NBP_MEMORY_NULL_POINTER) {
                nbp_mt_scheduler_processing_module_context(
                    data->module,
                    data->ctx
                );
                NBP_MEMORY_FREE(data->ctx);
            }
        } else {
            // these lines are excluded from coverage because it is impossible
            // to use other values if there is no bug in implementation
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_GENERIC_ERROR,
                "unknown data type"
            );
            NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
            // LCOV_EXCL_STOP
        }

        tmp = data;
        data = data->next;

        NBP_MEMORY_FREE(tmp);
    }

    nbpMtSchedulerData = NBP_MEMORY_NULL_POINTER;
    nbpMtSchedulerDataLast = NBP_MEMORY_NULL_POINTER;

    // TODO: check if there is a cycle

    for (testId = 0; testId < nbpMtSchedulerNumberOfTests; testId++) {
        if (nbpMtSchedulerTests[testId].numberOfPendingTests == 0) {
            nbp_mt_scheduler_queue_push(testId);
        }
    }
}

static void nbp_mt_scheduler_create_threads_and_run()
{
    unsigned int index = 0;
    unsigned int numberOfThreads = nbp_mt_scheduler_get_number_of_threads();
    nbp_mt_scheduler_thread_t* threads;
    NBP_ERROR_CODE_TYPE err;

    numberOfThreads--;

    threads = (nbp_mt_scheduler_thread_t*) NBP_MEMORY_ALLOC(
        numberOfThreads * sizeof(nbp_mt_scheduler_thread_t)
    );
    if (threads == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for memory allocation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_OUT_OF_MEMORY,
            "could not alloc array of threads"
        );
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        // LCOV_EXCL_STOP
    }

    for ( ; index < numberOfThreads; index++) {
        threads[index].workerId = index;
        err = NBP_MT_SCHEDULER_THREAD_CREATE(
            threads[index].thread,
            nbp_mt_scheduler_worker_thread_func,
            (void*) &threads[index].workerId
        );
        if (err != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_MT_SCHEDULER_THREAD_CREATE
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(err, "could not create thread");
            NBP_EXIT(err);
            // LCOV_EXCL_STOP
        }
    }

    nbp_mt_scheduler_worker_thread_func((void*) &index);

    for (index = 0; index < numberOfThreads; index++) {
        err = NBP_MT_SCHEDULER_THREAD_JOIN(threads[index].thread);
        if (err != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_MT_SCHEDULER_THREAD_JOIN
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(err, "failed to join thread");
            NBP_EXIT(err);
            // LCOV_EXCL_STOP
        }
    }

    NBP_MEMORY_FREE(threads);
}

NBP_SCHEDULER_CALLBACK_INIT(nbp_mt_scheduler_init)
{
    NBP_ERROR_CODE_TYPE errCode;

    errCode = NBP_MT_SCHEDULER_MUTEX_INIT(nbpMtSchedulerMutex);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_MT_SCHEDULER_MUTEX_INIT
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(errCode, "failed to init mutex");
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }

    errCode = NBP_MT_SCHEDULER_CONDVAR_INIT(nbpMtSchedulerCondVar);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_MT_SCHEDULER_CONDVAR_INIT
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(errCode, "failed to init conditional variable");
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }
}

NBP_SCHEDULER_CALLBACK_UNINIT(nbp_mt_scheduler_uninit)
{
    NBP_ERROR_CODE_TYPE errCode;
    nbp_mt_scheduler_data_t* tmp;

    while (nbpMtSchedulerData != NBP_MEMORY_NULL_POINTER) {
        if (nbpMtSchedulerData->ctx != NBP_MEMORY_NULL_POINTER) {
            NBP_MEMORY_FREE(nbpMtSchedulerData->ctx);
        }

        tmp = nbpMtSchedulerData;
        nbpMtSchedulerData = nbpMtSchedulerData->next;

        NBP_MEMORY_FREE(tmp);
    }
    nbpMtSchedulerDataLast = NBP_MEMORY_NULL_POINTER;

    nbpMtSchedulerTests = NBP_MEMORY_NULL_POINTER;
    nbpMtSchedulerAdjacencyMatrix = NBP_MEMORY_NULL_POINTER;

    nbpMtSchedulerQueue = NBP_MEMORY_NULL_POINTER;
    nbpMtSchedulerQueueLast = NBP_MEMORY_NULL_POINTER;

    errCode = NBP_MT_SCHEDULER_MUTEX_UNINIT(nbpMtSchedulerMutex);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_MT_SCHEDULER_MUTEX_UNINIT
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(errCode, "failed to uninit mutex");
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }

    errCode = NBP_MT_SCHEDULER_CONDVAR_UNINIT(nbpMtSchedulerCondVar);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_MT_SCHEDULER_CONDVAR_UNINIT
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(errCode, "failed to uninit conditional variable");
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }
}

NBP_SCHEDULER_CALLBACK_RUN(nbp_mt_scheduler_run)
{
    unsigned int index = 0;
    nbp_mt_scheduler_test_t* test = NBP_MEMORY_NULL_POINTER;

    if (nbpMtSchedulerNumberOfTests == 0) {
        return;
    }

    nbp_mt_scheduler_allocate_array_of_tests();
    nbp_mt_scheduler_allocate_adjacency_matrix();
    nbp_mt_scheduler_processing_data();
    nbp_mt_scheduler_create_threads_and_run();

    for ( ; index < nbpMtSchedulerNumberOfTests; index++) {
        test = &nbpMtSchedulerTests[index];
        if (test->requestedWorkerId == NBP_MEMORY_NULL_POINTER) {
            continue;
        }

        NBP_MEMORY_FREE(test->requestedWorkerId);
        while (test->requestedWorkerId != NBP_MEMORY_NULL_POINTER) {
            test->requestedWorkerId = NBP_MEMORY_NULL_POINTER;
            test = test->nextTestOnThisWorker;
        }
    }

    NBP_MEMORY_FREE(nbpMtSchedulerAdjacencyMatrix);
    NBP_MEMORY_FREE(nbpMtSchedulerTests);
}

NBP_SCHEDULER_CALLBACK_RUN_TEST(nbp_mt_scheduler_run_test)
{
    nbp_mt_scheduler_data_t* data = NBP_MEMORY_NULL_POINTER;

    data = (nbp_mt_scheduler_data_t*) NBP_MEMORY_ALLOC(
        sizeof(nbp_mt_scheduler_data_t)
    );
    if (data == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for memory allocation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_OUT_OF_MEMORY,
            "could not add test"
        );
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        // LCOV_EXCL_STOP
    }

    data->dataType = NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_TEST;
    data->test = NBP_TEST_THIS;
    data->ctx = (nbp_mt_scheduler_context_t*) NBP_MEMORY_NULL_POINTER;
    data->next = NBP_MEMORY_NULL_POINTER;

    if (nbpMtSchedulerDataLast == NBP_MEMORY_NULL_POINTER) {
        nbpMtSchedulerData = data;
    } else {
        nbpMtSchedulerDataLast->next = data;
    }
    nbpMtSchedulerDataLast = data;

    nbpMtSchedulerNumberOfTests++;
}

NBP_SCHEDULER_CALLBACK_RUN_TEST_CTX(nbp_mt_scheduler_run_test_ctx)
{
    nbp_mt_scheduler_data_t* data = NBP_MEMORY_NULL_POINTER;

    data = (nbp_mt_scheduler_data_t*) NBP_MEMORY_ALLOC(
        sizeof(nbp_mt_scheduler_data_t)
    );
    if (data == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for memory allocation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_OUT_OF_MEMORY,
            "could not add test"
        );
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        // LCOV_EXCL_STOP
    }

    data->dataType = NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_TEST;
    data->test = NBP_TEST_THIS;
    data->ctx = (nbp_mt_scheduler_context_t*) NBP_SCHEDULER_CTX;
    data->next = NBP_MEMORY_NULL_POINTER;

    if (nbpMtSchedulerDataLast == NBP_MEMORY_NULL_POINTER) {
        nbpMtSchedulerData = data;
    } else {
        nbpMtSchedulerDataLast->next = data;
    }
    nbpMtSchedulerDataLast = data;

    nbpMtSchedulerNumberOfTests++;
}

NBP_SCHEDULER_CALLBACK_RUN_MODULE_CTX(nbp_mt_scheduler_run_module_ctx)
{
    nbp_mt_scheduler_data_t* data = NBP_MEMORY_NULL_POINTER;

    data = (nbp_mt_scheduler_data_t*) NBP_MEMORY_ALLOC(
        sizeof(nbp_mt_scheduler_data_t)
    );
    if (data == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for memory allocation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_OUT_OF_MEMORY,
            "could not add module"
        );
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        // LCOV_EXCL_STOP
    }

    data->dataType = NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_MODULE;
    data->module = NBP_MODULE_THIS;
    data->ctx = (nbp_mt_scheduler_context_t*) NBP_SCHEDULER_CTX;
    data->next = NBP_MEMORY_NULL_POINTER;

    if (nbpMtSchedulerDataLast == NBP_MEMORY_NULL_POINTER) {
        nbpMtSchedulerData = data;
    } else {
        nbpMtSchedulerDataLast->next = data;
    }
    nbpMtSchedulerDataLast = data;
}

NBP_SCHEDULER(
    nbpMtScheduler,
    NBP_SCHEDULER_CALLBACKS(
        NBP_SCHEDULER_CALLBACK_INIT(nbp_mt_scheduler_init),
        NBP_SCHEDULER_CALLBACK_UNINIT(nbp_mt_scheduler_uninit),
        NBP_SCHEDULER_CALLBACK_RUN(nbp_mt_scheduler_run),
        NBP_SCHEDULER_CALLBACK_RUN_TEST(nbp_mt_scheduler_run_test),
        NBP_SCHEDULER_CALLBACK_RUN_TEST_CTX(nbp_mt_scheduler_run_test_ctx),
        NBP_SCHEDULER_CALLBACK_RUN_MODULE_CTX(nbp_mt_scheduler_run_module_ctx)
    )
);

/*
 * undef thread wrapper
 */
#undef NBP_MT_SCHEDULER_THREAD_TYPE
#undef NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE
#undef NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE_DEFAULT_VALUE
#undef NBP_MT_SCHEDULER_THREAD_CREATE
#undef NBP_MT_SCHEDULER_THREAD_JOIN

/*
 * undef mutex wrapper
 */
#undef NBP_MT_SCHEDULER_MUTEX_TYPE
#undef NBP_MT_SCHEDULER_MUTEX_INITIALIZER
#undef NBP_MT_SCHEDULER_MUTEX_INIT
#undef NBP_MT_SCHEDULER_MUTEX_UNINIT
#undef NBP_MT_SCHEDULER_MUTEX_LOCK
#undef NBP_MT_SCHEDULER_MUTEX_UNLOCK

/*
 * undef conditional variable wrapper
 */
#undef NBP_MT_SCHEDULER_CONDVAR_TYPE
#undef NBP_MT_SCHEDULER_CONDVAR_INITIALIZER
#undef NBP_MT_SCHEDULER_CONDVAR_INIT
#undef NBP_MT_SCHEDULER_CONDVAR_UNINIT
#undef NBP_MT_SCHEDULER_CONDVAR_WAIT
#undef NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ONE
#undef NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ALL

/*
 * undef data types
 */
#undef NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_UNKNOWN
#undef NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_TEST
#undef NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_MODULE

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_PRIVATE_SCHEDULER_MT_SCHEDULER_H
