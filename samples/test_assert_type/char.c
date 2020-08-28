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

NBP_TEST(test_assert_char_eq)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_CHAR_EQ(get_char_b(), char_b, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_CHAR_EQ(get_char_b(), char_b, NBP_ASSERT_FATAL_FOR_TEST, NBP_FAILURE_MESSAGE("test_assert failed"));
    NBP_ASSERT_CHAR_EQ(get_char_b(), char_b, NBP_ASSERT_FATAL_FOR_TEST, NBP_SUCCESS_MESSAGE("test_assert passed"));
    NBP_ASSERT_CHAR_EQ(get_char_b(), char_b, NBP_ASSERT_FATAL_FOR_TEST, NBP_FAILURE_MESSAGE("test_assert failed"), NBP_SUCCESS_MESSAGE("test_assert passed"));
}

NBP_TEST(test_assert_char_ne)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_CHAR_NE(get_char_b(), char_a, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_CHAR_NE(get_char_b(), char_a, NBP_ASSERT_FATAL_FOR_TEST, NBP_FAILURE_MESSAGE("test_assert failed"));
    NBP_ASSERT_CHAR_NE(get_char_b(), char_a, NBP_ASSERT_FATAL_FOR_TEST, NBP_SUCCESS_MESSAGE("test_assert passed"));
    NBP_ASSERT_CHAR_NE(get_char_b(), char_a, NBP_ASSERT_FATAL_FOR_TEST, NBP_FAILURE_MESSAGE("test_assert failed"), NBP_SUCCESS_MESSAGE("test_assert passed"));
}

NBP_TEST(test_assert_char_gt)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_CHAR_GT(get_char_b(), char_a, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_CHAR_GT(get_char_b(), char_a, NBP_ASSERT_FATAL_FOR_TEST, NBP_FAILURE_MESSAGE("test_assert failed"));
    NBP_ASSERT_CHAR_GT(get_char_b(), char_a, NBP_ASSERT_FATAL_FOR_TEST, NBP_SUCCESS_MESSAGE("test_assert passed"));
    NBP_ASSERT_CHAR_GT(get_char_b(), char_a, NBP_ASSERT_FATAL_FOR_TEST, NBP_FAILURE_MESSAGE("test_assert failed"), NBP_SUCCESS_MESSAGE("test_assert passed"));
}

NBP_TEST(test_assert_char_ge)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_CHAR_GE(get_char_b(), char_a, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_CHAR_GE(get_char_b(), char_b, NBP_ASSERT_FATAL_FOR_TEST, NBP_FAILURE_MESSAGE("test_assert failed"));
    NBP_ASSERT_CHAR_GE(get_char_b(), char_a, NBP_ASSERT_FATAL_FOR_TEST, NBP_SUCCESS_MESSAGE("test_assert passed"));
    NBP_ASSERT_CHAR_GE(get_char_b(), char_b, NBP_ASSERT_FATAL_FOR_TEST, NBP_FAILURE_MESSAGE("test_assert failed"), NBP_SUCCESS_MESSAGE("test_assert passed"));
}

NBP_TEST(test_assert_char_lt)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_CHAR_LT(get_char_b(), char_c, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_CHAR_LT(get_char_b(), char_c, NBP_ASSERT_FATAL_FOR_TEST, NBP_FAILURE_MESSAGE("test_assert failed"));
    NBP_ASSERT_CHAR_LT(get_char_b(), char_c, NBP_ASSERT_FATAL_FOR_TEST, NBP_SUCCESS_MESSAGE("test_assert passed"));
    NBP_ASSERT_CHAR_LT(get_char_b(), char_c, NBP_ASSERT_FATAL_FOR_TEST, NBP_FAILURE_MESSAGE("test_assert failed"), NBP_SUCCESS_MESSAGE("test_assert passed"));
}

NBP_TEST(test_assert_char_le)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_CHAR_LE(get_char_b(), char_c, NBP_ASSERT_FATAL_FOR_TEST);
    NBP_ASSERT_CHAR_LE(get_char_b(), char_b, NBP_ASSERT_FATAL_FOR_TEST, NBP_FAILURE_MESSAGE("test_assert failed"));
    NBP_ASSERT_CHAR_LE(get_char_b(), char_c, NBP_ASSERT_FATAL_FOR_TEST, NBP_SUCCESS_MESSAGE("test_assert passed"));
    NBP_ASSERT_CHAR_LE(get_char_b(), char_b, NBP_ASSERT_FATAL_FOR_TEST, NBP_FAILURE_MESSAGE("test_assert failed"), NBP_SUCCESS_MESSAGE("test_assert passed"));
}

NBP_MODULE(test_assert_char)
{
    NBP_TEST_RUN(test_assert_char_eq);
    NBP_TEST_RUN(test_assert_char_ne);
    NBP_TEST_RUN(test_assert_char_gt);
    NBP_TEST_RUN(test_assert_char_ge);
    NBP_TEST_RUN(test_assert_char_lt);
    NBP_TEST_RUN(test_assert_char_le);
}