#include <stdio.h>
#include <string.h>

// option 1 store everything in the struct

struct student1
{
    char name[50];
    double gpa;
};

// option 2, store a pointer toae inside the struct
// stundet 2 takes up less space than student1, because storing char* takes up less space than char{50}
typedef struct student2
{
    char *name;
    double gpa;
} student2;

int main()
{
    // array of student1's
    student1 s1[150]; // 150 cells, store the info about the student in the cell

    // malloc block of student1's
    student1 *s1_block = (student1 *)malloc(150 * sizeof(student1));
    // unlike s1, can return s1_block,becase the address s1_address s valid until the explicitly free it

    // array of student2's
    student2 s2[150]; // 150 cell, store the of info about the student in each cell, cannot say right now printf("%s\n",s2[0].name)
    // s2[0].name is not a valid address, can say printf("%f\n",s2[0],name) // since gpa has some value, it will be prtined
    // printf("%ld",s2[0].name); // will print some arbitary value

    s2[0].name = "John"; // fine but not allowed to modify s2[0].name[00] to 'j'

    // or

    s2[0].name = (char *)malloc(50 * sizeof(char));
    strcpy(s2[0].name, "John"); // fine
    // strcpy(s2[0].name, "John"); is the same as
    // s2[0].name[0] = 'J';
    // s2[0].name[0] = 'o';
    // s2[0].name[0] = 'h';
    // s2[0].name[0] = 'n';
    // s2[0].name[0] = '\n';

    // malloc a block of pointets to student2's
    student2 **p_s2_block = (student2 **)malloc(150 * sizeof(student2)); // the address of the first object of the blokc of objects that are type student2 *;
    int i = 0;
    for (i = 0, i < 150, i++)
    {
        p_s2_block[i] = (studnet2 *)malloc(sizeof(studet2 *));
        p_s2_block[i]->gpa = 4.0;
        // student2 s2
        //  s2.gpa
        //  student2 *p_s2 = &s2;
        //  p_s2 -> gpa = 4.0   ,  (*p_s2).gpa = 4.0;

        p_s2_block[i]->name = (char *)malloc(50 * sizeof(char));
        strcp(p_s2_block[i]->name, "John");

        // p_s2_block[i] -> name = "John" // fine, but weird, how do you know it's John
    }
    // what we did
    // * allowcated space for

    return 0;
}