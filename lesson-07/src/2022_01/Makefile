CC=g++-11
FLAGS=-std=c++20 -Wall -pedantic -Wextra -Werror

all: concepts exception_ctr

concepts: concepts.cpp
	$(CC) $(FLAGS) concepts.cpp -o concepts

exception_ctr: exception_ctr.cpp
	$(CC) $(FLAGS) exception_ctr.cpp -o exception_ctr

clean:
	rm -rf concepts exception_ctr *.o
