externc: externc.o module.o
	g++ -g -Wall -pedantic $^ -o $@

externc.o: externc.cpp
	g++ -g -c -Wall -pedantic $< -o $@

module.o: module.c
	gcc -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm externc.o module.o externc
