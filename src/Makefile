.PHONY: all a clean gcov_report s21_math remove_s21_math linter cppcheck leaks
CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
LIB = s21_math.a
LIB_DIR = function/*.c
TESTFILE = test
GCOV_FLAG = -fprofile-arcs -ftest-coverage
LIBS_FOR_CHECK_PCKG = -lcheck -lsubunit -lm -lpthread 
D_OS = -D __My_Linux__
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	LIBS_FOR_CHECK_PCKG = -lcheck -lsubunit -lm -lpthread -lrt
	D_OS = -D __My_Linux__
else
	LIBS_FOR_CHECK_PCKG = -lcheck -lm -lpthread
	D_OS = -D __My_APPLE__
endif

all: clean s21_math.a gcov_report


clang:
	cp ../materials/linters/.clang-format .

check:
	clang-format -n *.c *.h

format:
	clang-format -i *.c *.h

test: s21_math.a
	$(CC) $(FLAGS) -o a.out test.c -L. $(LIB) $(LIBS_FOR_CHECK_PCKG) $(GCOV_FLAG) -lm


gcov_report:
	$(CC) $(FLAGS) $(GCOV_FLAG)  $(TESTFILE).c  $(LIBS_FOR_CHECK_PCKG) -o a2.out
	gcov a2.out
	lcov -o test.info -c -d .
	genhtml -o report test.info

s21_math.a:
	$(CC) $(D_OS) -c $(FLAGS) $(LIB_DIR)
	ar -rcs $(LIB) *.o
	rm -rf *.o



clean:
	rm -f *.a *.o *.so *.out $(TESTFILE) *.info *.gcno *.gcda
	rm -f *$(TEST_LIB)*.a *$(TEST_LIB)*.o
	rm -rf report
	rm -rf .clang-format



