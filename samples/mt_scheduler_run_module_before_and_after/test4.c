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

NBP_TEST_FIXTURES(test4, test_setup, test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    SAMPLE_SLEEP();
    SAMPLE_FORCE_SLEEP_MS(500);

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
