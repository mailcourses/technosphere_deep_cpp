#include <iostream>
#include <mutex>
#include <vector>
#include <thread>
#include <chrono>
#include <queue>

struct Client
{
    size_t id;
    explicit Client(size_t id) : id(id) {}
};

std::queue<Client> clients_queue;

struct Barber
{
    void Work();
    void Trim(Client c);
    void Push(Client c);

    size_t chairs_cnt_ = 3;
    std::mutex mutex_;
    std::condition_variable cv_;
};

void
Barber::Work()
{
    while (true) {
        std::unique_lock<std::mutex> lock(mutex_);
        while (clients_queue.empty())
        {
            std::cout << "Barber is sleeping..." << std::endl;
            cv_.wait(lock);
            std::cout << "Barber woke up..." << std::endl;
        }
        Client c = clients_queue.front();
        clients_queue.pop();
        lock.unlock();
        Trim(c);
    }
}

void
Barber::Trim(Client c)
{
    std::cout << "Starting to trim client #" << c.id << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Finished to trim client #" << c.id << std::endl;
}

void
Barber::Push(Client c)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (clients_queue.size() == chairs_cnt_) {
        std::cout << "Client #" << c.id << " is going away..." << std::endl;
        return;
    }

    std::cout << "Client #" << c.id << " is pushing to queue" << std::endl;
    clients_queue.push( c );
    cv_.notify_one();
}

int main()
{
    std::vector<std::thread> clients;
    constexpr size_t max_client_cnt = 10;
    Barber barber;
    clients.push_back(std::thread([&barber]() {
        barber.Work();
    }));

    for (size_t i = 0; i < max_client_cnt; ++i) {
        Client client(i);
        clients.push_back(std::thread([client, &barber]() {
            barber.Push(client);
        }));
    }

    for (auto &client : clients) {
        client.join();
    }
}
