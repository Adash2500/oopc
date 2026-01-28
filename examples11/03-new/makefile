all: newhandler placementnew placement2 placementnew2

newhandler: newhandler.o
	g++ -g -Wall -pedantic $^ -o $@

newhandler.o: newhandler.cpp
	g++ -g -c -Wall -pedantic $< -o $@

placementnew: placementnew.o
	g++ -g -Wall -pedantic $^ -o $@

placemenetnew.o: placementnew.cpp
	g++ -g -c -Wall -pedantic $< -o $@

placementnew2: placementnew2.o
	g++ -g -Wall -pedantic $^ -o $@

placemenetnew2.o: placementnew2.cpp
	g++ -g -c -Wall -pedantic $< -o $@

placement2: placement2.o
	g++ -g -Wall -pedantic $^ -o $@

placement2.o: placement2.cpp
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm newhandler.o newhandler placementnew.o placementnew placement2.o placement2 placementnew2.o placementnew2