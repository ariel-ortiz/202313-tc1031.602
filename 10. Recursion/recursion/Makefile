# Archivo para construir la práctica de recursión.

CC = g++ -g

all: main tests

main: main.o intlist.o recursion.o
	$(CC) main.o intlist.o recursion.o -o main

main.o: main.cpp intlist.h
	$(CC) -c main.cpp

intlist.o: intlist.cpp intlist.h
	$(CC) -c intlist.cpp

recursion.o: recursion.h recursion.cpp
	$(CC) -c recursion.cpp

tests: tests.o tests_main.o intlist.o recursion.o
	$(CC) tests.o tests_main.o intlist.o recursion.o -o tests

tests.o: tests.cpp intlist.h
	$(CC) -c tests.cpp

tests_main.o: tests_main.cpp
	$(CC) -c tests_main.cpp

clean:
	rm -f main tests main.o intlist.o recursion.o tests.o tests_main.o
