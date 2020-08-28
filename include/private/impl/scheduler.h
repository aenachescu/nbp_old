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

#ifndef NBP_PRIVATE_IMPL_SCHEDULER_H
#define NBP_PRIVATE_IMPL_SCHEDULER_H

NBP_SYNC_ATOMIC_UINT_TYPE nbpNumberOfRunTests = NBP_SYNC_ATOMIC_UINT_INIT(0);

static void nbp_scheduler_update_module_stats(nbp_test_details_t* test)
{
    nbp_module_details_t* m = test->module;

    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(
        &m->asserts.nonFatal.numPassed,
        test->asserts.nonFatal.numPassed
    );
    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(
        &m->asserts.nonFatal.numFailed,
        test->asserts.nonFatal.numFailed
    );

    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(
        &m->asserts.fatalForTest.numPassed,
        test->asserts.fatalForTest.numPassed
    );
    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(
        &m->asserts.fatalForTest.numFailed,
        test->asserts.fatalForTest.numFailed
    );

    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(
        &m->asserts.fatalForModule.numPassed,
        test->asserts.fatalForModule.numPassed
    );
    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(
        &m->asserts.fatalForModule.numFailed,
        test->asserts.fatalForModule.numFailed
    );

    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(
        &m->asserts.fatal.numPassed,
        test->asserts.fatal.numPassed
    );
    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(
        &m->asserts.fatal.numFailed,
        test->asserts.fatal.numFailed
    );
}

static void nbp_scheduler_update_parent_stats(nbp_module_details_t* module)
{
    nbp_module_details_t* m = module;
    nbp_module_details_t* p = module->parent;

    if (p == NBP_MEMORY_NULL_POINTER) {
        return;
    }

#define NBP_PRIVATE_TMP_ADD(a, b)                                              \
    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(&a, NBP_SYNC_ATOMIC_UINT_LOAD(&b))

    // modules stats
    NBP_PRIVATE_TMP_ADD(p->modules.numPassed, m->modules.numPassed);
    NBP_PRIVATE_TMP_ADD(p->modules.numFailed, m->modules.numFailed);
    NBP_PRIVATE_TMP_ADD(p->modules.numSkipped, m->modules.numSkipped);

    // tests stats
    NBP_PRIVATE_TMP_ADD(p->tests.numPassed, m->tests.numPassed);
    NBP_PRIVATE_TMP_ADD(p->tests.numFailed, m->tests.numFailed);
    NBP_PRIVATE_TMP_ADD(p->tests.numSkipped, m->tests.numSkipped);

    // non fatal asserts stats
    NBP_PRIVATE_TMP_ADD(
        p->asserts.nonFatal.numPassed,
        m->asserts.nonFatal.numPassed
    );
    NBP_PRIVATE_TMP_ADD(
        p->asserts.nonFatal.numFailed,
        m->asserts.nonFatal.numFailed
    );

    // fatal for test asserts stats
    NBP_PRIVATE_TMP_ADD(
        p->asserts.fatalForTest.numPassed,
        m->asserts.fatalForTest.numPassed
    );
    NBP_PRIVATE_TMP_ADD(
        p->asserts.fatalForTest.numFailed,
        m->asserts.fatalForTest.numFailed
    );

    // fatal for module asserts stats
    NBP_PRIVATE_TMP_ADD(
        p->asserts.fatalForModule.numPassed,
        m->asserts.fatalForModule.numPassed
    );
    NBP_PRIVATE_TMP_ADD(
        p->asserts.fatalForModule.numFailed,
        m->asserts.fatalForModule.numFailed
    );

    // fatal asserts stats
    NBP_PRIVATE_TMP_ADD(p->asserts.fatal.numPassed, m->asserts.fatal.numPassed);
    NBP_PRIVATE_TMP_ADD(p->asserts.fatal.numFailed, m->asserts.fatal.numFailed);

#undef NBP_PRIVATE_TMP_ADD
}

static void nbp_scheduler_update_module_state(nbp_module_details_t* module)
{
    unsigned int numPassedTests = NBP_SYNC_ATOMIC_UINT_LOAD(
        &module->tests.numPassed
    );
    unsigned int numSkippedTests = NBP_SYNC_ATOMIC_UINT_LOAD(
        &module->tests.numSkipped
    );
    unsigned int numPassedModules = NBP_SYNC_ATOMIC_UINT_LOAD(
        &module->modules.numPassed
    );
    unsigned int numSkippedModules = NBP_SYNC_ATOMIC_UINT_LOAD(
        &module->modules.numSkipped
    );
    unsigned int oldVal;
    unsigned int state;

    if (module->tests.num == numPassedTests &&
        module->modules.num == numPassedModules) {
        state = NBP_MODULE_STATE_PASSED;
        goto end;
    }

    if (module->tests.num == numSkippedTests &&
        module->modules.num == numSkippedModules) {
        state = NBP_MODULE_STATE_SKIPPED;
        goto end;
    }

    state = NBP_MODULE_STATE_FAILED;
    goto end;

end:
    oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
        &module->moduleState,
        NBP_MODULE_STATE_RUNNING,
        state
    );
    if (oldVal != NBP_MODULE_STATE_RUNNING) {
        // these lines are excluded from coverage because it is impossible to
        // have other state if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE,
            "module is not running"
        );
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE);
        // LCOV_EXCL_STOP
    }

    if (module->parent == NBP_MEMORY_NULL_POINTER) {
        return;
    }

    NBP_SYNC_ATOMIC_UINT_TYPE* parentNum;
    switch (state) {
        case NBP_MODULE_STATE_PASSED:
            parentNum = &module->parent->modules.numPassed;
            break;
        case NBP_MODULE_STATE_FAILED:
            parentNum = &module->parent->modules.numFailed;
            break;
        case NBP_MODULE_STATE_SKIPPED:
            parentNum = &module->parent->modules.numSkipped;
            break;
        default:
            // these lines are excluded from coverage because it is impossible
            // to have other state if there is no sync issue
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE,
                "unknown module state"
            );
            NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE);
            // LCOV_EXCL_STOP
    }

    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(parentNum, 1);
}

static void nbp_scheduler_update_test_state(nbp_test_details_t* test)
{
    do {
        if (test->asserts.nonFatal.numFailed != 0) {
            break;
        }

        if (test->asserts.fatalForTest.numFailed != 0) {
            break;
        }

        if (test->asserts.fatalForModule.numFailed != 0) {
            break;
        }

        if (test->asserts.fatal.numFailed != 0) {
            break;
        }

        unsigned int oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
            &test->testState,
            NBP_TEST_STATE_RUNNING,
            NBP_TEST_STATE_PASSED
        );
        if (oldVal != NBP_TEST_STATE_RUNNING) {
            // these lines are excluded from coverage because it is impossible
            // to have other state if there is no sync issue
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_UNEXPECTED_TEST_STATE,
                "test is not running"
            );
            NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_TEST_STATE);
            // LCOV_EXCL_STOP
        }

        NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(&test->module->tests.numPassed, 1);
        return;
    } while (0);

    unsigned int oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
        &test->testState,
        NBP_TEST_STATE_RUNNING,
        NBP_TEST_STATE_FAILED
    );
    if (oldVal != NBP_TEST_STATE_RUNNING) {
        // these lines are excluded from coverage because it is impossible to
        // have other state if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_UNEXPECTED_TEST_STATE,
            "test is not running"
        );
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_TEST_STATE);
        // LCOV_EXCL_STOP
    }

    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(&test->module->tests.numFailed, 1);
}

static unsigned int nbp_scheduler_setup_module(nbp_module_details_t* module)
{
    if (module == NBP_MEMORY_NULL_POINTER) {
        return NBP_MODULE_PRIVATE_SKIP_PROCESSED;
    }

    unsigned int oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
        &module->isSkipped,
        NBP_MODULE_PRIVATE_SKIP_NOT_SET,
        NBP_MODULE_PRIVATE_SKIP_PROCESSED
    );

    if (oldVal == NBP_MODULE_PRIVATE_SKIP_SET) {
        return NBP_MODULE_PRIVATE_SKIP_SET;
    }

    if (oldVal == NBP_MODULE_PRIVATE_SKIP_PROCESSED) {
        NBP_ERROR_CODE_TYPE errCode = NBP_SYNC_EVENT_WAIT(module->setupEvent);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_SYNC_EVENT_WAIT
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        oldVal = NBP_SYNC_ATOMIC_UINT_LOAD(&module->isSkipped);
        if (oldVal == NBP_MODULE_PRIVATE_SKIP_PROCESSED ||
            oldVal == NBP_MODULE_PRIVATE_SKIP_SET) {
            return oldVal;
        }

        // these lines are excluded from coverage because it is impossible to
        // have other value if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
        // LCOV_EXCL_STOP
    }

    if (oldVal == NBP_MODULE_PRIVATE_SKIP_NOT_SET) {
        unsigned int parentFlags = nbp_scheduler_setup_module(module->parent);
        if (parentFlags == NBP_MODULE_PRIVATE_SKIP_PROCESSED) {
            if (module->setupFunc != NBP_MEMORY_NULL_POINTER) {
                module->setupFunc(module);
            }

            NBP_ERROR_CODE_TYPE errCode = NBP_SYNC_EVENT_NOTIFY(module->setupEvent);
            if (errCode != NBP_ERROR_CODE_SUCCESS) {
                // these lines are excluded from coverage because it is pretty
                // hard to trigger an error for NBP_SYNC_EVENT_WAIT
                // LCOV_EXCL_START
                NBP_ERROR_REPORT(errCode);
                NBP_EXIT(errCode);
                // LCOV_EXCL_STOP
            }

            return NBP_MODULE_PRIVATE_SKIP_PROCESSED;
        }

        if (parentFlags == NBP_MODULE_PRIVATE_SKIP_SET) {
            oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
                &module->isSkipped,
                NBP_MODULE_PRIVATE_SKIP_PROCESSED,
                NBP_MODULE_PRIVATE_SKIP_SET
            );
            if (oldVal != NBP_MODULE_PRIVATE_SKIP_PROCESSED) {
                // these lines are excluded from coverage because it is
                // impossible to have other value if there is no sync issue
                // LCOV_EXCL_START
                NBP_ERROR_REPORT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
                NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
                // LCOV_EXCL_STOP
            }
            return NBP_MODULE_PRIVATE_SKIP_SET;
        }

        // these lines are excluded from coverage because it is impossible to
        // have other value if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
        // LCOV_EXCL_STOP
    }

    // these lines are excluded from coverage because it is impossible to have
    // other value if there is no sync issue
    // LCOV_EXCL_START
    NBP_ERROR_REPORT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
    NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
    // LCOV_EXCL_STOP
}

static void nbp_scheduler_verify_module_stats(nbp_module_details_t* module)
{
    unsigned int passed, failed, skipped;

    passed  = NBP_SYNC_ATOMIC_UINT_LOAD(&module->tests.numPassed);
    failed  = NBP_SYNC_ATOMIC_UINT_LOAD(&module->tests.numFailed);
    skipped = NBP_SYNC_ATOMIC_UINT_LOAD(&module->tests.numSkipped);
    if (module->tests.num != passed + failed + skipped) {
        // this line is excluded from coverage because it is impossible to have
        // other value if there is no sync issue
        // LCOV_EXCL_START
        goto error;
        // LCOV_EXCL_STOP
    }

    passed  = NBP_SYNC_ATOMIC_UINT_LOAD(&module->modules.numPassed);
    failed  = NBP_SYNC_ATOMIC_UINT_LOAD(&module->modules.numFailed);
    skipped = NBP_SYNC_ATOMIC_UINT_LOAD(&module->modules.numSkipped);
    if (module->modules.num != passed + failed + skipped) {
        // this line is excluded from coverage because it is impossible to have
        // other value if there is no sync issue
        // LCOV_EXCL_START
        goto error;
        // LCOV_EXCL_STOP
    }

    return;

    // these lines are excluded from coverage because it is impossible to have
    // other value if there is no sync issue
    // LCOV_EXCL_START
error:
    NBP_ERROR_REPORT_CTX_STRING(
        NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA,
        "the sum of numPassed, numFailed and numSkipped is not equal to num"
    );
    NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
    // LCOV_EXCL_STOP
}

static void nbp_scheduler_teardown_module(nbp_module_details_t* module)
{
    unsigned int num = 0;
    unsigned int isSkipped = 0;
    unsigned int numOfCompletedEmptySubmodules = 0;
    unsigned int moduleState = 0;
    NBP_ERROR_CODE_TYPE errCode;
    nbp_module_details_t* moduleIdx;

    while (1) {
        numOfCompletedEmptySubmodules = 0;
        num = NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(&module->completedTaskNum, 1);

        if (module->emptySubmodulesNum != 0 &&
            module->taskNum == num + module->emptySubmodulesNum) {
            num += module->emptySubmodulesNum;

            moduleIdx = module->firstModule;
            while (moduleIdx != NBP_MEMORY_NULL_POINTER) {
                moduleState = NBP_SYNC_ATOMIC_UINT_LOAD(&moduleIdx->moduleState);
                if (moduleState == NBP_MODULE_STATE_READY) {
                    nbp_scheduler_complete_empty_module(moduleIdx);
                    numOfCompletedEmptySubmodules++;
                }

                moduleIdx = moduleIdx->next;
            }

            if (module->emptySubmodulesNum != numOfCompletedEmptySubmodules) {
                // these lines are excluded from coverage because it is
                // impossible to have other value if there is no sync issue
                // LCOV_EXCL_START
                NBP_ERROR_REPORT_CTX_STRING(
                    NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA,
                    "unexpected number of completed empty submodules"
                );
                NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
                // LCOV_EXCL_STOP
            }
        }

        if (module->taskNum > num) {
            break;
        }

        if (module->taskNum < num) {
            // these lines are excluded from coverage because it is impossible
            // to have more completed task than the number of task if there is
            // no sync issue
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA,
                "there are too many completed tasks"
            );
            NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
            // LCOV_EXCL_STOP
        }

        nbp_scheduler_verify_module_stats(module);

        isSkipped = NBP_SYNC_ATOMIC_UINT_LOAD(&module->isSkipped);
        if (isSkipped == NBP_MODULE_PRIVATE_SKIP_PROCESSED) {
            if (module->teardownFunc != NBP_MEMORY_NULL_POINTER) {
                module->teardownFunc(module);
            }
        }

        nbp_scheduler_update_module_state(module);
        nbp_scheduler_update_parent_stats(module);

        nbp_printer_notify_module_completed(module);

        errCode = NBP_SYNC_EVENT_UNINIT(module->runEvent);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_SYNC_EVENT_UNINIT
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        errCode = NBP_SYNC_EVENT_UNINIT(module->setupEvent);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_SYNC_EVENT_UNINIT
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        module = module->parent;
        if (module == NBP_MEMORY_NULL_POINTER) {
            break;
        }
    }
}

static void nbp_scheduler_skip_module(nbp_module_details_t* module)
{
    nbp_test_details_t* testIdx = module->firstTest;
    while (testIdx != NBP_MEMORY_NULL_POINTER) {
        NBP_SYNC_ATOMIC_UINT_CAS(
            &testIdx->isSkipped,
            NBP_TEST_PRIVATE_SKIP_NOT_SET,
            NBP_TEST_PRIVATE_SKIP_SET
        );
        testIdx = testIdx->next;
    }

    nbp_module_details_t* moduleIdx = module->firstModule;
    unsigned int isSkipped;
    while (moduleIdx != NBP_MEMORY_NULL_POINTER) {
        isSkipped = NBP_SYNC_ATOMIC_UINT_CAS(
            &moduleIdx->isSkipped,
            NBP_MODULE_PRIVATE_SKIP_NOT_SET,
            NBP_MODULE_PRIVATE_SKIP_SET
        );

        if (isSkipped == NBP_MODULE_PRIVATE_SKIP_PROCESSED) {
            nbp_scheduler_skip_module(moduleIdx);
        }

        moduleIdx = moduleIdx->next;
    }
}

static void nbp_scheduler_run_test_running(nbp_test_details_t* test)
{
    nbp_printer_notify_test_started(test);

    if (test->testSetupFunc != NBP_MEMORY_NULL_POINTER) {
        test->testSetupFunc(test);
    }

    test->testFunc(
        test,
        NBP_ASSERT_NON_FATAL,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER
    );

    if (test->asserts.fatal.numFailed != 0) {
        nbp_scheduler_skip_module(nbpMainModule);
    } else if (test->asserts.fatalForModule.numFailed != 0) {
        nbp_scheduler_skip_module(test->module);
    }

    if (test->testTeardownFunc != NBP_MEMORY_NULL_POINTER) {
        test->testTeardownFunc(test);
    }

    nbp_scheduler_update_test_state(test);
    nbp_scheduler_update_module_stats(test);

    nbp_printer_notify_test_completed(test);
}

static void nbp_scheduler_run_test_skipped(nbp_test_details_t* test)
{
    nbp_printer_notify_test_started(test);

    unsigned int oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
        &test->testState,
        NBP_TEST_STATE_RUNNING,
        NBP_TEST_STATE_SKIPPED
    );
    if (oldVal != NBP_TEST_STATE_RUNNING) {
        // these lines are excluded from coverage because it is impossible to
        // have other state if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_UNEXPECTED_TEST_STATE,
            "test is not running"
        );
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_TEST_STATE);
        // LCOV_EXCL_STOP
    }

    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(&test->module->tests.numSkipped, 1);

    nbp_printer_notify_test_completed(test);
}

static unsigned int nbp_scheduler_run_module(nbp_module_details_t* module)
{
    if (module == NBP_MEMORY_NULL_POINTER) {
        return NBP_MODULE_STATE_RUNNING;
    }

    unsigned int oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
        &module->moduleState,
        NBP_MODULE_STATE_READY,
        NBP_MODULE_STATE_RUNNING
    );

    if (oldVal == NBP_MODULE_STATE_RUNNING) {
        NBP_ERROR_CODE_TYPE errCode = NBP_SYNC_EVENT_WAIT(module->runEvent);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_SYNC_EVENT_WAIT
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        return NBP_MODULE_STATE_RUNNING;
    }

    if (oldVal == NBP_MODULE_STATE_READY) {
        unsigned int parentState = nbp_scheduler_run_module(module->parent);
        if (parentState != NBP_MODULE_STATE_RUNNING) {
            // these lines are excluded from coverage because it is impossible
            // to have other state if there is no sync issue
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE,
                "parent module is not running"
            );
            NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE);
            // LCOV_EXCL_STOP
        }

        nbp_printer_notify_module_started(module);

        NBP_ERROR_CODE_TYPE errCode = NBP_SYNC_EVENT_NOTIFY(module->runEvent);
        if (errCode != NBP_ERROR_CODE_SUCCESS) {
            // these lines are excluded from coverage because it is pretty hard
            // to trigger an error for NBP_SYNC_EVENT_NOTIFY
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(errCode);
            NBP_EXIT(errCode);
            // LCOV_EXCL_STOP
        }

        return NBP_MODULE_STATE_RUNNING;
    }

    // these lines are excluded from coverage because it is impossible to have
    // other state if there is no sync issue
    // LCOV_EXCL_START
    NBP_ERROR_REPORT_CTX_STRING(
        NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE,
        "module is not ready or running"
    );
    NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE);
    // LCOV_EXCL_STOP
}

void nbp_scheduler_notify_init(void)
{
    nbpSchedulerInterface->configFunc(nbpSchedulerInterface);

    if (nbpSchedulerInterface->initCbk != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->initCbk();
    }
}

void nbp_scheduler_notify_uninit(void)
{
    if (nbpSchedulerInterface->uninitCbk != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->uninitCbk();
    }
}

void nbp_scheduler_notify_run(void)
{
    if (nbpSchedulerInterface->runCbk != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->runCbk();
    }
}

void nbp_scheduler_notify_run_test(nbp_test_details_t* test)
{
    if (nbpSchedulerInterface->runTestCbk != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->runTestCbk(test);
    } else {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_INVALID_SCHEDULER);
        NBP_EXIT(NBP_ERROR_CODE_INVALID_SCHEDULER);
    }
}

void nbp_scheduler_notify_run_test_ctx(nbp_test_details_t* test, void* ctx)
{
    if (nbpSchedulerInterface->runTestCtxCbk != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->runTestCtxCbk(test, ctx);
    } else {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_INVALID_SCHEDULER);
        NBP_EXIT(NBP_ERROR_CODE_INVALID_SCHEDULER);
    }
}

void nbp_scheduler_notify_run_module(nbp_module_details_t* module)
{
    if (nbpSchedulerInterface->runModuleCbk != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->runModuleCbk(module);
    }
}

void nbp_scheduler_notify_run_module_ctx(nbp_module_details_t* module,
    void* ctx)
{
    if (nbpSchedulerInterface->runModuleCtxCbk != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->runModuleCtxCbk(module, ctx);
    }
}

void nbp_scheduler_notify_run_module_completed(nbp_module_details_t* module)
{
    if (nbpSchedulerInterface->runModuleCompletedCbk != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->runModuleCompletedCbk(module);
    }
}

void nbp_scheduler_run_test(nbp_test_details_t* test)
{
    // the test can be run only from NBP_SCHEDULER_FUNC_RUN function
    extern int nbpSchedulerRunEnabled;
    if (nbpSchedulerRunEnabled != 1) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger this error
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(NBP_ERROR_CODE_SCHEDULER_RUN_DISABLED);
        return;
        // LCOV_EXCL_STOP
    }

    unsigned int oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
        &test->testState,
        NBP_TEST_STATE_READY,
        NBP_TEST_STATE_RUNNING
    );

    if (oldVal != NBP_TEST_STATE_READY) {
        // these lines are excluded from coverage because it is impossible to
        // have other state if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_UNEXPECTED_TEST_STATE,
            "test is not ready"
        );
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_TEST_STATE);
        // LCOV_EXCL_STOP
    }

    unsigned int moduleState = nbp_scheduler_run_module(test->module);
    if (moduleState != NBP_MODULE_STATE_RUNNING) {
        // these lines are excluded from coverage because it is impossible to
        // have other state if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE,
            "module is not running"
        );
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE);
        // LCOV_EXCL_STOP
    }

    oldVal = NBP_SYNC_ATOMIC_UINT_CAS(
        &test->isSkipped,
        NBP_TEST_PRIVATE_SKIP_NOT_SET,
        NBP_TEST_PRIVATE_SKIP_PROCESSED
    );

    if (oldVal == NBP_TEST_PRIVATE_SKIP_NOT_SET) {
        unsigned int moduleFlags = nbp_scheduler_setup_module(test->module);
        if (moduleFlags == NBP_MODULE_PRIVATE_SKIP_PROCESSED) {
            nbp_scheduler_run_test_running(test);
        } else if (moduleFlags == NBP_MODULE_PRIVATE_SKIP_SET) {
            nbp_scheduler_run_test_skipped(test);
        } else {
            // these lines are excluded from coverage because it is impossible
            // to have other value if there is no sync issue
            // LCOV_EXCL_START
            NBP_ERROR_REPORT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
            NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
            // LCOV_EXCL_STOP
        }
    } else if (oldVal == NBP_TEST_PRIVATE_SKIP_SET) {
        nbp_scheduler_run_test_skipped(test);
    } else {
        // these lines are excluded from coverage because it is impossible to
        // have other value if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
        // LCOV_EXCL_STOP
    }

    nbp_scheduler_teardown_module(test->module);

    NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(&nbpNumberOfRunTests, 1);
}

void nbp_scheduler_complete_empty_module(nbp_module_details_t* module)
{
    unsigned int numberOfCompletedTasks;
    unsigned int moduleState;
    nbp_module_details_t* moduleIdx;
    NBP_ERROR_CODE_TYPE errCode;

    // starting module

    moduleState = NBP_SYNC_ATOMIC_UINT_CAS(
        &module->moduleState,
        NBP_MODULE_STATE_READY,
        NBP_MODULE_STATE_RUNNING
    );
    if (moduleState != NBP_MODULE_STATE_READY) {
        // these lines are excluded from coverage because it is impossible to
        // have other state if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE,
            "unexpected module state"
        );
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE);
        // LCOV_EXCL_STOP
    }

    nbp_printer_notify_module_started(module);

    // iterating over all empty submodules

    moduleIdx = module->firstModule;
    while (moduleIdx != NBP_MEMORY_NULL_POINTER) {
        moduleState = NBP_SYNC_ATOMIC_UINT_LOAD(&moduleIdx->moduleState);
        if (moduleState != NBP_MODULE_STATE_READY) {
            // these lines are excluded from coverage because it is impossible
            // to have other state if there is no sync issue
            // LCOV_EXCL_START
            NBP_ERROR_REPORT_CTX_STRING(
                NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE,
                "unexpected module state"
            );
            NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE);
            // LCOV_EXCL_STOP
        }

        nbp_scheduler_complete_empty_module(moduleIdx);

        moduleIdx = moduleIdx->next;
    }

    // sanity check

    numberOfCompletedTasks = NBP_SYNC_ATOMIC_UINT_LOAD(&module->completedTaskNum);

    if (module->taskNum != numberOfCompletedTasks) {
        // these lines are excluded from coverage because it is impossible to
        // have other value if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA,
            "number of completed tasks is not equal to number of tasks"
        );
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA);
        // LCOV_EXCL_STOP
    }

    // update state & stats

    moduleState = NBP_SYNC_ATOMIC_UINT_CAS(
        &module->moduleState,
        NBP_MODULE_STATE_RUNNING,
        NBP_MODULE_STATE_PASSED
    );
    if (moduleState != NBP_MODULE_STATE_RUNNING) {
        // these lines are excluded from coverage because it is impossible to
        // have other state if there is no sync issue
        // LCOV_EXCL_START
        NBP_ERROR_REPORT_CTX_STRING(
            NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE,
            "unexpected module state"
        );
        NBP_EXIT(NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE);
        // LCOV_EXCL_STOP
    }

    nbp_scheduler_verify_module_stats(module);

    if (module->parent != NBP_MEMORY_NULL_POINTER) {
        NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(&module->parent->completedTaskNum, 1);
        NBP_SYNC_ATOMIC_UINT_ADD_AND_FETCH(&module->parent->modules.numPassed, 1);
    }

    nbp_scheduler_update_parent_stats(module);

    nbp_printer_notify_module_completed(module);

    // destroy events

    errCode = NBP_SYNC_EVENT_UNINIT(module->runEvent);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_SYNC_EVENT_UNINIT
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(errCode);
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }

    errCode = NBP_SYNC_EVENT_UNINIT(module->setupEvent);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_SYNC_EVENT_UNINIT
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(errCode);
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }
}

#endif // end if NBP_PRIVATE_IMPL_SCHEDULER_H
