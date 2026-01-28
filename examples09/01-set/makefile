all: set

set: set.o
	g++ -g -Wall -pedantic $^ -o $@

set.o: set.cpp employee.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm set.o set