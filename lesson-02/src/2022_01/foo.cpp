#include <iostream>

static int i = 10;

void foo(int a)
{
    int k = 1;
    if (a > 10) {
        static int j;// = a;
        static bool b;
        std::cout << "j: " << j << ", k: " << k << std::endl;
        j += 1;
        std::cout << "our bool var: " << b << std::endl;
    }
    std::cout << "i: " << i << std::endl;
    k += 1;
    i += 1;
}

int main()
{
    for (size_t a = 0; a < 10; ++a) {
        foo(100);
    }
    std::cout << "i: " << i << std::endl;
}
