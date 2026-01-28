vararg: vararg.o
	g++ -g -Wall -pedantic $^ -o $@

vararg.o: vararg.cpp
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm vararg.o vararg
