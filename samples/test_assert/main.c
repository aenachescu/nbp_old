/*
No Bugs in Production (NBP)
Copyright (C) 2019-present Alin Enachescu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#define NBP_LIBRARY_MAIN
#include <nbp.h>

#include "../sample_utils.h"

NBP_MAIN_MODULE(test_assert_sample)
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
    NBP_TEST_ASSERT(1);
    NBP_TEST_ASSERT_MSG(1 == 1, "fail message", "pass message");
    NBP_TEST_ASSERT_PASS_MSG(2 == 2, "whoaaa");
}

NBP_TEST(test2)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
    NBP_TEST_ASSERT_FAIL_MSG(1 == 1, "it should not be printed");
    NBP_TEST_ASSERT_PASS_MSG(2 == 2, "best best best");
}

NBP_TEST(test3)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
}

NBP_TEST(test4)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
    NBP_TEST_ASSERT_MSG(1 != 1, "failed :(", "passed :)");
}

NBP_TEST(test5)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
    NBP_TEST_ASSERT_PASS_MSG(1 == 1, "qwe");
    NBP_TEST_ASSERT_PASS_MSG(2 == 2, "asd");
    NBP_TEST_ASSERT_PASS_MSG(3 == 3, "zxc");
    NBP_TEST_ASSERT_FAIL_MSG(4 != 4, "pff");
    NBP_TEST_ASSERT_PASS_MSG(5 == 5, "rty");
    NBP_TEST_ASSERT_PASS_MSG(6 == 6, "fgh");
}

NBP_TEST(test6)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
    NBP_TEST_ASSERT_FAIL_MSG(1 == 4, "pff");
}

NBP_TEST(test7)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
    NBP_TEST_ASSERT(1 != 1);
    NBP_TEST_ASSERT(2 == 2);
    NBP_TEST_ASSERT_PASS_MSG(3 == 3, "pass msg");
}

NBP_TEST(test8)
{
    int a = 0, b = 1, c = 2, d = 2;
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
    NBP_TEST_ASSERT(a == b);
    NBP_TEST_ASSERT_PASS_MSG(c == d, "peeeerfect");
}

NBP_TEST(test9)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
}

NBP_TEST(test10)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
}

NBP_TEST(test11)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
}

NBP_TEST(test12)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
}

NBP_TEST(test13)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
}

NBP_TEST(test14)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
}

NBP_TEST(test15)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
}

NBP_TEST(test16)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
}

NBP_TEST(test17)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
}

NBP_TEST(test18)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
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
    NBP_TEST_ASSERT(1);
    NBP_TEST_ASSERT(func1() == func2(2));
}

NBP_TEST(test20)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
    NBP_TEST_ASSERT_MSG(func2(1) == func2(1), "fail", "pass");
    NBP_TEST_ASSERT_MSG(func2(2) == func2(1), "fail", "pass");
}

NBP_TEST(test21)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
}

NBP_TEST(test22)
{
    SAMPLE_SLEEP();
    NBP_TEST_ASSERT(1);
}