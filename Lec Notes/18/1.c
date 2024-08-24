#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Defining the maximum size of the stack

// Stack structure using an array
typedef struct
{
    int items[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initializeStack(Stack *s)
{
    s->top = -1;
}

// Check if the stack is full
int isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

// Check if the stack is empty
int isEmpty(Stack *s)
{
    return s->top == -1;
}

// Push an item onto the stack
void push(Stack *s, int item)
{
    if (isFull(s))
    {
        printf("Stack is full!\n");
    }
    else
    {
        s->top++;
        s->items[s->top] = item;
    }
}

// Pop an item from the stack
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return -1; // Returning -1 to indicate an empty stack
    }
    else
    {
        int item = s->items[s->top];
        s->top--;
        return item;
    }
}

// Peek at the top item of the stack
int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return -1; // Returning -1 to indicate an empty stack
    }
    else
    {
        return s->items[s->top];
    }
}

// Main function to demonstrate stack operations
int main()
{
    Stack myStack;
    initializeStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top item: %d\n", peek(&myStack)); // Should print 30

    printf("Popped: %d\n", pop(&myStack)); // Should print 30
    printf("Popped: %d\n", pop(&myStack)); // Should print 20

    push(&myStack, 40);
    printf("Top item: %d\n", peek(&myStack)); // Should print 40

    return 0;
}
