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
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        void                                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_INIT(func)                                        \
    .init = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_INIT                                               \
    .init = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_UNINIT(func)                                          \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        void                                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_UNINIT(func)                                      \
    .uninit = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_UNINIT                                             \
    .uninit = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_REPORT_ERROR(func)                                    \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_error_t nbpParamError                   \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_REPORT_ERROR(func)                                \
    .reportError = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_REPORT_ERROR                                       \
    .reportError = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_EXIT_TRIGGERED(func)                                  \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamErrorCode                       \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_EXIT_TRIGGERED(func)                              \
    .exitTriggered = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_EXIT_TRIGGERED                                     \
    .exitTriggered = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_HANDLE_VERSION_COMMAND(func)                          \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_HANDLE_VERSION_COMMAND(func)                      \
    .handleVersionCommand = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_HANDLE_VERSION_COMMAND                             \
    .handleVersionCommand = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_STARTED(func)                                    \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest            \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_STARTED(func)                                \
    .testStarted = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_STARTED                                       \
    .testStarted = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_COMPLETED(func)                                  \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest            \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_COMPLETED(func)                              \
    .testCompleted = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_COMPLETED                                     \
    .testCompleted = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_STARTED(func)                                  \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_STARTED(func)                              \
    .moduleStarted = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_STARTED                                     \
    .moduleStarted = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_COMPLETED(func)                                \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_COMPLETED(func)                            \
    .moduleCompleted = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_COMPLETED                                   \
    .moduleCompleted = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_BEFORE_RUN(func)                                      \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamModulesNum,            \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamTestsNum               \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_BEFORE_RUN(func)                                  \
    .beforeRun = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_BEFORE_RUN                                         \
    .beforeRun = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_AFTER_RUN(func)                                       \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamPassedModulesNum,      \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamFailedModulesNum,      \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamSkippedModulesNum,     \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamPassedTestsNum,        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamFailedTestsNum,        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamSkippedTestsNum,       \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamChecksNum,             \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamPassedChecksNum,       \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamFailedChecksNum,       \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamTestAssertsNum,        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamPassedTestAssertsNum,  \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamFailedTestAssertsNum,  \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamModuleAssertsNum,      \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamPassedModuleAssertsNum,\
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamFailedModuleAssertsNum,\
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamAssertsNum,            \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamPassedAssertsNum,      \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamFailedAssertsNum       \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_AFTER_RUN(func)                                   \
    .afterRun = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_AFTER_RUN                                          \
    .afterRun = NBP_MEMORY_NULL_POINTER


/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_SCHEDULING_TEST(func)                                 \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest            \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_SCHEDULING_TEST(func)                             \
    .schedulingTest = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_SCHEDULING_TEST                                    \
    .schedulingTest = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_BEFORE_SCHEDULING_MODULE(func)                        \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_BEFORE_SCHEDULING_MODULE(func)                    \
    .beforeSchedulingModule = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_BEFORE_SCHEDULING_MODULE                           \
    .beforeSchedulingModule = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_AFTER_SCHEDULING_MODULE(func)                         \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_AFTER_SCHEDULING_MODULE(func)                     \
    .afterSchedulingModule = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_AFTER_SCHEDULING_MODULE                            \
    .afterSchedulingModule = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_RESULT(func)                                    \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamCond,                   \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_RESULT(func)                                \
    .checkResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_RESULT                                       \
    .checkResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_OP_RESULT(func)                                 \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamVal1,                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamVal2,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_OP_RESULT(func)                             \
    .checkOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_OP_RESULT                                    \
    .checkOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_CHAR_OP_RESULT(func)                            \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER char nbpParamVal1,                          \
        NBP_MAYBE_UNUSED_PARAMETER char nbpParamVal2,                          \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_CHAR_OP_RESULT(func)                        \
    .checkCharOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_CHAR_OP_RESULT                               \
    .checkCharOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_SHORT_OP_RESULT(func)                           \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER short int nbpParamVal1,                     \
        NBP_MAYBE_UNUSED_PARAMETER short int nbpParamVal2,                     \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_SHORT_OP_RESULT(func)                       \
    .checkShortOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_SHORT_OP_RESULT                              \
    .checkShortOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_USHORT_OP_RESULT(func)                          \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned short int nbpParamVal1,            \
        NBP_MAYBE_UNUSED_PARAMETER unsigned short int nbpParamVal2,            \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_USHORT_OP_RESULT(func)                      \
    .checkUShortOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_USHORT_OP_RESULT                             \
    .checkUShortOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_INT_OP_RESULT(func)                             \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamVal1,                           \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamVal2,                           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_INT_OP_RESULT(func)                         \
    .checkIntOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_INT_OP_RESULT                                \
    .checkIntOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_UINT_OP_RESULT(func)                            \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamVal1,                  \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamVal2,                  \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_UINT_OP_RESULT(func)                        \
    .checkUIntOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_UINT_OP_RESULT                               \
    .checkUIntOpResult = NBP_MEMORY_NULL_POINTER

    /*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_LONG_OP_RESULT(func)                            \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER long int nbpParamVal1,                      \
        NBP_MAYBE_UNUSED_PARAMETER long int nbpParamVal2,                      \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_LONG_OP_RESULT(func)                        \
    .checkLongOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_LONG_OP_RESULT                               \
    .checkLongOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_ULONG_OP_RESULT(func)                           \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long int nbpParamVal1,             \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long int nbpParamVal2,             \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_ULONG_OP_RESULT(func)                       \
    .checkULongOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_ULONG_OP_RESULT                              \
    .checkULongOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_LLONG_OP_RESULT(func)                           \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER long long int nbpParamVal1,                 \
        NBP_MAYBE_UNUSED_PARAMETER long long int nbpParamVal2,                 \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_LLONG_OP_RESULT(func)                       \
    .checkLLongOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_LLONG_OP_RESULT                              \
    .checkLLongOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_ULLONG_OP_RESULT(func)                          \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long long int nbpParamVal1,        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long long int nbpParamVal2,        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_ULLONG_OP_RESULT(func)                      \
    .checkULLongOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_ULLONG_OP_RESULT                             \
    .checkULLongOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_FLOAT_OP_RESULT(func)                           \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER float nbpParamVal1,                         \
        NBP_MAYBE_UNUSED_PARAMETER float nbpParamVal2,                         \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_FLOAT_OP_RESULT(func)                       \
    .checkFloatOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_FLOAT_OP_RESULT                              \
    .checkFloatOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_DOUBLE_OP_RESULT(func)                          \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER double nbpParamVal1,                        \
        NBP_MAYBE_UNUSED_PARAMETER double nbpParamVal2,                        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_DOUBLE_OP_RESULT(func)                      \
    .checkDoubleOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_DOUBLE_OP_RESULT                             \
    .checkDoubleOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_LDOUBLE_OP_RESULT(func)                         \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER long double nbpParamVal1,                   \
        NBP_MAYBE_UNUSED_PARAMETER long double nbpParamVal2,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_LDOUBLE_OP_RESULT(func)                     \
    .checkLDoubleOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_LDOUBLE_OP_RESULT                            \
    .checkLDoubleOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_RESULT(func)                              \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamCond,                   \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_RESULT(func)                          \
    .testAssertResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_RESULT                                 \
    .testAssertResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_OP_RESULT(func)                           \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamVal1,                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamVal2,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_OP_RESULT(func)                       \
    .testAssertOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_OP_RESULT                              \
    .testAssertOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_CHAR_OP_RESULT(func)                      \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER char nbpParamVal1,                          \
        NBP_MAYBE_UNUSED_PARAMETER char nbpParamVal2,                          \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_CHAR_OP_RESULT(func)                  \
    .testAssertCharOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_CHAR_OP_RESULT                         \
    .testAssertCharOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_SHORT_OP_RESULT(func)                     \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER short int nbpParamVal1,                     \
        NBP_MAYBE_UNUSED_PARAMETER short int nbpParamVal2,                     \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_SHORT_OP_RESULT(func)                 \
    .testAssertShortOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_SHORT_OP_RESULT                        \
    .testAssertShortOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_USHORT_OP_RESULT(func)                    \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned short int nbpParamVal1,            \
        NBP_MAYBE_UNUSED_PARAMETER unsigned short int nbpParamVal2,            \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_USHORT_OP_RESULT(func)                \
    .testAssertUShortOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_USHORT_OP_RESULT                       \
    .testAssertUShortOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_INT_OP_RESULT(func)                       \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamVal1,                           \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamVal2,                           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_INT_OP_RESULT(func)                   \
    .testAssertIntOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_INT_OP_RESULT                          \
    .testAssertIntOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_UINT_OP_RESULT(func)                      \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamVal1,                  \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamVal2,                  \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_UINT_OP_RESULT(func)                  \
    .testAssertUIntOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_UINT_OP_RESULT                         \
    .testAssertUIntOpResult = NBP_MEMORY_NULL_POINTER

    /*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_LONG_OP_RESULT(func)                      \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER long int nbpParamVal1,                      \
        NBP_MAYBE_UNUSED_PARAMETER long int nbpParamVal2,                      \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_LONG_OP_RESULT(func)                  \
    .testAssertLongOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_LONG_OP_RESULT                         \
    .testAssertLongOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_ULONG_OP_RESULT(func)                     \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long int nbpParamVal1,             \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long int nbpParamVal2,             \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_ULONG_OP_RESULT(func)                 \
    .testAssertULongOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_ULONG_OP_RESULT                        \
    .testAssertULongOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_LLONG_OP_RESULT(func)                     \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER long long int nbpParamVal1,                 \
        NBP_MAYBE_UNUSED_PARAMETER long long int nbpParamVal2,                 \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_LLONG_OP_RESULT(func)                 \
    .testAssertLLongOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_LLONG_OP_RESULT                        \
    .testAssertLLongOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_ULLONG_OP_RESULT(func)                    \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long long int nbpParamVal1,        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long long int nbpParamVal2,        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_ULLONG_OP_RESULT(func)                \
    .testAssertULLongOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_ULLONG_OP_RESULT                       \
    .testAssertULLongOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_FLOAT_OP_RESULT(func)                     \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER float nbpParamVal1,                         \
        NBP_MAYBE_UNUSED_PARAMETER float nbpParamVal2,                         \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_FLOAT_OP_RESULT(func)                 \
    .testAssertFloatOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_FLOAT_OP_RESULT                        \
    .testAssertFloatOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_DOUBLE_OP_RESULT(func)                    \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER double nbpParamVal1,                        \
        NBP_MAYBE_UNUSED_PARAMETER double nbpParamVal2,                        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_DOUBLE_OP_RESULT(func)                \
    .testAssertDoubleOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_DOUBLE_OP_RESULT                       \
    .testAssertDoubleOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_LDOUBLE_OP_RESULT(func)                   \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER long double nbpParamVal1,                   \
        NBP_MAYBE_UNUSED_PARAMETER long double nbpParamVal2,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_ASSERT_LDOUBLE_OP_RESULT(func)               \
    .testAssertLDoubleOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_ASSERT_LDOUBLE_OP_RESULT                      \
    .testAssertLDoubleOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_RESULT(func)                            \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamCond,                   \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_RESULT(func)                        \
    .moduleAssertResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_RESULT                               \
    .moduleAssertResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_OP_RESULT(func)                         \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamVal1,                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamVal2,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_OP_RESULT(func)                     \
    .moduleAssertOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_OP_RESULT                            \
    .moduleAssertOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_CHAR_OP_RESULT(func)                    \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER char nbpParamVal1,                          \
        NBP_MAYBE_UNUSED_PARAMETER char nbpParamVal2,                          \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_CHAR_OP_RESULT(func)                \
    .moduleAssertCharOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_CHAR_OP_RESULT                       \
    .moduleAssertCharOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_SHORT_OP_RESULT(func)                   \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER short int nbpParamVal1,                     \
        NBP_MAYBE_UNUSED_PARAMETER short int nbpParamVal2,                     \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_SHORT_OP_RESULT(func)               \
    .moduleAssertShortOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_SHORT_OP_RESULT                      \
    .moduleAssertShortOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_USHORT_OP_RESULT(func)                  \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned short int nbpParamVal1,            \
        NBP_MAYBE_UNUSED_PARAMETER unsigned short int nbpParamVal2,            \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_USHORT_OP_RESULT(func)              \
    .moduleAssertUShortOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_USHORT_OP_RESULT                     \
    .moduleAssertUShortOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_INT_OP_RESULT(func)                     \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamVal1,                           \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamVal2,                           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_INT_OP_RESULT(func)                 \
    .moduleAssertIntOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_INT_OP_RESULT                        \
    .moduleAssertIntOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_UINT_OP_RESULT(func)                    \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamVal1,                  \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamVal2,                  \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_UINT_OP_RESULT(func)                \
    .moduleAssertUIntOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_UINT_OP_RESULT                       \
    .moduleAssertUIntOpResult = NBP_MEMORY_NULL_POINTER

    /*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_LONG_OP_RESULT(func)                    \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER long int nbpParamVal1,                      \
        NBP_MAYBE_UNUSED_PARAMETER long int nbpParamVal2,                      \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_LONG_OP_RESULT(func)                \
    .moduleAssertLongOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_LONG_OP_RESULT                       \
    .moduleAssertLongOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_ULONG_OP_RESULT(func)                   \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long int nbpParamVal1,             \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long int nbpParamVal2,             \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_ULONG_OP_RESULT(func)               \
    .moduleAssertULongOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_ULONG_OP_RESULT                      \
    .moduleAssertULongOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_LLONG_OP_RESULT(func)                   \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER long long int nbpParamVal1,                 \
        NBP_MAYBE_UNUSED_PARAMETER long long int nbpParamVal2,                 \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_LLONG_OP_RESULT(func)               \
    .moduleAssertLLongOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_LLONG_OP_RESULT                      \
    .moduleAssertLLongOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_ULLONG_OP_RESULT(func)                  \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long long int nbpParamVal1,        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long long int nbpParamVal2,        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_ULLONG_OP_RESULT(func)              \
    .moduleAssertULLongOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_ULLONG_OP_RESULT                     \
    .moduleAssertULLongOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_FLOAT_OP_RESULT(func)                   \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER float nbpParamVal1,                         \
        NBP_MAYBE_UNUSED_PARAMETER float nbpParamVal2,                         \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_FLOAT_OP_RESULT(func)               \
    .moduleAssertFloatOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_FLOAT_OP_RESULT                      \
    .moduleAssertFloatOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_DOUBLE_OP_RESULT(func)                  \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER double nbpParamVal1,                        \
        NBP_MAYBE_UNUSED_PARAMETER double nbpParamVal2,                        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_DOUBLE_OP_RESULT(func)              \
    .moduleAssertDoubleOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_DOUBLE_OP_RESULT                     \
    .moduleAssertDoubleOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_LDOUBLE_OP_RESULT(func)                 \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER long double nbpParamVal1,                   \
        NBP_MAYBE_UNUSED_PARAMETER long double nbpParamVal2,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_ASSERT_LDOUBLE_OP_RESULT(func)             \
    .moduleAssertLDoubleOpResult =                                             \
        NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_ASSERT_LDOUBLE_OP_RESULT                    \
    .moduleAssertLDoubleOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_RESULT(func)                                   \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamCond,                   \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_RESULT(func)                               \
    .assertResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_RESULT                                      \
    .assertResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_OP_RESULT(func)                                \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamVal1,                   \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamVal2,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_OP_RESULT(func)                            \
    .assertOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_OP_RESULT                                   \
    .assertOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_CHAR_OP_RESULT(func)                           \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER char nbpParamVal1,                          \
        NBP_MAYBE_UNUSED_PARAMETER char nbpParamVal2,                          \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_CHAR_OP_RESULT(func)                       \
    .assertCharOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_CHAR_OP_RESULT                              \
    .assertCharOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_SHORT_OP_RESULT(func)                          \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER short int nbpParamVal1,                     \
        NBP_MAYBE_UNUSED_PARAMETER short int nbpParamVal2,                     \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_SHORT_OP_RESULT(func)                      \
    .assertShortOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_SHORT_OP_RESULT                             \
    .assertShortOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_USHORT_OP_RESULT(func)                         \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned short int nbpParamVal1,            \
        NBP_MAYBE_UNUSED_PARAMETER unsigned short int nbpParamVal2,            \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_USHORT_OP_RESULT(func)                     \
    .assertUShortOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_USHORT_OP_RESULT                            \
    .assertUShortOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_INT_OP_RESULT(func)                            \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamVal1,                           \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamVal2,                           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_INT_OP_RESULT(func)                        \
    .assertIntOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_INT_OP_RESULT                               \
    .assertIntOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_UINT_OP_RESULT(func)                           \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamVal1,                  \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamVal2,                  \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_UINT_OP_RESULT(func)                       \
    .assertUIntOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_UINT_OP_RESULT                              \
    .assertUIntOpResult = NBP_MEMORY_NULL_POINTER

    /*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_LONG_OP_RESULT(func)                           \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER long int nbpParamVal1,                      \
        NBP_MAYBE_UNUSED_PARAMETER long int nbpParamVal2,                      \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_LONG_OP_RESULT(func)                       \
    .assertLongOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_LONG_OP_RESULT                              \
    .assertLongOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_ULONG_OP_RESULT(func)                          \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long int nbpParamVal1,             \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long int nbpParamVal2,             \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_ULONG_OP_RESULT(func)                      \
    .assertULongOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_ULONG_OP_RESULT                             \
    .assertULongOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_LLONG_OP_RESULT(func)                          \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER long long int nbpParamVal1,                 \
        NBP_MAYBE_UNUSED_PARAMETER long long int nbpParamVal2,                 \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_LLONG_OP_RESULT(func)                      \
    .assertLLongOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_LLONG_OP_RESULT                             \
    .assertLLongOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_ULLONG_OP_RESULT(func)                         \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long long int nbpParamVal1,        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned long long int nbpParamVal2,        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_ULLONG_OP_RESULT(func)                     \
    .assertULLongOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_ULLONG_OP_RESULT                            \
    .assertULLongOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_FLOAT_OP_RESULT(func)                          \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER float nbpParamVal1,                         \
        NBP_MAYBE_UNUSED_PARAMETER float nbpParamVal2,                         \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_FLOAT_OP_RESULT(func)                      \
    .assertFloatOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_FLOAT_OP_RESULT                             \
    .assertFloatOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_DOUBLE_OP_RESULT(func)                         \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER double nbpParamVal1,                        \
        NBP_MAYBE_UNUSED_PARAMETER double nbpParamVal2,                        \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_DOUBLE_OP_RESULT(func)                     \
    .assertDoubleOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_DOUBLE_OP_RESULT                            \
    .assertDoubleOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_LDOUBLE_OP_RESULT(func)                        \
    static void NBP_PP_CONCAT(nbp_printer_func_, func)(                        \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER long double nbpParamVal1,                   \
        NBP_MAYBE_UNUSED_PARAMETER long double nbpParamVal2,                   \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamPassed,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailMsg,                \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamPassMsg                 \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_ASSERT_LDOUBLE_OP_RESULT(func)                    \
    .assertLDoubleOpResult = NBP_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_ASSERT_LDOUBLE_OP_RESULT                           \
    .assertLDoubleOpResult = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER(name, ...)                                                 \
    nbp_printer_interface_t NBP_PP_CONCAT(nbpPrinter, name) = {                \
        __VA_ARGS__                                                            \
    }

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_PTR(name)                                              \
    & NBP_PP_CONCAT(nbpPrinter, name)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_INCLUDE(name)                                              \
    extern nbp_printer_interface_t NBP_PP_CONCAT(nbpPrinter, name)

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
#define NBP_PRINTER_GET_FIRST_VALUE() nbpParamVal1

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SECOND_VALUE() nbpParamVal2

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_CHECK_STATUS() nbpParamPassed

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_CHECK_LINE() nbpParamLine

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_TEST_ASSERT_STATUS() nbpParamPassed

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_TEST_ASSERT_LINE() nbpParamLine

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_MODULE_ASSERT_STATUS() nbpParamPassed

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_MODULE_ASSERT_LINE() nbpParamLine

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_ASSERT_STATUS() nbpParamPassed

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_ASSERT_LINE() nbpParamLine

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FAIL_MSG() nbpParamFailMsg

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FAIL_MSG NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_PASS_MSG() nbpParamPassMsg

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_PASS_MSG NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_MODULES() nbpParamModulesNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_PASSED_MODULES() nbpParamPassedModulesNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_FAILED_MODULES() nbpParamFailedModulesNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_SKIPPED_MODULES() nbpParamSkippedModulesNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_TESTS() nbpParamTestsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_PASSED_TESTS() nbpParamPassedTestsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_FAILED_TESTS() nbpParamFailedTestsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_SKIPPED_TESTS() nbpParamSkippedTestsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_CHECKS() nbpParamChecksNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_PASSED_CHECKS() nbpParamPassedChecksNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_FAILED_CHECKS() nbpParamFailedChecksNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_TEST_ASSERTS() nbpParamTestAssertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_PASSED_TEST_ASSERTS()                        \
    nbpParamPassedTestAssertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_FAILED_TEST_ASSERTS()                        \
    nbpParamFailedTestAssertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_MODULE_ASSERTS() nbpParamModuleAssertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_PASSED_MODULE_ASSERTS()                      \
    nbpParamPassedModuleAssertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_FAILED_MODULE_ASSERTS()                      \
    nbpParamFailedModuleAssertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_ASSERTS() nbpParamAssertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_PASSED_ASSERTS() nbpParamPassedAssertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_NUMBER_OF_FAILED_ASSERTS() nbpParamFailedAssertsNum

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_ERROR() nbpParamError

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_EXIT_ERROR_CODE() nbpParamErrorCode

#endif // end if NBP_PRIVATE_API_PRINTER_H
