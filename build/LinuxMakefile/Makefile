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
COMPILER_FLAG=-DNBP_COMPILER_GCC
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
SANITIZERS=
SAMPLE_FLAGS=
CFLAGS=                                                                        \
	-Wall -Wextra -Werror -Wconversion                                         \
	$(GCOV_FLAGS)                                                              \
	-DNBP_OS_LINUX                                                             \
	$(COMPILER_FLAG)                                                           \
	$(SANITIZERS)                                                              \
	$(SAMPLE_FLAGS)

MT_SCHEDULER_FLAGS=                                                            \
	-DNBP_MT_SCHEDULER                                                         \
	-DNBP_MT_SCHEDULER_NUMBER_OF_THREADS=4                                     \
	-lpthread

bin_folder_from_build_folder=../../bin/

build_folder_from_sample_bin_folder=../../build/LinuxMakefile/

samples_folder_from_build_folder=../../samples/
samples_folder_from_sample_bin_folder=../../samples/

lib_folder_from_build_folder=../../include/
lib_folder_from_sample_bin_folder=../../include/

include_folders=\
	-I$(lib_folder_from_sample_bin_folder)

lib_files=\
	$(lib_folder_from_build_folder)nbp.h

#
# basic sample
#

files1=$(samples_folder_from_sample_bin_folder)basic/main.c
depends1=$(samples_folder_from_build_folder)basic/main.c
name1=basic_sample

basic_sample: $(depends1) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name1) && \
	cd $(bin_folder_from_build_folder)$(name1) && \
	$(CC) -o $(name1) $(files1) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_basic_sample:
	rm -rf $(bin_folder_from_build_folder)$(name1)

#
# modules sample
#

files2=\
	$(samples_folder_from_sample_bin_folder)modules/main.c\
	$(samples_folder_from_sample_bin_folder)modules/module1.c\
	$(samples_folder_from_sample_bin_folder)modules/module2.c
depends2=\
	$(samples_folder_from_build_folder)modules/main.c\
	$(samples_folder_from_build_folder)modules/module1.c\
	$(samples_folder_from_build_folder)modules/module2.c
name2=modules_sample

modules_sample: $(depends2) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name2) && \
	cd $(bin_folder_from_build_folder)$(name2) && \
	$(CC) -o $(name2) $(files2) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_modules_sample:
	rm -rf $(bin_folder_from_build_folder)$(name2)

#
# submodules sample
#

files3=\
	$(samples_folder_from_sample_bin_folder)submodules/main.c\
	$(samples_folder_from_sample_bin_folder)submodules/module1.c\
	$(samples_folder_from_sample_bin_folder)submodules/module2.c\
	$(samples_folder_from_sample_bin_folder)submodules/submodule1.c\
	$(samples_folder_from_sample_bin_folder)submodules/submodule2.c\
	$(samples_folder_from_sample_bin_folder)submodules/submodule3.c\
	$(samples_folder_from_sample_bin_folder)submodules/submodule4.c
depends3=\
	$(samples_folder_from_build_folder)submodules/main.c\
	$(samples_folder_from_build_folder)submodules/module1.c\
	$(samples_folder_from_build_folder)submodules/module2.c\
	$(samples_folder_from_build_folder)submodules/submodule1.c\
	$(samples_folder_from_build_folder)submodules/submodule2.c\
	$(samples_folder_from_build_folder)submodules/submodule3.c\
	$(samples_folder_from_build_folder)submodules/submodule4.c
name3=submodules_sample

submodules_sample: $(depends3) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name3) && \
	cd $(bin_folder_from_build_folder)$(name3) && \
	$(CC) -o $(name3) $(files3) $(include_folders) \
	$(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_submodules_sample:
	rm -rf $(bin_folder_from_build_folder)$(name3)

#
# modules_one_file sample
#

files4=$(samples_folder_from_sample_bin_folder)modules_one_file/main.c
depends4=$(samples_folder_from_build_folder)modules_one_file/main.c
name4=modules_one_file_sample

modules_one_file_sample: $(depends4) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name4) && \
	cd $(bin_folder_from_build_folder)$(name4) && \
	$(CC) -o $(name4) $(files4) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_modules_one_file_sample:
	rm -rf $(bin_folder_from_build_folder)$(name4)

#
# submodules_one_file sample
#

files5=$(samples_folder_from_sample_bin_folder)submodules_one_file/main.c
depends5=$(samples_folder_from_build_folder)submodules_one_file/main.c
name5=submodules_one_file_sample

submodules_one_file_sample: $(depends5) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name5) && \
	cd $(bin_folder_from_build_folder)$(name5) && \
	$(CC) -o $(name5) $(files5) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_submodules_one_file_sample:
	rm -rf $(bin_folder_from_build_folder)$(name5)

#
# main_module_fixtures sample
#

files6=\
	$(samples_folder_from_sample_bin_folder)main_module_fixtures/main.c\
	$(samples_folder_from_sample_bin_folder)main_module_fixtures/fixtures.c
depends6=\
	$(samples_folder_from_build_folder)main_module_fixtures/main.c\
	$(samples_folder_from_build_folder)main_module_fixtures/fixtures.c
name6=main_module_fixtures_sample

main_module_fixtures_sample: $(depends6) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name6) && \
	cd $(bin_folder_from_build_folder)$(name6) && \
	$(CC) -o $(name6) $(files6) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_main_module_fixtures_sample:
	rm -rf $(bin_folder_from_build_folder)$(name6)

#
# main_module_fixtures_one_file sample
#

files7=$(samples_folder_from_sample_bin_folder)main_module_fixtures_one_file/main.c
depends7=$(samples_folder_from_build_folder)main_module_fixtures_one_file/main.c
name7=main_module_fixtures_one_file_sample

main_module_fixtures_one_file_sample: $(depends7) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name7) && \
	cd $(bin_folder_from_build_folder)$(name7) && \
	$(CC) -o $(name7) $(files7) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_main_module_fixtures_one_file_sample:
	rm -rf $(bin_folder_from_build_folder)$(name7)

#
# main_module_setup sample
#

files8=\
	$(samples_folder_from_sample_bin_folder)main_module_setup/main.c\
	$(samples_folder_from_sample_bin_folder)main_module_setup/setup.c
depends8=\
	$(samples_folder_from_build_folder)main_module_setup/main.c\
	$(samples_folder_from_build_folder)main_module_setup/setup.c
name8=main_module_setup_sample

main_module_setup_sample: $(depends8) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name8) && \
	cd $(bin_folder_from_build_folder)$(name8) && \
	$(CC) -o $(name8) $(files8) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_main_module_setup_sample:
	rm -rf $(bin_folder_from_build_folder)$(name8)

#
# main_module_setup_one_file sample
#

files9=\
	$(samples_folder_from_sample_bin_folder)main_module_setup_one_file/main.c
depends9=\
	$(samples_folder_from_build_folder)main_module_setup_one_file/main.c
name9=main_module_setup_one_file_sample

main_module_setup_one_file_sample: $(depends9) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name9) && \
	cd $(bin_folder_from_build_folder)$(name9) && \
	$(CC) -o $(name9) $(files9) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_main_module_setup_one_file_sample:
	rm -rf $(bin_folder_from_build_folder)$(name9)

#
# main_module_teardown sample
#

files10=\
	$(samples_folder_from_sample_bin_folder)main_module_teardown/main.c\
	$(samples_folder_from_sample_bin_folder)main_module_teardown/teardown.c
depends10=\
	$(samples_folder_from_build_folder)main_module_teardown/main.c\
	$(samples_folder_from_build_folder)main_module_teardown/teardown.c
name10=main_module_teardown_sample

main_module_teardown_sample: $(depends10) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name10) && \
	cd $(bin_folder_from_build_folder)$(name10) && \
	$(CC) -o $(name10) $(files10) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_main_module_teardown_sample:
	rm -rf $(bin_folder_from_build_folder)$(name10)

#
# main_module_teardown_one_file sample
#

files11=\
	$(samples_folder_from_sample_bin_folder)main_module_teardown_one_file/main.c
depends11=\
	$(samples_folder_from_build_folder)main_module_teardown_one_file/main.c
name11=main_module_teardown_one_file_sample

main_module_teardown_one_file_sample: $(depends11) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name11) && \
	cd $(bin_folder_from_build_folder)$(name11) && \
	$(CC) -o $(name11) $(files11) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_main_module_teardown_one_file_sample:
	rm -rf $(bin_folder_from_build_folder)$(name11)

#
# module_fixtures sample
#

files12=\
	$(samples_folder_from_sample_bin_folder)module_fixtures/main.c\
	$(samples_folder_from_sample_bin_folder)module_fixtures/module1.c\
	$(samples_folder_from_sample_bin_folder)module_fixtures/module2.c\
	$(samples_folder_from_sample_bin_folder)module_fixtures/submodule1.c\
	$(samples_folder_from_sample_bin_folder)module_fixtures/submodule2.c\
	$(samples_folder_from_sample_bin_folder)module_fixtures/submodule3.c\
	$(samples_folder_from_sample_bin_folder)module_fixtures/submodule4.c\
	$(samples_folder_from_sample_bin_folder)module_fixtures/module_setup.c\
	$(samples_folder_from_sample_bin_folder)module_fixtures/module_teardown.c\
	$(samples_folder_from_sample_bin_folder)module_fixtures/submodule_fixtures.c
depends12=\
	$(samples_folder_from_build_folder)module_fixtures/main.c\
	$(samples_folder_from_build_folder)module_fixtures/module1.c\
	$(samples_folder_from_build_folder)module_fixtures/module2.c\
	$(samples_folder_from_build_folder)module_fixtures/submodule1.c\
	$(samples_folder_from_build_folder)module_fixtures/submodule2.c\
	$(samples_folder_from_build_folder)module_fixtures/submodule3.c\
	$(samples_folder_from_build_folder)module_fixtures/submodule4.c\
	$(samples_folder_from_build_folder)module_fixtures/module_setup.c\
	$(samples_folder_from_build_folder)module_fixtures/module_teardown.c\
	$(samples_folder_from_build_folder)module_fixtures/submodule_fixtures.c
name12=module_fixtures_sample

module_fixtures_sample: $(depends12) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name12) && \
	cd $(bin_folder_from_build_folder)$(name12) && \
	$(CC) -o $(name12) $(files12) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_module_fixtures_sample:
	rm -rf $(bin_folder_from_build_folder)$(name12)

#
# module_fixtures_one_file sample
#

files13=$(samples_folder_from_sample_bin_folder)module_fixtures_one_file/main.c
depends13=$(samples_folder_from_build_folder)module_fixtures_one_file/main.c
name13=module_fixtures_one_file_sample

module_fixtures_one_file_sample: $(depends13) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name13) && \
	cd $(bin_folder_from_build_folder)$(name13) && \
	$(CC) -o $(name13) $(files13) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_module_fixtures_one_file_sample:
	rm -rf $(bin_folder_from_build_folder)$(name13)

#
# test_fixtures sample
#

files14=\
	$(samples_folder_from_sample_bin_folder)test_fixtures/main.c\
	$(samples_folder_from_sample_bin_folder)test_fixtures/module1.c\
	$(samples_folder_from_sample_bin_folder)test_fixtures/module2.c\
	$(samples_folder_from_sample_bin_folder)test_fixtures/submodule1.c\
	$(samples_folder_from_sample_bin_folder)test_fixtures/submodule2.c\
	$(samples_folder_from_sample_bin_folder)test_fixtures/submodule3.c\
	$(samples_folder_from_sample_bin_folder)test_fixtures/submodule4.c\
	$(samples_folder_from_sample_bin_folder)test_fixtures/test_after.c\
	$(samples_folder_from_sample_bin_folder)test_fixtures/test_before.c\
	$(samples_folder_from_sample_bin_folder)test_fixtures/test_fixtures.c
depends14=\
	$(samples_folder_from_build_folder)test_fixtures/main.c\
	$(samples_folder_from_build_folder)test_fixtures/module1.c\
	$(samples_folder_from_build_folder)test_fixtures/module2.c\
	$(samples_folder_from_build_folder)test_fixtures/submodule1.c\
	$(samples_folder_from_build_folder)test_fixtures/submodule2.c\
	$(samples_folder_from_build_folder)test_fixtures/submodule3.c\
	$(samples_folder_from_build_folder)test_fixtures/submodule4.c\
	$(samples_folder_from_build_folder)test_fixtures/test_after.c\
	$(samples_folder_from_build_folder)test_fixtures/test_before.c\
	$(samples_folder_from_build_folder)test_fixtures/test_fixtures.c
name14=test_fixtures_sample

test_fixtures_sample: $(depends14) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name14) && \
	cd $(bin_folder_from_build_folder)$(name14) && \
	$(CC) -o $(name14) $(files14) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_test_fixtures_sample:
	rm -rf $(bin_folder_from_build_folder)$(name14)

#
# test_fixtures_one_file sample
#

files15=$(samples_folder_from_sample_bin_folder)test_fixtures_one_file/main.c
depends15=$(samples_folder_from_build_folder)test_fixtures_one_file/main.c
name15=test_fixtures_one_file_sample

test_fixtures_one_file_sample: $(depends15) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name15) && \
	cd $(bin_folder_from_build_folder)$(name15) && \
	$(CC) -o $(name15) $(files15) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_test_fixtures_one_file_sample:
	rm -rf $(bin_folder_from_build_folder)$(name15)

#
# check sample
#

files16=$(samples_folder_from_sample_bin_folder)check/main.c
depends16=$(samples_folder_from_build_folder)check/main.c
name16=check_sample

check_sample: $(depends16) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name16) && \
	cd $(bin_folder_from_build_folder)$(name16) && \
	$(CC) -o $(name16) $(files16) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_check_sample:
	rm -rf $(bin_folder_from_build_folder)$(name16)

#
# test_and_module sample
#

files17=$(samples_folder_from_sample_bin_folder)test_and_module/main.c
depends17=$(samples_folder_from_build_folder)test_and_module/main.c
name17=test_and_module_sample

test_and_module_sample: $(depends17) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name17) && \
	cd $(bin_folder_from_build_folder)$(name17) && \
	$(CC) -o $(name17) $(files17) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_test_and_module_sample:
	rm -rf $(bin_folder_from_build_folder)$(name17)

#
# test_and_module_fixtures sample
#

files18=$(samples_folder_from_sample_bin_folder)test_and_module_fixtures/main.c
depends18=$(samples_folder_from_build_folder)test_and_module_fixtures/main.c
name18=test_and_module_fixtures_sample

test_and_module_fixtures_sample: $(depends18) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name18) && \
	cd $(bin_folder_from_build_folder)$(name18) && \
	$(CC) -o $(name18) $(files18) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_test_and_module_fixtures_sample:
	rm -rf $(bin_folder_from_build_folder)$(name18)

#
# test_and_module_name sample
#

files19=$(samples_folder_from_sample_bin_folder)test_and_module_name/main.c
depends19=$(samples_folder_from_build_folder)test_and_module_name/main.c
name19=test_and_module_name_sample

test_and_module_name_sample: $(depends19) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name19) && \
	cd $(bin_folder_from_build_folder)$(name19) && \
	$(CC) -o $(name19) $(files19) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_test_and_module_name_sample:
	rm -rf $(bin_folder_from_build_folder)$(name19)

#
# check_type sample
#

files20=\
	$(samples_folder_from_sample_bin_folder)check_type/main.c\
	$(samples_folder_from_sample_bin_folder)check_type/char.c\
	$(samples_folder_from_sample_bin_folder)check_type/short.c\
	$(samples_folder_from_sample_bin_folder)check_type/ushort.c\
	$(samples_folder_from_sample_bin_folder)check_type/int.c\
	$(samples_folder_from_sample_bin_folder)check_type/uint.c\
	$(samples_folder_from_sample_bin_folder)check_type/long.c\
	$(samples_folder_from_sample_bin_folder)check_type/ulong.c\
	$(samples_folder_from_sample_bin_folder)check_type/llong.c\
	$(samples_folder_from_sample_bin_folder)check_type/ullong.c\
	$(samples_folder_from_sample_bin_folder)check_type/float.c\
	$(samples_folder_from_sample_bin_folder)check_type/double.c\
	$(samples_folder_from_sample_bin_folder)check_type/ldouble.c
depends20=\
	$(samples_folder_from_build_folder)check_type/main.c\
	$(samples_folder_from_build_folder)check_type/char.c\
	$(samples_folder_from_build_folder)check_type/short.c\
	$(samples_folder_from_build_folder)check_type/ushort.c\
	$(samples_folder_from_build_folder)check_type/int.c\
	$(samples_folder_from_build_folder)check_type/uint.c\
	$(samples_folder_from_build_folder)check_type/long.c\
	$(samples_folder_from_build_folder)check_type/ulong.c\
	$(samples_folder_from_build_folder)check_type/llong.c\
	$(samples_folder_from_build_folder)check_type/ullong.c\
	$(samples_folder_from_build_folder)check_type/float.c\
	$(samples_folder_from_build_folder)check_type/double.c\
	$(samples_folder_from_build_folder)check_type/ldouble.c
name20=check_type_sample

check_type_sample: $(depends20) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name20) && \
	cd $(bin_folder_from_build_folder)$(name20) && \
	$(CC) -o $(name20) $(files20) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_check_type_sample:
	rm -rf $(bin_folder_from_build_folder)$(name20)

#
# check_operator sample
#

files21=$(samples_folder_from_sample_bin_folder)check_operator/main.c
depends21=$(samples_folder_from_build_folder)check_operator/main.c
name21=check_operator_sample

check_operator_sample: $(depends21) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name21) && \
	cd $(bin_folder_from_build_folder)$(name21) && \
	$(CC) -o $(name21) $(files21) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_check_operator_sample:
	rm -rf $(bin_folder_from_build_folder)$(name21)

#
# assert_type sample
#

files22=\
	$(samples_folder_from_sample_bin_folder)assert_type/main.c\
	$(samples_folder_from_sample_bin_folder)assert_type/char.c\
	$(samples_folder_from_sample_bin_folder)assert_type/short.c\
	$(samples_folder_from_sample_bin_folder)assert_type/ushort.c\
	$(samples_folder_from_sample_bin_folder)assert_type/int.c\
	$(samples_folder_from_sample_bin_folder)assert_type/uint.c\
	$(samples_folder_from_sample_bin_folder)assert_type/long.c\
	$(samples_folder_from_sample_bin_folder)assert_type/ulong.c\
	$(samples_folder_from_sample_bin_folder)assert_type/llong.c\
	$(samples_folder_from_sample_bin_folder)assert_type/ullong.c\
	$(samples_folder_from_sample_bin_folder)assert_type/float.c\
	$(samples_folder_from_sample_bin_folder)assert_type/double.c\
	$(samples_folder_from_sample_bin_folder)assert_type/ldouble.c
depends22=\
	$(samples_folder_from_build_folder)assert_type/main.c\
	$(samples_folder_from_build_folder)assert_type/char.c\
	$(samples_folder_from_build_folder)assert_type/short.c\
	$(samples_folder_from_build_folder)assert_type/ushort.c\
	$(samples_folder_from_build_folder)assert_type/int.c\
	$(samples_folder_from_build_folder)assert_type/uint.c\
	$(samples_folder_from_build_folder)assert_type/long.c\
	$(samples_folder_from_build_folder)assert_type/ulong.c\
	$(samples_folder_from_build_folder)assert_type/llong.c\
	$(samples_folder_from_build_folder)assert_type/ullong.c\
	$(samples_folder_from_build_folder)assert_type/float.c\
	$(samples_folder_from_build_folder)assert_type/double.c\
	$(samples_folder_from_build_folder)assert_type/ldouble.c
name22=assert_type_sample

assert_type_sample: $(depends22) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name22) && \
	cd $(bin_folder_from_build_folder)$(name22) && \
	$(CC) -o $(name22) $(files22) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_assert_type_sample:
	rm -rf $(bin_folder_from_build_folder)$(name22)

#
# test_assert_type sample
#

files23=\
	$(samples_folder_from_sample_bin_folder)test_assert_type/main.c\
	$(samples_folder_from_sample_bin_folder)test_assert_type/char.c\
	$(samples_folder_from_sample_bin_folder)test_assert_type/short.c\
	$(samples_folder_from_sample_bin_folder)test_assert_type/ushort.c\
	$(samples_folder_from_sample_bin_folder)test_assert_type/int.c\
	$(samples_folder_from_sample_bin_folder)test_assert_type/uint.c\
	$(samples_folder_from_sample_bin_folder)test_assert_type/long.c\
	$(samples_folder_from_sample_bin_folder)test_assert_type/ulong.c\
	$(samples_folder_from_sample_bin_folder)test_assert_type/llong.c\
	$(samples_folder_from_sample_bin_folder)test_assert_type/ullong.c\
	$(samples_folder_from_sample_bin_folder)test_assert_type/float.c\
	$(samples_folder_from_sample_bin_folder)test_assert_type/double.c\
	$(samples_folder_from_sample_bin_folder)test_assert_type/ldouble.c
depends23=\
	$(samples_folder_from_build_folder)test_assert_type/main.c\
	$(samples_folder_from_build_folder)test_assert_type/char.c\
	$(samples_folder_from_build_folder)test_assert_type/short.c\
	$(samples_folder_from_build_folder)test_assert_type/ushort.c\
	$(samples_folder_from_build_folder)test_assert_type/int.c\
	$(samples_folder_from_build_folder)test_assert_type/uint.c\
	$(samples_folder_from_build_folder)test_assert_type/long.c\
	$(samples_folder_from_build_folder)test_assert_type/ulong.c\
	$(samples_folder_from_build_folder)test_assert_type/llong.c\
	$(samples_folder_from_build_folder)test_assert_type/ullong.c\
	$(samples_folder_from_build_folder)test_assert_type/float.c\
	$(samples_folder_from_build_folder)test_assert_type/double.c\
	$(samples_folder_from_build_folder)test_assert_type/ldouble.c
name23=test_assert_type_sample

test_assert_type_sample: $(depends23) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name23) && \
	cd $(bin_folder_from_build_folder)$(name23) && \
	$(CC) -o $(name23) $(files23) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_test_assert_type_sample:
	rm -rf $(bin_folder_from_build_folder)$(name23)

#
# module_assert_type sample
#

files24=\
	$(samples_folder_from_sample_bin_folder)module_assert_type/main.c\
	$(samples_folder_from_sample_bin_folder)module_assert_type/char.c\
	$(samples_folder_from_sample_bin_folder)module_assert_type/short.c\
	$(samples_folder_from_sample_bin_folder)module_assert_type/ushort.c\
	$(samples_folder_from_sample_bin_folder)module_assert_type/int.c\
	$(samples_folder_from_sample_bin_folder)module_assert_type/uint.c\
	$(samples_folder_from_sample_bin_folder)module_assert_type/long.c\
	$(samples_folder_from_sample_bin_folder)module_assert_type/ulong.c\
	$(samples_folder_from_sample_bin_folder)module_assert_type/llong.c\
	$(samples_folder_from_sample_bin_folder)module_assert_type/ullong.c\
	$(samples_folder_from_sample_bin_folder)module_assert_type/float.c\
	$(samples_folder_from_sample_bin_folder)module_assert_type/double.c\
	$(samples_folder_from_sample_bin_folder)module_assert_type/ldouble.c
depends24=\
	$(samples_folder_from_build_folder)module_assert_type/main.c\
	$(samples_folder_from_build_folder)module_assert_type/char.c\
	$(samples_folder_from_build_folder)module_assert_type/short.c\
	$(samples_folder_from_build_folder)module_assert_type/ushort.c\
	$(samples_folder_from_build_folder)module_assert_type/int.c\
	$(samples_folder_from_build_folder)module_assert_type/uint.c\
	$(samples_folder_from_build_folder)module_assert_type/long.c\
	$(samples_folder_from_build_folder)module_assert_type/ulong.c\
	$(samples_folder_from_build_folder)module_assert_type/llong.c\
	$(samples_folder_from_build_folder)module_assert_type/ullong.c\
	$(samples_folder_from_build_folder)module_assert_type/float.c\
	$(samples_folder_from_build_folder)module_assert_type/double.c\
	$(samples_folder_from_build_folder)module_assert_type/ldouble.c
name24=module_assert_type_sample

module_assert_type_sample: $(depends24) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name24) && \
	cd $(bin_folder_from_build_folder)$(name24) && \
	$(CC) -o $(name24) $(files24) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_module_assert_type_sample:
	rm -rf $(bin_folder_from_build_folder)$(name24)

#
# assert_operator sample
#

files25=$(samples_folder_from_sample_bin_folder)assert_operator/main.c
depends25=$(samples_folder_from_build_folder)assert_operator/main.c
name25=assert_operator_sample

assert_operator_sample: $(depends25) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name25) && \
	cd $(bin_folder_from_build_folder)$(name25) && \
	$(CC) -o $(name25) $(files25) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_assert_operator_sample:
	rm -rf $(bin_folder_from_build_folder)$(name25)

#
# test_assert_operator sample
#

files26=$(samples_folder_from_sample_bin_folder)test_assert_operator/main.c
depends26=$(samples_folder_from_build_folder)test_assert_operator/main.c
name26=test_assert_operator_sample

test_assert_operator_sample: $(depends26) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name26) && \
	cd $(bin_folder_from_build_folder)$(name26) && \
	$(CC) -o $(name26) $(files26) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_test_assert_operator_sample:
	rm -rf $(bin_folder_from_build_folder)$(name26)

#
# module_assert_operator sample
#

files27=$(samples_folder_from_sample_bin_folder)module_assert_operator/main.c
depends27=$(samples_folder_from_build_folder)module_assert_operator/main.c
name27=module_assert_operator_sample

module_assert_operator_sample: $(depends27) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name27) && \
	cd $(bin_folder_from_build_folder)$(name27) && \
	$(CC) -o $(name27) $(files27) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_module_assert_operator_sample:
	rm -rf $(bin_folder_from_build_folder)$(name27)

#
# test_assert sample
#

files28=$(samples_folder_from_sample_bin_folder)test_assert/main.c
depends28=$(samples_folder_from_build_folder)test_assert/main.c
name28=test_assert_sample

test_assert_sample: $(depends28) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name28) && \
	cd $(bin_folder_from_build_folder)$(name28) && \
	$(CC) -o $(name28) $(files28) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_test_assert_sample:
	rm -rf $(bin_folder_from_build_folder)$(name28)

#
# module_assert sample
#

files29=$(samples_folder_from_sample_bin_folder)module_assert/main.c
depends29=$(samples_folder_from_build_folder)module_assert/main.c
name29=module_assert_sample

module_assert_sample: $(depends29) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name29) && \
	cd $(bin_folder_from_build_folder)$(name29) && \
	$(CC) -o $(name29) $(files29) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_module_assert_sample:
	rm -rf $(bin_folder_from_build_folder)$(name29)

#
# assert sample
#

files30=$(samples_folder_from_sample_bin_folder)assert/main.c
depends30=$(samples_folder_from_build_folder)assert/main.c
name30=assert_sample

assert_sample: $(depends30) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name30) && \
	cd $(bin_folder_from_build_folder)$(name30) && \
	$(CC) -o $(name30) $(files30) $(include_folders) $(CFLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_assert_sample:
	rm -rf $(bin_folder_from_build_folder)$(name30)

#
# mt scheduler basic sample
#

files31=$(samples_folder_from_sample_bin_folder)mt_scheduler_basic/main.c
depends31=$(samples_folder_from_build_folder)mt_scheduler_basic/main.c
name31=mt_scheduler_basic_sample

mt_scheduler_basic_sample: $(depends31) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name31) && \
	cd $(bin_folder_from_build_folder)$(name31) && \
	$(CC) -o $(name31) $(files31) $(include_folders) $(CFLAGS) \
		$(MT_SCHEDULER_FLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_mt_scheduler_basic_sample:
	rm -rf $(bin_folder_from_build_folder)$(name31)

#
# mt scheduler module fixtures ran only once sample
#

files32=$(samples_folder_from_sample_bin_folder)mt_scheduler_module_fixtures_ran_only_once/main.c
depends32=$(samples_folder_from_build_folder)mt_scheduler_module_fixtures_ran_only_once/main.c
name32=mt_scheduler_module_fixtures_ran_only_once_sample

mt_scheduler_module_fixtures_ran_only_once_sample: $(depends32) $(lib_files)
	mkdir -p $(bin_folder_from_build_folder)$(name32) && \
	cd $(bin_folder_from_build_folder)$(name32) && \
	$(CC) -o $(name32) $(files32) $(include_folders) $(CFLAGS) \
		$(MT_SCHEDULER_FLAGS) && \
	cd $(build_folder_from_sample_bin_folder)

clean_mt_scheduler_module_fixtures_ran_only_once_sample:
	rm -rf $(bin_folder_from_build_folder)$(name32)

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
	test_and_module_sample\
	test_and_module_fixtures_sample\
	test_and_module_name_sample\
	check_type_sample\
	check_operator_sample\
	assert_type_sample\
	test_assert_type_sample\
	module_assert_type_sample\
	assert_operator_sample\
	test_assert_operator_sample\
	module_assert_operator_sample\
	test_assert_sample\
	module_assert_sample\
	assert_sample\
	mt_scheduler_basic_sample\
	mt_scheduler_module_fixtures_ran_only_once_sample\

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
	clean_test_and_module_sample\
	clean_test_and_module_fixtures_sample\
	clean_test_and_module_name_sample\
	clean_check_type_sample\
	clean_check_operator_sample\
	clean_assert_type_sample\
	clean_test_assert_type_sample\
	clean_module_assert_type_sample\
	clean_assert_operator_sample\
	clean_test_assert_operator_sample\
	clean_module_assert_operator_sample\
	clean_test_assert_sample\
	clean_module_assert_sample\
	clean_assert_sample\
	clean_mt_scheduler_basic_sample\
	clean_mt_scheduler_module_fixtures_ran_only_once_sample\
