all: threads1 threads1_cxx11 threads2_cxx11 volatile1_cxx11 volatile1_cxx11.s volatile2_cxx11 volatile2_cxx11.s

threads1: threads1.o
	g++ -g $^ -lpthread -o$@

threads1.o: threads1.cpp
	g++ -g -c -Wall -pedantic $< -o $@

threads1_cxx11: threads1_cxx11.cpp
	g++ -g -std=c++11 -pthread -Wall -pedantic $< -o $@

threads2_cxx11: threads2_cxx11.cpp
	g++ -g -std=c++11 -pthread -Wall -pedantic $< -o $@

volatile1_cxx11: volatile1_cxx11.cpp
	g++ -g -std=c++11 -pthread -Wall -pedantic -O2 $< -o $@	

volatile1_cxx11.s: volatile1_cxx11.cpp
	g++ -g -std=c++11 -pthread -Wall -pedantic -S -O2 $< -o $@	
	
volatile2_cxx11: volatile2_cxx11.cpp
	g++ -g -std=c++11 -pthread -Wall -pedantic -O2 $< -o $@	

volatile2_cxx11.s: volatile2_cxx11.cpp
	g++ -g -std=c++11 -pthread -Wall -pedantic -S -O2 $< -o $@	
	

.PHONY: clean

clean:
	-rm threads1.o threads1 threads1_cxx11 threads2_cxx11 volatile1_cxx11 volatile1_cxx11.s volatile2_cxx11 volatile2_cxx11.s
