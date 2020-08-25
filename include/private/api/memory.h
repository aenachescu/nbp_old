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

#ifndef NBP_PRIVATE_API_MEMORY_H
#define NBP_PRIVATE_API_MEMORY_H

/*
 * TODO: add docs
 */
#ifndef NBP_MEMORY_CUSTOM_ALLOCATOR

#include <stdlib.h>

/*
 * TODO: add docs
 */
#define NBP_MEMORY_NULL_POINTER NULL

/*
 * TODO: add docs
 */
#define NBP_MEMORY_ALLOC malloc

/*
 * TODO: add docs
 */
#define NBP_MEMORY_FREE free

#else // if custom memory allocator is enabled

#ifndef NBP_MEMORY_NULL_POINTER
#error "Custom memory allocator is enabled but NBP_MEMORY_NULL_POINTER is undefined"
#endif // end if NBP_MEMORY_NULL_POINTER

#ifndef NBP_MEMORY_ALLOC
#error "Custom memory allocator is enabled but NBP_MEMORY_ALLOC is undefined"
#endif // end if NBP_MEMORY_ALLOC

#ifndef NBP_MEMORY_FREE
#error "Custom memory allocator is enabled but NBP_MEMORY_FREE is undefined"
#endif // end if NBP_MEMORY_FREE

#endif // end if NBP_MEMORY_CUSTOM_ALLOCATOR

#endif // end if NBP_PRIVATE_API_MEMORY_H
