#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> arr;
    for (size_t i = 0; i < 100; ++i)
    {
        arr.push_back(i+1);
    }

    //
    {
        auto comp = [](int i) { return i % 5 == 0; };
        auto it = std::find_if(std::begin(arr), std::end(arr), comp);
        std::cout << "value=" << *it << std::endl;
    }
    // ... или так
    {
        auto it = std::find_if(std::begin(arr), std::end(arr), [](int x) { return x % 5 == 0; });
        std::cout << "value=" << *it << std::endl;
    }

    std::cout << "Array size=" << arr.size() << std::endl;
    {
        int a = 200;
        auto comp = [&arr,a](std::vector<int> *arr2) mutable {
            std::cout << "a=" << a << ", array size=" << arr2->size() << std::endl;
            a = 1;
            arr2->push_back(a);
            arr.push_back(a);
        };
        comp(&arr);
        std::cout << "Array size=" << arr.size() << ", a=" << a << std::endl;
    }
}

class A
{
    void inc() const
    {
        i += 10;
    }
    mutable int i = 0;
};
