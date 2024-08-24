#include <stdio.h>

int main()
{
    // str is type of char * in main
    // p_str is address of str, of type char**
    // &str = p_str; of type char**

    return 0;
}

void change_int(int *p_int)
{
    *p_int = 5;
    p_int = 0; // no effect, change has alreaedy been made, but now _int points to a different address
}

void change_int_p(int **p_p_int)
{
    *p_p_int = malloc(sizeof(int)); // making changes on the address
}

void safer_strcat(char **p_str1, char *str2)
{
    // need enough space at *p_str1 to hold both str1 and str2
    // need strlen(*p_str1) + strlen(str2) + 1

    // Assume tat *p_str1 was allocated with malloc
    // if it wasnt, we are in big trouble

        *p_str1 = realloc(*p_str1, strlen(*p_str1) + strlen(str2) + 1);
    if (*p_str1 == NULL)
    {
        printf("Safer strcat failed to allocate memroy\n");
        exit(1);
    }
}
