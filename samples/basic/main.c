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

#define NBP_LIBRARY_MAIN
#include <nbp.h>

#include "../sample_utils.h"

NBP_TEST(test_my_add)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 + 1 == 2);
    NBP_CHECK(2 + 2 == 4);
    NBP_CHECK(3 + 3 == 6);
    NBP_CHECK(4 + 4 == 8);
    NBP_CHECK(5 + 5 == 10);
}

NBP_TEST(test_my_sub)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 - 1 == 0);
    NBP_CHECK(2 - 2 == 0);
    NBP_CHECK(3 - 3 == 0);
    NBP_CHECK(4 - 4 == 0);
    NBP_CHECK(5 - 5 == 0);
}

NBP_TEST(test_my_mul)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 * 1 == 1);
    NBP_CHECK(2 * 2 == 4);
    NBP_CHECK(3 * 3 == 9);
    NBP_CHECK(4 * 4 == 16);
    NBP_CHECK(5 * 5 == 25);
}

NBP_TEST(test_my_div)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 / 1 == 1);
    NBP_CHECK(2 / 2 == 1);
    NBP_CHECK(3 / 3 == 1);
    NBP_CHECK(4 / 4 == 1);
    NBP_CHECK(5 / 5 == 1);
}

NBP_MAIN_MODULE(basic_sample)
{
    NBP_CALL_TEST(test_my_add);
    NBP_CALL_TEST(test_my_sub);
    NBP_CALL_TEST(test_my_mul);
    NBP_CALL_TEST(test_my_div);
}
