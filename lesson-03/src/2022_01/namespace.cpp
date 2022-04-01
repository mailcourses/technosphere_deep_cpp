#include <iostream>
#include <map>

namespace math {

#include "math.hpp"

}

using namespace std;

// foo.hpp
namespace foo
{
    void boo() { std::cout << "foo()" << std::endl; }
}

// Текущий файл.
void boo()
{
    std::cout << "global boo()" << std::endl;
}

/*struct string
{
};
*/

namespace A
{
    void moo1() {}
    void moo2() {}
}

namespace B
{
    //void moo() {}
}

using A::moo1;
using namespace B;

// C-style
typedef std::map<std::string, std::map<std::string, int>> map_t1;
// Modern C++-style
using map_t2 = std::map<std::string, std::map<std::string, int>>;

int main()
{
    moo1();
    std::string hello("Hello, world!");
    std::cout << hello << std::endl;

    string hello2("Hello, daschunds!");
    cout << hello2 << endl;

    {
        //using namespace foo;
        boo();
    }

    math::myCos(10.f);
    boo();
    return 0;
}

