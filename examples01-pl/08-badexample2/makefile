all: good bad1 bad2

good: good.c
	gcc -g -Wall $< -o $@

bad1: bad1.c
	gcc -g -Wall $< -o $@

bad2: bad2.c
	gcc -g -Wall $< -o $@

.PHONY: clean

clean:
	-rm good bad1 bad2