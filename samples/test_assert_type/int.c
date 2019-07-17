/*
No Bugs in Production (NBP)
Copyright (C) 2019-present Alin Enachescu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
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

NBP_TEST(test_assert_int_eq)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_INT_EQ(get_int(), int_);
    NBP_TEST_ASSERT_INT_EQ_FAIL_MSG(get_int(), int_, "test_assert failed");
    NBP_TEST_ASSERT_INT_EQ_PASS_MSG(get_int(), int_, "test_assert passed");
    NBP_TEST_ASSERT_INT_EQ_MSG(get_int(), int_, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_int_ne)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_INT_NE(get_int(), int_min);
    NBP_TEST_ASSERT_INT_NE_FAIL_MSG(get_int(), int_min, "test_assert failed");
    NBP_TEST_ASSERT_INT_NE_PASS_MSG(get_int(), int_min, "test_assert passed");
    NBP_TEST_ASSERT_INT_NE_MSG(get_int(), int_min, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_int_gt)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_INT_GT(get_int(), int_min);
    NBP_TEST_ASSERT_INT_GT_FAIL_MSG(get_int(), int_min, "test_assert failed");
    NBP_TEST_ASSERT_INT_GT_PASS_MSG(get_int(), int_min, "test_assert passed");
    NBP_TEST_ASSERT_INT_GT_MSG(get_int(), int_min, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_int_ge)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_INT_GE(get_int(), int_min);
    NBP_TEST_ASSERT_INT_GE_FAIL_MSG(get_int(), int_, "test_assert failed");
    NBP_TEST_ASSERT_INT_GE_PASS_MSG(get_int(), int_min, "test_assert passed");
    NBP_TEST_ASSERT_INT_GE_MSG(get_int(), int_, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_int_lt)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_INT_LT(get_int(), int_max);
    NBP_TEST_ASSERT_INT_LT_FAIL_MSG(get_int(), int_max, "test_assert failed");
    NBP_TEST_ASSERT_INT_LT_PASS_MSG(get_int(), int_max, "test_assert passed");
    NBP_TEST_ASSERT_INT_LT_MSG(get_int(), int_max, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_int_le)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_INT_LE(get_int(), int_max);
    NBP_TEST_ASSERT_INT_LE_FAIL_MSG(get_int(), int_, "test_assert failed");
    NBP_TEST_ASSERT_INT_LE_PASS_MSG(get_int(), int_max, "test_assert passed");
    NBP_TEST_ASSERT_INT_LE_MSG(get_int(), int_, "test_assert failed", "test_assert passed");
}

NBP_MODULE(test_assert_int)
{
    NBP_CALL_TEST(test_assert_int_eq);
    NBP_CALL_TEST(test_assert_int_ne);
    NBP_CALL_TEST(test_assert_int_gt);
    NBP_CALL_TEST(test_assert_int_ge);
    NBP_CALL_TEST(test_assert_int_lt);
    NBP_CALL_TEST(test_assert_int_le);
}