#include <iostream>


template<typename X, typename Y>
auto boo(X x, Y y) -> decltype(x+y)
{
    return x + y;
}

template<typename X, typename Y>
auto moo(X x, Y y) -> decltype(x+y)
{
    if (x < 10) {
        return x;
    }
    return x + y;
}

constexpr int sum(int a, int b)
{
    return a + b;
}

void func() {
    // значение переменной будет посчитано на этапе компиляции.
    constexpr int c = sum(5, 12);
    std::cout << "c: " << c << std::endl;
}

auto foo(int x, int y) -> decltype(x)
{
    return sum(x, y);
}

int main()
{
    std::cout << foo(2, 5) << std::endl;

    std::cout << boo(2, 5.5) << std::endl;
    std::cout << boo(2.5, 5) << std::endl;
    /*
    decltype(boo(2.5, 5)) var1 = 1;
    decltype(boo('c', 'a')) var2 = 'd';
    */

    std::cout << "moo: " << moo(2, 5.5) << std::endl;

    func();
    return 0;
}
