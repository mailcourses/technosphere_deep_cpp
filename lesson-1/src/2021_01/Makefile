CC=g++
FLAGS=-std=c++17 -Wall -Werror -fsanitize=address -Wextra
#FLAGS=-std=c++17 -Wall -Werror -Wextra

all: main.o square.o
	$(CC) $(FLAGS) main.o square.o -o main

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -c

square.o: square.hpp square.cpp
	$(CC) $(FLAGS) square.cpp -c

test: main.o square.o
	g++ -std=c++17 ... -o test
	./test

clean:
	rm -f *.o main
