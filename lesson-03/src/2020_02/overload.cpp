#include <iostream>

void foo(int)
{
    std::cout << "foo(int)" << std::endl;
}


void foo(bool)
{
    std::cout << "foo(bool)" << std::endl;
}

void foo(const std::string &)
{
    std::cout << "foo(std::string)" << std::endl;
}

int main()
{
    foo(1); // 1 -> foo(int)
    foo(true); // 2 -> foo(bool)
    //foo(1.1); // 3 -> foo(int)? не скомпилируется, так как два подходящих вариант.
    foo("Hello"); //4 -> foo(std::string)? на самом деле bool.
}
