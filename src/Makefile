FLAGS=-Wall -Wextra -Werror
CC=gcc
FUNC_FILES_C=function/*.c
FUNC_FILES_O=*.o

all: s21_math.a

s21_math.a:
	$(CC) $(FLAGS) -c $(FUNC_FILES_C)
	cp testFiles/s21_math.h s21_math.h
	make build_library
	rm -rf *.o