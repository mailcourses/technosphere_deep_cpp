#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    std::vector<int32_t> v1;
    std::vector<int32_t> v2(10);
    // v2.size() == 10;
    // [][][][][][][][][][]
    std::vector<int32_t> v3(5, -1);
    // [-1][-1][-1][-1][-1]
    // 10 x 10
    std::vector< std::vector< int32_t > > dp(10, std::vector<int32_t>(10, -1));


    std::vector<int32_t> arr = {-1, 0, 1, 4, 5, 10};
    auto it_begin = arr.rbegin();
    auto it_end = arr.rend(); // std::end(arr);
    while (it_begin != it_end) {
        std::cout << *it_begin << std::endl;
        it_begin++;
    }

    size_t arr_size = arr.size();
    for(size_t i = 0; i < arr_size; ++i) {
        arr.push_back(arr[i]);
    }
}
