all: minimum minimum_concepts swap1 swap2 bubblesort

minimum: minimum.o
	g++ -g -Wall -pedantic $^ -o $@

minimum.o: minimum.cpp
	g++ -g -c -Wall -pedantic $< -o $@

minimum_concepts: minimum_concepts.o
	g++ -g -Wall -pedantic $^ -o $@

minimum_concepts.o: minimum_concepts.cpp
	g++ -std=c++20 -g -c -Wall -pedantic $< -o $@

swap1: swap1.o
	g++ -g -Wall -pedantic $^ -o $@

swap1.o: swap1.cpp
	g++ -g -c -Wall -pedantic $< -o $@

swap2: swap2.o
	g++ -g -Wall -pedantic $^ -o $@

swap2.o: swap2.cpp
	g++ -g -c -Wall -pedantic $< -o $@

bubblesort: bubblesort.o
	g++ -g -Wall -pedantic $^ -o $@

bubblesort.o: bubblesort.cpp
	g++ -g -c -Wall $< -o $@


.PHONY: clean

clean:
	-rm minimum.o minimum swap1.o swap1 swap2.o swap2 bubblesort.o bubblesort