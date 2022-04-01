CC=g++-11
FLAGS=-Wall -pedantic -Wextra -Werror

all: namespace lambda

namespace: namespace.cpp
	$(CC) $(FLAGS) namespace.cpp -o namespace

lambda: lambda.cpp
	$(CC) $(FLAGS) lambda.cpp -o lambda

clean:
	rm -rf namespace *.o
