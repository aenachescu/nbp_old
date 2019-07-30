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

NBP_BEFORE_TEST(beforeTest)
{
    write_message_to_file_2("before test", NBP_GET_TEST_NAME(NBP_THIS_TEST));
}

NBP_AFTER_TEST(afterTest)
{
    write_message_to_file_2("after test", NBP_GET_TEST_NAME(NBP_THIS_TEST));
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

NBP_MAIN_MODULE_FIXTURES(module_assert_sample, setupModule, teardownModule)
{
    NBP_CALL_BEFORE_TEST(beforeTest);
    NBP_CALL_AFTER_TEST(afterTest);

    NBP_CALL_TEST(test1);
    NBP_CALL_MODULE(module1);
    NBP_CALL_TEST(test2);
    NBP_CALL_MODULE(module2);
    NBP_CALL_TEST(test3);
}

NBP_MODULE_FIXTURES(module1, setupModule, teardownModule)
{
    NBP_CALL_BEFORE_TEST(beforeTest);
    NBP_CALL_AFTER_TEST(afterTest);
    NBP_CALL_BEFORE_TEST(beforeTest);
    NBP_CALL_AFTER_TEST(afterTest);

    NBP_CALL_TEST(test4);
    NBP_CALL_MODULE(submodule1);
    NBP_CALL_TEST(test5);
    NBP_CALL_TEST(test6);
    NBP_CALL_TEST(test7);
    NBP_CALL_MODULE(submodule2);
    NBP_CALL_TEST(test8);
    NBP_CALL_MODULE(submodule3);
    NBP_CALL_TEST(test9);
}

NBP_MODULE_FIXTURES(module2, setupModule, teardownModule)
{
    NBP_CALL_BEFORE_TEST(beforeTest);
    NBP_CALL_AFTER_TEST(afterTest);

    NBP_CALL_TEST(test10);
    NBP_CALL_MODULE(submodule4);
    NBP_CALL_TEST(test11);
    NBP_CALL_MODULE(submodule5);
    NBP_CALL_TEST(test12);
}

NBP_MODULE_FIXTURES(submodule1, setupModule, teardownModule)
{
    NBP_CALL_BEFORE_TEST(beforeTest);
    NBP_CALL_AFTER_TEST(afterTest);

    NBP_CALL_TEST(test13);
    NBP_CALL_TEST(test14);
    NBP_CALL_TEST(test15);
    NBP_CALL_TEST(test16);
}

NBP_MODULE_FIXTURES(submodule2, setupModule, teardownModule)
{
    NBP_CALL_BEFORE_TEST(beforeTest);
    NBP_CALL_AFTER_TEST(afterTest);

    NBP_CALL_TEST(test17);
    NBP_CALL_TEST(test18);
    NBP_CALL_TEST(test19);
    NBP_CALL_TEST(test20);
}

NBP_MODULE_FIXTURES(submodule3, setupModule, teardownModule)
{
    NBP_CALL_BEFORE_TEST(beforeTest);
    NBP_CALL_AFTER_TEST(afterTest);

    NBP_CALL_TEST(test21);
    NBP_CALL_TEST(test22);
    NBP_CALL_TEST(test23);
    NBP_CALL_TEST(test24);
}

NBP_MODULE_FIXTURES(submodule4, setupModule, teardownModule)
{
    NBP_CALL_BEFORE_TEST(beforeTest);
    NBP_CALL_AFTER_TEST(afterTest);

    NBP_CALL_TEST(test25);
    NBP_CALL_TEST(test26);
    NBP_CALL_TEST(test27);
    NBP_CALL_TEST(test28);
}

NBP_MODULE_FIXTURES(submodule5, setupModule, teardownModule)
{
    NBP_CALL_BEFORE_TEST(beforeTest);
    NBP_CALL_AFTER_TEST(afterTest);

    NBP_CALL_TEST(test29);
    NBP_CALL_TEST(test30);
    NBP_CALL_TEST(test31);
    NBP_CALL_TEST(test32);
}

NBP_TEST(test1)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test2)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test3)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test4)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test5)
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 != 1);
}

NBP_TEST(test6)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 != 1);
}

NBP_TEST(test7)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test8)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test9)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test10)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test11)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test12)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test13)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test14)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test15)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test16)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test17)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test18)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test19)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test20)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test21)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test22)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test23)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test24)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test25)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 != 1);
}

NBP_TEST(test26)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test27)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test28)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test29)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test30)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test31)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}

NBP_TEST(test32)
{
    SAMPLE_SLEEP();
    NBP_MODULE_ASSERT(1 == 1);
}
