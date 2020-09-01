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

NBP_MODULE_SETUP(module_setup)
{
    write_message_to_console("this message should not be displayed");
}

NBP_MODULE_TEARDOWN(module_teardown)
{
    write_message_to_console("this message should not be displayed");
}

NBP_TEST_SETUP(test_setup)
{
    write_message_to_console("this message should not be displayed");
}

NBP_TEST_TEARDOWN(test_teardown)
{
    write_message_to_console("this message should not be displayed");
}

NBP_MAIN_MODULE(version_command,
    NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    write_message_to_console("this message should not be displayed");
    NBP_MODULE_RUN(module1);
    NBP_TEST_RUN(test2);
}

NBP_MODULE(module1, NBP_MODULE_FIXTURES(module_setup, module_teardown))
{
    write_message_to_console("this message should not be displayed");
    NBP_TEST_RUN(test1);
}

NBP_TEST(test1, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    SAMPLE_SLEEP();
    write_message_to_console("this message should not be displayed");
    NBP_ASSERT(1 == 1);
}

NBP_TEST(test2, NBP_TEST_FIXTURES(test_setup, test_teardown))
{
    SAMPLE_SLEEP();
    write_message_to_console("this message should not be displayed");
    NBP_ASSERT(1 == 1);
}
