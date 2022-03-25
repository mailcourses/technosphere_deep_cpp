// example.cpp
#include <iostream>

#define NAME(world) #world

int main(int argc, char **argv)
{
    #line 100
    std::cout << "Hello, " << NAME(ugly world) << " from "
              << __FILE__ << " and line #" << __LINE__
              << std::endl;
    return 0;
}
