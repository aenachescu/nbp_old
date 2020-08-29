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

#include <limits.h>

unsigned int get_uint()
{
    return 2U;
}

volatile unsigned int uint_min = 0;
volatile unsigned int uint_max = UINT_MAX;
volatile unsigned int uint_ = 2U;

NBP_TEST(non_fatal_assert_uint_eq)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_UINT_EQ(get_uint(), uint_);
    NBP_ASSERT_UINT_EQ(get_uint(), uint_, NBP_ASSERT_FAILURE_MESSAGE("non fatal assert failed"));
    NBP_ASSERT_UINT_EQ(get_uint(), uint_, NBP_ASSERT_SUCCESS_MESSAGE("non fatal assert passed"));
    NBP_ASSERT_UINT_EQ(get_uint(), uint_, NBP_ASSERT_FAILURE_MESSAGE("non fatal assert failed"), NBP_ASSERT_SUCCESS_MESSAGE("non fatal assert passed"));
}

NBP_TEST(non_fatal_assert_uint_ne)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_UINT_NE(get_uint(), uint_min);
    NBP_ASSERT_UINT_NE(get_uint(), uint_min, NBP_ASSERT_FAILURE_MESSAGE("non fatal assert failed"));
    NBP_ASSERT_UINT_NE(get_uint(), uint_min, NBP_ASSERT_SUCCESS_MESSAGE("non fatal assert passed"));
    NBP_ASSERT_UINT_NE(get_uint(), uint_min, NBP_ASSERT_FAILURE_MESSAGE("non fatal assert failed"), NBP_ASSERT_SUCCESS_MESSAGE("non fatal assert passed"));
}

NBP_TEST(non_fatal_assert_uint_gt)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_UINT_GT(get_uint(), uint_min);
    NBP_ASSERT_UINT_GT(get_uint(), uint_min, NBP_ASSERT_FAILURE_MESSAGE("non fatal assert failed"));
    NBP_ASSERT_UINT_GT(get_uint(), uint_min, NBP_ASSERT_SUCCESS_MESSAGE("non fatal assert passed"));
    NBP_ASSERT_UINT_GT(get_uint(), uint_min, NBP_ASSERT_FAILURE_MESSAGE("non fatal assert failed"), NBP_ASSERT_SUCCESS_MESSAGE("non fatal assert passed"));
}

NBP_TEST(non_fatal_assert_uint_ge)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_UINT_GE(get_uint(), uint_min);
    NBP_ASSERT_UINT_GE(get_uint(), uint_, NBP_ASSERT_FAILURE_MESSAGE("non fatal assert failed"));
    NBP_ASSERT_UINT_GE(get_uint(), uint_min, NBP_ASSERT_SUCCESS_MESSAGE("non fatal assert passed"));
    NBP_ASSERT_UINT_GE(get_uint(), uint_, NBP_ASSERT_FAILURE_MESSAGE("non fatal assert failed"), NBP_ASSERT_SUCCESS_MESSAGE("non fatal assert passed"));
}

NBP_TEST(non_fatal_assert_uint_lt)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_UINT_LT(get_uint(), uint_max);
    NBP_ASSERT_UINT_LT(get_uint(), uint_max, NBP_ASSERT_FAILURE_MESSAGE("non fatal assert failed"));
    NBP_ASSERT_UINT_LT(get_uint(), uint_max, NBP_ASSERT_SUCCESS_MESSAGE("non fatal assert passed"));
    NBP_ASSERT_UINT_LT(get_uint(), uint_max, NBP_ASSERT_FAILURE_MESSAGE("non fatal assert failed"), NBP_ASSERT_SUCCESS_MESSAGE("non fatal assert passed"));
}

NBP_TEST(non_fatal_assert_uint_le)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_UINT_LE(get_uint(), uint_max);
    NBP_ASSERT_UINT_LE(get_uint(), uint_, NBP_ASSERT_FAILURE_MESSAGE("non fatal assert failed"));
    NBP_ASSERT_UINT_LE(get_uint(), uint_max, NBP_ASSERT_SUCCESS_MESSAGE("non fatal assert passed"));
    NBP_ASSERT_UINT_LE(get_uint(), uint_, NBP_ASSERT_FAILURE_MESSAGE("non fatal assert failed"), NBP_ASSERT_SUCCESS_MESSAGE("non fatal assert passed"));
}

NBP_MODULE(non_fatal_assert_uint)
{
    NBP_TEST_RUN(non_fatal_assert_uint_eq);
    NBP_TEST_RUN(non_fatal_assert_uint_ne);
    NBP_TEST_RUN(non_fatal_assert_uint_gt);
    NBP_TEST_RUN(non_fatal_assert_uint_ge);
    NBP_TEST_RUN(non_fatal_assert_uint_lt);
    NBP_TEST_RUN(non_fatal_assert_uint_le);
}