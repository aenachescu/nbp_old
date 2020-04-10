/*
No Bugs in Production (NBP)
https://github.com/aenachescu/nbp

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2019-2020 Alin Enachescu <https://github.com/aenachescu>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
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