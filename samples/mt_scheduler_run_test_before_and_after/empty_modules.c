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

#include <nbp.h>

NBP_MODULE_FIXTURES(empty_module1, empty_module_setup, empty_module_teardown)
{
    NBP_MODULE_RUN(empty_module3);
    NBP_MODULE_RUN(empty_module4);
}

NBP_MODULE_FIXTURES(empty_module2, empty_module_setup, empty_module_teardown)
{
    NBP_MODULE_RUN(empty_module9);
    NBP_MODULE_RUN(empty_module10);
}

NBP_MODULE_FIXTURES(empty_module3, empty_module_setup, empty_module_teardown)
{
    NBP_MODULE_RUN(empty_module5);
    NBP_MODULE_RUN(empty_module6);
}

NBP_MODULE_FIXTURES(empty_module4, empty_module_setup, empty_module_teardown)
{
    NBP_MODULE_RUN(empty_module7);
    NBP_MODULE_RUN(empty_module8);
}

NBP_MODULE_FIXTURES(empty_module5, empty_module_setup, empty_module_teardown)
{
}

NBP_MODULE_FIXTURES(empty_module6, empty_module_setup, empty_module_teardown)
{
}

NBP_MODULE_FIXTURES(empty_module7, empty_module_setup, empty_module_teardown)
{
}

NBP_MODULE_FIXTURES(empty_module8, empty_module_setup, empty_module_teardown)
{
}

NBP_MODULE_FIXTURES(empty_module9, empty_module_setup, empty_module_teardown)
{
    NBP_MODULE_RUN(empty_module11);
    NBP_MODULE_RUN(empty_module12);
}

NBP_MODULE_FIXTURES(empty_module10, empty_module_setup, empty_module_teardown)
{
    NBP_MODULE_RUN(empty_module13);
    NBP_MODULE_RUN(empty_module14);
}

NBP_MODULE_FIXTURES(empty_module11, empty_module_setup, empty_module_teardown)
{
}

NBP_MODULE_FIXTURES(empty_module12, empty_module_setup, empty_module_teardown)
{
}

NBP_MODULE_FIXTURES(empty_module13, empty_module_setup, empty_module_teardown)
{
}

NBP_MODULE_FIXTURES(empty_module14, empty_module_setup, empty_module_teardown)
{
}
