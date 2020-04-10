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

#ifndef NBP_PRIVATE_TYPES_SYNC_H
#define NBP_PRIVATE_TYPES_SYNC_H

#ifdef NBP_MT_SUPPORT

#ifdef NBP_OS_LINUX

#include <semaphore.h>

/*
 * Atomic unsigned int wrapper
 */

#define NBP_ATOMIC_UINT_TYPE unsigned int

#define NBP_ATOMIC_UINT_INIT(val) val

#define NBP_ATOMIC_UINT_LOAD(ptr) __atomic_load_n((ptr), __ATOMIC_SEQ_CST)

#define NBP_ATOMIC_UINT_ADD_AND_FETCH(ptr, value)                              \
    __sync_add_and_fetch((ptr), (value))

#define NBP_ATOMIC_UINT_CAS(ptr, oldVal, newVal)                               \
    __sync_val_compare_and_swap((ptr), (oldVal), (newVal))

/*
 * Event wrapper
 */

#define NBP_EVENT_TYPE sem_t

#define NBP_EVENT_DEFAULT_VALUE { .__align = 0 }

#define NBP_EVENT_INIT(ev)                                                     \
    sem_init(&ev, 0, 0) == 0                                                   \
        ? NBP_NO_ERROR                                                         \
        : NBP_ERROR_FAILED_TO_INIT_EVENT

#define NBP_EVENT_UNINIT(ev)                                                   \
    sem_destroy(&ev) == 0                                                      \
        ? NBP_NO_ERROR                                                         \
        : NBP_ERROR_FAILED_TO_UNINIT_EVENT

#define NBP_WAIT_EVENT(ev)                                                     \
    sem_wait(&ev) == 0 && sem_post(&ev) == 0                                   \
        ? NBP_NO_ERROR                                                         \
        : NBP_ERROR_FAILED_TO_WAIT_EVENT

#define NBP_SIGNAL_EVENT(ev)                                                   \
    sem_post(&ev) == 0                                                         \
        ? NBP_NO_ERROR                                                         \
        : NBP_ERROR_FAILED_TO_SIGNAL_EVENT

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

#else // NBP_MT_SUPPORT not defined

#define NBP_ATOMIC_UINT_TYPE unsigned int

#define NBP_ATOMIC_UINT_INIT(val) val

#define NBP_ATOMIC_UINT_LOAD(ptr) (*(ptr))

#define NBP_ATOMIC_UINT_ADD_AND_FETCH(ptr, value)                              \
    ((*(ptr)) += (value))

#define NBP_ATOMIC_UINT_CAS(ptr, oldVal, newVal)                               \
    ((*(ptr)) == (oldVal) ? (*(ptr)) = (newVal), (oldVal) : (*(ptr)))

#define NBP_EVENT_TYPE int

#define NBP_EVENT_DEFAULT_VALUE 0

#define NBP_EVENT_INIT(ev) NBP_NO_ERROR

#define NBP_EVENT_UNINIT(ev) NBP_NO_ERROR

#define NBP_WAIT_EVENT(ev) NBP_NO_ERROR

#define NBP_SIGNAL_EVENT(ev) NBP_NO_ERROR

#endif // end if NBP_MT_SUPPORT

#endif // end if NBP_PRIVATE_TYPES_SYNC_H