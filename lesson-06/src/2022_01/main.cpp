#include "vector.hpp"

struct SuperStruct
{
};

int main()
{
    {
        my::vector<int32_t> vec(100);
        for (size_t i = 0; i < 10; ++i)
        {
            vec.push_back(i);
        }
    }

    {
        my::vector<std::string> vec(100);
        vec.push_back(std::string("dummy string"));
    }

    {
        my::vector<SuperStruct> vec(100);
        vec.push_back(SuperStruct());
    }
    constexpr float f = 10.0;
    my::foo<f>();
}
