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

SAMPLE_THREAD_ID_TYPE test2ThreadId     = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test3ThreadId     = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test4ThreadId     = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test5ThreadId     = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test6ThreadId     = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test7ThreadId     = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test8ThreadId     = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test9ThreadId     = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test10ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test11ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test12ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test13ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test14ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test15ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test16ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test17ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test18ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test19ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test20ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test21ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test22ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test23ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test24ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test25ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test26ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test27ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test28ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test29ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test30ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test31ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test32ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test33ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;

SAMPLE_SEMAPHORE_TYPE g_semaphores[4];

NBP_MODULE_SETUP(main_module_setup)
{
    for (unsigned int i = 0; i < 4; ++i) {
        int err = SAMPLE_SEMAPHORE_INIT(g_semaphores[i]);
        if (err != 0) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for SAMPLE_SEMAPHORE_INIT
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_SYNC_ERROR,
                "failed to init semaphore"
            );
            NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
            // LCOV_EXCL_STOP
        }
    }
}

NBP_MODULE_TEARDOWN(main_module_teardown)
{
    for (unsigned int i = 0; i < 4; ++i) {
        int err = SAMPLE_SEMAPHORE_UNINIT(g_semaphores[i]);
        if (err != 0) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for SAMPLE_SEMAPHORE_UNINIT
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_SYNC_ERROR,
                "failed to uninit semaphore"
            );
            NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
            // LCOV_EXCL_STOP
        }
    }
}

NBP_MAIN_MODULE_FIXTURES(mt_scheduler_run_test_on_same_thread_as_module,
    main_module_setup, main_module_teardown)
{
    NBP_TEST_RUN(test26);
    NBP_TEST_RUN(test27);
    NBP_TEST_RUN(test28);
    NBP_TEST_RUN(test29);

    NBP_TEST_RUN_CTX(
        test1,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test2),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test3),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module1),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module2),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test26),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test27),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test28),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test29),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test30),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test31),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test32),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test33)
        )
    );
    NBP_TEST_RUN_CTX(
        test2,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_MODULE(module1)
        )
    );
    NBP_TEST_RUN_CTX(
        test3,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_MODULE(module2),
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(test2)
        )
    );

    NBP_MODULE_RUN(module1);
    NBP_MODULE_RUN(module2);

    NBP_TEST_RUN(test30);
    NBP_TEST_RUN(test31);
    NBP_TEST_RUN(test32);
    NBP_TEST_RUN(test33);
}

NBP_TEST(test1)
{
    unsigned int num;

    SAMPLE_SLEEP();

    NBP_CHECK(test2ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);

    NBP_CHECK(test26ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test27ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test28ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test29ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test30ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test31ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test32ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test33ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);

    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test3ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test4ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test5ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test6ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test7ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test8ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test9ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test10ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test11ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test12ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test13ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test14ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test15ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test16ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test17ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test18ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test19ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test20ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test21ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test22ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test23ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test24ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test25ThreadId));

    num = 0;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test26ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test27ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test28ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test29ThreadId)) num++;
    NBP_CHECK(num > 0);

    num = 0;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test30ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test31ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test32ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test33ThreadId)) num++;
    NBP_CHECK(num > 0);
}

NBP_TEST(test2)
{
    SAMPLE_SLEEP();

    test2ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test2ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}


NBP_TEST(test3)
{
    SAMPLE_SLEEP();

    test3ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test3ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test26)
{
    int err, i;

    SAMPLE_SLEEP();

    // unblock test27, test28, test29
    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[0]);
        NBP_ASSERT_INT_EQ(err, 0);
    }

    // wait for test27, test28, test29
    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[1]);
        NBP_ASSERT_INT_EQ(err, 0);
    }

    test26ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test26ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test27)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[0]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[1]);
    NBP_ASSERT_INT_EQ(err, 0);

    test27ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test27ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test28)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[0]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[1]);
    NBP_ASSERT_INT_EQ(err, 0);

    test28ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test28ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test29)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[0]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[1]);
    NBP_ASSERT_INT_EQ(err, 0);

    test29ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test29ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test30)
{
    int err, i;

    SAMPLE_SLEEP();

    // unblock test31, test32, test33
    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[2]);
        NBP_ASSERT_INT_EQ(err, 0);
    }

    // wait for test31, test32, test33
    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[3]);
        NBP_ASSERT_INT_EQ(err, 0);
    }

    test30ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test30ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test31)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[2]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[3]);
    NBP_ASSERT_INT_EQ(err, 0);

    test31ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test31ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test32)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[2]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[3]);
    NBP_ASSERT_INT_EQ(err, 0);

    test32ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test32ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test33)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[2]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[3]);
    NBP_ASSERT_INT_EQ(err, 0);

    test33ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test33ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}
