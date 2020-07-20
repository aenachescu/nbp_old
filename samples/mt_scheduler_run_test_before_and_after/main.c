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
#include "fixtures.h"

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

NBP_TEST_FIXTURES(test1, test1_setup, test1_teardown)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1SetupValue);
    NBP_CHECK(value == 2);

    // check teardown values
    NBP_CHECK(test1_test3TeardownValue == 0);
    NBP_CHECK(test1_test4TeardownValue == 0);
    NBP_CHECK(test1_test5TeardownValue == 1);
    NBP_CHECK(test1_test6TeardownValue == 1);

    NBP_CHECK(test1_module1TeardownValue == 0);
    NBP_CHECK(test1_module2TeardownValue == 0);
    NBP_CHECK(test1_module3TeardownValue == 5);
    NBP_CHECK(test1_module4TeardownValue == 23);

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

    SAMPLE_FORCE_SLEEP_MS(1000);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test1Value, 1);
}

NBP_TEST_FIXTURES(test3, test3_setup, test3_teardown)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check teardown values
    NBP_CHECK(test3_test1TeardownValue == 1);
    NBP_CHECK(test3_test2TeardownValue == 1);

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test3SetupValue);
    NBP_CHECK(value == 2);

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test3Value, 1);
}

NBP_TEST_FIXTURES(test5, test5_setup, test5_teardown)
{
    unsigned int value;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(1000);

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test5SetupValue);
    NBP_CHECK(value == 2);

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test5Value, 1);
}

NBP_MAIN_MODULE_FIXTURES(mt_scheduler_run_test_before_and_after,
    main_module_setup, main_module_teardown)
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

NBP_TEST_FIXTURES(test7, test7_setup, test7_teardown)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test7SetupValue);
    NBP_CHECK(value == 3);

    // check teardown values
    NBP_CHECK(module1_test1TeardownValue == 1);
    NBP_CHECK(module1_test2TeardownValue == 1);

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module1Value, 1);
}

NBP_TEST_FIXTURES(test8, test8_setup, test8_teardown)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test8SetupValue);
    NBP_CHECK(value == 3);

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module1Value, 1);
}

NBP_TEST_FIXTURES(test9, test9_setup, test9_teardown)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test9SetupValue);
    NBP_CHECK(value == 3);

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module1Value, 1);
}

NBP_TEST_FIXTURES(test10, test10_setup, test10_teardown)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test10SetupValue);
    NBP_CHECK(value == 3);

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module1Value, 1);
}

NBP_MODULE_FIXTURES(module1, module1_setup, module1_teardown)
{
    NBP_TEST_RUN(test7);
    NBP_TEST_RUN(test8);
    NBP_TEST_RUN(test9);
    NBP_TEST_RUN(test10);
}

NBP_TEST_FIXTURES(test15, test15_setup, test15_teardown)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test15SetupValue);
    NBP_CHECK(value == 3);

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);

    SAMPLE_FORCE_SLEEP_MS(1000);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module3Value, 1);
}

NBP_TEST_FIXTURES(test16, test16_setup, test16_teardown)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test16SetupValue);
    NBP_CHECK(value == 3);

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);

    SAMPLE_FORCE_SLEEP_MS(1000);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module3Value, 1);
}

NBP_TEST_FIXTURES(test17, test17_setup, test17_teardown)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test17SetupValue);
    NBP_CHECK(value == 3);

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);

    SAMPLE_FORCE_SLEEP_MS(1000);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module3Value, 1);
}

NBP_TEST_FIXTURES(test18, test18_setup, test18_teardown)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test18SetupValue);
    NBP_CHECK(value == 3);

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);

    SAMPLE_FORCE_SLEEP_MS(1000);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module3Value, 1);
}

NBP_MODULE_FIXTURES(module3, module3_setup, module3_teardown)
{
    NBP_TEST_RUN(test15);
    NBP_TEST_RUN(test16);
    NBP_TEST_RUN(test17);
    NBP_TEST_RUN(test18);
}
