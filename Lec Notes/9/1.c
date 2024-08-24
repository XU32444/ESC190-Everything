#include <stdio.h>
#include "a.h" // copy a
#include "student.h"
#include <string.h>

typedef struct student
{
    char name[20];
    int age;
} student;

typedef struct student_wp
{
    char *name;
    int *age;
} student_wp;

int main()
{

    student s1;
    strcpy(s1.name, "John");

    student_wp s2;
    s2.name = "John"; // fine
    s2.name = (char *)malloc(20 * sizeof(char));
    srtcpy(s2.name, "John");

    // when freeing, need to say
    free(s2.name);

    printf("Hello World!\n");
    student s1;
    s1.age = 20;
    char name[200] = "Bob";
    // name = "Alice";        // Bad, cannot reassign arrays
    strcpy(name, "Alice"); // OK
    name[0] = 'a';         // OK
    printf("%s", name);
    return 0;
}
