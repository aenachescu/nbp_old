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

#include <limits.h>

int get_int()
{
    return 2;
}

#define MY_INT_MAX 0x7fffffff

volatile int int_min = INT_MIN;
volatile int int_max = INT_MAX;
volatile int int_ = 2;

NBP_TEST(module_assert_operator_eq)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_EQ(get_int(), int_);
    NBP_MODULE_ASSERT_EQ_FAIL_MSG(get_int(), int_, "module_assert failed");
    NBP_MODULE_ASSERT_EQ_PASS_MSG(get_int(), int_, "module_assert passed");
    NBP_MODULE_ASSERT_EQ_MSG(get_int(), int_, "module_assert failed", "module_assert passed");
}

NBP_TEST(module_assert_operator_ne)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_NE(get_int(), int_min);
    NBP_MODULE_ASSERT_NE_FAIL_MSG(get_int(), int_min, "module_assert failed");
    NBP_MODULE_ASSERT_NE_PASS_MSG(get_int(), int_min, "module_assert passed");
    NBP_MODULE_ASSERT_NE_MSG(get_int(), int_min, "module_assert failed", "module_assert passed");
}

NBP_TEST(module_assert_operator_gt)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_GT(get_int(), int_min);
    NBP_MODULE_ASSERT_GT_FAIL_MSG(get_int(), int_min, "module_assert failed");
    NBP_MODULE_ASSERT_GT_PASS_MSG(get_int(), int_min, "module_assert passed");
    NBP_MODULE_ASSERT_GT_MSG(get_int(), int_min, "module_assert failed", "module_assert passed");
}

NBP_TEST(module_assert_operator_ge)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_GE(get_int(), int_min);
    NBP_MODULE_ASSERT_GE_FAIL_MSG(get_int(), int_, "module_assert failed");
    NBP_MODULE_ASSERT_GE_PASS_MSG(get_int(), int_min, "module_assert passed");
    NBP_MODULE_ASSERT_GE_MSG(get_int(), int_, "module_assert failed", "module_assert passed");
}

NBP_TEST(module_assert_operator_lt)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_LT(get_int(), int_max);
    NBP_MODULE_ASSERT_LT_FAIL_MSG(get_int(), int_max, "module_assert failed");
    NBP_MODULE_ASSERT_LT_PASS_MSG(get_int(), int_max, "module_assert passed");
    NBP_MODULE_ASSERT_LT_MSG(get_int(), int_max, "module_assert failed", "module_assert passed");
}

NBP_TEST(module_assert_operator_le)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_LE(get_int(), int_max);
    NBP_MODULE_ASSERT_LE_FAIL_MSG(get_int(), int_, "module_assert failed");
    NBP_MODULE_ASSERT_LE_PASS_MSG(get_int(), MY_INT_MAX, "module_assert passed");
    NBP_MODULE_ASSERT_LE_MSG(get_int(), int_, "module_assert failed", "module_assert passed");
}

NBP_MAIN_MODULE(module_assert_operator)
{
    NBP_TEST_RUN(module_assert_operator_eq);
    NBP_TEST_RUN(module_assert_operator_ne);
    NBP_TEST_RUN(module_assert_operator_gt);
    NBP_TEST_RUN(module_assert_operator_ge);
    NBP_TEST_RUN(module_assert_operator_lt);
    NBP_TEST_RUN(module_assert_operator_le);
}