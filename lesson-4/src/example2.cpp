#include <iostream>

class A
{
public:
    A() { std::cout << "A()" << std::endl; }
    ~A() { std::cout << "~A()" << std::endl; }
    int x_;
    void foo(int ) {}
};

class B : public A
{
public:
    B() { std::cout << "B()" << std::endl; }
    ~B() { std::cout << "~B()" << std::endl; }
    void foo() const
    {
        std::cout << "foo()" << std::endl;
        y_ = 10;
    //...
    }
    mutable int y_;
};

int main()
{
    const B b;
    b.foo();
}
