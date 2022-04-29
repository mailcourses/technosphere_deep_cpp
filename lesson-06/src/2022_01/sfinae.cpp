#include <iostream>

struct A
{
    void foo()
    {
    }
};

struct B
{

};

struct C
{
    int foo()
    {
        return 0;
    }
};

/*
std::is_same<int, int>::value == true
std::is_same<int, double>::value == false
*/

template<typename T, typename U>
struct is_same
{
    static const bool value = false;
};

template<typename T>
struct is_same<T, T>
{
    static const bool value = true;
};

template<typename T>
struct HasFoo
{
private:
    static int check(...);

    template<typename U>
    static auto check(U *u) -> decltype(u->foo());

    template<typename U>
    static auto check(U u) -> decltype(u.foo());
public:
    static const bool value = is_same<void, decltype(check(static_cast<T*>(nullptr)))>::value;
    //static const bool value = is_same<void, decltype(check(T()))>::value;
};

int main()
{
    std::cout << std::boolalpha;
    std::cout << HasFoo<A>::value << std::endl;
    std::cout << HasFoo<B>::value << std::endl;
    std::cout << HasFoo<C>::value << std::endl;
    return 0;
}
