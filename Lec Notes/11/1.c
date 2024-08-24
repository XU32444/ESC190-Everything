#include <stdio.h>
#include <stdlib.h>

int main()
{
    // can resize blocks of memory using realloc
    char *str = malloc(100 * sizeof(char)); // str is a pointer
    // wnat to take more space
    str = realloc(str, 200 * sizeof(char));

    char *block = malloc(1000000);
    if (block == NULL)
    {
        printf("Out of Memory\n");
        exit(1); // exit and terminates the program, the 1 is sent to the system
    }
    else
    {
        printf("%p\n", block);
    }

    return 0;
}