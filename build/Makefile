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

lib_folder=-I../include
lib_files=../include/nbp.h

#
# basic sample
#

basic_sample_files=\
	../samples/basic/basic_sample_test.c

basic_sample: $(basic_sample_files) $(lib_files)
	$(CC) -o basic_sample $(basic_sample_files) $(lib_folder) $(CFLAGS)

clean_basic_sample:
	rm -f basic_sample
	rm -f basic_sample_test.gcno basic_sample_test.gcda

#
# modules sample
#

modules_sample_files=\
	../samples/modules/modules_sample_test.c\
	../samples/modules/modules_sample_module1.c\
	../samples/modules/modules_sample_module2.c

modules_sample: $(modules_sample_files) $(lib_files)
	$(CC) -o modules_sample $(modules_sample_files) $(lib_folder) $(CFLAGS)

clean_modules_sample:
	rm -f modules_sample
	rm -f modules_sample_test.gcno modules_sample_test.gcda
	rm -f modules_sample_module1.gcno modules_sample_module1.gcda
	rm -f modules_sample_module2.gcno modules_sample_module2.gcda

#
# submodules sample
#

submodules_sample_files=\
	../samples/submodules/submodules_sample_test.c\
	../samples/submodules/submodules_sample_module1.c\
	../samples/submodules/submodules_sample_module2.c\
	../samples/submodules/submodules_sample_submodule1.c\
	../samples/submodules/submodules_sample_submodule2.c\
	../samples/submodules/submodules_sample_submodule3.c\
	../samples/submodules/submodules_sample_submodule4.c

submodules_sample: $(submodules_sample_files) $(lib_files)
	$(CC) -o submodules_sample $(submodules_sample_files) $(lib_folder) \
	$(CFLAGS)

clean_submodules_sample:
	rm -f submodules_sample
	rm -f submodules_sample_test.gcno submodules_sample_test.gcda
	rm -f submodules_sample_module1.gcno submodules_sample_module1.gcda
	rm -f submodules_sample_module2.gcno submodules_sample_module2.gcda
	rm -f submodules_sample_submodule1.gcno submodules_sample_submodule1.gcda
	rm -f submodules_sample_submodule2.gcno submodules_sample_submodule2.gcda
	rm -f submodules_sample_submodule3.gcno submodules_sample_submodule3.gcda
	rm -f submodules_sample_submodule4.gcno submodules_sample_submodule4.gcda

#
# modules_one_file sample
#

modules_one_file_sample_files=\
	../samples/modules_one_file/modules_one_file_sample_test.c

modules_one_file_sample: $(modules_one_file_sample_files) $(lib_files)
	$(CC) -o modules_one_file_sample $(modules_one_file_sample_files) \
	$(lib_folder) $(CFLAGS)

clean_modules_one_file_sample:
	rm -f modules_one_file_sample
	rm -f modules_one_file_sample_test.gcno modules_one_file_sample_test.gcda

#
# submodules_one_file_ sample
#

submodules_one_file_sample_files=\
	../samples/submodules_one_file/submodules_one_file_sample_test.c

submodules_one_file_sample: $(submodules_one_file_sample_files) $(lib_files)
	$(CC) -o submodules_one_file_sample $(submodules_one_file_sample_files) \
	$(lib_folder) $(CFLAGS)

clean_submodules_one_file_sample:
	rm -f submodules_one_file_sample
	rm -f submodules_one_file_sample_test.gcno \
		submodules_one_file_sample_test.gcda

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
