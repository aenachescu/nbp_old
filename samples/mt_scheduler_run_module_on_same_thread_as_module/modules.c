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

extern SAMPLE_THREAD_ID_TYPE test44ThreadId;
extern SAMPLE_THREAD_ID_TYPE test45ThreadId;
extern SAMPLE_THREAD_ID_TYPE test46ThreadId;
extern SAMPLE_THREAD_ID_TYPE test47ThreadId;
extern SAMPLE_THREAD_ID_TYPE test48ThreadId;
extern SAMPLE_THREAD_ID_TYPE test49ThreadId;
extern SAMPLE_THREAD_ID_TYPE test50ThreadId;
extern SAMPLE_THREAD_ID_TYPE test51ThreadId;
extern SAMPLE_THREAD_ID_TYPE test52ThreadId;
extern SAMPLE_THREAD_ID_TYPE test53ThreadId;
extern SAMPLE_THREAD_ID_TYPE test54ThreadId;
extern SAMPLE_THREAD_ID_TYPE test55ThreadId;
extern SAMPLE_THREAD_ID_TYPE test56ThreadId;
extern SAMPLE_THREAD_ID_TYPE test57ThreadId;
extern SAMPLE_THREAD_ID_TYPE test58ThreadId;
extern SAMPLE_THREAD_ID_TYPE test59ThreadId;
extern SAMPLE_THREAD_ID_TYPE test60ThreadId;
extern SAMPLE_THREAD_ID_TYPE test61ThreadId;
extern SAMPLE_THREAD_ID_TYPE test62ThreadId;
extern SAMPLE_THREAD_ID_TYPE test63ThreadId;
extern SAMPLE_THREAD_ID_TYPE test64ThreadId;
extern SAMPLE_THREAD_ID_TYPE test65ThreadId;
extern SAMPLE_THREAD_ID_TYPE test66ThreadId;
extern SAMPLE_THREAD_ID_TYPE test67ThreadId;
extern SAMPLE_THREAD_ID_TYPE test68ThreadId;
extern SAMPLE_THREAD_ID_TYPE test69ThreadId;
extern SAMPLE_THREAD_ID_TYPE test70ThreadId;
extern SAMPLE_THREAD_ID_TYPE test71ThreadId;
extern SAMPLE_THREAD_ID_TYPE test72ThreadId;
extern SAMPLE_THREAD_ID_TYPE test73ThreadId;
extern SAMPLE_THREAD_ID_TYPE test74ThreadId;
extern SAMPLE_THREAD_ID_TYPE test75ThreadId;
extern SAMPLE_THREAD_ID_TYPE test76ThreadId;
extern SAMPLE_THREAD_ID_TYPE test77ThreadId;

/*******************************************************************************
 * module6 implementation
 ******************************************************************************/

NBP_MODULE(module6)
{
    NBP_TEST_RUN(test44);
    NBP_TEST_RUN(test45);
    NBP_TEST_RUN(test46);
    NBP_TEST_RUN(test47);
}

NBP_TEST(test44)
{
    SAMPLE_SLEEP();

    test44ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test44ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test45)
{
    SAMPLE_SLEEP();

    test45ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test45ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test46)
{
    SAMPLE_SLEEP();

    test46ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test46ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test47)
{
    SAMPLE_SLEEP();

    test47ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test47ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

/*******************************************************************************
 * module7 implementation
 ******************************************************************************/

NBP_MODULE(module7)
{
    NBP_TEST_RUN(test48);
    NBP_TEST_RUN(test49);
    NBP_TEST_RUN(test50);
    NBP_TEST_RUN(test51);
}

NBP_TEST(test48)
{
    SAMPLE_SLEEP();

    test48ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test48ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test49)
{
    SAMPLE_SLEEP();

    test49ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test49ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test50)
{
    SAMPLE_SLEEP();

    test50ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test50ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test51)
{
    SAMPLE_SLEEP();

    test51ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test51ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

/*******************************************************************************
 * module8 implementation
 ******************************************************************************/

NBP_MODULE(module8)
{
    NBP_TEST_RUN(test52);
    NBP_TEST_RUN(test53);
    NBP_TEST_RUN(test54);
    NBP_TEST_RUN(test55);
}

NBP_TEST(test52)
{
    SAMPLE_SLEEP();

    test52ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test52ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test53)
{
    SAMPLE_SLEEP();

    test53ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test53ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test54)
{
    SAMPLE_SLEEP();

    test54ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test54ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test55)
{
    SAMPLE_SLEEP();

    test55ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test55ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

/*******************************************************************************
 * module9 implementation
 ******************************************************************************/

NBP_MODULE(module9)
{
    NBP_MODULE_RUN(empty_module5);
    NBP_MODULE_RUN(submodule5);
    NBP_TEST_RUN(test56);
    NBP_MODULE_RUN(empty_module6);
    NBP_MODULE_RUN(submodule6);
    NBP_TEST_RUN(test57);
}

NBP_MODULE(empty_module5,
    NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
    NBP_MODULE_RUN(empty_submodule9);
    NBP_MODULE_RUN(empty_submodule10);
}

NBP_MODULE(empty_module6,
    NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
    NBP_MODULE_RUN(empty_submodule11);
    NBP_MODULE_RUN(empty_submodule12);
}

NBP_MODULE(empty_submodule9,
    NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
}

NBP_MODULE(empty_submodule10,
    NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
}

NBP_MODULE(empty_submodule11,
    NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
}

NBP_MODULE(empty_submodule12,
    NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
}

NBP_MODULE(submodule5)
{
    NBP_MODULE_RUN(subsubmodule9);
    NBP_TEST_RUN(test58);
    NBP_MODULE_RUN(subsubmodule10);
    NBP_TEST_RUN(test59);
}

NBP_MODULE(submodule6)
{
    NBP_TEST_RUN(test60);
    NBP_MODULE_RUN(subsubmodule11);
    NBP_TEST_RUN(test61);
    NBP_MODULE_RUN(subsubmodule12);
}

NBP_MODULE(subsubmodule9)
{
    NBP_TEST_RUN(test62);
    NBP_TEST_RUN(test63);
}

NBP_MODULE(subsubmodule10)
{
    NBP_TEST_RUN(test64);
    NBP_TEST_RUN(test65);
}

NBP_MODULE(subsubmodule11)
{
    NBP_TEST_RUN(test66);
    NBP_TEST_RUN(test67);
}

NBP_MODULE(subsubmodule12)
{
    NBP_TEST_RUN(test68);
    NBP_TEST_RUN(test69);
}

NBP_TEST(test56)
{
    SAMPLE_SLEEP();

    test56ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test56ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test57)
{
    SAMPLE_SLEEP();

    test57ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test57ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test58)
{
    SAMPLE_SLEEP();

    test58ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test58ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test59)
{
    SAMPLE_SLEEP();

    test59ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test59ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test60)
{
    SAMPLE_SLEEP();

    test60ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test60ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test61)
{
    SAMPLE_SLEEP();

    test61ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test61ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test62)
{
    SAMPLE_SLEEP();

    test62ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test62ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test63)
{
    SAMPLE_SLEEP();

    test63ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test63ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test64)
{
    SAMPLE_SLEEP();

    test64ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test64ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test65)
{
    SAMPLE_SLEEP();

    test65ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test65ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test66)
{
    SAMPLE_SLEEP();

    test66ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test66ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test67)
{
    SAMPLE_SLEEP();

    test67ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test67ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test68)
{
    SAMPLE_SLEEP();

    test68ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test68ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test69)
{
    SAMPLE_SLEEP();

    test69ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test69ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

/*******************************************************************************
 * module10 implementation
 ******************************************************************************/

NBP_MODULE(module10)
{
    NBP_MODULE_RUN(empty_module7);
    NBP_MODULE_RUN(submodule7);
    NBP_MODULE_RUN(empty_module8);
    NBP_MODULE_RUN(submodule8);
}

NBP_MODULE(empty_module7,
    NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
    NBP_MODULE_RUN(empty_submodule13);
    NBP_MODULE_RUN(empty_submodule14);
}

NBP_MODULE(empty_module8,
    NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
    NBP_MODULE_RUN(empty_submodule15);
    NBP_MODULE_RUN(empty_submodule16);
}

NBP_MODULE(empty_submodule13,
    NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
}

NBP_MODULE(empty_submodule14,
    NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
}

NBP_MODULE(empty_submodule15,
    NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
}

NBP_MODULE(empty_submodule16,
    NBP_MODULE_FIXTURES(setupEmptyModule, teardownEmptyModule))
{
}

NBP_MODULE(submodule7)
{
    NBP_MODULE_RUN(subsubmodule13);
    NBP_MODULE_RUN(subsubmodule14);
}

NBP_MODULE(submodule8)
{
    NBP_MODULE_RUN(subsubmodule15);
    NBP_MODULE_RUN(subsubmodule16);
}

NBP_MODULE(subsubmodule13)
{
    NBP_TEST_RUN(test70);
    NBP_TEST_RUN(test71);
}

NBP_MODULE(subsubmodule14)
{
    NBP_TEST_RUN(test72);
    NBP_TEST_RUN(test73);
}

NBP_MODULE(subsubmodule15)
{
    NBP_TEST_RUN(test74);
    NBP_TEST_RUN(test75);
}

NBP_MODULE(subsubmodule16)
{
    NBP_TEST_RUN(test76);
    NBP_TEST_RUN(test77);
}

NBP_TEST(test70)
{
    SAMPLE_SLEEP();

    test70ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test70ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test71)
{
    SAMPLE_SLEEP();

    test71ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test71ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test72)
{
    SAMPLE_SLEEP();

    test72ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test72ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test73)
{
    SAMPLE_SLEEP();

    test73ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test73ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test74)
{
    SAMPLE_SLEEP();

    test74ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test74ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test75)
{
    SAMPLE_SLEEP();

    test75ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test75ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test76)
{
    SAMPLE_SLEEP();

    test76ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test76ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}

NBP_TEST(test77)
{
    SAMPLE_SLEEP();

    test77ThreadId = SAMPLE_THREAD_GET_ID();
    NBP_ASSERT(
        test77ThreadId != SAMPLE_THREAD_ID_INVALID_VALUE,
        NBP_ASSERT_FATAL
    );
}
