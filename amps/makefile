reader-archives = -Lreader -lsureader -ltttreader
calculator-archives = -Lcalculator -lmiddleware
common-params = $(reader-archives) $(calculator-archives) -lm -O2 -Wall -L$(CWPROOT)/lib -lsu -lcwp -Wall
main-params = main.c $(common-params) -o main.exe
test-params = test.c $(common-params) -o test.exe

default: test

test: run-test clean

run-test: compile-test
	./test.exe

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
	python plot.py data/sample0.bin
	python plot.py data/sample100.bin
	python plot.py data/sample200.bin
	python plot.py data/sample300.bin
	python plot.py data/sample400.bin
	python plot.py data/sample500.bin
	python plot.py data/sample600.bin

clean:
	rm *.exe
	rm *.o
	rm reader/*.o
	rm reader/*.a
	rm reader/*.gch
	rm calculator/*.o
	rm calculator/*.a
	rm data/*.bin
