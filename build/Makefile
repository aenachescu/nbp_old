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
	$(samples_folder)basic/basic_sample_test.c

basic_sample_files_depends=\
	../samples/basic/basic_sample_test.c

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
	$(samples_folder)modules/modules_sample_test.c\
	$(samples_folder)modules/modules_sample_module1.c\
	$(samples_folder)modules/modules_sample_module2.c

modules_sample_files_depends=\
	../samples/modules/modules_sample_test.c\
	../samples/modules/modules_sample_module1.c\
	../samples/modules/modules_sample_module2.c

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
	$(samples_folder)submodules/submodules_sample_test.c\
	$(samples_folder)submodules/submodules_sample_module1.c\
	$(samples_folder)submodules/submodules_sample_module2.c\
	$(samples_folder)submodules/submodules_sample_submodule1.c\
	$(samples_folder)submodules/submodules_sample_submodule2.c\
	$(samples_folder)submodules/submodules_sample_submodule3.c\
	$(samples_folder)submodules/submodules_sample_submodule4.c

submodules_sample_files_depends=\
	../samples/submodules/submodules_sample_test.c\
	../samples/submodules/submodules_sample_module1.c\
	../samples/submodules/submodules_sample_module2.c\
	../samples/submodules/submodules_sample_submodule1.c\
	../samples/submodules/submodules_sample_submodule2.c\
	../samples/submodules/submodules_sample_submodule3.c\
	../samples/submodules/submodules_sample_submodule4.c

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
	$(samples_folder)modules_one_file/modules_one_file_sample_test.c

modules_one_file_sample_files_depends=\
	../samples/modules_one_file/modules_one_file_sample_test.c

modules_one_file_sample: $(modules_one_file_sample_files_depends) $(lib_files)
	mkdir -p $(bin_folder)modules_one_file_sample && \
	cd $(bin_folder)modules_one_file_sample && \
	$(CC) -o modules_one_file_sample $(modules_one_file_sample_files) \
	$(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_modules_one_file_sample:
	rm -rf $(bin_folder)modules_one_file_sample

#
# submodules_one_file_ sample
#

submodules_one_file_sample_files=\
	$(samples_folder)submodules_one_file/submodules_one_file_sample_test.c

submodules_one_file_sample_files_depends=\
	../samples/submodules_one_file/submodules_one_file_sample_test.c

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
# make all
#

all:\
	basic_sample\
	modules_sample\
	submodules_sample\
	modules_one_file_sample\
	submodules_one_file_sample\

#
# make clean
#

clean:\
	clean_basic_sample\
	clean_modules_sample\
	clean_submodules_sample\
	clean_modules_one_file_sample\
	clean_submodules_one_file_sample\
