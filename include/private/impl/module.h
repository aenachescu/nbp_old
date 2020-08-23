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

#ifndef NBP_PRIVATE_IMPL_MODULE_H
#define NBP_PRIVATE_IMPL_MODULE_H

unsigned int nbpTotalNumberOfModules = 0;

// these fixtures are not run because if they are used then the fixture pfn will
// be replace with NBP_MEMORY_NULL_POINTER
// LCOV_EXCL_START
NBP_MODULE_SETUP(nbp_module_empty_setup_func)
{
}

NBP_MODULE_TEARDOWN(nbp_module_empty_teardown_func)
{
}
// LCOV_EXCL_STOP

static void nbp_module_init(nbp_module_details_t* module,
    nbp_module_details_t* parent, nbp_module_setup_pfn_t setupFunc,
    nbp_module_teardown_pfn_t teardownFunc)
{
    unsigned int state = NBP_SYNC_ATOMIC_UINT_CAS(
        &module->moduleState,
        NBP_MODULE_STATE_NOT_INITIALIZED,
        NBP_MODULE_STATE_READY
    );
    if (state != NBP_MODULE_STATE_NOT_INITIALIZED) {
        NBP_ERROR_REPORT(NBP_ERROR_CODE_MODULE_ALREADY_RUN);
        NBP_EXIT(NBP_ERROR_CODE_MODULE_ALREADY_RUN);
    }

    int errCode = NBP_SYNC_EVENT_INIT(module->runEvent);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_SYNC_EVENT_INIT.
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(errCode);
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }

    errCode = NBP_SYNC_EVENT_INIT(module->setupEvent);
    if (errCode != NBP_ERROR_CODE_SUCCESS) {
        // these lines are excluded from coverage because it is pretty hard to
        // trigger an error for NBP_SYNC_EVENT_INIT.
        // LCOV_EXCL_START
        NBP_ERROR_REPORT(errCode);
        NBP_EXIT(errCode);
        // LCOV_EXCL_STOP
    }

    nbp_module_setup_pfn_t emptyModuleSetup =
        NBP_PP_CONCAT(nbp_module_setup_, nbp_module_empty_setup_func);
    if (module->setup == emptyModuleSetup) {
        module->setup = NBP_MEMORY_NULL_POINTER;
    }

    if (module->setup == NBP_MEMORY_NULL_POINTER &&
        setupFunc != NBP_MEMORY_NULL_POINTER &&
        setupFunc != emptyModuleSetup) {
        module->setup = setupFunc;
    }

    nbp_module_teardown_pfn_t emptyModuleTeardown =
        NBP_PP_CONCAT(nbp_module_teardown_, nbp_module_empty_teardown_func);
    if (module->teardown == emptyModuleTeardown) {
        module->teardown = NBP_MEMORY_NULL_POINTER;
    }

    if (module->teardown == NBP_MEMORY_NULL_POINTER &&
        teardownFunc != NBP_MEMORY_NULL_POINTER &&
        teardownFunc != emptyModuleTeardown) {
        module->teardown = teardownFunc;
    }

    module->moduleId = nbpTotalNumberOfModules;
    nbpTotalNumberOfModules++;

    module->parent = parent;

    if (parent != NBP_MEMORY_NULL_POINTER) {
        parent->ownModules.num++;
        parent->taskNum++;
        if (parent->firstModule == NBP_MEMORY_NULL_POINTER) {
            parent->firstModule = module;
            parent->lastModule = module;
        } else {
            module->prev = parent->lastModule;
            parent->lastModule->next = module;
            parent->lastModule = module;
        }

        module->depth = parent->depth + 1;
    }
}

static void nbp_module_update_stats(nbp_module_details_t* module)
{
    nbp_module_details_t* idx = module->firstModule;
    while (idx != NBP_MEMORY_NULL_POINTER) {
        module->subModules.num += idx->ownModules.num;
        module->subModules.num += idx->subModules.num;
        module->subTests.num   += idx->ownTests.num;
        module->subTests.num   += idx->subTests.num;

        if (idx->isEmptyModule == 0) {
            module->isEmptyModule = 0;
        } else {
            module->emptySubmodulesNum++;
        }

        idx = idx->next;
    }
}

void nbp_module_run(nbp_module_details_t* module, nbp_module_details_t* parent,
    nbp_module_setup_pfn_t setupFunc, nbp_module_teardown_pfn_t teardownFunc)
{
    nbp_module_init(module, parent, setupFunc, teardownFunc);

    nbp_printer_notify_before_scheduling_module(module);

    nbp_scheduler_notify_module_started(module);

    module->moduleFunc(
        module,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER
    );

    nbp_scheduler_notify_module_completed(module);

    nbp_module_update_stats(module);

    nbp_printer_notify_after_scheduling_module(module);
}

void nbp_module_run_ctx(nbp_module_details_t* module, void* ctx,
    nbp_module_details_t* parent, nbp_module_setup_pfn_t setupFunc,
    nbp_module_teardown_pfn_t teardownFunc)
{
    nbp_module_init(module, parent, setupFunc, teardownFunc);

    nbp_printer_notify_before_scheduling_module(module);

    nbp_scheduler_notify_module_started_ctx(module, ctx);

    module->moduleFunc(
        module,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER,
        NBP_MEMORY_NULL_POINTER
    );

    nbp_scheduler_notify_module_completed(module);

    nbp_module_update_stats(module);

    nbp_printer_notify_after_scheduling_module(module);
}

#endif // end if NBP_PRIVATE_IMPL_MODULE_H
