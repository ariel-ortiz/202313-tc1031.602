# En example of a Makefile

CC = g++ -g

main_fact: main.o fact.o
	$(CC) main.o fact.o -o main_fact

main.o: main.cpp fact.h
	$(CC) main.cpp -c

fact.o: fact.cpp fact.h
	$(CC) fact.cpp -c

clean:
	rm -f main.o fact.o main_fact
