#include <iostream>
#include <mutex>
#include <thread>
#include <queue>
#include <chrono>

struct Client {
    size_t id;
    Client(size_t id) : id(id) {}
};

std::queue<Client> clients;

class Barber
{
public:
    Barber() = default;
    ~Barber() = default;
    void Work();
    bool Push(Client client);
    void Trim(Client c)
    {
        std::cout << "Client #" << c.id << " is trimming..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Client #" << c.id << " finished." << std::endl;
    }
private:
    size_t max_chairs_ = 3;
    std::mutex mutex_;
    std::condition_variable busy_;
};

void Barber::Work()
{
    while( true )
    {
        std::unique_lock<std::mutex> lock(mutex_);
        if (clients.empty())
        {
            std::cout << "Barber is sleeping" << std::endl;
            busy_.wait(lock);
            std::cout << "Barber woke up" << std::endl;
        }

        Client c = clients.front();
        clients.pop();
        Trim(c);
    }
}

bool Barber::Push(Client client)
{
    std::unique_lock<std::mutex> lock(mutex_);
    if (clients.size() == max_chairs_) {
        std::cout << "Client# " << client.id << " is going away..." << std::endl;
        return false;
    }
    std::cout << "Client# " << client.id << " is pushing to queue..." << std::endl;
    clients.push(client);
    busy_.notify_all();
    return true;
}

int main()
{
    size_t max_client_cnt = 10;
    Barber barber;
    std::vector<std::thread> clients;
    clients.emplace_back(std::thread([&barber](){
        barber.Work();
    }));
    for (size_t i = 0; i < max_client_cnt; ++i)
    {
        Client client(i);
        clients.emplace_back(std::thread([client, &barber](){
            barber.Push(client);
        }));
    }
    for (auto &client : clients)
    {
        client.join();
    }
}
