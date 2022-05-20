#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    {
        std::vector<int> v { 0, 2, 3, 25, 5 };
        std::vector<int> t { 3, 19, 10, 2 };
        auto result = std::find_first_of(v.begin(), v.end(), t.begin(),
        t.end());
        if (result == v.end())
            std::cout << "no matches found\n";
        else
            std::cout << "found a match at "
                << std::distance(v.begin(), result) << "\n";
    }

    {
        std::vector<int> v1 { -3, 2, 3, 4 };
        std::for_each(v1.begin(), v1.end(), [](int &x) { x *= x; });
        for (auto el : v1) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }

    {
        std::string str = "Text with   spaces";
        std::string output;
        std::remove_copy(str.begin(), str.end(), std::back_inserter(output), ' ');
        std::cout << "Output: [" << output << std::endl;
    }
}
