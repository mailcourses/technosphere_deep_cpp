#include <iostream>

struct A
{
    void foo() {}
    int boo = 0;
};

struct B
{
    void boo() {}
};

template<typename T>
struct C
{
    T foo() {}
};

template<typename X, typename Y>
struct IsSame
{
    static constexpr bool value = false;
};

template<typename X>
struct IsSame<X, X>
{
    static constexpr bool value = true;
};

template<typename T>
struct HasFoo
{
private:
    struct FakeType {};
public:
    using ExpectedType = int;
    static constexpr bool value = IsSame<ExpectedType, decltype(HasFoo<T>::check((T*)nullptr))>::value;

    static FakeType check(...);

    template<typename U>
    static auto check(U *u) -> decltype(u->foo());
    //static auto check(U *u) -> decltype(u->boo);
};

int main()
{
    std::cout << HasFoo<A>::value << std::endl;
    std::cout << HasFoo<B>::value << std::endl;
    std::cout << HasFoo<C<int>>::value << std::endl; // int C::foo();
    std::cout << HasFoo<C<void>>::value << std::endl;// void C::foo();

    std::cout << "IsSame<int, int>=" << IsSame<int, int>::value << std::endl;
    std::cout << "IsSame<int, double>=" << IsSame<int, double>::value << std::endl;
    return 0;
}
