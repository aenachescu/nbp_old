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

unsigned long int get_ulong()
{
    return 2UL;
}

volatile unsigned long int ulong_min = 0;
volatile unsigned long int ulong_max = ULONG_MAX;
volatile unsigned long int ulong_ = 2UL;

NBP_TEST(module_assert_ulong_eq)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_ULONG_EQ(get_ulong(), ulong_);
    NBP_MODULE_ASSERT_ULONG_EQ_FAIL_MSG(get_ulong(), ulong_, "module_assert failed");
    NBP_MODULE_ASSERT_ULONG_EQ_PASS_MSG(get_ulong(), ulong_, "module_assert passed");
    NBP_MODULE_ASSERT_ULONG_EQ_MSG(get_ulong(), ulong_, "module_assert failed", "module_assert passed");
}

NBP_TEST(module_assert_ulong_ne)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_ULONG_NE(get_ulong(), ulong_min);
    NBP_MODULE_ASSERT_ULONG_NE_FAIL_MSG(get_ulong(), ulong_min, "module_assert failed");
    NBP_MODULE_ASSERT_ULONG_NE_PASS_MSG(get_ulong(), ulong_min, "module_assert passed");
    NBP_MODULE_ASSERT_ULONG_NE_MSG(get_ulong(), ulong_min, "module_assert failed", "module_assert passed");
}

NBP_TEST(module_assert_ulong_gt)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_ULONG_GT(get_ulong(), ulong_min);
    NBP_MODULE_ASSERT_ULONG_GT_FAIL_MSG(get_ulong(), ulong_min, "module_assert failed");
    NBP_MODULE_ASSERT_ULONG_GT_PASS_MSG(get_ulong(), ulong_min, "module_assert passed");
    NBP_MODULE_ASSERT_ULONG_GT_MSG(get_ulong(), ulong_min, "module_assert failed", "module_assert passed");
}

NBP_TEST(module_assert_ulong_ge)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_ULONG_GE(get_ulong(), ulong_min);
    NBP_MODULE_ASSERT_ULONG_GE_FAIL_MSG(get_ulong(), ulong_, "module_assert failed");
    NBP_MODULE_ASSERT_ULONG_GE_PASS_MSG(get_ulong(), ulong_min, "module_assert passed");
    NBP_MODULE_ASSERT_ULONG_GE_MSG(get_ulong(), ulong_, "module_assert failed", "module_assert passed");
}

NBP_TEST(module_assert_ulong_lt)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_ULONG_LT(get_ulong(), ulong_max);
    NBP_MODULE_ASSERT_ULONG_LT_FAIL_MSG(get_ulong(), ulong_max, "module_assert failed");
    NBP_MODULE_ASSERT_ULONG_LT_PASS_MSG(get_ulong(), ulong_max, "module_assert passed");
    NBP_MODULE_ASSERT_ULONG_LT_MSG(get_ulong(), ulong_max, "module_assert failed", "module_assert passed");
}

NBP_TEST(module_assert_ulong_le)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT_ULONG_LE(get_ulong(), ulong_max);
    NBP_MODULE_ASSERT_ULONG_LE_FAIL_MSG(get_ulong(), ulong_, "module_assert failed");
    NBP_MODULE_ASSERT_ULONG_LE_PASS_MSG(get_ulong(), ulong_max, "module_assert passed");
    NBP_MODULE_ASSERT_ULONG_LE_MSG(get_ulong(), ulong_, "module_assert failed", "module_assert passed");
}

NBP_MODULE(module_assert_ulong)
{
    NBP_CALL_TEST(module_assert_ulong_eq);
    NBP_CALL_TEST(module_assert_ulong_ne);
    NBP_CALL_TEST(module_assert_ulong_gt);
    NBP_CALL_TEST(module_assert_ulong_ge);
    NBP_CALL_TEST(module_assert_ulong_lt);
    NBP_CALL_TEST(module_assert_ulong_le);
}