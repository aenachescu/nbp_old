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

unsigned long int get_ulong()
{
    return 2UL;
}

volatile unsigned long int ulong_min = 0;
volatile unsigned long int ulong_max = ULONG_MAX;
volatile unsigned long int ulong_ = 2UL;

NBP_TEST(fatal_for_module_assert_ulong_eq)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_ULONG_EQ(get_ulong(), ulong_, NBP_ASSERT_FATAL_FOR_MODULE);
    NBP_ASSERT_ULONG_EQ(get_ulong(), ulong_, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_FAILURE_MESSAGE("fatal for module assert failed"));
    NBP_ASSERT_ULONG_EQ(get_ulong(), ulong_, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_SUCCESS_MESSAGE("fatal for module assert passed"));
    NBP_ASSERT_ULONG_EQ(get_ulong(), ulong_, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_FAILURE_MESSAGE("fatal for module assert failed"), NBP_ASSERT_SUCCESS_MESSAGE("fatal for module assert passed"));
}

NBP_TEST(fatal_for_module_assert_ulong_ne)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_ULONG_NE(get_ulong(), ulong_min, NBP_ASSERT_FATAL_FOR_MODULE);
    NBP_ASSERT_ULONG_NE(get_ulong(), ulong_min, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_FAILURE_MESSAGE("fatal for module assert failed"));
    NBP_ASSERT_ULONG_NE(get_ulong(), ulong_min, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_SUCCESS_MESSAGE("fatal for module assert passed"));
    NBP_ASSERT_ULONG_NE(get_ulong(), ulong_min, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_FAILURE_MESSAGE("fatal for module assert failed"), NBP_ASSERT_SUCCESS_MESSAGE("fatal for module assert passed"));
}

NBP_TEST(fatal_for_module_assert_ulong_gt)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_ULONG_GT(get_ulong(), ulong_min, NBP_ASSERT_FATAL_FOR_MODULE);
    NBP_ASSERT_ULONG_GT(get_ulong(), ulong_min, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_FAILURE_MESSAGE("fatal for module assert failed"));
    NBP_ASSERT_ULONG_GT(get_ulong(), ulong_min, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_SUCCESS_MESSAGE("fatal for module assert passed"));
    NBP_ASSERT_ULONG_GT(get_ulong(), ulong_min, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_FAILURE_MESSAGE("fatal for module assert failed"), NBP_ASSERT_SUCCESS_MESSAGE("fatal for module assert passed"));
}

NBP_TEST(fatal_for_module_assert_ulong_ge)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_ULONG_GE(get_ulong(), ulong_min, NBP_ASSERT_FATAL_FOR_MODULE);
    NBP_ASSERT_ULONG_GE(get_ulong(), ulong_, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_FAILURE_MESSAGE("fatal for module assert failed"));
    NBP_ASSERT_ULONG_GE(get_ulong(), ulong_min, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_SUCCESS_MESSAGE("fatal for module assert passed"));
    NBP_ASSERT_ULONG_GE(get_ulong(), ulong_, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_FAILURE_MESSAGE("fatal for module assert failed"), NBP_ASSERT_SUCCESS_MESSAGE("fatal for module assert passed"));
}

NBP_TEST(fatal_for_module_assert_ulong_lt)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_ULONG_LT(get_ulong(), ulong_max, NBP_ASSERT_FATAL_FOR_MODULE);
    NBP_ASSERT_ULONG_LT(get_ulong(), ulong_max, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_FAILURE_MESSAGE("fatal for module assert failed"));
    NBP_ASSERT_ULONG_LT(get_ulong(), ulong_max, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_SUCCESS_MESSAGE("fatal for module assert passed"));
    NBP_ASSERT_ULONG_LT(get_ulong(), ulong_max, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_FAILURE_MESSAGE("fatal for module assert failed"), NBP_ASSERT_SUCCESS_MESSAGE("fatal for module assert passed"));
}

NBP_TEST(fatal_for_module_assert_ulong_le)
{
    SAMPLE_SLEEP();
    NBP_ASSERT_ULONG_LE(get_ulong(), ulong_max, NBP_ASSERT_FATAL_FOR_MODULE);
    NBP_ASSERT_ULONG_LE(get_ulong(), ulong_, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_FAILURE_MESSAGE("fatal for module assert failed"));
    NBP_ASSERT_ULONG_LE(get_ulong(), ulong_max, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_SUCCESS_MESSAGE("fatal for module assert passed"));
    NBP_ASSERT_ULONG_LE(get_ulong(), ulong_, NBP_ASSERT_FATAL_FOR_MODULE, NBP_ASSERT_FAILURE_MESSAGE("fatal for module assert failed"), NBP_ASSERT_SUCCESS_MESSAGE("fatal for module assert passed"));
}

NBP_MODULE(fatal_for_module_assert_ulong)
{
    NBP_TEST_RUN(fatal_for_module_assert_ulong_eq);
    NBP_TEST_RUN(fatal_for_module_assert_ulong_ne);
    NBP_TEST_RUN(fatal_for_module_assert_ulong_gt);
    NBP_TEST_RUN(fatal_for_module_assert_ulong_ge);
    NBP_TEST_RUN(fatal_for_module_assert_ulong_lt);
    NBP_TEST_RUN(fatal_for_module_assert_ulong_le);
}