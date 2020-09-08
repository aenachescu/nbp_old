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

#ifndef NBP_LIBRARY_H
#define NBP_LIBRARY_H

#define NBP_VERSION_MAJOR       1
#define NBP_VERSION_MINOR       0
#define NBP_VERSION_REVISION    0

#define NBP_VERSION_STR         "1.0.0"

/*
 * Make sure there is only one compiler defined
 */
#undef NBP_PRIVATE_COMPILER_TYPE

#ifdef NBP_COMPILER_GCC
#define NBP_PRIVATE_COMPILER_TYPE
#endif // end if NBP_COMPILER_GCC

#ifdef NBP_COMPILER_CLANG
#ifndef NBP_PRIVATE_COMPILER_TYPE
#define NBP_PRIVATE_COMPILER_TYPE
#else // NBP_PRIVATE_COMPILER_TYPE not defined
#error "More NBP_COMPILER_* macros are defined"
#endif // end if NBP_PRIVATE_COMPILER_TYPE
#endif // end if NBP_COMPILER_CLANG

#ifdef NBP_COMPILER_CUSTOM
#ifndef NBP_PRIVATE_COMPILER_TYPE
#define NBP_PRIVATE_COMPILER_TYPE
#else // NBP_PRIVATE_COMPILER_TYPE not defined
#error "More NBP_COMPILER_* macros are defined"
#endif // end if NBP_PRIVATE_COMPILER_TYPE
#endif // end if NBP_COMPILER_CUSTOM

/*
 * If there is no compiler defined then try to detect the compiler
 */
#ifndef NBP_PRIVATE_COMPILER_TYPE
#ifdef __clang__
#define NBP_COMPILER_CLANG
#elif __GNUC__
#define NBP_COMPILER_GCC
#else // no compiler detected
#error "Unknown compiler"
#endif
#endif // end if NBP_PRIVATE_COMPILER_TYPE

#undef NBP_PRIVATE_COMPILER_TYPE

/*
 * Make sure there is only one OS defined
 */
#undef NBP_PRIVATE_OS_TYPE

#ifdef NBP_OS_LINUX
#define NBP_PRIVATE_OS_TYPE
#endif // end if NBP_OS_LINUX

#ifdef NBP_OS_WINDOWS
#ifndef NBP_PRIVATE_OS_TYPE
#define NBP_PRIVATE_OS_TYPE
#else // NBP_PRIVATE_OS_TYPE not defined
#error "More NBP_OS_* macros are defined"
#endif // end if NBP_PRIVATE_OS_TYPE
#endif // end if NBP_OS_WINDOWS

#ifdef NBP_OS_MAC
#ifndef NBP_PRIVATE_OS_TYPE
#define NBP_PRIVATE_OS_TYPE
#else // NBP_PRIVATE_OS_TYPE not defined
#error "More NBP_OS_* macros are defined"
#endif // end if NBP_PRIVATE_OS_TYPE
#endif // end if NBP_OS_MAC

#ifdef NBP_OS_CUSTOM
#ifndef NBP_PRIVATE_OS_TYPE
#define NBP_PRIVATE_OS_TYPE
#else // NBP_PRIVATE_OS_TYPE not defined
#error "More NBP_OS_* macros are defined"
#endif // end if NBP_PRIVATE_OS_TYPE
#endif // end if NBP_OS_CUSTOM

/*
 * If there is no OS defined then try to detect the OS
 */
#ifndef NBP_PRIVATE_OS_TYPE
#ifdef __linux__
#define NBP_OS_LINUX
#else // no OS detected
#error "Unknown OS"
#endif
#endif // end if NBP_PRIVATE_OS_TYPE

#undef NBP_PRIVATE_OS_TYPE

/*
 * Make sure there is only one defined scheduler
 */
#undef NBP_PRIVATE_SCHEDULER_TYPE

#ifdef NBP_CUSTOM_SCHEDULER
#define NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_CUSTOM_SCHEDULER

#ifdef NBP_MT_SCHEDULER
#ifdef NBP_PRIVATE_SCHEDULER_TYPE
#error "Cannot enabe NBP_MT_SCHEDULER because another scheduler is enabled"
#else // NBP_PRIVATE_SCHEDULER_TYPE not defined
#define NBP_PRIVATE_SCHEDULER_TYPE
#define NBP_MT_SUPPORT
#endif // end if NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_MT_SCHEDULER

#ifdef NBP_BASIC_SCHEDULER
#ifdef NBP_PRIVATE_SCHEDULER_TYPE
#error "Cannot enabe NBP_BASIC_SCHEDULER because another scheduler is enabled"
#else // NBP_PRIVATE_SCHEDULER_TYPE not defined
#define NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_BASIC_SCHEDULER

/*
 * If no scheduler is defined then define the default scheduler
 */
#ifndef NBP_PRIVATE_SCHEDULER_TYPE
#define NBP_BASIC_SCHEDULER
#endif // end if NBP_PRIVATE_SCHEDULER_TYPE

#undef NBP_PRIVATE_SCHEDULER_TYPE

/*
 * If no printer is defined then define the default printer
 */
#if !defined NBP_CUSTOM_PRINTER && !defined NBP_DEFAULT_PRINTER
#define NBP_DEFAULT_PRINTER
#endif // end if ! NBP_CUSTOM_PRINTER && ! NBP_DEFAULT_PRINTER

/*
 * TODO: add docs
 */
#ifndef NBP_MEMORY_CUSTOM_ALLOCATOR

#include <stdlib.h>

/*
 * TODO: add docs
 */
#define NBP_MEMORY_NULL_POINTER NULL

/*
 * TODO: add docs
 */
#define NBP_MEMORY_ALLOC malloc

/*
 * TODO: add docs
 */
#define NBP_MEMORY_FREE free

#else // if custom memory allocator is enabled

#ifndef NBP_MEMORY_NULL_POINTER
#error "Custom memory allocator is enabled but NBP_MEMORY_NULL_POINTER is undefined"
#endif // end if NBP_MEMORY_NULL_POINTER

#ifndef NBP_MEMORY_ALLOC
#error "Custom memory allocator is enabled but NBP_MEMORY_ALLOC is undefined"
#endif // end if NBP_MEMORY_ALLOC

#ifndef NBP_MEMORY_FREE
#error "Custom memory allocator is enabled but NBP_MEMORY_FREE is undefined"
#endif // end if NBP_MEMORY_FREE

#endif // end if NBP_MEMORY_CUSTOM_ALLOCATOR

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

/*
 * TODO: add docs
 */
#define NBP_MODULE_SETUP(func)                                                 \
    void NBP_PP_CONCAT(nbp_module_setup_, func)(                               \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE_USE_SETUP(func)                                             \
    NBP_MODULE_SETUP(func);                                                    \
    nbpParamModuleSetup = NBP_PP_CONCAT(nbp_module_setup_, func)

/*
 * TODO: add docs
 */
#define NBP_MODULE_RESET_SETUP()                                               \
    nbpParamModuleSetup = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_MODULE_TEARDOWN(func)                                              \
    void NBP_PP_CONCAT(nbp_module_teardown_, func)(                            \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE_USE_TEARDOWN(func)                                          \
    NBP_MODULE_TEARDOWN(func);                                                 \
    nbpParamModuleTeardown = NBP_PP_CONCAT(nbp_module_teardown_, func)

/*
 * TODO: add docs
 */
#define NBP_MODULE_RESET_TEARDOWN()                                            \
    nbpParamModuleTeardown = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_MODULE(func, ...)                                                  \
    void NBP_PP_CONCAT(nbp_module_config_, func)(                              \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )                                                                          \
    {                                                                          \
        NBP_MODULE_PRIVATE_GENERATE_CONFIG(P_ ## __VA_ARGS__)                  \
    }                                                                          \
    NBP_MODULE_PRIVATE_BASE(func)

/*
 * TODO: add docs
 */
#define NBP_MODULE_NAME(name)

/*
 * TODO: add docs
 */
#define NBP_MODULE_FIXTURES(setupFunc, teardownFunc)

/*
 * TODO: add docs
 */
#define NBP_MODULE_RUN(func)                                                   \
    extern nbp_module_details_t NBP_PP_CONCAT(nbpModuleDetails, func);         \
    nbp_module_run(                                                            \
        & NBP_PP_CONCAT(nbpModuleDetails, func),                               \
        nbpParamModule,                                                        \
        nbpParamModuleSetup,                                                   \
        nbpParamModuleTeardown                                                 \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE_RUN_CTX(func, ctx)                                          \
    extern nbp_module_details_t NBP_PP_CONCAT(nbpModuleDetails, func);         \
    NBP_PRIVATE_SCHEDULER_PREPROCESSING_CONTEXT(P_ ## ctx)                     \
    nbp_module_run_ctx(                                                        \
        & NBP_PP_CONCAT(nbpModuleDetails, func),                               \
        ctx,                                                                   \
        nbpParamModule,                                                        \
        nbpParamModuleSetup,                                                   \
        nbpParamModuleTeardown                                                 \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE_INCLUDE(func)                                               \
    extern nbp_module_details_t NBP_PP_CONCAT(nbpModuleDetails, func);

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PTR(func)                                               \
    & NBP_PP_CONCAT(nbpModuleDetails, func)

/*
 * TODO: add docs
 */
#define NBP_MODULE_FOR_EACH_TEST(module, it)                                   \
    for (it = module->firstTest; it != NBP_MEMORY_NULL_POINTER; it = it->next)

/*
 * TODO: add docs
 */
#define NBP_MODULE_FOR_EACH_SUBMODULE(module, it)                              \
    for (it = module->firstModule; it != NBP_MEMORY_NULL_POINTER; it = it->next)

/*
 * TODO: add docs
 */
#define NBP_MODULE_THIS nbpParamModule

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PARENT(module) module->parent

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NAME(module) module->moduleName

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_ID(module) module->moduleId

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_DEPTH(module) module->depth

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_STATE(module)                                           \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->moduleState)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_TESTS(module)                                 \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->tests.num)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_PASSED_TESTS(module)                          \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->tests.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_FAILED_TESTS(module)                          \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->tests.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_SKIPPED_TESTS(module)                         \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->tests.numSkipped)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_MODULES(module)                               \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->modules.num)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_PASSED_MODULES(module)                        \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->modules.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_FAILED_MODULES(module)                        \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->modules.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_SKIPPED_MODULES(module)                       \
    NBP_SYNC_ATOMIC_UINT_LOAD(&module->modules.numSkipped)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_ASSERTS(module, assertType)                   \
    NBP_MODULE_GET_NUMBER_OF_PASSED_ASSERTS(module, assertType) +              \
    NBP_MODULE_GET_NUMBER_OF_FAILED_ASSERTS(module, assertType)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_PASSED_ASSERTS(module, assertType)            \
    nbp_module_get_number_of_asserts(                                          \
        module,                                                                \
        NBP_ASSERT_STATUS_PASSED,                                              \
        assertType                                                             \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_NUMBER_OF_FAILED_ASSERTS(module, assertType)            \
    nbp_module_get_number_of_asserts(                                          \
        module,                                                                \
        NBP_ASSERT_STATUS_FAILED,                                              \
        assertType                                                             \
    )

#define NBP_MODULE_PRIVATE_GENERATE_CONFIG(...)                                \
    NBP_PP_CONCAT(                                                             \
        NBP_PP_PROCESSING_PARAM_,                                              \
        NBP_PP_VARCOUNT(P ## __VA_ARGS__)                                      \
    )(P ## __VA_ARGS__)

#define NBP_PP_EAT_PP_NBP_MODULE_NAME(name)                                    \
    nbpParamModule->moduleName = name;
#define NBP_PP_EAT_PP_NBP_MODULE_SETUP(setup)                                  \
    NBP_MODULE_SETUP(setup);                                                   \
    nbpParamModule->setupFunc = NBP_PP_CONCAT(nbp_module_setup_, setup);
#define NBP_PP_EAT_PP_NBP_MODULE_TEARDOWN(teardown)                            \
    NBP_MODULE_TEARDOWN(teardown);                                             \
    nbpParamModule->teardownFunc =                                             \
        NBP_PP_CONCAT(nbp_module_teardown_, teardown);
#define NBP_PP_EAT_PP_NBP_MODULE_FIXTURES(setup, teardown)                     \
    NBP_PP_EAT_PP_NBP_MODULE_SETUP(setup)                                      \
    NBP_PP_EAT_PP_NBP_MODULE_TEARDOWN(teardown)

#define NBP_MODULE_PRIVATE_BASE(func)                                          \
    void NBP_PP_CONCAT(nbp_module_, func)(                                     \
        nbp_module_details_t*,                                                 \
        nbp_module_setup_pfn_t,                                                \
        nbp_module_teardown_pfn_t,                                             \
        nbp_test_setup_pfn_t,                                                  \
        nbp_test_teardown_pfn_t                                                \
    );                                                                         \
    nbp_module_details_t NBP_PP_CONCAT(nbpModuleDetails, func) = {             \
        .moduleName             = #func,                                       \
        .moduleId               = 0,                                           \
        .moduleFunc             = NBP_PP_CONCAT(nbp_module_, func),            \
        .configFunc             = NBP_PP_CONCAT(nbp_module_config_, func),     \
        .parent                 = NBP_MEMORY_NULL_POINTER,                     \
        .setupFunc              = NBP_MEMORY_NULL_POINTER,                     \
        .teardownFunc           = NBP_MEMORY_NULL_POINTER,                     \
        .firstTest              = NBP_MEMORY_NULL_POINTER,                     \
        .lastTest               = NBP_MEMORY_NULL_POINTER,                     \
        .firstModule            = NBP_MEMORY_NULL_POINTER,                     \
        .lastModule             = NBP_MEMORY_NULL_POINTER,                     \
        .next                   = NBP_MEMORY_NULL_POINTER,                     \
        .prev                   = NBP_MEMORY_NULL_POINTER,                     \
        .depth                  = 0,                                           \
        .runEvent               = NBP_SYNC_EVENT_DEFAULT_VALUE,                \
        .setupEvent             = NBP_SYNC_EVENT_DEFAULT_VALUE,                \
        .isSkipped              =                                              \
            NBP_SYNC_ATOMIC_UINT_INIT(NBP_MODULE_PRIVATE_SKIP_NOT_SET),        \
        .moduleState            =                                              \
            NBP_SYNC_ATOMIC_UINT_INIT(NBP_MODULE_STATE_NOT_INITIALIZED),       \
        .taskNum                = 0,                                           \
        .completedTaskNum       = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
        .isEmptyModule          = 1,                                           \
        .emptySubmodulesNum     = 0,                                           \
        .tests = {                                                             \
            .num                = 0,                                           \
            .numPassed          = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
            .numFailed          = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
            .numSkipped         = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
        },                                                                     \
        .modules = {                                                           \
            .num                = 0,                                           \
            .numPassed          = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
            .numFailed          = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
            .numSkipped         = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
        },                                                                     \
        .asserts = {                                                           \
            .nonFatal = {                                                      \
                .numPassed      = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
                .numFailed      = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
            },                                                                 \
            .fatal = {                                                         \
                .numPassed      = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
                .numFailed      = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
            },                                                                 \
            .fatalForTest = {                                                  \
                .numPassed      = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
                .numFailed      = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
            },                                                                 \
            .fatalForModule = {                                                \
                .numPassed      = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
                .numFailed      = NBP_SYNC_ATOMIC_UINT_INIT(0),                \
            },                                                                 \
        },                                                                     \
    };                                                                         \
    void NBP_PP_CONCAT(nbp_module_, func)(                                     \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule,       \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_setup_pfn_t nbpParamModuleSetup, \
        NBP_MAYBE_UNUSED_PARAMETER                                             \
            nbp_module_teardown_pfn_t nbpParamModuleTeardown,                  \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_setup_pfn_t nbpParamTestSetup,     \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_teardown_pfn_t nbpParamTestTeardown\
    )

#ifdef NBP_LIBRARY_MAIN

#define NBP_MAIN_PRIVATE_MODULE_IMPL(func, scheduler, printers)                \
    extern nbp_module_details_t NBP_PP_CONCAT(nbpModuleDetails, func);         \
    nbp_module_details_t* nbpMainModule =                                      \
        & NBP_PP_CONCAT(nbpModuleDetails, func);                               \
    nbp_scheduler_interface_t* nbpSchedulerInterface = scheduler;              \
    nbp_printer_interface_t* nbpPrinterInterfaces[] = printers;                \
    unsigned int nbpPrinterInterfacesSize =                                    \
        sizeof(nbpPrinterInterfaces) / sizeof(nbpPrinterInterfaces[0]);

#ifdef NBP_CUSTOM_SCHEDULER

#error "Not supported"

#else // NBP_CUSTOM_SCHEDULER not defined

#ifdef NBP_BASIC_SCHEDULER
#define NBP_MAIN_PRIVATE_SCHEDULER_NAME nbpBasicScheduler
#endif // end if NBP_BASIC_SCHEDULER

#ifdef NBP_MT_SCHEDULER
#define NBP_MAIN_PRIVATE_SCHEDULER_NAME nbpMtScheduler
#endif // end if NBP_MT_SCHEDULER

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE(func, ...)                                             \
    extern nbp_printer_interface_t                                             \
        NBP_PP_CONCAT(nbpPrinter, nbpDefaultPrinter);                          \
    extern nbp_scheduler_interface_t                                           \
        NBP_PP_CONCAT(nbpScheduler, NBP_MAIN_PRIVATE_SCHEDULER_NAME);          \
    NBP_MAIN_PRIVATE_MODULE_IMPL(                                              \
        func,                                                                  \
        & NBP_PP_CONCAT(nbpScheduler, NBP_MAIN_PRIVATE_SCHEDULER_NAME),        \
        { & NBP_PP_CONCAT(nbpPrinter, nbpDefaultPrinter) }                     \
    );                                                                         \
    void NBP_PP_CONCAT(nbp_module_config_, func)(                              \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )                                                                          \
    {                                                                          \
        NBP_MODULE_PRIVATE_GENERATE_CONFIG(P_ ## __VA_ARGS__)                  \
    }                                                                          \
    NBP_MODULE_PRIVATE_BASE(func)

#endif // end if NBP_CUSTOM_SCHEDULER

#endif // end if NBP_LIBRARY_MAIN

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SUCCESS_MESSAGE(msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FAILURE_MESSAGE(msg)

/*
 * TODO: add docs
 */
#define NBP_ASSERT(cond, ...)                                                  \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_IMPL(cond)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_<operator>                                                      *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_EQ(a, b, ...)                                               \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_NE(a, b, ...)                                               \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_GT(a, b, ...)                                               \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_GE(a, b, ...)                                               \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LT(a, b, ...)                                               \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LE(a, b, ...)                                               \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_CHAR_<operator>                                                 *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_EQ(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_CHAR, char)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_NE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_CHAR, char)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_GT(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_CHAR, char)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_GE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_CHAR, char)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_LT(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_CHAR, char)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_CHAR_LE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_CHAR, char)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_SHORT_<operator>                                                *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_EQ(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_SHORT, short)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_NE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_SHORT, short)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_GT(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_SHORT, short)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_GE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_SHORT, short)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_LT(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_SHORT, short)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_SHORT_LE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_SHORT, short)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_USHORT_<operator>                                               *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_EQ(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_USHORT, ushort)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_NE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_USHORT, ushort)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_GT(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_USHORT, ushort)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_GE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_USHORT, ushort)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_LT(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_USHORT, ushort)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_USHORT_LE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_USHORT, ushort)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_INT_<operator>                                                  *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_EQ(a, b, ...)                                           \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_INT, int)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_NE(a, b, ...)                                           \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_INT, int)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_GT(a, b, ...)                                           \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_INT, int)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_GE(a, b, ...)                                           \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_INT, int)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_LT(a, b, ...)                                           \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_INT, int)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_INT_LE(a, b, ...)                                           \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_INT, int)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_UINT_<operator>                                                 *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_EQ(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_UINT, uint)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_NE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_UINT, uint)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_GT(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_UINT, uint)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_GE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_UINT, uint)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_LT(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_UINT, uint)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_UINT_LE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_UINT, uint)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_LONG_<operator>                                                 *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_EQ(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_LONG, long)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_NE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_LONG, long)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_GT(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_LONG, long)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_GE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_LONG, long)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_LT(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_LONG, long)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LONG_LE(a, b, ...)                                          \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_LONG, long)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_ULONG_<operator>                                                *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_EQ(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_ULONG, ulong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_NE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_ULONG, ulong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_GT(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_ULONG, ulong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_GE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_ULONG, ulong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_LT(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_ULONG, ulong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULONG_LE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_ULONG, ulong)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_LLONG_<operator>                                                *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_EQ(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_LLONG, llong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_NE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_LLONG, llong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_GT(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_LLONG, llong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_GE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_LLONG, llong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_LT(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_LLONG, llong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LLONG_LE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_LLONG, llong)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_ULLONG_<operator>                                               *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_EQ(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_NE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_GT(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_GE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_LT(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_ULLONG_LE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_ULLONG, ullong)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_FLOAT_<operator>                                                *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_EQ(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_FLOAT, float)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_NE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_FLOAT, float)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_GT(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_FLOAT, float)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_GE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_FLOAT, float)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_LT(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_FLOAT, float)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_FLOAT_LE(a, b, ...)                                         \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_FLOAT, float)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_DOUBLE_<operator>                                               *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_EQ(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ,         \
        NBP_PRINTER_TYPE_DOUBLE, double)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_NE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE,         \
        NBP_PRINTER_TYPE_DOUBLE, double)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_GT(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT,          \
        NBP_PRINTER_TYPE_DOUBLE, double)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_GE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE,         \
        NBP_PRINTER_TYPE_DOUBLE, double)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_LT(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT,          \
        NBP_PRINTER_TYPE_DOUBLE, double)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_DOUBLE_LE(a, b, ...)                                        \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE,         \
        NBP_PRINTER_TYPE_DOUBLE, double)

/******************************************************************************
 *                                                                            *
 *                                                                            *
 * NBP_ASSERT_LDOUBLE_<operator>                                              *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_EQ(a, b, ...)                                       \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, ==, NBP_PRINTER_OPERATOR_EQ)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_NE(a, b, ...)                                       \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, !=, NBP_PRINTER_OPERATOR_NE)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_GT(a, b, ...)                                       \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, >, NBP_PRINTER_OPERATOR_GT)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_GE(a, b, ...)                                       \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, >=, NBP_PRINTER_OPERATOR_GE)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_LT(a, b, ...)                                       \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, <, NBP_PRINTER_OPERATOR_LT)

/*
 * TODO: add docs
 */
#define NBP_ASSERT_LDOUBLE_LE(a, b, ...)                                       \
    NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(P_ ## __VA_ARGS__)              \
    NBP_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, <=, NBP_PRINTER_OPERATOR_LE)

#define NBP_ASSERT_PRIVATE_IMPL(cond)                                          \
    if (cond) {                                                                \
        nbp_test_increment_asserts_stats(                                      \
            nbpParamTest,                                                      \
            NBP_ASSERT_STATUS_PASSED,                                          \
            nbpParamAssertType                                                 \
        );                                                                     \
        nbp_printer_notify_assert_result(                                      \
            nbpParamTest,                                                      \
            #cond,                                                             \
            nbpParamAssertType,                                                \
            NBP_ASSERT_STATUS_PASSED,                                          \
            __LINE__,                                                          \
            NBP_MEMORY_NULL_POINTER,                                           \
            nbpParamSuccessMessage                                             \
        );                                                                     \
    } else {                                                                   \
        nbp_test_increment_asserts_stats(                                      \
            nbpParamTest,                                                      \
            NBP_ASSERT_STATUS_FAILED,                                          \
            nbpParamAssertType                                                 \
        );                                                                     \
        nbp_printer_notify_assert_result(                                      \
            nbpParamTest,                                                      \
            #cond,                                                             \
            nbpParamAssertType,                                                \
            NBP_ASSERT_STATUS_FAILED,                                          \
            __LINE__,                                                          \
            nbpParamFailureMessage,                                            \
            NBP_MEMORY_NULL_POINTER                                            \
        );                                                                     \
        if (nbpParamAssertType != NBP_ASSERT_NON_FATAL) {                      \
            return;                                                            \
        }                                                                      \
    }                                                                          \
    nbpParamAssertType      = NBP_ASSERT_NON_FATAL;                            \
    nbpParamSuccessMessage  = NBP_MEMORY_NULL_POINTER;                         \
    nbpParamFailureMessage  = NBP_MEMORY_NULL_POINTER;

#define NBP_ASSERT_PRIVATE_OP_IMPL(a, b, op, printerOp)                        \
    if (a op b) {                                                              \
        nbp_printer_type_value_t tmpA, tmpB;                                   \
        tmpA.stringValue = #a; tmpB.stringValue = #b;                          \
        nbp_test_increment_asserts_stats(                                      \
            nbpParamTest,                                                      \
            NBP_ASSERT_STATUS_PASSED,                                          \
            nbpParamAssertType                                                 \
        );                                                                     \
        nbp_printer_notify_assert_type_op_result(                              \
            nbpParamTest,                                                      \
            tmpA,                                                              \
            tmpB,                                                              \
            NBP_PRINTER_TYPE_NONE,                                             \
            printerOp,                                                         \
            nbpParamAssertType,                                                \
            NBP_ASSERT_STATUS_PASSED,                                          \
            __LINE__,                                                          \
            NBP_MEMORY_NULL_POINTER,                                           \
            nbpParamSuccessMessage                                             \
        );                                                                     \
    } else {                                                                   \
        nbp_printer_type_value_t tmpA, tmpB;                                   \
        tmpA.stringValue = #a; tmpB.stringValue = #b;                          \
        nbp_test_increment_asserts_stats(                                      \
            nbpParamTest,                                                      \
            NBP_ASSERT_STATUS_FAILED,                                          \
            nbpParamAssertType                                                 \
        );                                                                     \
        nbp_printer_notify_assert_type_op_result(                              \
            nbpParamTest,                                                      \
            tmpA,                                                              \
            tmpB,                                                              \
            NBP_PRINTER_TYPE_NONE,                                             \
            printerOp,                                                         \
            nbpParamAssertType,                                                \
            NBP_ASSERT_STATUS_FAILED,                                          \
            __LINE__,                                                          \
            nbpParamFailureMessage,                                            \
            NBP_MEMORY_NULL_POINTER                                            \
        );                                                                     \
        if (nbpParamAssertType != NBP_ASSERT_NON_FATAL) {                      \
            return;                                                            \
        }                                                                      \
    }                                                                          \
    nbpParamAssertType      = NBP_ASSERT_NON_FATAL;                            \
    nbpParamSuccessMessage  = NBP_MEMORY_NULL_POINTER;                         \
    nbpParamFailureMessage  = NBP_MEMORY_NULL_POINTER;

#define NBP_ASSERT_PRIVATE_TYPE_OP_IMPL(a, b, op, printerOp, type, valuePrefix)\
    do {                                                                       \
        nbp_printer_type_value_t tmpA, tmpB;                                   \
        tmpA.valuePrefix ## Value = a; tmpB.valuePrefix ## Value = b;          \
        if (tmpA.valuePrefix ## Value op tmpB.valuePrefix ## Value) {          \
            nbp_test_increment_asserts_stats(                                  \
                nbpParamTest,                                                  \
                NBP_ASSERT_STATUS_PASSED,                                      \
                nbpParamAssertType                                             \
            );                                                                 \
            nbp_printer_notify_assert_type_op_result(                          \
                nbpParamTest,                                                  \
                tmpA,                                                          \
                tmpB,                                                          \
                type,                                                          \
                printerOp,                                                     \
                nbpParamAssertType,                                            \
                NBP_ASSERT_STATUS_PASSED,                                      \
                __LINE__,                                                      \
                NBP_MEMORY_NULL_POINTER,                                       \
                nbpParamSuccessMessage                                         \
            );                                                                 \
        } else {                                                               \
            nbp_test_increment_asserts_stats(                                  \
                nbpParamTest,                                                  \
                NBP_ASSERT_STATUS_FAILED,                                      \
                nbpParamAssertType                                             \
            );                                                                 \
            nbp_printer_notify_assert_type_op_result(                          \
                nbpParamTest,                                                  \
                tmpA,                                                          \
                tmpB,                                                          \
                type,                                                          \
                printerOp,                                                     \
                nbpParamAssertType,                                            \
                NBP_ASSERT_STATUS_FAILED,                                      \
                __LINE__,                                                      \
                nbpParamFailureMessage,                                        \
                NBP_MEMORY_NULL_POINTER                                        \
            );                                                                 \
            if (nbpParamAssertType != NBP_ASSERT_NON_FATAL) {                  \
                return;                                                        \
            }                                                                  \
        }                                                                      \
        nbpParamAssertType      = NBP_ASSERT_NON_FATAL;                        \
        nbpParamSuccessMessage  = NBP_MEMORY_NULL_POINTER;                     \
        nbpParamFailureMessage  = NBP_MEMORY_NULL_POINTER;                     \
    } while (0);

#define NBP_ASSERT_PRIVATE_LDOUBLE_OP_IMPL(a, b, op, printerOp)                \
    do {                                                                       \
        long double ldA, ldB;                                                  \
        nbp_printer_type_value_t tmpA, tmpB;                                   \
        ldA = a; ldB = b;                                                      \
        tmpA.ldoubleValue = &ldA; tmpB.ldoubleValue = &ldB;                    \
        if (ldA op ldB) {                                                      \
            nbp_test_increment_asserts_stats(                                  \
                nbpParamTest,                                                  \
                NBP_ASSERT_STATUS_PASSED,                                      \
                nbpParamAssertType                                             \
            );                                                                 \
            nbp_printer_notify_assert_type_op_result(                          \
                nbpParamTest,                                                  \
                tmpA,                                                          \
                tmpB,                                                          \
                NBP_PRINTER_TYPE_LDOUBLE,                                      \
                printerOp,                                                     \
                nbpParamAssertType,                                            \
                NBP_ASSERT_STATUS_PASSED,                                      \
                __LINE__,                                                      \
                NBP_MEMORY_NULL_POINTER,                                       \
                nbpParamSuccessMessage                                         \
            );                                                                 \
        } else {                                                               \
            nbp_test_increment_asserts_stats(                                  \
                nbpParamTest,                                                  \
                NBP_ASSERT_STATUS_FAILED,                                      \
                nbpParamAssertType                                             \
            );                                                                 \
            nbp_printer_notify_assert_type_op_result(                          \
                nbpParamTest,                                                  \
                tmpA,                                                          \
                tmpB,                                                          \
                NBP_PRINTER_TYPE_LDOUBLE,                                      \
                printerOp,                                                     \
                nbpParamAssertType,                                            \
                NBP_ASSERT_STATUS_FAILED,                                      \
                __LINE__,                                                      \
                nbpParamFailureMessage,                                        \
                NBP_MEMORY_NULL_POINTER                                        \
            );                                                                 \
            if (nbpParamAssertType != NBP_ASSERT_NON_FATAL) {                  \
                return;                                                        \
            }                                                                  \
        }                                                                      \
        nbpParamAssertType      = NBP_ASSERT_NON_FATAL;                        \
        nbpParamSuccessMessage  = NBP_MEMORY_NULL_POINTER;                     \
        nbpParamFailureMessage  = NBP_MEMORY_NULL_POINTER;                     \
    } while (0);

#define NBP_ASSERT_PRIVATE_PARSE_ASSERT_PARAMETERS(...)                        \
    NBP_PP_CONCAT(                                                             \
        NBP_PP_PROCESSING_PARAM_,                                              \
        NBP_PP_VARCOUNT(P ## __VA_ARGS__)                                      \
    )(P ## __VA_ARGS__)

#define NBP_PP_EAT_PP_NBP_ASSERT_SUCCESS_MESSAGE(msg)                          \
    nbpParamSuccessMessage = msg;

#define NBP_PP_EAT_PP_NBP_ASSERT_FAILURE_MESSAGE(msg)                          \
    nbpParamFailureMessage = msg;

#define NBP_PP_EAT_PP_NBP_ASSERT_NON_FATAL                                     \
    nbpParamAssertType = NBP_ASSERT_NON_FATAL;
#define NBP_PP_EAT_PP_NBP_ASSERT_FATAL                                         \
    nbpParamAssertType = NBP_ASSERT_FATAL;
#define NBP_PP_EAT_PP_NBP_ASSERT_FATAL_FOR_TEST                                \
    nbpParamAssertType = NBP_ASSERT_FATAL_FOR_TEST;
#define NBP_PP_EAT_PP_NBP_ASSERT_FATAL_FOR_MODULE                              \
    nbpParamAssertType = NBP_ASSERT_FATAL_FOR_MODULE;

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CALLBACK_INIT(func)                                      \
    static void NBP_PP_CONCAT(nbp_scheduler_callback_, func)(                  \
        void                                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CALLBACK_UNINIT(func)                                    \
    static void NBP_PP_CONCAT(nbp_scheduler_callback_, func)(                  \
        void                                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CALLBACK_RUN(func)                                       \
    static void NBP_PP_CONCAT(nbp_scheduler_callback_, func)(                  \
        void                                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CALLBACK_RUN_TEST(func)                                  \
    static void NBP_PP_CONCAT(nbp_scheduler_callback_, func)(                  \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest            \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CALLBACK_RUN_TEST_CTX(func)                              \
    static void NBP_PP_CONCAT(nbp_scheduler_callback_, func)(                  \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER void* nbpParamCtx                           \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CALLBACK_RUN_MODULE(func)                                \
    static void NBP_PP_CONCAT(nbp_scheduler_callback_, func)(                  \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CALLBACK_RUN_MODULE_CTX(func)                            \
    static void NBP_PP_CONCAT(nbp_scheduler_callback_, func)(                  \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule,       \
        NBP_MAYBE_UNUSED_PARAMETER void* nbpParamCtx                           \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CALLBACK_RUN_MODULE_COMPLETED(func)                      \
    static void NBP_PP_CONCAT(nbp_scheduler_callback_, func)(                  \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CALLBACKS(...)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER(name, ...)                                               \
    void NBP_PP_CONCAT(nbp_scheduler_config_, name)(                           \
        NBP_MAYBE_UNUSED_PARAMETER nbp_scheduler_interface_t* nbpParamScheduler\
    )                                                                          \
    {                                                                          \
        NBP_SCHEDULER_PRIVATE_GENERATE_CONFIG(P_ ## __VA_ARGS__)               \
    }                                                                          \
    struct nbp_scheduler_interface_t                                           \
    NBP_PP_CONCAT(nbpScheduler, name) = {                                      \
        .schedulerName              = #name,                                   \
        .configFunc                 =                                          \
            NBP_PP_CONCAT(nbp_scheduler_config_, name),                        \
        .initCbk                    = NBP_MEMORY_NULL_POINTER,                 \
        .uninitCbk                  = NBP_MEMORY_NULL_POINTER,                 \
        .runCbk                     = NBP_MEMORY_NULL_POINTER,                 \
        .runTestCbk                 = NBP_MEMORY_NULL_POINTER,                 \
        .runTestCtxCbk              = NBP_MEMORY_NULL_POINTER,                 \
        .runModuleCbk               = NBP_MEMORY_NULL_POINTER,                 \
        .runModuleCtxCbk            = NBP_MEMORY_NULL_POINTER,                 \
        .runModuleCompletedCbk      = NBP_MEMORY_NULL_POINTER,                 \
    }

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_RUN_TEST(test)                                           \
    nbp_scheduler_run_test(test)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CTX nbpParamCtx

#define NBP_SCHEDULER_PRIVATE_GENERATE_CONFIG(...)                             \
    NBP_PP_CONCAT(                                                             \
        NBP_PP_PROCESSING_PARAM_,                                              \
        NBP_PP_VARCOUNT(P ## __VA_ARGS__)                                      \
    )(P ## __VA_ARGS__)                                                        \

#define NBP_PP_EAT_PP_NBP_SCHEDULER_CALLBACKS(...)                             \
    NBP_PP_CONCAT(                                                             \
        NBP_PP_PROCESSING_PARAM_2_,                                            \
        NBP_PP_VARCOUNT(PP_ ## __VA_ARGS__)                                    \
    )(PP_ ## __VA_ARGS__)

#define NBP_PP_EAT_PP_NBP_SCHEDULER_CALLBACK_INIT(func)                        \
    nbpParamScheduler->initCbk =                                               \
        NBP_PP_CONCAT(nbp_scheduler_callback_, func);
#define NBP_PP_EAT_PP_NBP_SCHEDULER_CALLBACK_UNINIT(func)                      \
    nbpParamScheduler->uninitCbk =                                             \
        NBP_PP_CONCAT(nbp_scheduler_callback_, func);
#define NBP_PP_EAT_PP_NBP_SCHEDULER_CALLBACK_RUN(func)                         \
    nbpParamScheduler->runCbk =                                                \
        NBP_PP_CONCAT(nbp_scheduler_callback_, func);
#define NBP_PP_EAT_PP_NBP_SCHEDULER_CALLBACK_RUN_TEST(func)                    \
    nbpParamScheduler->runTestCbk =                                            \
        NBP_PP_CONCAT(nbp_scheduler_callback_, func);
#define NBP_PP_EAT_PP_NBP_SCHEDULER_CALLBACK_RUN_TEST_CTX(func)                \
    nbpParamScheduler->runTestCtxCbk =                                         \
        NBP_PP_CONCAT(nbp_scheduler_callback_, func);
#define NBP_PP_EAT_PP_NBP_SCHEDULER_CALLBACK_RUN_MODULE(func)                  \
    nbpParamScheduler->runModuleCbk =                                          \
        NBP_PP_CONCAT(nbp_scheduler_callback_, func);
#define NBP_PP_EAT_PP_NBP_SCHEDULER_CALLBACK_RUN_MODULE_CTX(func)              \
    nbpParamScheduler->runModuleCtxCbk =                                       \
        NBP_PP_CONCAT(nbp_scheduler_callback_, func);
#define NBP_PP_EAT_PP_NBP_SCHEDULER_CALLBACK_RUN_MODULE_COMPLETED(func)        \
    nbpParamScheduler->runModuleCompletedCbk =                                 \
        NBP_PP_CONCAT(nbp_scheduler_callback_, func);

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_INIT(func)                                        \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        void                                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_UNINIT(func)                                      \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        void                                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_REPORT_ERROR(func)                                \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_error_t nbpParamError                   \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_EXIT_TRIGGERED(func)                              \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamErrorCode                       \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_HANDLE_VERSION_COMMAND(func)                      \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_TEST_STARTED(func)                                \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest            \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_TEST_COMPLETED(func)                              \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest            \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_MODULE_STARTED(func)                              \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_MODULE_COMPLETED(func)                            \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_BEFORE_RUN(func)                                  \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_AFTER_RUN(func)                                   \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_RUN_TEST(func)                                    \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest            \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_RUN_MODULE(func)                                  \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_RUN_MODULE_COMPLETED(func)                        \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_ASSERT_RESULT(func)                               \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamCond,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamAssertType,            \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamStatus,                \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamAssertFailureMsg,       \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamAssertSuccessMsg        \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_ASSERT_TYPE_OP_RESULT(func)                       \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER nbp_printer_type_value_t nbpParamVal1,      \
        NBP_MAYBE_UNUSED_PARAMETER nbp_printer_type_value_t nbpParamVal2,      \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamValueType,             \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamAssertType,            \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamStatus,                \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamAssertFailureMsg,       \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamAssertSuccessMsg        \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACKS(...)

/*
 * TODO: add docs
 */
#define NBP_PRINTER(name, ...)                                                 \
    void NBP_PP_CONCAT(nbp_printer_config_, name)(                             \
        NBP_MAYBE_UNUSED_PARAMETER nbp_printer_interface_t* nbpParamPrinter    \
    )                                                                          \
    {                                                                          \
        NBP_PRINTER_PRIVATE_GENERATE_CONFIG(P_ ## __VA_ARGS__)                 \
    }                                                                          \
    nbp_printer_interface_t NBP_PP_CONCAT(nbpPrinter, name) = {                \
        .printerName                        = #name,                           \
        .isInitialized                      = 0,                               \
        .configFunc                         =                                  \
            NBP_PP_CONCAT(nbp_printer_config_, name),                          \
        .initCbk                            = NBP_MEMORY_NULL_POINTER,         \
        .uninitCbk                          = NBP_MEMORY_NULL_POINTER,         \
        .reportErrorCbk                     = NBP_MEMORY_NULL_POINTER,         \
        .exitTriggeredCbk                   = NBP_MEMORY_NULL_POINTER,         \
        .handleVersionCommandCbk            = NBP_MEMORY_NULL_POINTER,         \
        .testStartedCbk                     = NBP_MEMORY_NULL_POINTER,         \
        .testCompletedCbk                   = NBP_MEMORY_NULL_POINTER,         \
        .moduleStartedCbk                   = NBP_MEMORY_NULL_POINTER,         \
        .moduleCompletedCbk                 = NBP_MEMORY_NULL_POINTER,         \
        .beforeRunCbk                       = NBP_MEMORY_NULL_POINTER,         \
        .afterRunCbk                        = NBP_MEMORY_NULL_POINTER,         \
        .runTestCbk                         = NBP_MEMORY_NULL_POINTER,         \
        .runModuleCbk                       = NBP_MEMORY_NULL_POINTER,         \
        .runModuleCompletedCbk              = NBP_MEMORY_NULL_POINTER,         \
        .assertResultCbk                    = NBP_MEMORY_NULL_POINTER,         \
        .assertTypeOpResultCbk              = NBP_MEMORY_NULL_POINTER          \
    }

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_OPERATOR() nbpParamOperator

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_OPERATOR_STR()                                         \
    nbp_printer_operator_to_string(nbpParamOperator)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_CONDITION() nbpParamCond

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_VALUE_TYPE() nbpParamValueType

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FIRST_VALUE() nbpParamVal1.stringValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SECOND_VALUE() nbpParamVal2.stringValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FIRST_VALUE_AS_CHAR() nbpParamVal1.charValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SECOND_VALUE_AS_CHAR() nbpParamVal2.charValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FIRST_VALUE_AS_SHORT() nbpParamVal1.shortValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SECOND_VALUE_AS_SHORT() nbpParamVal2.shortValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FIRST_VALUE_AS_USHORT() nbpParamVal1.ushortValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SECOND_VALUE_AS_USHORT() nbpParamVal2.ushortValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FIRST_VALUE_AS_INT() nbpParamVal1.intValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SECOND_VALUE_AS_INT() nbpParamVal2.intValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FIRST_VALUE_AS_UINT() nbpParamVal1.uintValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SECOND_VALUE_AS_UINT() nbpParamVal2.uintValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FIRST_VALUE_AS_LONG() nbpParamVal1.longValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SECOND_VALUE_AS_LONG() nbpParamVal2.longValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FIRST_VALUE_AS_ULONG() nbpParamVal1.ulongValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SECOND_VALUE_AS_ULONG() nbpParamVal2.ulongValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FIRST_VALUE_AS_LLONG() nbpParamVal1.llongValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SECOND_VALUE_AS_LLONG() nbpParamVal2.llongValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FIRST_VALUE_AS_ULLONG() nbpParamVal1.ullongValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SECOND_VALUE_AS_ULLONG() nbpParamVal2.ullongValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FIRST_VALUE_AS_FLOAT() nbpParamVal1.floatValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SECOND_VALUE_AS_FLOAT() nbpParamVal2.floatValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FIRST_VALUE_AS_DOUBLE() nbpParamVal1.doubleValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SECOND_VALUE_AS_DOUBLE() nbpParamVal2.doubleValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FIRST_VALUE_AS_LDOUBLE() *nbpParamVal1.ldoubleValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SECOND_VALUE_AS_LDOUBLE() *nbpParamVal2.ldoubleValue

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_LINE_NUMBER() nbpParamLine

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_ASSERT_STATUS() nbpParamStatus

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_ASSERT_TYPE() nbpParamAssertType

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_ASSERT_FAILURE_MESSAGE() nbpParamAssertFailureMsg

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FAILURE_MESSAGE NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_ASSERT_SUCCESS_MESSAGE() nbpParamAssertSuccessMsg

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_SUCCESS_MESSAGE NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_ERROR() nbpParamError

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_EXIT_ERROR_CODE() nbpParamErrorCode

#define NBP_PRINTER_PRIVATE_GENERATE_CONFIG(...)                               \
    NBP_PP_CONCAT(                                                             \
        NBP_PP_PROCESSING_PARAM_,                                              \
        NBP_PP_VARCOUNT(P ## __VA_ARGS__)                                      \
    )(P ## __VA_ARGS__)

#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACKS(...)                               \
    NBP_PP_CONCAT(                                                             \
        NBP_PP_PROCESSING_PARAM_2_,                                            \
        NBP_PP_VARCOUNT(PP_ ## __VA_ARGS__)                                    \
    )(PP_ ## __VA_ARGS__)

#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_INIT(func)                          \
    nbpParamPrinter->initCbk =                                                 \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_UNINIT(func)                        \
    nbpParamPrinter->uninitCbk =                                               \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_REPORT_ERROR(func)                  \
    nbpParamPrinter->reportErrorCbk =                                          \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_EXIT_TRIGGERED(func)                \
    nbpParamPrinter->exitTriggeredCbk =                                        \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_HANDLE_VERSION_COMMAND(func)        \
    nbpParamPrinter->handleVersionCommandCbk =                                 \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_TEST_STARTED(func)                  \
    nbpParamPrinter->testStartedCbk =                                          \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_TEST_COMPLETED(func)                \
    nbpParamPrinter->testCompletedCbk =                                        \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_MODULE_STARTED(func)                \
    nbpParamPrinter->moduleStartedCbk =                                        \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_MODULE_COMPLETED(func)              \
    nbpParamPrinter->moduleCompletedCbk =                                      \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_BEFORE_RUN(func)                    \
    nbpParamPrinter->beforeRunCbk =                                            \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_AFTER_RUN(func)                     \
    nbpParamPrinter->afterRunCbk =                                             \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_RUN_TEST(func)                      \
    nbpParamPrinter->runTestCbk =                                              \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_RUN_MODULE(func)                    \
    nbpParamPrinter->runModuleCbk =                                            \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_RUN_MODULE_COMPLETED(func)          \
    nbpParamPrinter->runModuleCompletedCbk =                                   \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_ASSERT_RESULT(func)                 \
    nbpParamPrinter->assertResultCbk =                                         \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_ASSERT_TYPE_OP_RESULT(func)         \
    nbpParamPrinter->assertTypeOpResultCbk =                                   \
        NBP_PP_CONCAT(nbp_printer_callback_, func);

/*
 * TODO: add docs
 */
#define NBP_ERROR_REPORT(errCode)                                              \
    nbp_printer_notify_report_error(errCode, __LINE__, __FILE__)

/*
 * TODO: add docs
 */
#define NBP_ERROR_REPORT_CTX_STRING(errCode, str)                              \
    nbp_printer_notify_report_error_ctx_string(errCode, __LINE__, __FILE__, str)
/*
 * TODO: add docs
 */
#define NBP_ERROR_REPORT_CTX_CUSTOM(errCode, ctx)                              \
    nbp_printer_notify_report_error_ctx_custom(errCode, __LINE__, __FILE__, ctx)

/*
 * TODO: add docs
 */
#define NBP_ERROR_GET_CODE(err) err.errorCode

/*
 * TODO: add docs
 */
#define NBP_ERROR_GET_LINE(err) err.line

/*
 * TODO: add docs
 */
#define NBP_ERROR_GET_FILENAME(err) err.filename

/*
 * TODO: add docs
 */
#define NBP_ERROR_GET_CONTEXT_TYPE(err) err.contextType

/*
 * TODO: add docs
 */
#define NBP_ERROR_GET_CONTEXT_STRING(err) err.contextString

/*
 * TODO: add docs
 */
#define NBP_ERROR_GET_CONTEXT_CUSTOM(err) err.contextCustom

#ifndef NBP_CUSTOM_EXIT

#include <stdlib.h>

/*
 * TODO: add docs
 */
#define NBP_EXIT(errorCode)                                                    \
    nbp_printer_notify_exit_triggered(errorCode);                              \
    exit(errorCode)

#else // NBP_CUSTOM_EXIT is defined

/*
 * TODO: add docs
 */
#ifndef NBP_EXIT_FUNC
#error "Custom exit is enabled but no exit function is provided"
#endif // end if NBP_EXIT

#define NBP_EXIT(errorCode)                                                    \
    nbp_printer_notify_exit_triggered(errorCode);                              \
    NBP_EXIT_FUNC(errorCode)

#endif // end if NBP_CUSTOM_EXIT


#define NBP_PP_PRIVATE_CONCAT_HELPER(a, b) a ## b

#define NBP_PP_CONCAT(a, b) NBP_PP_PRIVATE_CONCAT_HELPER(a, b)

#define NBP_PP_PRIVATE_VARCOUNT_HELPER(                                        \
    _, _32, _31, _30, _29, _28, _27, _26, _25, _24, _23, _22, _21, _20, _19,   \
    _18, _17, _16, _15, _14, _13, _12, _11, _10, _9, _8, _7, _6, _5, _4, _3,   \
    _2, _n, ...) _n

#define NBP_PP_VARCOUNT(...)                                                   \
    NBP_PP_PRIVATE_VARCOUNT_HELPER(                                            \
        P ## __VA_ARGS__,                                                      \
        32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15,\
        14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1,                         \
    )

// This macro is generated when a variadic macro is used with no parameters
#define NBP_PP_EAT_PP_

#define NBP_PP_PROCESSING_PARAM_1(param)                                       \
    NBP_PP_EAT_ ## param
#define NBP_PP_PROCESSING_PARAM_2(param, ...)                                  \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_1(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_3(param, ...)                                  \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_4(param, ...)                                  \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_3(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_5(param, ...)                                  \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_4(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_6(param, ...)                                  \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_5(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_7(param, ...)                                  \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_6(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_8(param, ...)                                  \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_7(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_9(param, ...)                                  \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_8(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_10(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_9(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_11(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_10(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_12(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_11(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_13(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_12(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_14(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_13(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_15(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_14(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_16(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_15(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_17(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_16(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_18(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_17(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_19(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_18(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_20(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_19(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_21(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_20(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_22(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_21(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_23(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_22(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_24(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_23(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_25(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_24(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_26(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_25(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_27(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_26(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_28(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_27(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_29(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_28(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_30(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_29(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_31(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_30(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_32(param, ...)                                 \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_31(PP_ ## __VA_ARGS__)

#define NBP_PP_PROCESSING_PARAM_2_1(param)                                     \
    NBP_PP_EAT_ ## param
#define NBP_PP_PROCESSING_PARAM_2_2(param, ...)                                \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_1(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_3(param, ...)                                \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_2(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_4(param, ...)                                \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_3(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_5(param, ...)                                \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_4(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_6(param, ...)                                \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_5(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_7(param, ...)                                \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_6(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_8(param, ...)                                \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_7(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_9(param, ...)                                \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_8(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_10(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_9(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_11(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_10(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_12(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_11(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_13(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_12(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_14(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_13(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_15(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_14(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_16(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_15(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_17(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_16(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_18(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_17(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_19(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_18(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_20(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_19(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_21(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_20(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_22(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_21(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_23(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_22(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_24(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_23(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_25(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_24(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_26(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_25(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_27(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_26(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_28(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_27(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_29(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_28(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_30(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_29(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_31(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_30(PP_ ## __VA_ARGS__)
#define NBP_PP_PROCESSING_PARAM_2_32(param, ...)                               \
    NBP_PP_EAT_ ## param                                                       \
    NBP_PP_PROCESSING_PARAM_2_31(PP_ ## __VA_ARGS__)

#define NBP_MAYBE_UNUSED_PARAMETER

#ifdef NBP_COMPILER_GCC

#undef NBP_MAYBE_UNUSED_PARAMETER
#define NBP_MAYBE_UNUSED_PARAMETER __attribute__ ((unused))

#endif // end if NBP_COMPILER_GCC

#ifdef NBP_COMPILER_CLANG

#undef NBP_MAYBE_UNUSED_PARAMETER
#define NBP_MAYBE_UNUSED_PARAMETER __attribute__ ((unused))

#endif // end if NBP_COMPILER_CLANG


/*
 * TODO: add docs
 */
#define NBP_ERROR_CONTEXT_EMPTY                     (unsigned int) 0x30000000
#define NBP_ERROR_CONTEXT_STRING                    (unsigned int) 0x30000001
#define NBP_ERROR_CONTEXT_CUSTOM                    (unsigned int) 0x30000002

/*
 * TODO: add docs
 */
#define NBP_ERROR_CODE_TYPE int

/*
 * TODO: add docs
 */
#define NBP_ERROR_CODE_SUCCESS                                  (int) 0
#define NBP_ERROR_CODE_TESTS_FAILED                             (int) 1
#define NBP_ERROR_CODE_NOT_ALL_TESTS_RUN                        (int) 2
#define NBP_ERROR_CODE_OUT_OF_MEMORY                            (int) 3
#define NBP_ERROR_CODE_UNKNOWN_OPERATOR                         (int) 4
#define NBP_ERROR_CODE_INVALID_SCHEDULER                        (int) 5
#define NBP_ERROR_CODE_SCHEDULER_RUN_DISABLED                   (int) 6
#define NBP_ERROR_CODE_INVALID_CMDLINE                          (int) 7
#define NBP_ERROR_CODE_SYNC_ERROR                               (int) 8
#define NBP_ERROR_CODE_GENERIC_ERROR                            (int) 9
#define NBP_ERROR_CODE_INTERNAL_ERROR                           (int) 10
#define NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA                 (int) 11
#define NBP_ERROR_CODE_TEST_ALREADY_RUN                         (int) 12
#define NBP_ERROR_CODE_MODULE_ALREADY_RUN                       (int) 13
#define NBP_ERROR_CODE_UNEXPECTED_TEST_STATE                    (int) 14
#define NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE                  (int) 15

struct nbp_error_t {
    NBP_ERROR_CODE_TYPE errorCode;
    int line;
    const char* filename;
    unsigned int contextType;
    union {
        const char* contextString;
        void* contextCustom;
    };
};
typedef struct nbp_error_t nbp_error_t;

#ifdef NBP_MT_SUPPORT

#ifdef NBP_OS_LINUX

#include <semaphore.h>

/*
 * Atomic unsigned int wrapper
 */

#define NBP_SYNC_ATOMIC_UINT_TYPE unsigned int

#define NBP_SYNC_ATOMIC_UINT_INIT(val) val

#define NBP_SYNC_ATOMIC_UINT_LOAD(ptr) __atomic_load_n((ptr), __ATOMIC_SEQ_CST)

#define NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(ptr, value)                         \
    __sync_add_and_fetch((ptr), (value))

#define NBP_SYNC_ATOMIC_UINT_CAS(ptr, oldVal, newVal)                          \
    __sync_val_compare_and_swap((ptr), (oldVal), (newVal))

/*
 * Event wrapper
 */

#define NBP_SYNC_EVENT_TYPE sem_t

#define NBP_SYNC_EVENT_DEFAULT_VALUE { .__align = 0 }

#define NBP_SYNC_EVENT_INIT(ev)                                                \
    sem_init(&ev, 0, 0) == 0                                                   \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#define NBP_SYNC_EVENT_UNINIT(ev)                                              \
    sem_destroy(&ev) == 0                                                      \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#define NBP_SYNC_EVENT_WAIT(ev)                                                \
    sem_wait(&ev) == 0 && sem_post(&ev) == 0                                   \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#define NBP_SYNC_EVENT_NOTIFY(ev)                                              \
    sem_post(&ev) == 0                                                         \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#endif // end if NBP_OS_LINUX

#ifdef NBP_OS_WINDOWS
#error "Not supported"
#endif // end if NBP_OS_WINDOWS

#ifdef NBP_OS_MAC
#error "Not supported"
#endif // end if NBP_OS_MAC

#ifdef NBP_OS_CUSTOM
#error "Not supported"
#endif // end if NBP_OS_CUSTOM

/*
 * Check if atomic uint wrapper is defined, otherwise define a dummy atomic uint
 * wrapper.
 * If NBP_OS_* is not defined then the atomic uint wrapper will not be defined
 * so the compiler will generate a lot of errors and the error message that
 * says that there is no NBP_OS_* defined is hard to see.
 */

#ifndef NBP_SYNC_ATOMIC_UINT_TYPE
#define NBP_SYNC_ATOMIC_UINT_TYPE unsigned int
#endif // end if NBP_SYNC_ATOMIC_UINT_TYPE

#ifndef NBP_SYNC_ATOMIC_UINT_INIT
#define NBP_SYNC_ATOMIC_UINT_INIT(val) val
#endif // end if NBP_SYNC_ATOMIC_UINT_INIT

#ifndef NBP_SYNC_ATOMIC_UINT_LOAD
#define NBP_SYNC_ATOMIC_UINT_LOAD(ptr) (*(ptr))
#endif // end if NBP_SYNC_ATOMIC_UINT_LOAD

#ifndef NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH
#define NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(ptr, value)                         \
    ((*(ptr)) += (value))
#endif // end if NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH

#ifndef NBP_SYNC_ATOMIC_UINT_CAS
#define NBP_SYNC_ATOMIC_UINT_CAS(ptr, oldVal, newVal)                          \
    ((*(ptr)) == (oldVal) ? (*(ptr)) = (newVal), (oldVal) : (*(ptr)))
#endif // end if NBP_SYNC_ATOMIC_UINT_CAS

/*
 * Check if event wrapper is defined, otherwise define a dummy event wrapper.
 * If NBP_OS_* is not defined then the event wrapper will not be defined so the
 * compiler will generate a lot of errors and the error message that says that
 * there is no NBP_OS_* defined is hard to see.
 */

#ifndef NBP_SYNC_EVENT_TYPE
#define NBP_SYNC_EVENT_TYPE int
#endif // end if NBP_SYNC_EVENT_TYPE

#ifndef NBP_SYNC_EVENT_DEFAULT_VALUE
#define NBP_SYNC_EVENT_DEFAULT_VALUE 0
#endif // end if NBP_SYNC_EVENT_DEFAULT_VALUE

#ifndef NBP_SYNC_EVENT_INIT
#define NBP_SYNC_EVENT_INIT(ev) NBP_ERROR_CODE_SYNC_ERROR
#endif // end if NBP_SYNC_EVENT_INIT

#ifndef NBP_SYNC_EVENT_UNINIT
#define NBP_SYNC_EVENT_UNINIT(ev) NBP_ERROR_CODE_SYNC_ERROR
#endif // end if NBP_SYNC_EVENT_UNINIT

#ifndef NBP_SYNC_EVENT_WAIT
#define NBP_SYNC_EVENT_WAIT(ev) NBP_ERROR_CODE_SYNC_ERROR
#endif // end if NBP_SYNC_EVENT_WAIT

#ifndef NBP_SYNC_EVENT_NOTIFY
#define NBP_SYNC_EVENT_NOTIFY(ev) NBP_ERROR_CODE_SYNC_ERROR
#endif // end if NBP_SYNC_EVENT_NOTIFY

#else // NBP_MT_SUPPORT not defined

/*
 * Atomic unsigned int wrapper
 */

#define NBP_SYNC_ATOMIC_UINT_TYPE unsigned int

#define NBP_SYNC_ATOMIC_UINT_INIT(val) val

#define NBP_SYNC_ATOMIC_UINT_LOAD(ptr) (*(ptr))

#define NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(ptr, value)                         \
    ((*(ptr)) += (value))

#define NBP_SYNC_ATOMIC_UINT_CAS(ptr, oldVal, newVal)                          \
    ((*(ptr)) == (oldVal) ? (*(ptr)) = (newVal), (oldVal) : (*(ptr)))

/*
 * Event wrapper
 */

#define NBP_SYNC_EVENT_TYPE int

#define NBP_SYNC_EVENT_DEFAULT_VALUE 0

#define NBP_SYNC_EVENT_INIT(ev) NBP_ERROR_CODE_SUCCESS

#define NBP_SYNC_EVENT_UNINIT(ev) NBP_ERROR_CODE_SUCCESS

#define NBP_SYNC_EVENT_WAIT(ev) NBP_ERROR_CODE_SUCCESS

#define NBP_SYNC_EVENT_NOTIFY(ev) NBP_ERROR_CODE_SUCCESS

#endif // end if NBP_MT_SUPPORT

/*
 * TODO: add docs
 */
#define NBP_ASSERT_STATUS_FAILED            (unsigned int) 0x70000000
#define NBP_ASSERT_STATUS_PASSED            (unsigned int) 0x70000001

/*
 * TODO: add docs
 */
#define NBP_ASSERT_NON_FATAL                (unsigned int) 0x71000000
#define NBP_ASSERT_FATAL                    (unsigned int) 0x71000001
#define NBP_ASSERT_FATAL_FOR_TEST           (unsigned int) 0x71000002
#define NBP_ASSERT_FATAL_FOR_MODULE         (unsigned int) 0x71000003

/*
 * TODO: add docs
 */
#define NBP_TEST_STATE_NOT_INITIALIZED  (unsigned int) 0x10000000
#define NBP_TEST_STATE_READY            (unsigned int) 0x10000001
#define NBP_TEST_STATE_RUNNING          (unsigned int) 0x10000002
#define NBP_TEST_STATE_PASSED           (unsigned int) 0x10000003
#define NBP_TEST_STATE_FAILED           (unsigned int) 0x10000004
#define NBP_TEST_STATE_SKIPPED          (unsigned int) 0x10000005

#define NBP_TEST_PRIVATE_SKIP_NOT_SET   (unsigned int) 0x11000000
#define NBP_TEST_PRIVATE_SKIP_SET       (unsigned int) 0x11000001
#define NBP_TEST_PRIVATE_SKIP_PROCESSED (unsigned int) 0x11000002

struct nbp_test_details_t;

typedef void (*nbp_test_setup_pfn_t)(
    struct nbp_test_details_t* /* current test */
);

typedef void (*nbp_test_teardown_pfn_t)(
    struct nbp_test_details_t* /* current test */
);

typedef void (*nbp_test_config_pfn_t)(
    struct nbp_test_details_t* /* current test */
);

typedef void (*nbp_test_pfn_t)(
    struct nbp_test_details_t*, /* current test */
    unsigned int, /* assert type */
    const char*, /* success message */
    const char* /* failure message */
);

struct nbp_test_details_t {
    const char* testName;
    unsigned int testId;
    nbp_test_pfn_t testFunc;
    nbp_test_config_pfn_t configFunc;
    struct nbp_module_details_t* module;

    nbp_test_setup_pfn_t testSetupFunc;
    nbp_test_teardown_pfn_t testTeardownFunc;

    struct nbp_test_details_t* next;
    struct nbp_test_details_t* prev;

    NBP_SYNC_ATOMIC_UINT_TYPE testState;
    NBP_SYNC_ATOMIC_UINT_TYPE isSkipped;

    struct {
        struct {
            unsigned int numPassed;
            unsigned int numFailed;
        } nonFatal, fatal, fatalForTest, fatalForModule;
    } asserts;
};
typedef struct nbp_test_details_t nbp_test_details_t;

/*
 * TODO: add docs
 */
#define NBP_MODULE_STATE_NOT_INITIALIZED  (unsigned int) 0x20000000
#define NBP_MODULE_STATE_READY            (unsigned int) 0x20000001
#define NBP_MODULE_STATE_RUNNING          (unsigned int) 0x20000002
#define NBP_MODULE_STATE_PASSED           (unsigned int) 0x20000003
#define NBP_MODULE_STATE_FAILED           (unsigned int) 0x20000004
#define NBP_MODULE_STATE_SKIPPED          (unsigned int) 0x20000005

#define NBP_MODULE_PRIVATE_SKIP_NOT_SET   (unsigned int) 0x21000000
#define NBP_MODULE_PRIVATE_SKIP_SET       (unsigned int) 0x21000001
#define NBP_MODULE_PRIVATE_SKIP_PROCESSED (unsigned int) 0x21000002

struct nbp_module_details_t;

typedef void(*nbp_module_setup_pfn_t)(
    struct nbp_module_details_t* /* current module */
);

typedef void(*nbp_module_teardown_pfn_t)(
    struct nbp_module_details_t* /* current module */
);

typedef void (*nbp_module_config_pfn_t)(
    struct nbp_module_details_t* /* current module */
);

typedef void (*nbp_module_pfn_t)(
    struct nbp_module_details_t*, /* current module */
    nbp_module_setup_pfn_t, /* module setup pfn */
    nbp_module_teardown_pfn_t, /* module teardown pfn */
    nbp_test_setup_pfn_t, /* test setup pfn */
    nbp_test_teardown_pfn_t /* test teardown pfn */
);

struct nbp_module_details_t {
    const char* moduleName;
    unsigned int moduleId;
    nbp_module_pfn_t moduleFunc;
    nbp_module_config_pfn_t configFunc;
    struct nbp_module_details_t* parent;

    nbp_module_setup_pfn_t setupFunc;
    nbp_module_teardown_pfn_t teardownFunc;

    struct nbp_test_details_t* firstTest;
    struct nbp_test_details_t* lastTest;

    struct nbp_module_details_t* firstModule;
    struct nbp_module_details_t* lastModule;

    struct nbp_module_details_t* next;
    struct nbp_module_details_t* prev;

    unsigned int depth;
    NBP_SYNC_EVENT_TYPE runEvent;
    NBP_SYNC_EVENT_TYPE setupEvent;
    NBP_SYNC_ATOMIC_UINT_TYPE isSkipped;
    NBP_SYNC_ATOMIC_UINT_TYPE moduleState;

    unsigned int taskNum;
    NBP_SYNC_ATOMIC_UINT_TYPE completedTaskNum;

    unsigned int isEmptyModule;
    unsigned int emptySubmodulesNum;

    struct {
        unsigned int num;
        NBP_SYNC_ATOMIC_UINT_TYPE numPassed;
        NBP_SYNC_ATOMIC_UINT_TYPE numFailed;
        NBP_SYNC_ATOMIC_UINT_TYPE numSkipped;
    } tests;

    struct {
        unsigned int num;
        NBP_SYNC_ATOMIC_UINT_TYPE numPassed;
        NBP_SYNC_ATOMIC_UINT_TYPE numFailed;
        NBP_SYNC_ATOMIC_UINT_TYPE numSkipped;
    } modules;

    struct {
        struct {
            NBP_SYNC_ATOMIC_UINT_TYPE numPassed;
            NBP_SYNC_ATOMIC_UINT_TYPE numFailed;
        } nonFatal, fatal, fatalForTest, fatalForModule;
    } asserts;
};
typedef struct nbp_module_details_t nbp_module_details_t;

struct nbp_scheduler_interface_t;
typedef struct nbp_scheduler_interface_t nbp_scheduler_interface_t;

typedef void (*nbp_scheduler_config_pfn_t)(
    nbp_scheduler_interface_t*
);

typedef void (*nbp_scheduler_callback_init_pfn_t)(
    void
);

typedef void (*nbp_scheduler_callback_uninit_pfn_t)(
    void
);

typedef void (*nbp_scheduler_callback_run_pfn_t)(
    void
);

typedef void (*nbp_scheduler_callback_run_test_pfn_t)(
    nbp_test_details_t* /* current test */
);

typedef void (*nbp_scheduler_callback_run_test_ctx_pfn_t)(
    nbp_test_details_t*, /* current test */
    void* /* context */
);

typedef void (*nbp_scheduler_callback_run_module_pfn_t)(
    nbp_module_details_t* /* current module */
);

typedef void (*nbp_scheduler_callback_run_module_ctx_pfn_t)(
    nbp_module_details_t*, /* current module */
    void* /* context */
);

typedef void (*nbp_scheduler_callback_run_module_completed_pfn_t)(
    nbp_module_details_t* /* current module */
);

struct nbp_scheduler_interface_t {
    const char* schedulerName;
    nbp_scheduler_config_pfn_t configFunc;

    nbp_scheduler_callback_init_pfn_t initCbk;
    nbp_scheduler_callback_uninit_pfn_t uninitCbk;
    nbp_scheduler_callback_run_pfn_t runCbk;
    nbp_scheduler_callback_run_test_pfn_t runTestCbk;
    nbp_scheduler_callback_run_test_ctx_pfn_t runTestCtxCbk;
    nbp_scheduler_callback_run_module_pfn_t runModuleCbk;
    nbp_scheduler_callback_run_module_ctx_pfn_t runModuleCtxCbk;
    nbp_scheduler_callback_run_module_completed_pfn_t runModuleCompletedCbk;
};
typedef struct nbp_scheduler_interface_t nbp_scheduler_interface_t;

/*
 * TODO: add docs
 */
#define NBP_PRINTER_OPERATOR_EQ         (unsigned int) 0x40000001
#define NBP_PRINTER_OPERATOR_NE         (unsigned int) 0x40000002
#define NBP_PRINTER_OPERATOR_LT         (unsigned int) 0x40000003
#define NBP_PRINTER_OPERATOR_LE         (unsigned int) 0x40000004
#define NBP_PRINTER_OPERATOR_GT         (unsigned int) 0x40000005
#define NBP_PRINTER_OPERATOR_GE         (unsigned int) 0x40000006

/*
 * TODO: add docs
 */
#define NBP_PRINTER_TYPE_NONE           (unsigned int) 0x41000000
#define NBP_PRINTER_TYPE_CHAR           (unsigned int) 0x41000001
#define NBP_PRINTER_TYPE_SHORT          (unsigned int) 0x41000002
#define NBP_PRINTER_TYPE_USHORT         (unsigned int) 0x41000003
#define NBP_PRINTER_TYPE_INT            (unsigned int) 0x41000004
#define NBP_PRINTER_TYPE_UINT           (unsigned int) 0x41000005
#define NBP_PRINTER_TYPE_LONG           (unsigned int) 0x41000006
#define NBP_PRINTER_TYPE_ULONG          (unsigned int) 0x41000007
#define NBP_PRINTER_TYPE_LLONG          (unsigned int) 0x41000008
#define NBP_PRINTER_TYPE_ULLONG         (unsigned int) 0x41000009
#define NBP_PRINTER_TYPE_FLOAT          (unsigned int) 0x4100000A
#define NBP_PRINTER_TYPE_DOUBLE         (unsigned int) 0x4100000B
#define NBP_PRINTER_TYPE_LDOUBLE        (unsigned int) 0x4100000C

union nbp_printer_type_value_t
{
    const char* stringValue;
    char charValue;
    short int shortValue;
    unsigned short int ushortValue;
    int intValue;
    unsigned int uintValue;
    long int longValue;
    unsigned long int ulongValue;
    long long int llongValue;
    unsigned long long int ullongValue;
    float floatValue;
    double doubleValue;
    long double* ldoubleValue;
};
typedef union nbp_printer_type_value_t nbp_printer_type_value_t;

struct nbp_printer_interface_t;
typedef struct nbp_printer_interface_t nbp_printer_interface_t;

typedef void (*nbp_printer_config_pfn_t)(
    nbp_printer_interface_t*
);

typedef void (*nbp_printer_callback_init_pfn_t)(
    void
);

typedef void (*nbp_printer_callback_uninit_pfn_t)(
    void
);

typedef void (*nbp_printer_callback_report_error_pfn_t)(
    nbp_error_t /* error context */
);

typedef void (*nbp_printer_callback_exit_triggered_pfn_t)(
    int /* exit status */
);

typedef void (*nbp_printer_callback_handle_version_command_pfn_t)(
    void
);

typedef void (*nbp_printer_callback_test_started_pfn_t)(
    nbp_test_details_t* /* current test */
);

typedef void (*nbp_printer_callback_test_completed_pfn_t)(
    nbp_test_details_t* /* current test */
);

typedef void (*nbp_printer_callback_module_started_pfn_t)(
    nbp_module_details_t* /* current module */
);

typedef void (*nbp_printer_callback_module_completed_pfn_t)(
    nbp_module_details_t* /* current module */
);

typedef void (*nbp_printer_callback_before_run_pfn_t)(
    nbp_module_details_t* /* main module */
);

typedef void (*nbp_printer_callback_after_run_pfn_t)(
    nbp_module_details_t* /* main module */
);

typedef void (*nbp_printer_callback_run_test_pfn_t) (
    nbp_test_details_t* /* current test */
);

typedef void (*nbp_printer_callback_run_module_pfn_t) (
    nbp_module_details_t* /* current module */
);

typedef void (*nbp_printer_callback_run_module_completed_pfn_t) (
    nbp_module_details_t* /* current module */
);

typedef void (*nbp_printer_callback_assert_result_pfn_t)(
    nbp_test_details_t*, /* current test */
    const char*, /* condition */
    unsigned int, /* assert type */
    unsigned int, /* status */
    int, /* line */
    const char*, /* assert failure message */
    const char* /* assert success message */
);

typedef void (*nbp_printer_callback_assert_type_op_result_pfn_t)(
    nbp_test_details_t*, /* current test */
    nbp_printer_type_value_t, /* first value */
    nbp_printer_type_value_t, /* second value */
    unsigned int, /* value type */
    unsigned int, /* operator */
    unsigned int, /* assert type */
    unsigned int, /* status */
    int, /* line */
    const char*, /* assert failure message */
    const char* /* assert success message */
);

struct nbp_printer_interface_t {
    const char* printerName;
    int isInitialized;
    nbp_printer_config_pfn_t configFunc;

    nbp_printer_callback_init_pfn_t initCbk;
    nbp_printer_callback_uninit_pfn_t uninitCbk;

    nbp_printer_callback_report_error_pfn_t reportErrorCbk;
    nbp_printer_callback_exit_triggered_pfn_t exitTriggeredCbk;

    nbp_printer_callback_handle_version_command_pfn_t handleVersionCommandCbk;

    nbp_printer_callback_test_started_pfn_t testStartedCbk;
    nbp_printer_callback_test_completed_pfn_t testCompletedCbk;

    nbp_printer_callback_module_started_pfn_t moduleStartedCbk;
    nbp_printer_callback_module_completed_pfn_t moduleCompletedCbk;

    nbp_printer_callback_before_run_pfn_t beforeRunCbk;
    nbp_printer_callback_after_run_pfn_t afterRunCbk;

    nbp_printer_callback_run_test_pfn_t runTestCbk;

    nbp_printer_callback_run_module_pfn_t runModuleCbk;
    nbp_printer_callback_run_module_completed_pfn_t runModuleCompletedCbk;

    nbp_printer_callback_assert_result_pfn_t assertResultCbk;
    nbp_printer_callback_assert_type_op_result_pfn_t assertTypeOpResultCbk;
};

typedef struct nbp_printer_interface_t nbp_printer_interface_t;


void nbp_test_run(
    nbp_test_details_t*, /* test */
    nbp_module_details_t*, /* module */
    nbp_test_setup_pfn_t, /* test setup pfn */
    nbp_test_teardown_pfn_t /* test teardown pfn */
);

void nbp_test_run_ctx(
    nbp_test_details_t*, /* test */
    void* ctx, /* context */
    nbp_module_details_t*, /* module */
    nbp_test_setup_pfn_t, /* test setup pfn */
    nbp_test_teardown_pfn_t /* test teardown pfn */
);

void nbp_test_increment_asserts_stats(
    nbp_test_details_t*, /* test */
    unsigned int, /* assert status */
    unsigned int /* assert type */
);

unsigned int nbp_test_get_number_of_asserts(
    nbp_test_details_t*, /* test */
    unsigned int, /* assert status */
    unsigned int /* assert type */
);

void nbp_module_run(
    nbp_module_details_t*, /* module */
    nbp_module_details_t*, /* parent */
    nbp_module_setup_pfn_t, /* module setup pfn */
    nbp_module_teardown_pfn_t /* module teardown pfn */
);

void nbp_module_run_ctx(
    nbp_module_details_t*, /* module */
    void* ctx, /* context */
    nbp_module_details_t*, /* parent */
    nbp_module_setup_pfn_t, /* module setup pfn */
    nbp_module_teardown_pfn_t /* module teardown pfn */
);

unsigned int nbp_module_get_number_of_asserts(
    nbp_module_details_t*, /* module */
    unsigned int, /* assert status */
    unsigned int /* assert type */
);

const char* nbp_printer_operator_to_string(
    unsigned int
);

void nbp_printer_notify_init(
    void
);

void nbp_printer_notify_uninit(
    void
);

void nbp_printer_notify_report_error(
    int, /* error code */
    int, /* line */
    const char* /* filename */
);

void nbp_printer_notify_report_error_ctx_string(
    int, /* error code */
    int, /* line */
    const char*, /* filename */
    const char* /* error context */
);

void nbp_printer_notify_report_error_ctx_custom(
    int, /* error code */
    int, /* line */
    const char*, /* filename */
    void* /* error context */
);

void nbp_printer_notify_exit_triggered(
    int /* error code */
);

void nbp_printer_notify_handle_version_command(
    void
);

void nbp_printer_notify_test_started(
    nbp_test_details_t* /* current test */
);

void nbp_printer_notify_test_completed(
    nbp_test_details_t* /* current test */
);

void nbp_printer_notify_module_started(
    nbp_module_details_t* /* current module */
);

void nbp_printer_notify_module_completed(
    nbp_module_details_t* /* current module */
);

void nbp_printer_notify_before_run(
    nbp_module_details_t* /* main module */
);

void nbp_printer_notify_after_run(
    nbp_module_details_t* /* main module */
);

void nbp_printer_notify_run_test(
    nbp_test_details_t* /* current test */
);

void nbp_printer_notify_run_module(
    nbp_module_details_t* /* current module */
);

void nbp_printer_notify_run_module_completed(
    nbp_module_details_t* /* current module */
);

void nbp_printer_notify_assert_result(
    nbp_test_details_t*, /* current test */
    const char*, /* condition */
    unsigned int, /* assert type */
    unsigned int, /* status */
    int, /* line */
    const char*, /* assert failure message */
    const char* /* assert success message */
);

void nbp_printer_notify_assert_type_op_result(
    nbp_test_details_t*, /* current test */
    nbp_printer_type_value_t, /* first value */
    nbp_printer_type_value_t, /* second value */
    unsigned int, /* value type */
    unsigned int, /* operator */
    unsigned int, /* assert type */
    unsigned int, /* status */
    int, /* line */
    const char*, /* assert failure message */
    const char* /* assert success message */
);

void nbp_scheduler_notify_init(
    void
);

void nbp_scheduler_notify_uninit(
    void
);

void nbp_scheduler_notify_run(
    void
);

void nbp_scheduler_notify_run_test(
    nbp_test_details_t* /* test */
);

void nbp_scheduler_notify_run_test_ctx(
    nbp_test_details_t*, /* test */
    void* /* context */
);

void nbp_scheduler_notify_run_module(
    nbp_module_details_t* /* module */
);

void nbp_scheduler_notify_run_module_ctx(
    nbp_module_details_t*, /* module */
    void* /* context */
);

void nbp_scheduler_notify_run_module_completed(
    nbp_module_details_t* /* module */
);

void nbp_scheduler_run_test(
    nbp_test_details_t* /* test */
);

void nbp_scheduler_complete_empty_module(
    nbp_module_details_t* /* module */
);


#ifdef NBP_LIBRARY_MAIN

extern nbp_module_details_t* nbpMainModule;
extern nbp_scheduler_interface_t* nbpSchedulerInterface;

int nbpSchedulerRunEnabled;

int nbp_string_equal(const char* a, const char* b)
{
    while (*a == *b && *a != '\0') {
        a++;
        b++;
    }

    return *a != *b ? 0 : 1;
}

int nbp_command_run_all()
{
    nbpSchedulerRunEnabled = 0;

    nbp_printer_notify_init();
    nbp_scheduler_notify_init();

    if (nbpSchedulerInterface->runCbk == NBP_MEMORY_NULL_POINTER) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_INVALID_SCHEDULER);
        NBP_EXIT(NBP_ERROR_CODE_INVALID_SCHEDULER);
    }

    nbp_module_run(
        nbpMainModule,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER
    );

    nbp_printer_notify_before_run(nbpMainModule);

    nbpSchedulerRunEnabled = 1;
    nbp_scheduler_notify_run();
    nbpSchedulerRunEnabled = 0;

    extern NBP_SYNC_ATOMIC_UINT_TYPE nbpNumberOfRunTests;
    extern unsigned int nbpTotalNumberOfTests;

    if (NBP_SYNC_ATOMIC_UINT_LOAD(&nbpNumberOfRunTests) != nbpTotalNumberOfTests) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_NOT_ALL_TESTS_RUN);
        NBP_EXIT(NBP_ERROR_CODE_NOT_ALL_TESTS_RUN);
    }

    if (nbpMainModule->isEmptyModule == 1) {
        nbp_scheduler_complete_empty_module(nbpMainModule);
    }

    nbp_printer_notify_after_run(nbpMainModule);

    nbp_scheduler_notify_uninit();
    nbp_printer_notify_uninit();

    if (NBP_MODULE_GET_STATE(nbpMainModule) == NBP_MODULE_STATE_PASSED) {
        return NBP_ERROR_CODE_SUCCESS;
    }

    return NBP_ERROR_CODE_TESTS_FAILED;
}

int nbp_command_version()
{
    nbp_printer_notify_init();
    nbp_printer_notify_handle_version_command();
    nbp_printer_notify_uninit();

    return NBP_ERROR_CODE_SUCCESS;
}

int main(int argc, const char** argv)
{
    if (argc < 1) {
        return NBP_ERROR_CODE_INVALID_CMDLINE;
    }

    if (argc == 1) {
        return nbp_command_run_all();
    }

    if (nbp_string_equal(argv[1], "--version") == 1) {
        return nbp_command_version();
    }

    return NBP_ERROR_CODE_INVALID_CMDLINE;
}

unsigned int nbpTotalNumberOfTests = 0;

static void nbp_test_init(nbp_test_details_t* test,
    nbp_module_details_t* module, nbp_test_setup_pfn_t testSetup,
    nbp_test_teardown_pfn_t testTeardown)
{
    unsigned int state = NBP_SYNC_ATOMIC_UINT_CAS(
        &test->testState,
        NBP_TEST_STATE_NOT_INITIALIZED,
        NBP_TEST_STATE_READY
    );
    if (state != NBP_TEST_STATE_NOT_INITIALIZED) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_TEST_ALREADY_RUN);
        NBP_EXIT(NBP_ERROR_CODE_TEST_ALREADY_RUN);
    }

    test->configFunc(test);

    test->testId = nbpTotalNumberOfTests;
    nbpTotalNumberOfTests++;

    test->module = module;
    test->module->isEmptyModule = 0;
    test->module->tests.num++;
    test->module->taskNum++;

    // set setup function
    if (test->testSetupFunc == NBP_MEMORY_NULL_POINTER &&
        testSetup != NBP_MEMORY_NULL_POINTER) {
        test->testSetupFunc = testSetup;
    }

    // set teardown function
    if (test->testTeardownFunc == NBP_MEMORY_NULL_POINTER &&
        testTeardown != NBP_MEMORY_NULL_POINTER) {
        test->testTeardownFunc = testTeardown;
    }

    if (module->firstTest == NBP_MEMORY_NULL_POINTER) {
        module->firstTest = test;
        module->lastTest = test;
    } else {
        test->prev = module->lastTest;
        module->lastTest->next = test;
        module->lastTest = test;
    }
}

void nbp_test_run(nbp_test_details_t* test, nbp_module_details_t* module,
    nbp_test_setup_pfn_t testSetup, nbp_test_teardown_pfn_t testTeardown)
{
    nbp_test_init(test, module, testSetup, testTeardown);

    nbp_printer_notify_run_test(test);
    nbp_scheduler_notify_run_test(test);
}

void nbp_test_run_ctx(nbp_test_details_t* test, void* ctx,
    nbp_module_details_t* module, nbp_test_setup_pfn_t testSetup,
    nbp_test_teardown_pfn_t testTeardown)
{
    nbp_test_init(test, module, testSetup, testTeardown);

    nbp_printer_notify_run_test(test);
    nbp_scheduler_notify_run_test_ctx(test, ctx);
}

void nbp_test_increment_asserts_stats(nbp_test_details_t* test,
    unsigned int assertStatus, unsigned int assertType)
{
    switch (assertType)
    {
        case NBP_ASSERT_NON_FATAL:
            if (assertStatus == NBP_ASSERT_STATUS_PASSED) {
                test->asserts.nonFatal.numPassed++;
            } else if (assertStatus == NBP_ASSERT_STATUS_FAILED) {
                test->asserts.nonFatal.numFailed++;
            }
            break;

        case NBP_ASSERT_FATAL:
            if (assertStatus == NBP_ASSERT_STATUS_PASSED) {
                test->asserts.fatal.numPassed++;
            } else if (assertStatus == NBP_ASSERT_STATUS_FAILED) {
                test->asserts.fatal.numFailed++;
            }
            break;

        case NBP_ASSERT_FATAL_FOR_TEST:
            if (assertStatus == NBP_ASSERT_STATUS_PASSED) {
                test->asserts.fatalForTest.numPassed++;
            } else if (assertStatus == NBP_ASSERT_STATUS_FAILED) {
                test->asserts.fatalForTest.numFailed++;
            }
            break;

        case NBP_ASSERT_FATAL_FOR_MODULE:
            if (assertStatus == NBP_ASSERT_STATUS_PASSED) {
                test->asserts.fatalForModule.numPassed++;
            } else if (assertStatus == NBP_ASSERT_STATUS_FAILED) {
                test->asserts.fatalForModule.numFailed++;
            }
            break;

        default:
            return;
    }
}

unsigned int nbp_test_get_number_of_asserts(nbp_test_details_t* test,
    unsigned int assertStatus, unsigned int assertType)
{
    switch (assertType)
    {
        case NBP_ASSERT_NON_FATAL:
            if (assertStatus == NBP_ASSERT_STATUS_PASSED) {
                return test->asserts.nonFatal.numPassed;
            } else if (assertStatus == NBP_ASSERT_STATUS_FAILED) {
                return test->asserts.nonFatal.numFailed;
            }
            break;

        case NBP_ASSERT_FATAL:
            if (assertStatus == NBP_ASSERT_STATUS_PASSED) {
                return test->asserts.fatal.numPassed;
            } else if (assertStatus == NBP_ASSERT_STATUS_FAILED) {
                return test->asserts.fatal.numFailed;
            }
            break;

        case NBP_ASSERT_FATAL_FOR_TEST:
            if (assertStatus == NBP_ASSERT_STATUS_PASSED) {
                return test->asserts.fatalForTest.numPassed;
            } else if (assertStatus == NBP_ASSERT_STATUS_FAILED) {
                return test->asserts.fatalForTest.numFailed;
            }
            break;

        case NBP_ASSERT_FATAL_FOR_MODULE:
            if (assertStatus == NBP_ASSERT_STATUS_PASSED) {
                return test->asserts.fatalForModule.numPassed;
            } else if (assertStatus == NBP_ASSERT_STATUS_FAILED) {
                return test->asserts.fatalForModule.numFailed;
            }
            break;
    }

    return 0;
}

unsigned int nbpTotalNumberOfModules = 0;

static void nbp_module_init(nbp_module_details_t* module,
    nbp_module_details_t* parent, nbp_module_setup_pfn_t setupFunc,
    nbp_module_teardown_pfn_t teardownFunc)
{
    unsigned int state = NBP_SYNC_ATOMIC_UINT_CAS(
        &module->moduleState,
        NBP_MODULE_STATE_NOT_INITIALIZED,
        NBP_MODULE_STATE_READY
    );
    if (state != NBP_MODULE_STATE_NOT_INITIALIZED) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_MODULE_ALREADY_RUN);
        NBP_EXIT(NBP_ERROR_CODE_MODULE_ALREADY_RUN);
    }

    module->configFunc(module);

    int errCode = NBP_SYNC_EVENT_INIT(module->runEvent);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_SYNC_EVENT_INIT.
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(errCode);
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }

    errCode = NBP_SYNC_EVENT_INIT(module->setupEvent);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_SYNC_EVENT_INIT.
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(errCode);
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }

    if (module->setupFunc == NBP_MEMORY_NULL_POINTER &&
        setupFunc != NBP_MEMORY_NULL_POINTER) {
        module->setupFunc = setupFunc;
    }

    if (module->teardownFunc == NBP_MEMORY_NULL_POINTER &&
        teardownFunc != NBP_MEMORY_NULL_POINTER) {
        module->teardownFunc = teardownFunc;
    }

    module->moduleId = nbpTotalNumberOfModules;
    nbpTotalNumberOfModules++;

    module->parent = parent;

    if (parent != NBP_MEMORY_NULL_POINTER) {
        parent->modules.num++;
        parent->taskNum++;
        if (parent->firstModule == NBP_MEMORY_NULL_POINTER) {
            parent->firstModule = module;
            parent->lastModule = module;
        } else {
            module->prev = parent->lastModule;
            parent->lastModule->next = module;
            parent->lastModule = module;
        }

        module->depth = parent->depth + 1;
    }
}

static void nbp_module_update_stats(nbp_module_details_t* module)
{
    nbp_module_details_t* idx = module->firstModule;
    while (idx != NBP_MEMORY_NULL_POINTER) {
        module->modules.num += idx->modules.num;
        module->tests.num   += idx->tests.num;

        if (idx->isEmptyModule == 0) {
            module->isEmptyModule = 0;
        } else {
            module->emptySubmodulesNum++;
        }

        idx = idx->next;
    }
}

void nbp_module_run(nbp_module_details_t* module, nbp_module_details_t* parent,
    nbp_module_setup_pfn_t setupFunc, nbp_module_teardown_pfn_t teardownFunc)
{
    nbp_module_init(module, parent, setupFunc, teardownFunc);

    nbp_printer_notify_run_module(module);

    nbp_scheduler_notify_run_module(module);

    module->moduleFunc(
        module,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER
    );

    nbp_scheduler_notify_run_module_completed(module);

    nbp_module_update_stats(module);

    nbp_printer_notify_run_module_completed(module);
}

void nbp_module_run_ctx(nbp_module_details_t* module, void* ctx,
    nbp_module_details_t* parent, nbp_module_setup_pfn_t setupFunc,
    nbp_module_teardown_pfn_t teardownFunc)
{
    nbp_module_init(module, parent, setupFunc, teardownFunc);

    nbp_printer_notify_run_module(module);

    nbp_scheduler_notify_run_module_ctx(module, ctx);

    module->moduleFunc(
        module,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER
    );

    nbp_scheduler_notify_run_module_completed(module);

    nbp_module_update_stats(module);

    nbp_printer_notify_run_module_completed(module);
}

unsigned int nbp_module_get_number_of_asserts(nbp_module_details_t* module,
    unsigned int assertStatus, unsigned int assertType)
{
    switch (assertType)
    {
        case NBP_ASSERT_NON_FATAL:
            if (assertStatus == NBP_ASSERT_STATUS_PASSED) {
                return module->asserts.nonFatal.numPassed;
            } else if (assertStatus == NBP_ASSERT_STATUS_FAILED) {
                return module->asserts.nonFatal.numFailed;
            }
            break;

        case NBP_ASSERT_FATAL:
            if (assertStatus == NBP_ASSERT_STATUS_PASSED) {
                return module->asserts.fatal.numPassed;
            } else if (assertStatus == NBP_ASSERT_STATUS_FAILED) {
                return module->asserts.fatal.numFailed;
            }
            break;

        case NBP_ASSERT_FATAL_FOR_TEST:
            if (assertStatus == NBP_ASSERT_STATUS_PASSED) {
                return module->asserts.fatalForTest.numPassed;
            } else if (assertStatus == NBP_ASSERT_STATUS_FAILED) {
                return module->asserts.fatalForTest.numFailed;
            }
            break;

        case NBP_ASSERT_FATAL_FOR_MODULE:
            if (assertStatus == NBP_ASSERT_STATUS_PASSED) {
                return module->asserts.fatalForModule.numPassed;
            } else if (assertStatus == NBP_ASSERT_STATUS_FAILED) {
                return module->asserts.fatalForModule.numFailed;
            }
            break;
    }

    return 0;
}

extern nbp_printer_interface_t* nbpPrinterInterfaces[];
extern unsigned int nbpPrinterInterfacesSize;

const char* nbp_printer_operator_to_string(unsigned int op)
{
    switch (op) {
        case NBP_PRINTER_OPERATOR_EQ:
            return "==";
        case NBP_PRINTER_OPERATOR_NE:
            return "!=";
        case NBP_PRINTER_OPERATOR_GT:
            return ">";
        case NBP_PRINTER_OPERATOR_GE:
            return ">=";
        case NBP_PRINTER_OPERATOR_LT:
            return "<";
        case NBP_PRINTER_OPERATOR_LE:
            return "<=";
    }

    // these lines are excluded from coverage because it is almost impossible to
    // use other operator.
    // LCOV_EXCL_START
    NBP_ERROR_REPORT(NBP_ERROR_CODE_UNKNOWN_OPERATOR);
    return "unknown";
    // LCOV_EXCL_STOP
}

void nbp_printer_notify_init(void)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        nbpPrinterInterfaces[i]->configFunc(nbpPrinterInterfaces[i]);
        if (nbpPrinterInterfaces[i]->initCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->initCbk();
        }
        nbpPrinterInterfaces[i]->isInitialized = 1;
    }
}

void nbp_printer_notify_uninit(void)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->uninitCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->uninitCbk();
        }
        nbpPrinterInterfaces[i]->isInitialized = 0;
    }
}

void nbp_printer_notify_report_error(int errCode, int line,
    const char* filename)
{
    nbp_error_t err;

    err.errorCode       = errCode;
    err.line            = line;
    err.filename        = filename;
    err.contextType     = NBP_ERROR_CONTEXT_EMPTY;
    err.contextString   = NBP_MEMORY_NULL_POINTER;

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->isInitialized == 0) {
            continue;
        }

        if (nbpPrinterInterfaces[i]->reportErrorCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->reportErrorCbk(err);
        }
    }
}

void nbp_printer_notify_report_error_ctx_string(int errCode, int line,
    const char* filename, const char* ctx)
{
    nbp_error_t err;

    err.errorCode       = errCode;
    err.line            = line;
    err.filename        = filename;
    err.contextType     = NBP_ERROR_CONTEXT_STRING;
    err.contextString   = ctx;

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->isInitialized == 0) {
            continue;
        }

        if (nbpPrinterInterfaces[i]->reportErrorCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->reportErrorCbk(err);
        }
    }
}

void nbp_printer_notify_report_error_ctx_custom(int errCode, int line,
    const char* filename, void* ctx)
{
    nbp_error_t err;

    err.errorCode       = errCode;
    err.line            = line;
    err.filename        = filename;
    err.contextType     = NBP_ERROR_CONTEXT_CUSTOM;
    err.contextCustom   = ctx;

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->isInitialized == 0) {
            continue;
        }

        if (nbpPrinterInterfaces[i]->reportErrorCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->reportErrorCbk(err);
        }
    }
}

void nbp_printer_notify_exit_triggered(int errorCode)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->isInitialized == 0) {
            continue;
        }

        if (nbpPrinterInterfaces[i]->exitTriggeredCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->exitTriggeredCbk(errorCode);
        }
    }
}

void nbp_printer_notify_handle_version_command(void)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->handleVersionCommandCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->handleVersionCommandCbk();
        }
    }
}

void nbp_printer_notify_test_started(nbp_test_details_t* test)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testStartedCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testStartedCbk(test);
        }
    }
}

void nbp_printer_notify_test_completed(nbp_test_details_t* test)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testCompletedCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testCompletedCbk(test);
        }
    }
}

void nbp_printer_notify_module_started(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleStartedCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleStartedCbk(module);
        }
    }
}

void nbp_printer_notify_module_completed(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleCompletedCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleCompletedCbk(module);
        }
    }
}

void nbp_printer_notify_before_run(nbp_module_details_t* mainModule)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->beforeRunCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->beforeRunCbk(mainModule);
        }
    }
}

void nbp_printer_notify_after_run(nbp_module_details_t* mainModule)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->afterRunCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->afterRunCbk(mainModule);
        }
    }
}

void nbp_printer_notify_run_test(nbp_test_details_t* test)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->runTestCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->runTestCbk(test);
        }
    }
}

void nbp_printer_notify_run_module(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->runModuleCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->runModuleCbk(module);
        }
    }
}

void nbp_printer_notify_run_module_completed(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->runModuleCompletedCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->runModuleCompletedCbk(module);
        }
    }
}

void nbp_printer_notify_assert_result(nbp_test_details_t* test,
    const char* cond, unsigned int assertType, unsigned int status, int line,
    const char* assertFailureMsg, const char* assertSuccessMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertResultCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertResultCbk(
                test,
                cond,
                assertType,
                status,
                line,
                assertFailureMsg,
                assertSuccessMsg
            );
        }
    }
}

void nbp_printer_notify_assert_type_op_result(nbp_test_details_t* test,
    nbp_printer_type_value_t a, nbp_printer_type_value_t b,
    unsigned int valueType, unsigned int op, unsigned int assertType,
    unsigned int status, int line, const char* assertFailureMsg,
    const char* assertSuccessMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertTypeOpResultCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertTypeOpResultCbk(
                test,
                a,
                b,
                valueType,
                op,
                assertType,
                status,
                line,
                assertFailureMsg,
                assertSuccessMsg
            );
        }
    }
}

NBP_SYNC_ATOMIC_UINT_TYPE nbpNumberOfRunTests = NBP_SYNC_ATOMIC_UINT_INIT(0);

static void nbp_scheduler_update_module_stats(nbp_test_details_t* test)
{
    nbp_module_details_t* m = test->module;

    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(
        &m->asserts.nonFatal.numPassed,
        test->asserts.nonFatal.numPassed
    );
    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(
        &m->asserts.nonFatal.numFailed,
        test->asserts.nonFatal.numFailed
    );

    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(
        &m->asserts.fatalForTest.numPassed,
        test->asserts.fatalForTest.numPassed
    );
    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(
        &m->asserts.fatalForTest.numFailed,
        test->asserts.fatalForTest.numFailed
    );

    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(
        &m->asserts.fatalForModule.numPassed,
        test->asserts.fatalForModule.numPassed
    );
    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(
        &m->asserts.fatalForModule.numFailed,
        test->asserts.fatalForModule.numFailed
    );

    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(
        &m->asserts.fatal.numPassed,
        test->asserts.fatal.numPassed
    );
    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(
        &m->asserts.fatal.numFailed,
        test->asserts.fatal.numFailed
    );
}

static void nbp_scheduler_update_parent_stats(nbp_module_details_t* module)
{
    nbp_module_details_t* m = module;
    nbp_module_details_t* p = module->parent;

    if (p == NBP_MEMORY_NULL_POINTER) {
        return;
    }

#define NBP_PRIVATE_TMP_ADD(a, b)                                              \
    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(&a, NBP_SYNC_ATOMIC_UINT_LOAD(&b))

    // modules stats
    NBP_PRIVATE_TMP_ADD(p->modules.numPassed, m->modules.numPassed);
    NBP_PRIVATE_TMP_ADD(p->modules.numFailed, m->modules.numFailed);
    NBP_PRIVATE_TMP_ADD(p->modules.numSkipped, m->modules.numSkipped);

    // tests stats
    NBP_PRIVATE_TMP_ADD(p->tests.numPassed, m->tests.numPassed);
    NBP_PRIVATE_TMP_ADD(p->tests.numFailed, m->tests.numFailed);
    NBP_PRIVATE_TMP_ADD(p->tests.numSkipped, m->tests.numSkipped);

    // non fatal asserts stats
    NBP_PRIVATE_TMP_ADD(
        p->asserts.nonFatal.numPassed,
        m->asserts.nonFatal.numPassed
    );
    NBP_PRIVATE_TMP_ADD(
        p->asserts.nonFatal.numFailed,
        m->asserts.nonFatal.numFailed
    );

    // fatal for test asserts stats
    NBP_PRIVATE_TMP_ADD(
        p->asserts.fatalForTest.numPassed,
        m->asserts.fatalForTest.numPassed
    );
    NBP_PRIVATE_TMP_ADD(
        p->asserts.fatalForTest.numFailed,
        m->asserts.fatalForTest.numFailed
    );

    // fatal for module asserts stats
    NBP_PRIVATE_TMP_ADD(
        p->asserts.fatalForModule.numPassed,
        m->asserts.fatalForModule.numPassed
    );
    NBP_PRIVATE_TMP_ADD(
        p->asserts.fatalForModule.numFailed,
        m->asserts.fatalForModule.numFailed
    );

    // fatal asserts stats
    NBP_PRIVATE_TMP_ADD(p->asserts.fatal.numPassed, m->asserts.fatal.numPassed);
    NBP_PRIVATE_TMP_ADD(p->asserts.fatal.numFailed, m->asserts.fatal.numFailed);

#undef NBP_PRIVATE_TMP_ADD
}

static void nbp_scheduler_update_module_state(nbp_module_details_t* module)
{
    unsigned int numPassedTests = NBP_SYNC_ATOMIC_UINT_LOAD(
        &module->tests.numPassed
    );
    unsigned int numSkippedTests = NBP_SYNC_ATOMIC_UINT_LOAD(
        &module->tests.numSkipped
    );
    unsigned int numPassedModules = NBP_SYNC_ATOMIC_UINT_LOAD(
        &module->modules.numPassed
    );
    unsigned int numSkippedModules = NBP_SYNC_ATOMIC_UINT_LOAD(
        &module->modules.numSkipped
    );
    unsigned int oldVal;
    unsigned int state;

    if (module->tests.num == numPassedTests &&
        module->modules.num == numPassedModules) {
        state = NBP_MODULE_STATE_PASSED;
        goto end;
    }

    if (module->tests.num == numSkippedTests &&
        module->modules.num == numSkippedModules) {
        state = NBP_MODULE_STATE_SKIPPED;
        goto end;
    }

    state = NBP_MODULE_STATE_FAILED;
    goto end;

end:
    oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
        &module->moduleState,
        NBP_MODULE_STATE_RUNNING,
        state
    );
    if (oldVal != NBP_MODULE_STATE_RUNNING) {
        // these lines are excluded from coverage because it is impossible to
        // have other state if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE,
            "module is not running"
        );
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE);
        // LCOV_EXCL_STOP
    }

    if (module->parent == NBP_MEMORY_NULL_POINTER) {
        return;
    }

    NBP_SYNC_ATOMIC_UINT_TYPE* parentNum;
    switch (state) {
        case NBP_MODULE_STATE_PASSED:
            parentNum = &module->parent->modules.numPassed;
            break;
        case NBP_MODULE_STATE_FAILED:
            parentNum = &module->parent->modules.numFailed;
            break;
        case NBP_MODULE_STATE_SKIPPED:
            parentNum = &module->parent->modules.numSkipped;
            break;
        default:
            // these lines are excluded from coverage because it is impossible
            // to have other state if there is no sync issue
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE,
                "unknown module state"
            );
            NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE);
            // LCOV_EXCL_STOP
    }

    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(parentNum, 1);
}

static void nbp_scheduler_update_test_state(nbp_test_details_t* test)
{
    do {
        if (test->asserts.nonFatal.numFailed != 0) {
            break;
        }

        if (test->asserts.fatalForTest.numFailed != 0) {
            break;
        }

        if (test->asserts.fatalForModule.numFailed != 0) {
            break;
        }

        if (test->asserts.fatal.numFailed != 0) {
            break;
        }

        unsigned int oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
            &test->testState,
            NBP_TEST_STATE_RUNNING,
            NBP_TEST_STATE_PASSED
        );
        if (oldVal != NBP_TEST_STATE_RUNNING) {
            // these lines are excluded from coverage because it is impossible
            // to have other state if there is no sync issue
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_UNEXPECTED_TEST_STATE,
                "test is not running"
            );
            NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_TEST_STATE);
            // LCOV_EXCL_STOP
        }

        NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(&test->module->tests.numPassed, 1);
        return;
    } while (0);

    unsigned int oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
        &test->testState,
        NBP_TEST_STATE_RUNNING,
        NBP_TEST_STATE_FAILED
    );
    if (oldVal != NBP_TEST_STATE_RUNNING) {
        // these lines are excluded from coverage because it is impossible to
        // have other state if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_UNEXPECTED_TEST_STATE,
            "test is not running"
        );
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_TEST_STATE);
        // LCOV_EXCL_STOP
    }

    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(&test->module->tests.numFailed, 1);
}

static unsigned int nbp_scheduler_setup_module(nbp_module_details_t* module)
{
    if (module == NBP_MEMORY_NULL_POINTER) {
        return NBP_MODULE_PRIVATE_SKIP_PROCESSED;
    }

    unsigned int oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
        &module->isSkipped,
        NBP_MODULE_PRIVATE_SKIP_NOT_SET,
        NBP_MODULE_PRIVATE_SKIP_PROCESSED
    );

    if (oldVal == NBP_MODULE_PRIVATE_SKIP_SET) {
        return NBP_MODULE_PRIVATE_SKIP_SET;
    }

    if (oldVal == NBP_MODULE_PRIVATE_SKIP_PROCESSED) {
        NBP_ERROR_CODE_TYPE errCode = NBP_SYNC_EVENT_WAIT(module->setupEvent);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_SYNC_EVENT_WAIT
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        oldVal = NBP_SYNC_ATOMIC_UINT_LOAD(&module->isSkipped);
        if (oldVal == NBP_MODULE_PRIVATE_SKIP_PROCESSED ||
            oldVal == NBP_MODULE_PRIVATE_SKIP_SET) {
            return oldVal;
        }

        // these lines are excluded from coverage because it is impossible to
        // have other value if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
        // LCOV_EXCL_STOP
    }

    if (oldVal == NBP_MODULE_PRIVATE_SKIP_NOT_SET) {
        unsigned int parentFlags = nbp_scheduler_setup_module(module->parent);
        if (parentFlags == NBP_MODULE_PRIVATE_SKIP_PROCESSED) {
            if (module->setupFunc != NBP_MEMORY_NULL_POINTER) {
                module->setupFunc(module);
            }

            NBP_ERROR_CODE_TYPE errCode = NBP_SYNC_EVENT_NOTIFY(module->setupEvent);
            if (errCode != NBP_ERROR_CODE_SUCCESS) {
                // these lines are excluded from coverage because it is pretty
                // hard to trigger an error for NBP_SYNC_EVENT_WAIT
                // LCOV_EXCL_START
                NBP_ERROR_REPORT(errCode);
                NBP_EXIT(errCode);
                // LCOV_EXCL_STOP
            }

            return NBP_MODULE_PRIVATE_SKIP_PROCESSED;
        }

        if (parentFlags == NBP_MODULE_PRIVATE_SKIP_SET) {
            oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
                &module->isSkipped,
                NBP_MODULE_PRIVATE_SKIP_PROCESSED,
                NBP_MODULE_PRIVATE_SKIP_SET
            );
            if (oldVal != NBP_MODULE_PRIVATE_SKIP_PROCESSED) {
                // these lines are excluded from coverage because it is
                // impossible to have other value if there is no sync issue
                // LCOV_EXCL_START
                NBP_ERROR_REPORT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
                NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
                // LCOV_EXCL_STOP
            }
            return NBP_MODULE_PRIVATE_SKIP_SET;
        }

        // these lines are excluded from coverage because it is impossible to
        // have other value if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
        // LCOV_EXCL_STOP
    }

    // these lines are excluded from coverage because it is impossible to have
    // other value if there is no sync issue
    // LCOV_EXCL_START
    NBP_ERROR_REPORT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
    NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
    // LCOV_EXCL_STOP
}

static void nbp_scheduler_verify_module_stats(nbp_module_details_t* module)
{
    unsigned int passed, failed, skipped;

    passed  = NBP_SYNC_ATOMIC_UINT_LOAD(&module->tests.numPassed);
    failed  = NBP_SYNC_ATOMIC_UINT_LOAD(&module->tests.numFailed);
    skipped = NBP_SYNC_ATOMIC_UINT_LOAD(&module->tests.numSkipped);
    if (module->tests.num != passed + failed + skipped) {
        // this line is excluded from coverage because it is impossible to have
        // other value if there is no sync issue
        // LCOV_EXCL_START
        goto error;
        // LCOV_EXCL_STOP
    }

    passed  = NBP_SYNC_ATOMIC_UINT_LOAD(&module->modules.numPassed);
    failed  = NBP_SYNC_ATOMIC_UINT_LOAD(&module->modules.numFailed);
    skipped = NBP_SYNC_ATOMIC_UINT_LOAD(&module->modules.numSkipped);
    if (module->modules.num != passed + failed + skipped) {
        // this line is excluded from coverage because it is impossible to have
        // other value if there is no sync issue
        // LCOV_EXCL_START
        goto error;
        // LCOV_EXCL_STOP
    }

    return;

    // these lines are excluded from coverage because it is impossible to have
    // other value if there is no sync issue
    // LCOV_EXCL_START
error:
    NBP_ERROR_REPORT_CTX_STRING(
        NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA,
        "the sum of numPassed, numFailed and numSkipped is not equal to num"
    );
    NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
    // LCOV_EXCL_STOP
}

static void nbp_scheduler_teardown_module(nbp_module_details_t* module)
{
    unsigned int num = 0;
    unsigned int isSkipped = 0;
    unsigned int numOfCompletedEmptySubmodules = 0;
    unsigned int moduleState = 0;
    NBP_ERROR_CODE_TYPE errCode;
    nbp_module_details_t* moduleIdx;

    while (1) {
        numOfCompletedEmptySubmodules = 0;
        num = NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(&module->completedTaskNum, 1);

        if (module->emptySubmodulesNum != 0 &&
            module->taskNum == num + module->emptySubmodulesNum) {
            num += module->emptySubmodulesNum;

            moduleIdx = module->firstModule;
            while (moduleIdx != NBP_MEMORY_NULL_POINTER) {
                moduleState = NBP_SYNC_ATOMIC_UINT_LOAD(&moduleIdx->moduleState);
                if (moduleState == NBP_MODULE_STATE_READY) {
                    nbp_scheduler_complete_empty_module(moduleIdx);
                    numOfCompletedEmptySubmodules++;
                }

                moduleIdx = moduleIdx->next;
            }

            if (module->emptySubmodulesNum != numOfCompletedEmptySubmodules) {
                // these lines are excluded from coverage because it is
                // impossible to have other value if there is no sync issue
                // LCOV_EXCL_START
                NBP_ERROR_REPORT_CTX_STRING(
                    NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA,
                    "unexpected number of completed empty submodules"
                );
                NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
                // LCOV_EXCL_STOP
            }
        }

        if (module->taskNum > num) {
            break;
        }

        if (module->taskNum < num) {
            // these lines are excluded from coverage because it is impossible
            // to have more completed task than the number of task if there is
            // no sync issue
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA,
                "there are too many completed tasks"
            );
            NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
            // LCOV_EXCL_STOP
        }

        nbp_scheduler_verify_module_stats(module);

        isSkipped = NBP_SYNC_ATOMIC_UINT_LOAD(&module->isSkipped);
        if (isSkipped == NBP_MODULE_PRIVATE_SKIP_PROCESSED) {
            if (module->teardownFunc != NBP_MEMORY_NULL_POINTER) {
                module->teardownFunc(module);
            }
        }

        nbp_scheduler_update_module_state(module);
        nbp_scheduler_update_parent_stats(module);

        nbp_printer_notify_module_completed(module);

        errCode = NBP_SYNC_EVENT_UNINIT(module->runEvent);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_SYNC_EVENT_UNINIT
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        errCode = NBP_SYNC_EVENT_UNINIT(module->setupEvent);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_SYNC_EVENT_UNINIT
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        module = module->parent;
        if (module == NBP_MEMORY_NULL_POINTER) {
            break;
        }
    }
}

static void nbp_scheduler_skip_module(nbp_module_details_t* module)
{
    nbp_test_details_t* testIdx = module->firstTest;
    while (testIdx != NBP_MEMORY_NULL_POINTER) {
        NBP_SYNC_ATOMIC_UINT_CAS(
            &testIdx->isSkipped,
            NBP_TEST_PRIVATE_SKIP_NOT_SET,
            NBP_TEST_PRIVATE_SKIP_SET
        );
        testIdx = testIdx->next;
    }

    nbp_module_details_t* moduleIdx = module->firstModule;
    unsigned int isSkipped;
    while (moduleIdx != NBP_MEMORY_NULL_POINTER) {
        isSkipped = NBP_SYNC_ATOMIC_UINT_CAS(
            &moduleIdx->isSkipped,
            NBP_MODULE_PRIVATE_SKIP_NOT_SET,
            NBP_MODULE_PRIVATE_SKIP_SET
        );

        if (isSkipped == NBP_MODULE_PRIVATE_SKIP_PROCESSED) {
            nbp_scheduler_skip_module(moduleIdx);
        }

        moduleIdx = moduleIdx->next;
    }
}

static void nbp_scheduler_run_test_running(nbp_test_details_t* test)
{
    nbp_printer_notify_test_started(test);

    if (test->testSetupFunc != NBP_MEMORY_NULL_POINTER) {
        test->testSetupFunc(test);
    }

    test->testFunc(
        test,
        NBP_ASSERT_NON_FATAL,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER
    );

    if (test->asserts.fatal.numFailed != 0) {
        nbp_scheduler_skip_module(nbpMainModule);
    } else if (test->asserts.fatalForModule.numFailed != 0) {
        nbp_scheduler_skip_module(test->module);
    }

    if (test->testTeardownFunc != NBP_MEMORY_NULL_POINTER) {
        test->testTeardownFunc(test);
    }

    nbp_scheduler_update_test_state(test);
    nbp_scheduler_update_module_stats(test);

    nbp_printer_notify_test_completed(test);
}

static void nbp_scheduler_run_test_skipped(nbp_test_details_t* test)
{
    nbp_printer_notify_test_started(test);

    unsigned int oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
        &test->testState,
        NBP_TEST_STATE_RUNNING,
        NBP_TEST_STATE_SKIPPED
    );
    if (oldVal != NBP_TEST_STATE_RUNNING) {
        // these lines are excluded from coverage because it is impossible to
        // have other state if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_UNEXPECTED_TEST_STATE,
            "test is not running"
        );
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_TEST_STATE);
        // LCOV_EXCL_STOP
    }

    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(&test->module->tests.numSkipped, 1);

    nbp_printer_notify_test_completed(test);
}

static unsigned int nbp_scheduler_run_module(nbp_module_details_t* module)
{
    if (module == NBP_MEMORY_NULL_POINTER) {
        return NBP_MODULE_STATE_RUNNING;
    }

    unsigned int oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
        &module->moduleState,
        NBP_MODULE_STATE_READY,
        NBP_MODULE_STATE_RUNNING
    );

    if (oldVal == NBP_MODULE_STATE_RUNNING) {
        NBP_ERROR_CODE_TYPE errCode = NBP_SYNC_EVENT_WAIT(module->runEvent);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_SYNC_EVENT_WAIT
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        return NBP_MODULE_STATE_RUNNING;
    }

    if (oldVal == NBP_MODULE_STATE_READY) {
        unsigned int parentState = nbp_scheduler_run_module(module->parent);
        if (parentState != NBP_MODULE_STATE_RUNNING) {
            // these lines are excluded from coverage because it is impossible
            // to have other state if there is no sync issue
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE,
                "parent module is not running"
            );
            NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE);
            // LCOV_EXCL_STOP
        }

        nbp_printer_notify_module_started(module);

        NBP_ERROR_CODE_TYPE errCode = NBP_SYNC_EVENT_NOTIFY(module->runEvent);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_SYNC_EVENT_NOTIFY
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        return NBP_MODULE_STATE_RUNNING;
    }

    // these lines are excluded from coverage because it is impossible to have
    // other state if there is no sync issue
    // LCOV_EXCL_START
    NBP_ERROR_REPORT_CTX_STRING(
        NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE,
        "module is not ready or running"
    );
    NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE);
    // LCOV_EXCL_STOP
}

void nbp_scheduler_notify_init(void)
{
    nbpSchedulerInterface->configFunc(nbpSchedulerInterface);

    if (nbpSchedulerInterface->initCbk != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->initCbk();
    }
}

void nbp_scheduler_notify_uninit(void)
{
    if (nbpSchedulerInterface->uninitCbk != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->uninitCbk();
    }
}

void nbp_scheduler_notify_run(void)
{
    if (nbpSchedulerInterface->runCbk != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->runCbk();
    }
}

void nbp_scheduler_notify_run_test(nbp_test_details_t* test)
{
    if (nbpSchedulerInterface->runTestCbk != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->runTestCbk(test);
    } else {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_INVALID_SCHEDULER);
        NBP_EXIT(NBP_ERROR_CODE_INVALID_SCHEDULER);
    }
}

void nbp_scheduler_notify_run_test_ctx(nbp_test_details_t* test, void* ctx)
{
    if (nbpSchedulerInterface->runTestCtxCbk != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->runTestCtxCbk(test, ctx);
    } else {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_INVALID_SCHEDULER);
        NBP_EXIT(NBP_ERROR_CODE_INVALID_SCHEDULER);
    }
}

void nbp_scheduler_notify_run_module(nbp_module_details_t* module)
{
    if (nbpSchedulerInterface->runModuleCbk != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->runModuleCbk(module);
    }
}

void nbp_scheduler_notify_run_module_ctx(nbp_module_details_t* module,
    void* ctx)
{
    if (nbpSchedulerInterface->runModuleCtxCbk != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->runModuleCtxCbk(module, ctx);
    }
}

void nbp_scheduler_notify_run_module_completed(nbp_module_details_t* module)
{
    if (nbpSchedulerInterface->runModuleCompletedCbk != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->runModuleCompletedCbk(module);
    }
}

void nbp_scheduler_run_test(nbp_test_details_t* test)
{
    // the test can be run only from NBP_SCHEDULER_FUNC_RUN function
    extern int nbpSchedulerRunEnabled;
    if (nbpSchedulerRunEnabled != 1) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger this error
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(NBP_ERROR_CODE_SCHEDULER_RUN_DISABLED);
        return;
        // LCOV_EXCL_STOP
    }

    unsigned int oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
        &test->testState,
        NBP_TEST_STATE_READY,
        NBP_TEST_STATE_RUNNING
    );

    if (oldVal != NBP_TEST_STATE_READY) {
        // these lines are excluded from coverage because it is impossible to
        // have other state if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_UNEXPECTED_TEST_STATE,
            "test is not ready"
        );
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_TEST_STATE);
        // LCOV_EXCL_STOP
    }

    unsigned int moduleState = nbp_scheduler_run_module(test->module);
    if (moduleState != NBP_MODULE_STATE_RUNNING) {
        // these lines are excluded from coverage because it is impossible to
        // have other state if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE,
            "module is not running"
        );
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE);
        // LCOV_EXCL_STOP
    }

    oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
        &test->isSkipped,
        NBP_TEST_PRIVATE_SKIP_NOT_SET,
        NBP_TEST_PRIVATE_SKIP_PROCESSED
    );

    if (oldVal == NBP_TEST_PRIVATE_SKIP_NOT_SET) {
        unsigned int moduleFlags = nbp_scheduler_setup_module(test->module);
        if (moduleFlags == NBP_MODULE_PRIVATE_SKIP_PROCESSED) {
            nbp_scheduler_run_test_running(test);
        } else if (moduleFlags == NBP_MODULE_PRIVATE_SKIP_SET) {
            nbp_scheduler_run_test_skipped(test);
        } else {
            // these lines are excluded from coverage because it is impossible
            // to have other value if there is no sync issue
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
            NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
            // LCOV_EXCL_STOP
        }
    } else if (oldVal == NBP_TEST_PRIVATE_SKIP_SET) {
        nbp_scheduler_run_test_skipped(test);
    } else {
        // these lines are excluded from coverage because it is impossible to
        // have other value if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
        // LCOV_EXCL_STOP
    }

    nbp_scheduler_teardown_module(test->module);

    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(&nbpNumberOfRunTests, 1);
}

void nbp_scheduler_complete_empty_module(nbp_module_details_t* module)
{
    unsigned int numberOfCompletedTasks;
    unsigned int moduleState;
    nbp_module_details_t* moduleIdx;
    NBP_ERROR_CODE_TYPE errCode;

    // starting module

    moduleState = NBP_SYNC_ATOMIC_UINT_CAS(
        &module->moduleState,
        NBP_MODULE_STATE_READY,
        NBP_MODULE_STATE_RUNNING
    );
    if (moduleState != NBP_MODULE_STATE_READY) {
        // these lines are excluded from coverage because it is impossible to
        // have other state if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE,
            "unexpected module state"
        );
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE);
        // LCOV_EXCL_STOP
    }

    nbp_printer_notify_module_started(module);

    // iterating over all empty submodules

    moduleIdx = module->firstModule;
    while (moduleIdx != NBP_MEMORY_NULL_POINTER) {
        moduleState = NBP_SYNC_ATOMIC_UINT_LOAD(&moduleIdx->moduleState);
        if (moduleState != NBP_MODULE_STATE_READY) {
            // these lines are excluded from coverage because it is impossible
            // to have other state if there is no sync issue
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE,
                "unexpected module state"
            );
            NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE);
            // LCOV_EXCL_STOP
        }

        nbp_scheduler_complete_empty_module(moduleIdx);

        moduleIdx = moduleIdx->next;
    }

    // sanity check

    numberOfCompletedTasks = NBP_SYNC_ATOMIC_UINT_LOAD(&module->completedTaskNum);

    if (module->taskNum != numberOfCompletedTasks) {
        // these lines are excluded from coverage because it is impossible to
        // have other value if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA,
            "number of completed tasks is not equal to number of tasks"
        );
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
        // LCOV_EXCL_STOP
    }

    // update state & stats

    moduleState = NBP_SYNC_ATOMIC_UINT_CAS(
        &module->moduleState,
        NBP_MODULE_STATE_RUNNING,
        NBP_MODULE_STATE_PASSED
    );
    if (moduleState != NBP_MODULE_STATE_RUNNING) {
        // these lines are excluded from coverage because it is impossible to
        // have other state if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE,
            "unexpected module state"
        );
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE);
        // LCOV_EXCL_STOP
    }

    nbp_scheduler_verify_module_stats(module);

    if (module->parent != NBP_MEMORY_NULL_POINTER) {
        NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(&module->parent->completedTaskNum, 1);
        NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(&module->parent->modules.numPassed, 1);
    }

    nbp_scheduler_update_parent_stats(module);

    nbp_printer_notify_module_completed(module);

    // destroy events

    errCode = NBP_SYNC_EVENT_UNINIT(module->runEvent);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_SYNC_EVENT_UNINIT
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(errCode);
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }

    errCode = NBP_SYNC_EVENT_UNINIT(module->setupEvent);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_SYNC_EVENT_UNINIT
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(errCode);
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }
}

#endif // end if NBP_LIBRARY_MAIN

/*
 * if custom scheduler is not used then use a default scheduler
 */
#ifndef NBP_CUSTOM_SCHEDULER

/*
 * TODO: add docs
 */
#ifdef NBP_MT_SCHEDULER
#define NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_UNKNOWN            (unsigned int) 0x60000000
#define NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_BEFORE             (unsigned int) 0x60000001
#define NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_AFTER              (unsigned int) 0x60000002
#define NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD        (unsigned int) 0x60000003

#define NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_UNKNOWN       (unsigned int) 0x61000000
#define NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_EMPTY         (unsigned int) 0x61000001
#define NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_TEST          (unsigned int) 0x61000002
#define NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_MODULE        (unsigned int) 0x61000003

struct nbp_mt_scheduler_rule_t {
    unsigned int ruleType;
    unsigned int dataType;
    union {
        nbp_test_details_t* test;
        nbp_module_details_t* module;
    };
};
typedef struct nbp_mt_scheduler_rule_t nbp_mt_scheduler_rule_t;

struct nbp_mt_scheduler_context_t {
    unsigned long long numberOfRules;
    nbp_mt_scheduler_rule_t rules[1];
};
typedef struct nbp_mt_scheduler_context_t nbp_mt_scheduler_context_t;

nbp_mt_scheduler_rule_t nbp_mt_schduler_create_rule_from_test(
    unsigned int ruleType,
    nbp_test_details_t* test
);

nbp_mt_scheduler_rule_t nbp_mt_schduler_create_rule_from_module(
    unsigned int ruleType,
    nbp_module_details_t* module
);

nbp_mt_scheduler_rule_t nbp_mt_scheduler_create_empty_rule(
    unsigned int ruleType
);

void* nbp_mt_scheduler_create_ctx(
    unsigned long long numberOfRules,
    ...
);

/*
 * TODO: add docs
 */
#define NBP_MT_SCHEDULER_RUN_BEFORE_TEST(test)                                 \
    nbp_mt_schduler_create_rule_from_test(                                     \
        NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_BEFORE,                             \
        NBP_TEST_GET_PTR(test)                                                 \
    )

/*
 * TODO: add docs
 */
#define NBP_MT_SCHEDULER_RUN_AFTER_TEST(test)                                  \
    nbp_mt_schduler_create_rule_from_test(                                     \
        NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_AFTER,                              \
        NBP_TEST_GET_PTR(test)                                                 \
    )

/*
 * TODO: add docs
 */
#define NBP_MT_SCHEDULER_RUN_BEFORE_MODULE(module)                             \
    nbp_mt_schduler_create_rule_from_module(                                   \
        NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_BEFORE,                             \
        NBP_MODULE_GET_PTR(module)                                             \
    )

/*
 * TODO: add docs
 */
#define NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module)                              \
    nbp_mt_schduler_create_rule_from_module(                                   \
        NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_AFTER,                              \
        NBP_MODULE_GET_PTR(module)                                             \
    )

/*
 * TODO: add docs
 */
#define NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(test)                      \
    nbp_mt_schduler_create_rule_from_test(                                     \
        NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD,                        \
        NBP_TEST_GET_PTR(test)                                                 \
    )

/*
 * TODO: add docs
 */
#define NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_MODULE(module)                  \
    nbp_mt_schduler_create_rule_from_module(                                   \
        NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD,                        \
        NBP_MODULE_GET_PTR(module)                                             \
    )

/*
 * TODO: add docs
 */
#define NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD                                    \
    nbp_mt_scheduler_create_empty_rule(                                        \
        NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD                         \
    )

/*
 * TODO: add docs
 */
#define NBP_MT_SCHEDULER_CTX(...)                                              \
    nbp_mt_scheduler_create_ctx(                                               \
        NBP_MT_SCHEDULER_PRIVATE_GET_NUMBER_OF_RULES(__VA_ARGS__),             \
        ## __VA_ARGS__                                                         \
    )

#define NBP_MT_SCHEDULER_PRIVATE_GET_NUMBER_OF_RULES(...)                      \
    sizeof((nbp_mt_scheduler_rule_t[]){ __VA_ARGS__ }) /                       \
    sizeof(nbp_mt_scheduler_rule_t)

/*
 * NBP_SCHEDULER_PREPROCESSING_CONTEXT implementation
 */

#define NBP_PP_EAT_PP_NBP_MT_SCHEDULER_RUN_AFTER_TEST(name)                    \
    NBP_TEST_INCLUDE(name);

#define NBP_PP_EAT_PP_NBP_MT_SCHEDULER_RUN_BEFORE_TEST(name)                   \
    NBP_TEST_INCLUDE(name);

#define NBP_PP_EAT_PP_NBP_MT_SCHEDULER_RUN_AFTER_MODULE(name)                  \
    NBP_MODULE_INCLUDE(name);

#define NBP_PP_EAT_PP_NBP_MT_SCHEDULER_RUN_BEFORE_MODULE(name)                 \
    NBP_MODULE_INCLUDE(name);

#define NBP_PP_EAT_PP_NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_TEST(name)        \
    NBP_TEST_INCLUDE(name);

#define NBP_PP_EAT_PP_NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_AS_MODULE(name)      \
    NBP_MODULE_INCLUDE(name);

#define NBP_PP_EAT_PP_NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD

#define NBP_PP_EAT_PP_NBP_MT_SCHEDULER_CTX(...)                                \
    NBP_PP_CONCAT(                                                             \
        NBP_PP_PROCESSING_PARAM_,                                              \
        NBP_PP_VARCOUNT(PP_ ## __VA_ARGS__)                                    \
    )(PP_ ## __VA_ARGS__)

#define NBP_SCHEDULER_PREPROCESSING_CONTEXT(ctx)                               \
    NBP_PP_EAT_ ## ctx

#ifdef NBP_LIBRARY_MAIN

#include <stdarg.h>

/*
 * nbp_mt_scheduler_get_number_of_threads() implementation
 */
#ifdef NBP_MT_SCHEDULER_NUMBER_OF_THREADS

#if NBP_MT_SCHEDULER_NUMBER_OF_THREADS >= 1

unsigned int nbp_mt_scheduler_get_number_of_threads()
{
    int num = NBP_MT_SCHEDULER_NUMBER_OF_THREADS;
    if (num < 1) {
        // these lines are excluded from coverage because it is impossible to
        // trigger an error
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_GENERIC_ERROR,
            "failed to get the number of threads"
        );
        NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
        return 1;
        // LCOV_EXCL_STOP
    }

    return (unsigned int) num;
}

#else // NBP_MT_SCHEDULER_NUMBER_OF_THREADS is less than 1

#error "Invalid number of threads"

#endif // end if NBP_MT_SCHEDULER_NUMBER_OF_THREADS >= 1

#else // NBP_MT_SCHEDULER_NUMBER_OF_THREADS not defined

#ifdef NBP_OS_LINUX

#include <sys/sysinfo.h>

unsigned int nbp_mt_scheduler_get_number_of_threads()
{
    int num = get_nprocs();
    if (num < 1) {
        // these lines are excluded from coverage because it is impossible to
        // trigger an error for get_nprocs
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_GENERIC_ERROR,
            "failed to get the number of threads"
        );
        NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
        return 1;
        // LCOV_EXCL_STOP
    }

    return (unsigned int) num;
}

#endif // end if NBP_OS_LINUX

#ifdef NBP_OS_WINDOWS
#error "Not supported"
#endif // end if NBP_OS_WINDOWS

#ifdef NBP_OS_MAC
#error "Not supported"
#endif // end if NBP_OS_MAC

#ifdef NBP_OS_CUSTOM
#error "Not supported"
#endif // end if NBP_OS_CUSTOM

#endif // end if NBP_MT_SCHEDULER_NUMBER_OF_THREADS

#ifdef NBP_OS_LINUX

#include <pthread.h>

/*
 * Thread wrapper
 */

#define NBP_MT_SCHEDULER_THREAD_TYPE pthread_t

#define NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE void*

#define NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE_DEFAULT_VALUE NULL

#define NBP_MT_SCHEDULER_THREAD_CREATE(thread, func, param)                    \
    pthread_create(&thread, NULL, func, param) == 0                            \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_GENERIC_ERROR

#define NBP_MT_SCHEDULER_THREAD_JOIN(thread)                                   \
    pthread_join(thread, NULL) == 0                                            \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_GENERIC_ERROR

/*
 * Mutex wrapper
 */

#define NBP_MT_SCHEDULER_MUTEX_TYPE pthread_mutex_t

#define NBP_MT_SCHEDULER_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER

#define NBP_MT_SCHEDULER_MUTEX_INIT(mutex)                                     \
    pthread_mutex_init(&mutex, NULL) == 0                                      \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#define NBP_MT_SCHEDULER_MUTEX_UNINIT(mutex)                                   \
    pthread_mutex_destroy(&mutex) == 0                                         \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#define NBP_MT_SCHEDULER_MUTEX_LOCK(mutex)                                     \
    pthread_mutex_lock(&mutex) == 0                                            \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#define NBP_MT_SCHEDULER_MUTEX_UNLOCK(mutex)                                   \
    pthread_mutex_unlock(&mutex) == 0                                          \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

/*
 * Conditional variable wrapper
 */

#define NBP_MT_SCHEDULER_CONDVAR_TYPE pthread_cond_t

#define NBP_MT_SCHEDULER_CONDVAR_INITIALIZER PTHREAD_COND_INITIALIZER

#define NBP_MT_SCHEDULER_CONDVAR_INIT(condvar)                                 \
    pthread_cond_init(&condvar, NULL) == 0                                     \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#define NBP_MT_SCHEDULER_CONDVAR_UNINIT(condvar)                               \
    pthread_cond_destroy(&condvar) == 0                                        \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#define NBP_MT_SCHEDULER_CONDVAR_WAIT(condvar, mutex)                          \
    pthread_cond_wait(&condvar, &mutex) == 0                                   \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#define NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ONE(condvar)                           \
    pthread_cond_signal(&condvar) == 0                                         \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#define NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ALL(condvar)                           \
    pthread_cond_broadcast(&condvar) == 0                                      \
        ? NBP_ERROR_CODE_SUCCESS                                               \
        : NBP_ERROR_CODE_SYNC_ERROR

#endif // end if NBP_OS_LINUX

#ifdef NBP_OS_WINDOWS
#error "Not supported"
#endif // end if NBP_OS_WINDOWS

#ifdef NBP_OS_MAC
#error "Not supported"
#endif // end if NBP_OS_MAC

#ifdef NBP_OS_CUSTOM
#error "Not supported"
#endif // end if NBP_OS_CUSTOM

/*
 * Check if thread wrapper is defined, otherwise define a dummy thread wrapper.
 * If NBP_OS_* is not defined then the thread wrapper will not be defined so the
 * compiler will generate a lot of errors and the error message that says that
 * there is no NBP_OS_* defined is hard to see.
 */

#ifndef NBP_MT_SCHEDULER_THREAD_TYPE
#define NBP_MT_SCHEDULER_THREAD_TYPE int
#endif // end if NBP_MT_SCHEDULER_THREAD_TYPE

#ifndef NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE
#define NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE void*
#endif // end if NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE

#ifndef NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE_DEFAULT_VALUE
#define NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE_DEFAULT_VALUE ((void*) 0x0)
#endif // end if NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE_DEFAULT_VALUE

#ifndef NBP_MT_SCHEDULER_THREAD_CREATE
#define NBP_MT_SCHEDULER_THREAD_CREATE(thread, func, param)                    \
    NBP_ERROR_CODE_GENERIC_ERROR
#endif // end if NBP_MT_SCHEDULER_THREAD_CREATE

#ifndef NBP_MT_SCHEDULER_THREAD_JOIN
#define NBP_MT_SCHEDULER_THREAD_JOIN(thread) NBP_ERROR_CODE_GENERIC_ERROR
#endif // end if NBP_MT_SCHEDULER_THREAD_JOIN

/*
 * Check if mutex wrapper is defined, otherwise define a dummy mutex wrapper.
 * If NBP_OS_* is not defined then the mutex wrapper will not be defined so the
 * compiler will generate a lot of errors and the error message that says that
 * there is no NBP_OS_* defined is hard to see.
 */

#ifndef NBP_MT_SCHEDULER_MUTEX_TYPE
#define NBP_MT_SCHEDULER_MUTEX_TYPE int
#endif // end if NBP_MT_SCHEDULER_MUTEX_TYPE

#ifndef NBP_MT_SCHEDULER_MUTEX_INITIALIZER
#define NBP_MT_SCHEDULER_MUTEX_INITIALIZER 0
#endif // end if NBP_MT_SCHEDULER_MUTEX_INITIALIZER

#ifndef NBP_MT_SCHEDULER_MUTEX_INIT
#define NBP_MT_SCHEDULER_MUTEX_INIT(mutex) mutex++
#endif // end if NBP_MT_SCHEDULER_MUTEX_INIT

#ifndef NBP_MT_SCHEDULER_MUTEX_UNINIT
#define NBP_MT_SCHEDULER_MUTEX_UNINIT(mutex) mutex++
#endif // end if NBP_MT_SCHEDULER_MUTEX_UNINIT

#ifndef NBP_MT_SCHEDULER_MUTEX_LOCK
#define NBP_MT_SCHEDULER_MUTEX_LOCK(mutex) mutex++
#endif // end if NBP_MT_SCHEDULER_MUTEX_LOCK

#ifndef NBP_MT_SCHEDULER_MUTEX_UNLOCK
#define NBP_MT_SCHEDULER_MUTEX_UNLOCK(mutex) mutex++
#endif // end if NBP_MT_SCHEDULER_MUTEX_UNLOCK

/*
 * Check if conditional variable wrapper is defined, otherwise define a dummy
 * conditional variable wrapper.
 * If NBP_OS_* is not defined then the conditional variable wrapper will not be
 * defined so the compiler will generate a lot of errors and the error message
 * that says that there is no NBP_OS_* defined is hard to see.
 */

#ifndef NBP_MT_SCHEDULER_CONDVAR_TYPE
#define NBP_MT_SCHEDULER_CONDVAR_TYPE int
#endif // end if NBP_MT_SCHEDULER_CONDVAR_TYPE

#ifndef NBP_MT_SCHEDULER_CONDVAR_INITIALIZER
#define NBP_MT_SCHEDULER_CONDVAR_INITIALIZER 0
#endif // end if NBP_MT_SCHEDULER_CONDVAR_INITIALIZER

#ifndef NBP_MT_SCHEDULER_CONDVAR_INIT
#define NBP_MT_SCHEDULER_CONDVAR_INIT(condvar) condvar++
#endif // end if NBP_MT_SCHEDULER_CONDVAR_INIT

#ifndef NBP_MT_SCHEDULER_CONDVAR_UNINIT
#define NBP_MT_SCHEDULER_CONDVAR_UNINIT(condvar) condvar++
#endif // end if NBP_MT_SCHEDULER_CONDVAR_UNINIT

#ifndef NBP_MT_SCHEDULER_CONDVAR_WAIT
#define NBP_MT_SCHEDULER_CONDVAR_WAIT(condvar, mutex) condvar++
#endif // end if NBP_MT_SCHEDULER_CONDVAR_WAIT

#ifndef NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ONE
#define NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ONE(condvar) condvar++
#endif // end if NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ONE

#ifndef NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ALL
#define NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ALL(condvar) condvar++
#endif // end if NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ALL

#define NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_UNKNOWN  (unsigned int) 0x62000000
#define NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_TEST     (unsigned int) 0x62000001
#define NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_MODULE   (unsigned int) 0x62000002

#define NBP_MT_SCHEDULER_PRIVATE_INVALID_WORKER_ID  (unsigned int) 0xFFFFFFFF

struct nbp_mt_scheduler_data_t {
    unsigned int dataType;
    union {
        nbp_test_details_t* test;
        nbp_module_details_t* module;
    };
    nbp_mt_scheduler_context_t* ctx;
    struct nbp_mt_scheduler_data_t* next;
};
typedef struct nbp_mt_scheduler_data_t nbp_mt_scheduler_data_t;

struct nbp_mt_scheduler_test_t {
    nbp_test_details_t* test;
    unsigned int numberOfPendingTests;

    unsigned int* requestedWorkerId;
    struct nbp_mt_scheduler_test_t* nextTestOnThisWorker;

    struct nbp_mt_scheduler_test_t* nextInQueue;
};
typedef struct nbp_mt_scheduler_test_t nbp_mt_scheduler_test_t;

struct nbp_mt_scheduler_thread_t {
    NBP_MT_SCHEDULER_THREAD_TYPE thread;
    unsigned int workerId;
};
typedef struct nbp_mt_scheduler_thread_t nbp_mt_scheduler_thread_t;

static nbp_mt_scheduler_data_t* nbpMtSchedulerData = NBP_MEMORY_NULL_POINTER;
static nbp_mt_scheduler_data_t* nbpMtSchedulerDataLast = NBP_MEMORY_NULL_POINTER;

static nbp_mt_scheduler_test_t* nbpMtSchedulerTests = NBP_MEMORY_NULL_POINTER;
static unsigned int nbpMtSchedulerNumberOfTests = 0;
static unsigned int nbpMtSchedulerNumberOfColumns = 0;
static unsigned int* nbpMtSchedulerAdjacencyMatrix = NBP_MEMORY_NULL_POINTER;

static nbp_mt_scheduler_test_t* nbpMtSchedulerQueue = NBP_MEMORY_NULL_POINTER;
static nbp_mt_scheduler_test_t* nbpMtSchedulerQueueLast = NBP_MEMORY_NULL_POINTER;

static NBP_MT_SCHEDULER_MUTEX_TYPE nbpMtSchedulerMutex = NBP_MT_SCHEDULER_MUTEX_INITIALIZER;
static NBP_MT_SCHEDULER_CONDVAR_TYPE nbpMtSchedulerCondVar = NBP_MT_SCHEDULER_CONDVAR_INITIALIZER;

static unsigned int nbpMtSchedulerNumberOfDispatchedTests = 0;

nbp_mt_scheduler_rule_t nbp_mt_schduler_create_rule_from_test(
    unsigned int ruleType, nbp_test_details_t* test)
{
    nbp_mt_scheduler_rule_t rule;

    rule.ruleType   = ruleType;
    rule.dataType   = NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_TEST;
    rule.test       = test;

    return rule;
}

nbp_mt_scheduler_rule_t nbp_mt_schduler_create_rule_from_module(
    unsigned int ruleType, nbp_module_details_t* module)
{
    nbp_mt_scheduler_rule_t rule;

    rule.ruleType   = ruleType;
    rule.dataType   = NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_MODULE;
    rule.module     = module;

    return rule;
}

nbp_mt_scheduler_rule_t nbp_mt_scheduler_create_empty_rule(
    unsigned int ruleType)
{
    nbp_mt_scheduler_rule_t rule;

    rule.ruleType   = ruleType;
    rule.dataType   = NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_EMPTY;
    rule.test       = NBP_MEMORY_NULL_POINTER;

    return rule;
}

void* nbp_mt_scheduler_create_ctx(unsigned long long numberOfRules, ...)
{
    va_list args;

    unsigned long long index;
    unsigned long long size = sizeof(nbp_mt_scheduler_context_t);
    if (numberOfRules > 1) {
        size += ((numberOfRules - 1) * sizeof(nbp_mt_scheduler_rule_t));
    }

    nbp_mt_scheduler_context_t* ctx =
        (nbp_mt_scheduler_context_t*) NBP_MEMORY_ALLOC(size);
    if (ctx == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for memory allocation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_OUT_OF_MEMORY,
            "could not alloc context"
        );
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        return NBP_MEMORY_NULL_POINTER;
        // LCOV_EXCL_STOP
    }

    va_start(args, numberOfRules);

    ctx->numberOfRules = numberOfRules;
    for (index = 0; index < numberOfRules; ++index) {
        ctx->rules[index] = va_arg(args, nbp_mt_scheduler_rule_t);
    }

    va_end(args);

    return (void*) ctx;
}

static void nbp_mt_scheduler_queue_push(unsigned int testId)
{
    if (nbpMtSchedulerQueueLast == NBP_MEMORY_NULL_POINTER) {
        nbpMtSchedulerQueue = &nbpMtSchedulerTests[testId];
        nbpMtSchedulerQueueLast = &nbpMtSchedulerTests[testId];
    } else {
        nbpMtSchedulerQueueLast->nextInQueue = &nbpMtSchedulerTests[testId];
        nbpMtSchedulerQueueLast = &nbpMtSchedulerTests[testId];
    }
}

static nbp_mt_scheduler_test_t* nbp_mt_scheduler_queue_pop(unsigned int workerId)
{
    nbp_mt_scheduler_test_t* prev = NBP_MEMORY_NULL_POINTER;
    nbp_mt_scheduler_test_t* test = nbpMtSchedulerQueue;

    while (test != NBP_MEMORY_NULL_POINTER) {
        if (test->requestedWorkerId == NBP_MEMORY_NULL_POINTER) {
            break;
        }

        if (*test->requestedWorkerId == NBP_MT_SCHEDULER_PRIVATE_INVALID_WORKER_ID ) {
            *test->requestedWorkerId = workerId;
            break;
        }

        if (*test->requestedWorkerId == workerId) {
            break;
        }

        prev = test;
        test = test->nextInQueue;
    }

    // no test found for this worker
    if (test == NBP_MEMORY_NULL_POINTER) {
        return test;
    }

    // test is the first element in queue
    if (test == nbpMtSchedulerQueue) {
        nbpMtSchedulerQueue = test->nextInQueue;

        // test is the only element in queue
        if (test == nbpMtSchedulerQueueLast) {
            nbpMtSchedulerQueueLast = NBP_MEMORY_NULL_POINTER;
        }

        return test;
    }

    // test is the last element in queue
    if (test == nbpMtSchedulerQueueLast) {
        prev->nextInQueue = NBP_MEMORY_NULL_POINTER;
        nbpMtSchedulerQueueLast = prev;

        return test;
    }

    // the is somewhere in queue but it is not the first or last
    prev->nextInQueue = test->nextInQueue;

    return test;
}

static nbp_test_details_t* nbp_mt_scheduler_get_first_test_from_module(
    nbp_module_details_t* module)
{
    nbp_test_details_t* firstTest = NBP_MEMORY_NULL_POINTER;
    nbp_test_details_t* test;
    nbp_module_details_t* submodule;

    NBP_MODULE_FOR_EACH_TEST(module, test) {
        return test;
    }

    NBP_MODULE_FOR_EACH_SUBMODULE(module, submodule) {
        firstTest = nbp_mt_scheduler_get_first_test_from_module(submodule);
        if (firstTest != NBP_MEMORY_NULL_POINTER) {
            return firstTest;
        }
    }

    return NBP_MEMORY_NULL_POINTER;
}

static void nbp_mt_scheduler_set_test_on_same_thread_as_test(
    unsigned int testId1, unsigned int testId2)
{
    nbp_mt_scheduler_test_t* test1;
    nbp_mt_scheduler_test_t* test2;
    nbp_mt_scheduler_test_t* last = NBP_MEMORY_NULL_POINTER;
    nbp_mt_scheduler_test_t* current;

    if (testId1 == testId2) {
        return;
    }

    test1 = &nbpMtSchedulerTests[testId1];
    test2 = &nbpMtSchedulerTests[testId2];

    if (test1->requestedWorkerId == test2->requestedWorkerId) {
        if (test1->requestedWorkerId != NBP_MEMORY_NULL_POINTER) {
            return;
        }

        test1->requestedWorkerId =
            (unsigned int*) NBP_MEMORY_ALLOC(sizeof(unsigned int));
        if (test1->requestedWorkerId == NBP_MEMORY_NULL_POINTER) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for memory allocation
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(NBP_ERROR_CODE_OUT_OF_MEMORY);
            NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
            // LCOV_EXCL_STOP
        }

        *test1->requestedWorkerId = NBP_MT_SCHEDULER_PRIVATE_INVALID_WORKER_ID;

        test2->requestedWorkerId = test1->requestedWorkerId;

        test1->nextTestOnThisWorker = test2;
        test2->nextTestOnThisWorker = test1;

        return;
    }

    if (test1->requestedWorkerId == NBP_MEMORY_NULL_POINTER) {
        test1->requestedWorkerId = test2->requestedWorkerId;

        test1->nextTestOnThisWorker = test2->nextTestOnThisWorker;
        test2->nextTestOnThisWorker = test1;

        return;
    }

    if (test2->requestedWorkerId == NBP_MEMORY_NULL_POINTER) {
        test2->requestedWorkerId = test1->requestedWorkerId;

        test2->nextTestOnThisWorker = test1->nextTestOnThisWorker;
        test1->nextTestOnThisWorker = test2;

        return;
    }

    NBP_MEMORY_FREE(test2->requestedWorkerId);
    test2->requestedWorkerId = test1->requestedWorkerId;

    current = test2->nextTestOnThisWorker;
    while (current != test2) {
        current->requestedWorkerId = test1->requestedWorkerId;

        last = current;
        current = current->nextTestOnThisWorker;
    }

    current = test1->nextTestOnThisWorker;
    test1->nextTestOnThisWorker = test2;
    last->nextTestOnThisWorker = current;
}

static void nbp_mt_scheduler_set_module_on_same_thread_as_test(
    nbp_module_details_t* module, unsigned int testId)
{
    nbp_test_details_t* test;
    nbp_module_details_t* submodule;
    unsigned int testId2;

    NBP_MODULE_FOR_EACH_TEST(module, test) {
        testId2 = NBP_TEST_GET_ID(test);
        nbp_mt_scheduler_set_test_on_same_thread_as_test(testId, testId2);
    }

    NBP_MODULE_FOR_EACH_SUBMODULE(module, submodule) {
        nbp_mt_scheduler_set_module_on_same_thread_as_test(submodule, testId);
    }
}

static void nbp_mt_scheduler_set_module_on_same_thread_as_module(
    nbp_module_details_t* module1, nbp_module_details_t* module2)
{
    nbp_test_details_t* module1FirstTest = NBP_MEMORY_NULL_POINTER;
    nbp_test_details_t* module2FirstTest = NBP_MEMORY_NULL_POINTER;
    unsigned int module1FirstTestId = 0;
    unsigned int module2FirstTestId = 0;

    module1FirstTest = nbp_mt_scheduler_get_first_test_from_module(module1);
    if (module1FirstTest != NBP_MEMORY_NULL_POINTER) {
        module1FirstTestId = NBP_TEST_GET_ID(module1FirstTest);
        nbp_mt_scheduler_set_module_on_same_thread_as_test(
            module1,
            module1FirstTestId
        );
    }

    module2FirstTest = nbp_mt_scheduler_get_first_test_from_module(module2);
    if (module2FirstTest != NBP_MEMORY_NULL_POINTER) {
        module2FirstTestId = NBP_TEST_GET_ID(module2FirstTest);
        nbp_mt_scheduler_set_module_on_same_thread_as_test(
            module2,
            module2FirstTestId
        );
    }

    if (module1FirstTest != NBP_MEMORY_NULL_POINTER &&
        module2FirstTest != NBP_MEMORY_NULL_POINTER) {
        nbp_mt_scheduler_set_test_on_same_thread_as_test(
            module1FirstTestId,
            module2FirstTestId
        );
    }
}

static void nbp_mt_scheduler_set_module_on_same_thread(
    nbp_module_details_t* module)
{
    nbp_test_details_t* firstTest = NBP_MEMORY_NULL_POINTER;
    nbp_test_details_t* test;
    nbp_module_details_t* submodule;
    unsigned int firstTestId;
    unsigned int testId;

    firstTest = nbp_mt_scheduler_get_first_test_from_module(module);
    if (firstTest == NBP_MEMORY_NULL_POINTER) {
        return;
    }

    firstTestId = NBP_TEST_GET_ID(firstTest);

    NBP_MODULE_FOR_EACH_TEST(module, test) {
        testId = NBP_TEST_GET_ID(test);
        nbp_mt_scheduler_set_test_on_same_thread_as_test(firstTestId, testId);
    }

    NBP_MODULE_FOR_EACH_SUBMODULE(module, submodule) {
        nbp_mt_scheduler_set_module_on_same_thread_as_test(
            submodule,
            firstTestId
        );
    }
}

static void nbp_mt_scheduler_add_pending_test_to_test(unsigned int pendingTestId,
    unsigned int testId)
{
    unsigned int bitsPerUint = sizeof(unsigned int) * 8;
    unsigned int rowIndex;
    unsigned int columnIndex;
    unsigned int testIndex;
    unsigned int testBit;
    unsigned int* matrixElement;

    rowIndex = pendingTestId * nbpMtSchedulerNumberOfColumns;
    columnIndex = testId / bitsPerUint;
    matrixElement = nbpMtSchedulerAdjacencyMatrix + rowIndex + columnIndex;

    testIndex = testId % bitsPerUint;
    testBit = ((unsigned int) 1) << testIndex;

    if ((*matrixElement & testBit) == 0) {
        *matrixElement |= testBit;
        nbpMtSchedulerTests[testId].numberOfPendingTests++;
    }
}

static void nbp_mt_scheduler_add_pending_test_to_module(
    unsigned int pendingTestId, nbp_module_details_t* module)
{
    nbp_test_details_t* test;
    nbp_module_details_t* submodule;
    unsigned int testId;

    NBP_MODULE_FOR_EACH_TEST(module, test) {
        testId = NBP_TEST_GET_ID(test);
        nbp_mt_scheduler_add_pending_test_to_test(pendingTestId, testId);
    }

    NBP_MODULE_FOR_EACH_SUBMODULE(module, submodule) {
        nbp_mt_scheduler_add_pending_test_to_module(pendingTestId, submodule);
    }
}

static void nbp_mt_scheduler_add_pending_module_to_test(
    nbp_module_details_t* pendingModule, unsigned int testId)
{
    nbp_test_details_t* test;
    nbp_module_details_t* submodule;
    unsigned int pendingTestId;

    NBP_MODULE_FOR_EACH_TEST(pendingModule, test) {
        pendingTestId = NBP_TEST_GET_ID(test);
        nbp_mt_scheduler_add_pending_test_to_test(pendingTestId, testId);
    }

    NBP_MODULE_FOR_EACH_SUBMODULE(pendingModule, submodule) {
        nbp_mt_scheduler_add_pending_module_to_test(submodule, testId);
    }
}

static void nbp_mt_scheduler_add_pending_module_to_module(
    nbp_module_details_t* pendingModule, nbp_module_details_t* module)
{
    nbp_test_details_t* test;
    nbp_module_details_t* submodule;
    unsigned int testId;

    NBP_MODULE_FOR_EACH_TEST(module, test) {
        testId = NBP_TEST_GET_ID(test);
        nbp_mt_scheduler_add_pending_module_to_test(pendingModule, testId);
    }

    NBP_MODULE_FOR_EACH_SUBMODULE(module, submodule) {
        nbp_mt_scheduler_add_pending_module_to_module(pendingModule, submodule);
    }
}

static int nbp_mt_scheduler_test_completed(unsigned int testId)
{
    unsigned int bitsPerUint = sizeof(unsigned int) * 8;
    unsigned int columnIndex = 0;
    unsigned int rowIndex;
    unsigned int testIndex;
    unsigned int* matrixRowStart;
    int notifyWorkers = 0;

    rowIndex = testId * nbpMtSchedulerNumberOfColumns;
    matrixRowStart = nbpMtSchedulerAdjacencyMatrix + rowIndex;

    for ( ; columnIndex < nbpMtSchedulerNumberOfColumns; columnIndex++) {
        testIndex = columnIndex * bitsPerUint;
        while (matrixRowStart[columnIndex] != 0) {
            if ((matrixRowStart[columnIndex] & 1) != 0) {
                nbpMtSchedulerTests[testIndex].numberOfPendingTests--;
                if (nbpMtSchedulerTests[testIndex].numberOfPendingTests == 0) {
                    nbp_mt_scheduler_queue_push(testIndex);
                    notifyWorkers = 1;
                }
            }

            testIndex++;
            matrixRowStart[columnIndex] >>= 1; /* TODO: portable lzcnt */
        }
    }

    return notifyWorkers;
}

static NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE nbp_mt_scheduler_worker_thread_func(
    void* param)
{
    unsigned int workerId = *((unsigned int*) param);
    nbp_mt_scheduler_test_t* test;
    NBP_ERROR_CODE_TYPE errCode;
    int notifyWorkers = 0;

    (void)(workerId);

    errCode = NBP_MT_SCHEDULER_MUTEX_LOCK(nbpMtSchedulerMutex);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_MT_SCHEDULER_MUTEX_LOCK
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(errCode);
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }

    while (nbpMtSchedulerNumberOfDispatchedTests != nbpMtSchedulerNumberOfTests) {
        test = nbp_mt_scheduler_queue_pop(workerId);
        if (test == NBP_MEMORY_NULL_POINTER) {
            errCode = NBP_MT_SCHEDULER_CONDVAR_WAIT(
                nbpMtSchedulerCondVar,
                nbpMtSchedulerMutex
            );
            if (errCode != NBP_ERROR_CODE_SUCCESS) {
                // these lines are excluded from coverage because it is pretty
                // hard to trigger an error for NBP_MT_SCHEDULER_CONDVAR_WAIT
                // LCOV_EXCL_START
                NBP_ERROR_REPORT(errCode);
                NBP_EXIT(errCode);
                // LCOV_EXCL_STOP
            }

            continue;
        }

        nbpMtSchedulerNumberOfDispatchedTests++;

        errCode = NBP_MT_SCHEDULER_MUTEX_UNLOCK(nbpMtSchedulerMutex);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_MT_SCHEDULER_MUTEX_UNLOCK
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        NBP_SCHEDULER_RUN_TEST(test->test);

        errCode = NBP_MT_SCHEDULER_MUTEX_LOCK(nbpMtSchedulerMutex);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_MT_SCHEDULER_MUTEX_LOCK
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        notifyWorkers = nbp_mt_scheduler_test_completed(
            NBP_TEST_GET_ID(test->test)
        );
        if (notifyWorkers == 0) {
            continue;
        }

        errCode = NBP_MT_SCHEDULER_MUTEX_UNLOCK(nbpMtSchedulerMutex);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_MT_SCHEDULER_MUTEX_UNLOCK
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        errCode = NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ALL(nbpMtSchedulerCondVar);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ALL
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        errCode = NBP_MT_SCHEDULER_MUTEX_LOCK(nbpMtSchedulerMutex);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_MT_SCHEDULER_MUTEX_LOCK
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }
    }

    errCode = NBP_MT_SCHEDULER_MUTEX_UNLOCK(nbpMtSchedulerMutex);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_MT_SCHEDULER_MUTEX_UNLOCK
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(errCode);
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }

    return NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE_DEFAULT_VALUE;
}

static void nbp_mt_scheduler_processing_test_context(unsigned int testId,
    nbp_mt_scheduler_context_t* ctx)
{
    unsigned int ruleDataTestId;
    unsigned long long index;
    nbp_mt_scheduler_rule_t* rule;

    for (index = 0; index < ctx->numberOfRules; index++) {
        rule = &ctx->rules[index];
        if (rule->dataType == NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_TEST) {
            ruleDataTestId = NBP_TEST_GET_ID(rule->test);

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_AFTER) {
                nbp_mt_scheduler_add_pending_test_to_test(ruleDataTestId, testId);
                continue;
            }

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_BEFORE) {
                nbp_mt_scheduler_add_pending_test_to_test(testId, ruleDataTestId);
                continue;
            }

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD) {
                nbp_mt_scheduler_set_test_on_same_thread_as_test(testId, ruleDataTestId);
                continue;
            }

            // these lines are excluded from coverage because it is impossible
            // to use other values if there is no bug in implementation
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_GENERIC_ERROR,
                "unknown rule type"
            );
            NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
            // LCOV_EXCL_STOP
        }

        if (rule->dataType == NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_MODULE) {
            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_AFTER) {
                nbp_mt_scheduler_add_pending_module_to_test(rule->module, testId);
                continue;
            }

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_BEFORE) {
                nbp_mt_scheduler_add_pending_test_to_module(testId, rule->module);
                continue;
            }

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD) {
                nbp_mt_scheduler_set_module_on_same_thread_as_test(rule->module, testId);
                continue;
            }

            // these lines are excluded from coverage because it is impossible
            // to use other values if there is no bug in implementation
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_GENERIC_ERROR,
                "unknown rule type"
            );
            NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
            // LCOV_EXCL_STOP
        }

        // these lines are excluded from coverage because it is impossible to
        // use other values if there is no bug in implementation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_GENERIC_ERROR,
            "unknown rule data type"
        );
        NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
        // LCOV_EXCL_STOP
    }
}

static void nbp_mt_scheduler_processing_module_context(
    nbp_module_details_t* module, nbp_mt_scheduler_context_t* ctx)
{
    unsigned int ruleDataTestId;
    unsigned long long index;
    nbp_mt_scheduler_rule_t* rule;

    for (index = 0; index < ctx->numberOfRules; index++) {
        rule = &ctx->rules[index];
        if (rule->dataType == NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_TEST) {
            ruleDataTestId = NBP_TEST_GET_ID(rule->test);

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_AFTER) {
                nbp_mt_scheduler_add_pending_test_to_module(ruleDataTestId, module);
                continue;
            }

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_BEFORE) {
                nbp_mt_scheduler_add_pending_module_to_test(module, ruleDataTestId);
                continue;
            }

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD) {
                nbp_mt_scheduler_set_module_on_same_thread_as_test(module, ruleDataTestId);
                continue;
            }

            // these lines are excluded from coverage because it is impossible
            // to use other values if there is no bug in implementation
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_GENERIC_ERROR,
                "unknown rule type"
            );
            NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
            // LCOV_EXCL_STOP
        }

        if (rule->dataType == NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_MODULE) {
            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_AFTER) {
                nbp_mt_scheduler_add_pending_module_to_module(rule->module, module);
                continue;
            }

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_BEFORE) {
                nbp_mt_scheduler_add_pending_module_to_module(module, rule->module);
                continue;
            }

            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD) {
                nbp_mt_scheduler_set_module_on_same_thread_as_module(module, rule->module);
                continue;
            }

            // these lines are excluded from coverage because it is impossible
            // to use other values if there is no bug in implementation
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_GENERIC_ERROR,
                "unknown rule type"
            );
            NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
            // LCOV_EXCL_STOP
        }

        if (rule->dataType == NBP_MT_SCHEDULER_PRIVATE_RULE_DATA_TYPE_EMPTY) {
            if (rule->ruleType == NBP_MT_SCHEDULER_PRIVATE_RULE_TYPE_SAME_THREAD) {
                nbp_mt_scheduler_set_module_on_same_thread(module);
                continue;
            }

            // these lines are excluded from coverage because it is impossible
            // to use other values if there is no bug in implementation
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_GENERIC_ERROR,
                "unknown rule type"
            );
            NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
            // LCOV_EXCL_STOP
        }

        // these lines are excluded from coverage because it is impossible to
        // use other values if there is no bug in implementation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_GENERIC_ERROR,
            "unknown rule data type"
        );
        NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
        // LCOV_EXCL_STOP
    }
}

static void nbp_mt_scheduler_allocate_array_of_tests()
{
    unsigned int index = 0;

    nbpMtSchedulerTests = (nbp_mt_scheduler_test_t*) NBP_MEMORY_ALLOC(
        nbpMtSchedulerNumberOfTests * sizeof(nbp_mt_scheduler_test_t)
    );
    if (nbpMtSchedulerTests == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for memory allocation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_OUT_OF_MEMORY,
            "could not alloc array of tests"
        );
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        // LCOV_EXCL_STOP
    }

    for ( ; index < nbpMtSchedulerNumberOfTests; index++) {
        nbpMtSchedulerTests[index].test = NBP_MEMORY_NULL_POINTER;
        nbpMtSchedulerTests[index].numberOfPendingTests = 0;

        nbpMtSchedulerTests[index].requestedWorkerId = NBP_MEMORY_NULL_POINTER;
        nbpMtSchedulerTests[index].nextTestOnThisWorker = NBP_MEMORY_NULL_POINTER;

        nbpMtSchedulerTests[index].nextInQueue = NBP_MEMORY_NULL_POINTER;
    }
}

static void nbp_mt_scheduler_allocate_adjacency_matrix()
{
    unsigned int bitsPerUint = sizeof(unsigned int) * 8;
    unsigned int index = 0;
    unsigned int numberOfElements;

    nbpMtSchedulerNumberOfColumns = nbpMtSchedulerNumberOfTests / bitsPerUint +
        (nbpMtSchedulerNumberOfTests % bitsPerUint != 0 ? 1 : 0);

    numberOfElements = nbpMtSchedulerNumberOfTests * nbpMtSchedulerNumberOfColumns;

    nbpMtSchedulerAdjacencyMatrix = (unsigned int*) NBP_MEMORY_ALLOC(
        numberOfElements * sizeof(unsigned int)
    );
    if (nbpMtSchedulerAdjacencyMatrix == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for memory allocation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_OUT_OF_MEMORY,
            "could not alloc adjacency matrix"
        );
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        // LCOV_EXCL_STOP
    }

    for ( ; index < numberOfElements; index++) {
        nbpMtSchedulerAdjacencyMatrix[index] = 0;
    }
}

static void nbp_mt_scheduler_processing_data()
{
    unsigned int testId;
    nbp_mt_scheduler_data_t* data = nbpMtSchedulerData;
    nbp_mt_scheduler_data_t* tmp;

    while (data != NBP_MEMORY_NULL_POINTER) {
        if (data->dataType == NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_TEST) {
            testId = NBP_TEST_GET_ID(data->test);
            nbpMtSchedulerTests[testId].test = data->test;

            if (data->ctx != NBP_MEMORY_NULL_POINTER) {
                nbp_mt_scheduler_processing_test_context(testId, data->ctx);
                NBP_MEMORY_FREE(data->ctx);
            }
        } else if (data->dataType == NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_MODULE) {
            if (data->ctx != NBP_MEMORY_NULL_POINTER) {
                nbp_mt_scheduler_processing_module_context(
                    data->module,
                    data->ctx
                );
                NBP_MEMORY_FREE(data->ctx);
            }
        } else {
            // these lines are excluded from coverage because it is impossible
            // to use other values if there is no bug in implementation
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_GENERIC_ERROR,
                "unknown data type"
            );
            NBP_EXIT(NBP_ERROR_CODE_GENERIC_ERROR);
            // LCOV_EXCL_STOP
        }

        tmp = data;
        data = data->next;

        NBP_MEMORY_FREE(tmp);
    }

    nbpMtSchedulerData = NBP_MEMORY_NULL_POINTER;
    nbpMtSchedulerDataLast = NBP_MEMORY_NULL_POINTER;

    // TODO: check if there is a cycle

    for (testId = 0; testId < nbpMtSchedulerNumberOfTests; testId++) {
        if (nbpMtSchedulerTests[testId].numberOfPendingTests == 0) {
            nbp_mt_scheduler_queue_push(testId);
        }
    }
}

static void nbp_mt_scheduler_create_threads_and_run()
{
    unsigned int index = 0;
    unsigned int numberOfThreads = nbp_mt_scheduler_get_number_of_threads();
    nbp_mt_scheduler_thread_t* threads;
    NBP_ERROR_CODE_TYPE err;

    numberOfThreads--;

    threads = (nbp_mt_scheduler_thread_t*) NBP_MEMORY_ALLOC(
        numberOfThreads * sizeof(nbp_mt_scheduler_thread_t)
    );
    if (threads == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for memory allocation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_OUT_OF_MEMORY,
            "could not alloc array of threads"
        );
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        // LCOV_EXCL_STOP
    }

    for ( ; index < numberOfThreads; index++) {
        threads[index].workerId = index;
        err = NBP_MT_SCHEDULER_THREAD_CREATE(
            threads[index].thread,
            nbp_mt_scheduler_worker_thread_func,
            (void*) &threads[index].workerId
        );
        if (err != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_MT_SCHEDULER_THREAD_CREATE
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(err, "could not create thread");
            NBP_EXIT(err);
            // LCOV_EXCL_STOP
        }
    }

    nbp_mt_scheduler_worker_thread_func((void*) &index);

    for (index = 0; index < numberOfThreads; index++) {
        err = NBP_MT_SCHEDULER_THREAD_JOIN(threads[index].thread);
        if (err != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_MT_SCHEDULER_THREAD_JOIN
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(err, "failed to join thread");
            NBP_EXIT(err);
            // LCOV_EXCL_STOP
        }
    }

    NBP_MEMORY_FREE(threads);
}

NBP_SCHEDULER_CALLBACK_INIT(nbp_mt_scheduler_init)
{
    NBP_ERROR_CODE_TYPE errCode;

    errCode = NBP_MT_SCHEDULER_MUTEX_INIT(nbpMtSchedulerMutex);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_MT_SCHEDULER_MUTEX_INIT
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(errCode, "failed to init mutex");
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }

    errCode = NBP_MT_SCHEDULER_CONDVAR_INIT(nbpMtSchedulerCondVar);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_MT_SCHEDULER_CONDVAR_INIT
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(errCode, "failed to init conditional variable");
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }
}

NBP_SCHEDULER_CALLBACK_UNINIT(nbp_mt_scheduler_uninit)
{
    NBP_ERROR_CODE_TYPE errCode;
    nbp_mt_scheduler_data_t* tmp;

    while (nbpMtSchedulerData != NBP_MEMORY_NULL_POINTER) {
        if (nbpMtSchedulerData->ctx != NBP_MEMORY_NULL_POINTER) {
            NBP_MEMORY_FREE(nbpMtSchedulerData->ctx);
        }

        tmp = nbpMtSchedulerData;
        nbpMtSchedulerData = nbpMtSchedulerData->next;

        NBP_MEMORY_FREE(tmp);
    }
    nbpMtSchedulerDataLast = NBP_MEMORY_NULL_POINTER;

    nbpMtSchedulerTests = NBP_MEMORY_NULL_POINTER;
    nbpMtSchedulerAdjacencyMatrix = NBP_MEMORY_NULL_POINTER;

    nbpMtSchedulerQueue = NBP_MEMORY_NULL_POINTER;
    nbpMtSchedulerQueueLast = NBP_MEMORY_NULL_POINTER;

    errCode = NBP_MT_SCHEDULER_MUTEX_UNINIT(nbpMtSchedulerMutex);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_MT_SCHEDULER_MUTEX_UNINIT
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(errCode, "failed to uninit mutex");
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }

    errCode = NBP_MT_SCHEDULER_CONDVAR_UNINIT(nbpMtSchedulerCondVar);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_MT_SCHEDULER_CONDVAR_UNINIT
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(errCode, "failed to uninit conditional variable");
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }
}

NBP_SCHEDULER_CALLBACK_RUN(nbp_mt_scheduler_run)
{
    unsigned int index = 0;
    nbp_mt_scheduler_test_t* test = NBP_MEMORY_NULL_POINTER;

    if (nbpMtSchedulerNumberOfTests == 0) {
        return;
    }

    nbp_mt_scheduler_allocate_array_of_tests();
    nbp_mt_scheduler_allocate_adjacency_matrix();
    nbp_mt_scheduler_processing_data();
    nbp_mt_scheduler_create_threads_and_run();

    for ( ; index < nbpMtSchedulerNumberOfTests; index++) {
        test = &nbpMtSchedulerTests[index];
        if (test->requestedWorkerId == NBP_MEMORY_NULL_POINTER) {
            continue;
        }

        NBP_MEMORY_FREE(test->requestedWorkerId);
        while (test->requestedWorkerId != NBP_MEMORY_NULL_POINTER) {
            test->requestedWorkerId = NBP_MEMORY_NULL_POINTER;
            test = test->nextTestOnThisWorker;
        }
    }

    NBP_MEMORY_FREE(nbpMtSchedulerAdjacencyMatrix);
    NBP_MEMORY_FREE(nbpMtSchedulerTests);
}

NBP_SCHEDULER_CALLBACK_RUN_TEST(nbp_mt_scheduler_run_test)
{
    nbp_mt_scheduler_data_t* data = NBP_MEMORY_NULL_POINTER;

    data = (nbp_mt_scheduler_data_t*) NBP_MEMORY_ALLOC(
        sizeof(nbp_mt_scheduler_data_t)
    );
    if (data == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for memory allocation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_OUT_OF_MEMORY,
            "could not add test"
        );
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        // LCOV_EXCL_STOP
    }

    data->dataType = NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_TEST;
    data->test = NBP_TEST_THIS;
    data->ctx = (nbp_mt_scheduler_context_t*) NBP_MEMORY_NULL_POINTER;
    data->next = NBP_MEMORY_NULL_POINTER;

    if (nbpMtSchedulerDataLast == NBP_MEMORY_NULL_POINTER) {
        nbpMtSchedulerData = data;
    } else {
        nbpMtSchedulerDataLast->next = data;
    }
    nbpMtSchedulerDataLast = data;

    nbpMtSchedulerNumberOfTests++;
}

NBP_SCHEDULER_CALLBACK_RUN_TEST_CTX(nbp_mt_scheduler_run_test_ctx)
{
    nbp_mt_scheduler_data_t* data = NBP_MEMORY_NULL_POINTER;

    data = (nbp_mt_scheduler_data_t*) NBP_MEMORY_ALLOC(
        sizeof(nbp_mt_scheduler_data_t)
    );
    if (data == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for memory allocation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_OUT_OF_MEMORY,
            "could not add test"
        );
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        // LCOV_EXCL_STOP
    }

    data->dataType = NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_TEST;
    data->test = NBP_TEST_THIS;
    data->ctx = (nbp_mt_scheduler_context_t*) NBP_SCHEDULER_CTX;
    data->next = NBP_MEMORY_NULL_POINTER;

    if (nbpMtSchedulerDataLast == NBP_MEMORY_NULL_POINTER) {
        nbpMtSchedulerData = data;
    } else {
        nbpMtSchedulerDataLast->next = data;
    }
    nbpMtSchedulerDataLast = data;

    nbpMtSchedulerNumberOfTests++;
}

NBP_SCHEDULER_CALLBACK_RUN_MODULE_CTX(nbp_mt_scheduler_run_module_ctx)
{
    nbp_mt_scheduler_data_t* data = NBP_MEMORY_NULL_POINTER;

    data = (nbp_mt_scheduler_data_t*) NBP_MEMORY_ALLOC(
        sizeof(nbp_mt_scheduler_data_t)
    );
    if (data == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for memory allocation
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_OUT_OF_MEMORY,
            "could not add module"
        );
        NBP_EXIT(NBP_ERROR_CODE_OUT_OF_MEMORY);
        // LCOV_EXCL_STOP
    }

    data->dataType = NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_MODULE;
    data->module = NBP_MODULE_THIS;
    data->ctx = (nbp_mt_scheduler_context_t*) NBP_SCHEDULER_CTX;
    data->next = NBP_MEMORY_NULL_POINTER;

    if (nbpMtSchedulerDataLast == NBP_MEMORY_NULL_POINTER) {
        nbpMtSchedulerData = data;
    } else {
        nbpMtSchedulerDataLast->next = data;
    }
    nbpMtSchedulerDataLast = data;
}

NBP_SCHEDULER(
    nbpMtScheduler,
    NBP_SCHEDULER_CALLBACKS(
        NBP_SCHEDULER_CALLBACK_INIT(nbp_mt_scheduler_init),
        NBP_SCHEDULER_CALLBACK_UNINIT(nbp_mt_scheduler_uninit),
        NBP_SCHEDULER_CALLBACK_RUN(nbp_mt_scheduler_run),
        NBP_SCHEDULER_CALLBACK_RUN_TEST(nbp_mt_scheduler_run_test),
        NBP_SCHEDULER_CALLBACK_RUN_TEST_CTX(nbp_mt_scheduler_run_test_ctx),
        NBP_SCHEDULER_CALLBACK_RUN_MODULE_CTX(nbp_mt_scheduler_run_module_ctx)
    )
);

/*
 * undef thread wrapper
 */
#undef NBP_MT_SCHEDULER_THREAD_TYPE
#undef NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE
#undef NBP_MT_SCHEDULER_THREAD_FUNC_RETURN_TYPE_DEFAULT_VALUE
#undef NBP_MT_SCHEDULER_THREAD_CREATE
#undef NBP_MT_SCHEDULER_THREAD_JOIN

/*
 * undef mutex wrapper
 */
#undef NBP_MT_SCHEDULER_MUTEX_TYPE
#undef NBP_MT_SCHEDULER_MUTEX_INITIALIZER
#undef NBP_MT_SCHEDULER_MUTEX_INIT
#undef NBP_MT_SCHEDULER_MUTEX_UNINIT
#undef NBP_MT_SCHEDULER_MUTEX_LOCK
#undef NBP_MT_SCHEDULER_MUTEX_UNLOCK

/*
 * undef conditional variable wrapper
 */
#undef NBP_MT_SCHEDULER_CONDVAR_TYPE
#undef NBP_MT_SCHEDULER_CONDVAR_INITIALIZER
#undef NBP_MT_SCHEDULER_CONDVAR_INIT
#undef NBP_MT_SCHEDULER_CONDVAR_UNINIT
#undef NBP_MT_SCHEDULER_CONDVAR_WAIT
#undef NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ONE
#undef NBP_MT_SCHEDULER_CONDVAR_NOTIFY_ALL

/*
 * undef data types
 */
#undef NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_UNKNOWN
#undef NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_TEST
#undef NBP_MT_SCHEDULER_PRIVATE_DATA_TYPE_MODULE

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_MT_SCHEDULER

/*
 * TODO: add docs
 */
#ifdef NBP_BASIC_SCHEDULER
#ifdef NBP_LIBRARY_MAIN

struct nbp_basic_scheduler_data_t {
    nbp_test_details_t* test;
    struct nbp_basic_scheduler_data_t* next;
};
typedef struct nbp_basic_scheduler_data_t nbp_basic_scheduler_data_t;

static nbp_basic_scheduler_data_t nbpBasicSchedulerData;
static nbp_basic_scheduler_data_t* nbpBasicSchedulerDataLast;

NBP_SCHEDULER_CALLBACK_INIT(nbp_basic_scheduler_init)
{
    nbpBasicSchedulerData.test = NBP_MEMORY_NULL_POINTER;
    nbpBasicSchedulerData.next = NBP_MEMORY_NULL_POINTER;
    nbpBasicSchedulerDataLast = &nbpBasicSchedulerData;
}

NBP_SCHEDULER_CALLBACK_UNINIT(nbp_basic_scheduler_uninit)
{
    nbp_basic_scheduler_data_t* data = nbpBasicSchedulerData.next;
    nbp_basic_scheduler_data_t* tmp = NBP_MEMORY_NULL_POINTER;
    while (data != NBP_MEMORY_NULL_POINTER) {
        tmp = data;
        data = data->next;
        NBP_MEMORY_FREE(tmp);
    }
}

NBP_SCHEDULER_CALLBACK_RUN(nbp_basic_scheduler_run)
{
    nbp_basic_scheduler_data_t* data = &nbpBasicSchedulerData;
    while (data->test != NBP_MEMORY_NULL_POINTER) {
        NBP_SCHEDULER_RUN_TEST(data->test);
        data = data->next;
    }
}

NBP_SCHEDULER_CALLBACK_RUN_TEST(nbp_basic_scheduler_run_test)
{
    nbpBasicSchedulerDataLast->test = NBP_TEST_THIS;
    nbpBasicSchedulerDataLast->next = (nbp_basic_scheduler_data_t*)
        NBP_MEMORY_ALLOC(sizeof(nbp_basic_scheduler_data_t));

    if (nbpBasicSchedulerDataLast->next == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is pretty hard
        // to trigger an error for memory allocation.
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_OUT_OF_MEMORY,
            "could not add test"
        );
        return;
        // LCOV_EXCL_STOP
    }

    nbpBasicSchedulerDataLast = nbpBasicSchedulerDataLast->next;
    nbpBasicSchedulerDataLast->next = NBP_MEMORY_NULL_POINTER;
    nbpBasicSchedulerDataLast->test = NBP_MEMORY_NULL_POINTER;
}

NBP_SCHEDULER(
    nbpBasicScheduler,
    NBP_SCHEDULER_CALLBACKS(
        NBP_SCHEDULER_CALLBACK_INIT(nbp_basic_scheduler_init),
        NBP_SCHEDULER_CALLBACK_UNINIT(nbp_basic_scheduler_uninit),
        NBP_SCHEDULER_CALLBACK_RUN(nbp_basic_scheduler_run),
        NBP_SCHEDULER_CALLBACK_RUN_TEST(nbp_basic_scheduler_run_test)
    )
);

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_BASIC_SCHEDULER

#endif // end if NBP_CUSTOM_SCHEDULER

#ifdef NBP_SCHEDULER_PREPROCESSING_CONTEXT

#define NBP_PRIVATE_SCHEDULER_PREPROCESSING_CONTEXT(ctx)                       \
    NBP_SCHEDULER_PREPROCESSING_CONTEXT(P ## ctx)

#else // NBP_SCHEDULER_PREPROCESSING_CONTEXT is not defined

#define NBP_PRIVATE_SCHEDULER_PREPROCESSING_CONTEXT(ctx)

#endif // end if NBP_SCHEDULER_PREPROCESSING_CONTEXT

#ifdef NBP_DEFAULT_PRINTER

#ifdef NBP_LIBRARY_MAIN

/*
 * Default nbp printer for Linux
 */
#ifdef NBP_OS_LINUX
#include <stdio.h>
#include <string.h>

#define NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL              "\x1B[0m"
#define NBP_LINUX_PRINTER_PRIVATE_COLOR_RED                 "\x1B[31m"
#define NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN               "\x1B[32m"
#define NBP_LINUX_PRINTER_PRIVATE_COLOR_YELLOW              "\x1B[33m"

#define NBP_LINUX_PRINTER_PRIVATE_CLEAR_LINE                "\x1B[2K\r"

#define NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_UNKNOWN      (unsigned int) 0x50000000
#define NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_TEST         (unsigned int) 0x50000001
#define NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_MODULE       (unsigned int) 0x50000002

#define NBP_LINUX_PRINTER_PRIVATE_GENERATE_CONDITION(buff, size)               \

#ifdef NBP_MT_SUPPORT

#include <pthread.h>

static inline NBP_ERROR_CODE_TYPE nbp_linux_printer_mutex_init(
    pthread_mutex_t* mutex)
{
    return pthread_mutex_init(mutex, NULL) == 0
        ? NBP_ERROR_CODE_SUCCESS
        : NBP_ERROR_CODE_SYNC_ERROR;
}

static inline NBP_ERROR_CODE_TYPE nbp_linux_printer_mutex_uninit(
    pthread_mutex_t* mutex)
{
    return pthread_mutex_destroy(mutex) == 0
        ? NBP_ERROR_CODE_SUCCESS
        : NBP_ERROR_CODE_SYNC_ERROR;
}

static inline NBP_ERROR_CODE_TYPE nbp_linux_printer_mutex_lock(
    pthread_mutex_t* mutex)
{
    return pthread_mutex_lock(mutex) == 0
        ? NBP_ERROR_CODE_SUCCESS
        : NBP_ERROR_CODE_SYNC_ERROR;
}

static inline NBP_ERROR_CODE_TYPE nbp_linux_printer_mutex_unlock(
    pthread_mutex_t* mutex)
{
    return pthread_mutex_unlock(mutex) == 0
        ? NBP_ERROR_CODE_SUCCESS
        : NBP_ERROR_CODE_SYNC_ERROR;
}

#define NBP_LINUX_PRINTER_PRIVATE_DECLARE_MUTEX(name)                          \
    pthread_mutex_t name = PTHREAD_MUTEX_INITIALIZER;

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_INIT(name)                             \
    nbp_linux_printer_mutex_init(&name)

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNINIT(name)                           \
    nbp_linux_printer_mutex_uninit(&name)

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_LOCK(name)                             \
    nbp_linux_printer_mutex_lock(&name)

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNLOCK(name)                           \
    nbp_linux_printer_mutex_unlock(&name)

#else // NBP_MT_SUPPORT not defined

static inline NBP_ERROR_CODE_TYPE nbp_linux_printer_mutex_init_empty()
{
    return NBP_ERROR_CODE_SUCCESS;
}

static inline NBP_ERROR_CODE_TYPE nbp_linux_printer_mutex_uninit_empty()
{
    return NBP_ERROR_CODE_SUCCESS;
}

static inline NBP_ERROR_CODE_TYPE nbp_linux_printer_mutex_lock_empty()
{
    return NBP_ERROR_CODE_SUCCESS;
}

static inline NBP_ERROR_CODE_TYPE nbp_linux_printer_mutex_unlock_empty()
{
    return NBP_ERROR_CODE_SUCCESS;
}

#define NBP_LINUX_PRINTER_PRIVATE_DECLARE_MUTEX(name)

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_INIT(name)                             \
    nbp_linux_printer_mutex_init_empty()

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNINIT(name)                           \
    nbp_linux_printer_mutex_uninit_empty()

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_LOCK(name)                             \
    nbp_linux_printer_mutex_lock_empty()

#define NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNLOCK(name)                           \
    nbp_linux_printer_mutex_unlock_empty()

#endif // end if NBP_MT_SUPPORT

struct nbp_linux_printer_messages_list_t {
    char* message;
    struct nbp_linux_printer_messages_list_t* next;
};
typedef struct nbp_linux_printer_messages_list_t nbp_linux_printer_messages_list_t;

struct nbp_linux_printer_test_t {
    nbp_test_details_t* test;
    nbp_linux_printer_messages_list_t* messages;
    nbp_linux_printer_messages_list_t* messagesLast;
};
typedef struct nbp_linux_printer_test_t nbp_linux_printer_test_t;

struct nbp_linux_printer_module_t {
    nbp_module_details_t* module;
};
typedef struct nbp_linux_printer_module_t nbp_linux_printer_module_t;

struct nbp_linux_printer_data_t {
    unsigned int type;
    union {
        nbp_linux_printer_test_t test;
        nbp_linux_printer_module_t module;
    };
    struct nbp_linux_printer_data_t* next;
};
typedef struct nbp_linux_printer_data_t nbp_linux_printer_data_t;

static nbp_linux_printer_data_t* nbpLinuxPrinterData;
static nbp_linux_printer_data_t* nbpLinuxPrinterDataLast;

static unsigned int nbpLinuxPrinterModulesNum;
static unsigned int nbpLinuxPrinterTestsNum;
static unsigned int nbpLinuxPrinterCompletedTestsNum;

NBP_LINUX_PRINTER_PRIVATE_DECLARE_MUTEX(nbpLinuxPrinterMutex);

static char* nbp_linux_printer_duplicate_str(const char* str)
{
    char* dup = (char*) NBP_MEMORY_ALLOC(strlen(str) + 1);
    if (dup != NBP_MEMORY_NULL_POINTER) {
        strcpy(dup, str);
    }
    return dup;
}

static nbp_linux_printer_data_t* nbp_linux_printer_create_data_from_test(
    nbp_test_details_t* test)
{
    nbp_linux_printer_data_t* data = NBP_MEMORY_NULL_POINTER;

    do {
        data = (nbp_linux_printer_data_t*) NBP_MEMORY_ALLOC(sizeof(*data));
        if (data == NBP_MEMORY_NULL_POINTER) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for memory allocation.
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_OUT_OF_MEMORY,
                "could not allocate nbp_linux_printer_data_t struct from test"
            );
            break;
            // LCOV_EXCL_STOP
        }

        data->type              = NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_TEST;
        data->test.test         = test;
        data->test.messages     = NBP_MEMORY_NULL_POINTER;
        data->test.messagesLast = NBP_MEMORY_NULL_POINTER;
        data->next              = NBP_MEMORY_NULL_POINTER;
    } while (0);

    return data;
}

static nbp_linux_printer_data_t* nbp_linux_printer_create_data_from_module(
    nbp_module_details_t* module)
{
    nbp_linux_printer_data_t* data = NBP_MEMORY_NULL_POINTER;

    do {
        data = (nbp_linux_printer_data_t*) NBP_MEMORY_ALLOC(sizeof(*data));
        if (data == NBP_MEMORY_NULL_POINTER) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for memory allocation.
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_OUT_OF_MEMORY,
                "could not allocate nbp_linux_printer_data_t struct from module"
            );
            break;
            // LCOV_EXCL_STOP
        }

        data->type          = NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_MODULE;
        data->module.module = module;
        data->next          = NBP_MEMORY_NULL_POINTER;
    } while (0);

    return data;
}

static nbp_linux_printer_data_t* nbp_linux_printer_find_printer_test(
    nbp_test_details_t* test)
{
    nbp_linux_printer_data_t* data = nbpLinuxPrinterData;
    for ( ; data != NBP_MEMORY_NULL_POINTER; data = data->next) {
        if (data->type != NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_TEST) {
            continue;
        }

        if (data->test.test != test) {
            continue;
        }

        return data;
    }

    return NBP_MEMORY_NULL_POINTER;
}

static void nbp_linux_printer_delete_messages(
    nbp_linux_printer_messages_list_t* msg)
{
    nbp_linux_printer_messages_list_t* tmp = NBP_MEMORY_NULL_POINTER;
    while (msg != NBP_MEMORY_NULL_POINTER) {
        tmp = msg;
        msg = tmp->next;

        tmp->next = NBP_MEMORY_NULL_POINTER;

        NBP_MEMORY_FREE(tmp->message);
        NBP_MEMORY_FREE(tmp);
    }
}

static nbp_linux_printer_messages_list_t* nbp_linux_printer_create_message(
    char* msg)
{
    nbp_linux_printer_messages_list_t* message = NBP_MEMORY_NULL_POINTER;

    do {
        message = (nbp_linux_printer_messages_list_t*)
            NBP_MEMORY_ALLOC(sizeof(nbp_linux_printer_messages_list_t));

        if (message == NBP_MEMORY_NULL_POINTER) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for memory allocation.
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_OUT_OF_MEMORY,
                "could not allocate nbp_linux_printer_messages_list_t struct"
            );
            break;
            // LCOV_EXCL_STOP
        }

        message->next = NBP_MEMORY_NULL_POINTER;
        message->message = nbp_linux_printer_duplicate_str(msg);

        if (message->message == NBP_MEMORY_NULL_POINTER) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for memory allocation.
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_OUT_OF_MEMORY,
                "could not duplicate the message"
            );
            break;
            // LCOV_EXCL_STOP
        }

        return message;
    } while (0);

    if (message != NBP_MEMORY_NULL_POINTER) {
        NBP_MEMORY_FREE(message);
    }

    return NBP_MEMORY_NULL_POINTER;
}

static void nbp_linux_printer_add_message(nbp_test_details_t* test, char* msg)
{
    nbp_linux_printer_data_t* data = nbp_linux_printer_find_printer_test(test);

    if (data == NBP_MEMORY_NULL_POINTER) {
        // these lines are excluded from coverage because it is impossible to
        // not find a test if there's no bug in nbp core.
        // LCOV_EXCL_START
        char errMsg[1024];
        snprintf(errMsg, 1024, "test [%s] not found", NBP_TEST_GET_NAME(test));
        NBP_ERROR_REPORT_CTX_STRING(NBP_ERROR_CODE_INTERNAL_ERROR, errMsg);
        return;
        // LCOV_EXCL_STOP
    }

    if (data->test.messages == NBP_MEMORY_NULL_POINTER) {
        data->test.messages = nbp_linux_printer_create_message(msg);
        data->test.messagesLast = data->test.messages;
    } else {
        data->test.messagesLast->next = nbp_linux_printer_create_message(msg);
        if (data->test.messagesLast->next != NBP_MEMORY_NULL_POINTER) {
            data->test.messagesLast = data->test.messagesLast->next;
        }
    }
}

static void nbp_linux_printer_add_assert_result(nbp_test_details_t* test,
    const char* cond, unsigned int passed, int line, const char* failMsg,
    const char* passMsg)
{
    char buffer[1024] = { 0 };

    if (passed == NBP_ASSERT_STATUS_PASSED) {
        if (passMsg == NBP_PRINTER_NO_SUCCESS_MESSAGE) {
            return;
        }

        snprintf(
            buffer,
            1024,
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN
                "%s (%s) (%d)"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            cond,
            passMsg,
            line
        );
    } else {
        if (failMsg == NBP_PRINTER_NO_FAILURE_MESSAGE) {
            snprintf(
                buffer,
                1024,
                NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
                    "%s (%d)"
                NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
                cond,
                line
            );
        } else {
            snprintf(
                buffer,
                1024,
                NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
                    "%s (%s) (%d)"
                NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
                cond,
                failMsg,
                line
            );
        }
    }

    nbp_linux_printer_add_message(test, buffer);
}

static void nbp_linux_printer_print_depth(unsigned int depth)
{
    while (depth-- > 0) {
        printf("    ");
    }
}

static void nbp_linux_printer_print_test(nbp_linux_printer_test_t* test)
{
    unsigned int state = NBP_TEST_GET_STATE(test->test);
    unsigned int depth = NBP_TEST_GET_DEPTH(test->test);

    nbp_linux_printer_print_depth(depth);
    if (state == NBP_TEST_STATE_PASSED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_TEST_GET_NAME(test->test)
        );
    } else if (state == NBP_TEST_STATE_FAILED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_TEST_GET_NAME(test->test)
        );
    } else if (state == NBP_TEST_STATE_SKIPPED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_YELLOW
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_TEST_GET_NAME(test->test)
        );
    } else {
        printf("%s\n", NBP_TEST_GET_NAME(test->test));
    }

    nbp_linux_printer_messages_list_t* msg = test->messages;
    depth++;

    while (msg != NBP_MEMORY_NULL_POINTER) {
        nbp_linux_printer_print_depth(depth);
        printf("%s", msg->message);
        msg = msg->next;
    }
}

static void nbp_linux_printer_print_module(nbp_linux_printer_module_t* module)
{
    unsigned int state = NBP_MODULE_GET_STATE(module->module);

    nbp_linux_printer_print_depth(NBP_MODULE_GET_DEPTH(module->module));
    if (state == NBP_MODULE_STATE_PASSED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_MODULE_GET_NAME(module->module)
        );
    } else if (state == NBP_MODULE_STATE_FAILED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_MODULE_GET_NAME(module->module)
        );
    } else if (state == NBP_MODULE_STATE_SKIPPED) {
        printf(
            NBP_LINUX_PRINTER_PRIVATE_COLOR_YELLOW
                "%s"
            NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
            NBP_MODULE_GET_NAME(module->module)
        );
    } else {
        printf("%s\n", NBP_MODULE_GET_NAME(module->module));
    }
}

static void nbp_linux_printer_print_data()
{
    nbp_linux_printer_data_t* data = nbpLinuxPrinterData;

    while (data != NBP_MEMORY_NULL_POINTER) {
        if (data->type == NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_MODULE) {
            nbp_linux_printer_print_module(&data->module);
        } else if (data->type == NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_TEST) {
            nbp_linux_printer_print_test(&data->test);
        }

        data = data->next;
    }
}

NBP_PRINTER_CALLBACK_INIT(nbp_linux_printer_init)
{
    nbpLinuxPrinterData                 = NBP_MEMORY_NULL_POINTER;
    nbpLinuxPrinterDataLast             = NBP_MEMORY_NULL_POINTER;
    nbpLinuxPrinterModulesNum           = 0;
    nbpLinuxPrinterTestsNum             = 0;
    nbpLinuxPrinterCompletedTestsNum    = 0;
    NBP_LINUX_PRINTER_PRIVATE_MUTEX_INIT(nbpLinuxPrinterMutex);
}

NBP_PRINTER_CALLBACK_UNINIT(nbp_linux_printer_uninit)
{
    nbp_linux_printer_data_t* tmp = NBP_MEMORY_NULL_POINTER;
    while (nbpLinuxPrinterData != NBP_MEMORY_NULL_POINTER) {
        tmp = nbpLinuxPrinterData;
        nbpLinuxPrinterData = tmp->next;

        tmp->next = NBP_MEMORY_NULL_POINTER;

        if (tmp->type == NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_TEST) {
            nbp_linux_printer_delete_messages(tmp->test.messages);
        }

        NBP_MEMORY_FREE(tmp);
    }

    nbpLinuxPrinterDataLast = NBP_MEMORY_NULL_POINTER;

    NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNINIT(nbpLinuxPrinterMutex);
}

NBP_PRINTER_CALLBACK_REPORT_ERROR(nbp_linux_printer_report_error)
{
    NBP_LINUX_PRINTER_PRIVATE_MUTEX_LOCK(nbpLinuxPrinterMutex);

    switch (NBP_ERROR_GET_CONTEXT_TYPE(NBP_PRINTER_GET_ERROR())) {
        case NBP_ERROR_CONTEXT_STRING:
            printf(
                "\n" NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
                    "[error] code = %d, line = %d, file = %s, message = %s"
                NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
                NBP_ERROR_GET_CODE(NBP_PRINTER_GET_ERROR()),
                NBP_ERROR_GET_LINE(NBP_PRINTER_GET_ERROR()),
                NBP_ERROR_GET_FILENAME(NBP_PRINTER_GET_ERROR()),
                NBP_ERROR_GET_CONTEXT_STRING(NBP_PRINTER_GET_ERROR())
            );
            break;
        case NBP_ERROR_CONTEXT_EMPTY:
        case NBP_ERROR_CONTEXT_CUSTOM:
        default:
            printf(
                "\n" NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
                    "[error] code = %d, line = %d, file = %s"
                NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL "\n",
                NBP_ERROR_GET_CODE(NBP_PRINTER_GET_ERROR()),
                NBP_ERROR_GET_LINE(NBP_PRINTER_GET_ERROR()),
                NBP_ERROR_GET_FILENAME(NBP_PRINTER_GET_ERROR())
            );
            break;
    }

    NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNLOCK(nbpLinuxPrinterMutex);
}

NBP_PRINTER_CALLBACK_HANDLE_VERSION_COMMAND(nbp_linux_printer_handle_version_command)
{
    printf("%s\n", NBP_VERSION_STR);
}

NBP_PRINTER_CALLBACK_TEST_COMPLETED(nbp_linux_printer_test_completed)
{
    NBP_LINUX_PRINTER_PRIVATE_MUTEX_LOCK(nbpLinuxPrinterMutex);

    nbpLinuxPrinterCompletedTestsNum++;

    printf(
        NBP_LINUX_PRINTER_PRIVATE_CLEAR_LINE "Running... %u/%u",
        nbpLinuxPrinterCompletedTestsNum,
        nbpLinuxPrinterTestsNum
    );
    fflush(stdout);

    NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNLOCK(nbpLinuxPrinterMutex);
}

NBP_PRINTER_CALLBACK_BEFORE_RUN(nbp_linux_printer_before_run)
{
    nbpLinuxPrinterTestsNum   = NBP_MODULE_GET_NUMBER_OF_TESTS(NBP_MODULE_THIS);
    nbpLinuxPrinterModulesNum =
        NBP_MODULE_GET_NUMBER_OF_MODULES(NBP_MODULE_THIS) + 1;

    printf("Running...");
    fflush(stdout);
}

NBP_PRINTER_CALLBACK_AFTER_RUN(nbp_linux_printer_after_run)
{
    unsigned int numPassedModules;
    unsigned int numFailedModules;
    unsigned int numSkippedModules;
    unsigned int moduleState;
    unsigned int numAsserts;
    unsigned int numPassedAsserts;
    unsigned int numFailedAsserts;

    printf(NBP_LINUX_PRINTER_PRIVATE_CLEAR_LINE);
    nbp_linux_printer_print_data();

    numPassedModules  = NBP_MODULE_GET_NUMBER_OF_PASSED_MODULES(NBP_MODULE_THIS);
    numFailedModules  = NBP_MODULE_GET_NUMBER_OF_FAILED_MODULES(NBP_MODULE_THIS);
    numSkippedModules = NBP_MODULE_GET_NUMBER_OF_SKIPPED_MODULES(NBP_MODULE_THIS);
    moduleState       = NBP_MODULE_GET_STATE(NBP_MODULE_THIS);

    if (moduleState == NBP_MODULE_STATE_PASSED) {
        numPassedModules++;
    } else if (moduleState == NBP_MODULE_STATE_FAILED) {
        numFailedModules++;
    }

    // print modules stats
    printf(
        "Passed  modules: %s%u%s/%u\n"
        "Failed  modules: %s%u%s/%u\n"
        "Skipped modules: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        numPassedModules,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterModulesNum,

        numFailedModules == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        numFailedModules,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterModulesNum,

        numSkippedModules == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_YELLOW,
        numSkippedModules,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterModulesNum
    );

    // print tests stats
    printf(
        "Passed  tests: %s%u%s/%u\n"
        "Failed  tests: %s%u%s/%u\n"
        "Skipped tests: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        NBP_MODULE_GET_NUMBER_OF_PASSED_TESTS(NBP_MODULE_THIS),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterTestsNum,

        NBP_MODULE_GET_NUMBER_OF_FAILED_TESTS(NBP_MODULE_THIS) == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        NBP_MODULE_GET_NUMBER_OF_FAILED_TESTS(NBP_MODULE_THIS),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterTestsNum,

        NBP_MODULE_GET_NUMBER_OF_SKIPPED_TESTS(NBP_MODULE_THIS) == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_YELLOW,
        NBP_MODULE_GET_NUMBER_OF_SKIPPED_TESTS(NBP_MODULE_THIS),
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        nbpLinuxPrinterTestsNum
    );

    // print checks stats

    numAsserts = NBP_MODULE_GET_NUMBER_OF_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_NON_FATAL
    );
    numPassedAsserts = NBP_MODULE_GET_NUMBER_OF_PASSED_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_NON_FATAL
    );
    numFailedAsserts = NBP_MODULE_GET_NUMBER_OF_FAILED_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_NON_FATAL
    );

    printf(
        "Passed non-fatal asserts: %s%u%s/%u\n"
        "Failed non-fatal asserts: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        numPassedAsserts,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        numAsserts,

        numFailedAsserts == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        numFailedAsserts,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        numAsserts
    );

    // print test asserts stats

    numAsserts = NBP_MODULE_GET_NUMBER_OF_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL_FOR_TEST
    );
    numPassedAsserts = NBP_MODULE_GET_NUMBER_OF_PASSED_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL_FOR_TEST
    );
    numFailedAsserts = NBP_MODULE_GET_NUMBER_OF_FAILED_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL_FOR_TEST
    );

    printf(
        "Passed fatal-for-test asserts: %s%u%s/%u\n"
        "Failed fatal-for-test asserts: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        numPassedAsserts,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        numAsserts,

        numFailedAsserts == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        numFailedAsserts,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        numAsserts
    );

    // print module asserts stats

    numAsserts = NBP_MODULE_GET_NUMBER_OF_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL_FOR_MODULE
    );
    numPassedAsserts = NBP_MODULE_GET_NUMBER_OF_PASSED_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL_FOR_MODULE
    );
    numFailedAsserts = NBP_MODULE_GET_NUMBER_OF_FAILED_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL_FOR_MODULE
    );

    printf(
        "Passed fatal-for-module asserts: %s%u%s/%u\n"
        "Failed fatal-for-module asserts: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        numPassedAsserts,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        numAsserts,

        numFailedAsserts == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        numFailedAsserts,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        numAsserts
    );

    // print asserts stats

    numAsserts = NBP_MODULE_GET_NUMBER_OF_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL
    );
    numPassedAsserts = NBP_MODULE_GET_NUMBER_OF_PASSED_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL
    );
    numFailedAsserts = NBP_MODULE_GET_NUMBER_OF_FAILED_ASSERTS(
        NBP_MODULE_THIS,
        NBP_ASSERT_FATAL
    );

    printf(
        "Passed fatal asserts: %s%u%s/%u\n"
        "Failed fatal asserts: %s%u%s/%u\n",

        NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN,
        numPassedAsserts,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        numAsserts,

        numFailedAsserts == 0 ?
            NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN :
            NBP_LINUX_PRINTER_PRIVATE_COLOR_RED,
        numFailedAsserts,
        NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL,
        numAsserts
    );
}

NBP_PRINTER_CALLBACK_RUN_TEST(nbp_linux_printer_run_test)
{
    if (nbpLinuxPrinterData == NBP_MEMORY_NULL_POINTER) {
        nbpLinuxPrinterData = nbp_linux_printer_create_data_from_test(
            NBP_TEST_THIS
        );
        nbpLinuxPrinterDataLast = nbpLinuxPrinterData;
    } else {
        nbpLinuxPrinterDataLast->next = nbp_linux_printer_create_data_from_test(
            NBP_TEST_THIS
        );
        if (nbpLinuxPrinterDataLast->next != NBP_MEMORY_NULL_POINTER) {
            nbpLinuxPrinterDataLast = nbpLinuxPrinterDataLast->next;
        }
    }
}

NBP_PRINTER_CALLBACK_RUN_MODULE(nbp_linux_printer_run_module)
{
    if (nbpLinuxPrinterData == NBP_MEMORY_NULL_POINTER) {
        nbpLinuxPrinterData = nbp_linux_printer_create_data_from_module(
            NBP_MODULE_THIS
        );
        nbpLinuxPrinterDataLast = nbpLinuxPrinterData;
    } else {
        nbpLinuxPrinterDataLast->next = nbp_linux_printer_create_data_from_module(
            NBP_MODULE_THIS
        );
        if (nbpLinuxPrinterDataLast->next != NBP_MEMORY_NULL_POINTER) {
            nbpLinuxPrinterDataLast = nbpLinuxPrinterDataLast->next;
        }
    }
}

NBP_PRINTER_CALLBACK_ASSERT_RESULT(nbp_linux_printer_assert_result)
{
    nbp_linux_printer_add_assert_result(
        NBP_TEST_THIS,
        NBP_PRINTER_GET_CONDITION(),
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_LINE_NUMBER(),
        NBP_PRINTER_GET_ASSERT_FAILURE_MESSAGE(),
        NBP_PRINTER_GET_ASSERT_SUCCESS_MESSAGE()
    );
}

NBP_PRINTER_CALLBACK_ASSERT_TYPE_OP_RESULT(nbp_linux_printer_assert_type_op_result)
{
    char buff[1024] = { 0 };

    switch (NBP_PRINTER_GET_VALUE_TYPE()) {
        case NBP_PRINTER_TYPE_NONE:
            snprintf(
                buff,
                1024,
                "%s %s %s",
                NBP_PRINTER_GET_FIRST_VALUE(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE()
            );
            break;
        case NBP_PRINTER_TYPE_CHAR:
            snprintf(
                buff,
                1024,
                "%c %s %c",
                NBP_PRINTER_GET_FIRST_VALUE_AS_CHAR(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_CHAR()
            );
            break;
        case NBP_PRINTER_TYPE_SHORT:
            snprintf(
                buff,
                1024,
                "%hd %s %hd",
                NBP_PRINTER_GET_FIRST_VALUE_AS_SHORT(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_SHORT()
            );
            break;
        case NBP_PRINTER_TYPE_USHORT:
            snprintf(
                buff,
                1024,
                "%hu %s %hu",
                NBP_PRINTER_GET_FIRST_VALUE_AS_USHORT(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_USHORT()
            );
            break;
        case NBP_PRINTER_TYPE_INT:
            snprintf(
                buff,
                1024,
                "%d %s %d",
                NBP_PRINTER_GET_FIRST_VALUE_AS_INT(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_INT()
            );
            break;
        case NBP_PRINTER_TYPE_UINT:
            snprintf(
                buff,
                1024,
                "%u %s %u",
                NBP_PRINTER_GET_FIRST_VALUE_AS_UINT(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_UINT()
            );
            break;
        case NBP_PRINTER_TYPE_LONG:
            snprintf(
                buff,
                1024,
                "%ld %s %ld",
                NBP_PRINTER_GET_FIRST_VALUE_AS_LONG(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_LONG()
            );
            break;
        case NBP_PRINTER_TYPE_ULONG:
            snprintf(
                buff,
                1024,
                "%lu %s %lu",
                NBP_PRINTER_GET_FIRST_VALUE_AS_ULONG(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_ULONG()
            );
            break;
        case NBP_PRINTER_TYPE_LLONG:
            snprintf(
                buff,
                1024,
                "%lld %s %lld",
                NBP_PRINTER_GET_FIRST_VALUE_AS_LLONG(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_LLONG()
            );
            break;
        case NBP_PRINTER_TYPE_ULLONG:
            snprintf(
                buff,
                1024,
                "%llu %s %llu",
                NBP_PRINTER_GET_FIRST_VALUE_AS_ULLONG(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_ULLONG()
            );
            break;
        case NBP_PRINTER_TYPE_FLOAT:
            snprintf(
                buff,
                1024,
                "%f %s %f",
                NBP_PRINTER_GET_FIRST_VALUE_AS_FLOAT(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_FLOAT()
            );
            break;
        case NBP_PRINTER_TYPE_DOUBLE:
            snprintf(
                buff,
                1024,
                "%f %s %f",
                NBP_PRINTER_GET_FIRST_VALUE_AS_DOUBLE(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_DOUBLE()
            );
            break;
        case NBP_PRINTER_TYPE_LDOUBLE:
            snprintf(
                buff,
                1024,
                "%Lf %s %Lf",
                NBP_PRINTER_GET_FIRST_VALUE_AS_LDOUBLE(),
                NBP_PRINTER_GET_OPERATOR_STR(),
                NBP_PRINTER_GET_SECOND_VALUE_AS_LDOUBLE()
            );
            break;
        default:
            snprintf(
                buff,
                1024,
                "unknown value type"
            );
            break;
    }

    nbp_linux_printer_add_assert_result(
        NBP_TEST_THIS,
        buff,
        NBP_PRINTER_GET_ASSERT_STATUS(),
        NBP_PRINTER_GET_LINE_NUMBER(),
        NBP_PRINTER_GET_ASSERT_FAILURE_MESSAGE(),
        NBP_PRINTER_GET_ASSERT_SUCCESS_MESSAGE()
    );
}

NBP_PRINTER(
    nbpDefaultPrinter,
    NBP_PRINTER_CALLBACKS(
        NBP_PRINTER_CALLBACK_INIT(nbp_linux_printer_init),
        NBP_PRINTER_CALLBACK_UNINIT(nbp_linux_printer_uninit),
        NBP_PRINTER_CALLBACK_REPORT_ERROR(nbp_linux_printer_report_error),
        NBP_PRINTER_CALLBACK_HANDLE_VERSION_COMMAND(nbp_linux_printer_handle_version_command),
        NBP_PRINTER_CALLBACK_TEST_COMPLETED(nbp_linux_printer_test_completed),
        NBP_PRINTER_CALLBACK_BEFORE_RUN(nbp_linux_printer_before_run),
        NBP_PRINTER_CALLBACK_AFTER_RUN(nbp_linux_printer_after_run),
        NBP_PRINTER_CALLBACK_RUN_TEST(nbp_linux_printer_run_test),
        NBP_PRINTER_CALLBACK_RUN_MODULE(nbp_linux_printer_run_module),
        NBP_PRINTER_CALLBACK_ASSERT_RESULT(nbp_linux_printer_assert_result),
        NBP_PRINTER_CALLBACK_ASSERT_TYPE_OP_RESULT(nbp_linux_printer_assert_type_op_result),
    )
);

#undef NBP_LINUX_PRINTER_PRIVATE_COLOR_NORMAL
#undef NBP_LINUX_PRINTER_PRIVATE_COLOR_RED
#undef NBP_LINUX_PRINTER_PRIVATE_COLOR_GREEN
#undef NBP_LINUX_PRINTER_PRIVATE_COLOR_YELLOW

#undef NBP_LINUX_PRINTER_PRIVATE_CLEAR_LINE

#undef NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_UNKNOWN
#undef NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_TEST
#undef NBP_LINUX_PRINTER_PRIVATE_PRINTER_TYPE_MODULE

#undef NBP_LINUX_PRINTER_PRIVATE_GENERATE_CONDITION

#undef NBP_LINUX_PRINTER_PRIVATE_DECLARE_MUTEX
#undef NBP_LINUX_PRINTER_PRIVATE_MUTEX_INIT
#undef NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNINIT
#undef NBP_LINUX_PRINTER_PRIVATE_MUTEX_LOCK
#undef NBP_LINUX_PRINTER_PRIVATE_MUTEX_UNLOCK

#endif // end if NBP_OS_LINUX

/*
 * Default nbp printer for Windows
 */
#ifdef NBP_OS_WINDOWS
#error "Not supported"
#endif // end if NBP_OS_WINDOWS

/*
 * Default nbp printer for Mac
 */
#ifdef NBP_OS_MAC
#error "Not supported"
#endif // end if NBP_OS_MAC

/*
 * We don't have default printer for custom OS
 */
#ifdef NBP_OS_CUSTOM
#error "Default printer is not supported on custom OS"
#endif

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_DEFAULT_PRINTER

#endif // end if NBP_LIBRARY_H
