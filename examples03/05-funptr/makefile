funptr: funptr.o
	g++ -g $^ -o $@

funptr.o: funptr.cpp
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm funptr.o funptr