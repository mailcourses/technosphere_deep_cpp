#include <iostream>
#include "fake.hpp"

const int very_magic_number = 100500;

int main()
{
    std::cout << fake::magic_int_method(5, 6) << std::endl;
    std::cout << fake::magic_str_method(very_magic_number) << std::endl;
    return 0;
}
