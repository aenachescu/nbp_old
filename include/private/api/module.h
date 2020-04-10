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

#ifndef NBP_PRIVATE_API_MODULE_H
#define NBP_PRIVATE_API_MODULE_H

/*
 * TODO: add docs
 */
#define NBP_NO_SETUP_FUNC                                                      \
    nbp_empty_setup_func

/*
 * TODO: add docs
 */
#define NBP_SETUP_MODULE(func)                                                 \
    void NBP_PRIVATE_PP_CONCAT(nbp_setup_module_, func)(                       \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* module                \
    )

/*
 * TODO: add docs
 */
#define NBP_NO_TEARDOWN_FUNC                                                   \
    nbp_empty_teardown_func

/*
 * TODO: add docs
 */
#define NBP_TEARDOWN_MODULE(func)                                              \
    void NBP_PRIVATE_PP_CONCAT(nbp_teardown_module_, func)(                    \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* module                \
    )

#define NBP_PRIVATE_MODULE(func, name, setupFunc, teardownFunc)                \
    void NBP_PRIVATE_PP_CONCAT(nbp_module_, func)(                             \
        nbp_module_details_t*,                                                 \
        nbp_test_setup_pfn_t,                                                  \
        nbp_test_teardown_pfn_t                                                \
    );                                                                         \
    nbp_module_details_t NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func) = {     \
        .moduleName        = name,                                             \
        .moduleId          = 0,                                                \
        .moduleFunc        = NBP_PRIVATE_PP_CONCAT(nbp_module_, func),         \
        .parent            = NBP_NULL_POINTER,                                 \
        .setup             = setupFunc,                                        \
        .teardown          = teardownFunc,                                     \
        .firstTest         = NBP_NULL_POINTER,                                 \
        .lastTest          = NBP_NULL_POINTER,                                 \
        .firstModule       = NBP_NULL_POINTER,                                 \
        .lastModule        = NBP_NULL_POINTER,                                 \
        .next              = NBP_NULL_POINTER,                                 \
        .prev              = NBP_NULL_POINTER,                                 \
        .depth             = 0,                                                \
        .runEvent          = NBP_EVENT_DEFAULT_VALUE,                          \
        .setupEvent        = NBP_EVENT_DEFAULT_VALUE,                          \
        .flags             =                                                   \
            NBP_ATOMIC_UINT_INIT(NBP_MODULE_FLAGS_NOT_INITIALIZED),            \
        .moduleState       =                                                   \
            NBP_ATOMIC_UINT_INIT(NBP_MODULE_STATE_NOT_INITIALIZED),            \
        .taskNum           = NBP_ATOMIC_UINT_INIT(0),                          \
        .completedTaskNum  = NBP_ATOMIC_UINT_INIT(0),                          \
        .ownTests = {                                                          \
            .num           = NBP_ATOMIC_UINT_INIT(0),                          \
            .numPassed     = NBP_ATOMIC_UINT_INIT(0),                          \
            .numFailed     = NBP_ATOMIC_UINT_INIT(0),                          \
            .numSkipped    = NBP_ATOMIC_UINT_INIT(0),                          \
        },                                                                     \
        .subTests = {                                                          \
            .num           = NBP_ATOMIC_UINT_INIT(0),                          \
            .numPassed     = NBP_ATOMIC_UINT_INIT(0),                          \
            .numFailed     = NBP_ATOMIC_UINT_INIT(0),                          \
            .numSkipped    = NBP_ATOMIC_UINT_INIT(0),                          \
        },                                                                     \
        .ownModules = {                                                        \
            .num           = NBP_ATOMIC_UINT_INIT(0),                          \
            .numPassed     = NBP_ATOMIC_UINT_INIT(0),                          \
            .numFailed     = NBP_ATOMIC_UINT_INIT(0),                          \
            .numSkipped    = NBP_ATOMIC_UINT_INIT(0),                          \
        },                                                                     \
        .subModules = {                                                        \
            .num           = NBP_ATOMIC_UINT_INIT(0),                          \
            .numPassed     = NBP_ATOMIC_UINT_INIT(0),                          \
            .numFailed     = NBP_ATOMIC_UINT_INIT(0),                          \
            .numSkipped    = NBP_ATOMIC_UINT_INIT(0),                          \
        },                                                                     \
        .own = {                                                               \
            .checks = {                                                        \
                .numPassed = NBP_ATOMIC_UINT_INIT(0),                          \
                .numFailed = NBP_ATOMIC_UINT_INIT(0),                          \
            },                                                                 \
            .testAsserts = {                                                   \
                .numPassed = NBP_ATOMIC_UINT_INIT(0),                          \
                .numFailed = NBP_ATOMIC_UINT_INIT(0),                          \
            },                                                                 \
            .moduleAsserts = {                                                 \
                .numPassed = NBP_ATOMIC_UINT_INIT(0),                          \
                .numFailed = NBP_ATOMIC_UINT_INIT(0),                          \
            },                                                                 \
            .asserts = {                                                       \
                .numPassed = NBP_ATOMIC_UINT_INIT(0),                          \
                .numFailed = NBP_ATOMIC_UINT_INIT(0),                          \
            },                                                                 \
        },                                                                     \
        .sub = {                                                               \
            .checks = {                                                        \
                .numPassed = NBP_ATOMIC_UINT_INIT(0),                          \
                .numFailed = NBP_ATOMIC_UINT_INIT(0),                          \
            },                                                                 \
            .testAsserts = {                                                   \
                .numPassed = NBP_ATOMIC_UINT_INIT(0),                          \
                .numFailed = NBP_ATOMIC_UINT_INIT(0),                          \
            },                                                                 \
            .moduleAsserts = {                                                 \
                .numPassed = NBP_ATOMIC_UINT_INIT(0),                          \
                .numFailed = NBP_ATOMIC_UINT_INIT(0),                          \
            },                                                                 \
            .asserts = {                                                       \
                .numPassed = NBP_ATOMIC_UINT_INIT(0),                          \
                .numFailed = NBP_ATOMIC_UINT_INIT(0),                          \
            },                                                                 \
        },                                                                     \
    };                                                                         \
    void NBP_PRIVATE_PP_CONCAT(nbp_module_, func)(                             \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* module,               \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_setup_pfn_t testSetup,             \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_teardown_pfn_t testTeardown        \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE_NAME(func, name)                                            \
    NBP_PRIVATE_MODULE(func, name, NBP_NULL_POINTER, NBP_NULL_POINTER)

/*
 * TODO: add docs
 */
#define NBP_MODULE(func)                                                       \
    NBP_MODULE_NAME(func, #func)

/*
 * TODO: add docs
 */
#define NBP_MODULE_NAME_FIXTURES(func, name, setupFunc, teardownFunc)          \
    NBP_SETUP_MODULE(setupFunc);                                               \
    NBP_TEARDOWN_MODULE(teardownFunc);                                         \
    NBP_PRIVATE_MODULE(                                                        \
        func,                                                                  \
        name,                                                                  \
        NBP_PRIVATE_PP_CONCAT(nbp_setup_module_, setupFunc),                   \
        NBP_PRIVATE_PP_CONCAT(nbp_teardown_module_, teardownFunc)              \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE_FIXTURES(func, setupFunc, teardownFunc)                     \
    NBP_MODULE_NAME_FIXTURES(func, #func, setupFunc, teardownFunc)

/*
 * TODO: add docs
 */
#define NBP_CALL_MODULE(func)                                                  \
    extern nbp_module_details_t NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func); \
    nbp_call_module(                                                           \
        & NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func),                       \
        module                                                                 \
    )

/*
 * TODO: add docs
 */
#define NBP_CALL_MODULE_CTX(func, ctx)                                         \
    extern nbp_module_details_t NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func); \
    nbp_call_module_ctx(                                                       \
        & NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func),                       \
        ctx,                                                                   \
        module                                                                 \
    )

/*
 * TODO: add docs
 */
#define NBP_INCLUDE_MODULE(func)                                               \
    extern nbp_module_details_t NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func);

/*
 * TODO: add docs
 */
#define NBP_GET_MODULE_PTR(func)                                               \
    & NBP_PRIVATE_PP_CONCAT(nbpModuleDetails, func)

/*
 * TODO: add docs
 */
#define NBP_MODULE_FOR_EACH_TEST(module, it)                                   \
    for (it = module->firstTest; it != NBP_NULL_POINTER; it = it->next)

/*
 * TODO: add docs
 */
#define NBP_MODULE_FOR_EACH_SUBMODULE(module, it)                              \
    for (it = module->firstModule; it != NBP_NULL_POINTER; it = it->next)

/*
 * TODO: add docs
 */
#define NBP_THIS_MODULE module

/*
 * TODO: add docs
 */
#define NBP_GET_MODULE_NAME(module) module->moduleName

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_ID(module) module->moduleId

/*
 * TODO: add docs
 */
#define NBP_GET_MODULE_DEPTH(module) module->depth

/*
 * TODO: add docs
 */
#define NBP_GET_MODULE_STATE(module)                                           \
    NBP_ATOMIC_UINT_LOAD(&module->moduleState)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_STATE(module)                                           \
    NBP_ATOMIC_UINT_LOAD(&module->moduleState)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_TESTS_NUM(module)                                   \
    NBP_ATOMIC_UINT_LOAD(&module->ownTests.num)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_PASSED_TESTS_NUM(module)                            \
    NBP_ATOMIC_UINT_LOAD(&module->ownTests.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_FAILED_TESTS_NUM(module)                            \
    NBP_ATOMIC_UINT_LOAD(&module->ownTests.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_SKIPPED_TESTS_NUM(module)                           \
    NBP_ATOMIC_UINT_LOAD(&module->ownTests.numSkipped)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUBTESTS_NUM(module)                                    \
    NBP_ATOMIC_UINT_LOAD(&module->subTests.num)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PASSED_SUBTESTS_NUM(module)                             \
    NBP_ATOMIC_UINT_LOAD(&module->subTests.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_FAILED_SUBTESTS_NUM(module)                             \
    NBP_ATOMIC_UINT_LOAD(&module->subTests.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SKIPPED_SUBTESTS_NUM(module)                            \
    NBP_ATOMIC_UINT_LOAD(&module->subTests.numSkipped)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_TESTS_NUM(module)                                       \
    NBP_MODULE_GET_OWN_TESTS_NUM(module) +                                     \
    NBP_MODULE_GET_SUBTESTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PASSED_TESTS_NUM(module)                                \
    NBP_MODULE_GET_OWN_PASSED_TESTS_NUM(module) +                              \
    NBP_MODULE_GET_PASSED_SUBTESTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_FAILED_TESTS_NUM(module)                                \
    NBP_MODULE_GET_OWN_FAILED_TESTS_NUM(module) +                              \
    NBP_MODULE_GET_FAILED_SUBTESTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SKIPPED_TESTS_NUM(module)                               \
    NBP_MODULE_GET_OWN_SKIPPED_TESTS_NUM(module) +                             \
    NBP_MODULE_GET_SKIPPED_SUBTESTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_MODULES_NUM(module)                                 \
    NBP_ATOMIC_UINT_LOAD(&module->ownModules.num)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_PASSED_MODULES_NUM(module)                          \
    NBP_ATOMIC_UINT_LOAD(&module->ownModules.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_FAILED_MODULES_NUM(module)                          \
    NBP_ATOMIC_UINT_LOAD(&module->ownModules.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_SKIPPED_MODULES_NUM(module)                         \
    NBP_ATOMIC_UINT_LOAD(&module->ownModules.numSkipped)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUBMODULES_NUM(module)                                  \
    NBP_ATOMIC_UINT_LOAD(&module->subModules.num)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PASSED_SUBMODULES_NUM(module)                           \
    NBP_ATOMIC_UINT_LOAD(&module->subModules.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_FAILED_SUBMODULES_NUM(module)                           \
    NBP_ATOMIC_UINT_LOAD(&module->subModules.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SKIPPED_SUBMODULES_NUM(module)                          \
    NBP_ATOMIC_UINT_LOAD(&module->subModules.numSkipped)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_MODULES_NUM(module)                                     \
    NBP_MODULE_GET_OWN_MODULES_NUM(module) +                                   \
    NBP_MODULE_GET_SUBMODULES_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PASSED_MODULES_NUM(module)                              \
    NBP_MODULE_GET_OWN_PASSED_MODULES_NUM(module) +                            \
    NBP_MODULE_GET_PASSED_SUBMODULES_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_FAILED_MODULES_NUM(module)                              \
    NBP_MODULE_GET_OWN_FAILED_MODULES_NUM(module) +                            \
    NBP_MODULE_GET_FAILED_SUBMODULES_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SKIPPED_MODULES_NUM(module)                             \
    NBP_MODULE_GET_OWN_SKIPPED_MODULES_NUM(module) +                           \
    NBP_MODULE_GET_SKIPPED_SUBMODULES_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_CHECKS_NUM(module)                                  \
    NBP_MODULE_GET_OWN_PASSED_CHECKS_NUM(module) +                             \
    NBP_MODULE_GET_OWN_FAILED_CHECKS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_PASSED_CHECKS_NUM(module)                           \
    NBP_ATOMIC_UINT_LOAD(&module->own.checks.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_FAILED_CHECKS_NUM(module)                           \
    NBP_ATOMIC_UINT_LOAD(&module->own.checks.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_CHECKS_NUM(module)                                  \
    NBP_MODULE_GET_SUB_PASSED_CHECKS_NUM(module) +                             \
    NBP_MODULE_GET_SUB_FAILED_CHECKS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_PASSED_CHECKS_NUM(module)                           \
    NBP_ATOMIC_UINT_LOAD(&module->sub.checks.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_FAILED_CHECKS_NUM(module)                           \
    NBP_ATOMIC_UINT_LOAD(&module->sub.checks.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_CHECKS_NUM(module)                                      \
    NBP_MODULE_GET_PASSED_CHECKS_NUM(module) +                                 \
    NBP_MODULE_GET_FAILED_CHECKS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PASSED_CHECKS_NUM(module)                               \
    NBP_MODULE_GET_OWN_PASSED_CHECKS_NUM(module) +                             \
    NBP_MODULE_GET_SUB_PASSED_CHECKS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_FAILED_CHECKS_NUM(module)                               \
    NBP_MODULE_GET_OWN_FAILED_CHECKS_NUM(module) +                             \
    NBP_MODULE_GET_SUB_FAILED_CHECKS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_TEST_ASSERTS_NUM(module)                            \
    NBP_MODULE_GET_OWN_PASSED_TEST_ASSERTS_NUM(module) +                       \
    NBP_MODULE_GET_OWN_FAILED_TEST_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_PASSED_TEST_ASSERTS_NUM(module)                     \
    NBP_ATOMIC_UINT_LOAD(&module->own.testAsserts.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_FAILED_TEST_ASSERTS_NUM(module)                     \
    NBP_ATOMIC_UINT_LOAD(&module->own.testAsserts.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_TEST_ASSERTS_NUM(module)                            \
    NBP_MODULE_GET_SUB_PASSED_TEST_ASSERTS_NUM(module) +                       \
    NBP_MODULE_GET_SUB_FAILED_TEST_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_PASSED_TEST_ASSERTS_NUM(module)                     \
    NBP_ATOMIC_UINT_LOAD(&module->sub.testAsserts.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_FAILED_TEST_ASSERTS_NUM(module)                     \
    NBP_ATOMIC_UINT_LOAD(&module->sub.testAsserts.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_TEST_ASSERTS_NUM(module)                                \
    NBP_MODULE_GET_PASSED_TEST_ASSERTS_NUM(module) +                           \
    NBP_MODULE_GET_FAILED_TEST_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PASSED_TEST_ASSERTS_NUM(module)                         \
    NBP_MODULE_GET_OWN_PASSED_TEST_ASSERTS_NUM(module) +                       \
    NBP_MODULE_GET_SUB_PASSED_TEST_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_FAILED_TEST_ASSERTS_NUM(module)                         \
    NBP_MODULE_GET_OWN_FAILED_TEST_ASSERTS_NUM(module) +                       \
    NBP_MODULE_GET_SUB_FAILED_TEST_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_MODULE_ASSERTS_NUM(module)                          \
    NBP_MODULE_GET_OWN_PASSED_MODULE_ASSERTS_NUM(module) +                     \
    NBP_MODULE_GET_OWN_FAILED_MODULE_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_PASSED_MODULE_ASSERTS_NUM(module)                   \
    NBP_ATOMIC_UINT_LOAD(&module->own.moduleAsserts.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_FAILED_MODULE_ASSERTS_NUM(module)                   \
    NBP_ATOMIC_UINT_LOAD(&module->own.moduleAsserts.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_MODULE_ASSERTS_NUM(module)                          \
    NBP_MODULE_GET_SUB_PASSED_MODULE_ASSERTS_NUM(module) +                     \
    NBP_MODULE_GET_SUB_FAILED_MODULE_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_PASSED_MODULE_ASSERTS_NUM(module)                   \
    NBP_ATOMIC_UINT_LOAD(&module->sub.moduleAsserts.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_FAILED_MODULE_ASSERTS_NUM(module)                   \
    NBP_ATOMIC_UINT_LOAD(&module->sub.moduleAsserts.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_MODULE_ASSERTS_NUM(module)                              \
    NBP_MODULE_GET_PASSED_MODULE_ASSERTS_NUM(module) +                         \
    NBP_MODULE_GET_FAILED_MODULE_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PASSED_MODULE_ASSERTS_NUM(module)                       \
    NBP_MODULE_GET_OWN_PASSED_MODULE_ASSERTS_NUM(module) +                     \
    NBP_MODULE_GET_SUB_PASSED_MODULE_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_FAILED_MODULE_ASSERTS_NUM(module)                       \
    NBP_MODULE_GET_OWN_FAILED_MODULE_ASSERTS_NUM(module) +                     \
    NBP_MODULE_GET_SUB_FAILED_MODULE_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_ASSERTS_NUM(module)                                 \
    NBP_MODULE_GET_OWN_PASSED_ASSERTS_NUM(module) +                            \
    NBP_MODULE_GET_OWN_FAILED_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_PASSED_ASSERTS_NUM(module)                          \
    NBP_ATOMIC_UINT_LOAD(&module->own.asserts.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_OWN_FAILED_ASSERTS_NUM(module)                          \
    NBP_ATOMIC_UINT_LOAD(&module->own.asserts.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_ASSERTS_NUM(module)                                 \
    NBP_MODULE_GET_SUB_PASSED_ASSERTS_NUM(module) +                            \
    NBP_MODULE_GET_SUB_FAILED_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_PASSED_ASSERTS_NUM(module)                          \
    NBP_ATOMIC_UINT_LOAD(&module->sub.asserts.numPassed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_SUB_FAILED_ASSERTS_NUM(module)                          \
    NBP_ATOMIC_UINT_LOAD(&module->sub.asserts.numFailed)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_ASSERTS_NUM(module)                                     \
    NBP_MODULE_GET_PASSED_ASSERTS_NUM(module) +                                \
    NBP_MODULE_GET_FAILED_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_PASSED_ASSERTS_NUM(module)                              \
    NBP_MODULE_GET_OWN_PASSED_ASSERTS_NUM(module) +                            \
    NBP_MODULE_GET_SUB_PASSED_ASSERTS_NUM(module)

/*
 * TODO: add docs
 */
#define NBP_MODULE_GET_FAILED_ASSERTS_NUM(module)                              \
    NBP_MODULE_GET_OWN_FAILED_ASSERTS_NUM(module) +                            \
    NBP_MODULE_GET_SUB_FAILED_ASSERTS_NUM(module)

#endif // end if NBP_PRIVATE_API_MODULE_H
