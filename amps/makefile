common-params = reader/sureader.a reader/tttreader.a -lm -O2 -Wall -L$(CWPROOT)/lib -lsu -lcwp -Wall
main-params = main.c $(common-params) -o main.exe
test-params = test.c $(common-params) -o test.exe

default: run

test: run-test clean

run-test: compile-test
	./test.exe

run: compile-main
	./main.exe data/zonoise10.su data/zonoise10.bin

compile-test: compile-sureader compile-tttreader
	gcc $(test-params)

plot-test: test plot

compile-main: compile-sureader compile-tttreader
	gcc $(main-params)

compile-sureader: compile-header
	gcc reader/sureader.c reader/header/suheader.o -Wall -c -o reader/sureader.o
	ar cr reader/sureader.a reader/sureader.o

compile-tttreader:
	gcc reader/tttreader.c  -I$(CWPROOT)/include  -c -o reader/tttreader.o
	ar cr reader/tttreader.a reader/tttreader.o

compile-header:
	gcc reader/header/suheader.c -Wall -c -o reader/header/suheader.o
	ar cr reader/header/suheader.a reader/header/suheader.o

plot:
	python plot.py $(WHAT)

clean:
	rm *.exe
	rm *.o
	rm reader/*.o
	rm reader/*.a
	rm reader/*.gch
	rm data/*.bin
