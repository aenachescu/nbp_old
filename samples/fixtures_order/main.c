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

NBP_MAIN_MODULE_FIXTURES(fixtures_order, module_setup, module_teardown)
{
    NBP_MODULE_RUN(module1);
    NBP_MODULE_RUN(module2);
}

NBP_MODULE_FIXTURES(module1, module_setup, module_teardown)
{
    NBP_MODULE_RUN(submodule1);
    NBP_MODULE_RUN(submodule2);
}

NBP_MODULE_FIXTURES(module2, module_setup, module_teardown)
{
    NBP_MODULE_RUN(empty_submodule1);
    NBP_TEST_RUN(test1);
    NBP_MODULE_RUN(submodule3);
    NBP_MODULE_RUN(empty_submodule2);
    NBP_TEST_RUN(test2);
    NBP_MODULE_RUN(submodule4);
}

NBP_MODULE_FIXTURES(submodule1, module_setup, module_teardown)
{
    NBP_MODULE_RUN(subsubmodule1);
    NBP_MODULE_RUN(subsubmodule2);
}

NBP_MODULE_FIXTURES(submodule2, module_setup, module_teardown)
{
    NBP_MODULE_RUN(subsubmodule3);
    NBP_MODULE_RUN(subsubmodule4);
}

NBP_MODULE_FIXTURES(submodule3, module_setup, module_teardown)
{
    NBP_TEST_RUN(test3);
    NBP_MODULE_RUN(subsubmodule5);
    NBP_TEST_RUN(test4);
    NBP_MODULE_RUN(subsubmodule6);
}

NBP_MODULE_FIXTURES(submodule4, module_setup, module_teardown)
{
    NBP_MODULE_RUN(subsubmodule7);
    NBP_TEST_RUN(test5);
    NBP_MODULE_RUN(subsubmodule8);
    NBP_TEST_RUN(test6);
}

NBP_MODULE_FIXTURES(empty_submodule1, module_setup, module_teardown)
{
    NBP_MODULE_RUN(empty_subsubmodule1);
    NBP_MODULE_RUN(empty_subsubmodule2);
}

NBP_MODULE_FIXTURES(empty_submodule2, module_setup, module_teardown)
{
    NBP_MODULE_RUN(empty_subsubmodule3);
    NBP_MODULE_RUN(empty_subsubmodule4);
}

NBP_MODULE_FIXTURES(subsubmodule1, module_setup, module_teardown)
{
    NBP_TEST_RUN(test7);
    NBP_TEST_RUN(test8);
    NBP_TEST_RUN(test9);
    NBP_TEST_RUN(test10);
}

NBP_MODULE_FIXTURES(subsubmodule2, module_setup, module_teardown)
{
    NBP_TEST_RUN(test11);
    NBP_TEST_RUN(test12);
    NBP_TEST_RUN(test13);
    NBP_TEST_RUN(test14);
}

NBP_MODULE_FIXTURES(subsubmodule3, module_setup, module_teardown)
{
    NBP_TEST_RUN(test15);
    NBP_TEST_RUN(test16);
    NBP_TEST_RUN(test17);
    NBP_TEST_RUN(test18);
}

NBP_MODULE_FIXTURES(subsubmodule4, module_setup, module_teardown)
{
    NBP_TEST_RUN(test19);
    NBP_TEST_RUN(test20);
    NBP_TEST_RUN(test21);
    NBP_TEST_RUN(test22);
}

NBP_MODULE_FIXTURES(subsubmodule5, module_setup, module_teardown)
{
    NBP_TEST_RUN(test23);
    NBP_TEST_RUN(test24);
    NBP_TEST_RUN(test25);
    NBP_TEST_RUN(test26);
}

NBP_MODULE_FIXTURES(subsubmodule6, module_setup, module_teardown)
{
    NBP_TEST_RUN(test27);
    NBP_TEST_RUN(test28);
    NBP_TEST_RUN(test29);
    NBP_TEST_RUN(test30);
}

NBP_MODULE_FIXTURES(subsubmodule7, module_setup, module_teardown)
{
    NBP_TEST_RUN(test31);
    NBP_TEST_RUN(test32);
    NBP_TEST_RUN(test33);
    NBP_TEST_RUN(test34);
}

NBP_MODULE_FIXTURES(subsubmodule8, module_setup, module_teardown)
{
    NBP_TEST_RUN(test35);
    NBP_TEST_RUN(test36);
    NBP_TEST_RUN(test37);
    NBP_TEST_RUN(test38);
}

NBP_MODULE_FIXTURES(empty_subsubmodule1, module_setup, module_teardown)
{
}

NBP_MODULE_FIXTURES(empty_subsubmodule2, module_setup, module_teardown)
{
}

NBP_MODULE_FIXTURES(empty_subsubmodule3, module_setup, module_teardown)
{
}

NBP_MODULE_FIXTURES(empty_subsubmodule4, module_setup, module_teardown)
{
}

NBP_TEST_FIXTURES(test1, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test2, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test3, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test4, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test5, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test6, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test7, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test8, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test9, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test10, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test11, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test12, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test13, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test14, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test15, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test16, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test17, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test18, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test19, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test20, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test21, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test22, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test23, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test24, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test25, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test26, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test27, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test28, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test29, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test30, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test31, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test32, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test33, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test34, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test35, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test36, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test37, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST_FIXTURES(test38, test_setup, test_teardown)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}
