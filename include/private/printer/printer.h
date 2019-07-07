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

#ifndef NBP_PRIVATE_PRINTER_H
#define NBP_PRIVATE_PRINTER_H

#ifdef NBP_LIBRARY_MAIN

/*
 * TODO: add docs
 */
#ifndef NBP_CUSTOM_PRINTER

/*
 * If no printer is defined then enable NBP_MT_PRINTER when NPB_MT_SUPPORT
 * is enabled or enable NBP_PRINTER when NBP_MT_SUPPORT is disabled
 */
#if !defined NBP_MT_PRINTER && !defined NBP_PRINTER
#ifdef NBP_MT_SUPPORT
#define NBP_MT_PRINTER
#else // NBP_MT_SUPPORT not defined
#define NBP_PRINTER
#endif // end if NBP_MT_SUPPORT
#endif // end if ! NBP_MT_PRINTER && ! NBP_PRINTER

#endif // end if NBP_CUSTOM_PRINTER

/*
 * TODO: add docs
 */
#ifdef NBP_MT_PRINTER

/*
 * Check if NBP_MT_SUPPORT is enabled because NBP_MT_PRINTER can be enabled
 * by integrator and NBP_MT_PRINTER is multi thread.
 */
#ifndef NBP_MT_SUPPORT
#error "Cannot enable NBP_MT_PRINTER if NBP_MT_SUPPORT is not enabled"
#endif // end if NBP_MT_SUPPORT

#error "Not supported"

#endif // end if NBP_MT_PRINTER

/*
 * TODO: add docs
 */
#ifdef NBP_PRINTER

/*
 * Check if NBP_MT_SUPPORT is not enabled because NBP_PRINTER can be enabled
 * by integrator and NBP_PRINTER is single thread.
 */
#ifdef NBP_MT_SUPPORT
#error "Cannot enable NBP_PRINTER if NBP_MT_SUPPORT is enabled"
#endif // end if NBP_MT_SUPPORT

#include "basic_printer/basic_printer.h"

#endif // end if NBP_PRINTER

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_PRIVATE_PRINTER_H
