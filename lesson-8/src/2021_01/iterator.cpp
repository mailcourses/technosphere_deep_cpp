#include <iterator>
#include <iostream>
#include <random>
#include <algorithm>

template <class T>
class Iterator
    : public std::iterator<std::forward_iterator_tag, T>
{
private:
    T* ptr_;
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;
public:
    explicit Iterator(T* ptr)
        : ptr_(ptr)
    {
    }

    bool operator==(const Iterator<T>& other) const
    {
        return ptr_ == other.ptr_;
    }

    bool operator!=(const Iterator<T>& other) const
    {
        return !(*this == other);
    }

    difference_type operator-(const Iterator<T>& other) const
    {
        return std::distance(ptr_, other.ptr_);
    }

    reference operator*() const
    {
        return *ptr_;
    }

    Iterator& operator++()
    {
        ++ptr_;
        return *this;
    }
};

template <class T, size_t N>
class Array
{
    T data_[N];
public:
    using iterator = Iterator<T>;
public:
    Array( std::initializer_list<T> init )
    {
        auto current = init.begin();
        const auto end = init.end();
        for (size_t i = 0; current != end; ++i)
        {
            data_[i] = *current++;
        }
    }

    iterator begin() noexcept
    {
        return iterator(data_);
    }

    iterator end() noexcept
    {
        return iterator(data_ + N);
    }
};

int main()
{
    Array<int, 5> arr = { 1, 2, 3, 4, 5};

    int sum = std::accumulate(std::begin(arr), std::end(arr), 0);
    std::cout << "Sum of array is " << sum << std::endl;

    // Не будет работать, требуется random access iterator.
    {
        /*
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(std::begin(arr), std::end(arr), g);
        */
    }

    for (auto i : arr) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    Array<int, 5>::iterator it = arr.begin();
    while (it != arr.end()) {
        ++(*it);
        ++it;
    }

    for (auto i : arr) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    return 0;
}
