#include <iostream>

struct Karasik
{
    Karasik() { std::cout << "Karasik()" << std::endl; }
    ~Karasik() { std::cout << "~Karasik()" << std::endl; }
    void foo() { std::cout << "foo()" << std::endl; }
};

template<class T>
class my_shared_ptr
{
private:
    struct Data
    {
        T* obj_;
        uint32_t counter_;
        Data(T* obj, uint32_t counter) : obj_(obj), counter_(counter) {}
    };
public:
    my_shared_ptr() = default;
    my_shared_ptr(T *obj) : data(new Data(obj, 1)) {}
    my_shared_ptr(const my_shared_ptr &rhs)
    {
        data = rhs.data;
        ++data->counter_;
    }
    my_shared_ptr& operator=(const my_shared_ptr& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        release();
        data = rhs.data;
        ++data->counter_;

    }
    ~my_shared_ptr()
    {
        release();
    }
    T* operator->() { return data->obj_; }
    const T* operator->() const { return data->obj_; }
private:
    void release()
    {
        --data->counter_;
        if (data->counter_ == 0) {
            delete data->obj_;
        }
    }
private:
    Data *data;
};

int main()
{
    my_shared_ptr<Karasik> ptr(new Karasik());
    ptr = ptr;
    ptr->foo();
}
