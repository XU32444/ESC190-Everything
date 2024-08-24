#include <stdio.h>
void change_A(int *p_a);
void dont_change(int a);

int main()
{

    int a = 42;
    change_A(&a);
    dont_change(a);
    printf("%d\n", a);

    return 0;
}

void change_A(int *p_a)
{
    *p_a = 12;
}

void dont_change(int a)
{
    a = 42;
}

void f1(int *p_a)
{
    p_a = 0;
}
