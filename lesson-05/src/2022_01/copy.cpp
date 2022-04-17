#include <iostream>

class string
{
public:
    string() : size_(10), data_(new char[size_])
    {
        init();
    }
    explicit string(size_t size) : size_(size), data_(new char[size_])
    {
        std::cout << "ctr string(size_t)" << std::endl;
        init();
    }

    string(const string &rhs)
    {
        std::cout << "copy ctr string" << std::endl;
        size_ = rhs.size_;
    }

    string& operator=(const string& rhs)
    {
        if (this == &rhs) {
            return *this;
        }

        delete[] data_;
        data_ = new char[rhs.size_];
        size_ = rhs.size_;
        for (size_t i = 0; i < rhs.size_; ++i) {
            data_[i] = rhs.data_[i];
        }
        return *this;
    }

    ~string()
    {
        delete[] data_;
    }

    friend std::ostream& operator<<(std::ostream& ostream, const string &rhs);
private:
    void init()
    {
        for(size_t i = 0; i < size_; ++i) {
            data_[i] = 'a';
        }
    }
private:
    size_t size_ = 0;
    char *data_ = nullptr;
};

std::ostream& operator<<(std::ostream& ostream, const string &rhs)
{
    for(size_t i = 0; i < rhs.size_; ++i) {
        ostream << rhs.data_[i];
    }
    return ostream;
}

struct B
{
    int x = 10;
    B& operator=(const B& ) = delete;
};

struct C
{
    ~C() {}
    // C() {}
    // C& operator=(const C&) { return *this; }
    // C(const C&) {}
};

int main()
{
    string s1(100);
    string s2;
    std::cout << s1 << std::endl;
    s2 = s2;
    std::cout << s2 << std::endl;
    s2 = s1;
    std::cout << s2 << std::endl;
    string s3 = string(5);
    string s4(5);
    B b1, b2;
    //b1 = b2;
    B b3(b1);
    std::cout << s3 << std::endl;
    C c1, c2;
    c1 = c2;
    C c3(c1);
}
