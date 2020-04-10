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

#define NBP_LIBRARY_MAIN
#include <nbp.h>

NBP_MAIN_MODULE(module_assert_type)
{
    NBP_CALL_MODULE(module_assert_char);
    NBP_CALL_MODULE(module_assert_short);
    NBP_CALL_MODULE(module_assert_ushort);
    NBP_CALL_MODULE(module_assert_int);
    NBP_CALL_MODULE(module_assert_uint);
    NBP_CALL_MODULE(module_assert_long);
    NBP_CALL_MODULE(module_assert_ulong);
    NBP_CALL_MODULE(module_assert_llong);
    NBP_CALL_MODULE(module_assert_ullong);
    NBP_CALL_MODULE(module_assert_float);
    NBP_CALL_MODULE(module_assert_double);
    NBP_CALL_MODULE(module_assert_ldouble);
}