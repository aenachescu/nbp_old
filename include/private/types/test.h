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

#define NBP_TEST_STATE_NOT_INITIALIZED  (unsigned int) 0
#define NBP_TEST_STATE_READY            (unsigned int) 1
#define NBP_TEST_STATE_RUNNING          (unsigned int) 2
#define NBP_TEST_STATE_PASSED           (unsigned int) 3
#define NBP_TEST_STATE_FAILED           (unsigned int) 4
#define NBP_TEST_STATE_SKIPPED          (unsigned int) 5

#define NBP_TEST_FLAGS_NOT_INITIALIZED  (unsigned int) 0
#define NBP_TEST_FLAGS_SKIP             (unsigned int) 1
#define NBP_TEST_FLAGS_PROCESSED        (unsigned int) 2

struct nbp_test_details_t;

typedef void (*nbp_before_test_pfn_t)(
    struct nbp_test_details_t* /* current test */
);

typedef void (*nbp_after_test_pfn_t)(
    struct nbp_test_details_t* /* current test */
);

typedef void (*nbp_test_pfn_t)(
    struct nbp_test_details_t* /* current test */
);

struct nbp_test_details_t {
    const char* testName;
    nbp_test_pfn_t testFunc;
    struct nbp_module_details_t* module;

    nbp_before_test_pfn_t beforeTestFunc;
    nbp_after_test_pfn_t afterTestFunc;

    struct nbp_test_details_t* next;
    struct nbp_test_details_t* prev;

    NBP_ATOMIC_UINT_TYPE testState;
    NBP_ATOMIC_UINT_TYPE flags;

    struct {
        NBP_ATOMIC_UINT_TYPE numPassed;
        NBP_ATOMIC_UINT_TYPE numFailed;
    } checks, testAsserts, moduleAsserts, asserts;
};
typedef struct nbp_test_details_t nbp_test_details_t;

#endif // end if NBP_PRIVATE_TYPES_TEST_H
