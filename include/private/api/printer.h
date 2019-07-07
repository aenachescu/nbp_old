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
    static int NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                 \
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
        int errCode                                                            \
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

#endif // end if NBP_PRIVATE_API_PRINTER_H

