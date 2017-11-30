common-params = -Lreader -lsureader -ltttreader -lm -O2 -Wall

default: middleware

middleware:
	gcc $(common-params) -c -o calculator/middleware.o calculator/middleware.c
	ar cr calculator/libmiddleware.a reader/sureader.o reader/tttreader.o calculator/middleware.o
