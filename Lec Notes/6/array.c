#include <stdio.h>

int main()
{
    char s1[] = "abcdefg";
    char *s2 = "abcdefg";
    printf("%c\n", *(s2 + 2));
    printf("%s\n", s2);
    printf("%s\n", s2);

    // all the strings in c are type of const char*
    const int a = 43;
    // a = 32 // errorQQ
    int *p_a = &a;
    *p_a = 21;
    printf("%d", a);

    return 0;
}