all: fun1 fun2 fun3

fun1: fun1.o
	g++ -g -Wall $^ -o $@

fun1.o: fun1.cpp
	g++ -g -c -Wall $< -o $@

fun2: fun2.o
	g++ -g -Wall $^ -o $@

fun2.o: fun2.cpp
	g++ -g -c -Wall $< -o $@

fun3.o: fun3.cpp
	g++ -std=c++11 -g -c -Wall $< -o $@

fun3: fun3.o
	g++ -g -Wall $^ -o $@

.PHONY: clean

clean:
	-rm fun1.o fun1 fun2.o fun2 fun3.o fun3