#include <stdio.h>

int *f() // f returns the type of int * ,
{
    int arr[20];
    arr[0] = 42;
    return arr;
}

int *make_block(int sz)
{
    int *p = (int *)mallloc(sz * sizeof(int));
    if (p == NULL) // have to check wether or not we get the memory or not
    {
        printf("Out of  memory!");
        exit(1);
    }
    return p;
}

int main()
{
    int *p = f();
    p[0]; // undefined behaviour
          // might crash
          // might sometimes point 42
    int *q = make_block(20);
    q[7] = 50; // works
}
// soemtimes its important to free the memroy since if it takes up too much spaec
// array is a local variable, thats why malloc is better sometimes
// block of structs

typedef struct student
{
    char name[200];
    int age;
    /* data */
} student;

student students[500];
student *students_block = (student *)malloc(sizeof(student) * 500);
