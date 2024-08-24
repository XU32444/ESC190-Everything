#include <stdio.h>
#include <stdlib.h>

// Linked Lists
// A way to store lists without pre allowcating  a lot of memory
// [2,3,435,632,4,234,23,44,234,]

// A->B->C->D->E

typedef struct node
{
    int data;
    struct node *next;

} node;

// Head

void create_linked_list(node **p_head, int *data, int size)
{
    if (size == 0)
    {
        *p_head = NULL;
        return;
    }
    node *cur = (node *)malloc(sizeof(node));
    cur->data = data[0];
    *p_head = cur;
    for (int i = 0; i < size; i++)
    {
        cur->next = (node *)malloc(sizeof(node));
        cur->next->data = data[i];
        cur = cur->next;
    }
    cur->next = NULL;
}

void print_linked_list(node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
}

void insert_linked_list(node **p_head, int ind, int num)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = num;
    if (ind == 0)
    {
        node *new = (node *)malloc(sizeof(node));
        new->data = num;
        new->next = *p_head;
        *p_head = new;
    }
    else
    {
        // go throuhg the linked list until node i-1
        // insert the node after i - 1;
        node *cur = *p_head;
        for (int i = 0; i < ind - 1; i++)
        {
            cur = cur->next;
        }
        new->next = cur->next;
        cur->next = new;
    }
}

int main()
{
    // Crate a simple linked list
    node *head = (node *)malloc(sizeof(node));
    head->data = 1;

    node *n2 = (node *)malloc(sizeof(node));
    n2->data = 5;
    head->next = n2;

    // want to insert the value 10 between 1 and 5
    node *n10 = (node *)malloc(sizeof(node));
    head->next = n10;
    n10->next = n2;
    n10->data = 10;

    node a;
    a.data = 12;

    printf("%d\n", head->data);
    // free(&a); would crash
    // free(a); would not complile, a is not a pointer
    // free(head);
    // free(n2);

    return 0;
}