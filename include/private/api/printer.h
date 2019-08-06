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
    .init = 0x0

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
    .uninit = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_HANDLE_ERROR(func)                                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_error_t err                                                        \
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
    .handleError = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_BEGIN(func)                                      \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test                                               \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_BEGIN(func)                                  \
    .testBegin = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_BEGIN                                         \
    .testBegin = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_END(func)                                        \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test                                               \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_END(func)                                    \
    .testEnd = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_END                                           \
    .testEnd = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_BEGIN(func)                                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_module_details_t* module                                           \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_BEGIN(func)                                \
    .moduleBegin = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_BEGIN                                       \
    .moduleBegin = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_END(func)                                      \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_module_details_t* module                                           \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_END(func)                                  \
    .moduleEnd = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_END                                         \
    .moduleEnd = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_BEFORE_RUN(func)                                      \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        unsigned int modulesNum,                                               \
        unsigned int testsNum                                                  \
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
    .beforeRun = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_AFTER_RUN(func)                                       \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        unsigned int passedModulesNum,                                         \
        unsigned int failedModulesNum,                                         \
        unsigned int skippedModulesNum,                                        \
        unsigned int passedTestsNum,                                           \
        unsigned int failedTestsNum,                                           \
        unsigned int skippedTestsNum,                                          \
        unsigned int checksNum,                                                \
        unsigned int passedChecksNum,                                          \
        unsigned int failedChecksNum,                                          \
        unsigned int testAssertsNum,                                           \
        unsigned int passedTestAssertsNum,                                     \
        unsigned int failedTestAssertsNum,                                     \
        unsigned int moduleAssertsNum,                                         \
        unsigned int passedModuleAssertsNum,                                   \
        unsigned int failedModuleAssertsNum,                                   \
        unsigned int assertsNum,                                               \
        unsigned int passedAssertsNum,                                         \
        unsigned int failedAssertsNum                                          \
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
    .afterRun = 0x0


/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_SCHEDULING_TEST(func)                                 \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test                                               \
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
    .schedulingTest = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_BEFORE_SCHEDULING_MODULE(func)                        \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_module_details_t* module                                           \
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
    .beforeSchedulingModule = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_AFTER_SCHEDULING_MODULE(func)                         \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_module_details_t* module                                           \
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
    .afterSchedulingModule = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_RESULT(func)                                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        const char* cond,                                                      \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .checkResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_OP_RESULT(func)                                 \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        const char* a,                                                         \
        const char* b,                                                         \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .checkOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_CHAR_OP_RESULT(func)                            \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        char a,                                                                \
        char b,                                                                \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .checkCharOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_SHORT_OP_RESULT(func)                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        short int a,                                                           \
        short int b,                                                           \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .checkShortOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_USHORT_OP_RESULT(func)                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        unsigned short int a,                                                  \
        unsigned short int b,                                                  \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .checkUShortOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_INT_OP_RESULT(func)                             \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        int a,                                                                 \
        int b,                                                                 \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .checkIntOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_UINT_OP_RESULT(func)                            \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        unsigned int a,                                                        \
        unsigned int b,                                                        \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .checkUIntOpResult = 0x0

    /*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_LONG_OP_RESULT(func)                            \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        long int a,                                                            \
        long int b,                                                            \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .checkLongOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_ULONG_OP_RESULT(func)                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        unsigned long int a,                                                   \
        unsigned long int b,                                                   \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .checkULongOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_LLONG_OP_RESULT(func)                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        long long int a,                                                       \
        long long int b,                                                       \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .checkLLongOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_ULLONG_OP_RESULT(func)                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        unsigned long long int a,                                              \
        unsigned long long int b,                                              \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .checkULLongOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_FLOAT_OP_RESULT(func)                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        float a,                                                               \
        float b,                                                               \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .checkFloatOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_DOUBLE_OP_RESULT(func)                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        double a,                                                              \
        double b,                                                              \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .checkDoubleOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_LDOUBLE_OP_RESULT(func)                         \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        long double a,                                                         \
        long double b,                                                         \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .checkLDoubleOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_RESULT(func)                              \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        const char* cond,                                                      \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .testAssertResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_OP_RESULT(func)                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        const char* a,                                                         \
        const char* b,                                                         \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .testAssertOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_CHAR_OP_RESULT(func)                      \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        char a,                                                                \
        char b,                                                                \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .testAssertCharOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_SHORT_OP_RESULT(func)                     \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        short int a,                                                           \
        short int b,                                                           \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .testAssertShortOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_USHORT_OP_RESULT(func)                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        unsigned short int a,                                                  \
        unsigned short int b,                                                  \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .testAssertUShortOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_INT_OP_RESULT(func)                       \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        int a,                                                                 \
        int b,                                                                 \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .testAssertIntOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_UINT_OP_RESULT(func)                      \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        unsigned int a,                                                        \
        unsigned int b,                                                        \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .testAssertUIntOpResult = 0x0

    /*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_LONG_OP_RESULT(func)                      \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        long int a,                                                            \
        long int b,                                                            \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .testAssertLongOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_ULONG_OP_RESULT(func)                     \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        unsigned long int a,                                                   \
        unsigned long int b,                                                   \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .testAssertULongOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_LLONG_OP_RESULT(func)                     \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        long long int a,                                                       \
        long long int b,                                                       \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .testAssertLLongOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_ULLONG_OP_RESULT(func)                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        unsigned long long int a,                                              \
        unsigned long long int b,                                              \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .testAssertULLongOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_FLOAT_OP_RESULT(func)                     \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        float a,                                                               \
        float b,                                                               \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .testAssertFloatOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_DOUBLE_OP_RESULT(func)                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        double a,                                                              \
        double b,                                                              \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .testAssertDoubleOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_ASSERT_LDOUBLE_OP_RESULT(func)                   \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        long double a,                                                         \
        long double b,                                                         \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .testAssertLDoubleOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_RESULT(func)                            \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        const char* cond,                                                      \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .moduleAssertResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_OP_RESULT(func)                         \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        const char* a,                                                         \
        const char* b,                                                         \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .moduleAssertOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_CHAR_OP_RESULT(func)                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        char a,                                                                \
        char b,                                                                \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .moduleAssertCharOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_SHORT_OP_RESULT(func)                   \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        short int a,                                                           \
        short int b,                                                           \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .moduleAssertShortOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_USHORT_OP_RESULT(func)                  \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        unsigned short int a,                                                  \
        unsigned short int b,                                                  \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .moduleAssertUShortOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_INT_OP_RESULT(func)                     \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        int a,                                                                 \
        int b,                                                                 \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .moduleAssertIntOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_UINT_OP_RESULT(func)                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        unsigned int a,                                                        \
        unsigned int b,                                                        \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .moduleAssertUIntOpResult = 0x0

    /*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_LONG_OP_RESULT(func)                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        long int a,                                                            \
        long int b,                                                            \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .moduleAssertLongOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_ULONG_OP_RESULT(func)                   \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        unsigned long int a,                                                   \
        unsigned long int b,                                                   \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .moduleAssertULongOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_LLONG_OP_RESULT(func)                   \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        long long int a,                                                       \
        long long int b,                                                       \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .moduleAssertLLongOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_ULLONG_OP_RESULT(func)                  \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        unsigned long long int a,                                              \
        unsigned long long int b,                                              \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .moduleAssertULLongOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_FLOAT_OP_RESULT(func)                   \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        float a,                                                               \
        float b,                                                               \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .moduleAssertFloatOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_DOUBLE_OP_RESULT(func)                  \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        double a,                                                              \
        double b,                                                              \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .moduleAssertDoubleOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_ASSERT_LDOUBLE_OP_RESULT(func)                 \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        long double a,                                                         \
        long double b,                                                         \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .moduleAssertLDoubleOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_RESULT(func)                                   \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        const char* cond,                                                      \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .assertResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_OP_RESULT(func)                                \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        const char* a,                                                         \
        const char* b,                                                         \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .assertOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_CHAR_OP_RESULT(func)                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        char a,                                                                \
        char b,                                                                \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .assertCharOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_SHORT_OP_RESULT(func)                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        short int a,                                                           \
        short int b,                                                           \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .assertShortOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_USHORT_OP_RESULT(func)                         \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        unsigned short int a,                                                  \
        unsigned short int b,                                                  \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .assertUShortOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_INT_OP_RESULT(func)                            \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        int a,                                                                 \
        int b,                                                                 \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .assertIntOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_UINT_OP_RESULT(func)                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        unsigned int a,                                                        \
        unsigned int b,                                                        \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .assertUIntOpResult = 0x0

    /*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_LONG_OP_RESULT(func)                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        long int a,                                                            \
        long int b,                                                            \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .assertLongOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_ULONG_OP_RESULT(func)                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        unsigned long int a,                                                   \
        unsigned long int b,                                                   \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .assertULongOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_LLONG_OP_RESULT(func)                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        long long int a,                                                       \
        long long int b,                                                       \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .assertLLongOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_ULLONG_OP_RESULT(func)                         \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        unsigned long long int a,                                              \
        unsigned long long int b,                                              \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .assertULLongOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_FLOAT_OP_RESULT(func)                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        float a,                                                               \
        float b,                                                               \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .assertFloatOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_DOUBLE_OP_RESULT(func)                         \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        double a,                                                              \
        double b,                                                              \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .assertDoubleOpResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_ASSERT_LDOUBLE_OP_RESULT(func)                        \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t* test,                                              \
        long double a,                                                         \
        long double b,                                                         \
        int op,                                                                \
        int passed,                                                            \
        int line,                                                              \
        const char* failMsg,                                                   \
        const char* passMsg                                                    \
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
    .assertLDoubleOpResult = 0x0

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
#define NBP_PRINTER_NO_FAIL_MSG 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_GET_PASS_MSG() passMsg

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_PASS_MSG 0x0

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

