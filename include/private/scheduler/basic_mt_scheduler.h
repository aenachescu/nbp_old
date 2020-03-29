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
#define NBP_MT_SCHEDULER_DATA_TYPE_TEST_NAME        (unsigned char) 4
#define NBP_MT_SCHEDULER_DATA_TYPE_MODULE_NAME      (unsigned char) 5

struct nbp_mt_scheduler_rule_t {
    unsigned char ruleType;
    unsigned char dataType;
    union {
        nbp_test_details_t* test;
        nbp_module_details_t* module;
        const char* name;
    };
};
typedef struct nbp_mt_scheduler_rule_t nbp_mt_scheduler_rule_t;

struct nbp_mt_scheduler_context_t {
    unsigned int numberOfRules;
    nbp_mt_scheduler_rule_t* rules;
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

nbp_mt_scheduler_rule_t nbp_mt_schduler_create_rule_from_test_name(
    unsigned char ruleType,
    const char* testName
);

nbp_mt_scheduler_rule_t nbp_mt_schduler_create_rule_from_module_name(
    unsigned char ruleType,
    const char* moduleName
);

void* nbp_mt_scheduler_create_ctx(
    int numberOfRules,
    nbp_mt_scheduler_rule_t* rules
);

#define NBP_MT_SCHEDULER_RUN_BEFORE_TEST(test)                                 \
    nbp_mt_schduler_create_rule_from_test(                                     \
        NBP_MT_SCHEDULER_RULE_TYPE_BEFORE,                                     \
        test                                                                   \
    )

#define NBP_MT_SCHEDULER_RUN_AFTER_TEST(test)                                  \
    nbp_mt_schduler_create_rule_from_test(                                     \
        NBP_MT_SCHEDULER_RULE_TYPE_AFTER,                                      \
        test                                                                   \
    )

#define NBP_MT_SCHEDULER_RUN_BEFORE_MODULE(module)                             \
    nbp_mt_schduler_create_rule_from_module(                                   \
        NBP_MT_SCHEDULER_RULE_TYPE_BEFORE,                                     \
        module                                                                 \
    )

#define NBP_MT_SCHEDULER_RUN_AFTER_MODULE(module)                              \
    nbp_mt_schduler_create_rule_from_module(                                   \
        NBP_MT_SCHEDULER_RULE_TYPE_AFTER,                                      \
        module                                                                 \
    )

#define NBP_MT_SCHEDULER_RUN_BEFORE_TEST_NAME(testName)                        \
    nbp_mt_schduler_create_rule_from_test_name(                                \
        NBP_MT_SCHEDULER_RULE_TYPE_BEFORE,                                     \
        testName                                                               \
    )

#define NBP_MT_SCHEDULER_RUN_AFTER_TEST_NAME(testName)                         \
    nbp_mt_schduler_create_rule_from_test_name(                                \
        NBP_MT_SCHEDULER_RULE_TYPE_AFTER,                                      \
        testName                                                               \
    )

#define NBP_MT_SCHEDULER_RUN_BEFORE_MODULE_NAME(moduleName)                    \
    nbp_mt_schduler_create_rule_from_module_name(                              \
        NBP_MT_SCHEDULER_RULE_TYPE_BEFORE,                                     \
        moduleName                                                             \
    )

#define NBP_MT_SCHEDULER_RUN_AFTER_MODULE_NAME(moduleName)                     \
    nbp_mt_schduler_create_rule_from_module_name(                              \
        NBP_MT_SCHEDULER_RULE_TYPE_AFTER,                                      \
        moduleName                                                             \
    )

#define NBP_MT_SCHEDULER_PRIVATE_GET_NUMBER_OF_RULES(...)                      \
    sizeof((nbp_mt_scheduler_rule_t[]){ __VA_ARGS__ }) /                       \
    sizeof(nbp_mt_scheduler_rule_t)

#define NBP_MT_SCHEDULER_CTX(...)                                              \
    nbp_mt_scheduler_create_ctx(                                               \
        NBP_MT_SCHEDULER_PRIVATE_GET_NUMBER_OF_RULES(__VA_ARGS__),             \
        (nbp_mt_scheduler_rule_t[]){ __VA_ARGS__ }                             \
    )

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

// TODO: implement nbp_mt_scheduler_create_rule_* functions
// TODO: implement nbp_mt_scheduler_create_ctx function

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
