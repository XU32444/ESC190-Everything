#include <stdio.h>
#include <stdlib.h> // for malloc



int main()
{

    int *block_int = (int *)malloc(sizeof(int) * 150); // alllocate space for 150 int

    block_int[7] = 42;
    printf("%d",*(block_int+7))
    *(block_int + 7) = 42; // reminder, those are the same // block + 7 gets the right location in mmeory table // becuase C is 



}

// sizeof int = 4 byte
// size of char = 1 byte
// size of char* usually 8 byes
// size of int* usually 8 byes