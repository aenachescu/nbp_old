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

NBP_TEST_SETUP(submodule3_test_setup1)
{
    write_message_to_file_2(
        "submodule3_test_setup1",
        NBP_TEST_GET_NAME(NBP_TEST_THIS)
    );
}

NBP_TEST_SETUP(submodule3_test_setup2)
{
    write_message_to_file_2(
        "submodule3_test_setup2",
        NBP_TEST_GET_NAME(NBP_TEST_THIS)
    );
}

NBP_TEST_TEARDOWN(submodule4_test_teardown1)
{
    write_message_to_file_2(
        "submodule4_test_teardown1",
        NBP_TEST_GET_NAME(NBP_TEST_THIS)
    );
}

NBP_TEST_TEARDOWN(submodule4_test_teardown2)
{
    write_message_to_file_2(
        "submodule4_test_teardown2",
        NBP_TEST_GET_NAME(NBP_TEST_THIS)
    );
}

NBP_TEST_SETUP(my_test_setup1)
{
    write_message_to_file_2(
        "my_test_setup1",
        NBP_TEST_GET_NAME(NBP_TEST_THIS)
    );
}

NBP_TEST_SETUP(my_test_setup2)
{
    write_message_to_file_2(
        "my_test_setup2",
        NBP_TEST_GET_NAME(NBP_TEST_THIS)
    );
}

NBP_TEST_SETUP(my_test_setup3)
{
    write_message_to_file_2(
        "my_test_setup3",
        NBP_TEST_GET_NAME(NBP_TEST_THIS)
    );
}

NBP_TEST_TEARDOWN(my_test_teardown1)
{
    write_message_to_file_2(
        "my_test_teardown1",
        NBP_TEST_GET_NAME(NBP_TEST_THIS)
    );
}

NBP_TEST_TEARDOWN(my_test_teardown2)
{
    write_message_to_file_2(
        "my_test_teardown2",
        NBP_TEST_GET_NAME(NBP_TEST_THIS)
    );
}

NBP_TEST_TEARDOWN(my_test_teardown3)
{
    write_message_to_file_2(
        "my_test_teardown3",
        NBP_TEST_GET_NAME(NBP_TEST_THIS)
    );
}

NBP_MAIN_MODULE(test_fixtures_one_file)
{
    NBP_MODULE_RUN(module1);
    NBP_MODULE_RUN(module2);
    NBP_MODULE_RUN(module3);
}

NBP_MODULE(module1)
{
    NBP_MODULE_RUN(submodule1);
    NBP_MODULE_RUN(submodule2);
}

NBP_MODULE(module2)
{
    NBP_MODULE_RUN(submodule3);
    NBP_MODULE_RUN(submodule4);
}

NBP_MODULE(module3)
{
    NBP_MODULE_RUN(submodule5);
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

NBP_MODULE(submodule1)
{
    NBP_TEST_USE_SETUP(my_test_setup1);
    NBP_TEST_USE_TEARDOWN(my_test_teardown1);

    NBP_TEST_RUN(test1);
    NBP_TEST_RUN(test2);

    NBP_TEST_USE_SETUP(my_test_setup2);
    NBP_TEST_USE_TEARDOWN(my_test_teardown2);

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

NBP_MODULE(submodule2)
{
    NBP_TEST_USE_SETUP(my_test_setup1);
    NBP_TEST_USE_TEARDOWN(my_test_teardown1);

    NBP_TEST_RUN(test5);
    NBP_TEST_RUN(test6);

    NBP_TEST_RESET_SETUP();
    NBP_TEST_RESET_TEARDOWN();

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

NBP_MODULE(submodule4)
{
    NBP_TEST_USE_TEARDOWN(submodule4_test_teardown1);
    NBP_TEST_RUN(test13);

    NBP_TEST_RESET_TEARDOWN();
    NBP_TEST_RUN(test14);

    NBP_TEST_USE_TEARDOWN(submodule4_test_teardown2);
    NBP_TEST_RUN(test15);
    NBP_TEST_RUN(test16);
}

NBP_TEST(test17, NBP_TEST_FIXTURES(my_test_setup3, my_test_teardown3))
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_TEST(test18, NBP_TEST_SETUP(my_test_setup3))
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_TEST(test19, NBP_TEST_TEARDOWN(my_test_teardown3))
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_TEST(test20)
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_TEST(test21, NBP_TEST_NAME("test21"),
    NBP_TEST_FIXTURES(my_test_setup3, my_test_teardown3))
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_TEST(test22, NBP_TEST_NAME("test22"), NBP_TEST_SETUP(my_test_setup3))
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_TEST(test23, NBP_TEST_NAME("test23"), NBP_TEST_TEARDOWN(my_test_teardown3))
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_TEST(test24, NBP_TEST_NAME("test24"))
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1);
}

NBP_MODULE(submodule5)
{
    NBP_TEST_USE_SETUP(my_test_setup2);
    NBP_TEST_USE_TEARDOWN(my_test_teardown2);

    NBP_TEST_RUN(test17);
    NBP_TEST_RUN(test18);
    NBP_TEST_RUN(test19);
    NBP_TEST_RUN(test20);

    NBP_TEST_RESET_SETUP();
    NBP_TEST_RESET_TEARDOWN();

    NBP_TEST_RUN(test21);
    NBP_TEST_RUN(test22);
    NBP_TEST_RUN(test23);
    NBP_TEST_RUN(test24);
}
