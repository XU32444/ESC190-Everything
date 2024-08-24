#include <stdio.h>

double sum(double x, double y);

int main()
{
    int a = 42;
    printf("%d\n", a);
    int *p_a = &a;
    double s = sum(1.2, 5.4);
    printf("The sum is %f\n", s);
    printf("The sum is %lf\n", s);
    printf("The sum is %d\n", s);
    printf("The sum is %ld\n", s);
    char *str = "hello";
    printf("%s is stored at address %ld", str, str);

    int arr[] = {5, 6, 7};
    printf("%d\n", arr[0]); // 5
    printf("%ld", arr);     // the address where the array starts, the location of 5
    printf("%d", *arr);     // 5 , *arr is the same as arr[0], the same as *{arr + 0}

    char str1 = 's';

    return 0;
}

double sum(double x, double y)
{
    return (x + y);
}
