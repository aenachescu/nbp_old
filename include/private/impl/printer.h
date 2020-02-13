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

void nbp_notify_printer_handle_error(nbp_error_t err)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->handleError != NBP_NULL_POINTER) {
            nbpPrinterInterfaces[i]->handleError(err);
        }
    }
}

void nbp_notify_printer_test_started(nbp_test_details_t* test)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testStarted != NBP_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testStarted(test);
        }
    }
}

void nbp_notify_printer_test_completed(nbp_test_details_t* test)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testCompleted != NBP_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testCompleted(test);
        }
    }
}

void nbp_notify_printer_module_started(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleStarted != NBP_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleStarted(module);
        }
    }
}

void nbp_notify_printer_module_completed(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleCompleted != NBP_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleCompleted(module);
        }
    }
}

void nbp_notify_printer_before_run(unsigned int modulesNum,
    unsigned int testsNum)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->beforeRun != NBP_NULL_POINTER) {
            nbpPrinterInterfaces[i]->beforeRun(modulesNum, testsNum);
        }
    }
}

void nbp_notify_printer_after_run(unsigned int passedModulesNum,
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
        if (nbpPrinterInterfaces[i]->afterRun != NBP_NULL_POINTER) {
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

void nbp_notify_printer_scheduling_test(nbp_test_details_t* test)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->schedulingTest != NBP_NULL_POINTER) {
            nbpPrinterInterfaces[i]->schedulingTest(test);
        }
    }
}

void nbp_notify_printer_before_scheduling_module(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->beforeSchedulingModule != NBP_NULL_POINTER) {
            nbpPrinterInterfaces[i]->beforeSchedulingModule(module);
        }
    }
}

void nbp_notify_printer_after_scheduling_module(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->afterSchedulingModule != NBP_NULL_POINTER) {
            nbpPrinterInterfaces[i]->afterSchedulingModule(module);
        }
    }
}

void nbp_notify_printer_check_result(nbp_test_details_t* test, const char* cond,
    int passed, int line, const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_check_op_result(nbp_test_details_t* test,
    const char* a, const char* b, int op, int passed, int line,
    const char* failMsg, const char* passMsg )
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_check_char_op_result(nbp_test_details_t* test, char a,
    char b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkCharOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_check_short_op_result(nbp_test_details_t* test,
    short int a, short int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkShortOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_check_ushort_op_result(nbp_test_details_t* test,
    unsigned short int a, unsigned short int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkUShortOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_check_int_op_result(nbp_test_details_t* test, int a,
    int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkIntOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_check_uint_op_result(nbp_test_details_t* test,
    unsigned int a, unsigned int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkUIntOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_check_long_op_result(nbp_test_details_t* test,
    long int a, long int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkLongOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_check_ulong_op_result(nbp_test_details_t* test,
    unsigned long int a, unsigned long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkULongOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_check_llong_op_result(nbp_test_details_t* test,
    long long int a, long long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkLLongOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_check_ullong_op_result(nbp_test_details_t* test,
    unsigned long long int a, unsigned long long int b, int op, int passed,
    int line, const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkULLongOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_check_float_op_result(nbp_test_details_t* test,
    float a, float b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkFloatOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_check_double_op_result(nbp_test_details_t* test,
    double a, double b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkDoubleOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_check_ldouble_op_result(nbp_test_details_t* test,
    long double a, long double b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkLDoubleOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_test_assert_result(nbp_test_details_t* test, const char* cond,
    int passed, int line, const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_test_assert_op_result(nbp_test_details_t* test,
    const char* a, const char* b, int op, int passed, int line,
    const char* failMsg, const char* passMsg )
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_test_assert_char_op_result(nbp_test_details_t* test, char a,
    char b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertCharOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_test_assert_short_op_result(nbp_test_details_t* test,
    short int a, short int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertShortOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_test_assert_ushort_op_result(nbp_test_details_t* test,
    unsigned short int a, unsigned short int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertUShortOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_test_assert_int_op_result(nbp_test_details_t* test, int a,
    int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertIntOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_test_assert_uint_op_result(nbp_test_details_t* test,
    unsigned int a, unsigned int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertUIntOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_test_assert_long_op_result(nbp_test_details_t* test,
    long int a, long int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertLongOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_test_assert_ulong_op_result(nbp_test_details_t* test,
    unsigned long int a, unsigned long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertULongOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_test_assert_llong_op_result(nbp_test_details_t* test,
    long long int a, long long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertLLongOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_test_assert_ullong_op_result(nbp_test_details_t* test,
    unsigned long long int a, unsigned long long int b, int op, int passed,
    int line, const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertULLongOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_test_assert_float_op_result(nbp_test_details_t* test,
    float a, float b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertFloatOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_test_assert_double_op_result(nbp_test_details_t* test,
    double a, double b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertDoubleOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_test_assert_ldouble_op_result(nbp_test_details_t* test,
    long double a, long double b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertLDoubleOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_module_assert_result(nbp_test_details_t* test,
    const char* cond, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_module_assert_op_result(nbp_test_details_t* test,
    const char* a, const char* b, int op, int passed, int line,
    const char* failMsg, const char* passMsg )
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_module_assert_char_op_result(nbp_test_details_t* test,
    char a, char b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertCharOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_module_assert_short_op_result(nbp_test_details_t* test,
    short int a, short int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertShortOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_module_assert_ushort_op_result(nbp_test_details_t* test,
    unsigned short int a, unsigned short int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertUShortOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_module_assert_int_op_result(nbp_test_details_t* test,
    int a, int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertIntOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_module_assert_uint_op_result(nbp_test_details_t* test,
    unsigned int a, unsigned int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertUIntOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_module_assert_long_op_result(nbp_test_details_t* test,
    long int a, long int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertLongOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_module_assert_ulong_op_result(nbp_test_details_t* test,
    unsigned long int a, unsigned long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertULongOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_module_assert_llong_op_result(nbp_test_details_t* test,
    long long int a, long long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertLLongOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_module_assert_ullong_op_result(nbp_test_details_t* test,
    unsigned long long int a, unsigned long long int b, int op, int passed,
    int line, const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertULLongOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_module_assert_float_op_result(nbp_test_details_t* test,
    float a, float b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertFloatOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_module_assert_double_op_result(nbp_test_details_t* test,
    double a, double b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertDoubleOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_module_assert_ldouble_op_result(
    nbp_test_details_t* test, long double a, long double b, int op, int passed,
    int line, const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertLDoubleOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_assert_result(nbp_test_details_t* test,
    const char* cond, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_assert_op_result(nbp_test_details_t* test,
    const char* a, const char* b, int op, int passed, int line,
    const char* failMsg, const char* passMsg )
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_assert_char_op_result(nbp_test_details_t* test, char a,
    char b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertCharOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_assert_short_op_result(nbp_test_details_t* test,
    short int a, short int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertShortOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_assert_ushort_op_result(nbp_test_details_t* test,
    unsigned short int a, unsigned short int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertUShortOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_assert_int_op_result(nbp_test_details_t* test, int a,
    int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertIntOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_assert_uint_op_result(nbp_test_details_t* test,
    unsigned int a, unsigned int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertUIntOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_assert_long_op_result(nbp_test_details_t* test,
    long int a, long int b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertLongOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_assert_ulong_op_result(nbp_test_details_t* test,
    unsigned long int a, unsigned long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertULongOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_assert_llong_op_result(nbp_test_details_t* test,
    long long int a, long long int b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertLLongOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_assert_ullong_op_result(nbp_test_details_t* test,
    unsigned long long int a, unsigned long long int b, int op, int passed,
    int line, const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertULLongOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_assert_float_op_result(nbp_test_details_t* test,
    float a, float b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertFloatOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_assert_double_op_result(nbp_test_details_t* test,
    double a, double b, int op, int passed, int line, const char* failMsg,
    const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertDoubleOpResult != NBP_NULL_POINTER) {
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

void nbp_notify_printer_assert_ldouble_op_result(nbp_test_details_t* test,
    long double a, long double b, int op, int passed, int line,
    const char* failMsg, const char* passMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertLDoubleOpResult != NBP_NULL_POINTER) {
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
