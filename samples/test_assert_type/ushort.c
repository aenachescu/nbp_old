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

unsigned short int get_ushort()
{
    return 2;
}

volatile unsigned short int ush_min = 0;
volatile unsigned short int ush_max = USHRT_MAX;
volatile unsigned short int ush = 2;

NBP_TEST(test_assert_ushort_eq)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_USHORT_EQ(get_ushort(), ush);
    NBP_TEST_ASSERT_USHORT_EQ_FAIL_MSG(get_ushort(), ush, "test_assert failed");
    NBP_TEST_ASSERT_USHORT_EQ_PASS_MSG(get_ushort(), ush, "test_assert passed");
    NBP_TEST_ASSERT_USHORT_EQ_MSG(get_ushort(), ush, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_ushort_ne)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_USHORT_NE(get_ushort(), ush_min);
    NBP_TEST_ASSERT_USHORT_NE_FAIL_MSG(get_ushort(), ush_min, "test_assert failed");
    NBP_TEST_ASSERT_USHORT_NE_PASS_MSG(get_ushort(), ush_min, "test_assert passed");
    NBP_TEST_ASSERT_USHORT_NE_MSG(get_ushort(), ush_min, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_ushort_gt)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_USHORT_GT(get_ushort(), ush_min);
    NBP_TEST_ASSERT_USHORT_GT_FAIL_MSG(get_ushort(), ush_min, "test_assert failed");
    NBP_TEST_ASSERT_USHORT_GT_PASS_MSG(get_ushort(), ush_min, "test_assert passed");
    NBP_TEST_ASSERT_USHORT_GT_MSG(get_ushort(), ush_min, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_ushort_ge)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_USHORT_GE(get_ushort(), ush_min);
    NBP_TEST_ASSERT_USHORT_GE_FAIL_MSG(get_ushort(), ush, "test_assert failed");
    NBP_TEST_ASSERT_USHORT_GE_PASS_MSG(get_ushort(), ush_min, "test_assert passed");
    NBP_TEST_ASSERT_USHORT_GE_MSG(get_ushort(), ush, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_ushort_lt)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_USHORT_LT(get_ushort(), ush_max);
    NBP_TEST_ASSERT_USHORT_LT_FAIL_MSG(get_ushort(), ush_max, "test_assert failed");
    NBP_TEST_ASSERT_USHORT_LT_PASS_MSG(get_ushort(), ush_max, "test_assert passed");
    NBP_TEST_ASSERT_USHORT_LT_MSG(get_ushort(), ush_max, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_ushort_le)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_USHORT_LE(get_ushort(), ush_max);
    NBP_TEST_ASSERT_USHORT_LE_FAIL_MSG(get_ushort(), ush, "test_assert failed");
    NBP_TEST_ASSERT_USHORT_LE_PASS_MSG(get_ushort(), ush_max, "test_assert passed");
    NBP_TEST_ASSERT_USHORT_LE_MSG(get_ushort(), ush, "test_assert failed", "test_assert passed");
}

NBP_MODULE(test_assert_ushort)
{
    NBP_CALL_TEST(test_assert_ushort_eq);
    NBP_CALL_TEST(test_assert_ushort_ne);
    NBP_CALL_TEST(test_assert_ushort_gt);
    NBP_CALL_TEST(test_assert_ushort_ge);
    NBP_CALL_TEST(test_assert_ushort_lt);
    NBP_CALL_TEST(test_assert_ushort_le);
}