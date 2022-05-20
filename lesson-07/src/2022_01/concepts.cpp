#include <iostream>

struct A
{
    void foo() {}
    friend std::ostream& operator<<(std::ostream &out, const A&a);
    int order = 66;
};

std::ostream& operator<<(std::ostream &out, const A&a)
{
    out << "A=" << a.order;
    return out;
}

struct B
{
};

struct C
{
    int foo() { return 1; }
};

template<typename T>
concept ConceptName =
    requires (T t) {
        { t.foo() } -> std::same_as<void>;
        { std::cout << t };
    };

template<ConceptName T>
void foo()
{
    std::cout << "Called with concept type" << std::endl;
}

template<typename T>
void foo()
{
    std::cout << "Called without concept type" << std::endl;
}

namespace my
{
template<typename T>
concept is_pod = std::is_standard_layout<T>::value && std::is_trivial<T>::value;
}

int main()
{
    foo<A>();
    foo<B>();
    foo<C>();
    std::cout << my::is_pod<A> << std::endl;
    return 0;
}
