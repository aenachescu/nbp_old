/*
No Bugs in Production (NBP)
https://github.com/aenachescu/nbp

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2019-2020 Alin Enachescu <https://github.com/aenachescu>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef NBP_PRIVATE_DETAILS_MODULE_H
#define NBP_PRIVATE_DETAILS_MODULE_H

void nbp_module_run(
    nbp_module_details_t*, /* module */
    nbp_module_details_t*, /* parent */
    nbp_module_setup_pfn_t, /* module setup pfn */
    nbp_module_teardown_pfn_t /* module teardown pfn */
);

void nbp_module_run_ctx(
    nbp_module_details_t*, /* module */
    void* ctx, /* context */
    nbp_module_details_t*, /* parent */
    nbp_module_setup_pfn_t, /* module setup pfn */
    nbp_module_teardown_pfn_t /* module teardown pfn */
);

unsigned int nbp_module_get_number_of_asserts(
    nbp_module_details_t*, /* module */
    unsigned int, /* assert status */
    unsigned int /* assert type */
);

#endif // end if NBP_PRIVATE_DETAILS_MODULE_H
