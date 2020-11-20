#include <iostream>

template<class T>
class Less
{
public:
    Less(T x) : x_(x) {}
    bool operator()(const T& x)
    {
        return x < x_;
    }
private:
    T x_;
};

int main()
{
    Less lessThan3(3);
    std::cout << lessThan3(5) << std::endl;
    std::cout << lessThan3(2) << std::endl;
}
