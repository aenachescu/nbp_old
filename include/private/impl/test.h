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

#ifndef NBP_PRIVATE_IMPL_TEST_H
#define NBP_PRIVATE_IMPL_TEST_H

unsigned int nbpTotalNumberOfTests = 0;

NBP_TEST_SETUP(nbp_test_empty_setup_func)
{
}

NBP_TEST_TEARDOWN(nbp_test_empty_teardown_func)
{
}

static void nbp_test_init(nbp_test_details_t* test,
    nbp_module_details_t* module, nbp_test_setup_pfn_t testSetup,
    nbp_test_teardown_pfn_t testTeardown)
{
    unsigned int state = NBP_SYNC_ATOMIC_UINT_CAS(
        &test->testState,
        NBP_TEST_STATE_NOT_INITIALIZED,
        NBP_TEST_STATE_READY
    );
    if (state != NBP_TEST_STATE_NOT_INITIALIZED) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_TEST_ALREADY_RAN);
        NBP_EXIT(NBP_ERROR_CODE_TEST_ALREADY_RAN);
    }

    test->testId = nbpTotalNumberOfTests;
    nbpTotalNumberOfTests++;

    test->module = module;
    test->module->isEmptyModule = 0;
    test->module->ownTests.num++;
    test->module->taskNum++;

    // reset setup function if it is the same with empty setup function
    if (test->testSetupFunc == nbp_test_setup_nbp_test_empty_setup_func) {
        test->testSetupFunc = NBP_MEMORY_NULL_POINTER;
    }

    // set setup function
    if (test->testSetupFunc == NBP_MEMORY_NULL_POINTER &&
        testSetup != NBP_MEMORY_NULL_POINTER &&
        testSetup != nbp_test_setup_nbp_test_empty_setup_func) {
        test->testSetupFunc = testSetup;
    }

    // reset teardown function if it is the same with empty teardown function
    if (test->testTeardownFunc == nbp_test_teardown_nbp_test_empty_teardown_func) {
        test->testTeardownFunc = NBP_MEMORY_NULL_POINTER;
    }

    // set teardown function
    if (test->testTeardownFunc == NBP_MEMORY_NULL_POINTER &&
        testTeardown != NBP_MEMORY_NULL_POINTER &&
        testTeardown != nbp_test_teardown_nbp_test_empty_teardown_func) {
        test->testTeardownFunc = testTeardown;
    }

    if (module->firstTest == NBP_MEMORY_NULL_POINTER) {
        module->firstTest = test;
        module->lastTest = test;
    } else {
        test->prev = module->lastTest;
        module->lastTest->next = test;
        module->lastTest = test;
    }
}

void nbp_test_run(nbp_test_details_t* test, nbp_module_details_t* module,
    nbp_test_setup_pfn_t testSetup, nbp_test_teardown_pfn_t testTeardown)
{
    if (nbpSchedulerInterface->addTest == NBP_MEMORY_NULL_POINTER) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_INVALID_SCHEDULER);
        NBP_EXIT(NBP_ERROR_CODE_INVALID_SCHEDULER);
    }

    nbp_test_init(test, module, testSetup, testTeardown);

    nbp_printer_notify_scheduling_test(test);
    nbpSchedulerInterface->addTest(test);
}

void nbp_test_run_ctx(nbp_test_details_t* test, void* ctx,
    nbp_module_details_t* module, nbp_test_setup_pfn_t testSetup,
    nbp_test_teardown_pfn_t testTeardown)
{
    if (nbpSchedulerInterface->addTestCtx == NBP_MEMORY_NULL_POINTER) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_INVALID_SCHEDULER);
        NBP_EXIT(NBP_ERROR_CODE_INVALID_SCHEDULER);
    }

    nbp_test_init(test, module, testSetup, testTeardown);

    nbp_printer_notify_scheduling_test(test);
    nbpSchedulerInterface->addTestCtx(test, ctx);
}

#endif // end if NBP_PRIVATE_IMPL_TEST_H
