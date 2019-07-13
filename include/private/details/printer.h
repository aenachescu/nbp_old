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

#ifndef NBP_PRIVATE_DETAILS_PRINTER_H
#define NBP_PRIVATE_DETAILS_PRINTER_H

const char* nbp_printer_operator_to_string(
    int
);

void nbp_notify_printer_test_begin(
    nbp_test_details_t* /* current test */
);

void nbp_notify_printer_test_end(
    nbp_test_details_t* /* current test */
);

void nbp_notify_printer_module_begin(
    nbp_module_details_t* /* current module */
);

void nbp_notify_printer_module_end(
    nbp_module_details_t* /* current module */
);

void nbp_notify_printer_handle_error(
    int /* error code */
);

void nbp_notify_printer_check_result(
    nbp_test_details_t*, /* current test */
    const char*, /* condition */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_check_op_result(
    nbp_test_details_t*, /* current test */
    const char*, /* first value */
    const char*, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_check_char_op_result(
    nbp_test_details_t*, /* current test */
    char, /* first value */
    char, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_check_short_op_result(
    nbp_test_details_t*, /* current test */
    short int, /* first value */
    short int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_check_ushort_op_result(
    nbp_test_details_t*, /* current test */
    unsigned short int, /* first value */
    unsigned short int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_check_int_op_result(
    nbp_test_details_t*, /* current test */
    int, /* first value */
    int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_check_uint_op_result(
    nbp_test_details_t*, /* current test */
    unsigned int, /* first value */
    unsigned int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_check_long_op_result(
    nbp_test_details_t*, /* current test */
    long int, /* first value */
    long int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_check_ulong_op_result(
    nbp_test_details_t*, /* current test */
    unsigned long int, /* first value */
    unsigned long int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_check_llong_op_result(
    nbp_test_details_t*, /* current test */
    long long int, /* first value */
    long long int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_check_ullong_op_result(
    nbp_test_details_t*, /* current test */
    unsigned long long int, /* first value */
    unsigned long long int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_check_float_op_result(
    nbp_test_details_t*, /* current test */
    float, /* first value */
    float, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_check_double_op_result(
    nbp_test_details_t*, /* current test */
    double, /* first value */
    double, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_check_ldouble_op_result(
    nbp_test_details_t*, /* current test */
    long double, /* first value */
    long double, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_test_assert_result(
    nbp_test_details_t*, /* current test */
    const char*, /* condition */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_test_assert_op_result(
    nbp_test_details_t*, /* current test */
    const char*, /* first value */
    const char*, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_test_assert_char_op_result(
    nbp_test_details_t*, /* current test */
    char, /* first value */
    char, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_test_assert_short_op_result(
    nbp_test_details_t*, /* current test */
    short int, /* first value */
    short int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_test_assert_ushort_op_result(
    nbp_test_details_t*, /* current test */
    unsigned short int, /* first value */
    unsigned short int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_test_assert_int_op_result(
    nbp_test_details_t*, /* current test */
    int, /* first value */
    int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_test_assert_uint_op_result(
    nbp_test_details_t*, /* current test */
    unsigned int, /* first value */
    unsigned int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_test_assert_long_op_result(
    nbp_test_details_t*, /* current test */
    long int, /* first value */
    long int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_test_assert_ulong_op_result(
    nbp_test_details_t*, /* current test */
    unsigned long int, /* first value */
    unsigned long int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_test_assert_llong_op_result(
    nbp_test_details_t*, /* current test */
    long long int, /* first value */
    long long int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_test_assert_ullong_op_result(
    nbp_test_details_t*, /* current test */
    unsigned long long int, /* first value */
    unsigned long long int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_test_assert_float_op_result(
    nbp_test_details_t*, /* current test */
    float, /* first value */
    float, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_test_assert_double_op_result(
    nbp_test_details_t*, /* current test */
    double, /* first value */
    double, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_test_assert_ldouble_op_result(
    nbp_test_details_t*, /* current test */
    long double, /* first value */
    long double, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_module_assert_result(
    nbp_test_details_t*, /* current test */
    const char*, /* condition */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_module_assert_op_result(
    nbp_test_details_t*, /* current test */
    const char*, /* first value */
    const char*, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_module_assert_char_op_result(
    nbp_test_details_t*, /* current test */
    char, /* first value */
    char, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_module_assert_short_op_result(
    nbp_test_details_t*, /* current test */
    short int, /* first value */
    short int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_module_assert_ushort_op_result(
    nbp_test_details_t*, /* current test */
    unsigned short int, /* first value */
    unsigned short int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_module_assert_int_op_result(
    nbp_test_details_t*, /* current test */
    int, /* first value */
    int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_module_assert_uint_op_result(
    nbp_test_details_t*, /* current test */
    unsigned int, /* first value */
    unsigned int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_module_assert_long_op_result(
    nbp_test_details_t*, /* current test */
    long int, /* first value */
    long int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_module_assert_ulong_op_result(
    nbp_test_details_t*, /* current test */
    unsigned long int, /* first value */
    unsigned long int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_module_assert_llong_op_result(
    nbp_test_details_t*, /* current test */
    long long int, /* first value */
    long long int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_module_assert_ullong_op_result(
    nbp_test_details_t*, /* current test */
    unsigned long long int, /* first value */
    unsigned long long int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_module_assert_float_op_result(
    nbp_test_details_t*, /* current test */
    float, /* first value */
    float, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_module_assert_double_op_result(
    nbp_test_details_t*, /* current test */
    double, /* first value */
    double, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_module_assert_ldouble_op_result(
    nbp_test_details_t*, /* current test */
    long double, /* first value */
    long double, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_assert_result(
    nbp_test_details_t*, /* current test */
    const char*, /* condition */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_assert_op_result(
    nbp_test_details_t*, /* current test */
    const char*, /* first value */
    const char*, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_assert_char_op_result(
    nbp_test_details_t*, /* current test */
    char, /* first value */
    char, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_assert_short_op_result(
    nbp_test_details_t*, /* current test */
    short int, /* first value */
    short int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_assert_ushort_op_result(
    nbp_test_details_t*, /* current test */
    unsigned short int, /* first value */
    unsigned short int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_assert_int_op_result(
    nbp_test_details_t*, /* current test */
    int, /* first value */
    int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_assert_uint_op_result(
    nbp_test_details_t*, /* current test */
    unsigned int, /* first value */
    unsigned int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_assert_long_op_result(
    nbp_test_details_t*, /* current test */
    long int, /* first value */
    long int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_assert_ulong_op_result(
    nbp_test_details_t*, /* current test */
    unsigned long int, /* first value */
    unsigned long int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_assert_llong_op_result(
    nbp_test_details_t*, /* current test */
    long long int, /* first value */
    long long int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_assert_ullong_op_result(
    nbp_test_details_t*, /* current test */
    unsigned long long int, /* first value */
    unsigned long long int, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_assert_float_op_result(
    nbp_test_details_t*, /* current test */
    float, /* first value */
    float, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_assert_double_op_result(
    nbp_test_details_t*, /* current test */
    double, /* first value */
    double, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_notify_printer_assert_ldouble_op_result(
    nbp_test_details_t*, /* current test */
    long double, /* first value */
    long double, /* second value */
    int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

#endif // end if NBP_PRIVATE_DETAILS_PRINTER_H
