EXECUTABLES = 01-unique_ptr1 02-move 03-unique_ptr2 04-unique_ptr3_bad 05-unique_ptr4_good 06-vector 07-shared_ptr1 08-shared_ptr2_bad 09-weak_ptr

all: $(EXECUTABLES)

%: %.cpp
	g++ -g -Wall -pedantic -fno-elide-constructors $< -o $@
#	g++ -g -Wall -pedantic $< -o $@


.PHONY: clean

clean:
	-rm $(EXECUTABLES)