#include <iostream>
#include <functional>

using func_t = void (*)(int, double);

void foo(int i, double f)
{
    std::cout << "i=" << i << ", f=" << f << std::endl;
}

void (*boo())(int, double)
{
    return foo;
}

func_t boo2()
{
    return foo;
}

int main()
{
    void (*FuncPtr)(int, double) = foo;
    void (*FuncPtr2)(int, double);
    FuncPtr(10, 36.6);
    FuncPtr2 = boo();
    FuncPtr2(-1, 123.);
    // Используем func_t через using.
    func_t FuncPtr3;
    FuncPtr3 = boo2();
    FuncPtr3(0, 2);
    // Используем std::function.
    std::function<void(int, double)> func = foo;
    func(123, 0.0);
    return 0;
}
