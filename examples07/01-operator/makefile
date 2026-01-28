all: operator koenig.o

operator: operator.cpp
	g++ -g -Wall -pedantic $^ -o $@

koenig.o: koenig.cpp
	g++ -c -g -Wall -pedantic $^ -o $@

.PHONY: clean

clean:
	-rm operator koenig.o
