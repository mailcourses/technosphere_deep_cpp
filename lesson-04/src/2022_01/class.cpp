#include<iostream>

class Cat
{
//private:
public:
    Cat() { std::cout << "Cat constructor" << std::endl; }
    Cat(const std::string & name)
    {
        name_ = name;
        std::cout << "Cat constructor" << std::endl;
    }
    ~Cat() { std::cout << "Cat destructor" << std::endl; }
    void bark()
    {
        name_ += "dog";
    }
public:
    // Количество лет.
    int age = 4;
private:
    std::string name_;
};

struct Dog
{
    Dog() { std::cout << "Dog constructor" << std::endl; }
    ~Dog() { std::cout << "Dog destructor" << std::endl; }
//public:
    int age = 10;
};

class LittleCat : public Cat
{
};

int main()
{
    Cat cat;
 //   Cat cat2("phantomas");
    Dog dog;
    cat.bark();
    std::cout << "Age of cat: " << cat.age << std::endl;
    std::cout << "Age of dog: " << dog.age << std::endl;
    LittleCat cat_jr;
    std::cout << cat_jr.age << std::endl;
}
