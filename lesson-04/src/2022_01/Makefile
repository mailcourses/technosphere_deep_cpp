CC=g++-11
FLAGS=-Wall -pedantic -Wextra -Werror -std=c++20
#FLAGS=-Wall -pedantic -Werror -std=c++20

all: class enum profiler pod virtual operator_new

class: class.cpp
	$(CC) $(FLAGS) class.cpp -o class

enum: enum.cpp
	$(CC) $(FLAGS) enum.cpp -o enum

profiler: profiler.cpp
	$(CC) $(FLAGS) profiler.cpp -o profiler

pod: pod.cpp
	$(CC) $(FLAGS) pod.cpp -o pod

virtual: virtual.cpp
	$(CC) $(FLAGS) virtual.cpp -o virtual

operator_new: operator_new.cpp
	$(CC) $(FLAGS) operator_new.cpp -o operator_new

clean:
	rm -rf class enum profiler pod virtual operator_new *.o
