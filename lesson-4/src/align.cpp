#include <iostream>

struct A
{
    char a;
    double b;
};

int main()
{
    std::cout << sizeof(char) << std::endl;
    std::cout << sizeof(int64_t) << std::endl;
    std::cout << sizeof(double) << std::endl;
    std::cout << sizeof(A) << std::endl;

    std::cout << "=====" << "\n";
    std::cout << offsetof(A, a) << std::endl;
    std::cout << offsetof(A, b) << std::endl;
}
