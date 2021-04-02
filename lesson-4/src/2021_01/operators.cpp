#include <iostream>

class Vector
{
public:
    int a;
    int b;
    int c;
    Vector()
    {
        data_ = new int[3];
    }
    Vector(int x) : a(x), b(x), c(x) {}

    Vector& operator=(const Vector& other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] data_;
        data_ = new int[3];
        for (size_t i = 0; i < 3; ++i) {
            data_[i] = other.data_[i];
        }
        return *this;
    }
/*
    Vector& operator+(const Vector& other)
    {
        this->a = this->a + other.a;
        this->b = this->b + other.b;
        this->c = this->c + other.c;
        return *this;
    }
*/

    ~Vector()
    {
        std::cout << "~Vector()" << std::endl;
        delete[] data_;
    }
private:
    int *data_;
};

int main()
{
    Vector v1, v2;
    //Vector v3 = v1 + v2;
    std::cout << v1.a << std::endl;
    {
        Vector v3;
        v3 = v1 + v2;
    }
    std::cout << v1.a << std::endl;
}

