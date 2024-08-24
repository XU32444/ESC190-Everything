#include <stdio.h>

void swapper(int *x, int *y);

int main()
{
    int a = 100;
    int b = 1;
    printf("a = %d, b = %d\n", a, b);
    swapper(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}

void swapper(int *x, int *y)
{
    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
}
