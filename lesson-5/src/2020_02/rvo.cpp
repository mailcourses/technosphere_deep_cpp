#include <iostream>

class Server
{
public:
    Server(int port) : port_(port)
    {
        std::cout << "Server(port)" << std::endl;
    }
    Server(const Server& copied)
    {
        std::cout << "Server(Server)" << std::endl;
    }
    Server& operator=(const Server& copied)
    {
        std::cout << "Server operator=" << std::endl;
    }
    void changePort() { port_ = 10; }
private:
    int port_;
};

Server foo(int port)
{
    Server res(port);
    res.changePort();
    return res;
}

int main()
{
    Server s = foo(123);
    return 0;
}
