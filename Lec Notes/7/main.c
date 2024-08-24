#include <stdio.h>

void does_change(int *p_a);
void dont_change_a(int a);
void wont_change(int *p_a);
void change_arr(int *arr);
void dont_change_arr(int *arr);
void print_arr(int *arr);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    print_arr(arr);
    change_arr(arr);
    print_arr(arr);
    return 0;
}

void dont_change_a(int a)
{
    a = 10;
}

void wont_change(int *p_a)
{
    p_a = 10; // the pointer that originally point to the address of a now points to 10
}

void does_change(int *p_a)
{
    *p_a = 100; // will change the number to 100
}

// how to send list in C
void change_arr(int *arr)
{
    arr[0] = 5;
}

void dont_change_arr(int *arr)
{
    arr = 0;
}

void print_arr(int *arr)
{
    int a = 0;
    a = 6;
    for (int i = 0; i < a; i++)
    {
        printf("%d,", *(arr + i));
    }
}

void string_changer(char *s)
{
    s[0] = 's';
}