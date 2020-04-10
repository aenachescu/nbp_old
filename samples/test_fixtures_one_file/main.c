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
        NBP_GET_TEST_NAME(NBP_THIS_TEST)
    );
}

NBP_TEST_SETUP(submodule3_test_setup2)
{
    write_message_to_file_2(
        "submodule3_test_setup2",
        NBP_GET_TEST_NAME(NBP_THIS_TEST)
    );
}

NBP_TEST_TEARDOWN(submodule4_test_teardown1)
{
    write_message_to_file_2(
        "submodule4_test_teardown1",
        NBP_GET_TEST_NAME(NBP_THIS_TEST)
    );
}

NBP_TEST_TEARDOWN(submodule4_test_teardown2)
{
    write_message_to_file_2(
        "submodule4_test_teardown2",
        NBP_GET_TEST_NAME(NBP_THIS_TEST)
    );
}

NBP_TEST_SETUP(my_test_setup1)
{
    write_message_to_file_2(
        "my_test_setup1",
        NBP_GET_TEST_NAME(NBP_THIS_TEST)
    );
}

NBP_TEST_SETUP(my_test_setup2)
{
    write_message_to_file_2(
        "my_test_setup2",
        NBP_GET_TEST_NAME(NBP_THIS_TEST)
    );
}

NBP_TEST_TEARDOWN(my_test_teardown1)
{
    write_message_to_file_2(
        "my_test_teardown1",
        NBP_GET_TEST_NAME(NBP_THIS_TEST)
    );
}

NBP_TEST_TEARDOWN(my_test_teardown2)
{
    write_message_to_file_2(
        "my_test_teardown2",
        NBP_GET_TEST_NAME(NBP_THIS_TEST)
    );
}

NBP_MAIN_MODULE(test_fixtures_one_file_sample)
{
    NBP_CALL_MODULE(module1);
    NBP_CALL_MODULE(module2);
}

NBP_MODULE(module1)
{
    NBP_CALL_MODULE(submodule1);
    NBP_CALL_MODULE(submodule2);
}

NBP_MODULE(module2)
{
    NBP_CALL_MODULE(submodule3);
    NBP_CALL_MODULE(submodule4);
}

NBP_TEST(test1)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test2)
{
    SAMPLE_SLEEP();
    NBP_CHECK(2);
}

NBP_TEST(test3)
{
    SAMPLE_SLEEP();
    NBP_CHECK(3);
}

NBP_TEST(test4)
{
    SAMPLE_SLEEP();
    NBP_CHECK(4);
}

NBP_MODULE(submodule1)
{
    NBP_TEST_USE_SETUP(my_test_setup1);
    NBP_TEST_USE_TEARDOWN(my_test_teardown1);

    NBP_CALL_TEST(test1);
    NBP_CALL_TEST(test2);

    NBP_TEST_USE_SETUP(my_test_setup2);
    NBP_TEST_USE_TEARDOWN(my_test_teardown2);

    NBP_CALL_TEST(test3);
    NBP_CALL_TEST(test4);
}

NBP_TEST(test5)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test6)
{
    SAMPLE_SLEEP();
    NBP_CHECK(2);
}

NBP_TEST(test7)
{
    SAMPLE_SLEEP();
    NBP_CHECK(3);
}

NBP_TEST(test8)
{
    SAMPLE_SLEEP();
    NBP_CHECK(4);
}

NBP_MODULE(submodule2)
{
    NBP_TEST_USE_SETUP(my_test_setup1);
    NBP_TEST_USE_TEARDOWN(my_test_teardown1);

    NBP_CALL_TEST(test5);
    NBP_CALL_TEST(test6);

    NBP_TEST_RESET_SETUP();
    NBP_TEST_RESET_TEARDOWN();

    NBP_CALL_TEST(test7);
    NBP_CALL_TEST(test8);
}

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
    NBP_CALL_TEST(test9);

    NBP_TEST_RESET_SETUP();
    NBP_CALL_TEST(test10);

    NBP_TEST_USE_SETUP(submodule3_test_setup2);
    NBP_CALL_TEST(test11);
    NBP_CALL_TEST(test12);
}

NBP_TEST(test13)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test14)
{
    SAMPLE_SLEEP();
    NBP_CHECK(2);
}

NBP_TEST(test15)
{
    SAMPLE_SLEEP();
    NBP_CHECK(3);
}

NBP_TEST(test16)
{
    SAMPLE_SLEEP();
    NBP_CHECK(4);
}

NBP_MODULE(submodule4)
{
    NBP_TEST_USE_TEARDOWN(submodule4_test_teardown1);
    NBP_CALL_TEST(test13);

    NBP_TEST_RESET_TEARDOWN();
    NBP_CALL_TEST(test14);

    NBP_TEST_USE_TEARDOWN(submodule4_test_teardown2);
    NBP_CALL_TEST(test15);
    NBP_CALL_TEST(test16);
}