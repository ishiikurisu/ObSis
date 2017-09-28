main-params = -o main.exe -lm -O2 -Wall -Ireader main.c  sureader.o

default: run

run: compile-main
	./main.exe

compile-main: compile-reader
	gcc $(main-params)

compile-reader:
	gcc reader/sureader.c -Wall -c
	ar cr reader/sureader.o reader/sureader.a

clean:
	rm *.exe
	rm *.o
