testassoc: testassoc.o assoctab.o
	g++ -g -Wall $^ -o $@

assoctab.o: assoctab.cpp assoctab.h
	g++ -g -c -Wall -pedantic $< -o $@

testassoc.o: testassoc.cpp assoctab.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm assoctab.o testassoc.o testassoc
