#include <chrono>
#include <iostream>
#include <string_view>
#include <source_location>

using duration_t = std::chrono::microseconds;

class Profiler
{
public:
    Profiler(const std::string &name) : another_func_ref(name), func_name(name), start_ts_( std::chrono::system_clock::now() )
    {
        std::cout << "Profiler constructor" << std::endl;
    }

    Profiler(const std::source_location &location = std::source_location::current()) : location_(location), another_func_ref(location_.function_name())

    {
        start_ts_ = std::chrono::system_clock::now();
        func_name = location.function_name();
    }

    ~Profiler()
    {
        auto end_ts = std::chrono::system_clock::now();
        uint64_t duration = std::chrono::duration_cast<duration_t>( end_ts - start_ts_ ).count();
        std::cout << "Function [" << func_name << "] from file [" << location_.file_name() << "] takes " << duration << " microseconds" << std::endl;
    }
private:
    std::source_location location_;
    const std::string another_func_ref;
    std::string func_name;
    std::chrono::time_point<std::chrono::system_clock> start_ts_;
};

class Weapon
{
public:
    void use() {}
};

class SuperHero
{
public:
    void power() const
    {
        health += 100;
        weapon.use();
    }
private:
    mutable int health = 100;
    mutable Weapon weapon;
};

void foo()
{
    Profiler prf;
    for (size_t i = 0; i < 1000000; ++i);
}

void boo()
{
    Profiler prf(__func__);
    for (size_t i = 0; i < 10000000; ++i);
    foo();
}

int main()
{
    boo();

    SuperHero batman;
    batman.power();
    const SuperHero superman;
    superman.power();
}
