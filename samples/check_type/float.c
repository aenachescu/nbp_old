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

#include <float.h>

float get_float()
{
    return 1.14f;
}

volatile float float_min = FLT_MIN;
volatile float float_max = FLT_MAX;
volatile float float_ = 1.14f;

NBP_TEST(check_float_eq)
{
    SAMPLE_SLEEP();
    NBP_CHECK_FLOAT_EQ(get_float(), float_);
    NBP_CHECK_FLOAT_EQ_FAIL_MSG(get_float(), float_, "check failed");
    NBP_CHECK_FLOAT_EQ_PASS_MSG(get_float(), float_, "check passed");
    NBP_CHECK_FLOAT_EQ_MSG(get_float(), float_, "check failed", "check passed");
}

NBP_TEST(check_float_ne)
{
    SAMPLE_SLEEP();
    NBP_CHECK_FLOAT_NE(get_float(), float_min);
    NBP_CHECK_FLOAT_NE_FAIL_MSG(get_float(), float_min, "check failed");
    NBP_CHECK_FLOAT_NE_PASS_MSG(get_float(), float_min, "check passed");
    NBP_CHECK_FLOAT_NE_MSG(get_float(), float_min, "check failed", "check passed");
}

NBP_TEST(check_float_gt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_FLOAT_GT(get_float(), float_min);
    NBP_CHECK_FLOAT_GT_FAIL_MSG(get_float(), float_min, "check failed");
    NBP_CHECK_FLOAT_GT_PASS_MSG(get_float(), float_min, "check passed");
    NBP_CHECK_FLOAT_GT_MSG(get_float(), float_min, "check failed", "check passed");
}

NBP_TEST(check_float_ge)
{
    SAMPLE_SLEEP();
    NBP_CHECK_FLOAT_GE(get_float(), float_min);
    NBP_CHECK_FLOAT_GE_FAIL_MSG(get_float(), float_, "check failed");
    NBP_CHECK_FLOAT_GE_PASS_MSG(get_float(), float_min, "check passed");
    NBP_CHECK_FLOAT_GE_MSG(get_float(), float_, "check failed", "check passed");
}

NBP_TEST(check_float_lt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_FLOAT_LT(get_float(), float_max);
    NBP_CHECK_FLOAT_LT_FAIL_MSG(get_float(), float_max, "check failed");
    NBP_CHECK_FLOAT_LT_PASS_MSG(get_float(), float_max, "check passed");
    NBP_CHECK_FLOAT_LT_MSG(get_float(), float_max, "check failed", "check passed");
}

NBP_TEST(check_float_le)
{
    SAMPLE_SLEEP();
    NBP_CHECK_FLOAT_LE(get_float(), float_max);
    NBP_CHECK_FLOAT_LE_FAIL_MSG(get_float(), float_, "check failed");
    NBP_CHECK_FLOAT_LE_PASS_MSG(get_float(), float_max, "check passed");
    NBP_CHECK_FLOAT_LE_MSG(get_float(), float_, "check failed", "check passed");
}

NBP_MODULE(check_float)
{
    NBP_TEST_RUN(check_float_eq);
    NBP_TEST_RUN(check_float_ne);
    NBP_TEST_RUN(check_float_gt);
    NBP_TEST_RUN(check_float_ge);
    NBP_TEST_RUN(check_float_lt);
    NBP_TEST_RUN(check_float_le);
}