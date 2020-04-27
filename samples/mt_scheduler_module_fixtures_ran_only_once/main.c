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

SAMPLE_ATOMIC_UINT_TYPE setupCounter = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE teardownCounter = SAMPLE_ATOMIC_UINT_INIT(0);

NBP_MODULE_SETUP(setup)
{
    SAMPLE_FORCE_SLEEP_MS(1000);
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&setupCounter, 1);
}

NBP_MODULE_TEARDOWN(teardown)
{
    SAMPLE_FORCE_SLEEP_MS(1000);
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&teardownCounter, 1);
}

NBP_MODULE_FIXTURES(module1, setup, teardown)
{
    NBP_TEST_RUN(test1);
    NBP_TEST_RUN(test2);
    NBP_TEST_RUN(test3);
    NBP_TEST_RUN(test4);
}

NBP_TEST(test1)
{
    SAMPLE_SLEEP();

    unsigned int counter = SAMPLE_ATOMIC_UINT_LOAD(&setupCounter);
    NBP_CHECK(counter == 1);
}

NBP_TEST(test2)
{
    SAMPLE_SLEEP();

    unsigned int counter = SAMPLE_ATOMIC_UINT_LOAD(&setupCounter);
    NBP_CHECK(counter == 1);
}

NBP_TEST(test3)
{
    SAMPLE_SLEEP();

    unsigned int counter = SAMPLE_ATOMIC_UINT_LOAD(&setupCounter);
    NBP_CHECK(counter == 1);
}

NBP_TEST(test4)
{
    SAMPLE_SLEEP();

    unsigned int counter = SAMPLE_ATOMIC_UINT_LOAD(&setupCounter);
    NBP_CHECK(counter == 1);
}

NBP_TEST(test5)
{
    SAMPLE_SLEEP();

    unsigned int counter = SAMPLE_ATOMIC_UINT_LOAD(&setupCounter);
    NBP_CHECK(counter == 1);

    counter = SAMPLE_ATOMIC_UINT_LOAD(&teardownCounter);
    NBP_CHECK(counter == 1);
}

NBP_MAIN_MODULE(mt_scheduler_module_fixtures_ran_only_once)
{
    NBP_MODULE_RUN(module1);
    NBP_TEST_RUN_CTX(
        test5,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module1)
        )
    );
}
