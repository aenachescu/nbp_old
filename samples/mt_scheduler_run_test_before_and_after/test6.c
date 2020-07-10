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

SAMPLE_ATOMIC_UINT_TYPE test1Value;
SAMPLE_ATOMIC_UINT_TYPE test2Value;
SAMPLE_ATOMIC_UINT_TYPE test6Value;

NBP_TEST_FIXTURES(test6, NBP_TEST_NO_SETUP, test6_teardown)
{
    unsigned int value;

    SAMPLE_SLEEP();

    // check if it is ran before test1 and test2
    value = SAMPLE_ATOMIC_UINT_LOAD(&test1Value);
    NBP_CHECK(value == 0);
    value = SAMPLE_ATOMIC_UINT_LOAD(&test2Value);
    NBP_CHECK(value == 0);
}
