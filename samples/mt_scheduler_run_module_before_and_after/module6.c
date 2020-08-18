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

NBP_MODULE_FIXTURES(module6, module_setup, module_teardown)
{
    NBP_MODULE_RUN(empty_module11);
    NBP_MODULE_RUN(submodule11);
    NBP_TEST_RUN(test97);
    NBP_MODULE_RUN(empty_module12);
    NBP_MODULE_RUN(submodule12);
    NBP_TEST_RUN(test98);
}

NBP_MODULE_FIXTURES(submodule11, module_setup, module_teardown)
{
    NBP_MODULE_RUN(subsubmodule21);
    NBP_TEST_RUN(test99);
    NBP_MODULE_RUN(subsubmodule22);
    NBP_TEST_RUN(test100);
}

NBP_MODULE_FIXTURES(submodule12, module_setup, module_teardown)
{
    NBP_TEST_RUN(test101);
    NBP_MODULE_RUN(subsubmodule23);
    NBP_TEST_RUN(test102);
    NBP_MODULE_RUN(subsubmodule24);
}

NBP_MODULE_FIXTURES(subsubmodule21, module_setup, module_teardown)
{
    NBP_TEST_RUN(test103);
    NBP_TEST_RUN(test104);
    NBP_TEST_RUN(test105);
    NBP_TEST_RUN(test106);
}

NBP_MODULE_FIXTURES(subsubmodule22, module_setup, module_teardown)
{
    NBP_TEST_RUN(test107);
    NBP_TEST_RUN(test108);
    NBP_TEST_RUN(test109);
    NBP_TEST_RUN(test110);
}

NBP_MODULE_FIXTURES(subsubmodule23, module_setup, module_teardown)
{
    NBP_TEST_RUN(test111);
    NBP_TEST_RUN(test112);
    NBP_TEST_RUN(test113);
    NBP_TEST_RUN(test114);
}

NBP_MODULE_FIXTURES(subsubmodule24, module_setup, module_teardown)
{
    NBP_TEST_RUN(test115);
    NBP_TEST_RUN(test116);
    NBP_TEST_RUN(test117);
    NBP_TEST_RUN(test118);
}

NBP_TEST_FIXTURES(test97, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test98, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test99, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test100, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test101, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test102, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test103, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test104, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test105, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test106, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test107, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test108, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test109, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test110, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test111, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test112, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test113, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test114, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test115, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test116, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test117, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}

NBP_TEST_FIXTURES(test118, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(100);

    testData = sample_utils_get_test_data_or_create("module3");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    testData = sample_utils_get_test_data_or_create("module4");
    NBP_TEST_ASSERT(testData != NBP_MEMORY_NULL_POINTER);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue), 0);
    NBP_CHECK_UINT_EQ(SAMPLE_ATOMIC_UINT_LOAD(&testData->runValue), 0);

    sample_utils_increment_run_data_recursively(NBP_TEST_THIS);
}
