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

// these lines are excluded from coverage because if a module has no test then
// the setup and teardown functions are not run
// LCOV_EXCL_START

NBP_MODULE_SETUP(setupEmptyModule)
{
    write_message_to_console("this message should not be displayed");
}

NBP_MODULE_TEARDOWN(teardownEmptyModule)
{
    write_message_to_console("this message should not be displayed");
}

// LCOV_EXCL_STOP

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
SAMPLE_THREAD_ID_TYPE test34ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;

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

NBP_MAIN_MODULE(mt_scheduler_run_module_on_same_thread_as_test,
    NBP_MODULE_FIXTURES(main_module_setup, main_module_teardown))
{
    NBP_TEST_RUN(test27);
    NBP_TEST_RUN(test28);
    NBP_TEST_RUN(test29);
    NBP_TEST_RUN(test30);

    NBP_TEST_RUN_CTX(
        test1,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test2),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test3),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test4),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module1),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module2),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test27),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test28),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test29),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test30),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test31),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test32),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test33),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test34)
        )
    );

    NBP_TEST_RUN(test2);
    NBP_TEST_RUN(test3);

    NBP_TEST_RUN_CTX(
        test4,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(test3)
        )
    );

    NBP_MODULE_RUN_CTX(
        module1,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(test2),
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(test3)
        )
    );
    NBP_MODULE_RUN_CTX(
        module2,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(test4)
        )
    );

    NBP_TEST_RUN(test31);
    NBP_TEST_RUN(test32);
    NBP_TEST_RUN(test33);
    NBP_TEST_RUN(test34);
}

NBP_TEST(test1)
{
    unsigned int num;

    SAMPLE_SLEEP();

    NBP_ASSERT(test2ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);

    NBP_ASSERT(test27ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_ASSERT(test28ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_ASSERT(test29ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_ASSERT(test30ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_ASSERT(test31ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_ASSERT(test32ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_ASSERT(test33ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_ASSERT(test34ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);

    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test3ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test4ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test5ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test6ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test7ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test8ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test9ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test10ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test11ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test12ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test13ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test14ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test15ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test16ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test17ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test18ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test19ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test20ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test21ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test22ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test23ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test24ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test25ThreadId));
    NBP_ASSERT(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test26ThreadId));

    num = 0;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test27ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test28ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test29ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test30ThreadId)) num++;
    NBP_ASSERT(num > 0);

    num = 0;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test31ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test32ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test33ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test34ThreadId)) num++;
    NBP_ASSERT(num > 0);
}

NBP_TEST(test2)
{
    SAMPLE_SLEEP();

    test2ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test2ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}


NBP_TEST(test3)
{
    SAMPLE_SLEEP();

    test3ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test3ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test4)
{
    SAMPLE_SLEEP();

    test4ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test4ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_MODULE(module2)
{
    NBP_MODULE_RUN(empty_module3);
    NBP_MODULE_RUN(submodule3);
    NBP_MODULE_RUN(empty_module4);
    NBP_MODULE_RUN(submodule4);
}

NBP_MODULE(empty_module3, NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
    NBP_MODULE_RUN(empty_submodule5);
    NBP_MODULE_RUN(empty_submodule6);
}

NBP_MODULE(empty_module4, NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
    NBP_MODULE_RUN(empty_submodule7);
    NBP_MODULE_RUN(empty_submodule8);
}

NBP_MODULE(empty_submodule5, NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
}

NBP_MODULE(empty_submodule6, NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
}

NBP_MODULE(empty_submodule7, NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
}

NBP_MODULE(empty_submodule8, NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
}

NBP_MODULE(submodule3)
{
    NBP_MODULE_RUN(subsubmodule5);
    NBP_MODULE_RUN(subsubmodule6);
}

NBP_MODULE(submodule4)
{
    NBP_MODULE_RUN(subsubmodule7);
    NBP_MODULE_RUN(subsubmodule8);
}

NBP_MODULE(subsubmodule5)
{
    NBP_TEST_RUN(test19);
    NBP_TEST_RUN(test20);
}

NBP_MODULE(subsubmodule6)
{
    NBP_TEST_RUN(test21);
    NBP_TEST_RUN(test22);
}

NBP_MODULE(subsubmodule7)
{
    NBP_TEST_RUN(test23);
    NBP_TEST_RUN(test24);
}

NBP_MODULE(subsubmodule8)
{
    NBP_TEST_RUN(test25);
    NBP_TEST_RUN(test26);
}

NBP_TEST(test19)
{
    SAMPLE_SLEEP();

    test19ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test19ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test20)
{
    SAMPLE_SLEEP();

    test20ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test20ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test21)
{
    SAMPLE_SLEEP();

    test21ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test21ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test22)
{
    SAMPLE_SLEEP();

    test22ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test22ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test23)
{
    SAMPLE_SLEEP();

    test23ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test23ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test24)
{
    SAMPLE_SLEEP();

    test24ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test24ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test25)
{
    SAMPLE_SLEEP();

    test25ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test25ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test26)
{
    SAMPLE_SLEEP();

    test26ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test26ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test27)
{
    int err, i;

    SAMPLE_SLEEP();

    // unblock test27, test28, test29
    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[0]);
        NBP_ASSERT_INT_EQ(err, 0, NBP_ASSERT_FATAL);
    }

    // wait for test27, test28, test29
    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[1]);
        NBP_ASSERT_INT_EQ(err, 0, NBP_ASSERT_FATAL);
    }

    test27ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test27ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test28)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[0]);
    NBP_ASSERT_INT_EQ(err, 0, NBP_ASSERT_FATAL);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[1]);
    NBP_ASSERT_INT_EQ(err, 0, NBP_ASSERT_FATAL);

    test28ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test28ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test29)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[0]);
    NBP_ASSERT_INT_EQ(err, 0, NBP_ASSERT_FATAL);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[1]);
    NBP_ASSERT_INT_EQ(err, 0, NBP_ASSERT_FATAL);

    test29ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test29ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test30)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[0]);
    NBP_ASSERT_INT_EQ(err, 0, NBP_ASSERT_FATAL);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[1]);
    NBP_ASSERT_INT_EQ(err, 0, NBP_ASSERT_FATAL);

    test30ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test30ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test31)
{
    int err, i;

    SAMPLE_SLEEP();

    // unblock test31, test32, test33
    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[2]);
        NBP_ASSERT_INT_EQ(err, 0, NBP_ASSERT_FATAL);
    }

    // wait for test31, test32, test33
    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[3]);
        NBP_ASSERT_INT_EQ(err, 0, NBP_ASSERT_FATAL);
    }

    test31ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test31ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test32)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[2]);
    NBP_ASSERT_INT_EQ(err, 0, NBP_ASSERT_FATAL);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[3]);
    NBP_ASSERT_INT_EQ(err, 0, NBP_ASSERT_FATAL);

    test32ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test32ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test33)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[2]);
    NBP_ASSERT_INT_EQ(err, 0, NBP_ASSERT_FATAL);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[3]);
    NBP_ASSERT_INT_EQ(err, 0, NBP_ASSERT_FATAL);

    test33ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test33ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test34)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[2]);
    NBP_ASSERT_INT_EQ(err, 0, NBP_ASSERT_FATAL);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[3]);
    NBP_ASSERT_INT_EQ(err, 0, NBP_ASSERT_FATAL);

    test34ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test34ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

