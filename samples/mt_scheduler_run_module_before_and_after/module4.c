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

NBP_MODULE_FIXTURES(module4, module_setup, module_teardown)
{
    NBP_MODULE_RUN(empty_module7);
    NBP_MODULE_RUN(submodule7);
    NBP_TEST_RUN(test53);
    NBP_MODULE_RUN(empty_module8);
    NBP_MODULE_RUN(submodule8);
    NBP_TEST_RUN(test54);
}

NBP_MODULE_FIXTURES(submodule7, module_setup, module_teardown)
{
    NBP_MODULE_RUN(subsubmodule13);
    NBP_TEST_RUN(test55);
    NBP_MODULE_RUN(subsubmodule14);
    NBP_TEST_RUN(test56);
}

NBP_MODULE_FIXTURES(submodule8, module_setup, module_teardown)
{
    NBP_TEST_RUN(test57);
    NBP_MODULE_RUN(subsubmodule15);
    NBP_TEST_RUN(test58);
    NBP_MODULE_RUN(subsubmodule16);
}

NBP_MODULE_FIXTURES(subsubmodule13, module_setup, module_teardown)
{
    NBP_TEST_RUN(test59);
    NBP_TEST_RUN(test60);
    NBP_TEST_RUN(test61);
    NBP_TEST_RUN(test62);
}

NBP_MODULE_FIXTURES(subsubmodule14, module_setup, module_teardown)
{
    NBP_TEST_RUN(test63);
    NBP_TEST_RUN(test64);
    NBP_TEST_RUN(test65);
    NBP_TEST_RUN(test66);
}

NBP_MODULE_FIXTURES(subsubmodule15, module_setup, module_teardown)
{
    NBP_TEST_RUN(test67);
    NBP_TEST_RUN(test68);
    NBP_TEST_RUN(test69);
    NBP_TEST_RUN(test70);
}

NBP_MODULE_FIXTURES(subsubmodule16, module_setup, module_teardown)
{
    NBP_TEST_RUN(test71);
    NBP_TEST_RUN(test72);
    NBP_TEST_RUN(test73);
    NBP_TEST_RUN(test74);
}

NBP_TEST(test53, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test54, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test55, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test56, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test57, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test58, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test59, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test60, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test61, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test62, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test63, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test64, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test65, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test66, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test67, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test68, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test69, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test70, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test71, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test72, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test73, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST(test74, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();

    testData = sample_utils_get_test_data_from_copy("module4", "test2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "test4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 1);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 1);

    testData = sample_utils_get_test_data_from_copy("module4", "module2");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 23);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 16);

    testData = sample_utils_get_test_data_from_copy("module4", "module6");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 2);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 29);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 22);

    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("test1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("test3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module1");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module5");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}
