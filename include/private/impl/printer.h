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

#ifndef NBP_PRIVATE_IMPL_PRINTER_H
#define NBP_PRIVATE_IMPL_PRINTER_H

const char* nbp_printer_operator_to_string(int op)
{
    switch (op) {
        case NBP_PRINTER_OPERATOR_EQ:
            return "==";
        case NBP_PRINTER_OPERATOR_NE:
            return "!=";
        case NBP_PRINTER_OPERATOR_GT:
            return ">";
        case NBP_PRINTER_OPERATOR_GE:
            return ">=";
        case NBP_PRINTER_OPERATOR_LT:
            return "<";
        case NBP_PRINTER_OPERATOR_LE:
            return "<=";
    }

    NBP_HANDLE_ERROR(NBP_ERROR_UNKNOWN_OPERATOR);
    return "unknown";
}

void nbp_printer_notify_handle_error(int errCode)
{
    nbp_error_t err;

    err.errorCode = errCode;
    err.contextType = NBP_ERROR_CONTEXT_EMPTY;
    err.contextString = NBP_MEMORY_NULL_POINTER;

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->handleError != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->handleError(err);
        }
    }
}

void nbp_printer_notify_handle_error_ctx_string(int errCode, const char* ctx)
{
    nbp_error_t err;

    err.errorCode = errCode;
    err.contextType = NBP_ERROR_CONTEXT_STRING;
    err.contextString = ctx;

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->handleError != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->handleError(err);
        }
    }
}

void nbp_printer_notify_handle_error_ctx_custom(int errCode, void* ctx)
{
    nbp_error_t err;

    err.errorCode = errCode;
    err.contextType = NBP_ERROR_CONTEXT_CUSTOM;
    err.contextCustom = ctx;

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->handleError != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->handleError(err);
        }
    }
}

void nbp_printer_notify_test_started(nbp_test_details_t* test)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testStarted != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testStarted(test);
        }
    }
}

void nbp_printer_notify_test_completed(nbp_test_details_t* test)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testCompleted != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testCompleted(test);
        }
    }
}

void nbp_printer_notify_module_started(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleStarted != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleStarted(module);
        }
    }
}

void nbp_printer_notify_module_completed(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleCompleted != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleCompleted(module);
        }
    }
}

void nbp_printer_notify_before_run(unsigned int modulesNum,
    unsigned int testsNum)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->beforeRun != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->beforeRun(modulesNum, testsNum);
        }
    }
}

void nbp_printer_notify_after_run(unsigned int passedModulesNum,
    unsigned int failedModulesNum, unsigned int skippedModulesNum,
    unsigned int passedTestsNum, unsigned int failedTestsNum,
    unsigned int skippedTestsNum, unsigned int checksNum,
    unsigned int passedChecksNum, unsigned int failedChecksNum,
    unsigned int testAssertsNum, unsigned int passedTestAssertsNum,
    unsigned int failedTestAssertsNum, unsigned int moduleAssertsNum,
    unsigned int passedModuleAssertsNum, unsigned int failedModuleAssertsNum,
    unsigned int assertsNum, unsigned int passedAssertsNum,
    unsigned int failedAssertsNum)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->afterRun != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->afterRun(
                passedModulesNum,
                failedModulesNum,
                skippedModulesNum,
                passedTestsNum,
                failedTestsNum,
                skippedTestsNum,
                checksNum,
                passedChecksNum,
                failedChecksNum,
                testAssertsNum,
                passedTestAssertsNum,
                failedTestAssertsNum,
                moduleAssertsNum,
                passedModuleAssertsNum,
                failedModuleAssertsNum,
                assertsNum,
                passedAssertsNum,
                failedAssertsNum
            );
        }
    }
}

void nbp_printer_notify_scheduling_test(nbp_test_details_t* test)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->schedulingTest != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->schedulingTest(test);
        }
    }
}

void nbp_printer_notify_before_scheduling_module(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->beforeSchedulingModule != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->beforeSchedulingModule(module);
        }
    }
}

void nbp_printer_notify_after_scheduling_module(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->afterSchedulingModule != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->afterSchedulingModule(module);
        }
    }
}

void nbp_printer_notify_check_result(nbp_test_details_t* test, const char* cond,
    int passed, int line, const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->checkResult(
                test,
                cond,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_check_op_result(nbp_test_details_t* test,
    const char* a, const char* b, int op, int passed, int line,
    const char* failMsg, const char* passMsg )
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->checkOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_check_char_op_result(nbp_test_details_t* test, char a,
    char b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkCharOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->checkCharOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_check_short_op_result(nbp_test_details_t* test,
    short int a, short int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkShortOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->checkShortOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_check_ushort_op_result(nbp_test_details_t* test,
    unsigned short int a, unsigned short int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkUShortOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->checkUShortOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_check_int_op_result(nbp_test_details_t* test, int a,
    int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkIntOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->checkIntOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_check_uint_op_result(nbp_test_details_t* test,
    unsigned int a, unsigned int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkUIntOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->checkUIntOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_check_long_op_result(nbp_test_details_t* test,
    long int a, long int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkLongOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->checkLongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_check_ulong_op_result(nbp_test_details_t* test,
    unsigned long int a, unsigned long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkULongOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->checkULongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_check_llong_op_result(nbp_test_details_t* test,
    long long int a, long long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkLLongOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->checkLLongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_check_ullong_op_result(nbp_test_details_t* test,
    unsigned long long int a, unsigned long long int b, int op, int passed,
    int line, const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkULLongOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->checkULLongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_check_float_op_result(nbp_test_details_t* test,
    float a, float b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkFloatOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->checkFloatOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_check_double_op_result(nbp_test_details_t* test,
    double a, double b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkDoubleOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->checkDoubleOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_check_ldouble_op_result(nbp_test_details_t* test,
    long double a, long double b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkLDoubleOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->checkLDoubleOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_test_assert_result(nbp_test_details_t* test, const char* cond,
    int passed, int line, const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testAssertResult(
                test,
                cond,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_test_assert_op_result(nbp_test_details_t* test,
    const char* a, const char* b, int op, int passed, int line,
    const char* failMsg, const char* passMsg )
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testAssertOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_test_assert_char_op_result(nbp_test_details_t* test, char a,
    char b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertCharOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testAssertCharOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_test_assert_short_op_result(nbp_test_details_t* test,
    short int a, short int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertShortOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testAssertShortOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_test_assert_ushort_op_result(nbp_test_details_t* test,
    unsigned short int a, unsigned short int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertUShortOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testAssertUShortOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_test_assert_int_op_result(nbp_test_details_t* test, int a,
    int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertIntOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testAssertIntOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_test_assert_uint_op_result(nbp_test_details_t* test,
    unsigned int a, unsigned int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertUIntOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testAssertUIntOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_test_assert_long_op_result(nbp_test_details_t* test,
    long int a, long int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertLongOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testAssertLongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_test_assert_ulong_op_result(nbp_test_details_t* test,
    unsigned long int a, unsigned long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertULongOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testAssertULongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_test_assert_llong_op_result(nbp_test_details_t* test,
    long long int a, long long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertLLongOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testAssertLLongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_test_assert_ullong_op_result(nbp_test_details_t* test,
    unsigned long long int a, unsigned long long int b, int op, int passed,
    int line, const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertULLongOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testAssertULLongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_test_assert_float_op_result(nbp_test_details_t* test,
    float a, float b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertFloatOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testAssertFloatOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_test_assert_double_op_result(nbp_test_details_t* test,
    double a, double b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertDoubleOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testAssertDoubleOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_test_assert_ldouble_op_result(nbp_test_details_t* test,
    long double a, long double b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertLDoubleOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testAssertLDoubleOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_module_assert_result(nbp_test_details_t* test,
    const char* cond, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleAssertResult(
                test,
                cond,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_module_assert_op_result(nbp_test_details_t* test,
    const char* a, const char* b, int op, int passed, int line,
    const char* failMsg, const char* passMsg )
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleAssertOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_module_assert_char_op_result(nbp_test_details_t* test,
    char a, char b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertCharOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleAssertCharOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_module_assert_short_op_result(nbp_test_details_t* test,
    short int a, short int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertShortOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleAssertShortOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_module_assert_ushort_op_result(nbp_test_details_t* test,
    unsigned short int a, unsigned short int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertUShortOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleAssertUShortOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_module_assert_int_op_result(nbp_test_details_t* test,
    int a, int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertIntOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleAssertIntOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_module_assert_uint_op_result(nbp_test_details_t* test,
    unsigned int a, unsigned int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertUIntOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleAssertUIntOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_module_assert_long_op_result(nbp_test_details_t* test,
    long int a, long int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertLongOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleAssertLongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_module_assert_ulong_op_result(nbp_test_details_t* test,
    unsigned long int a, unsigned long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertULongOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleAssertULongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_module_assert_llong_op_result(nbp_test_details_t* test,
    long long int a, long long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertLLongOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleAssertLLongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_module_assert_ullong_op_result(nbp_test_details_t* test,
    unsigned long long int a, unsigned long long int b, int op, int passed,
    int line, const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertULLongOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleAssertULLongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_module_assert_float_op_result(nbp_test_details_t* test,
    float a, float b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertFloatOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleAssertFloatOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_module_assert_double_op_result(nbp_test_details_t* test,
    double a, double b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertDoubleOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleAssertDoubleOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_module_assert_ldouble_op_result(
    nbp_test_details_t* test, long double a, long double b, int op, int passed,
    int line, const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertLDoubleOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleAssertLDoubleOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_assert_result(nbp_test_details_t* test,
    const char* cond, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertResult(
                test,
                cond,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_assert_op_result(nbp_test_details_t* test,
    const char* a, const char* b, int op, int passed, int line,
    const char* failMsg, const char* passMsg )
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_assert_char_op_result(nbp_test_details_t* test, char a,
    char b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertCharOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertCharOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_assert_short_op_result(nbp_test_details_t* test,
    short int a, short int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertShortOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertShortOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_assert_ushort_op_result(nbp_test_details_t* test,
    unsigned short int a, unsigned short int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertUShortOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertUShortOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_assert_int_op_result(nbp_test_details_t* test, int a,
    int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertIntOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertIntOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_assert_uint_op_result(nbp_test_details_t* test,
    unsigned int a, unsigned int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertUIntOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertUIntOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_assert_long_op_result(nbp_test_details_t* test,
    long int a, long int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertLongOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertLongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_assert_ulong_op_result(nbp_test_details_t* test,
    unsigned long int a, unsigned long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertULongOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertULongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_assert_llong_op_result(nbp_test_details_t* test,
    long long int a, long long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertLLongOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertLLongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_assert_ullong_op_result(nbp_test_details_t* test,
    unsigned long long int a, unsigned long long int b, int op, int passed,
    int line, const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertULLongOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertULLongOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_assert_float_op_result(nbp_test_details_t* test,
    float a, float b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertFloatOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertFloatOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_assert_double_op_result(nbp_test_details_t* test,
    double a, double b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertDoubleOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertDoubleOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

void nbp_printer_notify_assert_ldouble_op_result(nbp_test_details_t* test,
    long double a, long double b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertLDoubleOpResult != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertLDoubleOpResult(
                test,
                a,
                b,
                op,
                passed,
                line,
                failMsg,
                passMsg
            );
        }
    }
}

#endif // end if NBP_PRIVATE_IMPL_PRINTER_H
