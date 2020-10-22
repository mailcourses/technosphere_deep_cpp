#include <iostream>

class A
{
public:
    A() {}
    void foo() { std::cout << "A::foo()" << std::endl; }
};

class B : public A
{
public:
    B() {}
    void foo() { std::cout << "B::foo()" << std::endl; }
};

class Device
{
public:
    Device() {}
    virtual void write(const std::string &str) = 0;
    /*{
        std::cout << "Device::write()" << std::endl;
    }*/
};

class Console : public Device
{
public:
    virtual void write(const std::string &str) override {
        std::cout << "Console::write()" << std::endl;
    }
};

class Printer : public Device
{
public:
    virtual void write(const std::string &str) override {
        std::cout << "Printer::write()" << std::endl;
    }
};

int main()
{
    B *b = new B();
    b->foo(); // B:foo
    A *a = b;
    a->foo(); // A::foo
    std::cout << "Device size=" << sizeof(Device) << std::endl;
    Device *d[] = { new Console(), new Printer };
    for (size_t i = 0; i < 2; ++i) {
        d[i]->write("Hello");
    }
    Device dev;
}
