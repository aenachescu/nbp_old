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

#ifndef NBP_PRIVATE_MEMORY_ALLOCATOR_H
#define NBP_PRIVATE_MEMORY_ALLOCATOR_H

/*
 * TODO: add docs
 */
#ifndef NBP_CUSTOM_MEMORY_ALLOCATOR

#include <stdlib.h>
#define NBP_ALLOC malloc
#define NBP_FREE free
#define NBP_NULL_POINTER NULL

#else // if custom memory allocator is enabled

#ifndef NBP_ALLOC
#error "Custom memory allocator is enabled but no alloc function is provided"
#endif // end if NBP_ALLOC

#ifndef NBP_FREE
#error "Custom memory allocator is enabled but no free function is provided"
#endif // end if NBP_FREE

#ifndef NBP_NULL_POINTER
#error "Custom memory allocator is enabled but NBP_NULL_POINTER is undefined"
#endif // end if NBP_NULL_POINTER

#endif // end if NBP_CUSTOM_MEMORY_ALLOCATOR

#endif // end if NBP_PRIVATE_MEMORY_ALLOCATOR_H
