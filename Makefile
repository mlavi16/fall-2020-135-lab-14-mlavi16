main: main.o
	g++ -o main main.o

tests: tests.o
	g++ -o tests tests.o

main.o: main.cpp MyVector.cxx MyVector.h

tests.o: tests.cpp doctest.h MyVector.h

clean:
	rm -f main.o tests.o main tests

help:
	@echo  make main : make executable named main
	@echo make tests : make test suite named tests