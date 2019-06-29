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

static void nbp_basic_scheduler_setup_module(nbp_module_details_t* module)
{
    if (module == 0x0) {
        return;
    }

    if (module->moduleState == NBP_MODULE_STATE_RUNNING) {
        return;
    }

    nbp_basic_scheduler_setup_module(module->parent);

    module->moduleState = NBP_MODULE_STATE_RUNNING;
    nbp_notify_printer_module_begin(module);
    if (module->setup) {
        module->setup(module);
    }
}

static void nbp_basic_scheduler_run_test(nbp_test_details_t* test)
{
    test->testState = NBP_TEST_STATE_RUNNING;

    nbp_notify_printer_test_begin(test);

    if (test->beforeTestFunc) {
        test->beforeTestFunc(test);
    }

    test->testFunc(test);

    if (test->afterTestFunc) {
        test->afterTestFunc(test);
    }

    nbp_notify_printer_test_end(test);

    test->testState = NBP_TEST_STATE_COMPLETED;

    test->module->numCompletedTests++;
}

static void nbp_basic_scheduler_teardown_module(nbp_module_details_t* module)
{
    while (module->numTests == module->numCompletedTests &&
        module->numSubmodules == module->numCompletedSubmodules) {
        if (module->teardown) {
            module->teardown(module);
        }
        nbp_notify_printer_module_end(module);
        module->moduleState = NBP_MODULE_STATE_COMPLETED;

        module = module->parent;
        if (module == 0x0) {
            break;
        }

        module->numCompletedSubmodules++;
    }
}

static void nbp_basic_scheduler_init(void)
{
    nbpSchedulerData.test = 0x0;
    nbpSchedulerData.next = 0x0;
    nbpSchedulerDataLast = &nbpSchedulerData;
}

static void nbp_basic_scheduler_uninit(void)
{
    nbp_scheduler_data_t* data = nbpSchedulerData.next;
    nbp_scheduler_data_t* tmp = 0x0;
    while (data != 0x0) {
        tmp = data;
        data = data->next;
        NBP_FREE(tmp);
    }
}

static void nbp_basic_scheduler_run(void)
{
    nbp_scheduler_data_t* data = &nbpSchedulerData;
    while (data->test != 0x0) {
        nbp_basic_scheduler_setup_module(data->test->module);
        nbp_basic_scheduler_run_test(data->test);
        nbp_basic_scheduler_teardown_module(data->test->module);
        data = data->next;
    }
}

static void nbp_basic_scheduler_add_test(nbp_test_details_t* test)
{
    nbpSchedulerDataLast->test = test;
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

nbp_scheduler_interface_t nbpScheduler = {
    .init = nbp_basic_scheduler_init,
    .uninit = nbp_basic_scheduler_uninit,
    .run = nbp_basic_scheduler_run,
    .addTest = nbp_basic_scheduler_add_test
};

#endif // end if NBP_PRIVATE_SCHEDULER_BASIC_SCHEDULER_H
