all: fifo1_bad fifo2 fifo3

.cpp:
	g++ -std=c++17 -g -Wall -pedantic $^ -o $@ -lpthread


.PHONY: clean

clean:
	-rm fifo1_bad fifo2 fifo3