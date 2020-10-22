#include <iostream>

class A
{
public:
    void foo() { std::cout << "A::foo" << std::endl; }
    void boo() { std::cout << "A::boo, x=" << this->x << std::endl; }
private:
    int x = 10;
};

int main()
{
    A *a = nullptr;
    // Всё ок!
    a->foo();
    // Segmentation fault
    a->boo();
}
