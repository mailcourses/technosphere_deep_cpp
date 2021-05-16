#include <iostream>
#include <mutex>
#include <random>
#include <shared_mutex>
#include <thread>
#include <vector>
#include <algorithm>
#include <unordered_map>

template<class K, class V>
class ThreadSafeMap
{
public:
    ThreadSafeMap() = default;
    void Put(K key, V value)
    {
        std::cout << "PUT " << key << std::endl;
        std::unique_lock<std::shared_mutex> lock(mutex_);
        cache_[key] = value;
    }

    bool Get(K key, V &value)
    {
        std::cout << "GET " << key << std::endl;
        std::shared_lock<std::shared_mutex> lock(mutex_);
        auto it = cache_.find(key);
        if (it == cache_.end()) {
            return false;
        }
        value = cache_[key];
        return true;
    }

    void Erase(K key)
    {
        std::cout << "Erase " << key << std::endl;
        std::unique_lock<std::shared_mutex> lock(mutex_);
        auto it = cache_.find(key);
        if (it == cache_.end()) {
            return;
        }
        cache_.erase(key);
    }
private:
    std::unordered_map<K, V> cache_;
    std::shared_mutex mutex_;
};

int main()
{
    ThreadSafeMap<char, std::string> cache;
    size_t max_threads = 20;
    std::vector<std::thread> threads;
    std::vector<char> keys = { 'a', 'b', 'c', 'd' };
    std::vector<char> actions = {'+', '-', '?'};
    for (size_t k = 0; k < max_threads; ++k)
    {
        auto rng = std::default_random_engine {};
        std::shuffle(std::begin(actions), std::end(actions), rng);
        threads.emplace_back(std::thread([&cache, &keys, actions, k](){
            for (size_t i = 0; i < keys.size(); ++i) {
                size_t j = i % actions.size();
                if (actions[j] == '+') {
                    const std::string value = "Hello, world!";
                    cache.Put(keys[i], value);
                }
                else if (actions[j] == '-') {
                    cache.Erase(keys[i]);
                }
                else if (actions[j] == '?') {
                    std::string value;
                    cache.Get(keys[i], value);
                }
            }
        }));
    }
    for (auto & thread : threads) {
        thread.join();
    }
}
