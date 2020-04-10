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

#ifndef NBP_PRIVATE_TYPES_EXIT_STATUS_H
#define NBP_PRIVATE_TYPES_EXIT_STATUS_H

#define NBP_EXIT_STATUS_PASSED                                  (int)  0
#define NBP_EXIT_STATUS_FAILED                                  (int)  1
#define NBP_EXIT_STATUS_GENERIC_ERROR                           (int) -1
#define NBP_EXIT_STATUS_INVALID_CMDLINE                         (int) -2
#define NBP_EXIT_STATUS_EVENT_ERROR                             (int) -3
#define NBP_EXIT_STATUS_MUTEX_ERROR                             (int) -4
#define NBP_EXIT_STATUS_INVALID_SCHEDULER                       (int) -5
#define NBP_EXIT_STATUS_OUT_OF_MEMORY                           (int) -6

#endif // end if NBP_PRIVATE_TYPES_EXIT_STATUS_H

