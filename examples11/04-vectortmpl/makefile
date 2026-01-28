all: testvector

testvector: testvector.cpp vector.h
	g++ -std=c++17 -g -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm testvector