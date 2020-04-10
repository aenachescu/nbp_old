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

NBP_MAIN_MODULE(check_sample)
{
    NBP_CALL_TEST(test1);
    NBP_CALL_MODULE(module1);
    NBP_CALL_TEST(test2);
    NBP_CALL_MODULE(module2);
    NBP_CALL_TEST(test3);
}

NBP_MODULE(module1)
{
    NBP_CALL_MODULE(submodule1);
    NBP_CALL_TEST(test4);
    NBP_CALL_MODULE(submodule2);
}

NBP_MODULE(module2)
{
    NBP_CALL_TEST(test5);
    NBP_CALL_MODULE(submodule3);
    NBP_CALL_MODULE(submodule4);
    NBP_CALL_TEST(test6);
}

NBP_MODULE(submodule1)
{
    NBP_CALL_TEST(test7);
    NBP_CALL_TEST(test8);
    NBP_CALL_TEST(test9);
    NBP_CALL_TEST(test10);
}

NBP_MODULE(submodule2)
{
    NBP_CALL_TEST(test11);
    NBP_CALL_TEST(test12);
    NBP_CALL_TEST(test13);
    NBP_CALL_TEST(test14);
}

NBP_MODULE(submodule3)
{
    NBP_CALL_TEST(test15);
    NBP_CALL_TEST(test16);
    NBP_CALL_TEST(test17);
    NBP_CALL_TEST(test18);
}

NBP_MODULE(submodule4)
{
    NBP_CALL_TEST(test19);
    NBP_CALL_TEST(test20);
    NBP_CALL_TEST(test21);
    NBP_CALL_TEST(test22);
}

NBP_TEST(test1)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
    NBP_CHECK_MSG(1 == 1, "fail message", "pass message");
    NBP_CHECK_PASS_MSG(2 == 2, "whoaaa");
}

NBP_TEST(test2)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
    NBP_CHECK_FAIL_MSG(1 == 1, "it should not be printed");
    NBP_CHECK_PASS_MSG(2 == 2, "best best best");
}

NBP_TEST(test3)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test4)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
    NBP_CHECK_MSG(1 != 1, "failed :(", "passed :)");
}

NBP_TEST(test5)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
    NBP_CHECK_PASS_MSG(1 == 1, "qwe");
    NBP_CHECK_PASS_MSG(2 == 2, "asd");
    NBP_CHECK_PASS_MSG(3 == 3, "zxc");
    NBP_CHECK_FAIL_MSG(4 != 4, "pff");
    NBP_CHECK_PASS_MSG(5 == 5, "rty");
    NBP_CHECK_PASS_MSG(6 == 6, "fgh");
}

NBP_TEST(test6)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
    NBP_CHECK_FAIL_MSG(1 == 4, "pff");
}

NBP_TEST(test7)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
    NBP_CHECK(1 != 1);
    NBP_CHECK(2 == 2);
    NBP_CHECK_PASS_MSG(3 == 3, "pass msg");
}

NBP_TEST(test8)
{
    int a = 0, b = 1, c = 2, d = 2;
    SAMPLE_SLEEP();
    NBP_CHECK(1);
    NBP_CHECK(a == b);
    NBP_CHECK_PASS_MSG(c == d, "peeeerfect");
}

NBP_TEST(test9)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test10)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test11)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test12)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test13)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test14)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test15)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test16)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test17)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test18)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

int func1()
{
    return 1;
}

int func2(int b)
{
    return b;
}

NBP_TEST(test19)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
    NBP_CHECK(func1() == func2(2));
}

NBP_TEST(test20)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
    NBP_CHECK_MSG(func2(1) == func2(1), "fail", "pass");
    NBP_CHECK_MSG(func2(2) == func2(1), "fail", "pass");
}

NBP_TEST(test21)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test22)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}