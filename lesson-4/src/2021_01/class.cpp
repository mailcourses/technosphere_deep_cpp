#include <iostream>


class Cat
{
public:
    Cat(uint8_t age, std::string &name, Cat *parent) : parent_(parent), name_(name) {
        age_ = age;
        if (parent) {
            name_ += "son";
        }
        if (age_ < 2) {
            name_ += " jr.";
        }
    }
private:
    uint8_t age_;
    std::string &name_;
    Cat *parent_;
};

int main()
{
    std::string cat_name("phantomas");
    std::cout << cat_name << std::endl;
    Cat phantomas(10, cat_name, nullptr);
    cat_name = "felix";
    Cat felix(1, cat_name, &phantomas);
    std::cout << "After " << cat_name << std::endl;
}
