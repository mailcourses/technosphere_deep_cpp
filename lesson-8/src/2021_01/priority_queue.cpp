#include <queue>
#include <vector>
#include <iostream>

int main()
{
    int k = 3;
    std::vector<int> arr = {1, 8, 5, 6, 0, 9, 7};

    // O(n log n)
    std::sort(std::rbegin(arr), std::rend(arr));
    //std::sort(arr.begin(), arr.end());
    for (size_t i = 0; i < k; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;

    // O(n log n) -> O(n log k)
    std::priority_queue<int, std::vector<int>, std::greater<int>> q1;
    for (int item : arr) {
        q1.push(item);
        if (q1.size() > k) {
            q1.pop();
        }
    }
    for (size_t i = 0; i < k && !q1.empty(); ++i) {
        std::cout << q1.top() << ", ";
        q1.pop();
    }
    std::cout << std::endl;

    //https://en.cppreference.com/w/cpp/container/priority_queue/priority_queue
    std::vector<int> vec={3, 1, 4, 1, 5};
    std::priority_queue<int> c3(std::less<int>(), vec);
    std::cout << c3.size() << '\n';

    return 0;
}
