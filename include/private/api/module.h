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
#define NBP_SETUP_MODULE(name)                                                 \
    void NBP_PRIVATE_PP_CONCAT(nbp_setup_module_, name)(                       \
        nbp_module_details_t* module                                           \
    )

/*
 * TODO: add docs
 */
#define NBP_NO_TEARDOWN_FUNC                                                   \
    nbp_empty_teardown_func

/*
 * TODO: add docs
 */
#define NBP_TEARDOWN_MODULE(name)                                              \
    void NBP_PRIVATE_PP_CONCAT(nbp_teardown_module_, name)(                    \
        nbp_module_details_t* module                                           \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE(name)                                                       \
    void NBP_PRIVATE_PP_CONCAT(nbp_module_, name)(                             \
        nbp_module_details_t*,                                                 \
        nbp_before_test_pfn_t,                                                 \
        nbp_after_test_pfn_t                                                   \
    );                                                                         \
    nbp_module_details_t nbpModuleDetails ## name = {                          \
        .moduleName             = #name,                                       \
        .moduleFunc             = NBP_PRIVATE_PP_CONCAT(nbp_module_, name),    \
        .setup                  = 0x0,                                         \
        .teardown               = 0x0,                                         \
        .firstTest              = 0x0,                                         \
        .lastTest               = 0x0,                                         \
        .parent                 = 0x0,                                         \
        .firstSubmodule         = 0x0,                                         \
        .lastSubmodule          = 0x0,                                         \
        .next                   = 0x0,                                         \
        .prev                   = 0x0,                                         \
        .numTests               = 0,                                           \
        .numCompletedTests      = 0,                                           \
        .numSubmodules          = 0,                                           \
        .numCompletedSubmodules = 0,                                           \
        .moduleState            = NBP_MODULE_STATE_NOT_INITIALIZED,            \
        .deepth                 = 0,                                           \
    };                                                                         \
    void NBP_PRIVATE_PP_CONCAT(nbp_module_, name)(                             \
        nbp_module_details_t* module,                                          \
        nbp_before_test_pfn_t beforeTest,                                      \
        nbp_after_test_pfn_t afterTest                                         \
    )

/*
 * TODO: add docs
 */
#define NBP_MODULE_FIXTURES(name, setupFunc, teardownFunc)                     \
    void NBP_PRIVATE_PP_CONCAT(nbp_module_, name)(                             \
        nbp_module_details_t*,                                                 \
        nbp_before_test_pfn_t,                                                 \
        nbp_after_test_pfn_t                                                   \
    );                                                                         \
    NBP_SETUP_MODULE(setupFunc);                                               \
    NBP_TEARDOWN_MODULE(teardownFunc);                                         \
    nbp_module_details_t nbpModuleDetails ## name = {                          \
        .moduleName             = #name,                                       \
        .moduleFunc             = NBP_PRIVATE_PP_CONCAT(nbp_module_, name),    \
        .setup                  =                                              \
            NBP_PRIVATE_PP_CONCAT(nbp_setup_module_, setupFunc),               \
        .teardown               =                                              \
            NBP_PRIVATE_PP_CONCAT(nbp_teardown_module_, teardownFunc),         \
        .firstTest              = 0x0,                                         \
        .lastTest               = 0x0,                                         \
        .parent                 = 0x0,                                         \
        .firstSubmodule         = 0x0,                                         \
        .lastSubmodule          = 0x0,                                         \
        .next                   = 0x0,                                         \
        .prev                   = 0x0,                                         \
        .numTests               = 0,                                           \
        .numCompletedTests      = 0,                                           \
        .numSubmodules          = 0,                                           \
        .numCompletedSubmodules = 0,                                           \
        .moduleState            = NBP_MODULE_STATE_NOT_INITIALIZED,            \
        .deepth                 = 0,                                           \
    };                                                                         \
    void NBP_PRIVATE_PP_CONCAT(nbp_module_, name)(                             \
        nbp_module_details_t* module,                                          \
        nbp_before_test_pfn_t beforeTest,                                      \
        nbp_after_test_pfn_t afterTest                                         \
    )

/*
 * TODO: add docs
 */
#define NBP_CALL_MODULE(name)                                                  \
    extern nbp_module_details_t nbpModuleDetails ## name;                      \
    (void)(beforeTest);                                                        \
    (void)(afterTest);                                                         \
    nbp_call_module(                                                           \
        & nbpModuleDetails ## name,                                            \
        module                                                                 \
    )

/*
 * TODO: add docs
 */
#define NBP_THIS_MODULE module

/*
 * TODO: add docs
 */
#define NBP_GET_MODULE_NAME(module) module->moduleName

#endif // end if NBP_PRIVATE_API_MODULE_H
