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

function run_test {
    echo "running test $1"

    sample=${1%_sample}

    cd ../samples/$sample
    expected_output=$(<expected_linux_printer_output.txt)
    cd ../../bin

    cd $1
    output=$(./$1)
    testStatus=$?
    cd ..

    if [ $testStatus -ne $2 ]; then
        echo "expected status: $2"
        echo "current status: $testStatus"
        echo $'test failed\n'
        status=1
        return
    fi

    if [ "$expected_output" == "$output" ]; then
        echo $'test passed\n'
    else
        echo "$expected_output"
        echo "$output"
        echo $'test failed\n'
        status=1
    fi
}

cd ../bin

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

cd ../build

exit $status