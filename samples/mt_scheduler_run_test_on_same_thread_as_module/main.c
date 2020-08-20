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

NBP_MAIN_MODULE(mt_scheduler_run_test_on_same_thread_as_module)
{
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
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test29)
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

    NBP_TEST_RUN(test26);
    NBP_TEST_RUN(test27);
    NBP_TEST_RUN(test28);
    NBP_TEST_RUN(test29);
}

NBP_TEST(test1)
{
    unsigned int num = 0;

    SAMPLE_SLEEP();

    NBP_CHECK(test2ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
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

    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test26ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test27ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test28ThreadId)) num++;
    if (!SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test29ThreadId)) num++;
    NBP_CHECK(num > 0);
}

NBP_TEST(test2)
{
    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

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
    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(10);

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
