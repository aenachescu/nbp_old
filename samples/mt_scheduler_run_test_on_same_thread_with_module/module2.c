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

#include <nbp.h>

#include "../sample_utils.h"

extern SAMPLE_THREAD_ID_TYPE test18ThreadId;
extern SAMPLE_THREAD_ID_TYPE test19ThreadId;
extern SAMPLE_THREAD_ID_TYPE test20ThreadId;
extern SAMPLE_THREAD_ID_TYPE test21ThreadId;
extern SAMPLE_THREAD_ID_TYPE test22ThreadId;
extern SAMPLE_THREAD_ID_TYPE test23ThreadId;
extern SAMPLE_THREAD_ID_TYPE test24ThreadId;
extern SAMPLE_THREAD_ID_TYPE test25ThreadId;

NBP_MODULE(module2)
{
    NBP_MODULE_RUN(empty_module3);
    NBP_MODULE_RUN(submodule3);
    NBP_MODULE_RUN(empty_module4);
    NBP_MODULE_RUN(submodule4);
}

NBP_MODULE_FIXTURES(empty_module3, setupEmptyModule, teardownEmptyModule)
{
    NBP_MODULE_RUN(empty_submodule5);
    NBP_MODULE_RUN(empty_submodule6);
}

NBP_MODULE_FIXTURES(empty_module4, setupEmptyModule, teardownEmptyModule)
{
    NBP_MODULE_RUN(empty_submodule7);
    NBP_MODULE_RUN(empty_submodule8);
}

NBP_MODULE_FIXTURES(empty_submodule5, setupEmptyModule, teardownEmptyModule)
{
}

NBP_MODULE_FIXTURES(empty_submodule6, setupEmptyModule, teardownEmptyModule)
{
}

NBP_MODULE_FIXTURES(empty_submodule7, setupEmptyModule, teardownEmptyModule)
{
}

NBP_MODULE_FIXTURES(empty_submodule8, setupEmptyModule, teardownEmptyModule)
{
}

NBP_MODULE(submodule3)
{
    NBP_MODULE_RUN(subsubmodule5);
    NBP_MODULE_RUN(subsubmodule6);
}

NBP_MODULE(submodule4)
{
    NBP_MODULE_RUN(subsubmodule7);
    NBP_MODULE_RUN(subsubmodule8);
}

NBP_MODULE(subsubmodule5)
{
    NBP_TEST_RUN(test18);
    NBP_TEST_RUN(test19);
}

NBP_MODULE(subsubmodule6)
{
    NBP_TEST_RUN(test20);
    NBP_TEST_RUN(test21);
}

NBP_MODULE(subsubmodule7)
{
    NBP_TEST_RUN(test22);
    NBP_TEST_RUN(test23);
}

NBP_MODULE(subsubmodule8)
{
    NBP_TEST_RUN(test24);
    NBP_TEST_RUN(test25);
}

NBP_TEST(test18)
{
    SAMPLE_SLEEP();

    test18ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test18ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test19)
{
    SAMPLE_SLEEP();

    test19ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test19ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test20)
{
    SAMPLE_SLEEP();

    test20ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test20ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test21)
{
    SAMPLE_SLEEP();

    test21ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test21ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test22)
{
    SAMPLE_SLEEP();

    test22ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test22ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test23)
{
    SAMPLE_SLEEP();

    test23ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test23ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test24)
{
    SAMPLE_SLEEP();

    test24ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test24ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}

NBP_TEST(test25)
{
    SAMPLE_SLEEP();

    test25ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(test25ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE);
}
