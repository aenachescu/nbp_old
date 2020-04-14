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

long int get_long()
{
    return 2L;
}

volatile long int long_min = LONG_MIN;
volatile long int long_max = LONG_MAX;
volatile long int long_ = 2L;

NBP_TEST(assert_long_eq)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_LONG_EQ(get_long(), long_);
    NBP_ASSERT_LONG_EQ_FAIL_MSG(get_long(), long_, "assert failed");
    NBP_ASSERT_LONG_EQ_PASS_MSG(get_long(), long_, "assert passed");
    NBP_ASSERT_LONG_EQ_MSG(get_long(), long_, "assert failed", "assert passed");
}

NBP_TEST(assert_long_ne)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_LONG_NE(get_long(), long_min);
    NBP_ASSERT_LONG_NE_FAIL_MSG(get_long(), long_min, "assert failed");
    NBP_ASSERT_LONG_NE_PASS_MSG(get_long(), long_min, "assert passed");
    NBP_ASSERT_LONG_NE_MSG(get_long(), long_min, "assert failed", "assert passed");
}

NBP_TEST(assert_long_gt)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_LONG_GT(get_long(), long_min);
    NBP_ASSERT_LONG_GT_FAIL_MSG(get_long(), long_min, "assert failed");
    NBP_ASSERT_LONG_GT_PASS_MSG(get_long(), long_min, "assert passed");
    NBP_ASSERT_LONG_GT_MSG(get_long(), long_min, "assert failed", "assert passed");
}

NBP_TEST(assert_long_ge)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_LONG_GE(get_long(), long_min);
    NBP_ASSERT_LONG_GE_FAIL_MSG(get_long(), long_, "assert failed");
    NBP_ASSERT_LONG_GE_PASS_MSG(get_long(), long_min, "assert passed");
    NBP_ASSERT_LONG_GE_MSG(get_long(), long_, "assert failed", "assert passed");
}

NBP_TEST(assert_long_lt)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_LONG_LT(get_long(), long_max);
    NBP_ASSERT_LONG_LT_FAIL_MSG(get_long(), long_max, "assert failed");
    NBP_ASSERT_LONG_LT_PASS_MSG(get_long(), long_max, "assert passed");
    NBP_ASSERT_LONG_LT_MSG(get_long(), long_max, "assert failed", "assert passed");
}

NBP_TEST(assert_long_le)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_LONG_LE(get_long(), long_max);
    NBP_ASSERT_LONG_LE_FAIL_MSG(get_long(), long_, "assert failed");
    NBP_ASSERT_LONG_LE_PASS_MSG(get_long(), long_max, "assert passed");
    NBP_ASSERT_LONG_LE_MSG(get_long(), long_, "assert failed", "assert passed");
}

NBP_MODULE(assert_long)
{
    NBP_TEST_RUN(assert_long_eq);
    NBP_TEST_RUN(assert_long_ne);
    NBP_TEST_RUN(assert_long_gt);
    NBP_TEST_RUN(assert_long_ge);
    NBP_TEST_RUN(assert_long_lt);
    NBP_TEST_RUN(assert_long_le);
}