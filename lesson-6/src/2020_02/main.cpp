#include "vector.hpp"

struct SuperPuperStruct
{
};

int main()
{
    foo();

    MyVector<int> v;
    v.push_back(10);

    MyVector<SuperPuperStruct> v2;
    v2.push_back(SuperPuperStruct());
}
