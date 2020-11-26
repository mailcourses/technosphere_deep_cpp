## Домашнее задание №8

Реализовать пул потоков со следующим интерфейсом:

```c++
class ThreadPool
{
public:
    explicit ThreadPool(size_t poolSize);

     // pass arguments by value
    template <class Func, class... Args>
    auto exec(Func func, Args... args) -> std::future<decltype(func(args...))>;
};
```

Использование пула потоков:

```c++
struct A {};

void foo(const A&) {}

ThreadPool pool(8);

auto task1 = pool.exec(foo, A());
task1.get();

auto task2 = pool.exec([]() { return 1; });
task2.get();
```
