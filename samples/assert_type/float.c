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

float get_float()
{
    return 1.14f;
}

volatile float float_min = FLT_MIN;
volatile float float_max = FLT_MAX;
volatile float float_ = 1.14f;

NBP_TEST(assert_float_eq)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_FLOAT_EQ(get_float(), float_);
    NBP_ASSERT_FLOAT_EQ_FAIL_MSG(get_float(), float_, "assert failed");
    NBP_ASSERT_FLOAT_EQ_PASS_MSG(get_float(), float_, "assert passed");
    NBP_ASSERT_FLOAT_EQ_MSG(get_float(), float_, "assert failed", "assert passed");
}

NBP_TEST(assert_float_ne)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_FLOAT_NE(get_float(), float_min);
    NBP_ASSERT_FLOAT_NE_FAIL_MSG(get_float(), float_min, "assert failed");
    NBP_ASSERT_FLOAT_NE_PASS_MSG(get_float(), float_min, "assert passed");
    NBP_ASSERT_FLOAT_NE_MSG(get_float(), float_min, "assert failed", "assert passed");
}

NBP_TEST(assert_float_gt)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_FLOAT_GT(get_float(), float_min);
    NBP_ASSERT_FLOAT_GT_FAIL_MSG(get_float(), float_min, "assert failed");
    NBP_ASSERT_FLOAT_GT_PASS_MSG(get_float(), float_min, "assert passed");
    NBP_ASSERT_FLOAT_GT_MSG(get_float(), float_min, "assert failed", "assert passed");
}

NBP_TEST(assert_float_ge)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_FLOAT_GE(get_float(), float_min);
    NBP_ASSERT_FLOAT_GE_FAIL_MSG(get_float(), float_, "assert failed");
    NBP_ASSERT_FLOAT_GE_PASS_MSG(get_float(), float_min, "assert passed");
    NBP_ASSERT_FLOAT_GE_MSG(get_float(), float_, "assert failed", "assert passed");
}

NBP_TEST(assert_float_lt)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_FLOAT_LT(get_float(), float_max);
    NBP_ASSERT_FLOAT_LT_FAIL_MSG(get_float(), float_max, "assert failed");
    NBP_ASSERT_FLOAT_LT_PASS_MSG(get_float(), float_max, "assert passed");
    NBP_ASSERT_FLOAT_LT_MSG(get_float(), float_max, "assert failed", "assert passed");
}

NBP_TEST(assert_float_le)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_FLOAT_LE(get_float(), float_max);
    NBP_ASSERT_FLOAT_LE_FAIL_MSG(get_float(), float_, "assert failed");
    NBP_ASSERT_FLOAT_LE_PASS_MSG(get_float(), float_max, "assert passed");
    NBP_ASSERT_FLOAT_LE_MSG(get_float(), float_, "assert failed", "assert passed");
}

NBP_MODULE(assert_float)
{
    NBP_CALL_TEST(assert_float_eq);
    NBP_CALL_TEST(assert_float_ne);
    NBP_CALL_TEST(assert_float_gt);
    NBP_CALL_TEST(assert_float_ge);
    NBP_CALL_TEST(assert_float_lt);
    NBP_CALL_TEST(assert_float_le);
}