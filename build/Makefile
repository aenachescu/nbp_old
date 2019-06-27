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
CFLAGS=-Wall -Wextra -Werror -DSAMPLE_LINUX -fprofile-arcs -ftest-coverage \
	$(SAMPLE_FLAGS) -DNBP_OS_LINUX -Wconversion

lib_folder=-I../../include
lib_files=../include/nbp.h

samples_folder=../../samples/
bin_folder=../bin/

#
# basic sample
#

files1=$(samples_folder)basic/main.c
depends1=../samples/basic/main.c
name1=basic_sample

basic_sample: $(depends1) $(lib_files)
	mkdir -p $(bin_folder)$(name1) && \
	cd $(bin_folder)$(name1) && \
	$(CC) -o $(name1) $(files1) $(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_basic_sample:
	rm -rf $(bin_folder)$(name1)

#
# modules sample
#

files2=\
	$(samples_folder)modules/main.c\
	$(samples_folder)modules/module1.c\
	$(samples_folder)modules/module2.c
depends2=\
	../samples/modules/main.c\
	../samples/modules/module1.c\
	../samples/modules/module2.c
name2=modules_sample

modules_sample: $(depends2) $(lib_files)
	mkdir -p $(bin_folder)$(name2) && \
	cd $(bin_folder)$(name2) && \
	$(CC) -o $(name2) $(files2) $(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_modules_sample:
	rm -rf $(bin_folder)$(name2)

#
# submodules sample
#

files3=\
	$(samples_folder)submodules/main.c\
	$(samples_folder)submodules/module1.c\
	$(samples_folder)submodules/module2.c\
	$(samples_folder)submodules/submodule1.c\
	$(samples_folder)submodules/submodule2.c\
	$(samples_folder)submodules/submodule3.c\
	$(samples_folder)submodules/submodule4.c
depends3=\
	../samples/submodules/main.c\
	../samples/submodules/module1.c\
	../samples/submodules/module2.c\
	../samples/submodules/submodule1.c\
	../samples/submodules/submodule2.c\
	../samples/submodules/submodule3.c\
	../samples/submodules/submodule4.c
name3=submodules_sample

submodules_sample: $(depends3) $(lib_files)
	mkdir -p $(bin_folder)$(name3) && \
	cd $(bin_folder)$(name3) && \
	$(CC) -o $(name3) $(files3) $(lib_folder) \
	$(CFLAGS) && \
	cd ../../build

clean_submodules_sample:
	rm -rf $(bin_folder)$(name3)

#
# modules_one_file sample
#

files4=$(samples_folder)modules_one_file/main.c
depends4=../samples/modules_one_file/main.c
name4=modules_one_file_sample

modules_one_file_sample: $(depends4) $(lib_files)
	mkdir -p $(bin_folder)$(name4) && \
	cd $(bin_folder)$(name4) && \
	$(CC) -o $(name4) $(files4) $(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_modules_one_file_sample:
	rm -rf $(bin_folder)$(name4)

#
# submodules_one_file sample
#

files5=$(samples_folder)submodules_one_file/main.c
depends5=../samples/submodules_one_file/main.c
name5=submodules_one_file_sample

submodules_one_file_sample: $(depends5) $(lib_files)
	mkdir -p $(bin_folder)$(name5) && \
	cd $(bin_folder)$(name5) && \
	$(CC) -o $(name5) $(files5) $(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_submodules_one_file_sample:
	rm -rf $(bin_folder)$(name5)

#
# main_module_fixtures sample
#

files6=\
	$(samples_folder)main_module_fixtures/main.c\
	$(samples_folder)main_module_fixtures/fixtures.c
depends6=\
	../samples/main_module_fixtures/main.c\
	../samples/main_module_fixtures/fixtures.c
name6=main_module_fixtures_sample

main_module_fixtures_sample: $(depends6) $(lib_files)
	mkdir -p $(bin_folder)$(name6) && \
	cd $(bin_folder)$(name6) && \
	$(CC) -o $(name6) $(files6) $(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_main_module_fixtures_sample:
	rm -rf $(bin_folder)$(name6)

#
# main_module_fixtures_one_file sample
#

files7=$(samples_folder)main_module_fixtures_one_file/main.c
depends7=../samples/main_module_fixtures_one_file/main.c
name7=main_module_fixtures_one_file_sample

main_module_fixtures_one_file_sample: $(depends7) $(lib_files)
	mkdir -p $(bin_folder)$(name7) && \
	cd $(bin_folder)$(name7) && \
	$(CC) -o $(name7) $(files7) $(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_main_module_fixtures_one_file_sample:
	rm -rf $(bin_folder)$(name7)

#
# main_module_setup sample
#

files8=\
	$(samples_folder)main_module_setup/main.c\
	$(samples_folder)main_module_setup/setup.c
depends8=\
	../samples/main_module_setup/main.c\
	../samples/main_module_setup/setup.c
name8=main_module_setup_sample

main_module_setup_sample: $(depends8) $(lib_files)
	mkdir -p $(bin_folder)$(name8) && \
	cd $(bin_folder)$(name8) && \
	$(CC) -o $(name8) $(files8) $(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_main_module_setup_sample:
	rm -rf $(bin_folder)$(name8)

#
# main_module_setup_one_file sample
#

files9=\
	$(samples_folder)main_module_setup_one_file/main.c
depends9=\
	../samples/main_module_setup_one_file/main.c
name9=main_module_setup_one_file_sample

main_module_setup_one_file_sample: $(depends9) $(lib_files)
	mkdir -p $(bin_folder)$(name9) && \
	cd $(bin_folder)$(name9) && \
	$(CC) -o $(name9) $(files9) $(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_main_module_setup_one_file_sample:
	rm -rf $(bin_folder)$(name9)

#
# main_module_teardown sample
#

files10=\
	$(samples_folder)main_module_teardown/main.c\
	$(samples_folder)main_module_teardown/teardown.c
depends10=\
	../samples/main_module_teardown/main.c\
	../samples/main_module_teardown/teardown.c
name10=main_module_teardown_sample

main_module_teardown_sample: $(depends10) $(lib_files)
	mkdir -p $(bin_folder)$(name10) && \
	cd $(bin_folder)$(name10) && \
	$(CC) -o $(name10) $(files10) $(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_main_module_teardown_sample:
	rm -rf $(bin_folder)$(name10)

#
# main_module_teardown_one_file sample
#

files11=\
	$(samples_folder)main_module_teardown_one_file/main.c
depends11=\
	../samples/main_module_teardown_one_file/main.c
name11=main_module_teardown_one_file_sample

main_module_teardown_one_file_sample: $(depends11) $(lib_files)
	mkdir -p $(bin_folder)$(name11) && \
	cd $(bin_folder)$(name11) && \
	$(CC) -o $(name11) $(files11) $(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_main_module_teardown_one_file_sample:
	rm -rf $(bin_folder)$(name11)

#
# module_fixtures sample
#

files12=\
	$(samples_folder)module_fixtures/main.c\
	$(samples_folder)module_fixtures/module1.c\
	$(samples_folder)module_fixtures/module2.c\
	$(samples_folder)module_fixtures/submodule1.c\
	$(samples_folder)module_fixtures/submodule2.c\
	$(samples_folder)module_fixtures/submodule3.c\
	$(samples_folder)module_fixtures/submodule4.c\
	$(samples_folder)module_fixtures/module_setup.c\
	$(samples_folder)module_fixtures/module_teardown.c\
	$(samples_folder)module_fixtures/submodule_fixtures.c
depends12=\
	../samples/module_fixtures/main.c\
	../samples/module_fixtures/module1.c\
	../samples/module_fixtures/module2.c\
	../samples/module_fixtures/submodule1.c\
	../samples/module_fixtures/submodule2.c\
	../samples/module_fixtures/submodule3.c\
	../samples/module_fixtures/submodule4.c\
	../samples/module_fixtures/module_setup.c\
	../samples/module_fixtures/module_teardown.c\
	../samples/module_fixtures/submodule_fixtures.c
name12=module_fixtures_sample

module_fixtures_sample: $(depends12) $(lib_files)
	mkdir -p $(bin_folder)$(name12) && \
	cd $(bin_folder)$(name12) && \
	$(CC) -o $(name12) $(files12) $(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_module_fixtures_sample:
	rm -rf $(bin_folder)$(name12)

#
# module_fixtures_one_file sample
#

files13=$(samples_folder)module_fixtures_one_file/main.c
depends13=../samples/module_fixtures_one_file/main.c
name13=module_fixtures_one_file_sample

module_fixtures_one_file_sample: $(depends13) $(lib_files)
	mkdir -p $(bin_folder)$(name13) && \
	cd $(bin_folder)$(name13) && \
	$(CC) -o $(name13) $(files13) $(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_module_fixtures_one_file_sample:
	rm -rf $(bin_folder)$(name13)

#
# test_fixtures sample
#

files14=\
	$(samples_folder)test_fixtures/main.c\
	$(samples_folder)test_fixtures/module1.c\
	$(samples_folder)test_fixtures/module2.c\
	$(samples_folder)test_fixtures/submodule1.c\
	$(samples_folder)test_fixtures/submodule2.c\
	$(samples_folder)test_fixtures/submodule3.c\
	$(samples_folder)test_fixtures/submodule4.c\
	$(samples_folder)test_fixtures/test_after.c\
	$(samples_folder)test_fixtures/test_before.c\
	$(samples_folder)test_fixtures/test_fixtures.c
depends14=\
	../samples/test_fixtures/main.c\
	../samples/test_fixtures/module1.c\
	../samples/test_fixtures/module2.c\
	../samples/test_fixtures/submodule1.c\
	../samples/test_fixtures/submodule2.c\
	../samples/test_fixtures/submodule3.c\
	../samples/test_fixtures/submodule4.c\
	../samples/test_fixtures/test_after.c\
	../samples/test_fixtures/test_before.c\
	../samples/test_fixtures/test_fixtures.c
name14=test_fixtures_sample

test_fixtures_sample: $(depends14) $(lib_files)
	mkdir -p $(bin_folder)$(name14) && \
	cd $(bin_folder)$(name14) && \
	$(CC) -o $(name14) $(files14) $(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_test_fixtures_sample:
	rm -rf $(bin_folder)$(name14)

#
# test_fixtures_one_file sample
#

files15=$(samples_folder)test_fixtures_one_file/main.c
depends15=../samples/test_fixtures_one_file/main.c
name15=test_fixtures_one_file_sample

test_fixtures_one_file_sample: $(depends15) $(lib_files)
	mkdir -p $(bin_folder)$(name15) && \
	cd $(bin_folder)$(name15) && \
	$(CC) -o $(name15) $(files15) $(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_test_fixtures_one_file_sample:
	rm -rf $(bin_folder)$(name15)

#
# check sample
#

files16=$(samples_folder)check/main.c
depends16=../samples/check/main.c
name16=check_sample

check_sample: $(depends16) $(lib_files)
	mkdir -p $(bin_folder)$(name16) && \
	cd $(bin_folder)$(name16) && \
	$(CC) -o $(name16) $(files16) $(lib_folder) $(CFLAGS) && \
	cd ../../build

clean_check_sample:
	rm -rf $(bin_folder)$(name16)

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
	main_module_setup_sample\
	main_module_setup_one_file_sample\
	main_module_teardown_sample\
	main_module_teardown_one_file_sample\
	module_fixtures_sample\
	module_fixtures_one_file_sample\
	test_fixtures_sample\
	test_fixtures_one_file_sample\
	check_sample\

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
	clean_main_module_setup_sample\
	clean_main_module_setup_one_file_sample\
	clean_main_module_teardown_sample\
	clean_main_module_teardown_one_file_sample\
	clean_module_fixtures_sample\
	clean_module_fixtures_one_file_sample\
	clean_test_fixtures_sample\
	clean_test_fixtures_one_file_sample\
	clean_check_sample\
