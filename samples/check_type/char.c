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

NBP_TEST(check_char_eq)
{
    SAMPLE_SLEEP();
    NBP_CHECK_CHAR_EQ(get_char_b(), char_b);
    NBP_CHECK_CHAR_EQ_FAIL_MSG(get_char_b(), char_b, "check failed");
    NBP_CHECK_CHAR_EQ_PASS_MSG(get_char_b(), char_b, "check passed");
    NBP_CHECK_CHAR_EQ_MSG(get_char_b(), char_b, "check failed", "check passed");
}

NBP_TEST(check_char_ne)
{
    SAMPLE_SLEEP();
    NBP_CHECK_CHAR_NE(get_char_b(), char_a);
    NBP_CHECK_CHAR_NE_FAIL_MSG(get_char_b(), char_a, "check failed");
    NBP_CHECK_CHAR_NE_PASS_MSG(get_char_b(), char_a, "check passed");
    NBP_CHECK_CHAR_NE_MSG(get_char_b(), char_a, "check failed", "check passed");
}

NBP_TEST(check_char_gt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_CHAR_GT(get_char_b(), char_a);
    NBP_CHECK_CHAR_GT_FAIL_MSG(get_char_b(), char_a, "check failed");
    NBP_CHECK_CHAR_GT_PASS_MSG(get_char_b(), char_a, "check passed");
    NBP_CHECK_CHAR_GT_MSG(get_char_b(), char_a, "check failed", "check passed");
}

NBP_TEST(check_char_ge)
{
    SAMPLE_SLEEP();
    NBP_CHECK_CHAR_GE(get_char_b(), char_a);
    NBP_CHECK_CHAR_GE_FAIL_MSG(get_char_b(), char_b, "check failed");
    NBP_CHECK_CHAR_GE_PASS_MSG(get_char_b(), char_a, "check passed");
    NBP_CHECK_CHAR_GE_MSG(get_char_b(), char_b, "check failed", "check passed");
}

NBP_TEST(check_char_lt)
{
    SAMPLE_SLEEP();
    NBP_CHECK_CHAR_LT(get_char_b(), char_c);
    NBP_CHECK_CHAR_LT_FAIL_MSG(get_char_b(), char_c, "check failed");
    NBP_CHECK_CHAR_LT_PASS_MSG(get_char_b(), char_c, "check passed");
    NBP_CHECK_CHAR_LT_MSG(get_char_b(), char_c, "check failed", "check passed");
}

NBP_TEST(check_char_le)
{
    SAMPLE_SLEEP();
    NBP_CHECK_CHAR_LE(get_char_b(), char_c);
    NBP_CHECK_CHAR_LE_FAIL_MSG(get_char_b(), char_b, "check failed");
    NBP_CHECK_CHAR_LE_PASS_MSG(get_char_b(), char_c, "check passed");
    NBP_CHECK_CHAR_LE_MSG(get_char_b(), char_b, "check failed", "check passed");
}

NBP_MODULE(check_char)
{
    NBP_CALL_TEST(check_char_eq);
    NBP_CALL_TEST(check_char_ne);
    NBP_CALL_TEST(check_char_gt);
    NBP_CALL_TEST(check_char_ge);
    NBP_CALL_TEST(check_char_lt);
    NBP_CALL_TEST(check_char_le);
}