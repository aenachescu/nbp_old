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

    if (module->firstTest == NBP_NULL_POINTER) {
        module->firstTest = test;
        module->lastTest = test;
    } else {
        test->prev = module->lastTest;
        module->lastTest->next = test;
        module->lastTest = test;
    }

    return NBP_NO_ERROR;
}

void nbp_call_test(nbp_test_details_t* test, nbp_module_details_t* module,
    nbp_test_setup_pfn_t testSetup, nbp_test_teardown_pfn_t testTeardown)
{
    if (nbpSchedulerInterface->addTest == NBP_NULL_POINTER) {
        NBP_HANDLE_ERROR(NBP_ERROR_SCHEDULER_NO_ADD_TEST_FUNC);
        NBP_EXIT(NBP_EXIT_STATUS_INVALID_SCHEDULER);
    }

    NBP_ERROR_TYPE err = nbp_test_init(test, module, testSetup, testTeardown);
    if (err != NBP_NO_ERROR) {
        return;
    }

    nbp_notify_printer_scheduling_test(test);
    nbpSchedulerInterface->addTest(test);
}

void nbp_call_test_ctx(nbp_test_details_t* test, void* ctx,
    nbp_module_details_t* module, nbp_test_setup_pfn_t testSetup,
    nbp_test_teardown_pfn_t testTeardown)
{
    if (nbpSchedulerInterface->addTestCtx == NBP_NULL_POINTER) {
        NBP_HANDLE_ERROR(NBP_ERROR_SCHEDULER_NO_ADD_TEST_FUNC);
        NBP_EXIT(NBP_EXIT_STATUS_INVALID_SCHEDULER);
    }

    NBP_ERROR_TYPE err = nbp_test_init(test, module, testSetup, testTeardown);
    if (err != NBP_NO_ERROR) {
        return;
    }

    nbp_notify_printer_scheduling_test(test);
    nbpSchedulerInterface->addTestCtx(test, ctx);
}

#endif // end if NBP_PRIVATE_IMPL_TEST_H
