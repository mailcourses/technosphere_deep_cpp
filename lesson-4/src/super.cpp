#include <iostream>

class Super
{
public:
    Super(size_t size, int val) : size_(size)
    {
        buffer_ = new int[size];
        for(size_t i = 0; i < size_; ++i) {
            buffer_[i] = val;
        }
    }
    ~Super()
    {
        delete[] buffer_;
    }
    Super operator+(int other) {
        Super tmp(size_, 0);
        for (size_t i = 0; i < size_; ++i) {
            tmp.buffer_[i] = buffer_[i] + other;
        }
        return tmp;
    }
    Super operator+(const Super &other)
    {
        Super tmp(size_, 0);
        for (size_t i = 0; i < size_; ++i) {
            tmp.buffer_[i] = buffer_[i] + other.buffer_[i];
        }
        return tmp;
    }
    friend std::ostream& operator<<(std::ostream& ostream, const Super& super);
private:
    int *buffer_;
    size_t size_;
};

std::ostream& operator<<(std::ostream& ostream, const Super& super)
{
    for (size_t i = 0; i < super.size_; ++i)
    {
        ostream << super.buffer_[i] << " ";
    }
    return ostream;
}

int main()
{
    size_t max_size = 10;
    Super s1(max_size, 2);
    Super s2(max_size, 9);
    /*s1 + s2;*/
    Super s3 = s1 + 5;
    Super s4 = s1 + s3;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;
}
