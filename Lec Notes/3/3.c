#include <stdio.h>

int main()
{
    // before we use a variabe, we need to declare it
    // optionaly, can also initalize it

    int a = 10;
    int b;               // b is an integer, but is not initialized
                         // can have any value
                         // almost in 100% of cases, want to initialize
                         // types include, double(float), char(single character), int*(address of int),
    char *s1 = "hi!";    // put "hi!" followed by "\0" in memory, s1 stores the address of h, not the sequence of character
                         // stores the address of h in s1
    printf("%s\n", s1);  // %s means string
    printf("%ls\n", s1); // %d means integer
                         // %ld means
    printf("The string is : %s, the address is %ld \n", s1, s1);

    int s = 43;
    printf("The integer is %s \n", s); // string
    printf("The integer is %d \n", s); // integer

    printf("Hello World \n");

    return 0;
}