CC=g++-11
FLAGS=-std=c++20 -Wall -pedantic -Wextra -Werror

all: main func sfinae

main: vector.tpp vector.hpp main.cpp
	$(CC) $(FLAGS) main.cpp -o vector

func: func.cpp
	$(CC) $(FLAGS) func.cpp -o func

sfinae: sfinae.cpp
	$(CC) $(FLAGS) sfinae.cpp -o sfinae

clean:
	rm -rf vector func sfinae *.o
