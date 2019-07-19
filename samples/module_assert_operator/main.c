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

#define MY_INT_MAX 0x7fffffff

volatile int int_min = INT_MIN;
volatile int int_max = INT_MAX;
volatile int int_ = 2;

NBP_TEST(module_assert_operator_eq)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_EQ(get_int(), int_);
    NBP_MODULE_ASSERT_EQ_FAIL_MSG(get_int(), int_, "module_assert failed");
    NBP_MODULE_ASSERT_EQ_PASS_MSG(get_int(), int_, "module_assert passed");
    NBP_MODULE_ASSERT_EQ_MSG(get_int(), int_, "module_assert failed", "module_assert passed");
}

NBP_TEST(module_assert_operator_ne)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_NE(get_int(), int_min);
    NBP_MODULE_ASSERT_NE_FAIL_MSG(get_int(), int_min, "module_assert failed");
    NBP_MODULE_ASSERT_NE_PASS_MSG(get_int(), int_min, "module_assert passed");
    NBP_MODULE_ASSERT_NE_MSG(get_int(), int_min, "module_assert failed", "module_assert passed");
}

NBP_TEST(module_assert_operator_gt)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_GT(get_int(), int_min);
    NBP_MODULE_ASSERT_GT_FAIL_MSG(get_int(), int_min, "module_assert failed");
    NBP_MODULE_ASSERT_GT_PASS_MSG(get_int(), int_min, "module_assert passed");
    NBP_MODULE_ASSERT_GT_MSG(get_int(), int_min, "module_assert failed", "module_assert passed");
}

NBP_TEST(module_assert_operator_ge)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_GE(get_int(), int_min);
    NBP_MODULE_ASSERT_GE_FAIL_MSG(get_int(), int_, "module_assert failed");
    NBP_MODULE_ASSERT_GE_PASS_MSG(get_int(), int_min, "module_assert passed");
    NBP_MODULE_ASSERT_GE_MSG(get_int(), int_, "module_assert failed", "module_assert passed");
}

NBP_TEST(module_assert_operator_lt)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_LT(get_int(), int_max);
    NBP_MODULE_ASSERT_LT_FAIL_MSG(get_int(), int_max, "module_assert failed");
    NBP_MODULE_ASSERT_LT_PASS_MSG(get_int(), int_max, "module_assert passed");
    NBP_MODULE_ASSERT_LT_MSG(get_int(), int_max, "module_assert failed", "module_assert passed");
}

NBP_TEST(module_assert_operator_le)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_LE(get_int(), int_max);
    NBP_MODULE_ASSERT_LE_FAIL_MSG(get_int(), int_, "module_assert failed");
    NBP_MODULE_ASSERT_LE_PASS_MSG(get_int(), MY_INT_MAX, "module_assert passed");
    NBP_MODULE_ASSERT_LE_MSG(get_int(), int_, "module_assert failed", "module_assert passed");
}

NBP_MAIN_MODULE(module_assert_operator)
{
    NBP_CALL_TEST(module_assert_operator_eq);
    NBP_CALL_TEST(module_assert_operator_ne);
    NBP_CALL_TEST(module_assert_operator_gt);
    NBP_CALL_TEST(module_assert_operator_ge);
    NBP_CALL_TEST(module_assert_operator_lt);
    NBP_CALL_TEST(module_assert_operator_le);
}