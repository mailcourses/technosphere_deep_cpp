#include <iostream>

#define PI 3.1415
#define MAX(x, y) ( x > y ? x : y )
#define MULT(x, y) (x) * (y)

int main()
{
    #line 100
    std::cout << PI << ", " << __LINE__ << std::endl;


    std::cout << "MAX cases" << std::endl;
    int a = 4;
    std::cout << MAX(++a, 0) << std::endl;
    std::cout << MAX(++a, 10) << std::endl;

    std::cout << "MULT(1+2, 3+4)" << std::endl;
    std::cout << MULT(1+2, 3+4) << std::endl;
    #ifndef __cplusplus
    #error "There is no cpp"
    #endif
    return 0;
}

