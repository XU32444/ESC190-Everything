#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *p = (char *)calloc(10000, sizeof(char));
    free(p);

    /////
    char *p = (char *)malloc(10000); // calloc fills everything with zero
    *(p) = 's';
    printf("Value: %c\n", p[5000]); // *(p+5000)
    printf("%s\n", p + 10000 - 3);  // in principle, if p[9997] is not '\0' and p[9998] is not '\0' will tyr to acccess p[9999] and p[10000],
    // eveentually access memory tahts not suppoed to access

    int **p_p_int;
    p_p_int = (int **)malloc(2 * sizeof(int *));
    // p_p_int is a blokc int int*
    int *p_int = *p_p_int; // p_p_int[0] // *(p_p_int + 0)
    // begin
    int *p_int;       // now p_int is an address
    p_int = *p_p_int; // *p_p_int is the address of the first
    // expty block in a long empty sequence
    // end
    int my_int = *p_int; //

    return 0;
}
