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

#define NBP_LIBRARY_MAIN
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

NBP_TEST(check_operator_eq)
{
    SAMPLE_SLEEP();
    NBP_CHECK_EQ(get_int(), int_);
    NBP_CHECK_EQ_FAIL_MSG(get_int(), int_, "check failed");
    NBP_CHECK_EQ_PASS_MSG(get_int(), int_, "check passed");
    NBP_CHECK_EQ_MSG(get_int(), int_, "check failed", "check passed");
}

NBP_TEST(check_operator_ne)
{
    SAMPLE_SLEEP();
    NBP_CHECK_NE(get_int(), int_min);
    NBP_CHECK_NE_FAIL_MSG(get_int(), int_min, "check failed");
    NBP_CHECK_NE_PASS_MSG(get_int(), int_min, "check passed");
    NBP_CHECK_NE_MSG(get_int(), int_min, "check failed", "check passed");
}

NBP_TEST(check_operator_gt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_GT(get_int(), int_min);
    NBP_CHECK_GT_FAIL_MSG(get_int(), int_min, "check failed");
    NBP_CHECK_GT_PASS_MSG(get_int(), int_min, "check passed");
    NBP_CHECK_GT_MSG(get_int(), int_min, "check failed", "check passed");
}

NBP_TEST(check_operator_ge)
{
    SAMPLE_SLEEP();
    NBP_CHECK_GE(get_int(), int_min);
    NBP_CHECK_GE_FAIL_MSG(get_int(), int_, "check failed");
    NBP_CHECK_GE_PASS_MSG(get_int(), int_min, "check passed");
    NBP_CHECK_GE_MSG(get_int(), int_, "check failed", "check passed");
}

NBP_TEST(check_operator_lt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_LT(get_int(), int_max);
    NBP_CHECK_LT_FAIL_MSG(get_int(), int_max, "check failed");
    NBP_CHECK_LT_PASS_MSG(get_int(), int_max, "check passed");
    NBP_CHECK_LT_MSG(get_int(), int_max, "check failed", "check passed");
}

NBP_TEST(check_operator_le)
{
    SAMPLE_SLEEP();
    NBP_CHECK_LE(get_int(), int_max);
    NBP_CHECK_LE_FAIL_MSG(get_int(), int_, "check failed");
    NBP_CHECK_LE_PASS_MSG(get_int(), INT_MAX, "check passed");
    NBP_CHECK_LE_MSG(get_int(), int_, "check failed", "check passed");
}

NBP_MAIN_MODULE(check_operator)
{
    NBP_CALL_TEST(check_operator_eq);
    NBP_CALL_TEST(check_operator_ne);
    NBP_CALL_TEST(check_operator_gt);
    NBP_CALL_TEST(check_operator_ge);
    NBP_CALL_TEST(check_operator_lt);
    NBP_CALL_TEST(check_operator_le);
}