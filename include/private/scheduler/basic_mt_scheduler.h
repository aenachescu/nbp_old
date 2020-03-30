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

#ifndef NBP_PRIVATE_SCHEDULER_BASIC_MT_SCHEDULER_H
#define NBP_PRIVATE_SCHEDULER_BASIC_MT_SCHEDULER_H

#define NBP_MT_SCHEDULER_RULE_TYPE_UNKNOWN          (unsigned char) 0
#define NBP_MT_SCHEDULER_RULE_TYPE_BEFORE           (unsigned char) 1
#define NBP_MT_SCHEDULER_RULE_TYPE_AFTER            (unsigned char) 2

#define NBP_MT_SCHEDULER_DATA_TYPE_UNKNOWN          (unsigned char) 0
#define NBP_MT_SCHEDULER_DATA_TYPE_EMPTY            (unsigned char) 1
#define NBP_MT_SCHEDULER_DATA_TYPE_TEST             (unsigned char) 2
#define NBP_MT_SCHEDULER_DATA_TYPE_MODULE           (unsigned char) 3

struct nbp_mt_scheduler_rule_t {
    unsigned char ruleType;
    unsigned char dataType;
    union {
        nbp_test_details_t* test;
        nbp_module_details_t* module;
    };
};
typedef struct nbp_mt_scheduler_rule_t nbp_mt_scheduler_rule_t;

struct nbp_mt_scheduler_context_t {
    unsigned long long numberOfRules;
    nbp_mt_scheduler_rule_t rules[1];
};
typedef struct nbp_mt_scheduler_context_t nbp_mt_scheduler_context_t;

nbp_mt_scheduler_rule_t nbp_mt_schduler_create_rule_from_test(
    unsigned char ruleType,
    nbp_test_details_t* test
);

nbp_mt_scheduler_rule_t nbp_mt_schduler_create_rule_from_module(
    unsigned char ruleType,
    nbp_module_details_t* module
);

void* nbp_mt_scheduler_create_ctx(
    unsigned long long numberOfRules,
    nbp_mt_scheduler_rule_t* rules
);

#define NBP_MT_SCHEDULER_RUN_BEFORE_TEST(test)                                 \
    nbp_mt_schduler_create_rule_from_test(                                     \
        NBP_MT_SCHEDULER_RULE_TYPE_BEFORE,                                     \
        NBP_GET_TEST_PTR(test)                                                 \
    )

#define NBP_MT_SCHEDULER_RUN_AFTER_TEST(test)                                  \
    nbp_mt_schduler_create_rule_from_test(                                     \
        NBP_MT_SCHEDULER_RULE_TYPE_AFTER,                                      \
        NBP_GET_TEST_PTR(test)                                                 \
    )

#define NBP_MT_SCHEDULER_RUN_BEFORE_MODULE(module)                             \
    nbp_mt_schduler_create_rule_from_module(                                   \
        NBP_MT_SCHEDULER_RULE_TYPE_BEFORE,                                     \
        NBP_GET_MODULE_PTR(module)                                             \
    )

#define NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module)                              \
    nbp_mt_schduler_create_rule_from_module(                                   \
        NBP_MT_SCHEDULER_RULE_TYPE_AFTER,                                      \
        NBP_GET_MODULE_PTR(module)                                             \
    )

#define NBP_MT_SCHEDULER_PRIVATE_GET_NUMBER_OF_RULES(...)                      \
    sizeof((nbp_mt_scheduler_rule_t[]){ __VA_ARGS__ }) /                       \
    sizeof(nbp_mt_scheduler_rule_t)

#define NBP_MT_SCHEDULER_CTX(...)                                              \
    nbp_mt_scheduler_create_ctx(                                               \
        NBP_MT_SCHEDULER_PRIVATE_GET_NUMBER_OF_RULES(__VA_ARGS__),             \
        (nbp_mt_scheduler_rule_t[]){ __VA_ARGS__ }                             \
    )

/*
 * NBP_SCHEDULER_PREPROCESSING_CONTEXT implementation
 */

#define NBP_MT_SCHEDULER_PRIVATE_PP_EAT_P_NBP_MT_SCHEDULER_RUN_AFTER_TEST(     \
    name)                                                                      \
    NBP_INCLUDE_TEST(name);

#define NBP_MT_SCHEDULER_PRIVATE_PP_EAT_P_NBP_MT_SCHEDULER_RUN_BEFORE_TEST(    \
    name)                                                                      \
    NBP_INCLUDE_TEST(name);

#define NBP_MT_SCHEDULER_PRIVATE_PP_EAT_P_NBP_MT_SCHEDULER_RUN_AFTER_MODULE(   \
    name)                                                                      \
    NBP_INCLUDE_MODULE(name);

#define NBP_MT_SCHEDULER_PRIVATE_PP_EAT_P_NBP_MT_SCHEDULER_RUN_BEFORE_MODULE(  \
    name)                                                                      \
    NBP_INCLUDE_MODULE(name);

// it's used when NBP_MT_SCHEDULER_CTX is called without rules
#define NBP_MT_SCHEDULER_PRIVATE_PP_EAT_P_

#define NBP_MT_SCHEDULER_PRIVATE_PP_VARCOUNT(...)                              \
    NBP_MT_SCHEDULER_PRIVATE_PP_VARCOUNT_HELPER(                               \
        P ## __VA_ARGS__,                                                      \
        9, 8, 7, 6, 5, 4, 3, 2, 1,                                             \
    )

#define NBP_MT_SCHEDULER_PRIVATE_PP_VARCOUNT_HELPER(                           \
    _, _9, _8, _7, _6, _5, _4, _3, _2, _n, ...) _n

#define NBP_MT_SCHEDULER_PRIVATE_PP_CONCAT(a, b)                               \
    NBP_MT_SCHEDULER_PRIVATE_PP_CONCAT_HELPER(a, b)

#define NBP_MT_SCHEDULER_PRIVATE_PP_CONCAT_HELPER(a, b) a ## b

#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_1(rule)                    \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule
#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_2(rule, ...)               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule                                   \
    NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_1(P_ ## __VA_ARGS__)
#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_3(rule, ...)               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule                                   \
    NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_2(P_ ## __VA_ARGS__)
#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_4(rule, ...)               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule                                   \
    NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_3(P_ ## __VA_ARGS__)
#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_5(rule, ...)               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule                                   \
    NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_4(P_ ## __VA_ARGS__)
#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_6(rule, ...)               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule                                   \
    NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_5(P_ ## __VA_ARGS__)
#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_7(rule, ...)               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule                                   \
    NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_6(P_ ## __VA_ARGS__)
#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_8(rule, ...)               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule                                   \
    NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_7(P_ ## __VA_ARGS__)
#define NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_9(rule, ...)               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## rule                                   \
    NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_8(P_ ## __VA_ARGS__)

#define NBP_MT_SCHEDULER_PRIVATE_PP_EAT_PP_NBP_MT_SCHEDULER_CTX(...)           \
    NBP_MT_SCHEDULER_PRIVATE_PP_CONCAT(                                        \
        NBP_MT_SCHEDULER_PRIVATE_PP_PROCESSING_RULE_,                          \
        NBP_MT_SCHEDULER_PRIVATE_PP_VARCOUNT(P_ ## __VA_ARGS__)                \
    )(P_ ## __VA_ARGS__)

#define NBP_SCHEDULER_PREPROCESSING_CONTEXT(ctx)                               \
    NBP_MT_SCHEDULER_PRIVATE_PP_EAT_ ## ctx

#ifdef NBP_LIBRARY_MAIN

/*
 * nbp_basic_mt_scheduler_get_number_of_threads() implementation
 */
#ifdef NBP_MT_SCHEDULER_NUMBER_OF_THREADS

#if NBP_MT_SCHEDULER_NUMBER_OF_THREADS >= 1

int nbp_basic_mt_scheduler_get_number_of_threads()
{
    return NBP_MT_SCHEDULER_NUMBER_OF_THREADS;
}

#else // NBP_MT_SCHEDULER_NUMBER_OF_THREADS is less than 1

#error "Invalid number of threads"

#endif // end if NBP_MT_SCHEDULER_NUMBER_OF_THREADS >= 1

#else // NBP_MT_SCHEDULER_NUMBER_OF_THREADS not defined

#ifdef NBP_OS_LINUX

#include <sys/sysinfo.h>

int nbp_basic_mt_scheduler_get_number_of_threads()
{
    return get_nprocs();
}

#endif // end if NBP_OS_LINUX

#ifdef NBP_OS_WINDOWS
#error "Not supported"
#endif // end if NBP_OS_WINDOWS

#ifdef NBP_OS_MAC
#error "Not supported"
#endif // end if NBP_OS_MAC

#ifdef NBP_OS_CUSTOM
#error "Not supported"
#endif // end if NBP_OS_CUSTOM

#endif // end if NBP_MT_SCHEDULER_NUMBER_OF_THREADS

nbp_mt_scheduler_rule_t nbp_mt_schduler_create_rule_from_test(
    unsigned char ruleType, nbp_test_details_t* test)
{
    nbp_mt_scheduler_rule_t rule;

    rule.ruleType   = ruleType;
    rule.dataType   = NBP_MT_SCHEDULER_DATA_TYPE_TEST;
    rule.test       = test;

    return rule;
}

nbp_mt_scheduler_rule_t nbp_mt_schduler_create_rule_from_module(
    unsigned char ruleType, nbp_module_details_t* module)
{
    nbp_mt_scheduler_rule_t rule;

    rule.ruleType   = ruleType;
    rule.dataType   = NBP_MT_SCHEDULER_DATA_TYPE_MODULE;
    rule.module     = module;

    return rule;
}

void* nbp_mt_scheduler_create_ctx(unsigned long long numberOfRules,
    nbp_mt_scheduler_rule_t* rules)
{
    unsigned long long index;
    unsigned long long size = sizeof(nbp_mt_scheduler_context_t);
    if (numberOfRules > 1) {
        size += ((numberOfRules - 1) * sizeof(nbp_mt_scheduler_rule_t));
    }

    nbp_mt_scheduler_context_t* ctx = (nbp_mt_scheduler_context_t*) NBP_ALLOC(size);
    if (ctx == NBP_NULL_POINTER) {
        NBP_HANDLE_ERROR_CTX_STRING(
            NBP_ERROR_ALLOC,
            "could not alloc context"
        );
        NBP_EXIT(NBP_EXIT_STATUS_OUT_OF_MEMORY);
        return NBP_NULL_POINTER;
    }

    ctx->numberOfRules = numberOfRules;
    for (index = 0; index < numberOfRules; ++index) {
        ctx->rules[index] = rules[index];
    }

    return (void*) ctx;
}

NBP_SCHEDULER_FUNC_INIT(nbp_basic_mt_scheduler_init)
{
}

NBP_SCHEDULER_FUNC_UNINIT(nbp_basic_mt_scheduler_uninit)
{
}

NBP_SCHEDULER_FUNC_RUN(nbp_basic_mt_scheduler_run)
{
}

NBP_SCHEDULER_FUNC_ADD_TEST(nbp_basic_mt_scheduler_add_test)
{
}

NBP_SCHEDULER_FUNC_ADD_TEST_CTX(nbp_basic_mt_scheduler_add_test_ctx)
{
}

NBP_SCHEDULER_FUNC_MODULE_STARTED_CTX(nbp_basic_mt_scheduler_module_started_ctx)
{
}

NBP_DEFINE_SCHEDULER(
    nbpDefaultScheduler,
    NBP_SCHEDULER_USE_FUNC_INIT(nbp_basic_mt_scheduler_init),
    NBP_SCHEDULER_USE_FUNC_UNINIT(nbp_basic_mt_scheduler_uninit),
    NBP_SCHEDULER_USE_FUNC_RUN(nbp_basic_mt_scheduler_run),
    NBP_SCHEDULER_USE_FUNC_ADD_TEST(nbp_basic_mt_scheduler_add_test),
    NBP_SCHEDULER_USE_FUNC_ADD_TEST_CTX(nbp_basic_mt_scheduler_add_test_ctx),
    NBP_SCHEDULER_NO_FUNC_MODULE_STARTED,
    NBP_SCHEDULER_USE_FUNC_MODULE_STARTED_CTX(nbp_basic_mt_scheduler_module_started_ctx),
    NBP_SCHEDULER_NO_FUNC_MODULE_COMPLETED
);

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_PRIVATE_SCHEDULER_BASIC_MT_SCHEDULER_H
