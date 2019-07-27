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

#error "not supported"

#else 

#define NBP_ATOMIC_UINT_TYPE unsigned int

#define NBP_ATOMIC_UINT_LOAD(ptr) (*(ptr))

#define NBP_ATOMIC_UINT_ADD_AND_FETCH(ptr, value)                              \
    (*(ptr)) += value

#define NBP_ATOMIC_UINT_CAS(ptr, oldVal, newVal)                               \
    (*(ptr)) == oldVal ? (*(ptr)) = newVal, oldVal : (*(ptr))

#define NBP_EVENT_TYPE int

#define NBP_EVENT_DEFAULT_VALUE 0

#define NBP_EVENT_INIT(ev) do {} while(0)

#define NBP_EVENT_UNINIT(ev) do {} while(0)

#define NBP_WAIT_EVENT(ev) do {} while(0)

#define NBP_SIGNAL_EVENT(ev) do {} while(0)

#endif // end if NBP_MT_SUPPORT

#endif // end if NBP_PRIVATE_TYPES_SYNC_H