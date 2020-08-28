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

short int get_short()
{
    return 2;
}

volatile short int sh_min = SHRT_MIN;
volatile short int sh_max = SHRT_MAX;
volatile short int sh = 2;

NBP_TEST(assert_short_eq)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_SHORT_EQ(get_short(), sh, NBP_ASSERT_FATAL);
    NBP_ASSERT_SHORT_EQ(get_short(), sh, NBP_ASSERT_FATAL, NBP_FAILURE_MESSAGE("assert failed"));
    NBP_ASSERT_SHORT_EQ(get_short(), sh, NBP_ASSERT_FATAL, NBP_SUCCESS_MESSAGE("assert passed"));
    NBP_ASSERT_SHORT_EQ(get_short(), sh, NBP_ASSERT_FATAL, NBP_FAILURE_MESSAGE("assert failed"), NBP_SUCCESS_MESSAGE("assert passed"));
}

NBP_TEST(assert_short_ne)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_SHORT_NE(get_short(), sh_min, NBP_ASSERT_FATAL);
    NBP_ASSERT_SHORT_NE(get_short(), sh_min, NBP_ASSERT_FATAL, NBP_FAILURE_MESSAGE("assert failed"));
    NBP_ASSERT_SHORT_NE(get_short(), sh_min, NBP_ASSERT_FATAL, NBP_SUCCESS_MESSAGE("assert passed"));
    NBP_ASSERT_SHORT_NE(get_short(), sh_min, NBP_ASSERT_FATAL, NBP_FAILURE_MESSAGE("assert failed"), NBP_SUCCESS_MESSAGE("assert passed"));
}

NBP_TEST(assert_short_gt)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_SHORT_GT(get_short(), sh_min, NBP_ASSERT_FATAL);
    NBP_ASSERT_SHORT_GT(get_short(), sh_min, NBP_ASSERT_FATAL, NBP_FAILURE_MESSAGE("assert failed"));
    NBP_ASSERT_SHORT_GT(get_short(), sh_min, NBP_ASSERT_FATAL, NBP_SUCCESS_MESSAGE("assert passed"));
    NBP_ASSERT_SHORT_GT(get_short(), sh_min, NBP_ASSERT_FATAL, NBP_FAILURE_MESSAGE("assert failed"), NBP_SUCCESS_MESSAGE("assert passed"));
}

NBP_TEST(assert_short_ge)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_SHORT_GE(get_short(), sh_min, NBP_ASSERT_FATAL);
    NBP_ASSERT_SHORT_GE(get_short(), sh, NBP_ASSERT_FATAL, NBP_FAILURE_MESSAGE("assert failed"));
    NBP_ASSERT_SHORT_GE(get_short(), sh_min, NBP_ASSERT_FATAL, NBP_SUCCESS_MESSAGE("assert passed"));
    NBP_ASSERT_SHORT_GE(get_short(), sh, NBP_ASSERT_FATAL, NBP_FAILURE_MESSAGE("assert failed"), NBP_SUCCESS_MESSAGE("assert passed"));
}

NBP_TEST(assert_short_lt)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_SHORT_LT(get_short(), sh_max, NBP_ASSERT_FATAL);
    NBP_ASSERT_SHORT_LT(get_short(), sh_max, NBP_ASSERT_FATAL, NBP_FAILURE_MESSAGE("assert failed"));
    NBP_ASSERT_SHORT_LT(get_short(), sh_max, NBP_ASSERT_FATAL, NBP_SUCCESS_MESSAGE("assert passed"));
    NBP_ASSERT_SHORT_LT(get_short(), sh_max, NBP_ASSERT_FATAL, NBP_FAILURE_MESSAGE("assert failed"), NBP_SUCCESS_MESSAGE("assert passed"));
}

NBP_TEST(assert_short_le)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_SHORT_LE(get_short(), sh_max, NBP_ASSERT_FATAL);
    NBP_ASSERT_SHORT_LE(get_short(), sh, NBP_ASSERT_FATAL, NBP_FAILURE_MESSAGE("assert failed"));
    NBP_ASSERT_SHORT_LE(get_short(), sh_max, NBP_ASSERT_FATAL, NBP_SUCCESS_MESSAGE("assert passed"));
    NBP_ASSERT_SHORT_LE(get_short(), sh, NBP_ASSERT_FATAL, NBP_FAILURE_MESSAGE("assert failed"), NBP_SUCCESS_MESSAGE("assert passed"));
}

NBP_MODULE(assert_short)
{
    NBP_TEST_RUN(assert_short_eq);
    NBP_TEST_RUN(assert_short_ne);
    NBP_TEST_RUN(assert_short_gt);
    NBP_TEST_RUN(assert_short_ge);
    NBP_TEST_RUN(assert_short_lt);
    NBP_TEST_RUN(assert_short_le);
}