#include "fake.hpp"

namespace fake
{

int magic_int_method(int a, int b)
{
    return a + b;
}

std::string magic_str_method(int /*magic*/)
{
    return std::string("hello, world!");
}


} // namespace fake
