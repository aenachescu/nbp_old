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

#ifndef NBP_PRIVATE_API_PRINTER_H
#define NBP_PRIVATE_API_PRINTER_H

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_INIT(func)                                            \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        void                                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_INIT(func)                                        \
    .init = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_INIT                                               \
    .init = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_UNINIT(func)                                          \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        void                                                                   \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_UNINIT(func)                                      \
    .uninit = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_UNINIT                                             \
    .uninit = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_HANDLE_ERROR(func)                                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        int                                                                    \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_HANDLE_ERROR(func)                                \
    .handleError = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_HANDLE_ERROR                                       \
    .handleError = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_BEGIN(func)                                      \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t*                                                    \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_BEGIN(func)                                  \
    .testBegin = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_BEGIN                                         \
    .testBegin = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_TEST_END(func)                                        \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t*                                                    \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_TEST_END(func)                                    \
    .testEnd = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_TEST_END                                           \
    .testEnd = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_BEGIN(func)                                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_module_details_t*                                                  \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_BEGIN(func)                                \
    .moduleBegin = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_BEGIN                                       \
    .moduleBegin = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_MODULE_END(func)                                      \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_module_details_t*                                                  \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_MODULE_END(func)                                  \
    .moduleEnd = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_MODULE_END                                         \
    .moduleEnd = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_RESULT(func)                                    \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t*,                                                   \
        const char*,                                                           \
        int,                                                                   \
        int,                                                                   \
        const char*,                                                           \
        const char*                                                            \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_RESULT(func)                                \
    .checkResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_RESULT                                       \
    .checkResult = 0x0

/*
 * TODO: add docs
 */
#define NBP_PRINTER_FUNC_CHECK_OP_RESULT(func)                                 \
    static void NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)(                \
        nbp_test_details_t*,                                                   \
        const char*,                                                           \
        const char*,                                                           \
        int,                                                                   \
        int,                                                                   \
        int,                                                                   \
        const char*,                                                           \
        const char*                                                            \
    )

/*
 * TODO: add docs
 */
#define NBP_PRINTER_USE_FUNC_CHECK_OP_RESULT(func)                             \
    .checkOpResult = NBP_PRIVATE_PP_CONCAT(nbp_printer_func_, func)

/*
 * TODO: add docs
 */
#define NBP_PRINTER_NO_FUNC_CHECK_OP_RESULT                                    \
    .checkOpResult = 0x0

#endif // end if NBP_PRIVATE_API_PRINTER_H

