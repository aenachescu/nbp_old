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

#ifndef NBP_PRIVATE_API_ERROR_H
#define NBP_PRIVATE_API_ERROR_H

/*
 * TODO: add docs
 */
#define NBP_HANDLE_ERROR(errCode)                                              \
    do {                                                                       \
        nbp_error_t err;                                                       \
        err.errorCode = errCode;                                               \
        err.contextType = NBP_ERROR_CONTEXT_EMPTY;                             \
        err.contextString = (const char*) 0x0;                                 \
        nbp_notify_printer_handle_error(err);                                  \
    } while (0);

/*
 * TODO: add docs
 */
#define NBP_HANDLE_ERROR_CTX_STRING(errCode, str)                              \
    do {                                                                       \
        nbp_error_t err;                                                       \
        err.errorCode = errCode;                                               \
        err.contextType = NBP_ERROR_CONTEXT_STRING;                            \
        err.contextString = str;                                               \
        nbp_notify_printer_handle_error(err);                                  \
    } while (0);

/*
 * TODO: add docs
 */
#define NBP_HANDLE_ERROR_CTX_CUSTOM(errCode, ctx)                              \
    do {                                                                       \
        nbp_error_t err;                                                       \
        err.errorCode = errCode;                                               \
        err.contextType = NBP_ERROR_CONTEXT_CUSTOM;                            \
        err.contextString = ctx;                                               \
        nbp_notify_printer_handle_error(err);                                  \
    } while (0);

/*
 * TODO: add docs
 */
#define NBP_ERROR_GET_CODE(err) err.errorCode

/*
 * TODO: add docs
 */
#define NBP_ERROR_GET_CONTEXT_TYPE(err) err.contextType

/*
 * TODO: add docs
 */
#define NBP_ERROR_GET_CONTEXT_STRING(err) err.contextString

/*
 * TODO: add docs
 */
#define NBP_ERROR_GET_CONTEXT_CUSTOM(err) err.contextCustom

#endif // end if NBP_PRIVATE_API_ERROR_H
