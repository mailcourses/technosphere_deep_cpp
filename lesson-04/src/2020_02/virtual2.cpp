#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "A()" << std::endl;
        arr = new int[100];
    }
    virtual ~A() {
        std::cout << "~A()" << std::endl;
        delete[] arr;
    }
private:
    int *arr;
};

class B : public A
{
public:
    B()
    {
        std::cout << "B()" << std::endl;
        arr2 = new int[200];
    }
    ~B()
    {
        std::cout << "~B()" << std::endl;
        delete[] arr2;
    }
private:
    int *arr2;
};

int main()
{
    A *b = new B();
    delete b;
}
