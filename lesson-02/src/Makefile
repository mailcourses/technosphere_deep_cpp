CC=g++-11
FLAGS=-std=c++20 -Wall -pedantic -Wextra -Werror

all: smart_ptr mem

mem: mem.cpp
	$(CC) $(FLAGS) mem.cpp -o mem

smart_ptr: smart_ptr.cpp
	$(CC) $(FLAGS) smart_ptr.cpp -o smart_ptr

clean:
	rm -f mem smart_ptr

