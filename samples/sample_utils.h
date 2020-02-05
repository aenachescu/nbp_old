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

#ifndef NBP_SAMPLE_UTILS
#define NBP_SAMPLE_UTILS

#include <stdio.h>

static inline void write_message_to_file(const char* msg)
{
    FILE *fp = fopen("output.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%s\n", msg);
        fclose(fp);
    }
}

static inline void write_message_to_file_2(const char* msg1, const char* msg2)
{
    FILE *fp = fopen("output.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%s %s\n", msg1, msg2);
        fclose(fp);
    }
}

#ifdef SAMPLE_DISABLE_SLEEP

#define SAMPLE_SLEEP()

#else

#ifdef SAMPLE_LINUX
#include <unistd.h>
#define SAMPLE_SLEEP() usleep(200000)
#elif defined SAMPLE_WINDOWS
#include <Windows.h>
#define SAMPLE_SLEEP() Sleep(200000)
#else
#error "Unknown OS"
#endif

#endif

#endif // end if NBP_SAMPLE_UTILS
