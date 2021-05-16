#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <vector>

using Fork = std::pair<size_t, size_t>;

class Steward
{
public:
    Steward() = delete;
    Steward(size_t max_philosophers_cnt) : max_philosophers_cnt_(max_philosophers_cnt), busyForks_(max_philosophers_cnt, false) {}
    ~Steward() = default;
    Fork getForks(size_t philosopher_id)
    {
        Fork ph_fork = getPhilospherFork(philosopher_id);

        std::unique_lock<std::mutex> lock(mutex_);

        while (busyForks_[ph_fork.first] || busyForks_[ph_fork.second])
        {
            std::cout << "Philosopher#" << philosopher_id << " is waiting" << std::endl;
            forksAreBack_.wait(lock);
        }
        busyForks_[ph_fork.first] = true;
        busyForks_[ph_fork.second] = true;
        return ph_fork;
    }

    void returnForks(Fork fork)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        busyForks_[fork.first] = false;
        busyForks_[fork.second] = false;
        std::cout << "Philosopher#" << fork.first << " returned forks" << std::endl;
        forksAreBack_.notify_all();
    }

    Fork getPhilospherFork(size_t philosopher_id)
    {
        return std::make_pair( philosopher_id, (philosopher_id + 1) % max_philosophers_cnt_ );
    }
private:
    size_t max_philosophers_cnt_ = 0;
    std::vector<bool> busyForks_;
    std::mutex mutex_;
    std::condition_variable forksAreBack_;
};

int main()
{
    size_t max_philosophers_cnt = 10;
    Steward steward(max_philosophers_cnt);
    std::vector<std::thread> philosophers;
    for (size_t i = 0; i < max_philosophers_cnt; ++i)
    {
        philosophers.emplace_back(std::thread([i, &steward]() {
            Fork ph_fork = steward.getForks(i);
            // кушает;
            std::cout << "Philosopher#" << i << " is eating" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            steward.returnForks(ph_fork);
        }));
    }
    for (std::thread & philosopher : philosophers) {
        philosopher.join();
    }
}
