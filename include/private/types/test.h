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

#ifndef NBP_PRIVATE_TYPES_TEST_H
#define NBP_PRIVATE_TYPES_TEST_H

#define NBP_TEST_STATE_NOT_INITIALIZED  0
#define NBP_TEST_STATE_READY            1
#define NBP_TEST_STATE_RUNNING          2
#define NBP_TEST_STATE_COMPLETED        3
#define NBP_TEST_STATE_SKIPPED          4

struct nbp_test_details_t;

typedef void (*nbp_before_test_pfn_t)(
    struct nbp_test_details_t*
);

typedef void (*nbp_after_test_pfn_t)(
    struct nbp_test_details_t*
);

typedef void (*nbp_test_pfn_t)(
    struct nbp_test_details_t*
);

struct nbp_test_details_t {
    const char* testName;
    nbp_test_pfn_t testFunc;
    nbp_before_test_pfn_t beforeTestFunc;
    nbp_after_test_pfn_t afterTestFunc;
    struct nbp_module_details_t* module;
    unsigned int passedChecks;
    unsigned int failedChecks;
    unsigned int passedTestAsserts;
    unsigned int failedTestAsserts;
    unsigned int passedModuleAsserts;
    unsigned int failedModuleAsserts;
    unsigned int passedAsserts;
    unsigned int failedAsserts;
    unsigned int testState;
    struct nbp_test_details_t* next;
    struct nbp_test_details_t* prev;
};
typedef struct nbp_test_details_t nbp_test_details_t;

#endif // end if NBP_PRIVATE_TYPES_TEST_H
