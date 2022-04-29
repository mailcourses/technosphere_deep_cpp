#pragma once

#include <iostream>

namespace my
{

template<float N>
void foo()
{
    std::cout << "my::foo N = " << N << std::endl;
}

template<typename T>
class vector
{
public:
    vector(size_t capacity) : data_(new T[capacity]), capacity_(capacity)
    {
        std::cout << "vector ctr" << std::endl;
    }

    void push_back(const T& elem);

    ~vector()
    {
        std::cout << "vector dtor" << std::endl;
        delete[] data_;
    }
private:
    T* data_ = nullptr;
    size_t capacity_ = 0;
    size_t size_ = 0;
};

/*template<typename T>
void vector<T>::push_back(const T& elem)
{
    data_[size_++] = elem;
}*/

#include "vector.tpp"

} // namespace my
