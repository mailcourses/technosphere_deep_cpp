CC=g++-11
FLAGS=-std=c++20 -Wall -pedantic -Wextra -Werror
TEST_LIBS=-lgtest_main -lgtest -lpthread

.PHONY: test clean

all: main test_bin

main: fake.o main.cpp
	$(CC) $(FLAGS) fake.o main.cpp -o main

fake.o: fake.cpp fake.hpp
	$(CC) $(FLAGS) fake.cpp -c

test_bin: fake.o test.cpp
	$(CC) $(FLAGS) fake.o test.cpp -o test_bin $(TEST_LIBS)

test:
	./test_bin

clean:
	rm -f *.o main test_bin

