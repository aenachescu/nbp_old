/*
No Bugs in Production (NBP)
Copyright (C) 2019-present Alin Enachescu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
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

    err = SAMPLE_SEMAPHORE_WAIT(g_semaphore2);
    NBP_ASSERT(err == 0);

    NBP_CHECK(1 + 1 == 2);
}

NBP_TEST(test2)
{
    SAMPLE_SLEEP();

    int err = SAMPLE_SEMAPHORE_RELEASE(g_semaphore1);
    NBP_ASSERT(err == 0);

    err = SAMPLE_SEMAPHORE_WAIT(g_semaphore2);
    NBP_ASSERT(err == 0);

    NBP_CHECK(1 + 1 == 2);
}

NBP_TEST(test3)
{
    SAMPLE_SLEEP();

    int err = SAMPLE_SEMAPHORE_RELEASE(g_semaphore1);
    NBP_ASSERT(err == 0);

    err = SAMPLE_SEMAPHORE_WAIT(g_semaphore2);
    NBP_ASSERT(err == 0);

    NBP_CHECK(1 + 1 == 2);
}

NBP_TEST(test4)
{
    SAMPLE_SLEEP();

    int i, err;

    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_WAIT(g_semaphore1);
        NBP_ASSERT(err == 0);
    }

    for (i = 0; i < 3; i++) {
        err = SAMPLE_SEMAPHORE_RELEASE(g_semaphore2);
        NBP_ASSERT(err == 0);
    }

    NBP_CHECK(1 + 1 == 2);
}

NBP_SETUP_MODULE(main_module_setup)
{
    int err;

    err = SAMPLE_SEMAPHORE_INIT(g_semaphore1);
    if (err == 1) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_GENERIC,
            "failed to init semaphore1"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    err = SAMPLE_SEMAPHORE_INIT(g_semaphore2);
    if (err == 1) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_GENERIC,
            "failed to init semaphore2"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }
}

NBP_TEARDOWN_MODULE(main_module_teardown)
{
    int err;

    err = SAMPLE_SEMAPHORE_UNINIT(g_semaphore1);
    if (err == 1) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_GENERIC,
            "failed to uninit semaphore1"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    err = SAMPLE_SEMAPHORE_UNINIT(g_semaphore2);
    if (err == 1) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_GENERIC,
            "failed to uninit semaphore2"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }
}

NBP_MAIN_MODULE_FIXTURES(mt_basic_sample, main_module_setup, main_module_teardown)
{
    NBP_CALL_TEST(test1);
    NBP_CALL_TEST(test2);
    NBP_CALL_TEST(test3);
    NBP_CALL_TEST(test4);
}
