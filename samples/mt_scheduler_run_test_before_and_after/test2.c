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

extern SAMPLE_ATOMIC_UINT_TYPE test2Value;
extern SAMPLE_ATOMIC_UINT_TYPE test3Value;
extern SAMPLE_ATOMIC_UINT_TYPE test4Value;
extern SAMPLE_ATOMIC_UINT_TYPE test5Value;
extern SAMPLE_ATOMIC_UINT_TYPE test6Value;

extern SAMPLE_ATOMIC_UINT_TYPE module1Value;
extern SAMPLE_ATOMIC_UINT_TYPE module2Value;
extern SAMPLE_ATOMIC_UINT_TYPE module3Value;
extern SAMPLE_ATOMIC_UINT_TYPE module4Value;

NBP_TEST(test2, NBP_TEST_FIXTURES(test2_setup, test2_teardown))
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check setup values
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2SetupValue);
    NBP_ASSERT_UINT_EQ(value, 2);

    // check teardown values
    NBP_ASSERT_UINT_EQ(test2_test3TeardownValue, 0);
    NBP_ASSERT_UINT_EQ(test2_test4TeardownValue, 0);
    NBP_ASSERT_UINT_EQ(test2_test5TeardownValue, 1);
    NBP_ASSERT_UINT_EQ(test2_test6TeardownValue, 1);

    NBP_ASSERT_UINT_EQ(test2_module1TeardownValue, 0);
    NBP_ASSERT_UINT_EQ(test2_module2TeardownValue, 0);
    NBP_ASSERT_UINT_EQ(test2_module3TeardownValue, 5);
    NBP_ASSERT_UINT_EQ(test2_module4TeardownValue, 23);

    // check if it is run before test3 and test4
    value = SAMPLE_ATOMIC_UINT_LOAD(&test3Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test4Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    // check if it is run after test5 and test6
    value = SAMPLE_ATOMIC_UINT_LOAD(&test5Value);
    NBP_ASSERT_UINT_EQ(value, 1);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test6Value);
    NBP_ASSERT_UINT_EQ(value, 1);

    // check if it is run before module1 and module2
    value = SAMPLE_ATOMIC_UINT_LOAD(&module1Value);
    NBP_ASSERT_UINT_EQ(value, 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&module2Value);
    NBP_ASSERT_UINT_EQ(value, 0);

    // check if it is run after module3 and module4
    value = SAMPLE_ATOMIC_UINT_LOAD(&module3Value);
    NBP_ASSERT_UINT_EQ(value, 4);
    value = SAMPLE_ATOMIC_UINT_LOAD(&module4Value);
    NBP_ASSERT_UINT_EQ(value, 16);

    SAMPLE_FORCE_SLEEP_MS(100);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test2Value, 1);
}
