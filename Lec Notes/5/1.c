#include <stdio.h>

void f1(int a);
void f2(int *p_a);
void f3(int *p_a);

int main()
{
    // all variables in c must be declared
    int a = 42;
    char *S = "xyyz";
    int arr[] = {4, 5};
    printf("%d\n", *arr);
    printf("%d\n", *(arr + 1));
    // prof said that, when you declare a pointer, the use of * is  comletely different from dereferencing or, accessing useage of *

    return 0;
}

void f1(int a)
{
    // f(43) copies 43 to local variable  a, the varibale iis local, it has no efect
    a = 42;
}

void f2(int *p_a)
{
    // no differencevoid f3(int *p_a);
    // you changed the pointer varibale, p_a that orginaly points to thee value a now pointed to the address of zero.
    p_a = 0;
}

void f3(int *p_a)
{
    // no its zero, since you access the memory.
    *p_a = 0;
}
