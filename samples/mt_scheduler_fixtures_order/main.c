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

NBP_MAIN_MODULE_FIXTURES(mt_scheduler_fixtures_order, main_module_setup,
    main_module_teardown)
{
    NBP_MODULE_RUN(module1);
    NBP_MODULE_RUN(module2);
}

NBP_MODULE_FIXTURES(module1, module1_setup, module1_teardown)
{
    NBP_MODULE_RUN(submodule1);
    NBP_MODULE_RUN(submodule2);
}

NBP_MODULE_FIXTURES(module2, module2_setup, module2_teardown)
{
    NBP_MODULE_RUN(empty_submodule1);
    NBP_TEST_RUN(test1);
    NBP_MODULE_RUN(submodule3);
    NBP_MODULE_RUN(empty_submodule2);
    NBP_TEST_RUN(test2);
    NBP_MODULE_RUN(submodule4);
}

NBP_MODULE_FIXTURES(submodule1, submodule1_setup, submodule1_teardown)
{
    NBP_MODULE_RUN(subsubmodule1);
    NBP_MODULE_RUN(subsubmodule2);
}

NBP_MODULE_FIXTURES(submodule2, submodule2_setup, submodule2_teardown)
{
    NBP_MODULE_RUN(subsubmodule3);
    NBP_MODULE_RUN(subsubmodule4);
}

NBP_MODULE_FIXTURES(submodule3, submodule3_setup, submodule3_teardown)
{
    NBP_TEST_RUN(test3);
    NBP_MODULE_RUN(subsubmodule5);
    NBP_TEST_RUN(test4);
    NBP_MODULE_RUN(subsubmodule6);
}

NBP_MODULE_FIXTURES(submodule4, submodule4_setup, submodule4_teardown)
{
    NBP_MODULE_RUN(subsubmodule7);
    NBP_TEST_RUN(test5);
    NBP_MODULE_RUN(subsubmodule8);
    NBP_TEST_RUN(test6);
}

NBP_MODULE_FIXTURES(empty_submodule1, empty_submodule1_setup,
    empty_submodule1_teardown)
{
    NBP_MODULE_RUN(empty_subsubmodule1);
    NBP_MODULE_RUN(empty_subsubmodule2);
}

NBP_MODULE_FIXTURES(empty_submodule2, empty_submodule2_setup,
    empty_submodule2_teardown)
{
    NBP_MODULE_RUN(empty_subsubmodule3);
    NBP_MODULE_RUN(empty_subsubmodule4);
}

NBP_MODULE_FIXTURES(subsubmodule1, subsubmodule1_setup, subsubmodule1_teardown)
{
    NBP_TEST_RUN(test7);
    NBP_TEST_RUN(test8);
    NBP_TEST_RUN(test9);
    NBP_TEST_RUN(test10);
}

NBP_MODULE_FIXTURES(subsubmodule2, subsubmodule2_setup, subsubmodule2_teardown)
{
    NBP_TEST_RUN(test11);
    NBP_TEST_RUN(test12);
    NBP_TEST_RUN(test13);
    NBP_TEST_RUN(test14);
}

NBP_MODULE_FIXTURES(subsubmodule3, subsubmodule3_setup, subsubmodule3_teardown)
{
    NBP_TEST_RUN(test15);
    NBP_TEST_RUN(test16);
    NBP_TEST_RUN(test17);
    NBP_TEST_RUN(test18);
}

NBP_MODULE_FIXTURES(subsubmodule4, subsubmodule4_setup, subsubmodule4_teardown)
{
    NBP_TEST_RUN(test19);
    NBP_TEST_RUN(test20);
    NBP_TEST_RUN(test21);
    NBP_TEST_RUN(test22);
}

NBP_MODULE_FIXTURES(subsubmodule5, subsubmodule5_setup, subsubmodule5_teardown)
{
    NBP_TEST_RUN(test23);
    NBP_TEST_RUN(test24);
    NBP_TEST_RUN(test25);
    NBP_TEST_RUN(test26);
}

NBP_MODULE_FIXTURES(subsubmodule6, subsubmodule6_setup, subsubmodule6_teardown)
{
    NBP_TEST_RUN(test27);
    NBP_TEST_RUN(test28);
    NBP_TEST_RUN(test29);
    NBP_TEST_RUN(test30);
}

NBP_MODULE_FIXTURES(subsubmodule7, subsubmodule7_setup, subsubmodule7_teardown)
{
    NBP_TEST_RUN(test31);
    NBP_TEST_RUN(test32);
    NBP_TEST_RUN(test33);
    NBP_TEST_RUN(test34);
}

NBP_MODULE_FIXTURES(subsubmodule8, subsubmodule8_setup, subsubmodule8_teardown)
{
    NBP_TEST_RUN(test35);
    NBP_TEST_RUN(test36);
    NBP_TEST_RUN(test37);
    NBP_TEST_RUN(test38);
}

NBP_MODULE_FIXTURES(empty_subsubmodule1, empty_subsubmodule1_setup,
    empty_subsubmodule1_teardown)
{
}

NBP_MODULE_FIXTURES(empty_subsubmodule2, empty_subsubmodule2_setup,
    empty_subsubmodule2_teardown)
{
}

NBP_MODULE_FIXTURES(empty_subsubmodule3, empty_subsubmodule3_setup,
    empty_subsubmodule3_teardown)
{
}

NBP_MODULE_FIXTURES(empty_subsubmodule4, empty_subsubmodule4_setup,
    empty_subsubmodule4_teardown)
{
}

NBP_TEST(test1, NBP_TEST_FIXTURES(test1_setup, test1_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test2, NBP_TEST_FIXTURES(test2_setup, test2_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test3, NBP_TEST_FIXTURES(test3_setup, test3_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test4, NBP_TEST_FIXTURES(test4_setup, test4_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test5, NBP_TEST_FIXTURES(test5_setup, test5_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test6, NBP_TEST_FIXTURES(test6_setup, test6_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test7, NBP_TEST_FIXTURES(test7_setup, test7_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test8, NBP_TEST_FIXTURES(test8_setup, test8_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test9, NBP_TEST_FIXTURES(test9_setup, test9_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test10, NBP_TEST_FIXTURES(test10_setup, test10_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test11, NBP_TEST_FIXTURES(test11_setup, test11_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test12, NBP_TEST_FIXTURES(test12_setup, test12_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test13, NBP_TEST_FIXTURES(test13_setup, test13_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test14, NBP_TEST_FIXTURES(test14_setup, test14_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test15, NBP_TEST_FIXTURES(test15_setup, test15_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test16, NBP_TEST_FIXTURES(test16_setup, test16_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test17, NBP_TEST_FIXTURES(test17_setup, test17_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test18, NBP_TEST_FIXTURES(test18_setup, test18_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test19, NBP_TEST_FIXTURES(test19_setup, test19_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test20, NBP_TEST_FIXTURES(test20_setup, test20_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test21, NBP_TEST_FIXTURES(test21_setup, test21_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test22, NBP_TEST_FIXTURES(test22_setup, test22_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test23, NBP_TEST_FIXTURES(test23_setup, test23_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test24, NBP_TEST_FIXTURES(test24_setup, test24_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test25, NBP_TEST_FIXTURES(test25_setup, test25_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test26, NBP_TEST_FIXTURES(test26_setup, test26_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test27, NBP_TEST_FIXTURES(test27_setup, test27_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test28, NBP_TEST_FIXTURES(test28_setup, test28_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test29, NBP_TEST_FIXTURES(test29_setup, test29_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test30, NBP_TEST_FIXTURES(test30_setup, test30_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test31, NBP_TEST_FIXTURES(test31_setup, test31_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test32, NBP_TEST_FIXTURES(test32_setup, test32_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test33, NBP_TEST_FIXTURES(test33_setup, test33_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test34, NBP_TEST_FIXTURES(test34_setup, test34_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test35, NBP_TEST_FIXTURES(test35_setup, test35_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test36, NBP_TEST_FIXTURES(test36_setup, test36_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test37, NBP_TEST_FIXTURES(test37_setup, test37_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

NBP_TEST(test38, NBP_TEST_FIXTURES(test38_setup, test38_teardown))
{
    SAMPLE_SLEEP();
    NBP_CHECK(1 == 1);
}

SAMPLE_ATOMIC_UINT_TYPE mainModuleSetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE mainModuleTeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE module1SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE module1TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE module2SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE module2TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE submodule1SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE submodule1TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE submodule2SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE submodule2TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE submodule3SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE submodule3TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE submodule4SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE submodule4TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE subsubmodule1SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE subsubmodule1TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE subsubmodule2SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE subsubmodule2TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE subsubmodule3SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE subsubmodule3TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE subsubmodule4SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE subsubmodule4TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE subsubmodule5SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE subsubmodule5TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE subsubmodule6SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE subsubmodule6TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE subsubmodule7SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE subsubmodule7TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE subsubmodule8SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE subsubmodule8TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE emptySubmodule1SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE emptySubmodule1TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE emptySubmodule2SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE emptySubmodule2TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE emptySubsubmodule1SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE emptySubsubmodule1TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE emptySubsubmodule2SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE emptySubsubmodule2TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE emptySubsubmodule3SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE emptySubsubmodule3TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE emptySubsubmodule4SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE emptySubsubmodule4TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test1SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test1TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test2SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test2TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test3SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test3TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test4SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test4TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test5SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test5TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test6SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test6TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test7SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test7TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test8SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test8TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test9SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test9TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test10SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test10TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test11SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test11TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test12SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test12TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test13SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test13TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test14SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test14TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test15SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test15TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test16SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test16TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test17SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test17TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test18SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test18TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test19SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test19TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test20SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test20TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test21SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test21TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test22SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test22TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test23SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test23TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test24SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test24TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test25SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test25TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test26SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test26TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test27SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test27TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test28SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test28TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test29SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test29TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test30SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test30TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test31SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test31TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test32SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test32TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test33SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test33TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test34SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test34TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test35SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test35TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test36SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test36TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test37SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test37TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test38SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test38TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

NBP_MODULE_SETUP(main_module_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&mainModuleSetupValue, 1);
}

NBP_MODULE_TEARDOWN(main_module_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &mainModuleTeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&module1TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &mainModuleTeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&module2TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&mainModuleTeardownValue, 1);

    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&mainModuleSetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&mainModuleTeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&module1SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&module1TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&submodule1SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&submodule1TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule1SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule1TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test7SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test7TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test8SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test8TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test9SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test9TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test10SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test10TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule2SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule2TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test11SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test11TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test12SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test12TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test13SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test13TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test14SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test14TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&submodule2SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&submodule2TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule3SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule3TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test15SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test15TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test16SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test16TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test17SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test17TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test18SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test18TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule4SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule4TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test19SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test19TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test20SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test20TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test21SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test21TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test22SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test22TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&module2SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&module2TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubmodule1SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubmodule1TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubsubmodule1SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubsubmodule1TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubsubmodule2SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubsubmodule2TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test1SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test1TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&submodule3SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&submodule3TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test3SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test3TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule5SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule5TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test23SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test23TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test24SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test24TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test25SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test25TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test26SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test26TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test4SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test4TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule6SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule6TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test27SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test27TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test28SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test28TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test29SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test29TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test30SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test30TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubmodule2SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubmodule2TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubsubmodule3SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubsubmodule3TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubsubmodule4SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubsubmodule4TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test2SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test2TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&submodule4SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&submodule4TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule7SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule7TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test31SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test31TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test32SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test32TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test33SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test33TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test34SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test34TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test5SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test5TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule8SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule8TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test35SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test35TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test36SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test36TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test37SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test37TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test38SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test38TeardownValue)
    );
    write_uint_to_file_2(
        SAMPLE_ATOMIC_UINT_LOAD(&test6SetupValue),
        SAMPLE_ATOMIC_UINT_LOAD(&test6TeardownValue)
    );
}

NBP_MODULE_SETUP(module1_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module1SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&mainModuleSetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module1SetupValue, 1);
}

NBP_MODULE_TEARDOWN(module1_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module1TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule1TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module1TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule2TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module1TeardownValue, 1);
}

NBP_MODULE_SETUP(module2_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module2SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&mainModuleSetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2SetupValue, 1);
}

NBP_MODULE_TEARDOWN(module2_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubmodule1TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test1TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule3TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubmodule2TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test2TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule4TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2TeardownValue, 1);
}

NBP_MODULE_SETUP(submodule1_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule1SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&module1SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&submodule1SetupValue, 1);
}

NBP_MODULE_TEARDOWN(submodule1_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule1TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule1TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule1TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule2TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&submodule1TeardownValue, 1);
}

NBP_MODULE_SETUP(submodule2_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule2SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&module1SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&submodule2SetupValue, 1);
}

NBP_MODULE_TEARDOWN(submodule2_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule3TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule4TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&submodule2TeardownValue, 1);
}

NBP_MODULE_SETUP(submodule3_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule3SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&module2SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&submodule3SetupValue, 1);
}

NBP_MODULE_TEARDOWN(submodule3_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule3TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test3TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule3TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule5TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule3TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test4TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule3TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule6TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&submodule3TeardownValue, 1);
}

NBP_MODULE_SETUP(submodule4_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule4SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&module2SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&submodule4SetupValue, 1);
}

NBP_MODULE_TEARDOWN(submodule4_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule7TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test5TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule8TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test6TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&submodule4TeardownValue, 1);
}

NBP_MODULE_SETUP(subsubmodule1_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule1SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule1SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&subsubmodule1SetupValue, 1);
}

NBP_MODULE_TEARDOWN(subsubmodule1_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule1TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test7TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule1TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test8TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule1TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test9TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule1TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test10TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&subsubmodule1TeardownValue, 1);
}

NBP_MODULE_SETUP(subsubmodule2_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule2SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule1SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&subsubmodule2SetupValue, 1);
}

NBP_MODULE_TEARDOWN(subsubmodule2_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test11TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test12TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test13TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test14TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&subsubmodule2TeardownValue, 1);
}

NBP_MODULE_SETUP(subsubmodule3_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule3SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule2SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&subsubmodule3SetupValue, 1);
}

NBP_MODULE_TEARDOWN(subsubmodule3_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule3TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test15TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule3TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test16TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule3TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test17TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule3TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test18TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&subsubmodule3TeardownValue, 1);
}

NBP_MODULE_SETUP(subsubmodule4_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule4SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule2SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&subsubmodule4SetupValue, 1);
}

NBP_MODULE_TEARDOWN(subsubmodule4_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test19TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test20TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test21TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test22TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&subsubmodule4TeardownValue, 1);
}

NBP_MODULE_SETUP(subsubmodule5_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule5SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule3SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&subsubmodule5SetupValue, 1);
}

NBP_MODULE_TEARDOWN(subsubmodule5_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule5TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test23TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule5TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test24TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule5TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test25TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule5TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test26TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&subsubmodule5TeardownValue, 1);
}

NBP_MODULE_SETUP(subsubmodule6_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule6SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule3SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&subsubmodule6SetupValue, 1);
}

NBP_MODULE_TEARDOWN(subsubmodule6_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule6TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test27TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule6TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test28TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule6TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test29TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule6TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test30TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&subsubmodule6TeardownValue, 1);
}

NBP_MODULE_SETUP(subsubmodule7_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule7SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule4SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&subsubmodule7SetupValue, 1);
}

NBP_MODULE_TEARDOWN(subsubmodule7_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule7TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test31TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule7TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test32TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule7TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test33TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule7TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test34TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&subsubmodule7TeardownValue, 1);
}

NBP_MODULE_SETUP(subsubmodule8_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule8SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule4SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&subsubmodule8SetupValue, 1);
}

NBP_MODULE_TEARDOWN(subsubmodule8_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule8TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test35TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule8TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test36TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule8TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test37TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &subsubmodule8TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test38TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&subsubmodule8TeardownValue, 1);
}

NBP_MODULE_SETUP(empty_submodule1_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &emptySubmodule1SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&module2SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&emptySubmodule1SetupValue, 1);
}

NBP_MODULE_TEARDOWN(empty_submodule1_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &emptySubmodule1TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubsubmodule1TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &emptySubmodule1TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubsubmodule2TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&emptySubmodule1TeardownValue, 1);
}

NBP_MODULE_SETUP(empty_submodule2_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &emptySubmodule2SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&module2SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&emptySubmodule2SetupValue, 1);
}

NBP_MODULE_TEARDOWN(empty_submodule2_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &emptySubmodule2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubsubmodule3TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &emptySubmodule2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubsubmodule4TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&emptySubmodule2TeardownValue, 1);
}

NBP_MODULE_SETUP(empty_subsubmodule1_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &emptySubsubmodule1SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubmodule1SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&emptySubsubmodule1SetupValue, 1);
}

NBP_MODULE_TEARDOWN(empty_subsubmodule1_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&emptySubsubmodule1TeardownValue, 1);
}

NBP_MODULE_SETUP(empty_subsubmodule2_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &emptySubsubmodule2SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubmodule1SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&emptySubsubmodule2SetupValue, 1);
}

NBP_MODULE_TEARDOWN(empty_subsubmodule2_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&emptySubsubmodule2TeardownValue, 1);
}

NBP_MODULE_SETUP(empty_subsubmodule3_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &emptySubsubmodule3SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubmodule2SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&emptySubsubmodule3SetupValue, 1);
}

NBP_MODULE_TEARDOWN(empty_subsubmodule3_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&emptySubsubmodule3TeardownValue, 1);
}

NBP_MODULE_SETUP(empty_subsubmodule4_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &emptySubsubmodule4SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&emptySubmodule2SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&emptySubsubmodule4SetupValue, 1);
}

NBP_MODULE_TEARDOWN(empty_subsubmodule4_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&emptySubsubmodule4TeardownValue, 1);
}

NBP_TEST_SETUP(test1_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test1SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&module2SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test1SetupValue, 1);
}

NBP_TEST_TEARDOWN(test1_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test1TeardownValue, 1);
}

NBP_TEST_SETUP(test2_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test2SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&module2SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test2SetupValue, 1);
}

NBP_TEST_TEARDOWN(test2_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test2TeardownValue, 1);
}

NBP_TEST_SETUP(test3_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test3SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule3SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test3SetupValue, 1);
}

NBP_TEST_TEARDOWN(test3_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test3TeardownValue, 1);
}

NBP_TEST_SETUP(test4_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test4SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule3SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test4SetupValue, 1);
}

NBP_TEST_TEARDOWN(test4_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test4TeardownValue, 1);
}

NBP_TEST_SETUP(test5_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test5SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule4SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test5SetupValue, 1);
}

NBP_TEST_TEARDOWN(test5_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test5TeardownValue, 1);
}

NBP_TEST_SETUP(test6_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test6SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule4SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test6SetupValue, 1);
}

NBP_TEST_TEARDOWN(test6_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test6TeardownValue, 1);
}

NBP_TEST_SETUP(test7_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test7SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule1SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test7SetupValue, 1);
}

NBP_TEST_TEARDOWN(test7_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test7TeardownValue, 1);
}

NBP_TEST_SETUP(test8_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test8SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule1SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test8SetupValue, 1);
}

NBP_TEST_TEARDOWN(test8_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test8TeardownValue, 1);
}

NBP_TEST_SETUP(test9_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test9SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule1SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test9SetupValue, 1);
}

NBP_TEST_TEARDOWN(test9_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test9TeardownValue, 1);
}

NBP_TEST_SETUP(test10_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test10SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule1SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test10SetupValue, 1);
}

NBP_TEST_TEARDOWN(test10_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test10TeardownValue, 1);
}

NBP_TEST_SETUP(test11_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test11SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule2SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test11SetupValue, 1);
}

NBP_TEST_TEARDOWN(test11_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test11TeardownValue, 1);
}

NBP_TEST_SETUP(test12_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test12SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule2SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test12SetupValue, 1);
}

NBP_TEST_TEARDOWN(test12_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test12TeardownValue, 1);
}

NBP_TEST_SETUP(test13_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test13SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule2SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test13SetupValue, 1);
}

NBP_TEST_TEARDOWN(test13_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test13TeardownValue, 1);
}

NBP_TEST_SETUP(test14_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test14SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule2SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test14SetupValue, 1);
}

NBP_TEST_TEARDOWN(test14_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test14TeardownValue, 1);
}

NBP_TEST_SETUP(test15_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test15SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule3SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test15SetupValue, 1);
}

NBP_TEST_TEARDOWN(test15_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test15TeardownValue, 1);
}

NBP_TEST_SETUP(test16_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test16SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule3SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test16SetupValue, 1);
}

NBP_TEST_TEARDOWN(test16_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test16TeardownValue, 1);
}

NBP_TEST_SETUP(test17_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test17SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule3SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test17SetupValue, 1);
}

NBP_TEST_TEARDOWN(test17_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test17TeardownValue, 1);
}

NBP_TEST_SETUP(test18_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test18SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule3SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test18SetupValue, 1);
}

NBP_TEST_TEARDOWN(test18_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test18TeardownValue, 1);
}

NBP_TEST_SETUP(test19_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test19SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule4SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test19SetupValue, 1);
}

NBP_TEST_TEARDOWN(test19_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test19TeardownValue, 1);
}

NBP_TEST_SETUP(test20_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test20SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule4SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test20SetupValue, 1);
}

NBP_TEST_TEARDOWN(test20_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test20TeardownValue, 1);
}

NBP_TEST_SETUP(test21_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test21SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule4SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test21SetupValue, 1);
}

NBP_TEST_TEARDOWN(test21_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test21TeardownValue, 1);
}

NBP_TEST_SETUP(test22_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test22SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule4SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test22SetupValue, 1);
}

NBP_TEST_TEARDOWN(test22_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test22TeardownValue, 1);
}

NBP_TEST_SETUP(test23_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test23SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule5SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test23SetupValue, 1);
}

NBP_TEST_TEARDOWN(test23_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test23TeardownValue, 1);
}

NBP_TEST_SETUP(test24_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test24SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule5SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test24SetupValue, 1);
}

NBP_TEST_TEARDOWN(test24_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test24TeardownValue, 1);
}

NBP_TEST_SETUP(test25_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test25SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule5SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test25SetupValue, 1);
}

NBP_TEST_TEARDOWN(test25_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test25TeardownValue, 1);
}

NBP_TEST_SETUP(test26_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test26SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule5SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test26SetupValue, 1);
}

NBP_TEST_TEARDOWN(test26_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test26TeardownValue, 1);
}

NBP_TEST_SETUP(test27_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test27SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule6SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test27SetupValue, 1);
}

NBP_TEST_TEARDOWN(test27_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test27TeardownValue, 1);
}

NBP_TEST_SETUP(test28_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test28SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule6SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test28SetupValue, 1);
}

NBP_TEST_TEARDOWN(test28_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test28TeardownValue, 1);
}

NBP_TEST_SETUP(test29_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test29SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule6SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test29SetupValue, 1);
}

NBP_TEST_TEARDOWN(test29_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test29TeardownValue, 1);
}

NBP_TEST_SETUP(test30_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test30SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule6SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test30SetupValue, 1);
}

NBP_TEST_TEARDOWN(test30_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test30TeardownValue, 1);
}

NBP_TEST_SETUP(test31_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test31SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule7SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test31SetupValue, 1);
}

NBP_TEST_TEARDOWN(test31_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test31TeardownValue, 1);
}

NBP_TEST_SETUP(test32_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test32SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule7SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test32SetupValue, 1);
}

NBP_TEST_TEARDOWN(test32_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test32TeardownValue, 1);
}

NBP_TEST_SETUP(test33_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test33SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule7SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test33SetupValue, 1);
}

NBP_TEST_TEARDOWN(test33_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test33TeardownValue, 1);
}

NBP_TEST_SETUP(test34_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test34SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule7SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test34SetupValue, 1);
}

NBP_TEST_TEARDOWN(test34_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test34TeardownValue, 1);
}

NBP_TEST_SETUP(test35_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test35SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule8SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test35SetupValue, 1);
}

NBP_TEST_TEARDOWN(test35_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test35TeardownValue, 1);
}

NBP_TEST_SETUP(test36_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test36SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule8SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test36SetupValue, 1);
}

NBP_TEST_TEARDOWN(test36_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test36TeardownValue, 1);
}

NBP_TEST_SETUP(test37_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test37SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule8SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test37SetupValue, 1);
}

NBP_TEST_TEARDOWN(test37_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test37TeardownValue, 1);
}

NBP_TEST_SETUP(test38_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test38SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule8SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test38SetupValue, 1);
}

NBP_TEST_TEARDOWN(test38_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test38TeardownValue, 1);
}
