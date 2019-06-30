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

path_to_bin="../bin"
path_to_project="/home/travis/build/aenachescu/nbp/"

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
)

files=""

for i in "${arr[@]}"
do
    files="$files -a $path_to_bin/$i/coverage.info"
    lcov --directory $path_to_bin/$i/. --capture --output-file \
        $path_to_bin/$i/coverage.info
done

lcov $files -o $path_to_bin/coverage.info

sed -i "s|$path_to_project||g" $path_to_bin/coverage.info

cd ..
coveralls-lcov bin/coverage.info
cd build