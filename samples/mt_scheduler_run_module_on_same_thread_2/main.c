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

NBP_MAIN_MODULE(mt_scheduler_run_module_on_same_thread)
{
    NBP_MODULE_RUN_CTX(
        module,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD
        )
    );

    NBP_TEST_RUN_CTX(
        test1,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module)
        )
    );
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

NBP_MODULE(module)
{
    NBP_MODULE_RUN(empty_module1);
    NBP_MODULE_RUN(submodule1);
    NBP_MODULE_RUN(empty_module2);
    NBP_MODULE_RUN(submodule2);
}

NBP_MODULE(submodule1)
{
    NBP_MODULE_RUN(subsubmodule1);
    NBP_MODULE_RUN(subsubmodule2);
}

NBP_MODULE(submodule2)
{
    NBP_MODULE_RUN(subsubmodule3);
    NBP_MODULE_RUN(subsubmodule4);
}

NBP_MODULE(subsubmodule1)
{
    NBP_TEST_RUN(test2);
    NBP_TEST_RUN(test3);
}

NBP_MODULE(subsubmodule2)
{
    NBP_TEST_RUN(test4);
    NBP_TEST_RUN(test5);
}

NBP_MODULE(subsubmodule3)
{
    NBP_TEST_RUN(test6);
    NBP_TEST_RUN(test7);
}

NBP_MODULE(subsubmodule4)
{
    NBP_TEST_RUN(test8);
    NBP_TEST_RUN(test9);
}

NBP_TEST(test1)
{
    SAMPLE_SLEEP();

    NBP_CHECK(test2ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test3ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test4ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test5ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test6ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test7ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test8ThreadId));
    NBP_CHECK(SAMPLE_THREAD_ID_EQUAL(test2ThreadId, test9ThreadId));
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
