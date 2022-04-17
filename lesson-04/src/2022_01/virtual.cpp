#include <iostream>

class Printer
{
public:
    virtual void foo() = 0;
    virtual void print() = 0;
};

class Logger : public Printer
{
public:
    virtual void foo()
    {
        std::cout << "A::foo()" << std::endl;
    }

    virtual void boo(int /*i*/)
    {
        std::cout << "A::boo()" << std::endl;
    }

    virtual void moo() final
    {
        std::cout << "A::boo()" << std::endl;
    }

    virtual void print() override
    {
        std::cout << "A::print()" << std::endl;
    }

    virtual ~Logger() { std::cout << "~Logger()" << std::endl; }
};

class Device : public Logger
{
public:
    virtual void foo()
    {
        std::cout << "B::foo()" << std::endl;
        boo(10);
    }

    virtual void boo(int /*i*/) override
    {
        std::cout << "B::boo()" << std::endl;
    }

    virtual ~Device() { std::cout << "~Device()" << std::endl; }
};

void printer(Printer *ptr)
{
    ptr->foo();
    ptr->print();
}

int main()
{
    Logger *a = new Logger;
    Device *b = new Device;
    a->foo();
    b->foo();
    std::cout << "======" << std::endl;
    printer(a);
    printer(b);

    delete b;
    delete a;

    std::cout << "======" << std::endl;

    Logger *c = new Device;
    c->foo();

    delete c;

    std::cout << "======" << std::endl;

}
