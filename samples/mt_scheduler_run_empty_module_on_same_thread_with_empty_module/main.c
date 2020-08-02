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

#include "../sample_utils.h"

NBP_MAIN_MODULE(mt_scheduler_run_empty_module_on_same_thread_with_empty_module)
{
    NBP_MODULE_RUN(empty_module2);
    NBP_MODULE_RUN_CTX(
        empty_module1,
        NBP_MT_SCHEDULER_CTX(
            NBP_MT_SCHEDULER_RUN_ON_SAME_THREAD_WITH_MODULE(empty_module2)
        )
    );
}

NBP_MODULE_SETUP(setupEmptyModule)
{
    write_message_to_console("this message should not be displayed");
}

NBP_MODULE_TEARDOWN(teardownEmptyModule)
{
    write_message_to_console("this message should not be displayed");
}

NBP_MODULE_FIXTURES(empty_module1, setupEmptyModule, teardownEmptyModule)
{
    NBP_MODULE_RUN(empty_submodule1);
    NBP_MODULE_RUN(empty_submodule2);
}

NBP_MODULE_FIXTURES(empty_submodule1, setupEmptyModule, teardownEmptyModule)
{
}

NBP_MODULE_FIXTURES(empty_submodule2, setupEmptyModule, teardownEmptyModule)
{
}

NBP_MODULE_FIXTURES(empty_module2, setupEmptyModule, teardownEmptyModule)
{
    NBP_MODULE_RUN(empty_submodule3);
    NBP_MODULE_RUN(empty_submodule4);
}

NBP_MODULE_FIXTURES(empty_submodule3, setupEmptyModule, teardownEmptyModule)
{
}

NBP_MODULE_FIXTURES(empty_submodule4, setupEmptyModule, teardownEmptyModule)
{
}
