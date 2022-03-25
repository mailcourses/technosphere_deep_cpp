#include <iostream>
#include <vector>
#include <map>

template<class Container, class Index>
auto executeContainer(Container &c, Index i) -> decltype(c[i])
{
    // Ещё что-то делаем.
    return c[i];
}

struct SuperPuperStruct
{
    std::string operator[](size_t idx)
    {
        return std::string("Super");
    }
};

template<typename X, typename Y>
auto boo(int a, int b) -> decltype(std::declval<X>() + std::declval<Y>())
{
    X x(a);
    Y y(b);
    return x + y;
}

int main()
{
    std::vector<int> v1(10, 5);
    std::cout << executeContainer(v1, 3) << std::endl;

    std::map<std::string, int> m1 = {{"hello", 1}, {"world", 2}};
    std::cout << executeContainer(m1, "hello") << std::endl;

    SuperPuperStruct sps;
    std::cout << executeContainer(sps, 4) << std::endl;


    std::cout << boo<double, int>(10, 20) << std::endl;
    return 0;
}
