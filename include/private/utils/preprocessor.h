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

#ifndef NBP_PRIVATE_UTILS_PREPROCESSOR_H
#define NBP_PRIVATE_UTILS_PREPROCESSOR_H

#define NBP_PRIAVTE_PP_CONCAT_HELPER(a, b) a ## b
#define NBP_PRIVATE_PP_CONCAT(a, b) NBP_PRIAVTE_PP_CONCAT_HELPER(a, b)

#endif // end if NBP_PRIVATE_UTILS_PREPROCESSOR_H
