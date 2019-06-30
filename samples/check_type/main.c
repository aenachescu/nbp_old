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

#define NBP_LIBRARY_MAIN
#include <nbp.h>

NBP_MAIN_MODULE(check_type)
{
    NBP_CALL_MODULE(check_char);
    NBP_CALL_MODULE(check_short);
    NBP_CALL_MODULE(check_ushort);
    NBP_CALL_MODULE(check_int);
    NBP_CALL_MODULE(check_uint);
    NBP_CALL_MODULE(check_long);
    NBP_CALL_MODULE(check_ulong);
    NBP_CALL_MODULE(check_llong);
    NBP_CALL_MODULE(check_ullong);
    NBP_CALL_MODULE(check_float);
    NBP_CALL_MODULE(check_double);
    NBP_CALL_MODULE(check_ldouble);
}