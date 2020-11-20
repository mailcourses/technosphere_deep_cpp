## Домашнее задание №7

Написать свой контейнер Vector аналогичный std::vector, аллокатор и итератор произвольного доступа для него.

Из поддерживаемых методов достаточно:
- operator[]
- push_back
- pop_back
- emplace_back
- empty
- size
- clear
- begin, rbegin
- end, rend
- resize
- reserve
- capacity

Интерфейс аллокатора и итератора смотрите в [документации](https://en.cppreference.com/w/).

Примера итератора, который итерирует последовательность по четным числам:
```c++
#include <iostream>
#include <set>
#include <vector>

template <class Iter>
class OddIterator
    : public std::iterator<std::forward_iterator_tag, typename Iter::value_type>
{
    Iter current_;
    Iter end_;

    void findNext()
    {
        while (current_ != end_)
        {
            if (*current_ % 2 == 0)
                return;
            ++current_;
        }
    }

public:
    OddIterator(Iter&& begin, Iter&& end)
        : current_(std::move(begin))
        , end_(std::move(end))
    {
        findNext();
    }

    bool operator==(const OddIterator& other) const
    {
        return current_ == other.current_;
    }

    bool operator!=(const OddIterator& other) const
    {
        return !(*this == other);
    }

    void operator++()
    {
        if (current_ != end_)
        {
            ++current_;
            findNext();
        }
    }

    int operator*() const
    {
        return *current_;
    }
};

template <class Container>
OddIterator<typename Container::const_iterator> getBegin(const Container& data)
{
    return OddIterator<typename Container::const_iterator>(data.cbegin(), data.cend());
}

template <class Container>
OddIterator<typename Container::const_iterator> getEnd(const Container& data)
{
    return OddIterator<typename Container::const_iterator>(data.cend(), data.cend());
}

int main()
{
    std::vector<int> data1 = { 9, 8, 1, 3, 4, 5, 6 };
    std::for_each(getBegin(data1), getEnd(data1), [](int x) { std::cout << x << '\n'; });

    std::cout << '\n';

    std::set<int> data2(data1.begin(), data1.end());
    std::for_each(getBegin(data2), getEnd(data2), [](int x) { std::cout << x << '\n'; });

    return 0;
}
```
