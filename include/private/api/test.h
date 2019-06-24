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

#ifndef NBP_PRIVATE_API_TEST_H
#define NBP_PRIVATE_API_TEST_H

/*
 * TODO: add docs
 */
#define NBP_BEFORE_TEST(name)                                                  \
    void nbp_before_test_ ## name(nbp_test_details_t* test)

/*
 * TODO: add docs
 */
#define NBP_CALL_BEFORE_TEST(func)                                             \
    NBP_BEFORE_TEST(func);                                                     \
    beforeTest = nbp_before_test_ ## func

/*
 * TODO: add docs
 */
#define NBP_RESET_BEFORE_TEST()                                                \
    beforeTest = 0x0

/*
 * TODO: add docs
 */
#define NBP_AFTER_TEST(name)                                                   \
    void nbp_after_test_ ## name(nbp_test_details_t* test)

/*
 * TODO: add docs
 */
#define NBP_CALL_AFTER_TEST(func)                                              \
    NBP_AFTER_TEST(func);                                                      \
    afterTest = nbp_after_test_ ## func

/*
 * TODO: add docs
 */
#define NBP_RESET_AFTER_TEST()                                                 \
    afterTest = 0x0

/*
 * TODO: add docs
 */
#define NBP_TEST(name)                                                         \
    void nbp_test_ ## name(                                                    \
        nbp_test_details_t*                                                    \
    );                                                                         \
    nbp_test_details_t nbpTestDetails ## name = {                              \
        .testName               = #name,                                       \
        .testFunc               = nbp_test_ ## name,                           \
        .beforeTestFunc         = 0x0,                                         \
        .afterTestFunc          = 0x0,                                         \
        .module                 = 0x0,                                         \
        .passedChecks           = 0,                                           \
        .failedChecks           = 0,                                           \
        .passedTestAsserts      = 0,                                           \
        .failedTestAsserts      = 0,                                           \
        .passedModuleAsserts    = 0,                                           \
        .failedModuleAsserts    = 0,                                           \
        .passedAsserts          = 0,                                           \
        .failedAsserts          = 0,                                           \
        .testState              = NBP_TEST_STATE_NOT_INITIALIZED,              \
        .next                   = 0x0,                                         \
        .prev                   = 0x0                                          \
    };                                                                         \
    void nbp_test_ ## name(                                                    \
        nbp_test_details_t* test                                               \
    )

/*
 * TODO: add docs
 */
#define NBP_CALL_TEST(name)                                                    \
    extern nbp_test_details_t nbpTestDetails ## name;                          \
    nbp_call_test(                                                             \
        & nbpTestDetails ## name,                                              \
        module,                                                                \
        beforeTest,                                                            \
        afterTest                                                              \
    )

/*
 * TODO: add docs
 */
#define NBP_THIS_TEST test

/*
 * TODO: add docs
 */
#define NBP_GET_TEST_NAME(test) test->testName

#endif // end if NBP_PRIVATE_API_TEST_H
