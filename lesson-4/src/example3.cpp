#include <iostream>

class Shape
{
public:
    Shape(){}
    void foo() { x_ = -10; }
protected:
    int x_ = 0;
    int y_ = 0;
};

class Circle : public Shape
{
public:
    Circle() { }
    Circle(int x, int y) { x_ = x; y_ = y; }
    void draw() { std::cout << "Circle(x,y)=" << x_ << ", " << y_ << std::endl; }
public:
    int radius = 5;
};

int main()
{
    Circle c(10, 20);
    c.foo();
    c.draw();
}
