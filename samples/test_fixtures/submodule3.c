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

NBP_TEST(test9)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test10)
{
    SAMPLE_SLEEP();
    NBP_CHECK(2);
}

NBP_TEST(test11)
{
    SAMPLE_SLEEP();
    NBP_CHECK(3);
}

NBP_TEST(test12)
{
    SAMPLE_SLEEP();
    NBP_CHECK(4);
}

NBP_MODULE(submodule3)
{
    NBP_TEST_USE_SETUP(submodule3_test_setup1);
    NBP_TEST_RUN(test9);

    NBP_TEST_RESET_SETUP();
    NBP_TEST_RUN(test10);

    NBP_TEST_USE_SETUP(submodule3_test_setup2);
    NBP_TEST_RUN(test11);
    NBP_TEST_RUN(test12);
}
