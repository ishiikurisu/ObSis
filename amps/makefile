main-params = -o main.exe -lm -O2 -Wall -Ireader main.c  sureader.o

default: run

run: compile-main
	./main.exe data/zonoise10.su

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
