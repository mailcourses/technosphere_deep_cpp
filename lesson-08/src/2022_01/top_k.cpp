#include <iostream>
#include <queue>
#include <vector>

int main()
{
    constexpr int32_t k = 3;
    std::vector<int32_t> arr = {1, 3, 2, 9, 6, 7, 5};
    std::vector<int32_t> arr1 = arr;
    //std::sort(arr.begin(), arr.end(), [](int a, int b) { return a > b; } );
    // O(n logn)  -> O(n log K)
    std::sort(arr.begin(), arr.end(), std::greater<int>() );

    for (size_t i = 0; i < k; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    std::priority_queue<int32_t, std::vector<int32_t>, std::greater<int>> q;
    for (size_t i = 0; i < arr1.size(); ++i) {
        q.push(arr1[i]);
        if (q.size() > k) {
            q.pop();
        }
    }

    while (!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << std::endl;
    return 0;
}
