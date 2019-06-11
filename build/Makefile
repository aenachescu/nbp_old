CC=gcc

lib_folder=-I../include

basic_sample_files=\
	../samples/basic/basic_sample_test.c

basic_sample:
	$(CC) -o basic_sample $(basic_sample_files) $(lib_folder)

clean_basic_sample:
	rm -f basic_sample

modules_sample_files=\
	../samples/modules/modules_sample_test.c\
	../samples/modules/basic_math_test.c\
	../samples/modules/advanced_math_test.c

modules_sample:
	$(CC) -o modules_sample $(modules_sample_files) $(lib_folder)

clean_modules_sample:
	rm -f modules_sample

submodules_sample_files=\
	../samples/submodules/submodules_sample_test.c\
	../samples/submodules/module1.c\
	../samples/submodules/module2.c\
	../samples/submodules/submodule1.c\
	../samples/submodules/submodule2.c\
	../samples/submodules/submodule3.c\
	../samples/submodules/submodule4.c

submodules_sample:
	$(CC) -o submodules_sample $(submodules_sample_files) $(lib_folder)

clean_submodules_sample:
	rm -f submodules_sample

modules_one_file_sample_files=\
	../samples/modules_one_file/modules_one_file_sample_test.c

modules_one_file_sample:
	$(CC) -o modules_one_file_sample $(modules_one_file_sample_files) \
	$(lib_folder)

clean_modules_one_file_sample:
	rm -f modules_one_file_sample

submodules_one_file_sample_files=\
	../samples/submodules_one_file/submodules_one_file_sample_test.c

submodules_one_file_sample:
	$(CC) -o submodules_one_file_sample $(submodules_one_file_sample_files) \
	$(lib_folder)

clean_submodules_one_file_sample:
	rm -f submodules_one_file_sample

all:\
	basic_sample\
	modules_sample\
	submodules_sample\
	modules_one_file_sample\
	submodules_one_file_sample\

clean:\
	clean_basic_sample\
	clean_modules_sample\
	clean_submodules_sample\
	clean_modules_one_file_sample\
	clean_submodules_one_file_sample\
