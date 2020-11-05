#include <iostream>
#include <memory>


class String
{
public:
    String();
    // String s1;
    // String s2 = s1;
    String(const String &other);
    // String s1;
    // String s2 = std::move(s1);
    String(String&& other);

    // String s1, s2;
    // s1 = std::move(s2);
    String& operator=(const String& copied)/* = delete Если не хотите, чтобы компилятор генерировал оператор*/;
    String& operator=(String&& copied)/* = delete Если не хотите, чтобы компилятор генерировал оператор*/;
    // String s1, s2;
    // s1 = s2;
    ~String() { delete[] data_;};
public:
    int value = 0;
private:
    size_t size_ = 0;
    char *data_ = nullptr;
};

const size_t MAX_LENGHT = 100;

String::String() : size_(MAX_LENGHT)
{
    data_ = new char[size_];
    value = 5;
}

String::String(const String &other) : size_(other.size_), value(other.value)
{
    std::cout << "Copy constructor" << std::endl;
    data_ = new char[size_];
    std::copy(data_, data_ + size_, other.data_);
}

String::String(String&& other) : size_(std::move(other.size_)), value(std::move(other.value))
{
    std::cout << "Move constructor" << std::endl;
    data_ = other.data_;
    other.data_ = nullptr;
    other.size_ = 0;
    other.value = -1;
}

String&
String::operator=(const String& copied)
{
    std::cout << "Copy operator=" << std::endl;
    if (this == &copied)
    {
        return *this;
    }
    size_ = copied.size_;
    char *tmp = new char[size_];
    delete[] data_;
    data_ = tmp;
    value = copied.value;
    std::copy(data_, data_ + size_, copied.data_);
}

String&
String::operator=(String&& moved)
{
    std::cout << "Move operator=" << std::endl;
    if (this == &moved)
    {
        return *this;
    }
    size_ = std::move(moved.size_);
    data_ = moved.data_;
    value = std::move(moved.value);
    moved.data_ = nullptr;
    moved.size_ = 0;
    moved.value = -1;
}

int main()
{
    String s1;
    String s2;
    /*
    std::vector<String> words;
    ...
    words[from] = words[to];
    */
    s1 = s2;
    s2.value = 10;
    String s3 = s2;
    String s4 = std::move(s3);
    String s5;
    s5 = std::move(s4);
    std::cout << "s1.value=" << s1.value << std::endl;
    std::cout << "s2.value=" << s2.value << std::endl;
    std::cout << "s3.value=" << s3.value << std::endl;
    std::cout << "s4.value=" << s4.value << std::endl;
    std::cout << "s5.value=" << s5.value << std::endl;


    // Пример запрета копирования.
    std::unique_ptr<String> up1(new String());
    // Нельзя копировать!
    //std::unique_ptr<String> up2 = up1;
}

