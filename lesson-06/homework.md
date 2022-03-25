## Домашнее задание №5

Простой сериализатор поддерживающий два типа: uint64_t и bool.

```c++
struct Data
{
    uint64_t a;
    bool b;
    uint64_t c;
};

Data x { 1, true, 2 };

std::stringstream stream;

Serializer serializer(stream);
serializer.save(x);

Data y { 0, false, 0 };

Deserializer deserializer(stream);
const Error err = deserializer.load(y);

assert(err == Error::NoError);

assert(x.a == y.a);
assert(x.b == y.b);
assert(x.c == y.c);
```

Сериализовать в текстовый вид с разделением пробелом, bool сериализуется как true и false

##### Подсказки по реализации

```c++
struct Data
{
    uint64_t a;
    bool b;
    uint64_t c;

    template <class Serializer>
    Error serialize(Serializer& serializer)
    {
        return serializer(a, b, c);
    }
};
```

```c++
// serializer.h
#pragma once

enum class Error
{
    NoError,
    CorruptedArchive
};

class Serializer
{
    static constexpr char Separator = ' ';
public:
    explicit Serializer(std::ostream& out)
        : out_(out)
    {
    }

    template <class T>
    Error save(T& object)
    {
        return object.serialize(*this);
    }

    template <class... ArgsT>
    Error operator()(ArgsT... args)
    {
        return process(args...);
    }
    Error process(bool &&arg);
    Error process(uint64_t &&arg);
private:
    // process использует variadic templates
};
```

Deserializer реализуется аналогично Serializer, только принимает std::istream, а не std::ostream

Пример десериализации bool:

```c++
Error load(bool& value)
{
    std::string text;
    in_ >> text;

    if (text == "true")
        value = true;
    else if (text == "false")
        value = false;
    else
        return Error::CorruptedArchive;

    return Error::NoError;
}
```
