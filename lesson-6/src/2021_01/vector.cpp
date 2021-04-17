#include "vector.hpp"

template<typename T>
Vector<T>::Vector()
{
    data_ = new T[10];
}

template<typename T>
void Vector<T>::push_back(T elem)
{
    data_[0] = elem;
}

/*
Первый способ, но не всегда рабочий.
template class Vector<int>;
template class Vector<float>;
*/
