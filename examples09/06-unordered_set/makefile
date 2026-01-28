all: unordered_set unordered_set2

unordered_set: unordered_set.o
	g++ -g -Wall -pedantic $^ -o $@

unordered_set.o: unordered_set.cpp employee.h
	g++ -g -c -Wall -pedantic $< -o $@

unordered_set2: unordered_set2.o
	g++ -g -Wall -pedantic $^ -o $@

unordered_set2.o: unordered_set2.cpp employee.h
	g++ -g -c -Wall -pedantic $< -o $@


.PHONY: clean

clean:
	-rm unordered_set.o unordered_set unordered_set2.o unordered_set2