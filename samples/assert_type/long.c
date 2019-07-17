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
    NBP_CALL_TEST(assert_long_eq);
    NBP_CALL_TEST(assert_long_ne);
    NBP_CALL_TEST(assert_long_gt);
    NBP_CALL_TEST(assert_long_ge);
    NBP_CALL_TEST(assert_long_lt);
    NBP_CALL_TEST(assert_long_le);
}