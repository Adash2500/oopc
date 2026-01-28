all: funptr1 funptr2

funptr1: funptr1.o
	g++ -g -Wall -pedantic $^ -o $@

funptr1.o: funptr1.cpp
	g++ -g -c -Wall -pedantic $< -o $@

funptr2: funptr2.o
	g++ -g -Wall -pedantic $^ -o $@

funptr2.o: funptr2.cpp
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm funptr1.o funptr1 funptr2.o funptr2