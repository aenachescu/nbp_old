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
#define NBP_BEFORE_TEST(func)                                                  \
    void NBP_PRIVATE_PP_CONCAT(nbp_before_test_, func)(                        \
        nbp_test_details_t* test                                               \
    )

/*
 * TODO: add docs
 */
#define NBP_CALL_BEFORE_TEST(func)                                             \
    NBP_BEFORE_TEST(func);                                                     \
    beforeTest = NBP_PRIVATE_PP_CONCAT(nbp_before_test_, func)

/*
 * TODO: add docs
 */
#define NBP_RESET_BEFORE_TEST()                                                \
    beforeTest = 0x0

/*
 * TODO: add docs
 */
#define NBP_AFTER_TEST(func)                                                   \
    void NBP_PRIVATE_PP_CONCAT(nbp_after_test_, func)(                         \
        nbp_test_details_t* test                                               \
    )

/*
 * TODO: add docs
 */
#define NBP_CALL_AFTER_TEST(func)                                              \
    NBP_AFTER_TEST(func);                                                      \
    afterTest = NBP_PRIVATE_PP_CONCAT(nbp_after_test_, func)

/*
 * TODO: add docs
 */
#define NBP_RESET_AFTER_TEST()                                                 \
    afterTest = 0x0

#define NBP_PRIVATE_TEST(func, name)                                           \
    void NBP_PRIVATE_PP_CONCAT(nbp_test_, func)(                               \
        nbp_test_details_t*                                                    \
    );                                                                         \
    nbp_test_details_t NBP_PRIVATE_PP_CONCAT(nbpTestDetails, func) = {         \
        .testName               = name,                                        \
        .testFunc               = NBP_PRIVATE_PP_CONCAT(nbp_test_, func),      \
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
    void NBP_PRIVATE_PP_CONCAT(nbp_test_, func)(                               \
        nbp_test_details_t* test                                               \
    )

/*
 * TODO: add docs
 */
#define NBP_TEST(func)                                                         \
    NBP_PRIVATE_TEST(func, #func)

/*
 * TODO: add docs
 */
#define NBP_TEST_NAME(func, name)                                              \
    NBP_PRIVATE_TEST(func, name)

/*
 * TODO: add docs
 */
#define NBP_CALL_TEST(func)                                                    \
    extern nbp_test_details_t NBP_PRIVATE_PP_CONCAT(nbpTestDetails, func);     \
    nbp_call_test(                                                             \
        & NBP_PRIVATE_PP_CONCAT(nbpTestDetails, func),                         \
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