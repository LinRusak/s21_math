.PHONY: all a clean gcov_report s21_math remove_s21_math linter cppcheck leaks
CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
TEST_LIB = s21_math_test
TESTFILE = test
GCOV_FLAG = -fprofile-arcs -ftest-coverage
LIBS_FOR_CHECK_PCKG = -lcheck -lsubunit -lm -lpthread 
D_OS =
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	LIBS_FOR_CHECK_PCKG = -lcheck -lsubunit -lm -lpthread -lrt
	D_OS = -D __My_Linux__
else
	LIBS_FOR_CHECK_PCKG = -lcheck -lm -lpthread
	D_OS = -D __My_APPLE__
endif

all: clean s21_math.a gcov_report

a: clean s21_math.a gcov_report

clang:
	cp ../materials/linters/.clang-format .

check:
	clang-format -n *.c *.h

format:
	clang-format -i *.c *.h

test: s21_math.a
	@echo "=========== test ==========="
	$(CC) $(FLAGS) -o a.out test.c -L. $(TEST_LIB).a $(LIBS_FOR_CHECK_PCKG) $(GCOV_FLAG) -lm
	./a.out

clean:
	rm -f *.a *.o *.so *.out $(TESTFILE) *.info *.gcno *.gcda
	rm -rf report
	rm -rf .clang-format

gcov_report:
	$(CC) $(D_OS) -c $(FLAGS) $(GCOV_FLAG) $(TEST_LIB).c -o $(TEST_LIB).a
	$(CC) $(FLAGS) $(GCOV_FLAG) $(TEST_LIB).a $(TESTFILE).c $(LIBS_FOR_CHECK_PCKG) -o a2.out
	./a2.out
	@echo "=== gcov start ==="
	gcov a2.out
	lcov -o test.info -c -d .
	genhtml -o report test.info

s21_math.a: remove_s21_math.a
	@echo "=== s21_math compile ==="
	$(CC) $(D_OS) -c $(FLAGS) $(TEST_LIB).c -o $(TEST_LIB).a

remove_s21_math.a:
	rm -f *$(TEST_LIB)*.a *$(TEST_LIB)*.o


leaks:
	CK_FORK=no leaks --atExit -- ./a.out
