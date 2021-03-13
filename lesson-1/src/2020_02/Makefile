CC = g++
FLAGS = -std=c++17 -Wall
EXEC = my_prog

all: $(EXEC)

my_prog: main.o square.o
	$(CC) $(FLAGS) main.o square.o -o $(EXEC)
main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp
square.o: square.cpp
	$(CC) $(FLAGS) -c square.cpp
clean:
	rm *.o $(EXEC)
