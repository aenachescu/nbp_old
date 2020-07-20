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

#include <nbp.h>

#include "../sample_utils.h"

#define FIXTURE_VALUE_UNLOADED 0xFFFFFFFF

unsigned int test1_test3TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int test1_test4TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int test1_test5TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int test1_test6TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int test1_module1TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int test1_module2TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int test1_module3TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int test1_module4TeardownValue = FIXTURE_VALUE_UNLOADED;

unsigned int test2_test3TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int test2_test4TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int test2_test5TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int test2_test6TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int test2_module1TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int test2_module2TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int test2_module3TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int test2_module4TeardownValue = FIXTURE_VALUE_UNLOADED;

unsigned int test3_test1TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int test3_test2TeardownValue = FIXTURE_VALUE_UNLOADED;

unsigned int test4_test1TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int test4_test2TeardownValue = FIXTURE_VALUE_UNLOADED;

unsigned int module1_test1TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int module1_test2TeardownValue = FIXTURE_VALUE_UNLOADED;

unsigned int module2_test1TeardownValue = FIXTURE_VALUE_UNLOADED;
unsigned int module2_test2TeardownValue = FIXTURE_VALUE_UNLOADED;

SAMPLE_ATOMIC_UINT_TYPE mainModuleSetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE mainModuleTeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

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

SAMPLE_ATOMIC_UINT_TYPE test39SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test39TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test40SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test40TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test41SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test41TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test42SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test42TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test43SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test43TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test44SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test44TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test45SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test45TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE test46SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE test46TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE module1SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE module1TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE module2SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE module2TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE module3SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE module3TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

SAMPLE_ATOMIC_UINT_TYPE module4SetupValue = SAMPLE_ATOMIC_UINT_INIT(0);
SAMPLE_ATOMIC_UINT_TYPE module4TeardownValue = SAMPLE_ATOMIC_UINT_INIT(0);

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

NBP_MODULE_SETUP(empty_module_setup)
{
    write_message_to_file("this message should not be printed");
}

NBP_MODULE_TEARDOWN(empty_module_teardown)
{
    write_message_to_file("this message should not be printed");
}

NBP_MODULE_SETUP(main_module_setup)
{
    write_message_to_file("main_module_setup");
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&mainModuleSetupValue, 1);
}

NBP_MODULE_TEARDOWN(main_module_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &mainModuleTeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test1TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &mainModuleTeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test2TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &mainModuleTeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test3TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &mainModuleTeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test4TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &mainModuleTeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test5TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &mainModuleTeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test6TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &mainModuleTeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&module1TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &mainModuleTeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&module2TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &mainModuleTeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&module3TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &mainModuleTeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&module4TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&mainModuleTeardownValue, 1);

    write_message_to_file("main_module_teardown");
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&mainModuleTeardownValue));

    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&module1TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test7TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test8TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test9TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test10TeardownValue));

    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&module3TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test15TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test16TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test17TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test18TeardownValue));

    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test3TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test5TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test1TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test2TeardownValue));

    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&module2TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&submodule1TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule1TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test31TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test23TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test24TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule2TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test32TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test25TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test26TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test11TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test12TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&submodule2TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule3TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test33TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test27TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test28TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule4TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test34TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test29TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test30TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test13TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test14TeardownValue));

    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&module4TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&submodule3TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule5TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test43TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test35TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test36TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule6TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test44TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test37TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test38TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test19TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test20TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&submodule4TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule7TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test45TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test39TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test40TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule8TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test46TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test41TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test42TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test21TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test22TeardownValue));

    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test4TeardownValue));
    write_uint_to_file(SAMPLE_ATOMIC_UINT_LOAD(&test6TeardownValue));
}

NBP_TEST_SETUP(test1_setup)
{
    test1_test3TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&test3TeardownValue);
    test1_test4TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&test4TeardownValue);
    test1_test5TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&test5TeardownValue);
    test1_test6TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&test6TeardownValue);

    test1_module1TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&module1TeardownValue);
    test1_module2TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&module2TeardownValue);
    test1_module3TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&module3TeardownValue);
    test1_module4TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&module4TeardownValue);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test1SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&mainModuleSetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test1SetupValue, 1);
}

NBP_TEST_TEARDOWN(test1_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test1TeardownValue, 1);
}

NBP_TEST_SETUP(test2_setup)
{
    test2_test3TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&test3TeardownValue);
    test2_test4TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&test4TeardownValue);
    test2_test5TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&test5TeardownValue);
    test2_test6TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&test6TeardownValue);

    test2_module1TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&module1TeardownValue);
    test2_module2TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&module2TeardownValue);
    test2_module3TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&module3TeardownValue);
    test2_module4TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&module4TeardownValue);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test2SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&mainModuleSetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test2SetupValue, 1);
}

NBP_TEST_TEARDOWN(test2_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test2TeardownValue, 1);
}

NBP_TEST_SETUP(test3_setup)
{
    test3_test1TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&test1TeardownValue);
    test3_test2TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&test2TeardownValue);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test3SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&mainModuleSetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test3SetupValue, 1);
}

NBP_TEST_TEARDOWN(test3_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test3TeardownValue, 1);
}

NBP_TEST_SETUP(test4_setup)
{
    test4_test1TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&test1TeardownValue);
    test4_test2TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&test2TeardownValue);

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test4SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&mainModuleSetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&mainModuleSetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&mainModuleSetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&module1SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&module1SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&module1SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&module1SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&module2SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&module2SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&module2SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&module2SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&module3SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&module3SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&module3SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&module3SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&module4SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&module4SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&module4SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&module4SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&submodule1SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&submodule1SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&submodule1SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&submodule1SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&submodule2SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&submodule2SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&submodule2SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&submodule2SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule1SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule2SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule3SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule4SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&submodule3SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&submodule3SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&submodule3SetupValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&submodule3SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test38SetupValue, 1);
}

NBP_TEST_TEARDOWN(test38_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test38TeardownValue, 1);
}

NBP_TEST_SETUP(test39_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test39SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule4SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test39SetupValue, 1);
}

NBP_TEST_TEARDOWN(test39_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test39TeardownValue, 1);
}

NBP_TEST_SETUP(test40_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test40SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule4SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test40SetupValue, 1);
}

NBP_TEST_TEARDOWN(test40_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test40TeardownValue, 1);
}

NBP_TEST_SETUP(test41_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test41SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule4SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test41SetupValue, 1);
}

NBP_TEST_TEARDOWN(test41_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test41TeardownValue, 1);
}

NBP_TEST_SETUP(test42_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test42SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule4SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test42SetupValue, 1);
}

NBP_TEST_TEARDOWN(test42_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test42TeardownValue, 1);
}

NBP_TEST_SETUP(test43_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test43SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule5SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test43SetupValue, 1);
}

NBP_TEST_TEARDOWN(test43_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test43TeardownValue, 1);
}

NBP_TEST_SETUP(test44_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test44SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule6SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test44SetupValue, 1);
}

NBP_TEST_TEARDOWN(test44_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test44TeardownValue, 1);
}

NBP_TEST_SETUP(test45_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test45SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule7SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test45SetupValue, 1);
}

NBP_TEST_TEARDOWN(test45_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test45TeardownValue, 1);
}

NBP_TEST_SETUP(test46_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &test46SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule8SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test46SetupValue, 1);
}

NBP_TEST_TEARDOWN(test46_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&test46TeardownValue, 1);
}

NBP_MODULE_SETUP(module1_setup)
{
    module1_test1TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&test1TeardownValue);
    module1_test2TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&test2TeardownValue);

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
        SAMPLE_ATOMIC_UINT_LOAD(&test7TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module1TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test8TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module1TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test9TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module1TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test10TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module1TeardownValue, 1);
}

NBP_MODULE_SETUP(module2_setup)
{
    module2_test1TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&test1TeardownValue);
    module2_test2TeardownValue = SAMPLE_ATOMIC_UINT_LOAD(&test2TeardownValue);

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
        SAMPLE_ATOMIC_UINT_LOAD(&test11TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test12TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test13TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test14TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule1TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule2TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module2TeardownValue, 1);
}

NBP_MODULE_SETUP(module3_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module3SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&mainModuleSetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module3SetupValue, 1);
}

NBP_MODULE_TEARDOWN(module3_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module3TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test15TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module3TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test16TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module3TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test17TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module3TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test18TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module3TeardownValue, 1);
}

NBP_MODULE_SETUP(module4_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module4SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&mainModuleSetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4SetupValue, 1);
}

NBP_MODULE_TEARDOWN(module4_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test19TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test20TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test21TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test22TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule3TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &module4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&submodule4TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&module4TeardownValue, 1);
}

NBP_MODULE_SETUP(submodule1_setup)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule1SetupValue,
        SAMPLE_ATOMIC_UINT_LOAD(&module2SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&submodule1SetupValue, 1);
}

NBP_MODULE_TEARDOWN(submodule1_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule1TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test23TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule1TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test24TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule1TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test25TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule1TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test26TeardownValue)
    );

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
        SAMPLE_ATOMIC_UINT_LOAD(&module2SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&submodule2SetupValue, 1);
}

NBP_MODULE_TEARDOWN(submodule2_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test27TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test28TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test29TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule2TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test30TeardownValue)
    );

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
        SAMPLE_ATOMIC_UINT_LOAD(&module4SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&submodule3SetupValue, 1);
}

NBP_MODULE_TEARDOWN(submodule3_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule3TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test35TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule3TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test36TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule3TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test37TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule3TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test38TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule3TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule5TeardownValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&module4SetupValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&submodule4SetupValue, 1);
}

NBP_MODULE_TEARDOWN(submodule4_teardown)
{
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test39TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test40TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test41TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&test42TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule7TeardownValue)
    );
    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
        &submodule4TeardownValue,
        SAMPLE_ATOMIC_UINT_LOAD(&subsubmodule8TeardownValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&test31TeardownValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&test32TeardownValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&test33TeardownValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&test34TeardownValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&test43TeardownValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&test44TeardownValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&test45TeardownValue)
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
        SAMPLE_ATOMIC_UINT_LOAD(&test46TeardownValue)
    );

    SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&subsubmodule8TeardownValue, 1);
}
