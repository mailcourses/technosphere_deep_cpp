module;

#include <iostream>

export module mexample;

export int square(int value) {
    return value * value;
}

export int mult(int a, int b) {
    return a * b;
}
