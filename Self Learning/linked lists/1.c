#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void LL_printer(node curr);
int len(node *curr);
void printer(node *curr);
void append(node *curr, int index, int data);
void delete(node *curr, int index);
int main()
{
    node elem1, elem2, elem3;
    elem1.data = 1;
    elem1.next = &elem2;
    elem2.data = 2;
    elem2.next = &elem3;
    elem3.data = 3;
    elem3.next = NULL;
    printer(&elem1);
    append(&elem1, 2, 100);
    printf("\n");
    printer(&elem1);
    printf("\n");
    delete (&elem1, 2);
    printer(&elem1);

    return 0;
}

void append(node *curr, int index, int data)
{

    if ((index < 0) || index > len(curr))
    {
        perror("Wrong index input");
        exit(0);
    }
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    if (index == 0)
    {
        newnode->next = curr;
    }
    else
    {
        node *before = NULL;
        node *after = NULL;
        for (int i = 0; i < index; i++)
        {
            if (i == index - 1)
            {
                before = curr;
                after = curr->next;
                before->next = newnode;
                newnode->next = after;
            }
            else
            {
                curr = curr->next;
            }
        }
    }
}
void LL_printer(node curr)
{
    int k = 1;
    while (curr.next != NULL)
    {
        printf("The %dth element is %d \n", k, curr.data);
        k++;
        curr = *(curr.next);
    }
    printf("The %dth element is %d \n", k, curr.data);
}

int len(node *curr)
{
    int i = 0;
    while (curr != NULL)
    {
        i++;
        curr = curr->next;
    }
    return i;
}

void printer(node *curr)
{
    node *init = curr;
    int len = 0;
    while (curr != NULL)
    {
        len++;
        curr = curr->next;
    }
    curr = init;
    for (int i = 0; i < len; i++)
    {
        printf("The %dth elemt in the linked list is %d\n", i + 1, curr->data);
        curr = curr->next;
    }
}

void delete(node *head, int index)
{
    if ((index < 0) || (index > len(head)))
    {
        perror("ERROR");
    }
    node *curr = head;
    if (index == (len(head) - 1))
    {
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        free(curr);
    }
    else
    {
        node *before = NULL;
        node *need_delete = NULL;
        node *after = NULL;
        for (int i = 0; i < index; i++)
        {
            if (i == index - 1)
            {
                before = curr;
                need_delete = curr->next;
                after = curr->next->next;
            }
            else
            {
                curr = curr->next;
            }
        }
        before->next = after;
        free(need_delete);
    }
}