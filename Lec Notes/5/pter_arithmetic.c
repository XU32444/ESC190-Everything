#include <stdio.h>

int main()
{

    char *s = "hi";
    // s stores the address of 'h'
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    int arr[] = {3, 4, 5};
    int *p_a = arr;
    printf("%d\n", *p_a);
    printf("%d\n", *(p_a + 1));
    printf("%d\n", *(p_a + 2));

    // in c :   arr[5] = *(arr+5);

    return 0;
}


