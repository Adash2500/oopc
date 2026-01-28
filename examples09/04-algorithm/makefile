all: algo1 algo2

algo1: algo1.o
	g++ -g -Wall -pedantic $^ -o $@

algo1.o: algo1.cpp
	g++ -g -c -Wall -pedantic $< -o $@

algo2: algo2.o
	g++ -g -Wall -pedantic $^ -o $@

algo2.o: algo2.cpp
	g++ -g -c -Wall -pedantic $< -o $@


.PHONY: clean

clean:
	-rm algo1.o algo1 algo2.o algo2