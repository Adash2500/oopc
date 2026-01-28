static: static.o
	g++ -g -Wall $^ -o $@

static.o: static.cpp
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm static.o static
