.PHONY: clean all test 
CFLAGS = -Wall -Werror -MP -MMD 

all: bin/equation.exe 

bin/equation.exe: build/main.o build/procedure.o 
	gcc $(CFLAGS) build/main.o build/procedure.o -o bin/equation.exe -lm

build/main.o: src/main.c src/procedure.h
	gcc $(CFLAGS) -c src/main.c -o build/main.o -lm

build/procedure.o: src/procedure.c src/procedure.h 
	gcc $(CFLAGS) -c src/procedure.c -o build/procedure.o -lm

test: 
	make bin/equation_test.exe 
	bin/equation_test.exe 
