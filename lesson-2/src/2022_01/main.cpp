#include <iostream>

int main(int argc, char **argv, char **env)
{
    std::cout << "Arguments count: " << argc << std::endl;
    for (size_t i = 0; i < argc; ++i) {
        std::cout << "argument #" << i+1 << ": " << argv[i] << std::endl;
    }

    for (size_t i = 0; i < 1000; ++i) {
        std::cout << "env #" << i << ": " << env[i] << std::endl;
    }

    return 0;
}
