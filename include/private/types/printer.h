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

struct nbp_printer_interface_t {
    nbp_printer_init_pfn_t init;
    nbp_printer_uninit_pfn_t uninit;
    nbp_printer_handle_error_pfn_t handleError;
    nbp_printer_test_begin_pfn_t testBegin;
    nbp_printer_test_end_pfn_t testEnd;
    nbp_printer_module_begin_pfn_t moduleBegin;
    nbp_printer_module_end_pfn_t moduleEnd;
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
};

typedef struct nbp_printer_interface_t nbp_printer_interface_t;

#endif // end if NBP_PRIVATE_TYPES_PRINTER_H