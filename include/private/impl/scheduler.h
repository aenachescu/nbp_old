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

#ifndef NBP_PRIVATE_IMPL_SCHEDULER_H
#define NBP_PRIVATE_IMPL_SCHEDULER_H

static void nbp_scheduler_setup_module(nbp_module_details_t* module)
{
    if (module == 0x0) {
        return;
    }

    if (module->moduleState == NBP_MODULE_STATE_RUNNING) {
        return;
    }

    nbp_scheduler_setup_module(module->parent);

    module->moduleState = NBP_MODULE_STATE_RUNNING;
    nbp_notify_printer_module_begin(module);
    if (module->setup) {
        module->setup(module);
    }
}

static void nbp_scheduler_teardown_module(nbp_module_details_t* module)
{
    while (module->numTests == module->numCompletedTests &&
        module->numSubmodules == module->numCompletedSubmodules) {
        if (module->teardown) {
            module->teardown(module);
        }
        nbp_notify_printer_module_end(module);
        module->moduleState = NBP_MODULE_STATE_COMPLETED;

        module = module->parent;
        if (module == 0x0) {
            break;
        }

        module->numCompletedSubmodules++;
    }
}

void nbp_scheduler_run_test(nbp_test_details_t* test)
{
    nbp_scheduler_setup_module(test->module);

    test->testState = NBP_TEST_STATE_RUNNING;

    nbp_notify_printer_test_begin(test);

    if (test->beforeTestFunc) {
        test->beforeTestFunc(test);
    }

    test->testFunc(test);

    if (test->afterTestFunc) {
        test->afterTestFunc(test);
    }

    nbp_notify_printer_test_end(test);

    test->testState = NBP_TEST_STATE_COMPLETED;

    test->module->numCompletedTests++;

    nbp_scheduler_teardown_module(test->module);
}

#endif // end if NBP_PRIVATE_IMPL_SCHEDULER_H

