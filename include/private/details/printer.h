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

#ifndef NBP_PRIVATE_DETAILS_PRINTER_H
#define NBP_PRIVATE_DETAILS_PRINTER_H

const char* nbp_printer_operator_to_string(
    unsigned int
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

void nbp_printer_notify_before_run(
    unsigned int, /* num of modules */
    unsigned int  /* num of tests   */
);

void nbp_printer_notify_after_run(
    unsigned int, /* num of passed  modules             */
    unsigned int, /* num of failed  modules             */
    unsigned int, /* num of skipped modules             */
    unsigned int, /* num of passed  tests               */
    unsigned int, /* num of failed  tests               */
    unsigned int, /* num of skipped tests               */
    unsigned int, /* num of         checks              */
    unsigned int, /* num of passed  checks              */
    unsigned int, /* num of failed  checks              */
    unsigned int, /* num of         test asserts        */
    unsigned int, /* num of passed  test asserts        */
    unsigned int, /* num of failed  test asserts        */
    unsigned int, /* num of         modules asserts     */
    unsigned int, /* num of passed  modules asserts     */
    unsigned int, /* num of failed  modules asserts     */
    unsigned int, /* num of         asserts             */
    unsigned int, /* num of passed  asserts             */
    unsigned int  /* num of failed  asserts             */
);

void nbp_printer_notify_scheduling_test(
    nbp_test_details_t* /* current test */
);

void nbp_printer_notify_before_scheduling_module(
    nbp_module_details_t* /* current module */
);

void nbp_printer_notify_after_scheduling_module(
    nbp_module_details_t* /* current module */
);

void nbp_printer_notify_check_result(
    nbp_test_details_t*, /* current test */
    const char*, /* condition */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_check_op_result(
    nbp_test_details_t*, /* current test */
    const char*, /* first value */
    const char*, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_check_char_op_result(
    nbp_test_details_t*, /* current test */
    char, /* first value */
    char, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_check_short_op_result(
    nbp_test_details_t*, /* current test */
    short int, /* first value */
    short int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_check_ushort_op_result(
    nbp_test_details_t*, /* current test */
    unsigned short int, /* first value */
    unsigned short int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_check_int_op_result(
    nbp_test_details_t*, /* current test */
    int, /* first value */
    int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_check_uint_op_result(
    nbp_test_details_t*, /* current test */
    unsigned int, /* first value */
    unsigned int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_check_long_op_result(
    nbp_test_details_t*, /* current test */
    long int, /* first value */
    long int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_check_ulong_op_result(
    nbp_test_details_t*, /* current test */
    unsigned long int, /* first value */
    unsigned long int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_check_llong_op_result(
    nbp_test_details_t*, /* current test */
    long long int, /* first value */
    long long int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_check_ullong_op_result(
    nbp_test_details_t*, /* current test */
    unsigned long long int, /* first value */
    unsigned long long int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_check_float_op_result(
    nbp_test_details_t*, /* current test */
    float, /* first value */
    float, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_check_double_op_result(
    nbp_test_details_t*, /* current test */
    double, /* first value */
    double, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_check_ldouble_op_result(
    nbp_test_details_t*, /* current test */
    long double, /* first value */
    long double, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_test_assert_result(
    nbp_test_details_t*, /* current test */
    const char*, /* condition */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_test_assert_op_result(
    nbp_test_details_t*, /* current test */
    const char*, /* first value */
    const char*, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_test_assert_char_op_result(
    nbp_test_details_t*, /* current test */
    char, /* first value */
    char, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_test_assert_short_op_result(
    nbp_test_details_t*, /* current test */
    short int, /* first value */
    short int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_test_assert_ushort_op_result(
    nbp_test_details_t*, /* current test */
    unsigned short int, /* first value */
    unsigned short int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_test_assert_int_op_result(
    nbp_test_details_t*, /* current test */
    int, /* first value */
    int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_test_assert_uint_op_result(
    nbp_test_details_t*, /* current test */
    unsigned int, /* first value */
    unsigned int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_test_assert_long_op_result(
    nbp_test_details_t*, /* current test */
    long int, /* first value */
    long int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_test_assert_ulong_op_result(
    nbp_test_details_t*, /* current test */
    unsigned long int, /* first value */
    unsigned long int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_test_assert_llong_op_result(
    nbp_test_details_t*, /* current test */
    long long int, /* first value */
    long long int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_test_assert_ullong_op_result(
    nbp_test_details_t*, /* current test */
    unsigned long long int, /* first value */
    unsigned long long int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_test_assert_float_op_result(
    nbp_test_details_t*, /* current test */
    float, /* first value */
    float, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_test_assert_double_op_result(
    nbp_test_details_t*, /* current test */
    double, /* first value */
    double, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_test_assert_ldouble_op_result(
    nbp_test_details_t*, /* current test */
    long double, /* first value */
    long double, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_module_assert_result(
    nbp_test_details_t*, /* current test */
    const char*, /* condition */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_module_assert_op_result(
    nbp_test_details_t*, /* current test */
    const char*, /* first value */
    const char*, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_module_assert_char_op_result(
    nbp_test_details_t*, /* current test */
    char, /* first value */
    char, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_module_assert_short_op_result(
    nbp_test_details_t*, /* current test */
    short int, /* first value */
    short int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_module_assert_ushort_op_result(
    nbp_test_details_t*, /* current test */
    unsigned short int, /* first value */
    unsigned short int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_module_assert_int_op_result(
    nbp_test_details_t*, /* current test */
    int, /* first value */
    int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_module_assert_uint_op_result(
    nbp_test_details_t*, /* current test */
    unsigned int, /* first value */
    unsigned int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_module_assert_long_op_result(
    nbp_test_details_t*, /* current test */
    long int, /* first value */
    long int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_module_assert_ulong_op_result(
    nbp_test_details_t*, /* current test */
    unsigned long int, /* first value */
    unsigned long int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_module_assert_llong_op_result(
    nbp_test_details_t*, /* current test */
    long long int, /* first value */
    long long int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_module_assert_ullong_op_result(
    nbp_test_details_t*, /* current test */
    unsigned long long int, /* first value */
    unsigned long long int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_module_assert_float_op_result(
    nbp_test_details_t*, /* current test */
    float, /* first value */
    float, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_module_assert_double_op_result(
    nbp_test_details_t*, /* current test */
    double, /* first value */
    double, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_module_assert_ldouble_op_result(
    nbp_test_details_t*, /* current test */
    long double, /* first value */
    long double, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_assert_result(
    nbp_test_details_t*, /* current test */
    const char*, /* condition */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_assert_op_result(
    nbp_test_details_t*, /* current test */
    const char*, /* first value */
    const char*, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_assert_char_op_result(
    nbp_test_details_t*, /* current test */
    char, /* first value */
    char, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_assert_short_op_result(
    nbp_test_details_t*, /* current test */
    short int, /* first value */
    short int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_assert_ushort_op_result(
    nbp_test_details_t*, /* current test */
    unsigned short int, /* first value */
    unsigned short int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_assert_int_op_result(
    nbp_test_details_t*, /* current test */
    int, /* first value */
    int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_assert_uint_op_result(
    nbp_test_details_t*, /* current test */
    unsigned int, /* first value */
    unsigned int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_assert_long_op_result(
    nbp_test_details_t*, /* current test */
    long int, /* first value */
    long int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_assert_ulong_op_result(
    nbp_test_details_t*, /* current test */
    unsigned long int, /* first value */
    unsigned long int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_assert_llong_op_result(
    nbp_test_details_t*, /* current test */
    long long int, /* first value */
    long long int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_assert_ullong_op_result(
    nbp_test_details_t*, /* current test */
    unsigned long long int, /* first value */
    unsigned long long int, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_assert_float_op_result(
    nbp_test_details_t*, /* current test */
    float, /* first value */
    float, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_assert_double_op_result(
    nbp_test_details_t*, /* current test */
    double, /* first value */
    double, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

void nbp_printer_notify_assert_ldouble_op_result(
    nbp_test_details_t*, /* current test */
    long double, /* first value */
    long double, /* second value */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* fail message */
    const char* /* pass message */
);

#endif // end if NBP_PRIVATE_DETAILS_PRINTER_H
