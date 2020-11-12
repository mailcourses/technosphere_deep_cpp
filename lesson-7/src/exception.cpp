#include <iostream>

struct A
{
    int i;
    A(int i) : i(i) { std::cout << "A(" << i << ")\n"; }
    ~A() { std::cout << "~A(" << i << ")" << std::endl;; }
};

struct Error
{
};

struct FileError : Error
{
};

int foo()
{
    try {
        A a(3);
        throw FileError();
    }
    catch (const Error &ex)
    {
        std::cerr << "Error catch" << std::endl;
        throw;
    }
}

int bar()
{
    A a(1);
    try {
        A a(2);
        foo();
    }
    catch (const FileError &ex)
    {
        std::cerr << "FileError handler" << std::endl;
    }
    catch (...)
    {
        std::cerr << "elipsis handler" << std::endl;
    }
}

int main()
{
    bar();
}
