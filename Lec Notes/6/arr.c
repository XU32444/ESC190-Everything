#include <stdio.h>

void set_arr0(int *arr)
{
    arr[0] = 44;
    *(arr + 1) = 12;
}

int main()
{
    int arr[] = {5, 6, 7};
    set_arr0(arr);
    for (int i = 0; i < 3; i++)
    {
        printf("%d, ", arr[i]);
    }
    return 0;
}
