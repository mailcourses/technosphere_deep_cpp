#include <iostream>

struct A
{
    A(int val) { x = val; }
    int x;
};

int main()
{
    A a(10);// a.x = 10;
    A b(20); // b.x = 20;
    a = b;
    std::cout << a.x << std::endl;
}
