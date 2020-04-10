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

SAMPLE_ATOMIC_UINT_TYPE setupCounter = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE teardownCounter = SAMPLE_ATOMIC_UINT_INIT(0);

NBP_SETUP_MODULE(setup)
{
    SAMPLE_FORCE_SLEEP_MS(1000);
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&setupCounter, 1);
}

NBP_TEARDOWN_MODULE(teardown)
{
    SAMPLE_FORCE_SLEEP_MS(1000);
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&teardownCounter, 1);
}

NBP_MODULE_FIXTURES(module1, setup, teardown)
{
    NBP_CALL_TEST(test1);
    NBP_CALL_TEST(test2);
    NBP_CALL_TEST(test3);
    NBP_CALL_TEST(test4);
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
    NBP_CALL_MODULE(module1);
    NBP_CALL_TEST_CTX(
        test5,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module1)
        )
    );
}
