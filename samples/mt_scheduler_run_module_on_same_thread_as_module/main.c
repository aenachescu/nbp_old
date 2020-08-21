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
SAMPLE_THREAD_ID_TYPE test34ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test35ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test36ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test37ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test38ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test39ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test40ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test41ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test42ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test43ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test44ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test45ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test46ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test47ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test48ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test49ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test50ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test51ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test52ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test53ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test54ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test55ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test56ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test57ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test58ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test59ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test60ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test61ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test62ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test63ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test64ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test65ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test66ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test67ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test68ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test69ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test70ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test71ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test72ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test73ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test74ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test75ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test76ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test77ThreadId    = SAMPLE_THREAD_ID_INVALID_VALUE;

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

NBP_MAIN_MODULE_FIXTURES(mt_scheduler_run_module_on_same_thread_as_module,
    main_module_setup, main_module_teardown)
{
    NBP_TEST_RUN(test2);
    NBP_TEST_RUN(test3);
    NBP_TEST_RUN(test4);
    NBP_TEST_RUN(test5);

    NBP_TEST_RUN_CTX(
        test1,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module1),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module2),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module3),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module4),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module5),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module6),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module7),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module8),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module9),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module10),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test2),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test3),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test4),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test5),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test6),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test7),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test8),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test9)
        )
    );

    NBP_MODULE_RUN_CTX(
        module1,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_MODULE(module2),
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_MODULE(module3),
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_MODULE(module4),
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_MODULE(module5)
        )
    );
    NBP_MODULE_RUN(module2);
    NBP_MODULE_RUN(module3);
    NBP_MODULE_RUN(module4);
    NBP_MODULE_RUN(module5);

    NBP_MODULE_RUN(module6);
    NBP_MODULE_RUN_CTX(
        module7,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_MODULE(module6)
        )
    );
    NBP_MODULE_RUN_CTX(
        module8,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_MODULE(module7)
        )
    );
    NBP_MODULE_RUN_CTX(
        module9,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_MODULE(module8),
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_MODULE(module6)
        )
    );
    NBP_MODULE_RUN_CTX(
        module10,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_MODULE(module9),
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_MODULE(module1)
        )
    );

    NBP_TEST_RUN(test6);
    NBP_TEST_RUN(test7);
    NBP_TEST_RUN(test8);
    NBP_TEST_RUN(test9);
}

NBP_TEST(test1)
{
    unsigned int num;

    SAMPLE_SLEEP();

    NBP_CHECK(test2ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test3ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test4ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test5ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test6ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test7ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test8ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(test9ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);

    NBP_CHECK(test10ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);

    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test11ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test12ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test13ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test14ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test15ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test16ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test17ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test18ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test19ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test20ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test21ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test22ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test23ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test24ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test25ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test26ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test27ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test28ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test29ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test30ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test31ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test32ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test33ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test34ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test35ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test36ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test37ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test38ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test39ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test40ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test41ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test42ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test43ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test44ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test45ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test46ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test47ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test48ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test49ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test50ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test51ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test52ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test53ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test54ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test55ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test56ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test57ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test58ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test59ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test60ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test61ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test62ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test63ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test64ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test65ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test66ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test67ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test68ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test69ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test70ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test71ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test72ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test73ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test74ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test75ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test76ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test77ThreadId));

    num = 0;
    if (!SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test2ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test3ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test4ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test5ThreadId)) num++;
    NBP_CHECK(num > 0);

    num = 0;
    if (!SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test6ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test7ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test8ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test10ThreadId, test9ThreadId)) num++;
    NBP_CHECK(num > 0);
}

NBP_TEST(test2)
{
    int err, i;

    SAMPLE_SLEEP();

    // unblock test3, test4, test5
    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[0]);
        NBP_ASSERT_INT_EQ(err, 0);
    }

    // wait for test3, test4, test5
    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[1]);
        NBP_ASSERT_INT_EQ(err, 0);
    }

    test2ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test2ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test3)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[0]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[1]);
    NBP_ASSERT_INT_EQ(err, 0);

    test3ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test3ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test4)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[0]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[1]);
    NBP_ASSERT_INT_EQ(err, 0);

    test4ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test4ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test5)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[0]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[1]);
    NBP_ASSERT_INT_EQ(err, 0);

    test5ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test5ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test6)
{
    int err, i;

    SAMPLE_SLEEP();

    // unblock test7, test8, test9
    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[2]);
        NBP_ASSERT_INT_EQ(err, 0);
    }

    // wait for test7, test8, test9
    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[3]);
        NBP_ASSERT_INT_EQ(err, 0);
    }

    test6ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test6ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test7)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[2]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[3]);
    NBP_ASSERT_INT_EQ(err, 0);

    test7ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test7ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test8)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[2]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[3]);
    NBP_ASSERT_INT_EQ(err, 0);

    test8ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test8ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test9)
{
    int err;

    SAMPLE_SLEEP();

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphores[2]);
    NBP_ASSERT_INT_EQ(err, 0);

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[3]);
    NBP_ASSERT_INT_EQ(err, 0);

    test9ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test9ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

/*******************************************************************************
 * module1 implementation
 ******************************************************************************/

NBP_MODULE(module1)
{
    NBP_MODULE_RUN(empty_module1);
    NBP_MODULE_RUN(submodule1);
    NBP_TEST_RUN(test10);
    NBP_MODULE_RUN(empty_module2);
    NBP_MODULE_RUN(submodule2);
    NBP_TEST_RUN(test11);
}

NBP_MODULE_FIXTURES(empty_module1, setupEmptyModule, teardownEmptyModule)
{
    NBP_MODULE_RUN(empty_submodule1);
    NBP_MODULE_RUN(empty_submodule2);
}

NBP_MODULE_FIXTURES(empty_module2, setupEmptyModule, teardownEmptyModule)
{
    NBP_MODULE_RUN(empty_submodule3);
    NBP_MODULE_RUN(empty_submodule4);
}

NBP_MODULE_FIXTURES(empty_submodule1, setupEmptyModule, teardownEmptyModule)
{
}

NBP_MODULE_FIXTURES(empty_submodule2, setupEmptyModule, teardownEmptyModule)
{
}

NBP_MODULE_FIXTURES(empty_submodule3, setupEmptyModule, teardownEmptyModule)
{
}

NBP_MODULE_FIXTURES(empty_submodule4, setupEmptyModule, teardownEmptyModule)
{
}

NBP_MODULE(submodule1)
{
    NBP_MODULE_RUN(subsubmodule1);
    NBP_TEST_RUN(test12);
    NBP_MODULE_RUN(subsubmodule2);
    NBP_TEST_RUN(test13);
}

NBP_MODULE(submodule2)
{
    NBP_TEST_RUN(test14);
    NBP_MODULE_RUN(subsubmodule3);
    NBP_TEST_RUN(test15);
    NBP_MODULE_RUN(subsubmodule4);
}

NBP_MODULE(subsubmodule1)
{
    NBP_TEST_RUN(test16);
    NBP_TEST_RUN(test17);
}

NBP_MODULE(subsubmodule2)
{
    NBP_TEST_RUN(test18);
    NBP_TEST_RUN(test19);
}

NBP_MODULE(subsubmodule3)
{
    NBP_TEST_RUN(test20);
    NBP_TEST_RUN(test21);
}

NBP_MODULE(subsubmodule4)
{
    NBP_TEST_RUN(test22);
    NBP_TEST_RUN(test23);
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
    SAMPLE_SLEEP();

    test12ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test12ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test13)
{
    SAMPLE_SLEEP();

    test13ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test13ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test14)
{
    SAMPLE_SLEEP();

    test14ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test14ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test15)
{
    SAMPLE_SLEEP();

    test15ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test15ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test16)
{
    SAMPLE_SLEEP();

    test16ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test16ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test17)
{
    SAMPLE_SLEEP();

    test17ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test17ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test18)
{
    SAMPLE_SLEEP();

    test18ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test18ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test19)
{
    SAMPLE_SLEEP();

    test19ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test19ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test20)
{
    SAMPLE_SLEEP();

    test20ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test20ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test21)
{
    SAMPLE_SLEEP();

    test21ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test21ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test22)
{
    SAMPLE_SLEEP();

    test22ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test22ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test23)
{
    SAMPLE_SLEEP();

    test23ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test23ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

/*******************************************************************************
 * module2 implementation
 ******************************************************************************/

NBP_MODULE(module2)
{
    NBP_MODULE_RUN(empty_module3);
    NBP_MODULE_RUN(submodule3);
    NBP_MODULE_RUN(empty_module4);
    NBP_MODULE_RUN(submodule4);
}

NBP_MODULE_FIXTURES(empty_module3, setupEmptyModule, teardownEmptyModule)
{
    NBP_MODULE_RUN(empty_submodule5);
    NBP_MODULE_RUN(empty_submodule6);
}

NBP_MODULE_FIXTURES(empty_module4, setupEmptyModule, teardownEmptyModule)
{
    NBP_MODULE_RUN(empty_submodule7);
    NBP_MODULE_RUN(empty_submodule8);
}

NBP_MODULE_FIXTURES(empty_submodule5, setupEmptyModule, teardownEmptyModule)
{
}

NBP_MODULE_FIXTURES(empty_submodule6, setupEmptyModule, teardownEmptyModule)
{
}

NBP_MODULE_FIXTURES(empty_submodule7, setupEmptyModule, teardownEmptyModule)
{
}

NBP_MODULE_FIXTURES(empty_submodule8, setupEmptyModule, teardownEmptyModule)
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
    NBP_TEST_RUN(test24);
    NBP_TEST_RUN(test25);
}

NBP_MODULE(subsubmodule6)
{
    NBP_TEST_RUN(test26);
    NBP_TEST_RUN(test27);
}

NBP_MODULE(subsubmodule7)
{
    NBP_TEST_RUN(test28);
    NBP_TEST_RUN(test29);
}

NBP_MODULE(subsubmodule8)
{
    NBP_TEST_RUN(test30);
    NBP_TEST_RUN(test31);
}

NBP_TEST(test24)
{
    SAMPLE_SLEEP();

    test24ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test24ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test25)
{
    SAMPLE_SLEEP();

    test25ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test25ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test26)
{
    SAMPLE_SLEEP();

    test26ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test26ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test27)
{
    SAMPLE_SLEEP();

    test27ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test27ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test28)
{
    SAMPLE_SLEEP();

    test28ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test28ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test29)
{
    SAMPLE_SLEEP();

    test29ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test29ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test30)
{
    SAMPLE_SLEEP();

    test30ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test30ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test31)
{
    SAMPLE_SLEEP();

    test31ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test31ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

/*******************************************************************************
 * module3 implementation
 ******************************************************************************/

NBP_MODULE(module3)
{
    NBP_TEST_RUN(test32);
    NBP_TEST_RUN(test33);
    NBP_TEST_RUN(test34);
    NBP_TEST_RUN(test35);
}

NBP_TEST(test32)
{
    SAMPLE_SLEEP();

    test32ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test32ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test33)
{
    SAMPLE_SLEEP();

    test33ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test33ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test34)
{
    SAMPLE_SLEEP();

    test34ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test34ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test35)
{
    SAMPLE_SLEEP();

    test35ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test35ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

/*******************************************************************************
 * module4 implementation
 ******************************************************************************/

NBP_MODULE(module4)
{
    NBP_TEST_RUN(test36);
    NBP_TEST_RUN(test37);
    NBP_TEST_RUN(test38);
    NBP_TEST_RUN(test39);
}

NBP_TEST(test36)
{
    SAMPLE_SLEEP();

    test36ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test36ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test37)
{
    SAMPLE_SLEEP();

    test37ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test37ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test38)
{
    SAMPLE_SLEEP();

    test38ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test38ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test39)
{
    SAMPLE_SLEEP();

    test39ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test39ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

/*******************************************************************************
 * module5 implementation
 ******************************************************************************/

NBP_MODULE(module5)
{
    NBP_TEST_RUN(test40);
    NBP_TEST_RUN(test41);
    NBP_TEST_RUN(test42);
    NBP_TEST_RUN(test43);
}

NBP_TEST(test40)
{
    SAMPLE_SLEEP();

    test40ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test40ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test41)
{
    SAMPLE_SLEEP();

    test41ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test41ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test42)
{
    SAMPLE_SLEEP();

    test42ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test42ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test43)
{
    SAMPLE_SLEEP();

    test43ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test43ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}
