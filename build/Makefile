CC=gcc
CFLAGS=-Wall -Wextra -Werror -DSAMPLE_LINUX -fprofile-arcs -ftest-coverage

lib_folder=-I../include
lib_files=../include/nbp.h

basic_sample_files=\
	../samples/basic/basic_sample_test.c

basic_sample: $(basic_sample_files) $(lib_files)
	$(CC) -o basic_sample $(basic_sample_files) $(lib_folder) $(CFLAGS)

clean_basic_sample:
	rm -f basic_sample

modules_sample_files=\
	../samples/modules/modules_sample_test.c\
	../samples/modules/modules_sample_module1.c\
	../samples/modules/modules_sample_module2.c

modules_sample: $(modules_sample_files) $(lib_files)
	$(CC) -o modules_sample $(modules_sample_files) $(lib_folder) $(CFLAGS)

clean_modules_sample:
	rm -f modules_sample

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

modules_one_file_sample_files=\
	../samples/modules_one_file/modules_one_file_sample_test.c

modules_one_file_sample: $(modules_one_file_sample_files) $(lib_files)
	$(CC) -o modules_one_file_sample $(modules_one_file_sample_files) \
	$(lib_folder) $(CFLAGS)

clean_modules_one_file_sample:
	rm -f modules_one_file_sample

submodules_one_file_sample_files=\
	../samples/submodules_one_file/submodules_one_file_sample_test.c

submodules_one_file_sample: $(submodules_one_file_sample_files) $(lib_files)
	$(CC) -o submodules_one_file_sample $(submodules_one_file_sample_files) \
	$(lib_folder) $(CFLAGS)

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
