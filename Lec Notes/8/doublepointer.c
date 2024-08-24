#include <stdio.h>

void set0_pointer(int **pp)
{
    *pp = 0;
}

int main()
{

    int a = 42;
    int *p_a = &a;
    printf("%p\n", p_a);
    set0_pointer(&p_a);
    printf("%d\n", a);
    printf("%p\n", p_a);

    return 0;
}
