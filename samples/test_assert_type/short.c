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

short int get_short()
{
    return 2;
}

volatile short int sh_min = SHRT_MIN;
volatile short int sh_max = SHRT_MAX;
volatile short int sh = 2;

NBP_TEST(test_assert_short_eq)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_SHORT_EQ(get_short(), sh);
    NBP_TEST_ASSERT_SHORT_EQ_FAIL_MSG(get_short(), sh, "test_assert failed");
    NBP_TEST_ASSERT_SHORT_EQ_PASS_MSG(get_short(), sh, "test_assert passed");
    NBP_TEST_ASSERT_SHORT_EQ_MSG(get_short(), sh, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_short_ne)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_SHORT_NE(get_short(), sh_min);
    NBP_TEST_ASSERT_SHORT_NE_FAIL_MSG(get_short(), sh_min, "test_assert failed");
    NBP_TEST_ASSERT_SHORT_NE_PASS_MSG(get_short(), sh_min, "test_assert passed");
    NBP_TEST_ASSERT_SHORT_NE_MSG(get_short(), sh_min, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_short_gt)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_SHORT_GT(get_short(), sh_min);
    NBP_TEST_ASSERT_SHORT_GT_FAIL_MSG(get_short(), sh_min, "test_assert failed");
    NBP_TEST_ASSERT_SHORT_GT_PASS_MSG(get_short(), sh_min, "test_assert passed");
    NBP_TEST_ASSERT_SHORT_GT_MSG(get_short(), sh_min, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_short_ge)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_SHORT_GE(get_short(), sh_min);
    NBP_TEST_ASSERT_SHORT_GE_FAIL_MSG(get_short(), sh, "test_assert failed");
    NBP_TEST_ASSERT_SHORT_GE_PASS_MSG(get_short(), sh_min, "test_assert passed");
    NBP_TEST_ASSERT_SHORT_GE_MSG(get_short(), sh, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_short_lt)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_SHORT_LT(get_short(), sh_max);
    NBP_TEST_ASSERT_SHORT_LT_FAIL_MSG(get_short(), sh_max, "test_assert failed");
    NBP_TEST_ASSERT_SHORT_LT_PASS_MSG(get_short(), sh_max, "test_assert passed");
    NBP_TEST_ASSERT_SHORT_LT_MSG(get_short(), sh_max, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_short_le)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_SHORT_LE(get_short(), sh_max);
    NBP_TEST_ASSERT_SHORT_LE_FAIL_MSG(get_short(), sh, "test_assert failed");
    NBP_TEST_ASSERT_SHORT_LE_PASS_MSG(get_short(), sh_max, "test_assert passed");
    NBP_TEST_ASSERT_SHORT_LE_MSG(get_short(), sh, "test_assert failed", "test_assert passed");
}

NBP_MODULE(test_assert_short)
{
    NBP_CALL_TEST(test_assert_short_eq);
    NBP_CALL_TEST(test_assert_short_ne);
    NBP_CALL_TEST(test_assert_short_gt);
    NBP_CALL_TEST(test_assert_short_ge);
    NBP_CALL_TEST(test_assert_short_lt);
    NBP_CALL_TEST(test_assert_short_le);
}