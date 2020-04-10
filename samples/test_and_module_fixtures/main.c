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

NBP_TEST_SETUP(testSetup)
{
    write_message_to_file_2(
        "test setup",
        NBP_GET_TEST_NAME(NBP_THIS_TEST)
    );
}

NBP_AFTER_TEST(afterTest)
{
    write_message_to_file_2(
        "after test",
        NBP_GET_TEST_NAME(NBP_THIS_TEST)
    );
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

NBP_TEST(test_and_module_fixtures_test1)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test_and_module_fixtures_test2)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test_and_module_fixtures_test3)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
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

NBP_MODULE_FIXTURES(module1, setupModule, teardownModule)
{
    NBP_TEST_USE_SETUP(testSetup);
    NBP_CALL_AFTER_TEST(afterTest);

    NBP_CALL_TEST(test1);
}

NBP_MODULE_FIXTURES(module2, setupModule, teardownModule)
{
    NBP_TEST_USE_SETUP(testSetup);
    NBP_CALL_AFTER_TEST(afterTest);

    NBP_CALL_TEST(test2);
}

NBP_MAIN_MODULE_FIXTURES(test_and_module_fixtures, setupModule, teardownModule)
{
    NBP_TEST_USE_SETUP(testSetup);
    NBP_CALL_AFTER_TEST(afterTest);

    NBP_CALL_TEST(test_and_module_fixtures_test1);
    NBP_CALL_MODULE(module1);
    NBP_CALL_TEST(test_and_module_fixtures_test2);
    NBP_CALL_MODULE(module2);
    NBP_CALL_TEST(test_and_module_fixtures_test3);
}
