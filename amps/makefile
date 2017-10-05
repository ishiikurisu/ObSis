common-params = sureader.o -lm -O2 -Wall -Ireader
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

compile-reader:
	gcc reader/sureader.c -Wall -c
	ar cr reader/sureader.a reader/sureader.o

clean:
	rm *.exe
	rm *.o
	rm reader/*.o
	rm reader/*.a
	rm reader/*.gch
