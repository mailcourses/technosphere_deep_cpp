#include <iostream>
#include <memory>

int main()
{
    int *i = new int;
    *i = 10;

    std::cout << "1) i = " << *i << std::endl;

    std::unique_ptr<int> uptr(new int);
    //std::unique_ptr<int> uptr2(i);
    std::cout << "2) uptr = " << *uptr.get() << std::endl;
    *i += 100;
    std::cout << "3) i = " << *i << std::endl;
    delete i;
    std::cout << "4) uptr = " << *uptr.get() << std::endl;
    // std::unique_ptr<int> uptr2 = uptr; <-- не компилируется

    std::string *str = new std::string();
    std::shared_ptr<std::string> sptr(str);
    std::shared_ptr<std::string> sptr1(new std::string());
    sptr1 = sptr;
    return 0;
}
