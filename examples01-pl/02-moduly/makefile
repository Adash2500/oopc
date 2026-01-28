hello: witaj.o hello.o
	gcc -g witaj.o hello.o -o hello -lm

witaj.o: witaj.c witaj.h
	gcc -g -Wall -pedantic -c witaj.c -o witaj.o

hello.o: hello.c witaj.h
	gcc -g -Wall -pedantic -c hello.c -o hello.o

.PHONY: clean

clean:
	-rm hello.o witaj.o hello