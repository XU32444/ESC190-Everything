#include <stdio.h>
#include <string.h>

int main()
{

    char s1[] = "hi";
    char s1[] = {'h', 'i', '\0'};
    char *s2 = 0;
    s2 = s1;        // legal, but strings are now aliases
    strcpy(s2, s1); // not yet ok, since cannot copy to address s2

    s2 = (char *)malloc(sizeof(char) * (strlen(s1)+1);
    // returns an addrss in the memory table, where is has the size of the length of the stirng and plus 1, for hte null character '\n'

    

    return 0;
}