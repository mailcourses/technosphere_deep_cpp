#include <iostream>


void boo(char *ch)
{
    char &ch_ref = *ch;
    std::cout << "ch_ref: [" << ch_ref << "]" << std::endl;
}

int main()
{
    char *ch = nullptr;
    boo(nullptr);
    return 0;
}
