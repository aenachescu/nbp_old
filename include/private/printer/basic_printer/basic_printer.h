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

#ifndef NBP_PRIVATE_PRINTER_BASIC_PRINTER_H
#define NBP_PRIVATE_PRINTER_BASIC_PRINTER_H

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

#ifndef NBP_PRIVATE_OS_TYPE
#error "Unknown OS"
#endif // end if NBP_PRIVATE_OS_TYPE

#undef NBP_PRIVATE_OS_TYPE

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

#endif // end if NBP_PRIVATE_PRINTER_BASIC_PRINTER_H
