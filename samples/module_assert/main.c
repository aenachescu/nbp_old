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

NBP_TEST_SETUP(testSetup)
{
    write_message_to_file_2("test setup", NBP_GET_TEST_NAME(NBP_THIS_TEST));
}

NBP_TEST_TEARDOWN(testTeardown)
{
    write_message_to_file_2("test teardown", NBP_GET_TEST_NAME(NBP_THIS_TEST));
}

NBP_SETUP_MODULE(setupModule)
{
    write_message_to_file_2(
        "setup module",
        NBP_GET_MODULE_NAME(NBP_THIS_MODULE)
    );
}

NBP_TEARDOWN_MODULE(teardownModule)
{
    write_message_to_file_2(
        "teardown module",
        NBP_GET_MODULE_NAME(NBP_THIS_MODULE)
    );
}

NBP_MAIN_MODULE_FIXTURES(module_assert_sample, setupModule, teardownModule)
{
    NBP_TEST_USE_SETUP(testSetup);
    NBP_TEST_USE_TEARDOWN(testTeardown);

    NBP_CALL_TEST(test1);
    NBP_CALL_MODULE(module1);
    NBP_CALL_TEST(test2);
    NBP_CALL_MODULE(module2);
    NBP_CALL_TEST(test3);
}

NBP_MODULE_FIXTURES(module1, setupModule, teardownModule)
{
    NBP_TEST_USE_SETUP(testSetup);
    NBP_TEST_USE_TEARDOWN(testTeardown);
    NBP_TEST_USE_SETUP(testSetup);
    NBP_TEST_USE_TEARDOWN(testTeardown);

    NBP_CALL_TEST(test4);
    NBP_CALL_MODULE(submodule1);
    NBP_CALL_TEST(test5);
    NBP_CALL_TEST(test6);
    NBP_CALL_TEST(test7);
    NBP_CALL_MODULE(submodule2);
    NBP_CALL_TEST(test8);
    NBP_CALL_MODULE(submodule3);
    NBP_CALL_TEST(test9);
}

NBP_MODULE_FIXTURES(module2, setupModule, teardownModule)
{
    NBP_TEST_USE_SETUP(testSetup);
    NBP_TEST_USE_TEARDOWN(testTeardown);

    NBP_CALL_TEST(test10);
    NBP_CALL_MODULE(submodule4);
    NBP_CALL_TEST(test11);
    NBP_CALL_MODULE(submodule5);
    NBP_CALL_TEST(test12);
}

NBP_MODULE_FIXTURES(submodule1, setupModule, teardownModule)
{
    NBP_TEST_USE_SETUP(testSetup);
    NBP_TEST_USE_TEARDOWN(testTeardown);

    NBP_CALL_TEST(test13);
    NBP_CALL_TEST(test14);
    NBP_CALL_TEST(test15);
    NBP_CALL_TEST(test16);
}

NBP_MODULE_FIXTURES(submodule2, setupModule, teardownModule)
{
    NBP_TEST_USE_SETUP(testSetup);
    NBP_TEST_USE_TEARDOWN(testTeardown);

    NBP_CALL_TEST(test17);
    NBP_CALL_TEST(test18);
    NBP_CALL_TEST(test19);
    NBP_CALL_TEST(test20);
}

NBP_MODULE_FIXTURES(submodule3, setupModule, teardownModule)
{
    NBP_TEST_USE_SETUP(testSetup);
    NBP_TEST_USE_TEARDOWN(testTeardown);

    NBP_CALL_TEST(test21);
    NBP_CALL_TEST(test22);
    NBP_CALL_TEST(test23);
    NBP_CALL_TEST(test24);
}

NBP_MODULE_FIXTURES(submodule4, setupModule, teardownModule)
{
    NBP_TEST_USE_SETUP(testSetup);
    NBP_TEST_USE_TEARDOWN(testTeardown);

    NBP_CALL_TEST(test25);
    NBP_CALL_TEST(test26);
    NBP_CALL_TEST(test27);
    NBP_CALL_TEST(test28);
}

NBP_MODULE_FIXTURES(submodule5, setupModule, teardownModule)
{
    NBP_TEST_USE_SETUP(testSetup);
    NBP_TEST_USE_TEARDOWN(testTeardown);

    NBP_CALL_TEST(test29);
    NBP_CALL_TEST(test30);
    NBP_CALL_TEST(test31);
    NBP_CALL_TEST(test32);
}

NBP_TEST(test1)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test2)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test3)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test4)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test5)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 != 1);
}

NBP_TEST(test6)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 != 1);
}

NBP_TEST(test7)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test8)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test9)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test10)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test11)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test12)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test13)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test14)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test15)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test16)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test17)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test18)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test19)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test20)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test21)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test22)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test23)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test24)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test25)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 != 1);
}

NBP_TEST(test26)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test27)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test28)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test29)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test30)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test31)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test32)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}
