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

#ifndef NBP_SAMPLE_UTILS
#define NBP_SAMPLE_UTILS

#include <stdio.h>
#include <string.h>

static inline void write_message_to_file(const char* msg)
{
    FILE *fp = fopen("output.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%s\n", msg);
        fclose(fp);
    }
}

static inline void write_message_to_file_2(const char* msg1, const char* msg2)
{
    FILE *fp = fopen("output.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%s %s\n", msg1, msg2);
        fclose(fp);
    }
}

static inline void write_uint_to_file(unsigned int value)
{
    FILE *fp = fopen("output.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%u\n", value);
        fclose(fp);
    }
}

static inline void write_uint_to_file_2(unsigned int value, unsigned int value2)
{
    FILE *fp = fopen("output.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%u %u\n", value, value2);
        fclose(fp);
    }
}

static inline void write_message_to_console(const char* msg)
{
    printf("%s\n", msg);
}

#ifdef NBP_OS_LINUX

#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define SAMPLE_FORCE_SLEEP_MS(ms) usleep(ms * 1000)

int sample_semaphore_timedwait_ms(sem_t *sem, unsigned int timeMs);

/*
 * Semaphore wrapper
 */

#define SAMPLE_SEMAPHORE_TYPE sem_t

#define SAMPLE_SEMAPHORE_DEFAULT_VALUE { .__align = 0 }

#define SAMPLE_SEMAPHORE_INIT(sem)                                             \
    sem_init(&sem, 0, 0) == 0 ? 0 : 1

#define SAMPLE_SEMAPHORE_UNINIT(sem)                                           \
    sem_destroy(&sem) == 0 ? 0 : 1

#define SAMPLE_SEMAPHORE_WAIT(sem)                                             \
    sem_wait(&sem) == 0 ? 0 : 1

#define SAMPLE_SEMAPHORE_TIMEDWAIT_MS(sem, timeMs)                             \
    sample_semaphore_timedwait_ms(&sem, timeMs)

#define SAMPLE_SEMAPHORE_RELEASE(sem)                                          \
    sem_post(&sem) == 0 ? 0 : 1

/*
 * Atomic unsigned int wrapper
 */

#define SAMPLE_ATOMIC_UINT_TYPE unsigned int

#define SAMPLE_ATOMIC_UINT_INIT(val) val

#define SAMPLE_ATOMIC_UINT_LOAD(ptr)                                           \
    __atomic_load_n((ptr), __ATOMIC_SEQ_CST)

#define SAMPLE_ATOMIC_UINT_STORE(ptr, val)                                     \
    __atomic_store_n((ptr), val, __ATOMIC_SEQ_CST)

#define SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(ptr, value)                           \
    __sync_add_and_fetch((ptr), (value))

/*
 * Thread wrapper
 */

#define SAMPLE_THREAD_ID_TYPE pthread_t

#define SAMPLE_THREAD_ID_INVALID_VALUE 0

#define SAMPLE_THREAD_GET_ID() pthread_self()

#define SAMPLE_THREAD_ID_EQUAL(a, b) pthread_equal(a, b)

/*
 * Mutex wrapper
 */

#define SAMPLE_MUTEX_DECLARE(name)                                             \
    pthread_mutex_t name = PTHREAD_MUTEX_INITIALIZER;

#define SAMPLE_MUTEX_INIT(name)                                                \
    pthread_mutex_init(&name, NULL) == 0 ? 0 : 1

#define SAMPLE_MUTEX_UNINIT(name)                                              \
    pthread_mutex_destroy(&name) == 0 ? 0 : 1

#define SAMPLE_MUTEX_LOCK(name)                                                \
    pthread_mutex_lock(&name) == 0 ? 0 : 1

#define SAMPLE_MUTEX_UNLOCK(name)                                              \
    pthread_mutex_unlock(&name) == 0 ? 0 : 1

#ifdef NBP_LIBRARY_MAIN

#include <time.h>

int sample_semaphore_timedwait_ms(sem_t *sem, unsigned int timeMs)
{
    int err;
    struct timespec ts;
    unsigned long long int nsec;

    err = clock_gettime(CLOCK_REALTIME, &ts);
    if (err != 0) {
        return 1;
    }

    ts.tv_sec += (timeMs / 1000);
    timeMs = timeMs % 1000;

    nsec = timeMs * 1000000;
    nsec += (unsigned long long int) ts.tv_nsec;

    ts.tv_sec += (time_t) (nsec / 1000000000);
    ts.tv_nsec = (long int) (nsec % 1000000000);

    err = sem_timedwait(sem, &ts);
    if (err != 0) {
        return 1;
    }

    return 0;
}

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_OS_LINUX

#ifdef NBP_OS_WINDOWS

#include <Windows.h>
#define SAMPLE_FORCE_SLEEP_MS(ms) Sleep(ms)

#endif // end if NBP_OS_WINDOWS

#ifdef NBP_OS_MAC
#error "Not supported"
#endif // end if NBP_OS_MAC

#ifdef NBP_OS_CUSTOM
#error "Not supported"
#endif // end if NBP_OS_CUSTOM

/*
 * Semaphore wrapper if there is no NBP_OS_* defined
 */

#ifndef SAMPLE_SEMAPHORE_TYPE
#define SAMPLE_SEMAPHORE_TYPE int
#endif // end if SAMPLE_SEMAPHORE_TYPE

#ifndef SAMPLE_SEMAPHORE_DEFAULT_VALUE
#define SAMPLE_SEMAPHORE_DEFAULT_VALUE 1
#endif // end if SAMPLE_SEMAPHORE_DEFAULT_VALUE

#ifndef SAMPLE_SEMAPHORE_INIT
#define SAMPLE_SEMAPHORE_INIT(sem) 1
#endif // end if SAMPLE_SEMAPHORE_INIT

#ifndef SAMPLE_SEMAPHORE_UNINIT
#define SAMPLE_SEMAPHORE_UNINIT(sem) 1
#endif // end if SAMPLE_SEMAPHORE_UNINIT

#ifndef SAMPLE_SEMAPHORE_WAIT
#define SAMPLE_SEMAPHORE_WAIT(sem) 1
#endif // end if SAMPLE_SEMAPHORE_WAIT

#ifndef SAMPLE_SEMAPHORE_TIMEDWAIT_MS
#define SAMPLE_SEMAPHORE_TIMEDWAIT_MS(sem, timeMs) 1
#endif // end if SAMPLE_SEMAPHORE_TIMEDWAIT_MS

#ifndef SAMPLE_SEMAPHORE_RELEASE
#define SAMPLE_SEMAPHORE_RELEASE(sem) 1
#endif // end if SAMPLE_SEMAPHORE_RELEASE

/*
 * Atomic uint wrapper if there is no NBP_OS_* defined
 */

#ifndef SAMPLE_ATOMIC_UINT_TYPE
#define SAMPLE_ATOMIC_UINT_TYPE unsigned int
#endif // end if SAMPLE_ATOMIC_UINT_TYPE

#ifndef SAMPLE_ATOMIC_UINT_INIT
#define SAMPLE_ATOMIC_UINT_INIT(val) val
#endif // end if SAMPLE_ATOMIC_UINT_INIT

#ifndef SAMPLE_ATOMIC_UINT_LOAD
#define SAMPLE_ATOMIC_UINT_LOAD(ptr) (*(ptr))
#endif // end if SAMPLE_ATOMIC_UINT_LOAD

#ifndef SAMPLE_ATOMIC_UINT_STORE
#define SAMPLE_ATOMIC_UINT_STORE(ptr, val) ((*(ptr)) = (val))
#endif // end if SAMPLE_ATOMIC_UINT_STORE

#ifndef SAMPLE_ATOMIC_UINT_ADD_AND_FETCH
#define SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(ptr, value)                           \
    ((*(ptr)) += value)
#endif // end if SAMPLE_ATOMIC_UINT_ADD_AND_FETCH

/*
 * Thread wrapper if there is no NBP_OS_* defined
 */

#ifndef SAMPLE_THREAD_ID_TYPE
#define SAMPLE_THREAD_ID_TYPE int
#endif // end if SAMPLE_THREAD_ID_TYPE

#ifndef SAMPLE_THREAD_ID_INVALID_VALUE
#define SAMPLE_THREAD_ID_INVALID_VALUE 0
#endif // end if SAMPLE_THREAD_ID_INVALID_VALUE

#ifndef SAMPLE_THREAD_GET_ID
#define SAMPLE_THREAD_GET_ID() 0
#endif // end if SAMPLE_THREAD_GET_ID

#ifndef SAMPLE_THREAD_ID_EQUAL
#define SAMPLE_THREAD_ID_EQUAL(a, b) 0
#endif // end if SAMPLE_THREAD_ID_EQUAL

/*
 * Mutex wrapper if there is no NBP_OS_* defined
 */

#ifndef SAMPLE_MUTEX_DECLARE
#define SAMPLE_MUTEX_DECLARE(name) int name
#endif // end if SAMPLE_MUTEX_DECLARE

#ifndef SAMPLE_MUTEX_INIT
#define SAMPLE_MUTEX_INIT(name) 1
#endif // end if SAMPLE_MUTEX_INIT

#ifndef SAMPLE_MUTEX_UNINIT
#define SAMPLE_MUTEX_UNINIT(name) 1
#endif // end if SAMPLE_MUTEX_UNINIT

#ifndef SAMPLE_MUTEX_LOCK
#define SAMPLE_MUTEX_LOCK(name) 1
#endif // end if SAMPLE_MUTEX_LOCK

#ifndef SAMPLE_MUTEX_UNLOCK
#define SAMPLE_MUTEX_UNLOCK(name) 1
#endif // end if SAMPLE_MUTEX_UNLOCK

/*
 * SAMPLE_FORCE_SLEEP_MS implementation if there is no NBP_OS_* defined
 */
#ifndef SAMPLE_FORCE_SLEEP_MS
#define SAMPLE_FORCE_SLEEP_MS(ms)
#endif // end if SAMPLE_FORCE_SLEEP_MS

/*
 * Sample sleep implementation
 */

#ifdef SAMPLE_DISABLE_SLEEP
#define SAMPLE_SLEEP()
#else // SAMPLE_DISABLE_SLEEP not defined
#define SAMPLE_SLEEP() SAMPLE_FORCE_SLEEP_MS(200)
#endif // end if SAMPLE_DISABLE_SLEEP

#define SAMPLE_DEFAULT_SEMAPHORE_TIMEOUT_MS (unsigned int) 10000

#define SAMPLE_SEMAPHORE_WAIT_TIMEOUT(sem)                                     \
    SAMPLE_SEMAPHORE_TIMEDWAIT_MS(sem, SAMPLE_DEFAULT_SEMAPHORE_TIMEOUT_MS)

struct sample_utils_test_data_t
{
    const char* name;
    SAMPLE_ATOMIC_UINT_TYPE setupValue;
    SAMPLE_ATOMIC_UINT_TYPE teardownValue;
    SAMPLE_ATOMIC_UINT_TYPE runValue;
    struct sample_utils_test_data_t* next;
};
typedef struct sample_utils_test_data_t sample_utils_test_data_t;

struct sample_utils_test_data_copy_t
{
    const char* name;
    sample_utils_test_data_t *data;
    struct sample_utils_test_data_copy_t* next;
};
typedef struct sample_utils_test_data_copy_t sample_utils_test_data_copy_t;

void sample_utils_init();

void sample_utils_uninit();

sample_utils_test_data_t* sample_utils_get_test_data(const char*);

sample_utils_test_data_t* sample_utils_get_test_data_or_create(const char*);

int sample_utils_increment_run_data_recursively(nbp_test_details_t*);

void sample_utils_create_test_data_copy(const char*);

void sample_utils_delete_test_data_copy(const char*);

sample_utils_test_data_t* sample_utils_get_test_data_from_copy(
    const char*,
    const char*
);

#ifdef NBP_LIBRARY_MAIN

sample_utils_test_data_t* sampleUtilsTestDataListHead = NBP_MEMORY_NULL_POINTER;
sample_utils_test_data_t* sampleUtilsTestDataListLast = NBP_MEMORY_NULL_POINTER;
sample_utils_test_data_copy_t* sampleUtilsTestDataCopyListHead = NBP_MEMORY_NULL_POINTER;
sample_utils_test_data_copy_t* sampleUtilsTestDataCopyListLast = NBP_MEMORY_NULL_POINTER;
SAMPLE_MUTEX_DECLARE(sampleUtilsTestDataListMutex);

void sample_utils_init()
{
    int err;

    err = SAMPLE_MUTEX_INIT(sampleUtilsTestDataListMutex);
    if (err != 0) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_SYNC_ERROR);
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
    }
}

void sample_utils_uninit()
{
    sample_utils_test_data_t* data = NBP_MEMORY_NULL_POINTER;
    sample_utils_test_data_t* dataTmp = NBP_MEMORY_NULL_POINTER;
    int err;

    err = SAMPLE_MUTEX_LOCK(sampleUtilsTestDataListMutex);
    if (err != 0) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_SYNC_ERROR);
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
    }

    data = sampleUtilsTestDataListHead;
    while (data != NBP_MEMORY_NULL_POINTER) {
        dataTmp = data;
        data = data->next;
        NBP_MEMORY_FREE(dataTmp);
    }

    sampleUtilsTestDataListHead = NBP_MEMORY_NULL_POINTER;
    sampleUtilsTestDataListLast = NBP_MEMORY_NULL_POINTER;

    sampleUtilsTestDataCopyListHead = NBP_MEMORY_NULL_POINTER;
    sampleUtilsTestDataCopyListLast = NBP_MEMORY_NULL_POINTER;

    err = SAMPLE_MUTEX_UNLOCK(sampleUtilsTestDataListMutex);
    if (err != 0) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_SYNC_ERROR);
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
    }

    err = SAMPLE_MUTEX_UNINIT(sampleUtilsTestDataListMutex);
    if (err != 0) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_SYNC_ERROR);
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
    }
}

sample_utils_test_data_t* sample_utils_get_test_data(const char* name)
{
    sample_utils_test_data_t* data = NBP_MEMORY_NULL_POINTER;
    int err;

    err = SAMPLE_MUTEX_LOCK(sampleUtilsTestDataListMutex);
    if (err != 0) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_SYNC_ERROR);
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
    }

    data = sampleUtilsTestDataListHead;
    while (data != NBP_MEMORY_NULL_POINTER) {
        if (strcmp(data->name, name) == 0) {
            break;
        }
        data = data->next;
    }

    err = SAMPLE_MUTEX_UNLOCK(sampleUtilsTestDataListMutex);
    if (err != 0) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_SYNC_ERROR);
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
    }

    return data;
}

sample_utils_test_data_t* sample_utils_get_test_data_or_create(const char* name)
{
    sample_utils_test_data_t* data = NBP_MEMORY_NULL_POINTER;
    int err;

    err = SAMPLE_MUTEX_LOCK(sampleUtilsTestDataListMutex);
    if (err != 0) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_SYNC_ERROR);
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
    }

    data = sampleUtilsTestDataListHead;
    while (data != NBP_MEMORY_NULL_POINTER) {
        if (strcmp(data->name, name) == 0) {
            break;
        }
        data = data->next;
    }

    if (data == NBP_MEMORY_NULL_POINTER) {
        data = (sample_utils_test_data_t*) NBP_MEMORY_ALLOC(
            sizeof(sample_utils_test_data_t)
        );
        if (data == NBP_MEMORY_NULL_POINTER) {
            NBP_ERROR_REPORT(NBP_ERROR_CODE_OUT_OF_MEMORY);
            NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        } else {
            data->name = name;
            data->next = NBP_MEMORY_NULL_POINTER;
            SAMPLE_ATOMIC_UINT_STORE(&data->setupValue, 0);
            SAMPLE_ATOMIC_UINT_STORE(&data->teardownValue, 0);
            SAMPLE_ATOMIC_UINT_STORE(&data->runValue, 0);

            if (sampleUtilsTestDataListLast == NBP_MEMORY_NULL_POINTER) {
                sampleUtilsTestDataListHead = data;
                sampleUtilsTestDataListLast = data;
            } else {
                sampleUtilsTestDataListLast->next = data;
                sampleUtilsTestDataListLast = data;
            }
        }
    }

    err = SAMPLE_MUTEX_UNLOCK(sampleUtilsTestDataListMutex);
    if (err != 0) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_SYNC_ERROR);
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
    }

    return data;
}

int sample_utils_increment_run_data_recursively(nbp_test_details_t* test)
{
    int err = 0;
    int ret = 1;
    nbp_module_details_t* module = NBP_MEMORY_NULL_POINTER;
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    do {
        testData = sample_utils_get_test_data_or_create(NBP_TEST_GET_NAME(test));
        if (testData == NBP_MEMORY_NULL_POINTER) {
            break;
        }

        SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&testData->runValue, 1);

        module = NBP_TEST_GET_MODULE(test);
        while (module != NBP_MEMORY_NULL_POINTER) {
            testData = sample_utils_get_test_data_or_create(
                NBP_MODULE_GET_NAME(module)
            );
            if (testData == NBP_MEMORY_NULL_POINTER) {
                err = 1;
                break;
            }

            SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&testData->runValue, 1);

            module = NBP_MODULE_GET_PARENT(module);
        }

        if ( err == 1) {
            break;
        }

        ret = 0;
    } while (0);

    return ret;
}

void sample_utils_create_test_data_copy(const char* copyName)
{
    sample_utils_test_data_copy_t* testDataCopyNew = NBP_MEMORY_NULL_POINTER;
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;
    sample_utils_test_data_t* testDataNew = NBP_MEMORY_NULL_POINTER;
    sample_utils_test_data_t* testDataNewLast = NBP_MEMORY_NULL_POINTER;
    int err;

    err = SAMPLE_MUTEX_LOCK(sampleUtilsTestDataListMutex);
    if (err != 0) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_SYNC_ERROR);
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
    }

    do {
        testDataCopyNew = (sample_utils_test_data_copy_t*) NBP_MEMORY_ALLOC(
            sizeof(sample_utils_test_data_copy_t)
        );
        if (testDataCopyNew == NBP_MEMORY_NULL_POINTER) {
            NBP_ERROR_REPORT(NBP_ERROR_CODE_OUT_OF_MEMORY);
            NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        }

        testDataCopyNew->name = copyName;
        testDataCopyNew->next = NBP_MEMORY_NULL_POINTER;
        testDataCopyNew->data = NBP_MEMORY_NULL_POINTER;

        testData = sampleUtilsTestDataListHead;
        while (testData != NBP_MEMORY_NULL_POINTER) {
            testDataNew = (sample_utils_test_data_t*) NBP_MEMORY_ALLOC(
                sizeof(sample_utils_test_data_t)
            );
            if (testDataNew == NBP_MEMORY_NULL_POINTER) {
                NBP_ERROR_REPORT(NBP_ERROR_CODE_OUT_OF_MEMORY);
                NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
            }

            testDataNew->name = testData->name;
            testDataNew->next = NBP_MEMORY_NULL_POINTER;

            SAMPLE_ATOMIC_UINT_STORE(
                &testDataNew->setupValue,
                SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue)
            );
            SAMPLE_ATOMIC_UINT_STORE(
                &testDataNew->teardownValue,
                SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue)
            );
            SAMPLE_ATOMIC_UINT_STORE(
                &testDataNew->runValue,
                SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue)
            );

            if (testDataNewLast == NBP_MEMORY_NULL_POINTER) {
                testDataNewLast = testDataNew;
                testDataCopyNew->data = testDataNew;
            } else {
                testDataNewLast->next = testDataNew;
                testDataNewLast = testDataNew;
            }

            testData = testData->next;
        }

        if (sampleUtilsTestDataCopyListLast == NBP_MEMORY_NULL_POINTER) {
            sampleUtilsTestDataCopyListHead = testDataCopyNew;
            sampleUtilsTestDataCopyListLast = testDataCopyNew;
        } else {
            sampleUtilsTestDataCopyListLast->next = testDataCopyNew;
            sampleUtilsTestDataCopyListLast = testDataCopyNew;
        }
    } while (0);

    err = SAMPLE_MUTEX_UNLOCK(sampleUtilsTestDataListMutex);
    if (err != 0) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_SYNC_ERROR);
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
    }
}

void sample_utils_delete_test_data_copy(const char* copyName)
{
    sample_utils_test_data_copy_t* testDataCopy = NBP_MEMORY_NULL_POINTER;
    sample_utils_test_data_copy_t* testDataCopyPrev = NBP_MEMORY_NULL_POINTER;
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;
    sample_utils_test_data_t* testDataTmp = NBP_MEMORY_NULL_POINTER;
    int err;

    err = SAMPLE_MUTEX_LOCK(sampleUtilsTestDataListMutex);
    if (err != 0) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_SYNC_ERROR);
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
    }

    testDataCopy = sampleUtilsTestDataCopyListHead;
    while (testDataCopy != NBP_MEMORY_NULL_POINTER) {
        if (strcmp(testDataCopy->name, copyName) == 0) {
            break;
        }

        testDataCopyPrev = testDataCopy;
        testDataCopy = testDataCopy->next;
    }

    if (testDataCopy != NBP_MEMORY_NULL_POINTER) {
        if (testDataCopy == sampleUtilsTestDataCopyListHead) {
            sampleUtilsTestDataCopyListHead = testDataCopy->next;

            if (testDataCopy == sampleUtilsTestDataCopyListLast) {
                sampleUtilsTestDataCopyListLast = NBP_MEMORY_NULL_POINTER;
            }
        } else if (testDataCopy == sampleUtilsTestDataCopyListLast) {
            testDataCopyPrev->next = NBP_MEMORY_NULL_POINTER;
            sampleUtilsTestDataCopyListLast = testDataCopyPrev;
        } else {
            testDataCopyPrev->next = testDataCopy->next;
        }

        testData = testDataCopy->data;
        while (testData != NBP_MEMORY_NULL_POINTER) {
            testDataTmp = testData;
            testData = testData->next;

            NBP_MEMORY_FREE(testDataTmp);
        }

        NBP_MEMORY_FREE(testDataCopy);
    }

    err = SAMPLE_MUTEX_UNLOCK(sampleUtilsTestDataListMutex);
    if (err != 0) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_SYNC_ERROR);
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
    }
}

sample_utils_test_data_t* sample_utils_get_test_data_from_copy(
    const char* copyName, const char* name)
{
    sample_utils_test_data_copy_t* testDataCopy = NBP_MEMORY_NULL_POINTER;
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;
    int err;

    err = SAMPLE_MUTEX_LOCK(sampleUtilsTestDataListMutex);
    if (err != 0) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_SYNC_ERROR);
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
    }

    testDataCopy = sampleUtilsTestDataCopyListHead;
    while (testDataCopy != NBP_MEMORY_NULL_POINTER) {
        if (strcmp(testDataCopy->name, copyName) == 0) {
            break;
        }
        testDataCopy = testDataCopy->next;
    }

    if (testDataCopy != NBP_MEMORY_NULL_POINTER) {
        testData = testDataCopy->data;
        while (testData != NBP_MEMORY_NULL_POINTER) {
            if (strcmp(testData->name, name) == 0) {
                break;
            }
            testData = testData->next;
        }
    }

    err = SAMPLE_MUTEX_UNLOCK(sampleUtilsTestDataListMutex);
    if (err != 0) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_SYNC_ERROR);
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
    }

    return testData;
}

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_SAMPLE_UTILS
