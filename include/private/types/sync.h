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