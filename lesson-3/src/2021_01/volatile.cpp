
int foo(volatile int &a)
{
    a = 10;
    int x = 20;
    a = x;
    a = 30;
    boo(a);
    return a;
}

int main()
{
    int a = 0;
    foo(a);
}
