#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>
#include <algorithm>
#include <shared_mutex>
#include <unordered_map>

template<typename K, typename V>
class ThreadSafeCache
{
public:
    ThreadSafeCache() = default;
    void Put(K key, V value);
    void Erase(K key);
    bool Find(K key);
private:
    std::unordered_map<K, V> cache_;
    std::shared_mutex mutex_;
};

template<typename K, typename V>
void ThreadSafeCache<K, V>::Put(K key, V value)
{
    std::cout << "PUT " << key << std::endl;
    std::unique_lock<std::shared_mutex> lock(mutex_);
    cache_[key] = value;
}

template<typename K, typename V>
void ThreadSafeCache<K, V>::Erase(K key)
{
    std::cout << "ERASE " << key << std::endl;
    std::unique_lock<std::shared_mutex> lock(mutex_);
    cache_.erase(key);
}

template<typename K, typename V>
bool ThreadSafeCache<K, V>::Find(K key)
{
    std::cout << "Find " << key << std::endl;
    std::shared_lock<std::shared_mutex> lock(mutex_);
    auto it = cache_.find(key);
    if (it == cache_.end()) {
        return false;
    }
    std::cout << "Find value=" << it->second << " by key=" << key << std::endl;
    return true;
}

int main()
{
    ThreadSafeCache<char, std::string> cache;
    constexpr size_t max_threads = 100;
    std::vector<std::thread> threads;
    std::vector<char> actions = {'+', '-', '?'};
    std::vector<char> keys = {'a', 'b', 'c', 'd', 'e'};
    for (size_t i = 0; i < max_threads; ++i) {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(std::begin(actions), std::end(actions), rd);
        std::shuffle(std::begin(keys), std::end(keys), rd);

        char action = actions.front();
        char key = keys.front();

        threads.push_back( std::thread([&cache, action, key](){
            if (action == '+') {
                cache.Put(key, std::string("Random"));
            } else if (action == '-') {
                cache.Erase(key);
            } else if (action == '?') {
                cache.Find(key);
            }
        }) );
    }

    for (auto &thread : threads ) {
        thread.join();
    }
}
