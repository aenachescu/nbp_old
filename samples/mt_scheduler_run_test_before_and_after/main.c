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

SAMPLE_ATOMIC_UINT_TYPE test1Value = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test2Value = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test3Value = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test4Value = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test5Value = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test6Value = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE module1Value = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE module2Value = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE module3Value = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE module4Value = SAMPLE_ATOMIC_UINT_INIT(0);

NBP_TEST_FIXTURES(test1, NBP_TEST_NO_SETUP, test1_teardown)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test3 and test4
    value = SAMPLE_ATOMIC_UINT_LOAD(&test3Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test4Value);
    NBP_CHECK(value == 0);

    // check if it is ran after test5 and test6
    value = SAMPLE_ATOMIC_UINT_LOAD(&test5Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test6Value);
    NBP_CHECK(value == 1);

    // check if it is ran before module1 and module2
    value = SAMPLE_ATOMIC_UINT_LOAD(&module1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&module2Value);
    NBP_CHECK(value == 0);

    // check if it is ran after module3 and module4
    value = SAMPLE_ATOMIC_UINT_LOAD(&module3Value);
    NBP_CHECK(value == 4);
    value = SAMPLE_ATOMIC_UINT_LOAD(&module4Value);
    NBP_CHECK(value == 16);
}

NBP_TEST_FIXTURES(test3, NBP_TEST_NO_SETUP, test3_teardown)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST_FIXTURES(test5, NBP_TEST_NO_SETUP, test5_teardown)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}

NBP_MAIN_MODULE(mt_scheduler_run_test_before_and_after)
{
    NBP_MODULE_RUN(module1);
    NBP_MODULE_RUN(module3);

    NBP_TEST_RUN(test3);
    NBP_TEST_RUN(test5);

    NBP_TEST_RUN_CTX(
        test1,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_BEFORE_TEST(test3),
            NBP_MT_SCHEDULER_RUN_BEFORE_TEST(test4),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test5),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test6),
            NBP_MT_SCHEDULER_RUN_BEFORE_MODULE(module1),
            NBP_MT_SCHEDULER_RUN_BEFORE_MODULE(module2),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module3),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module4)
        )
    );

    NBP_TEST_RUN_CTX(
        test2,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_BEFORE_TEST(test3),
            NBP_MT_SCHEDULER_RUN_BEFORE_TEST(test4),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test5),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test6),
            NBP_MT_SCHEDULER_RUN_BEFORE_MODULE(module1),
            NBP_MT_SCHEDULER_RUN_BEFORE_MODULE(module2),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module3),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module4)
        )
    );

    NBP_MODULE_RUN(module2);
    NBP_MODULE_RUN(module4);

    NBP_TEST_RUN(test4);
    NBP_TEST_RUN(test6);
}

NBP_TEST(test7)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST(test8)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST(test9)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST(test10)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_MODULE(module1)
{
    NBP_TEST_USE_TEARDOWN(module1_test_teardown);

    NBP_TEST_RUN(test7);
    NBP_TEST_RUN(test8);
    NBP_TEST_RUN(test9);
    NBP_TEST_RUN(test10);
}

NBP_TEST(test15)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}

NBP_TEST(test16)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}

NBP_TEST(test17)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}

NBP_TEST(test18)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}

NBP_MODULE(module3)
{
    NBP_TEST_USE_TEARDOWN(module3_test_teardown);

    NBP_TEST_RUN(test15);
    NBP_TEST_RUN(test16);
    NBP_TEST_RUN(test17);
    NBP_TEST_RUN(test18);
}
