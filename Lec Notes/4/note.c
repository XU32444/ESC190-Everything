#include <stdio.h>

int main()
{
    int a = 42;
    int *p_a = &a;
    changer(p_a);
    printf("%p", p_a);
    printf("%d", a);
    long int la = 213213123123;
    char c = '@';

    char *s = "abs";

    // arrays in  c
    int arr[] = {5, 10, 2};
    arr[0] = 3; // can only use {} for initialization

    return 0;
}

// function

void changer(int *p_a)
{
    *p_a = 44;
}

int add(int a, int b) // specify return type and input parameter type
{
    return a + b;
}

int f(int *p_a)
{
    *p_a = 43;
}
