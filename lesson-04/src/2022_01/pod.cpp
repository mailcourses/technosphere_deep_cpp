#include <iostream>
#include <type_traits>

class Cat
{
public:
    int m1;
};

class Bat
{
public:
    int m1;
    Cat m2;
};

class Rat : public Bat
{
private:
    int m3 = 0;
};

struct S
{
    int32_t m1;
    double m2;
    int32_t m3;
};

struct S1
{
    double m2;
    int32_t m1;
    int32_t m3;
};

int main()
{
    std::cout << "Is Cat type is POD: " << std::is_standard_layout<Cat>::value << std::endl;
    std::cout << "Is Bat type is POD: " << std::is_standard_layout<Bat>::value << std::endl;
    std::cout << "Is Rat type is POD: " << std::is_standard_layout<Rat>::value << std::endl;

    std::cout << "sizeof(char): " <<  sizeof(char) << std::endl;
    std::cout << "sizeof(double): " << sizeof(double) << std::endl;
    std::cout << "sizeof(S): " << sizeof(S) << std::endl;
    std::cout << "sizeof(S1): " << sizeof(S1) << std::endl;
}
