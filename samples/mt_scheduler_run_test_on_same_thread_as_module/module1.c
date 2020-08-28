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

#include <nbp.h>

#include "../sample_utils.h"

extern SAMPLE_THREAD_ID_TYPE test4ThreadId;
extern SAMPLE_THREAD_ID_TYPE test5ThreadId;
extern SAMPLE_THREAD_ID_TYPE test6ThreadId;
extern SAMPLE_THREAD_ID_TYPE test7ThreadId;
extern SAMPLE_THREAD_ID_TYPE test8ThreadId;
extern SAMPLE_THREAD_ID_TYPE test9ThreadId;
extern SAMPLE_THREAD_ID_TYPE test10ThreadId;
extern SAMPLE_THREAD_ID_TYPE test11ThreadId;
extern SAMPLE_THREAD_ID_TYPE test12ThreadId;
extern SAMPLE_THREAD_ID_TYPE test13ThreadId;
extern SAMPLE_THREAD_ID_TYPE test14ThreadId;
extern SAMPLE_THREAD_ID_TYPE test15ThreadId;
extern SAMPLE_THREAD_ID_TYPE test16ThreadId;
extern SAMPLE_THREAD_ID_TYPE test17ThreadId;

NBP_MODULE(module1)
{
    NBP_MODULE_RUN(empty_module1);
    NBP_MODULE_RUN(submodule1);
    NBP_TEST_RUN(test4);
    NBP_MODULE_RUN(empty_module2);
    NBP_MODULE_RUN(submodule2);
    NBP_TEST_RUN(test5);
}

NBP_MODULE(empty_module1, NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
    NBP_MODULE_RUN(empty_submodule1);
    NBP_MODULE_RUN(empty_submodule2);
}

NBP_MODULE(empty_module2, NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
    NBP_MODULE_RUN(empty_submodule3);
    NBP_MODULE_RUN(empty_submodule4);
}

NBP_MODULE(empty_submodule1, NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
}

NBP_MODULE(empty_submodule2, NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
}

NBP_MODULE(empty_submodule3, NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
}

NBP_MODULE(empty_submodule4, NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
}

NBP_MODULE(submodule1)
{
    NBP_MODULE_RUN(subsubmodule1);
    NBP_TEST_RUN(test6);
    NBP_MODULE_RUN(subsubmodule2);
    NBP_TEST_RUN(test7);
}

NBP_MODULE(submodule2)
{
    NBP_TEST_RUN(test8);
    NBP_MODULE_RUN(subsubmodule3);
    NBP_TEST_RUN(test9);
    NBP_MODULE_RUN(subsubmodule4);
}

NBP_MODULE(subsubmodule1)
{
    NBP_TEST_RUN(test10);
    NBP_TEST_RUN(test11);
}

NBP_MODULE(subsubmodule2)
{
    NBP_TEST_RUN(test12);
    NBP_TEST_RUN(test13);
}

NBP_MODULE(subsubmodule3)
{
    NBP_TEST_RUN(test14);
    NBP_TEST_RUN(test15);
}

NBP_MODULE(subsubmodule4)
{
    NBP_TEST_RUN(test16);
    NBP_TEST_RUN(test17);
}

NBP_TEST(test4)
{
    SAMPLE_SLEEP();

    test4ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test4ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test5)
{
    SAMPLE_SLEEP();

    test5ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test5ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test6)
{
    SAMPLE_SLEEP();

    test6ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test6ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test7)
{
    SAMPLE_SLEEP();

    test7ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test7ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test8)
{
    SAMPLE_SLEEP();

    test8ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test8ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test9)
{
    SAMPLE_SLEEP();

    test9ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test9ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test10)
{
    SAMPLE_SLEEP();

    test10ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test10ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test11)
{
    SAMPLE_SLEEP();

    test11ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test11ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test12)
{
    SAMPLE_SLEEP();

    test12ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test12ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test13)
{
    SAMPLE_SLEEP();

    test13ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test13ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test14)
{
    SAMPLE_SLEEP();

    test14ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test14ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test15)
{
    SAMPLE_SLEEP();

    test15ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test15ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test16)
{
    SAMPLE_SLEEP();

    test16ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test16ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}

NBP_TEST(test17)
{
    SAMPLE_SLEEP();

    test17ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test17ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE, NBP_ASSERT_FATAL);
}
