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

SAMPLE_THREAD_ID_TYPE test2ThreadId = SAMPLE_THREAD_ID_INVALID_VALUE;
SAMPLE_THREAD_ID_TYPE test3ThreadId = SAMPLE_THREAD_ID_INVALID_VALUE;

NBP_MAIN_MODULE(mt_scheduler_run_test_on_same_thread_with_test)
{
    NBP_TEST_RUN_CTX(
        test1,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test2),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test3)
        )
    );
    NBP_TEST_RUN_CTX(
        test2,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_WITH_TEST(test3)
        )
    );
    NBP_TEST_RUN(test3);
}

NBP_TEST(test1)
{
    SAMPLE_SLEEP();

    NBP_CHECK(test2ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test3ThreadId));
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
