#include <iostream>
#include <string_view>
#include <source_location>
#include <type_traits>


struct POD
{
    int x;    // 4
    double y; // 8
    int z;    // 4
};

class A
{
public:
    A()
    {
        std::cout << "A()" << std::endl;
    }
};

class Profiler
{
public:
    Profiler(const std::string &func_name,
             const std::source_location &location=std::source_location::current()) : func_name_(func_name), location_(location) {}
    ~Profiler()
    {
        std::cout << func_name_ << " takes " << std::endl;
        std::cout << location_.file_name() << " takes " << location_.function_name() << std::endl;
    }
private:
    std::string func_name_;
    std::source_location location_;
};

int square(int x)
{
    Profiler prf(__func__);
    return x*x;
}

void *operator new(size_t size)
{
    std::cout << "My own new operator" << std::endl;
    void *ptr = malloc(size);
    return ptr;
}

struct Cat
{
    Cat() {
        std::cout << "Cat constructor" << std::endl;
    }
    /*void *operator new(size_t size) {
        std::cout << "Cat own new operator" << std::endl;
        void *ptr = ::operator new(size);
        return ptr;
    }*/
    ~Cat() {}
    int a{10};
private:
    int b;
};

struct Bat
{
    int a;
    double c;
};

struct Rat
{
public:
    Bat m1;
    int m2;
    Rat *m3;
    static double m4;
private:
    void f() {}
};

int main()
{
    Profiler prf(__func__);
    std::string *str = static_cast<std::string *>(malloc(sizeof(std::string)));
    new (str) std::string();
    //std::string *str2 = new std::string();
    Cat *cat = new Cat;
    //str->push_back('c');
    //call std::string::string("Hello, world") on *str;
    std::cout << *str << std::endl;
    square(4);

    std::cout << sizeof(POD) << std::endl; // 24

    A a1;
    A a2 = A();
    std::string str3("Hahaha");
    Cat cat1;
    Cat cat2;
    cat1 = cat2;
    Cat cat3(cat1);
    std::cout << "Cat is pod: " << std::is_pod<Cat>::value << std::endl;
    std::cout << "Bat is pod: " << std::is_pod<Bat>::value << std::endl;
    std::cout << "Rat is pod: " << std::is_pod<Rat>::value << std::endl;
}
