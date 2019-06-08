CC=gcc

lib_folder=-I../include

basic_sample_files=\
	../samples/basic/basic_sample_test.c

basic_sample:
	$(CC) -o basic_sample $(basic_sample_files) $(lib_folder)

clean_basic_sample:
	rm -f basic_sample

modules_sample_files=\
	../samples/modules/main_test.c\
	../samples/modules/basic_math_test.c\
	../samples/modules/advanced_math_test.c

modules_sample:
	$(CC) -o modules_sample $(modules_sample_files) $(lib_folder)

clean_modules_sample:
	rm -f modules_sample

all:\
	basic_sample\
	modules_sample

clean:\
	clean_basic_sample\
	clean_modules_sample