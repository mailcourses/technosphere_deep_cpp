#include <iostream>

void foo(const int& /*value*/)
{
    std::cout << "foo(const int&)" << std::endl;
}
/*
void foo(int&&)
{
    std::cout << "foo(int&&)" << std::endl;
}*/
void foo(int& /*value*/)
{
    std::cout << "foo(int&)" << std::endl;
}

int main()
{
    foo(0);
    return 0;
}
