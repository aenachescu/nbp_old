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

#ifndef NBP_PRIVATE_API_EXIT_H
#define NBP_PRIVATE_API_EXIT_H

#ifndef NBP_CUSTOM_EXIT

#include <stdlib.h>

#define NBP_EXIT(exitCode) exit(exitCode)

#else // NBP_CUSTOM_EXIT is defined

#ifndef NBP_EXIT
#error "Custom exit is enabled but no exit function is provided"
#endif // end if NBP_EXIT

#endif // end if NBP_CUSTOM_EXIT

#endif // end if NBP_PRIVATE_API_EXIT_H
