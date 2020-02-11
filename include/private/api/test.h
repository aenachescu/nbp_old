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
 * @public doc
 *
 * @brief
 *  Defines a function that can be called before running a test using the
 *  NBP_CALL_BEFORE_TEST macro.
 *
 *  Use the NBP_THIS_TEST macro if you want to get info about the test that will
 *  run.
 *
 * @params
 *  func - Represents the function name. It must be unique in the entire program
 *         not just in the C file where it is defined.
 *
 * @code
 *  NBP_BEFORE_TEST(beforeMyTests)
 *  {
 *      // do something
 *  }
 * @endcode
 */
#define NBP_BEFORE_TEST(func)                                                  \
    void NBP_PRIVATE_PP_CONCAT(nbp_before_test_, func)(                        \
        nbp_test_details_t* test                                               \
    )

/*
 * @public doc
 *
 * @brief
 *  Calls the function `func` before running a test. The function must be
 *  defined using the NBP_BEFORE_TEST macro and it can be defined in any C file
 *  not just in the current C file.
 *
 *  This macro must be used in the NBP_MODULE macro. This function will be
 *  called before any test that will run until another NBP_CALL_BEFORE_TEST
 *  macro will be used or until the NBP_RESET_BEFORE_TEST macro will be used.
 *
 * @params
 *  func - Represents the function name that was passed to the NBP_BEFORE_TEST
 *         macro.
 *
 * @code
 *  NBP_BEFORE_TEST(beforeMyFirstTest)
 *  {
 *      // do something
 *  }
 *
 *  NBP_BEFORE_TEST(beforeMySecondAndThirdTest)
 *  {
 *      // do something
 *  }
 *
 *  NBP_MODULE(myFirstModule)
 *  {
 *      NBP_CALL_BEFORE_TEST(beforeMyFirstTest);
 *      NBP_CALL_TEST(myFirstTest);
 *      NBP_CALL_BEFORE_TEST(beforeMySecondAndThirdTest);
 *      NBP_CALL_TEST(mySecondTest);
 *      NBP_CALL_TEST(myThirdTest);
 *  }
 * @endcode
 */
#define NBP_CALL_BEFORE_TEST(func)                                             \
    NBP_BEFORE_TEST(func);                                                     \
    beforeTest = NBP_PRIVATE_PP_CONCAT(nbp_before_test_, func)

/*
 * @public doc
 *
 * @brief
 *  No function will be called before running the tests called after this macro.
 *  This macro must be used in the NBP_MODULE macro.
 *
 * @code
 *  NBP_BEFORE_TEST(beforeMyFirstTest)
 *  {
 *      // do something
 *  }
 *
 *  NBP_MODULE(myFirstModule)
 *  {
 *      NBP_CALL_BEFORE_TEST(beforeMyFirstTest);
 *      NBP_CALL_TEST(myFirstTest);
 *      NBP_RESET_BEFORE_TEST();
 *      // no function will be called before mySecondTest and myThirdTest.
 *      NBP_CALL_TEST(mySecondTest);
 *      NBP_CALL_TEST(myThirdTest);
 *  }
 * @endcode
 */
#define NBP_RESET_BEFORE_TEST()                                                \
    beforeTest = NBP_NULL_POINTER

/*
 * @public doc
 *
 * @brief
 *  Defines a function that can be called after running a test using the
 *  NBP_CALL_AFTER_TEST macro.
 *
 *  Use the NBP_THIS_TEST macro if you want to get info about the test that was
 *  run.
 *
 * @params
 *  func - Represents the function name. It must be unique in the entire program
 *         not just in the C file where it is defined.
 *
 * @code
 *  NBP_AFTER_TEST(afterMyTests)
 *  {
 *      // do something
 *  }
 * @endcode
 */
#define NBP_AFTER_TEST(func)                                                   \
    void NBP_PRIVATE_PP_CONCAT(nbp_after_test_, func)(                         \
        nbp_test_details_t* test                                               \
    )

/*
 * @public doc
 *
 * @brief
 *  Calls the function `func` after running a test. The function must be defined
 *  using the NBP_AFTER_TEST macro and it can be defined in any C file not just
 *  in the current C file.
 *
 *  This macro must be used in the NBP_MODULE macro. This function will be
 *  called after any test that will run until another NBP_CALL_AFTER_TEST macro
 *  will be used or until the NBP_RESET_AFTER_TEST macro will be used.
 *
 * @params
 *  func - Represents the function name that was passed to the NBP_AFTER_TEST
 *         macro.
 *
 * @code
 *  NBP_AFTER_TEST(afterMyFirstTest)
 *  {
 *      // do something
 *  }
 *
 *  NBP_AFTER_TEST(afterMySecondAndThirdTest)
 *  {
 *      // do something
 *  }
 *
 *  NBP_MODULE(myFirstModule)
 *  {
 *      NBP_CALL_AFTER_TEST(afterMyFirstTest);
 *      NBP_CALL_TEST(myFirstTest);
 *      NBP_CALL_AFTER_TEST(afterMySecondAndThirdTest);
 *      NBP_CALL_TEST(mySecondTest);
 *      NBP_CALL_TEST(myThirdTest);
 *  }
 * @endcode
 */
#define NBP_CALL_AFTER_TEST(func)                                              \
    NBP_AFTER_TEST(func);                                                      \
    afterTest = NBP_PRIVATE_PP_CONCAT(nbp_after_test_, func)

/*
 * @public doc
 *
 * @brief
 *  No function will be called after running the tests called after this macro.
 *  This macro must be used in the NBP_MODULE macro.
 *
 * @code
 *  NBP_AFTER_TEST(afterMyFirstTest)
 *  {
 *      // do something
 *  }
 *
 *  NBP_MODULE(myFirstModule)
 *  {
 *      NBP_CALL_AFTER_TEST(afterMyFirstTest);
 *      NBP_CALL_TEST(myFirstTest);
 *      NBP_RESET_AFTER_TEST();
 *      // no function will be called after mySecondTest and myThirdTest.
 *      NBP_CALL_TEST(mySecondTest);
 *      NBP_CALL_TEST(myThirdTest);
 *  }
 * @endcode
 */
#define NBP_RESET_AFTER_TEST()                                                 \
    afterTest = NBP_NULL_POINTER

#define NBP_PRIVATE_TEST(func, name)                                           \
    void NBP_PRIVATE_PP_CONCAT(nbp_test_, func)(                               \
        nbp_test_details_t*                                                    \
    );                                                                         \
    nbp_test_details_t NBP_PRIVATE_PP_CONCAT(nbpTestDetails, func) = {         \
        .testName                   = name,                                    \
        .testFunc                   = NBP_PRIVATE_PP_CONCAT(nbp_test_, func),  \
        .module                     = NBP_NULL_POINTER,                        \
        .beforeTestFunc             = NBP_NULL_POINTER,                        \
        .afterTestFunc              = NBP_NULL_POINTER,                        \
        .next                       = NBP_NULL_POINTER,                        \
        .prev                       = NBP_NULL_POINTER,                        \
        .testState                  =                                          \
            NBP_ATOMIC_UINT_INIT(NBP_TEST_STATE_NOT_INITIALIZED),              \
        .flags                      =                                          \
            NBP_ATOMIC_UINT_INIT(NBP_TEST_FLAGS_NOT_INITIALIZED),              \
        .checks = {                                                            \
            .numPassed              = NBP_ATOMIC_UINT_INIT(0),                 \
            .numFailed              = NBP_ATOMIC_UINT_INIT(0),                 \
        },                                                                     \
        .testAsserts = {                                                       \
            .numPassed              = NBP_ATOMIC_UINT_INIT(0),                 \
            .numFailed              = NBP_ATOMIC_UINT_INIT(0),                 \
        },                                                                     \
        .moduleAsserts = {                                                     \
            .numPassed              = NBP_ATOMIC_UINT_INIT(0),                 \
            .numFailed              = NBP_ATOMIC_UINT_INIT(0),                 \
        },                                                                     \
        .asserts = {                                                           \
            .numPassed              = NBP_ATOMIC_UINT_INIT(0),                 \
            .numFailed              = NBP_ATOMIC_UINT_INIT(0),                 \
        },                                                                     \
    };                                                                         \
    void NBP_PRIVATE_PP_CONCAT(nbp_test_, func)(                               \
        nbp_test_details_t* test                                               \
    )

/*
 * @public doc
 *
 * @brief
 *  Defines a test that can be called using the NBP_CALL_TEST macro.
 *  Use the NBP_THIS_TEST macro if you want to get info about the test.
 *
 * @params
 *  func - Represents the function name. It must be unique in the entire program
 *         not just in the C file where it is defined. At the same time in this
 *         macro it represents the name of the test.
 *
 * @code
 *  NBP_TEST(myTest)
 *  {
 *      // do something
 *  }
 * @endcode
 */
#define NBP_TEST(func)                                                         \
    NBP_PRIVATE_TEST(func, #func)

/*
 * @public doc
 *
 * @brief
 *  Defines a test that can be called using the NBP_CALL_TEST macro.
 *  Use the NBP_THIS_TEST macro if you want to get info about the test.
 *
 * @params
 *  func - Represents the function name. It must be unique in the entire program
 *         not just in the C file where it is defined.
 *  name - const char* that represents the test name.
 *
 * @code
 *  NBP_TEST_NAME(myTest, "it tests if something is wrong...")
 *  {
 *      // do something
 *  }
 * @endcode
 */
#define NBP_TEST_NAME(func, name)                                              \
    NBP_PRIVATE_TEST(func, name)

/*
 * @public doc
 *
 * @brief
 *  Calls a test that was defined using the NBP_TEST or NBP_TEST_NAME macro.
 *  The test can be defined in any C file not just in the current C file.
 *  This macro must be used in the NBP_MODULE macro.
 *
 *  The test will be passed to the scheduler and the scheduler will decide
 *  when the test will run.
 *
 * @params
 *  func - Represents the function name that was passed to the NBP_TEST or
 *         NBP_TEST_NAME macro.
 *
 * @code
 *  NBP_TEST(myFirstTest)
 *  {
 *      // do something
 *  }
 *
 *  NBP_TEST_NAME(mySecondTest, "bla bla bla")
 *  {
 *      // do something
 *  }
 *
 *  NBP_MODULE(myFirstModule)
 *  {
 *      NBP_CALL_TEST(myFirstTest);
 *      NBP_CALL_TEST(mySecondTest);
 *  }
 * @endcode
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
#define NBP_CALL_TEST_CTX(func, ctx)                                           \
    extern nbp_test_details_t NBP_PRIVATE_PP_CONCAT(nbpTestDetails, func);     \
    nbp_call_test_ctx(                                                         \
        & NBP_PRIVATE_PP_CONCAT(nbpTestDetails, func),                         \
        ctx,                                                                   \
        module,                                                                \
        beforeTest,                                                            \
        afterTest                                                              \
    )

/*
 * TODO: add docs
 */
#define NBP_INCLUDE_TEST(func)                                                 \
    extern nbp_test_details_t NBP_PRIVATE_PP_CONCAT(nbpTestDetails, func)

/*
 * @public doc
 *
 * @brief
 *  This macro gets the current test. Use this macro only in the functions whose
 *  documentation specifies that this macro can be used.
 *
 * @return
 *  Pointer to nbp_test_details_t struct. Do not free or modify this structure,
 *  but you can store this pointer and use it via NBP_TEST_GET_* macros.
 */
#define NBP_THIS_TEST test

/*
 * @public doc
 *
 * @brief
 *  This macro gets the test name.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_THIS_TEST macro.
 *
 * @return
 *  Pointer to const char. Do not free or modify this pointer.
 */
#define NBP_GET_TEST_NAME(test)                                                \
    test->testName

/*
 * @public doc
 *
 * @brief
 *  This macro gets the test depth which is equal to the module depth + 1.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_THIS_TEST macro.
 *
 * @return
 *  unsigned int which is greater than 0.
 */
#define NBP_GET_TEST_DEPTH(test)                                               \
    NBP_GET_MODULE_DEPTH(test->module) + 1

/*
 * @public doc
 *
 * @brief
 *  This macro gets the test state.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_THIS_TEST macro.
 *
 * @return
 *  unsigned int which represents one of the NBP_TEST_STATE_* macros.
 */
#define NBP_GET_TEST_STATE(test)                                               \
    NBP_ATOMIC_UINT_LOAD(&test->testState)

/*
 * @public doc
 *
 * @brief
 *  This macro gets the total number of NBP_CHECK* macros executed by this test.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_THIS_TEST macro.
 *
 * @return
 *  unsigned int which represents the total number of NBP_CHECK* macros
 *  executed by this test.
 */
#define NBP_TEST_GET_CHECKS_NUM(test)                                          \
    NBP_TEST_GET_PASSED_CHECKS_NUM(test) +                                     \
    NBP_TEST_GET_FAILED_CHECKS_NUM(test)

/*
 * @public doc
 *
 * @brief
 *  This macro gets the number of passed NBP_CHECK* macros.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_THIS_TEST macro.
 *
 * @return
 *  unsigned int which represents the number of passed NBP_CHECK* macros.
 */
#define NBP_TEST_GET_PASSED_CHECKS_NUM(test)                                   \
    NBP_ATOMIC_UINT_LOAD(&test->checks.numPassed)

/*
 * @public doc
 *
 * @brief
 *  This macro gets the number of failed NBP_CHECK* macros.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_THIS_TEST macro.
 *
 * @return
 *  unsigned int which represents the number of failed NBP_CHECK* macros.
 */
#define NBP_TEST_GET_FAILED_CHECKS_NUM(test)                                   \
    NBP_ATOMIC_UINT_LOAD(&test->checks.numFailed)

/*
 * @public doc
 *
 * @brief
 *  This macro gets the total number of NBP_TEST_ASSERT* macros executed by this
 *  test.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_THIS_TEST macro.
 *
 * @return
 *  unsigned int which represents the total number of NBP_TEST_ASSERT* macros
 *  executed by this test.
 */
#define NBP_TEST_GET_TEST_ASSERT_NUM(test)                                     \
    NBP_TEST_GET_PASSED_TEST_ASSERT_NUM(test) +                                \
    NBP_TEST_GET_FAILED_TEST_ASSERT_NUM(test)

/*
 * @public doc
 *
 * @brief
 *  This macro gets the number of passed NBP_TEST_ASSERT* macros.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_THIS_TEST macro.
 *
 * @return
 *  unsigned int which represents the number of passed NBP_TEST_ASSERT* macros.
 */
#define NBP_TEST_GET_PASSED_TEST_ASSERT_NUM(test)                              \
    NBP_ATOMIC_UINT_LOAD(&test->testAsserts.numPassed)

/*
 * @public doc
 *
 * @brief
 *  This macro gets the number of failed NBP_TEST_ASSERT* macros.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_THIS_TEST macro.
 *
 * @return
 *  unsigned int which represents the number of failed NBP_TEST_ASSERT* macros.
 */
#define NBP_TEST_GET_FAILED_TEST_ASSERT_NUM(test)                              \
    NBP_ATOMIC_UINT_LOAD(&test->testAsserts.numFailed)

/*
 * @public doc
 *
 * @brief
 *  This macro gets the total number of NBP_MODULE_ASSERT* macros executed by
 *  this test.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_THIS_TEST macro.
 *
 * @return
 *  unsigned int which represents the total number of NBP_MODULE_ASSERT* macros
 *  executed by this test.
 */
#define NBP_TEST_GET_MODULE_ASSERTS_NUM(test)                                  \
    NBP_TEST_GET_PASSED_MODULE_ASSERTS_NUM(test) +                             \
    NBP_TEST_GET_FAILED_MODULE_ASSERTS_NUM(test)

/*
 * @public doc
 *
 * @brief
 *  This macro gets the number of passed NBP_MODULE_ASSERT* macros.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_THIS_TEST macro.
 *
 * @return
 *  unsigned int which represents the number of passed NBP_MODULE_ASSERT* macros.
 */
#define NBP_TEST_GET_PASSED_MODULE_ASSERTS_NUM(test)                           \
    NBP_ATOMIC_UINT_LOAD(&test->moduleAsserts.numPassed)

/*
 * @public doc
 *
 * @brief
 *  This macro gets the number of failed NBP_MODULE_ASSERT* macros.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_THIS_TEST macro.
 *
 * @return
 *  unsigned int which represents the number of failed NBP_MODULE_ASSERT* macros.
 */
#define NBP_TEST_GET_FAILED_MODULE_ASSERTS_NUM(test)                           \
    NBP_ATOMIC_UINT_LOAD(&test->moduleAsserts.numFailed)

/*
 * @public doc
 *
 * @brief
 *  This macro gets the total number of NBP_ASSERT* macros executed by this test.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_THIS_TEST macro.
 *
 * @return
 *  unsigned int which represents the total number of NBP_ASSERT* macros
 *  executed by this test.
 */
#define NBP_TEST_GET_ASSERTS_NUM(test)                                         \
    NBP_TEST_GET_PASSED_ASSERTS_NUM(test) +                                    \
    NBP_TEST_GET_FAILED_ASSERTS_NUM(test)

/*
 * @public doc
 *
 * @brief
 *  This macro gets the number of passed NBP_ASSERT* macros.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_THIS_TEST macro.
 *
 * @return
 *  unsigned int which represents the number of passed NBP_ASSERT* macros.
 */
#define NBP_TEST_GET_PASSED_ASSERTS_NUM(test)                                  \
    NBP_ATOMIC_UINT_LOAD(&test->asserts.numPassed)

/*
 * @public doc
 *
 * @brief
 *  This macro gets the number of failed NBP_ASSERT* macros.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_THIS_TEST macro.
 *
 * @return
 *  unsigned int which represents the number of failed NBP_ASSERT* macros.
 */
#define NBP_TEST_GET_FAILED_ASSERTS_NUM(test)                                  \
    NBP_ATOMIC_UINT_LOAD(&test->asserts.numFailed)

#endif // end if NBP_PRIVATE_API_TEST_H

