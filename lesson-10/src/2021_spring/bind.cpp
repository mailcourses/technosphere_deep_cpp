#include <iostream>
#include <functional>
#include <queue>

void foo(int a, float b, std::string & str)
{
    std::cout << "a=" << a << ", b=" << b << ", str=" << str << std::endl;
    str += ".suffix";
}

void boo(int a=10, int b=20)
{
    std::cout << "boo::a=" << a << ", b=" << b << std::endl;
}

int main()
{
    std::queue<std::function<void()>> q;
    boo(1);
    std::string str("Hello, Peter");
    auto goo = std::bind(foo, std::placeholders::_1, std::placeholders::_2, std::ref(str));
    foo(1, 2.0f, str);
    std::cout << "After foo str=" << str << std::endl;
    goo(11, 3.0f);
    std::cout << "After goo str=" << str << std::endl;
    auto moo = std::bind(goo, 30, -1.f);
    q.push(moo);
    moo();
    auto func = q.front();
    func();
    std::cout << "After moo str=" << str << std::endl;
    return 0;
}
