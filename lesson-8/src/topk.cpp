#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void top_k(const std::vector<int> &v, int k, std::vector<int> &res)
{
    // O(n log n)
    /*std::vector<int> tmp = v;
    std::sort(tmp.begin(), tmp.end());
    for (size_t i = 0; i < k; ++i)
    {
        res.push_back(tmp[i]);
    }
    */
    // O(n log k)
    std::priority_queue<int> pq;
    for (size_t i = 0; i < v.size(); ++i)
    {
        pq.push(v[i]);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    for (size_t i = 0; i < k; ++i)
    {
        res.push_back(pq.top());
        pq.pop();
    }
    std::reverse(res.begin(), res.end());
}

int main()
{
    // ..
    int k = 3;
    std::vector<int> v1 = {9, 2, 5, 0, 3, 10, 4, 20};

    std::vector<int> res;
    res.reserve(k);

    top_k(v1, k, res);
    for (auto elem : res) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;
    return 0;
}
