#include <stdio.h>
#include <stdbool.h>
#define MAX 100

// Stack structure

typedef struct
{
    int items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void iniStack(Stack *s)
{
    s->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(const Stack *s)
{
    return s->top == -1;
}

// Function to check if the stack is full
bool isFull(const Stack *s)
{
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return -1; // return -1 indicate an error
    }
    return s->items[s->top--];
}

// Function to get the top element of the stack
int peek(const Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty");
        return -1; // return -1 indicates an error
    }
    return s->items[s->top];
}

// Main function
int main()
{
    Stack myStack;
    iniStack(&myStack); // Initialize the stack

    // Push elements onto the stack
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    // print and pop elements from the stack
    while (isEmpty(&myStack))
    {
        printf("Top element: %d\n", peek(&myStack));
        pop(&myStack);
    }

    return 0;
}