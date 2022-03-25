#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

using map_t = std::unordered_map<std::string, std::unordered_map< int, std::vector<int> > >;
typedef std::unordered_map<std::string, std::unordered_map<int, std::vector<int>>> map2_t;

#define MAP_T std::unordered_map<std::string, std::unordered_map< int, std::vector<int> > >

namespace mystd
{
class string
{
    public:
        string()
        {
            std::cout << "string!" << std::endl;
        }
};
}

int main()
{
    mystd::string str;
    MAP_T mymap;
}
