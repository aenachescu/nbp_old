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
#define NBP_SCHEDULER_CALLBACK_INIT(func)                                      \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_callback_, func)(          \
        void                                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CALLBACK_UNINIT(func)                                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_callback_, func)(          \
        void                                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CALLBACK_RUN(func)                                       \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_callback_, func)(          \
        void                                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CALLBACK_RUN_TEST(func)                                  \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_callback_, func)(          \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest            \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CALLBACK_RUN_TEST_CTX(func)                              \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_callback_, func)(          \
        NBP_MAYBE_UNUSED_PARAMETER nbp_test_details_t* nbpParamTest,           \
        NBP_MAYBE_UNUSED_PARAMETER void* nbpParamCtx                           \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CALLBACK_RUN_MODULE(func)                                \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_callback_, func)(          \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CALLBACK_RUN_MODULE_CTX(func)                            \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_callback_, func)(          \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule,       \
        NBP_MAYBE_UNUSED_PARAMETER void* nbpParamCtx                           \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CALLBACK_RUN_MODULE_COMPLETED(func)                      \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_callback_, func)(          \
        NBP_MAYBE_UNUSED_PARAMETER nbp_module_details_t* nbpParamModule        \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_CALLBACKS(...)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER(name, ...)                                               \
    void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_config_, name)(                   \
        NBP_MAYBE_UNUSED_PARAMETER nbp_scheduler_interface_t* nbpParamScheduler\
    )                                                                          \
    {                                                                          \
        NBP_SCHEDULER_PRIVATE_GENERATE_CONFIG(P_ ## __VA_ARGS__)               \
    }                                                                          \
    struct nbp_scheduler_interface_t                                           \
    NBP_PRIVATE_PP_CONCAT(nbpScheduler, name) = {                              \
        .schedulerName              = #name,                                   \
        .configFunc                 =                                          \
            NBP_PRIVATE_PP_CONCAT(nbp_scheduler_config_, name),                \
        .initCbk                    = NBP_MEMORY_NULL_POINTER,                 \
        .uninitCbk                  = NBP_MEMORY_NULL_POINTER,                 \
        .runCbk                     = NBP_MEMORY_NULL_POINTER,                 \
        .runTestCbk                 = NBP_MEMORY_NULL_POINTER,                 \
        .runTestCtxCbk              = NBP_MEMORY_NULL_POINTER,                 \
        .runModuleCbk               = NBP_MEMORY_NULL_POINTER,                 \
        .runModuleCtxCbk            = NBP_MEMORY_NULL_POINTER,                 \
        .runModuleCompletedCbk      = NBP_MEMORY_NULL_POINTER,                 \
    }

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_GET_PTR(name)                                            \
    & NBP_PRIVATE_PP_CONCAT(nbpScheduler, name)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_INCLUDE(name)                                            \
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

#define NBP_SCHEDULER_PRIVATE_GENERATE_CONFIG(...)                             \
    NBP_PRIVATE_PP_CONCAT(                                                     \
        NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_,                     \
        NBP_PP_VARCOUNT(P ## __VA_ARGS__)                                      \
    )(P ## __VA_ARGS__)                                                        \

/*
 * This macro is generated when the NBP_SCHEDULER macro is used only with the
 * 'name' parameter.
 */
#define NBP_SCHEDULER_PRIVATE_PP_EAT_PP_

/*
 * This macro is generated when the NBP_SCHEDULER_CALLBACKS macro is used with
 * no parameter.
 */
#define NBP_SCHEDULER_PRIVATE_PP_EAT_P_

#define NBP_SCHEDULER_PRIVATE_PP_EAT_PP_NBP_SCHEDULER_CALLBACKS(...)           \
    NBP_PRIVATE_PP_CONCAT(                                                     \
        NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_,                  \
        NBP_PP_VARCOUNT(P_ ## __VA_ARGS__)                                     \
    )(P_ ## __VA_ARGS__)

#define NBP_SCHEDULER_PRIVATE_PP_EAT_P_NBP_SCHEDULER_CALLBACKS(...)            \
    NBP_PRIVATE_PP_CONCAT(                                                     \
        NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_,                  \
        NBP_PP_VARCOUNT(P_ ## __VA_ARGS__)                                     \
    )(P_ ## __VA_ARGS__)

#define NBP_SCHEDULER_PRIVATE_PP_EAT_P_NBP_SCHEDULER_CALLBACK_INIT(func)       \
    nbpParamScheduler->initCbk =                                               \
        NBP_PRIVATE_PP_CONCAT(nbp_scheduler_callback_, func);
#define NBP_SCHEDULER_PRIVATE_PP_EAT_P_NBP_SCHEDULER_CALLBACK_UNINIT(func)     \
    nbpParamScheduler->uninitCbk =                                             \
        NBP_PRIVATE_PP_CONCAT(nbp_scheduler_callback_, func);
#define NBP_SCHEDULER_PRIVATE_PP_EAT_P_NBP_SCHEDULER_CALLBACK_RUN(func)        \
    nbpParamScheduler->runCbk =                                                \
        NBP_PRIVATE_PP_CONCAT(nbp_scheduler_callback_, func);
#define NBP_SCHEDULER_PRIVATE_PP_EAT_P_NBP_SCHEDULER_CALLBACK_RUN_TEST(func)   \
    nbpParamScheduler->runTestCbk =                                            \
        NBP_PRIVATE_PP_CONCAT(nbp_scheduler_callback_, func);
#define NBP_SCHEDULER_PRIVATE_PP_EAT_P_NBP_SCHEDULER_CALLBACK_RUN_TEST_CTX(    \
    func)                                                                      \
    nbpParamScheduler->runTestCtxCbk =                                         \
        NBP_PRIVATE_PP_CONCAT(nbp_scheduler_callback_, func);
#define NBP_SCHEDULER_PRIVATE_PP_EAT_P_NBP_SCHEDULER_CALLBACK_RUN_MODULE(func) \
    nbpParamScheduler->runModuleCbk =                                          \
        NBP_PRIVATE_PP_CONCAT(nbp_scheduler_callback_, func);
#define NBP_SCHEDULER_PRIVATE_PP_EAT_P_NBP_SCHEDULER_CALLBACK_RUN_MODULE_CTX(  \
    func)                                                                      \
    nbpParamScheduler->runModuleCtxCbk =                                       \
        NBP_PRIVATE_PP_CONCAT(nbp_scheduler_callback_, func);
#define NBP_SCHEDULER_PRIVATE_PP_EAT_P_NBP_SCHEDULER_CALLBACK_RUN_MODULE_COMPLETED(\
    func)                                                                      \
    nbpParamScheduler->runModuleCompletedCbk =                                 \
        NBP_PRIVATE_PP_CONCAT(nbp_scheduler_callback_, func);

/*
 * These macros are used to parse the parameters passed to the NBP_SCHEDULER
 * macro.
 */
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_1(param)              \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_2(param, ...)         \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_1(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_3(param, ...)         \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_2(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_4(param, ...)         \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_3(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_5(param, ...)         \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_4(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_6(param, ...)         \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_5(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_7(param, ...)         \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_6(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_8(param, ...)         \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_7(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_9(param, ...)         \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_8(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_10(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_9(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_11(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_10(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_12(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_11(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_13(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_12(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_14(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_13(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_15(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_14(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_16(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_15(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_17(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_16(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_18(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_17(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_19(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_18(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_20(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_19(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_21(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_20(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_22(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_21(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_23(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_22(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_24(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_23(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_25(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_24(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_26(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_25(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_27(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_26(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_28(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_27(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_29(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_28(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_30(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_29(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_31(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_30(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_32(param, ...)        \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CONFIG_PARAM_31(P_ ## __VA_ARGS__)

/*
 * These macros are used to parse the parameters passed to the
 * NBP_SCHEDULER_CALLBACKS macro.
 */
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_1(param)           \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_2(param, ...)      \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_1(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_3(param, ...)      \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_2(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_4(param, ...)      \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_3(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_5(param, ...)      \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_4(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_6(param, ...)      \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_5(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_7(param, ...)      \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_6(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_8(param, ...)      \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_7(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_9(param, ...)      \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_8(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_10(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_9(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_11(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_10(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_12(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_11(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_13(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_12(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_14(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_13(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_15(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_14(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_16(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_15(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_17(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_16(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_18(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_17(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_19(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_18(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_20(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_19(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_21(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_20(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_22(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_21(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_23(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_22(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_24(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_23(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_25(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_24(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_26(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_25(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_27(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_26(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_28(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_27(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_29(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_28(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_30(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_29(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_31(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_30(P_ ## __VA_ARGS__)
#define NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_32(param, ...)     \
    NBP_SCHEDULER_PRIVATE_PP_EAT_ ## param                                     \
    NBP_SCHEDULER_PRIVATE_PP_PROCESSING_CALLBACKS_PARAM_31(P_ ## __VA_ARGS__)

#endif // end if NBP_PRIVATE_API_SCHEDULER_H
