#include <iostream>
#include <memory>

/*
template<typename T>
class unique_ptr
{
public:
    unique_ptr(T* obj)
    {
        obj_ = obj;
    }
    ~unique_ptr()
    {
        delete obj_;
    }
...
private:
    T *obj_;
}
*/
int main()
{
    {
        int *a = new int(2);
        //int *tmp = new int(20);
        std::unique_ptr<int> ptr1(a);
        //Копирующий конструктор удалён! Не компилируется.
        //std::unique_ptr<int> ptr2 = ptr1;
        ptr1.reset(new int(5));
        std::cout << a << std::endl;
        //std::unique_ptr<int> ptr2(a);
        int *b = ptr1.get();
        std::cout << "ptr1=" << *ptr1 << std::endl;
        *b += 1;
        std::cout << "b=" << *b << std::endl;
        std::cout << "ptr1=" << *ptr1 << std::endl;
    }

    {
        std::shared_ptr<int> ptr1(new int(5));
        std::cout << "Counter=" << ptr1.use_count() << std::endl;
        {
            std::shared_ptr<int> ptr2 = ptr1;
            std::cout << "Counter1=" << ptr1.use_count() << std::endl;
            std::cout << "Counter2=" << ptr2.use_count() << std::endl;
        }
        std::cout << "Counter=" << ptr1.use_count() << std::endl;
    }
}
