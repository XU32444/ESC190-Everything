#include <stdio.h>
void f(int *a);
void fu(int a);
int main()
{
    int a = 3;
    printf("%d\n", a);
    fu(a);
    printf("%d\n", a);
    f(&a);
    printf("%d\n", a);

    return 0;
}

void f(int *a)
{
    *a = 23;
    // will make a difference since it goes to the address where a is
}

void fu(int a)
{
    a = 1;
    printf("%d\n", a);
    // wont make a differnce since the a that passed in has gone to the local memory made for the function
}