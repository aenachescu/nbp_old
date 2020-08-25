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

extern nbp_printer_interface_t* nbpPrinterInterfaces[];
extern unsigned int nbpPrinterInterfacesSize;

const char* nbp_printer_operator_to_string(unsigned int op)
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

    // these lines are excluded from coverage because it is almost impossible to
    // use other operator.
    // LCOV_EXCL_START
    NBP_ERROR_REPORT(NBP_ERROR_CODE_UNKNOWN_OPERATOR);
    return "unknown";
    // LCOV_EXCL_STOP
}

void nbp_printer_notify_init(void)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        nbpPrinterInterfaces[i]->configFunc(nbpPrinterInterfaces[i]);
        if (nbpPrinterInterfaces[i]->initCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->initCbk();
        }
    }
}

void nbp_printer_notify_uninit(void)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->uninitCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->uninitCbk();
        }
    }
}

void nbp_printer_notify_report_error(int errCode, int line,
    const char* filename)
{
    nbp_error_t err;

    err.errorCode       = errCode;
    err.line            = line;
    err.filename        = filename;
    err.contextType     = NBP_ERROR_CONTEXT_EMPTY;
    err.contextString   = NBP_MEMORY_NULL_POINTER;

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->reportErrorCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->reportErrorCbk(err);
        }
    }
}

void nbp_printer_notify_report_error_ctx_string(int errCode, int line,
    const char* filename, const char* ctx)
{
    nbp_error_t err;

    err.errorCode       = errCode;
    err.line            = line;
    err.filename        = filename;
    err.contextType     = NBP_ERROR_CONTEXT_STRING;
    err.contextString   = ctx;

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->reportErrorCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->reportErrorCbk(err);
        }
    }
}

void nbp_printer_notify_report_error_ctx_custom(int errCode, int line,
    const char* filename, void* ctx)
{
    nbp_error_t err;

    err.errorCode       = errCode;
    err.line            = line;
    err.filename        = filename;
    err.contextType     = NBP_ERROR_CONTEXT_CUSTOM;
    err.contextCustom   = ctx;

    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->reportErrorCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->reportErrorCbk(err);
        }
    }
}

void nbp_printer_notify_exit_triggered(int errorCode)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->exitTriggeredCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->exitTriggeredCbk(errorCode);
        }
    }
}

void nbp_printer_notify_handle_version_command(void)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->handleVersionCommandCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->handleVersionCommandCbk();
        }
    }
}

void nbp_printer_notify_test_started(nbp_test_details_t* test)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testStartedCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testStartedCbk(test);
        }
    }
}

void nbp_printer_notify_test_completed(nbp_test_details_t* test)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testCompletedCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testCompletedCbk(test);
        }
    }
}

void nbp_printer_notify_module_started(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleStartedCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleStartedCbk(module);
        }
    }
}

void nbp_printer_notify_module_completed(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleCompletedCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleCompletedCbk(module);
        }
    }
}

void nbp_printer_notify_before_run(unsigned int modulesNum,
    unsigned int testsNum)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->beforeRunCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->beforeRunCbk(modulesNum, testsNum);
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
        if (nbpPrinterInterfaces[i]->afterRunCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->afterRunCbk(
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

void nbp_printer_notify_run_test(nbp_test_details_t* test)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->runTestCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->runTestCbk(test);
        }
    }
}

void nbp_printer_notify_run_module(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->runModuleCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->runModuleCbk(module);
        }
    }
}

void nbp_printer_notify_run_module_completed(nbp_module_details_t* module)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->runModuleCompletedCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->runModuleCompletedCbk(module);
        }
    }
}

void nbp_printer_notify_check_result(nbp_test_details_t* test, const char* cond,
    int status, int line, const char* failureMsg, const char* successMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkResultCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->checkResultCbk(
                test,
                cond,
                status,
                line,
                failureMsg,
                successMsg
            );
        }
    }
}

void nbp_printer_notify_check_type_op_result(nbp_test_details_t* test,
    nbp_printer_type_value_t a, nbp_printer_type_value_t b, unsigned int type,
    unsigned int op, int status, int line, const char* failureMsg,
    const char* successMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->checkTypeOpResultCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->checkTypeOpResultCbk(
                test,
                a,
                b,
                type,
                op,
                status,
                line,
                failureMsg,
                successMsg
            );
        }
    }
}

void nbp_printer_notify_test_assert_result(nbp_test_details_t* test, const char* cond,
    int status, int line, const char* failureMsg, const char* successMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertResultCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testAssertResultCbk(
                test,
                cond,
                status,
                line,
                failureMsg,
                successMsg
            );
        }
    }
}

void nbp_printer_notify_test_assert_type_op_result(nbp_test_details_t* test,
    nbp_printer_type_value_t a, nbp_printer_type_value_t b, unsigned int type,
    unsigned int op, int status, int line, const char* failureMsg,
    const char* successMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->testAssertTypeOpResultCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->testAssertTypeOpResultCbk(
                test,
                a,
                b,
                type,
                op,
                status,
                line,
                failureMsg,
                successMsg
            );
        }
    }
}

void nbp_printer_notify_module_assert_result(nbp_test_details_t* test,
    const char* cond, int status, int line, const char* failureMsg,
    const char* successMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertResultCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleAssertResultCbk(
                test,
                cond,
                status,
                line,
                failureMsg,
                successMsg
            );
        }
    }
}

void nbp_printer_notify_module_assert_type_op_result(nbp_test_details_t* test,
    nbp_printer_type_value_t a, nbp_printer_type_value_t b, unsigned int type,
    unsigned int op, int status, int line, const char* failureMsg,
    const char* successMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->moduleAssertTypeOpResultCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->moduleAssertTypeOpResultCbk(
                test,
                a,
                b,
                type,
                op,
                status,
                line,
                failureMsg,
                successMsg
            );
        }
    }
}

void nbp_printer_notify_assert_result(nbp_test_details_t* test,
    const char* cond, int status, int line, const char* failureMsg,
    const char* successMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertResultCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertResultCbk(
                test,
                cond,
                status,
                line,
                failureMsg,
                successMsg
            );
        }
    }
}

void nbp_printer_notify_assert_type_op_result(nbp_test_details_t* test,
    nbp_printer_type_value_t a, nbp_printer_type_value_t b, unsigned int type,
    unsigned int op, int status, int line, const char* failureMsg,
    const char* successMsg)
{
    for (unsigned int i = 0; i < nbpPrinterInterfacesSize; i++) {
        if (nbpPrinterInterfaces[i]->assertTypeOpResultCbk != NBP_MEMORY_NULL_POINTER) {
            nbpPrinterInterfaces[i]->assertTypeOpResultCbk(
                test,
                a,
                b,
                type,
                op,
                status,
                line,
                failureMsg,
                successMsg
            );
        }
    }
}

#endif // end if NBP_PRIVATE_IMPL_PRINTER_H
