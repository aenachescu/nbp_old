CC=gcc

basic_sample_files=\
	../samples/basic/src/basic_sample.c\
	../samples/basic/test/basic_sample_test.c

basic_sample_include=\
	-I../include\
	-I../samples/basic/include

basic_sample:
	$(CC) -o basic_sample $(basic_sample_files) $(basic_sample_include)

clean_basic_sample:
	rm -f basic_sample

modules_sample_files=\
	../samples/modules/src/basic_math.c\
	../samples/modules/src/advanced_math.c\
	../samples/modules/test/main_test.c\
	../samples/modules/test/basic_math_test.c\
	../samples/modules/test/advanced_math_test.c

modules_sample_include=\
	-I../include\
	-I../samples/modules/include

modules_sample:
	$(CC) -o modules_sample $(modules_sample_files) $(modules_sample_include)

clean_modules_sample:
	rm -f modules_sample

all:\
	basic_sample\
	modules_sample

clean:\
	clean_basic_sample\
	clean_modules_sample