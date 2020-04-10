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

#ifndef NBP_PRIVATE_API_PRINTER_H
#define NBP_PRIVATE_API_PRINTER_H

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_INIT(func)                                            \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        void                                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_INIT(func)                                        \
    .init = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_INIT                                               \
    .init = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_UNINIT(func)                                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        void                                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_UNINIT(func)                                      \
    .uninit = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_UNINIT                                             \
    .uninit = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_HANDLE_ERROR(func)                                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_error_t err                             \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_HANDLE_ERROR(func)                                \
    .handleError = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_HANDLE_ERROR                                       \
    .handleError = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_HANDLE_VERSION_COMMAND(func)                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_HANDLE_VERSION_COMMAND(func)                      \
    .handleVersionCommand = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_HANDLE_VERSION_COMMAND                             \
    .handleVersionCommand = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_STARTED(func)                                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test                    \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_STARTED(func)                                \
    .testStarted = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_STARTED                                       \
    .testStarted = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_COMPLETED(func)                                  \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test                    \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_COMPLETED(func)                              \
    .testCompleted = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_COMPLETED                                     \
    .testCompleted = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_STARTED(func)                                  \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* module                \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_STARTED(func)                              \
    .moduleStarted = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_STARTED                                     \
    .moduleStarted = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_COMPLETED(func)                                \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* module                \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_COMPLETED(func)                            \
    .moduleCompleted = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_COMPLETED                                   \
    .moduleCompleted = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_BEFORE_RUN(func)                                      \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int modulesNum,                    \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int testsNum                       \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_BEFORE_RUN(func)                                  \
    .beforeRun = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_BEFORE_RUN                                         \
    .beforeRun = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_AFTER_RUN(func)                                       \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int passedModulesNum,              \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int failedModulesNum,              \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int skippedModulesNum,             \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int passedTestsNum,                \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int failedTestsNum,                \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int skippedTestsNum,               \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int checksNum,                     \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int passedChecksNum,               \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int failedChecksNum,               \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int testAssertsNum,                \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int passedTestAssertsNum,          \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int failedTestAssertsNum,          \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int moduleAssertsNum,              \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int passedModuleAssertsNum,        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int failedModuleAssertsNum,        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int assertsNum,                    \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int passedAssertsNum,              \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int failedAssertsNum               \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_AFTER_RUN(func)                                   \
    .afterRun = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_AFTER_RUN                                          \
    .afterRun = NBP_NULL_POINTER


/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_SCHEDULING_TEST(func)                                 \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test                    \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_SCHEDULING_TEST(func)                             \
    .schedulingTest = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_SCHEDULING_TEST                                    \
    .schedulingTest = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_BEFORE_SCHEDULING_MODULE(func)                        \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* module                \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_BEFORE_SCHEDULING_MODULE(func)                    \
    .beforeSchedulingModule = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_BEFORE_SCHEDULING_MODULE                           \
    .beforeSchedulingModule = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_AFTER_SCHEDULING_MODULE(func)                         \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* module                \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_AFTER_SCHEDULING_MODULE(func)                     \
    .afterSchedulingModule = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_AFTER_SCHEDULING_MODULE                            \
    .afterSchedulingModule = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_RESULT(func)                                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* cond,                           \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_RESULT(func)                                \
    .checkResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_RESULT                                       \
    .checkResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_OP_RESULT(func)                                 \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* a,                              \
        NBP_MAYBE_UNUSED_PARAMETER const char* b,                              \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_OP_RESULT(func)                             \
    .checkOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_OP_RESULT                                    \
    .checkOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_CHAR_OP_RESULT(func)                            \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER char a,                                     \
        NBP_MAYBE_UNUSED_PARAMETER char b,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_CHAR_OP_RESULT(func)                        \
    .checkCharOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_CHAR_OP_RESULT                               \
    .checkCharOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_SHORT_OP_RESULT(func)                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER short int a,                                \
        NBP_MAYBE_UNUSED_PARAMETER short int b,                                \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_SHORT_OP_RESULT(func)                       \
    .checkShortOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_SHORT_OP_RESULT                              \
    .checkShortOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_USHORT_OP_RESULT(func)                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned short int a,                       \
        NBP_MAYBE_UNUSED_PARAMETER unsigned short int b,                       \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_USHORT_OP_RESULT(func)                      \
    .checkUShortOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_USHORT_OP_RESULT                             \
    .checkUShortOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_INT_OP_RESULT(func)                             \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER int a,                                      \
        NBP_MAYBE_UNUSED_PARAMETER int b,                                      \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_INT_OP_RESULT(func)                         \
    .checkIntOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_INT_OP_RESULT                                \
    .checkIntOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_UINT_OP_RESULT(func)                            \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int a,                             \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int b,                             \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_UINT_OP_RESULT(func)                        \
    .checkUIntOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_UINT_OP_RESULT                               \
    .checkUIntOpResult = NBP_NULL_POINTER

    /*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_LONG_OP_RESULT(func)                            \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER long int a,                                 \
        NBP_MAYBE_UNUSED_PARAMETER long int b,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_LONG_OP_RESULT(func)                        \
    .checkLongOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_LONG_OP_RESULT                               \
    .checkLongOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_ULONG_OP_RESULT(func)                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long int a,                        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long int b,                        \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_ULONG_OP_RESULT(func)                       \
    .checkULongOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_ULONG_OP_RESULT                              \
    .checkULongOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_LLONG_OP_RESULT(func)                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER long long int a,                            \
        NBP_MAYBE_UNUSED_PARAMETER long long int b,                            \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_LLONG_OP_RESULT(func)                       \
    .checkLLongOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_LLONG_OP_RESULT                              \
    .checkLLongOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_ULLONG_OP_RESULT(func)                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long long int a,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long long int b,                   \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_ULLONG_OP_RESULT(func)                      \
    .checkULLongOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_ULLONG_OP_RESULT                             \
    .checkULLongOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_FLOAT_OP_RESULT(func)                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER float a,                                    \
        NBP_MAYBE_UNUSED_PARAMETER float b,                                    \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_FLOAT_OP_RESULT(func)                       \
    .checkFloatOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_FLOAT_OP_RESULT                              \
    .checkFloatOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_DOUBLE_OP_RESULT(func)                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER double a,                                   \
        NBP_MAYBE_UNUSED_PARAMETER double b,                                   \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_DOUBLE_OP_RESULT(func)                      \
    .checkDoubleOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_DOUBLE_OP_RESULT                             \
    .checkDoubleOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_LDOUBLE_OP_RESULT(func)                         \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER long double a,                              \
        NBP_MAYBE_UNUSED_PARAMETER long double b,                              \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_LDOUBLE_OP_RESULT(func)                     \
    .checkLDoubleOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_LDOUBLE_OP_RESULT                            \
    .checkLDoubleOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_RESULT(func)                              \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* cond,                           \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_RESULT(func)                          \
    .testAssertResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_RESULT                                 \
    .testAssertResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_OP_RESULT(func)                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* a,                              \
        NBP_MAYBE_UNUSED_PARAMETER const char* b,                              \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_OP_RESULT(func)                       \
    .testAssertOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_OP_RESULT                              \
    .testAssertOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_CHAR_OP_RESULT(func)                      \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER char a,                                     \
        NBP_MAYBE_UNUSED_PARAMETER char b,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_CHAR_OP_RESULT(func)                  \
    .testAssertCharOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_CHAR_OP_RESULT                         \
    .testAssertCharOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_SHORT_OP_RESULT(func)                     \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER short int a,                                \
        NBP_MAYBE_UNUSED_PARAMETER short int b,                                \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_SHORT_OP_RESULT(func)                 \
    .testAssertShortOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_SHORT_OP_RESULT                        \
    .testAssertShortOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_USHORT_OP_RESULT(func)                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned short int a,                       \
        NBP_MAYBE_UNUSED_PARAMETER unsigned short int b,                       \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_USHORT_OP_RESULT(func)                \
    .testAssertUShortOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_USHORT_OP_RESULT                       \
    .testAssertUShortOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_INT_OP_RESULT(func)                       \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER int a,                                      \
        NBP_MAYBE_UNUSED_PARAMETER int b,                                      \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_INT_OP_RESULT(func)                   \
    .testAssertIntOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_INT_OP_RESULT                          \
    .testAssertIntOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_UINT_OP_RESULT(func)                      \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int a,                             \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int b,                             \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_UINT_OP_RESULT(func)                  \
    .testAssertUIntOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_UINT_OP_RESULT                         \
    .testAssertUIntOpResult = NBP_NULL_POINTER

    /*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_LONG_OP_RESULT(func)                      \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER long int a,                                 \
        NBP_MAYBE_UNUSED_PARAMETER long int b,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_LONG_OP_RESULT(func)                  \
    .testAssertLongOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_LONG_OP_RESULT                         \
    .testAssertLongOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_ULONG_OP_RESULT(func)                     \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long int a,                        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long int b,                        \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_ULONG_OP_RESULT(func)                 \
    .testAssertULongOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_ULONG_OP_RESULT                        \
    .testAssertULongOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_LLONG_OP_RESULT(func)                     \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER long long int a,                            \
        NBP_MAYBE_UNUSED_PARAMETER long long int b,                            \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_LLONG_OP_RESULT(func)                 \
    .testAssertLLongOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_LLONG_OP_RESULT                        \
    .testAssertLLongOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_ULLONG_OP_RESULT(func)                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long long int a,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long long int b,                   \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_ULLONG_OP_RESULT(func)                \
    .testAssertULLongOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_ULLONG_OP_RESULT                       \
    .testAssertULLongOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_FLOAT_OP_RESULT(func)                     \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER float a,                                    \
        NBP_MAYBE_UNUSED_PARAMETER float b,                                    \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_FLOAT_OP_RESULT(func)                 \
    .testAssertFloatOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_FLOAT_OP_RESULT                        \
    .testAssertFloatOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_DOUBLE_OP_RESULT(func)                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER double a,                                   \
        NBP_MAYBE_UNUSED_PARAMETER double b,                                   \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_DOUBLE_OP_RESULT(func)                \
    .testAssertDoubleOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_DOUBLE_OP_RESULT                       \
    .testAssertDoubleOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_LDOUBLE_OP_RESULT(func)                   \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER long double a,                              \
        NBP_MAYBE_UNUSED_PARAMETER long double b,                              \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_LDOUBLE_OP_RESULT(func)               \
    .testAssertLDoubleOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_LDOUBLE_OP_RESULT                      \
    .testAssertLDoubleOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_RESULT(func)                            \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* cond,                           \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_RESULT(func)                        \
    .moduleAssertResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_RESULT                               \
    .moduleAssertResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_OP_RESULT(func)                         \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* a,                              \
        NBP_MAYBE_UNUSED_PARAMETER const char* b,                              \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_OP_RESULT(func)                     \
    .moduleAssertOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_OP_RESULT                            \
    .moduleAssertOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_CHAR_OP_RESULT(func)                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER char a,                                     \
        NBP_MAYBE_UNUSED_PARAMETER char b,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_CHAR_OP_RESULT(func)                \
    .moduleAssertCharOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_CHAR_OP_RESULT                       \
    .moduleAssertCharOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_SHORT_OP_RESULT(func)                   \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER short int a,                                \
        NBP_MAYBE_UNUSED_PARAMETER short int b,                                \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_SHORT_OP_RESULT(func)               \
    .moduleAssertShortOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_SHORT_OP_RESULT                      \
    .moduleAssertShortOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_USHORT_OP_RESULT(func)                  \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned short int a,                       \
        NBP_MAYBE_UNUSED_PARAMETER unsigned short int b,                       \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_USHORT_OP_RESULT(func)              \
    .moduleAssertUShortOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_USHORT_OP_RESULT                     \
    .moduleAssertUShortOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_INT_OP_RESULT(func)                     \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER int a,                                      \
        NBP_MAYBE_UNUSED_PARAMETER int b,                                      \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_INT_OP_RESULT(func)                 \
    .moduleAssertIntOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_INT_OP_RESULT                        \
    .moduleAssertIntOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_UINT_OP_RESULT(func)                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int a,                             \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int b,                             \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_UINT_OP_RESULT(func)                \
    .moduleAssertUIntOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_UINT_OP_RESULT                       \
    .moduleAssertUIntOpResult = NBP_NULL_POINTER

    /*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_LONG_OP_RESULT(func)                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER long int a,                                 \
        NBP_MAYBE_UNUSED_PARAMETER long int b,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_LONG_OP_RESULT(func)                \
    .moduleAssertLongOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_LONG_OP_RESULT                       \
    .moduleAssertLongOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_ULONG_OP_RESULT(func)                   \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long int a,                        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long int b,                        \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_ULONG_OP_RESULT(func)               \
    .moduleAssertULongOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_ULONG_OP_RESULT                      \
    .moduleAssertULongOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_LLONG_OP_RESULT(func)                   \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER long long int a,                            \
        NBP_MAYBE_UNUSED_PARAMETER long long int b,                            \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_LLONG_OP_RESULT(func)               \
    .moduleAssertLLongOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_LLONG_OP_RESULT                      \
    .moduleAssertLLongOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_ULLONG_OP_RESULT(func)                  \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long long int a,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long long int b,                   \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_ULLONG_OP_RESULT(func)              \
    .moduleAssertULLongOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_ULLONG_OP_RESULT                     \
    .moduleAssertULLongOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_FLOAT_OP_RESULT(func)                   \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER float a,                                    \
        NBP_MAYBE_UNUSED_PARAMETER float b,                                    \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_FLOAT_OP_RESULT(func)               \
    .moduleAssertFloatOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_FLOAT_OP_RESULT                      \
    .moduleAssertFloatOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_DOUBLE_OP_RESULT(func)                  \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER double a,                                   \
        NBP_MAYBE_UNUSED_PARAMETER double b,                                   \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_DOUBLE_OP_RESULT(func)              \
    .moduleAssertDoubleOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_DOUBLE_OP_RESULT                     \
    .moduleAssertDoubleOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_LDOUBLE_OP_RESULT(func)                 \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER long double a,                              \
        NBP_MAYBE_UNUSED_PARAMETER long double b,                              \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_LDOUBLE_OP_RESULT(func)             \
    .moduleAssertLDoubleOpResult =                                             \
        NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_LDOUBLE_OP_RESULT                    \
    .moduleAssertLDoubleOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_RESULT(func)                                   \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* cond,                           \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_RESULT(func)                               \
    .assertResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_RESULT                                      \
    .assertResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_OP_RESULT(func)                                \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* a,                              \
        NBP_MAYBE_UNUSED_PARAMETER const char* b,                              \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_OP_RESULT(func)                            \
    .assertOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_OP_RESULT                                   \
    .assertOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_CHAR_OP_RESULT(func)                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER char a,                                     \
        NBP_MAYBE_UNUSED_PARAMETER char b,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_CHAR_OP_RESULT(func)                       \
    .assertCharOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_CHAR_OP_RESULT                              \
    .assertCharOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_SHORT_OP_RESULT(func)                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER short int a,                                \
        NBP_MAYBE_UNUSED_PARAMETER short int b,                                \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_SHORT_OP_RESULT(func)                      \
    .assertShortOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_SHORT_OP_RESULT                             \
    .assertShortOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_USHORT_OP_RESULT(func)                         \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned short int a,                       \
        NBP_MAYBE_UNUSED_PARAMETER unsigned short int b,                       \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_USHORT_OP_RESULT(func)                     \
    .assertUShortOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_USHORT_OP_RESULT                            \
    .assertUShortOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_INT_OP_RESULT(func)                            \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER int a,                                      \
        NBP_MAYBE_UNUSED_PARAMETER int b,                                      \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_INT_OP_RESULT(func)                        \
    .assertIntOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_INT_OP_RESULT                               \
    .assertIntOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_UINT_OP_RESULT(func)                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int a,                             \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int b,                             \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_UINT_OP_RESULT(func)                       \
    .assertUIntOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_UINT_OP_RESULT                              \
    .assertUIntOpResult = NBP_NULL_POINTER

    /*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_LONG_OP_RESULT(func)                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER long int a,                                 \
        NBP_MAYBE_UNUSED_PARAMETER long int b,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_LONG_OP_RESULT(func)                       \
    .assertLongOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_LONG_OP_RESULT                              \
    .assertLongOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_ULONG_OP_RESULT(func)                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long int a,                        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long int b,                        \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_ULONG_OP_RESULT(func)                      \
    .assertULongOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_ULONG_OP_RESULT                             \
    .assertULongOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_LLONG_OP_RESULT(func)                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER long long int a,                            \
        NBP_MAYBE_UNUSED_PARAMETER long long int b,                            \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_LLONG_OP_RESULT(func)                      \
    .assertLLongOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_LLONG_OP_RESULT                             \
    .assertLLongOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_ULLONG_OP_RESULT(func)                         \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long long int a,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long long int b,                   \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_ULLONG_OP_RESULT(func)                     \
    .assertULLongOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_ULLONG_OP_RESULT                            \
    .assertULLongOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_FLOAT_OP_RESULT(func)                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER float a,                                    \
        NBP_MAYBE_UNUSED_PARAMETER float b,                                    \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_FLOAT_OP_RESULT(func)                      \
    .assertFloatOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_FLOAT_OP_RESULT                             \
    .assertFloatOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_DOUBLE_OP_RESULT(func)                         \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER double a,                                   \
        NBP_MAYBE_UNUSED_PARAMETER double b,                                   \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_DOUBLE_OP_RESULT(func)                     \
    .assertDoubleOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_DOUBLE_OP_RESULT                            \
    .assertDoubleOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_LDOUBLE_OP_RESULT(func)                        \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* test,                   \
        NBP_MAYBE_UNUSED_PARAMETER long double a,                              \
        NBP_MAYBE_UNUSED_PARAMETER long double b,                              \
        NBP_MAYBE_UNUSED_PARAMETER int op,                                     \
        NBP_MAYBE_UNUSED_PARAMETER int passed,                                 \
        NBP_MAYBE_UNUSED_PARAMETER int line,                                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* failMsg,                        \
        NBP_MAYBE_UNUSED_PARAMETER const char* passMsg                         \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_LDOUBLE_OP_RESULT(func)                    \
    .assertLDoubleOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_LDOUBLE_OP_RESULT                           \
    .assertLDoubleOpResult = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_DEFINE_PRINTER(name, ...)                                          \
    nbp_printer_interface_t NBP_PRIVATE_PP_CONCAT(nbpPrinter, name) = {        \
        __VA_ARGS__                                                            \
    }

/*
 * TODO: add docs
 */
#define NBP_GET_PRINTER(name)                                                  \
    & NBP_PRIVATE_PP_CONCAT(nbpPrinter, name)

/*
 * TODO: add docs
 */
#define NBP_INCLUDE_PRINTER(name)                                              \
    extern nbp_printer_interface_t NBP_PRIVATE_PP_CONCAT(nbpPrinter, name)

/*
 * TODO: add docs
 */
#define NBP_USE_PRINTERS(...)                                                  \
    { __VA_ARGS__ }

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_OPERATOR() op

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_OPERATOR_STR() nbp_printer_operator_to_string(op)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_CONDITION() cond

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FIRST_VALUE() a

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SECOND_VALUE() b

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_CHECK_STATUS() passed

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_CHECK_LINE() line

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_TEST_ASSERT_STATUS() passed

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_TEST_ASSERT_LINE() line

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_MODULE_ASSERT_STATUS() passed

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_MODULE_ASSERT_LINE() line

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_ASSERT_STATUS() passed

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_ASSERT_LINE() line

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FAIL_MSG() failMsg

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FAIL_MSG NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_PASS_MSG() passMsg

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_PASS_MSG NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_MODULES_NUM() modulesNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_PASSED_MODULES_NUM() passedModulesNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FAILED_MODULES_NUM() failedModulesNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SKIPPED_MODULES_NUM() skippedModulesNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_TESTS_NUM() testsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_PASSED_TESTS_NUM() passedTestsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FAILED_TESTS_NUM() failedTestsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SKIPPED_TESTS_NUM() skippedTestsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_CHECKS_NUM() checksNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_PASSED_CHECKS_NUM() passedChecksNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FAILED_CHECKS_NUM() failedChecksNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_TEST_ASSERTS_NUM() testAssertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_PASSED_TEST_ASSERTS_NUM() passedTestAssertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FAILED_TEST_ASSERTS_NUM() failedTestAssertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_MODULE_ASSERTS_NUM() moduleAssertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_PASSED_MODULE_ASSERTS_NUM() passedModuleAssertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FAILED_MODULE_ASSERTS_NUM() failedModuleAssertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_ASSERTS_NUM() assertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_PASSED_ASSERTS_NUM() passedAssertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FAILED_ASSERTS_NUM() failedAssertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_ERROR() err

#endif // end if NBP_PRIVATE_API_PRINTER_H

