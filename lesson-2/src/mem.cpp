#include <iostream>

int main()
{
    int64_t i = 1;
    int64_t *pi = new int64_t;

    /*
        int32_t, int64_t
        uint32_t, uint64_t
    */
    std::cout << std::hex << static_cast<int64_t *>(&i) << std::endl;
    std::cout << std::hex << static_cast<int64_t *>(pi) << std::endl;
    std::cout << std::hex << (int64_t *)main << std::endl;
    // ... или
    std::cout << std::hex << reinterpret_cast<void*>(main) << std::endl;

    std::cin.get();

    return 0;
}

