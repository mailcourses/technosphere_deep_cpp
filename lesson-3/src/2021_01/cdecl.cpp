void foo1(int a, int b, int c, int d)
{
    int tmp = 1;
}

//[[gnu::fastcall]]
[[gnu::stdcall]]
void foo2(int a, int b, int c, int d)
{
    int tmp = 2;
}

void boo1()
{
    foo1(1,2,3,4);
}

void boo2()
{
    foo2(1,2,3,4);
}
