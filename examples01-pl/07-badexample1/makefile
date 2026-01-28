all: good bad

good: good.c
	gcc -g -Wall $< -o $@

bad: bad.c
	gcc -g -Wall $< -o $@

.PHONY: clean

clean:
	-rm good bad