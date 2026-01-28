all: virtbase virtbase_err

virtbase: virtbase.cpp
	g++ -g -Wall -pedantic $^ -o $@


virtbase_err: virtbase.cpp
	g++ -g -Wall -pedantic -DERROR $^ -o $@

.PHONY: clean

clean:
	-rm virtbase