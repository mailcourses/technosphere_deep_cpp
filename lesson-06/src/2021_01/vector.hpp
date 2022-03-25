template<typename T>
class Vector
{
public:
    Vector();
    void push_back(T elem);
private:
    T* data_;
};

/*
Второй способ.

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

*/

// Третий способ.
#include "vector.tpp"
