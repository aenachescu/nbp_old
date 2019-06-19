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

#include <nbp.h>

#include "../sample_utils.h"

NBP_TEST(test1)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1);
}

NBP_TEST(test2)
{
    SAMPLE_SLEEP();
    NBP_CHECK(2);
}

NBP_TEST(test3)
{
    SAMPLE_SLEEP();
    NBP_CHECK(3);
}

NBP_TEST(test4)
{
    SAMPLE_SLEEP();
    NBP_CHECK(4);
}

NBP_MODULE_FIXTURES(submodule1, submodule_setup, submodule_teardown)
{
    NBP_CALL_TEST(test1);
    NBP_CALL_TEST(test2);
    NBP_CALL_TEST(test3);
    NBP_CALL_TEST(test4);
}
