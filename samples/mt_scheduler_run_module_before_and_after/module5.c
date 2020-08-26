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

NBP_MODULE_FIXTURES(module5, module_setup, module_teardown)
{
    NBP_MODULE_RUN(empty_module9);
    NBP_MODULE_RUN(submodule9);
    NBP_TEST_RUN(test75);
    NBP_MODULE_RUN(empty_module10);
    NBP_MODULE_RUN(submodule10);
    NBP_TEST_RUN(test76);
}

NBP_MODULE_FIXTURES(submodule9, module_setup, module_teardown)
{
    NBP_MODULE_RUN(subsubmodule17);
    NBP_TEST_RUN(test77);
    NBP_MODULE_RUN(subsubmodule18);
    NBP_TEST_RUN(test78);
}

NBP_MODULE_FIXTURES(submodule10, module_setup, module_teardown)
{
    NBP_TEST_RUN(test79);
    NBP_MODULE_RUN(subsubmodule19);
    NBP_TEST_RUN(test80);
    NBP_MODULE_RUN(subsubmodule20);
}

NBP_MODULE_FIXTURES(subsubmodule17, module_setup, module_teardown)
{
    NBP_TEST_RUN(test81);
    NBP_TEST_RUN(test82);
    NBP_TEST_RUN(test83);
    NBP_TEST_RUN(test84);
}

NBP_MODULE_FIXTURES(subsubmodule18, module_setup, module_teardown)
{
    NBP_TEST_RUN(test85);
    NBP_TEST_RUN(test86);
    NBP_TEST_RUN(test87);
    NBP_TEST_RUN(test88);
}

NBP_MODULE_FIXTURES(subsubmodule19, module_setup, module_teardown)
{
    NBP_TEST_RUN(test89);
    NBP_TEST_RUN(test90);
    NBP_TEST_RUN(test91);
    NBP_TEST_RUN(test92);
}

NBP_MODULE_FIXTURES(subsubmodule20, module_setup, module_teardown)
{
    NBP_TEST_RUN(test93);
    NBP_TEST_RUN(test94);
    NBP_TEST_RUN(test95);
    NBP_TEST_RUN(test96);
}

NBP_TEST(test75, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test76, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test77, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test78, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test79, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test80, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test81, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test82, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test83, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test84, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test85, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test86, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test87, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test88, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test89, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test90, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test91, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test92, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test93, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test94, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test95, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test96, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module5", "module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module5", "module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}
