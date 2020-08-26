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
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamModulesNum,            \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamTestsNum               \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_AFTER_RUN(func)                                   \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
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
#define NBP_PRINTER_CALLBACK_CHECK_RESULT(func)                                \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamCond,                   \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamStatus,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailureMsg,             \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamSuccessMsg              \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_CHECK_TYPE_OP_RESULT(func)                        \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER nbp_printer_type_value_t nbpParamVal1,      \
        NBP_MAYBE_UNUSED_PARAMETER nbp_printer_type_value_t nbpParamVal2,      \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamType,                  \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamStatus,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailureMsg,             \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamSuccessMsg              \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_TEST_ASSERT_RESULT(func)                          \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamCond,                   \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamStatus,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailureMsg,             \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamSuccessMsg              \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_TEST_ASSERT_TYPE_OP_RESULT(func)                  \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER nbp_printer_type_value_t nbpParamVal1,      \
        NBP_MAYBE_UNUSED_PARAMETER nbp_printer_type_value_t nbpParamVal2,      \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamType,                  \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamStatus,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailureMsg,             \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamSuccessMsg              \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_MODULE_ASSERT_RESULT(func)                        \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamCond,                   \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamStatus,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailureMsg,             \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamSuccessMsg              \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_MODULE_ASSERT_TYPE_OP_RESULT(func)                \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER nbp_printer_type_value_t nbpParamVal1,      \
        NBP_MAYBE_UNUSED_PARAMETER nbp_printer_type_value_t nbpParamVal2,      \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamType,                  \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamStatus,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailureMsg,             \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamSuccessMsg              \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_ASSERT_RESULT(func)                               \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamCond,                   \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamStatus,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailureMsg,             \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamSuccessMsg              \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_CALLBACK_ASSERT_TYPE_OP_RESULT(func)                       \
    static void NBP_PP_CONCAT(nbp_printer_callback_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER nbp_printer_type_value_t nbpParamVal1,      \
        NBP_MAYBE_UNUSED_PARAMETER nbp_printer_type_value_t nbpParamVal2,      \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamType,                  \
        NBP_MAYBE_UNUSED_PARAMETER unsigned int nbpParamOperator,              \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamStatus,                         \
        NBP_MAYBE_UNUSED_PARAMETER int nbpParamLine,                           \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamFailureMsg,             \
        NBP_MAYBE_UNUSED_PARAMETER const char* nbpParamSuccessMsg              \
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
        .checkResultCbk                     = NBP_MEMORY_NULL_POINTER,         \
        .checkTypeOpResultCbk               = NBP_MEMORY_NULL_POINTER,         \
        .testAssertResultCbk                = NBP_MEMORY_NULL_POINTER,         \
        .testAssertTypeOpResultCbk          = NBP_MEMORY_NULL_POINTER,         \
        .moduleAssertResultCbk              = NBP_MEMORY_NULL_POINTER,         \
        .moduleAssertTypeOpResultCbk        = NBP_MEMORY_NULL_POINTER,         \
        .assertResultCbk                    = NBP_MEMORY_NULL_POINTER,         \
        .assertTypeOpResultCbk              = NBP_MEMORY_NULL_POINTER          \
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
#define NBP_PRINTER_GET_VALUE_TYPE() nbpParamType

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
#define NBP_PRINTER_GET_CHECK_STATUS() nbpParamStatus

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_TEST_ASSERT_STATUS() nbpParamStatus

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_MODULE_ASSERT_STATUS() nbpParamStatus

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_ASSERT_STATUS() nbpParamStatus

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_FAILURE_MESSAGE() nbpParamFailureMsg

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FAILURE_MESSAGE NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_SUCCESS_MESSAGE() nbpParamSuccessMsg

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_SUCCESS_MESSAGE NBP_MEMORY_NULL_POINTER

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
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_CHECK_RESULT(func)                  \
    nbpParamPrinter->checkResultCbk =                                          \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_CHECK_TYPE_OP_RESULT(func)          \
    nbpParamPrinter->checkTypeOpResultCbk =                                    \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_TEST_ASSERT_RESULT(func)            \
    nbpParamPrinter->testAssertResultCbk =                                     \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_TEST_ASSERT_TYPE_OP_RESULT(func)    \
    nbpParamPrinter->testAssertTypeOpResultCbk =                               \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_MODULE_ASSERT_RESULT(func)          \
    nbpParamPrinter->moduleAssertResultCbk =                                   \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_MODULE_ASSERT_TYPE_OP_RESULT(func)  \
    nbpParamPrinter->moduleAssertTypeOpResultCbk =                             \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_ASSERT_RESULT(func)                 \
    nbpParamPrinter->assertResultCbk =                                         \
        NBP_PP_CONCAT(nbp_printer_callback_, func);
#define NBP_PP_EAT_PP_NBP_PRINTER_CALLBACK_ASSERT_TYPE_OP_RESULT(func)         \
    nbpParamPrinter->assertTypeOpResultCbk =                                   \
        NBP_PP_CONCAT(nbp_printer_callback_, func);

#endif // end if NBP_PRIVATE_API_PRINTER_H
