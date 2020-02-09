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

#ifndef NBP_PRIVATE_API_SCHEDULER_H
#define NBP_PRIVATE_API_SCHEDULER_H

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_FUNC_INIT(func)                                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)(void)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_USE_FUNC_INIT(func)                                      \
    .init = NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_NO_FUNC_INIT                                             \
    .init = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_FUNC_UNINIT(func)                                        \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)(void)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_USE_FUNC_UNINIT(func)                                    \
    .uninit = NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_NO_FUNC_UNINIT                                           \
    .uninit = NBP_NULL_POINTER

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_FUNC_RUN(func)                                           \
    static void NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)(void)

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
        nbp_test_details_t* test                                               \
    )

/*
 * TODO: add docs
 */
#define NBP_SCHEDULER_USE_FUNC_ADD_TEST(func)                                  \
    .addTest = NBP_PRIVATE_PP_CONCAT(nbp_scheduler_func_, func)

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

#endif // end if NBP_PRIVATE_API_SCHEDULER_H
