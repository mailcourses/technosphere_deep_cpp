#include <iostream>
#include <memory>

struct A
{
    A()
    {
        std::cout << "A ctr" << std::endl;
    }
    ~A()
    {
        std::cout << "~A dctr" << std::endl;
    }
};

using Data = A;

class Searcher
{
public:
    Searcher()
    {
        data_.reset(new Data);
        std::cout << "Searcher ctor" << std::endl;
        initialize();
    }
    ~Searcher()
    {
        std::cout << "~Searcher dctr" << std::endl;
        //delete data_;
    }

    void initialize()
    {
        throw std::string("Exception init");
    }

private:
    std::unique_ptr<Data> data_;
};

int main()
{
    Searcher searcher;
}
