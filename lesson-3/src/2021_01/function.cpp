#include <iostream>
#include <functional>
#include <vector>

using MoveFunction = std::function<void (int&, int &)>;

// Указатель на функцию.
typedef void(*FunctionPtr)(int &, int&);

// Простая функция.
void moveLeft(int &x, int &y)
{
    std::cout << "moveLeft(" << x << ", " << y << ")" << std::endl;
}

// Функтор.
class Functor
{
public:
    void operator()(int &, int &)
    {
        std::cout << "Functor::operator()" << std::endl;
    }
};

int main()
{
    // Лямбда.
    auto lamda_comp = [](int &x, int &y) {  std::cout << "lamda(x,y)" << std::endl; };

    FunctionPtr func_ptr = lamda_comp;

    std::vector<MoveFunction> directions = { lambda_comp, moveLeft, Functor() };
    directions.push_back( func_ptr );

    int x = 10, y = 20;
    for (auto func : directions ) {
        func(x, y);
    }
}
