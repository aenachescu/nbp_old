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

struct nbp_scheduler_data_t {
    nbp_test_details_t* test;
    struct nbp_scheduler_data_t* next;
};
typedef struct nbp_scheduler_data_t nbp_scheduler_data_t;

static nbp_scheduler_data_t nbpSchedulerData;
static nbp_scheduler_data_t* nbpSchedulerDataLast;

NBP_SCHEDULER_FUNC_INIT(basic_scheduler_init)
{
    nbpSchedulerData.test = 0x0;
    nbpSchedulerData.next = 0x0;
    nbpSchedulerDataLast = &nbpSchedulerData;
}

NBP_SCHEDULER_FUNC_UNINIT(basic_scheduler_uninit)
{
    nbp_scheduler_data_t* data = nbpSchedulerData.next;
    nbp_scheduler_data_t* tmp = 0x0;
    while (data != 0x0) {
        tmp = data;
        data = data->next;
        NBP_FREE(tmp);
    }
}

NBP_SCHEDULER_FUNC_RUN(basic_scheduler_run)
{
    nbp_scheduler_data_t* data = &nbpSchedulerData;
    while (data->test != 0x0) {
        NBP_SCHEDULER_RUN_TEST(data->test);
        data = data->next;
    }
}

NBP_SCHEDULER_FUNC_ADD_TEST(basic_scheduler_add_test)
{
    nbpSchedulerDataLast->test = NBP_THIS_TEST;
    nbpSchedulerDataLast->next =
        (nbp_scheduler_data_t*) NBP_ALLOC(sizeof(nbp_scheduler_data_t));

    if (nbpSchedulerDataLast->next == 0x0) {
        nbp_notify_printer_handle_error(NBP_ERROR_ALLOC);
        return;
    }

    nbpSchedulerDataLast = nbpSchedulerDataLast->next;
    nbpSchedulerDataLast->next = 0x0;
    nbpSchedulerDataLast->test = 0x0;
}

NBP_DEFINE_SCHEDULER(
    nbpScheduler,
    NBP_SCHEDULER_USE_FUNC_INIT(basic_scheduler_init),
    NBP_SCHEDULER_USE_FUNC_UNINIT(basic_scheduler_uninit),
    NBP_SCHEDULER_USE_FUNC_RUN(basic_scheduler_run),
    NBP_SCHEDULER_USE_FUNC_ADD_TEST(basic_scheduler_add_test)
);

#endif // end if NBP_PRIVATE_SCHEDULER_BASIC_SCHEDULER_H
