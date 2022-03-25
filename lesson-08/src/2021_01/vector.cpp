#include <iostream>
#include <vector>

struct HeavyImage
{
    HeavyImage(int w, int h, std::string data) : w_(w)
    {
        std::cout << "HeavyImage(int, int, std::string), w_=" << w_ << std::endl;
    }

    HeavyImage(const HeavyImage& rhs) {
        w_ = rhs.w_;
        std::cout << "HeavyImage(const HeavyImage & rhs), w=" << w_ << std::endl;
    }

    HeavyImage& operator=(const HeavyImage& rhs)
    {
        w_ = rhs.w_;
        std::cout << "HeavyImage operator=(const HeavyImage & rhs)" << std::endl;
        return *this;
    }

    HeavyImage& operator=(HeavyImage&& rhs) noexcept
    {
        std::cout << "HeavyImage operator=(const HeavyImage && rhs)" << std::endl;
        return *this;
    }
    int w_;
};

int main()
{

    {
        std::vector<HeavyImage> hi;
        hi.reserve(2);
        hi.push_back( HeavyImage(10, 20, std::string("hello, world") ) );
        //std::cout << "capacity hi=" << hi.capacity() << std::endl;
        hi.emplace_back(20, 20, std::string("hello, world"));
    }

    std::vector<int> arr = {1,2,3,4};
    {
        std::vector<int>::iterator start = arr.begin();
        std::vector<int>::iterator end = arr.end();
        while (start != end) {
            std::cout << *start++ << ", ";
        }
        std::cout << std::endl;
    }

    {
        auto start = arr.rbegin();
        auto end = arr.rend();
        while (start != end) {
            std::cout << *start++ << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}
