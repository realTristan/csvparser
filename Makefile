DEPS = src/utils/string.c src/utils/row.c src/utils/file.c src/parser.c
MAIN = src/testing/main.c
FLAGS = -Wall -std=c99
OUPUT = main.out
CC = gcc

all: output execute

output:
	$(CC) $(FLAGS) $(DEPS) $(MAIN) -o build/main.out

execute:
	./build/main.out