#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

int LL_Len(node *head)
{
    node *curr = head;
    int res = 0;
    while (curr != NULL)
    {
        curr = curr->next;
        res++;
    }
    return res;
}

int main()
{
    node *n1 = (node *)malloc(sizeof(node));
    node *n2 = (node *)malloc(sizeof(node));
    node *n3 = (node *)malloc(sizeof(node));
    n1->data = 1;
    n1->next = n2;
    n2->data = 2;
    n2->next = n3;
    n3->data = 3;
    n3->next = NULL;
    printf("%d\n", LL_Len(n1));
    return 0;
}