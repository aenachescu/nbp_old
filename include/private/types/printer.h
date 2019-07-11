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

#ifndef NBP_PRIVATE_TYPES_PRINTER_H
#define NBP_PRIVATE_TYPES_PRINTER_H

#define NBP_PRINTER_OPERATOR_EQ     (int) 1
#define NBP_PRINTER_OPERATOR_NE     (int) 2
#define NBP_PRINTER_OPERATOR_LT     (int) 3
#define NBP_PRINTER_OPERATOR_LE     (int) 4
#define NBP_PRINTER_OPERATOR_GT     (int) 5
#define NBP_PRINTER_OPERATOR_GE     (int) 6

typedef void (*nbp_printer_init_pfn_t)(
    void
);

typedef int (*nbp_printer_uninit_pfn_t)(
    void
);

typedef void (*nbp_printer_handle_error_pfn_t)(
    int
);

typedef void (*nbp_printer_test_begin_pfn_t)(
    nbp_test_details_t*
);

typedef void (*nbp_printer_test_end_pfn_t)(
    nbp_test_details_t*
);

typedef void (*nbp_printer_module_begin_pfn_t)(
    nbp_module_details_t*
);

typedef void (*nbp_printer_module_end_pfn_t)(
    nbp_module_details_t*
);

typedef void (*nbp_printer_check_result_pfn_t)(
    nbp_test_details_t*,
    const char*,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_check_op_result_pfn_t)(
    nbp_test_details_t*,
    const char*,
    const char*,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_check_char_op_result_pfn_t)(
    nbp_test_details_t*,
    char,
    char,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_check_short_op_result_pfn_t)(
    nbp_test_details_t*,
    short int,
    short int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_check_ushort_op_result_pfn_t)(
    nbp_test_details_t*,
    unsigned short int,
    unsigned short int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_check_int_op_result_pfn_t)(
    nbp_test_details_t*,
    int,
    int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_check_uint_op_result_pfn_t)(
    nbp_test_details_t*,
    unsigned int,
    unsigned int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_check_long_op_result_pfn_t)(
    nbp_test_details_t*,
    long int,
    long int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_check_ulong_op_result_pfn_t)(
    nbp_test_details_t*,
    unsigned long int,
    unsigned long int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_check_llong_op_result_pfn_t)(
    nbp_test_details_t*,
    long long int,
    long long int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_check_ullong_op_result_pfn_t)(
    nbp_test_details_t*,
    unsigned long long int,
    unsigned long long int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_check_float_op_result_pfn_t)(
    nbp_test_details_t*,
    float,
    float,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_check_double_op_result_pfn_t)(
    nbp_test_details_t*,
    double,
    double,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_check_ldouble_op_result_pfn_t)(
    nbp_test_details_t*,
    long double,
    long double,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_test_assert_result_pfn_t)(
    nbp_test_details_t*,
    const char*,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_test_assert_op_result_pfn_t)(
    nbp_test_details_t*,
    const char*,
    const char*,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_test_assert_char_op_result_pfn_t)(
    nbp_test_details_t*,
    char,
    char,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_test_assert_short_op_result_pfn_t)(
    nbp_test_details_t*,
    short int,
    short int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_test_assert_ushort_op_result_pfn_t)(
    nbp_test_details_t*,
    unsigned short int,
    unsigned short int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_test_assert_int_op_result_pfn_t)(
    nbp_test_details_t*,
    int,
    int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_test_assert_uint_op_result_pfn_t)(
    nbp_test_details_t*,
    unsigned int,
    unsigned int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_test_assert_long_op_result_pfn_t)(
    nbp_test_details_t*,
    long int,
    long int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_test_assert_ulong_op_result_pfn_t)(
    nbp_test_details_t*,
    unsigned long int,
    unsigned long int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_test_assert_llong_op_result_pfn_t)(
    nbp_test_details_t*,
    long long int,
    long long int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_test_assert_ullong_op_result_pfn_t)(
    nbp_test_details_t*,
    unsigned long long int,
    unsigned long long int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_test_assert_float_op_result_pfn_t)(
    nbp_test_details_t*,
    float,
    float,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_test_assert_double_op_result_pfn_t)(
    nbp_test_details_t*,
    double,
    double,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_test_assert_ldouble_op_result_pfn_t)(
    nbp_test_details_t*,
    long double,
    long double,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_module_assert_result_pfn_t)(
    nbp_test_details_t*,
    const char*,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_module_assert_op_result_pfn_t)(
    nbp_test_details_t*,
    const char*,
    const char*,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_module_assert_char_op_result_pfn_t)(
    nbp_test_details_t*,
    char,
    char,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_module_assert_short_op_result_pfn_t)(
    nbp_test_details_t*,
    short int,
    short int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_module_assert_ushort_op_result_pfn_t)(
    nbp_test_details_t*,
    unsigned short int,
    unsigned short int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_module_assert_int_op_result_pfn_t)(
    nbp_test_details_t*,
    int,
    int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_module_assert_uint_op_result_pfn_t)(
    nbp_test_details_t*,
    unsigned int,
    unsigned int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_module_assert_long_op_result_pfn_t)(
    nbp_test_details_t*,
    long int,
    long int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_module_assert_ulong_op_result_pfn_t)(
    nbp_test_details_t*,
    unsigned long int,
    unsigned long int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_module_assert_llong_op_result_pfn_t)(
    nbp_test_details_t*,
    long long int,
    long long int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_module_assert_ullong_op_result_pfn_t)(
    nbp_test_details_t*,
    unsigned long long int,
    unsigned long long int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_module_assert_float_op_result_pfn_t)(
    nbp_test_details_t*,
    float,
    float,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_module_assert_double_op_result_pfn_t)(
    nbp_test_details_t*,
    double,
    double,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_module_assert_ldouble_op_result_pfn_t)(
    nbp_test_details_t*,
    long double,
    long double,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_assert_result_pfn_t)(
    nbp_test_details_t*,
    const char*,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_assert_op_result_pfn_t)(
    nbp_test_details_t*,
    const char*,
    const char*,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_assert_char_op_result_pfn_t)(
    nbp_test_details_t*,
    char,
    char,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_assert_short_op_result_pfn_t)(
    nbp_test_details_t*,
    short int,
    short int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_assert_ushort_op_result_pfn_t)(
    nbp_test_details_t*,
    unsigned short int,
    unsigned short int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_assert_int_op_result_pfn_t)(
    nbp_test_details_t*,
    int,
    int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_assert_uint_op_result_pfn_t)(
    nbp_test_details_t*,
    unsigned int,
    unsigned int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_assert_long_op_result_pfn_t)(
    nbp_test_details_t*,
    long int,
    long int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_assert_ulong_op_result_pfn_t)(
    nbp_test_details_t*,
    unsigned long int,
    unsigned long int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_assert_llong_op_result_pfn_t)(
    nbp_test_details_t*,
    long long int,
    long long int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_assert_ullong_op_result_pfn_t)(
    nbp_test_details_t*,
    unsigned long long int,
    unsigned long long int,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_assert_float_op_result_pfn_t)(
    nbp_test_details_t*,
    float,
    float,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_assert_double_op_result_pfn_t)(
    nbp_test_details_t*,
    double,
    double,
    int,
    int,
    int,
    const char*,
    const char*
);

typedef void (*nbp_printer_assert_ldouble_op_result_pfn_t)(
    nbp_test_details_t*,
    long double,
    long double,
    int,
    int,
    int,
    const char*,
    const char*
);

struct nbp_printer_interface_t {
    nbp_printer_init_pfn_t init;
    nbp_printer_uninit_pfn_t uninit;
    nbp_printer_handle_error_pfn_t handleError;
    nbp_printer_test_begin_pfn_t testBegin;
    nbp_printer_test_end_pfn_t testEnd;
    nbp_printer_module_begin_pfn_t moduleBegin;
    nbp_printer_module_end_pfn_t moduleEnd;

    // callbacks for NBP_CHECK_* macros
    nbp_printer_check_result_pfn_t checkResult;
    nbp_printer_check_op_result_pfn_t checkOpResult;
    nbp_printer_check_char_op_result_pfn_t checkCharOpResult;
    nbp_printer_check_short_op_result_pfn_t checkShortOpResult;
    nbp_printer_check_ushort_op_result_pfn_t checkUShortOpResult;
    nbp_printer_check_int_op_result_pfn_t checkIntOpResult;
    nbp_printer_check_uint_op_result_pfn_t checkUIntOpResult;
    nbp_printer_check_long_op_result_pfn_t checkLongOpResult;
    nbp_printer_check_ulong_op_result_pfn_t checkULongOpResult;
    nbp_printer_check_llong_op_result_pfn_t checkLLongOpResult;
    nbp_printer_check_ullong_op_result_pfn_t checkULLongOpResult;
    nbp_printer_check_float_op_result_pfn_t checkFloatOpResult;
    nbp_printer_check_double_op_result_pfn_t checkDoubleOpResult;
    nbp_printer_check_ldouble_op_result_pfn_t checkLDoubleOpResult;

    // callbacks for NBP_TEST_ASSERT_* macros
    nbp_printer_test_assert_result_pfn_t testAssertResult;
    nbp_printer_test_assert_op_result_pfn_t testAssertOpResult;
    nbp_printer_test_assert_char_op_result_pfn_t testAssertCharOpResult;
    nbp_printer_test_assert_short_op_result_pfn_t testAssertShortOpResult;
    nbp_printer_test_assert_ushort_op_result_pfn_t testAssertUShortOpResult;
    nbp_printer_test_assert_int_op_result_pfn_t testAssertIntOpResult;
    nbp_printer_test_assert_uint_op_result_pfn_t testAssertUIntOpResult;
    nbp_printer_test_assert_long_op_result_pfn_t testAssertLongOpResult;
    nbp_printer_test_assert_ulong_op_result_pfn_t testAssertULongOpResult;
    nbp_printer_test_assert_llong_op_result_pfn_t testAssertLLongOpResult;
    nbp_printer_test_assert_ullong_op_result_pfn_t testAssertULLongOpResult;
    nbp_printer_test_assert_float_op_result_pfn_t testAssertFloatOpResult;
    nbp_printer_test_assert_double_op_result_pfn_t testAssertDoubleOpResult;
    nbp_printer_test_assert_ldouble_op_result_pfn_t testAssertLDoubleOpResult;

    // callbacks for NBP_MODULE_ASSERT_* macros
    nbp_printer_module_assert_result_pfn_t moduleAssertResult;
    nbp_printer_module_assert_op_result_pfn_t moduleAssertOpResult;
    nbp_printer_module_assert_char_op_result_pfn_t moduleAssertCharOpResult;
    nbp_printer_module_assert_short_op_result_pfn_t moduleAssertShortOpResult;
    nbp_printer_module_assert_ushort_op_result_pfn_t moduleAssertUShortOpResult;
    nbp_printer_module_assert_int_op_result_pfn_t moduleAssertIntOpResult;
    nbp_printer_module_assert_uint_op_result_pfn_t moduleAssertUIntOpResult;
    nbp_printer_module_assert_long_op_result_pfn_t moduleAssertLongOpResult;
    nbp_printer_module_assert_ulong_op_result_pfn_t moduleAssertULongOpResult;
    nbp_printer_module_assert_llong_op_result_pfn_t moduleAssertLLongOpResult;
    nbp_printer_module_assert_ullong_op_result_pfn_t moduleAssertULLongOpResult;
    nbp_printer_module_assert_float_op_result_pfn_t moduleAssertFloatOpResult;
    nbp_printer_module_assert_double_op_result_pfn_t moduleAssertDoubleOpResult;
    nbp_printer_module_assert_ldouble_op_result_pfn_t moduleAssertLDoubleOpResult;

    // callbacks for NBP_ASSERT_* macros
    nbp_printer_assert_result_pfn_t assertResult;
    nbp_printer_assert_op_result_pfn_t assertOpResult;
    nbp_printer_assert_char_op_result_pfn_t assertCharOpResult;
    nbp_printer_assert_short_op_result_pfn_t assertShortOpResult;
    nbp_printer_assert_ushort_op_result_pfn_t assertUShortOpResult;
    nbp_printer_assert_int_op_result_pfn_t assertIntOpResult;
    nbp_printer_assert_uint_op_result_pfn_t assertUIntOpResult;
    nbp_printer_assert_long_op_result_pfn_t assertLongOpResult;
    nbp_printer_assert_ulong_op_result_pfn_t assertULongOpResult;
    nbp_printer_assert_llong_op_result_pfn_t assertLLongOpResult;
    nbp_printer_assert_ullong_op_result_pfn_t assertULLongOpResult;
    nbp_printer_assert_float_op_result_pfn_t assertFloatOpResult;
    nbp_printer_assert_double_op_result_pfn_t assertDoubleOpResult;
    nbp_printer_assert_ldouble_op_result_pfn_t assertLDoubleOpResult;
};

typedef struct nbp_printer_interface_t nbp_printer_interface_t;

#endif // end if NBP_PRIVATE_TYPES_PRINTER_H
