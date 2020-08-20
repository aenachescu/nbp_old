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

NBP_MODULE_SETUP(module1_setup)
{
    write_message_to_file_2("module setup", "module1");
}

NBP_MODULE_TEARDOWN(module1_teardown)
{
    write_message_to_file_2("module teardown", "module1");
}

NBP_MODULE_SETUP(submodule1_setup)
{
    write_message_to_file_2("module setup", "submodule1");
}

NBP_MODULE_TEARDOWN(submodule1_teardown)
{
    write_message_to_file_2("module teardown", "submodule1");
}

NBP_MODULE_SETUP(submodule4_setup)
{
    write_message_to_file_2("module setup", "submodule4");
}

NBP_MODULE_TEARDOWN(submodule4_teardown)
{
    write_message_to_file_2("module teardown", "submodule4");
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

NBP_TEST_SETUP(test7_setup)
{
    write_message_to_file_2("test setup", "test7");
}

NBP_TEST_TEARDOWN(test7_teardown)
{
    write_message_to_file_2("test teardown", "test7");
}

NBP_TEST_SETUP(test8_setup)
{
    write_message_to_file_2("test setup", "test8");
}

NBP_TEST_TEARDOWN(test8_teardown)
{
    write_message_to_file_2("test teardown", "test8");
}

NBP_TEST_SETUP(test11_setup)
{
    write_message_to_file_2("test setup", "test11");
}

NBP_TEST_TEARDOWN(test11_teardown)
{
    write_message_to_file_2("test teardown", "test11");
}

NBP_TEST_SETUP(test12_setup)
{
    write_message_to_file_2("test setup", "test12");
}

NBP_TEST_TEARDOWN(test12_teardown)
{
    write_message_to_file_2("test teardown", "test12");
}

NBP_TEST_SETUP(test17_setup)
{
    write_message_to_file_2("test setup", "test17");
}

NBP_TEST_TEARDOWN(test17_teardown)
{
    write_message_to_file_2("test teardown", "test17");
}

NBP_TEST_SETUP(test18_setup)
{
    write_message_to_file_2("test setup", "test18");
}

NBP_TEST_TEARDOWN(test18_teardown)
{
    write_message_to_file_2("test teardown", "test18");
}

NBP_TEST_SETUP(test21_setup)
{
    write_message_to_file_2("test setup", "test21");
}

NBP_TEST_TEARDOWN(test21_teardown)
{
    write_message_to_file_2("test teardown", "test21");
}

NBP_TEST_SETUP(test22_setup)
{
    write_message_to_file_2("test setup", "test22");
}

NBP_TEST_TEARDOWN(test22_teardown)
{
    write_message_to_file_2("test teardown", "test22");
}

NBP_MAIN_MODULE_FIXTURES(module_and_test_with_same_name, module_setup, module_teardown)
{
    NBP_TEST_RUN(test1);
    NBP_TEST_RUN(test2);
    NBP_MODULE_RUN(module1);
    NBP_MODULE_RUN(module2);
}

NBP_MODULE_NAME_FIXTURES(module1, "foo", module1_setup, module1_teardown)
{
    NBP_MODULE_RUN(submodule1);
    NBP_TEST_RUN(test3);
    NBP_MODULE_RUN(submodule2);
    NBP_TEST_RUN(test4);
}

NBP_MODULE_FIXTURES(module2, module_setup, module_teardown)
{
    NBP_MODULE_RUN(submodule3);
    NBP_TEST_RUN(test5);
    NBP_MODULE_RUN(submodule4);
    NBP_TEST_RUN(test6);
}

NBP_MODULE_NAME_FIXTURES(submodule1, "foo", submodule1_setup, submodule1_teardown)
{
    NBP_TEST_RUN(test7);
    NBP_TEST_RUN(test8);
    NBP_TEST_RUN(test9);
    NBP_TEST_RUN(test10);
}

NBP_MODULE_FIXTURES(submodule2, module_setup, module_teardown)
{
    NBP_TEST_RUN(test11);
    NBP_TEST_RUN(test12);
    NBP_TEST_RUN(test13);
    NBP_TEST_RUN(test14);
}

NBP_MODULE_FIXTURES(submodule3, module_setup, module_teardown)
{
    NBP_TEST_RUN(test15);
    NBP_TEST_RUN(test16);
    NBP_TEST_RUN(test17);
    NBP_TEST_RUN(test18);
}

NBP_MODULE_NAME_FIXTURES(submodule4, "foo", submodule4_setup, submodule4_teardown)
{
    NBP_TEST_RUN(test19);
    NBP_TEST_RUN(test20);
    NBP_TEST_RUN(test21);
    NBP_TEST_RUN(test22);
}

NBP_TEST_NAME_FIXTURES(test1, "foo", test1_setup, test1_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test1");
}

NBP_TEST_FIXTURES(test2, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test2");
}

NBP_TEST_NAME_FIXTURES(test3, "foo", test3_setup, test3_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test3");
}

NBP_TEST_FIXTURES(test4, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test4");
}

NBP_TEST_FIXTURES(test5, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test5");
}

NBP_TEST_NAME_FIXTURES(test6, "foo", test6_setup, test6_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test6");
}

NBP_TEST_NAME_FIXTURES(test7, "foo", test7_setup, test7_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test7");
}

NBP_TEST_NAME_FIXTURES(test8, "foo", test8_setup, test8_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test8");
}

NBP_TEST_FIXTURES(test9, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test9");
}

NBP_TEST_FIXTURES(test10, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test10");
}

NBP_TEST_NAME_FIXTURES(test11, "foo", test11_setup, test11_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test11");
}

NBP_TEST_NAME_FIXTURES(test12, "foo", test12_setup, test12_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test12");
}

NBP_TEST_FIXTURES(test13, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test13");
}

NBP_TEST_FIXTURES(test14, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test14");
}

NBP_TEST_FIXTURES(test15, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test15");
}

NBP_TEST_FIXTURES(test16, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test16");
}

NBP_TEST_NAME_FIXTURES(test17, "foo", test17_setup, test17_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test17");
}

NBP_TEST_NAME_FIXTURES(test18, "foo", test18_setup, test18_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test18");
}

NBP_TEST_FIXTURES(test19, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test19");
}

NBP_TEST_FIXTURES(test20, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test20");
}

NBP_TEST_NAME_FIXTURES(test21, "foo", test21_setup, test21_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test21");
}

NBP_TEST_NAME_FIXTURES(test22, "foo", test22_setup, test22_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK_PASS_MSG(1 == 1, "test22");
}
