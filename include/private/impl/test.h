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

static unsigned int nbpTotalNumberOfTests = 0;

static NBP_ERROR_TYPE nbp_test_init(nbp_test_details_t* test,
    nbp_module_details_t* module, nbp_test_setup_pfn_t testSetup,
    nbp_test_teardown_pfn_t testTeardown)
{
    unsigned int state = NBP_ATOMIC_UINT_CAS(
        &test->testState,
        NBP_TEST_STATE_NOT_INITIALIZED,
        NBP_TEST_STATE_READY
    );
    if (state != NBP_TEST_STATE_NOT_INITIALIZED) {
        NBP_HANDLE_ERROR(NBP_ERROR_TEST_ALREADY_CALLED);
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    test->testId = nbpTotalNumberOfTests;
    nbpTotalNumberOfTests++;

    test->module = module;
    test->testSetupFunc = testSetup;
    test->testTeardownFunc = testTeardown;
    NBP_ATOMIC_UINT_ADD_AND_FETCH(&test->module->ownTests.num, 1);
    NBP_ATOMIC_UINT_ADD_AND_FETCH(&test->module->taskNum, 1);

    if (module->firstTest == NBP_MEMORY_NULL_POINTER) {
        module->firstTest = test;
        module->lastTest = test;
    } else {
        test->prev = module->lastTest;
        module->lastTest->next = test;
        module->lastTest = test;
    }

    return NBP_NO_ERROR;
}

void nbp_test_run(nbp_test_details_t* test, nbp_module_details_t* module,
    nbp_test_setup_pfn_t testSetup, nbp_test_teardown_pfn_t testTeardown)
{
    if (nbpSchedulerInterface->addTest == NBP_MEMORY_NULL_POINTER) {
        NBP_HANDLE_ERROR(NBP_ERROR_SCHEDULER_NO_ADD_TEST_FUNC);
        NBP_EXIT(NBP_EXIT_STATUS_INVALID_SCHEDULER);
    }

    NBP_ERROR_TYPE err = nbp_test_init(test, module, testSetup, testTeardown);
    if (err != NBP_NO_ERROR) {
        return;
    }

    nbp_printer_notify_scheduling_test(test);
    nbpSchedulerInterface->addTest(test);
}

void nbp_test_run_ctx(nbp_test_details_t* test, void* ctx,
    nbp_module_details_t* module, nbp_test_setup_pfn_t testSetup,
    nbp_test_teardown_pfn_t testTeardown)
{
    if (nbpSchedulerInterface->addTestCtx == NBP_MEMORY_NULL_POINTER) {
        NBP_HANDLE_ERROR(NBP_ERROR_SCHEDULER_NO_ADD_TEST_FUNC);
        NBP_EXIT(NBP_EXIT_STATUS_INVALID_SCHEDULER);
    }

    NBP_ERROR_TYPE err = nbp_test_init(test, module, testSetup, testTeardown);
    if (err != NBP_NO_ERROR) {
        return;
    }

    nbp_printer_notify_scheduling_test(test);
    nbpSchedulerInterface->addTestCtx(test, ctx);
}

#endif // end if NBP_PRIVATE_IMPL_TEST_H
