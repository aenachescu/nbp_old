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

long double get_ldouble()
{
    return 1.14L;
}

volatile long double ldouble_min = LDBL_MIN;
volatile long double ldouble_max = LDBL_MAX;
volatile long double ldouble_ = 1.14L;

NBP_TEST(check_ldouble_eq)
{
    SAMPLE_SLEEP();
    NBP_CHECK_LDOUBLE_EQ(get_ldouble(), ldouble_);
    NBP_CHECK_LDOUBLE_EQ_FAIL_MSG(get_ldouble(), ldouble_, "check failed");
    NBP_CHECK_LDOUBLE_EQ_PASS_MSG(get_ldouble(), ldouble_, "check passed");
    NBP_CHECK_LDOUBLE_EQ_MSG(get_ldouble(), ldouble_, "check failed", "check passed");
}

NBP_TEST(check_ldouble_ne)
{
    SAMPLE_SLEEP();
    NBP_CHECK_LDOUBLE_NE(get_ldouble(), ldouble_min);
    NBP_CHECK_LDOUBLE_NE_FAIL_MSG(get_ldouble(), ldouble_min, "check failed");
    NBP_CHECK_LDOUBLE_NE_PASS_MSG(get_ldouble(), ldouble_min, "check passed");
    NBP_CHECK_LDOUBLE_NE_MSG(get_ldouble(), ldouble_min, "check failed", "check passed");
}

NBP_TEST(check_ldouble_gt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_LDOUBLE_GT(get_ldouble(), ldouble_min);
    NBP_CHECK_LDOUBLE_GT_FAIL_MSG(get_ldouble(), ldouble_min, "check failed");
    NBP_CHECK_LDOUBLE_GT_PASS_MSG(get_ldouble(), ldouble_min, "check passed");
    NBP_CHECK_LDOUBLE_GT_MSG(get_ldouble(), ldouble_min, "check failed", "check passed");
}

NBP_TEST(check_ldouble_ge)
{
    SAMPLE_SLEEP();
    NBP_CHECK_LDOUBLE_GE(get_ldouble(), ldouble_min);
    NBP_CHECK_LDOUBLE_GE_FAIL_MSG(get_ldouble(), ldouble_, "check failed");
    NBP_CHECK_LDOUBLE_GE_PASS_MSG(get_ldouble(), ldouble_min, "check passed");
    NBP_CHECK_LDOUBLE_GE_MSG(get_ldouble(), ldouble_, "check failed", "check passed");
}

NBP_TEST(check_ldouble_lt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_LDOUBLE_LT(get_ldouble(), ldouble_max);
    NBP_CHECK_LDOUBLE_LT_FAIL_MSG(get_ldouble(), ldouble_max, "check failed");
    NBP_CHECK_LDOUBLE_LT_PASS_MSG(get_ldouble(), ldouble_max, "check passed");
    NBP_CHECK_LDOUBLE_LT_MSG(get_ldouble(), ldouble_max, "check failed", "check passed");
}

NBP_TEST(check_ldouble_le)
{
    SAMPLE_SLEEP();
    NBP_CHECK_LDOUBLE_LE(get_ldouble(), ldouble_max);
    NBP_CHECK_LDOUBLE_LE_FAIL_MSG(get_ldouble(), ldouble_, "check failed");
    NBP_CHECK_LDOUBLE_LE_PASS_MSG(get_ldouble(), ldouble_max, "check passed");
    NBP_CHECK_LDOUBLE_LE_MSG(get_ldouble(), ldouble_, "check failed", "check passed");
}

NBP_MODULE(check_ldouble)
{
    NBP_CALL_TEST(check_ldouble_eq);
    NBP_CALL_TEST(check_ldouble_ne);
    NBP_CALL_TEST(check_ldouble_gt);
    NBP_CALL_TEST(check_ldouble_ge);
    NBP_CALL_TEST(check_ldouble_lt);
    NBP_CALL_TEST(check_ldouble_le);
}