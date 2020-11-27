#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <mutex>
#include <chrono>

std::atomic<size_t> gValue = 5;
std::mutex m;
std::mutex m_odd;
std::timed_mutex t_m;

void foo(size_t i)
{
    if (i % 2 == 0) {
        std::lock_guard<std::mutex> guard(m);
        gValue.store(i);
        std::cout << "Thread#" << i << ", gValue=" << gValue.load() << std::endl;
    } else {
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        auto period = std::chrono::milliseconds(100);
        if (t_m.try_lock_for(period))
        {
            gValue.store(i);
            std::cout << "Thread#" << i << ", gValue=" << gValue.load() << std::endl;
        } else {
            std::cout << "Failed to wait timed mutex for thread#" << i << std::endl;
        }
        // ... очень длинный код
        // m.unlock(); // забыли написать.
    }
}

int main()
{
    std::vector<std::thread> pool;
    std::cout << "Optimal thread cnt=" << std::thread::hardware_concurrency() << std::endl;
    for (size_t i = 0; i < 10; ++i) {
        std::thread t(foo, i+1);
        pool.push_back(std::move(t));
    }

    for (size_t i = 0; i < pool.size(); ++i) {
        pool[i].join();
    }
}
