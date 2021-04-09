#include <iostream>

int x = 0;

int& ref()
{
    return x;
}

int foo()
{
    return 3;
}

void foo(int &a)
{
    std::cout << "lvalue ref" << std::endl;
}

void foo(int &&a)
{
    std::cout << "rvalue ref" << std::endl;
}

int main()
{
    int a = 100500;
    foo(x); // lvalue?
    foo(ref()); // lvalue
    foo(a); // lvalue
    foo(1); // rvalue
    foo(std::move(a)); //rvalue
    foo(foo()); //rvalue
    int *b = &a;
    foo(*b);
}

