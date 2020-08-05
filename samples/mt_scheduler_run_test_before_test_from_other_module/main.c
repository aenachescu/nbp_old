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

#define NBP_LIBRARY_MAIN
#include <nbp.h>

#include "../sample_utils.h"

SAMPLE_ATOMIC_UINT_TYPE test1SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test1TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test3SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test3TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

unsigned int test3_test1SetupValue = 0;
unsigned int test3_test1TeardownValue = 0;

SAMPLE_SEMAPHORE_TYPE g_semaphore = SAMPLE_SEMAPHORE_DEFAULT_VALUE;

NBP_MAIN_MODULE_FIXTURES(mt_scheduler_run_test_before_test_from_other_module,
    main_module_setup, main_module_teardown)
{
    NBP_MODULE_RUN(module);
    NBP_TEST_RUN_CTX(
        test1,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_BEFORE_TEST(test3)
        )
    );
}

NBP_MODULE(module)
{
    NBP_TEST_RUN(test2);
    NBP_TEST_RUN(test3);
    NBP_MODULE_RUN(submodule1);
    NBP_TEST_RUN(test4);
    NBP_TEST_RUN(test5);
    NBP_MODULE_RUN(submodule2);
}

NBP_MODULE(submodule1)
{
    NBP_TEST_RUN(test6);
    NBP_TEST_RUN(test7);
}

NBP_MODULE(submodule2)
{
    NBP_TEST_RUN(test8);
    NBP_TEST_RUN(test9);
}

NBP_MODULE_SETUP(main_module_setup)
{
    int err;

    err = SAMPLE_SEMAPHORE_INIT(g_semaphore);
    if (err == 1) {
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_SYNC_ERROR,
            "failed to init g_semaphore"
        );
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
        // LCOV_EXCL_STOP
    }
}

NBP_MODULE_TEARDOWN(main_module_teardown)
{
    int err;

    err = SAMPLE_SEMAPHORE_UNINIT(g_semaphore);
    if (err == 1) {
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_SYNC_ERROR,
            "failed to uninit g_semaphore"
        );
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
        // LCOV_EXCL_STOP
    }
}

NBP_TEST_SETUP(test1_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test1SetupValue, 1);
}

NBP_TEST_TEARDOWN(test1_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test1TeardownValue, 1);
}

NBP_TEST_SETUP(test3_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test3SetupValue, 1);

    test3_test1SetupValue = SAMPLE_ATOMIC_UINT_LOAD(&test1SetupValue);
    test3_test1TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&test1TeardownValue);
}

NBP_TEST_TEARDOWN(test3_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test3TeardownValue, 1);
}

NBP_TEST_FIXTURES(test1, test1_setup, test1_teardown)
{
    SAMPLE_SLEEP();

    int i, err;

    for (i = 0; i < 7; i++) {
        err = SAMPLE_SEMAPHORE_WAIT(g_semaphore);
        NBP_ASSERT(err == 0);
    }

    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&test3SetupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&test3TeardownValue), 0);
}

NBP_TEST(test2)
{
    SAMPLE_SLEEP();

    int err = SAMPLE_SEMAPHORE_RELEASE(g_semaphore);
    NBP_ASSERT(err == 0);
}

NBP_TEST_FIXTURES(test3, test3_setup, test3_teardown)
{
    SAMPLE_SLEEP();

    NBP_ASSERT_UINT_EQ(test3_test1SetupValue, 1);
    NBP_ASSERT_UINT_EQ(test3_test1TeardownValue, 1);
}

NBP_TEST(test4)
{
    SAMPLE_SLEEP();

    int err = SAMPLE_SEMAPHORE_RELEASE(g_semaphore);
    NBP_ASSERT(err == 0);
}

NBP_TEST(test5)
{
    SAMPLE_SLEEP();

    int err = SAMPLE_SEMAPHORE_RELEASE(g_semaphore);
    NBP_ASSERT(err == 0);
}

NBP_TEST(test6)
{
    SAMPLE_SLEEP();

    int err = SAMPLE_SEMAPHORE_RELEASE(g_semaphore);
    NBP_ASSERT(err == 0);
}

NBP_TEST(test7)
{
    SAMPLE_SLEEP();

    int err = SAMPLE_SEMAPHORE_RELEASE(g_semaphore);
    NBP_ASSERT(err == 0);
}

NBP_TEST(test8)
{
    SAMPLE_SLEEP();

    int err = SAMPLE_SEMAPHORE_RELEASE(g_semaphore);
    NBP_ASSERT(err == 0);
}

NBP_TEST(test9)
{
    SAMPLE_SLEEP();

    int err = SAMPLE_SEMAPHORE_RELEASE(g_semaphore);
    NBP_ASSERT(err == 0);
}
