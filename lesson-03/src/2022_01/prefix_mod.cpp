const int foo(int) { return 1; }

void const boo() {}

int main()
{
    int a0 = 0;
    const int * a = &a0; // (1)
    int const * b; // (2) == (1)
    // *a = 10; <-- ошибка компиляции.
    // как и
    // *b = 10;
    int * const c = &a0; // (3)
    // c = b; <-- ошибка компиляции.
    *c = 10;
    const int * const d = c; // (4)
    // d = b; <-- ошибка компиляции.
    // *d = 10;// <-- ошибка компиляции.
    *c = 20;
    const int &a1 = a0;
    //a2 = 10;
}
