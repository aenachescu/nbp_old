# No Bugs in Production (NBP)
# Copyright (C) 2019-present Alin Enachescu

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

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

if [ $status -ne 0 ]; then
    echo $'run_tests failed\n'
else
    echo $'run_tests passed\n'
fi

exit $status