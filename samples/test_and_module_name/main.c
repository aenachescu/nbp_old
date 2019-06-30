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

NBP_TEST_NAME(test_and_module_name_test1, "first test")
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST_NAME(test_and_module_name_test2, "second test")
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST_NAME(test_and_module_name_test3, "third test")
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST_NAME(test1, "first test")
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST_NAME(test2, "second test")
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_MODULE_NAME(module1, "first module")
{
    NBP_CALL_TEST(test1);
}

NBP_MODULE_NAME(module2, "second module")
{
    NBP_CALL_TEST(test2);
}

NBP_MAIN_MODULE_NAME(test_and_module_name, "main module")
{
    NBP_CALL_TEST(test_and_module_name_test1);
    NBP_CALL_MODULE(module1);
    NBP_CALL_TEST(test_and_module_name_test2);
    NBP_CALL_MODULE(module2);
    NBP_CALL_TEST(test_and_module_name_test3);
}
