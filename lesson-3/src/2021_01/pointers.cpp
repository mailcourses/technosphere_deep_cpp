#include <iostream>

int main()
{
    int a = 10;
    const int *p1 = &a;
    int * const p2 = &a;
    std::cout << "1) a=" << a << std::endl;
    *p2 = 20;
    int b = 30;
    p1 = &b;
    std::cout << "2) a=" << a << std::endl;
}
