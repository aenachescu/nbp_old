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

#ifndef NBP_PRIVATE_TYPES_MODULE_H
#define NBP_PRIVATE_TYPES_MODULE_H

#define NBP_MODULE_STATE_NOT_INITIALIZED  (unsigned int) 0
#define NBP_MODULE_STATE_READY            (unsigned int) 1
#define NBP_MODULE_STATE_RUNNING          (unsigned int) 2
#define NBP_MODULE_STATE_PASSED           (unsigned int) 3
#define NBP_MODULE_STATE_FAILED           (unsigned int) 4
#define NBP_MODULE_STATE_SKIPPED          (unsigned int) 5

#define NBP_MODULE_PRIVATE_SKIP_NOT_SET   (unsigned int) 0
#define NBP_MODULE_PRIVATE_SKIP_SET       (unsigned int) 1
#define NBP_MODULE_PRIVATE_SKIP_PROCESSED (unsigned int) 2

struct nbp_module_details_t;

typedef void(*nbp_module_setup_pfn_t)(
    struct nbp_module_details_t* /* current module */
);

typedef void(*nbp_module_teardown_pfn_t)(
    struct nbp_module_details_t* /* current module */
);

typedef void (*nbp_module_pfn_t)(
    struct nbp_module_details_t*, /* current module */
    nbp_module_setup_pfn_t, /* module setup pfn */
    nbp_module_teardown_pfn_t, /* module teardown pfn */
    nbp_test_setup_pfn_t, /* test setup pfn */
    nbp_test_teardown_pfn_t /* test teardown pfn */
);

struct nbp_module_details_t {
    const char* moduleName;
    unsigned int moduleId;
    nbp_module_pfn_t moduleFunc;
    struct nbp_module_details_t* parent;

    nbp_module_setup_pfn_t setup;
    nbp_module_teardown_pfn_t teardown;

    struct nbp_test_details_t* firstTest;
    struct nbp_test_details_t* lastTest;

    struct nbp_module_details_t* firstModule;
    struct nbp_module_details_t* lastModule;

    struct nbp_module_details_t* next;
    struct nbp_module_details_t* prev;

    unsigned int depth;
    NBP_SYNC_EVENT_TYPE runEvent;
    NBP_SYNC_EVENT_TYPE setupEvent;
    NBP_SYNC_ATOMIC_UINT_TYPE isSkipped;
    NBP_SYNC_ATOMIC_UINT_TYPE moduleState;

    unsigned int taskNum;
    NBP_SYNC_ATOMIC_UINT_TYPE completedTaskNum;

    unsigned int isEmptyModule;
    unsigned int emptySubmodulesNum;

    struct {
        unsigned int num;
        NBP_SYNC_ATOMIC_UINT_TYPE numPassed;
        NBP_SYNC_ATOMIC_UINT_TYPE numFailed;
        NBP_SYNC_ATOMIC_UINT_TYPE numSkipped;
    } ownTests, subTests;

    struct {
        unsigned int num;
        NBP_SYNC_ATOMIC_UINT_TYPE numPassed;
        NBP_SYNC_ATOMIC_UINT_TYPE numFailed;
        NBP_SYNC_ATOMIC_UINT_TYPE numSkipped;
    } ownModules, subModules;

    struct {
        struct {
            NBP_SYNC_ATOMIC_UINT_TYPE numPassed;
            NBP_SYNC_ATOMIC_UINT_TYPE numFailed;
        } checks, testAsserts, moduleAsserts, asserts;
    } own, sub;
};
typedef struct nbp_module_details_t nbp_module_details_t;

#endif // end if NBP_PRIVATE_TYPES_MODULE_H
