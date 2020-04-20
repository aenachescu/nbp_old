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

SAMPLE_SEMAPHORE_TYPE g_semaphores[4];
SAMPLE_ATOMIC_UINT_TYPE g_setupCounter = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE g_teardownCounter = SAMPLE_ATOMIC_UINT_INIT(0);

NBP_MAIN_MODULE_FIXTURES(mt_scheduler_run_test_fixtures_in_parallel,
    mainSetup, mainTeardown)
{
    NBP_TEST_USE_SETUP(testSetup);
    NBP_TEST_USE_TEARDOWN(testTeardown);
    NBP_TEST_RUN(test1);
    NBP_TEST_RUN(test2);
}

NBP_SETUP_MODULE(mainSetup)
{
    for (unsigned int i = 0; i < 4; ++i) {
        int err = SAMPLE_SEMAPHORE_INIT(g_semaphores[i]);
        if (err != 0) {
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_GENERIC,
                "failed to init semaphore"
            );
            NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
        }
    }
}

NBP_TEARDOWN_MODULE(mainTeardown)
{
    for (unsigned int i = 0; i < 4; ++i) {
        int err = SAMPLE_SEMAPHORE_UNINIT(g_semaphores[i]);
        if (err != 0) {
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_GENERIC,
                "failed to uninit semaphore"
            );
            NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
        }
    }
}

NBP_TEST_SETUP(testSetup)
{
    unsigned int order[] = {0, 1};
    int err;

    if (SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&g_setupCounter, 1) != 1) {
        order[0] = 1;
        order[1] = 0;
    }

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[order[0]]);
    if (err != 0) {
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_GENERIC,
            "failed to release semaphore"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    err = SAMPLE_SEMAPHORE_WAIT(g_semaphores[order[1]]);
    if (err != 0) {
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_GENERIC,
            "failed to wait semaphore"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }
}

NBP_TEST_TEARDOWN(testTeardown)
{
    unsigned int order[] = {2, 3};
    int err;

    if (SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&g_teardownCounter, 1) != 1) {
        order[0] = 3;
        order[1] = 2;
    }

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[order[0]]);
    if (err != 0) {
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_GENERIC,
            "failed to release semaphore"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    err = SAMPLE_SEMAPHORE_WAIT(g_semaphores[order[1]]);
    if (err != 0) {
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_GENERIC,
            "failed to wait semaphore"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }
}

NBP_TEST(test1)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test2)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}
