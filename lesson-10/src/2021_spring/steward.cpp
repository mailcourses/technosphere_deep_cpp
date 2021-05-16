#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>

using Forks = std::pair<size_t, size_t>;

class Steward
{
public:
    Steward() = default;
    Steward(size_t max_pholosophers_cnt) : max_pholosophers_cnt_(max_pholosophers_cnt),
                                           busyForks_(max_pholosophers_cnt, false) {}

    Forks getForks(size_t i);
    void returnForks(Forks fork);
    Forks getPhilospherFork(size_t ph_i);
private:
    size_t max_pholosophers_cnt_;
    std::vector<bool> busyForks_;
    std::mutex mutex_;
    std::condition_variable cv_;
};

Forks
Steward::getForks(size_t ph_i) {
    Forks ph_forks = getPhilospherFork( ph_i );

    std::unique_lock<std::mutex> lock(mutex_);

    while (busyForks_[ph_forks.first] || busyForks_[ph_forks.second]) {
        std::cout << "Philosopher #" << ph_i << " is waiting..." << std::endl;
        cv_.wait(lock);
    }

    // Вилки свободны
    busyForks_[ph_forks.first] = true;
    busyForks_[ph_forks.second] = true;
    return ph_forks;
}

void
Steward::returnForks(Forks fork) {
    std::lock_guard<std::mutex> lock(mutex_);
    busyForks_[fork.first] = false;
    busyForks_[fork.second] = false;

    std::cout << "Philosopher #" << fork.first << " finished..." << std::endl;
    cv_.notify_all();
}

Forks
Steward::getPhilospherFork(size_t ph_i)
{
    return std::make_pair(ph_i, (ph_i + 1) % max_pholosophers_cnt_);
}

int main()
{
    size_t max_pholosophers_cnt = 10;
    std::vector<std::thread> philosophers;
    Steward steward(max_pholosophers_cnt);
    for (size_t i = 0; i < max_pholosophers_cnt; ++i) {
        philosophers.emplace_back([i, &steward]() {
            Forks forks = steward.getForks(i);
            std::cout << "Philosopher #" << i << " is eating..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            steward.returnForks(forks);
        });
    }

    for (size_t i = 0; i < max_pholosophers_cnt; ++i) {
        philosophers[i].join();
    }
}
