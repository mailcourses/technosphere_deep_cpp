CC=g++-11
FLAGS=-std=c++20 -Wall -pedantic -Wextra -Werror

all: shared_ptr rlvalue copy

shared_ptr: shared_ptr.cpp
	$(CC) $(FLAGS) shared_ptr.cpp -o shared_ptr

rlvalue: rlvalue.cpp
	$(CC) $(FLAGS) rlvalue.cpp -o rlvalue

copy: copy.cpp
	$(CC) $(FLAGS) copy.cpp -o copy

clean:
	rm -rf shared_ptr rlvalue copy *.o
