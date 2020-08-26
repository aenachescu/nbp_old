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

NBP_MAIN_MODULE(empty_tests, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_TEST_RUN(test1);
    NBP_TEST_RUN(test2);
    NBP_MODULE_RUN(module1);
    NBP_MODULE_RUN(module2);
}

NBP_MODULE(module1, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_TEST_RUN(test3);
    NBP_TEST_RUN(test4);
    NBP_TEST_RUN(test5);
    NBP_TEST_RUN(test6);
}

NBP_MODULE(module2, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    NBP_TEST_RUN(test7);
    NBP_TEST_RUN(test8);
    NBP_TEST_RUN(test9);
    NBP_TEST_RUN(test10);
}

NBP_TEST(test1, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
}

NBP_TEST(test2, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
}

NBP_TEST(test3, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
}

NBP_TEST(test4, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
}

NBP_TEST(test5, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
}

NBP_TEST(test6, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
}

NBP_TEST(test7, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
}

NBP_TEST(test8, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
}

NBP_TEST(test9, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
}

NBP_TEST(test10, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
}
