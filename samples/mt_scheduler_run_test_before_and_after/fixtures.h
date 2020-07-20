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

#include "../sample_utils.h"

extern unsigned int test1_test3TeardownValue;
extern unsigned int test1_test4TeardownValue;
extern unsigned int test1_test5TeardownValue;
extern unsigned int test1_test6TeardownValue;
extern unsigned int test1_module1TeardownValue;
extern unsigned int test1_module2TeardownValue;
extern unsigned int test1_module3TeardownValue;
extern unsigned int test1_module4TeardownValue;

extern unsigned int test2_test3TeardownValue;
extern unsigned int test2_test4TeardownValue;
extern unsigned int test2_test5TeardownValue;
extern unsigned int test2_test6TeardownValue;
extern unsigned int test2_module1TeardownValue;
extern unsigned int test2_module2TeardownValue;
extern unsigned int test2_module3TeardownValue;
extern unsigned int test2_module4TeardownValue;

extern unsigned int test3_test1TeardownValue;
extern unsigned int test3_test2TeardownValue;

extern unsigned int test4_test1TeardownValue;
extern unsigned int test4_test2TeardownValue;

extern unsigned int module1_test1TeardownValue;
extern unsigned int module1_test2TeardownValue;

extern unsigned int module2_test1TeardownValue;
extern unsigned int module2_test2TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE mainModuleSetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE mainModuleTeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test1SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test1TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test2SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test2TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test3SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test3TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test4SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test4TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test5SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test5TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test6SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test6TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test7SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test7TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test8SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test8TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test9SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test9TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test10SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test10TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test11SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test11TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test12SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test12TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test13SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test13TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test14SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test14TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test15SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test15TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test16SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test16TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test17SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test17TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test18SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test18TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test19SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test19TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test20SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test20TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test21SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test21TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test22SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test22TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test23SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test23TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test24SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test24TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test25SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test25TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test26SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test26TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test27SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test27TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test28SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test28TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test29SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test29TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test30SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test30TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test31SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test31TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test32SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test32TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test33SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test33TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test34SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test34TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test35SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test35TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test36SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test36TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test37SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test37TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test38SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test38TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test39SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test39TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test40SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test40TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test41SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test41TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test42SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test42TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test43SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test43TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test44SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test44TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test45SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test45TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE test46SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE test46TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE module1SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE module1TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE module2SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE module2TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE module3SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE module3TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE module4SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE module4TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE submodule1SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE submodule1TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE submodule2SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE submodule2TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE submodule3SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE submodule3TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE submodule4SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE submodule4TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE subsubmodule1SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE subsubmodule1TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE subsubmodule2SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE subsubmodule2TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE subsubmodule3SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE subsubmodule3TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE subsubmodule4SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE subsubmodule4TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE subsubmodule5SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE subsubmodule5TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE subsubmodule6SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE subsubmodule6TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE subsubmodule7SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE subsubmodule7TeardownValue;

extern SAMPLE_ATOMIC_UINT_TYPE subsubmodule8SetupValue;
extern SAMPLE_ATOMIC_UINT_TYPE subsubmodule8TeardownValue;
