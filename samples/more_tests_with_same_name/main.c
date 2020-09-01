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

NBP_MODULE_SETUP(module_setup)
{
    write_message_to_file_2(
        "module setup",
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
}

NBP_MODULE_TEARDOWN(module_teardown)
{
    write_message_to_file_2(
        "module teardown",
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
}

NBP_TEST_SETUP(test_setup)
{
    write_message_to_file_2("test setup", NBP_TEST_GET_NAME(NBP_TEST_THIS));
}

NBP_TEST_TEARDOWN(test_teardown)
{
    write_message_to_file_2("test teardown", NBP_TEST_GET_NAME(NBP_TEST_THIS));
}

NBP_TEST_SETUP(test1_setup)
{
    write_message_to_file_2("test setup", "test1");
}

NBP_TEST_TEARDOWN(test1_teardown)
{
    write_message_to_file_2("test teardown", "test1");
}

NBP_TEST_SETUP(test3_setup)
{
    write_message_to_file_2("test setup", "test3");
}

NBP_TEST_TEARDOWN(test3_teardown)
{
    write_message_to_file_2("test teardown", "test3");
}

NBP_TEST_SETUP(test6_setup)
{
    write_message_to_file_2("test setup", "test6");
}

NBP_TEST_TEARDOWN(test6_teardown)
{
    write_message_to_file_2("test teardown", "test6");
}

NBP_TEST_SETUP(test8_setup)
{
    write_message_to_file_2("test setup", "test8");
}

NBP_TEST_TEARDOWN(test8_teardown)
{
    write_message_to_file_2("test teardown", "test8");
}

NBP_MAIN_MODULE(more_tests_with_same_name,
    NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_TEST_RUN(test1);
    NBP_TEST_RUN(test2);
    NBP_MODULE_RUN(module1);
    NBP_TEST_RUN(test3);
    NBP_TEST_RUN(test4);
}

NBP_MODULE(module1, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_TEST_RUN(test5);
    NBP_TEST_RUN(test6);
    NBP_TEST_RUN(test7);
    NBP_TEST_RUN(test8);
}

NBP_TEST(test1, NBP_TEST_NAME("test"),
    NBP_TEST_FIXTURES(test1_setup, test1_teardown))
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1 == 1, NBP_ASSERT_SUCCESS_MESSAGE("test1"));
}

NBP_TEST(test2, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1 == 1, NBP_ASSERT_SUCCESS_MESSAGE("test2"));
}

NBP_TEST(test3, NBP_TEST_NAME("test"),
    NBP_TEST_FIXTURES(test3_setup, test3_teardown))
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1 == 1, NBP_ASSERT_SUCCESS_MESSAGE("test3"));
}

NBP_TEST(test4, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1 == 1, NBP_ASSERT_SUCCESS_MESSAGE("test4"));
}

NBP_TEST(test5, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1 == 1, NBP_ASSERT_SUCCESS_MESSAGE("test5"));
}

NBP_TEST(test6, NBP_TEST_NAME("test"),
    NBP_TEST_FIXTURES(test6_setup, test6_teardown))
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1 == 1, NBP_ASSERT_SUCCESS_MESSAGE("test6"));
}

NBP_TEST(test7, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1 == 1, NBP_ASSERT_SUCCESS_MESSAGE("test7"));
}

NBP_TEST(test8, NBP_TEST_NAME("test"),
    NBP_TEST_FIXTURES(test8_setup, test8_teardown))
{
    SAMPLE_SLEEP();
    NBP_ASSERT(1 == 1, NBP_ASSERT_SUCCESS_MESSAGE("test8"));
}
