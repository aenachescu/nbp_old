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

NBP_TEARDOWN_MODULE(teardownMainModule)
{
    (void)(NBP_THIS_MODULE);
    write_message_to_file("teardown");
}

NBP_TEST(test1)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test2)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test3)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test4)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_MAIN_MODULE_FIXTURES(main_module_teardown_one_file, NBP_NO_SETUP_FUNC,
    teardownMainModule)
{
    NBP_CALL_TEST(test1);
    NBP_CALL_TEST(test2);
    NBP_CALL_TEST(test3);
    NBP_CALL_TEST(test4);
}