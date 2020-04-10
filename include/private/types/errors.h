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

#ifndef NBP_PRIVATE_TYPES_ERRORS_H
#define NBP_PRIVATE_TYPES_ERRORS_H

#define NBP_ERROR_CONTEXT_EMPTY                                 (int) 0
#define NBP_ERROR_CONTEXT_STRING                                (int) 1
#define NBP_ERROR_CONTEXT_CUSTOM                                (int) 2

#define NBP_ERROR_TYPE int

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
