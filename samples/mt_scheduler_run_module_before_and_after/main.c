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

NBP_MAIN_MODULE(mt_scheduler_run_module_before_and_after,
    NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_MODULE_RUN(module1);
    NBP_MODULE_RUN(module2);

    NBP_TEST_RUN(test1);
    NBP_TEST_RUN(test2);

    NBP_MODULE_RUN_CTX(
        module3,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_BEFORE_TEST(test1),
            NBP_MT_SCHEDULER_RUN_BEFORE_TEST(test3),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test2),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test4),
            NBP_MT_SCHEDULER_RUN_BEFORE_MODULE(module1),
            NBP_MT_SCHEDULER_RUN_BEFORE_MODULE(module5),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module2),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module6)
        )
    );
    NBP_MODULE_RUN_CTX(
        module4,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_BEFORE_TEST(test1),
            NBP_MT_SCHEDULER_RUN_BEFORE_TEST(test3),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test2),
            NBP_MT_SCHEDULER_RUN_AFTER_TEST(test4),
            NBP_MT_SCHEDULER_RUN_BEFORE_MODULE(module1),
            NBP_MT_SCHEDULER_RUN_BEFORE_MODULE(module5),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module2),
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module6)
        )
    );

    NBP_TEST_RUN(test3);
    NBP_TEST_RUN(test4);

    NBP_MODULE_RUN(module5);
    NBP_MODULE_RUN(module6);
}

NBP_TEST(test1, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("test1", "module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("test1", "module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test2, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

/*******************************************************************************
 * module1 implementation
 ******************************************************************************/

NBP_MODULE(module1, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_MODULE_RUN(empty_module1);
    NBP_MODULE_RUN(submodule1);
    NBP_MODULE_RUN(empty_module2);
    NBP_MODULE_RUN(submodule2);
}

NBP_MODULE(submodule1, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_MODULE_RUN(subsubmodule1);
    NBP_MODULE_RUN(subsubmodule2);
}

NBP_MODULE(submodule2, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_MODULE_RUN(subsubmodule3);
    NBP_MODULE_RUN(subsubmodule4);
}

NBP_MODULE(subsubmodule1, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_TEST_RUN(test5);
    NBP_TEST_RUN(test6);
    NBP_TEST_RUN(test7);
    NBP_TEST_RUN(test8);
}

NBP_MODULE(subsubmodule2, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_TEST_RUN(test9);
    NBP_TEST_RUN(test10);
    NBP_TEST_RUN(test11);
    NBP_TEST_RUN(test12);
}

NBP_MODULE(subsubmodule3, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_TEST_RUN(test13);
    NBP_TEST_RUN(test14);
    NBP_TEST_RUN(test15);
    NBP_TEST_RUN(test16);
}

NBP_MODULE(subsubmodule4, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_TEST_RUN(test17);
    NBP_TEST_RUN(test18);
    NBP_TEST_RUN(test19);
    NBP_TEST_RUN(test20);
}

NBP_TEST(test5, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module1", "module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module1", "module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test6, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module1", "module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module1", "module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test7, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module1", "module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module1", "module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test8, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module1", "module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module1", "module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test9, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module1", "module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module1", "module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test10, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module1", "module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module1", "module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test11, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module1", "module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module1", "module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test12, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module1", "module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module1", "module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test13, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module1", "module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module1", "module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test14, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module1", "module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module1", "module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test15, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module1", "module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module1", "module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test16, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module1", "module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module1", "module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test17, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module1", "module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module1", "module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test18, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module1", "module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module1", "module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test19, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module1", "module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module1", "module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test20, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module1", "module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module1", "module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

/*******************************************************************************
 * module2 implementation
 ******************************************************************************/

NBP_MODULE(module2, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_MODULE_RUN(empty_module3);
    NBP_MODULE_RUN(submodule3);
    NBP_MODULE_RUN(empty_module4);
    NBP_MODULE_RUN(submodule4);
}

NBP_MODULE(submodule3, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_MODULE_RUN(subsubmodule5);
    NBP_MODULE_RUN(subsubmodule6);
}

NBP_MODULE(submodule4, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_MODULE_RUN(subsubmodule7);
    NBP_MODULE_RUN(subsubmodule8);
}

NBP_MODULE(subsubmodule5, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_TEST_RUN(test21);
    NBP_TEST_RUN(test22);
    NBP_TEST_RUN(test23);
    NBP_TEST_RUN(test24);
}

NBP_MODULE(subsubmodule6, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_TEST_RUN(test25);
    NBP_TEST_RUN(test26);
    NBP_TEST_RUN(test27);
    NBP_TEST_RUN(test28);
}

NBP_MODULE(subsubmodule7, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_TEST_RUN(test29);
    NBP_TEST_RUN(test30);
    NBP_TEST_RUN(test31);
    NBP_TEST_RUN(test32);
}

NBP_MODULE(subsubmodule8, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_TEST_RUN(test33);
    NBP_TEST_RUN(test34);
    NBP_TEST_RUN(test35);
    NBP_TEST_RUN(test36);
}

NBP_TEST(test21, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test22, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test23, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test24, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test25, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test26, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test27, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test28, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test29, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test30, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test31, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test32, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test33, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test34, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test35, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test36, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

/*******************************************************************************
 * module3 implementation
 ******************************************************************************/

NBP_MODULE(module3, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_MODULE_RUN(empty_module5);
    NBP_MODULE_RUN(submodule5);
    NBP_MODULE_RUN(empty_module6);
    NBP_MODULE_RUN(submodule6);
}

NBP_MODULE(submodule5, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_MODULE_RUN(subsubmodule9);
    NBP_MODULE_RUN(subsubmodule10);
}

NBP_MODULE(submodule6, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_MODULE_RUN(subsubmodule11);
    NBP_MODULE_RUN(subsubmodule12);
}

NBP_MODULE(subsubmodule9, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_TEST_RUN(test37);
    NBP_TEST_RUN(test38);
    NBP_TEST_RUN(test39);
    NBP_TEST_RUN(test40);
}

NBP_MODULE(subsubmodule10, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_TEST_RUN(test41);
    NBP_TEST_RUN(test42);
    NBP_TEST_RUN(test43);
    NBP_TEST_RUN(test44);
}

NBP_MODULE(subsubmodule11, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_TEST_RUN(test45);
    NBP_TEST_RUN(test46);
    NBP_TEST_RUN(test47);
    NBP_TEST_RUN(test48);
}

NBP_MODULE(subsubmodule12, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_TEST_RUN(test49);
    NBP_TEST_RUN(test50);
    NBP_TEST_RUN(test51);
    NBP_TEST_RUN(test52);
}

NBP_TEST(test37, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module3", "test2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "test4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "module2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module3", "module6");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test38, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module3", "test2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "test4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "module2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module3", "module6");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test39, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module3", "test2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "test4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "module2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module3", "module6");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test40, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module3", "test2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "test4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "module2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module3", "module6");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test41, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module3", "test2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "test4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "module2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module3", "module6");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test42, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module3", "test2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "test4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "module2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module3", "module6");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test43, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module3", "test2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "test4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "module2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module3", "module6");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test44, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module3", "test2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "test4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "module2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module3", "module6");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test45, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module3", "test2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "test4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "module2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module3", "module6");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test46, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module3", "test2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "test4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "module2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module3", "module6");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test47, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module3", "test2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "test4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "module2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module3", "module6");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test48, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module3", "test2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "test4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "module2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module3", "module6");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test49, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module3", "test2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "test4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "module2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module3", "module6");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test50, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module3", "test2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "test4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "module2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module3", "module6");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test51, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module3", "test2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "test4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "module2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module3", "module6");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test52, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module3", "test2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "test4");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module3", "module2");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module3", "module6");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_ASSERT(testData != NBP_MEMORY_NULL_POINTER, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_ASSERT_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}
