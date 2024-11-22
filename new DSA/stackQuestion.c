#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int main()
{
    push(10);
    push(20);
    printf("Top element: %d\n", peek());
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    return 0;
}
