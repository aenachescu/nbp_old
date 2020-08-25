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

#ifndef NBP_PRIVATE_TYPES_TEST_H
#define NBP_PRIVATE_TYPES_TEST_H

/*
 * TODO: add docs
 */
#define NBP_TEST_STATE_NOT_INITIALIZED  (unsigned int) 0x10000000
#define NBP_TEST_STATE_READY            (unsigned int) 0x10000001
#define NBP_TEST_STATE_RUNNING          (unsigned int) 0x10000002
#define NBP_TEST_STATE_PASSED           (unsigned int) 0x10000003
#define NBP_TEST_STATE_FAILED           (unsigned int) 0x10000004
#define NBP_TEST_STATE_SKIPPED          (unsigned int) 0x10000005

#define NBP_TEST_PRIVATE_SKIP_NOT_SET   (unsigned int) 0x11000000
#define NBP_TEST_PRIVATE_SKIP_SET       (unsigned int) 0x11000001
#define NBP_TEST_PRIVATE_SKIP_PROCESSED (unsigned int) 0x11000002

struct nbp_test_details_t;

typedef void (*nbp_test_setup_pfn_t)(
    struct nbp_test_details_t* /* current test */
);

typedef void (*nbp_test_teardown_pfn_t)(
    struct nbp_test_details_t* /* current test */
);

typedef void (*nbp_test_pfn_t)(
    struct nbp_test_details_t*, /* current test */
    const char*, /* success message */
    const char* /* failure message */
);

struct nbp_test_details_t {
    const char* testName;
    unsigned int testId;
    nbp_test_pfn_t testFunc;
    struct nbp_module_details_t* module;

    nbp_test_setup_pfn_t testSetupFunc;
    nbp_test_teardown_pfn_t testTeardownFunc;

    struct nbp_test_details_t* next;
    struct nbp_test_details_t* prev;

    NBP_SYNC_ATOMIC_UINT_TYPE testState;
    NBP_SYNC_ATOMIC_UINT_TYPE isSkipped;

    struct {
        unsigned int numPassed;
        unsigned int numFailed;
    } checks, testAsserts, moduleAsserts, asserts;
};
typedef struct nbp_test_details_t nbp_test_details_t;

#endif // end if NBP_PRIVATE_TYPES_TEST_H
