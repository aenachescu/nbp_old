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

extern SAMPLE_ATOMIC_UINT_TYPE test1Value;
extern SAMPLE_ATOMIC_UINT_TYPE test2Value;

extern SAMPLE_ATOMIC_UINT_TYPE module4Value;

NBP_TEST(test19)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);

    SAMPLE_FORCE_SLEEP_MS(1000);
}

NBP_TEST(test20)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);

    SAMPLE_FORCE_SLEEP_MS(1000);
}

NBP_TEST(test21)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);

    SAMPLE_FORCE_SLEEP_MS(1000);
}

NBP_TEST(test22)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);

    SAMPLE_FORCE_SLEEP_MS(1000);
}

NBP_MODULE(module4)
{
    NBP_TEST_USE_TEARDOWN(module4_test_teardown);

    NBP_MODULE_RUN(submodule3);

    NBP_TEST_RUN(test19);
    NBP_TEST_RUN(test20);

    NBP_MODULE_RUN(submodule4);

    NBP_TEST_RUN(test21);
    NBP_TEST_RUN(test22);
}

NBP_MODULE(submodule3)
{
    NBP_TEST_USE_TEARDOWN(module4_test_teardown);

    NBP_MODULE_RUN(subsubmodule5);

    NBP_TEST_RUN(test35);
    NBP_TEST_RUN(test36);

    NBP_MODULE_RUN(subsubmodule6);

    NBP_TEST_RUN(test37);
    NBP_TEST_RUN(test38);
}

NBP_MODULE(submodule4)
{
    NBP_TEST_USE_TEARDOWN(module4_test_teardown);

    NBP_MODULE_RUN(subsubmodule7);

    NBP_TEST_RUN(test39);
    NBP_TEST_RUN(test40);

    NBP_MODULE_RUN(subsubmodule8);

    NBP_TEST_RUN(test41);
    NBP_TEST_RUN(test42);
}

NBP_MODULE(subsubmodule5)
{
    NBP_TEST_USE_TEARDOWN(module4_test_teardown);
    NBP_TEST_RUN(test43);
}

NBP_MODULE(subsubmodule6)
{
    NBP_TEST_USE_TEARDOWN(module4_test_teardown);
    NBP_TEST_RUN(test44);
}

NBP_MODULE(subsubmodule7)
{
    NBP_TEST_USE_TEARDOWN(module4_test_teardown);
    NBP_TEST_RUN(test45);
}

NBP_MODULE(subsubmodule8)
{
    NBP_TEST_USE_TEARDOWN(module4_test_teardown);
    NBP_TEST_RUN(test46);
}

NBP_TEST(test35)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}

NBP_TEST(test36)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}

NBP_TEST(test37)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}

NBP_TEST(test38)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}

NBP_TEST(test39)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}

NBP_TEST(test40)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}

NBP_TEST(test41)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}

NBP_TEST(test42)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}

NBP_TEST(test43)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}

NBP_TEST(test44)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}

NBP_TEST(test45)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}

NBP_TEST(test46)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}
