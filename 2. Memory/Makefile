CC = g++ -g

all: example_pointers example_references memory_errors example_new_delete\
		simple_linked_list

example_pointers: example_pointers.cpp
	$(CC) example_pointers.cpp -o example_pointers

example_references: example_references.cpp
	$(CC) example_references.cpp -o example_references

memory_errors: memory_errors.cpp
	$(CC) memory_errors.cpp -o memory_errors

example_new_delete: example_new_delete.cpp
	$(CC) example_new_delete.cpp -o example_new_delete

simple_linked_list: simple_linked_list.cpp
	$(CC) simple_linked_list.cpp -o simple_linked_list

clean:
	rm -rf example_pointers example_references memory_errors example_new_delete\
		simple_linked_list