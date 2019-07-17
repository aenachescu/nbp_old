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

char get_char_b()
{
    return 'b';
}

volatile char char_a = 'a';
volatile char char_b = 'b';
volatile char char_c = 'c';

NBP_TEST(test_assert_char_eq)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_CHAR_EQ(get_char_b(), char_b);
    NBP_TEST_ASSERT_CHAR_EQ_FAIL_MSG(get_char_b(), char_b, "test_assert failed");
    NBP_TEST_ASSERT_CHAR_EQ_PASS_MSG(get_char_b(), char_b, "test_assert passed");
    NBP_TEST_ASSERT_CHAR_EQ_MSG(get_char_b(), char_b, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_char_ne)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_CHAR_NE(get_char_b(), char_a);
    NBP_TEST_ASSERT_CHAR_NE_FAIL_MSG(get_char_b(), char_a, "test_assert failed");
    NBP_TEST_ASSERT_CHAR_NE_PASS_MSG(get_char_b(), char_a, "test_assert passed");
    NBP_TEST_ASSERT_CHAR_NE_MSG(get_char_b(), char_a, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_char_gt)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_CHAR_GT(get_char_b(), char_a);
    NBP_TEST_ASSERT_CHAR_GT_FAIL_MSG(get_char_b(), char_a, "test_assert failed");
    NBP_TEST_ASSERT_CHAR_GT_PASS_MSG(get_char_b(), char_a, "test_assert passed");
    NBP_TEST_ASSERT_CHAR_GT_MSG(get_char_b(), char_a, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_char_ge)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_CHAR_GE(get_char_b(), char_a);
    NBP_TEST_ASSERT_CHAR_GE_FAIL_MSG(get_char_b(), char_b, "test_assert failed");
    NBP_TEST_ASSERT_CHAR_GE_PASS_MSG(get_char_b(), char_a, "test_assert passed");
    NBP_TEST_ASSERT_CHAR_GE_MSG(get_char_b(), char_b, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_char_lt)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_CHAR_LT(get_char_b(), char_c);
    NBP_TEST_ASSERT_CHAR_LT_FAIL_MSG(get_char_b(), char_c, "test_assert failed");
    NBP_TEST_ASSERT_CHAR_LT_PASS_MSG(get_char_b(), char_c, "test_assert passed");
    NBP_TEST_ASSERT_CHAR_LT_MSG(get_char_b(), char_c, "test_assert failed", "test_assert passed");
}

NBP_TEST(test_assert_char_le)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT_CHAR_LE(get_char_b(), char_c);
    NBP_TEST_ASSERT_CHAR_LE_FAIL_MSG(get_char_b(), char_b, "test_assert failed");
    NBP_TEST_ASSERT_CHAR_LE_PASS_MSG(get_char_b(), char_c, "test_assert passed");
    NBP_TEST_ASSERT_CHAR_LE_MSG(get_char_b(), char_b, "test_assert failed", "test_assert passed");
}

NBP_MODULE(test_assert_char)
{
    NBP_CALL_TEST(test_assert_char_eq);
    NBP_CALL_TEST(test_assert_char_ne);
    NBP_CALL_TEST(test_assert_char_gt);
    NBP_CALL_TEST(test_assert_char_ge);
    NBP_CALL_TEST(test_assert_char_lt);
    NBP_CALL_TEST(test_assert_char_le);
}