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

unsigned long long int get_ullong()
{
    return 2ULL;
}

volatile unsigned long long int ullong_min = 0;
volatile unsigned long long int ullong_max = ULLONG_MAX;
volatile unsigned long long int ullong_ = 2ULL;

NBP_TEST(check_ullong_eq)
{
    SAMPLE_SLEEP();
    NBP_CHECK_ULLONG_EQ(get_ullong(), ullong_);
    NBP_CHECK_ULLONG_EQ_FAIL_MSG(get_ullong(), ullong_, "check failed");
    NBP_CHECK_ULLONG_EQ_PASS_MSG(get_ullong(), ullong_, "check passed");
    NBP_CHECK_ULLONG_EQ_MSG(get_ullong(), ullong_, "check failed", "check passed");
}

NBP_TEST(check_ullong_ne)
{
    SAMPLE_SLEEP();
    NBP_CHECK_ULLONG_NE(get_ullong(), ullong_min);
    NBP_CHECK_ULLONG_NE_FAIL_MSG(get_ullong(), ullong_min, "check failed");
    NBP_CHECK_ULLONG_NE_PASS_MSG(get_ullong(), ullong_min, "check passed");
    NBP_CHECK_ULLONG_NE_MSG(get_ullong(), ullong_min, "check failed", "check passed");
}

NBP_TEST(check_ullong_gt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_ULLONG_GT(get_ullong(), ullong_min);
    NBP_CHECK_ULLONG_GT_FAIL_MSG(get_ullong(), ullong_min, "check failed");
    NBP_CHECK_ULLONG_GT_PASS_MSG(get_ullong(), ullong_min, "check passed");
    NBP_CHECK_ULLONG_GT_MSG(get_ullong(), ullong_min, "check failed", "check passed");
}

NBP_TEST(check_ullong_ge)
{
    SAMPLE_SLEEP();
    NBP_CHECK_ULLONG_GE(get_ullong(), ullong_min);
    NBP_CHECK_ULLONG_GE_FAIL_MSG(get_ullong(), ullong_, "check failed");
    NBP_CHECK_ULLONG_GE_PASS_MSG(get_ullong(), ullong_min, "check passed");
    NBP_CHECK_ULLONG_GE_MSG(get_ullong(), ullong_, "check failed", "check passed");
}

NBP_TEST(check_ullong_lt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_ULLONG_LT(get_ullong(), ullong_max);
    NBP_CHECK_ULLONG_LT_FAIL_MSG(get_ullong(), ullong_max, "check failed");
    NBP_CHECK_ULLONG_LT_PASS_MSG(get_ullong(), ullong_max, "check passed");
    NBP_CHECK_ULLONG_LT_MSG(get_ullong(), ullong_max, "check failed", "check passed");
}

NBP_TEST(check_ullong_le)
{
    SAMPLE_SLEEP();
    NBP_CHECK_ULLONG_LE(get_ullong(), ullong_max);
    NBP_CHECK_ULLONG_LE_FAIL_MSG(get_ullong(), ullong_, "check failed");
    NBP_CHECK_ULLONG_LE_PASS_MSG(get_ullong(), ullong_max, "check passed");
    NBP_CHECK_ULLONG_LE_MSG(get_ullong(), ullong_, "check failed", "check passed");
}

NBP_MODULE(check_ullong)
{
    NBP_CALL_TEST(check_ullong_eq);
    NBP_CALL_TEST(check_ullong_ne);
    NBP_CALL_TEST(check_ullong_gt);
    NBP_CALL_TEST(check_ullong_ge);
    NBP_CALL_TEST(check_ullong_lt);
    NBP_CALL_TEST(check_ullong_le);
}