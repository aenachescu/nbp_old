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

#ifndef NBP_PRIVATE_CHECK_COMPILE_FLAGS_H
#define NBP_PRIVATE_CHECK_COMPILE_FLAGS_H

/*
 * Make sure there is only one OS defined
 */
#undef NBP_PRIVATE_OS_TYPE

#ifdef NBP_OS_LINUX
#define NBP_PRIVATE_OS_TYPE
#endif // end if NBP_OS_LINUX

#ifdef NBP_OS_WINDOWS
#ifndef NBP_PRIVATE_OS_TYPE
#define NBP_PRIVATE_OS_TYPE
#else // NBP_PRIVATE_OS_TYPE not defined
#error "More NBP_OS_* macros are defined"
#endif // end if NBP_PRIVATE_OS_TYPE
#endif // end if NBP_OS_WINDOWS

#ifdef NBP_OS_MAC
#ifndef NBP_PRIVATE_OS_TYPE
#define NBP_PRIVATE_OS_TYPE
#else // NBP_PRIVATE_OS_TYPE not defined
#error "More NBP_OS_* macros are defined"
#endif // end if NBP_PRIVATE_OS_TYPE
#endif // end if NBP_OS_MAC

#ifdef NBP_OS_CUSTOM
#ifndef NBP_PRIVATE_OS_TYPE
#define NBP_PRIVATE_OS_TYPE
#else // NBP_PRIVATE_OS_TYPE not defined
#error "More NBP_OS_* macros are defined"
#endif // end if NBP_PRIVATE_OS_TYPE
#endif // end if NBP_OS_CUSTOM

#ifndef NBP_PRIVATE_OS_TYPE
#error "Unknown OS"
#endif // end if NBP_PRIVATE_OS_TYPE

#undef NBP_PRIVATE_OS_TYPE

/*
 * Make sure there is only one compiler defined
 */
#undef NBP_PRIVATE_COMPILER_TYPE

#ifdef NBP_COMPILER_GCC
#define NBP_PRIVATE_COMPILER_TYPE
#endif // end if NBP_COMPILER_GCC

#ifdef NBP_COMPILER_GPP
#ifndef NBP_PRIVATE_COMPILER_TYPE
#define NBP_PRIVATE_COMPILER_TYPE
#else // NBP_PRIVATE_COMPILER_TYPE not defined
#error "More NBP_COMPILER_* macros are defined"
#endif // end if NBP_PRIVATE_COMPILER_TYPE
#endif // end if NBP_COMPILER_GPP

#ifdef NBP_COMPILER_CLANG
#ifndef NBP_PRIVATE_COMPILER_TYPE
#define NBP_PRIVATE_COMPILER_TYPE
#else // NBP_PRIVATE_COMPILER_TYPE not defined
#error "More NBP_COMPILER_* macros are defined"
#endif // end if NBP_PRIVATE_COMPILER_TYPE
#endif // end if NBP_COMPILER_CLANG

#ifndef NBP_PRIVATE_COMPILER_TYPE
#error "Unknown compiler"
#endif // end if NBP_PRIVATE_COMPILER_TYPE

#undef NBP_PRIVATE_COMPILER_TYPE

/*
 * Make sure there is only one defined scheduler
 */
#undef NBP_PRIVATE_SCHEDULER_TYPE

#ifdef NBP_CUSTOM_SCHEDULER
#define NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_CUSTOM_SCHEDULER

#ifdef NBP_MT_SCHEDULER
#ifdef NBP_PRIVATE_SCHEDULER_TYPE
#error "Cannot enabe NBP_MT_SCHEDULER because another scheduler is enabled"
#else // NBP_PRIVATE_SCHEDULER_TYPE not defined
#define NBP_PRIVATE_SCHEDULER_TYPE
#define NBP_MT_SUPPORT
#endif // end if NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_MT_SCHEDULER

#ifdef NBP_SCHEDULER
#ifdef NBP_PRIVATE_SCHEDULER_TYPE
#error "Cannot enabe NBP_SCHEDULER because another scheduler is enabled"
#else // NBP_PRIVATE_SCHEDULER_TYPE not defined
#define NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_SCHEDULER

/*
 * If no scheduler is defined then define the default scheduler
 */
#ifndef NBP_PRIVATE_SCHEDULER_TYPE
#define NBP_SCHEDULER
#endif // end if NBP_PRIVATE_SCHEDULER_TYPE

#undef NBP_PRIVATE_SCHEDULER_TYPE

/*
 * If no printer is defined then define the default printer
 */
#if !defined NBP_CUSTOM_PRINTER && !defined NBP_PRINTER
#define NBP_PRINTER
#endif // end if ! NBP_CUSTOM_PRINTER && ! NBP_PRINTER

#endif // end if NBP_PRIVATE_CHECK_COMPILE_FLAGS_H
