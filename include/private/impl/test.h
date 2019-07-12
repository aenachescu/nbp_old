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

void nbp_call_test(nbp_test_details_t* test, nbp_module_details_t* module,
    nbp_before_test_pfn_t beforeTest, nbp_after_test_pfn_t afterTest)
{
    if (test->testState != NBP_TEST_STATE_NOT_INITIALIZED) {
        nbp_notify_printer_handle_error(NBP_ERROR_TEST_ALREADY_CALLED);
        return;
    }

    test->testState = NBP_TEST_STATE_READY;
    test->module = module;
    test->beforeTestFunc = beforeTest;
    test->afterTestFunc = afterTest;
    test->module->ownTests.num++;

    if (module->firstTest == 0x0) {
        module->firstTest = test;
        module->lastTest = test;
    } else {
        test->prev = module->lastTest;
        module->lastTest->next = test;
        module->lastTest = test;
    }

    nbpSchedulerInterface->addTest(test);
}

#endif // end if NBP_PRIVATE_IMPL_TEST_H
