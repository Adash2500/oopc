all: fun1 fun2 fun3 fun4 fun5 unordered_set3 unordered_set4

fun1: fun1.o
	g++ -g -Wall $^ -o $@

fun1.o: fun1.cpp
	g++ -std=c++14 -g -c -Wall $< -o $@

fun2: fun2.o
	g++ -g -Wall $^ -o $@

fun2.o: fun2.cpp
	g++ -std=c++14 -g -c -Wall $< -o $@

fun3.o: fun3.cpp
	g++ -std=c++14 -g -c -Wall $< -o $@

fun3: fun3.o
	g++ -g -Wall $^ -o $@

fun4.o: fun4.cpp
	g++ -std=c++14 -g -c -Wall $< -o $@

fun4: fun4.o
	g++ -g -Wall $^ -o $@

fun5.o: fun5.cpp
	g++ -std=c++14 -g -c -Wall $< -o $@

fun5: fun5.o
	g++ -g -Wall $^ -o $@


unordered_set3.o: unordered_set3.cpp
	g++ -std=c++2a -g -c -Wall $< -o $@

unordered_set3: unordered_set3.o
	g++ -g -Wall $^ -o $@

unordered_set4.o: unordered_set4.cpp
	g++ -std=c++2a -g -c -Wall $< -o $@

unordered_set4: unordered_set4.o
	g++ -g -Wall $^ -o $@

.PHONY: clean

clean:
	-rm fun1.o fun1 fun2.o fun2 fun3.o fun3 fun4.o fun4 fun5.o fun5 unordered_set3.o unordered_set3 unordered_set4.o unordered_set4