#include <iostream>
#include <memory>

struct A
{
    int x = 10;
};

namespace my
{

class shared_ptr2;

struct V
{
    friend class shared_ptr2;
    int x = 10;
private:
    void foo(shared_ptr2 &obj);
};

// shared_ptr должен быть шаблонным, но пока так.
using T = A;

class shared_ptr2
{
    friend class shared_ptr;
    friend class V;
    T *obj_;
public:
    void foo(V &v)
    {
        v.foo(*this);
    }
};

class shared_ptr
{
   friend class shared_ptr2;
public:
    shared_ptr() : counter_(new uint64_t(0)) {};

    shared_ptr(T *new_obj) : obj_(new_obj), counter_(new uint64_t(1)) {}

    shared_ptr(const shared_ptr2 & other)
    {
        obj_ = other.obj_; // <-- ошибка, если shared_ptr2 не был бы дружным.
    }

    shared_ptr(const shared_ptr & other)
    {
        //this->obj_ = other.obj_;
        std::cout << "copy ctr" << std::endl;
        obj_ = other.obj_; // <-- ошибки не будет
        (*other.counter_) += 1;
        counter_ = other.counter_;
    }

    shared_ptr(shared_ptr && other) : obj_(other.obj_), counter_(other.counter_)
    {
        std::cout << "move ctr" << std::endl;
        other.obj_ = nullptr;
        other.counter_ = nullptr;
    }

    shared_ptr& operator=(const shared_ptr &other)
    {
        std::cout << "operator=" << std::endl;
        if (this == &other) {
            return *this;
        }
        cleanup();
        obj_ = other.obj_;
        (*other.counter_) += 1;
        counter_ = other.counter_;
        return *this;
    }

    shared_ptr& operator=(shared_ptr&& other)
    {
        std::cout << "move operator=" << std::endl;
        if (this == &other) {
            return *this;
        }
        obj_ = other.obj_;
        counter_ = other.counter_;
        other.obj_ = nullptr;
        other.counter_ = nullptr;
        return *this;
    }

    ~shared_ptr()
    {
        std::cout << "~shared_ptr counter_ " << std::endl;
        cleanup();
    }

private:
    void cleanup()
    {
        // Во время демонстрации была Segmentation fault.
        // Потому что при move мы занулили counter_, а в
        // std::cout ниже пытались разыменовать указатель counter_.
        if (counter_ == nullptr) {
            std::cout << "empty counter_" << std::endl;
            return;
        }
        std::cout << "[cleanup] current counter size = " << *counter_ << std::endl;
        --(*counter_);
        if (*counter_ == 0) {
            delete obj_;
            delete counter_;
            std::cout << "[cleanup] deleting heap memory" << std::endl;
        }
    }

    // shared_ptr ptr1;
    // ptr1 << std::cout;
    // std::cout << ptr1;
    //friend std::ostream& operator<<(std::ostream &ostream, const shared_ptr &ptr);
private:
    T *obj_ = nullptr;
    uint64_t *counter_ = nullptr;
};

// Если бы объявили внутри определения класса V,
// то словили бы:
// error: invalid use of incomplete type ‘class my::shared_ptr2’
void
V::foo(shared_ptr2 &obj)
{
    obj.obj_ = nullptr;
}

}; // namespace my

int main()
{
    my::shared_ptr ptr3(new A);
    ptr3 = ptr3;
    {
        // ctr(T *) (/)
        my::shared_ptr ptr1(new A);
        // ctr(const T&) (/)
        my::shared_ptr ptr2 = ptr1;
        // operator=(const T&) (/)
        ptr3 = ptr2;
    }

    my::shared_ptr ptr4;
    // operator=(T&&) (/)
    ptr4 = std::move(ptr3);

    std::shared_ptr<A> ptr2(new A);
    return 0;
}

/*
Пример представления чисел в длинной арифметике:
119
11
[9|1|1]
+
[1|1]
-------
[0|3|1]
*/
