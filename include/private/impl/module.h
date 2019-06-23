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
    if (module->moduleState != NBP_MODULE_STATE_NOT_INITIALIZED) {
        nbp_notify_printer_handle_error(NBP_ERROR_MODULE_ALREADY_CALLED);
        return;
    }

    module->moduleState = NBP_MODULE_STATE_READY;
    module->parent = parent;

    if (parent != 0x0) {
        parent->numSubmodules++;
        if (parent->firstSubmodule == 0x0) {
            parent->firstSubmodule = module;
            parent->lastSubmodule = module;
        } else {
            module->prev = parent->lastSubmodule;
            parent->lastSubmodule->next = module;
            parent->lastSubmodule = module;
        }

        module->deepth = parent->deepth + 1;
    }

    module->moduleFunc(module, 0x0, 0x0);
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
