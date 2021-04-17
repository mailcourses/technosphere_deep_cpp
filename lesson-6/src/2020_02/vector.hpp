#pragma once

#include <iostream>

template<class T>
class MyVector
{
private:
    T *data_;
public:
    void push_back(T);
};

void foo();
/*
Первый способ - реализация внутри *.hpp
template<class T>
void MyVector<T>::push_back(T )
{
}

void foo()
{
    std::cout << "foo" << std::endl;
}
*/

/*
Второй способ -- с помощью include
#include "vector.tpp"
*/

