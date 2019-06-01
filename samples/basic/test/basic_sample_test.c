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

#include "basic_sample.h"

NBP_TEST(test_my_add)
{
    NBP_CHECK(my_add(1, 1) == 2);
    NBP_CHECK(my_add(2, 2) == 4);
    NBP_CHECK(my_add(3, 3) == 6);
    NBP_CHECK(my_add(4, 4) == 8);
    NBP_CHECK(my_add(5, 5) == 10);
}

NBP_TEST(test_my_sub)
{
    NBP_CHECK(my_sub(1, 1) == 0);
    NBP_CHECK(my_sub(2, 2) == 0);
    NBP_CHECK(my_sub(3, 3) == 0);
    NBP_CHECK(my_sub(4, 4) == 0);
    NBP_CHECK(my_sub(5, 5) == 0);
}

NBP_TEST(test_my_mul)
{
    NBP_CHECK(my_mul(1, 1) == 1);
    NBP_CHECK(my_mul(2, 2) == 4);
    NBP_CHECK(my_mul(3, 3) == 9);
    NBP_CHECK(my_mul(4, 4) == 16);
    NBP_CHECK(my_mul(5, 5) == 25);
}

NBP_TEST(test_my_div)
{
    NBP_CHECK(my_div(1, 1) == 1);
    NBP_CHECK(my_div(2, 2) == 1);
    NBP_CHECK(my_div(3, 3) == 1);
    NBP_CHECK(my_div(4, 4) == 1);
    NBP_CHECK(my_div(5, 5) == 1);
}

NBP_MAIN()
{
    NBP_CALL_TEST(test_my_add);
    NBP_CALL_TEST(test_my_sub);
    NBP_CALL_TEST(test_my_mul);
    NBP_CALL_TEST(test_my_div);

    NBP_RUN();
}
