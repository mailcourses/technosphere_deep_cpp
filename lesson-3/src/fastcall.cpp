[[gnu::fastcall]]
void foo1(int a, int b, int c, int d) {}

void foo2(int a, int b, int c, int d) {}

void foo3(int a, int b, int, int, int, int, int, int)
{
}

void boo1()
{
    foo1(1, 2, 3, 4);
}

void boo2()
{
    foo2(5, 6, 7, 8);
}

void boo3()
{
    foo3(1, 2, 3, 4, 5, 6, 7, 8);
}
