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

#ifndef NBP_PRIVATE_TYPES_PRINTER_H
#define NBP_PRIVATE_TYPES_PRINTER_H

/*
 * TODO: add docs
 */
#define NBP_PRINTER_OPERATOR_EQ         (unsigned int) 0x40000001
#define NBP_PRINTER_OPERATOR_NE         (unsigned int) 0x40000002
#define NBP_PRINTER_OPERATOR_LT         (unsigned int) 0x40000003
#define NBP_PRINTER_OPERATOR_LE         (unsigned int) 0x40000004
#define NBP_PRINTER_OPERATOR_GT         (unsigned int) 0x40000005
#define NBP_PRINTER_OPERATOR_GE         (unsigned int) 0x40000006

/*
 * TODO: add docs
 */
#define NBP_PRINTER_TYPE_NONE           (unsigned int) 0x41000000
#define NBP_PRINTER_TYPE_CHAR           (unsigned int) 0x41000001
#define NBP_PRINTER_TYPE_SHORT          (unsigned int) 0x41000002
#define NBP_PRINTER_TYPE_USHORT         (unsigned int) 0x41000003
#define NBP_PRINTER_TYPE_INT            (unsigned int) 0x41000004
#define NBP_PRINTER_TYPE_UINT           (unsigned int) 0x41000005
#define NBP_PRINTER_TYPE_LONG           (unsigned int) 0x41000006
#define NBP_PRINTER_TYPE_ULONG          (unsigned int) 0x41000007
#define NBP_PRINTER_TYPE_LLONG          (unsigned int) 0x41000008
#define NBP_PRINTER_TYPE_ULLONG         (unsigned int) 0x41000009
#define NBP_PRINTER_TYPE_FLOAT          (unsigned int) 0x4100000A
#define NBP_PRINTER_TYPE_DOUBLE         (unsigned int) 0x4100000B
#define NBP_PRINTER_TYPE_LDOUBLE        (unsigned int) 0x4100000C

union nbp_printer_type_value_t
{
    const char* stringValue;
    char charValue;
    short int shortValue;
    unsigned short int ushortValue;
    int intValue;
    unsigned int uintValue;
    long int longValue;
    unsigned long int ulongValue;
    long long int llongValue;
    unsigned long long int ullongValue;
    float floatValue;
    double doubleValue;
    long double* ldoubleValue;
};
typedef union nbp_printer_type_value_t nbp_printer_type_value_t;

struct nbp_printer_interface_t;
typedef struct nbp_printer_interface_t nbp_printer_interface_t;

typedef void (*nbp_printer_config_pfn_t)(
    nbp_printer_interface_t*
);

typedef void (*nbp_printer_callback_init_pfn_t)(
    void
);

typedef void (*nbp_printer_callback_uninit_pfn_t)(
    void
);

typedef void (*nbp_printer_callback_report_error_pfn_t)(
    nbp_error_t /* error context */
);

typedef void (*nbp_printer_callback_exit_triggered_pfn_t)(
    int /* exit status */
);

typedef void (*nbp_printer_callback_handle_version_command_pfn_t)(
    void
);

typedef void (*nbp_printer_callback_test_started_pfn_t)(
    nbp_test_details_t* /* current test */
);

typedef void (*nbp_printer_callback_test_completed_pfn_t)(
    nbp_test_details_t* /* current test */
);

typedef void (*nbp_printer_callback_module_started_pfn_t)(
    nbp_module_details_t* /* current module */
);

typedef void (*nbp_printer_callback_module_completed_pfn_t)(
    nbp_module_details_t* /* current module */
);

typedef void (*nbp_printer_callback_before_run_pfn_t)(
    nbp_module_details_t* /* main module */
);

typedef void (*nbp_printer_callback_after_run_pfn_t)(
    nbp_module_details_t* /* main module */
);

typedef void (*nbp_printer_callback_run_test_pfn_t) (
    nbp_test_details_t* /* current test */
);

typedef void (*nbp_printer_callback_run_module_pfn_t) (
    nbp_module_details_t* /* current module */
);

typedef void (*nbp_printer_callback_run_module_completed_pfn_t) (
    nbp_module_details_t* /* current module */
);

typedef void (*nbp_printer_callback_assert_result_pfn_t)(
    nbp_test_details_t*, /* current test */
    const char*, /* condition */
    unsigned int, /* assert type */
    unsigned int, /* status */
    int, /* line */
    const char*, /* assert failure message */
    const char* /* assert success message */
);

typedef void (*nbp_printer_callback_assert_type_op_result_pfn_t)(
    nbp_test_details_t*, /* current test */
    nbp_printer_type_value_t, /* first value */
    nbp_printer_type_value_t, /* second value */
    unsigned int, /* value type */
    unsigned int, /* operator */
    unsigned int, /* assert type */
    unsigned int, /* status */
    int, /* line */
    const char*, /* assert failure message */
    const char* /* assert success message */
);

struct nbp_printer_interface_t {
    const char* printerName;
    int isInitialized;
    nbp_printer_config_pfn_t configFunc;

    nbp_printer_callback_init_pfn_t initCbk;
    nbp_printer_callback_uninit_pfn_t uninitCbk;

    nbp_printer_callback_report_error_pfn_t reportErrorCbk;
    nbp_printer_callback_exit_triggered_pfn_t exitTriggeredCbk;

    nbp_printer_callback_handle_version_command_pfn_t handleVersionCommandCbk;

    nbp_printer_callback_test_started_pfn_t testStartedCbk;
    nbp_printer_callback_test_completed_pfn_t testCompletedCbk;

    nbp_printer_callback_module_started_pfn_t moduleStartedCbk;
    nbp_printer_callback_module_completed_pfn_t moduleCompletedCbk;

    nbp_printer_callback_before_run_pfn_t beforeRunCbk;
    nbp_printer_callback_after_run_pfn_t afterRunCbk;

    nbp_printer_callback_run_test_pfn_t runTestCbk;

    nbp_printer_callback_run_module_pfn_t runModuleCbk;
    nbp_printer_callback_run_module_completed_pfn_t runModuleCompletedCbk;

    nbp_printer_callback_assert_result_pfn_t assertResultCbk;
    nbp_printer_callback_assert_type_op_result_pfn_t assertTypeOpResultCbk;
};

typedef struct nbp_printer_interface_t nbp_printer_interface_t;

#endif // end if NBP_PRIVATE_TYPES_PRINTER_H
