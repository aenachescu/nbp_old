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

#ifndef NBP_PRIVATE_API_SCHEDULER_H
#define NBP_PRIVATE_API_SCHEDULER_H

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_FUNC_INIT(func)                                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)(              \
        void                                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_USE_FUNC_INIT(func)                                      \
    .init = NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_NO_FUNC_INIT                                             \
    .init = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_FUNC_UNINIT(func)                                        \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)(              \
        void                                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_USE_FUNC_UNINIT(func)                                    \
    .uninit = NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_NO_FUNC_UNINIT                                           \
    .uninit = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_FUNC_RUN(func)                                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)(              \
        void                                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_USE_FUNC_RUN(func)                                       \
    .run = NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_FUNC_ADD_TEST(func)                                      \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)(              \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest            \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_USE_FUNC_ADD_TEST(func)                                  \
    .addTest = NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_NO_FUNC_ADD_TEST                                         \
    .addTest = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_FUNC_ADD_TEST_CTX(func)                                  \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)(              \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER void* nbpParamCtx                           \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_USE_FUNC_ADD_TEST_CTX(func)                              \
    .addTestCtx = NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_NO_FUNC_ADD_TEST_CTX                                     \
    .addTestCtx = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_FUNC_MODULE_STARTED(func)                                \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)(              \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_USE_FUNC_MODULE_STARTED(func)                            \
    .moduleStarted = NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_NO_FUNC_MODULE_STARTED                                   \
    .moduleStarted = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_FUNC_MODULE_STARTED_CTX(func)                            \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)(              \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule,       \
        NBP_MAYBE_UNUSED_PARAMETER void* nbpParamCtx                           \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_USE_FUNC_MODULE_STARTED_CTX(func)                        \
    .moduleStartedCtx = NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_NO_FUNC_MODULE_STARTED_CTX                               \
    .moduleStartedCtx = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_FUNC_MODULE_COMPLETED(func)                              \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)(              \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_USE_FUNC_MODULE_COMPLETED(func)                          \
    .moduleCompleted = NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_NO_FUNC_MODULE_COMPLETED                                 \
    .moduleCompleted = NBP_MEMORY_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_DEFINE_SCHEDULER(name, ...)                                        \
    struct nbp_scheduler_interface_t                                           \
    NBP_PRIVATE_PP_CONCAT(nbpScheduler, name) = {                              \
        __VA_ARGS__                                                            \
    }

/*
 * TODO: add docs
 */
#define NBP_USE_SCHEDULER(name)                                                \
    & NBP_PRIVATE_PP_CONCAT(nbpScheduler, name)

/*
 * TODO: add docs
 */
#define NBP_INCLUDE_SCHEDULER(name)                                            \
    extern nbp_scheduler_interface_t NBP_PRIVATE_PP_CONCAT(nbpScheduler, name)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_RUN_TEST(test)                                           \
    nbp_scheduler_run_test(test)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CTX nbpParamCtx

#endif // end if NBP_PRIVATE_API_SCHEDULER_H
