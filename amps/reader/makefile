make: compile-sureader compile-tttreader

compile-sureader: compile-header
	gcc reader/sureader.c reader/header/suheader.o -Wall -c -o reader/sureader.o
	ar cr reader/libsureader.a reader/sureader.o

compile-tttreader:
	gcc reader/tttreader.c  -I$(CWPROOT)/include  -c -o reader/tttreader.o
	ar cr reader/libtttreader.a reader/tttreader.o

compile-header:
	gcc reader/header/suheader.c -Wall -c -o reader/header/suheader.o
	ar cr reader/header/libsuheader.a reader/header/suheader.o
