#include <iostream>

struct Base
{
    Base() { std::cout << "Base()" << std::endl; }
    virtual void boo()
    {
        std::cout << "Base::boo" << std::endl;
    }
    virtual void foo(const std::string& str) {
        std::cout << "Base::foo " << str << std::endl;
        boo();
    }
    virtual ~Base() { std::cout << "~Base()" << std::endl; }
};

struct Derived : Base
{
    Derived() { std::cout << "Derived()" << std::endl; }
    //virtual void foo(const std::string& str) override
    virtual void boo() override
    {
        std::cout << "Derived::boo " << std::endl;
    }
    virtual ~Derived() { std::cout << "~Derived()" << std::endl; }
};

int main()
{
    Derived d1;
    Base b1 = d1;
    b1.boo();

    Derived *d = new Derived();
    Base *b = d;
    std::string str("message");
    d->foo(str);//"tmp message");
    std::cout << "sizeof(Base)=" << sizeof(Base) << std::endl;
    std::cout << "sizeof(Derived)=" << sizeof(Derived) << std::endl;
    delete b;
    delete d;
}
