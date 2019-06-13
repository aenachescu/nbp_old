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

#include <nbp.h>

#ifdef SAMPLE_LINUX
#include <unistd.h>
#define SAMPLE_SLEEP(seconds) sleep(seconds)
#else
#error "Unknow OS"
#endif

NBP_TEST(test5)
{
    SAMPLE_SLEEP(1);
    NBP_CHECK(1);
}

NBP_TEST(test6)
{
    SAMPLE_SLEEP(1);
    NBP_CHECK(2);
}

NBP_TEST(test7)
{
    SAMPLE_SLEEP(1);
    NBP_CHECK(3);
}

NBP_TEST(test8)
{
    SAMPLE_SLEEP(1);
    NBP_CHECK(4);
}

NBP_MODULE(submodule2)
{
    NBP_CALL_TEST(test5);
    NBP_CALL_TEST(test6);
    NBP_CALL_TEST(test7);
    NBP_CALL_TEST(test8);
}
