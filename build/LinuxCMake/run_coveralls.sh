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

path_to_bin="../../bin"
path_to_project="$( cd "$(dirname "$0")/../.." >/dev/null 2>&1 ; pwd -P )"

declare -a arr=(
    "basic_sample"
    "modules_sample"
    "modules_one_file_sample"
    "submodules_sample"
    "submodules_one_file_sample"
    "main_module_fixtures_sample"
    "main_module_fixtures_one_file_sample"
    "main_module_setup_sample"
    "main_module_setup_one_file_sample"
    "main_module_teardown_sample"
    "main_module_teardown_one_file_sample"
    "module_fixtures_sample"
    "module_fixtures_one_file_sample"
    "test_fixtures_sample"
    "test_fixtures_one_file_sample"
    "check_sample"
    "test_and_module_sample"
    "test_and_module_fixtures_sample"
    "test_and_module_name_sample"
    "check_type_sample"
    "check_operator_sample"
    "assert_type_sample"
    "test_assert_type_sample"
    "module_assert_type_sample"
    "assert_operator_sample"
    "test_assert_operator_sample"
    "module_assert_operator_sample"
    "test_assert_sample"
    "module_assert_sample"
    "assert_sample"
    "mt_scheduler_basic_sample"
    "mt_scheduler_module_fixtures_ran_only_once_sample"
    "mt_scheduler_run_test_fixtures_in_parallel_sample"
    "mt_scheduler_run_module_fixtures_in_parallel_sample"
    "empty_modules_sample"
)

files=""

for i in "${arr[@]}"
do
    files="$files -a $path_to_bin/$i/coverage.info"
    path_to_objects="$path_to_project/build/LinuxCMake/CMakeFiles/${i}.dir/${path_to_project}/samples/${i//_sample/}"
    cp $path_to_objects/*.gcda $path_to_bin/$i/
    cp $path_to_objects/*.gcno $path_to_bin/$i/
    lcov --directory $path_to_bin/$i/ --capture --output-file \
        $path_to_bin/$i/coverage.info
done

lcov $files -o $path_to_bin/coverage.info

sed -i "s|$path_to_project||g" $path_to_bin/coverage.info

cd ../../
coveralls-lcov bin/coverage.info
cd build/LinuxCMake
