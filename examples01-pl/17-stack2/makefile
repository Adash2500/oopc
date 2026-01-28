teststack: teststack.o stack.o
	gcc -Wall $^ -o $@

stack.o: stack.c stack.h
	gcc -c -Wall $< -o $@

teststack.o: teststack.c stack.h
	gcc -c -Wall $< -o $@

.PHONY: clean

clean:
	-rm stack.o teststack.o teststack