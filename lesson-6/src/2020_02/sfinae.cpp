#include <iostream>

struct A
{
    void foo() {}
};

struct B
{
};

struct C
{
    double foo() { return 1.0; }
};

template<typename T, typename Y>
struct IsSame
{
    static constexpr bool value = false;
};

template <typename T>
struct IsSame<T, T>
{
    static constexpr bool value = true;
};

template<typename T>
struct HasFoo
{
private:
    static int check(...);

    template<typename U>
    static auto check(U *u) -> decltype(u->foo());
public:
    static constexpr bool value = IsSame<void, decltype(HasFoo<T>::check((T*) nullptr))>::value; // true или false;
};

int main()
{
    std::cout << HasFoo<A>::value << std::endl;
    std::cout << HasFoo<B>::value << std::endl;
    std::cout << HasFoo<C>::value << std::endl;

    std::cout << IsSame<int, int>::value << std::endl;
    std::cout << IsSame<int, double>::value << std::endl;

}
