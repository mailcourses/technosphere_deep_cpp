#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void foo(int) {
    return;
}

int main()
{
    int a = 10;
    int b = 20;
    std::cout << "Before a = " << a << ", b = " << b << std::endl;
    auto func = [=, &b]( const int &/*var*/) {
        b = 40;
    };
    func(b);
    std::cout << "After a = " << a << ", b = " << b << std::endl;

    std::vector<int> arr = {3, 4, 1, 5, 2, 6};
    std::sort(std::begin(arr), std::end(arr), [](int a, int b) { return a > b; });
    bool (*less)(int, int) = [](int a, int b) { return a < b; };

    std::sort(std::begin(arr), std::end(arr), less);
    for (auto el : arr) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    {
        std::function<void(int)> func;
        if (!func) {
            std::cout << "func is not set" << std::endl;
        } else {
            std::cout << "func is set" << std::endl;
        }
        try {
            func(10);
        } catch (std::bad_function_call &ex) {
            std::cout << "Catch std::bad_function_call exception" << std::endl;
        }
    }
    {
        std::function<void(int)> func(foo);
        if (!func) {
            std::cout << "func is not set" << std::endl;
        } else {
            std::cout << "func is set" << std::endl;
        }
    }

    return 0;
}
