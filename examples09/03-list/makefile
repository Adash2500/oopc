all: list

list: list.cpp
	g++ -std=c++2a -g -Wall -pedantic $^ -o $@
.PHONY: clean

clean:
	-rm list