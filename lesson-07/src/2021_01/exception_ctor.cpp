#include <iostream>

struct Searcher
{
    Searcher() : buffer(new char[1024])
    {
        std::cout << "Searcher()" << std::endl;
        try {
            connect();
        }
        catch(...) {}
    }

    // 1-ый подход
    void init()
    {
        connect();
    }

    void connect()
    {
        // ...
        throw std::exception();
    }

    ~Searcher()
    {
        std::cout << "~Searcher()" << std::endl;
        delete[] buffer;
    }
    char *buffer;
};

int main()
{
    try {
        Searcher searcher;
        searcher.init();
    }
    catch(...)
    {
        //..
    }
    return 0;
}
