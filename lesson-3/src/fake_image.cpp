#include <iostream>
#include <functional>

// Фейковый тип.
class FakeImageObject
{
    public:
        FakeImageObject() {}
};

using HandlerFunc = std::function<void(FakeImageObject &)>;

void ResizeImage(FakeImageObject &obj)
{
    //....
    std::cout << "ResizeImage" << std::endl;
}

int main()
{
    int max_size = 100;
    auto ApplySepia = [max_size](FakeImageObject & obj) {
        // ... using max_size;
        std::cout << "ApplySepia for max_size" << max_size << std::endl;
    };
    std::vector<HandlerFunc> conv = {
        ResizeImage,
        ApplySepia,
    };
    FakeImageObject image;
    for (auto stage : conv)
    {
        stage( image );
    }
}
