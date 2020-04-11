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

static unsigned int nbpTotalNumberOfModules = 0;

static NBP_ERROR_TYPE nbp_module_init(nbp_module_details_t* module,
    nbp_module_details_t* parent)
{
    unsigned int state = NBP_ATOMIC_UINT_CAS(
        &module->moduleState,
        NBP_MODULE_STATE_NOT_INITIALIZED,
        NBP_MODULE_STATE_READY
    );
    if (state != NBP_MODULE_STATE_NOT_INITIALIZED) {
        NBP_HANDLE_ERROR(NBP_ERROR_MODULE_ALREADY_CALLED);
        NBP_EXIT(NBP_EXIT_STATUS_GENERIC_ERROR);
    }

    int errCode = NBP_EVENT_INIT(module->runEvent);
    if (errCode != NBP_NO_ERROR) {
        NBP_HANDLE_ERROR(errCode);
        NBP_EXIT(NBP_EXIT_STATUS_EVENT_ERROR);
    }

    errCode = NBP_EVENT_INIT(module->setupEvent);
    if (errCode != NBP_NO_ERROR) {
        NBP_HANDLE_ERROR(errCode);
        NBP_EXIT(NBP_EXIT_STATUS_EVENT_ERROR);
    }

    module->moduleId = nbpTotalNumberOfTests;
    nbpTotalNumberOfModules++;

    module->parent = parent;

    if (parent != NBP_MEMORY_NULL_POINTER) {
        NBP_ATOMIC_UINT_ADD_AND_FETCH(&parent->ownModules.num, 1);
        NBP_ATOMIC_UINT_ADD_AND_FETCH(&parent->taskNum, 1);
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

    return NBP_NO_ERROR;
}

static void nbp_module_update_stats(nbp_module_details_t* module)
{
    nbp_module_details_t* idx = module->firstModule;
    while (idx != NBP_MEMORY_NULL_POINTER) {
        NBP_ATOMIC_UINT_ADD_AND_FETCH(
            &module->subModules.num,
            NBP_ATOMIC_UINT_LOAD(&idx->ownModules.num)
        );
        NBP_ATOMIC_UINT_ADD_AND_FETCH(
            &module->subModules.num,
            NBP_ATOMIC_UINT_LOAD(&idx->subModules.num)
        );
        NBP_ATOMIC_UINT_ADD_AND_FETCH(
            &module->subTests.num,
            NBP_ATOMIC_UINT_LOAD(&idx->ownTests.num)
        );
        NBP_ATOMIC_UINT_ADD_AND_FETCH(
            &module->subTests.num,
            NBP_ATOMIC_UINT_LOAD(&idx->subTests.num)
        );
        idx = idx->next;
    }
}

void nbp_call_module(nbp_module_details_t* module, nbp_module_details_t* parent)
{
    if (nbp_module_init(module, parent) != NBP_NO_ERROR) {
        return;
    }

    nbp_notify_printer_before_scheduling_module(module);

    if (nbpSchedulerInterface->moduleStarted != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->moduleStarted(module);
    }

    module->moduleFunc(module, NBP_MEMORY_NULL_POINTER, NBP_MEMORY_NULL_POINTER);

    if (nbpSchedulerInterface->moduleCompleted != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->moduleCompleted(module);
    }

    nbp_notify_printer_after_scheduling_module(module);

    nbp_module_update_stats(module);
}

void nbp_call_module_ctx(nbp_module_details_t* module, void* ctx,
    nbp_module_details_t* parent)
{
    if (nbp_module_init(module, parent) != NBP_NO_ERROR) {
        return;
    }

    nbp_notify_printer_before_scheduling_module(module);

    if (nbpSchedulerInterface->moduleStartedCtx != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->moduleStartedCtx(module, ctx);
    }

    module->moduleFunc(module, NBP_MEMORY_NULL_POINTER, NBP_MEMORY_NULL_POINTER);

    if (nbpSchedulerInterface->moduleCompleted != NBP_MEMORY_NULL_POINTER) {
        nbpSchedulerInterface->moduleCompleted(module);
    }

    nbp_notify_printer_after_scheduling_module(module);

    nbp_module_update_stats(module);
}

NBP_SETUP_MODULE(nbp_empty_setup_func)
{
}

NBP_TEARDOWN_MODULE(nbp_empty_teardown_func)
{
}

#endif // end if NBP_PRIVATE_IMPL_MODULE_H
