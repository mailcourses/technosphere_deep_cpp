#include <iostream>
#include <limits>

enum Color {
    RED,// = std::numeric_limits<uint64_t>::max(),
    YELLOW,
    BLACK,
    WHITE
};

enum class HttpError {
    NotFound = 404,
    OK = 200,
    Empty = 201,
    NotModified,
};

int main()
{
    Color c = YELLOW;
    //int RED = 20;
    HttpError error = HttpError::NotModified;
    //... Очень сложная логика
    if (error == HttpError::OK) {
        std::cout << "OK" << std::endl;
    }

    std::cout << "c: " << c << std::endl;
 //   std::cout << "error: " << error << std::endl;
    if (c == BLACK) {
        std::cout << "BLACK colour" << std::endl;
    }
    //...
    switch(c) {
        case RED:
            std::cout << "RED" << std::endl;
            break;
        case YELLOW:
            std::cout << "YELLOW" << std::endl;
            break;
        case BLACK:
            std::cout << "BLACK" << std::endl;
            break;
        default:
            std::cout << "default" << std::endl;
    }
}
