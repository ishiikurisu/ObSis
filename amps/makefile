reader-archives = -Lreader -lsureader -ltttreader
calculator-archives = -Lcalculator -lmiddleware
common-params = $(reader-archives) $(calculator-archives) -lm -O2 -Wall -L$(CWPROOT)/lib -lsu -lcwp -Wall
main-params = main.c $(common-params) -o main.exe
test-params = test.c $(common-params) -o test.exe

default: test

test: run-test clean

run-test: compile-test
	./test.exe
	psimage n1=4000 curve=./data/sample.data > ./data/sample.ps

run: compile-main
	./main.exe data/zonoise10.su data/zonoise10.bin

compile-test: compile-calculator
	gcc $(test-params)

plot-test: test plot

compile-main: compile-reader
	gcc $(main-params)

compile-calculator: compile-reader
	make -f calculator/makefile

compile-reader:
	make -f reader/makefile

plot:
	python plot.py $(WHAT)

clean:
	rm *.exe
	rm *.o
	rm reader/*.o
	rm reader/*.a
	rm reader/*.gch
	rm calculator/*.o
	rm calculator/*.a
	rm data/*.bin
