all: threads1 threads2

threads1: threads1.o
	g++ -g -Wall -pedantic $^ -o $@ -lpthread

threads1.o: threads1.cpp mutex.h
	g++ -g -c -Wall -pedantic $< -o $@

threads2: threads2.o
	g++ -g -Wall -pedantic $^ -o $@ -lpthread

threads2.o: threads2.cpp mutex.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm threads1.o threads1 threads2.o threads2