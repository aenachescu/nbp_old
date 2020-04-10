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

SAMPLE_SEMAPHORE_TYPE g_semaphores[4];
SAMPLE_ATOMIC_UINT_TYPE g_setupCounter = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE g_teardownCounter = SAMPLE_ATOMIC_UINT_INIT(0);

NBP_MAIN_MODULE_FIXTURES(mt_scheduler_run_test_fixtures_in_parallel,
    mainSetup, mainTeardown)
{
    NBP_TEST_USE_SETUP(testSetup);
    NBP_CALL_AFTER_TEST(afterTest);
    NBP_CALL_TEST(test1);
    NBP_CALL_TEST(test2);
}

NBP_SETUP_MODULE(mainSetup)
{
    for (unsigned int i = 0; i < 4; ++i) {
        int err = SAMPLE_SEMAPHORE_INIT(g_semaphores[i]);
        if (err != 0) {
            NBP_HANDLE_ERROR_CTX_STRING(
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
            NBP_HANDLE_ERROR_CTX_STRING(
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
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_GENERIC,
            "failed to release semaphore"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    err = SAMPLE_SEMAPHORE_WAIT(g_semaphores[order[1]]);
    if (err != 0) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_GENERIC,
            "failed to wait semaphore"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }
}

NBP_AFTER_TEST(afterTest)
{
    unsigned int order[] = {2, 3};
    int err;

    if (SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&g_teardownCounter, 1) != 1) {
        order[0] = 3;
        order[1] = 2;
    }

    err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[order[0]]);
    if (err != 0) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_GENERIC,
            "failed to release semaphore"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    err = SAMPLE_SEMAPHORE_WAIT(g_semaphores[order[1]]);
    if (err != 0) {
        NBP_HANDLE_ERROR_CTX_STRING(
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
