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

#ifndef NBP_PRIVATE_PRINTER_H
#define NBP_PRIVATE_PRINTER_H

#ifdef NBP_LIBRARY_MAIN

/*
 * Default nbp printer for Linux
 */
#ifdef NBP_OS_LINUX
#include "linux_basic_printer.h"
#endif // end if NBP_OS_LINUX

/*
 * Default nbp printer for Windows
 */
#ifdef NBP_OS_WINDOWS
#error "Not supported"
#endif // end if NBP_OS_WINDOWS

/*
 * Default nbp printer for Mac
 */
#ifdef NBP_OS_MAC
#error "Not supported"
#endif // end if NBP_OS_MAC

/*
 * We don't have default printer for custom OS
 */
#ifdef NBP_OS_CUSTOM
#error "Not supported"
#endif

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_PRIVATE_PRINTER_H
