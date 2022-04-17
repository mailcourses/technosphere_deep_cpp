#include <iostream>
#include <new>

void* operator new(size_t sz)
{
    std::cout << "Global operator new" << std::endl;
    void *ptr = malloc(sz);
    return ptr;
}

struct Cat
{
    Cat()
    {
        std::cout << "Cat constructor" << std::endl;
    }

    ~Cat()
    {
        std::cout << "Cat destructor" << std::endl;
    }

    void* operator new(size_t sz)
    {
        std::cout << "Cat operator new" << std::endl;
        void *ptr = ::operator new(sz);
        return ptr;
    }

    void operator delete(void *ptr)
    {
        std::cout << "Cat operator delete" << std::endl;
        free(ptr);
    }
};

int main()
{
    Cat *cat = new Cat;
    delete cat;

    char *ch = new char;
    delete ch;
}

