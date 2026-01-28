testmymalloc: mymalloc.o main.o
	gcc -g $^ -o $@ -lm

mymalloc.o: mymalloc.c mymalloc.h
	gcc -g -Wall -c $< -o $@

main.o: main.c mymalloc.h
	gcc -g -Wall -c $< -o $@

.PHONY: clean

clean:
	-rm main.o mymalloc.o testmymalloc