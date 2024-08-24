#include <stdio.h>

int main()
{

    int *p = malloc(3 * (sizeof(int)));
    *p = 1;
    *(p + 1) = 12;
    *(p + 2) = 12123;

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", *(p + i));
        printf("%p\n", p + i);
    }

    return 0;
}