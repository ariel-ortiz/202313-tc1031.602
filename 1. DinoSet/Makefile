CC = g++ -g

all: main tests

main: main.o
	$(CC) main.o -o main

main.o: main.cpp dinoset.h
	$(CC) -c main.cpp

tests: tests.o tests_main.o
	$(CC) tests_main.o tests.o -o tests

tests.o: tests.cpp dinoset.h
	$(CC) -c tests.cpp

tests_main.o: tests_main.cpp
	$(CC) -c tests_main.cpp

clean:
	rm -f main tests tests_main.o tests.o main.o
