#include <iostream>
#include <cstring>

class StrangeString
{
public:
    StrangeString()
    {
        std::cout << "Default constructor" << std::endl;
    }
    StrangeString(const char *data) : data_(new char[strlen(data)])
    {
        std::cout << "Default constructor (char *)" << std::endl;
        std::copy(data, data + strlen(data), data_);
    }

    // Конструктор и оператор копирования
    StrangeString(const StrangeString & other);
    StrangeString& operator=(const StrangeString & other);

    StrangeString(StrangeString && other);
    StrangeString& operator=(StrangeString && other);
    /*
        friend StrangeString operator+(StrangeString &lhs, StrangeString &rhs);
        lhs + rhs;

        StrangeString operator+(StrangeString &rhs)
        this + rhs
    */
    friend void foo(const StrangeString & other);
    /*String a;
    a.foo(b);
    */

    friend std::ostream& operator<<(std::ostream &out, const StrangeString& ss);

    /*
        StrangeString a;
        a << std::cout << std::endl;
        
        //std::cout << a << std::endl;
    */
    std::ostream& operator<<(std::ostream &out)
    {
        out << "StrangeString(" << data_ << ")";
        return out;
    }

    ~StrangeString() { delete[] data_; }
private:
    char *data_ = nullptr;
    size_t size_ = 0;
};

void foo(const StrangeString & other)
{
    std::cout << "Foo for " << other.data_ << std::endl;
}

std::ostream& operator<<(std::ostream &out, const StrangeString& ss)
{
    out << "StrangeString(" << ss.data_ << ")";
    return out;
}

StrangeString::StrangeString(const StrangeString & other) : data_(new char[other.size_]), size_(other.size_)
{
    std::cout << "Copy constructor" << std::endl;
    std::copy(other.data_, other.data_ + other.size_, data_);
}

StrangeString& StrangeString::operator=(const StrangeString & other)
{
    if (this == &other) {
        return *this;
    }

    char *tmp = new char[other.size_];
    delete[] data_;
    data_ = tmp;
    size_ = other.size_;
    std::copy(other.data_, other.data_ + other.size_, data_);

    std::cout << "Copy operator=" << std::endl;
    return *this;
}

StrangeString::StrangeString(StrangeString && other) : data_(other.data_), size_(other.size_)
{
    std::cout << "Move constructor" << std::endl;
    other.data_ = nullptr;
    other.size_ = 0;
}

StrangeString& StrangeString::operator=(StrangeString && other)
{
    std::cout << "Move operator=" << std::endl;
    if (this == &other) {
        return *this;
    }

    delete[] data_;

    data_ = other.data_;
    size_ = other.size_;

    other.data_ = nullptr;
    other.size_ = 0;

}

StrangeString makeString(const char *data)
{
    StrangeString tmp(data);
    std::cout << "makeString(" << tmp << ")" << std::endl;
    return tmp;
}

int main()
{

    StrangeString abc = makeString("Hello");

    std::cout << "==== Start main from here ====" << std::endl;
    StrangeString a; // default конструктор
    StrangeString b = a; // конструктор копирования
    StrangeString c = StrangeString("abcd"); // конструктор принимающий char * без оператора копирования
    c << std::cout << std::endl;
    std::cout << c << std::endl;
    foo(c);
    c = b; // оператор копирования
    b = b;
    StrangeString d =  std::move(c); // конструктор перемещения
    c = std::move(c);
    c = std::move(d); // оператор перемещения
}
