all: testvalgrind1 testvalgrind2 test

testvalgrind1: testvalgrind1.c
	gcc -g -Wall $< -o $@

testvalgrind2: testvalgrind2.c
	gcc -g -Wall $< -o $@

.PHONY: clean test

clean:
	-rm testvalgrind1 testvalgrind2

test:
	valgrind -v ./testvalgrind1
	valgrind -v ./testvalgrind2