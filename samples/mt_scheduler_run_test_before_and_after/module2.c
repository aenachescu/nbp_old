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
#include "fixtures.h"

extern SAMPLE_ATOMIC_UINT_TYPE test1Value;
extern SAMPLE_ATOMIC_UINT_TYPE test2Value;

extern SAMPLE_ATOMIC_UINT_TYPE module2Value;

NBP_TEST(test11, NBP_TEST_FIXTURES(test11_setup, test11_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test11SetupValue);
    NBP_CHECK_UINT_EQ(value, 3);

    // check teardown values
    NBP_CHECK_UINT_EQ(module2_test1TeardownValue, 1);
    NBP_CHECK_UINT_EQ(module2_test2TeardownValue, 1);

    // check if it is run after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK_UINT_EQ(value, 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK_UINT_EQ(value, 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2Value, 1);
}

NBP_TEST(test12, NBP_TEST_FIXTURES(test12_setup, test12_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test12SetupValue);
    NBP_CHECK_UINT_EQ(value, 3);

    // check if it is run after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK_UINT_EQ(value, 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK_UINT_EQ(value, 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2Value, 1);
}

NBP_TEST(test13, NBP_TEST_FIXTURES(test13_setup, test13_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test13SetupValue);
    NBP_CHECK_UINT_EQ(value, 3);

    // check if it is run after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK_UINT_EQ(value, 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK_UINT_EQ(value, 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2Value, 1);
}

NBP_TEST(test14, NBP_TEST_FIXTURES(test14_setup, test14_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test14SetupValue);
    NBP_CHECK_UINT_EQ(value, 3);

    // check if it is run after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK_UINT_EQ(value, 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK_UINT_EQ(value, 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2Value, 1);
}

NBP_MODULE_FIXTURES(module2, module2_setup, module2_teardown)
{
    NBP_MODULE_RUN(empty_module1);

    NBP_MODULE_RUN(submodule1);

    NBP_TEST_RUN(test11);
    NBP_TEST_RUN(test12);

    NBP_MODULE_RUN(submodule2);

    NBP_TEST_RUN(test13);
    NBP_TEST_RUN(test14);
}

NBP_MODULE_FIXTURES(submodule1, submodule1_setup, submodule1_teardown)
{
    NBP_MODULE_RUN(subsubmodule1);

    NBP_TEST_RUN(test23);
    NBP_TEST_RUN(test24);

    NBP_MODULE_RUN(subsubmodule2);

    NBP_TEST_RUN(test25);
    NBP_TEST_RUN(test26);
}

NBP_MODULE_FIXTURES(submodule2, submodule2_setup, submodule2_teardown)
{
    NBP_MODULE_RUN(subsubmodule3);

    NBP_TEST_RUN(test27);
    NBP_TEST_RUN(test28);

    NBP_MODULE_RUN(subsubmodule4);

    NBP_TEST_RUN(test29);
    NBP_TEST_RUN(test30);
}

NBP_MODULE_FIXTURES(subsubmodule1, subsubmodule1_setup, subsubmodule1_teardown)
{
    NBP_TEST_RUN(test31);
}

NBP_MODULE_FIXTURES(subsubmodule2, subsubmodule2_setup, subsubmodule2_teardown)
{
    NBP_TEST_RUN(test32);
}

NBP_MODULE_FIXTURES(subsubmodule3, subsubmodule3_setup, subsubmodule3_teardown)
{
    NBP_TEST_RUN(test33);
}

NBP_MODULE_FIXTURES(subsubmodule4, subsubmodule4_setup, subsubmodule4_teardown)
{
    NBP_TEST_RUN(test34);
}

NBP_TEST(test23, NBP_TEST_FIXTURES(test23_setup, test23_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test23SetupValue);
    NBP_CHECK_UINT_EQ(value, 4);

    // check if it is run after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK_UINT_EQ(value, 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK_UINT_EQ(value, 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2Value, 1);
}

NBP_TEST(test24, NBP_TEST_FIXTURES(test24_setup, test24_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test24SetupValue);
    NBP_CHECK_UINT_EQ(value, 4);

    // check if it is run after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK_UINT_EQ(value, 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK_UINT_EQ(value, 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2Value, 1);
}

NBP_TEST(test25, NBP_TEST_FIXTURES(test25_setup, test25_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test25SetupValue);
    NBP_CHECK_UINT_EQ(value, 4);

    // check if it is run after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK_UINT_EQ(value, 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK_UINT_EQ(value, 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2Value, 1);
}

NBP_TEST(test26, NBP_TEST_FIXTURES(test26_setup, test26_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test26SetupValue);
    NBP_CHECK_UINT_EQ(value, 4);

    // check if it is run after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK_UINT_EQ(value, 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK_UINT_EQ(value, 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2Value, 1);
}

NBP_TEST(test27, NBP_TEST_FIXTURES(test27_setup, test27_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test27SetupValue);
    NBP_CHECK_UINT_EQ(value, 4);

    // check if it is run after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK_UINT_EQ(value, 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK_UINT_EQ(value, 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2Value, 1);
}

NBP_TEST(test28, NBP_TEST_FIXTURES(test28_setup, test28_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test28SetupValue);
    NBP_CHECK_UINT_EQ(value, 4);

    // check if it is run after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK_UINT_EQ(value, 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK_UINT_EQ(value, 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2Value, 1);
}

NBP_TEST(test29, NBP_TEST_FIXTURES(test29_setup, test29_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test29SetupValue);
    NBP_CHECK_UINT_EQ(value, 4);

    // check if it is run after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK_UINT_EQ(value, 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK_UINT_EQ(value, 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2Value, 1);
}

NBP_TEST(test30, NBP_TEST_FIXTURES(test30_setup, test30_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test30SetupValue);
    NBP_CHECK_UINT_EQ(value, 4);

    // check if it is run after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK_UINT_EQ(value, 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK_UINT_EQ(value, 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2Value, 1);
}

NBP_TEST(test31, NBP_TEST_FIXTURES(test31_setup, test31_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test31SetupValue);
    NBP_CHECK_UINT_EQ(value, 5);

    // check if it is run after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK_UINT_EQ(value, 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK_UINT_EQ(value, 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2Value, 1);
}

NBP_TEST(test32, NBP_TEST_FIXTURES(test32_setup, test32_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test32SetupValue);
    NBP_CHECK_UINT_EQ(value, 5);

    // check if it is run after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK_UINT_EQ(value, 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK_UINT_EQ(value, 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2Value, 1);
}

NBP_TEST(test33, NBP_TEST_FIXTURES(test33_setup, test33_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test33SetupValue);
    NBP_CHECK_UINT_EQ(value, 5);

    // check if it is run after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK_UINT_EQ(value, 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK_UINT_EQ(value, 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2Value, 1);
}

NBP_TEST(test34, NBP_TEST_FIXTURES(test34_setup, test34_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test34SetupValue);
    NBP_CHECK_UINT_EQ(value, 5);

    // check if it is run after test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK_UINT_EQ(value, 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK_UINT_EQ(value, 1);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2Value, 1);
}
