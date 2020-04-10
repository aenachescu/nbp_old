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

unsigned int get_uint()
{
    return 2U;
}

volatile unsigned int uint_min = 0;
volatile unsigned int uint_max = UINT_MAX;
volatile unsigned int uint_ = 2U;

NBP_TEST(check_uint_eq)
{
    SAMPLE_SLEEP();
    NBP_CHECK_UINT_EQ(get_uint(), uint_);
    NBP_CHECK_UINT_EQ_FAIL_MSG(get_uint(), uint_, "check failed");
    NBP_CHECK_UINT_EQ_PASS_MSG(get_uint(), uint_, "check passed");
    NBP_CHECK_UINT_EQ_MSG(get_uint(), uint_, "check failed", "check passed");
}

NBP_TEST(check_uint_ne)
{
    SAMPLE_SLEEP();
    NBP_CHECK_UINT_NE(get_uint(), uint_min);
    NBP_CHECK_UINT_NE_FAIL_MSG(get_uint(), uint_min, "check failed");
    NBP_CHECK_UINT_NE_PASS_MSG(get_uint(), uint_min, "check passed");
    NBP_CHECK_UINT_NE_MSG(get_uint(), uint_min, "check failed", "check passed");
}

NBP_TEST(check_uint_gt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_UINT_GT(get_uint(), uint_min);
    NBP_CHECK_UINT_GT_FAIL_MSG(get_uint(), uint_min, "check failed");
    NBP_CHECK_UINT_GT_PASS_MSG(get_uint(), uint_min, "check passed");
    NBP_CHECK_UINT_GT_MSG(get_uint(), uint_min, "check failed", "check passed");
}

NBP_TEST(check_uint_ge)
{
    SAMPLE_SLEEP();
    NBP_CHECK_UINT_GE(get_uint(), uint_min);
    NBP_CHECK_UINT_GE_FAIL_MSG(get_uint(), uint_, "check failed");
    NBP_CHECK_UINT_GE_PASS_MSG(get_uint(), uint_min, "check passed");
    NBP_CHECK_UINT_GE_MSG(get_uint(), uint_, "check failed", "check passed");
}

NBP_TEST(check_uint_lt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_UINT_LT(get_uint(), uint_max);
    NBP_CHECK_UINT_LT_FAIL_MSG(get_uint(), uint_max, "check failed");
    NBP_CHECK_UINT_LT_PASS_MSG(get_uint(), uint_max, "check passed");
    NBP_CHECK_UINT_LT_MSG(get_uint(), uint_max, "check failed", "check passed");
}

NBP_TEST(check_uint_le)
{
    SAMPLE_SLEEP();
    NBP_CHECK_UINT_LE(get_uint(), uint_max);
    NBP_CHECK_UINT_LE_FAIL_MSG(get_uint(), uint_, "check failed");
    NBP_CHECK_UINT_LE_PASS_MSG(get_uint(), uint_max, "check passed");
    NBP_CHECK_UINT_LE_MSG(get_uint(), uint_, "check failed", "check passed");
}

NBP_MODULE(check_uint)
{
    NBP_CALL_TEST(check_uint_eq);
    NBP_CALL_TEST(check_uint_ne);
    NBP_CALL_TEST(check_uint_gt);
    NBP_CALL_TEST(check_uint_ge);
    NBP_CALL_TEST(check_uint_lt);
    NBP_CALL_TEST(check_uint_le);
}