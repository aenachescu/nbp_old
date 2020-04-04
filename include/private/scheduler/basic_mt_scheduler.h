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

#ifndef NBP_PRIVATE_SCHEDULER_MT_SCHEDULER_H
#define NBP_PRIVATE_SCHEDULER_MT_SCHEDULER_H

#define NBP_MT_SCHEDULER_RULE_TYPE_UNKNOWN                  (unsigned char) 0
#define NBP_MT_SCHEDULER_RULE_TYPE_BEFORE                   (unsigned char) 1
#define NBP_MT_SCHEDULER_RULE_TYPE_AFTER                    (unsigned char) 2

#define NBP_MT_SCHEDULER_RULE_DATA_TYPE_UNKNOWN             (unsigned char) 0
#define NBP_MT_SCHEDULER_RULE_DATA_TYPE_EMPTY               (unsigned char) 1
#define NBP_MT_SCHEDULER_RULE_DATA_TYPE_TEST                (unsigned char) 2
#define NBP_MT_SCHEDULER_RULE_DATA_TYPE_MODULE              (unsigned char) 3

struct nbp_mt_scheduler_rule_t {
    unsigned char ruleType;
    unsigned char dataType;
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
    unsigned char ruleType,
    nbp_test_details_t* test
);

nbp_mt_scheduler_rule_t nbp_mt_schduler_create_rule_from_module(
    unsigned char ruleType,
    nbp_module_details_t* module
);

void* nbp_mt_scheduler_create_ctx(
    unsigned long long numberOfRules,
    nbp_mt_scheduler_rule_t* rules
);

#define NBP_MT_SCHEDULER_RUN_BEFORE_TEST(test)                                 \
    nbp_mt_schduler_create_rule_from_test(                                     \
        NBP_MT_SCHEDULER_RULE_TYPE_BEFORE,                                     \
        NBP_GET_TEST_PTR(test)                                                 \
    )

#define NBP_MT_SCHEDULER_RUN_AFTER_TEST(test)                                  \
    nbp_mt_schduler_create_rule_from_test(                                     \
        NBP_MT_SCHEDULER_RULE_TYPE_AFTER,                                      \
        NBP_GET_TEST_PTR(test)                                                 \
    )

#define NBP_MT_SCHEDULER_RUN_BEFORE_MODULE(module)                             \
    nbp_mt_schduler_create_rule_from_module(                                   \
        NBP_MT_SCHEDULER_RULE_TYPE_BEFORE,                                     \
        NBP_GET_MODULE_PTR(module)                                             \
    )

#define NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module)                              \
    nbp_mt_schduler_create_rule_from_module(                                   \
        NBP_MT_SCHEDULER_RULE_TYPE_AFTER,                                      \
        NBP_GET_MODULE_PTR(module)                                             \
    )

#define NBP_MT_SCHEDULER_PRIVATE_GET_NUMBER_OF_RULES(...)                      \
    sizeof((nbp_mt_scheduler_rule_t[]){ __VA_ARGS__ }) /                       \
    sizeof(nbp_mt_scheduler_rule_t)

#define NBP_MT_SCHEDULER_CTX(...)                                              \
    nbp_mt_scheduler_create_ctx(                                               \
        NBP_MT_SCHEDULER_PRIVATE_GET_NUMBER_OF_RULES(__VA_ARGS__),             \
        (nbp_mt_scheduler_rule_t[]){ __VA_ARGS__ }                             \
    )

/*
 * NBP_SCHEDULER_PREPROCESSING_CONTEXT implementation
 */

#define NBP_MT_SCHEDULER_PRIVATE_PP_EAT_P_NBP_MT_SCHEDULER_RUN_AFTER_TEST(     \
    name)                                                                      \
    NBP_INCLUDE_TEST(name);

#define NBP_MT_SCHEDULER_PRIVATE_PP_EAT_P_NBP_MT_SCHEDULER_RUN_BEFORE_TEST(    \
    name)                                                                      \
    NBP_INCLUDE_TEST(name);

#define NBP_MT_SCHEDULER_PRIVATE_PP_EAT_P_NBP_MT_SCHEDULER_RUN_AFTER_MODULE(   \
    name)                                                                      \
    NBP_INCLUDE_MODULE(name);

#define NBP_MT_SCHEDULER_PRIVATE_PP_EAT_P_NBP_MT_SCHEDULER_RUN_BEFORE_MODULE(  \
    name)                                                                      \
    NBP_INCLUDE_MODULE(name);

// it's used when NBP_MT_SCHEDULER_CTX is called without rules
#define NBP_MT_SCHEDULER_PRIVATE_PP_EAT_P_

#define NBP_MT_SCHEDULER_PRIVATE_PP_VARCOUNT(...)                              \
    NBP_MT_SCHEDULER_PRIVATE_PP_VARCOUNT_HELPER(                               \
        P ## __VA_ARGS__,                                                      \
        9, 8, 7, 6, 5, 4, 3, 2, 1,                                             \
    )

#define NBP_MT_SCHEDULER_PRIVATE_PP_VARCOUNT_HELPER(                           \
    _, _9, _8, _7, _6, _5, _4, _3, _2, _n, ...) _n

#define NBP_MT_SCHEDULER_PRIVATE_PP_CONCAT(a, b)                               \
    NBP_MT_SCHEDULER_PRIVATE_PP_CONCAT_HELPER(a, b)

#define NBP_MT_SCHEDULER_PRIVATE_PP_CONCAT_HELPER(a, b) a ## b

#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_1(rule)                    \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule
#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_2(rule, ...)               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule                                   \
    NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_1(P_ ## __VA_ARGS__)
#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_3(rule, ...)               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule                                   \
    NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_2(P_ ## __VA_ARGS__)
#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_4(rule, ...)               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule                                   \
    NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_3(P_ ## __VA_ARGS__)
#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_5(rule, ...)               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule                                   \
    NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_4(P_ ## __VA_ARGS__)
#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_6(rule, ...)               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule                                   \
    NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_5(P_ ## __VA_ARGS__)
#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_7(rule, ...)               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule                                   \
    NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_6(P_ ## __VA_ARGS__)
#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_8(rule, ...)               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule                                   \
    NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_7(P_ ## __VA_ARGS__)
#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_9(rule, ...)               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule                                   \
    NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_8(P_ ## __VA_ARGS__)

#define NBP_MT_SCHEDULER_PRIVATE_PP_EAT_PP_NBP_MT_SCHEDULER_CTX(...)           \
    NBP_MT_SCHEDULER_PRIVATE_PP_CONCAT(                                        \
        NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_,                          \
        NBP_MT_SCHEDULER_PRIVATE_PP_VARCOUNT(P_ ## __VA_ARGS__)                \
    )(P_ ## __VA_ARGS__)

#define NBP_SCHEDULER_PREPROCESSING_CONTEXT(ctx)                               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## ctx

#ifdef NBP_LIBRARY_MAIN

/*
 * nbp_mt_scheduler_get_number_of_threads() implementation
 */
#ifdef NBP_MT_SCHEDULER_NUMBER_OF_THREADS

#if NBP_MT_SCHEDULER_NUMBER_OF_THREADS >= 1

unsigned int nbp_mt_scheduler_get_number_of_threads()
{
    int num = NBP_MT_SCHEDULER_NUMBER_OF_THREADS;
    if (num < 1) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_GENERIC,
            "failed to get the number of threads"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
        return 1;
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
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_GENERIC,
            "failed to get the number of threads"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
        return 1;
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
        ? NBP_NO_ERROR                                                         \
        : NBP_ERROR_GENERIC

#define NBP_MT_SCHEDULER_THREAD_JOIN(thread)                                   \
    pthread_join(thread, NULL) == 0                                            \
        ? NBP_NO_ERROR                                                         \
        : NBP_ERROR_GENERIC

/*
 * Mutex wrapper
 */

#define NBP_MT_SCHEDULER_MUTEX_TYPE pthread_mutex_t

#define NBP_MT_SCHEDULER_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER

#define NBP_MT_SCHEDULER_MUTEX_INIT(mutex)                                     \
    pthread_mutex_init(&mutex, NULL) == 0                                      \
        ? NBP_NO_ERROR                                                         \
        : NBP_ERROR_GENERIC

#define NBP_MT_SCHEDULER_MUTEX_UNINIT(mutex)                                   \
    pthread_mutex_destroy(&mutex) == 0                                         \
        ? NBP_NO_ERROR                                                         \
        : NBP_ERROR_GENERIC

#define NBP_MT_SCHEDULER_MUTEX_LOCK(mutex)                                     \
    pthread_mutex_lock(&mutex) == 0                                            \
        ? NBP_NO_ERROR                                                         \
        : NBP_ERROR_GENERIC

#define NBP_MT_SCHEDULER_MUTEX_UNLOCK(mutex)                                   \
    pthread_mutex_unlock(&mutex) == 0                                          \
        ? NBP_NO_ERROR                                                         \
        : NBP_ERROR_GENERIC

/*
 * Conditional variable wrapper
 */

#define NBP_MT_SCHEDULER_CONDVAR_TYPE pthread_cond_t

#define NBP_MT_SCHEDULER_CONDVAR_INITIALIZER PTHREAD_COND_INITIALIZER

#define NBP_MT_SCHEDULER_CONDVAR_INIT(condvar)                                 \
    pthread_cond_init(&condvar, NULL) == 0                                     \
        ? NBP_NO_ERROR                                                         \
        : NBP_ERROR_GENERIC

#define NBP_MT_SCHEDULER_CONDVAR_UNINIT(condvar)                               \
    pthread_cond_destroy(&condvar) == 0                                        \
        ? NBP_NO_ERROR                                                         \
        : NBP_ERROR_GENERIC

#define NBP_MT_SCHEDULER_CONDVAR_WAIT(condvar, mutex)                          \
    pthread_cond_wait(&condvar, &mutex) == 0                                   \
        ? NBP_NO_ERROR                                                         \
        : NBP_ERROR_GENERIC

#define NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ONE(condvar)                           \
    pthread_cond_signal(&condvar) == 0                                         \
        ? NBP_NO_ERROR                                                         \
        : NBP_ERROR_GENERIC

#define NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ALL(condvar)                           \
    pthread_cond_broadcast(&condvar) == 0                                      \
        ? NBP_NO_ERROR                                                         \
        : NBP_ERROR_GENERIC

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

#define NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_UNKNOWN  (unsigned char) 0
#define NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_TEST     (unsigned char) 1
#define NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_MODULE   (unsigned char) 2

struct nbp_mt_scheduler_data_t {
    unsigned char dataType;
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

    struct nbp_mt_scheduler_test_t* nextInQueue;
};
typedef struct nbp_mt_scheduler_test_t nbp_mt_scheduler_test_t;

struct nbp_mt_scheduler_thread_t {
    NBP_MT_SCHEDULER_THREAD_TYPE thread;
    unsigned int workerId;
};
typedef struct nbp_mt_scheduler_thread_t nbp_mt_scheduler_thread_t;

static nbp_mt_scheduler_data_t nbpMtSchedulerData;
static nbp_mt_scheduler_data_t* nbpMtSchedulerDataLast = NBP_NULL_POINTER;

static nbp_mt_scheduler_test_t* nbpMtSchedulerTests = NBP_NULL_POINTER;
static unsigned int nbpMtSchedulerNumberOfTests = 0;
static unsigned int nbpMtSchedulerNumberOfColumns = 0;
static unsigned int* nbpMtSchedulerAdjacencyMatrix = NBP_NULL_POINTER;

static nbp_mt_scheduler_test_t* nbpMtSchedulerQueue = NBP_NULL_POINTER;
static nbp_mt_scheduler_test_t* nbpMtSchedulerQueueLast = NBP_NULL_POINTER;

static NBP_MT_SCHEDULER_MUTEX_TYPE nbpMtSchedulerMutex = PTHREAD_MUTEX_INITIALIZER;
static NBP_MT_SCHEDULER_CONDVAR_TYPE nbpMtSchedulerCondVar = PTHREAD_COND_INITIALIZER;

static unsigned int nbpMtSchedulerNumberOfDispatchedTests = 0;

nbp_mt_scheduler_rule_t nbp_mt_schduler_create_rule_from_test(
    unsigned char ruleType, nbp_test_details_t* test)
{
    nbp_mt_scheduler_rule_t rule;

    rule.ruleType   = ruleType;
    rule.dataType   = NBP_MT_SCHEDULER_RULE_DATA_TYPE_TEST;
    rule.test       = test;

    return rule;
}

nbp_mt_scheduler_rule_t nbp_mt_schduler_create_rule_from_module(
    unsigned char ruleType, nbp_module_details_t* module)
{
    nbp_mt_scheduler_rule_t rule;

    rule.ruleType   = ruleType;
    rule.dataType   = NBP_MT_SCHEDULER_RULE_DATA_TYPE_MODULE;
    rule.module     = module;

    return rule;
}

void* nbp_mt_scheduler_create_ctx(unsigned long long numberOfRules,
    nbp_mt_scheduler_rule_t* rules)
{
    unsigned long long index;
    unsigned long long size = sizeof(nbp_mt_scheduler_context_t);
    if (numberOfRules > 1) {
        size += ((numberOfRules - 1) * sizeof(nbp_mt_scheduler_rule_t));
    }

    nbp_mt_scheduler_context_t* ctx = (nbp_mt_scheduler_context_t*) NBP_ALLOC(size);
    if (ctx == NBP_NULL_POINTER) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_ALLOC,
            "could not alloc context"
        );
        NBP_EXIT(NBP_EXIT_STATUS_OUT_OF_MEMORY);
        return NBP_NULL_POINTER;
    }

    ctx->numberOfRules = numberOfRules;
    for (index = 0; index < numberOfRules; ++index) {
        ctx->rules[index] = rules[index];
    }

    return (void*) ctx;
}

static void nbp_mt_scheduler_queue_push(unsigned int testId)
{
    if (nbpMtSchedulerQueueLast == NBP_NULL_POINTER) {
        nbpMtSchedulerQueue = &nbpMtSchedulerTests[testId];
        nbpMtSchedulerQueueLast = &nbpMtSchedulerTests[testId];
    } else {
        nbpMtSchedulerQueueLast->nextInQueue = &nbpMtSchedulerTests[testId];
        nbpMtSchedulerQueueLast = &nbpMtSchedulerTests[testId];
    }
}

static nbp_mt_scheduler_test_t* nbp_mt_scheduler_queue_pop()
{
    nbp_mt_scheduler_test_t* test = NBP_NULL_POINTER;

    if (nbpMtSchedulerQueue == NBP_NULL_POINTER) {
        return test;
    }

    test = nbpMtSchedulerQueue;

    nbpMtSchedulerQueue = nbpMtSchedulerQueue->nextInQueue;
    if (nbpMtSchedulerQueue == NBP_NULL_POINTER) {
        nbpMtSchedulerQueueLast = NBP_NULL_POINTER;
    }

    return test;
}

static void nbp_mt_scheduler_add_pending_test(unsigned int pendingTestId,
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

static void nbp_mt_scheduler_test_completed(unsigned int testId)
{
    unsigned int bitsPerUint = sizeof(unsigned int) * 8;
    unsigned int columnIndex = 0;
    unsigned int rowIndex;
    unsigned int testIndex;
    unsigned int* matrixRowStart;

    rowIndex = testId * nbpMtSchedulerNumberOfColumns;
    matrixRowStart = nbpMtSchedulerAdjacencyMatrix + rowIndex;

    for ( ; columnIndex < nbpMtSchedulerNumberOfColumns; columnIndex++) {
        testIndex = columnIndex * bitsPerUint;
        while (matrixRowStart[columnIndex] != 0) {
            if ((matrixRowStart[columnIndex] & 1) != 0) {
                nbpMtSchedulerTests[testIndex].numberOfPendingTests--;
                if (nbpMtSchedulerTests[testIndex].numberOfPendingTests == 0) {
                    nbp_mt_scheduler_queue_push(testIndex);
                }
            }

            testIndex++;
            matrixRowStart[columnIndex] >>= 1; /* TODO: portable lzcnt */
        }
    }
}

static NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE nbp_mt_scheduler_worker_thread_func(
    void* param)
{
    unsigned int workerId = *((unsigned int*) param);
    nbp_mt_scheduler_test_t* test;

    (void)(workerId);

    /* TODO: check return value for mutex/condvar functions */

    NBP_MT_SCHEDULER_MUTEX_LOCK(nbpMtSchedulerMutex);
    while (nbpMtSchedulerNumberOfDispatchedTests != nbpMtSchedulerNumberOfTests) {
        test = nbp_mt_scheduler_queue_pop();
        if (test == NBP_NULL_POINTER) {
            NBP_MT_SCHEDULER_CONDVAR_WAIT(nbpMtSchedulerCondVar, nbpMtSchedulerMutex);
            continue;
        }

        nbpMtSchedulerNumberOfDispatchedTests++;

        NBP_MT_SCHEDULER_MUTEX_UNLOCK(nbpMtSchedulerMutex);
        NBP_SCHEDULER_RUN_TEST(test->test);
        NBP_MT_SCHEDULER_MUTEX_LOCK(nbpMtSchedulerMutex);

        nbp_mt_scheduler_test_completed(NBP_TEST_GET_ID(test->test));

        NBP_MT_SCHEDULER_MUTEX_UNLOCK(nbpMtSchedulerMutex);
        NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ALL(nbpMtSchedulerCondVar);
        NBP_MT_SCHEDULER_MUTEX_LOCK(nbpMtSchedulerMutex);
    }
    NBP_MT_SCHEDULER_MUTEX_UNLOCK(nbpMtSchedulerMutex);

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
        if (rule->dataType == NBP_MT_SCHEDULER_RULE_DATA_TYPE_TEST) {
            ruleDataTestId = NBP_TEST_GET_ID(rule->test);

            if (rule->ruleType == NBP_MT_SCHEDULER_RULE_TYPE_AFTER) {
                nbp_mt_scheduler_add_pending_test(ruleDataTestId, testId);
                continue;
            }

            if (rule->ruleType == NBP_MT_SCHEDULER_RULE_TYPE_BEFORE) {
                nbp_mt_scheduler_add_pending_test(testId, ruleDataTestId);
                continue;
            }

            NBP_HANDLE_ERROR_CTX_STRING(
                NBP_ERROR_GENERIC,
                "unknown rule type"
            );
            NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
        }

        if (rule->dataType == NBP_MT_SCHEDULER_RULE_DATA_TYPE_MODULE) {
            // TODO
        }

        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_GENERIC,
            "unknown rule data type"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }
}

static void nbp_mt_scheduler_allocate_array_of_tests()
{
    unsigned int index = 0;

    nbpMtSchedulerTests = (nbp_mt_scheduler_test_t*) NBP_ALLOC(
        nbpMtSchedulerNumberOfTests * sizeof(nbp_mt_scheduler_test_t)
    );
    if (nbpMtSchedulerTests == NBP_NULL_POINTER) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_ALLOC,
            "could not alloc array of tests"
        );
        NBP_EXIT(NBP_EXIT_STATUS_OUT_OF_MEMORY);
    }

    for ( ; index < nbpMtSchedulerNumberOfTests; index++) {
        nbpMtSchedulerTests[index].test = NBP_NULL_POINTER;
        nbpMtSchedulerTests[index].numberOfPendingTests = 0;
        nbpMtSchedulerTests[index].nextInQueue = NBP_NULL_POINTER;
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

    nbpMtSchedulerAdjacencyMatrix = (unsigned int*) NBP_ALLOC(
        numberOfElements * sizeof(unsigned int)
    );
    if (nbpMtSchedulerAdjacencyMatrix == NBP_NULL_POINTER) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_ALLOC,
            "could not alloc adjacency matrix"
        );
        NBP_EXIT(NBP_EXIT_STATUS_OUT_OF_MEMORY);
    }

    for ( ; index < numberOfElements; index++) {
        nbpMtSchedulerAdjacencyMatrix[index] = 0;
    }
}

static void nbp_mt_scheduler_processing_data()
{
    unsigned int testId;
    nbp_mt_scheduler_data_t* data = &nbpMtSchedulerData;

    while (data->next != NBP_NULL_POINTER) {
        if (data->dataType == NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_TEST) {
            testId = NBP_TEST_GET_ID(data->test);
            nbpMtSchedulerTests[testId].test = data->test;

            if (data->ctx != NBP_NULL_POINTER) {
                nbp_mt_scheduler_processing_test_context(testId, data->ctx);
            }
        } else if (data->dataType == NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_MODULE) {
            // TODO
        }

        data = data->next;
    }

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
    NBP_ERROR_TYPE err;

    numberOfThreads--;

    threads = (nbp_mt_scheduler_thread_t*) NBP_ALLOC(
        numberOfThreads * sizeof(nbp_mt_scheduler_thread_t)
    );
    if (threads == NBP_NULL_POINTER) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_ALLOC,
            "could not alloc array of threads"
        );
        NBP_EXIT(NBP_EXIT_STATUS_OUT_OF_MEMORY);
    }

    for ( ; index < numberOfThreads; index++) {
        threads[index].workerId = index;
        err = NBP_MT_SCHEDULER_THREAD_CREATE(
            threads[index].thread,
            nbp_mt_scheduler_worker_thread_func,
            (void*) &threads[index].workerId
        );
        if (err != NBP_NO_ERROR) {
            NBP_HANDLE_ERROR_CTX_STRING(
                NBP_ERROR_GENERIC,
                "could not create thread"
            );
            NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
        }
    }

    nbp_mt_scheduler_worker_thread_func((void*) &index);

    for (index = 0; index < numberOfThreads; index++) {
        err = NBP_MT_SCHEDULER_THREAD_JOIN(threads[index].thread);
        if (err != NBP_NO_ERROR) {
            NBP_HANDLE_ERROR_CTX_STRING(
                NBP_ERROR_GENERIC,
                "failed to join thread"
            );
            NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
        }
    }

    NBP_FREE(threads);
}

/* TODO: check return value for mutex/condvar functions */
NBP_SCHEDULER_FUNC_INIT(nbp_mt_scheduler_init)
{
    nbpMtSchedulerData.dataType = NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_UNKNOWN;
    nbpMtSchedulerData.ctx = NBP_NULL_POINTER;
    nbpMtSchedulerData.next = NBP_NULL_POINTER;
    nbpMtSchedulerDataLast = &nbpMtSchedulerData;

    NBP_MT_SCHEDULER_MUTEX_INIT(nbpMtSchedulerMutex);
    NBP_MT_SCHEDULER_CONDVAR_INIT(nbpMtSchedulerCondVar);
}

NBP_SCHEDULER_FUNC_UNINIT(nbp_mt_scheduler_uninit)
{
    NBP_MT_SCHEDULER_MUTEX_UNINIT(nbpMtSchedulerMutex);
    NBP_MT_SCHEDULER_CONDVAR_UNINIT(nbpMtSchedulerCondVar);
}

NBP_SCHEDULER_FUNC_RUN(nbp_mt_scheduler_run)
{
    if (nbpMtSchedulerNumberOfTests == 0) {
        return;
    }

    nbp_mt_scheduler_allocate_array_of_tests();
    nbp_mt_scheduler_allocate_adjacency_matrix();
    nbp_mt_scheduler_processing_data();
    nbp_mt_scheduler_create_threads_and_run();
}

NBP_SCHEDULER_FUNC_ADD_TEST(nbp_mt_scheduler_add_test)
{
    nbpMtSchedulerDataLast->dataType = NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_TEST;
    nbpMtSchedulerDataLast->test = NBP_THIS_TEST;
    nbpMtSchedulerDataLast->ctx =
        (nbp_mt_scheduler_context_t*) NBP_NULL_POINTER;
    nbpMtSchedulerDataLast->next =
        (nbp_mt_scheduler_data_t*) NBP_ALLOC(sizeof(nbp_mt_scheduler_data_t));

    if (nbpMtSchedulerDataLast->next == NBP_NULL_POINTER) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_ALLOC,
            "could not add test"
        );
        NBP_EXIT(NBP_EXIT_STATUS_OUT_OF_MEMORY);
    }

    nbpMtSchedulerDataLast = nbpMtSchedulerDataLast->next;
    nbpMtSchedulerDataLast->dataType = NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_UNKNOWN;
    nbpMtSchedulerDataLast->ctx = NBP_NULL_POINTER;
    nbpMtSchedulerDataLast->next = NBP_NULL_POINTER;

    nbpMtSchedulerNumberOfTests++;
}

NBP_SCHEDULER_FUNC_ADD_TEST_CTX(nbp_mt_scheduler_add_test_ctx)
{
    nbpMtSchedulerDataLast->dataType = NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_TEST;
    nbpMtSchedulerDataLast->test = NBP_THIS_TEST;
    nbpMtSchedulerDataLast->ctx =
        (nbp_mt_scheduler_context_t*) NBP_SCHEDULER_CTX;
    nbpMtSchedulerDataLast->next =
        (nbp_mt_scheduler_data_t*) NBP_ALLOC(sizeof(nbp_mt_scheduler_data_t));

    if (nbpMtSchedulerDataLast->next == NBP_NULL_POINTER) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_ALLOC,
            "could not add test"
        );
        NBP_EXIT(NBP_EXIT_STATUS_OUT_OF_MEMORY);
    }

    nbpMtSchedulerDataLast = nbpMtSchedulerDataLast->next;
    nbpMtSchedulerDataLast->dataType = NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_UNKNOWN;
    nbpMtSchedulerDataLast->ctx = NBP_NULL_POINTER;
    nbpMtSchedulerDataLast->next = NBP_NULL_POINTER;

    nbpMtSchedulerNumberOfTests++;
}

NBP_SCHEDULER_FUNC_MODULE_STARTED_CTX(nbp_mt_scheduler_module_started_ctx)
{
    NBP_HANDLE_ERROR_CTX_STRING(
        NBP_ERROR_GENERIC,
        "module started ctx not supported yet"
    );
    NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
}

NBP_DEFINE_SCHEDULER(
    nbpDefaultScheduler,
    NBP_SCHEDULER_USE_FUNC_INIT(nbp_mt_scheduler_init),
    NBP_SCHEDULER_USE_FUNC_UNINIT(nbp_mt_scheduler_uninit),
    NBP_SCHEDULER_USE_FUNC_RUN(nbp_mt_scheduler_run),
    NBP_SCHEDULER_USE_FUNC_ADD_TEST(nbp_mt_scheduler_add_test),
    NBP_SCHEDULER_USE_FUNC_ADD_TEST_CTX(nbp_mt_scheduler_add_test_ctx),
    NBP_SCHEDULER_NO_FUNC_MODULE_STARTED,
    NBP_SCHEDULER_USE_FUNC_MODULE_STARTED_CTX(nbp_mt_scheduler_module_started_ctx),
    NBP_SCHEDULER_NO_FUNC_MODULE_COMPLETED
);

#endif // end if NBP_LIBRARY_MAIN

/*
 * TODO: undef unused macros
 */

#endif // end if NBP_PRIVATE_SCHEDULER_MT_SCHEDULER_H
