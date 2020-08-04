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

NBP_MODULE_SETUP(setupModule)
{
    write_message_to_file_2(
        "setup module",
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
}

NBP_MODULE_TEARDOWN(teardownModule)
{
    write_message_to_file_2(
        "teardown module",
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
}

NBP_MAIN_MODULE_FIXTURES(empty_modules, setupModule, teardownModule)
{
    NBP_MODULE_RUN(module1);
    NBP_MODULE_RUN(module2);
    NBP_MODULE_RUN(module3);
}

NBP_MODULE_FIXTURES(module1, setupModule, teardownModule)
{
    NBP_MODULE_RUN(submodule1);
    NBP_MODULE_RUN(submodule2);
}

NBP_MODULE_FIXTURES(module2, setupModule, teardownModule)
{
    NBP_MODULE_RUN(submodule3);
    NBP_MODULE_RUN(submodule4);

    NBP_TEST_RUN(test1);
}

NBP_MODULE_FIXTURES(module3, setupModule, teardownModule)
{
    NBP_MODULE_RUN(submodule5);
    NBP_MODULE_RUN(submodule6);

    NBP_TEST_RUN(test2);
    NBP_TEST_RUN(test3);

    NBP_MODULE_RUN(submodule7);
}

NBP_MODULE_FIXTURES(submodule1, setupModule, teardownModule)
{
}

NBP_MODULE_FIXTURES(submodule2, setupModule, teardownModule)
{
}

NBP_MODULE_FIXTURES(submodule3, setupModule, teardownModule)
{
}

NBP_MODULE_FIXTURES(submodule4, setupModule, teardownModule)
{
}

NBP_MODULE_FIXTURES(submodule5, setupModule, teardownModule)
{
    NBP_MODULE_RUN(submodule9);
}

NBP_MODULE_FIXTURES(submodule6, setupModule, teardownModule)
{
}

NBP_MODULE_FIXTURES(submodule7, setupModule, teardownModule)
{
    NBP_TEST_RUN(test4);
    NBP_MODULE_RUN(submodule8);
}

NBP_MODULE_FIXTURES(submodule8, setupModule, teardownModule)
{
}

NBP_MODULE_FIXTURES(submodule9, setupModule, teardownModule)
{
}

NBP_TEST(test1)
{
    SAMPLE_SLEEP();

    NBP_CHECK(1 == 1);
}

NBP_TEST(test2)
{
    SAMPLE_SLEEP();

    NBP_MODULE_ASSERT(1 != 1);
}

// these tests are skipped
// LCOV_EXCL_START

NBP_TEST(test3)
{
    SAMPLE_SLEEP();

    NBP_CHECK(1 == 1);
}

NBP_TEST(test4)
{
    SAMPLE_SLEEP();

    NBP_CHECK(1 == 1);
}

// LCOV_EXCL_STOP
