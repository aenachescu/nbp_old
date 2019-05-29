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

#ifndef NBP_LIBRARY_H
#define NBP_LIBRARY_H

typedef struct {
    const char* testName;
} nbp_test_details_t;

typedef struct {
    const char* moduleName;
} nbp_module_details_t;

typedef void (*nbp_test_pfn_t)(nbp_test_details_t*);
typedef void (*nbp_module_pfn_t)(nbp_module_details_t*);

void nbp_call_test(nbp_test_pfn_t, const char*, nbp_module_details_t*);

void nbp_call_module(nbp_module_pfn_t, const char*, nbp_module_details_t*);

/*
 * TODO: add docs
 */
#define NBP_TEST(name) void name(nbp_test_details_t* details)

/*
 * TODO: add docs
 */
#define NBP_CALL_TEST(name) nbp_call_test(name, ##name, moduleDetails)

/*
 * TODO: add docs
 */
#define NBP_MODULE(name) void name(nbp_module_details_t* moduleDetails)

/*
 * TODO: add docs
 */
#define NBP_CALL_MODULE(name) nbp_call_module(name, ##name, moduleDetails)

/*
 * TODO: add docs
 */
#define NBP_CALL_BEFORE_TEST(func)

/*
 * TODO: add docs
 */
#define NBP_CALL_AFTER_TEST(func)

/*
 * TODO: add docs
 */
#define NBP_CALL_BEFORE_MODULE(func)

/*
 * TODO: add docs
 */
#define NBP_CALL_AFTER_MODULE(func)

/*
 * TODO: add docs
 */
#ifdef NBP_LIBRARY_MAIN

/*
 * TODO: add docs
 */
#ifndef NBP_CUSTOM_MEMORY_ALLOCATOR

#include <stdlib.h>
#define NBP_ALLOC malloc
#define NBP_FREE free

#else // if custom memory allocator is enabled

#ifndef NBP_ALLOC
#error "Custom memory allocator is enabled but no alloc function is provided"
#endif

#ifndef NBP_FREE
#error "Custom memory allocator is enabled but no free function is provided"
#endif

#endif // end if NBP_CUSTOM_MEMORY_ALLOCATOR

/*
 * TODO: add docs
 */
#define NBP_MAIN() int main(int argc, const char *argv[])

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_LIBRARY_H

