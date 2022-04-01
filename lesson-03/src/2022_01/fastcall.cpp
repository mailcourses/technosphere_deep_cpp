void foo1(int, int, int, int)
{
}

[[gnu::fastcall]]
void foo2(int, int, int, int, int, int, int, int)
{
}


void boo1()
{
    foo1(1,2,3,4);
}

void boo2()
{
    foo2(1,2,3,4, 5, 6, 7, 8);
}
