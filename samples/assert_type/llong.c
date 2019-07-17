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

long long int get_llong()
{
    return 2LL;
}

volatile long long int llong_min = LLONG_MIN;
volatile long long int llong_max = LLONG_MAX;
volatile long long int llong_ = 2LL;

NBP_TEST(assert_llong_eq)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_LLONG_EQ(get_llong(), llong_);
    NBP_ASSERT_LLONG_EQ_FAIL_MSG(get_llong(), llong_, "assert failed");
    NBP_ASSERT_LLONG_EQ_PASS_MSG(get_llong(), llong_, "assert passed");
    NBP_ASSERT_LLONG_EQ_MSG(get_llong(), llong_, "assert failed", "assert passed");
}

NBP_TEST(assert_llong_ne)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_LLONG_NE(get_llong(), llong_min);
    NBP_ASSERT_LLONG_NE_FAIL_MSG(get_llong(), llong_min, "assert failed");
    NBP_ASSERT_LLONG_NE_PASS_MSG(get_llong(), llong_min, "assert passed");
    NBP_ASSERT_LLONG_NE_MSG(get_llong(), llong_min, "assert failed", "assert passed");
}

NBP_TEST(assert_llong_gt)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_LLONG_GT(get_llong(), llong_min);
    NBP_ASSERT_LLONG_GT_FAIL_MSG(get_llong(), llong_min, "assert failed");
    NBP_ASSERT_LLONG_GT_PASS_MSG(get_llong(), llong_min, "assert passed");
    NBP_ASSERT_LLONG_GT_MSG(get_llong(), llong_min, "assert failed", "assert passed");
}

NBP_TEST(assert_llong_ge)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_LLONG_GE(get_llong(), llong_min);
    NBP_ASSERT_LLONG_GE_FAIL_MSG(get_llong(), llong_, "assert failed");
    NBP_ASSERT_LLONG_GE_PASS_MSG(get_llong(), llong_min, "assert passed");
    NBP_ASSERT_LLONG_GE_MSG(get_llong(), llong_, "assert failed", "assert passed");
}

NBP_TEST(assert_llong_lt)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_LLONG_LT(get_llong(), llong_max);
    NBP_ASSERT_LLONG_LT_FAIL_MSG(get_llong(), llong_max, "assert failed");
    NBP_ASSERT_LLONG_LT_PASS_MSG(get_llong(), llong_max, "assert passed");
    NBP_ASSERT_LLONG_LT_MSG(get_llong(), llong_max, "assert failed", "assert passed");
}

NBP_TEST(assert_llong_le)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_LLONG_LE(get_llong(), llong_max);
    NBP_ASSERT_LLONG_LE_FAIL_MSG(get_llong(), llong_, "assert failed");
    NBP_ASSERT_LLONG_LE_PASS_MSG(get_llong(), llong_max, "assert passed");
    NBP_ASSERT_LLONG_LE_MSG(get_llong(), llong_, "assert failed", "assert passed");
}

NBP_MODULE(assert_llong)
{
    NBP_CALL_TEST(assert_llong_eq);
    NBP_CALL_TEST(assert_llong_ne);
    NBP_CALL_TEST(assert_llong_gt);
    NBP_CALL_TEST(assert_llong_ge);
    NBP_CALL_TEST(assert_llong_lt);
    NBP_CALL_TEST(assert_llong_le);
}