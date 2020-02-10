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

#ifndef NBP_PRIVATE_TYPES_ERRORS_H
#define NBP_PRIVATE_TYPES_ERRORS_H

#define NBP_ERROR_CONTEXT_EMPTY                                 (int) 0
#define NBP_ERROR_CONTEXT_STRING                                (int) 1
#define NBP_ERROR_CONTEXT_CUSTOM                                (int) 2

#define ERROR_TYPE int

#define NBP_NO_ERROR                                            (int) 0
#define NBP_ERROR_ALLOC                                         (int) 1
#define NBP_ERROR_TEST_ALREADY_CALLED                           (int) 2
#define NBP_ERROR_MODULE_ALREADY_CALLED                         (int) 3
#define NBP_ERROR_SCHEDULER_NO_RUN_FUNC                         (int) 4
#define NBP_ERROR_SCHEDULER_NO_ADD_TEST_FUNC                    (int) 5
#define NBP_ERROR_UNKNOWN_OPERATOR                              (int) 6
#define NBP_ERROR_SCHEDULER_RUN_DISABLED                        (int) 7
#define NBP_ERROR_INVALID_TEST_STATE                            (int) 8
#define NBP_ERROR_INVALID_MODULE_STATE                          (int) 9
#define NBP_ERROR_FAILED_TO_INIT_EVENT                          (int) 10
#define NBP_ERROR_FAILED_TO_UNINIT_EVENT                        (int) 11
#define NBP_ERROR_FAILED_TO_WAIT_EVENT                          (int) 12
#define NBP_ERROR_FAILED_TO_SIGNAL_EVENT                        (int) 13
#define NBP_ERROR_TEST_FLAGS_INVALID_VALUE                      (int) 14
#define NBP_ERROR_MODULE_FLAGS_INVALID_VALUE                    (int) 15
#define NBP_ERROR_INVALID_MODULE_STATS                          (int) 16
#define NBP_ERROR_GENERIC                                       (int) 17
#define NBP_ERROR_TEST_NOT_FOUND                                (int) 18
#define NBP_ERROR_FAILED_TO_INIT_MUTEX                          (int) 19
#define NBP_ERROR_FAILED_TO_UNINIT_MUTEX                        (int) 20
#define NBP_ERROR_FAILED_TO_LOCK_MUTEX                          (int) 21
#define NBP_ERROR_FAILED_TO_UNLOCK_MUTEX                        (int) 22

struct nbp_error_t {
    int errorCode;
    int contextType;
    union {
        const char* contextString;
        void* contextCustom;
    };
};
typedef struct nbp_error_t nbp_error_t;

#endif // end if NBP_PRIVATE_TYPES_ERRORS_H
