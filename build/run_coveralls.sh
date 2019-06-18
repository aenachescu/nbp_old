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

path_to_bin="/home/travis/build/aenachescu/nbp/bin"

path_to_project="/home/travis/build/aenachescu/nbp"

samples="
    -b $path_to_bin/basic_sample
    -b $path_to_bin/modules_sample
    -b $path_to_bin/modules_one_file_sample
    -b $path_to_bin/submodules_sample
    -b $path_to_bin/submodules_one_file_sample
    -b $path_to_bin/main_module_fixtures_sample
    -b $path_to_bin/main_module_fixtures_one_file_sample
    -b $path_to_bin/main_module_setup_sample
    -b $path_to_bin/main_module_setup_one_file_sample
"

coveralls -r $path_to_project $samples --gcov $1 --gcov-options '\-lp'
