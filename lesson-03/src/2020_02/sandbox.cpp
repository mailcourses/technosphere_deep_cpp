#include <iostream>
#include <ctype.h>

int main()
{
    std::cout << std::isspace(' ') << std::endl;
    std::cout << std::isspace('\r') << std::endl;
    std::cout << std::isspace('\t') << std::endl;
    std::cout << std::isspace('\n') << std::endl;
    std::cout << std::isspace('1') << std::endl;
}
