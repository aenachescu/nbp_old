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

extern SAMPLE_ATOMIC_UINT_TYPE module4Value;

NBP_TEST(test19, NBP_TEST_FIXTURES(test19_setup, test19_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test19SetupValue);
    NBP_ASSERT_UINT_EQ(value, 3);

    // check if it is run before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    SAMPLE_FORCE_SLEEP_MS(100);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4Value, 1);
}

NBP_TEST(test20, NBP_TEST_FIXTURES(test20_setup, test20_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test20SetupValue);
    NBP_ASSERT_UINT_EQ(value, 3);

    // check if it is run before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    SAMPLE_FORCE_SLEEP_MS(100);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4Value, 1);
}

NBP_TEST(test21, NBP_TEST_FIXTURES(test21_setup, test21_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test21SetupValue);
    NBP_ASSERT_UINT_EQ(value, 3);

    // check if it is run before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    SAMPLE_FORCE_SLEEP_MS(100);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4Value, 1);
}

NBP_TEST(test22, NBP_TEST_FIXTURES(test22_setup, test22_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test22SetupValue);
    NBP_ASSERT_UINT_EQ(value, 3);

    // check if it is run before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    SAMPLE_FORCE_SLEEP_MS(100);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4Value, 1);
}

NBP_MODULE(module4, NBP_MODULE_FIXTURES(module4_setup, module4_teardown))
{
    NBP_MODULE_RUN(empty_module2);

    NBP_MODULE_RUN(submodule3);

    NBP_TEST_RUN(test19);
    NBP_TEST_RUN(test20);

    NBP_MODULE_RUN(submodule4);

    NBP_TEST_RUN(test21);
    NBP_TEST_RUN(test22);
}

NBP_MODULE(submodule3,
    NBP_MODULE_FIXTURES(submodule3_setup, submodule3_teardown))
{
    NBP_MODULE_RUN(subsubmodule5);

    NBP_TEST_RUN(test35);
    NBP_TEST_RUN(test36);

    NBP_MODULE_RUN(subsubmodule6);

    NBP_TEST_RUN(test37);
    NBP_TEST_RUN(test38);
}

NBP_MODULE(submodule4,
    NBP_MODULE_FIXTURES(submodule4_setup, submodule4_teardown))
{
    NBP_MODULE_RUN(subsubmodule7);

    NBP_TEST_RUN(test39);
    NBP_TEST_RUN(test40);

    NBP_MODULE_RUN(subsubmodule8);

    NBP_TEST_RUN(test41);
    NBP_TEST_RUN(test42);
}

NBP_MODULE(subsubmodule5,
    NBP_MODULE_FIXTURES(subsubmodule5_setup, subsubmodule5_teardown))
{
    NBP_TEST_RUN(test43);
}

NBP_MODULE(subsubmodule6,
    NBP_MODULE_FIXTURES(subsubmodule6_setup, subsubmodule6_teardown))
{
    NBP_TEST_RUN(test44);
}

NBP_MODULE(subsubmodule7,
    NBP_MODULE_FIXTURES(subsubmodule7_setup, subsubmodule7_teardown))
{
    NBP_TEST_RUN(test45);
}

NBP_MODULE(subsubmodule8,
    NBP_MODULE_FIXTURES(subsubmodule8_setup, subsubmodule8_teardown))
{
    NBP_TEST_RUN(test46);
}

NBP_TEST(test35, NBP_TEST_FIXTURES(test35_setup, test35_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test35SetupValue);
    NBP_ASSERT_UINT_EQ(value, 4);

    // check if it is run before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4Value, 1);
}

NBP_TEST(test36, NBP_TEST_FIXTURES(test36_setup, test36_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test36SetupValue);
    NBP_ASSERT_UINT_EQ(value, 4);

    // check if it is run before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4Value, 1);
}

NBP_TEST(test37, NBP_TEST_FIXTURES(test37_setup, test37_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test37SetupValue);
    NBP_ASSERT_UINT_EQ(value, 4);

    // check if it is run before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4Value, 1);
}

NBP_TEST(test38, NBP_TEST_FIXTURES(test38_setup, test38_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test38SetupValue);
    NBP_ASSERT_UINT_EQ(value, 4);

    // check if it is run before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4Value, 1);
}

NBP_TEST(test39, NBP_TEST_FIXTURES(test39_setup, test39_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test39SetupValue);
    NBP_ASSERT_UINT_EQ(value, 4);

    // check if it is run before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4Value, 1);
}

NBP_TEST(test40, NBP_TEST_FIXTURES(test40_setup, test40_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test40SetupValue);
    NBP_ASSERT_UINT_EQ(value, 4);

    // check if it is run before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4Value, 1);
}

NBP_TEST(test41, NBP_TEST_FIXTURES(test41_setup, test41_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test41SetupValue);
    NBP_ASSERT_UINT_EQ(value, 4);

    // check if it is run before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4Value, 1);
}

NBP_TEST(test42, NBP_TEST_FIXTURES(test42_setup, test42_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test42SetupValue);
    NBP_ASSERT_UINT_EQ(value, 4);

    // check if it is run before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4Value, 1);
}

NBP_TEST(test43, NBP_TEST_FIXTURES(test43_setup, test43_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test43SetupValue);
    NBP_ASSERT_UINT_EQ(value, 5);

    // check if it is run before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4Value, 1);
}

NBP_TEST(test44, NBP_TEST_FIXTURES(test44_setup, test44_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test44SetupValue);
    NBP_ASSERT_UINT_EQ(value, 5);

    // check if it is run before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4Value, 1);
}

NBP_TEST(test45, NBP_TEST_FIXTURES(test45_setup, test45_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test45SetupValue);
    NBP_ASSERT_UINT_EQ(value, 5);

    // check if it is run before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4Value, 1);
}

NBP_TEST(test46, NBP_TEST_FIXTURES(test46_setup, test46_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test46SetupValue);
    NBP_ASSERT_UINT_EQ(value, 5);

    // check if it is run before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4Value, 1);
}
