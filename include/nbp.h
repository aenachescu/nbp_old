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

struct nbp_test_details_t;
struct nbp_module_details_t;

typedef void (*nbp_test_pfn_t)(struct nbp_test_details_t*);
typedef void (*nbp_module_pfn_t)(struct nbp_module_details_t*);

typedef void (*nbp_before_test_pfn_t)(void);
typedef void (*nbp_after_test_pfn_t)(void);

typedef void(*nbp_setup_module_pfn_t)(void);
typedef void(*nbp_teardown_module_pfn_t)(void);

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
    struct nbp_test_details_t* next;
    struct nbp_test_details_t* prev;
};
typedef struct nbp_test_details_t nbp_test_details_t;

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
};
typedef struct nbp_module_details_t nbp_module_details_t;

void nbp_call_test(nbp_test_details_t*, nbp_module_details_t*);

void nbp_call_module(nbp_module_details_t*, nbp_module_details_t*);

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
#define NBP_TEST(name)                                                         \
    void name(nbp_test_details_t* testDetails);                                \
    nbp_test_details_t nbpTestDetails ## name = {                              \
        .testName               = #name,                                       \
        .testFunc               = name,                                        \
        .beforeTestFunc         = 0x0,                                         \
        .afterTestFunc          = 0x0,                                         \
        .module                 = 0x0,                                         \
        .passedChecks           = 0,                                           \
        .failedChecks           = 0,                                           \
        .passedTestAsserts      = 0,                                           \
        .failedTestAsserts      = 0,                                           \
        .passedModuleAsserts    = 0,                                           \
        .failedModuleAsserts    = 0,                                           \
        .passedAsserts          = 0,                                           \
        .failedAsserts          = 0,                                           \
        .next                   = 0x0,                                         \
        .prev                   = 0x0                                          \
    };                                                                         \
    void name(nbp_test_details_t* testDetails)

/*
 * TODO: add docs
 */
#define NBP_CALL_TEST(name)                                                    \
    extern nbp_test_details_t nbpTestDetails ## name;                          \
    nbp_call_test(& nbpTestDetails ## name, moduleDetails)

/*
 * TODO: add docs
 */
#define NBP_MODULE(name)                                                       \
    void name(nbp_module_details_t* moduleDetails);                            \
    nbp_module_details_t nbpModuleDetails ## name = {                          \
        .moduleName     = #name,                                               \
        .moduleFunc     = name,                                                \
        .setup          = 0x0,                                                 \
        .teardown       = 0x0,                                                 \
        .firstTest      = 0x0,                                                 \
        .lastTest       = 0x0,                                                 \
        .parent         = 0x0,                                                 \
        .firstSubmodule = 0x0,                                                 \
        .lastSubmodule  = 0x0,                                                 \
        .next           = 0x0,                                                 \
        .prev           = 0x0,                                                 \
    };                                                                         \
    void name(nbp_module_details_t* moduleDetails)

/*
 * TODO: add docs
 */
#define NBP_MODULE_METHODS(name, setupFunc, teardownFunc)                      \
    void name(nbp_module_details_t* moduleDetails);                            \
    nbp_module_details_t nbpModuleDetails ## name = {                          \
        .moduleName     = #name,                                               \
        .moduleFunc     = name,                                                \
        .setup          = setupFunc,                                           \
        .teardown       = teardownFunc,                                        \
        .firstTest      = 0x0,                                                 \
        .lastTest       = 0x0,                                                 \
        .parent         = 0x0,                                                 \
        .firstSubmodule = 0x0,                                                 \
        .lastSubmodule  = 0x0,                                                 \
        .next           = 0x0,                                                 \
        .prev           = 0x0,                                                 \
    };                                                                         \
    void name(nbp_module_details_t* moduleDetails)

/*
 * TODO: add docs
 */
#define NBP_CALL_MODULE(name)                                                  \
    extern nbp_module_details_t nbpModuleDetails ## name;                      \
    nbp_call_module(& nbpModuleDetails ## name, moduleDetails)

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
#define NBP_MAIN_MODULE(name)                                                  \
    void name(nbp_module_details_t* moduleDetails);                            \
    int main(int argc, const char** argv)                                      \
    {                                                                          \
        extern nbp_module_details_t nbpModuleDetails ## name;                  \
        nbp_call_module(& nbpModuleDetails ## name, 0x0);                      \
        return 0;                                                              \
    }                                                                          \
    NBP_MODULE(name)

/*
 * TODO: add docs
 */
#define NBP_MAIN_MODULE_METHODS(name, setupFunc, teardownFunc)                 \
    void name(nbp_module_details_t* moduleDetails);                            \
    int main(int argc, const char** argv)                                      \
    {                                                                          \
        extern nbp_module_details_t nbpModuleDetails ## name;                  \
        nbp_call_module(& nbpModuleDetails ## name, 0x0);                      \
        return 0;                                                              \
    }                                                                          \
    NBP_MODULE_METHODS(name, setupFunc, teardownFunc)

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

void nbp_call_test(nbp_test_details_t* test, nbp_module_details_t* module)
{
    test->module = module;
    if (module->firstTest == 0x0) {
        module->firstTest = test;
        module->lastTest = test;
    } else {
        test->prev = module->lastTest;
        module->lastTest->next = test;
        module->lastTest = test;
    }
}

void nbp_call_module(nbp_module_details_t* module, nbp_module_details_t* parent)
{
    module->parent = parent;
    if (parent != 0x0) {
        if (parent->firstSubmodule == 0x0) {
            parent->firstSubmodule = module;
            parent->lastSubmodule = module;
        } else {
            module->prev = parent->lastSubmodule;
            parent->lastSubmodule->next = module;
            parent->lastSubmodule = module;
        }
    }

    module->moduleFunc(module);
}

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_LIBRARY_H

