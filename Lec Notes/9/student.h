#ifndef STUDENT_H
#define STUDENT_H

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

#endif
