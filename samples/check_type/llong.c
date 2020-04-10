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

long long int get_llong()
{
    return 2LL;
}

volatile long long int llong_min = LLONG_MIN;
volatile long long int llong_max = LLONG_MAX;
volatile long long int llong_ = 2LL;

NBP_TEST(check_llong_eq)
{
    SAMPLE_SLEEP();
    NBP_CHECK_LLONG_EQ(get_llong(), llong_);
    NBP_CHECK_LLONG_EQ_FAIL_MSG(get_llong(), llong_, "check failed");
    NBP_CHECK_LLONG_EQ_PASS_MSG(get_llong(), llong_, "check passed");
    NBP_CHECK_LLONG_EQ_MSG(get_llong(), llong_, "check failed", "check passed");
}

NBP_TEST(check_llong_ne)
{
    SAMPLE_SLEEP();
    NBP_CHECK_LLONG_NE(get_llong(), llong_min);
    NBP_CHECK_LLONG_NE_FAIL_MSG(get_llong(), llong_min, "check failed");
    NBP_CHECK_LLONG_NE_PASS_MSG(get_llong(), llong_min, "check passed");
    NBP_CHECK_LLONG_NE_MSG(get_llong(), llong_min, "check failed", "check passed");
}

NBP_TEST(check_llong_gt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_LLONG_GT(get_llong(), llong_min);
    NBP_CHECK_LLONG_GT_FAIL_MSG(get_llong(), llong_min, "check failed");
    NBP_CHECK_LLONG_GT_PASS_MSG(get_llong(), llong_min, "check passed");
    NBP_CHECK_LLONG_GT_MSG(get_llong(), llong_min, "check failed", "check passed");
}

NBP_TEST(check_llong_ge)
{
    SAMPLE_SLEEP();
    NBP_CHECK_LLONG_GE(get_llong(), llong_min);
    NBP_CHECK_LLONG_GE_FAIL_MSG(get_llong(), llong_, "check failed");
    NBP_CHECK_LLONG_GE_PASS_MSG(get_llong(), llong_min, "check passed");
    NBP_CHECK_LLONG_GE_MSG(get_llong(), llong_, "check failed", "check passed");
}

NBP_TEST(check_llong_lt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_LLONG_LT(get_llong(), llong_max);
    NBP_CHECK_LLONG_LT_FAIL_MSG(get_llong(), llong_max, "check failed");
    NBP_CHECK_LLONG_LT_PASS_MSG(get_llong(), llong_max, "check passed");
    NBP_CHECK_LLONG_LT_MSG(get_llong(), llong_max, "check failed", "check passed");
}

NBP_TEST(check_llong_le)
{
    SAMPLE_SLEEP();
    NBP_CHECK_LLONG_LE(get_llong(), llong_max);
    NBP_CHECK_LLONG_LE_FAIL_MSG(get_llong(), llong_, "check failed");
    NBP_CHECK_LLONG_LE_PASS_MSG(get_llong(), llong_max, "check passed");
    NBP_CHECK_LLONG_LE_MSG(get_llong(), llong_, "check failed", "check passed");
}

NBP_MODULE(check_llong)
{
    NBP_CALL_TEST(check_llong_eq);
    NBP_CALL_TEST(check_llong_ne);
    NBP_CALL_TEST(check_llong_gt);
    NBP_CALL_TEST(check_llong_ge);
    NBP_CALL_TEST(check_llong_lt);
    NBP_CALL_TEST(check_llong_le);
}