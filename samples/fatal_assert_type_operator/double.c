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

#include <float.h>

double get_double()
{
    return 1.14;
}

volatile double double_min = DBL_MIN;
volatile double double_max = DBL_MAX;
volatile double double_ = 1.14;

NBP_TEST(fatal_assert_double_eq)
{
    SAMPLE_SLEEP();

    NBP_ASSERT_DOUBLE_EQ(
        get_double(),
        double_,
        NBP_ASSERT_FATAL
    );
    NBP_ASSERT_DOUBLE_EQ(
        get_double(),
        double_,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_FAILURE_MESSAGE("fatal assert failed")
    );
    NBP_ASSERT_DOUBLE_EQ(
        get_double(),
        double_,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_SUCCESS_MESSAGE("fatal assert passed")
    );
    NBP_ASSERT_DOUBLE_EQ(
        get_double(),
        double_,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_FAILURE_MESSAGE("fatal assert failed"),
        NBP_ASSERT_SUCCESS_MESSAGE("fatal assert passed")
    );
}

NBP_TEST(fatal_assert_double_ne)
{
    SAMPLE_SLEEP();

    NBP_ASSERT_DOUBLE_NE(
        get_double(),
        double_min,
        NBP_ASSERT_FATAL
    );
    NBP_ASSERT_DOUBLE_NE(
        get_double(),
        double_min,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_FAILURE_MESSAGE("fatal assert failed")
    );
    NBP_ASSERT_DOUBLE_NE(
        get_double(),
        double_min,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_SUCCESS_MESSAGE("fatal assert passed")
    );
    NBP_ASSERT_DOUBLE_NE(
        get_double(),
        double_min,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_FAILURE_MESSAGE("fatal assert failed"),
        NBP_ASSERT_SUCCESS_MESSAGE("fatal assert passed")
    );
}

NBP_TEST(fatal_assert_double_gt)
{
    SAMPLE_SLEEP();

    NBP_ASSERT_DOUBLE_GT(
        get_double(),
        double_min,
        NBP_ASSERT_FATAL
    );
    NBP_ASSERT_DOUBLE_GT(
        get_double(),
        double_min,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_FAILURE_MESSAGE("fatal assert failed")
    );
    NBP_ASSERT_DOUBLE_GT(
        get_double(),
        double_min,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_SUCCESS_MESSAGE("fatal assert passed")
    );
    NBP_ASSERT_DOUBLE_GT(
        get_double(),
        double_min,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_FAILURE_MESSAGE("fatal assert failed"),
        NBP_ASSERT_SUCCESS_MESSAGE("fatal assert passed")
    );
}

NBP_TEST(fatal_assert_double_ge)
{
    SAMPLE_SLEEP();

    NBP_ASSERT_DOUBLE_GE(
        get_double(),
        double_min,
        NBP_ASSERT_FATAL
    );
    NBP_ASSERT_DOUBLE_GE(
        get_double(),
        double_,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_FAILURE_MESSAGE("fatal assert failed")
    );
    NBP_ASSERT_DOUBLE_GE(
        get_double(),
        double_min,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_SUCCESS_MESSAGE("fatal assert passed")
    );
    NBP_ASSERT_DOUBLE_GE(
        get_double(),
        double_,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_FAILURE_MESSAGE("fatal assert failed"),
        NBP_ASSERT_SUCCESS_MESSAGE("fatal assert passed")
    );
}

NBP_TEST(fatal_assert_double_lt)
{
    SAMPLE_SLEEP();

    NBP_ASSERT_DOUBLE_LT(
        get_double(),
        double_max,
        NBP_ASSERT_FATAL
    );
    NBP_ASSERT_DOUBLE_LT(
        get_double(),
        double_max,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_FAILURE_MESSAGE("fatal assert failed")
    );
    NBP_ASSERT_DOUBLE_LT(
        get_double(),
        double_max,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_SUCCESS_MESSAGE("fatal assert passed")
    );
    NBP_ASSERT_DOUBLE_LT(
        get_double(),
        double_max,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_FAILURE_MESSAGE("fatal assert failed"),
        NBP_ASSERT_SUCCESS_MESSAGE("fatal assert passed")
    );
}

NBP_TEST(fatal_assert_double_le)
{
    SAMPLE_SLEEP();

    NBP_ASSERT_DOUBLE_LE(
        get_double(),
        double_max,
        NBP_ASSERT_FATAL
    );
    NBP_ASSERT_DOUBLE_LE(
        get_double(),
        double_,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_FAILURE_MESSAGE("fatal assert failed")
    );
    NBP_ASSERT_DOUBLE_LE(
        get_double(),
        double_max,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_SUCCESS_MESSAGE("fatal assert passed")
    );
    NBP_ASSERT_DOUBLE_LE(
        get_double(),
        double_,
        NBP_ASSERT_FATAL,
        NBP_ASSERT_FAILURE_MESSAGE("fatal assert failed"),
        NBP_ASSERT_SUCCESS_MESSAGE("fatal assert passed")
    );
}

NBP_MODULE(fatal_assert_double)
{
    NBP_TEST_RUN(fatal_assert_double_eq);
    NBP_TEST_RUN(fatal_assert_double_ne);
    NBP_TEST_RUN(fatal_assert_double_gt);
    NBP_TEST_RUN(fatal_assert_double_ge);
    NBP_TEST_RUN(fatal_assert_double_lt);
    NBP_TEST_RUN(fatal_assert_double_le);
}
