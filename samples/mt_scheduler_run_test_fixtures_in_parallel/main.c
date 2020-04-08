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

SAMPLE_SEMAPHORE_TYPE g_semaphores[2];
SAMPLE_ATOMIC_UINT_TYPE g_counter = SAMPLE_ATOMIC_UINT_INIT(0);

NBP_MAIN_MODULE_FIXTURES(mt_scheduler_run_test_fixtures_in_parallel, setup, teardown)
{
    NBP_CALL_BEFORE_TEST(beforeTest);
    NBP_CALL_AFTER_TEST(afterTest);
    NBP_CALL_TEST(test1);
    NBP_CALL_TEST(test2);
}

NBP_SETUP_MODULE(setup)
{
    for (size_t i = 0; i < 2; ++i) {
        int err = SAMPLE_SEMAPHORE_INIT(g_semaphores[i]);
        if (err != 0) {
            NBP_HANDLE_ERROR_CTX_STRING(
                NBP_ERROR_GENERIC,
                "failed to init semaphores"
            );
            NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
        }
    }
}

NBP_TEARDOWN_MODULE(teardown)
{
    for (size_t i = 0; i < 2; ++i) {
        int err = SAMPLE_SEMAPHORE_UNINIT(g_semaphores[i]);
        if (err != 0) {
            NBP_HANDLE_ERROR_CTX_STRING(
                NBP_ERROR_GENERIC,
                "failed to uninit semaphore1"
            );
            NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);        
        }
    }
}

void check_parallelism() {
    size_t order[] = {0, 1}; 
    if (SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&g_counter, 1) != 1) {
        order[0] = 1;
        order[1] = 0;
    }
    int err = SAMPLE_SEMAPHORE_RELEASE(g_semaphores[order[0]]);
    if (err != 0) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_GENERIC,
            "failed to unlock semaphore"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);        
    }

    err = SAMPLE_SEMAPHORE_WAIT(g_semaphores[order[1]]);
    if (err != 0) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_GENERIC,
            "failed to lock semaphore"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);        
    }
    
    SAMPLE_ATOMIC_UINT_STORE(&g_counter, 0);
}

NBP_BEFORE_TEST(beforeTest)
{
    check_parallelism();
}

NBP_AFTER_TEST(afterTest)
{
    check_parallelism();
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