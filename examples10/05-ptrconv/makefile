all: ptrconv1 ptrconv2

ptrconv1: ptrconv1.cpp
	g++ -g -Wall -pedantic $^ -o $@

ptrconv2: ptrconv2.cpp
	g++ -g -Wall -pedantic $^ -o $@

.PHONY: clean

clean:
	-rm ptrconv1 ptrconv2
