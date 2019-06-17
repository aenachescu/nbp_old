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

CC=gcc
CFLAGS=-Wall -Wextra -Werror -DSAMPLE_LINUX -fprofile-arcs -ftest-coverage

lib_folder=-I../../include
lib_files=../include/nbp.h

samples_folder=../../samples/
bin_folder=../bin/

#
# basic sample
#

basic_sample_files=\
	$(samples_folder)basic/main.c

basic_sample_files_depends=\
	../samples/basic/main.c

basic_sample: $(basic_sample_files_depends) $(lib_files)
	mkdir -p $(bin_folder)basic_sample && \
	cd $(bin_folder)basic_sample && \
	$(CC) -o basic_sample $(basic_sample_files) $(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_basic_sample:
	rm -rf $(bin_folder)basic_sample

#
# modules sample
#

modules_sample_files=\
	$(samples_folder)modules/main.c\
	$(samples_folder)modules/module1.c\
	$(samples_folder)modules/module2.c

modules_sample_files_depends=\
	../samples/modules/main.c\
	../samples/modules/module1.c\
	../samples/modules/module2.c

modules_sample: $(modules_sample_files_depends) $(lib_files)
	mkdir -p $(bin_folder)modules_sample && \
	cd $(bin_folder)modules_sample && \
	$(CC) -o modules_sample $(modules_sample_files) $(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_modules_sample:
	rm -rf $(bin_folder)modules_sample

#
# submodules sample
#

submodules_sample_files=\
	$(samples_folder)submodules/main.c\
	$(samples_folder)submodules/module1.c\
	$(samples_folder)submodules/module2.c\
	$(samples_folder)submodules/submodule1.c\
	$(samples_folder)submodules/submodule2.c\
	$(samples_folder)submodules/submodule3.c\
	$(samples_folder)submodules/submodule4.c

submodules_sample_files_depends=\
	../samples/submodules/main.c\
	../samples/submodules/module1.c\
	../samples/submodules/module2.c\
	../samples/submodules/submodule1.c\
	../samples/submodules/submodule2.c\
	../samples/submodules/submodule3.c\
	../samples/submodules/submodule4.c

submodules_sample: $(submodules_sample_files_depends) $(lib_files)
	mkdir -p $(bin_folder)submodules_sample && \
	cd $(bin_folder)submodules_sample && \
	$(CC) -o submodules_sample $(submodules_sample_files) $(lib_folder) \
	$(CFLAGS) && \
	cd ../../build

clean_submodules_sample:
	rm -rf $(bin_folder)submodules_sample

#
# modules_one_file sample
#

modules_one_file_sample_files=\
	$(samples_folder)modules_one_file/main.c

modules_one_file_sample_files_depends=\
	../samples/modules_one_file/main.c

modules_one_file_sample: $(modules_one_file_sample_files_depends) $(lib_files)
	mkdir -p $(bin_folder)modules_one_file_sample && \
	cd $(bin_folder)modules_one_file_sample && \
	$(CC) -o modules_one_file_sample $(modules_one_file_sample_files) \
	$(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_modules_one_file_sample:
	rm -rf $(bin_folder)modules_one_file_sample

#
# submodules_one_file sample
#

submodules_one_file_sample_files=\
	$(samples_folder)submodules_one_file/main.c

submodules_one_file_sample_files_depends=\
	../samples/submodules_one_file/main.c

submodules_one_file_sample: $(submodules_one_file_sample_files_depends) \
	$(lib_files)
	mkdir -p $(bin_folder)submodules_one_file_sample && \
	cd $(bin_folder)submodules_one_file_sample && \
	$(CC) -o submodules_one_file_sample $(submodules_one_file_sample_files) \
	$(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_submodules_one_file_sample:
	rm -rf $(bin_folder)submodules_one_file_sample

#
# main_module_fixtures sample
#

main_module_fixtures_sample_files=\
	$(samples_folder)main_module_fixtures/main.c\
	$(samples_folder)main_module_fixtures/fixtures.c

main_module_fixtures_sample_files_depends=\
	../samples/main_module_fixtures/main.c\
	../samples/main_module_fixtures/fixtures.c

main_module_fixtures_sample: $(main_module_fixtures_sample_files_depends) \
	$(lib_files)
	mkdir -p $(bin_folder)main_module_fixtures_sample && \
	cd $(bin_folder)main_module_fixtures_sample && \
	$(CC) -o main_module_fixtures_sample $(main_module_fixtures_sample_files) \
	$(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_main_module_fixtures_sample:
	rm -rf $(bin_folder)main_module_fixtures_sample

#
# main_module_fixtures_one_file sample
#

main_module_fixtures_one_file_sample_files=\
	$(samples_folder)main_module_fixtures_one_file/main.c

main_module_fixtures_one_file_sample_files_depends=\
	../samples/main_module_fixtures_one_file/main.c

main_module_fixtures_one_file_sample: $(main_module_fixtures_one_file_sample_files_depends) \
	$(lib_files)
	mkdir -p $(bin_folder)main_module_fixtures_one_file_sample && \
	cd $(bin_folder)main_module_fixtures_one_file_sample && \
	$(CC) -o main_module_fixtures_one_file_sample $(main_module_fixtures_one_file_sample_files) \
	$(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_main_module_fixtures_one_file_sample:
	rm -rf $(bin_folder)main_module_fixtures_one_file_sample

#
# make all
#

all:\
	basic_sample\
	modules_sample\
	submodules_sample\
	modules_one_file_sample\
	submodules_one_file_sample\
	main_module_fixtures_sample\
	main_module_fixtures_one_file_sample\

#
# make clean
#

clean:\
	clean_basic_sample\
	clean_modules_sample\
	clean_submodules_sample\
	clean_modules_one_file_sample\
	clean_submodules_one_file_sample\
	clean_main_module_fixtures_sample\
	clean_main_module_fixtures_one_file_sample\
