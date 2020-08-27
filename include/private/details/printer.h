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

void nbp_printer_notify_check_result(
    nbp_test_details_t*, /* current test */
    const char*, /* condition */
    int, /* status */
    int, /* line */
    const char*, /* failure message */
    const char* /* success message */
);

void nbp_printer_notify_check_type_op_result(
    nbp_test_details_t*, /* current test */
    nbp_printer_type_value_t, /* first value */
    nbp_printer_type_value_t, /* second value */
    unsigned int, /* type */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* failure message */
    const char* /* success message */
);

void nbp_printer_notify_test_assert_result(
    nbp_test_details_t*, /* current test */
    const char*, /* condition */
    int, /* status */
    int, /* line */
    const char*, /* failure message */
    const char* /* success message */
);

void nbp_printer_notify_test_assert_type_op_result(
    nbp_test_details_t*, /* current test */
    nbp_printer_type_value_t, /* first value */
    nbp_printer_type_value_t, /* second value */
    unsigned int, /* type */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* failure message */
    const char* /* success message */
);

void nbp_printer_notify_module_assert_result(
    nbp_test_details_t*, /* current test */
    const char*, /* condition */
    int, /* status */
    int, /* line */
    const char*, /* failure message */
    const char* /* success message */
);

void nbp_printer_notify_module_assert_type_op_result(
    nbp_test_details_t*, /* current test */
    nbp_printer_type_value_t, /* first value */
    nbp_printer_type_value_t, /* second value */
    unsigned int, /* type */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* failure message */
    const char* /* success message */
);

void nbp_printer_notify_assert_result(
    nbp_test_details_t*, /* current test */
    const char*, /* condition */
    int, /* status */
    int, /* line */
    const char*, /* failure message */
    const char* /* success message */
);

void nbp_printer_notify_assert_type_op_result(
    nbp_test_details_t*, /* current test */
    nbp_printer_type_value_t, /* first value */
    nbp_printer_type_value_t, /* second value */
    unsigned int, /* type */
    unsigned int, /* operator */
    int, /* status */
    int, /* line */
    const char*, /* failure message */
    const char* /* success message */
);

#endif // end if NBP_PRIVATE_DETAILS_PRINTER_H
