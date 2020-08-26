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

NBP_MAIN_MODULE(mt_scheduler_run_test_on_same_thread_as_test,
    NBP_MODULE_FIXTURES(main_module_setup, main_module_teardown))
{
    NBP_TEST_RUN(test12);
    NBP_TEST_RUN(test13);
    NBP_TEST_RUN(test14);
    NBP_TEST_RUN(test15);

    NBP_TEST_RUN_CTX(
        test1,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test2),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test3),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test4),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test5),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test6),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test7),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test8),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test9),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test10),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test11),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test12),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test13),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test14),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test15),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test16),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test17),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test18),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test19)
        )
    );

    NBP_TEST_RUN_CTX(
        test2,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(test3),
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(test4),
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(test5),
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(test6)
        )
    );
    NBP_TEST_RUN(test3);
    NBP_TEST_RUN(test4);
    NBP_TEST_RUN(test5);
    NBP_TEST_RUN(test6);

    NBP_TEST_RUN(test7);
    NBP_TEST_RUN_CTX(
        test8,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(test7)
        )
    );
    NBP_TEST_RUN_CTX(
        test9,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(test8)
        )
    );
    NBP_TEST_RUN_CTX(
        test10,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(test9),
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(test7)
        )
    );
    NBP_TEST_RUN_CTX(
        test11,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(test10),
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(test2)
        )
    );

    NBP_TEST_RUN(test16);
    NBP_TEST_RUN(test17);
    NBP_TEST_RUN(test18);
    NBP_TEST_RUN(test19);
}

NBP_TEST(test1)
{
    unsigned int num;

    SAMPLE_SLEEP();

    NBP_CHECK(test2ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);

    NBP_CHECK(test12ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test13ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test14ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test15ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test16ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test17ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test18ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test19ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);

    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test3ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test4ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test5ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test6ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test7ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test8ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test9ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test10ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test11ThreadId));

    num = 0;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test12ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test13ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test14ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test15ThreadId)) num++;
    NBP_CHECK(num > 0);

    num = 0;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test16ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test17ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test18ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test19ThreadId)) num++;
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

NBP_TEST(test4)
{
    SAMPLE_SLEEP();

    test4ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test4ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test5)
{
    SAMPLE_SLEEP();

    test5ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test5ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test6)
{
    SAMPLE_SLEEP();

    test6ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test6ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test7)
{
    SAMPLE_SLEEP();

    test7ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test7ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test8)
{
    SAMPLE_SLEEP();

    test8ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test8ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test9)
{
    SAMPLE_SLEEP();

    test9ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test9ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test10)
{
    SAMPLE_SLEEP();

    test10ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test10ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test11)
{
    SAMPLE_SLEEP();

    test11ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test11ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test12)
{
    int err, i;

    SAMPLE_SLEEP();

    // unblock test13, test14, test15
    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[0]);
        NBP_ASSERT_INT_EQ(err, 0);
    }

    // wait for test13, test14, test15
    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[1]);
        NBP_ASSERT_INT_EQ(err, 0);
    }

    test12ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test12ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test13)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[0]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[1]);
    NBP_ASSERT_INT_EQ(err, 0);

    test13ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test13ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test14)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[0]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[1]);
    NBP_ASSERT_INT_EQ(err, 0);

    test14ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test14ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test15)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[0]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[1]);
    NBP_ASSERT_INT_EQ(err, 0);

    test15ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test15ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test16)
{
    int err, i;

    SAMPLE_SLEEP();

    // unblock test17, test18, test19
    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[2]);
        NBP_ASSERT_INT_EQ(err, 0);
    }

    // wait for test17, test18, test19
    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[3]);
        NBP_ASSERT_INT_EQ(err, 0);
    }

    test16ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test16ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test17)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[2]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[3]);
    NBP_ASSERT_INT_EQ(err, 0);

    test17ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test17ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test18)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[2]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[3]);
    NBP_ASSERT_INT_EQ(err, 0);

    test18ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test18ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test19)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[2]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[3]);
    NBP_ASSERT_INT_EQ(err, 0);

    test19ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test19ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}
