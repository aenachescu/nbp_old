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

#ifndef NBP_PRIVATE_IMPL_MODULE_H
#define NBP_PRIVATE_IMPL_MODULE_H

void nbp_call_module(nbp_module_details_t* module, nbp_module_details_t* parent)
{
    unsigned int state = NBP_ATOMIC_UINT_CAS(
        &module->moduleState,
        NBP_MODULE_STATE_NOT_INITIALIZED,
        NBP_MODULE_STATE_READY
    );
    if (state != NBP_MODULE_STATE_NOT_INITIALIZED) {
        NBP_HANDLE_ERROR(NBP_ERROR_MODULE_ALREADY_CALLED);
        return;
    }

    int errCode = NBP_EVENT_INIT(module->runEvent);
    if (errCode != NBP_NO_ERROR) {
        NBP_HANDLE_ERROR(errCode);
        NBP_EXIT(errCode);
    }

    errCode = NBP_EVENT_INIT(module->setupEvent);
    if (errCode != NBP_NO_ERROR) {
        NBP_HANDLE_ERROR(errCode);
        NBP_EXIT(errCode);
    }

    module->parent = parent;

    if (parent != 0x0) {
        NBP_ATOMIC_UINT_ADD_AND_FETCH(&parent->ownModules.num, 1);
        NBP_ATOMIC_UINT_ADD_AND_FETCH(&parent->taskNum, 1);
        if (parent->firstModule == 0x0) {
            parent->firstModule = module;
            parent->lastModule = module;
        } else {
            module->prev = parent->lastModule;
            parent->lastModule->next = module;
            parent->lastModule = module;
        }

        module->depth = parent->depth + 1;
    }

    nbp_notify_printer_before_scheduling_module(module);
    module->moduleFunc(module, 0x0, 0x0);
    nbp_notify_printer_after_scheduling_module(module);

    nbp_module_details_t* idx = module->firstModule;
    while (idx != 0x0) {
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

NBP_SETUP_MODULE(nbp_empty_setup_func)
{
    (void)(NBP_THIS_MODULE);
}

NBP_TEARDOWN_MODULE(nbp_empty_teardown_func)
{
    (void)(NBP_THIS_MODULE);
}

#endif // end if NBP_PRIVATE_IMPL_MODULE_H
