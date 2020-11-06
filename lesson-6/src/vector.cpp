#include <iostream>
#include "vector.hpp"


template<class T>
void MyVector<T>::push_back(T /*elem*/)
{
}

void foo()
{
    std::cout << "foo" << std::endl;
}

template class MyVector<int>;
template class MyVector<std::string>;
