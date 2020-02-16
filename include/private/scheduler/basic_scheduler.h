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

#ifndef NBP_PRIVATE_SCHEDULER_BASIC_SCHEDULER_H
#define NBP_PRIVATE_SCHEDULER_BASIC_SCHEDULER_H

#ifdef NBP_LIBRARY_MAIN

struct nbp_scheduler_data_t {
    nbp_test_details_t* test;
    struct nbp_scheduler_data_t* next;
};
typedef struct nbp_scheduler_data_t nbp_scheduler_data_t;

static nbp_scheduler_data_t nbpSchedulerData;
static nbp_scheduler_data_t* nbpSchedulerDataLast;

NBP_SCHEDULER_FUNC_INIT(nbp_basic_scheduler_init)
{
    nbpSchedulerData.test = NBP_NULL_POINTER;
    nbpSchedulerData.next = NBP_NULL_POINTER;
    nbpSchedulerDataLast = &nbpSchedulerData;
}

NBP_SCHEDULER_FUNC_UNINIT(nbp_basic_scheduler_uninit)
{
    nbp_scheduler_data_t* data = nbpSchedulerData.next;
    nbp_scheduler_data_t* tmp = NBP_NULL_POINTER;
    while (data != NBP_NULL_POINTER) {
        tmp = data;
        data = data->next;
        NBP_FREE(tmp);
    }
}

NBP_SCHEDULER_FUNC_RUN(nbp_basic_scheduler_run)
{
    nbp_scheduler_data_t* data = &nbpSchedulerData;
    while (data->test != NBP_NULL_POINTER) {
        NBP_SCHEDULER_RUN_TEST(data->test);
        data = data->next;
    }
}

NBP_SCHEDULER_FUNC_ADD_TEST(nbp_basic_scheduler_add_test)
{
    nbpSchedulerDataLast->test = NBP_THIS_TEST;
    nbpSchedulerDataLast->next =
        (nbp_scheduler_data_t*) NBP_ALLOC(sizeof(nbp_scheduler_data_t));

    if (nbpSchedulerDataLast->next == NBP_NULL_POINTER) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_ALLOC,
            "could not add test"
        );
        return;
    }

    nbpSchedulerDataLast = nbpSchedulerDataLast->next;
    nbpSchedulerDataLast->next = NBP_NULL_POINTER;
    nbpSchedulerDataLast->test = NBP_NULL_POINTER;
}

NBP_DEFINE_SCHEDULER(
    nbpDefaultScheduler,
    NBP_SCHEDULER_USE_FUNC_INIT(nbp_basic_scheduler_init),
    NBP_SCHEDULER_USE_FUNC_UNINIT(nbp_basic_scheduler_uninit),
    NBP_SCHEDULER_USE_FUNC_RUN(nbp_basic_scheduler_run),
    NBP_SCHEDULER_USE_FUNC_ADD_TEST(nbp_basic_scheduler_add_test),
    NBP_SCHEDULER_NO_FUNC_ADD_TEST_CTX,
    NBP_SCHEDULER_NO_FUNC_MODULE_STARTED,
    NBP_SCHEDULER_NO_FUNC_MODULE_STARTED_CTX,
    NBP_SCHEDULER_NO_FUNC_MODULE_COMPLETED
);

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_PRIVATE_SCHEDULER_BASIC_SCHEDULER_H
