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

#if defined NBP_OS_LINUX

#include <unistd.h>
#include <semaphore.h>

#define SAMPLE_FORCE_SLEEP_MS(ms) usleep(ms * 1000)

#define SAMPLE_SEMAPHORE_TYPE sem_t

#define SAMPLE_SEMAPHORE_DEFAULT_VALUE { .__align = 0 }

#define SAMPLE_SEMAPHORE_INIT(sem)                                             \
    sem_init(&sem, 0, 0) == 0 ? 0 : 1

#define SAMPLE_SEMAPHORE_UNINIT(sem)                                           \
    sem_destroy(&sem) == 0 ? 0 : 1

#define SAMPLE_SEMAPHORE_WAIT(sem)                                             \
    sem_wait(&sem) == 0 ? 0 : 1

#define SAMPLE_SEMAPHORE_RELEASE(sem)                                          \
    sem_post(&sem) == 0 ? 0 : 1

#elif defined NBP_OS_WINDOWS

#include <Windows.h>
#define SAMPLE_FORCE_SLEEP_MS(ms) Sleep(ms)

#else

#error "Unknown OS"

#endif

#ifdef SAMPLE_DISABLE_SLEEP
#define SAMPLE_SLEEP()
#else // SAMPLE_DISABLE_SLEEP not defined
#define SAMPLE_SLEEP() SAMPLE_FORCE_SLEEP_MS(200)
#endif // end if SAMPLE_DISABLE_SLEEP

#endif // end if NBP_SAMPLE_UTILS
