all: employee1 employee2

employee1: employee1.o
	g++ -g -Wall -pedantic $^ -o $@

employee1.o: employee1.cpp
	g++ -g -c -Wall -pedantic $< -o $@

employee2: employee2.o
	g++ -g -Wall -pedantic $^ -o $@

employee2.o: employee2.cpp
	g++ -g -c -Wall -pedantic $< -o $@


.PHONY: clean

clean:
	-rm employee1.o employee1 employee2.o employee2