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

SAMPLE_SEMAPHORE_TYPE g_semaphore1 = SAMPLE_SEMAPHORE_DEFAULT_VALUE;
SAMPLE_SEMAPHORE_TYPE g_semaphore2 = SAMPLE_SEMAPHORE_DEFAULT_VALUE;

NBP_TEST(test1)
{
    SAMPLE_SLEEP();

    int err = SAMPLE_SEMAPHORE_RELEASE(g_semaphore1);
    NBP_ASSERT(err == 0);

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphore2);
    NBP_ASSERT(err == 0);

    NBP_CHECK(1 + 1 == 2);
}

NBP_TEST(test2)
{
    SAMPLE_SLEEP();

    int err = SAMPLE_SEMAPHORE_RELEASE(g_semaphore1);
    NBP_ASSERT(err == 0);

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphore2);
    NBP_ASSERT(err == 0);

    NBP_CHECK(1 + 1 == 2);
}

NBP_TEST(test3)
{
    SAMPLE_SLEEP();

    int err = SAMPLE_SEMAPHORE_RELEASE(g_semaphore1);
    NBP_ASSERT(err == 0);

    err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphore2);
    NBP_ASSERT(err == 0);

    NBP_CHECK(1 + 1 == 2);
}

NBP_TEST(test4)
{
    SAMPLE_SLEEP();

    int i, err;

    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_WAIT_TIMEOUT(g_semaphore1);
        NBP_ASSERT(err == 0);
    }

    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_RELEASE(g_semaphore2);
        NBP_ASSERT(err == 0);
    }

    NBP_CHECK(1 + 1 == 2);
}

NBP_MODULE_SETUP(main_module_setup)
{
    int err;

    err = SAMPLE_SEMAPHORE_INIT(g_semaphore1);
    if (err == 1) {
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_SYNC_ERROR,
            "failed to init semaphore1"
        );
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
        // LCOV_EXCL_STOP
    }

    err = SAMPLE_SEMAPHORE_INIT(g_semaphore2);
    if (err == 1) {
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_SYNC_ERROR,
            "failed to init semaphore2"
        );
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
        // LCOV_EXCL_STOP
    }
}

NBP_MODULE_TEARDOWN(main_module_teardown)
{
    int err;

    err = SAMPLE_SEMAPHORE_UNINIT(g_semaphore1);
    if (err == 1) {
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_SYNC_ERROR,
            "failed to uninit semaphore1"
        );
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
        // LCOV_EXCL_STOP
    }

    err = SAMPLE_SEMAPHORE_UNINIT(g_semaphore2);
    if (err == 1) {
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_SYNC_ERROR,
            "failed to uninit semaphore2"
        );
        NBP_EXIT(NBP_ERROR_CODE_SYNC_ERROR);
        // LCOV_EXCL_STOP
    }
}

NBP_MAIN_MODULE_FIXTURES(mt_scheduler_basic_sample, main_module_setup,
    main_module_teardown)
{
    NBP_TEST_RUN(test1);
    NBP_TEST_RUN(test2);
    NBP_TEST_RUN(test3);
    NBP_TEST_RUN(test4);
}
