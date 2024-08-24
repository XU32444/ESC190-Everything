#include <stdio.h>
#include <stdlib.h> // for malloc

int my_strlen(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

int str_len2(const char *str)
{
    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
}

// x != '\0' is te smae as x when treated as a boolean
// in C, the vlaue of a = b is b (and it has the effect of assigning B to A)
// a = (c = 3), first set c to 3, then c to a
// the value of a++ is a (and it has the effectof incrementing a by 1)
// int a  = 5, int b = 4, b = a++ // this sets b to 4, a to 6, set b to 5;

int strlen(const char *str)
{
    int len = 0;
    while (*(str++))
    {
        len++;
    }
    return len;
}

// recursive strlen (also DOnt, but mighht be helpful)
// BASE CASE, *stris '\0' => return 0
// RECURSIVE STEP = return 1 + strlenrec(str + 1)

int strlen_rec(const char *str)
{
    if (*str == '\0')
    {
        return 0;
    }
    else
    {
        return 1 + strlen_rec(str + 1);
    }
}

int main()
{
    const char *str = "lennn";
    printf("%d", my_strlen(str));

    return 0;
}