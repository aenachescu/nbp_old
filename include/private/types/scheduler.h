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

#ifndef NBP_PRIVATE_TYPES_SCHEDULER_H
#define NBP_PRIVATE_TYPES_SCHEDULER_H

typedef void (*nbp_scheduler_init_pfn_t)(
    void
);

typedef void (*nbp_scheduler_uninit_pfn_t)(
    void
);

typedef void (*nbp_scheduler_run_pfn_t)(
    void
);

typedef void (*nbp_scheduler_add_test_pfn_t)(
    nbp_test_details_t*
);

struct nbp_scheduler_interface_t {
    nbp_scheduler_init_pfn_t init;
    nbp_scheduler_uninit_pfn_t uninit;
    nbp_scheduler_run_pfn_t run;
    nbp_scheduler_add_test_pfn_t addTest;
};
typedef struct nbp_scheduler_interface_t nbp_scheduler_interface_t;

#endif // end if NBP_PRIVATE_TYPES_SCHEDULER_H
