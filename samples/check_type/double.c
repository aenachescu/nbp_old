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

#include <float.h>

double get_double()
{
    return 1.14;
}

volatile double double_min = DBL_MIN;
volatile double double_max = DBL_MAX;
volatile double double_ = 1.14;

NBP_TEST(check_double_eq)
{
    SAMPLE_SLEEP();
    NBP_CHECK_DOUBLE_EQ(get_double(), double_);
    NBP_CHECK_DOUBLE_EQ_FAIL_MSG(get_double(), double_, "check failed");
    NBP_CHECK_DOUBLE_EQ_PASS_MSG(get_double(), double_, "check passed");
    NBP_CHECK_DOUBLE_EQ_MSG(get_double(), double_, "check failed", "check passed");
}

NBP_TEST(check_double_ne)
{
    SAMPLE_SLEEP();
    NBP_CHECK_DOUBLE_NE(get_double(), double_min);
    NBP_CHECK_DOUBLE_NE_FAIL_MSG(get_double(), double_min, "check failed");
    NBP_CHECK_DOUBLE_NE_PASS_MSG(get_double(), double_min, "check passed");
    NBP_CHECK_DOUBLE_NE_MSG(get_double(), double_min, "check failed", "check passed");
}

NBP_TEST(check_double_gt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_DOUBLE_GT(get_double(), double_min);
    NBP_CHECK_DOUBLE_GT_FAIL_MSG(get_double(), double_min, "check failed");
    NBP_CHECK_DOUBLE_GT_PASS_MSG(get_double(), double_min, "check passed");
    NBP_CHECK_DOUBLE_GT_MSG(get_double(), double_min, "check failed", "check passed");
}

NBP_TEST(check_double_ge)
{
    SAMPLE_SLEEP();
    NBP_CHECK_DOUBLE_GE(get_double(), double_min);
    NBP_CHECK_DOUBLE_GE_FAIL_MSG(get_double(), double_, "check failed");
    NBP_CHECK_DOUBLE_GE_PASS_MSG(get_double(), double_min, "check passed");
    NBP_CHECK_DOUBLE_GE_MSG(get_double(), double_, "check failed", "check passed");
}

NBP_TEST(check_double_lt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_DOUBLE_LT(get_double(), double_max);
    NBP_CHECK_DOUBLE_LT_FAIL_MSG(get_double(), double_max, "check failed");
    NBP_CHECK_DOUBLE_LT_PASS_MSG(get_double(), double_max, "check passed");
    NBP_CHECK_DOUBLE_LT_MSG(get_double(), double_max, "check failed", "check passed");
}

NBP_TEST(check_double_le)
{
    SAMPLE_SLEEP();
    NBP_CHECK_DOUBLE_LE(get_double(), double_max);
    NBP_CHECK_DOUBLE_LE_FAIL_MSG(get_double(), double_, "check failed");
    NBP_CHECK_DOUBLE_LE_PASS_MSG(get_double(), double_max, "check passed");
    NBP_CHECK_DOUBLE_LE_MSG(get_double(), double_, "check failed", "check passed");
}

NBP_MODULE(check_double)
{
    NBP_CALL_TEST(check_double_eq);
    NBP_CALL_TEST(check_double_ne);
    NBP_CALL_TEST(check_double_gt);
    NBP_CALL_TEST(check_double_ge);
    NBP_CALL_TEST(check_double_lt);
    NBP_CALL_TEST(check_double_le);
}