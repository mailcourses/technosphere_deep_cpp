#include <iostream>

struct Logger
{
    void log(const std::string & message)
    {
        std::cout << "[2021-04-02 18:52:10][INFO] " << message << std::endl;
    }
};

class Endpoint
{
public:
    void send_query(const std::string &query) const;
private:
    mutable Logger logger;
};

void
Endpoint::send_query(const std::string &query) const
{
    std::cout << "sending query [" << query << "]" << std::endl;
    // const Logger logger;
    this->logger.log(query);
}

int main()
{
    const Endpoint endpoint;
    endpoint.send_query("q=cat phantomas");
}
