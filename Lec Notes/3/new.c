#include <stdio.h>

int main()
{

    int a = 42;
    int b;

    char *s1 = "abcdef"; // s1 is of type char*
    char s2 = '@';
    double d = 3.14;

    printf("%s", s1);
    printf("The integer is %d \n", a);
    printf("the character is %c \n", s2);
    printf("the string is %c \n", s2);

    int *p_a = &a;
    printf("The value of p_a, or we can say, the address of a is : %ld\n", p_a);
    printf("Dereferenced, the value of the thing that has the address stored in p_a : %d\n", *p_a);
    // addressed of values are refered to as pointers

    double x = 12.34;
    double *address_of_x = &x;
    double y = 25 + *address_of_x; // y = 25 + 12.34;

    char *s3 = "hello!"; // * is used as a type of char
    char c = *s3;       
    printf("%c", c);

    return 0;
}