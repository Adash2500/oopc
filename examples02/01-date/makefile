TestDateType: TestDateType.o DateType.o
	g++ -g $^ -o $@

DateType.o: DateType.cpp DateType.h
	g++ -g -c -Wall -pedantic $< -o $@

TestDateType.o: TestDateType.cpp DateType.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm TestDateType DateType.o TestDateType.o