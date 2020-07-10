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

extern SAMPLE_ATOMIC_UINT_TYPE module3Value;

NBP_TEST(test11)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST(test12)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST(test13)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST(test14)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_MODULE(module2)
{
    NBP_TEST_USE_TEARDOWN(module2_test_teardown);

    NBP_MODULE_RUN(submodule1);

    NBP_TEST_RUN(test11);
    NBP_TEST_RUN(test12);

    NBP_MODULE_RUN(submodule2);

    NBP_TEST_RUN(test13);
    NBP_TEST_RUN(test14);
}

NBP_MODULE(submodule1)
{
    NBP_TEST_USE_TEARDOWN(module2_test_teardown);

    NBP_MODULE_RUN(subsubmodule1);

    NBP_TEST_RUN(test23);
    NBP_TEST_RUN(test24);

    NBP_MODULE_RUN(subsubmodule2);

    NBP_TEST_RUN(test25);
    NBP_TEST_RUN(test26);
}

NBP_MODULE(submodule2)
{
    NBP_TEST_USE_TEARDOWN(module2_test_teardown);

    NBP_MODULE_RUN(subsubmodule3);

    NBP_TEST_RUN(test27);
    NBP_TEST_RUN(test28);

    NBP_MODULE_RUN(subsubmodule4);

    NBP_TEST_RUN(test29);
    NBP_TEST_RUN(test30);
}

NBP_MODULE(subsubmodule1)
{
    NBP_TEST_USE_TEARDOWN(module2_test_teardown);
    NBP_TEST_RUN(test31);
}

NBP_MODULE(subsubmodule2)
{
    NBP_TEST_USE_TEARDOWN(module2_test_teardown);
    NBP_TEST_RUN(test32);
}

NBP_MODULE(subsubmodule3)
{
    NBP_TEST_USE_TEARDOWN(module2_test_teardown);
    NBP_TEST_RUN(test33);
}

NBP_MODULE(subsubmodule4)
{
    NBP_TEST_USE_TEARDOWN(module2_test_teardown);
    NBP_TEST_RUN(test34);
}

NBP_TEST(test23)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST(test24)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST(test25)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST(test26)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST(test27)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST(test28)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST(test29)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST(test30)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST(test31)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST(test32)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST(test33)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}

NBP_TEST(test34)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 1);
}
