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
    write_message_to_file("fixture");
}

NBP_MODULE_TEARDOWN(module_teardown)
{
    write_message_to_file("fixture");
}

NBP_TEST_SETUP(test_setup)
{
    write_message_to_file("fixture");
}

NBP_TEST_TEARDOWN(test_teardown)
{
    write_message_to_file("fixture");
}

NBP_MAIN_MODULE_FIXTURES(mt_scheduler_empty_context, module_setup,
    module_teardown)
{
    NBP_TEST_RUN(test1);
    NBP_TEST_RUN_CTX(test2, NBP_MT_SCHEDULER_CTX());
    NBP_MODULE_RUN(module1);
    NBP_MODULE_RUN_CTX(module2, NBP_MT_SCHEDULER_CTX());
}

NBP_MODULE_FIXTURES(module1, module_setup, module_teardown)
{
    NBP_TEST_RUN(test3);
    NBP_TEST_RUN_CTX(test4, NBP_MT_SCHEDULER_CTX());
    NBP_TEST_RUN(test5);
    NBP_TEST_RUN_CTX(test6, NBP_MT_SCHEDULER_CTX());
}

NBP_MODULE_FIXTURES(module2, module_setup, module_teardown)
{
    NBP_TEST_RUN_CTX(test7, NBP_MT_SCHEDULER_CTX());
    NBP_TEST_RUN(test8);
    NBP_TEST_RUN_CTX(test9, NBP_MT_SCHEDULER_CTX());
    NBP_TEST_RUN(test10);
}

NBP_TEST(test1, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test2, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test3, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test4, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test5, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test6, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test7, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test8, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test9, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test10, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}
