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

#ifndef NBP_LIBRARY_H
#define NBP_LIBRARY_H

typedef struct nbp_test_details_t;
typedef struct nbp_module_details_t;

typedef void (*nbp_test_pfn_t)(nbp_test_details_t*);
typedef void (*nbp_module_pfn_t)(nbp_module_details_t*);

typedef void (*nbp_before_test_pfn_t)(void);
typedef void (*nbp_after_test_pfn_t)(void);

typedef struct {
    const char* testName;
    nbp_test_pfn_t func;
    unsigned int passedChecks;
    unsigned int failedChecks;
    unsigned int passedTestAsserts;
    unsigned int failedTestAsserts;
    unsigned int passedModuleAsserts;
    unsigned int failedModuleAsserts;
    unsigned int passedAsserts;
    unsigned int failedAsserts;
} nbp_test_details_t;

typedef struct {
    const char* moduleName;
} nbp_module_details_t;

void nbp_call_test(nbp_test_pfn_t, const char*, nbp_module_details_t*);

void nbp_call_module(nbp_module_pfn_t, const char*, nbp_module_details_t*);

void nbp_set_before_test_pfn(nbp_before_test_pfn_t);
void nbp_set_after_test_pfn(nbp_after_test_pfn_t);

/*
 * TODO: add docs
 */
#define NBP_CHECK(cond)                                                        \
    if (cond) {                                                                \
        testDetails->passedChecks++;                                           \
    } else {                                                                   \
        testDetails->failedChecks++;                                           \
    }

/*
 * TODO: add docs
 */
#define NBP_ASSERT(cond)

/*
 * TODO: add docs
 */
#define NBP_TEST_ASSERT(cond)

/*
 * TODO: add docs
 */
#define NBP_MODULE_ASSERT(cond)

/*
 * TODO: add docs
 */
#define NBP_TEST(name) void name(nbp_test_details_t* testDetails)

/*
 * TODO: add docs
 */
#define NBP_CALL_TEST(name) nbp_call_test(name, #name, moduleDetails)

/*
 * TODO: add docs
 */
#define NBP_MODULE(name) void name(nbp_module_details_t* moduleDetails)

/*
 * TODO: add docs
 */
#define NBP_CALL_MODULE(name)                                                  \
    NBP_MODULE(name);                                                          \
    nbp_call_module(name, ##name, moduleDetails)

/*
 * TODO: add docs
 */
#define NBP_CALL_BEFORE_TEST(func) nbp_set_before_test_pfn(func)

/*
 * TODO: add docs
 */
#define NBP_CALL_AFTER_TEST(func) nbp_set_after_test_pfn(func)

/*
 * TODO: add docs
 */
#define NBP_CALL_BEFORE_MODULE(func) nbp_set_before_module_pfn(func)

/*
 * TODO: add docs
 */
#define NBP_CALL_AFTER_MODULE(func) nbp_set_after_module_pfn(func)

/*
 * TODO: add docs
 */
#ifdef NBP_LIBRARY_MAIN

/*
 * TODO: add docs
 */
#ifndef NBP_CUSTOM_MEMORY_ALLOCATOR

#include <stdlib.h>
#define NBP_ALLOC malloc
#define NBP_FREE free

#else // if custom memory allocator is enabled

#ifndef NBP_ALLOC
#error "Custom memory allocator is enabled but no alloc function is provided"
#endif

#ifndef NBP_FREE
#error "Custom memory allocator is enabled but no free function is provided"
#endif

#endif // end if NBP_CUSTOM_MEMORY_ALLOCATOR

/*
 * TODO: add docs
 */
#define NBP_MAIN()                                                             \
    nbp_module_details_t nbpGlobalModule = {                                   \
        .moduleName = "main"                                                   \
    };                                                                         \
    nbp_module_details_t* moduleDetails = &nbpGlobalModule;                    \
    int main(int argc, const char *argv[])

/*
 * TODO: add docs
 */
#define NBP_RUN() return 0;

nbp_before_test_pfn_t nbpBeforeTestPfn = (nbp_before_test_pfn_t) 0x0;
nbp_after_test_pfn_t  nbpAfterTestPfn  = (nbp_after_test_pfn_t)  0x0;

void nbp_set_before_test_pfn(nbp_before_test_pfn_t func)
{
    nbpBeforeTestPfn = func;
}

void nbp_set_after_test_pfn(nbp_after_test_pfn_t func)
{
    nbpAfterTestPfn = func;
}

void nbp_call_test(nbp_test_pfn_t test, const char* testName,
    nbp_module_details_t* moduleDetails)
{
    return;
}

void nbp_call_module(nbp_module_pfn_t module, const char* moduleName,
    nbp_module_details_t* moduleDetails)
{
    return;
}

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_LIBRARY_H

