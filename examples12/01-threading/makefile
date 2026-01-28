all: async1 async2 async3 promise parallel_algorithm

async1: async1.cpp
	g++ -g -Wall -pedantic $< -o $@ -lpthread

async2: async2.cpp
	g++ -g -Wall -pedantic $< -o $@ -lpthread

async3: async3.cpp
	g++ -g -Wall -pedantic $< -o $@ -lpthread

promise: promise.cpp
	g++ -g -Wall -pedantic $^ -o $@ -lpthread

parallel_algorithm: parallel_algorithm.cpp
	g++ -std=c++17 -g -Wall -pedantic $< -o $@ -ltbb


.PHONY: clean

clean:
	-rm async1 async2 async3 promise parallel_algorithm