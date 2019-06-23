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

#ifndef NBP_PRIVATE_DETAILS_PRINTER_H
#define NBP_PRIVATE_DETAILS_PRINTER_H

void nbp_notify_printer_test_begin(
    nbp_test_details_t*
);

void nbp_notify_printer_test_end(
    nbp_test_details_t*
);

void nbp_notify_printer_module_begin(
    nbp_module_details_t*
);

void nbp_notify_printer_module_end(
    nbp_module_details_t*
);

void nbp_notify_printer_handle_error(
    int
);

void nbp_notify_printer_check_result(
    nbp_test_details_t*,
    const char*,
    int,
    int,
    const char*,
    const char*
);

void nbp_notify_printer_check_op_result(
    nbp_test_details_t*,
    const char*,
    const char*,
    int,
    int,
    int,
    const char*,
    const char*
);

#endif // end if NBP_PRIVATE_DETAILS_PRINTER_H
