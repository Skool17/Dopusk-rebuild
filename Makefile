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

bin/equation_test.exe: build/test/main.o build/test/function_test.o
	@gcc $(CFLAGS) build/test/main.o build/test/function_test.o build/procedure.o -o bin/equation_test.exe -lm
	
build/test/main.o: test/main.c src/procedure.h
	@gcc $(CFLAGS) -I thirdparty -c test/main.c -o build/test/main.o  -lm

build/test/function_test.o: src/procedure.h test/function_test.c
	@gcc $(CFlAGS) -I thirdparty -c test/function_test.c -o build/test/function_test.o  -lm 

clean:
	@echo "Cleaning files in build directory" 	
	@rm -rf build/*.d build/*.o 
	@rm -rf build/test/*.d build/test/*.o
	@echo "Cleaning binaries"
	@rm -rf bin/equation.exe 
	@rm -rf bin/equation_test.exe 
	@echo "All files have been cleaned."	
