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

NBP_MODULE_SETUP(module1_setup)
{
    write_message_to_file_2(
        "module1_setup",
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
}

NBP_MODULE_SETUP(module2_setup)
{
    write_message_to_file_2(
        "module2_setup",
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
}

NBP_MODULE_SETUP(module3_setup1)
{
    write_message_to_file_2(
        "module3_setup1",
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
}

NBP_MODULE_SETUP(module3_setup2)
{
    write_message_to_file_2(
        "module3_setup2",
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
}

NBP_MODULE_TEARDOWN(module1_teardown)
{
    write_message_to_file_2(
        "module1_teardown",
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
}

NBP_MODULE_TEARDOWN(module2_teardown)
{
    write_message_to_file_2(
        "module2_teardown",
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
}

NBP_MODULE_TEARDOWN(module3_teardown1)
{
    write_message_to_file_2(
        "module3_teardown1",
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
}

NBP_MODULE_TEARDOWN(module3_teardown2)
{
    write_message_to_file_2(
        "module3_teardown2",
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
}

NBP_MAIN_MODULE(module_fixtures_one_file)
{
    NBP_MODULE_RUN(module1);
    NBP_MODULE_RUN(module2);
    NBP_MODULE_RUN(module3);
}

NBP_MODULE(module1, NBP_MODULE_FIXTURES(module1_setup, module1_teardown))
{
    NBP_MODULE_RUN(submodule1);
    NBP_MODULE_RUN(submodule2);
}

NBP_MODULE(module2, NBP_MODULE_FIXTURES(module2_setup, module2_teardown))
{
    NBP_MODULE_RUN(submodule3);
    NBP_MODULE_RUN(submodule4);
}

NBP_MODULE(module3)
{
    NBP_MODULE_USE_SETUP(module3_setup2);
    NBP_MODULE_USE_TEARDOWN(module3_teardown2);

    NBP_MODULE_RUN(submodule5);
    NBP_MODULE_RUN(submodule6);
    NBP_MODULE_RUN(submodule7);
    NBP_MODULE_RUN(submodule8);

    NBP_MODULE_RESET_SETUP();
    NBP_MODULE_RESET_TEARDOWN();

    NBP_MODULE_RUN(submodule9);
    NBP_MODULE_RUN(submodule10);

    NBP_MODULE_RESET_SETUP();
    NBP_MODULE_RESET_TEARDOWN();

    NBP_MODULE_RUN(submodule11);
    NBP_MODULE_RUN(submodule12);
}

NBP_TEST(test1)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_TEST(test2)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(2);
}

NBP_TEST(test3)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(3);
}

NBP_TEST(test4)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(4);
}

NBP_MODULE(submodule1, NBP_MODULE_FIXTURES(submodule_setup, submodule_teardown))
{
    NBP_TEST_RUN(test1);
    NBP_TEST_RUN(test2);
    NBP_TEST_RUN(test3);
    NBP_TEST_RUN(test4);
}

NBP_TEST(test5)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_TEST(test6)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(2);
}

NBP_TEST(test7)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(3);
}

NBP_TEST(test8)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(4);
}

NBP_MODULE(submodule2, NBP_MODULE_FIXTURES(submodule_setup, submodule_teardown))
{
    NBP_TEST_RUN(test5);
    NBP_TEST_RUN(test6);
    NBP_TEST_RUN(test7);
    NBP_TEST_RUN(test8);
}

NBP_TEST(test9)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_TEST(test10)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(2);
}

NBP_TEST(test11)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(3);
}

NBP_TEST(test12)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(4);
}

NBP_MODULE(submodule3, NBP_MODULE_SETUP(submodule3_setup))
{
    NBP_TEST_RUN(test9);
    NBP_TEST_RUN(test10);
    NBP_TEST_RUN(test11);
    NBP_TEST_RUN(test12);
}

NBP_TEST(test13)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_TEST(test14)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(2);
}

NBP_TEST(test15)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(3);
}

NBP_TEST(test16)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(4);
}

NBP_MODULE(submodule4, NBP_MODULE_TEARDOWN(submodule4_teardown))
{
    NBP_TEST_RUN(test13);
    NBP_TEST_RUN(test14);
    NBP_TEST_RUN(test15);
    NBP_TEST_RUN(test16);
}

NBP_TEST(test17)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_MODULE(submodule5, NBP_MODULE_FIXTURES(module3_setup1, module3_teardown1))
{
    NBP_TEST_RUN(test17);
}

NBP_TEST(test18)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_MODULE(submodule6, NBP_MODULE_SETUP(module3_setup1))
{
    NBP_TEST_RUN(test18);
}

NBP_TEST(test19)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_MODULE(submodule7, NBP_MODULE_TEARDOWN(module3_teardown1))
{
    NBP_TEST_RUN(test19);
}

NBP_TEST(test20)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_MODULE(submodule8)
{
    NBP_TEST_RUN(test20);
}

NBP_TEST(test21)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_MODULE(submodule9, NBP_MODULE_NAME("submodule9"),
    NBP_MODULE_FIXTURES(module3_setup1, module3_teardown1))
{
    NBP_TEST_RUN(test21);
}

NBP_TEST(test22)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_MODULE(submodule10, NBP_MODULE_NAME("submodule10"),
    NBP_MODULE_SETUP(module3_setup1))
{
    NBP_TEST_RUN(test22);
}

NBP_TEST(test23)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_MODULE(submodule11, NBP_MODULE_NAME("submodule11"),
    NBP_MODULE_TEARDOWN(module3_teardown1))
{
    NBP_TEST_RUN(test23);
}

NBP_TEST(test24)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_MODULE(submodule12, NBP_MODULE_NAME("submodule12"))
{
    NBP_TEST_RUN(test24);
}

NBP_MODULE_SETUP(submodule_setup)
{
    write_message_to_file_2(
        "submodule_setup",
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
}

NBP_MODULE_TEARDOWN(submodule_teardown)
{
    write_message_to_file_2(
        "submodule_teardown",
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
}

NBP_MODULE_SETUP(submodule3_setup)
{
    write_message_to_file_2(
        "submodule3_setup",
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
}

NBP_MODULE_TEARDOWN(submodule4_teardown)
{
    write_message_to_file_2(
        "submodule4_teardown",
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
}
