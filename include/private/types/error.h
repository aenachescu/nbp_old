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

#ifndef NBP_PRIVATE_TYPES_ERROR_H
#define NBP_PRIVATE_TYPES_ERROR_H

#define NBP_ERROR_CONTEXT_EMPTY                     (unsigned int) 0x30000000
#define NBP_ERROR_CONTEXT_STRING                    (unsigned int) 0x30000001
#define NBP_ERROR_CONTEXT_CUSTOM                    (unsigned int) 0x30000002

#define NBP_ERROR_CODE_TYPE int

#define NBP_ERROR_CODE_SUCCESS                                  (int) 0
#define NBP_ERROR_CODE_TESTS_FAILED                             (int) 1
#define NBP_ERROR_CODE_NOT_ALL_TESTS_RUN                        (int) 2
#define NBP_ERROR_CODE_OUT_OF_MEMORY                            (int) 3
#define NBP_ERROR_CODE_UNKNOWN_OPERATOR                         (int) 4
#define NBP_ERROR_CODE_INVALID_SCHEDULER                        (int) 5
#define NBP_ERROR_CODE_SCHEDULER_RUN_DISABLED                   (int) 6
#define NBP_ERROR_CODE_INVALID_CMDLINE                          (int) 7
#define NBP_ERROR_CODE_SYNC_ERROR                               (int) 8
#define NBP_ERROR_CODE_GENERIC_ERROR                            (int) 9
#define NBP_ERROR_CODE_INTERNAL_ERROR                           (int) 10
#define NBP_ERROR_CODE_UNEXPECTED_INTERNAL_DATA                 (int) 11
#define NBP_ERROR_CODE_TEST_ALREADY_RUN                         (int) 12
#define NBP_ERROR_CODE_MODULE_ALREADY_RUN                       (int) 13
#define NBP_ERROR_CODE_UNEXPECTED_TEST_STATE                    (int) 14
#define NBP_ERROR_CODE_UNEXPECTED_MODULE_STATE                  (int) 15

struct nbp_error_t {
    NBP_ERROR_CODE_TYPE errorCode;
    int line;
    const char* filename;
    unsigned int contextType;
    union {
        const char* contextString;
        void* contextCustom;
    };
};
typedef struct nbp_error_t nbp_error_t;

#endif // end if NBP_PRIVATE_TYPES_ERROR_H
