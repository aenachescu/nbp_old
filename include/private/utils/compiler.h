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

#ifndef NBP_PRIVATE_UTILS_COMPILER_H
#define NBP_PRIVATE_UTILS_COMPILER_H

#define NBP_MAYBE_UNUSED_PARAMETER

#ifdef NBP_COMPILER_GCC

#undef NBP_MAYBE_UNUSED_PARAMETER
#define NBP_MAYBE_UNUSED_PARAMETER __attribute__ ((unused))

#endif // end if NBP_COMPILER_GCC

#ifdef NBP_COMPILER_GPP

#undef NBP_MAYBE_UNUSED_PARAMETER
#define NBP_MAYBE_UNUSED_PARAMETER __attribute__ ((unused))

#endif // end if NBP_COMPILER_GPP

#ifdef NBP_COMPILER_CLANG

#undef NBP_MAYBE_UNUSED_PARAMETER
#define NBP_MAYBE_UNUSED_PARAMETER __attribute__ ((unused))

#endif // end if NBP_COMPILER_CLANG

#endif // end if NBP_PRIVATE_UTILS_COMPILER_H
