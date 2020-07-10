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
extern SAMPLE_ATOMIC_UINT_TYPE test3Value;
extern SAMPLE_ATOMIC_UINT_TYPE test4Value;
extern SAMPLE_ATOMIC_UINT_TYPE test5Value;
extern SAMPLE_ATOMIC_UINT_TYPE test6Value;

extern SAMPLE_ATOMIC_UINT_TYPE module1Value;
extern SAMPLE_ATOMIC_UINT_TYPE module2Value;
extern SAMPLE_ATOMIC_UINT_TYPE module3Value;
extern SAMPLE_ATOMIC_UINT_TYPE module4Value;

NBP_TEST_TEARDOWN(test1_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test1Value, 1);
}

NBP_TEST_TEARDOWN(test2_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test2Value, 1);
}

NBP_TEST_TEARDOWN(test3_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test3Value, 1);
}

NBP_TEST_TEARDOWN(test4_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test4Value, 1);
}

NBP_TEST_TEARDOWN(test5_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test5Value, 1);
}

NBP_TEST_TEARDOWN(test6_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test6Value, 1);
}

NBP_TEST_TEARDOWN(module1_test_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module1Value, 1);
}

NBP_TEST_TEARDOWN(module2_test_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2Value, 1);
}

NBP_TEST_TEARDOWN(module3_test_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module3Value, 1);
}

NBP_TEST_TEARDOWN(module4_test_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4Value, 1);
}
