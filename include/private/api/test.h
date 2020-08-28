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

#ifndef NBP_PRIVATE_API_TEST_H
#define NBP_PRIVATE_API_TEST_H

/*
 * @public doc
 *
 * @brief
 *  Defines a function that can be called before running a test using the
 *  NBP_TEST_USE_SETUP macro.
 *
 *  Use the NBP_TEST_THIS macro if you want to get info about the test that will
 *  run.
 *
 * @params
 *  func - Represents the function name. It must be unique in the entire program
 *         not just in the C file where it is defined.
 *
 * @code
 *  NBP_TEST_SETUP(setupMyTests)
 *  {
 *      // do something
 *  }
 * @endcode
 */

#define NBP_TEST_SETUP(func)                                                   \
    void NBP_PP_CONCAT(nbp_test_setup_, func)(                                 \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest            \
    )

/*
 * @public doc
 *
 * @brief
 *  Calls the function `func` before running a test. The function must be
 *  defined using the NBP_TEST_SETUP macro and it can be defined in any C file
 *  not just in the current C file.
 *
 *  This macro must be used in the NBP_MODULE macro. This function will be
 *  called before any test that will run until another NBP_TEST_USE_SETUP
 *  macro will be used or until the NBP_TEST_RESET_SETUP macro will be used.
 *
 * @params
 *  func - Represents the function name that was passed to the NBP_TEST_SETUP
 *         macro.
 *
 * @code
 *  NBP_TEST_SETUP(setupMyFirstTest)
 *  {
 *      // do something
 *  }
 *
 *  NBP_TEST_SETUP(setupMySecondAndThirdTest)
 *  {
 *      // do something
 *  }
 *
 *  NBP_MODULE(myFirstModule)
 *  {
 *      NBP_TEST_USE_SETUP(setupMyFirstTest);
 *      NBP_TEST_RUN(myFirstTest);
 *      NBP_TEST_USE_SETUP(setupMySecondAndThirdTest);
 *      NBP_TEST_RUN(mySecondTest);
 *      NBP_TEST_RUN(myThirdTest);
 *  }
 * @endcode
 */
#define NBP_TEST_USE_SETUP(func)                                               \
    NBP_TEST_SETUP(func);                                                      \
    nbpParamTestSetup = NBP_PP_CONCAT(nbp_test_setup_, func)

/*
 * @public doc
 *
 * @brief
 *  No function will be called before running the tests called after this macro.
 *  This macro must be used in the NBP_MODULE macro.
 *
 * @code
 *  NBP_TEST_SETUP(setupMyFirstTest)
 *  {
 *      // do something
 *  }
 *
 *  NBP_MODULE(myFirstModule)
 *  {
 *      NBP_TEST_USE_SETUP(setupMyFirstTest);
 *      NBP_TEST_RUN(myFirstTest);
 *      NBP_TEST_RESET_SETUP();
 *      // no function will be called before mySecondTest and myThirdTest.
 *      NBP_TEST_RUN(mySecondTest);
 *      NBP_TEST_RUN(myThirdTest);
 *  }
 * @endcode
 */
#define NBP_TEST_RESET_SETUP()                                                 \
    nbpParamTestSetup = NBP_MEMORY_NULL_POINTER

/*
 * @public doc
 *
 * @brief
 *  Defines a function that can be called after running a test using the
 *  NBP_TEST_USE_TEARDOWN macro.
 *
 *  Use the NBP_TEST_THIS macro if you want to get info about the test that was
 *  run.
 *
 * @params
 *  func - Represents the function name. It must be unique in the entire program
 *         not just in the C file where it is defined.
 *
 * @code
 *  NBP_TEST_TEARDOWN(myTestsTeardown)
 *  {
 *      // do something
 *  }
 * @endcode
 */
#define NBP_TEST_TEARDOWN(func)                                                \
    void NBP_PP_CONCAT(nbp_test_teardown_, func)(                              \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest            \
    )

/*
 * @public doc
 *
 * @brief
 *  Calls the function `func` after running a test. The function must be defined
 *  using the NBP_TEST_TEARDOWN macro and it can be defined in any C file not just
 *  in the current C file.
 *
 *  This macro must be used in the NBP_MODULE macro. This function will be
 *  called after any test that will run until another NBP_TEST_USE_TEARDOWN macro
 *  will be used or until the NBP_TEST_RESET_TEARDOWN macro will be used.
 *
 * @params
 *  func - Represents the function name that was passed to the NBP_TEST_TEARDOWN
 *         macro.
 *
 * @code
 *  NBP_TEST_TEARDOWN(myFirstTestSetup)
 *  {
 *      // do something
 *  }
 *
 *  NBP_TEST_TEARDOWN(mySecondAndThirdTestSetup)
 *  {
 *      // do something
 *  }
 *
 *  NBP_MODULE(myFirstModule)
 *  {
 *      NBP_TEST_USE_TEARDOWN(myFirstTestSetup);
 *      NBP_TEST_RUN(myFirstTest);
 *      NBP_TEST_USE_TEARDOWN(mySecondAndThirdTestSetup);
 *      NBP_TEST_RUN(mySecondTest);
 *      NBP_TEST_RUN(myThirdTest);
 *  }
 * @endcode
 */
#define NBP_TEST_USE_TEARDOWN(func)                                            \
    NBP_TEST_TEARDOWN(func);                                                   \
    nbpParamTestTeardown = NBP_PP_CONCAT(nbp_test_teardown_, func)

/*
 * @public doc
 *
 * @brief
 *  No function will be called after running the tests called after this macro.
 *  This macro must be used in the NBP_MODULE macro.
 *
 * @code
 *  NBP_TEST_TEARDOWN(myFirstTestSetup)
 *  {
 *      // do something
 *  }
 *
 *  NBP_MODULE(myFirstModule)
 *  {
 *      NBP_TEST_USE_TEARDOWN(myFirstTestSetup);
 *      NBP_TEST_RUN(myFirstTest);
 *      NBP_TEST_RESET_TEARDOWN();
 *      // no function will be called after mySecondTest and myThirdTest.
 *      NBP_TEST_RUN(mySecondTest);
 *      NBP_TEST_RUN(myThirdTest);
 *  }
 * @endcode
 */
#define NBP_TEST_RESET_TEARDOWN()                                              \
    nbpParamTestTeardown = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_TEST(func, ...)                                                    \
    void NBP_PP_CONCAT(nbp_test_config_, func)(                                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest            \
    )                                                                          \
    {                                                                          \
        NBP_TEST_PRIVATE_GENERATE_CONFIG(P_ ## __VA_ARGS__)                    \
    }                                                                          \
    void NBP_PP_CONCAT(nbp_test_, func)(                                       \
        nbp_test_details_t*,                                                   \
        unsigned int,                                                          \
        const char*,                                                           \
        const char*                                                            \
    );                                                                         \
    nbp_test_details_t NBP_PP_CONCAT(nbpTestDetails, func) = {                 \
        .testName                   = #func,                                   \
        .testId                     = 0,                                       \
        .testFunc                   = NBP_PP_CONCAT(nbp_test_, func),          \
        .configFunc                 = NBP_PP_CONCAT(nbp_test_config_, func),   \
        .module                     = NBP_MEMORY_NULL_POINTER,                 \
        .testSetupFunc              = NBP_MEMORY_NULL_POINTER,                 \
        .testTeardownFunc           = NBP_MEMORY_NULL_POINTER,                 \
        .next                       = NBP_MEMORY_NULL_POINTER,                 \
        .prev                       = NBP_MEMORY_NULL_POINTER,                 \
        .testState                  =                                          \
            NBP_SYNC_ATOMIC_UINT_INIT(NBP_TEST_STATE_NOT_INITIALIZED),         \
        .isSkipped                  =                                          \
            NBP_SYNC_ATOMIC_UINT_INIT(NBP_TEST_PRIVATE_SKIP_NOT_SET),          \
        .asserts = {                                                           \
            .nonFatal = {                                                      \
                .numPassed      = 0,                                           \
                .numFailed      = 0,                                           \
            },                                                                 \
            .fatal = {                                                         \
                .numPassed      = 0,                                           \
                .numFailed      = 0,                                           \
            },                                                                 \
            .fatalForTest = {                                                  \
                .numPassed      = 0,                                           \
                .numFailed      = 0,                                           \
            },                                                                 \
            .fatalForModule = {                                                \
                .numPassed      = 0,                                           \
                .numFailed      = 0,                                           \
            },                                                                 \
        },                                                                     \
    };                                                                         \
    void NBP_PP_CONCAT(nbp_test_, func)(                                       \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamAssertType,            \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamSuccessMessage,         \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailureMessage          \
    )

/*
 * TODO: add docs
 */
#define NBP_TEST_NAME(name)

/*
 * TODO: add docs
 */
#define NBP_TEST_FIXTURES(setup, teardown)

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
 *      NBP_TEST_RUN(myFirstTest);
 *      NBP_TEST_RUN(mySecondTest);
 *  }
 * @endcode
 */
#define NBP_TEST_RUN(func)                                                     \
    extern nbp_test_details_t NBP_PP_CONCAT(nbpTestDetails, func);             \
    nbp_test_run(                                                              \
        & NBP_PP_CONCAT(nbpTestDetails, func),                                 \
        nbpParamModule,                                                        \
        nbpParamTestSetup,                                                     \
        nbpParamTestTeardown                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_TEST_RUN_CTX(func, ctx)                                            \
    extern nbp_test_details_t NBP_PP_CONCAT(nbpTestDetails, func);             \
    NBP_PRIVATE_SCHEDULER_PREPROCESSING_CONTEXT(P_ ## ctx)                     \
    nbp_test_run_ctx(                                                          \
        & NBP_PP_CONCAT(nbpTestDetails, func),                                 \
        ctx,                                                                   \
        nbpParamModule,                                                        \
        nbpParamTestSetup,                                                     \
        nbpParamTestTeardown                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_TEST_INCLUDE(func)                                                 \
    extern nbp_test_details_t NBP_PP_CONCAT(nbpTestDetails, func)

/*
 * TODO: add docs
 */
#define NBP_TEST_GET_PTR(func)                                                 \
    & NBP_PP_CONCAT(nbpTestDetails, func)

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
#define NBP_TEST_THIS nbpParamTest

/*
 * @public doc
 *
 * @brief
 *  This macro gets the test name.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_TEST_THIS macro.
 *
 * @return
 *  Pointer to const char. Do not free or modify this pointer.
 */
#define NBP_TEST_GET_NAME(test)                                                \
    test->testName

/*
 * TODO: add docs
 */
#define NBP_TEST_GET_ID(test)                                                  \
    test->testId

/*
 * TODO: add docs
 */
#define NBP_TEST_GET_MODULE(test)                                              \
    test->module

/*
 * @public doc
 *
 * @brief
 *  This macro gets the test depth which is equal to the module depth + 1.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_TEST_THIS macro.
 *
 * @return
 *  unsigned int which is greater than 0.
 */
#define NBP_TEST_GET_DEPTH(test)                                               \
    NBP_MODULE_GET_DEPTH(test->module) + 1

/*
 * @public doc
 *
 * @brief
 *  This macro gets the test state.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_TEST_THIS macro.
 *
 * @return
 *  unsigned int which represents one of the NBP_TEST_STATE_* macros.
 */
#define NBP_TEST_GET_STATE(test)                                               \
    NBP_SYNC_ATOMIC_UINT_LOAD(&test->testState)

/*
 * @public doc
 *
 * @brief
 *  This macro gets the total number of NBP_ASSERT* macros executed by this test.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_TEST_THIS macro.
 *
 * @return
 *  unsigned int which represents the total number of NBP_ASSERT* macros
 *  executed by this test.
 */
#define NBP_TEST_GET_NUMBER_OF_ASSERTS(test, assertType)                       \
    NBP_TEST_GET_NUMBER_OF_PASSED_ASSERTS(test, assertType) +                  \
    NBP_TEST_GET_NUMBER_OF_FAILED_ASSERTS(test, assertType)

/*
 * @public doc
 *
 * @brief
 *  This macro gets the number of passed NBP_ASSERT* macros.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_TEST_THIS macro.
 *
 * @return
 *  unsigned int which represents the number of passed NBP_ASSERT* macros.
 */
#define NBP_TEST_GET_NUMBER_OF_PASSED_ASSERTS(test, assertType)                \
    nbp_test_get_number_of_asserts(                                            \
        test,                                                                  \
        NBP_ASSERT_STATUS_PASSED,                                              \
        assertType                                                             \
    )


/*
 * @public doc
 *
 * @brief
 *  This macro gets the number of failed NBP_ASSERT* macros.
 *
 * @params
 *  test - a pointer to nbp_test_details_t structure which was obtained using
 *         the NBP_TEST_THIS macro.
 *
 * @return
 *  unsigned int which represents the number of failed NBP_ASSERT* macros.
 */
#define NBP_TEST_GET_NUMBER_OF_FAILED_ASSERTS(test, assertType)                \
    nbp_test_get_number_of_asserts(                                            \
        test,                                                                  \
        NBP_ASSERT_STATUS_FAILED,                                              \
        assertType                                                             \
    )

#define NBP_TEST_PRIVATE_GENERATE_CONFIG(...)                                  \
    NBP_PP_CONCAT(                                                             \
        NBP_PP_PROCESSING_PARAM_,                                              \
        NBP_PP_VARCOUNT(P ## __VA_ARGS__)                                      \
    )(P ## __VA_ARGS__)

#define NBP_PP_EAT_PP_NBP_TEST_NAME(name)                                      \
    nbpParamTest->testName = name;
#define NBP_PP_EAT_PP_NBP_TEST_SETUP(setup)                                    \
    NBP_TEST_SETUP(setup);                                                     \
    nbpParamTest->testSetupFunc = NBP_PP_CONCAT(nbp_test_setup_, setup);
#define NBP_PP_EAT_PP_NBP_TEST_TEARDOWN(teardown)                              \
    NBP_TEST_TEARDOWN(teardown);                                               \
    nbpParamTest->testTeardownFunc =                                           \
        NBP_PP_CONCAT(nbp_test_teardown_, teardown);
#define NBP_PP_EAT_PP_NBP_TEST_FIXTURES(setup, teardown)                       \
    NBP_PP_EAT_PP_NBP_TEST_SETUP(setup)                                        \
    NBP_PP_EAT_PP_NBP_TEST_TEARDOWN(teardown)

#endif // end if NBP_PRIVATE_API_TEST_H
