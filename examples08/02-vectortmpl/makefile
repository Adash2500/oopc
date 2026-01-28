all: testvector opnew

testvector: testvector.o
	g++ -g -Wall $^ -o $@

testvector.o: testvector.cpp vector.h
	g++ -g -c -Wall -pedantic $< -o $@

opnew: opnew.o
	g++ -g -Wall $^ -o $@

opnew.o: opnew.cpp
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm testvector.o testvector opnew.o opnew