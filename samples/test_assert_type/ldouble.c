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

long double get_ldouble()
{
    return 1.14L;
}

volatile long double ldouble_min = LDBL_MIN;
volatile long double ldouble_max = LDBL_MAX;
volatile long double ldouble_ = 1.14L;

NBP_TEST(test_assert_ldouble_eq)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_LDOUBLE_EQ(get_ldouble(), ldouble_);
    NBP_TEST_ASSERT_LDOUBLE_EQ_FAIL_MSG(get_ldouble(), ldouble_, "test_assert failed");
    NBP_TEST_ASSERT_LDOUBLE_EQ_PASS_MSG(get_ldouble(), ldouble_, "test_assert passed");
    NBP_TEST_ASSERT_LDOUBLE_EQ_MSG(get_ldouble(), ldouble_, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_ldouble_ne)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_LDOUBLE_NE(get_ldouble(), ldouble_min);
    NBP_TEST_ASSERT_LDOUBLE_NE_FAIL_MSG(get_ldouble(), ldouble_min, "test_assert failed");
    NBP_TEST_ASSERT_LDOUBLE_NE_PASS_MSG(get_ldouble(), ldouble_min, "test_assert passed");
    NBP_TEST_ASSERT_LDOUBLE_NE_MSG(get_ldouble(), ldouble_min, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_ldouble_gt)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_LDOUBLE_GT(get_ldouble(), ldouble_min);
    NBP_TEST_ASSERT_LDOUBLE_GT_FAIL_MSG(get_ldouble(), ldouble_min, "test_assert failed");
    NBP_TEST_ASSERT_LDOUBLE_GT_PASS_MSG(get_ldouble(), ldouble_min, "test_assert passed");
    NBP_TEST_ASSERT_LDOUBLE_GT_MSG(get_ldouble(), ldouble_min, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_ldouble_ge)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_LDOUBLE_GE(get_ldouble(), ldouble_min);
    NBP_TEST_ASSERT_LDOUBLE_GE_FAIL_MSG(get_ldouble(), ldouble_, "test_assert failed");
    NBP_TEST_ASSERT_LDOUBLE_GE_PASS_MSG(get_ldouble(), ldouble_min, "test_assert passed");
    NBP_TEST_ASSERT_LDOUBLE_GE_MSG(get_ldouble(), ldouble_, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_ldouble_lt)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_LDOUBLE_LT(get_ldouble(), ldouble_max);
    NBP_TEST_ASSERT_LDOUBLE_LT_FAIL_MSG(get_ldouble(), ldouble_max, "test_assert failed");
    NBP_TEST_ASSERT_LDOUBLE_LT_PASS_MSG(get_ldouble(), ldouble_max, "test_assert passed");
    NBP_TEST_ASSERT_LDOUBLE_LT_MSG(get_ldouble(), ldouble_max, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_ldouble_le)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_LDOUBLE_LE(get_ldouble(), ldouble_max);
    NBP_TEST_ASSERT_LDOUBLE_LE_FAIL_MSG(get_ldouble(), ldouble_, "test_assert failed");
    NBP_TEST_ASSERT_LDOUBLE_LE_PASS_MSG(get_ldouble(), ldouble_max, "test_assert passed");
    NBP_TEST_ASSERT_LDOUBLE_LE_MSG(get_ldouble(), ldouble_, "test_assert failed", "test_assert passed");
}

NBP_MODULE(test_assert_ldouble)
{
    NBP_CALL_TEST(test_assert_ldouble_eq);
    NBP_CALL_TEST(test_assert_ldouble_ne);
    NBP_CALL_TEST(test_assert_ldouble_gt);
    NBP_CALL_TEST(test_assert_ldouble_ge);
    NBP_CALL_TEST(test_assert_ldouble_lt);
    NBP_CALL_TEST(test_assert_ldouble_le);
}