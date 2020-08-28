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

#include <limits.h>

int get_int()
{
    return 2;
}

volatile int int_min = INT_MIN;
volatile int int_max = INT_MAX;
volatile int int_ = 2;

NBP_TEST(module_assert_int_eq)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_INT_EQ(get_int(), int_, NBP_ASSERT_FATAL_FOR_MODULE);
    NBP_ASSERT_INT_EQ(get_int(), int_, NBP_ASSERT_FATAL_FOR_MODULE, NBP_FAILURE_MESSAGE("module_assert failed"));
    NBP_ASSERT_INT_EQ(get_int(), int_, NBP_ASSERT_FATAL_FOR_MODULE, NBP_SUCCESS_MESSAGE("module_assert passed"));
    NBP_ASSERT_INT_EQ(get_int(), int_, NBP_ASSERT_FATAL_FOR_MODULE, NBP_FAILURE_MESSAGE("module_assert failed"), NBP_SUCCESS_MESSAGE("module_assert passed"));
}

NBP_TEST(module_assert_int_ne)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_INT_NE(get_int(), int_min, NBP_ASSERT_FATAL_FOR_MODULE);
    NBP_ASSERT_INT_NE(get_int(), int_min, NBP_ASSERT_FATAL_FOR_MODULE, NBP_FAILURE_MESSAGE("module_assert failed"));
    NBP_ASSERT_INT_NE(get_int(), int_min, NBP_ASSERT_FATAL_FOR_MODULE, NBP_SUCCESS_MESSAGE("module_assert passed"));
    NBP_ASSERT_INT_NE(get_int(), int_min, NBP_ASSERT_FATAL_FOR_MODULE, NBP_FAILURE_MESSAGE("module_assert failed"), NBP_SUCCESS_MESSAGE("module_assert passed"));
}

NBP_TEST(module_assert_int_gt)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_INT_GT(get_int(), int_min, NBP_ASSERT_FATAL_FOR_MODULE);
    NBP_ASSERT_INT_GT(get_int(), int_min, NBP_ASSERT_FATAL_FOR_MODULE, NBP_FAILURE_MESSAGE("module_assert failed"));
    NBP_ASSERT_INT_GT(get_int(), int_min, NBP_ASSERT_FATAL_FOR_MODULE, NBP_SUCCESS_MESSAGE("module_assert passed"));
    NBP_ASSERT_INT_GT(get_int(), int_min, NBP_ASSERT_FATAL_FOR_MODULE, NBP_FAILURE_MESSAGE("module_assert failed"), NBP_SUCCESS_MESSAGE("module_assert passed"));
}

NBP_TEST(module_assert_int_ge)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_INT_GE(get_int(), int_min, NBP_ASSERT_FATAL_FOR_MODULE);
    NBP_ASSERT_INT_GE(get_int(), int_, NBP_ASSERT_FATAL_FOR_MODULE, NBP_FAILURE_MESSAGE("module_assert failed"));
    NBP_ASSERT_INT_GE(get_int(), int_min, NBP_ASSERT_FATAL_FOR_MODULE, NBP_SUCCESS_MESSAGE("module_assert passed"));
    NBP_ASSERT_INT_GE(get_int(), int_, NBP_ASSERT_FATAL_FOR_MODULE, NBP_FAILURE_MESSAGE("module_assert failed"), NBP_SUCCESS_MESSAGE("module_assert passed"));
}

NBP_TEST(module_assert_int_lt)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_INT_LT(get_int(), int_max, NBP_ASSERT_FATAL_FOR_MODULE);
    NBP_ASSERT_INT_LT(get_int(), int_max, NBP_ASSERT_FATAL_FOR_MODULE, NBP_FAILURE_MESSAGE("module_assert failed"));
    NBP_ASSERT_INT_LT(get_int(), int_max, NBP_ASSERT_FATAL_FOR_MODULE, NBP_SUCCESS_MESSAGE("module_assert passed"));
    NBP_ASSERT_INT_LT(get_int(), int_max, NBP_ASSERT_FATAL_FOR_MODULE, NBP_FAILURE_MESSAGE("module_assert failed"), NBP_SUCCESS_MESSAGE("module_assert passed"));
}

NBP_TEST(module_assert_int_le)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_INT_LE(get_int(), int_max, NBP_ASSERT_FATAL_FOR_MODULE);
    NBP_ASSERT_INT_LE(get_int(), int_, NBP_ASSERT_FATAL_FOR_MODULE, NBP_FAILURE_MESSAGE("module_assert failed"));
    NBP_ASSERT_INT_LE(get_int(), int_max, NBP_ASSERT_FATAL_FOR_MODULE, NBP_SUCCESS_MESSAGE("module_assert passed"));
    NBP_ASSERT_INT_LE(get_int(), int_, NBP_ASSERT_FATAL_FOR_MODULE, NBP_FAILURE_MESSAGE("module_assert failed"), NBP_SUCCESS_MESSAGE("module_assert passed"));
}

NBP_MODULE(module_assert_int)
{
    NBP_TEST_RUN(module_assert_int_eq);
    NBP_TEST_RUN(module_assert_int_ne);
    NBP_TEST_RUN(module_assert_int_gt);
    NBP_TEST_RUN(module_assert_int_ge);
    NBP_TEST_RUN(module_assert_int_lt);
    NBP_TEST_RUN(module_assert_int_le);
}