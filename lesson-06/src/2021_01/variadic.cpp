#include <iostream>

template <class T>
void print(T&& val)
{
    std::cout << val << '\n';
}

template <class T, class... Args>
void print(T&& val, Args&&... args)
{
     std::cout << "1) " << val << '\n';
     print(std::forward<Args>(args)...);
}

template <int, class... Args>
void print(const int& val, Args&&... args)
{
     std::cout << "2) " << val << '\n';
     print(std::forward<Args>(args)...);
}

int main()
{
    const int a = 10;
    print(1, "abc", 2.5, a);
}
