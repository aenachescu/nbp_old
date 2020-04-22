# No Bugs in Production (NBP)
# https://github.com/aenachescu/nbp
# 
# Licensed under the MIT License <http://opensource.org/licenses/MIT>.
# SPDX-License-Identifier: MIT
# Copyright (c) 2019-2020 Alin Enachescu <https://github.com/aenachescu>
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

status=0
sanopt=""

binPath="../../bin/"
samplesPath="../../samples/"

function run_test {
    echo "running test $1"

    sample=${1%_sample}
    has_output=0
    expected_output=""
    output=""

    currentSamplePath="${samplesPath}${sample}/"
    currentSampleBinPath="${binPath}$1/"
    expectedPrinterOutputPath="${currentSamplePath}expected_linux_printer_output.txt"
    expectedOutputPath="${currentSamplePath}expected_output.txt"

    # load expected test output
    expected_printer_output=$(<${expectedPrinterOutputPath})
    if [ -f "${expectedOutputPath}" ]; then
        has_output=1
        expected_output=$(<${expectedOutputPath})
    fi

    # run and get test output
    if [ -f "output.txt" ]; then
        rm output.txt
    fi
    printer_output=""
    if [ -z "$sanopt" ]; then
        printer_output=$(${currentSampleBinPath}$1)
    else
        printer_output=$(env $sanopt ${currentSampleBinPath}$1)
    fi
    testStatus=$?

    if [ -f "output.txt" ]; then
        output=$(<output.txt)
        rm output.txt
    fi

    # check test return code
    if [ $testStatus -ne $2 ]; then
        echo "***** expected status: $2"
        echo "***** current status: $testStatus"
        echo $'test failed\n'
        status=1
        return
    fi

    # check printer output
    if [ "$expected_printer_output" != "$printer_output" ]; then
        echo "***** expected printer output *****"
        echo "$expected_printer_output"
        echo "***** printer output *****"
        echo "$printer_output"
        echo $'test failed\n'
        status=1
        return
    fi

    # check output file
    if [ $has_output -eq 1 ]; then
        if [ "$expected_output" != "$output" ]; then
            echo "***** expected output file *****"
            echo "$expected_output"
            echo "***** output file *****"
            echo "$output"
            echo $'test failed\n'
            status=1
            return
        fi
    fi

    echo $'test passed\n'
}

if test "$#" -eq 1; then
    sanopt=$1
    echo "$sanopt"
fi

run_test basic_sample 0
run_test modules_sample 0
run_test modules_one_file_sample 0
run_test submodules_sample 0
run_test submodules_one_file_sample 0
run_test main_module_fixtures_sample 0
run_test main_module_fixtures_one_file_sample 0
run_test main_module_setup_sample 0
run_test main_module_setup_one_file_sample 0
run_test main_module_teardown_sample 0
run_test main_module_teardown_one_file_sample 0
run_test module_fixtures_sample 0
run_test module_fixtures_one_file_sample 0
run_test test_fixtures_sample 0
run_test test_fixtures_one_file_sample 0
run_test check_sample 1
run_test test_and_module_sample 0
run_test test_and_module_fixtures_sample 0
run_test test_and_module_name_sample 0
run_test check_type_sample 0
run_test check_operator_sample 0
run_test assert_type_sample 0
run_test test_assert_type_sample 0
run_test module_assert_type_sample 0
run_test assert_operator_sample 0
run_test test_assert_operator_sample 0
run_test module_assert_operator_sample 0
run_test test_assert_sample 1
run_test module_assert_sample 1
run_test assert_sample 1
run_test mt_scheduler_basic_sample 0
run_test mt_scheduler_module_fixtures_ran_only_once_sample 0
run_test mt_scheduler_run_test_fixtures_in_parallel_sample 0
run_test mt_scheduler_run_module_fixtures_in_parallel_sample 0
run_test empty_modules_sample 1

if [ $status -ne 0 ]; then
    echo $'run_tests failed\n'
else
    echo $'run_tests passed\n'
fi

exit $status