#include <iostream>

struct A
{
    mutable int x = 10;
};

void foo(const A& a)
{
    a.x = 20;
}

void boo(const std::string &str)
{
    str.size();
}

int main()
{
    A a1;
    foo(a1);
    foo(A());
    std::string s1("Hello");
    boo(s1);
    boo(std::string("world"));
    return 0;
}
