#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int top;
    int data[MAX_SIZE];
} Stack;

void initialize(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int element)
{
    if (isFull(s))
    {
        printf("Stack Overflow!\n");
        return;
    }
    s->top++;
    s->data[s->top] = element;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    int poppedElement = s->data[s->top];
    s->top--;
    return poppedElement;
}

void display(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Stack Elements: ");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main()
{
    Stack myStack;
    initialize(&myStack);

    // Push elements onto the stack
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    // Display the stack elements
    display(&myStack);

    // Pop elements from the stack
    int poppedElement = pop(&myStack);
    printf("Popped Element: %d\n", poppedElement);

    // Display the updated stack
    display(&myStack);

    return 0;
}