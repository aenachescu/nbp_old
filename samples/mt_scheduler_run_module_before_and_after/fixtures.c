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

// LCOV_EXCL_START

NBP_MODULE_SETUP(empty_module_setup)
{
    write_message_to_file("this message should not be printed");
}

NBP_MODULE_TEARDOWN(empty_module_teardown)
{
    write_message_to_file("this message should not be printed");
}

// LCOV_EXCL_STOP

void print_fixture_values();

NBP_MODULE_SETUP(module_setup)
{
    sample_utils_test_data_t* moduleData = NBP_MEMORY_NULL_POINTER;
    sample_utils_test_data_t* parentData = NBP_MEMORY_NULL_POINTER;
    int isMainModule = 0;

    isMainModule = strcmp(
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS),
        "mt_scheduler_run_module_before_and_after") == 0 ? 1 : 0;

    if (isMainModule == 1) {
        sample_utils_init();
    }

    sample_utils_create_test_data_copy(NBP_MODULE_GET_NAME(NBP_MODULE_THIS));

    moduleData = sample_utils_get_test_data_or_create(
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
    if (moduleData == NBP_MEMORY_NULL_POINTER) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
    } else {
        SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&moduleData->setupValue, 1);
    }

    if (isMainModule == 0) {
        parentData = sample_utils_get_test_data_or_create(
            NBP_MODULE_GET_NAME(NBP_MODULE_GET_PARENT(NBP_MODULE_THIS))
        );
        if (parentData == NBP_MEMORY_NULL_POINTER) {
            NBP_ERROR_REPORT(NBP_ERROR_CODE_OUT_OF_MEMORY);
            NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        } else {
            SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
                &moduleData->setupValue,
                SAMPLE_ATOMIC_UINT_LOAD(&parentData->setupValue)
            );
        }
    }
}

NBP_MODULE_TEARDOWN(module_teardown)
{
    sample_utils_test_data_t* moduleData = NBP_MEMORY_NULL_POINTER;
    sample_utils_test_data_t* childData = NBP_MEMORY_NULL_POINTER;
    nbp_module_details_t* submodule = NBP_MEMORY_NULL_POINTER;
    nbp_test_details_t* test = NBP_MEMORY_NULL_POINTER;
    int isMainModule = 0;

    isMainModule = strcmp(
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS),
        "mt_scheduler_run_module_before_and_after") == 0 ? 1 : 0;

    moduleData = sample_utils_get_test_data_or_create(
        NBP_MODULE_GET_NAME(NBP_MODULE_THIS)
    );
    if (moduleData != NBP_MEMORY_NULL_POINTER) {
        NBP_MODULE_FOR_EACH_TEST(NBP_MODULE_THIS, test) {
            childData = sample_utils_get_test_data_or_create(
                NBP_TEST_GET_NAME(test)
            );
            if (childData != NBP_MEMORY_NULL_POINTER) {
                SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
                    &moduleData->teardownValue,
                    SAMPLE_ATOMIC_UINT_LOAD(&childData->teardownValue)
                );
            } else {
                NBP_ERROR_REPORT(NBP_ERROR_CODE_OUT_OF_MEMORY);
                NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
            }
        }

        NBP_MODULE_FOR_EACH_SUBMODULE(NBP_MODULE_THIS, submodule) {
            childData = sample_utils_get_test_data_or_create(
                NBP_MODULE_GET_NAME(submodule)
            );
            if (childData != NBP_MEMORY_NULL_POINTER) {
                SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
                    &moduleData->teardownValue,
                    SAMPLE_ATOMIC_UINT_LOAD(&childData->teardownValue)
                );
            } else {
                NBP_ERROR_REPORT(NBP_ERROR_CODE_OUT_OF_MEMORY);
                NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
            }
        }

        SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&moduleData->teardownValue, 1);
    } else {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
    }

    sample_utils_delete_test_data_copy(NBP_MODULE_GET_NAME(NBP_MODULE_THIS));

    if (isMainModule == 1) {
        print_fixture_values();
        sample_utils_uninit();
    }
}

NBP_TEST_SETUP(test_setup)
{
    sample_utils_test_data_t* moduleData = NBP_MEMORY_NULL_POINTER;
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    sample_utils_create_test_data_copy(NBP_TEST_GET_NAME(NBP_TEST_THIS));

    testData = sample_utils_get_test_data_or_create(
        NBP_TEST_GET_NAME(NBP_TEST_THIS)
    );

    moduleData = sample_utils_get_test_data_or_create(
        NBP_MODULE_GET_NAME(NBP_TEST_GET_MODULE(NBP_TEST_THIS))
    );

    if (testData != NBP_MEMORY_NULL_POINTER &&
        moduleData != NBP_MEMORY_NULL_POINTER) {
        SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(
            &testData->setupValue,
            SAMPLE_ATOMIC_UINT_LOAD(&moduleData->setupValue)
        );
        SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&testData->setupValue, 1);
    } else {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
    }
}

NBP_TEST_TEARDOWN(test_teardown)
{
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    testData = sample_utils_get_test_data_or_create(
        NBP_TEST_GET_NAME(NBP_TEST_THIS)
    );
    if (testData != NBP_MEMORY_NULL_POINTER) {
        SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(&testData->teardownValue, 1);
    } else {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
    }

    sample_utils_delete_test_data_copy(NBP_TEST_GET_NAME(NBP_TEST_THIS));
}

const char* names[] = {
"mt_scheduler_run_module_before_and_after",
    "module1",
        "empty_module1",
            "empty_submodule1",
            "empty_submodule2",
        "submodule1",
            "subsubmodule1",
                "test5",
                "test6",
                "test7",
                "test8",
            "subsubmodule2",
                "test9",
                "test10",
                "test11",
                "test12",
        "empty_module2",
            "empty_submodule3",
            "empty_submodule4",
        "submodule2",
            "subsubmodule3",
                "test13",
                "test14",
                "test15",
                "test16",
            "subsubmodule4",
                "test17",
                "test18",
                "test19",
                "test20",
    "module2",
        "empty_module3",
            "empty_submodule5",
            "empty_submodule6",
        "submodule3",
            "subsubmodule5",
                "test21",
                "test22",
                "test23",
                "test24",
            "subsubmodule6",
                "test25",
                "test26",
                "test27",
                "test28",
        "empty_module4",
            "empty_submodule7",
            "empty_submodule8",
        "submodule4",
            "subsubmodule7",
                "test29",
                "test30",
                "test31",
                "test32",
            "subsubmodule8",
                "test33",
                "test34",
                "test35",
                "test36",
    "test1",
    "test2",
    "module3",
        "empty_module5",
            "empty_submodule9",
            "empty_submodule10",
        "submodule5",
            "subsubmodule9",
                "test37",
                "test38",
                "test39",
                "test40",
            "subsubmodule10",
                "test41",
                "test42",
                "test43",
                "test44",
        "empty_module6",
            "empty_submodule11",
            "empty_submodule12",
        "submodule6",
            "subsubmodule11",
                "test45",
                "test46",
                "test47",
                "test48",
            "subsubmodule12",
                "test49",
                "test50",
                "test51",
                "test52",
    "module4",
        "empty_module7",
            "empty_submodule13",
            "empty_submodule14",
        "submodule7",
            "subsubmodule13",
                "test59",
                "test60",
                "test61",
                "test62",
            "test55",
            "subsubmodule14",
                "test63",
                "test64",
                "test65",
                "test66",
            "test56",
        "test53",
        "empty_module8",
            "empty_submodule15",
            "empty_submodule16",
        "submodule8",
            "test57",
            "subsubmodule15",
                "test67",
                "test68",
                "test69",
                "test70",
            "test58",
            "subsubmodule16",
                "test71",
                "test72",
                "test73",
                "test74",
        "test54",
    "test3",
    "test4",
    "module5",
        "empty_module9",
            "empty_submodule17",
            "empty_submodule18",
        "submodule9",
            "subsubmodule17",
                "test81",
                "test82",
                "test83",
                "test84",
            "test77",
            "subsubmodule18",
                "test85",
                "test86",
                "test87",
                "test88",
            "test78",
        "test75",
        "empty_module10",
            "empty_submodule19",
            "empty_submodule20",
        "submodule10",
            "test79",
            "subsubmodule19",
                "test89",
                "test90",
                "test91",
                "test92",
            "test80",
            "subsubmodule20",
                "test93",
                "test94",
                "test95",
                "test96",
        "test76",
    "module6",
        "empty_module11",
            "empty_submodule21",
            "empty_submodule22",
        "submodule11",
            "subsubmodule21",
                "test103",
                "test104",
                "test105",
                "test106",
            "test99",
            "subsubmodule22",
                "test107",
                "test108",
                "test109",
                "test110",
            "test100",
        "test97",
        "empty_module12",
            "empty_submodule23",
            "empty_submodule24",
        "submodule12",
            "test101",
            "subsubmodule23",
                "test111",
                "test112",
                "test113",
                "test114",
            "test102",
            "subsubmodule24",
                "test115",
                "test116",
                "test117",
                "test118",
        "test98",
    NBP_MEMORY_NULL_POINTER
};

void print_fixture_values()
{
    int i = 0;
    sample_utils_test_data_t* testData = NBP_MEMORY_NULL_POINTER;

    while (names[i] != NBP_MEMORY_NULL_POINTER) {
        testData = sample_utils_get_test_data_or_create(names[i]);
        if (testData == NBP_MEMORY_NULL_POINTER) {
            NBP_ERROR_REPORT(NBP_ERROR_CODE_OUT_OF_MEMORY);
            NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        } else {
            write_uint_to_file_2(
                SAMPLE_ATOMIC_UINT_LOAD(&testData->setupValue),
                SAMPLE_ATOMIC_UINT_LOAD(&testData->teardownValue)
            );
        }
        i++;
    }
}
