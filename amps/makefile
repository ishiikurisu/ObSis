common-params = reader/sureader.o -lm -O2 -Wall
main-params = main.c $(common-params) -o main.exe
test-params = test.c $(common-params) -o test.exe

default: run

test: compile-test
	./test.exe

run: compile-main
	./main.exe data/zonoise10.su

compile-test: compile-reader
	gcc $(test-params)

compile-main: compile-reader
	gcc $(main-params)

compile-reader: compile-header
	gcc reader/sureader.c reader/header/suheader.o -Wall -c -o reader/sureader.o
	ar cr reader/sureader.a reader/sureader.o

compile-header:
	gcc reader/header/suheader.c -Wall -c -o reader/header/suheader.o
	ar cr reader/header/suheader.a reader/header/suheader.o

clean:
	rm *.exe
	rm *.o
	rm reader/*.o
	rm reader/*.a
	rm reader/*.gch
