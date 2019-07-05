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

#ifndef NBP_PRIVATE_TYPES_MODULE_H
#define NBP_PRIVATE_TYPES_MODULE_H

#define NBP_MODULE_STATE_NOT_INITIALIZED  0
#define NBP_MODULE_STATE_READY            1
#define NBP_MODULE_STATE_RUNNING          2
#define NBP_MODULE_STATE_COMPLETED        3
#define NBP_MODULE_STATE_SKIPPED          4

struct nbp_module_details_t;

typedef void(*nbp_setup_module_pfn_t)(
    struct nbp_module_details_t*
);

typedef void(*nbp_teardown_module_pfn_t)(
    struct nbp_module_details_t*
);

typedef void (*nbp_module_pfn_t)(
    struct nbp_module_details_t*,
    nbp_before_test_pfn_t,
    nbp_after_test_pfn_t
);

struct nbp_module_details_t {
    const char* moduleName;
    nbp_module_pfn_t moduleFunc;
    nbp_setup_module_pfn_t setup;
    nbp_teardown_module_pfn_t teardown;
    struct nbp_test_details_t* firstTest;
    struct nbp_test_details_t* lastTest;
    struct nbp_module_details_t* parent;
    struct nbp_module_details_t* firstSubmodule;
    struct nbp_module_details_t* lastSubmodule;
    struct nbp_module_details_t* next;
    struct nbp_module_details_t* prev;
    unsigned int numTests;
    unsigned int numCompletedTests;
    unsigned int numSubmodules;
    unsigned int numCompletedSubmodules;
    unsigned int moduleState;
    unsigned int depth;
};
typedef struct nbp_module_details_t nbp_module_details_t;

#endif // end if NBP_PRIVATE_TYPES_MODULE_H
