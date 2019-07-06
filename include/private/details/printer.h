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
    nbp_test_details_t*
);

void nbp_notify_printer_test_end(
    nbp_test_details_t*
);

void nbp_notify_printer_module_begin(
    nbp_module_details_t*
);

void nbp_notify_printer_module_end(
    nbp_module_details_t*
);

void nbp_notify_printer_handle_error(
    int
);

void nbp_notify_printer_check_result(
    nbp_test_details_t*,
    const char*,
    int,
    int,
    const char*,
    const char*
);

void nbp_notify_printer_check_op_result(
    nbp_test_details_t*,
    const char*,
    const char*,
    int,
    int,
    int,
    const char*,
    const char*
);

void nbp_notify_printer_check_char_op_result(
    nbp_test_details_t*,
    char,
    char,
    int,
    int,
    int,
    const char*,
    const char*
);

void nbp_notify_printer_check_short_op_result(
    nbp_test_details_t*,
    short int,
    short int,
    int,
    int,
    int,
    const char*,
    const char*
);

void nbp_notify_printer_check_ushort_op_result(
    nbp_test_details_t*,
    unsigned short int,
    unsigned short int,
    int,
    int,
    int,
    const char*,
    const char*
);

void nbp_notify_printer_check_int_op_result(
    nbp_test_details_t*,
    int,
    int,
    int,
    int,
    int,
    const char*,
    const char*
);

void nbp_notify_printer_check_uint_op_result(
    nbp_test_details_t*,
    unsigned int,
    unsigned int,
    int,
    int,
    int,
    const char*,
    const char*
);

void nbp_notify_printer_check_long_op_result(
    nbp_test_details_t*,
    long int,
    long int,
    int,
    int,
    int,
    const char*,
    const char*
);

void nbp_notify_printer_check_ulong_op_result(
    nbp_test_details_t*,
    unsigned long int,
    unsigned long int,
    int,
    int,
    int,
    const char*,
    const char*
);

void nbp_notify_printer_check_llong_op_result(
    nbp_test_details_t*,
    long long int,
    long long int,
    int,
    int,
    int,
    const char*,
    const char*
);

void nbp_notify_printer_check_ullong_op_result(
    nbp_test_details_t*,
    unsigned long long int,
    unsigned long long int,
    int,
    int,
    int,
    const char*,
    const char*
);

void nbp_notify_printer_check_float_op_result(
    nbp_test_details_t*,
    float,
    float,
    int,
    int,
    int,
    const char*,
    const char*
);

void nbp_notify_printer_check_double_op_result(
    nbp_test_details_t*,
    double,
    double,
    int,
    int,
    int,
    const char*,
    const char*
);

void nbp_notify_printer_check_ldouble_op_result(
    nbp_test_details_t*,
    long double,
    long double,
    int,
    int,
    int,
    const char*,
    const char*
);

#endif // end if NBP_PRIVATE_DETAILS_PRINTER_H
