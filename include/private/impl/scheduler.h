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

static void nbp_scheduler_update_module_stats(nbp_test_details_t* test)
{
    nbp_module_details_t* m = test->module;

    NBP_ATOMIC_UINT_ADD_AND_FETCH(
        &m->own.checks.numPassed,
        NBP_ATOMIC_UINT_LOAD(&test->checks.numPassed)
    );
    NBP_ATOMIC_UINT_ADD_AND_FETCH(
        &m->own.checks.numFailed,
        NBP_ATOMIC_UINT_LOAD(&test->checks.numFailed)
    );

    NBP_ATOMIC_UINT_ADD_AND_FETCH(
        &m->own.testAsserts.numPassed,
        NBP_ATOMIC_UINT_LOAD(&test->testAsserts.numPassed)
    );
    NBP_ATOMIC_UINT_ADD_AND_FETCH(
        &m->own.testAsserts.numFailed,
        NBP_ATOMIC_UINT_LOAD(&test->testAsserts.numFailed)
    );

    NBP_ATOMIC_UINT_ADD_AND_FETCH(
        &m->own.moduleAsserts.numPassed,
        NBP_ATOMIC_UINT_LOAD(&test->moduleAsserts.numPassed)
    );
    NBP_ATOMIC_UINT_ADD_AND_FETCH(
        &m->own.moduleAsserts.numFailed,
        NBP_ATOMIC_UINT_LOAD(&test->moduleAsserts.numFailed)
    );

    NBP_ATOMIC_UINT_ADD_AND_FETCH(
        &m->own.asserts.numPassed,
        NBP_ATOMIC_UINT_LOAD(&test->asserts.numPassed)
    );
    NBP_ATOMIC_UINT_ADD_AND_FETCH(
        &m->own.asserts.numFailed,
        NBP_ATOMIC_UINT_LOAD(&test->asserts.numFailed)
    );
}

static void nbp_scheduler_update_parent_stats(nbp_module_details_t* module)
{
    nbp_module_details_t* m = module;
    nbp_module_details_t* p = module->parent;

    if (p == 0x0) {
        return;
    }

#define NBP_PRIVATE_TMP_ADD(a, b)                                              \
    NBP_ATOMIC_UINT_ADD_AND_FETCH(&a, NBP_ATOMIC_UINT_LOAD(&b))

    // sub modules stats
    NBP_PRIVATE_TMP_ADD(p->subModules.numPassed, m->ownModules.numPassed);
    NBP_PRIVATE_TMP_ADD(p->subModules.numPassed, m->subModules.numPassed);
    NBP_PRIVATE_TMP_ADD(p->subModules.numFailed, m->ownModules.numFailed);
    NBP_PRIVATE_TMP_ADD(p->subModules.numFailed, m->subModules.numFailed);
    NBP_PRIVATE_TMP_ADD(p->subModules.numSkipped, m->ownModules.numSkipped);
    NBP_PRIVATE_TMP_ADD(p->subModules.numSkipped, m->subModules.numSkipped);

    // sub tests stats
    NBP_PRIVATE_TMP_ADD(p->subTests.numPassed, m->ownTests.numPassed);
    NBP_PRIVATE_TMP_ADD(p->subTests.numPassed, m->subTests.numPassed);
    NBP_PRIVATE_TMP_ADD(p->subTests.numFailed, m->ownTests.numFailed);
    NBP_PRIVATE_TMP_ADD(p->subTests.numFailed, m->subTests.numFailed);
    NBP_PRIVATE_TMP_ADD(p->subTests.numSkipped, m->ownTests.numSkipped);
    NBP_PRIVATE_TMP_ADD(p->subTests.numSkipped, m->subTests.numSkipped);

    // sub checks stats
    NBP_PRIVATE_TMP_ADD(p->sub.checks.numPassed, m->own.checks.numPassed);
    NBP_PRIVATE_TMP_ADD(p->sub.checks.numPassed, m->sub.checks.numPassed);
    NBP_PRIVATE_TMP_ADD(p->sub.checks.numFailed, m->own.checks.numFailed);
    NBP_PRIVATE_TMP_ADD(p->sub.checks.numFailed, m->sub.checks.numFailed);

    // sub test asserts stats
    NBP_PRIVATE_TMP_ADD(
        p->sub.testAsserts.numPassed,
        m->own.testAsserts.numPassed
    );
    NBP_PRIVATE_TMP_ADD(
        p->sub.testAsserts.numPassed,
        m->sub.testAsserts.numPassed
    );
    NBP_PRIVATE_TMP_ADD(
        p->sub.testAsserts.numFailed,
        m->own.testAsserts.numFailed
    );
    NBP_PRIVATE_TMP_ADD(
        p->sub.testAsserts.numFailed,
        m->sub.testAsserts.numFailed
    );

    // sub module asserts stats
    NBP_PRIVATE_TMP_ADD(
        p->sub.moduleAsserts.numPassed,
        m->own.moduleAsserts.numPassed
    );
    NBP_PRIVATE_TMP_ADD(
        p->sub.moduleAsserts.numPassed,
        m->sub.moduleAsserts.numPassed
    );
    NBP_PRIVATE_TMP_ADD(
        p->sub.moduleAsserts.numFailed,
        m->own.moduleAsserts.numFailed
    );
    NBP_PRIVATE_TMP_ADD(
        p->sub.moduleAsserts.numFailed,
        m->sub.moduleAsserts.numFailed
    );

    // sub asserts stats
    NBP_PRIVATE_TMP_ADD(p->sub.asserts.numPassed, m->own.asserts.numPassed);
    NBP_PRIVATE_TMP_ADD(p->sub.asserts.numPassed, m->sub.asserts.numPassed);
    NBP_PRIVATE_TMP_ADD(p->sub.asserts.numFailed, m->own.asserts.numFailed);
    NBP_PRIVATE_TMP_ADD(p->sub.asserts.numFailed, m->sub.asserts.numFailed);

#undef NBP_PRIVATE_TMP_ADD
}

static void nbp_scheduler_update_module_state(nbp_module_details_t* module)
{
    unsigned int numTests = NBP_ATOMIC_UINT_LOAD(&module->ownTests.num);
    unsigned int numModules = NBP_ATOMIC_UINT_LOAD(&module->ownModules.num);
    unsigned int oldVal;
    unsigned int state;

    if (numTests == NBP_ATOMIC_UINT_LOAD(&module->ownTests.numPassed) &&
        numModules == NBP_ATOMIC_UINT_LOAD(&module->ownModules.numPassed)) {
        state = NBP_MODULE_STATE_PASSED;
        goto end;
    }

    if (numTests == NBP_ATOMIC_UINT_LOAD(&module->ownTests.numSkipped) &&
        numModules == NBP_ATOMIC_UINT_LOAD(&module->ownModules.numSkipped)) {
        state = NBP_MODULE_STATE_SKIPPED;
        goto end;
    }

    state = NBP_MODULE_STATE_FAILED;
    goto end;

end:
    oldVal = NBP_ATOMIC_UINT_CAS(
        &module->moduleState,
        NBP_MODULE_STATE_RUNNING,
        state
    );
    if (oldVal != NBP_MODULE_STATE_RUNNING) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_INVALID_MODULE_STATE,
            "module is not running"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    if (module->parent == 0x0) {
        return;
    }

    NBP_ATOMIC_UINT_TYPE* parentNum;
    switch (state) {
        case NBP_MODULE_STATE_PASSED:
            parentNum = &module->parent->ownModules.numPassed;
            break;
        case NBP_MODULE_STATE_FAILED:
            parentNum = &module->parent->ownModules.numFailed;
            break;
        case NBP_MODULE_STATE_SKIPPED:
            parentNum = &module->parent->ownModules.numSkipped;
            break;
        default:
            NBP_HANDLE_ERROR_CTX_STRING(
                NBP_ERROR_INVALID_MODULE_STATE,
                "unknown module state"
            );
            NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    NBP_ATOMIC_UINT_ADD_AND_FETCH(parentNum, 1);
}

static void nbp_scheduler_update_test_state(nbp_test_details_t* test)
{
    do {
        if (NBP_ATOMIC_UINT_LOAD(&test->checks.numFailed) != 0) {
            break;
        }

        if (NBP_ATOMIC_UINT_LOAD(&test->testAsserts.numFailed) != 0) {
            break;
        }

        if (NBP_ATOMIC_UINT_LOAD(&test->moduleAsserts.numFailed) != 0) {
            break;
        }

        if (NBP_ATOMIC_UINT_LOAD(&test->asserts.numFailed) != 0) {
            break;
        }

        unsigned int oldVal = NBP_ATOMIC_UINT_CAS(
            &test->testState,
            NBP_TEST_STATE_RUNNING,
            NBP_TEST_STATE_PASSED
        );
        if (oldVal != NBP_TEST_STATE_RUNNING) {
            NBP_HANDLE_ERROR_CTX_STRING(
                NBP_ERROR_INVALID_TEST_STATE,
                "test is not running"
            );
            NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
        }

        NBP_ATOMIC_UINT_ADD_AND_FETCH(&test->module->ownTests.numPassed, 1);
        return;
    } while (0);

    unsigned int oldVal = NBP_ATOMIC_UINT_CAS(
        &test->testState,
        NBP_TEST_STATE_RUNNING,
        NBP_TEST_STATE_FAILED
    );
    if (oldVal != NBP_TEST_STATE_RUNNING) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_INVALID_TEST_STATE,
            "test is not running"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    NBP_ATOMIC_UINT_ADD_AND_FETCH(&test->module->ownTests.numFailed, 1);
}

static unsigned int nbp_scheduler_setup_module(nbp_module_details_t* module)
{
    if (module == 0x0) {
        return NBP_MODULE_FLAGS_PROCESSED;
    }

    unsigned int oldVal = NBP_ATOMIC_UINT_CAS(
        &module->flags,
        NBP_MODULE_FLAGS_NOT_INITIALIZED,
        NBP_MODULE_FLAGS_PROCESSED
    );

    if (oldVal == NBP_MODULE_FLAGS_SKIP) {
        return NBP_MODULE_FLAGS_SKIP;
    }

    if (oldVal == NBP_MODULE_FLAGS_PROCESSED) {
        NBP_WAIT_EVENT(module->setupEvent);

        oldVal = NBP_ATOMIC_UINT_LOAD(&module->flags);
        if (oldVal == NBP_MODULE_FLAGS_PROCESSED ||
            oldVal == NBP_MODULE_FLAGS_SKIP) {
            return oldVal;
        }

        NBP_HANDLE_ERROR(NBP_ERROR_MODULE_FLAGS_INVALID_VALUE);
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    if (oldVal == NBP_MODULE_FLAGS_NOT_INITIALIZED) {
        unsigned int parentFlags = nbp_scheduler_setup_module(module->parent);
        if (parentFlags == NBP_MODULE_FLAGS_PROCESSED) {
            if (module->setup) {
                module->setup(module);
            }
            NBP_SIGNAL_EVENT(module->setupEvent);
            return NBP_MODULE_FLAGS_PROCESSED;
        }

        if (parentFlags == NBP_MODULE_FLAGS_SKIP) {
            oldVal = NBP_ATOMIC_UINT_CAS(
                &module->flags,
                NBP_MODULE_FLAGS_PROCESSED,
                NBP_MODULE_FLAGS_SKIP
            );
            if (oldVal != NBP_MODULE_FLAGS_PROCESSED) {
                NBP_HANDLE_ERROR(NBP_ERROR_MODULE_FLAGS_INVALID_VALUE);
                NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
            }
            return NBP_MODULE_FLAGS_SKIP;
        }

        NBP_HANDLE_ERROR(NBP_ERROR_MODULE_FLAGS_INVALID_VALUE);
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    NBP_HANDLE_ERROR(NBP_ERROR_MODULE_FLAGS_INVALID_VALUE);
    NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
}

static void nbp_scheduler_verify_module_stats(nbp_module_details_t* module)
{
    unsigned int total, passed, failed, skipped;

    total   = NBP_ATOMIC_UINT_LOAD(&module->ownTests.num);
    passed  = NBP_ATOMIC_UINT_LOAD(&module->ownTests.numPassed);
    failed  = NBP_ATOMIC_UINT_LOAD(&module->ownTests.numFailed);
    skipped = NBP_ATOMIC_UINT_LOAD(&module->ownTests.numSkipped);
    if (total != passed + failed + skipped) {
        goto error;
    }

    total   = NBP_ATOMIC_UINT_LOAD(&module->ownModules.num);
    passed  = NBP_ATOMIC_UINT_LOAD(&module->ownModules.numPassed);
    failed  = NBP_ATOMIC_UINT_LOAD(&module->ownModules.numFailed);
    skipped = NBP_ATOMIC_UINT_LOAD(&module->ownModules.numSkipped);
    if (total != passed + failed + skipped) {
        goto error;
    }

    total   = NBP_ATOMIC_UINT_LOAD(&module->subTests.num);
    passed  = NBP_ATOMIC_UINT_LOAD(&module->subTests.numPassed);
    failed  = NBP_ATOMIC_UINT_LOAD(&module->subTests.numFailed);
    skipped = NBP_ATOMIC_UINT_LOAD(&module->subTests.numSkipped);
    if (total != passed + failed + skipped) {
        goto error;
    }

    total   = NBP_ATOMIC_UINT_LOAD(&module->subModules.num);
    passed  = NBP_ATOMIC_UINT_LOAD(&module->subModules.numPassed);
    failed  = NBP_ATOMIC_UINT_LOAD(&module->subModules.numFailed);
    skipped = NBP_ATOMIC_UINT_LOAD(&module->subModules.numSkipped);
    if (total != passed + failed + skipped) {
        goto error;
    }

    return;

error:
    NBP_HANDLE_ERROR_CTX_STRING(
        NBP_ERROR_INVALID_MODULE_STATS,
        "the sum of numPassed, numFailed and numSkipped is not equal to num"
    );
    NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
}

static void nbp_scheduler_teardown_module(nbp_module_details_t* module)
{
    unsigned int num, flags;
    while (1) {
        num = NBP_ATOMIC_UINT_ADD_AND_FETCH(&module->completedTaskNum, 1);
        if (NBP_ATOMIC_UINT_LOAD(&module->taskNum) > num) {
            break;
        }

        if (NBP_ATOMIC_UINT_LOAD(&module->taskNum) < num) {
            NBP_HANDLE_ERROR_CTX_STRING(
                NBP_ERROR_INVALID_MODULE_STATS,
                "there are too many completed tasks"
            );
            NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
        }

        nbp_scheduler_verify_module_stats(module);

        flags = NBP_ATOMIC_UINT_LOAD(&module->flags);
        if (flags == NBP_MODULE_FLAGS_PROCESSED) {
            if (module->teardown) {
                module->teardown(module);
            }
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

static void nbp_scheduler_skip_module(nbp_module_details_t* module)
{
    nbp_test_details_t* testIdx = module->firstTest;
    while (testIdx != 0x0) {
        NBP_ATOMIC_UINT_CAS(
            &testIdx->flags,
            NBP_TEST_FLAGS_NOT_INITIALIZED,
            NBP_TEST_FLAGS_SKIP
        );
        testIdx = testIdx->next;
    }

    nbp_module_details_t* moduleIdx = module->firstModule;
    unsigned int flags;
    while (moduleIdx != 0x0) {
        flags = NBP_ATOMIC_UINT_CAS(
            &moduleIdx->flags,
            NBP_MODULE_FLAGS_NOT_INITIALIZED,
            NBP_MODULE_FLAGS_SKIP
        );

        if (flags == NBP_MODULE_FLAGS_PROCESSED) {
            nbp_scheduler_skip_module(moduleIdx);
        }

        moduleIdx = moduleIdx->next;
    }
}

static void nbp_scheduler_run_test_running(nbp_test_details_t* test)
{
    nbp_notify_printer_test_begin(test);

    if (test->beforeTestFunc) {
        test->beforeTestFunc(test);
    }

    test->testFunc(test);

    if (NBP_ATOMIC_UINT_LOAD(&test->asserts.numFailed) != 0) {
        nbp_scheduler_skip_module(nbpMainModule);
    } else if (NBP_ATOMIC_UINT_LOAD(&test->moduleAsserts.numFailed) != 0) {
        nbp_scheduler_skip_module(test->module);
    }

    if (test->afterTestFunc) {
        test->afterTestFunc(test);
    }

    nbp_scheduler_update_test_state(test);
    nbp_scheduler_update_module_stats(test);

    nbp_notify_printer_test_end(test);
}

static void nbp_scheduler_run_test_skipped(nbp_test_details_t* test)
{
    nbp_notify_printer_test_begin(test);

    unsigned int oldVal = NBP_ATOMIC_UINT_CAS(
        &test->testState,
        NBP_TEST_STATE_RUNNING,
        NBP_TEST_STATE_SKIPPED
    );
    if (oldVal != NBP_TEST_STATE_RUNNING) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_INVALID_TEST_STATE,
            "test is not running"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    NBP_ATOMIC_UINT_ADD_AND_FETCH(&test->module->ownTests.numSkipped, 1);

    nbp_notify_printer_test_end(test);
}

static unsigned int nbp_scheduler_run_module(nbp_module_details_t* module)
{
    if (module == 0x0) {
        return NBP_MODULE_STATE_RUNNING;
    }

    unsigned int oldVal = NBP_ATOMIC_UINT_CAS(
        &module->moduleState,
        NBP_MODULE_STATE_READY,
        NBP_MODULE_STATE_RUNNING
    );

    if (oldVal == NBP_MODULE_STATE_RUNNING) {
        NBP_WAIT_EVENT(&module->runEvent);
        return NBP_MODULE_STATE_RUNNING;
    }

    if (oldVal == NBP_MODULE_STATE_READY) {
        unsigned int parentState = nbp_scheduler_run_module(module->parent);
        if (parentState != NBP_MODULE_STATE_RUNNING) {
            NBP_HANDLE_ERROR_CTX_STRING(
                NBP_ERROR_INVALID_MODULE_STATE,
                "parent module is not running"
            );
            NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
        }

        nbp_notify_printer_module_begin(module);
        NBP_SIGNAL_EVENT(&module->runEvent);

        return NBP_MODULE_STATE_RUNNING;
    }

    NBP_HANDLE_ERROR_CTX_STRING(
        NBP_ERROR_INVALID_MODULE_STATE,
        "module is not ready or running"
    );
    NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
}

void nbp_scheduler_run_test(nbp_test_details_t* test)
{
    // the test can be run only from NBP_SCHEDULER_FUNC_RUN function
    extern int nbpSchedulerRunEnabled;
    if (nbpSchedulerRunEnabled != 1) {
        NBP_HANDLE_ERROR(NBP_ERROR_SCHEDULER_RUN_DISABLED);
        return;
    }

    unsigned int oldVal = NBP_ATOMIC_UINT_CAS(
        &test->testState,
        NBP_TEST_STATE_READY,
        NBP_TEST_STATE_RUNNING
    );

    if (oldVal != NBP_TEST_STATE_READY) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_INVALID_TEST_STATE,
            "test is not ready"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    unsigned int moduleState = nbp_scheduler_run_module(test->module);
    if (moduleState != NBP_MODULE_STATE_RUNNING) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_INVALID_MODULE_STATE,
            "module is not running"
        );
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    oldVal = NBP_ATOMIC_UINT_CAS(
        &test->flags,
        NBP_TEST_FLAGS_NOT_INITIALIZED,
        NBP_TEST_FLAGS_PROCESSED
    );

    if (oldVal == NBP_TEST_FLAGS_NOT_INITIALIZED) {
        unsigned int moduleFlags = nbp_scheduler_setup_module(test->module);
        if (moduleFlags == NBP_MODULE_FLAGS_PROCESSED) {
            nbp_scheduler_run_test_running(test);
        } else if (moduleFlags == NBP_MODULE_FLAGS_SKIP) {
            nbp_scheduler_run_test_skipped(test);
        } else {
            NBP_HANDLE_ERROR(NBP_ERROR_MODULE_FLAGS_INVALID_VALUE);
            NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
        }
    } else if (oldVal == NBP_TEST_FLAGS_SKIP) {
        nbp_scheduler_run_test_skipped(test);
    } else {
        NBP_HANDLE_ERROR(NBP_ERROR_TEST_FLAGS_INVALID_VALUE);
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    nbp_scheduler_teardown_module(test->module);
}

#endif // end if NBP_PRIVATE_IMPL_SCHEDULER_H
