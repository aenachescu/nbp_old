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

static int nbp_scheduler_is_module_completed(nbp_module_details_t* module)
{
    unsigned int sum = 0;

    do {
        sum = module->ownTests.numPassed + module->ownTests.numFailed +
              module->ownTests.numSkipped;
        if (module->ownTests.num != sum) {
            break;
        }

        sum = module->ownModules.numPassed + module->ownModules.numFailed +
              module->ownModules.numSkipped;
        if (module->ownModules.num != sum) {
            break;
        }

        return 1;
    } while (0);

    return 0;
}

static void nbp_scheduler_update_module_stats(nbp_test_details_t* test)
{
    nbp_module_details_t* m = test->module;

    m->own.checks.numPassed += test->checks.numPassed;
    m->own.checks.numFailed += test->checks.numFailed;

    m->own.testAsserts.numPassed += test->testAsserts.numPassed;
    m->own.testAsserts.numFailed += test->testAsserts.numFailed;

    m->own.moduleAsserts.numPassed += test->moduleAsserts.numPassed;
    m->own.moduleAsserts.numFailed += test->moduleAsserts.numFailed;

    m->own.asserts.numPassed += test->asserts.numPassed;
    m->own.asserts.numFailed += test->asserts.numFailed;
}

static void nbp_scheduler_update_parent_stats(nbp_module_details_t* module)
{
    nbp_module_details_t* m = module;
    nbp_module_details_t* p = module->parent;

    if (p == 0x0) {
        return;
    }

    // sub modules stats
    p->subModules.numPassed     +=
        m->ownModules.numPassed + m->subModules.numPassed;
    p->subModules.numFailed     +=
        m->ownModules.numFailed + m->subModules.numFailed;
    p->subModules.numSkipped    +=
        m->ownModules.numSkipped + m->subModules.numSkipped;

    // sub tests stats
    p->subTests.numPassed   += m->ownTests.numPassed + m->subTests.numPassed;
    p->subTests.numFailed   += m->ownTests.numFailed + m->subTests.numFailed;
    p->subTests.numSkipped  += m->ownTests.numSkipped + m->subTests.numSkipped;

    // sub checks stats
    p->sub.checks.numPassed +=
        m->own.checks.numPassed + m->sub.checks.numPassed;
    p->sub.checks.numFailed +=
        m->own.checks.numFailed + m->sub.checks.numFailed;

    // sub test asserts stats
    p->sub.testAsserts.numPassed +=
        m->own.testAsserts.numPassed + m->sub.testAsserts.numPassed;
    p->sub.testAsserts.numFailed +=
        m->own.testAsserts.numFailed + m->sub.testAsserts.numFailed;

    // sub module asserts stats
    p->sub.moduleAsserts.numPassed +=
        m->own.moduleAsserts.numPassed + m->sub.moduleAsserts.numPassed;
    p->sub.moduleAsserts.numFailed +=
        m->own.moduleAsserts.numFailed + m->sub.moduleAsserts.numFailed;

    // sub asserts stats
    p->sub.asserts.numPassed +=
        m->own.asserts.numPassed + m->sub.asserts.numPassed;
    p->sub.asserts.numFailed +=
        m->own.asserts.numFailed + m->sub.asserts.numFailed;
}

static void nbp_scheduler_update_module_state(nbp_module_details_t* module)
{
    if (module->ownTests.num == module->ownTests.numPassed &&
        module->ownModules.num == module->ownModules.numPassed) {
        module->moduleState = NBP_MODULE_STATE_PASSED;
        if (module->parent != 0x0) {
            module->parent->ownModules.numPassed++;
        }
        return;
    }

    if (module->ownTests.num == module->ownTests.numSkipped &&
        module->ownModules.num == module->ownModules.numSkipped) {
        module->moduleState = NBP_MODULE_STATE_SKIPPED;
        if (module->parent != 0x0) {
            module->parent->ownModules.numSkipped++;
        }
        return;
    }

    module->moduleState = NBP_MODULE_STATE_FAILED;
    if (module->parent != 0x0) {
        module->parent->ownModules.numFailed++;
    }
}

static void nbp_scheduler_update_test_state(nbp_test_details_t* test)
{
    do {
        if (test->checks.numFailed != 0) {
            break;
        }

        if (test->testAsserts.numFailed != 0) {
            break;
        }

        if (test->moduleAsserts.numFailed != 0) {
            break;
        }

        if (test->asserts.numFailed != 0) {
            break;
        }

        test->testState = NBP_TEST_STATE_PASSED;
        test->module->ownTests.numPassed++;
        return;
    } while (0);

    test->testState = NBP_TEST_STATE_FAILED;
    test->module->ownTests.numFailed++;
}

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
    while (nbp_scheduler_is_module_completed(module)) {
        if (module->teardown) {
            module->teardown(module);
        }

        nbp_scheduler_update_module_state(module);
        nbp_scheduler_update_parent_stats(module);

        nbp_notify_printer_module_end(module);

        module = module->parent;
        if (module == 0x0) {
            break;
        }
    }
}

void nbp_scheduler_run_test(nbp_test_details_t* test)
{
    extern int nbpSchedulerRunEnabled;
    if (nbpSchedulerRunEnabled != 1) {
        // TODO: notify printer
        return;
    }

    if (test->testState == NBP_TEST_STATE_SKIPPED) {
        // TODO
        return;
    }

    if (test->testState != NBP_TEST_STATE_READY) {
        // TODO: notify printer
        return;
    }

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

    nbp_scheduler_update_test_state(test);
    nbp_scheduler_update_module_stats(test);

    nbp_notify_printer_test_end(test);

    nbp_scheduler_teardown_module(test->module);
}

#endif // end if NBP_PRIVATE_IMPL_SCHEDULER_H

