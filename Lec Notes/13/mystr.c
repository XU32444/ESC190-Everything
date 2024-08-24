// a = "asdasd"
// const char *str = "akjd";

/* void mystr_create(mystr *p_s, const char *str, int len)
{
    len = 123123;
    s.len = len;
}
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystr.h"

void mystr_create(mystr *p_s, const char *str, int len)
{
    // allowcate p_s->str, and copy str to p_s->str
    //  could instad say p_s.->str = str;
    //  BUT, then if str is a const char*,
    //  we wont koow that we are not allowed to modify, could crash.
    //  Also, don't know if need to free p_s->str later
    // p_s->str and str are now different pointers, but
    // with p_s->str = str, they are equal (so strings are aliases)
    p_s->len = len; // same as (*p_s).len = len;
    p_s->str = (char *)malloc((len + 1) * sizeof(char));
    if (p_s->str == NULL)
    {
        printf("Malloc Failed\n");
        exit(1);
    }
    strcpy(p_s->str, str);
}

void mystr_cat(mystr *p_dest, const mystr *p_src)
{
    p_dest->str = (char *)realloc(p_dest->str,
                                  (p_dest->len + p_src->len + 1) * sizeof(char));
    if (p_dest->str == NULL)
    {
        printf("Realloc Failed\n");
        exit(1);
    }
    strcat(p_dest->str, p_src->str);
}

int main()
{
    mystr s;
    mystr_create(&s, "EngSci", 6);
    mystr praxis;
    mystr_create(&praxis, "PRAXIS!!!", 9);

    mystr_cat(&s, &praxis);
    printf("%s\n", s.str);

    mystr_destry(&s);
    mystr_destry(&praxis);
}
